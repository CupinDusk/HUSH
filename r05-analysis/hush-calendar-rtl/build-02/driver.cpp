// Execute the generated model only. Arithmetic expectations arrive as input.
#include "netlist.cpp"
#include <algorithm>
#include <array>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <stdexcept>
#include <string>
#include <vector>
using Dut=cxxrtl_design::p_receiver;
#define GET(x) uint32_t(d.p_##x.get<uint32_t>())
#define SET(x,v) d.p_##x.set<uint32_t>(v)
struct Config{int id,p,r,F;};
static std::string ctx;
void need(bool x,const std::string&s){if(!x)throw std::runtime_error(ctx+": "+s);}
void edge(Dut&d){SET(clk,0);d.step();SET(clk,1);d.step();SET(clk,0);d.step();}
void reset(Dut&d,const Config&c,int K,int P,int phi,uint32_t start){
 need(P>=1&&P<=68&&phi>=0&&phi<P&&K>=1&&K<=65535,"policy bounds");
 SET(clk,0);SET(cfgp,c.p);SET(cfgr,c.r);SET(cfgf,c.F);SET(cfgk,K);SET(cfgperiod,P);SET(cfgphi,phi);SET(cfgstart,start);
 SET(cfgcp,start%c.p);SET(cfgrp,start%c.r);SET(cfgfp,start%c.F);SET(cfgpp,start%P);SET(wu,0);SET(wubytes,0);SET(rst,1);edge(d);SET(rst,0);d.step();
}
uint32_t count(Dut&d,int j){return (d.p_counts.curr.data[j/2]>>(16*(j%2)))&65535;}
std::vector<uint32_t> state(Dut&d){
 std::vector<uint32_t>v={GET(tick),GET(cp),GET(rp),GET(fp),GET(pp),GET(nextid),GET(qlen),GET(qowners)};
 for(int j=0;j<8;j++)v.push_back(d.p_qids.data[j]);
 for(uint32_t x:{GET(rzero),GET(ownerzero),GET(idzero),GET(bytezero),GET(rone),GET(ownerone),GET(idone),GET(byteone),GET(outstanding),GET(valid),GET(enabled),GET(bytes)})v.push_back(x);
 for(int j=0;j<4;j++)v.push_back(count(d,j));
 v.push_back(GET(failed));v.push_back(GET(fault));return v;
}
std::vector<uint32_t> events(Dut&d){return {GET(evwu),GET(evexpire),GET(evcancel),GET(evenq),GET(enqowner),GET(enqid),GET(enqowner2),GET(enqid2),GET(evattempt),GET(attemptowner),GET(attemptid),GET(evgrant),GET(grantowner),GET(grantid),GET(grantbyte),GET(evemit),GET(emitowner),GET(emitid),GET(emitbyte),GET(evtransfer),GET(transferowner),GET(transferid),GET(transferbyte),GET(evcallback),GET(callbackowner),GET(callbackid),GET(evblock),GET(blockowner),GET(blockid),GET(failtick),GET(failowner),GET(failid)};}
void header(std::ofstream&f){
 f<<"case,mode,p,r,F,K,P,phi,start,t,WUinput,WUbytes";
 std::string names="tick,cp,rp,fp,pp,nextid,qlen,qowners,qid0,qid1,qid2,qid3,qid4,qid5,qid6,qid7,R0v,R0owner,R0id,R0byte,R1v,R1owner,R1id,R1byte,outstanding,valid,enabled,bytes,count0,count1,count2,count3,failed,fault";
 for(std::string prefix:{"before_","after_"}){size_t n=0,m;do{m=names.find(',',n);f<<','<<prefix<<names.substr(n,m-n);n=m+1;}while(m!=std::string::npos);}
 f<<",evwu,evexpire,evcancel,evenq,enqowner,enqid,enqowner2,enqid2,evattempt,attemptowner,attemptid,evgrant,grantowner,grantid,grantbyte,evemit,emitowner,emitid,emitbyte,evtransfer,transferowner,transferid,transferbyte,evcallback,callbackowner,callbackid,evblock,blockowner,blockid,failtick,failowner,failid\n";
}
void raw(std::ofstream&f,const Config&c,int mode,int K,int P,int phi,uint32_t start,uint32_t t,int wu,uint32_t wb,const std::vector<uint32_t>&a,Dut&d){
 f<<c.id<<','<<mode<<','<<c.p<<','<<c.r<<','<<c.F<<','<<K<<','<<P<<','<<phi<<','<<start<<','<<t<<','<<wu<<','<<wb;
 for(auto&v:{a,state(d),events(d)})for(uint32_t x:v)f<<','<<x;f<<'\n';
}
struct Audit{
 std::map<uint32_t,int> requested;std::map<uint32_t,std::pair<int,int>> snapshots;std::set<uint32_t>captured,retired;
 uint64_t ticks=0,grants=0,emits=0,blocks=0,cancels=0,expiries=0,wus=0,transfers=0,enqueues=0;
 int maxq=0,maxglobal=0;std::array<int,4>maxline{};
 void check(Dut&d){
  need(GET(fault)==0,"RTL fault="+std::to_string(GET(fault)));
  if(GET(evenq)){need(!requested.count(GET(enqid))&&!retired.count(GET(enqid)),"ID reuse");requested[GET(enqid)]=GET(enqowner);enqueues++;}
  if(GET(evenq)>1){need(!requested.count(GET(enqid2))&&!retired.count(GET(enqid2)),"second ID reuse");requested[GET(enqid2)]=GET(enqowner2);enqueues++;}
  if(GET(evgrant)){
   uint32_t id=GET(grantid);int j=GET(grantowner),b=GET(grantbyte);need(requested.count(id)&&requested.at(id)==j,"capture owner not requested");need(captured.insert(id).second,"duplicated capture");snapshots[id]={j,b};
   need(!(GET(enabled)&(1u<<j))&&count(d,j)==0,"capture did not cancel");grants++;
  }
  if(GET(evemit)){
   uint32_t id=GET(emitid);need(snapshots.count(id)&&snapshots.at(id)==std::make_pair(int(GET(emitowner)),int(GET(emitbyte))),"immutable emission mismatch");snapshots.erase(id);emits++;
  }
  if(GET(evcallback)){uint32_t id=GET(callbackid);need(GET(evemit)&&id==GET(emitid)&&GET(callbackowner)==GET(emitowner),"callback mismatch");need(requested.erase(id)==1&&retired.insert(id).second,"loss/duplicate callback");}
  std::set<uint32_t>live;std::array<int,4>line{};uint32_t n=GET(qlen),owners=GET(qowners);
  need(n<=8,"FIFO overflow");maxq=std::max(maxq,int(n));
  for(uint32_t i=0;i<n;i++){uint32_t id=d.p_qids.data[i];int j=(owners>>(2*i))&3;need(requested.count(id)&&requested.at(id)==j&&live.insert(id).second,"queue token mismatch");line[j]++;}
  auto snap=[&](int v,int j,uint32_t id,int b){if(v){need(snapshots.count(id)&&snapshots.at(id)==std::make_pair(j,b)&&live.insert(id).second,"snapshot ownership/retention mismatch");line[j]++;}};
  snap(GET(rzero),GET(ownerzero),GET(idzero),GET(bytezero));snap(GET(rone),GET(ownerone),GET(idone),GET(byteone));
  need(live.size()==requested.size()&&snapshots.size()==GET(rzero)+GET(rone),"token conservation");
  for(int j=0;j<4;j++){need(uint32_t(line[j])==((GET(outstanding)>>(4*j))&15),"per-line outstanding mismatch");maxline[j]=std::max(maxline[j],line[j]);}maxglobal=std::max(maxglobal,int(live.size()));
  blocks+=GET(evblock);transfers+=GET(evtransfer);cancels+=__builtin_popcount(GET(evcancel));expiries+=__builtin_popcount(GET(evexpire));wus+=__builtin_popcount(GET(evwu));ticks++;
 }
};
uint32_t pattern(int mode,int t,int j){return mode==0?0:mode==1?255:(17*t+73*j)&255;}
void summaryhead(std::ofstream&f){f<<"case,mode,p,r,F,status,ticks,enqueues,captures,emissions,transfers,backpressure,cancels,expiries,WUs,maxFIFO,maxGlobal,maxLine0,maxLine1,maxLine2,maxLine3,endOutstanding,endR0,endR1,fault\n";}
void summaryrow(std::ofstream&f,const Config&c,int mode,const std::string&status,const Audit&a,Dut&d){f<<c.id<<','<<mode<<','<<c.p<<','<<c.r<<','<<c.F<<','<<status<<','<<a.ticks<<','<<a.enqueues<<','<<a.grants<<','<<a.emits<<','<<a.transfers<<','<<a.blocks<<','<<a.cancels<<','<<a.expiries<<','<<a.wus<<','<<a.maxq<<','<<a.maxglobal;for(int x:a.maxline)f<<','<<x;f<<','<<GET(outstanding)<<','<<GET(rzero)<<','<<GET(rone)<<','<<GET(fault)<<'\n';}
int main(int argc,char**argv){
 if(argc!=4)return 2;std::string mode=argv[1],out=argv[2],input=argv[3];
 try{
  std::vector<Config>cs;for(int p:{2,3,5,7,11,17})for(int r:{5,7})cs.push_back({int(cs.size()),p,r,8*std::lcm(p,r)});
  if(mode=="control"){
   std::ofstream control(out+"/CONTROL_TICKS.csv"),data(out+"/DATA_TICKS.csv"),summ(out+"/RUN_COUNTERS.csv");header(control);header(data);summaryhead(summ);
   for(const Config&c:cs){
    std::array<int,4>cuts={-1,-1,-1,-1};
    for(int m=-1;m<3;m++){
     ctx="case="+std::to_string(c.id)+" mode="+std::to_string(m);Dut d;reset(d,c,c.F+1,1,0,0);Audit a;
     for(int t=0;t<3*c.F;t++){
      need(GET(tick)==uint32_t(t),"clock");auto pre=state(d);int wu=0;uint32_t wb=0;
      for(int j=0;j<4;j++){if(m>=0&&t>cuts[j])wu|=1<<j;wb|=pattern(std::max(m,0),t,j)<<(8*j);}
      SET(wu,wu);SET(wubytes,wb);edge(d);a.check(d);need(!GET(failed),"unexpected failed read");
      if(GET(evgrant)){int j=GET(grantowner);if(m<0&&cuts[j]<0)cuts[j]=t;need(GET(grantbyte)==(m<0||t<=cuts[j]?0:pattern(m,t,j)),"capture byte after WU ordering");}
      raw(m<0?control:data,c,m,c.F+1,1,0,0,t,wu,wb,pre,d);
     }
     summaryrow(summ,c,m,"EXECUTED",a,d);need(a.requested.empty(),"frame does not clear: preserved trace");
    }
   }
   std::cout<<"Executed control plus three byte-pattern runs per applicable controller.\n";
  }else if(mode=="policies"){
   std::ifstream f(input);need(bool(f),"policy input absent");int N;f>>N;std::ofstream po(out+"/POLICY_RESULTS.csv"),trace(out+"/POLICY_TICKS.csv");
   po<<"query,case,K,P,phi,line,s,c,h,arm,start,translationFrames,startPhase,expectedSlack,expectedExpiry,actualExpiry,firstFail,failOwner,failId,ticks,captures,emissions,cancels,expiries,WUs,maxFIFO,maxGlobal,maxLine0,maxLine1,maxLine2,maxLine3,fault\n";header(trace);
   for(int q=0;q<N;q++){
    int id,ci,K,P,phi,j,s,c0,h,arm,start,n,slack,expiry;f>>id>>ci>>K>>P>>phi>>j>>s>>c0>>h>>arm>>start>>n>>slack>>expiry;
    ctx="policy="+std::to_string(q);need(bool(f)&&id==q&&ci>=0&&ci<12,"policy binding");const auto&c=cs[ci];need(start%c.F==0&&arm==s+1&&start<=s&&h<start+2*c.F&&K<=16&&P<=4*c.p,"witness bounds");
    Dut d;reset(d,c,K,P,phi,start);Audit a;int ax=-1,fail=-1,fo=-1,fi=-1;
    for(int t=start;t<=h;t++){
     auto pre=state(d);int wu=t==arm?1<<j:0;SET(wu,wu);SET(wubytes,0);edge(d);a.check(d);
     if(GET(evexpire)&(1u<<j))ax=t;
     // Full lossless actual tick trace, including the first failing tick.
     raw(trace,c,q,K,P,phi,start,t,wu,0,pre,d);
     if(GET(failed)){fail=GET(failtick);fo=GET(failowner);fi=GET(failid);break;}
    }
    po<<q<<','<<ci<<','<<K<<','<<P<<','<<phi<<','<<j<<','<<s<<','<<c0<<','<<h<<','<<arm<<','<<start<<','<<n<<','<<start%P<<','<<slack<<','<<expiry<<','<<ax<<','<<fail<<','<<fo<<','<<fi<<','<<a.ticks<<','<<a.grants<<','<<a.emits<<','<<a.cancels<<','<<a.expiries<<','<<a.wus<<','<<a.maxq<<','<<a.maxglobal;for(int x:a.maxline)po<<','<<x;po<<','<<GET(fault)<<'\n';
    need((fail<0)==(slack>0),"admission mismatch");if(slack<=0)need(fail==h&&fo==j&&ax==expiry,"first-failure witness mismatch");else need(ax==-1,"positive target expired");
   }
   std::cout<<"Executed "<<N<<" generated RTL policy witnesses.\n";
  }else throw std::runtime_error("mode");
  return 0;
 }catch(const std::exception&e){std::ofstream f(out+"/FAILURE.txt");f<<e.what()<<'\n';std::cerr<<e.what()<<'\n';return 1;}
}
