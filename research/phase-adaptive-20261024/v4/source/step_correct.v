module timer_step_induction(
 input phase_write, input [7:0] phase_k,config_k,
 input [7:0] count_state, period, offset,
 input valid_state,enabled_state,wu,read_request);
 localparam N=1,STATIC=0;
 wire [0:0] valid=valid_state,enabled=enabled_state,wu_mask=wu,read_mask=read_request;
 wire [7:0] count[0:0];assign count[0]=count_state;
 wire timer_tick=offset==0;
 reg [0:0] v_next,e_next,read_valid;
 reg [7:0] c_next[0:0];
 wire [7:0] effective_k=phase_write ? phase_k : config_k;
 wire infinite_load=effective_k==255;
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

 wire arm=wu&&valid_state;
 wire ref_en=arm ? !infinite_load : enabled_state;
 wire [15:0] old_distance={8'b0,offset}+({8'b0,count_state}-16'd1)*{8'b0,period};
 wire [15:0] new_distance={8'b0,offset}+({8'b0,effective_k}-16'd1)*{8'b0,period};
 wire [15:0] distance=arm ? new_distance : old_distance;
 wire ref_valid=valid_state&&!(ref_en&&distance==0);
 wire [7:0] next_offset=offset==0 ? period-8'd1 : offset-8'd1;
 wire [15:0] next_distance={8'b0,next_offset}+({8'b0,c_next[0]}-16'd1)*{8'b0,period};
 always @* begin
  assume(period>0 && offset<period);
  assume(config_k>0 && phase_k>0);
  assume(!enabled_state || (valid_state && count_state>0 && count_state<255));
  assume(enabled_state || count_state==0);
  assert(read_valid[0]==ref_valid);
  assert(v_next[0]==(read_request || ref_valid));
  assert(e_next[0]==(ref_en && ref_valid && !read_request));
  assert(!e_next[0] || (v_next[0] && c_next[0]>0 && c_next[0]<255));
  assert(e_next[0] || c_next[0]==0);
  if(e_next[0]) assert(next_distance==distance-16'd1);
 end
endmodule
