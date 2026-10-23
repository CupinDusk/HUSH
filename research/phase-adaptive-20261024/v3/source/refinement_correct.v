module old_step(input phase_write,input[7:0]phase_k,config_k,count_state,
 input valid_state,enabled_state,timer_tick,wu,read_request,
 output reg[0:0]v_next,e_next,read_valid,output[7:0]out_count);
 localparam N=1,STATIC=0;
 wire[0:0]valid=valid_state,enabled=enabled_state,wu_mask=wu,read_mask=read_request;
 wire[7:0]count[0:0];assign count[0]=count_state;
 reg[7:0]c_next[0:0];assign out_count=c_next[0];
 wire[7:0]effective_k=phase_write ? phase_k : config_k;
 wire infinite_load=effective_k==255;
 wire wu_ready=!phase_write;
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

endmodule
module new_step(input phase_write,input[7:0]phase_k,config_k,count_state,
 input valid_state,enabled_state,timer_tick,wu,read_request,
 output reg[0:0]v_next,e_next,read_valid,output[7:0]out_count);
 localparam N=1,STATIC=0;
 wire[0:0]valid=valid_state,enabled=enabled_state,wu_mask=wu,read_mask=read_request;
 wire[7:0]count[0:0];assign count[0]=count_state;
 reg[7:0]c_next[0:0];assign out_count=c_next[0];
 wire[7:0]effective_k=config_k;
 wire infinite_load=effective_k==255;
 wire wu_ready=!phase_write;
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

endmodule
module refinement(input phase_write,input[7:0]phase_k,config_k,count_state,
 input valid_state,enabled_state,timer_tick,wu,read_request);
 wire va,ea,ra,vb,eb,rb;wire[7:0]ca,cb;
 old_step a(phase_write,phase_k,config_k,count_state,valid_state,enabled_state,
            timer_tick,wu&&!phase_write,read_request,va,ea,ra,ca);
 new_step b(phase_write,phase_k,config_k,count_state,valid_state,enabled_state,
            timer_tick,wu,read_request,vb,eb,rb,cb);
 always @* assert({va,ea,ra,ca}=={vb,eb,rb,cb});
endmodule
