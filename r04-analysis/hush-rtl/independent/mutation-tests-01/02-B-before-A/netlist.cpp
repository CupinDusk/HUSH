#include <cxxrtl/cxxrtl.h>

#if defined(CXXRTL_INCLUDE_CAPI_IMPL) || \
    defined(CXXRTL_INCLUDE_VCD_CAPI_IMPL)
#include <cxxrtl/capi/cxxrtl_capi.cc>
#endif

#if defined(CXXRTL_INCLUDE_VCD_CAPI_IMPL)
#include <cxxrtl/capi/cxxrtl_capi_vcd.cc>
#endif

using namespace cxxrtl_yosys;

namespace cxxrtl_design {

// \top: 1
// \src: receiver.v:3.1-140.10
struct p_receiver : public module {
	// \src: receiver.v:26.20-26.29
	/*output*/ wire<16> p_attemptid;
	// \src: receiver.v:25.13-25.25
	/*output*/ wire<1> p_attemptowner;
	// \src: receiver.v:26.67-26.74
	/*output*/ wire<16> p_blockid;
	// \src: receiver.v:25.75-25.85
	/*output*/ wire<1> p_blockowner;
	// \src: receiver.v:17.28-17.35
	/*output*/ wire<8> p_byteone;
	// \src: receiver.v:17.19-17.27
	/*output*/ wire<8> p_bytezero;
	// \src: receiver.v:29.12-29.22
	wire<3> p_cachephase;
	// \src: receiver.v:26.56-26.66
	/*output*/ wire<16> p_callbackid;
	// \src: receiver.v:25.61-25.74
	/*output*/ wire<1> p_callbackowner;
	// \src: receiver.v:5.24-5.28
	/*input*/ value<3> p_cfgb;
	// \src: receiver.v:5.29-5.33
	/*input*/ value<3> p_cfgk;
	// \src: receiver.v:5.14-5.18
	/*input*/ value<3> p_cfgp;
	// \src: receiver.v:6.14-6.23
	/*input*/ value<5> p_cfgperiod;
	// \src: receiver.v:6.24-6.30
	/*input*/ value<5> p_cfgphi;
	// \src: receiver.v:5.19-5.23
	/*input*/ value<3> p_cfgr;
	// \src: receiver.v:4.8-4.11
	/*input*/ value<1> p_clk;
	value<1> prev_p_clk;
	bool posedge_p_clk() const {
		return !prev_p_clk.slice<0>().val() && p_clk.slice<0>().val();
	}
	// \src: receiver.v:18.19-18.25
	/*output*/ wire<3> p_counta;
	// \src: receiver.v:18.26-18.32
	/*output*/ wire<3> p_countb;
	// \src: receiver.v:17.36-17.41
	/*output*/ wire<8> p_dataa;
	// \src: receiver.v:17.42-17.47
	/*output*/ wire<8> p_datab;
	// \src: receiver.v:27.29-27.37
	/*output*/ wire<8> p_emitbyte;
	// \src: receiver.v:26.38-26.44
	/*output*/ wire<16> p_emitid;
	// \src: receiver.v:25.37-25.46
	/*output*/ wire<1> p_emitowner;
	// \src: receiver.v:10.48-10.55
	/*output*/ wire<2> p_enabled;
	// \src: receiver.v:23.20-23.26
	/*output*/ wire<16> p_enqida;
	// \src: receiver.v:23.27-23.33
	/*output*/ wire<16> p_enqidb;
	// \src: receiver.v:24.13-24.22
	/*output*/ wire<1> p_evattempt;
	// \src: receiver.v:24.60-24.67
	/*output*/ wire<1> p_evblock;
	// \src: receiver.v:24.49-24.59
	/*output*/ wire<1> p_evcallback;
	// \src: receiver.v:22.41-22.49
	/*output*/ wire<2> p_evcancel;
	// \src: receiver.v:24.31-24.37
	/*output*/ wire<1> p_evemit;
	// \src: receiver.v:22.26-22.31
	/*output*/ wire<2> p_evenq;
	// \src: receiver.v:22.32-22.40
	/*output*/ wire<2> p_evexpire;
	// \src: receiver.v:24.23-24.30
	/*output*/ wire<1> p_evgrant;
	// \src: receiver.v:24.38-24.48
	/*output*/ wire<1> p_evtransfer;
	// \src: receiver.v:22.19-22.25
	/*output*/ wire<2> p_evwait;
	// \src: receiver.v:22.50-22.54
	/*output*/ wire<2> p_evwu;
	// \src: receiver.v:30.12-30.23
	wire<5> p_expiryphase;
	// \src: receiver.v:19.13-19.19
	/*output*/ wire<1> p_failed;
	// \src: receiver.v:19.20-19.29
	/*output*/ wire<1> p_failowner;
	// \src: receiver.v:20.20-20.28
	/*output*/ wire<16> p_failtick;
	// \src: receiver.v:21.20-21.25
	/*output*/ wire<16> p_fault;
	// \src: receiver.v:27.19-27.28
	/*output*/ wire<8> p_grantbyte;
	// \src: receiver.v:26.30-26.37
	/*output*/ wire<16> p_grantid;
	// \src: receiver.v:25.26-25.36
	/*output*/ wire<1> p_grantowner;
	// \src: receiver.v:16.27-16.32
	/*output*/ wire<16> p_idone;
	// \src: receiver.v:16.20-16.26
	/*output*/ wire<16> p_idzero;
	// \src: receiver.v:15.34-15.42
	/*output*/ wire<1> p_ownerone;
	// \src: receiver.v:15.24-15.33
	/*output*/ wire<1> p_ownerzero;
	// \src: receiver.v:10.19-10.26
	/*output*/ wire<2> p_pending;
	// \src: receiver.v:11.20-11.25
	/*output*/ wire<16> p_polla;
	// \src: receiver.v:11.26-11.31
	/*output*/ wire<16> p_pollb;
	// \src: receiver.v:10.35-10.41
	/*output*/ wire<2> p_pollen;
	// \src: receiver.v:14.20-14.24
	/*output*/ wire<16> p_qid0;
	// \src: receiver.v:14.25-14.29
	/*output*/ wire<16> p_qid1;
	// \src: receiver.v:12.19-12.23
	/*output*/ wire<2> p_qlen;
	// \src: receiver.v:13.13-13.20
	/*output*/ wire<1> p_qowner0;
	// \src: receiver.v:13.21-13.28
	/*output*/ wire<1> p_qowner1;
	// \src: receiver.v:29.23-29.33
	wire<3> p_readyphase;
	// \src: receiver.v:15.19-15.23
	/*output*/ wire<1> p_rone;
	// \src: receiver.v:4.19-4.22
	/*input*/ value<1> p_rst;
	// \src: receiver.v:15.13-15.18
	/*output*/ wire<1> p_rzero;
	// \src: receiver.v:11.32-11.36
	/*output*/ wire<16> p_seqa;
	// \src: receiver.v:11.37-11.41
	/*output*/ wire<16> p_seqb;
	// \src: receiver.v:9.20-9.24
	/*output*/ wire<16> p_tick;
	// \src: receiver.v:27.38-27.50
	/*output*/ wire<8> p_transferbyte;
	// \src: receiver.v:26.45-26.55
	/*output*/ wire<16> p_transferid;
	// \src: receiver.v:25.47-25.60
	/*output*/ wire<1> p_transferowner;
	// \src: receiver.v:10.42-10.47
	/*output*/ wire<2> p_valid;
	// \src: receiver.v:10.27-10.34
	/*output*/ wire<2> p_waiting;
	// \src: receiver.v:7.14-7.16
	/*input*/ value<2> p_wu;
	// \src: receiver.v:8.14-8.17
	/*input*/ value<8> p_wua;
	// \src: receiver.v:8.18-8.21
	/*input*/ value<8> p_wub;
	p_receiver(interior) {}
	p_receiver() {
		reset();
	};

	void reset() override;

	bool eval(performer *performer = nullptr) override;

	template<class ObserverT>
	bool commit(ObserverT &observer) {
		bool changed = false;
		if (p_attemptid.commit(observer)) changed = true;
		if (p_attemptowner.commit(observer)) changed = true;
		if (p_blockid.commit(observer)) changed = true;
		if (p_blockowner.commit(observer)) changed = true;
		if (p_byteone.commit(observer)) changed = true;
		if (p_bytezero.commit(observer)) changed = true;
		if (p_cachephase.commit(observer)) changed = true;
		if (p_callbackid.commit(observer)) changed = true;
		if (p_callbackowner.commit(observer)) changed = true;
		prev_p_clk = p_clk;
		if (p_counta.commit(observer)) changed = true;
		if (p_countb.commit(observer)) changed = true;
		if (p_dataa.commit(observer)) changed = true;
		if (p_datab.commit(observer)) changed = true;
		if (p_emitbyte.commit(observer)) changed = true;
		if (p_emitid.commit(observer)) changed = true;
		if (p_emitowner.commit(observer)) changed = true;
		if (p_enabled.commit(observer)) changed = true;
		if (p_enqida.commit(observer)) changed = true;
		if (p_enqidb.commit(observer)) changed = true;
		if (p_evattempt.commit(observer)) changed = true;
		if (p_evblock.commit(observer)) changed = true;
		if (p_evcallback.commit(observer)) changed = true;
		if (p_evcancel.commit(observer)) changed = true;
		if (p_evemit.commit(observer)) changed = true;
		if (p_evenq.commit(observer)) changed = true;
		if (p_evexpire.commit(observer)) changed = true;
		if (p_evgrant.commit(observer)) changed = true;
		if (p_evtransfer.commit(observer)) changed = true;
		if (p_evwait.commit(observer)) changed = true;
		if (p_evwu.commit(observer)) changed = true;
		if (p_expiryphase.commit(observer)) changed = true;
		if (p_failed.commit(observer)) changed = true;
		if (p_failowner.commit(observer)) changed = true;
		if (p_failtick.commit(observer)) changed = true;
		if (p_fault.commit(observer)) changed = true;
		if (p_grantbyte.commit(observer)) changed = true;
		if (p_grantid.commit(observer)) changed = true;
		if (p_grantowner.commit(observer)) changed = true;
		if (p_idone.commit(observer)) changed = true;
		if (p_idzero.commit(observer)) changed = true;
		if (p_ownerone.commit(observer)) changed = true;
		if (p_ownerzero.commit(observer)) changed = true;
		if (p_pending.commit(observer)) changed = true;
		if (p_polla.commit(observer)) changed = true;
		if (p_pollb.commit(observer)) changed = true;
		if (p_pollen.commit(observer)) changed = true;
		if (p_qid0.commit(observer)) changed = true;
		if (p_qid1.commit(observer)) changed = true;
		if (p_qlen.commit(observer)) changed = true;
		if (p_qowner0.commit(observer)) changed = true;
		if (p_qowner1.commit(observer)) changed = true;
		if (p_readyphase.commit(observer)) changed = true;
		if (p_rone.commit(observer)) changed = true;
		if (p_rzero.commit(observer)) changed = true;
		if (p_seqa.commit(observer)) changed = true;
		if (p_seqb.commit(observer)) changed = true;
		if (p_tick.commit(observer)) changed = true;
		if (p_transferbyte.commit(observer)) changed = true;
		if (p_transferid.commit(observer)) changed = true;
		if (p_transferowner.commit(observer)) changed = true;
		if (p_valid.commit(observer)) changed = true;
		if (p_waiting.commit(observer)) changed = true;
		return changed;
	}

	bool commit() override {
		observer observer;
		return commit<>(observer);
	}

	void debug_eval();

	void debug_info(debug_items *items, debug_scopes *scopes, std::string path, metadata_map &&cell_attrs = {}) override;
}; // struct p_receiver

void p_receiver::reset() {
}

bool p_receiver::eval(performer *performer) {
	bool converged = true;
	bool posedge_p_clk = this->posedge_p_clk();
	// \src: receiver.v:33.2-139.5
	value<16> i_11_5c_fault_5b_15_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<16> i_12_5c_fault_5b_15_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<16> i_13_5c_fault_5b_15_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<16> i_14_5c_fault_5b_15_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<16> i_16_5c_fault_5b_15_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<16> i_17_5c_fault_5b_15_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<16> i_18_5c_fault_5b_15_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<16> i_19_5c_fault_5b_15_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<16> i_22_5c_fault_5b_15_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<16> i_23_5c_fault_5b_15_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<16> i_24_5c_fault_5b_15_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<16> i_25_5c_fault_5b_15_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<16> i_26_5c_fault_5b_15_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<16> i_27_5c_fault_5b_15_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<16> i_28_5c_fault_5b_15_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<2> i_2_5c_evenq_5b_1_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<2> i_2_5c_evwait_5b_1_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<2> i_2_5c_evwu_5b_1_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<3> i_3_5c_counta_5b_2_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<3> i_3_5c_countb_5b_2_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<8> i_3_5c_dataa_5b_7_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<8> i_3_5c_datab_5b_7_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<1> i_3_5c_enabled_5b_0_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<2> i_3_5c_evexpire_5b_1_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<1> i_3_5c_ownerone_5b_0_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<1> i_3_5c_ownerzero_5b_0_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<1> i_3_5c_pending_5b_1_3a_1_5d_;
	// \src: receiver.v:33.2-139.5
	value<16> i_3_5c_polla_5b_15_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<16> i_3_5c_pollb_5b_15_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<1> i_3_5c_pollen_5b_1_3a_1_5d_;
	// \src: receiver.v:33.2-139.5
	value<16> i_3_5c_qid0_5b_15_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<16> i_3_5c_qid1_5b_15_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<2> i_3_5c_qlen_5b_1_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<1> i_3_5c_qowner0_5b_0_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<1> i_3_5c_qowner1_5b_0_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<1> i_3_5c_rone_5b_0_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<1> i_3_5c_rzero_5b_0_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<3> i_3_5c_tokensa_5b_2_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<3> i_3_5c_tokensb_5b_2_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<2> i_3_5c_valid_5b_1_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<1> i_3_5c_waiting_5b_1_3a_1_5d_;
	// \src: receiver.v:33.2-139.5
	value<8> i_4_5c_bytezero_5b_7_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<3> i_4_5c_counta_5b_2_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<3> i_4_5c_countb_5b_2_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<1> i_4_5c_enabled_5b_1_3a_1_5d_;
	// \src: receiver.v:33.2-139.5
	value<1> i_4_5c_failed_5b_0_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<16> i_4_5c_fault_5b_15_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<16> i_4_5c_idzero_5b_15_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<1> i_4_5c_ownerzero_5b_0_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<1> i_4_5c_rzero_5b_0_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<16> i_5_5c_emitid_5b_15_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<1> i_5_5c_emitowner_5b_0_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<2> i_5_5c_enabled_5b_1_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<1> i_5_5c_evblock_5b_0_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<1> i_5_5c_evemit_5b_0_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<16> i_5_5c_fault_5b_15_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<1> i_5_5c_pending_5b_0_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<16> i_5_5c_polla_5b_15_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<16> i_5_5c_pollb_5b_15_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<1> i_5_5c_pollen_5b_0_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<2> i_5_5c_qlen_5b_1_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<1> i_5_5c_rone_5b_0_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<3> i_5_5c_tokensa_5b_2_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<3> i_5_5c_tokensb_5b_2_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<1> i_5_5c_waiting_5b_0_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<16> i_6_5c_fault_5b_15_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<16> i_6_5c_qid0_5b_15_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<1> i_6_5c_qowner0_5b_0_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<16> i_7_5c_fault_5b_15_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<2> i_7_5c_pending_5b_1_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<2> i_7_5c_pollen_5b_1_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<16> i_7_5c_qid1_5b_15_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<2> i_7_5c_qlen_5b_1_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<1> i_7_5c_qowner1_5b_0_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<3> i_7_5c_tokensa_5b_2_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<3> i_7_5c_tokensb_5b_2_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<2> i_7_5c_waiting_5b_1_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<16> i_8_5c_fault_5b_15_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<16> i_9_5c_fault_5b_15_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<1> i_9_5c_qowner0_5b_0_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<3> i_9_5c_tokensa_5b_2_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<3> i_9_5c_tokensb_5b_2_3a_0_5d_;
	value<16> i_add_24_receiver_2e_v_3a_119_24_156__Y;
	value<16> i_add_24_receiver_2e_v_3a_119_24_159__Y;
	value<4> i_add_24_receiver_2e_v_3a_135_24_196__Y;
	value<4> i_add_24_receiver_2e_v_3a_136_24_199__Y;
	value<6> i_add_24_receiver_2e_v_3a_137_24_202__Y;
	value<16> i_add_24_receiver_2e_v_3a_69_24_61__Y;
	value<16> i_add_24_receiver_2e_v_3a_80_24_75__Y;
	// \src: receiver.v:119.57-119.63
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4759;
	// \src: receiver.v:119.32-119.38
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4762;
	// \src: receiver.v:117.29-117.48
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4763;
	// \src: receiver.v:117.8-117.28
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4765;
	// \src: receiver.v:115.7-115.27
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4767;
	// \src: receiver.v:115.7-115.27
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4768;
	// \src: receiver.v:115.7-115.27
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4770;
	// \src: receiver.v:115.7-115.27
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4771;
	// \src: receiver.v:98.38-98.44
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4772;
	// \src: receiver.v:96.42-96.60
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4773;
	// \src: receiver.v:96.42-96.60
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4774;
	// \src: receiver.v:96.42-96.60
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4776;
	// \src: receiver.v:96.42-96.60
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4777;
	value<3> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4778;
	value<3> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4780;
	// \src: receiver.v:61.24-61.32
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4784;
	// \src: receiver.v:57.24-57.32
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4785;
	// \src: receiver.v:54.7-54.26
	value<1> i_eq_24_receiver_2e_v_3a_54_24_46__Y;
	// \src: receiver.v:56.9-56.18
	value<1> i_eq_24_receiver_2e_v_3a_56_24_47__Y;
	// \src: receiver.v:57.36-57.45
	value<1> i_eq_24_receiver_2e_v_3a_57_24_50__Y;
	// \src: receiver.v:60.9-60.18
	value<1> i_eq_24_receiver_2e_v_3a_60_24_51__Y;
	// \src: receiver.v:61.36-61.45
	value<1> i_eq_24_receiver_2e_v_3a_61_24_54__Y;
	// \src: receiver.v:70.9-70.16
	value<1> i_eq_24_receiver_2e_v_3a_70_24_65__Y;
	// \src: receiver.v:71.14-71.21
	value<1> i_eq_24_receiver_2e_v_3a_71_24_66__Y;
	// \src: receiver.v:81.9-81.16
	value<1> i_eq_24_receiver_2e_v_3a_81_24_79__Y;
	// \src: receiver.v:82.14-82.21
	value<1> i_eq_24_receiver_2e_v_3a_82_24_80__Y;
	// \src: receiver.v:87.7-87.20
	value<1> i_eq_24_receiver_2e_v_3a_87_24_83__Y;
	// \src: receiver.v:118.11-118.21
	value<1> i_gt_24_receiver_2e_v_3a_118_24_152__Y;
	// \src: receiver.v:126.7-126.13
	value<1> i_gt_24_receiver_2e_v_3a_126_24_160__Y;
	// \src: receiver.v:127.7-127.13
	value<1> i_gt_24_receiver_2e_v_3a_127_24_163__Y;
	// \src: receiver.v:108.9-108.23
	value<1> i_logic__and_24_receiver_2e_v_3a_108_24_121__Y;
	// \src: receiver.v:47.16-47.35
	value<1> i_logic__and_24_receiver_2e_v_3a_47_24_38__Y;
	// \src: receiver.v:52.7-52.24
	value<1> i_logic__and_24_receiver_2e_v_3a_52_24_44__Y;
	// \src: receiver.v:53.7-53.24
	value<1> i_logic__and_24_receiver_2e_v_3a_53_24_45__Y;
	// \src: receiver.v:65.7-65.31
	value<1> i_logic__and_24_receiver_2e_v_3a_65_24_56__Y;
	// \src: receiver.v:76.7-76.31
	value<1> i_logic__and_24_receiver_2e_v_3a_76_24_70__Y;
	// \src: receiver.v:89.8-89.29
	value<1> i_logic__and_24_receiver_2e_v_3a_89_24_91__Y;
	// \src: receiver.v:104.10-104.23
	value<1> i_ne_24_receiver_2e_v_3a_104_24_119__Y;
	// \src: receiver.v:115.7-115.27
	value<2> i_neg_24_receiver_2e_v_3a_115_24_128__Y;
	// \src: receiver.v:96.7-96.41
	value<2> i_neg_24_receiver_2e_v_3a_96_24_104__Y;
	value<16> i_procmux_24_2749__Y;
	value<16> i_procmux_24_3187__Y;
	value<16> i_procmux_24_3817__Y;
	value<1> i_procmux_24_442__CMP;
	value<16> i_procmux_24_627__Y;
	// \src: receiver.v:91.15-91.24
	value<1> i_shiftx_24_receiver_2e_v_3a_91_24_94__Y;
	// \src: receiver.v:94.17-94.36
	value<8> i_ternary_24_receiver_2e_v_3a_94_24_98__Y;
	// \src: receiver.v:52.7-52.24
	// cell $logic_and$receiver.v:52$44
	i_logic__and_24_receiver_2e_v_3a_52_24_44__Y = logic_and<1>(p_wu.slice<0>().val(), p_valid.curr.slice<0>().val());
	// cells $logic_and$receiver.v:47$38 $logic_not$receiver.v:47$36 $eq$receiver.v:47$37
	i_logic__and_24_receiver_2e_v_3a_47_24_38__Y = logic_and<1>(logic_not<1>(p_failed.curr), logic_not<1>(p_fault.curr));
	// cells $procmux$4004 $procmux$4001 $procmux$3999
	i_3_5c_counta_5b_2_3a_0_5d_ = (p_rst ? value<3>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_logic__and_24_receiver_2e_v_3a_52_24_44__Y ? p_cfgk : p_counta.curr) : value<3>{0u}));
	// \src: receiver.v:56.9-56.18
	// cell $eq$receiver.v:56$47
	i_eq_24_receiver_2e_v_3a_56_24_47__Y = logic_not<1>(i_3_5c_counta_5b_2_3a_0_5d_);
	// cells $procmux$4013 $procmux$4010 $procmux$4008
	i_3_5c_enabled_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_logic__and_24_receiver_2e_v_3a_52_24_44__Y ? value<1>{0x1u} : p_enabled.curr.slice<0>().val()) : value<1>{0u}));
	// \full_case: 1
	// \src: receiver.v:56.9-56.18|receiver.v:56.6-57.97
	// cell $procmux$3731
	i_6_5c_fault_5b_15_3a_0_5d_.slice<1,0>() = (i_eq_24_receiver_2e_v_3a_56_24_47__Y ? value<1>{0x1u}.concat(p_fault.curr.slice<0>()).val() : p_fault.curr.slice<1,0>().val());
	// connection
	i_6_5c_fault_5b_15_3a_0_5d_.slice<15,2>() = p_fault.curr.slice<15,2>().val();
	// \src: receiver.v:53.7-53.24
	// cell $logic_and$receiver.v:53$45
	i_logic__and_24_receiver_2e_v_3a_53_24_45__Y = logic_and<1>(p_wu.slice<1>().val(), p_valid.curr.slice<1>().val());
	// \full_case: 1
	// \src: receiver.v:55.8-55.18|receiver.v:55.5-58.8
	// cell $procmux$3817
	i_procmux_24_3817__Y.slice<1,0>() = (i_3_5c_enabled_5b_0_3a_0_5d_ ? i_6_5c_fault_5b_15_3a_0_5d_.slice<1,0>().val() : p_fault.curr.slice<1,0>().val());
	// \src: receiver.v:54.7-54.26
	// cell $eq$receiver.v:54$46
	i_eq_24_receiver_2e_v_3a_54_24_46__Y = eq_uu<1>(p_expiryphase.curr, p_cfgphi);
	// connection
	i_procmux_24_3817__Y.slice<15,2>() = p_fault.curr.slice<15,2>().val();
	// cells $procmux$3968 $procmux$3965 $procmux$3963
	i_3_5c_countb_5b_2_3a_0_5d_ = (p_rst ? value<3>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_logic__and_24_receiver_2e_v_3a_53_24_45__Y ? p_cfgk : p_countb.curr) : value<3>{0u}));
	// cells $procmux$3824 $procmux$3821 $procmux$3819
	i_5_5c_fault_5b_15_3a_0_5d_ = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_54_24_46__Y ? p_fault.curr.slice<15,2>().concat(i_procmux_24_3817__Y.slice<1,0>()).val() : value<16>{0u}) : value<16>{0u}));
	// \src: receiver.v:60.9-60.18
	// cell $eq$receiver.v:60$51
	i_eq_24_receiver_2e_v_3a_60_24_51__Y = logic_not<1>(i_3_5c_countb_5b_2_3a_0_5d_);
	// cells $procmux$3977 $procmux$3974 $procmux$3972
	i_4_5c_enabled_5b_1_3a_1_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_logic__and_24_receiver_2e_v_3a_53_24_45__Y ? value<1>{0x1u} : p_enabled.curr.slice<1>().val()) : value<1>{0u}));
	// \full_case: 1
	// \src: receiver.v:60.9-60.18|receiver.v:60.6-61.97
	// cell $procmux$3542
	i_8_5c_fault_5b_15_3a_0_5d_.slice<1,0>() = (i_eq_24_receiver_2e_v_3a_60_24_51__Y ? value<1>{0x1u}.concat(i_5_5c_fault_5b_15_3a_0_5d_.slice<0>()).val() : i_5_5c_fault_5b_15_3a_0_5d_.slice<1,0>().val());
	// connection
	i_8_5c_fault_5b_15_3a_0_5d_.slice<15,2>() = i_5_5c_fault_5b_15_3a_0_5d_.slice<15,2>().val();
	// \full_case: 1
	// \src: receiver.v:59.8-59.18|receiver.v:59.5-62.8
	// cell $procmux$3628
	i_7_5c_fault_5b_15_3a_0_5d_.slice<1,0>() = (i_4_5c_enabled_5b_1_3a_1_5d_ ? i_8_5c_fault_5b_15_3a_0_5d_.slice<1,0>().val() : i_5_5c_fault_5b_15_3a_0_5d_.slice<1,0>().val());
	// connection
	i_7_5c_fault_5b_15_3a_0_5d_.slice<15,2>() = i_5_5c_fault_5b_15_3a_0_5d_.slice<15,2>().val();
	// cells $logic_and$receiver.v:65$56 $eq$receiver.v:65$55
	i_logic__and_24_receiver_2e_v_3a_65_24_56__Y = logic_and<1>(p_pollen.curr.slice<1>().val(), eq_uu<1>(p_pollb.curr, p_tick.curr));
	// \src: receiver.v:71.14-71.21
	// cell $eq$receiver.v:71$66
	i_eq_24_receiver_2e_v_3a_71_24_66__Y = eq_uu<1>(p_qlen.curr, value<1>{0x1u});
	// \src: receiver.v:70.9-70.16
	// cell $eq$receiver.v:70$65
	i_eq_24_receiver_2e_v_3a_70_24_65__Y = logic_not<1>(p_qlen.curr);
	// \src: receiver.v:118.11-118.21
	// cell $gt$receiver.v:118$152
	i_gt_24_receiver_2e_v_3a_118_24_152__Y = gt_uu<1>(p_tick.curr, value<16>{0xffebu});
	// \src: receiver.v:61.24-61.32
	// cell $sub$receiver.v:61$53
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4784.slice<2,0>() = sub_uu<3>(i_3_5c_countb_5b_2_3a_0_5d_, value<1>{0x1u});
	// \src: receiver.v:57.24-57.32
	// cell $sub$receiver.v:57$49
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4785.slice<2,0>() = sub_uu<3>(i_3_5c_counta_5b_2_3a_0_5d_, value<1>{0x1u});
	// cells $procmux$3878 $procmux$3875 $procmux$3873
	i_4_5c_fault_5b_15_3a_0_5d_ = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_54_24_46__Y ? i_5_5c_fault_5b_15_3a_0_5d_.slice<15,2>().concat(i_7_5c_fault_5b_15_3a_0_5d_.slice<1,0>()).val() : p_fault.curr) : value<16>{0u}));
	// \src: receiver.v:61.36-61.45
	// cell $eq$receiver.v:61$54
	i_eq_24_receiver_2e_v_3a_61_24_54__Y = logic_not<1>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4784.slice<2,0>().val());
	// \src: receiver.v:57.36-57.45
	// cell $eq$receiver.v:57$50
	i_eq_24_receiver_2e_v_3a_57_24_50__Y = logic_not<1>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4785.slice<2,0>().val());
	// cells $procmux$3446 $procmux$3443 $procmux$3441 $procmux$3322 $add$receiver.v:73$68
	i_3_5c_qlen_5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_logic__and_24_receiver_2e_v_3a_65_24_56__Y ? (p_pending.curr.slice<1>().val() ? p_qlen.curr : add_uu<2>(p_qlen.curr, value<1>{0x1u})) : p_qlen.curr) : value<2>{0u}));
	// cells $procmux$3187 $logic_or$receiver.v:68$59 $eq$receiver.v:68$57
	i_procmux_24_3187__Y.slice<2,0>() = (logic_or<1>(eq_uu<1>(p_seqb.curr, value<16>{0xffffu}), i_gt_24_receiver_2e_v_3a_118_24_152__Y) ? value<1>{0x1u}.concat(i_4_5c_fault_5b_15_3a_0_5d_.slice<1,0>()).val() : i_4_5c_fault_5b_15_3a_0_5d_.slice<2,0>().val());
	// connection
	i_procmux_24_3187__Y.slice<15,3>() = i_4_5c_fault_5b_15_3a_0_5d_.slice<15,3>().val();
	// cells $procmux$3432 $procmux$3310 $procmux$3127
	i_3_5c_qowner0_5b_0_3a_0_5d_ = (i_logic__and_24_receiver_2e_v_3a_65_24_56__Y ? (p_pending.curr.slice<1>().val() ? p_qowner0.curr : (i_eq_24_receiver_2e_v_3a_70_24_65__Y ? value<1>{0x1u} : p_qowner0.curr)) : p_qowner0.curr);
	// \src: receiver.v:81.9-81.16
	// cell $eq$receiver.v:81$79
	i_eq_24_receiver_2e_v_3a_81_24_79__Y = logic_not<1>(i_3_5c_qlen_5b_1_3a_0_5d_);
	// cells $procmux$3423 $procmux$3298 $procmux$3172 $procmux$3076
	i_3_5c_qowner1_5b_0_3a_0_5d_ = (i_logic__and_24_receiver_2e_v_3a_65_24_56__Y ? (p_pending.curr.slice<1>().val() ? p_qowner1.curr : (i_eq_24_receiver_2e_v_3a_70_24_65__Y ? p_qowner1.curr : (i_eq_24_receiver_2e_v_3a_71_24_66__Y ? value<1>{0x1u} : p_qowner1.curr))) : p_qowner1.curr);
	// \src: receiver.v:82.14-82.21
	// cell $eq$receiver.v:82$80
	i_eq_24_receiver_2e_v_3a_82_24_80__Y = eq_uu<1>(i_3_5c_qlen_5b_1_3a_0_5d_, value<1>{0x1u});
	// cells $logic_and$receiver.v:76$70 $eq$receiver.v:76$69
	i_logic__and_24_receiver_2e_v_3a_76_24_70__Y = logic_and<1>(p_pollen.curr.slice<0>().val(), eq_uu<1>(p_polla.curr, p_tick.curr));
	// cells $procmux$3197 $procmux$3194 $procmux$3192 $procmux$3190
	i_11_5c_fault_5b_15_3a_0_5d_ = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_logic__and_24_receiver_2e_v_3a_65_24_56__Y ? (p_pending.curr.slice<1>().val() ? value<16>{0u} : i_4_5c_fault_5b_15_3a_0_5d_.slice<15,3>().concat(i_procmux_24_3187__Y.slice<2,0>()).val()) : value<16>{0u}) : value<16>{0u}));
	// \full_case: 1
	// \src: receiver.v:71.14-71.21|receiver.v:71.11-72.32
	// cell $procmux$3094
	i_13_5c_fault_5b_15_3a_0_5d_.slice<3,0>() = (i_eq_24_receiver_2e_v_3a_71_24_66__Y ? i_11_5c_fault_5b_15_3a_0_5d_.slice<3,0>().val() : value<1>{0x1u}.concat(i_11_5c_fault_5b_15_3a_0_5d_.slice<2,0>()).val());
	// connection
	i_13_5c_fault_5b_15_3a_0_5d_.slice<15,4>() = i_11_5c_fault_5b_15_3a_0_5d_.slice<15,4>().val();
	// cells $procmux$3932 $procmux$3929 $procmux$3927 $procmux$3664 $procmux$3602 $procmux$3524
	i_3_5c_valid_5b_1_3a_0_5d_.slice<1>() = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_54_24_46__Y ? (i_4_5c_enabled_5b_1_3a_1_5d_ ? (i_eq_24_receiver_2e_v_3a_60_24_51__Y ? p_valid.curr.slice<1>().val() : (i_eq_24_receiver_2e_v_3a_61_24_54__Y ? value<1>{0u} : p_valid.curr.slice<1>().val())) : p_valid.curr.slice<1>().val()) : p_valid.curr.slice<1>().val()) : value<1>{0u}));
	// cells $procmux$3905 $procmux$3902 $procmux$3900 $procmux$3853 $procmux$3791 $procmux$3713
	i_3_5c_valid_5b_1_3a_0_5d_.slice<0>() = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_54_24_46__Y ? (i_3_5c_enabled_5b_0_3a_0_5d_ ? (i_eq_24_receiver_2e_v_3a_56_24_47__Y ? p_valid.curr.slice<0>().val() : (i_eq_24_receiver_2e_v_3a_57_24_50__Y ? value<1>{0u} : p_valid.curr.slice<0>().val())) : p_valid.curr.slice<0>().val()) : p_valid.curr.slice<0>().val()) : value<1>{0u}));
	// cells $procmux$2999 $procmux$2996 $procmux$2994 $procmux$2872 $procmux$2689
	i_6_5c_qowner0_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_logic__and_24_receiver_2e_v_3a_76_24_70__Y ? (p_pending.curr.slice<0>().val() ? i_3_5c_qowner0_5b_0_3a_0_5d_ : (i_eq_24_receiver_2e_v_3a_81_24_79__Y ? value<1>{0u} : i_3_5c_qowner0_5b_0_3a_0_5d_)) : i_3_5c_qowner0_5b_0_3a_0_5d_) : value<1>{0u}));
	// cells $procmux$3008 $procmux$3005 $procmux$3003 $procmux$2884 $add$receiver.v:84$82
	i_5_5c_qlen_5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_logic__and_24_receiver_2e_v_3a_76_24_70__Y ? (p_pending.curr.slice<0>().val() ? i_3_5c_qlen_5b_1_3a_0_5d_ : add_uu<2>(i_3_5c_qlen_5b_1_3a_0_5d_, value<1>{0x1u})) : i_3_5c_qlen_5b_1_3a_0_5d_) : value<2>{0u}));
	// \full_case: 1
	// \src: receiver.v:70.9-70.16|receiver.v:70.6-72.32
	// cell $procmux$3142
	i_12_5c_fault_5b_15_3a_0_5d_.slice<3,0>() = (i_eq_24_receiver_2e_v_3a_70_24_65__Y ? i_11_5c_fault_5b_15_3a_0_5d_.slice<3,0>().val() : i_13_5c_fault_5b_15_3a_0_5d_.slice<3,0>().val());
	// connection
	i_12_5c_fault_5b_15_3a_0_5d_.slice<15,4>() = i_11_5c_fault_5b_15_3a_0_5d_.slice<15,4>().val();
	// \src: receiver.v:91.15-91.24
	// cell $shiftx$receiver.v:91$94
	i_shiftx_24_receiver_2e_v_3a_91_24_94__Y = shiftx_uu<1>(i_3_5c_valid_5b_1_3a_0_5d_, i_6_5c_qowner0_5b_0_3a_0_5d_);
	// cells $procmux$2990 $procmux$2987 $procmux$2985 $procmux$2860 $procmux$2734 $procmux$2638
	i_7_5c_qowner1_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_logic__and_24_receiver_2e_v_3a_76_24_70__Y ? (p_pending.curr.slice<0>().val() ? i_3_5c_qowner1_5b_0_3a_0_5d_ : (i_eq_24_receiver_2e_v_3a_81_24_79__Y ? i_3_5c_qowner1_5b_0_3a_0_5d_ : (i_eq_24_receiver_2e_v_3a_82_24_80__Y ? value<1>{0u} : i_3_5c_qowner1_5b_0_3a_0_5d_))) : i_3_5c_qowner1_5b_0_3a_0_5d_) : value<1>{0u}));
	// \src: receiver.v:98.38-98.44
	// cell $sub$receiver.v:98$114
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4772.slice<1,0>() = sub_uu<2>(i_5_5c_qlen_5b_1_3a_0_5d_, value<1>{0x1u});
	// cells $logic_and$receiver.v:89$91 $logic_not$receiver.v:89$89 $ne$receiver.v:89$90
	i_logic__and_24_receiver_2e_v_3a_89_24_91__Y = logic_and<1>(logic_not<1>(p_rzero.curr), reduce_bool<1>(i_5_5c_qlen_5b_1_3a_0_5d_));
	// \src: receiver.v:87.7-87.20
	// cell $eq$receiver.v:87$83
	i_eq_24_receiver_2e_v_3a_87_24_83__Y = logic_not<1>(p_cachephase.curr);
	// \src: receiver.v:104.10-104.23
	// cell $ne$receiver.v:104$119
	i_ne_24_receiver_2e_v_3a_104_24_119__Y = ne_uu<1>(p_readyphase.curr, value<1>{0x1u});
	// cells $procmux$3401 $procmux$3398 $procmux$3396 $procmux$3262
	i_9_5c_fault_5b_15_3a_0_5d_ = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_logic__and_24_receiver_2e_v_3a_65_24_56__Y ? (p_pending.curr.slice<1>().val() ? i_4_5c_fault_5b_15_3a_0_5d_ : i_11_5c_fault_5b_15_3a_0_5d_.slice<15,4>().concat(i_12_5c_fault_5b_15_3a_0_5d_.slice<3,0>()).val()) : i_4_5c_fault_5b_15_3a_0_5d_) : value<16>{0u}));
	// cells $procmux$2749 $logic_or$receiver.v:79$73 $eq$receiver.v:79$71
	i_procmux_24_2749__Y.slice<2,0>() = (logic_or<1>(eq_uu<1>(p_seqa.curr, value<16>{0xffffu}), i_gt_24_receiver_2e_v_3a_118_24_152__Y) ? value<1>{0x1u}.concat(i_9_5c_fault_5b_15_3a_0_5d_.slice<1,0>()).val() : i_9_5c_fault_5b_15_3a_0_5d_.slice<2,0>().val());
	// connection
	i_procmux_24_2749__Y.slice<15,3>() = i_9_5c_fault_5b_15_3a_0_5d_.slice<15,3>().val();
	// cells $procmux$2597 $procmux$2594 $procmux$2592 $procmux$2098 $procmux$1850
	i_9_5c_qowner0_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_logic__and_24_receiver_2e_v_3a_89_24_91__Y ? (i_shiftx_24_receiver_2e_v_3a_91_24_94__Y ? i_7_5c_qowner1_5b_0_3a_0_5d_ : i_6_5c_qowner0_5b_0_3a_0_5d_) : i_6_5c_qowner0_5b_0_3a_0_5d_) : i_6_5c_qowner0_5b_0_3a_0_5d_) : value<1>{0u}));
	// cells $procmux$2606 $procmux$2603 $procmux$2601 $procmux$2110 $procmux$1865
	i_7_5c_qlen_5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_logic__and_24_receiver_2e_v_3a_89_24_91__Y ? (i_shiftx_24_receiver_2e_v_3a_91_24_94__Y ? i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4772.slice<1,0>().val() : i_5_5c_qlen_5b_1_3a_0_5d_) : i_5_5c_qlen_5b_1_3a_0_5d_) : i_5_5c_qlen_5b_1_3a_0_5d_) : value<2>{0u}));
	// cells $procmux$2009 $procmux$2006 $procmux$2004 $procmux$2002 $procmux$1625
	i_4_5c_failed_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_logic__and_24_receiver_2e_v_3a_89_24_91__Y ? (i_shiftx_24_receiver_2e_v_3a_91_24_94__Y ? p_failed.curr : value<1>{0x1u}) : p_failed.curr) : value<1>{0u}) : value<1>{0u}));
	// cells $procmux$1208 $procmux$1086
	i_5_5c_evblock_5b_0_3a_0_5d_ = (p_rone.curr ? (i_ne_24_receiver_2e_v_3a_104_24_119__Y ? value<1>{0u} : value<1>{0x1u}) : value<1>{0u});
	// \src: receiver.v:126.7-126.13
	// cell $gt$receiver.v:126$160
	i_gt_24_receiver_2e_v_3a_126_24_160__Y = gt_uu<1>(i_7_5c_qlen_5b_1_3a_0_5d_, value<1>{0u});
	// cells $procmux$426 $procmux$406
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4778.slice<0>() = (i_gt_24_receiver_2e_v_3a_126_24_160__Y ? (i_9_5c_qowner0_5b_0_3a_0_5d_ ? value<1>{0u} : value<1>{0x1u}) : value<1>{0u});
	// connection
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4778.slice<2,1>() = value<2>{0u};
	// cells $procmux$417 $procmux$394
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4780.slice<0>() = (i_gt_24_receiver_2e_v_3a_126_24_160__Y ? (i_9_5c_qowner0_5b_0_3a_0_5d_ ? value<1>{0x1u} : value<1>{0u}) : value<1>{0u});
	// connection
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4780.slice<2,1>() = value<2>{0u};
	// cells $procmux$2759 $procmux$2756 $procmux$2754 $procmux$2752
	i_16_5c_fault_5b_15_3a_0_5d_ = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_logic__and_24_receiver_2e_v_3a_76_24_70__Y ? (p_pending.curr.slice<0>().val() ? value<16>{0u} : i_9_5c_fault_5b_15_3a_0_5d_.slice<15,3>().concat(i_procmux_24_2749__Y.slice<2,0>()).val()) : value<16>{0u}) : value<16>{0u}));
	// cells $procmux$431 $procmux$428
	i_3_5c_tokensa_5b_2_3a_0_5d_ = (p_rst ? value<3>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? value<2>{0u}.concat(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4778.slice<0>()).val() : value<3>{0u}));
	// cells $procmux$1217 $procmux$1214 $procmux$1212 $procmux$1210
	i_5_5c_rone_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? value<1>{0u} : i_5_5c_evblock_5b_0_3a_0_5d_) : value<1>{0u}) : value<1>{0u}));
	// \full_case: 1
	// \src: receiver.v:82.14-82.21|receiver.v:82.11-83.32
	// cell $procmux$2656
	i_18_5c_fault_5b_15_3a_0_5d_.slice<3,0>() = (i_eq_24_receiver_2e_v_3a_82_24_80__Y ? i_16_5c_fault_5b_15_3a_0_5d_.slice<3,0>().val() : value<1>{0x1u}.concat(i_16_5c_fault_5b_15_3a_0_5d_.slice<2,0>()).val());
	// connection
	i_18_5c_fault_5b_15_3a_0_5d_.slice<15,4>() = i_16_5c_fault_5b_15_3a_0_5d_.slice<15,4>().val();
	// cells $procmux$422 $procmux$419
	i_3_5c_tokensb_5b_2_3a_0_5d_ = (p_rst ? value<3>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? value<2>{0u}.concat(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4780.slice<0>()).val() : value<3>{0u}));
	// cells $procmux$2081 $procmux$2078 $procmux$2076 $procmux$2074 $procmux$1820
	i_4_5c_rzero_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_logic__and_24_receiver_2e_v_3a_89_24_91__Y ? (i_shiftx_24_receiver_2e_v_3a_91_24_94__Y ? value<1>{0x1u} : p_rzero.curr) : p_rzero.curr) : value<1>{0u}) : value<1>{0u}));
	// \full_case: 1
	// \src: receiver.v:81.9-81.16|receiver.v:81.6-83.32
	// cell $procmux$2704
	i_17_5c_fault_5b_15_3a_0_5d_.slice<3,0>() = (i_eq_24_receiver_2e_v_3a_81_24_79__Y ? i_16_5c_fault_5b_15_3a_0_5d_.slice<3,0>().val() : i_18_5c_fault_5b_15_3a_0_5d_.slice<3,0>().val());
	// connection
	i_17_5c_fault_5b_15_3a_0_5d_.slice<15,4>() = i_16_5c_fault_5b_15_3a_0_5d_.slice<15,4>().val();
	// \src: receiver.v:127.7-127.13
	// cell $gt$receiver.v:127$163
	i_gt_24_receiver_2e_v_3a_127_24_163__Y = gt_uu<1>(i_7_5c_qlen_5b_1_3a_0_5d_, value<1>{0x1u});
	// cells $logic_and$receiver.v:108$121 $logic_not$receiver.v:108$120
	i_logic__and_24_receiver_2e_v_3a_108_24_121__Y = logic_and<1>(i_4_5c_rzero_5b_0_3a_0_5d_, logic_not<1>(i_5_5c_rone_5b_0_3a_0_5d_));
	// cells $procmux$2062 $procmux$1805
	i_4_5c_ownerzero_5b_0_3a_0_5d_ = (i_logic__and_24_receiver_2e_v_3a_89_24_91__Y ? (i_shiftx_24_receiver_2e_v_3a_91_24_94__Y ? i_6_5c_qowner0_5b_0_3a_0_5d_ : p_ownerzero.curr) : p_ownerzero.curr);
	// cells $procmux$3491 $procmux$3488 $procmux$3486
	i_3_5c_pending_5b_1_3a_1_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_logic__and_24_receiver_2e_v_3a_65_24_56__Y ? value<1>{0x1u} : p_pending.curr.slice<1>().val()) : value<1>{0u}));
	// cells $procmux$3053 $procmux$3050 $procmux$3048
	i_5_5c_pending_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_logic__and_24_receiver_2e_v_3a_76_24_70__Y ? value<1>{0x1u} : p_pending.curr.slice<0>().val()) : value<1>{0u}));
	// cells $procmux$1172 $procmux$1169 $procmux$1167 $procmux$1165 $procmux$1163 $procmux$1014
	i_5_5c_emitowner_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? value<1>{0u} : (p_rone.curr ? (i_ne_24_receiver_2e_v_3a_104_24_119__Y ? p_ownerone.curr : p_emitowner.curr) : p_emitowner.curr)) : value<1>{0u}) : value<1>{0u}));
	// cells $procmux$389 $procmux$386 $procmux$384 $procmux$364 $add$receiver.v:127$165
	i_5_5c_tokensa_5b_2_3a_0_5d_ = (p_rst ? value<3>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_gt_24_receiver_2e_v_3a_127_24_163__Y ? (i_7_5c_qowner1_5b_0_3a_0_5d_ ? i_3_5c_tokensa_5b_2_3a_0_5d_ : add_uu<3>(i_3_5c_tokensa_5b_2_3a_0_5d_, value<1>{0x1u})) : i_3_5c_tokensa_5b_2_3a_0_5d_) : value<3>{0u}));
	// cells $procmux$2963 $procmux$2960 $procmux$2958 $procmux$2824
	i_14_5c_fault_5b_15_3a_0_5d_ = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_logic__and_24_receiver_2e_v_3a_76_24_70__Y ? (p_pending.curr.slice<0>().val() ? i_9_5c_fault_5b_15_3a_0_5d_ : i_16_5c_fault_5b_15_3a_0_5d_.slice<15,4>().concat(i_17_5c_fault_5b_15_3a_0_5d_.slice<3,0>()).val()) : i_9_5c_fault_5b_15_3a_0_5d_) : value<16>{0u}));
	// cells $procmux$380 $procmux$377 $procmux$375 $procmux$352 $add$receiver.v:127$164
	i_5_5c_tokensb_5b_2_3a_0_5d_ = (p_rst ? value<3>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_gt_24_receiver_2e_v_3a_127_24_163__Y ? (i_7_5c_qowner1_5b_0_3a_0_5d_ ? add_uu<3>(i_3_5c_tokensb_5b_2_3a_0_5d_, value<1>{0x1u}) : i_3_5c_tokensb_5b_2_3a_0_5d_) : i_3_5c_tokensb_5b_2_3a_0_5d_) : value<3>{0u}));
	// cells $procmux$2579 $procmux$2576 $procmux$2574
	i_3_5c_ownerzero_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? i_4_5c_ownerzero_5b_0_3a_0_5d_ : p_ownerzero.curr) : value<1>{0u}));
	// \src: receiver.v:117.29-117.48
	// cell $neg$receiver.v:117$149
	i_neg_24_receiver_2e_v_3a_115_24_128__Y = neg_u<2>(i_5_5c_emitowner_5b_0_3a_0_5d_);
	// cells $procmux$627 $shiftx$receiver.v:114$125
	i_procmux_24_627__Y.slice<4,0>() = (shiftx_uu<1>(i_3_5c_pending_5b_1_3a_1_5d_.concat(i_5_5c_pending_5b_0_3a_0_5d_).val(), i_5_5c_emitowner_5b_0_3a_0_5d_) ? i_14_5c_fault_5b_15_3a_0_5d_.slice<4,0>().val() : value<1>{0x1u}.concat(i_14_5c_fault_5b_15_3a_0_5d_.slice<3,0>()).val());
	// cells $procmux$1202 $procmux$1199 $procmux$1197 $procmux$1195 $procmux$1193 $procmux$1032
	i_5_5c_evemit_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? value<1>{0u} : (p_rone.curr ? (i_ne_24_receiver_2e_v_3a_104_24_119__Y ? value<1>{0x1u} : value<1>{0u}) : value<1>{0u})) : value<1>{0u}) : value<1>{0u}));
	// connection
	i_procmux_24_627__Y.slice<15,5>() = i_14_5c_fault_5b_15_3a_0_5d_.slice<15,5>().val();
	// cells $procmux$2372 $procmux$2369 $procmux$2367 $procmux$1462 $procmux$884
	i_3_5c_rzero_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? i_4_5c_rzero_5b_0_3a_0_5d_ : (i_logic__and_24_receiver_2e_v_3a_108_24_121__Y ? value<1>{0u} : i_4_5c_rzero_5b_0_3a_0_5d_)) : p_rzero.curr) : value<1>{0u}));
	// \src: receiver.v:117.29-117.48
	// cell $shift$receiver.v:117$150
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4771.slice<1,0>() = shift_us<2>(value<1>{0x1u}, i_neg_24_receiver_2e_v_3a_115_24_128__Y);
	// \src: receiver.v:119.32-119.38
	// cell $mul$receiver.v:119$154
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4762.slice<4,0>() = mul_uu<5>(value<2>{0x3u}, p_cfgp);
	// connection
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4762.slice<31,5>() = value<27>{0u};
	// \src: receiver.v:119.57-119.63
	// cell $mul$receiver.v:119$157
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4759.slice<4,0>() = mul_uu<5>(value<2>{0x2u}, p_cfgp);
	// connection
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4759.slice<31,5>() = value<27>{0u};
	// \src: receiver.v:117.29-117.48
	// cell $not$receiver.v:117$147
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4770.slice<1,0>() = not_u<2>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4771.slice<1,0>().val());
	// \src: receiver.v:117.8-117.28
	// cell $shift$receiver.v:117$143
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4768.slice<1,0>() = shift_us<2>(value<1>{0u}, i_neg_24_receiver_2e_v_3a_115_24_128__Y);
	// cells $procmux$3473 $procmux$3470 $procmux$3468 $procmux$3214
	i_3_5c_pollen_5b_1_3a_1_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_logic__and_24_receiver_2e_v_3a_65_24_56__Y ? (p_pending.curr.slice<1>().val() ? value<1>{0u} : p_pollen.curr.slice<1>().val()) : p_pollen.curr.slice<1>().val()) : value<1>{0u}));
	// cells $procmux$3035 $procmux$3032 $procmux$3030 $procmux$2776
	i_5_5c_pollen_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_logic__and_24_receiver_2e_v_3a_76_24_70__Y ? (p_pending.curr.slice<0>().val() ? value<1>{0u} : p_pollen.curr.slice<0>().val()) : p_pollen.curr.slice<0>().val()) : value<1>{0u}));
	// cells $add$receiver.v:119$156 $add$receiver.v:119$155
	i_add_24_receiver_2e_v_3a_119_24_156__Y = add_uu<16>(add_uu<16>(p_tick.curr, i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4762.slice<4,0>().val()), value<1>{0x1u});
	// cells $add$receiver.v:119$159 $add$receiver.v:119$158
	i_add_24_receiver_2e_v_3a_119_24_159__Y = add_uu<16>(add_uu<16>(p_tick.curr, i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4759.slice<4,0>().val()), value<1>{0x1u});
	// cells $procmux$347 $procmux$344 $procmux$342 $procmux$322 $add$receiver.v:128$167
	i_7_5c_tokensa_5b_2_3a_0_5d_ = (p_rst ? value<3>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_3_5c_rzero_5b_0_3a_0_5d_ ? (i_3_5c_ownerzero_5b_0_3a_0_5d_ ? i_5_5c_tokensa_5b_2_3a_0_5d_ : add_uu<3>(i_5_5c_tokensa_5b_2_3a_0_5d_, value<1>{0x1u})) : i_5_5c_tokensa_5b_2_3a_0_5d_) : value<3>{0u}));
	// cells $or$receiver.v:115$134 $and$receiver.v:115$131
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4767.slice<1,0>() = or_uu<2>(and_uu<2>(i_3_5c_pending_5b_1_3a_1_5d_.concat(i_5_5c_pending_5b_0_3a_0_5d_).val(), i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4770.slice<1,0>().val()), i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4768.slice<1,0>().val());
	// cells $procmux$3482 $procmux$3479 $procmux$3477 $procmux$3226
	i_3_5c_waiting_5b_1_3a_1_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_logic__and_24_receiver_2e_v_3a_65_24_56__Y ? (p_pending.curr.slice<1>().val() ? value<1>{0x1u} : p_waiting.curr.slice<1>().val()) : p_waiting.curr.slice<1>().val()) : value<1>{0u}));
	// cells $procmux$3044 $procmux$3041 $procmux$3039 $procmux$2788
	i_5_5c_waiting_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_logic__and_24_receiver_2e_v_3a_76_24_70__Y ? (p_pending.curr.slice<0>().val() ? value<1>{0x1u} : p_waiting.curr.slice<0>().val()) : p_waiting.curr.slice<0>().val()) : value<1>{0u}));
	// cells $procmux$338 $procmux$335 $procmux$333 $procmux$310 $add$receiver.v:128$166
	i_7_5c_tokensb_5b_2_3a_0_5d_ = (p_rst ? value<3>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_3_5c_rzero_5b_0_3a_0_5d_ ? (i_3_5c_ownerzero_5b_0_3a_0_5d_ ? add_uu<3>(i_5_5c_tokensb_5b_2_3a_0_5d_, value<1>{0x1u}) : i_5_5c_tokensb_5b_2_3a_0_5d_) : i_5_5c_tokensb_5b_2_3a_0_5d_) : value<3>{0u}));
	// cells $procmux$2354 $procmux$2351 $procmux$2349 $procmux$1438 $procmux$929
	i_3_5c_ownerone_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? p_ownerone.curr : (i_logic__and_24_receiver_2e_v_3a_108_24_121__Y ? i_4_5c_ownerzero_5b_0_3a_0_5d_ : p_ownerone.curr)) : p_ownerone.curr) : value<1>{0u}));
	// \src: receiver.v:116.17-116.28
	// cell $shiftx$receiver.v:116$135
	i_procmux_24_442__CMP = shiftx_uu<1>(i_3_5c_waiting_5b_1_3a_1_5d_.concat(i_5_5c_waiting_5b_0_3a_0_5d_).val(), i_5_5c_emitowner_5b_0_3a_0_5d_);
	// cells $or$receiver.v:117$151 $and$receiver.v:117$148
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4763.slice<1,0>() = or_uu<2>(and_uu<2>(i_3_5c_pollen_5b_1_3a_1_5d_.concat(i_5_5c_pollen_5b_0_3a_0_5d_).val(), i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4770.slice<1,0>().val()), i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4771.slice<1,0>().val());
	// cells $procmux$3459 $procmux$3346
	i_3_5c_pollb_5b_15_3a_0_5d_ = (i_logic__and_24_receiver_2e_v_3a_65_24_56__Y ? (p_pending.curr.slice<1>().val() ? p_pollb.curr : i_add_24_receiver_2e_v_3a_119_24_156__Y) : p_pollb.curr);
	// cells $procmux$3021 $procmux$2908
	i_3_5c_polla_5b_15_3a_0_5d_ = (i_logic__and_24_receiver_2e_v_3a_76_24_70__Y ? (p_pending.curr.slice<0>().val() ? p_polla.curr : i_add_24_receiver_2e_v_3a_119_24_159__Y) : p_polla.curr);
	// \src: receiver.v:69.11-69.17
	// cell $add$receiver.v:69$61
	i_add_24_receiver_2e_v_3a_69_24_61__Y = add_uu<16>(p_seqb.curr, value<1>{0x1u});
	// cells $procmux$638 $procmux$635 $procmux$633 $procmux$631 $procmux$629
	i_22_5c_fault_5b_15_3a_0_5d_ = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? value<16>{0u} : (i_5_5c_evemit_5b_0_3a_0_5d_ ? i_14_5c_fault_5b_15_3a_0_5d_.slice<15,5>().concat(i_procmux_24_627__Y.slice<4,0>()).val() : value<16>{0u})) : value<16>{0u}) : value<16>{0u}));
	// cells $procmux$2363 $procmux$2360 $procmux$2358 $procmux$1450 $procmux$944
	i_3_5c_rone_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? p_rone.curr : (i_logic__and_24_receiver_2e_v_3a_108_24_121__Y ? value<1>{0x1u} : i_5_5c_rone_5b_0_3a_0_5d_)) : p_rone.curr) : value<1>{0u}));
	// cells $or$receiver.v:117$144 $and$receiver.v:117$141
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4765.slice<1,0>() = or_uu<2>(and_uu<2>(i_3_5c_waiting_5b_1_3a_1_5d_.concat(i_5_5c_waiting_5b_0_3a_0_5d_).val(), i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4770.slice<1,0>().val()), i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4768.slice<1,0>().val());
	// \full_case: 1
	// \src: receiver.v:118.11-118.21|receiver.v:118.8-118.43
	// cell $procmux$481
	i_24_5c_fault_5b_15_3a_0_5d_.slice<2,0>() = (i_gt_24_receiver_2e_v_3a_118_24_152__Y ? value<1>{0x1u}.concat(i_22_5c_fault_5b_15_3a_0_5d_.slice<1,0>()).val() : i_22_5c_fault_5b_15_3a_0_5d_.slice<2,0>().val());
	// connection
	i_24_5c_fault_5b_15_3a_0_5d_.slice<15,3>() = i_22_5c_fault_5b_15_3a_0_5d_.slice<15,3>().val();
	// \full_case: 1
	// \src: receiver.v:116.10-116.28|receiver.v:116.7-120.10
	// cell $procmux$537
	i_23_5c_fault_5b_15_3a_0_5d_.slice<2,0>() = (i_procmux_24_442__CMP ? i_24_5c_fault_5b_15_3a_0_5d_.slice<2,0>().val() : i_22_5c_fault_5b_15_3a_0_5d_.slice<2,0>().val());
	// connection
	i_23_5c_fault_5b_15_3a_0_5d_.slice<15,3>() = i_22_5c_fault_5b_15_3a_0_5d_.slice<15,3>().val();
	// cells $procmux$3414 $procmux$3286 $procmux$3112
	i_3_5c_qid0_5b_15_3a_0_5d_ = (i_logic__and_24_receiver_2e_v_3a_65_24_56__Y ? (p_pending.curr.slice<1>().val() ? p_qid0.curr : (i_eq_24_receiver_2e_v_3a_70_24_65__Y ? i_add_24_receiver_2e_v_3a_69_24_61__Y : p_qid0.curr)) : p_qid0.curr);
	// \src: receiver.v:80.11-80.17
	// cell $add$receiver.v:80$75
	i_add_24_receiver_2e_v_3a_80_24_75__Y = add_uu<16>(p_seqa.curr, value<1>{0x1u});
	// cells $procmux$305 $procmux$302 $procmux$300 $procmux$280 $add$receiver.v:129$169
	i_9_5c_tokensa_5b_2_3a_0_5d_ = (p_rst ? value<3>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_3_5c_rone_5b_0_3a_0_5d_ ? (i_3_5c_ownerone_5b_0_3a_0_5d_ ? i_7_5c_tokensa_5b_2_3a_0_5d_ : add_uu<3>(i_7_5c_tokensa_5b_2_3a_0_5d_, value<1>{0x1u})) : i_7_5c_tokensa_5b_2_3a_0_5d_) : value<3>{0u}));
	// cells $procmux$2417 $procmux$2414 $procmux$2412 $procmux$1354 $procmux$749
	i_7_5c_pending_5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? i_3_5c_pending_5b_1_3a_1_5d_.concat(i_5_5c_pending_5b_0_3a_0_5d_).val() : (i_5_5c_evemit_5b_0_3a_0_5d_ ? i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4767.slice<1,0>().val() : i_3_5c_pending_5b_1_3a_1_5d_.concat(i_5_5c_pending_5b_0_3a_0_5d_).val())) : i_3_5c_pending_5b_1_3a_1_5d_.concat(i_5_5c_pending_5b_0_3a_0_5d_).val()) : value<2>{0u}));
	// cells $procmux$296 $procmux$293 $procmux$291 $procmux$268 $add$receiver.v:129$168
	i_9_5c_tokensb_5b_2_3a_0_5d_ = (p_rst ? value<3>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_3_5c_rone_5b_0_3a_0_5d_ ? (i_3_5c_ownerone_5b_0_3a_0_5d_ ? add_uu<3>(i_7_5c_tokensb_5b_2_3a_0_5d_, value<1>{0x1u}) : i_7_5c_tokensb_5b_2_3a_0_5d_) : i_7_5c_tokensb_5b_2_3a_0_5d_) : value<3>{0u}));
	// cells $procmux$3405 $procmux$3274 $procmux$3157 $procmux$3058
	i_3_5c_qid1_5b_15_3a_0_5d_ = (i_logic__and_24_receiver_2e_v_3a_65_24_56__Y ? (p_pending.curr.slice<1>().val() ? p_qid1.curr : (i_eq_24_receiver_2e_v_3a_70_24_65__Y ? p_qid1.curr : (i_eq_24_receiver_2e_v_3a_71_24_66__Y ? i_add_24_receiver_2e_v_3a_69_24_61__Y : p_qid1.curr))) : p_qid1.curr);
	// \src: receiver.v:96.42-96.60
	// cell $neg$receiver.v:96$111
	i_neg_24_receiver_2e_v_3a_96_24_104__Y = neg_u<2>(i_6_5c_qowner0_5b_0_3a_0_5d_);
	// \full_case: 1
	// \src: receiver.v:52.7-52.24|receiver.v:52.4-52.80
	// cell $procmux$4017
	i_3_5c_dataa_5b_7_3a_0_5d_ = (i_logic__and_24_receiver_2e_v_3a_52_24_44__Y ? p_wua : p_dataa.curr);
	// \full_case: 1
	// \src: receiver.v:53.7-53.24|receiver.v:53.4-53.80
	// cell $procmux$3981
	i_3_5c_datab_5b_7_3a_0_5d_ = (i_logic__and_24_receiver_2e_v_3a_53_24_45__Y ? p_wub : p_datab.curr);
	// cells $procmux$2399 $procmux$2396 $procmux$2394 $procmux$1330 $procmux$719 $procmux$555
	i_7_5c_pollen_5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? i_3_5c_pollen_5b_1_3a_1_5d_.concat(i_5_5c_pollen_5b_0_3a_0_5d_).val() : (i_5_5c_evemit_5b_0_3a_0_5d_ ? (i_procmux_24_442__CMP ? i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4763.slice<1,0>().val() : i_3_5c_pollen_5b_1_3a_1_5d_.concat(i_5_5c_pollen_5b_0_3a_0_5d_).val()) : i_3_5c_pollen_5b_1_3a_1_5d_.concat(i_5_5c_pollen_5b_0_3a_0_5d_).val())) : i_3_5c_pollen_5b_1_3a_1_5d_.concat(i_5_5c_pollen_5b_0_3a_0_5d_).val()) : value<2>{0u}));
	// \src: receiver.v:96.42-96.60
	// cell $shift$receiver.v:96$108
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4777.slice<1,0>() = shift_us<2>(value<1>{0x1u}, i_neg_24_receiver_2e_v_3a_96_24_104__Y);
	// \src: receiver.v:94.17-94.36
	// cell $ternary$receiver.v:94$98
	i_ternary_24_receiver_2e_v_3a_94_24_98__Y = (i_6_5c_qowner0_5b_0_3a_0_5d_ ? i_3_5c_datab_5b_7_3a_0_5d_ : i_3_5c_dataa_5b_7_3a_0_5d_);
	// cells $procmux$2976 $procmux$2848 $procmux$2674
	i_6_5c_qid0_5b_15_3a_0_5d_ = (i_logic__and_24_receiver_2e_v_3a_76_24_70__Y ? (p_pending.curr.slice<0>().val() ? i_3_5c_qid0_5b_15_3a_0_5d_ : (i_eq_24_receiver_2e_v_3a_81_24_79__Y ? i_add_24_receiver_2e_v_3a_80_24_75__Y : i_3_5c_qid0_5b_15_3a_0_5d_)) : i_3_5c_qid0_5b_15_3a_0_5d_);
	// cells $procmux$3914 $procmux$3911 $procmux$3909 $procmux$3652 $procmux$3587 $procmux$3506
	i_5_5c_enabled_5b_1_3a_0_5d_.slice<1>() = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_54_24_46__Y ? (i_4_5c_enabled_5b_1_3a_1_5d_ ? (i_eq_24_receiver_2e_v_3a_60_24_51__Y ? value<1>{0x1u} : (i_eq_24_receiver_2e_v_3a_61_24_54__Y ? value<1>{0u} : value<1>{0x1u})) : value<1>{0u}) : i_4_5c_enabled_5b_1_3a_1_5d_) : value<1>{0u}));
	// cells $procmux$3896 $procmux$3893 $procmux$3891 $procmux$3841 $procmux$3776 $procmux$3695
	i_5_5c_enabled_5b_1_3a_0_5d_.slice<0>() = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_54_24_46__Y ? (i_3_5c_enabled_5b_0_3a_0_5d_ ? (i_eq_24_receiver_2e_v_3a_56_24_47__Y ? value<1>{0x1u} : (i_eq_24_receiver_2e_v_3a_57_24_50__Y ? value<1>{0u} : value<1>{0x1u})) : value<1>{0u}) : i_3_5c_enabled_5b_0_3a_0_5d_) : value<1>{0u}));
	// cells $procmux$2408 $procmux$2405 $procmux$2403 $procmux$1342 $procmux$734 $procmux$591
	i_7_5c_waiting_5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? i_3_5c_waiting_5b_1_3a_1_5d_.concat(i_5_5c_waiting_5b_0_3a_0_5d_).val() : (i_5_5c_evemit_5b_0_3a_0_5d_ ? (i_procmux_24_442__CMP ? i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4765.slice<1,0>().val() : i_3_5c_waiting_5b_1_3a_1_5d_.concat(i_5_5c_waiting_5b_0_3a_0_5d_).val()) : i_3_5c_waiting_5b_1_3a_1_5d_.concat(i_5_5c_waiting_5b_0_3a_0_5d_).val())) : i_3_5c_waiting_5b_1_3a_1_5d_.concat(i_5_5c_waiting_5b_0_3a_0_5d_).val()) : value<2>{0u}));
	// cells $procmux$2381 $procmux$2378 $procmux$2376 $procmux$1306 $procmux$689 $procmux$501 $procmux$439
	i_5_5c_pollb_5b_15_3a_0_5d_ = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? i_3_5c_pollb_5b_15_3a_0_5d_ : (i_5_5c_evemit_5b_0_3a_0_5d_ ? (i_procmux_24_442__CMP ? (i_5_5c_emitowner_5b_0_3a_0_5d_ ? i_add_24_receiver_2e_v_3a_119_24_156__Y : i_3_5c_pollb_5b_15_3a_0_5d_) : i_3_5c_pollb_5b_15_3a_0_5d_) : i_3_5c_pollb_5b_15_3a_0_5d_)) : i_3_5c_pollb_5b_15_3a_0_5d_) : value<16>{0u}));
	// cells $procmux$2390 $procmux$2387 $procmux$2385 $procmux$1318 $procmux$704 $procmux$519 $procmux$460
	i_5_5c_polla_5b_15_3a_0_5d_ = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? i_3_5c_polla_5b_15_3a_0_5d_ : (i_5_5c_evemit_5b_0_3a_0_5d_ ? (i_procmux_24_442__CMP ? (i_5_5c_emitowner_5b_0_3a_0_5d_ ? i_3_5c_polla_5b_15_3a_0_5d_ : i_add_24_receiver_2e_v_3a_119_24_159__Y) : i_3_5c_polla_5b_15_3a_0_5d_) : i_3_5c_polla_5b_15_3a_0_5d_)) : i_3_5c_polla_5b_15_3a_0_5d_) : value<16>{0u}));
	// \src: receiver.v:96.42-96.60
	// cell $not$receiver.v:96$109
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4776.slice<1,0>() = not_u<2>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4777.slice<1,0>().val());
	// cells $procmux$2327 $procmux$2324 $procmux$2322 $procmux$1294 $procmux$674
	i_19_5c_fault_5b_15_3a_0_5d_ = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? i_14_5c_fault_5b_15_3a_0_5d_ : (i_5_5c_evemit_5b_0_3a_0_5d_ ? i_22_5c_fault_5b_15_3a_0_5d_.slice<15,3>().concat(i_23_5c_fault_5b_15_3a_0_5d_.slice<2,0>()).val() : i_14_5c_fault_5b_15_3a_0_5d_)) : i_14_5c_fault_5b_15_3a_0_5d_) : value<16>{0u}));
	// cells $procmux$3882 $procmux$3640 $procmux$3572
	i_4_5c_countb_5b_2_3a_0_5d_ = (i_eq_24_receiver_2e_v_3a_54_24_46__Y ? (i_4_5c_enabled_5b_1_3a_1_5d_ ? (i_eq_24_receiver_2e_v_3a_60_24_51__Y ? i_3_5c_countb_5b_2_3a_0_5d_ : i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4784.slice<2,0>().val()) : i_3_5c_countb_5b_2_3a_0_5d_) : i_3_5c_countb_5b_2_3a_0_5d_);
	// cells $procmux$3918 $procmux$3829 $procmux$3761
	i_4_5c_counta_5b_2_3a_0_5d_ = (i_eq_24_receiver_2e_v_3a_54_24_46__Y ? (i_3_5c_enabled_5b_0_3a_0_5d_ ? (i_eq_24_receiver_2e_v_3a_56_24_47__Y ? i_3_5c_counta_5b_2_3a_0_5d_ : i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4785.slice<2,0>().val()) : i_3_5c_counta_5b_2_3a_0_5d_) : i_3_5c_counta_5b_2_3a_0_5d_);
	// \src: receiver.v:96.42-96.60
	// cell $shift$receiver.v:96$112
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4774.slice<1,0>() = shift_us<2>(value<1>{0u}, i_neg_24_receiver_2e_v_3a_96_24_104__Y);
	// cells $procmux$2038 $procmux$1775
	i_4_5c_bytezero_5b_7_3a_0_5d_ = (i_logic__and_24_receiver_2e_v_3a_89_24_91__Y ? (i_shiftx_24_receiver_2e_v_3a_91_24_94__Y ? i_ternary_24_receiver_2e_v_3a_94_24_98__Y : p_bytezero.curr) : p_bytezero.curr);
	// cells $procmux$1133 $procmux$996
	i_5_5c_emitid_5b_15_3a_0_5d_ = (p_rone.curr ? (i_ne_24_receiver_2e_v_3a_104_24_119__Y ? p_idone.curr : p_emitid.curr) : p_emitid.curr);
	// cells $procmux$2050 $procmux$1790
	i_4_5c_idzero_5b_15_3a_0_5d_ = (i_logic__and_24_receiver_2e_v_3a_89_24_91__Y ? (i_shiftx_24_receiver_2e_v_3a_91_24_94__Y ? i_6_5c_qid0_5b_15_3a_0_5d_ : p_idzero.curr) : p_idzero.curr);
	// cells $procmux$258 $logic_or$receiver.v:130$177 $logic_or$receiver.v:130$174 $logic_or$receiver.v:130$172 $gt$receiver.v:130$170 $ne$receiver.v:130$171 $ne$receiver.v:130$173 $gt$receiver.v:130$176 $add$receiver.v:130$175
	i_25_5c_fault_5b_15_3a_0_5d_.slice<5,0>() = (logic_or<1>(logic_or<1>(logic_or<1>(gt_uu<1>(i_7_5c_qlen_5b_1_3a_0_5d_, value<2>{0x2u}), ne_uu<1>(i_9_5c_tokensa_5b_2_3a_0_5d_, i_7_5c_pending_5b_1_3a_0_5d_.slice<0>().val())), ne_uu<1>(i_9_5c_tokensb_5b_2_3a_0_5d_, i_7_5c_pending_5b_1_3a_0_5d_.slice<1>().val())), gt_uu<1>(add_uu<4>(i_9_5c_tokensa_5b_2_3a_0_5d_, i_9_5c_tokensb_5b_2_3a_0_5d_), value<2>{0x2u})) ? value<1>{0x1u}.concat(i_19_5c_fault_5b_15_3a_0_5d_.slice<4,0>()).val() : i_19_5c_fault_5b_15_3a_0_5d_.slice<5,0>().val());
	// connection
	i_25_5c_fault_5b_15_3a_0_5d_.slice<15,6>() = i_19_5c_fault_5b_15_3a_0_5d_.slice<15,6>().val();
	// cells $procmux$2967 $procmux$2836 $procmux$2719 $procmux$2620
	i_7_5c_qid1_5b_15_3a_0_5d_ = (i_logic__and_24_receiver_2e_v_3a_76_24_70__Y ? (p_pending.curr.slice<0>().val() ? i_3_5c_qid1_5b_15_3a_0_5d_ : (i_eq_24_receiver_2e_v_3a_81_24_79__Y ? i_3_5c_qid1_5b_15_3a_0_5d_ : (i_eq_24_receiver_2e_v_3a_82_24_80__Y ? i_add_24_receiver_2e_v_3a_80_24_75__Y : i_3_5c_qid1_5b_15_3a_0_5d_))) : i_3_5c_qid1_5b_15_3a_0_5d_);
	// cells $or$receiver.v:96$113 $and$receiver.v:96$110
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4773.slice<1,0>() = or_uu<2>(and_uu<2>(i_5_5c_enabled_5b_1_3a_0_5d_, i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4776.slice<1,0>().val()), i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4774.slice<1,0>().val());
	// \src: receiver.v:137.63-137.76
	// cell $add$receiver.v:137$204
	i_add_24_receiver_2e_v_3a_137_24_202__Y = add_uu<6>(p_expiryphase.curr, value<1>{0x1u});
	// \src: receiver.v:136.55-136.67
	// cell $add$receiver.v:136$201
	i_add_24_receiver_2e_v_3a_136_24_199__Y = add_uu<4>(p_readyphase.curr, value<1>{0x1u});
	// \src: receiver.v:135.55-135.67
	// cell $add$receiver.v:135$198
	i_add_24_receiver_2e_v_3a_135_24_196__Y = add_uu<4>(p_cachephase.curr, value<1>{0x1u});
	// cells $procmux$249 $logic_or$receiver.v:131$185 $logic_and$receiver.v:131$181 $logic_or$receiver.v:131$180 $logic_not$receiver.v:131$179 $logic_and$receiver.v:131$184 $logic_or$receiver.v:131$183 $logic_not$receiver.v:131$182
	i_26_5c_fault_5b_15_3a_0_5d_.slice<6,0>() = (logic_or<1>(logic_and<1>(i_7_5c_waiting_5b_1_3a_0_5d_.slice<0>().val(), logic_or<1>(logic_not<1>(i_7_5c_pending_5b_1_3a_0_5d_.slice<0>().val()), i_7_5c_pollen_5b_1_3a_0_5d_.slice<0>().val())), logic_and<1>(i_7_5c_waiting_5b_1_3a_0_5d_.slice<1>().val(), logic_or<1>(logic_not<1>(i_7_5c_pending_5b_1_3a_0_5d_.slice<1>().val()), i_7_5c_pollen_5b_1_3a_0_5d_.slice<1>().val()))) ? value<1>{0x1u}.concat(i_25_5c_fault_5b_15_3a_0_5d_.slice<5,0>()).val() : i_19_5c_fault_5b_15_3a_0_5d_.slice<6>().concat(i_25_5c_fault_5b_15_3a_0_5d_.slice<5,0>()).val());
	// connection
	i_26_5c_fault_5b_15_3a_0_5d_.slice<15,7>() = i_19_5c_fault_5b_15_3a_0_5d_.slice<15,7>().val();
	// cells $procmux$240 $logic_or$receiver.v:132$191 $logic_and$receiver.v:132$188 $le$receiver.v:132$187 $logic_and$receiver.v:132$190 $le$receiver.v:132$189
	i_27_5c_fault_5b_15_3a_0_5d_.slice<7,0>() = (logic_or<1>(logic_and<1>(i_7_5c_pollen_5b_1_3a_0_5d_.slice<0>().val(), le_uu<1>(i_5_5c_polla_5b_15_3a_0_5d_, p_tick.curr)), logic_and<1>(i_7_5c_pollen_5b_1_3a_0_5d_.slice<1>().val(), le_uu<1>(i_5_5c_pollb_5b_15_3a_0_5d_, p_tick.curr))) ? value<1>{0x1u}.concat(i_26_5c_fault_5b_15_3a_0_5d_.slice<6,0>()).val() : i_19_5c_fault_5b_15_3a_0_5d_.slice<7>().concat(i_26_5c_fault_5b_15_3a_0_5d_.slice<6,0>()).val());
	// connection
	i_27_5c_fault_5b_15_3a_0_5d_.slice<15,8>() = i_19_5c_fault_5b_15_3a_0_5d_.slice<15,8>().val();
	// cells $procmux$3864 $procmux$3805 $procmux$3746 $procmux$3677
	i_3_5c_evexpire_5b_1_3a_0_5d_.slice<0>() = (i_eq_24_receiver_2e_v_3a_54_24_46__Y ? (i_3_5c_enabled_5b_0_3a_0_5d_ ? (i_eq_24_receiver_2e_v_3a_56_24_47__Y ? value<1>{0u} : (i_eq_24_receiver_2e_v_3a_57_24_50__Y ? value<1>{0x1u} : value<1>{0u})) : value<1>{0u}) : value<1>{0u});
	// cells $procmux$3495 $procmux$3616 $procmux$3557 $procmux$3938
	i_3_5c_evexpire_5b_1_3a_0_5d_.slice<1>() = (i_eq_24_receiver_2e_v_3a_54_24_46__Y ? (i_4_5c_enabled_5b_1_3a_1_5d_ ? (i_eq_24_receiver_2e_v_3a_60_24_51__Y ? value<1>{0u} : (i_eq_24_receiver_2e_v_3a_61_24_54__Y ? value<1>{0x1u} : value<1>{0u})) : value<1>{0u}) : value<1>{0u});
	// cells $procmux$231 $ge$receiver.v:133$193
	i_28_5c_fault_5b_15_3a_0_5d_.slice<8,0>() = (ge_uu<1>(p_tick.curr, value<16>{0xffebu}) ? value<1>{0x1u}.concat(i_27_5c_fault_5b_15_3a_0_5d_.slice<7,0>()).val() : i_19_5c_fault_5b_15_3a_0_5d_.slice<8>().concat(i_27_5c_fault_5b_15_3a_0_5d_.slice<7,0>()).val());
	// connection
	i_28_5c_fault_5b_15_3a_0_5d_.slice<15,9>() = i_19_5c_fault_5b_15_3a_0_5d_.slice<15,9>().val();
	// cells $procmux$4436 $procmux$3990
	i_2_5c_evwu_5b_1_3a_0_5d_.slice<0>() = (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_logic__and_24_receiver_2e_v_3a_52_24_44__Y ? value<1>{0x1u} : value<1>{0u}) : p_evwu.curr.slice<0>().val());
	// cells $procmux$206 $procmux$3954
	i_2_5c_evwu_5b_1_3a_0_5d_.slice<1>() = (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_logic__and_24_receiver_2e_v_3a_53_24_45__Y ? value<1>{0x1u} : value<1>{0u}) : p_evwu.curr.slice<1>().val());
	// cells $procmux$4448 $procmux$3378 $procmux$3250
	i_2_5c_evenq_5b_1_3a_0_5d_.slice<1>() = (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_logic__and_24_receiver_2e_v_3a_65_24_56__Y ? (p_pending.curr.slice<1>().val() ? value<1>{0u} : value<1>{0x1u}) : value<1>{0u}) : p_evenq.curr.slice<1>().val());
	// cells $procmux$4406 $procmux$2940 $procmux$2812
	i_2_5c_evenq_5b_1_3a_0_5d_.slice<0>() = (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_logic__and_24_receiver_2e_v_3a_76_24_70__Y ? (p_pending.curr.slice<0>().val() ? value<1>{0u} : value<1>{0x1u}) : value<1>{0u}) : p_evenq.curr.slice<0>().val());
	// cells $procmux$4412 $procmux$2949 $procmux$2764
	i_2_5c_evwait_5b_1_3a_0_5d_.slice<0>() = (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_logic__and_24_receiver_2e_v_3a_76_24_70__Y ? (p_pending.curr.slice<0>().val() ? value<1>{0x1u} : value<1>{0u}) : value<1>{0u}) : p_evwait.curr.slice<0>().val());
	// cells $procmux$4367 $procmux$3387 $procmux$3202
	i_2_5c_evwait_5b_1_3a_0_5d_.slice<1>() = (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_logic__and_24_receiver_2e_v_3a_65_24_56__Y ? (p_pending.curr.slice<1>().val() ? value<1>{0x1u} : value<1>{0u}) : value<1>{0u}) : p_evwait.curr.slice<1>().val());
	// cells $procdff$4742 $procmux$4568 $procmux$4025 $procmux$4374 $eq$receiver.v:137$203
	if (posedge_p_clk) {
		p_expiryphase.next = (p_rst ? value<5>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (eq_uu<1>(i_add_24_receiver_2e_v_3a_137_24_202__Y, value<1>{0u}.concat(p_cfgperiod).val()) ? value<5>{0u} : i_add_24_receiver_2e_v_3a_137_24_202__Y.slice<4,0>().val()) : p_expiryphase.curr));
	}
	// cells $procdff$4741 $procmux$4571 $procmux$4031 $procmux$213 $eq$receiver.v:136$200
	if (posedge_p_clk) {
		p_readyphase.next = (p_rst ? value<3>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (eq_uu<1>(i_add_24_receiver_2e_v_3a_136_24_199__Y, value<1>{0u}.concat(p_cfgr).val()) ? value<3>{0u} : i_add_24_receiver_2e_v_3a_136_24_199__Y.slice<2,0>().val()) : p_readyphase.curr));
	}
	// cells $procdff$4740 $procmux$4574 $procmux$4037 $procmux$222 $eq$receiver.v:135$197
	if (posedge_p_clk) {
		p_cachephase.next = (p_rst ? value<3>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (eq_uu<1>(i_add_24_receiver_2e_v_3a_135_24_196__Y, value<1>{0u}.concat(p_cfgp).val()) ? value<3>{0u} : i_add_24_receiver_2e_v_3a_135_24_196__Y.slice<2,0>().val()) : p_cachephase.curr));
	}
	// cells $procdff$4739 $procmux$4475 $procmux$4097 $procmux$2196 $procmux$1366 $procmux$824
	if (posedge_p_clk) {
		p_transferbyte.next = (p_rst ? value<8>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? p_transferbyte.curr : (i_logic__and_24_receiver_2e_v_3a_108_24_121__Y ? i_4_5c_bytezero_5b_7_3a_0_5d_ : p_transferbyte.curr)) : p_transferbyte.curr) : p_transferbyte.curr));
	}
	// cells $procdff$4738 $procmux$4478 $procmux$4103 $procmux$2205 $procmux$1474 $procmux$1103 $procmux$978
	if (posedge_p_clk) {
		p_emitbyte.next = (p_rst ? value<8>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? p_emitbyte.curr : (p_rone.curr ? (i_ne_24_receiver_2e_v_3a_104_24_119__Y ? p_byteone.curr : p_emitbyte.curr) : p_emitbyte.curr)) : p_emitbyte.curr) : p_emitbyte.curr));
	}
	// cells $procdff$4737 $procmux$4481 $procmux$4109 $procmux$2439 $procmux$1918 $procmux$1670
	if (posedge_p_clk) {
		p_grantbyte.next = (p_rst ? value<8>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_logic__and_24_receiver_2e_v_3a_89_24_91__Y ? (i_shiftx_24_receiver_2e_v_3a_91_24_94__Y ? i_ternary_24_receiver_2e_v_3a_94_24_98__Y : p_grantbyte.curr) : p_grantbyte.curr) : p_grantbyte.curr) : p_grantbyte.curr));
	}
	// cells $procdff$4736 $procmux$4484 $procmux$4115 $procmux$2214 $procmux$1486 $procmux$1118 $procmux$1050
	if (posedge_p_clk) {
		p_blockid.next = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? p_blockid.curr : (p_rone.curr ? (i_ne_24_receiver_2e_v_3a_104_24_119__Y ? p_blockid.curr : p_idone.curr) : p_blockid.curr)) : p_blockid.curr) : p_blockid.curr));
	}
	// cells $procdff$4735 $procmux$4487 $procmux$4121 $procmux$2223 $procmux$1258 $procmux$779
	if (posedge_p_clk) {
		p_callbackid.next = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? p_callbackid.curr : (i_5_5c_evemit_5b_0_3a_0_5d_ ? i_5_5c_emitid_5b_15_3a_0_5d_ : p_callbackid.curr)) : p_callbackid.curr) : p_callbackid.curr));
	}
	// cells $procdff$4734 $procmux$4490 $procmux$4127 $procmux$2232 $procmux$1378 $procmux$839
	if (posedge_p_clk) {
		p_transferid.next = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? p_transferid.curr : (i_logic__and_24_receiver_2e_v_3a_108_24_121__Y ? i_4_5c_idzero_5b_15_3a_0_5d_ : p_transferid.curr)) : p_transferid.curr) : p_transferid.curr));
	}
	// cells $procdff$4733 $procmux$4493 $procmux$4133 $procmux$2241 $procmux$1498
	if (posedge_p_clk) {
		p_emitid.next = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? p_emitid.curr : i_5_5c_emitid_5b_15_3a_0_5d_) : p_emitid.curr) : p_emitid.curr));
	}
	// cells $procdff$4732 $procmux$4496 $procmux$4139 $procmux$2448 $procmux$1930 $procmux$1685
	if (posedge_p_clk) {
		p_grantid.next = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_logic__and_24_receiver_2e_v_3a_89_24_91__Y ? (i_shiftx_24_receiver_2e_v_3a_91_24_94__Y ? i_6_5c_qid0_5b_15_3a_0_5d_ : p_grantid.curr) : p_grantid.curr) : p_grantid.curr) : p_grantid.curr));
	}
	// cells $procdff$4731 $procmux$4499 $procmux$4145 $procmux$2457 $procmux$2134
	if (posedge_p_clk) {
		p_attemptid.next = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_logic__and_24_receiver_2e_v_3a_89_24_91__Y ? i_6_5c_qid0_5b_15_3a_0_5d_ : p_attemptid.curr) : p_attemptid.curr) : p_attemptid.curr));
	}
	// cells $procdff$4730 $procmux$4502 $procmux$4151 $procmux$2250 $procmux$1510 $procmux$1148 $procmux$1068
	if (posedge_p_clk) {
		p_blockowner.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? p_blockowner.curr : (p_rone.curr ? (i_ne_24_receiver_2e_v_3a_104_24_119__Y ? p_blockowner.curr : p_ownerone.curr) : p_blockowner.curr)) : p_blockowner.curr) : p_blockowner.curr));
	}
	// cells $procdff$4729 $procmux$4505 $procmux$4157 $procmux$2259 $procmux$1270 $procmux$794
	if (posedge_p_clk) {
		p_callbackowner.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? p_callbackowner.curr : (i_5_5c_evemit_5b_0_3a_0_5d_ ? i_5_5c_emitowner_5b_0_3a_0_5d_ : p_callbackowner.curr)) : p_callbackowner.curr) : p_callbackowner.curr));
	}
	// cells $procdff$4728 $procmux$4508 $procmux$4163 $procmux$2268 $procmux$1390 $procmux$854
	if (posedge_p_clk) {
		p_transferowner.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? p_transferowner.curr : (i_logic__and_24_receiver_2e_v_3a_108_24_121__Y ? i_4_5c_ownerzero_5b_0_3a_0_5d_ : p_transferowner.curr)) : p_transferowner.curr) : p_transferowner.curr));
	}
	// cells $procdff$4727 $procmux$4511 $procmux$4169 $procmux$2277 $procmux$1522
	if (posedge_p_clk) {
		p_emitowner.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? p_emitowner.curr : i_5_5c_emitowner_5b_0_3a_0_5d_) : p_emitowner.curr) : p_emitowner.curr));
	}
	// cells $procdff$4726 $procmux$4514 $procmux$4175 $procmux$2466 $procmux$1942 $procmux$1700
	if (posedge_p_clk) {
		p_grantowner.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_logic__and_24_receiver_2e_v_3a_89_24_91__Y ? (i_shiftx_24_receiver_2e_v_3a_91_24_94__Y ? i_6_5c_qowner0_5b_0_3a_0_5d_ : p_grantowner.curr) : p_grantowner.curr) : p_grantowner.curr) : p_grantowner.curr));
	}
	// cells $procdff$4725 $procmux$4517 $procmux$4181 $procmux$2475 $procmux$2146
	if (posedge_p_clk) {
		p_attemptowner.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_logic__and_24_receiver_2e_v_3a_89_24_91__Y ? i_6_5c_qowner0_5b_0_3a_0_5d_ : p_attemptowner.curr) : p_attemptowner.curr) : p_attemptowner.curr));
	}
	// cells $procdff$4724 $procmux$4520 $procmux$4187 $procmux$2286 $procmux$1534
	if (posedge_p_clk) {
		p_evblock.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? value<1>{0u} : i_5_5c_evblock_5b_0_3a_0_5d_) : value<1>{0u}) : p_evblock.curr));
	}
	// cells $procdff$4723 $procmux$4523 $procmux$4193 $procmux$2295 $procmux$1282 $procmux$809
	if (posedge_p_clk) {
		p_evcallback.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? value<1>{0u} : (i_5_5c_evemit_5b_0_3a_0_5d_ ? value<1>{0x1u} : value<1>{0u})) : value<1>{0u}) : p_evcallback.curr));
	}
	// cells $procdff$4722 $procmux$4526 $procmux$4199 $procmux$2304 $procmux$1402 $procmux$869
	if (posedge_p_clk) {
		p_evtransfer.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_108_24_121__Y ? value<1>{0x1u} : value<1>{0u})) : value<1>{0u}) : p_evtransfer.curr));
	}
	// cells $procdff$4721 $procmux$4529 $procmux$4205 $procmux$2313 $procmux$1546
	if (posedge_p_clk) {
		p_evemit.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? value<1>{0u} : i_5_5c_evemit_5b_0_3a_0_5d_) : value<1>{0u}) : p_evemit.curr));
	}
	// cells $procdff$4720 $procmux$4532 $procmux$4211 $procmux$2484 $procmux$1954 $procmux$1715
	if (posedge_p_clk) {
		p_evgrant.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_logic__and_24_receiver_2e_v_3a_89_24_91__Y ? (i_shiftx_24_receiver_2e_v_3a_91_24_94__Y ? value<1>{0x1u} : value<1>{0u}) : value<1>{0u}) : value<1>{0u}) : p_evgrant.curr));
	}
	// cells $procdff$4719 $procmux$4535 $procmux$4217 $procmux$2493 $procmux$2158
	if (posedge_p_clk) {
		p_evattempt.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_logic__and_24_receiver_2e_v_3a_89_24_91__Y ? value<1>{0x1u} : value<1>{0u}) : value<1>{0u}) : p_evattempt.curr));
	}
	// cells $procdff$4718 $procmux$4538 $procmux$4400 $procmux$3369 $procmux$3238
	if (posedge_p_clk) {
		p_enqidb.next = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_logic__and_24_receiver_2e_v_3a_65_24_56__Y ? (p_pending.curr.slice<1>().val() ? p_enqidb.curr : i_add_24_receiver_2e_v_3a_69_24_61__Y) : p_enqidb.curr) : p_enqidb.curr));
	}
	// cells $procdff$4717 $procmux$4541 $procmux$4361 $procmux$2931 $procmux$2800
	if (posedge_p_clk) {
		p_enqida.next = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_logic__and_24_receiver_2e_v_3a_76_24_70__Y ? (p_pending.curr.slice<0>().val() ? p_enqida.curr : i_add_24_receiver_2e_v_3a_80_24_75__Y) : p_enqida.curr) : p_enqida.curr));
	}
	// cells $procdff$4716 $procmux$4544
	if (posedge_p_clk) {
		p_evwu.next = (p_rst ? value<2>{0u} : i_2_5c_evwu_5b_1_3a_0_5d_);
	}
	// cells $procdff$4715 $procmux$4547 $procmux$4223 $procmux$2502 $procmux$1966 $procmux$1730 $shift$receiver.v:96$105 $shiftx$receiver.v:96$103
	if (posedge_p_clk) {
		p_evcancel.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_logic__and_24_receiver_2e_v_3a_89_24_91__Y ? (i_shiftx_24_receiver_2e_v_3a_91_24_94__Y ? shift_us<2>(shiftx_uu<1>(i_5_5c_enabled_5b_1_3a_0_5d_, i_6_5c_qowner0_5b_0_3a_0_5d_), i_neg_24_receiver_2e_v_3a_96_24_104__Y) : value<2>{0u}) : value<2>{0u}) : value<2>{0u}) : p_evcancel.curr));
	}
	// cells $procdff$4714 $procmux$4550 $procmux$4424
	if (posedge_p_clk) {
		p_evexpire.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? i_3_5c_evexpire_5b_1_3a_0_5d_ : p_evexpire.curr));
	}
	// cells $procdff$4713 $procmux$4553
	if (posedge_p_clk) {
		p_evenq.next = (p_rst ? value<2>{0u} : i_2_5c_evenq_5b_1_3a_0_5d_);
	}
	// cells $procdff$4712 $procmux$4556
	if (posedge_p_clk) {
		p_evwait.next = (p_rst ? value<2>{0u} : i_2_5c_evwait_5b_1_3a_0_5d_);
	}
	// cells $procdff$4711 $procmux$4472 $procmux$4049 $procmux$4467 $logic_or$receiver.v:46$35 $logic_or$receiver.v:46$33 $logic_or$receiver.v:46$31 $logic_or$receiver.v:46$29 $logic_or$receiver.v:46$27 $logic_or$receiver.v:46$25 $logic_or$receiver.v:46$23 $logic_or$receiver.v:46$19 $lt$receiver.v:46$17 $gt$receiver.v:46$18 $logic_and$receiver.v:46$22 $ne$receiver.v:46$20 $ne$receiver.v:46$21 $ge$receiver.v:46$24 $lt$receiver.v:46$26 $gt$receiver.v:46$28 $lt$receiver.v:46$30 $gt$receiver.v:46$32 $ge$receiver.v:46$34
	if (posedge_p_clk) {
		p_fault.next = (p_rst ? value<15>{0u}.concat((logic_or<1>(logic_or<1>(logic_or<1>(logic_or<1>(logic_or<1>(logic_or<1>(logic_or<1>(logic_or<1>(lt_uu<1>(p_cfgp, value<2>{0x2u}), gt_uu<1>(p_cfgp, value<3>{0x6u})), logic_and<1>(ne_uu<1>(p_cfgr, value<2>{0x3u}), ne_uu<1>(p_cfgr, value<3>{0x5u}))), ge_uu<1>(p_cfgb, p_cfgp)), lt_uu<1>(p_cfgk, value<1>{0x1u})), gt_uu<1>(p_cfgk, value<3>{0x5u})), lt_uu<1>(p_cfgperiod, value<1>{0x1u})), gt_uu<1>(p_cfgperiod, value<5>{0x18u})), ge_uu<1>(p_cfgphi, p_cfgperiod)) ? value<1>{0x1u} : value<1>{0u})).val() : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? i_19_5c_fault_5b_15_3a_0_5d_.slice<15,9>().concat(i_28_5c_fault_5b_15_3a_0_5d_.slice<8,0>()).val() : p_fault.curr));
	}
	// cells $procdff$4710 $procmux$4577 $procmux$4229 $procmux$2511 $procmux$1978 $procmux$1610
	if (posedge_p_clk) {
		p_failtick.next = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_logic__and_24_receiver_2e_v_3a_89_24_91__Y ? (i_shiftx_24_receiver_2e_v_3a_91_24_94__Y ? p_failtick.curr : p_tick.curr) : p_failtick.curr) : p_failtick.curr) : p_failtick.curr));
	}
	// cells $procdff$4709 $procmux$4580 $procmux$4235 $procmux$2520 $procmux$1990 $procmux$1595
	if (posedge_p_clk) {
		p_failowner.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_logic__and_24_receiver_2e_v_3a_89_24_91__Y ? (i_shiftx_24_receiver_2e_v_3a_91_24_94__Y ? p_failowner.curr : i_6_5c_qowner0_5b_0_3a_0_5d_) : p_failowner.curr) : p_failowner.curr) : p_failowner.curr));
	}
	// cells $procdff$4708 $procmux$4583 $procmux$4241 $procmux$2529
	if (posedge_p_clk) {
		p_failed.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? i_4_5c_failed_5b_0_3a_0_5d_ : p_failed.curr) : p_failed.curr));
	}
	// cells $procdff$4707 $procmux$4592 $procmux$4247 $procmux$2538 $procmux$2014 $procmux$1745 $procmux$1559
	if (posedge_p_clk) {
		p_countb.next = (p_rst ? value<3>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_logic__and_24_receiver_2e_v_3a_89_24_91__Y ? (i_shiftx_24_receiver_2e_v_3a_91_24_94__Y ? (i_6_5c_qowner0_5b_0_3a_0_5d_ ? value<3>{0u} : i_4_5c_countb_5b_2_3a_0_5d_) : i_4_5c_countb_5b_2_3a_0_5d_) : i_4_5c_countb_5b_2_3a_0_5d_) : i_4_5c_countb_5b_2_3a_0_5d_) : p_countb.curr));
	}
	// cells $procdff$4706 $procmux$4595 $procmux$4253 $procmux$2547 $procmux$2026 $procmux$1760 $procmux$1577
	if (posedge_p_clk) {
		p_counta.next = (p_rst ? value<3>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_logic__and_24_receiver_2e_v_3a_89_24_91__Y ? (i_shiftx_24_receiver_2e_v_3a_91_24_94__Y ? (i_6_5c_qowner0_5b_0_3a_0_5d_ ? i_4_5c_counta_5b_2_3a_0_5d_ : value<3>{0u}) : i_4_5c_counta_5b_2_3a_0_5d_) : i_4_5c_counta_5b_2_3a_0_5d_) : i_4_5c_counta_5b_2_3a_0_5d_) : p_counta.curr));
	}
	// cells $procdff$4705 $procmux$4598 $procmux$4442
	if (posedge_p_clk) {
		p_datab.next = (p_rst ? value<8>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? i_3_5c_datab_5b_7_3a_0_5d_ : p_datab.curr));
	}
	// cells $procdff$4704 $procmux$4601 $procmux$4454
	if (posedge_p_clk) {
		p_dataa.next = (p_rst ? value<8>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? i_3_5c_dataa_5b_7_3a_0_5d_ : p_dataa.curr));
	}
	// cells $procdff$4703 $procmux$4604 $procmux$4259 $procmux$2331 $procmux$1414 $procmux$899
	if (posedge_p_clk) {
		p_byteone.next = (p_rst ? value<8>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? p_byteone.curr : (i_logic__and_24_receiver_2e_v_3a_108_24_121__Y ? i_4_5c_bytezero_5b_7_3a_0_5d_ : p_byteone.curr)) : p_byteone.curr) : p_byteone.curr));
	}
	// cells $procdff$4702 $procmux$4607 $procmux$4265 $procmux$2556
	if (posedge_p_clk) {
		p_bytezero.next = (p_rst ? value<8>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? i_4_5c_bytezero_5b_7_3a_0_5d_ : p_bytezero.curr) : p_bytezero.curr));
	}
	// cells $procdff$4701 $procmux$4610 $procmux$4271 $procmux$2340 $procmux$1426 $procmux$914
	if (posedge_p_clk) {
		p_idone.next = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? p_idone.curr : (i_logic__and_24_receiver_2e_v_3a_108_24_121__Y ? i_4_5c_idzero_5b_15_3a_0_5d_ : p_idone.curr)) : p_idone.curr) : p_idone.curr));
	}
	// cells $procdff$4700 $procmux$4613 $procmux$4277 $procmux$2565
	if (posedge_p_clk) {
		p_idzero.next = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? i_4_5c_idzero_5b_15_3a_0_5d_ : p_idzero.curr) : p_idzero.curr));
	}
	// cells $procdff$4699 $procmux$4616 $procmux$4283
	if (posedge_p_clk) {
		p_ownerone.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? i_3_5c_ownerone_5b_0_3a_0_5d_ : p_ownerone.curr));
	}
	// cells $procdff$4698 $procmux$4619 $procmux$4289
	if (posedge_p_clk) {
		p_ownerzero.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? i_3_5c_ownerzero_5b_0_3a_0_5d_ : p_ownerzero.curr));
	}
	// cells $procdff$4697 $procmux$4622 $procmux$4295
	if (posedge_p_clk) {
		p_rone.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? i_3_5c_rone_5b_0_3a_0_5d_ : p_rone.curr));
	}
	// cells $procdff$4696 $procmux$4625 $procmux$4301
	if (posedge_p_clk) {
		p_rzero.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? i_3_5c_rzero_5b_0_3a_0_5d_ : p_rzero.curr));
	}
	// cells $procdff$4695 $procmux$4628 $procmux$4382
	if (posedge_p_clk) {
		p_qid1.next = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? i_7_5c_qid1_5b_15_3a_0_5d_ : p_qid1.curr));
	}
	// cells $procdff$4694 $procmux$4631 $procmux$4307 $procmux$2583 $procmux$2086 $procmux$1835
	if (posedge_p_clk) {
		p_qid0.next = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_logic__and_24_receiver_2e_v_3a_89_24_91__Y ? (i_shiftx_24_receiver_2e_v_3a_91_24_94__Y ? i_7_5c_qid1_5b_15_3a_0_5d_ : i_6_5c_qid0_5b_15_3a_0_5d_) : i_6_5c_qid0_5b_15_3a_0_5d_) : i_6_5c_qid0_5b_15_3a_0_5d_) : p_qid0.curr));
	}
	// cells $procdff$4693 $procmux$4634 $procmux$4388
	if (posedge_p_clk) {
		p_qowner1.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? i_7_5c_qowner1_5b_0_3a_0_5d_ : p_qowner1.curr));
	}
	// cells $procdff$4692 $procmux$4637 $procmux$4313
	if (posedge_p_clk) {
		p_qowner0.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? i_9_5c_qowner0_5b_0_3a_0_5d_ : p_qowner0.curr));
	}
	// cells $procdff$4691 $procmux$4640 $procmux$4319
	if (posedge_p_clk) {
		p_qlen.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? i_7_5c_qlen_5b_1_3a_0_5d_ : p_qlen.curr));
	}
	// cells $procdff$4690 $procmux$4643 $procmux$4418 $procmux$3450 $procmux$3334
	if (posedge_p_clk) {
		p_seqb.next = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_logic__and_24_receiver_2e_v_3a_65_24_56__Y ? (p_pending.curr.slice<1>().val() ? p_seqb.curr : i_add_24_receiver_2e_v_3a_69_24_61__Y) : p_seqb.curr) : p_seqb.curr));
	}
	// cells $procdff$4689 $procmux$4646 $procmux$4394 $procmux$3012 $procmux$2896
	if (posedge_p_clk) {
		p_seqa.next = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_logic__and_24_receiver_2e_v_3a_76_24_70__Y ? (p_pending.curr.slice<0>().val() ? p_seqa.curr : i_add_24_receiver_2e_v_3a_80_24_75__Y) : p_seqa.curr) : p_seqa.curr));
	}
	// cells $procdff$4688 $procmux$4649 $procmux$4325
	if (posedge_p_clk) {
		p_pollb.next = (p_rst ? value<13>{0u}.concat(p_cfgb).val() : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? i_5_5c_pollb_5b_15_3a_0_5d_ : p_pollb.curr));
	}
	// cells $procdff$4687 $procmux$4652 $procmux$4331
	if (posedge_p_clk) {
		p_polla.next = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? i_5_5c_polla_5b_15_3a_0_5d_ : p_polla.curr));
	}
	// cells $procdff$4686 $procmux$4586 $procmux$4337 $procmux$2610 $procmux$2122 $procmux$1880
	if (posedge_p_clk) {
		p_enabled.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_logic__and_24_receiver_2e_v_3a_89_24_91__Y ? (i_shiftx_24_receiver_2e_v_3a_91_24_94__Y ? i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4773.slice<1,0>().val() : i_5_5c_enabled_5b_1_3a_0_5d_) : i_5_5c_enabled_5b_1_3a_0_5d_) : i_5_5c_enabled_5b_1_3a_0_5d_) : p_enabled.curr));
	}
	// cells $procdff$4685 $procmux$4589 $procmux$4430
	if (posedge_p_clk) {
		p_valid.next = (p_rst ? value<2>{0x3u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? i_3_5c_valid_5b_1_3a_0_5d_ : p_valid.curr));
	}
	// cells $procdff$4684 $procmux$4655 $procmux$4343
	if (posedge_p_clk) {
		p_pollen.next = (p_rst ? value<2>{0x3u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? i_7_5c_pollen_5b_1_3a_0_5d_ : p_pollen.curr));
	}
	// cells $procdff$4683 $procmux$4658 $procmux$4349
	if (posedge_p_clk) {
		p_waiting.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? i_7_5c_waiting_5b_1_3a_0_5d_ : p_waiting.curr));
	}
	// cells $procdff$4682 $procmux$4661 $procmux$4355
	if (posedge_p_clk) {
		p_pending.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? i_7_5c_pending_5b_1_3a_0_5d_ : p_pending.curr));
	}
	// cells $procdff$4681 $procmux$4664 $procmux$4043 $add$receiver.v:134$195
	if (posedge_p_clk) {
		p_tick.next = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? add_uu<16>(p_tick.curr, value<1>{0x1u}) : p_tick.curr));
	}
	return converged;
}

void p_receiver::debug_eval() {
}

CXXRTL_EXTREMELY_COLD
void p_receiver::debug_info(debug_items *items, debug_scopes *scopes, std::string path, metadata_map &&cell_attrs) {
	assert(path.empty() || path[path.size() - 1] == ' ');
	if (scopes) {
		scopes->add(path.empty() ? path : path.substr(0, path.size() - 1), "receiver", metadata_map({
			{ "top", UINT64_C(1) },
			{ "src", "receiver.v:3.1-140.10" },
		}), std::move(cell_attrs));
	}
	if (items) {
		items->add(path, "attemptid", "src\000sreceiver.v:26.20-26.29\000", p_attemptid, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "attemptowner", "src\000sreceiver.v:25.13-25.25\000", p_attemptowner, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "blockid", "src\000sreceiver.v:26.67-26.74\000", p_blockid, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "blockowner", "src\000sreceiver.v:25.75-25.85\000", p_blockowner, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "byteone", "src\000sreceiver.v:17.28-17.35\000", p_byteone, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "bytezero", "src\000sreceiver.v:17.19-17.27\000", p_bytezero, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "cachephase", "src\000sreceiver.v:29.12-29.22\000", p_cachephase, 0, debug_item::DRIVEN_SYNC);
		items->add(path, "callbackid", "src\000sreceiver.v:26.56-26.66\000", p_callbackid, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "callbackowner", "src\000sreceiver.v:25.61-25.74\000", p_callbackowner, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "cfgb", "src\000sreceiver.v:5.24-5.28\000", p_cfgb, 0, debug_item::INPUT|debug_item::UNDRIVEN);
		items->add(path, "cfgk", "src\000sreceiver.v:5.29-5.33\000", p_cfgk, 0, debug_item::INPUT|debug_item::UNDRIVEN);
		items->add(path, "cfgp", "src\000sreceiver.v:5.14-5.18\000", p_cfgp, 0, debug_item::INPUT|debug_item::UNDRIVEN);
		items->add(path, "cfgperiod", "src\000sreceiver.v:6.14-6.23\000", p_cfgperiod, 0, debug_item::INPUT|debug_item::UNDRIVEN);
		items->add(path, "cfgphi", "src\000sreceiver.v:6.24-6.30\000", p_cfgphi, 0, debug_item::INPUT|debug_item::UNDRIVEN);
		items->add(path, "cfgr", "src\000sreceiver.v:5.19-5.23\000", p_cfgr, 0, debug_item::INPUT|debug_item::UNDRIVEN);
		items->add(path, "clk", "src\000sreceiver.v:4.8-4.11\000", p_clk, 0, debug_item::INPUT|debug_item::UNDRIVEN);
		items->add(path, "counta", "src\000sreceiver.v:18.19-18.25\000", p_counta, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "countb", "src\000sreceiver.v:18.26-18.32\000", p_countb, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "dataa", "src\000sreceiver.v:17.36-17.41\000", p_dataa, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "datab", "src\000sreceiver.v:17.42-17.47\000", p_datab, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "emitbyte", "src\000sreceiver.v:27.29-27.37\000", p_emitbyte, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "emitid", "src\000sreceiver.v:26.38-26.44\000", p_emitid, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "emitowner", "src\000sreceiver.v:25.37-25.46\000", p_emitowner, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "enabled", "src\000sreceiver.v:10.48-10.55\000", p_enabled, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "enqida", "src\000sreceiver.v:23.20-23.26\000", p_enqida, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "enqidb", "src\000sreceiver.v:23.27-23.33\000", p_enqidb, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "evattempt", "src\000sreceiver.v:24.13-24.22\000", p_evattempt, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "evblock", "src\000sreceiver.v:24.60-24.67\000", p_evblock, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "evcallback", "src\000sreceiver.v:24.49-24.59\000", p_evcallback, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "evcancel", "src\000sreceiver.v:22.41-22.49\000", p_evcancel, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "evemit", "src\000sreceiver.v:24.31-24.37\000", p_evemit, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "evenq", "src\000sreceiver.v:22.26-22.31\000", p_evenq, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "evexpire", "src\000sreceiver.v:22.32-22.40\000", p_evexpire, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "evgrant", "src\000sreceiver.v:24.23-24.30\000", p_evgrant, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "evtransfer", "src\000sreceiver.v:24.38-24.48\000", p_evtransfer, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "evwait", "src\000sreceiver.v:22.19-22.25\000", p_evwait, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "evwu", "src\000sreceiver.v:22.50-22.54\000", p_evwu, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "expiryphase", "src\000sreceiver.v:30.12-30.23\000", p_expiryphase, 0, debug_item::DRIVEN_SYNC);
		items->add(path, "failed", "src\000sreceiver.v:19.13-19.19\000", p_failed, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "failowner", "src\000sreceiver.v:19.20-19.29\000", p_failowner, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "failtick", "src\000sreceiver.v:20.20-20.28\000", p_failtick, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "fault", "src\000sreceiver.v:21.20-21.25\000", p_fault, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "grantbyte", "src\000sreceiver.v:27.19-27.28\000", p_grantbyte, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "grantid", "src\000sreceiver.v:26.30-26.37\000", p_grantid, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "grantowner", "src\000sreceiver.v:25.26-25.36\000", p_grantowner, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "idone", "src\000sreceiver.v:16.27-16.32\000", p_idone, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "idzero", "src\000sreceiver.v:16.20-16.26\000", p_idzero, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "ownerone", "src\000sreceiver.v:15.34-15.42\000", p_ownerone, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "ownerzero", "src\000sreceiver.v:15.24-15.33\000", p_ownerzero, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "pending", "src\000sreceiver.v:10.19-10.26\000", p_pending, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "polla", "src\000sreceiver.v:11.20-11.25\000", p_polla, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "pollb", "src\000sreceiver.v:11.26-11.31\000", p_pollb, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "pollen", "src\000sreceiver.v:10.35-10.41\000", p_pollen, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "qid0", "src\000sreceiver.v:14.20-14.24\000", p_qid0, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "qid1", "src\000sreceiver.v:14.25-14.29\000", p_qid1, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "qlen", "src\000sreceiver.v:12.19-12.23\000", p_qlen, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "qowner0", "src\000sreceiver.v:13.13-13.20\000", p_qowner0, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "qowner1", "src\000sreceiver.v:13.21-13.28\000", p_qowner1, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "readyphase", "src\000sreceiver.v:29.23-29.33\000", p_readyphase, 0, debug_item::DRIVEN_SYNC);
		items->add(path, "rone", "src\000sreceiver.v:15.19-15.23\000", p_rone, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "rst", "src\000sreceiver.v:4.19-4.22\000", p_rst, 0, debug_item::INPUT|debug_item::UNDRIVEN);
		items->add(path, "rzero", "src\000sreceiver.v:15.13-15.18\000", p_rzero, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "seqa", "src\000sreceiver.v:11.32-11.36\000", p_seqa, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "seqb", "src\000sreceiver.v:11.37-11.41\000", p_seqb, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "tick", "src\000sreceiver.v:9.20-9.24\000", p_tick, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "transferbyte", "src\000sreceiver.v:27.38-27.50\000", p_transferbyte, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "transferid", "src\000sreceiver.v:26.45-26.55\000", p_transferid, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "transferowner", "src\000sreceiver.v:25.47-25.60\000", p_transferowner, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "valid", "src\000sreceiver.v:10.42-10.47\000", p_valid, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "waiting", "src\000sreceiver.v:10.27-10.34\000", p_waiting, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "wu", "src\000sreceiver.v:7.14-7.16\000", p_wu, 0, debug_item::INPUT|debug_item::UNDRIVEN);
		items->add(path, "wua", "src\000sreceiver.v:8.14-8.17\000", p_wua, 0, debug_item::INPUT|debug_item::UNDRIVEN);
		items->add(path, "wub", "src\000sreceiver.v:8.18-8.21\000", p_wub, 0, debug_item::INPUT|debug_item::UNDRIVEN);
	}
}

} // namespace cxxrtl_design

extern "C"
cxxrtl_toplevel cxxrtl_design_create() {
	return new _cxxrtl_toplevel { std::unique_ptr<cxxrtl_design::p_receiver>(new cxxrtl_design::p_receiver) };
}
