// Independent absolute-expiry oracle. Input is a deterministic stream of
// configuration changes, WUs and atomic reads/refills; no model code shared.
#include <cstdio>
#include <cstdint>
#include <climits>
int main() {
 int period,phi;
 if(std::scanf("%d %d",&period,&phi)!=2) return 2;
 long long expiry[4]={LLONG_MAX,LLONG_MAX,LLONG_MAX,LLONG_MAX};
 bool valid[4]={false,false,false,false};
 int k=1,t,write,nk,wu,reads;
 while(std::scanf("%d %d %d %d %d",&t,&write,&nk,&wu,&reads)==5) {
  if(write) k=nk;
  for(int j=0;j<4;++j) {
   if((wu>>j&1) && valid[j]) {
    if(k==255) {expiry[j]=LLONG_MAX;continue;}
    long long next=t;
    while(next%period!=phi)++next;
    for(int c=1;c<k;++c)next+=period;
    expiry[j]=next;
   }
   if(expiry[j]<=t) {valid[j]=false;expiry[j]=LLONG_MAX;}
  }
  int mask=0;
  for(int j=0;j<4;++j) {
   if(valid[j])mask|=1<<j;
   if(reads>>j&1) {valid[j]=true;expiry[j]=LLONG_MAX;}
  }
  std::printf("%d %d\n",t,mask);
 }
}
