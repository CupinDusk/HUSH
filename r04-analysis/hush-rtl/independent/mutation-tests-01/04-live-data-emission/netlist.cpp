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
	value<1> i_3_5c_pending_5b_0_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<16> i_3_5c_polla_5b_15_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<16> i_3_5c_pollb_5b_15_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<1> i_3_5c_pollen_5b_0_3a_0_5d_;
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
	value<1> i_3_5c_waiting_5b_0_3a_0_5d_;
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
	value<1> i_5_5c_pending_5b_1_3a_1_5d_;
	// \src: receiver.v:33.2-139.5
	value<16> i_5_5c_polla_5b_15_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<16> i_5_5c_pollb_5b_15_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<1> i_5_5c_pollen_5b_1_3a_1_5d_;
	// \src: receiver.v:33.2-139.5
	value<2> i_5_5c_qlen_5b_1_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<1> i_5_5c_rone_5b_0_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<3> i_5_5c_tokensa_5b_2_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<3> i_5_5c_tokensb_5b_2_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<1> i_5_5c_waiting_5b_1_3a_1_5d_;
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
	value<16> i_add_24_receiver_2e_v_3a_119_24_157__Y;
	value<16> i_add_24_receiver_2e_v_3a_119_24_160__Y;
	value<4> i_add_24_receiver_2e_v_3a_135_24_197__Y;
	value<4> i_add_24_receiver_2e_v_3a_136_24_200__Y;
	value<6> i_add_24_receiver_2e_v_3a_137_24_203__Y;
	value<16> i_add_24_receiver_2e_v_3a_69_24_61__Y;
	value<16> i_add_24_receiver_2e_v_3a_80_24_75__Y;
	// \src: receiver.v:119.57-119.63
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4760;
	// \src: receiver.v:119.32-119.38
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4763;
	// \src: receiver.v:117.29-117.48
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4764;
	// \src: receiver.v:117.8-117.28
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4766;
	// \src: receiver.v:115.7-115.27
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4768;
	// \src: receiver.v:115.7-115.27
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4769;
	// \src: receiver.v:115.7-115.27
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4771;
	// \src: receiver.v:115.7-115.27
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4772;
	// \src: receiver.v:98.38-98.44
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4773;
	// \src: receiver.v:96.42-96.60
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4774;
	// \src: receiver.v:96.42-96.60
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4775;
	// \src: receiver.v:96.42-96.60
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4777;
	// \src: receiver.v:96.42-96.60
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4778;
	value<3> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4779;
	value<3> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4781;
	// \src: receiver.v:61.24-61.32
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4785;
	// \src: receiver.v:57.24-57.32
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4786;
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
	value<1> i_gt_24_receiver_2e_v_3a_118_24_153__Y;
	// \src: receiver.v:126.7-126.13
	value<1> i_gt_24_receiver_2e_v_3a_126_24_161__Y;
	// \src: receiver.v:127.7-127.13
	value<1> i_gt_24_receiver_2e_v_3a_127_24_164__Y;
	// \src: receiver.v:108.9-108.23
	value<1> i_logic__and_24_receiver_2e_v_3a_108_24_122__Y;
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
	value<2> i_neg_24_receiver_2e_v_3a_115_24_129__Y;
	// \src: receiver.v:96.7-96.41
	value<2> i_neg_24_receiver_2e_v_3a_96_24_104__Y;
	value<16> i_procmux_24_2750__Y;
	value<16> i_procmux_24_3188__Y;
	value<16> i_procmux_24_3818__Y;
	value<1> i_procmux_24_443__CMP;
	value<16> i_procmux_24_628__Y;
	// \src: receiver.v:91.15-91.24
	value<1> i_shiftx_24_receiver_2e_v_3a_91_24_94__Y;
	// \src: receiver.v:94.17-94.36
	value<8> i_ternary_24_receiver_2e_v_3a_94_24_98__Y;
	// \src: receiver.v:52.7-52.24
	// cell $logic_and$receiver.v:52$44
	i_logic__and_24_receiver_2e_v_3a_52_24_44__Y = logic_and<1>(p_wu.slice<0>().val(), p_valid.curr.slice<0>().val());
	// cells $logic_and$receiver.v:47$38 $logic_not$receiver.v:47$36 $eq$receiver.v:47$37
	i_logic__and_24_receiver_2e_v_3a_47_24_38__Y = logic_and<1>(logic_not<1>(p_failed.curr), logic_not<1>(p_fault.curr));
	// cells $procmux$4005 $procmux$4002 $procmux$4000
	i_3_5c_counta_5b_2_3a_0_5d_ = (p_rst ? value<3>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_logic__and_24_receiver_2e_v_3a_52_24_44__Y ? p_cfgk : p_counta.curr) : value<3>{0u}));
	// \src: receiver.v:56.9-56.18
	// cell $eq$receiver.v:56$47
	i_eq_24_receiver_2e_v_3a_56_24_47__Y = logic_not<1>(i_3_5c_counta_5b_2_3a_0_5d_);
	// cells $procmux$4014 $procmux$4011 $procmux$4009
	i_3_5c_enabled_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_logic__and_24_receiver_2e_v_3a_52_24_44__Y ? value<1>{0x1u} : p_enabled.curr.slice<0>().val()) : value<1>{0u}));
	// \full_case: 1
	// \src: receiver.v:56.9-56.18|receiver.v:56.6-57.97
	// cell $procmux$3732
	i_6_5c_fault_5b_15_3a_0_5d_.slice<1,0>() = (i_eq_24_receiver_2e_v_3a_56_24_47__Y ? value<1>{0x1u}.concat(p_fault.curr.slice<0>()).val() : p_fault.curr.slice<1,0>().val());
	// connection
	i_6_5c_fault_5b_15_3a_0_5d_.slice<15,2>() = p_fault.curr.slice<15,2>().val();
	// \src: receiver.v:53.7-53.24
	// cell $logic_and$receiver.v:53$45
	i_logic__and_24_receiver_2e_v_3a_53_24_45__Y = logic_and<1>(p_wu.slice<1>().val(), p_valid.curr.slice<1>().val());
	// \full_case: 1
	// \src: receiver.v:55.8-55.18|receiver.v:55.5-58.8
	// cell $procmux$3818
	i_procmux_24_3818__Y.slice<1,0>() = (i_3_5c_enabled_5b_0_3a_0_5d_ ? i_6_5c_fault_5b_15_3a_0_5d_.slice<1,0>().val() : p_fault.curr.slice<1,0>().val());
	// \src: receiver.v:54.7-54.26
	// cell $eq$receiver.v:54$46
	i_eq_24_receiver_2e_v_3a_54_24_46__Y = eq_uu<1>(p_expiryphase.curr, p_cfgphi);
	// connection
	i_procmux_24_3818__Y.slice<15,2>() = p_fault.curr.slice<15,2>().val();
	// cells $procmux$3969 $procmux$3966 $procmux$3964
	i_3_5c_countb_5b_2_3a_0_5d_ = (p_rst ? value<3>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_logic__and_24_receiver_2e_v_3a_53_24_45__Y ? p_cfgk : p_countb.curr) : value<3>{0u}));
	// cells $procmux$3825 $procmux$3822 $procmux$3820
	i_5_5c_fault_5b_15_3a_0_5d_ = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_54_24_46__Y ? p_fault.curr.slice<15,2>().concat(i_procmux_24_3818__Y.slice<1,0>()).val() : value<16>{0u}) : value<16>{0u}));
	// \src: receiver.v:60.9-60.18
	// cell $eq$receiver.v:60$51
	i_eq_24_receiver_2e_v_3a_60_24_51__Y = logic_not<1>(i_3_5c_countb_5b_2_3a_0_5d_);
	// cells $procmux$3978 $procmux$3975 $procmux$3973
	i_4_5c_enabled_5b_1_3a_1_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_logic__and_24_receiver_2e_v_3a_53_24_45__Y ? value<1>{0x1u} : p_enabled.curr.slice<1>().val()) : value<1>{0u}));
	// \full_case: 1
	// \src: receiver.v:60.9-60.18|receiver.v:60.6-61.97
	// cell $procmux$3543
	i_8_5c_fault_5b_15_3a_0_5d_.slice<1,0>() = (i_eq_24_receiver_2e_v_3a_60_24_51__Y ? value<1>{0x1u}.concat(i_5_5c_fault_5b_15_3a_0_5d_.slice<0>()).val() : i_5_5c_fault_5b_15_3a_0_5d_.slice<1,0>().val());
	// connection
	i_8_5c_fault_5b_15_3a_0_5d_.slice<15,2>() = i_5_5c_fault_5b_15_3a_0_5d_.slice<15,2>().val();
	// \full_case: 1
	// \src: receiver.v:59.8-59.18|receiver.v:59.5-62.8
	// cell $procmux$3629
	i_7_5c_fault_5b_15_3a_0_5d_.slice<1,0>() = (i_4_5c_enabled_5b_1_3a_1_5d_ ? i_8_5c_fault_5b_15_3a_0_5d_.slice<1,0>().val() : i_5_5c_fault_5b_15_3a_0_5d_.slice<1,0>().val());
	// connection
	i_7_5c_fault_5b_15_3a_0_5d_.slice<15,2>() = i_5_5c_fault_5b_15_3a_0_5d_.slice<15,2>().val();
	// cells $logic_and$receiver.v:65$56 $eq$receiver.v:65$55
	i_logic__and_24_receiver_2e_v_3a_65_24_56__Y = logic_and<1>(p_pollen.curr.slice<0>().val(), eq_uu<1>(p_polla.curr, p_tick.curr));
	// \src: receiver.v:71.14-71.21
	// cell $eq$receiver.v:71$66
	i_eq_24_receiver_2e_v_3a_71_24_66__Y = eq_uu<1>(p_qlen.curr, value<1>{0x1u});
	// \src: receiver.v:70.9-70.16
	// cell $eq$receiver.v:70$65
	i_eq_24_receiver_2e_v_3a_70_24_65__Y = logic_not<1>(p_qlen.curr);
	// \src: receiver.v:118.11-118.21
	// cell $gt$receiver.v:118$153
	i_gt_24_receiver_2e_v_3a_118_24_153__Y = gt_uu<1>(p_tick.curr, value<16>{0xffebu});
	// \src: receiver.v:61.24-61.32
	// cell $sub$receiver.v:61$53
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4785.slice<2,0>() = sub_uu<3>(i_3_5c_countb_5b_2_3a_0_5d_, value<1>{0x1u});
	// \src: receiver.v:57.24-57.32
	// cell $sub$receiver.v:57$49
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4786.slice<2,0>() = sub_uu<3>(i_3_5c_counta_5b_2_3a_0_5d_, value<1>{0x1u});
	// cells $procmux$3879 $procmux$3876 $procmux$3874
	i_4_5c_fault_5b_15_3a_0_5d_ = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_54_24_46__Y ? i_5_5c_fault_5b_15_3a_0_5d_.slice<15,2>().concat(i_7_5c_fault_5b_15_3a_0_5d_.slice<1,0>()).val() : p_fault.curr) : value<16>{0u}));
	// \src: receiver.v:61.36-61.45
	// cell $eq$receiver.v:61$54
	i_eq_24_receiver_2e_v_3a_61_24_54__Y = logic_not<1>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4785.slice<2,0>().val());
	// \src: receiver.v:57.36-57.45
	// cell $eq$receiver.v:57$50
	i_eq_24_receiver_2e_v_3a_57_24_50__Y = logic_not<1>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4786.slice<2,0>().val());
	// cells $procmux$3447 $procmux$3444 $procmux$3442 $procmux$3323 $add$receiver.v:73$68
	i_3_5c_qlen_5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_logic__and_24_receiver_2e_v_3a_65_24_56__Y ? (p_pending.curr.slice<0>().val() ? p_qlen.curr : add_uu<2>(p_qlen.curr, value<1>{0x1u})) : p_qlen.curr) : value<2>{0u}));
	// cells $procmux$3188 $logic_or$receiver.v:68$59 $eq$receiver.v:68$57
	i_procmux_24_3188__Y.slice<2,0>() = (logic_or<1>(eq_uu<1>(p_seqa.curr, value<16>{0xffffu}), i_gt_24_receiver_2e_v_3a_118_24_153__Y) ? value<1>{0x1u}.concat(i_4_5c_fault_5b_15_3a_0_5d_.slice<1,0>()).val() : i_4_5c_fault_5b_15_3a_0_5d_.slice<2,0>().val());
	// connection
	i_procmux_24_3188__Y.slice<15,3>() = i_4_5c_fault_5b_15_3a_0_5d_.slice<15,3>().val();
	// cells $procmux$3433 $procmux$3311 $procmux$3128
	i_3_5c_qowner0_5b_0_3a_0_5d_ = (i_logic__and_24_receiver_2e_v_3a_65_24_56__Y ? (p_pending.curr.slice<0>().val() ? p_qowner0.curr : (i_eq_24_receiver_2e_v_3a_70_24_65__Y ? value<1>{0u} : p_qowner0.curr)) : p_qowner0.curr);
	// \src: receiver.v:81.9-81.16
	// cell $eq$receiver.v:81$79
	i_eq_24_receiver_2e_v_3a_81_24_79__Y = logic_not<1>(i_3_5c_qlen_5b_1_3a_0_5d_);
	// cells $procmux$3424 $procmux$3299 $procmux$3173 $procmux$3077
	i_3_5c_qowner1_5b_0_3a_0_5d_ = (i_logic__and_24_receiver_2e_v_3a_65_24_56__Y ? (p_pending.curr.slice<0>().val() ? p_qowner1.curr : (i_eq_24_receiver_2e_v_3a_70_24_65__Y ? p_qowner1.curr : (i_eq_24_receiver_2e_v_3a_71_24_66__Y ? value<1>{0u} : p_qowner1.curr))) : p_qowner1.curr);
	// \src: receiver.v:82.14-82.21
	// cell $eq$receiver.v:82$80
	i_eq_24_receiver_2e_v_3a_82_24_80__Y = eq_uu<1>(i_3_5c_qlen_5b_1_3a_0_5d_, value<1>{0x1u});
	// cells $logic_and$receiver.v:76$70 $eq$receiver.v:76$69
	i_logic__and_24_receiver_2e_v_3a_76_24_70__Y = logic_and<1>(p_pollen.curr.slice<1>().val(), eq_uu<1>(p_pollb.curr, p_tick.curr));
	// cells $procmux$3198 $procmux$3195 $procmux$3193 $procmux$3191
	i_11_5c_fault_5b_15_3a_0_5d_ = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_logic__and_24_receiver_2e_v_3a_65_24_56__Y ? (p_pending.curr.slice<0>().val() ? value<16>{0u} : i_4_5c_fault_5b_15_3a_0_5d_.slice<15,3>().concat(i_procmux_24_3188__Y.slice<2,0>()).val()) : value<16>{0u}) : value<16>{0u}));
	// \full_case: 1
	// \src: receiver.v:71.14-71.21|receiver.v:71.11-72.32
	// cell $procmux$3095
	i_13_5c_fault_5b_15_3a_0_5d_.slice<3,0>() = (i_eq_24_receiver_2e_v_3a_71_24_66__Y ? i_11_5c_fault_5b_15_3a_0_5d_.slice<3,0>().val() : value<1>{0x1u}.concat(i_11_5c_fault_5b_15_3a_0_5d_.slice<2,0>()).val());
	// connection
	i_13_5c_fault_5b_15_3a_0_5d_.slice<15,4>() = i_11_5c_fault_5b_15_3a_0_5d_.slice<15,4>().val();
	// cells $procmux$3933 $procmux$3930 $procmux$3928 $procmux$3665 $procmux$3603 $procmux$3525
	i_3_5c_valid_5b_1_3a_0_5d_.slice<1>() = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_54_24_46__Y ? (i_4_5c_enabled_5b_1_3a_1_5d_ ? (i_eq_24_receiver_2e_v_3a_60_24_51__Y ? p_valid.curr.slice<1>().val() : (i_eq_24_receiver_2e_v_3a_61_24_54__Y ? value<1>{0u} : p_valid.curr.slice<1>().val())) : p_valid.curr.slice<1>().val()) : p_valid.curr.slice<1>().val()) : value<1>{0u}));
	// cells $procmux$3906 $procmux$3903 $procmux$3901 $procmux$3854 $procmux$3792 $procmux$3714
	i_3_5c_valid_5b_1_3a_0_5d_.slice<0>() = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_54_24_46__Y ? (i_3_5c_enabled_5b_0_3a_0_5d_ ? (i_eq_24_receiver_2e_v_3a_56_24_47__Y ? p_valid.curr.slice<0>().val() : (i_eq_24_receiver_2e_v_3a_57_24_50__Y ? value<1>{0u} : p_valid.curr.slice<0>().val())) : p_valid.curr.slice<0>().val()) : p_valid.curr.slice<0>().val()) : value<1>{0u}));
	// cells $procmux$3000 $procmux$2997 $procmux$2995 $procmux$2873 $procmux$2690
	i_6_5c_qowner0_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_logic__and_24_receiver_2e_v_3a_76_24_70__Y ? (p_pending.curr.slice<1>().val() ? i_3_5c_qowner0_5b_0_3a_0_5d_ : (i_eq_24_receiver_2e_v_3a_81_24_79__Y ? value<1>{0x1u} : i_3_5c_qowner0_5b_0_3a_0_5d_)) : i_3_5c_qowner0_5b_0_3a_0_5d_) : value<1>{0u}));
	// cells $procmux$3009 $procmux$3006 $procmux$3004 $procmux$2885 $add$receiver.v:84$82
	i_5_5c_qlen_5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_logic__and_24_receiver_2e_v_3a_76_24_70__Y ? (p_pending.curr.slice<1>().val() ? i_3_5c_qlen_5b_1_3a_0_5d_ : add_uu<2>(i_3_5c_qlen_5b_1_3a_0_5d_, value<1>{0x1u})) : i_3_5c_qlen_5b_1_3a_0_5d_) : value<2>{0u}));
	// \full_case: 1
	// \src: receiver.v:70.9-70.16|receiver.v:70.6-72.32
	// cell $procmux$3143
	i_12_5c_fault_5b_15_3a_0_5d_.slice<3,0>() = (i_eq_24_receiver_2e_v_3a_70_24_65__Y ? i_11_5c_fault_5b_15_3a_0_5d_.slice<3,0>().val() : i_13_5c_fault_5b_15_3a_0_5d_.slice<3,0>().val());
	// connection
	i_12_5c_fault_5b_15_3a_0_5d_.slice<15,4>() = i_11_5c_fault_5b_15_3a_0_5d_.slice<15,4>().val();
	// \src: receiver.v:91.15-91.24
	// cell $shiftx$receiver.v:91$94
	i_shiftx_24_receiver_2e_v_3a_91_24_94__Y = shiftx_uu<1>(i_3_5c_valid_5b_1_3a_0_5d_, i_6_5c_qowner0_5b_0_3a_0_5d_);
	// cells $procmux$2991 $procmux$2988 $procmux$2986 $procmux$2861 $procmux$2735 $procmux$2639
	i_7_5c_qowner1_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_logic__and_24_receiver_2e_v_3a_76_24_70__Y ? (p_pending.curr.slice<1>().val() ? i_3_5c_qowner1_5b_0_3a_0_5d_ : (i_eq_24_receiver_2e_v_3a_81_24_79__Y ? i_3_5c_qowner1_5b_0_3a_0_5d_ : (i_eq_24_receiver_2e_v_3a_82_24_80__Y ? value<1>{0x1u} : i_3_5c_qowner1_5b_0_3a_0_5d_))) : i_3_5c_qowner1_5b_0_3a_0_5d_) : value<1>{0u}));
	// \src: receiver.v:98.38-98.44
	// cell $sub$receiver.v:98$114
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4773.slice<1,0>() = sub_uu<2>(i_5_5c_qlen_5b_1_3a_0_5d_, value<1>{0x1u});
	// cells $logic_and$receiver.v:89$91 $logic_not$receiver.v:89$89 $ne$receiver.v:89$90
	i_logic__and_24_receiver_2e_v_3a_89_24_91__Y = logic_and<1>(logic_not<1>(p_rzero.curr), reduce_bool<1>(i_5_5c_qlen_5b_1_3a_0_5d_));
	// \src: receiver.v:87.7-87.20
	// cell $eq$receiver.v:87$83
	i_eq_24_receiver_2e_v_3a_87_24_83__Y = logic_not<1>(p_cachephase.curr);
	// \src: receiver.v:104.10-104.23
	// cell $ne$receiver.v:104$119
	i_ne_24_receiver_2e_v_3a_104_24_119__Y = ne_uu<1>(p_readyphase.curr, value<1>{0x1u});
	// cells $procmux$3402 $procmux$3399 $procmux$3397 $procmux$3263
	i_9_5c_fault_5b_15_3a_0_5d_ = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_logic__and_24_receiver_2e_v_3a_65_24_56__Y ? (p_pending.curr.slice<0>().val() ? i_4_5c_fault_5b_15_3a_0_5d_ : i_11_5c_fault_5b_15_3a_0_5d_.slice<15,4>().concat(i_12_5c_fault_5b_15_3a_0_5d_.slice<3,0>()).val()) : i_4_5c_fault_5b_15_3a_0_5d_) : value<16>{0u}));
	// cells $procmux$2750 $logic_or$receiver.v:79$73 $eq$receiver.v:79$71
	i_procmux_24_2750__Y.slice<2,0>() = (logic_or<1>(eq_uu<1>(p_seqb.curr, value<16>{0xffffu}), i_gt_24_receiver_2e_v_3a_118_24_153__Y) ? value<1>{0x1u}.concat(i_9_5c_fault_5b_15_3a_0_5d_.slice<1,0>()).val() : i_9_5c_fault_5b_15_3a_0_5d_.slice<2,0>().val());
	// connection
	i_procmux_24_2750__Y.slice<15,3>() = i_9_5c_fault_5b_15_3a_0_5d_.slice<15,3>().val();
	// cells $procmux$2598 $procmux$2595 $procmux$2593 $procmux$2099 $procmux$1851
	i_9_5c_qowner0_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_logic__and_24_receiver_2e_v_3a_89_24_91__Y ? (i_shiftx_24_receiver_2e_v_3a_91_24_94__Y ? i_7_5c_qowner1_5b_0_3a_0_5d_ : i_6_5c_qowner0_5b_0_3a_0_5d_) : i_6_5c_qowner0_5b_0_3a_0_5d_) : i_6_5c_qowner0_5b_0_3a_0_5d_) : value<1>{0u}));
	// cells $procmux$2607 $procmux$2604 $procmux$2602 $procmux$2111 $procmux$1866
	i_7_5c_qlen_5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_logic__and_24_receiver_2e_v_3a_89_24_91__Y ? (i_shiftx_24_receiver_2e_v_3a_91_24_94__Y ? i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4773.slice<1,0>().val() : i_5_5c_qlen_5b_1_3a_0_5d_) : i_5_5c_qlen_5b_1_3a_0_5d_) : i_5_5c_qlen_5b_1_3a_0_5d_) : value<2>{0u}));
	// cells $procmux$2010 $procmux$2007 $procmux$2005 $procmux$2003 $procmux$1626
	i_4_5c_failed_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_logic__and_24_receiver_2e_v_3a_89_24_91__Y ? (i_shiftx_24_receiver_2e_v_3a_91_24_94__Y ? p_failed.curr : value<1>{0x1u}) : p_failed.curr) : value<1>{0u}) : value<1>{0u}));
	// cells $procmux$1209 $procmux$1087
	i_5_5c_evblock_5b_0_3a_0_5d_ = (p_rone.curr ? (i_ne_24_receiver_2e_v_3a_104_24_119__Y ? value<1>{0u} : value<1>{0x1u}) : value<1>{0u});
	// \src: receiver.v:126.7-126.13
	// cell $gt$receiver.v:126$161
	i_gt_24_receiver_2e_v_3a_126_24_161__Y = gt_uu<1>(i_7_5c_qlen_5b_1_3a_0_5d_, value<1>{0u});
	// cells $procmux$427 $procmux$407
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4779.slice<0>() = (i_gt_24_receiver_2e_v_3a_126_24_161__Y ? (i_9_5c_qowner0_5b_0_3a_0_5d_ ? value<1>{0u} : value<1>{0x1u}) : value<1>{0u});
	// connection
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4779.slice<2,1>() = value<2>{0u};
	// cells $procmux$418 $procmux$395
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4781.slice<0>() = (i_gt_24_receiver_2e_v_3a_126_24_161__Y ? (i_9_5c_qowner0_5b_0_3a_0_5d_ ? value<1>{0x1u} : value<1>{0u}) : value<1>{0u});
	// connection
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4781.slice<2,1>() = value<2>{0u};
	// cells $procmux$2760 $procmux$2757 $procmux$2755 $procmux$2753
	i_16_5c_fault_5b_15_3a_0_5d_ = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_logic__and_24_receiver_2e_v_3a_76_24_70__Y ? (p_pending.curr.slice<1>().val() ? value<16>{0u} : i_9_5c_fault_5b_15_3a_0_5d_.slice<15,3>().concat(i_procmux_24_2750__Y.slice<2,0>()).val()) : value<16>{0u}) : value<16>{0u}));
	// cells $procmux$432 $procmux$429
	i_3_5c_tokensa_5b_2_3a_0_5d_ = (p_rst ? value<3>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? value<2>{0u}.concat(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4779.slice<0>()).val() : value<3>{0u}));
	// cells $procmux$1218 $procmux$1215 $procmux$1213 $procmux$1211
	i_5_5c_rone_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? value<1>{0u} : i_5_5c_evblock_5b_0_3a_0_5d_) : value<1>{0u}) : value<1>{0u}));
	// \full_case: 1
	// \src: receiver.v:82.14-82.21|receiver.v:82.11-83.32
	// cell $procmux$2657
	i_18_5c_fault_5b_15_3a_0_5d_.slice<3,0>() = (i_eq_24_receiver_2e_v_3a_82_24_80__Y ? i_16_5c_fault_5b_15_3a_0_5d_.slice<3,0>().val() : value<1>{0x1u}.concat(i_16_5c_fault_5b_15_3a_0_5d_.slice<2,0>()).val());
	// connection
	i_18_5c_fault_5b_15_3a_0_5d_.slice<15,4>() = i_16_5c_fault_5b_15_3a_0_5d_.slice<15,4>().val();
	// cells $procmux$423 $procmux$420
	i_3_5c_tokensb_5b_2_3a_0_5d_ = (p_rst ? value<3>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? value<2>{0u}.concat(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4781.slice<0>()).val() : value<3>{0u}));
	// cells $procmux$2082 $procmux$2079 $procmux$2077 $procmux$2075 $procmux$1821
	i_4_5c_rzero_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_logic__and_24_receiver_2e_v_3a_89_24_91__Y ? (i_shiftx_24_receiver_2e_v_3a_91_24_94__Y ? value<1>{0x1u} : p_rzero.curr) : p_rzero.curr) : value<1>{0u}) : value<1>{0u}));
	// \full_case: 1
	// \src: receiver.v:81.9-81.16|receiver.v:81.6-83.32
	// cell $procmux$2705
	i_17_5c_fault_5b_15_3a_0_5d_.slice<3,0>() = (i_eq_24_receiver_2e_v_3a_81_24_79__Y ? i_16_5c_fault_5b_15_3a_0_5d_.slice<3,0>().val() : i_18_5c_fault_5b_15_3a_0_5d_.slice<3,0>().val());
	// connection
	i_17_5c_fault_5b_15_3a_0_5d_.slice<15,4>() = i_16_5c_fault_5b_15_3a_0_5d_.slice<15,4>().val();
	// \src: receiver.v:127.7-127.13
	// cell $gt$receiver.v:127$164
	i_gt_24_receiver_2e_v_3a_127_24_164__Y = gt_uu<1>(i_7_5c_qlen_5b_1_3a_0_5d_, value<1>{0x1u});
	// cells $logic_and$receiver.v:108$122 $logic_not$receiver.v:108$121
	i_logic__and_24_receiver_2e_v_3a_108_24_122__Y = logic_and<1>(i_4_5c_rzero_5b_0_3a_0_5d_, logic_not<1>(i_5_5c_rone_5b_0_3a_0_5d_));
	// cells $procmux$2063 $procmux$1806
	i_4_5c_ownerzero_5b_0_3a_0_5d_ = (i_logic__and_24_receiver_2e_v_3a_89_24_91__Y ? (i_shiftx_24_receiver_2e_v_3a_91_24_94__Y ? i_6_5c_qowner0_5b_0_3a_0_5d_ : p_ownerzero.curr) : p_ownerzero.curr);
	// cells $procmux$3492 $procmux$3489 $procmux$3487
	i_3_5c_pending_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_logic__and_24_receiver_2e_v_3a_65_24_56__Y ? value<1>{0x1u} : p_pending.curr.slice<0>().val()) : value<1>{0u}));
	// cells $procmux$3054 $procmux$3051 $procmux$3049
	i_5_5c_pending_5b_1_3a_1_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_logic__and_24_receiver_2e_v_3a_76_24_70__Y ? value<1>{0x1u} : p_pending.curr.slice<1>().val()) : value<1>{0u}));
	// cells $procmux$1173 $procmux$1170 $procmux$1168 $procmux$1166 $procmux$1164 $procmux$1015
	i_5_5c_emitowner_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? value<1>{0u} : (p_rone.curr ? (i_ne_24_receiver_2e_v_3a_104_24_119__Y ? p_ownerone.curr : p_emitowner.curr) : p_emitowner.curr)) : value<1>{0u}) : value<1>{0u}));
	// cells $procmux$390 $procmux$387 $procmux$385 $procmux$365 $add$receiver.v:127$166
	i_5_5c_tokensa_5b_2_3a_0_5d_ = (p_rst ? value<3>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_gt_24_receiver_2e_v_3a_127_24_164__Y ? (i_7_5c_qowner1_5b_0_3a_0_5d_ ? i_3_5c_tokensa_5b_2_3a_0_5d_ : add_uu<3>(i_3_5c_tokensa_5b_2_3a_0_5d_, value<1>{0x1u})) : i_3_5c_tokensa_5b_2_3a_0_5d_) : value<3>{0u}));
	// cells $procmux$2964 $procmux$2961 $procmux$2959 $procmux$2825
	i_14_5c_fault_5b_15_3a_0_5d_ = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_logic__and_24_receiver_2e_v_3a_76_24_70__Y ? (p_pending.curr.slice<1>().val() ? i_9_5c_fault_5b_15_3a_0_5d_ : i_16_5c_fault_5b_15_3a_0_5d_.slice<15,4>().concat(i_17_5c_fault_5b_15_3a_0_5d_.slice<3,0>()).val()) : i_9_5c_fault_5b_15_3a_0_5d_) : value<16>{0u}));
	// cells $procmux$381 $procmux$378 $procmux$376 $procmux$353 $add$receiver.v:127$165
	i_5_5c_tokensb_5b_2_3a_0_5d_ = (p_rst ? value<3>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_gt_24_receiver_2e_v_3a_127_24_164__Y ? (i_7_5c_qowner1_5b_0_3a_0_5d_ ? add_uu<3>(i_3_5c_tokensb_5b_2_3a_0_5d_, value<1>{0x1u}) : i_3_5c_tokensb_5b_2_3a_0_5d_) : i_3_5c_tokensb_5b_2_3a_0_5d_) : value<3>{0u}));
	// cells $procmux$2580 $procmux$2577 $procmux$2575
	i_3_5c_ownerzero_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? i_4_5c_ownerzero_5b_0_3a_0_5d_ : p_ownerzero.curr) : value<1>{0u}));
	// \src: receiver.v:117.29-117.48
	// cell $neg$receiver.v:117$150
	i_neg_24_receiver_2e_v_3a_115_24_129__Y = neg_u<2>(i_5_5c_emitowner_5b_0_3a_0_5d_);
	// cells $procmux$628 $shiftx$receiver.v:114$126
	i_procmux_24_628__Y.slice<4,0>() = (shiftx_uu<1>(i_5_5c_pending_5b_1_3a_1_5d_.concat(i_3_5c_pending_5b_0_3a_0_5d_).val(), i_5_5c_emitowner_5b_0_3a_0_5d_) ? i_14_5c_fault_5b_15_3a_0_5d_.slice<4,0>().val() : value<1>{0x1u}.concat(i_14_5c_fault_5b_15_3a_0_5d_.slice<3,0>()).val());
	// cells $procmux$1203 $procmux$1200 $procmux$1198 $procmux$1196 $procmux$1194 $procmux$1033
	i_5_5c_evemit_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? value<1>{0u} : (p_rone.curr ? (i_ne_24_receiver_2e_v_3a_104_24_119__Y ? value<1>{0x1u} : value<1>{0u}) : value<1>{0u})) : value<1>{0u}) : value<1>{0u}));
	// connection
	i_procmux_24_628__Y.slice<15,5>() = i_14_5c_fault_5b_15_3a_0_5d_.slice<15,5>().val();
	// cells $procmux$2373 $procmux$2370 $procmux$2368 $procmux$1463 $procmux$885
	i_3_5c_rzero_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? i_4_5c_rzero_5b_0_3a_0_5d_ : (i_logic__and_24_receiver_2e_v_3a_108_24_122__Y ? value<1>{0u} : i_4_5c_rzero_5b_0_3a_0_5d_)) : p_rzero.curr) : value<1>{0u}));
	// \src: receiver.v:117.29-117.48
	// cell $shift$receiver.v:117$151
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4772.slice<1,0>() = shift_us<2>(value<1>{0x1u}, i_neg_24_receiver_2e_v_3a_115_24_129__Y);
	// \src: receiver.v:119.32-119.38
	// cell $mul$receiver.v:119$155
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4763.slice<4,0>() = mul_uu<5>(value<2>{0x3u}, p_cfgp);
	// connection
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4763.slice<31,5>() = value<27>{0u};
	// \src: receiver.v:119.57-119.63
	// cell $mul$receiver.v:119$158
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4760.slice<4,0>() = mul_uu<5>(value<2>{0x2u}, p_cfgp);
	// connection
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4760.slice<31,5>() = value<27>{0u};
	// \src: receiver.v:117.29-117.48
	// cell $not$receiver.v:117$148
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4771.slice<1,0>() = not_u<2>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4772.slice<1,0>().val());
	// \src: receiver.v:117.8-117.28
	// cell $shift$receiver.v:117$144
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4769.slice<1,0>() = shift_us<2>(value<1>{0u}, i_neg_24_receiver_2e_v_3a_115_24_129__Y);
	// cells $procmux$3474 $procmux$3471 $procmux$3469 $procmux$3215
	i_3_5c_pollen_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_logic__and_24_receiver_2e_v_3a_65_24_56__Y ? (p_pending.curr.slice<0>().val() ? value<1>{0u} : p_pollen.curr.slice<0>().val()) : p_pollen.curr.slice<0>().val()) : value<1>{0u}));
	// cells $procmux$3036 $procmux$3033 $procmux$3031 $procmux$2777
	i_5_5c_pollen_5b_1_3a_1_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_logic__and_24_receiver_2e_v_3a_76_24_70__Y ? (p_pending.curr.slice<1>().val() ? value<1>{0u} : p_pollen.curr.slice<1>().val()) : p_pollen.curr.slice<1>().val()) : value<1>{0u}));
	// cells $add$receiver.v:119$157 $add$receiver.v:119$156
	i_add_24_receiver_2e_v_3a_119_24_157__Y = add_uu<16>(add_uu<16>(p_tick.curr, i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4763.slice<4,0>().val()), value<1>{0x1u});
	// cells $add$receiver.v:119$160 $add$receiver.v:119$159
	i_add_24_receiver_2e_v_3a_119_24_160__Y = add_uu<16>(add_uu<16>(p_tick.curr, i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4760.slice<4,0>().val()), value<1>{0x1u});
	// cells $procmux$348 $procmux$345 $procmux$343 $procmux$323 $add$receiver.v:128$168
	i_7_5c_tokensa_5b_2_3a_0_5d_ = (p_rst ? value<3>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_3_5c_rzero_5b_0_3a_0_5d_ ? (i_3_5c_ownerzero_5b_0_3a_0_5d_ ? i_5_5c_tokensa_5b_2_3a_0_5d_ : add_uu<3>(i_5_5c_tokensa_5b_2_3a_0_5d_, value<1>{0x1u})) : i_5_5c_tokensa_5b_2_3a_0_5d_) : value<3>{0u}));
	// cells $or$receiver.v:115$135 $and$receiver.v:115$132
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4768.slice<1,0>() = or_uu<2>(and_uu<2>(i_5_5c_pending_5b_1_3a_1_5d_.concat(i_3_5c_pending_5b_0_3a_0_5d_).val(), i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4771.slice<1,0>().val()), i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4769.slice<1,0>().val());
	// cells $procmux$3483 $procmux$3480 $procmux$3478 $procmux$3227
	i_3_5c_waiting_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_logic__and_24_receiver_2e_v_3a_65_24_56__Y ? (p_pending.curr.slice<0>().val() ? value<1>{0x1u} : p_waiting.curr.slice<0>().val()) : p_waiting.curr.slice<0>().val()) : value<1>{0u}));
	// cells $procmux$3045 $procmux$3042 $procmux$3040 $procmux$2789
	i_5_5c_waiting_5b_1_3a_1_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_logic__and_24_receiver_2e_v_3a_76_24_70__Y ? (p_pending.curr.slice<1>().val() ? value<1>{0x1u} : p_waiting.curr.slice<1>().val()) : p_waiting.curr.slice<1>().val()) : value<1>{0u}));
	// cells $procmux$339 $procmux$336 $procmux$334 $procmux$311 $add$receiver.v:128$167
	i_7_5c_tokensb_5b_2_3a_0_5d_ = (p_rst ? value<3>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_3_5c_rzero_5b_0_3a_0_5d_ ? (i_3_5c_ownerzero_5b_0_3a_0_5d_ ? add_uu<3>(i_5_5c_tokensb_5b_2_3a_0_5d_, value<1>{0x1u}) : i_5_5c_tokensb_5b_2_3a_0_5d_) : i_5_5c_tokensb_5b_2_3a_0_5d_) : value<3>{0u}));
	// cells $procmux$2355 $procmux$2352 $procmux$2350 $procmux$1439 $procmux$930
	i_3_5c_ownerone_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? p_ownerone.curr : (i_logic__and_24_receiver_2e_v_3a_108_24_122__Y ? i_4_5c_ownerzero_5b_0_3a_0_5d_ : p_ownerone.curr)) : p_ownerone.curr) : value<1>{0u}));
	// \src: receiver.v:116.17-116.28
	// cell $shiftx$receiver.v:116$136
	i_procmux_24_443__CMP = shiftx_uu<1>(i_5_5c_waiting_5b_1_3a_1_5d_.concat(i_3_5c_waiting_5b_0_3a_0_5d_).val(), i_5_5c_emitowner_5b_0_3a_0_5d_);
	// cells $or$receiver.v:117$152 $and$receiver.v:117$149
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4764.slice<1,0>() = or_uu<2>(and_uu<2>(i_5_5c_pollen_5b_1_3a_1_5d_.concat(i_3_5c_pollen_5b_0_3a_0_5d_).val(), i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4771.slice<1,0>().val()), i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4772.slice<1,0>().val());
	// cells $procmux$3022 $procmux$2909
	i_3_5c_pollb_5b_15_3a_0_5d_ = (i_logic__and_24_receiver_2e_v_3a_76_24_70__Y ? (p_pending.curr.slice<1>().val() ? p_pollb.curr : i_add_24_receiver_2e_v_3a_119_24_157__Y) : p_pollb.curr);
	// cells $procmux$3460 $procmux$3347
	i_3_5c_polla_5b_15_3a_0_5d_ = (i_logic__and_24_receiver_2e_v_3a_65_24_56__Y ? (p_pending.curr.slice<0>().val() ? p_polla.curr : i_add_24_receiver_2e_v_3a_119_24_160__Y) : p_polla.curr);
	// \src: receiver.v:69.11-69.17
	// cell $add$receiver.v:69$61
	i_add_24_receiver_2e_v_3a_69_24_61__Y = add_uu<16>(p_seqa.curr, value<1>{0x1u});
	// cells $procmux$639 $procmux$636 $procmux$634 $procmux$632 $procmux$630
	i_22_5c_fault_5b_15_3a_0_5d_ = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? value<16>{0u} : (i_5_5c_evemit_5b_0_3a_0_5d_ ? i_14_5c_fault_5b_15_3a_0_5d_.slice<15,5>().concat(i_procmux_24_628__Y.slice<4,0>()).val() : value<16>{0u})) : value<16>{0u}) : value<16>{0u}));
	// cells $procmux$2364 $procmux$2361 $procmux$2359 $procmux$1451 $procmux$945
	i_3_5c_rone_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? p_rone.curr : (i_logic__and_24_receiver_2e_v_3a_108_24_122__Y ? value<1>{0x1u} : i_5_5c_rone_5b_0_3a_0_5d_)) : p_rone.curr) : value<1>{0u}));
	// cells $or$receiver.v:117$145 $and$receiver.v:117$142
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4766.slice<1,0>() = or_uu<2>(and_uu<2>(i_5_5c_waiting_5b_1_3a_1_5d_.concat(i_3_5c_waiting_5b_0_3a_0_5d_).val(), i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4771.slice<1,0>().val()), i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4769.slice<1,0>().val());
	// \full_case: 1
	// \src: receiver.v:118.11-118.21|receiver.v:118.8-118.43
	// cell $procmux$482
	i_24_5c_fault_5b_15_3a_0_5d_.slice<2,0>() = (i_gt_24_receiver_2e_v_3a_118_24_153__Y ? value<1>{0x1u}.concat(i_22_5c_fault_5b_15_3a_0_5d_.slice<1,0>()).val() : i_22_5c_fault_5b_15_3a_0_5d_.slice<2,0>().val());
	// connection
	i_24_5c_fault_5b_15_3a_0_5d_.slice<15,3>() = i_22_5c_fault_5b_15_3a_0_5d_.slice<15,3>().val();
	// \full_case: 1
	// \src: receiver.v:116.10-116.28|receiver.v:116.7-120.10
	// cell $procmux$538
	i_23_5c_fault_5b_15_3a_0_5d_.slice<2,0>() = (i_procmux_24_443__CMP ? i_24_5c_fault_5b_15_3a_0_5d_.slice<2,0>().val() : i_22_5c_fault_5b_15_3a_0_5d_.slice<2,0>().val());
	// connection
	i_23_5c_fault_5b_15_3a_0_5d_.slice<15,3>() = i_22_5c_fault_5b_15_3a_0_5d_.slice<15,3>().val();
	// cells $procmux$3415 $procmux$3287 $procmux$3113
	i_3_5c_qid0_5b_15_3a_0_5d_ = (i_logic__and_24_receiver_2e_v_3a_65_24_56__Y ? (p_pending.curr.slice<0>().val() ? p_qid0.curr : (i_eq_24_receiver_2e_v_3a_70_24_65__Y ? i_add_24_receiver_2e_v_3a_69_24_61__Y : p_qid0.curr)) : p_qid0.curr);
	// \src: receiver.v:80.11-80.17
	// cell $add$receiver.v:80$75
	i_add_24_receiver_2e_v_3a_80_24_75__Y = add_uu<16>(p_seqb.curr, value<1>{0x1u});
	// cells $procmux$306 $procmux$303 $procmux$301 $procmux$281 $add$receiver.v:129$170
	i_9_5c_tokensa_5b_2_3a_0_5d_ = (p_rst ? value<3>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_3_5c_rone_5b_0_3a_0_5d_ ? (i_3_5c_ownerone_5b_0_3a_0_5d_ ? i_7_5c_tokensa_5b_2_3a_0_5d_ : add_uu<3>(i_7_5c_tokensa_5b_2_3a_0_5d_, value<1>{0x1u})) : i_7_5c_tokensa_5b_2_3a_0_5d_) : value<3>{0u}));
	// cells $procmux$2418 $procmux$2415 $procmux$2413 $procmux$1355 $procmux$750
	i_7_5c_pending_5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? i_5_5c_pending_5b_1_3a_1_5d_.concat(i_3_5c_pending_5b_0_3a_0_5d_).val() : (i_5_5c_evemit_5b_0_3a_0_5d_ ? i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4768.slice<1,0>().val() : i_5_5c_pending_5b_1_3a_1_5d_.concat(i_3_5c_pending_5b_0_3a_0_5d_).val())) : i_5_5c_pending_5b_1_3a_1_5d_.concat(i_3_5c_pending_5b_0_3a_0_5d_).val()) : value<2>{0u}));
	// cells $procmux$297 $procmux$294 $procmux$292 $procmux$269 $add$receiver.v:129$169
	i_9_5c_tokensb_5b_2_3a_0_5d_ = (p_rst ? value<3>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_3_5c_rone_5b_0_3a_0_5d_ ? (i_3_5c_ownerone_5b_0_3a_0_5d_ ? add_uu<3>(i_7_5c_tokensb_5b_2_3a_0_5d_, value<1>{0x1u}) : i_7_5c_tokensb_5b_2_3a_0_5d_) : i_7_5c_tokensb_5b_2_3a_0_5d_) : value<3>{0u}));
	// cells $procmux$3406 $procmux$3275 $procmux$3158 $procmux$3059
	i_3_5c_qid1_5b_15_3a_0_5d_ = (i_logic__and_24_receiver_2e_v_3a_65_24_56__Y ? (p_pending.curr.slice<0>().val() ? p_qid1.curr : (i_eq_24_receiver_2e_v_3a_70_24_65__Y ? p_qid1.curr : (i_eq_24_receiver_2e_v_3a_71_24_66__Y ? i_add_24_receiver_2e_v_3a_69_24_61__Y : p_qid1.curr))) : p_qid1.curr);
	// \src: receiver.v:96.42-96.60
	// cell $neg$receiver.v:96$111
	i_neg_24_receiver_2e_v_3a_96_24_104__Y = neg_u<2>(i_6_5c_qowner0_5b_0_3a_0_5d_);
	// \full_case: 1
	// \src: receiver.v:52.7-52.24|receiver.v:52.4-52.80
	// cell $procmux$4018
	i_3_5c_dataa_5b_7_3a_0_5d_ = (i_logic__and_24_receiver_2e_v_3a_52_24_44__Y ? p_wua : p_dataa.curr);
	// \full_case: 1
	// \src: receiver.v:53.7-53.24|receiver.v:53.4-53.80
	// cell $procmux$3982
	i_3_5c_datab_5b_7_3a_0_5d_ = (i_logic__and_24_receiver_2e_v_3a_53_24_45__Y ? p_wub : p_datab.curr);
	// cells $procmux$2400 $procmux$2397 $procmux$2395 $procmux$1331 $procmux$720 $procmux$556
	i_7_5c_pollen_5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? i_5_5c_pollen_5b_1_3a_1_5d_.concat(i_3_5c_pollen_5b_0_3a_0_5d_).val() : (i_5_5c_evemit_5b_0_3a_0_5d_ ? (i_procmux_24_443__CMP ? i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4764.slice<1,0>().val() : i_5_5c_pollen_5b_1_3a_1_5d_.concat(i_3_5c_pollen_5b_0_3a_0_5d_).val()) : i_5_5c_pollen_5b_1_3a_1_5d_.concat(i_3_5c_pollen_5b_0_3a_0_5d_).val())) : i_5_5c_pollen_5b_1_3a_1_5d_.concat(i_3_5c_pollen_5b_0_3a_0_5d_).val()) : value<2>{0u}));
	// \src: receiver.v:96.42-96.60
	// cell $shift$receiver.v:96$108
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4778.slice<1,0>() = shift_us<2>(value<1>{0x1u}, i_neg_24_receiver_2e_v_3a_96_24_104__Y);
	// \src: receiver.v:94.17-94.36
	// cell $ternary$receiver.v:94$98
	i_ternary_24_receiver_2e_v_3a_94_24_98__Y = (i_6_5c_qowner0_5b_0_3a_0_5d_ ? i_3_5c_datab_5b_7_3a_0_5d_ : i_3_5c_dataa_5b_7_3a_0_5d_);
	// cells $procmux$2977 $procmux$2849 $procmux$2675
	i_6_5c_qid0_5b_15_3a_0_5d_ = (i_logic__and_24_receiver_2e_v_3a_76_24_70__Y ? (p_pending.curr.slice<1>().val() ? i_3_5c_qid0_5b_15_3a_0_5d_ : (i_eq_24_receiver_2e_v_3a_81_24_79__Y ? i_add_24_receiver_2e_v_3a_80_24_75__Y : i_3_5c_qid0_5b_15_3a_0_5d_)) : i_3_5c_qid0_5b_15_3a_0_5d_);
	// cells $procmux$3915 $procmux$3912 $procmux$3910 $procmux$3653 $procmux$3588 $procmux$3507
	i_5_5c_enabled_5b_1_3a_0_5d_.slice<1>() = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_54_24_46__Y ? (i_4_5c_enabled_5b_1_3a_1_5d_ ? (i_eq_24_receiver_2e_v_3a_60_24_51__Y ? value<1>{0x1u} : (i_eq_24_receiver_2e_v_3a_61_24_54__Y ? value<1>{0u} : value<1>{0x1u})) : value<1>{0u}) : i_4_5c_enabled_5b_1_3a_1_5d_) : value<1>{0u}));
	// cells $procmux$3897 $procmux$3894 $procmux$3892 $procmux$3842 $procmux$3777 $procmux$3696
	i_5_5c_enabled_5b_1_3a_0_5d_.slice<0>() = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_54_24_46__Y ? (i_3_5c_enabled_5b_0_3a_0_5d_ ? (i_eq_24_receiver_2e_v_3a_56_24_47__Y ? value<1>{0x1u} : (i_eq_24_receiver_2e_v_3a_57_24_50__Y ? value<1>{0u} : value<1>{0x1u})) : value<1>{0u}) : i_3_5c_enabled_5b_0_3a_0_5d_) : value<1>{0u}));
	// cells $procmux$2409 $procmux$2406 $procmux$2404 $procmux$1343 $procmux$735 $procmux$592
	i_7_5c_waiting_5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? i_5_5c_waiting_5b_1_3a_1_5d_.concat(i_3_5c_waiting_5b_0_3a_0_5d_).val() : (i_5_5c_evemit_5b_0_3a_0_5d_ ? (i_procmux_24_443__CMP ? i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4766.slice<1,0>().val() : i_5_5c_waiting_5b_1_3a_1_5d_.concat(i_3_5c_waiting_5b_0_3a_0_5d_).val()) : i_5_5c_waiting_5b_1_3a_1_5d_.concat(i_3_5c_waiting_5b_0_3a_0_5d_).val())) : i_5_5c_waiting_5b_1_3a_1_5d_.concat(i_3_5c_waiting_5b_0_3a_0_5d_).val()) : value<2>{0u}));
	// cells $procmux$2382 $procmux$2379 $procmux$2377 $procmux$1307 $procmux$690 $procmux$502 $procmux$440
	i_5_5c_pollb_5b_15_3a_0_5d_ = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? i_3_5c_pollb_5b_15_3a_0_5d_ : (i_5_5c_evemit_5b_0_3a_0_5d_ ? (i_procmux_24_443__CMP ? (i_5_5c_emitowner_5b_0_3a_0_5d_ ? i_add_24_receiver_2e_v_3a_119_24_157__Y : i_3_5c_pollb_5b_15_3a_0_5d_) : i_3_5c_pollb_5b_15_3a_0_5d_) : i_3_5c_pollb_5b_15_3a_0_5d_)) : i_3_5c_pollb_5b_15_3a_0_5d_) : value<16>{0u}));
	// cells $procmux$2391 $procmux$2388 $procmux$2386 $procmux$1319 $procmux$705 $procmux$520 $procmux$461
	i_5_5c_polla_5b_15_3a_0_5d_ = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? i_3_5c_polla_5b_15_3a_0_5d_ : (i_5_5c_evemit_5b_0_3a_0_5d_ ? (i_procmux_24_443__CMP ? (i_5_5c_emitowner_5b_0_3a_0_5d_ ? i_3_5c_polla_5b_15_3a_0_5d_ : i_add_24_receiver_2e_v_3a_119_24_160__Y) : i_3_5c_polla_5b_15_3a_0_5d_) : i_3_5c_polla_5b_15_3a_0_5d_)) : i_3_5c_polla_5b_15_3a_0_5d_) : value<16>{0u}));
	// \src: receiver.v:96.42-96.60
	// cell $not$receiver.v:96$109
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4777.slice<1,0>() = not_u<2>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4778.slice<1,0>().val());
	// cells $procmux$2328 $procmux$2325 $procmux$2323 $procmux$1295 $procmux$675
	i_19_5c_fault_5b_15_3a_0_5d_ = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? i_14_5c_fault_5b_15_3a_0_5d_ : (i_5_5c_evemit_5b_0_3a_0_5d_ ? i_22_5c_fault_5b_15_3a_0_5d_.slice<15,3>().concat(i_23_5c_fault_5b_15_3a_0_5d_.slice<2,0>()).val() : i_14_5c_fault_5b_15_3a_0_5d_)) : i_14_5c_fault_5b_15_3a_0_5d_) : value<16>{0u}));
	// cells $procmux$3883 $procmux$3641 $procmux$3573
	i_4_5c_countb_5b_2_3a_0_5d_ = (i_eq_24_receiver_2e_v_3a_54_24_46__Y ? (i_4_5c_enabled_5b_1_3a_1_5d_ ? (i_eq_24_receiver_2e_v_3a_60_24_51__Y ? i_3_5c_countb_5b_2_3a_0_5d_ : i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4785.slice<2,0>().val()) : i_3_5c_countb_5b_2_3a_0_5d_) : i_3_5c_countb_5b_2_3a_0_5d_);
	// cells $procmux$3919 $procmux$3830 $procmux$3762
	i_4_5c_counta_5b_2_3a_0_5d_ = (i_eq_24_receiver_2e_v_3a_54_24_46__Y ? (i_3_5c_enabled_5b_0_3a_0_5d_ ? (i_eq_24_receiver_2e_v_3a_56_24_47__Y ? i_3_5c_counta_5b_2_3a_0_5d_ : i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4786.slice<2,0>().val()) : i_3_5c_counta_5b_2_3a_0_5d_) : i_3_5c_counta_5b_2_3a_0_5d_);
	// \src: receiver.v:96.42-96.60
	// cell $shift$receiver.v:96$112
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4775.slice<1,0>() = shift_us<2>(value<1>{0u}, i_neg_24_receiver_2e_v_3a_96_24_104__Y);
	// cells $procmux$2039 $procmux$1776
	i_4_5c_bytezero_5b_7_3a_0_5d_ = (i_logic__and_24_receiver_2e_v_3a_89_24_91__Y ? (i_shiftx_24_receiver_2e_v_3a_91_24_94__Y ? i_ternary_24_receiver_2e_v_3a_94_24_98__Y : p_bytezero.curr) : p_bytezero.curr);
	// cells $procmux$1134 $procmux$997
	i_5_5c_emitid_5b_15_3a_0_5d_ = (p_rone.curr ? (i_ne_24_receiver_2e_v_3a_104_24_119__Y ? p_idone.curr : p_emitid.curr) : p_emitid.curr);
	// cells $procmux$2051 $procmux$1791
	i_4_5c_idzero_5b_15_3a_0_5d_ = (i_logic__and_24_receiver_2e_v_3a_89_24_91__Y ? (i_shiftx_24_receiver_2e_v_3a_91_24_94__Y ? i_6_5c_qid0_5b_15_3a_0_5d_ : p_idzero.curr) : p_idzero.curr);
	// cells $procmux$259 $logic_or$receiver.v:130$178 $logic_or$receiver.v:130$175 $logic_or$receiver.v:130$173 $gt$receiver.v:130$171 $ne$receiver.v:130$172 $ne$receiver.v:130$174 $gt$receiver.v:130$177 $add$receiver.v:130$176
	i_25_5c_fault_5b_15_3a_0_5d_.slice<5,0>() = (logic_or<1>(logic_or<1>(logic_or<1>(gt_uu<1>(i_7_5c_qlen_5b_1_3a_0_5d_, value<2>{0x2u}), ne_uu<1>(i_9_5c_tokensa_5b_2_3a_0_5d_, i_7_5c_pending_5b_1_3a_0_5d_.slice<0>().val())), ne_uu<1>(i_9_5c_tokensb_5b_2_3a_0_5d_, i_7_5c_pending_5b_1_3a_0_5d_.slice<1>().val())), gt_uu<1>(add_uu<4>(i_9_5c_tokensa_5b_2_3a_0_5d_, i_9_5c_tokensb_5b_2_3a_0_5d_), value<2>{0x2u})) ? value<1>{0x1u}.concat(i_19_5c_fault_5b_15_3a_0_5d_.slice<4,0>()).val() : i_19_5c_fault_5b_15_3a_0_5d_.slice<5,0>().val());
	// connection
	i_25_5c_fault_5b_15_3a_0_5d_.slice<15,6>() = i_19_5c_fault_5b_15_3a_0_5d_.slice<15,6>().val();
	// cells $procmux$2968 $procmux$2837 $procmux$2720 $procmux$2621
	i_7_5c_qid1_5b_15_3a_0_5d_ = (i_logic__and_24_receiver_2e_v_3a_76_24_70__Y ? (p_pending.curr.slice<1>().val() ? i_3_5c_qid1_5b_15_3a_0_5d_ : (i_eq_24_receiver_2e_v_3a_81_24_79__Y ? i_3_5c_qid1_5b_15_3a_0_5d_ : (i_eq_24_receiver_2e_v_3a_82_24_80__Y ? i_add_24_receiver_2e_v_3a_80_24_75__Y : i_3_5c_qid1_5b_15_3a_0_5d_))) : i_3_5c_qid1_5b_15_3a_0_5d_);
	// cells $or$receiver.v:96$113 $and$receiver.v:96$110
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4774.slice<1,0>() = or_uu<2>(and_uu<2>(i_5_5c_enabled_5b_1_3a_0_5d_, i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4777.slice<1,0>().val()), i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4775.slice<1,0>().val());
	// \src: receiver.v:137.63-137.76
	// cell $add$receiver.v:137$205
	i_add_24_receiver_2e_v_3a_137_24_203__Y = add_uu<6>(p_expiryphase.curr, value<1>{0x1u});
	// \src: receiver.v:136.55-136.67
	// cell $add$receiver.v:136$202
	i_add_24_receiver_2e_v_3a_136_24_200__Y = add_uu<4>(p_readyphase.curr, value<1>{0x1u});
	// \src: receiver.v:135.55-135.67
	// cell $add$receiver.v:135$199
	i_add_24_receiver_2e_v_3a_135_24_197__Y = add_uu<4>(p_cachephase.curr, value<1>{0x1u});
	// cells $procmux$250 $logic_or$receiver.v:131$186 $logic_and$receiver.v:131$182 $logic_or$receiver.v:131$181 $logic_not$receiver.v:131$180 $logic_and$receiver.v:131$185 $logic_or$receiver.v:131$184 $logic_not$receiver.v:131$183
	i_26_5c_fault_5b_15_3a_0_5d_.slice<6,0>() = (logic_or<1>(logic_and<1>(i_7_5c_waiting_5b_1_3a_0_5d_.slice<0>().val(), logic_or<1>(logic_not<1>(i_7_5c_pending_5b_1_3a_0_5d_.slice<0>().val()), i_7_5c_pollen_5b_1_3a_0_5d_.slice<0>().val())), logic_and<1>(i_7_5c_waiting_5b_1_3a_0_5d_.slice<1>().val(), logic_or<1>(logic_not<1>(i_7_5c_pending_5b_1_3a_0_5d_.slice<1>().val()), i_7_5c_pollen_5b_1_3a_0_5d_.slice<1>().val()))) ? value<1>{0x1u}.concat(i_25_5c_fault_5b_15_3a_0_5d_.slice<5,0>()).val() : i_19_5c_fault_5b_15_3a_0_5d_.slice<6>().concat(i_25_5c_fault_5b_15_3a_0_5d_.slice<5,0>()).val());
	// connection
	i_26_5c_fault_5b_15_3a_0_5d_.slice<15,7>() = i_19_5c_fault_5b_15_3a_0_5d_.slice<15,7>().val();
	// cells $procmux$241 $logic_or$receiver.v:132$192 $logic_and$receiver.v:132$189 $le$receiver.v:132$188 $logic_and$receiver.v:132$191 $le$receiver.v:132$190
	i_27_5c_fault_5b_15_3a_0_5d_.slice<7,0>() = (logic_or<1>(logic_and<1>(i_7_5c_pollen_5b_1_3a_0_5d_.slice<0>().val(), le_uu<1>(i_5_5c_polla_5b_15_3a_0_5d_, p_tick.curr)), logic_and<1>(i_7_5c_pollen_5b_1_3a_0_5d_.slice<1>().val(), le_uu<1>(i_5_5c_pollb_5b_15_3a_0_5d_, p_tick.curr))) ? value<1>{0x1u}.concat(i_26_5c_fault_5b_15_3a_0_5d_.slice<6,0>()).val() : i_19_5c_fault_5b_15_3a_0_5d_.slice<7>().concat(i_26_5c_fault_5b_15_3a_0_5d_.slice<6,0>()).val());
	// connection
	i_27_5c_fault_5b_15_3a_0_5d_.slice<15,8>() = i_19_5c_fault_5b_15_3a_0_5d_.slice<15,8>().val();
	// cells $procmux$3865 $procmux$3806 $procmux$3747 $procmux$3678
	i_3_5c_evexpire_5b_1_3a_0_5d_.slice<0>() = (i_eq_24_receiver_2e_v_3a_54_24_46__Y ? (i_3_5c_enabled_5b_0_3a_0_5d_ ? (i_eq_24_receiver_2e_v_3a_56_24_47__Y ? value<1>{0u} : (i_eq_24_receiver_2e_v_3a_57_24_50__Y ? value<1>{0x1u} : value<1>{0u})) : value<1>{0u}) : value<1>{0u});
	// cells $procmux$3496 $procmux$3617 $procmux$3558 $procmux$3939
	i_3_5c_evexpire_5b_1_3a_0_5d_.slice<1>() = (i_eq_24_receiver_2e_v_3a_54_24_46__Y ? (i_4_5c_enabled_5b_1_3a_1_5d_ ? (i_eq_24_receiver_2e_v_3a_60_24_51__Y ? value<1>{0u} : (i_eq_24_receiver_2e_v_3a_61_24_54__Y ? value<1>{0x1u} : value<1>{0u})) : value<1>{0u}) : value<1>{0u});
	// cells $procmux$232 $ge$receiver.v:133$194
	i_28_5c_fault_5b_15_3a_0_5d_.slice<8,0>() = (ge_uu<1>(p_tick.curr, value<16>{0xffebu}) ? value<1>{0x1u}.concat(i_27_5c_fault_5b_15_3a_0_5d_.slice<7,0>()).val() : i_19_5c_fault_5b_15_3a_0_5d_.slice<8>().concat(i_27_5c_fault_5b_15_3a_0_5d_.slice<7,0>()).val());
	// connection
	i_28_5c_fault_5b_15_3a_0_5d_.slice<15,9>() = i_19_5c_fault_5b_15_3a_0_5d_.slice<15,9>().val();
	// cells $procmux$4437 $procmux$3991
	i_2_5c_evwu_5b_1_3a_0_5d_.slice<0>() = (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_logic__and_24_receiver_2e_v_3a_52_24_44__Y ? value<1>{0x1u} : value<1>{0u}) : p_evwu.curr.slice<0>().val());
	// cells $procmux$207 $procmux$3955
	i_2_5c_evwu_5b_1_3a_0_5d_.slice<1>() = (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_logic__and_24_receiver_2e_v_3a_53_24_45__Y ? value<1>{0x1u} : value<1>{0u}) : p_evwu.curr.slice<1>().val());
	// cells $procmux$4449 $procmux$2941 $procmux$2813
	i_2_5c_evenq_5b_1_3a_0_5d_.slice<1>() = (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_logic__and_24_receiver_2e_v_3a_76_24_70__Y ? (p_pending.curr.slice<1>().val() ? value<1>{0u} : value<1>{0x1u}) : value<1>{0u}) : p_evenq.curr.slice<1>().val());
	// cells $procmux$4368 $procmux$3379 $procmux$3251
	i_2_5c_evenq_5b_1_3a_0_5d_.slice<0>() = (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_logic__and_24_receiver_2e_v_3a_65_24_56__Y ? (p_pending.curr.slice<0>().val() ? value<1>{0u} : value<1>{0x1u}) : value<1>{0u}) : p_evenq.curr.slice<0>().val());
	// cells $procmux$4404 $procmux$2950 $procmux$2765
	i_2_5c_evwait_5b_1_3a_0_5d_.slice<1>() = (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_logic__and_24_receiver_2e_v_3a_76_24_70__Y ? (p_pending.curr.slice<1>().val() ? value<1>{0x1u} : value<1>{0u}) : value<1>{0u}) : p_evwait.curr.slice<1>().val());
	// cells $procmux$4374 $procmux$3388 $procmux$3203
	i_2_5c_evwait_5b_1_3a_0_5d_.slice<0>() = (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_logic__and_24_receiver_2e_v_3a_65_24_56__Y ? (p_pending.curr.slice<0>().val() ? value<1>{0x1u} : value<1>{0u}) : value<1>{0u}) : p_evwait.curr.slice<0>().val());
	// cells $procdff$4743 $procmux$4569 $procmux$4026 $procmux$4411 $eq$receiver.v:137$204
	if (posedge_p_clk) {
		p_expiryphase.next = (p_rst ? value<5>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (eq_uu<1>(i_add_24_receiver_2e_v_3a_137_24_203__Y, value<1>{0u}.concat(p_cfgperiod).val()) ? value<5>{0u} : i_add_24_receiver_2e_v_3a_137_24_203__Y.slice<4,0>().val()) : p_expiryphase.curr));
	}
	// cells $procdff$4742 $procmux$4572 $procmux$4032 $procmux$214 $eq$receiver.v:136$201
	if (posedge_p_clk) {
		p_readyphase.next = (p_rst ? value<3>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (eq_uu<1>(i_add_24_receiver_2e_v_3a_136_24_200__Y, value<1>{0u}.concat(p_cfgr).val()) ? value<3>{0u} : i_add_24_receiver_2e_v_3a_136_24_200__Y.slice<2,0>().val()) : p_readyphase.curr));
	}
	// cells $procdff$4741 $procmux$4575 $procmux$4038 $procmux$223 $eq$receiver.v:135$198
	if (posedge_p_clk) {
		p_cachephase.next = (p_rst ? value<3>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (eq_uu<1>(i_add_24_receiver_2e_v_3a_135_24_197__Y, value<1>{0u}.concat(p_cfgp).val()) ? value<3>{0u} : i_add_24_receiver_2e_v_3a_135_24_197__Y.slice<2,0>().val()) : p_cachephase.curr));
	}
	// cells $procdff$4740 $procmux$4476 $procmux$4098 $procmux$2197 $procmux$1367 $procmux$825
	if (posedge_p_clk) {
		p_transferbyte.next = (p_rst ? value<8>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? p_transferbyte.curr : (i_logic__and_24_receiver_2e_v_3a_108_24_122__Y ? i_4_5c_bytezero_5b_7_3a_0_5d_ : p_transferbyte.curr)) : p_transferbyte.curr) : p_transferbyte.curr));
	}
	// cells $procdff$4739 $procmux$4479 $procmux$4104 $procmux$2206 $procmux$1475 $procmux$1104 $procmux$979 $ternary$receiver.v:105$120
	if (posedge_p_clk) {
		p_emitbyte.next = (p_rst ? value<8>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? p_emitbyte.curr : (p_rone.curr ? (i_ne_24_receiver_2e_v_3a_104_24_119__Y ? (p_ownerone.curr ? i_3_5c_datab_5b_7_3a_0_5d_ : i_3_5c_dataa_5b_7_3a_0_5d_) : p_emitbyte.curr) : p_emitbyte.curr)) : p_emitbyte.curr) : p_emitbyte.curr));
	}
	// cells $procdff$4738 $procmux$4482 $procmux$4110 $procmux$2440 $procmux$1919 $procmux$1671
	if (posedge_p_clk) {
		p_grantbyte.next = (p_rst ? value<8>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_logic__and_24_receiver_2e_v_3a_89_24_91__Y ? (i_shiftx_24_receiver_2e_v_3a_91_24_94__Y ? i_ternary_24_receiver_2e_v_3a_94_24_98__Y : p_grantbyte.curr) : p_grantbyte.curr) : p_grantbyte.curr) : p_grantbyte.curr));
	}
	// cells $procdff$4737 $procmux$4485 $procmux$4116 $procmux$2215 $procmux$1487 $procmux$1119 $procmux$1051
	if (posedge_p_clk) {
		p_blockid.next = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? p_blockid.curr : (p_rone.curr ? (i_ne_24_receiver_2e_v_3a_104_24_119__Y ? p_blockid.curr : p_idone.curr) : p_blockid.curr)) : p_blockid.curr) : p_blockid.curr));
	}
	// cells $procdff$4736 $procmux$4488 $procmux$4122 $procmux$2224 $procmux$1259 $procmux$780
	if (posedge_p_clk) {
		p_callbackid.next = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? p_callbackid.curr : (i_5_5c_evemit_5b_0_3a_0_5d_ ? i_5_5c_emitid_5b_15_3a_0_5d_ : p_callbackid.curr)) : p_callbackid.curr) : p_callbackid.curr));
	}
	// cells $procdff$4735 $procmux$4491 $procmux$4128 $procmux$2233 $procmux$1379 $procmux$840
	if (posedge_p_clk) {
		p_transferid.next = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? p_transferid.curr : (i_logic__and_24_receiver_2e_v_3a_108_24_122__Y ? i_4_5c_idzero_5b_15_3a_0_5d_ : p_transferid.curr)) : p_transferid.curr) : p_transferid.curr));
	}
	// cells $procdff$4734 $procmux$4494 $procmux$4134 $procmux$2242 $procmux$1499
	if (posedge_p_clk) {
		p_emitid.next = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? p_emitid.curr : i_5_5c_emitid_5b_15_3a_0_5d_) : p_emitid.curr) : p_emitid.curr));
	}
	// cells $procdff$4733 $procmux$4497 $procmux$4140 $procmux$2449 $procmux$1931 $procmux$1686
	if (posedge_p_clk) {
		p_grantid.next = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_logic__and_24_receiver_2e_v_3a_89_24_91__Y ? (i_shiftx_24_receiver_2e_v_3a_91_24_94__Y ? i_6_5c_qid0_5b_15_3a_0_5d_ : p_grantid.curr) : p_grantid.curr) : p_grantid.curr) : p_grantid.curr));
	}
	// cells $procdff$4732 $procmux$4500 $procmux$4146 $procmux$2458 $procmux$2135
	if (posedge_p_clk) {
		p_attemptid.next = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_logic__and_24_receiver_2e_v_3a_89_24_91__Y ? i_6_5c_qid0_5b_15_3a_0_5d_ : p_attemptid.curr) : p_attemptid.curr) : p_attemptid.curr));
	}
	// cells $procdff$4731 $procmux$4503 $procmux$4152 $procmux$2251 $procmux$1511 $procmux$1149 $procmux$1069
	if (posedge_p_clk) {
		p_blockowner.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? p_blockowner.curr : (p_rone.curr ? (i_ne_24_receiver_2e_v_3a_104_24_119__Y ? p_blockowner.curr : p_ownerone.curr) : p_blockowner.curr)) : p_blockowner.curr) : p_blockowner.curr));
	}
	// cells $procdff$4730 $procmux$4506 $procmux$4158 $procmux$2260 $procmux$1271 $procmux$795
	if (posedge_p_clk) {
		p_callbackowner.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? p_callbackowner.curr : (i_5_5c_evemit_5b_0_3a_0_5d_ ? i_5_5c_emitowner_5b_0_3a_0_5d_ : p_callbackowner.curr)) : p_callbackowner.curr) : p_callbackowner.curr));
	}
	// cells $procdff$4729 $procmux$4509 $procmux$4164 $procmux$2269 $procmux$1391 $procmux$855
	if (posedge_p_clk) {
		p_transferowner.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? p_transferowner.curr : (i_logic__and_24_receiver_2e_v_3a_108_24_122__Y ? i_4_5c_ownerzero_5b_0_3a_0_5d_ : p_transferowner.curr)) : p_transferowner.curr) : p_transferowner.curr));
	}
	// cells $procdff$4728 $procmux$4512 $procmux$4170 $procmux$2278 $procmux$1523
	if (posedge_p_clk) {
		p_emitowner.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? p_emitowner.curr : i_5_5c_emitowner_5b_0_3a_0_5d_) : p_emitowner.curr) : p_emitowner.curr));
	}
	// cells $procdff$4727 $procmux$4515 $procmux$4176 $procmux$2467 $procmux$1943 $procmux$1701
	if (posedge_p_clk) {
		p_grantowner.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_logic__and_24_receiver_2e_v_3a_89_24_91__Y ? (i_shiftx_24_receiver_2e_v_3a_91_24_94__Y ? i_6_5c_qowner0_5b_0_3a_0_5d_ : p_grantowner.curr) : p_grantowner.curr) : p_grantowner.curr) : p_grantowner.curr));
	}
	// cells $procdff$4726 $procmux$4518 $procmux$4182 $procmux$2476 $procmux$2147
	if (posedge_p_clk) {
		p_attemptowner.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_logic__and_24_receiver_2e_v_3a_89_24_91__Y ? i_6_5c_qowner0_5b_0_3a_0_5d_ : p_attemptowner.curr) : p_attemptowner.curr) : p_attemptowner.curr));
	}
	// cells $procdff$4725 $procmux$4521 $procmux$4188 $procmux$2287 $procmux$1535
	if (posedge_p_clk) {
		p_evblock.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? value<1>{0u} : i_5_5c_evblock_5b_0_3a_0_5d_) : value<1>{0u}) : p_evblock.curr));
	}
	// cells $procdff$4724 $procmux$4524 $procmux$4194 $procmux$2296 $procmux$1283 $procmux$810
	if (posedge_p_clk) {
		p_evcallback.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? value<1>{0u} : (i_5_5c_evemit_5b_0_3a_0_5d_ ? value<1>{0x1u} : value<1>{0u})) : value<1>{0u}) : p_evcallback.curr));
	}
	// cells $procdff$4723 $procmux$4527 $procmux$4200 $procmux$2305 $procmux$1403 $procmux$870
	if (posedge_p_clk) {
		p_evtransfer.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_108_24_122__Y ? value<1>{0x1u} : value<1>{0u})) : value<1>{0u}) : p_evtransfer.curr));
	}
	// cells $procdff$4722 $procmux$4530 $procmux$4206 $procmux$2314 $procmux$1547
	if (posedge_p_clk) {
		p_evemit.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? value<1>{0u} : i_5_5c_evemit_5b_0_3a_0_5d_) : value<1>{0u}) : p_evemit.curr));
	}
	// cells $procdff$4721 $procmux$4533 $procmux$4212 $procmux$2485 $procmux$1955 $procmux$1716
	if (posedge_p_clk) {
		p_evgrant.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_logic__and_24_receiver_2e_v_3a_89_24_91__Y ? (i_shiftx_24_receiver_2e_v_3a_91_24_94__Y ? value<1>{0x1u} : value<1>{0u}) : value<1>{0u}) : value<1>{0u}) : p_evgrant.curr));
	}
	// cells $procdff$4720 $procmux$4536 $procmux$4218 $procmux$2494 $procmux$2159
	if (posedge_p_clk) {
		p_evattempt.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_logic__and_24_receiver_2e_v_3a_89_24_91__Y ? value<1>{0x1u} : value<1>{0u}) : value<1>{0u}) : p_evattempt.curr));
	}
	// cells $procdff$4719 $procmux$4539 $procmux$4362 $procmux$2932 $procmux$2801
	if (posedge_p_clk) {
		p_enqidb.next = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_logic__and_24_receiver_2e_v_3a_76_24_70__Y ? (p_pending.curr.slice<1>().val() ? p_enqidb.curr : i_add_24_receiver_2e_v_3a_80_24_75__Y) : p_enqidb.curr) : p_enqidb.curr));
	}
	// cells $procdff$4718 $procmux$4542 $procmux$4398 $procmux$3370 $procmux$3239
	if (posedge_p_clk) {
		p_enqida.next = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_logic__and_24_receiver_2e_v_3a_65_24_56__Y ? (p_pending.curr.slice<0>().val() ? p_enqida.curr : i_add_24_receiver_2e_v_3a_69_24_61__Y) : p_enqida.curr) : p_enqida.curr));
	}
	// cells $procdff$4717 $procmux$4545
	if (posedge_p_clk) {
		p_evwu.next = (p_rst ? value<2>{0u} : i_2_5c_evwu_5b_1_3a_0_5d_);
	}
	// cells $procdff$4716 $procmux$4548 $procmux$4224 $procmux$2503 $procmux$1967 $procmux$1731 $shift$receiver.v:96$105 $shiftx$receiver.v:96$103
	if (posedge_p_clk) {
		p_evcancel.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_logic__and_24_receiver_2e_v_3a_89_24_91__Y ? (i_shiftx_24_receiver_2e_v_3a_91_24_94__Y ? shift_us<2>(shiftx_uu<1>(i_5_5c_enabled_5b_1_3a_0_5d_, i_6_5c_qowner0_5b_0_3a_0_5d_), i_neg_24_receiver_2e_v_3a_96_24_104__Y) : value<2>{0u}) : value<2>{0u}) : value<2>{0u}) : p_evcancel.curr));
	}
	// cells $procdff$4715 $procmux$4551 $procmux$4425
	if (posedge_p_clk) {
		p_evexpire.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? i_3_5c_evexpire_5b_1_3a_0_5d_ : p_evexpire.curr));
	}
	// cells $procdff$4714 $procmux$4554
	if (posedge_p_clk) {
		p_evenq.next = (p_rst ? value<2>{0u} : i_2_5c_evenq_5b_1_3a_0_5d_);
	}
	// cells $procdff$4713 $procmux$4557
	if (posedge_p_clk) {
		p_evwait.next = (p_rst ? value<2>{0u} : i_2_5c_evwait_5b_1_3a_0_5d_);
	}
	// cells $procdff$4712 $procmux$4473 $procmux$4050 $procmux$4468 $logic_or$receiver.v:46$35 $logic_or$receiver.v:46$33 $logic_or$receiver.v:46$31 $logic_or$receiver.v:46$29 $logic_or$receiver.v:46$27 $logic_or$receiver.v:46$25 $logic_or$receiver.v:46$23 $logic_or$receiver.v:46$19 $lt$receiver.v:46$17 $gt$receiver.v:46$18 $logic_and$receiver.v:46$22 $ne$receiver.v:46$20 $ne$receiver.v:46$21 $ge$receiver.v:46$24 $lt$receiver.v:46$26 $gt$receiver.v:46$28 $lt$receiver.v:46$30 $gt$receiver.v:46$32 $ge$receiver.v:46$34
	if (posedge_p_clk) {
		p_fault.next = (p_rst ? value<15>{0u}.concat((logic_or<1>(logic_or<1>(logic_or<1>(logic_or<1>(logic_or<1>(logic_or<1>(logic_or<1>(logic_or<1>(lt_uu<1>(p_cfgp, value<2>{0x2u}), gt_uu<1>(p_cfgp, value<3>{0x6u})), logic_and<1>(ne_uu<1>(p_cfgr, value<2>{0x3u}), ne_uu<1>(p_cfgr, value<3>{0x5u}))), ge_uu<1>(p_cfgb, p_cfgp)), lt_uu<1>(p_cfgk, value<1>{0x1u})), gt_uu<1>(p_cfgk, value<3>{0x5u})), lt_uu<1>(p_cfgperiod, value<1>{0x1u})), gt_uu<1>(p_cfgperiod, value<5>{0x18u})), ge_uu<1>(p_cfgphi, p_cfgperiod)) ? value<1>{0x1u} : value<1>{0u})).val() : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? i_19_5c_fault_5b_15_3a_0_5d_.slice<15,9>().concat(i_28_5c_fault_5b_15_3a_0_5d_.slice<8,0>()).val() : p_fault.curr));
	}
	// cells $procdff$4711 $procmux$4578 $procmux$4230 $procmux$2512 $procmux$1979 $procmux$1611
	if (posedge_p_clk) {
		p_failtick.next = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_logic__and_24_receiver_2e_v_3a_89_24_91__Y ? (i_shiftx_24_receiver_2e_v_3a_91_24_94__Y ? p_failtick.curr : p_tick.curr) : p_failtick.curr) : p_failtick.curr) : p_failtick.curr));
	}
	// cells $procdff$4710 $procmux$4581 $procmux$4236 $procmux$2521 $procmux$1991 $procmux$1596
	if (posedge_p_clk) {
		p_failowner.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_logic__and_24_receiver_2e_v_3a_89_24_91__Y ? (i_shiftx_24_receiver_2e_v_3a_91_24_94__Y ? p_failowner.curr : i_6_5c_qowner0_5b_0_3a_0_5d_) : p_failowner.curr) : p_failowner.curr) : p_failowner.curr));
	}
	// cells $procdff$4709 $procmux$4584 $procmux$4242 $procmux$2530
	if (posedge_p_clk) {
		p_failed.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? i_4_5c_failed_5b_0_3a_0_5d_ : p_failed.curr) : p_failed.curr));
	}
	// cells $procdff$4708 $procmux$4593 $procmux$4248 $procmux$2539 $procmux$2015 $procmux$1746 $procmux$1560
	if (posedge_p_clk) {
		p_countb.next = (p_rst ? value<3>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_logic__and_24_receiver_2e_v_3a_89_24_91__Y ? (i_shiftx_24_receiver_2e_v_3a_91_24_94__Y ? (i_6_5c_qowner0_5b_0_3a_0_5d_ ? value<3>{0u} : i_4_5c_countb_5b_2_3a_0_5d_) : i_4_5c_countb_5b_2_3a_0_5d_) : i_4_5c_countb_5b_2_3a_0_5d_) : i_4_5c_countb_5b_2_3a_0_5d_) : p_countb.curr));
	}
	// cells $procdff$4707 $procmux$4596 $procmux$4254 $procmux$2548 $procmux$2027 $procmux$1761 $procmux$1578
	if (posedge_p_clk) {
		p_counta.next = (p_rst ? value<3>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_logic__and_24_receiver_2e_v_3a_89_24_91__Y ? (i_shiftx_24_receiver_2e_v_3a_91_24_94__Y ? (i_6_5c_qowner0_5b_0_3a_0_5d_ ? i_4_5c_counta_5b_2_3a_0_5d_ : value<3>{0u}) : i_4_5c_counta_5b_2_3a_0_5d_) : i_4_5c_counta_5b_2_3a_0_5d_) : i_4_5c_counta_5b_2_3a_0_5d_) : p_counta.curr));
	}
	// cells $procdff$4706 $procmux$4599 $procmux$4443
	if (posedge_p_clk) {
		p_datab.next = (p_rst ? value<8>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? i_3_5c_datab_5b_7_3a_0_5d_ : p_datab.curr));
	}
	// cells $procdff$4705 $procmux$4602 $procmux$4455
	if (posedge_p_clk) {
		p_dataa.next = (p_rst ? value<8>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? i_3_5c_dataa_5b_7_3a_0_5d_ : p_dataa.curr));
	}
	// cells $procdff$4704 $procmux$4605 $procmux$4260 $procmux$2332 $procmux$1415 $procmux$900
	if (posedge_p_clk) {
		p_byteone.next = (p_rst ? value<8>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? p_byteone.curr : (i_logic__and_24_receiver_2e_v_3a_108_24_122__Y ? i_4_5c_bytezero_5b_7_3a_0_5d_ : p_byteone.curr)) : p_byteone.curr) : p_byteone.curr));
	}
	// cells $procdff$4703 $procmux$4608 $procmux$4266 $procmux$2557
	if (posedge_p_clk) {
		p_bytezero.next = (p_rst ? value<8>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? i_4_5c_bytezero_5b_7_3a_0_5d_ : p_bytezero.curr) : p_bytezero.curr));
	}
	// cells $procdff$4702 $procmux$4611 $procmux$4272 $procmux$2341 $procmux$1427 $procmux$915
	if (posedge_p_clk) {
		p_idone.next = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? p_idone.curr : (i_logic__and_24_receiver_2e_v_3a_108_24_122__Y ? i_4_5c_idzero_5b_15_3a_0_5d_ : p_idone.curr)) : p_idone.curr) : p_idone.curr));
	}
	// cells $procdff$4701 $procmux$4614 $procmux$4278 $procmux$2566
	if (posedge_p_clk) {
		p_idzero.next = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? i_4_5c_idzero_5b_15_3a_0_5d_ : p_idzero.curr) : p_idzero.curr));
	}
	// cells $procdff$4700 $procmux$4617 $procmux$4284
	if (posedge_p_clk) {
		p_ownerone.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? i_3_5c_ownerone_5b_0_3a_0_5d_ : p_ownerone.curr));
	}
	// cells $procdff$4699 $procmux$4620 $procmux$4290
	if (posedge_p_clk) {
		p_ownerzero.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? i_3_5c_ownerzero_5b_0_3a_0_5d_ : p_ownerzero.curr));
	}
	// cells $procdff$4698 $procmux$4623 $procmux$4296
	if (posedge_p_clk) {
		p_rone.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? i_3_5c_rone_5b_0_3a_0_5d_ : p_rone.curr));
	}
	// cells $procdff$4697 $procmux$4626 $procmux$4302
	if (posedge_p_clk) {
		p_rzero.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? i_3_5c_rzero_5b_0_3a_0_5d_ : p_rzero.curr));
	}
	// cells $procdff$4696 $procmux$4629 $procmux$4380
	if (posedge_p_clk) {
		p_qid1.next = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? i_7_5c_qid1_5b_15_3a_0_5d_ : p_qid1.curr));
	}
	// cells $procdff$4695 $procmux$4632 $procmux$4308 $procmux$2584 $procmux$2087 $procmux$1836
	if (posedge_p_clk) {
		p_qid0.next = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_logic__and_24_receiver_2e_v_3a_89_24_91__Y ? (i_shiftx_24_receiver_2e_v_3a_91_24_94__Y ? i_7_5c_qid1_5b_15_3a_0_5d_ : i_6_5c_qid0_5b_15_3a_0_5d_) : i_6_5c_qid0_5b_15_3a_0_5d_) : i_6_5c_qid0_5b_15_3a_0_5d_) : p_qid0.curr));
	}
	// cells $procdff$4694 $procmux$4635 $procmux$4386
	if (posedge_p_clk) {
		p_qowner1.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? i_7_5c_qowner1_5b_0_3a_0_5d_ : p_qowner1.curr));
	}
	// cells $procdff$4693 $procmux$4638 $procmux$4314
	if (posedge_p_clk) {
		p_qowner0.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? i_9_5c_qowner0_5b_0_3a_0_5d_ : p_qowner0.curr));
	}
	// cells $procdff$4692 $procmux$4641 $procmux$4320
	if (posedge_p_clk) {
		p_qlen.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? i_7_5c_qlen_5b_1_3a_0_5d_ : p_qlen.curr));
	}
	// cells $procdff$4691 $procmux$4644 $procmux$4392 $procmux$3013 $procmux$2897
	if (posedge_p_clk) {
		p_seqb.next = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_logic__and_24_receiver_2e_v_3a_76_24_70__Y ? (p_pending.curr.slice<1>().val() ? p_seqb.curr : i_add_24_receiver_2e_v_3a_80_24_75__Y) : p_seqb.curr) : p_seqb.curr));
	}
	// cells $procdff$4690 $procmux$4647 $procmux$4419 $procmux$3451 $procmux$3335
	if (posedge_p_clk) {
		p_seqa.next = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_logic__and_24_receiver_2e_v_3a_65_24_56__Y ? (p_pending.curr.slice<0>().val() ? p_seqa.curr : i_add_24_receiver_2e_v_3a_69_24_61__Y) : p_seqa.curr) : p_seqa.curr));
	}
	// cells $procdff$4689 $procmux$4650 $procmux$4326
	if (posedge_p_clk) {
		p_pollb.next = (p_rst ? value<13>{0u}.concat(p_cfgb).val() : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? i_5_5c_pollb_5b_15_3a_0_5d_ : p_pollb.curr));
	}
	// cells $procdff$4688 $procmux$4653 $procmux$4332
	if (posedge_p_clk) {
		p_polla.next = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? i_5_5c_polla_5b_15_3a_0_5d_ : p_polla.curr));
	}
	// cells $procdff$4687 $procmux$4587 $procmux$4338 $procmux$2611 $procmux$2123 $procmux$1881
	if (posedge_p_clk) {
		p_enabled.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? (i_eq_24_receiver_2e_v_3a_87_24_83__Y ? (i_logic__and_24_receiver_2e_v_3a_89_24_91__Y ? (i_shiftx_24_receiver_2e_v_3a_91_24_94__Y ? i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4774.slice<1,0>().val() : i_5_5c_enabled_5b_1_3a_0_5d_) : i_5_5c_enabled_5b_1_3a_0_5d_) : i_5_5c_enabled_5b_1_3a_0_5d_) : p_enabled.curr));
	}
	// cells $procdff$4686 $procmux$4590 $procmux$4431
	if (posedge_p_clk) {
		p_valid.next = (p_rst ? value<2>{0x3u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? i_3_5c_valid_5b_1_3a_0_5d_ : p_valid.curr));
	}
	// cells $procdff$4685 $procmux$4656 $procmux$4344
	if (posedge_p_clk) {
		p_pollen.next = (p_rst ? value<2>{0x3u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? i_7_5c_pollen_5b_1_3a_0_5d_ : p_pollen.curr));
	}
	// cells $procdff$4684 $procmux$4659 $procmux$4350
	if (posedge_p_clk) {
		p_waiting.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? i_7_5c_waiting_5b_1_3a_0_5d_ : p_waiting.curr));
	}
	// cells $procdff$4683 $procmux$4662 $procmux$4356
	if (posedge_p_clk) {
		p_pending.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_38__Y ? i_7_5c_pending_5b_1_3a_0_5d_ : p_pending.curr));
	}
	// cells $procdff$4682 $procmux$4665 $procmux$4044 $add$receiver.v:134$196
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
