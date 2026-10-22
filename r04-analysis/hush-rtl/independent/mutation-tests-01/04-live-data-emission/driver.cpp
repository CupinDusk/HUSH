// Drives the actual Yosys-generated CXXRTL model. No controller transition model.
#include "netlist.cpp"
#include <array>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <map>
#include <numeric>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>
using Dut=cxxrtl_design::p_receiver;
#define GET(x) int(d.p_##x.get<uint32_t>())
#define SET(x,v) d.p_##x.set<uint32_t>(v)
using Row=std::array<int,27>;
struct Case {int index,p,b,r,n,cut[2];std::vector<Row> rows;};
struct Stats {long long ticks=0,grants=0,emits=0,blocks=0,cancels=0,expiries=0,wu=0;int maxqueue=0;};
static std::string context;
void require(bool v,const std::string& why){if(!v)throw std::runtime_error(context+": "+why);}
void clockedge(Dut&d){SET(clk,0);d.step();SET(clk,1);d.step();SET(clk,0);d.step();}
void reset(Dut&d,const Case&c,int K,int P,int phi){
 require(c.p>=2&&c.p<=6&&c.b>=0&&c.b<c.p&&(c.r==3||c.r==5),"configuration");
 require(K>=1&&K<=5&&P>=1&&P<=24&&phi>=0&&phi<P,"counter configuration");
 SET(clk,0);SET(cfgp,c.p);SET(cfgb,c.b);SET(cfgr,c.r);SET(cfgk,K);SET(cfgperiod,P);SET(cfgphi,phi);SET(wu,0);SET(wua,0);SET(wub,0);SET(rst,1);clockedge(d);SET(rst,0);d.step();require(GET(fault)==0,"reset RTL fault");
}
Row before(Dut&d,const Case&c){
 int t=GET(tick),pe=GET(pollen),pn=GET(pending),wa=GET(waiting),len=GET(qlen);
 return {t,t%std::lcm(c.p,c.r),(pe&1)?GET(polla)-t:-1,(pe&2)?GET(pollb)-t:-1,pn&1,(pn>>1)&1,wa&1,(wa>>1)&1,len,len?GET(qowner0):-1,len>1?GET(qowner1):-1,GET(rzero)?GET(ownerzero):-1,GET(rone)?GET(ownerone):-1,0,0,0,0,-1,0,-1,0,-1,0,-1,0,-1,0};
}
void events(Dut&d,Row&v){
 v[13]=GET(evwait);v[14]=GET(evenq);v[15]=(v[14]&1)?GET(enqida):0;v[16]=(v[14]&2)?GET(enqidb):0;
 v[17]=GET(evgrant)?GET(grantowner):-1;v[18]=GET(evgrant)?GET(grantid):0;
 v[19]=GET(evemit)?GET(emitowner):-1;v[20]=GET(evemit)?GET(emitid):0;
 v[21]=GET(evblock)?GET(blockowner):-1;v[22]=GET(evblock)?GET(blockid):0;
 v[23]=GET(evtransfer)?GET(transferowner):-1;v[24]=GET(evtransfer)?GET(transferid):0;
 v[25]=GET(evcallback)?GET(callbackowner):-1;v[26]=GET(evcallback)?GET(callbackid):0;
}
int pattern(int mode,int t,int j){return mode==0?0:mode==1?255:(t*17+j*73)&255;}
void capturecheck(Dut&d,std::map<std::pair<int,int>,int>&snaps,Stats&s,int t,const Case&c,bool data,int mode){
 require(GET(fault)==0,"RTL invariant/width fault "+std::to_string(GET(fault)));
 if(GET(evgrant)){
  int j=GET(grantowner),id=GET(grantid),v=GET(grantbyte);require(!snaps.count({j,id}),"duplicate capture");
  require(v==(data&&t>c.cut[j]?pattern(mode,t,j):0),"captured byte differs from admitted WU word");snaps[{j,id}]=v;
  require(!(GET(enabled)&(1<<j)),"successful capture did not cancel timer");require((j?GET(countb):GET(counta))==0,"capture counter remains nonzero");s.grants++;
 }
 if(GET(evemit)){
  auto key=std::make_pair(GET(emitowner),GET(emitid));require(snaps.count(key),"emission without capture");require(snaps.at(key)==GET(emitbyte),"emitted snapshot changed");snaps.erase(key);s.emits++;
 }
 if(GET(rzero)){
  auto key=std::make_pair(GET(ownerzero),GET(idzero));require(snaps.count(key)&&snaps.at(key)==GET(bytezero),"R0 immutable snapshot mismatch");
 }
 if(GET(rone)){
  auto key=std::make_pair(GET(ownerone),GET(idone));require(snaps.count(key)&&snaps.at(key)==GET(byteone),"R1 immutable snapshot mismatch");
 }
 require(snaps.size()==size_t(GET(rzero)+GET(rone)),"snapshot ownership count");
 if(GET(evblock)){require(GET(rone)&&GET(ownerone)==GET(blockowner)&&GET(idone)==GET(blockid),"blocked register ownership changed");s.blocks++;}
 s.cancels+=__builtin_popcount(unsigned(GET(evcancel)));s.expiries+=__builtin_popcount(unsigned(GET(evexpire)));s.wu+=__builtin_popcount(unsigned(GET(evwu)));s.ticks++;
}
void rawrow(std::ofstream&out,int category,int mode,int index,const Row&v,Dut&d,int wu){
 out<<category<<','<<mode<<','<<index;for(int x:v)out<<','<<x;
 out<<','<<wu<<','<<GET(evwu)<<','<<GET(evexpire)<<','<<GET(evcancel)<<','<<GET(valid)<<','<<GET(enabled)<<','<<GET(counta)<<','<<GET(countb)<<','<<GET(dataa)<<','<<GET(datab)<<','<<GET(grantbyte)<<','<<GET(emitbyte)<<','<<GET(rzero)<<','<<GET(ownerzero)<<','<<GET(idzero)<<','<<GET(bytezero)<<','<<GET(rone)<<','<<GET(ownerone)<<','<<GET(idone)<<','<<GET(byteone)<<','<<GET(fault)<<'\n';
}
void header(std::ofstream&out){out<<"category,pattern,case,t,phase,pollDelayA,pollDelayB,pendingA,pendingB,waitA,waitB,queueLength,queueOwner0,queueOwner1,R0ownerBefore,R1ownerBefore,waitEvents,enqEvents,enqIdA,enqIdB,grantOwner,grantId,emitOwner,emitId,blockedOwner,blockedId,transferOwner,transferId,callbackOwner,callbackId,WUinput,WUaccepted,expired,cancelled,validAfter,enabledAfter,countA,countB,dataA,dataB,grantByte,emitByte,R0valid,R0owner,R0id,R0byte,R1valid,R1owner,R1id,R1byte,fault\n";}
int main(int argc,char**argv){
 if(argc!=3)return 2;std::string inp=argv[1],outp=argv[2];
 try{
  std::ifstream controls(inp+"/controls.txt");require(bool(controls),"control vectors absent");int ncase;controls>>ncase;require(ncase==40,"case count");std::vector<Case>cases;
  for(int z=0;z<ncase;z++){Case c;controls>>c.index>>c.p>>c.b>>c.r>>c.n>>c.cut[0]>>c.cut[1];require(c.index==z&&c.n>0&&c.n<65000,"case vector bound");c.rows.resize(c.n);for(auto&row:c.rows)for(int&x:row)controls>>x;require(bool(controls),"truncated control vectors");cases.push_back(c);}
  std::ofstream raw(outp+"/CONTROL_TICKS.csv"),dataout(outp+"/DATA_TICKS.csv"),caseout(outp+"/CASE_CHECKS.csv"),polout(outp+"/POLICY_CHECKS.csv");header(raw);header(dataout);
  caseout<<"category,pattern,case,ticks,grants,emits,backpressure,cancels,expiries,WUs,maxQueue,fault\n";
  long long controlticks=0,dataticks=0,allgrants=0,allemits=0,allcancels=0,allblocks=0;int bp=0,q2=0;int data_runs=0;
  for(int category=0;category<2;category++)for(int mode=0;mode<(category?3:1);mode++)for(const Case&c:cases){
   context="control case="+std::to_string(c.index)+" category="+std::to_string(category)+" pattern="+std::to_string(mode);Dut d;reset(d,c,5,24,0);Stats s;std::map<std::pair<int,int>,int>snaps;
   for(int t=0;t<c.n;t++){
    Row v=before(d,c);int word=category?((t>c.cut[0]?1:0)|(t>c.cut[1]?2:0)):0;
    SET(wu,word);SET(wua,pattern(mode,t,0));SET(wub,pattern(mode,t,1));clockedge(d);events(d,v);
    for(int k=0;k<27;k++)require(v[k]==c.rows[t][k],"frozen tick mismatch t="+std::to_string(t)+" field="+std::to_string(k)+" actual="+std::to_string(v[k])+" expected="+std::to_string(c.rows[t][k]));
    require(!GET(failed),"unexpected failed read");capturecheck(d,snaps,s,t,c,category,mode);s.maxqueue=std::max(s.maxqueue,v[8]+__builtin_popcount(unsigned(v[14])));rawrow(category?dataout:raw,category,mode,c.index,v,d,word);
   }
   caseout<<category<<','<<mode<<','<<c.index<<','<<s.ticks<<','<<s.grants<<','<<s.emits<<','<<s.blocks<<','<<s.cancels<<','<<s.expiries<<','<<s.wu<<','<<s.maxqueue<<','<<GET(fault)<<'\n';
   if(!category){controlticks+=s.ticks;bp+=s.blocks>0;q2+=s.maxqueue==2;}else{data_runs++;dataticks+=s.ticks;allgrants+=s.grants;allemits+=s.emits;allcancels+=s.cancels;allblocks+=s.blocks;}
  }
  require(controlticks==22823&&bp==26&&q2==40,"control aggregate differs from frozen domain");require(data_runs==120,"snapshot run count");
  std::ifstream policies(inp+"/policies.txt");int npolicy;policies>>npolicy;require(npolicy==37000,"policy count");int positives=0,negatives=0;long long policyticks=0;
  polout<<"query,case,p,b,r,K,P,phi,line,s,c,h,WUtick,expectedPass,expectedExpiry,actualFirstFail,actualFailOwner,actualExpiry,actualTicks,fault,captures,emissions,cancels\n";
  for(int u=0;u<npolicy;u++){
   int id,ci,p,b,r,K,P,phi,j,s0,c0,h,arm,positive,expiry;policies>>id>>ci>>p>>b>>r>>K>>P>>phi>>j>>s0>>c0>>h>>arm>>positive>>expiry;
   context="policy "+std::to_string(id);require(bool(policies)&&id==u&&ci>=0&&ci<40&&h<65000&&j>=0&&j<2&&arm==s0+1,"policy vector bounds");const Case&c=cases[ci];require(c.p==p&&c.b==b&&c.r==r&&P<=4*p&&arm>c.cut[j],"policy binding");
   Dut d;reset(d,c,K,P,phi);Stats st;std::map<std::pair<int,int>,int>snaps;int actualexpiry=-1,actualfail=-1,owner=-1;
   for(int t=0;t<=h;t++){
    require(GET(tick)==t,"RTL tick mismatch");SET(wu,t==arm?1<<j:0);SET(wua,0);SET(wub,0);clockedge(d);
    capturecheck(d,snaps,st,t,c,false,0);
    if(GET(evexpire)&(1<<j))actualexpiry=t;
    if(GET(failed)){actualfail=GET(failtick);owner=GET(failowner);break;}
   }
   polout<<id<<','<<ci<<','<<p<<','<<b<<','<<r<<','<<K<<','<<P<<','<<phi<<','<<j<<','<<s0<<','<<c0<<','<<h<<','<<arm<<','<<positive<<','<<expiry<<','<<actualfail<<','<<owner<<','<<actualexpiry<<','<<st.ticks<<','<<GET(fault)<<','<<st.grants<<','<<st.emits<<','<<st.cancels<<'\n';
   require((actualfail<0)==bool(positive),"admission mismatch");
   if(positive){positives++;require(actualexpiry==-1,"positive target expired");}else{negatives++;require(actualfail==h&&owner==j&&actualexpiry==expiry,"negative first-failure/expiry witness mismatch");}
   policyticks+=st.ticks;
  }
  require(positives==17387&&negatives==19613,"policy aggregate");
  std::ofstream summary(outp+"/RTL_RESULTS.json");summary<<"{\n  \"status\": \"PASS_EXECUTED_YOSYS_GENERATED_REFERENCE_RTL\",\n  \"control_cases\": 40,\n  \"control_ticks\": "<<controlticks<<",\n  \"backpressure_cases\": "<<bp<<",\n  \"queue_two_cases\": "<<q2<<",\n  \"policy_queries\": 37000,\n  \"policy_positive_survivals\": "<<positives<<",\n  \"policy_negative_first_failures\": "<<negatives<<",\n  \"policy_simulated_ticks\": "<<policyticks<<",\n  \"snapshot_runs\": "<<data_runs<<",\n  \"snapshot_ticks\": "<<dataticks<<",\n  \"snapshot_captures\": "<<allgrants<<",\n  \"snapshot_emissions\": "<<allemits<<",\n  \"snapshot_timer_cancels\": "<<allcancels<<",\n  \"snapshot_backpressure_ticks\": "<<allblocks<<",\n  \"mismatches\": 0,\n  \"scope\": \"New reference RTL, finite frozen tests; not native HUSH, coherence, hardware, PPA or universal WU-word exhaustion.\"\n}\n";
  std::cout<<"PASS generated RTL control="<<controlticks<<" policies="<<npolicy<<" snapshot runs="<<data_runs<<"\n";return 0;
 }catch(const std::exception&e){std::ofstream failure(outp+"/SIMULATION_FAILURE.txt");failure<<e.what()<<'\n';std::cerr<<e.what()<<'\n';return 1;}
}
