#include <array>
#include <deque>
#include <numeric>

void emit_ticks(const std::vector<Tick>&v){
    std::cout<<'[';for(size_t i=0;i<v.size();++i){if(i)std::cout<<',';std::cout<<v[i];}std::cout<<']';
}

void coupled_case(const char*policy,EndpointConfig config,const char*family,
                  unsigned index,unsigned mask,const std::set<Tick>&updates,
                  bool invalid_entry=false){
    actions={};action_serial=0;tick_now=5;next_request_id=0;
    pending_requests.clear();first_read_miss.reset();first_expiry.reset();
    Endpoint device(config,!invalid_entry);endpoint=&device;
    MemTest tester(9,1);tester.interval=16;tester.schedule(tester.tickEvent,5);
    unsigned accepted=0;Tick last=5;
    for(Tick t=5;t<=1000;++t){
        tick_now=t;last=t;
        const bool wu=std::string(family)=="mask" ? ((mask>>((t-5)%12))&1) : updates.count(t);
        if(device.begin_tick(t,wu) && !first_expiry)first_expiry=t;
        while(!actions.empty() && actions.top().when==t){
            auto event=actions.top();actions.pop();event.fn();
        }
        assert(actions.empty() || actions.top().when>t);
        if(first_read_miss)break;
        if(auto output=device.finish_tick(t))deliver_endpoint(tester,*output);
        accepted=0;for(auto&r:tester.sends)accepted+=r.accepted;
        if(accepted==9)break;
    }
    assert(first_read_miss || accepted==9);
    std::vector<Tick>services;for(auto&r:tester.sends)if(r.accepted)services.push_back(r.time);
    std::cout<<"{\"kind\":\"coupled\",\"policy\":\""<<policy<<"\",\"family\":\""<<family
             <<"\",\"index\":"<<index<<",\"last_tick\":"<<last<<",\"services\":";
    emit_ticks(services);std::cout<<",\"receipts\":";emit_ticks(tester.replies);
    std::cout<<",\"waiting_polls\":";emit_ticks(tester.waiting_polls);
    std::cout<<",\"first_miss\":";if(first_read_miss)std::cout<<*first_read_miss;else std::cout<<"null";
    std::cout<<",\"first_expiry\":";if(first_expiry)std::cout<<*first_expiry;else std::cout<<"null";
    std::cout<<",\"pending_snapshots\":"<<pending_requests.size()<<"}\n";
    endpoint=nullptr;actions={};pending_requests.clear();
    while(!live_packets.empty())delete*live_packets.begin();
}

// Quotient IDs label the four deterministic service phases; they never alias
// while pending. Source-coupled runs above instead use fresh monotone IDs.
unsigned service_id(unsigned phase){
    switch(phase%81){case 5:return 1;case 21:return 2;case 37:return 3;case 70:return 4;default:return 0;}
}
unsigned response_id(unsigned phase){
    switch(phase%81){case 18:return 1;case 36:return 2;case 54:return 3;case 0:return 4;default:return 0;}
}
using EndpointKey=std::array<uint64_t,11>;
EndpointKey key(unsigned phase,const Endpoint&e){
    return {phase,e.valid,e.enabled,e.count,e.value,e.register0.occupied,e.register0.id,
            e.register0.value,e.register1.occupied,e.register1.id,e.register1.value};
}
void emit_state(const char*policy,unsigned id,const EndpointKey&k){
    std::cout<<"{\"kind\":\"bfs_state\",\"policy\":\""<<policy<<"\",\"id\":"<<id<<",\"state\":[";
    for(unsigned i=0;i<k.size();++i){if(i)std::cout<<',';std::cout<<k[i];}
    std::cout<<"]}\n";
}
void bfs_case(const char*policy,EndpointConfig config){
    const unsigned period=std::lcm(81u,config.expiry_period);
    Endpoint initial(config);std::deque<std::pair<unsigned,Endpoint>>todo;
    std::map<EndpointKey,unsigned>seen;seen.emplace(key(5,initial),0);todo.push_back({5,initial});
    emit_state(policy,0,key(5,initial));
    uint64_t transitions=0,read_branches=0,response_branches=0;
    while(!todo.empty()){
        const auto [phase,state]=todo.front();todo.pop_front();const auto from=seen.at(key(phase,state));
        for(unsigned wu=0;wu<2;++wu){
            auto next=state;const bool expired=next.begin_tick(phase,wu);
            const unsigned request=service_id(phase);
            if(request){assert(next.accept_read(request));++read_branches;}
            auto output=next.finish_tick(phase);const unsigned expected=response_id(phase);
            assert(bool(output)==bool(expected));
            if(output){assert(output->id==expected && output->value==0);++response_branches;}
            const unsigned nextphase=(phase+1)%period;auto k=key(nextphase,next);
            auto [it,inserted]=seen.emplace(k,unsigned(seen.size()));
            if(inserted){todo.push_back({nextphase,next});emit_state(policy,it->second,k);}
            std::cout<<"{\"kind\":\"bfs_edge\",\"policy\":\""<<policy<<"\",\"from\":"<<from
                     <<",\"phase\":"<<phase<<",\"wu\":"<<wu<<",\"to\":"<<it->second
                     <<",\"read_id\":"<<request<<",\"response_id\":"<<(output?output->id:0)
                     <<",\"expired\":"<<expired<<"}\n";
            assert(!expired && next.valid);++transitions;
        }
    }
    assert(transitions==2*seen.size());
    std::cout<<"{\"kind\":\"bfs_summary\",\"policy\":\""<<policy<<"\",\"period\":"<<period
             <<",\"states\":"<<seen.size()<<",\"transitions\":"<<transitions
             <<",\"read_branches\":"<<read_branches<<",\"response_branches\":"<<response_branches<<"}\n";
}

void value_and_revocation_checks(){
    Endpoint e({9,3,18,2});assert(!e.begin_tick(5,true,17));assert(e.accept_read(1));
    for(unsigned t=6;t<=18;++t){
        e.begin_tick(t,true,uint8_t(100+t));
        auto out=e.finish_tick(t);
        if(t==9){assert(!out);assert(e.register1.occupied && e.register1.value==17);}
        if(t==18){assert(out && out->id==1 && out->value==17);}
    }
    e.begin_tick(19,true,99,true);assert(!e.valid && !e.enabled && !e.accept_read(2));
    e.begin_tick(20,true,88);assert(!e.valid && !e.enabled);
    std::cout<<"{\"kind\":\"value_revocation_controls\",\"snapshot_preserved_under_updates\":true,\"revocation_first\":true,\"invalid_WU_no_resurrection\":true}\n";
}

int main(int argc,char**argv){
    if(argc>1 && std::string(argv[1])=="--bfs"){
        bfs_case("old",{9,2,27,6});bfs_case("new",{9,3,18,2});return 0;
    }
    for(unsigned policy=0;policy<2;++policy){
        const EndpointConfig config=policy?EndpointConfig{9,3,18,2}:EndpointConfig{9,2,27,6};
        const char*name=policy?"new":"old";
        for(unsigned mask=0;mask<4096;++mask)coupled_case(name,config,"mask",mask,mask,{});
        unsigned index=0;coupled_case(name,config,"finite",index++,0,{});
        for(Tick a=5;a<=86;++a){
            coupled_case(name,config,"finite",index++,0,{a});
            for(Tick b=a+1;b<=86;++b)coupled_case(name,config,"finite",index++,0,{a,b});
        }
        assert(index==3404);
    }
    coupled_case("unsafe",{9,2,18,2},"negative",0,0,{38});
    coupled_case("invalid_entry",{9,3,18,2},"negative",1,0,{},true);
    value_and_revocation_checks();
    assert(live_packets.empty());return 0;
}
