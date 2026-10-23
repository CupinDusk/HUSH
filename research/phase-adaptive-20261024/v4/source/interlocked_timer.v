// Four clean receiver lines. This module excludes dirty/owner states and
// protocol queues. read_mask is an atomic local completion/refill harness.
module interlocked_timer #(parameter N=4, parameter STATIC=0)(
 input clk, input phase_write, input [7:0] phase_k,
 input timer_tick, input [N-1:0] wu_mask, read_mask,
 output reg [N-1:0] read_valid, output wire wu_ready
);
 reg [7:0] config_k=1;
 reg [N-1:0] valid=0, enabled=0;
 reg [7:0] count[0:N-1];
 reg [N-1:0] v_next, e_next;
 reg [7:0] c_next[0:N-1];
 wire [7:0] effective_k = STATIC ? phase_k : config_k;
 assign wu_ready = STATIC ? 1'b1 : !phase_write;
 wire infinite_load = effective_k==8'hff;
 integer j;
 initial for(j=0;j<N;j=j+1) count[j]=0;
 always @* begin
  v_next=valid; e_next=enabled;
  for(integer i=0;i<N;i=i+1) begin
   c_next[i]=count[i];
   if(wu_mask[i] && wu_ready && v_next[i]) begin
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
module fixed_interlocked_controller #(parameter N=4)(input clk,input boot_write,input [7:0] boot_k,
 input timer_tick,input [N-1:0] wu_mask,read_mask,output [N-1:0] read_valid, output wire wu_ready);
 reg [7:0] fixed_k=1;
 always @(posedge clk) if(boot_write) fixed_k<=boot_k;
 interlocked_timer #(.N(N),.STATIC(1)) core(clk,1'b0,fixed_k,timer_tick,wu_mask,read_mask,read_valid,wu_ready);
endmodule

