// New experiment main; upstream methods and existing environment are unchanged.
void slow_scenario(unsigned p,unsigned ell,Tick start,unsigned q,bool &comma){
    actions={};action_serial=0;tick_now=start;
    MemTest tester(p,ell);tester.interval=q;
    tester.schedule(tester.tickEvent,start);
    unsigned accepted=0,steps=0;
    while(accepted<61){
        if(actions.empty()||++steps>=100000)throw std::runtime_error("periodic event bound exceeded");
        auto event=actions.top();actions.pop();tick_now=event.when;event.fn();
        accepted=0;for(auto &r:tester.sends)accepted+=r.accepted;
    }
    assert(tester.sends.size()==61&&tester.replies.size()==60&&tester.waiting_polls.empty());
    for(auto &r:tester.sends)assert(r.read&&r.accepted);
    if(comma)std::cout<<",";comma=true;
    std::cout<<"{\"p\":"<<p<<",\"ell\":"<<ell<<",\"s0\":"<<start<<",\"q\":"<<q<<",\"services\":[";
    for(size_t i=0;i<tester.sends.size();++i){if(i)std::cout<<",";std::cout<<tester.sends[i].time;}
    std::cout<<"],\"receipts\":[";
    for(size_t i=0;i<tester.replies.size();++i){if(i)std::cout<<",";std::cout<<tester.replies[i];}
    std::cout<<"]}";
    actions={};while(!live_packets.empty())delete*live_packets.begin();
}
int main(){
    bool comma=false;std::cout<<"[";
    for(unsigned p=2;p<=6;++p)for(unsigned ell=1;ell<=4;++ell)
        for(unsigned q=(ell+1)*p;q<(ell+2)*p;++q)for(Tick start=0;start<p;++start)
            slow_scenario(p,ell,start,q,comma);
    slow_scenario(4,1,100,9,comma);
    std::cout<<"]\n";
}
