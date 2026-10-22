// New serial-client component stubs; controlled read-path RNG, one-tick client clock.
// Declared function-level packet/port/clock/event stubs, not full gem5.
#include <cassert>
#include <cstdint>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>
#ifdef NDEBUG
#error This source-function experiment requires active assertions
#endif
using Tick=uint64_t;using Addr=uint64_t;using Cycles=uint64_t;
static Tick tick_now=0;Tick curTick(){return tick_now;}
#define DPRINTF(...) ((void)0)
#define ccprintf(...) ((void)0)
#define panic(...) throw std::runtime_error("retained MemTest panic")
#define panic_if(c, ...) do{if(c)panic();}while(0)
void exitSimLoop(const char*){throw std::runtime_error("unexpected exit limit");}
struct AtomicOpFunctor{virtual ~AtomicOpFunctor()=default;};
using AtomicOpFunctorPtr=std::shared_ptr<AtomicOpFunctor>;
template<class T>struct TypedAtomicOpFunctor:AtomicOpFunctor{};
template<class T>struct AtomicGeneric3Op:TypedAtomicOpFunctor<T>{
    template<class F>AtomicGeneric3Op(T,T,F){}
};
struct Request{
    enum{UNCACHEABLE=1,ATOMIC_RETURN_OP=2};
    struct Flags{unsigned bits=0;void set(unsigned f){bits|=f;}};
    Addr addr;unsigned bytes;bool atomic=false;
    Request(Addr a,unsigned b,Flags,unsigned):addr(a),bytes(b){}
    Addr getPaddr()const{return addr;}unsigned getSize()const{return bytes;}
    void setContext(unsigned){}void setAtomicOpFunctor(AtomicOpFunctorPtr){}
    void setFlags(unsigned f){atomic=(f&ATOMIC_RETURN_OP)!=0;}
};
using RequestPtr=std::shared_ptr<Request>;
enum class MemCmd{ReadReq,WriteReq};
struct Packet;using PacketPtr=Packet*;static std::set<PacketPtr> live_packets;
struct Packet{
    RequestPtr req;MemCmd cmd;uint8_t*data=nullptr;
    Packet(RequestPtr r,MemCmd c):req(std::move(r)),cmd(c){live_packets.insert(this);}
    ~Packet(){live_packets.erase(this);delete[]data;}
    void dataDynamic(uint8_t*p){data=p;}
    template<class T>const T*getConstPtr()const{return reinterpret_cast<T*>(data);}
    bool isWrite()const{return cmd==MemCmd::WriteReq;}bool isRead()const{return cmd==MemCmd::ReadReq;}
    bool isAtomicOp()const{return req->atomic;}bool isError()const{return false;}
    bool suppressFuncError()const{return false;}void setSuppressFuncError(){}
};
struct Event{
    bool active=false;Tick when=0;uint64_t generation=0;std::function<void()>fn;
    bool scheduled()const{return active;}
};
struct Action{Tick when;uint64_t serial;std::function<void()>fn;
    bool operator<(const Action&o)const{return when!=o.when?when>o.when:serial>o.serial;}};
static std::priority_queue<Action> actions;static uint64_t action_serial=0;
void later(Tick when,std::function<void()>fn){assert(when>=curTick());actions.push({when,action_serial++,std::move(fn)});}
struct FakeRng{
    bool write=false;unsigned percent_call=0;
    void beginTick(){percent_call=0;}
    template<class T>T random(){return 0;}
    template<class T>T random(T low,T high){
        if(low==0&&high==100)return percent_call++==0&&write?100:0;
        return low;
    }
};
struct SendRecord{Tick time;bool read,accepted;};
class MemTest{
  public:
    struct CpuPort{
        MemTest&memtest;explicit CpuPort(MemTest&m):memtest(m){}
        bool recvTimingResp(PacketPtr);bool sendTimingReq(PacketPtr);
        Tick sendAtomic(PacketPtr){return 0;}void sendFunctional(PacketPtr p){p->data[0]=0;}
    };
    CpuPort port;FakeRng random_state;FakeRng*rng=&random_state;
    Event tickEvent,noResponseEvent,noRequestEvent;
    PacketPtr retryPkt=nullptr;bool waitResponse=false,atomic=false,suppressFuncErrors=false;
    unsigned size=64,blockSize=64,sizeBlocks=1,id=0,requestorId=0;
    Addr baseAddr1=64,baseAddr2=64,uncacheAddr=128;
    unsigned percentReads=100,percentUncacheable=0,percentAtomic=0,percentFunctional=0;
    unsigned interval=1,progressCheck=1000,progressInterval=1000,nextProgressMessage=1000;
    uint64_t maxLoads=0,numReads=0,numWrites=0,numAtomics=0;
    struct{uint64_t numReads=0,numWrites=0,numAtomics=0;}stats;
    std::set<Addr>outstandingAddrs;
    std::map<Addr,uint8_t>referenceData,atomicPendingData;
    unsigned cache_period=4,lat_cycles=2,rejections_remaining=0;
    std::vector<SendRecord>sends;std::vector<Tick>replies,waiting_polls;
    explicit MemTest(unsigned p,unsigned ell,bool write=false,bool reject=false):port(*this),cache_period(p),lat_cycles(ell),rejections_remaining(reject?1:0){
        random_state.write=write;
        tickEvent.fn=[this]{rng->beginTick();tick();if(waitResponse)waiting_polls.push_back(curTick());};
        noRequestEvent.fn=[] {throw std::runtime_error("no-request timeout");};
        noResponseEvent.fn=[] {throw std::runtime_error("no-response timeout");};
    }
    const char*name()const{return "isolated-MemTest";}
    Addr blockAlign(Addr a)const{return a&~Addr(blockSize-1);}
    Tick clockEdge(Cycles n)const{return curTick()+n;}
    void schedule(Event&e,Tick when){
        assert(!e.active);e.active=true;e.when=when;auto generation=++e.generation;
        later(when,[&e,generation]{if(e.active&&e.generation==generation){e.active=false;e.fn();}});
    }
    void deschedule(Event&e){e.active=false;++e.generation;}
    void reschedule(Event&e,Tick when,bool=false){if(e.active)deschedule(e);schedule(e,when);}
    void tick();bool sendPkt(PacketPtr);void recvRetry();void completeRequest(PacketPtr,bool functional=false);
};
