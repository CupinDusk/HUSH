// Explicit bounded-latency stub choices, not future service timestamps.
void variable_scenario(unsigned mask,bool &comma){
    actions={};action_serial=0;tick_now=3;response_latencies.clear();latency_index=0;
    for(unsigned i=0;i<8;++i)response_latencies.push_back(1+((mask>>i)&1));
    response_latencies.push_back(1); // ninth response is scheduled but not executed
    MemTest tester(5,1);tester.interval=8;tester.schedule(tester.tickEvent,3);
    unsigned accepted=0,steps=0;
    while(accepted<9){
        if(actions.empty()||++steps>=10000)throw std::runtime_error("variable event bound exceeded");
        auto event=actions.top();actions.pop();tick_now=event.when;event.fn();
        accepted=0;for(auto &r:tester.sends)accepted+=r.accepted;
    }
    assert(tester.sends.size()==9&&tester.replies.size()==8&&latency_index==9);
    for(auto &r:tester.sends)assert(r.read&&r.accepted);
    if(comma)std::cout<<",";comma=true;
    std::cout<<"{\"mask\":"<<mask<<",\"latencies\":[";
    for(unsigned i=0;i<8;++i){if(i)std::cout<<",";std::cout<<response_latencies[i];}
    std::cout<<"],\"services\":[";
    for(size_t i=0;i<tester.sends.size();++i){if(i)std::cout<<",";std::cout<<tester.sends[i].time;}
    std::cout<<"],\"receipts\":[";
    for(size_t i=0;i<tester.replies.size();++i){if(i)std::cout<<",";std::cout<<tester.replies[i];}
    std::cout<<"],\"waiting_polls\":[";
    for(size_t i=0;i<tester.waiting_polls.size();++i){if(i)std::cout<<",";std::cout<<tester.waiting_polls[i];}
    std::cout<<"]}";
    actions={};while(!live_packets.empty())delete*live_packets.begin();
}
int main(){bool comma=false;std::cout<<"[";for(unsigned mask=0;mask<256;++mask)variable_scenario(mask,comma);std::cout<<"]\n";}
