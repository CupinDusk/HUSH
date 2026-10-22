// Own calendar reference receiver. No native/private HUSH code.
// Blocking assignments intentionally implement PROTOCOL.json's tick order.
module receiver(
 input clk,rst,
 input [15:0] cfgp,cfgr,cfgf,cfgk,cfgperiod,cfgphi,
 input [31:0] cfgstart,
 input [15:0] cfgcp,cfgrp,cfgfp,cfgpp,
 input [3:0] wu,
 input [31:0] wubytes,
 output reg [31:0] tick,nextid,
 output reg [15:0] cp,rp,fp,pp,
 output reg [3:0] valid,enabled,
 output reg [63:0] counts,
 output reg [31:0] bytes,
 output reg [3:0] qlen,
 output [15:0] qowners,
 output [255:0] qids,
 output reg [15:0] outstanding,
 output reg rzero,rone,
 output reg [1:0] ownerzero,ownerone,
 output reg [31:0] idzero,idone,
 output reg [7:0] bytezero,byteone,
 output reg failed,
 output reg [31:0] failtick,failid,fault,
 output reg [1:0] failowner,
 output reg [3:0] evwu,evexpire,evcancel,
 output reg evenq,evattempt,evgrant,evemit,evtransfer,evcallback,evblock,
 output reg [1:0] enqowner,attemptowner,grantowner,emitowner,transferowner,callbackowner,blockowner,
 output reg [31:0] enqid,attemptid,grantid,emitid,transferid,callbackid,blockid,
 output reg [7:0] grantbyte,emitbyte,transferbyte
);
 reg [1:0] qo[0:7]; reg [31:0] qi[0:7];
 genvar g;
 generate for(g=0;g<8;g=g+1)begin
  assign qowners[2*g+:2]=qo[g];assign qids[32*g+:32]=qi[g];
 end endgenerate
 reg entryzero; reg [1:0] releaseowner;reg releasevalid;
 integer j,k; reg [3:0] tokens0,tokens1,tokens2,tokens3;
 always @(posedge clk)begin
  if(rst)begin
   tick=cfgstart;nextid=1;cp=cfgcp;rp=cfgrp;fp=cfgfp;pp=cfgpp;
   valid=15;enabled=0;counts=0;bytes=0;qlen=0;outstanding=0;
   for(j=0;j<8;j=j+1)begin qo[j]=0;qi[j]=0;end
   rzero=0;rone=0;ownerzero=0;ownerone=0;idzero=0;idone=0;bytezero=0;byteone=0;
   failed=0;failtick=0;failid=0;failowner=0;fault=0;
   evwu=0;evexpire=0;evcancel=0;evenq=0;evattempt=0;evgrant=0;evemit=0;evtransfer=0;evcallback=0;evblock=0;
   enqowner=0;attemptowner=0;grantowner=0;emitowner=0;transferowner=0;callbackowner=0;blockowner=0;
   enqid=0;attemptid=0;grantid=0;emitid=0;transferid=0;callbackid=0;blockid=0;
   grantbyte=0;emitbyte=0;transferbyte=0;
   entryzero=0;releaseowner=0;releasevalid=0;tokens0=0;tokens1=0;tokens2=0;tokens3=0;
   if(cfgp<2 || cfgp>17 || (cfgr!=5 && cfgr!=7) || cfgf<44 || cfgf>952 || cfgk==0 || cfgperiod==0 || cfgperiod>68 || cfgphi>=cfgperiod || cfgcp>=cfgp || cfgrp>=cfgr || cfgfp>=cfgf || cfgpp>=cfgperiod)fault=1;
  end else if(!failed && fault==0)begin
   evwu=0;evexpire=0;evcancel=0;evenq=0;evattempt=0;evgrant=0;evemit=0;evtransfer=0;evcallback=0;evblock=0;
   entryzero=rzero;
   for(j=0;j<4;j=j+1)begin
    if(wu[j] && valid[j])begin bytes[8*j+:8]=wubytes[8*j+:8];enabled[j]=1;counts[16*j+:16]=cfgk;evwu[j]=1;end
   end
   if(pp==cfgphi)begin
    for(j=0;j<4;j=j+1)begin
     if(enabled[j])begin
      if(counts[16*j+:16]==0)fault=fault|2;
      else begin counts[16*j+:16]=counts[16*j+:16]-1;if(counts[16*j+:16]==0)begin valid[j]=0;enabled[j]=0;evexpire[j]=1;end end
     end
    end
   end
   releasevalid=0;releaseowner=0;
   if(fp<4)begin releasevalid=1;releaseowner=fp[1:0];end
   if(fp>=40 && fp<44)begin releasevalid=1;releaseowner=fp-40;end
   if(releasevalid)begin
    if(qlen>=8)fault=fault|4;
    else begin
     evenq=1;enqowner=releaseowner;enqid=nextid;
     qo[qlen]=releaseowner;qi[qlen]=nextid;qlen=qlen+1;nextid=nextid+1;
     if(outstanding[4*releaseowner+:4]==15)fault=fault|8;
     outstanding[4*releaseowner+:4]=outstanding[4*releaseowner+:4]+1;
    end
   end
   if(cp==0 && !entryzero && qlen!=0)begin
    evattempt=1;attemptowner=qo[0];attemptid=qi[0];
    if(!valid[qo[0]])begin failed=1;failtick=tick;failowner=qo[0];failid=qi[0];end
    else begin
     evgrant=1;grantowner=qo[0];grantid=qi[0];grantbyte=bytes[8*qo[0]+:8];
     rzero=1;ownerzero=qo[0];idzero=qi[0];bytezero=grantbyte;
     evcancel[qo[0]]=enabled[qo[0]];enabled[qo[0]]=0;counts[16*qo[0]+:16]=0;
     for(j=0;j<7;j=j+1)begin qo[j]=qo[j+1];qi[j]=qi[j+1];end
     qo[7]=0;qi[7]=0;qlen=qlen-1;
    end
   end
   if(!failed)begin
    if(rone)begin
     if(rp==1 || rp==2)begin evemit=1;emitowner=ownerone;emitid=idone;emitbyte=byteone;rone=0;end
     else begin evblock=1;blockowner=ownerone;blockid=idone;end
    end
    if(rzero && !rone)begin
     evtransfer=1;transferowner=ownerzero;transferid=idzero;transferbyte=bytezero;
     rone=1;ownerone=ownerzero;idone=idzero;byteone=bytezero;rzero=0;
    end
    if(evemit)begin
     evcallback=1;callbackowner=emitowner;callbackid=emitid;
     if(outstanding[4*emitowner+:4]==0)fault=fault|16;
     else outstanding[4*emitowner+:4]=outstanding[4*emitowner+:4]-1;
    end
   end
   tokens0=0;tokens1=0;tokens2=0;tokens3=0;
   for(j=0;j<8;j=j+1)begin
    if(j<qlen)begin
     case(qo[j])0:tokens0=tokens0+1;1:tokens1=tokens1+1;2:tokens2=tokens2+1;3:tokens3=tokens3+1;endcase
    end
   end
   if(rzero)case(ownerzero)0:tokens0=tokens0+1;1:tokens1=tokens1+1;2:tokens2=tokens2+1;3:tokens3=tokens3+1;endcase
   if(rone)case(ownerone)0:tokens0=tokens0+1;1:tokens1=tokens1+1;2:tokens2=tokens2+1;3:tokens3=tokens3+1;endcase
   if(qlen>8 || {tokens3,tokens2,tokens1,tokens0}!=outstanding)fault=fault|32;
   if(tick>=32'h7ffffffe || nextid>=32'h7ffffffe)fault=fault|64;
   tick=tick+1;
   if(cp+1==cfgp)cp=0;else cp=cp+1;
   if(rp+1==cfgr)rp=0;else rp=rp+1;
   if(fp+1==cfgf)fp=0;else fp=fp+1;
   if(pp+1==cfgperiod)pp=0;else pp=pp+1;
  end
 end
endmodule
