void scenario(unsigned p,unsigned ell,Tick start,unsigned variant,bool&comma){
    actions={};action_serial=0;tick_now=start;
    MemTest tester(p,ell,variant==1,variant==2);
    tester.schedule(tester.tickEvent,start);
    unsigned accepted=0,steps=0;
    while(accepted<13){
        if(actions.empty()||++steps>=10000)throw std::runtime_error("serial event bound exceeded");
        auto event=actions.top();actions.pop();tick_now=event.when;event.fn();
        accepted=0;for(auto&r:tester.sends)accepted+=r.accepted;
    }
    std::vector<Tick>times;bool all_reads=true,no_retry=true;
    for(auto&r:tester.sends){if(r.accepted)times.push_back(r.time);all_reads&=r.read;no_retry&=r.accepted;}
    assert(times.size()==13&&tester.replies.size()==12);
    if(comma)std::cout<<",";comma=true;
    std::cout<<"{\"p\":"<<p<<",\"ell\":"<<ell<<",\"initial_service\":"<<start
      <<",\"variant\":"<<variant<<",\"all_reads\":"<<(all_reads?"true":"false")
      <<",\"no_retry\":"<<(no_retry?"true":"false")<<",\"services\":[";
    for(size_t i=0;i<times.size();++i){if(i)std::cout<<",";std::cout<<times[i];}
    std::cout<<"],\"receipts\":[";
    for(size_t i=0;i<tester.replies.size();++i){if(i)std::cout<<",";std::cout<<tester.replies[i];}
    std::cout<<"],\"waiting_polls\":[";
    for(size_t i=0;i<tester.waiting_polls.size();++i){if(i)std::cout<<",";std::cout<<tester.waiting_polls[i];}
    std::cout<<"]}";
    actions={};while(!live_packets.empty())delete*live_packets.begin();
}
int main(){
    bool comma=false;std::cout<<"[";
    for(unsigned p=2;p<=6;++p)for(unsigned ell=1;ell<=4;++ell)
        for(Tick start=0;start<2*p;++start)scenario(p,ell,start,0,comma);
    scenario(4,2,0,1,comma);scenario(4,2,0,2,comma);
    std::cout<<"]\n";
}
