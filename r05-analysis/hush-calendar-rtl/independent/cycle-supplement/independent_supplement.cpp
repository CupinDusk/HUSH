// Independent validator. Only netlist signal wiring/declared trace format shared.
// The oracle is a typed queue / immutable snapshot transition implementation.
#include "netlist.cpp"
#include <array>
#include <algorithm>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <numeric>
#include <stdexcept>
#include <string>
#include <vector>
using DUT=cxxrtl_design::p_receiver;
#define G(x) uint32_t(d.p_##x.get<uint32_t>())
#define S(x,v) d.p_##x.set<uint32_t>(v)
using State=std::array<uint32_t,34>;
using Events=std::array<uint32_t,32>;
struct Token {uint32_t owner=0,id=0,byte=0;};
struct Config {int id,p,r,F;};
std::string context;
void require(bool a,const std::string &why){if(!a)throw std::runtime_error(context+": "+why);}
void clockedge(DUT &d){S(clk,0);d.step();S(clk,1);d.step();S(clk,0);d.step();}
State readstate(DUT&d){State a={G(tick),G(cp),G(rp),G(fp),G(pp),G(nextid),G(qlen),G(qowners)};
 for(int i=0;i<8;i++)a[8+i]=d.p_qids.data[i];
 a[16]=G(rzero);a[17]=G(ownerzero);a[18]=G(idzero);a[19]=G(bytezero);a[20]=G(rone);a[21]=G(ownerone);a[22]=G(idone);a[23]=G(byteone);
 a[24]=G(outstanding);a[25]=G(valid);a[26]=G(enabled);a[27]=G(bytes);
 for(int j=0;j<4;j++)a[28+j]=(d.p_counts.curr.data[j/2]>>(16*(j%2)))&65535;
 a[32]=G(failed);a[33]=G(fault);return a;}
Events readevents(DUT&d){return {G(evwu),G(evexpire),G(evcancel),G(evenq),G(enqowner),G(enqid),G(enqowner2),G(enqid2),G(evattempt),G(attemptowner),G(attemptid),G(evgrant),G(grantowner),G(grantid),G(grantbyte),G(evemit),G(emitowner),G(emitid),G(emitbyte),G(evtransfer),G(transferowner),G(transferid),G(transferbyte),G(evcallback),G(callbackowner),G(callbackid),G(evblock),G(blockowner),G(blockid),G(failtick),G(failowner),G(failid)};}
struct Oracle {
 Config cfg;int K,P,phi;uint32_t t,next=1;int n=0;std::array<Token,8>queue{};Token a,b;bool av=false,bv=false,failed=false;
 std::array<uint32_t,4>out{},value{},timer{};uint32_t valid=15,enabled=0;Events e{};
 std::array<int,6>peak{},sample{};uint64_t ticks=0,enq=0,grants=0,emits=0,transfers=0,blocks=0,cancels=0,expires=0,wus=0,held=0,heldblock=0;
 Oracle(Config c,int k,int p,int ph,int start):cfg(c),K(k),P(p),phi(ph),t(start){}
 State pack()const{State s{};s[0]=t;s[1]=t%cfg.p;s[2]=t%cfg.r;s[3]=t%cfg.F;s[4]=t%P;s[5]=next;s[6]=n;
  for(int i=0;i<8;i++){s[7]|=queue[i].owner<<(2*i);s[8+i]=queue[i].id;}
  s[16]=av;s[17]=a.owner;s[18]=a.id;s[19]=a.byte;s[20]=bv;s[21]=b.owner;s[22]=b.id;s[23]=b.byte;
  for(int j=0;j<4;j++){s[24]|=out[j]<<(4*j);s[27]|=value[j]<<(8*j);s[28+j]=timer[j];}
  s[25]=valid;s[26]=enabled;s[32]=failed;return s;}
 void maxima(std::array<int,6>&dest){dest[0]=std::max(dest[0],n);int total=0;for(int j=0;j<4;j++){total+=out[j];dest[2+j]=std::max(dest[2+j],int(out[j]));}dest[1]=std::max(dest[1],total);}
 void step(uint32_t input,uint32_t inputbytes){
  require(!failed,"step after miss");bool entryoccupied=av;
  for(int k:{0,1,2,3,8,11,15,19,23,26})e[k]=0;
  for(int j=0;j<4;j++)if((input&valid)&(1u<<j)){value[j]=(inputbytes>>(8*j))&255;timer[j]=K;enabled|=1u<<j;e[0]|=1u<<j;}
  if(t%P==uint32_t(phi))for(int j=0;j<4;j++)if(enabled&(1u<<j)){require(timer[j]>0,"zero active timer");if(--timer[j]==0){valid&=~(1u<<j);enabled&=~(1u<<j);e[1]|=1u<<j;}}
  // Literal multiset scheduling instead of the RTL's two-group conditions.
  const int offsets[8]={0,1,2,3,40,41,42,43};
  for(int k=0;k<8;k++)if(t%cfg.F==uint32_t(offsets[k]%cfg.F)){
   require(n<8,"oracle FIFO overflow");Token x{uint32_t(k%4),next++,0};queue[n++]=x;out[x.owner]++;
   int z=e[3]++?6:4;e[z]=x.owner;e[z+1]=x.id;
  }
  maxima(peak); // Exact maximum immediately after all enqueues, before retirement.
  int tickPeakQueue=n;auto tickPeakLines=out;
  if(t%cfg.p==0&&!entryoccupied&&n){Token x=queue[0];e[8]=1;e[9]=x.owner;e[10]=x.id;
   if(!(valid&(1u<<x.owner))){failed=true;e[29]=t;e[30]=x.owner;e[31]=x.id;}
   else {x.byte=value[x.owner];a=x;av=true;e[11]=1;e[12]=x.owner;e[13]=x.id;e[14]=x.byte;
    if(enabled&(1u<<x.owner))e[2]|=1u<<x.owner;enabled&=~(1u<<x.owner);timer[x.owner]=0;
    for(int k=0;k<7;k++)queue[k]=queue[k+1];queue[7]=Token{};n--;}
  }
  if(!failed){
   if(bv){if(t%cfg.r==1||t%cfg.r==2){e[15]=1;e[16]=b.owner;e[17]=b.id;e[18]=b.byte;bv=false;}
    else{e[26]=1;e[27]=b.owner;e[28]=b.id;}}
   if(av&&!bv){b=a;bv=true;av=false;e[19]=1;e[20]=a.owner;e[21]=a.id;e[22]=a.byte;}
   if(e[15]){e[23]=1;e[24]=e[16];e[25]=e[17];require(out[e[24]]>0,"callback without request");out[e[24]]--;}
  }
  std::array<uint32_t,4>ownership{};std::array<uint32_t,10>ids{};int ni=0;
  auto token=[&](Token x){require(x.id>0&&x.id<next,"live ID range");for(int k=0;k<ni;k++)require(ids[k]!=x.id,"duplicate live ID");ids[ni++]=x.id;ownership[x.owner]++;};
  for(int k=0;k<n;k++)token(queue[k]);if(av)token(a);if(bv)token(b);require(ownership==out,"ownership/conservation");
  maxima(sample);
  require(n+int(e[11])==tickPeakQueue,"FIFO peak reconstruction");for(int j=0;j<4;j++)require(out[j]+int(e[23]&&e[24]==uint32_t(j))==tickPeakLines[j],"line peak reconstruction");
  enq+=e[3];grants+=e[11];emits+=e[15];transfers+=e[19];blocks+=e[26];cancels+=__builtin_popcount(e[2]);expires+=__builtin_popcount(e[1]);wus+=__builtin_popcount(e[0]);ticks++;
  bool expiredsnap=(av&&!(valid&(1u<<a.owner)))||(bv&&!(valid&(1u<<b.owner)));held+=expiredsnap;heldblock+=expiredsnap&&e[26];t++;
 }
};
void init(DUT&d,const Oracle&o){S(clk,0);S(cfgp,o.cfg.p);S(cfgr,o.cfg.r);S(cfgf,o.cfg.F);S(cfgk,o.K);S(cfgperiod,o.P);S(cfgphi,o.phi);S(cfgstart,o.t);S(cfgcp,o.t%o.cfg.p);S(cfgrp,o.t%o.cfg.r);S(cfgfp,o.t%o.cfg.F);S(cfgpp,o.t%o.P);S(wu,0);S(wubytes,0);S(rst,1);clockedge(d);S(rst,0);d.step();}
void compare(DUT&d,const Oracle&o){auto actual=readstate(d),expected=o.pack();for(int k=0;k<34;k++)if(actual[k]!=expected[k])throw std::runtime_error(context+" t="+std::to_string(o.t-1)+" state["+std::to_string(k)+"] got="+std::to_string(actual[k])+" expected="+std::to_string(expected[k]));auto ae=readevents(d);for(int k=0;k<32;k++)if(ae[k]!=o.e[k])throw std::runtime_error(context+" t="+std::to_string(o.t-1)+" event["+std::to_string(k)+"] got="+std::to_string(ae[k])+" expected="+std::to_string(o.e[k]));}
void runstep(DUT&d,Oracle&o,int wu,uint32_t bytes){S(wu,wu);S(wubytes,bytes);clockedge(d);o.step(wu,bytes);compare(d,o);}
void u32(std::ofstream&f,uint32_t v){for(int j=0;j<4;j++)f.put(char(v>>(8*j)));}
void varint(std::ofstream&f,uint32_t v){do{uint8_t b=v&127;v>>=7;f.put(char(b|(v?128:0)));}while(v);}
void delta(std::ofstream&f,std::array<uint32_t,61>&previous,const Oracle&o){auto s=o.pack();std::array<uint32_t,61>a{};std::copy(s.begin()+5,s.end(),a.begin());std::copy(o.e.begin(),o.e.end(),a.begin()+29);int n=0;for(int j=0;j<61;j++)n+=a[j]!=previous[j];f.put(char(n));for(int j=0;j<61;j++)if(a[j]!=previous[j]){f.put(char(j));varint(f,a[j]);}previous=a;}
void stats(std::ofstream&f,int id,int ci,int mode,const Oracle&o){f<<id<<','<<ci<<','<<mode<<','<<o.ticks<<','<<o.enq<<','<<o.grants<<','<<o.emits<<','<<o.transfers<<','<<o.blocks<<','<<o.cancels<<','<<o.expires<<','<<o.wus;for(int v:o.sample)f<<','<<v;for(int v:o.peak)f<<','<<v;f<<','<<o.held<<','<<o.heldblock<<'\n';}
void controlheader(std::ofstream&f){f<<"case,mode,p,r,F,K,P,phi,start,t,WUinput,WUbytes";std::string ns="tick,cp,rp,fp,pp,nextid,qlen,qowners,qid0,qid1,qid2,qid3,qid4,qid5,qid6,qid7,R0v,R0owner,R0id,R0byte,R1v,R1owner,R1id,R1byte,outstanding,valid,enabled,bytes,count0,count1,count2,count3,failed,fault";for(std::string pre:{"before_","after_"}){size_t n=0,m;do{m=ns.find(',',n);f<<','<<pre<<ns.substr(n,m-n);n=m+1;}while(m!=std::string::npos);}f<<",evwu,evexpire,evcancel,evenq,enqowner,enqid,enqowner2,enqid2,evattempt,attemptowner,attemptid,evgrant,grantowner,grantid,grantbyte,evemit,emitowner,emitid,emitbyte,evtransfer,transferowner,transferid,transferbyte,evcallback,callbackowner,callbackid,evblock,blockowner,blockid,failtick,failowner,failid\n";}
int main(int argc,char**argv){if(argc<3)return 2;std::string mode=argv[1],outdir=argv[2];try{
 std::vector<Config>cases;for(int p:{2,3,5,7,11,17})for(int r:{5,7})cases.push_back({int(cases.size()),p,r,8*std::lcm(p,r)});
 std::ofstream counters(outdir+"/INDEPENDENT_"+mode+"_COUNTERS.csv");counters<<"query,case,mode,ticks,enqueues,captures,emissions,transfers,backpressure,cancels,expiries,WUs,maxFIFO,maxGlobal,maxLine0,maxLine1,maxLine2,maxLine3,peakFIFO,peakGlobal,peakLine0,peakLine1,peakLine2,peakLine3,heldExpired,heldExpiredBlock\n";
 if(mode=="control"){
  std::ofstream extended(outdir+"/INDEPENDENT_CONTROL_5F.csv");controlheader(extended);
  for(auto c:cases){std::array<int,4>cut={-1,-1,-1,-1};for(int m=-1;m<3;m++){context="control case="+std::to_string(c.id)+" mode="+std::to_string(m);Oracle o(c,c.F+1,1,0,0);DUT d;init(d,o);compare(d,o);
   for(int t=0;t<(m<0?5:3)*c.F;t++){uint32_t bytes=0;int wu=0;for(int j=0;j<4;j++){uint32_t v=m==1?255:m==2?((17*t+73*j)&255):0;bytes|=v<<(8*j);if(m>=0&&t>cut[j])wu|=1<<j;}auto before=o.pack();runstep(d,o,wu,bytes);if(m<0){extended<<c.id<<",-1,"<<c.p<<','<<c.r<<','<<c.F<<','<<c.F+1<<",1,0,0,"<<t<<",0,0";for(auto v:before)extended<<','<<v;for(auto v:o.pack())extended<<','<<v;for(auto v:o.e)extended<<','<<v;extended<<'\n';}if(m<0&&o.e[11]&&cut[o.e[12]]<0)cut[o.e[12]]=t;require(!o.failed,"unexpected miss");}
   stats(counters,-1,c.id,m,o);
  }}
 }else if(mode=="policies"){
  require(argc==4,"policies input required");std::ifstream in(argv[3]);int N;in>>N;std::ofstream trace(outdir+"/INDEPENDENT_POLICY_TICKS.delta",std::ios::binary),result(outdir+"/INDEPENDENT_POLICY_RESULTS.csv");trace.write("HCR5DT01",8);
  result<<"query,case,K,P,phi,line,s,c,h,arm,start,translationFrames,startPhase,expectedSlack,expectedExpiry,actualExpiry,firstFail,failOwner,failId,ticks,captures,emissions,cancels,expiries,WUs,maxFIFO,maxGlobal,maxLine0,maxLine1,maxLine2,maxLine3,fault\n";
  for(int q=0;q<N;q++){int id,ci,K,P,phi,j,s,c,h,arm,start,n,slack,expiry;in>>id>>ci>>K>>P>>phi>>j>>s>>c>>h>>arm>>start>>n>>slack>>expiry;require(bool(in)&&id==q,"policy input");context="policy="+std::to_string(q);Oracle o(cases.at(ci),K,P,phi,start);DUT d;init(d,o);compare(d,o);std::array<uint32_t,61>previous{};u32(trace,q);u32(trace,h-start+1);int ax=-1;
   for(int t=start;t<=h;t++){runstep(d,o,t==arm?1<<j:0,0);delta(trace,previous,o);if(o.e[1]&(1u<<j))ax=t;require(!o.failed||t==h,"early first miss");}
   require(o.failed==(slack<=0),"survive/first miss decision");require(o.wus==1,"exactly one WU");if(o.failed)require(o.e[29]==uint32_t(h)&&o.e[30]==uint32_t(j)&&ax==expiry,"expiry/capture tie");else require(ax==-1,"positive expired");
   result<<q<<','<<ci<<','<<K<<','<<P<<','<<phi<<','<<j<<','<<s<<','<<c<<','<<h<<','<<arm<<','<<start<<','<<n<<','<<start%P<<','<<slack<<','<<expiry<<','<<ax<<','<<(o.failed?int(o.e[29]):-1)<<','<<(o.failed?int(o.e[30]):-1)<<','<<(o.failed?int(o.e[31]):-1)<<','<<o.ticks<<','<<o.grants<<','<<o.emits<<','<<o.cancels<<','<<o.expires<<','<<o.wus;for(int v:o.sample)result<<','<<v;result<<",0\n";stats(counters,q,ci,0,o);
  }require(N==6496,"complete separately declared cycle supplement");std::string extra;require(!(in>>extra),"trailing policy input");
 }else require(false,"mode");std::cout<<"PASS full state/event/byte/timer/ownership transitions "<<mode<<'\n';return 0;
 }catch(const std::exception&e){std::ofstream f(outdir+"/INDEPENDENT_FAILURE.txt");f<<e.what()<<'\n';std::cerr<<e.what()<<'\n';return 1;}}
