"""Source-loop counts and a retention-only inequality check; no native run."""
from pathlib import Path
import hashlib,json,time
HERE=Path(__file__).resolve().parent
SOURCE=HERE/'fir_pipeline_v3.c'
text=SOURCE.read_text();sha=lambda b:hashlib.sha256(b).hexdigest()
assert 'for(unsigned lag=1;lag<=LAGS && lag<count;lag++)' in text
assert 'for(unsigned i=0;i+lag<count;i++)total+=norm[i]*norm[i+lag];' in text
assert 'for(unsigned i=0;i<count;i++)norm[i]=out[i]*256u/calibration;' in text
assert 'LAGS=strtoul(argv[3],0,10)' in text
def value(i):return (i*17+3)%19+1
rows=[]
for N in [16,28,32]:
 n=N-2;M=n*n;weights=[1,2,1]
 out=[sum(value((y+j)*N+x+i)*weights[i]*weights[j] for j in range(3) for i in range(3))
      for y in range(n) for x in range(n)]
 norm=[x*256//value(0) for x in out]
 for L in [1,16,64]:
  ell=min(L,M-1);A=ell*M-ell*(ell+1)//2
  counted=sum(1 for lag in range(1,L+1) if lag<M for i in range(M-lag))
  assert counted==A
  checksum=sum(norm[i]*norm[i+lag] for lag in range(1,ell+1) for i in range(M-lag))
  rows.append({'N':N,'lags':L,'filtered_outputs_per_reader':M,'effective_lags':ell,
   'FIR_tap_accumulations_per_reader':9*M,
   'FIR_source_weight_multiplications_per_reader':18*M,
   'normalization_divisions_per_reader':M,
   'autocorrelation_product_accumulations_per_reader':A,
   'autocorrelation_source_norm_element_reads_per_reader':2*A,
   'input_validation_loads_per_reader':N*N,'FIR_input_loads_per_reader':9*M,
   'calibration_input_loads_per_reader':1,'total_shared_frame_loads_per_reader':N*N+9*M+1,
   'consumer_count':3,'all_consumers_FIR_taps':27*M,
   'all_consumers_normalization_divisions':3*M,'all_consumers_autocorrelation_pairs':3*A,
   'frame_bytes':8*N*N,'filtered_output_bytes_per_reader':8*M,
   'normalization_buffer_bytes_per_reader':8*M,
   'input_lines':(N*N+7)//8,'producer_stores_at_perline64':((N*N+7)//8)*64,
   'producer_stores_at_perline256':((N*N+7)//8)*256,
   'independent_reference_checksum':checksum,
   'scope':'Executed source-loop arithmetic/data-element counts, not retired machine instructions, cache transactions or WCET; N32 counts do not assert a native N32 run.'})
counts={'source_raw_sha256':sha(SOURCE.read_bytes()),'source_lf_sha256':sha(text.encode()),
 'unchanged_native_binary_sha256':'2240805a3edaceb2741e7b0285f9dd1cdd07188395705322a8ca088206300096',
 'binary_binding':'Existing v3 native binary hash retained in feature-launch observation; this script does not execute or recompile it.',
 'formula':'M=(N-2)^2, ell=min(LAGS,M-1), autocorrelation_pairs=ell*M-ell*(ell+1)/2',
 'counts_per_consumer':True,'rows':rows}
(HERE/'WORK_COUNTS.json').write_text(json.dumps(counts,indent=2)+'\n')
start=time.perf_counter();checks=0;mingap=10**9;maxgap=0
for K in range(1,255):
 for P in range(1,256):
  R=(K-1)*P;continuous=K*P
  for delta in range(P):
   quantized=R+delta
   assert R<=quantized<continuous
   gap=continuous-quantized
   mingap=min(mingap,gap);maxgap=max(maxgap,gap);checks+=1
assert checks==254*255*256//2
check={'scope':'Finite retention-function inequality only; no cache, service, full-system WCET or exact native/RTL equivalence proof.',
 'K_finite':[1,254],'P':[1,255],'all_relative_offsets':True,'checks':checks,'failures':0,
 'coverage_argument':'Every phase/arm residue pair maps to delta=(phi-r) mod P. Enumerating every delta covers all distinct expiry offsets; arm-time translation cancels.',
 'minimum_continuous_minus_quantized':mingap,'maximum_continuous_minus_quantized':maxgap,
 'mapping_P8':[{'native_T':[512,512,64],'finite_K':[64,64,8]},
               {'native_T':[512,512,8],'finite_K':[64,64,1]}],
 'elapsed_seconds':time.perf_counter()-start}
(HERE/'RETENTION_INEQUALITY_CHECK.json').write_text(json.dumps(check,indent=2)+'\n')
print(json.dumps({'work_rows':len(rows),'retention_checks':checks,'failures':0,
 'elapsed_seconds':check['elapsed_seconds']},indent=2))
