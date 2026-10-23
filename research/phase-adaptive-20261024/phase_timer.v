// Four clean receiver lines. This module excludes dirty/owner states and
// protocol queues. read_mask is an atomic local completion/refill harness.
module phase_timer #(parameter N=4, parameter STATIC=0)(
 input clk, input phase_write, input [7:0] phase_k,
 input timer_tick, input [N-1:0] wu_mask, read_mask,
 output reg [N-1:0] read_valid
);
 reg [7:0] config_k=1;
 reg [N-1:0] valid=0, enabled=0;
 reg [7:0] count[0:N-1];
 reg [N-1:0] v_next, e_next;
 reg [7:0] c_next[0:N-1];
 wire [7:0] effective_k = STATIC ? phase_k : (phase_write ? phase_k : config_k);
 wire infinite_load = effective_k==8'hff;
 integer j;
 initial for(j=0;j<N;j=j+1) count[j]=0;
 always @* begin
  v_next=valid; e_next=enabled;
  for(integer i=0;i<N;i=i+1) begin
   c_next[i]=count[i];
   if(wu_mask[i] && v_next[i]) begin
    e_next[i]=!infinite_load; c_next[i]=infinite_load ? 0 : effective_k;
   end
   if(timer_tick && e_next[i]) begin
    if(c_next[i]==1) begin
     v_next[i]=0; e_next[i]=0; c_next[i]=0;
    end else c_next[i]=c_next[i]-1;
   end
   read_valid[i]=v_next[i];
   if(read_mask[i]) begin
    v_next[i]=1; e_next[i]=0; c_next[i]=0;
   end
  end
 end
 always @(posedge clk) begin
  if(!STATIC && phase_write) config_k<=phase_k;
  valid<=v_next; enabled<=e_next;
  for(integer i=0;i<N;i=i+1) count[i]<=c_next[i];
 end
endmodule

// Matched fixed-timeout baseline. The same 8-bit configuration storage is
// loaded at initialization; its write signal is restricted by the system.
module fixed_timer_controller #(parameter N=4)(input clk,input boot_write,input [7:0] boot_k,
 input timer_tick,input [N-1:0] wu_mask,read_mask,output [N-1:0] read_valid);
 reg [7:0] fixed_k=1;
 always @(posedge clk) if(boot_write) fixed_k<=boot_k;
 phase_timer #(.N(N),.STATIC(1)) core(clk,1'b0,fixed_k,timer_tick,wu_mask,read_mask,read_valid);
endmodule

`ifdef FORMAL
module phase_safety(input clk, input write_config,
 input [1:0] select_k, input [3:0] wu, reads);
 wire [7:0] new_k=select_k==0 ? 1 : select_k==1 ? 2 : select_k==2 ? 4 : 255;
 reg [7:0] t=0, k=1;
 reg [1:0] phase=0;
 reg [7:0] deadline[0:3];
 reg [7:0] d_now[0:3];
 reg [7:0] oracle_expiry[0:3];
 reg [7:0] oracle_expiry_next[0:3];
 reg [3:0] oracle_valid=0, oracle_valid_next;
 wire [3:0] read_valid;
 wire [7:0] active_k=write_config ? new_k : k;
 wire [7:0] earliest_arm=active_k==255 ? 255 : t+(phase==0 ? 0 : 3-phase)+(active_k-1)*3;
 wire [7:0] after_read=active_k==255 ? 255 : t+(3-phase)+(active_k-1)*3;
 initial for(integer i=0;i<4;i=i+1) begin
  deadline[i]=0; oracle_expiry[i]=255;
 end
 phase_timer core(clk,write_config,new_k,phase==0,wu,reads,read_valid);
 always @* begin
  oracle_valid_next=oracle_valid;
  for(integer i=0;i<4;i=i+1) begin
   d_now[i]=deadline[i];
   if(write_config && earliest_arm<d_now[i]) d_now[i]=earliest_arm;
   // Time is deliberately bounded below wraparound by the formal run length.
   if(t<80) assert(!reads[i] || !(t<d_now[i]) || read_valid[i]);
   // Independent absolute-expiry specification: no decrementing counter.
   oracle_expiry_next[i]=oracle_expiry[i];
   if(wu[i] && oracle_valid_next[i]) oracle_expiry_next[i]=earliest_arm;
   if(t>=oracle_expiry_next[i]) oracle_valid_next[i]=0;
   if(t<80) assert(read_valid[i]==oracle_valid_next[i]);
   if(reads[i]) begin
    oracle_valid_next[i]=1;oracle_expiry_next[i]=255;
   end
  end
 end
 always @(posedge clk) begin
  t<=t+1;
  phase<=phase==2 ? 0 : phase+1;
  if(write_config) k<=new_k;
  oracle_valid<=oracle_valid_next;
  for(integer i=0;i<4;i=i+1) begin
   deadline[i]<=reads[i] ? after_read : d_now[i];
   oracle_expiry[i]<=oracle_expiry_next[i];
  end
 end
endmodule
`endif
