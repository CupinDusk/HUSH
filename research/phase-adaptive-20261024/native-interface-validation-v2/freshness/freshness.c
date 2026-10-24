#define _GNU_SOURCE
#include <pthread.h>
#include <stdatomic.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#ifndef MARKER_STUB
#include <gem5/m5ops.h>
#endif
typedef struct { _Alignas(64) _Atomic uint64_t version; } Line;
typedef struct { _Alignas(64) uint64_t checks,bad,last; } Result;
static Line *lines;
static _Alignas(64) _Atomic uint64_t published;
static Result result[3];
static unsigned Q,ROUNDS,READS,GAP,COST,loads[3];
static pthread_barrier_t start,readers;
static void emit(unsigned id){
#ifndef MARKER_STUB
 m5_work_begin(id,0);
 if(id>0 && id<3 && loads[id]!=loads[id-1] && COST)m5_quiesce_cycle(COST);
#else
 (void)id;
#endif
}
static void done(unsigned id){
#ifndef MARKER_STUB
 m5_work_begin(10+id,0);
#else
 (void)id;
#endif
}
static void phase(unsigned id,unsigned me){pthread_barrier_wait(&readers);if(!me)emit(id);pthread_barrier_wait(&readers);}
static void check(unsigned me,uint64_t lower,int final){
 for(unsigned i=0;i<Q;i++){
  uint64_t v=atomic_load_explicit(&lines[i].version,memory_order_relaxed);
  result[me].checks++;if(v<lower || (final && v!=ROUNDS))result[me].bad++;
 }
}
static void *work(void *arg){
 unsigned me=(unsigned)(uintptr_t)arg;
 pthread_barrier_wait(&start);if(me==0)emit(0);pthread_barrier_wait(&start);
 if(me==3){
  uint64_t state=1;
  for(unsigned r=1;r<=ROUNDS;r++){
   for(unsigned i=0;i<Q;i++){
    atomic_store_explicit(&lines[i].version,r,memory_order_relaxed);
    for(unsigned g=0;g<GAP;g++){state=state*1664525u+1013904223u;__asm__ volatile("":"+r"(state));}
   }
   atomic_store_explicit(&published,r,memory_order_release);
  }
  done(me);return NULL;
 }
 for(unsigned r=0;r<READS;r++){
  if(r==16)phase(1,me);if(r==32)phase(2,me);
  uint64_t lower=atomic_load_explicit(&published,memory_order_acquire);
  if(lower<result[me].last)result[me].bad++;
  result[me].last=lower;check(me,lower,0);
 }
 uint64_t final;
 do {final=atomic_load_explicit(&published,memory_order_acquire);}while(final!=ROUNDS);
 check(me,final,1);done(me);return NULL;
}
int main(int argc,char **argv){
 if(argc!=7)return 2;
 Q=strtoul(argv[1],0,10);ROUNDS=strtoul(argv[2],0,10);READS=strtoul(argv[3],0,10);GAP=strtoul(argv[4],0,10);COST=strtoul(argv[5],0,10);
 if((Q!=8 && Q!=64)||ROUNDS!=32||READS!=64||GAP!=16||COST!=8)return 2;
 if(posix_memalign((void**)&lines,64,Q*sizeof(*lines)))return 3;
 for(unsigned i=0;i<Q;i++)atomic_init(&lines[i].version,0);atomic_init(&published,0);
 const char *s=getenv("HUSH_STAGE_LOADS");if(!s || sscanf(s,"%u,%u,%u",&loads[0],&loads[1],&loads[2])!=3)return 6;
 pthread_barrier_init(&start,0,4);pthread_barrier_init(&readers,0,3);pthread_t th[3];
 for(unsigned i=1;i<4;i++)if(pthread_create(&th[i-1],0,work,(void*)(uintptr_t)i))return 4;
 work(0);for(unsigned i=0;i<3;i++)pthread_join(th[i],0);emit(99);
 uint64_t checks=0,bad=0;for(unsigned i=0;i<3;i++){checks+=result[i].checks;bad+=result[i].bad;}
 printf("VERSION_FRESHNESS %s Q=%u checks=%llu stale=%llu final=%llu\n",bad?"TEST FAILED":"TEST PASSED",Q,(unsigned long long)checks,(unsigned long long)bad,(unsigned long long)atomic_load(&published));
 free(lines);return bad?5:0;
}
