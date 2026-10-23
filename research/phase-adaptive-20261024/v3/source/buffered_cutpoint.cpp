#include <cstdio>
#include <algorithm>
static int F(int t,int k,int phi){return t+(phi-t%10+10)%10+(k-1)*10;}
int main(){
 int cases=0,expired_pending=0,bad_payload_detected=0,bad_completion_anchor_detected=0;
 for(int phi=0;phi<10;++phi)for(int next:{1,2,4,8})for(int latency:{1,4,16,32}) {
  bool valid=true,active=false;int count=0,k=4,data=5,payload=-1,expected=-1,d=0;
  int response=5+latency,followup=response+1;
  for(int t=0;t<=followup;++t){
   if(t==6){k=next;d=std::min(d,F(t,k,phi));}
   if(t==7 && valid){data=6;active=true;count=k;}
   if(t%10==phi && active){if(--count==0){active=false;valid=false;}}
   if(t==5){if(!valid)return 2;payload=data;expected=data;active=false;d=F(t+1,k,phi);}
   if(t==response){
    if(payload!=expected)return 3;
    if(!valid)++expired_pending;
    if(data!=expected)++bad_payload_detected;
   }
   if(t==followup){
    if(t<d && !valid)return 4;
    int wrong=F(response+1,k,phi);
    if(t<wrong && !valid)++bad_completion_anchor_detected;
   }
  }
  ++cases;
 }
 std::printf("{\"cases\":%d,\"expired_tag_at_response\":%d,\"payload_errors\":0,\"mutable_payload_faults_detected\":%d,\"completion_anchor_faults_detected\":%d}\n",cases,expired_pending,bad_payload_detected,bad_completion_anchor_detected);
 if(!expired_pending||!bad_payload_detected||!bad_completion_anchor_detected)return 5;
}
