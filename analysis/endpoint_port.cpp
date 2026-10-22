// This replaces the response-target stub, while MemTest bodies stay byte-exact.
#include "endpoint_implementation.hpp"
static Endpoint* endpoint=nullptr;
static uint64_t next_request_id=0;
static std::map<uint64_t,PacketPtr> pending_requests;
static std::optional<Tick> first_read_miss,first_expiry;

bool MemTest::CpuPort::sendTimingReq(PacketPtr pkt){
    assert(endpoint && pkt->isRead());
    const uint64_t id=++next_request_id;
    const bool accepted=endpoint->accept_read(id,pkt->req->getPaddr());
    memtest.sends.push_back({curTick(),true,accepted});
    if(!accepted){if(!first_read_miss)first_read_miss=curTick();return false;}
    assert(pending_requests.emplace(id,pkt).second);
    return true;
}

void deliver_endpoint(MemTest&tester,const EndpointRegister&response){
    auto it=pending_requests.find(response.id);assert(it!=pending_requests.end());
    auto* packet=it->second;pending_requests.erase(it);
    packet->data[0]=response.value;tester.replies.push_back(curTick());
    assert(tester.port.recvTimingResp(packet));
}
