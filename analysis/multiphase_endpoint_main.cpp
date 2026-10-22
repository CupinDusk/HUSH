// New policy driver, same pinned public MemTest control and endpoint header.
#include <array>
#include <deque>
#include <numeric>
void ticks34(const std::vector<Tick>&v){std::cout<<'[';for(size_t i=0;i<v.size();++i){if(i)std::cout<<',';std::cout<<v[i];}std::cout<<']';}
void coupled34(unsigned policy,unsigned mask,bool negative=false,bool invalid=false){
    actions={};action_serial=0;tick_now=0;next_request_id=0;pending_requests.clear();first_read_miss.reset();first_expiry.reset();
    EndpointConfig cfg=policy?EndpointConfig{12,5,10,1}:EndpointConfig{12,2,40,1};if(negative)cfg={12,1,40,1};
    Endpoint device(cfg,!invalid);endpoint=&device;MemTest tester(12,1);tester.interval=35;tester.schedule(tester.tickEvent,0);
    unsigned accepted=0;Tick last=0;
    for(Tick t=0;t<2000;++t){
        tick_now=t;last=t;bool wu=negative?t==1:((mask>>(t%12))&1);
        if(device.begin_tick(t,wu) && !first_expiry)first_expiry=t;
        while(!actions.empty() && actions.top().when==t){auto e=actions.top();actions.pop();e.fn();}
        assert(actions.empty() || actions.top().when>t);if(first_read_miss)break;
        if(auto r=device.finish_tick(t))deliver_endpoint(tester,*r);
        accepted=0;for(auto&r:tester.sends)accepted+=r.accepted;if(accepted==33)break;
    }
    if(negative){assert(first_expiry && *first_expiry==1 && first_read_miss && *first_read_miss==35);}
    else if(invalid){assert(first_read_miss && *first_read_miss==0);}
    else{assert(!first_expiry && !first_read_miss && accepted==33 && tester.replies.size()==32);}
    std::vector<Tick>ss;for(auto&r:tester.sends)if(r.accepted)ss.push_back(r.time);
    std::cout<<"{\"kind\":\"coupled\",\"policy\":"<<policy<<",\"mask\":"<<mask<<",\"negative\":"<<negative<<",\"invalid\":"<<invalid<<",\"services\":";ticks34(ss);
    std::cout<<",\"receipts\":";ticks34(tester.replies);std::cout<<",\"last\":"<<last<<"}\n";
    endpoint=nullptr;actions={};pending_requests.clear();while(!live_packets.empty())delete*live_packets.begin();
}
using K34=std::array<uint64_t,11>;
K34 key34(unsigned t,const Endpoint&e){return {t,e.valid,e.enabled,e.count,e.value,e.register0.occupied,e.register0.id,e.register0.value,e.register1.occupied,e.register1.id,e.register1.value};}
void print34(const K34&k){std::cout<<'[';for(size_t i=0;i<k.size();++i){if(i)std::cout<<',';std::cout<<k[i];}std::cout<<']';}
void bfs34(unsigned policy){
    EndpointConfig cfg=policy?EndpointConfig{12,5,10,1}:EndpointConfig{12,2,40,1};unsigned L=std::lcm(420u,cfg.expiry_period);
    std::vector<std::pair<unsigned,Endpoint>>states;states.emplace_back(0,Endpoint(cfg));std::map<K34,unsigned>seen;seen[key34(0,states[0].second)]=0;unsigned edges=0;
    for(size_t i=0;i<states.size();++i){
        auto [t,ep]=states[i];std::cout<<"{\"kind\":\"state\",\"policy\":"<<policy<<",\"id\":"<<i<<",\"key\":";print34(key34(t,ep));std::cout<<"}\n";
        for(unsigned wu=0;wu<2;++wu){
            auto next=ep;bool expired=next.begin_tick(t,wu);unsigned rid=(t%35==0)?1+(t%420)/35:0;if(rid)assert(next.accept_read(rid));
            auto out=next.finish_tick(t);unsigned reply=out?out->id:0;assert(!expired && next.valid);if(out)assert(out->value==0);
            unsigned nt=(t+1)%L;auto [it,added]=seen.emplace(key34(nt,next),unsigned(seen.size()));if(added)states.emplace_back(nt,next);
            std::cout<<"{\"kind\":\"edge\",\"policy\":"<<policy<<",\"from\":"<<i<<",\"to\":"<<it->second<<",\"wu\":"<<wu<<",\"read\":"<<rid<<",\"reply\":"<<reply<<",\"expired\":"<<expired<<"}\n";++edges;
        }
    }
    assert(edges==2*states.size());std::cout<<"{\"kind\":\"summary\",\"policy\":"<<policy<<",\"period\":"<<L<<",\"states\":"<<states.size()<<",\"edges\":"<<edges<<"}\n";
}
int main(int argc,char**argv){if(argc>1 && std::string(argv[1])=="--bfs"){bfs34(0);bfs34(1);return 0;}for(unsigned p=0;p<2;++p)for(unsigned mask=0;mask<4096;++mask)coupled34(p,mask);coupled34(0,0,true);coupled34(0,0,false,true);assert(live_packets.empty());}
