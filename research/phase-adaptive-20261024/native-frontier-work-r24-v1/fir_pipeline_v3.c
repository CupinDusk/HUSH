#define _GNU_SOURCE
#include <pthread.h>
#include <stdatomic.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef MARKER_STUB
#include <gem5/m5ops.h>
#endif
static unsigned N, LAGS, STORES, GAP, COST, PATTERN;
static unsigned stage_loads[3];
static _Atomic uint64_t *frame;
static pthread_barrier_t start_barrier, reader_barrier;
typedef struct { _Alignas(64) uint64_t checksum; uint64_t validated; } Result;
static Result results[3];
static uint64_t expected;
static uint64_t value(unsigned i) { return (i*17u+3u)%19u+1u; }
static void emit(unsigned id) {
#ifndef MARKER_STUB
 m5_work_begin(id,0);
 if(id>0 && id<3 && stage_loads[id]!=stage_loads[id-1] && COST) m5_quiesce_cycle(COST);
#else
 (void)id;
#endif
}
static void done(unsigned me) {
#ifndef MARKER_STUB
 m5_work_begin(10+me,0);
#else
 (void)me;
#endif
}
static void phase(unsigned id,unsigned me) {
 pthread_barrier_wait(&reader_barrier);
 if(me==0)emit(id);
 pthread_barrier_wait(&reader_barrier);
}
static uint64_t features(uint64_t *out,unsigned count,uint64_t calibration) {
 uint64_t *norm=malloc(count*sizeof(*norm));
 if(!norm)abort();
 for(unsigned i=0;i<count;i++)norm[i]=out[i]*256u/calibration;
 uint64_t total=0;
 for(unsigned lag=1;lag<=LAGS && lag<count;lag++)
  for(unsigned i=0;i+lag<count;i++)total+=norm[i]*norm[i+lag];
 free(norm);return total;
}
static uint64_t reference(void) {
 const unsigned w[3]={1,2,1};unsigned count=(N-2)*(N-2);
 uint64_t *out=calloc(count,sizeof(*out));if(!out)abort();
 for(unsigned y=0;y<N-2;y++)for(unsigned x=0;x<N-2;x++)
  for(unsigned j=0;j<3;j++)for(unsigned i=0;i<3;i++)
   out[y*(N-2)+x]+=value((y+j)*N+x+i)*w[i]*w[j];
 uint64_t r=features(out,count,value(0));free(out);return r;
}
static void *work(void *arg) {
 unsigned me=(unsigned)(uintptr_t)arg;
 pthread_barrier_wait(&start_barrier);
 if(me==0)emit(0);
 pthread_barrier_wait(&start_barrier);
 if(me==3) {
  uint64_t state=1;unsigned elems=N*N;
  for(unsigned t=0;t<STORES;t++) {
   unsigned index=PATTERN ? t%elems : (t%((elems+7)/8))*8;
   atomic_store_explicit(&frame[index],value(index),memory_order_relaxed);
   for(unsigned g=0;g<GAP;g++) { state=state*1664525u+1013904223u;__asm__ volatile("" : "+r"(state)); }
  }
  done(me);return NULL;
 }
 uint64_t check=0;
 for(unsigned i=0;i<N*N;i++)check+=atomic_load_explicit(&frame[i],memory_order_relaxed);
 results[me].validated=check;
 phase(1,me);
 unsigned count=(N-2)*(N-2);uint64_t *out=calloc(count,sizeof(*out));if(!out)abort();
 const unsigned w[3]={1,2,1};
 for(unsigned y=0;y<N-2;y++)for(unsigned x=0;x<N-2;x++)
  for(unsigned j=0;j<3;j++)for(unsigned i=0;i<3;i++)
   out[y*(N-2)+x]+=atomic_load_explicit(&frame[(y+j)*N+x+i],memory_order_relaxed)*w[i]*w[j];
 phase(2,me);
 uint64_t calibration=atomic_load_explicit(&frame[0],memory_order_relaxed);
 results[me].checksum=features(out,count,calibration);
 free(out);done(me);return NULL;
}
int main(int argc,char **argv) {
 if(argc!=7)return 2;
 N=strtoul(argv[1],0,10);unsigned perline=strtoul(argv[2],0,10);
 LAGS=strtoul(argv[3],0,10);GAP=strtoul(argv[4],0,10);COST=strtoul(argv[5],0,10);PATTERN=strtoul(argv[6],0,10);
 if(N<4 || N>64 || perline<1 || perline>1024 || LAGS<1 || LAGS>64 || COST>64 || PATTERN>1)return 2;
 STORES=((N*N+7)/8)*perline;
 if(posix_memalign((void**)&frame,64,N*N*sizeof(*frame)))return 3;
 uint64_t sum=0;
 for(unsigned i=0;i<N*N;i++){atomic_init(&frame[i],value(i));sum+=value(i);}
 const char *loads=getenv("HUSH_STAGE_LOADS");
 if(!loads || sscanf(loads,"%u,%u,%u",&stage_loads[0],&stage_loads[1],&stage_loads[2])!=3)return 6;
 expected=reference();
 pthread_barrier_init(&start_barrier,0,4);pthread_barrier_init(&reader_barrier,0,3);
 pthread_t threads[3];
 for(unsigned t=1;t<4;t++)if(pthread_create(&threads[t-1],0,work,(void*)(uintptr_t)t))return 4;
 work((void*)0);
 for(unsigned t=0;t<3;t++)pthread_join(threads[t],0);
 emit(99);
 int good=1;
 for(unsigned t=0;t<3;t++)if(results[t].checksum!=expected || results[t].validated!=sum)good=0;
 printf("FIR_PIPELINE %s N=%u stores=%u lags=%u checksum=%llu expected=%llu\n",good?"TEST PASSED":"TEST FAILED",N,STORES,LAGS,(unsigned long long)results[0].checksum,(unsigned long long)expected);
 free(frame);return good?0:5;
}
