// Parameter grid driver; source bodies and receiver header remain unchanged.
void emit_family_ticks(const std::vector<Tick>&v){
    std::cout<<'[';for(size_t i=0;i<v.size();++i){if(i)std::cout<<',';std::cout<<v[i];}std::cout<<']';
}
int main(){
    unsigned case_id,p,q,s0;
    while(std::cin>>case_id>>p>>q>>s0){
        for(unsigned mode=0;mode<3;++mode){
            actions={};action_serial=0;tick_now=s0;next_request_id=0;
            pending_requests.clear();first_read_miss.reset();first_expiry.reset();
            Endpoint device({p,2,q+2*p,0});endpoint=&device;
            MemTest tester(p,1);tester.interval=q;tester.schedule(tester.tickEvent,s0);
            unsigned accepted=0;
            for(Tick t=s0;t<100000;++t){
                tick_now=t;
                bool wu=mode==1 || (mode==2 && !tester.sends.empty() && t==tester.sends.back().time+1);
                assert(!device.begin_tick(t,wu));
                while(!actions.empty() && actions.top().when==t){auto e=actions.top();actions.pop();e.fn();}
                assert(actions.empty() || actions.top().when>t);
                assert(!first_read_miss);
                if(auto output=device.finish_tick(t))deliver_endpoint(tester,*output);
                accepted=0;for(auto&r:tester.sends)accepted+=r.accepted;
                if(accepted==33)break;
            }
            assert(accepted==33 && tester.replies.size()==32 && pending_requests.size()==1);
            std::vector<Tick>services;for(auto&r:tester.sends)if(r.accepted)services.push_back(r.time);
            std::cout<<"{\"case\":"<<case_id<<",\"WU_mode\":"<<mode<<",\"services\":";
            emit_family_ticks(services);std::cout<<",\"receipts\":";emit_family_ticks(tester.replies);
            std::cout<<",\"waiting_polls\":";emit_family_ticks(tester.waiting_polls);std::cout<<"}\n";
            endpoint=nullptr;actions={};pending_requests.clear();while(!live_packets.empty())delete*live_packets.begin();
        }
    }
}
