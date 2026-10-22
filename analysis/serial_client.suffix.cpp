bool MemTest::CpuPort::sendTimingReq(PacketPtr pkt){
    if(memtest.rejections_remaining){
        --memtest.rejections_remaining;memtest.sends.push_back({curTick(),pkt->isRead(),false});
        later(curTick()+6,[this]{memtest.recvRetry();});return false;
    }
    memtest.sends.push_back({curTick(),pkt->isRead(),true});
    const Tick target=((curTick()+memtest.cache_period-1)/memtest.cache_period+memtest.lat_cycles)*memtest.cache_period;
    later(target,[this,pkt]{
        memtest.replies.push_back(curTick());pkt->data[0]=memtest.referenceData[pkt->req->getPaddr()];
        const bool accepted=recvTimingResp(pkt);
        if(!accepted)throw std::runtime_error("unexpected response rejection");
    });
    return true;
}
