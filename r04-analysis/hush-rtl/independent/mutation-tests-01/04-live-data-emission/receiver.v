// New reference RTL for the specified R03 component, not native HUSH.
// One clk rising edge advances one logical integer tick. Epoch inputs stay fixed.
module receiver(
 input clk, input rst,
 input [2:0] cfgp,cfgr,cfgb,cfgk,
 input [4:0] cfgperiod,cfgphi,
 input [1:0] wu,
 input [7:0] wua,wub,
 output reg [15:0] tick,
 output reg [1:0] pending,waiting,pollen,valid,enabled,
 output reg [15:0] polla,pollb,seqa,seqb,
 output reg [1:0] qlen,
 output reg qowner0,qowner1,
 output reg [15:0] qid0,qid1,
 output reg rzero,rone,ownerzero,ownerone,
 output reg [15:0] idzero,idone,
 output reg [7:0] bytezero,byteone,dataa,datab,
 output reg [2:0] counta,countb,
 output reg failed,failowner,
 output reg [15:0] failtick,
 output reg [15:0] fault,
 output reg [1:0] evwait,evenq,evexpire,evcancel,evwu,
 output reg [15:0] enqida,enqidb,
 output reg evattempt,evgrant,evemit,evtransfer,evcallback,evblock,
 output reg attemptowner,grantowner,emitowner,transferowner,callbackowner,blockowner,
 output reg [15:0] attemptid,grantid,emitid,transferid,callbackid,blockid,
 output reg [7:0] grantbyte,emitbyte,transferbyte
);
 reg [2:0] cachephase,readyphase;
 reg [4:0] expiryphase;
 reg entryzero;
 reg [2:0] tokensa,tokensb;
 always @(posedge clk) begin
  if (rst) begin
   tick=0;pending=0;waiting=0;pollen=3;polla=0;pollb=cfgb;seqa=0;seqb=0;
   qlen=0;qowner0=0;qowner1=0;qid0=0;qid1=0;
   rzero=0;rone=0;ownerzero=0;ownerone=0;idzero=0;idone=0;
   bytezero=0;byteone=0;dataa=0;datab=0;counta=0;countb=0;
   valid=3;enabled=0;failed=0;failowner=0;failtick=0;fault=0;
   cachephase=0;readyphase=0;expiryphase=0;entryzero=0;tokensa=0;tokensb=0;
   evwait=0;evenq=0;evexpire=0;evcancel=0;evwu=0;enqida=0;enqidb=0;
   evattempt=0;evgrant=0;evemit=0;evtransfer=0;evcallback=0;evblock=0;
   attemptowner=0;grantowner=0;emitowner=0;transferowner=0;callbackowner=0;blockowner=0;
   attemptid=0;grantid=0;emitid=0;transferid=0;callbackid=0;blockid=0;
   grantbyte=0;emitbyte=0;transferbyte=0;
   if(cfgp<2 || cfgp>6 || (cfgr!=3 && cfgr!=5) || cfgb>=cfgp || cfgk<1 || cfgk>5 || cfgperiod<1 || cfgperiod>24 || cfgphi>=cfgperiod) fault=16'h0001;
  end else if (!failed && fault==0) begin
   evwait=0;evenq=0;evexpire=0;evcancel=0;evwu=0;
   evattempt=0;evgrant=0;evemit=0;evtransfer=0;evcallback=0;evblock=0;
   entryzero=rzero;
   // WU load precedes decrement, independently for each valid line.
   if(wu[0] && valid[0]) begin dataa=wua;enabled[0]=1;counta=cfgk;evwu[0]=1;end
   if(wu[1] && valid[1]) begin datab=wub;enabled[1]=1;countb=cfgk;evwu[1]=1;end
   if(expiryphase==cfgphi) begin
    if(enabled[0]) begin
     if(counta==0) fault=fault|16'h0002;
     else begin counta=counta-1;if(counta==0)begin valid[0]=0;enabled[0]=0;evexpire[0]=1;end end
    end
    if(enabled[1]) begin
     if(countb==0) fault=fault|16'h0002;
     else begin countb=countb-1;if(countb==0)begin valid[1]=0;enabled[1]=0;evexpire[1]=1;end end
    end
   end
   // Source polls A then B. Absolute poll fields are bounded 16-bit ticks.
   if(pollen[0] && polla==tick) begin
    if(pending[0])begin waiting[0]=1;pollen[0]=0;evwait[0]=1;end
    else begin
     if(seqa==65535 || tick>65515) fault=fault|16'h0004;
     seqa=seqa+1;pending[0]=1;polla=tick+2*cfgp+1;evenq[0]=1;enqida=seqa;
     if(qlen==0)begin qowner0=0;qid0=seqa;end
     else if(qlen==1)begin qowner1=0;qid1=seqa;end
     else fault=fault|16'h0008;
     qlen=qlen+1;
    end
   end
   if(pollen[1] && pollb==tick) begin
    if(pending[1])begin waiting[1]=1;pollen[1]=0;evwait[1]=1;end
    else begin
     if(seqb==65535 || tick>65515) fault=fault|16'h0004;
     seqb=seqb+1;pending[1]=1;pollb=tick+3*cfgp+1;evenq[1]=1;enqidb=seqb;
     if(qlen==0)begin qowner0=1;qid0=seqb;end
     else if(qlen==1)begin qowner1=1;qid1=seqb;end
     else fault=fault|16'h0008;
     qlen=qlen+1;
    end
   end
   if(cachephase==0) begin
    // Permission check is at the actual grant/capture attempt.
    if(!entryzero && qlen!=0) begin
     evattempt=1;attemptowner=qowner0;attemptid=qid0;
     if(!valid[qowner0])begin failed=1;failtick=tick;failowner=qowner0;end
     else begin
      evgrant=1;grantowner=qowner0;grantid=qid0;
      grantbyte=qowner0?datab:dataa;
      rzero=1;ownerzero=qowner0;idzero=qid0;bytezero=grantbyte;
      evcancel[qowner0]=enabled[qowner0];enabled[qowner0]=0;
      if(qowner0)countb=0;else counta=0;
      qowner0=qowner1;qid0=qid1;qlen=qlen-1;
     end
    end
    if(!failed)begin
     // Old R1 emits before R0 transfers. Grant used entry R0 occupancy.
     if(rone)begin
      if(readyphase!=1)begin
       evemit=1;emitowner=ownerone;emitid=idone;emitbyte=ownerone?datab:dataa;rone=0;
      end else begin evblock=1;blockowner=ownerone;blockid=idone;end
     end
     if(rzero && !rone)begin
      rone=1;ownerone=ownerzero;idone=idzero;byteone=bytezero;rzero=0;
      evtransfer=1;transferowner=ownerone;transferid=idone;transferbyte=byteone;
     end
     if(evemit)begin
      evcallback=1;callbackowner=emitowner;callbackid=emitid;
      if(!pending[emitowner])fault=fault|16'h0010;
      pending[emitowner]=0;
      if(waiting[emitowner])begin
       waiting[emitowner]=0;pollen[emitowner]=1;
       if(tick>65515)fault=fault|16'h0004;
       if(emitowner)pollb=tick+3*cfgp+1;else polla=tick+2*cfgp+1;
      end
     end
    end
   end
   // Token conservation, wait/poll discipline and finite-width guards.
   tokensa=0;tokensb=0;
   if(qlen>0)begin if(qowner0)tokensb=tokensb+1;else tokensa=tokensa+1;end
   if(qlen>1)begin if(qowner1)tokensb=tokensb+1;else tokensa=tokensa+1;end
   if(rzero)begin if(ownerzero)tokensb=tokensb+1;else tokensa=tokensa+1;end
   if(rone)begin if(ownerone)tokensb=tokensb+1;else tokensa=tokensa+1;end
   if(qlen>2 || tokensa!=pending[0] || tokensb!=pending[1] || tokensa+tokensb>2)fault=fault|16'h0020;
   if((waiting[0] && (!pending[0] || pollen[0])) || (waiting[1] && (!pending[1] || pollen[1])))fault=fault|16'h0040;
   if((pollen[0] && polla<=tick) || (pollen[1] && pollb<=tick))fault=fault|16'h0080;
   if(tick>=65515)fault=fault|16'h0100;
   tick=tick+1;
   if(cachephase+1==cfgp)cachephase=0;else cachephase=cachephase+1;
   if(readyphase+1==cfgr)readyphase=0;else readyphase=readyphase+1;
   if(expiryphase+1==cfgperiod)expiryphase=0;else expiryphase=expiryphase+1;
  end
 end
endmodule
