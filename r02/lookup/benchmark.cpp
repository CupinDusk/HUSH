#include <algorithm>
#include <array>
#include <chrono>
#include <cstdint>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using I128 = __int128;
using U128 = unsigned __int128;
using Clock = std::chrono::steady_clock;
constexpr uint64_t DENSE_CAP = uint64_t(1) << 20;
const char* ROUTES[] = {"grouped_scan", "canonical_scan", "reset_predecessor", "dense_phase_table"};
volatile I128 retained_checksum = 0;

struct Pair { uint64_t r; I128 span; };
struct Reset { uint64_t a; I128 h; };
struct Query { uint32_t profile; uint64_t phase; };
struct Profile {
    std::string name, corpus;
    uint64_t m;
    std::vector<Pair> raw, expected_grouped, expected_canonical, grouped, canonical;
    std::vector<Reset> reset;
    std::vector<I128> dense;
};
struct Corpus {
    std::string name, query_file;
    size_t query_count;
    std::vector<uint32_t> ids;
    std::vector<int> eligible;
    std::array<std::vector<int>, 9> orders;
    std::vector<Query> queries;
};

std::string decimal(I128 x) {
    bool neg = x < 0;
    U128 u = neg ? U128(-(x + 1)) + 1 : U128(x);
    std::string s;
    do { s.push_back(char('0' + u % 10)); u /= 10; } while (u);
    if (neg) s.push_back('-');
    std::reverse(s.begin(), s.end());
    return s;
}

I128 parse_i128(const std::string& s) {
    if (s.empty()) throw std::runtime_error("empty decimal");
    size_t pos = s[0] == '-' ? 1 : 0;
    bool neg = pos == 1;
    U128 u = 0;
    const U128 lim = (U128(1) << 127) - (neg ? 0 : 1);
    if (pos == s.size()) throw std::runtime_error("invalid decimal");
    for (; pos < s.size(); ++pos) {
        if (s[pos] < '0' || s[pos] > '9') throw std::runtime_error("invalid decimal");
        unsigned d = unsigned(s[pos] - '0');
        if (u > (lim - d) / 10) throw std::runtime_error("signed128 decimal overflow");
        u = u * 10 + d;
    }
    if (neg) return u == (U128(1) << 127) ? -I128(u - 1) - 1 : -I128(u);
    return I128(u);
}

std::string quote(const std::string& s) {
    std::string out = "\"";
    for (unsigned char c : s) {
        if (c == '\\' || c == '"') { out += '\\'; out += char(c); }
        else if (c == '\n') out += "\\n";
        else if (c == '\r') out += "\\r";
        else if (c == '\t') out += "\\t";
        else if (c < 32) out += "?";
        else out += char(c);
    }
    return out + '"';
}

template<class T> uint64_t capacity_bytes(const std::vector<T>& v) { return uint64_t(v.capacity()) * sizeof(T); }
uint64_t elapsed(Clock::time_point t0, Clock::time_point t1) {
    return uint64_t(std::chrono::duration_cast<std::chrono::nanoseconds>(t1 - t0).count());
}
std::ofstream events;
void emit(const std::string& s) { events << s << '\n'; events.flush(); if (!events) throw std::runtime_error("event write failed"); }

std::vector<Pair> read_pairs(std::istream& f, size_t n) {
    std::vector<Pair> rows;
    rows.reserve(n);
    for (size_t j = 0; j < n; ++j) {
        uint64_t r;
        std::string v;
        if (!(f >> r >> v)) throw std::runtime_error("profile pair read failed");
        I128 span = parse_i128(v);
        if (span < 0) throw std::runtime_error("negative source span");
        rows.push_back({r, span});
    }
    return rows;
}

std::vector<Pair> make_grouped(const std::vector<Pair>& raw, uint64_t m) {
    std::vector<Pair> tmp;
    tmp.reserve(raw.size());
    for (const Pair& x : raw) tmp.push_back({x.r % m, x.span});
    std::sort(tmp.begin(), tmp.end(), [](const Pair& a, const Pair& b) { return a.r < b.r; });
    size_t write = 0;
    for (size_t j = 0; j < tmp.size(); ++j) {
        if (write && tmp[write-1].r == tmp[j].r) tmp[write-1].span = std::max(tmp[write-1].span, tmp[j].span);
        else tmp[write++] = tmp[j];
    }
    tmp.resize(write);
    tmp.shrink_to_fit();
    return tmp;
}

std::vector<Pair> make_canonical(const std::vector<Pair>& rows, uint64_t m) {
    // Grouped rows already have distinct residues in increasing order.
    std::vector<I128> suffix(rows.size() + 1, -1);
    for (size_t j = rows.size(); j-- > 0;) suffix[j] = std::max(I128(rows[j].r) + rows[j].span, suffix[j+1]);
    I128 prefix = -1;
    std::vector<Pair> out;
    out.reserve(rows.size());
    for (size_t j = 0; j < rows.size(); ++j) {
        I128 w = I128(rows[j].r) + rows[j].span;
        if (w > prefix && w + I128(m) > suffix[j+1]) out.push_back(rows[j]);
        prefix = std::max(prefix, w);
    }
    if (out.empty()) throw std::runtime_error("empty canonical output");
    out.shrink_to_fit();
    return out;
}

std::vector<Reset> make_reset(const std::vector<Pair>& rows, uint64_t m) {
    std::vector<Reset> out;
    out.reserve(rows.size());
    for (const Pair& x : rows) out.push_back({x.r + 1 == m ? 0 : x.r + 1, -x.span});
    std::sort(out.begin(), out.end(), [](const Reset& a, const Reset& b) { return a.a < b.a; });
    return out;
}

inline I128 scan(const std::vector<Pair>& rows, uint64_t m, uint64_t z) {
    const Pair& first = rows.front();
    uint64_t d = z > first.r ? z - first.r - 1 : z + m - first.r - 1;
    I128 result = I128(d) - first.span;
    for (size_t j = 1; j < rows.size(); ++j) {
        const Pair& x = rows[j];
        // z, r < m <= 2^61-1. No remainder or signed overflow in this wrap.
        d = z > x.r ? z - x.r - 1 : z + m - x.r - 1;
        I128 v = I128(d) - x.span;
        result = std::min(result, v);
    }
    return result;
}

inline I128 predecessor(const std::vector<Reset>& rows, uint64_t m, uint64_t z) {
    size_t lo = 0, hi = rows.size();
    while (lo < hi) {
        size_t mid = lo + (hi - lo) / 2;
        if (rows[mid].a <= z) lo = mid + 1;
        else hi = mid;
    }
    const Reset& x = rows[lo ? lo - 1 : rows.size() - 1];
    uint64_t d = z >= x.a ? z - x.a : z + m - x.a;
    return x.h + I128(d);
}

template<int Route> I128 query(const Profile& p, uint64_t z) {
    if constexpr (Route == 0) return scan(p.grouped, p.m, z);
    if constexpr (Route == 1) return scan(p.canonical, p.m, z);
    if constexpr (Route == 2) return predecessor(p.reset, p.m, z);
    if constexpr (Route == 3) return p.dense[z];
}
template<int Route> __attribute__((noinline)) I128 run(const std::vector<Profile>& profiles, const std::vector<Query>& queries) {
    I128 sum = 0;
    for (const Query& q : queries) sum += query<Route>(profiles[q.profile], q.phase);
    return sum;
}
I128 run_route(int r, const std::vector<Profile>& p, const std::vector<Query>& q) {
    switch (r) {
        case 0: return run<0>(p, q);
        case 1: return run<1>(p, q);
        case 2: return run<2>(p, q);
        case 3: return run<3>(p, q);
        default: throw std::runtime_error("invalid route");
    }
}
I128 one_route(int r, const Profile& p, uint64_t z) {
    switch (r) {
        case 0: return query<0>(p, z);
        case 1: return query<1>(p, z);
        case 2: return query<2>(p, z);
        case 3: return query<3>(p, z);
        default: throw std::runtime_error("invalid route");
    }
}
void check_pairs(const std::vector<Pair>& a, const std::vector<Pair>& b, const std::string& context) {
    if (a.size() != b.size()) throw std::runtime_error(context + ": pair count mismatch");
    for (size_t j = 0; j < a.size(); ++j) if (a[j].r != b[j].r || a[j].span != b[j].span) throw std::runtime_error(context + ": pair value mismatch at " + std::to_string(j));
}
std::string ints(const std::vector<int>& xs) {
    std::string s = "[";
    for (size_t j=0; j<xs.size(); ++j) s += (j ? "," : "") + std::to_string(xs[j]);
    return s + "]";
}

int main(int argc, char** argv) {
    const std::string outfile = argc == 2 ? argv[1] : "native_events_attempt1.jsonl";
    { std::ifstream existing(outfile); if (existing.good()) { std::cerr << "Refusing to overwrite " << outfile << '\n'; return 2; } }
    events.open(outfile, std::ios::binary);
    try {
        emit("{\"event\":\"start\",\"arithmetic\":\"signed __int128\",\"sizeof_pair\":" + std::to_string(sizeof(Pair)) + ",\"sizeof_reset\":" + std::to_string(sizeof(Reset)) + ",\"sizeof_i128\":" + std::to_string(sizeof(I128)) + ",\"sizeof_query\":" + std::to_string(sizeof(Query)) + ",\"sizeof_profile\":" + std::to_string(sizeof(Profile)) + ",\"steady_clock\":" + (Clock::is_steady ? "true" : "false") + ",\"clock_period_num\":" + std::to_string(Clock::period::num) + ",\"clock_period_den\":" + std::to_string(Clock::period::den) + "}");
        std::ifstream pf("NATIVE_PROFILES.txt");
        size_t n;
        if (!(pf >> n)) throw std::runtime_error("profile header read failed");
        std::vector<Profile> profiles;
        profiles.reserve(n);
        for (size_t i = 0; i < n; ++i) {
            Profile p;
            size_t nr, ng, nc;
            if (!(pf >> p.name >> p.corpus >> p.m >> nr >> ng >> nc) || !p.m || p.m > ((uint64_t(1)<<61)-1) || !nr || !ng || !nc) throw std::runtime_error("profile header invalid");
            p.raw = read_pairs(pf, nr);
            p.expected_grouped = read_pairs(pf, ng);
            p.expected_canonical = read_pairs(pf, nc);
            profiles.push_back(std::move(p));
        }
        std::string trailing;
        if (pf >> trailing) throw std::runtime_error("extra profile input");
        std::ifstream cf("NATIVE_CONTROL.txt");
        size_t cn;
        if (!(cf >> cn)) throw std::runtime_error("control header read failed");
        std::vector<Corpus> corpora(cn);
        for (Corpus& c : corpora) {
            size_t ni, ne;
            if (!(cf >> c.name >> c.query_file >> c.query_count >> ni >> ne)) throw std::runtime_error("control corpus read failed");
            c.ids.resize(ni); c.eligible.resize(ne);
            for (auto& id : c.ids) if (!(cf >> id) || id >= n || profiles[id].corpus != c.name) throw std::runtime_error("invalid corpus profile");
            for (int& r : c.eligible) if (!(cf >> r) || r < 0 || r > 3) throw std::runtime_error("invalid eligible route");
            for (auto& order : c.orders) {
                order.resize(ne);
                for (int& r : order) if (!(cf >> r)) throw std::runtime_error("schedule read failed");
                auto a=order, b=c.eligible; std::sort(a.begin(),a.end()); std::sort(b.begin(),b.end());
                if (a != b) throw std::runtime_error("schedule route mismatch");
            }
            c.queries.reserve(c.query_count);
            std::ifstream qf(c.query_file, std::ios::binary);
            std::vector<bool> allowed(n, false);
            for (auto id : c.ids) allowed[id] = true;
            for (size_t j=0; j<c.query_count; ++j) {
                // The frozen on-disk record is exactly 12 bytes, never sizeof(Query).
                unsigned char b[12];
                if (!qf.read(reinterpret_cast<char*>(b),12)) throw std::runtime_error("truncated query input");
                uint32_t id=0; uint64_t z=0;
                for (int k=0;k<4;++k) id |= uint32_t(b[k]) << (8*k);
                for (int k=0;k<8;++k) z |= uint64_t(b[k+4]) << (8*k);
                if (id>=n || !allowed[id] || z>=profiles[id].m) throw std::runtime_error("invalid query id/phase");
                c.queries.push_back({id,z});
            }
            char extra;
            if (qf.get(extra)) throw std::runtime_error("extra query bytes");
        }
        if (cf >> trailing) throw std::runtime_error("extra control input");
        emit("{\"event\":\"inputs_loaded\",\"profiles\":"+std::to_string(n)+",\"corpora\":"+std::to_string(cn)+",\"profile_container_capacity_bytes\":"+std::to_string(capacity_bytes(profiles))+"}");

        for (Corpus& c : corpora) {
            std::cout << "Building " << c.name << std::endl;
            std::array<uint64_t,4> build_ns{};
            auto begin=Clock::now();
            for (auto id:c.ids) profiles[id].grouped=make_grouped(profiles[id].raw,profiles[id].m);
            build_ns[0]=elapsed(begin,Clock::now());
            for (auto id:c.ids) check_pairs(profiles[id].grouped,profiles[id].expected_grouped,profiles[id].name+" grouped");
            begin=Clock::now();
            for (auto id:c.ids) profiles[id].canonical=make_canonical(profiles[id].grouped,profiles[id].m);
            build_ns[1]=elapsed(begin,Clock::now());
            for (auto id:c.ids) check_pairs(profiles[id].canonical,profiles[id].expected_canonical,profiles[id].name+" canonical");
            begin=Clock::now();
            for (auto id:c.ids) profiles[id].reset=make_reset(profiles[id].canonical,profiles[id].m);
            build_ns[2]=elapsed(begin,Clock::now());
            for (auto id:c.ids) {
                auto expected=make_reset(profiles[id].expected_canonical,profiles[id].m);
                const auto& actual=profiles[id].reset;
                if (actual.size()!=expected.size()) throw std::runtime_error("reset size mismatch");
                for (size_t j=0;j<actual.size();++j) if (actual[j].a!=expected[j].a || actual[j].h!=expected[j].h) throw std::runtime_error("reset pair mismatch");
            }
            begin=Clock::now();
            for (auto id:c.ids) {
                auto& p=profiles[id];
                if (p.m<=DENSE_CAP) {
                    p.dense.resize(size_t(p.m));
                    // Dense construction evaluates the grouped envelope at every phase.
                    for (uint64_t z=0;z<p.m;++z) p.dense[size_t(z)]=scan(p.grouped,p.m,z);
                }
            }
            build_ns[3]=elapsed(begin,Clock::now());
            for (int r:c.eligible) if (r==3) for (auto id:c.ids) if (profiles[id].dense.empty()) throw std::runtime_error("eligible dense route unavailable");
            emit("{\"event\":\"construction\",\"corpus\":"+quote(c.name)+",\"profile_count\":"+std::to_string(c.ids.size())+",\"grouping_ns\":"+std::to_string(build_ns[0])+",\"canonical_conversion_ns\":"+std::to_string(build_ns[1])+",\"predecessor_sort_ns\":"+std::to_string(build_ns[2])+",\"dense_build_ns\":"+(std::find(c.eligible.begin(),c.eligible.end(),3)!=c.eligible.end()?std::to_string(build_ns[3]):"null")+",\"query_count\":"+std::to_string(c.query_count)+",\"query_array_capacity_bytes\":"+std::to_string(capacity_bytes(c.queries))+"}");
            for (auto id:c.ids) {
                const auto& p=profiles[id];
                emit("{\"event\":\"profile_storage\",\"id\":"+std::to_string(id)+",\"name\":"+quote(p.name)+",\"corpus\":"+quote(c.name)+",\"modulus\":"+std::to_string(p.m)+",\"raw_terms\":"+std::to_string(p.raw.size())+",\"grouped_terms\":"+std::to_string(p.grouped.size())+",\"canonical_terms\":"+std::to_string(p.canonical.size())+",\"reset_pairs\":"+std::to_string(p.reset.size())+",\"dense_scalars\":"+std::to_string(p.dense.size())+",\"raw_capacity_bytes\":"+std::to_string(capacity_bytes(p.raw))+",\"grouped_capacity_bytes\":"+std::to_string(capacity_bytes(p.grouped))+",\"canonical_capacity_bytes\":"+std::to_string(capacity_bytes(p.canonical))+",\"reset_capacity_bytes\":"+std::to_string(capacity_bytes(p.reset))+",\"dense_capacity_bytes\":"+std::to_string(capacity_bytes(p.dense))+",\"oracle_capacity_bytes\":"+std::to_string(capacity_bytes(p.expected_grouped)+capacity_bytes(p.expected_canonical))+"}");
            }
            I128 expected_sum=0;
            uint64_t route_checks=0;
            for (size_t j=0;j<c.queries.size();++j) {
                const Query& q=c.queries[j]; const Profile& p=profiles[q.profile];
                const I128 oracle=scan(p.expected_canonical,p.m,q.phase);
                for (int r:c.eligible) {
                    const I128 actual=one_route(r,p,q.phase);
                    if (actual!=oracle) throw std::runtime_error(c.name+" query "+std::to_string(j)+" route "+std::to_string(r)+" expected "+decimal(oracle)+" actual "+decimal(actual));
                    ++route_checks;
                }
                expected_sum+=oracle;
            }
            emit("{\"event\":\"validation\",\"corpus\":"+quote(c.name)+",\"status\":\"PASS_EVERY_QUERY_EVERY_ELIGIBLE_ROUTE\",\"query_count\":"+std::to_string(c.query_count)+",\"route_checks\":"+std::to_string(route_checks)+",\"expected_checksum\":"+quote(decimal(expected_sum))+"}");
            std::cout << "Validated " << c.name << "; warming" << std::endl;
            for (int r:c.eligible) {
                I128 sum=run_route(r,profiles,c.queries); retained_checksum=sum;
                if (sum!=expected_sum) throw std::runtime_error("warm checksum mismatch");
                emit("{\"event\":\"warm\",\"corpus\":"+quote(c.name)+",\"route\":"+std::to_string(r)+",\"checksum\":"+quote(decimal(sum))+"}");
            }
            for (int block=0;block<9;++block) {
                emit("{\"event\":\"block_order\",\"corpus\":"+quote(c.name)+",\"block\":"+std::to_string(block)+",\"order\":"+ints(c.orders[size_t(block)])+"}");
                for (size_t position=0;position<c.orders[size_t(block)].size();++position) {
                    int r=c.orders[size_t(block)][position];
                    auto t0=Clock::now();
                    I128 sum=run_route(r,profiles,c.queries);
                    auto t1=Clock::now();
                    retained_checksum=sum;
                    if (sum!=expected_sum) throw std::runtime_error("timed checksum mismatch");
                    emit("{\"event\":\"timing\",\"corpus\":"+quote(c.name)+",\"block\":"+std::to_string(block)+",\"position\":"+std::to_string(position)+",\"route\":"+std::to_string(r)+",\"route_name\":"+quote(ROUTES[r])+",\"elapsed_ns\":"+std::to_string(elapsed(t0,t1))+",\"query_count\":"+std::to_string(c.query_count)+",\"checksum\":"+quote(decimal(sum))+"}");
                }
                std::cout << "Timed " << c.name << " block " << block+1 << "/9" << std::endl;
            }
        }
        emit("{\"event\":\"complete\",\"status\":\"PASS\",\"retained_volatile_checksum\":"+quote(decimal(retained_checksum))+"}");
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "FAIL: " << e.what() << std::endl;
        if (events) emit("{\"event\":\"failure\",\"message\":"+quote(e.what())+"}");
        return 1;
    }
}
