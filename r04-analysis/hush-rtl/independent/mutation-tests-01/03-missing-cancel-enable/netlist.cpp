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
	// \src: receiver.v:33.2-139.5
	wire<16> i_14_5c_fault_5b_15_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	wire<16> i_15_5c_fault_5b_15_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	wire<16> i_9_5c_fault_5b_15_3a_0_5d_;
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
		if (i_14_5c_fault_5b_15_3a_0_5d_.commit(observer)) changed = true;
		if (i_15_5c_fault_5b_15_3a_0_5d_.commit(observer)) changed = true;
		if (i_9_5c_fault_5b_15_3a_0_5d_.commit(observer)) changed = true;
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
	bool converged = false;
	bool posedge_p_clk = this->posedge_p_clk();
	// \src: receiver.v:33.2-139.5
	value<16> i_11_5c_fault_5b_15_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<16> i_12_5c_fault_5b_15_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<16> i_13_5c_fault_5b_15_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<16> i_16_5c_fault_5b_15_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<16> i_17_5c_fault_5b_15_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<16> i_18_5c_fault_5b_15_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<16> i_19_5c_fault_5b_15_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<16> i_20_5c_fault_5b_15_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<16> i_21_5c_fault_5b_15_3a_0_5d_;
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
	value<1> i_9_5c_qowner0_5b_0_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<3> i_9_5c_tokensa_5b_2_3a_0_5d_;
	// \src: receiver.v:33.2-139.5
	value<3> i_9_5c_tokensb_5b_2_3a_0_5d_;
	value<16> i_add_24_receiver_2e_v_3a_119_24_142__Y;
	value<16> i_add_24_receiver_2e_v_3a_119_24_145__Y;
	value<4> i_add_24_receiver_2e_v_3a_135_24_182__Y;
	value<4> i_add_24_receiver_2e_v_3a_136_24_185__Y;
	value<6> i_add_24_receiver_2e_v_3a_137_24_188__Y;
	value<16> i_add_24_receiver_2e_v_3a_69_24_57__Y;
	value<16> i_add_24_receiver_2e_v_3a_80_24_71__Y;
	// \src: receiver.v:119.57-119.63
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4663;
	// \src: receiver.v:119.32-119.38
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4666;
	// \src: receiver.v:117.29-117.48
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4667;
	value<3> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4669;
	// \src: receiver.v:117.8-117.28
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4670;
	// \src: receiver.v:115.7-115.27
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4672;
	// \src: receiver.v:115.7-115.27
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4673;
	// \src: receiver.v:115.7-115.27
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4675;
	// \src: receiver.v:115.7-115.27
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4676;
	// \src: receiver.v:98.38-98.44
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4677;
	// \src: receiver.v:61.24-61.32
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4682;
	// \src: receiver.v:57.24-57.32
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4683;
	value<3> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4685;
	// \src: receiver.v:54.7-54.26
	value<1> i_eq_24_receiver_2e_v_3a_54_24_42__Y;
	// \src: receiver.v:56.9-56.18
	value<1> i_eq_24_receiver_2e_v_3a_56_24_43__Y;
	// \src: receiver.v:57.36-57.45
	value<1> i_eq_24_receiver_2e_v_3a_57_24_46__Y;
	// \src: receiver.v:60.9-60.18
	value<1> i_eq_24_receiver_2e_v_3a_60_24_47__Y;
	// \src: receiver.v:61.36-61.45
	value<1> i_eq_24_receiver_2e_v_3a_61_24_50__Y;
	// \src: receiver.v:70.9-70.16
	value<1> i_eq_24_receiver_2e_v_3a_70_24_61__Y;
	// \src: receiver.v:71.14-71.21
	value<1> i_eq_24_receiver_2e_v_3a_71_24_62__Y;
	// \src: receiver.v:81.9-81.16
	value<1> i_eq_24_receiver_2e_v_3a_81_24_75__Y;
	// \src: receiver.v:82.14-82.21
	value<1> i_eq_24_receiver_2e_v_3a_82_24_76__Y;
	// \src: receiver.v:87.7-87.20
	value<1> i_eq_24_receiver_2e_v_3a_87_24_79__Y;
	// \src: receiver.v:118.11-118.21
	value<1> i_gt_24_receiver_2e_v_3a_118_24_138__Y;
	// \src: receiver.v:126.7-126.13
	value<1> i_gt_24_receiver_2e_v_3a_126_24_146__Y;
	// \src: receiver.v:127.7-127.13
	value<1> i_gt_24_receiver_2e_v_3a_127_24_149__Y;
	// \src: receiver.v:108.9-108.23
	value<1> i_logic__and_24_receiver_2e_v_3a_108_24_107__Y;
	// \src: receiver.v:47.16-47.35
	value<1> i_logic__and_24_receiver_2e_v_3a_47_24_35__Y;
	// \src: receiver.v:52.7-52.24
	value<1> i_logic__and_24_receiver_2e_v_3a_52_24_40__Y;
	// \src: receiver.v:53.7-53.24
	value<1> i_logic__and_24_receiver_2e_v_3a_53_24_41__Y;
	// \src: receiver.v:65.7-65.31
	value<1> i_logic__and_24_receiver_2e_v_3a_65_24_52__Y;
	// \src: receiver.v:76.7-76.31
	value<1> i_logic__and_24_receiver_2e_v_3a_76_24_66__Y;
	// \src: receiver.v:89.8-89.29
	value<1> i_logic__and_24_receiver_2e_v_3a_89_24_86__Y;
	// \src: receiver.v:104.10-104.23
	value<1> i_ne_24_receiver_2e_v_3a_104_24_105__Y;
	// \src: receiver.v:115.7-115.27
	value<2> i_neg_24_receiver_2e_v_3a_115_24_114__Y;
	value<16> i_procmux_24_2254__Y;
	value<16> i_procmux_24_3101__Y;
	value<16> i_procmux_24_3731__Y;
	value<1> i_procmux_24_428__CMP;
	// \src: receiver.v:91.15-91.24
	value<1> i_shiftx_24_receiver_2e_v_3a_91_24_88__Y;
	// \src: receiver.v:94.17-94.36
	value<8> i_ternary_24_receiver_2e_v_3a_94_24_91__Y;
	// connection
	i_6_5c_fault_5b_15_3a_0_5d_.slice<15,2>() = p_fault.curr.slice<15,2>().val();
	// connection
	i_procmux_24_3731__Y.slice<15,2>() = p_fault.curr.slice<15,2>().val();
	// \src: receiver.v:53.7-53.24
	// cell $logic_and$receiver.v:53$41
	i_logic__and_24_receiver_2e_v_3a_53_24_41__Y = logic_and<1>(p_wu.slice<1>().val(), p_valid.curr.slice<1>().val());
	// \src: receiver.v:52.7-52.24
	// cell $logic_and$receiver.v:52$40
	i_logic__and_24_receiver_2e_v_3a_52_24_40__Y = logic_and<1>(p_wu.slice<0>().val(), p_valid.curr.slice<0>().val());
	// \src: receiver.v:118.11-118.21
	// cell $gt$receiver.v:118$138
	i_gt_24_receiver_2e_v_3a_118_24_138__Y = gt_uu<1>(p_tick.curr, value<16>{0xffebu});
	// \src: receiver.v:54.7-54.26
	// cell $eq$receiver.v:54$42
	i_eq_24_receiver_2e_v_3a_54_24_42__Y = eq_uu<1>(p_expiryphase.curr, p_cfgphi);
	// \src: receiver.v:70.9-70.16
	// cell $eq$receiver.v:70$61
	i_eq_24_receiver_2e_v_3a_70_24_61__Y = logic_not<1>(p_qlen.curr);
	// \src: receiver.v:71.14-71.21
	// cell $eq$receiver.v:71$62
	i_eq_24_receiver_2e_v_3a_71_24_62__Y = eq_uu<1>(p_qlen.curr, value<1>{0x1u});
	// cells $logic_and$receiver.v:65$52 $eq$receiver.v:65$51
	i_logic__and_24_receiver_2e_v_3a_65_24_52__Y = logic_and<1>(p_pollen.curr.slice<0>().val(), eq_uu<1>(p_polla.curr, p_tick.curr));
	// cells $logic_and$receiver.v:76$66 $eq$receiver.v:76$65
	i_logic__and_24_receiver_2e_v_3a_76_24_66__Y = logic_and<1>(p_pollen.curr.slice<1>().val(), eq_uu<1>(p_pollb.curr, p_tick.curr));
	// cells $logic_and$receiver.v:47$35 $logic_not$receiver.v:47$33 $eq$receiver.v:47$34
	i_logic__and_24_receiver_2e_v_3a_47_24_35__Y = logic_and<1>(logic_not<1>(p_failed.curr), logic_not<1>(p_fault.curr));
	// cells $procmux$3891 $procmux$3888 $procmux$3886
	i_4_5c_enabled_5b_1_3a_1_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_logic__and_24_receiver_2e_v_3a_53_24_41__Y ? value<1>{0x1u} : p_enabled.curr.slice<1>().val()) : value<1>{0u}));
	// cells $procmux$3882 $procmux$3879 $procmux$3877
	i_3_5c_countb_5b_2_3a_0_5d_ = (p_rst ? value<3>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_logic__and_24_receiver_2e_v_3a_53_24_41__Y ? p_cfgk : p_countb.curr) : value<3>{0u}));
	// cells $procmux$3927 $procmux$3924 $procmux$3922
	i_3_5c_enabled_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_logic__and_24_receiver_2e_v_3a_52_24_40__Y ? value<1>{0x1u} : p_enabled.curr.slice<0>().val()) : value<1>{0u}));
	// cells $procmux$3918 $procmux$3915 $procmux$3913
	i_3_5c_counta_5b_2_3a_0_5d_ = (p_rst ? value<3>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_logic__and_24_receiver_2e_v_3a_52_24_40__Y ? p_cfgk : p_counta.curr) : value<3>{0u}));
	// cells $procmux$3360 $procmux$3357 $procmux$3355 $procmux$3236 $add$receiver.v:73$64
	i_3_5c_qlen_5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_logic__and_24_receiver_2e_v_3a_65_24_52__Y ? (p_pending.curr.slice<0>().val() ? p_qlen.curr : add_uu<2>(p_qlen.curr, value<1>{0x1u})) : p_qlen.curr) : value<2>{0u}));
	// \src: receiver.v:60.9-60.18
	// cell $eq$receiver.v:60$47
	i_eq_24_receiver_2e_v_3a_60_24_47__Y = logic_not<1>(i_3_5c_countb_5b_2_3a_0_5d_);
	// \src: receiver.v:56.9-56.18
	// cell $eq$receiver.v:56$43
	i_eq_24_receiver_2e_v_3a_56_24_43__Y = logic_not<1>(i_3_5c_counta_5b_2_3a_0_5d_);
	// \src: receiver.v:81.9-81.16
	// cell $eq$receiver.v:81$75
	i_eq_24_receiver_2e_v_3a_81_24_75__Y = logic_not<1>(i_3_5c_qlen_5b_1_3a_0_5d_);
	// \src: receiver.v:82.14-82.21
	// cell $eq$receiver.v:82$76
	i_eq_24_receiver_2e_v_3a_82_24_76__Y = eq_uu<1>(i_3_5c_qlen_5b_1_3a_0_5d_, value<1>{0x1u});
	// \full_case: 1
	// \src: receiver.v:56.9-56.18|receiver.v:56.6-57.97
	// cell $procmux$3645
	i_6_5c_fault_5b_15_3a_0_5d_.slice<1,0>() = (i_eq_24_receiver_2e_v_3a_56_24_43__Y ? value<1>{0x1u}.concat(p_fault.curr.slice<0>()).val() : p_fault.curr.slice<1,0>().val());
	// \full_case: 1
	// \src: receiver.v:55.8-55.18|receiver.v:55.5-58.8
	// cell $procmux$3731
	i_procmux_24_3731__Y.slice<1,0>() = (i_3_5c_enabled_5b_0_3a_0_5d_ ? i_6_5c_fault_5b_15_3a_0_5d_.slice<1,0>().val() : p_fault.curr.slice<1,0>().val());
	// cells $procmux$3738 $procmux$3735 $procmux$3733
	i_5_5c_fault_5b_15_3a_0_5d_ = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_eq_24_receiver_2e_v_3a_54_24_42__Y ? p_fault.curr.slice<15,2>().concat(i_procmux_24_3731__Y.slice<1,0>()).val() : value<16>{0u}) : value<16>{0u}));
	// connection
	i_8_5c_fault_5b_15_3a_0_5d_.slice<15,2>() = i_5_5c_fault_5b_15_3a_0_5d_.slice<15,2>().val();
	// connection
	i_7_5c_fault_5b_15_3a_0_5d_.slice<15,2>() = i_5_5c_fault_5b_15_3a_0_5d_.slice<15,2>().val();
	// \full_case: 1
	// \src: receiver.v:60.9-60.18|receiver.v:60.6-61.97
	// cell $procmux$3456
	i_8_5c_fault_5b_15_3a_0_5d_.slice<1,0>() = (i_eq_24_receiver_2e_v_3a_60_24_47__Y ? value<1>{0x1u}.concat(i_5_5c_fault_5b_15_3a_0_5d_.slice<0>()).val() : i_5_5c_fault_5b_15_3a_0_5d_.slice<1,0>().val());
	// \full_case: 1
	// \src: receiver.v:59.8-59.18|receiver.v:59.5-62.8
	// cell $procmux$3542
	i_7_5c_fault_5b_15_3a_0_5d_.slice<1,0>() = (i_4_5c_enabled_5b_1_3a_1_5d_ ? i_8_5c_fault_5b_15_3a_0_5d_.slice<1,0>().val() : i_5_5c_fault_5b_15_3a_0_5d_.slice<1,0>().val());
	// cells $procmux$3792 $procmux$3789 $procmux$3787
	i_4_5c_fault_5b_15_3a_0_5d_ = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_eq_24_receiver_2e_v_3a_54_24_42__Y ? i_5_5c_fault_5b_15_3a_0_5d_.slice<15,2>().concat(i_7_5c_fault_5b_15_3a_0_5d_.slice<1,0>()).val() : p_fault.curr) : value<16>{0u}));
	// connection
	i_procmux_24_3101__Y.slice<15,3>() = i_4_5c_fault_5b_15_3a_0_5d_.slice<15,3>().val();
	// cells $procmux$3101 $logic_or$receiver.v:68$55 $eq$receiver.v:68$53
	i_procmux_24_3101__Y.slice<2,0>() = (logic_or<1>(eq_uu<1>(p_seqa.curr, value<16>{0xffffu}), i_gt_24_receiver_2e_v_3a_118_24_138__Y) ? value<1>{0x1u}.concat(i_4_5c_fault_5b_15_3a_0_5d_.slice<1,0>()).val() : i_4_5c_fault_5b_15_3a_0_5d_.slice<2,0>().val());
	// cells $procmux$3111 $procmux$3108 $procmux$3106 $procmux$3104
	i_11_5c_fault_5b_15_3a_0_5d_ = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_logic__and_24_receiver_2e_v_3a_65_24_52__Y ? (p_pending.curr.slice<0>().val() ? value<16>{0u} : i_4_5c_fault_5b_15_3a_0_5d_.slice<15,3>().concat(i_procmux_24_3101__Y.slice<2,0>()).val()) : value<16>{0u}) : value<16>{0u}));
	// connection
	i_13_5c_fault_5b_15_3a_0_5d_.slice<15,4>() = i_11_5c_fault_5b_15_3a_0_5d_.slice<15,4>().val();
	// connection
	i_12_5c_fault_5b_15_3a_0_5d_.slice<15,4>() = i_11_5c_fault_5b_15_3a_0_5d_.slice<15,4>().val();
	// \full_case: 1
	// \src: receiver.v:71.14-71.21|receiver.v:71.11-72.32
	// cell $procmux$3008
	i_13_5c_fault_5b_15_3a_0_5d_.slice<3,0>() = (i_eq_24_receiver_2e_v_3a_71_24_62__Y ? i_11_5c_fault_5b_15_3a_0_5d_.slice<3,0>().val() : value<1>{0x1u}.concat(i_11_5c_fault_5b_15_3a_0_5d_.slice<2,0>()).val());
	// \full_case: 1
	// \src: receiver.v:70.9-70.16|receiver.v:70.6-72.32
	// cell $procmux$3056
	i_12_5c_fault_5b_15_3a_0_5d_.slice<3,0>() = (i_eq_24_receiver_2e_v_3a_70_24_61__Y ? i_11_5c_fault_5b_15_3a_0_5d_.slice<3,0>().val() : i_13_5c_fault_5b_15_3a_0_5d_.slice<3,0>().val());
	// cells $procmux$3315 $procmux$3312 $procmux$3310 $procmux$3176
	i_14_5c_fault_5b_15_3a_0_5d_.next.slice<15,4>().concat(i_16_5c_fault_5b_15_3a_0_5d_.slice<3>()).concat(i_9_5c_fault_5b_15_3a_0_5d_.next.slice<2,0>()) = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_logic__and_24_receiver_2e_v_3a_65_24_52__Y ? (p_pending.curr.slice<0>().val() ? i_4_5c_fault_5b_15_3a_0_5d_ : i_11_5c_fault_5b_15_3a_0_5d_.slice<15,4>().concat(i_12_5c_fault_5b_15_3a_0_5d_.slice<3,0>()).val()) : i_4_5c_fault_5b_15_3a_0_5d_) : value<16>{0u}));
	// connection
	i_16_5c_fault_5b_15_3a_0_5d_.slice<15,4>() = i_14_5c_fault_5b_15_3a_0_5d_.curr.slice<15,4>().val();
	// cells $procmux$2663 $logic_or$receiver.v:79$69 $eq$receiver.v:79$67
	i_16_5c_fault_5b_15_3a_0_5d_.slice<2,0>() = (logic_or<1>(eq_uu<1>(p_seqb.curr, value<16>{0xffffu}), i_gt_24_receiver_2e_v_3a_118_24_138__Y) ? value<1>{0x1u}.concat(i_9_5c_fault_5b_15_3a_0_5d_.curr.slice<1,0>()).val() : i_9_5c_fault_5b_15_3a_0_5d_.curr.slice<2,0>().val());
	// \full_case: 1
	// \src: receiver.v:82.14-82.21|receiver.v:82.11-83.32
	// cell $procmux$2570
	i_18_5c_fault_5b_15_3a_0_5d_.slice<3,0>() = (i_eq_24_receiver_2e_v_3a_82_24_76__Y ? i_16_5c_fault_5b_15_3a_0_5d_.slice<3,0>().val() : value<1>{0x1u}.concat(i_16_5c_fault_5b_15_3a_0_5d_.slice<2,0>()).val());
	// connection
	i_9_5c_fault_5b_15_3a_0_5d_.next.slice<15,3>() = i_14_5c_fault_5b_15_3a_0_5d_.curr.slice<15,4>().concat(i_16_5c_fault_5b_15_3a_0_5d_.slice<3>()).val();
	// \full_case: 1
	// \src: receiver.v:76.7-76.31|receiver.v:76.4-86.7
	// cell $procmux$2872
	i_14_5c_fault_5b_15_3a_0_5d_.next.slice<3,0>() = (i_logic__and_24_receiver_2e_v_3a_76_24_66__Y ? i_15_5c_fault_5b_15_3a_0_5d_.curr.slice<3,0>().val() : i_16_5c_fault_5b_15_3a_0_5d_.slice<3>().concat(i_9_5c_fault_5b_15_3a_0_5d_.curr.slice<2,0>()).val());
	// connection
	i_18_5c_fault_5b_15_3a_0_5d_.slice<15,4>() = i_14_5c_fault_5b_15_3a_0_5d_.curr.slice<15,4>().val();
	// connection
	i_17_5c_fault_5b_15_3a_0_5d_.slice<15,4>() = i_14_5c_fault_5b_15_3a_0_5d_.curr.slice<15,4>().val();
	// \full_case: 1
	// \src: receiver.v:81.9-81.16|receiver.v:81.6-83.32
	// cell $procmux$2618
	i_17_5c_fault_5b_15_3a_0_5d_.slice<3,0>() = (i_eq_24_receiver_2e_v_3a_81_24_75__Y ? i_16_5c_fault_5b_15_3a_0_5d_.slice<3,0>().val() : i_18_5c_fault_5b_15_3a_0_5d_.slice<3,0>().val());
	// connection
	i_15_5c_fault_5b_15_3a_0_5d_.next.slice<15,4>() = i_14_5c_fault_5b_15_3a_0_5d_.curr.slice<15,4>().val();
	// \full_case: 1
	// \src: receiver.v:77.8-77.18|receiver.v:77.5-85.8
	// cell $procmux$2738
	i_15_5c_fault_5b_15_3a_0_5d_.next.slice<3,0>() = (p_pending.curr.slice<1>().val() ? i_16_5c_fault_5b_15_3a_0_5d_.slice<3>().concat(i_9_5c_fault_5b_15_3a_0_5d_.curr.slice<2,0>()).val() : i_17_5c_fault_5b_15_3a_0_5d_.slice<3,0>().val());
	// \src: receiver.v:61.24-61.32
	// cell $sub$receiver.v:61$49
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4682.slice<2,0>() = sub_uu<3>(i_3_5c_countb_5b_2_3a_0_5d_, value<1>{0x1u});
	// \src: receiver.v:57.24-57.32
	// cell $sub$receiver.v:57$45
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4683.slice<2,0>() = sub_uu<3>(i_3_5c_counta_5b_2_3a_0_5d_, value<1>{0x1u});
	// \src: receiver.v:61.36-61.45
	// cell $eq$receiver.v:61$50
	i_eq_24_receiver_2e_v_3a_61_24_50__Y = logic_not<1>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4682.slice<2,0>().val());
	// \src: receiver.v:57.36-57.45
	// cell $eq$receiver.v:57$46
	i_eq_24_receiver_2e_v_3a_57_24_46__Y = logic_not<1>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4683.slice<2,0>().val());
	// cells $procmux$3346 $procmux$3224 $procmux$3041
	i_3_5c_qowner0_5b_0_3a_0_5d_ = (i_logic__and_24_receiver_2e_v_3a_65_24_52__Y ? (p_pending.curr.slice<0>().val() ? p_qowner0.curr : (i_eq_24_receiver_2e_v_3a_70_24_61__Y ? value<1>{0u} : p_qowner0.curr)) : p_qowner0.curr);
	// cells $procmux$3337 $procmux$3212 $procmux$3086 $procmux$2990
	i_3_5c_qowner1_5b_0_3a_0_5d_ = (i_logic__and_24_receiver_2e_v_3a_65_24_52__Y ? (p_pending.curr.slice<0>().val() ? p_qowner1.curr : (i_eq_24_receiver_2e_v_3a_70_24_61__Y ? p_qowner1.curr : (i_eq_24_receiver_2e_v_3a_71_24_62__Y ? value<1>{0u} : p_qowner1.curr))) : p_qowner1.curr);
	// cells $procmux$3846 $procmux$3843 $procmux$3841 $procmux$3578 $procmux$3516 $procmux$3438
	i_3_5c_valid_5b_1_3a_0_5d_.slice<1>() = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_eq_24_receiver_2e_v_3a_54_24_42__Y ? (i_4_5c_enabled_5b_1_3a_1_5d_ ? (i_eq_24_receiver_2e_v_3a_60_24_47__Y ? p_valid.curr.slice<1>().val() : (i_eq_24_receiver_2e_v_3a_61_24_50__Y ? value<1>{0u} : p_valid.curr.slice<1>().val())) : p_valid.curr.slice<1>().val()) : p_valid.curr.slice<1>().val()) : value<1>{0u}));
	// cells $procmux$3819 $procmux$3816 $procmux$3814 $procmux$3767 $procmux$3705 $procmux$3627
	i_3_5c_valid_5b_1_3a_0_5d_.slice<0>() = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_eq_24_receiver_2e_v_3a_54_24_42__Y ? (i_3_5c_enabled_5b_0_3a_0_5d_ ? (i_eq_24_receiver_2e_v_3a_56_24_43__Y ? p_valid.curr.slice<0>().val() : (i_eq_24_receiver_2e_v_3a_57_24_46__Y ? value<1>{0u} : p_valid.curr.slice<0>().val())) : p_valid.curr.slice<0>().val()) : p_valid.curr.slice<0>().val()) : value<1>{0u}));
	// cells $procmux$2913 $procmux$2910 $procmux$2908 $procmux$2786 $procmux$2603
	i_6_5c_qowner0_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_logic__and_24_receiver_2e_v_3a_76_24_66__Y ? (p_pending.curr.slice<1>().val() ? i_3_5c_qowner0_5b_0_3a_0_5d_ : (i_eq_24_receiver_2e_v_3a_81_24_75__Y ? value<1>{0x1u} : i_3_5c_qowner0_5b_0_3a_0_5d_)) : i_3_5c_qowner0_5b_0_3a_0_5d_) : value<1>{0u}));
	// cells $procmux$2922 $procmux$2919 $procmux$2917 $procmux$2798 $add$receiver.v:84$78
	i_5_5c_qlen_5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_logic__and_24_receiver_2e_v_3a_76_24_66__Y ? (p_pending.curr.slice<1>().val() ? i_3_5c_qlen_5b_1_3a_0_5d_ : add_uu<2>(i_3_5c_qlen_5b_1_3a_0_5d_, value<1>{0x1u})) : i_3_5c_qlen_5b_1_3a_0_5d_) : value<2>{0u}));
	// \src: receiver.v:91.15-91.24
	// cell $shiftx$receiver.v:91$88
	i_shiftx_24_receiver_2e_v_3a_91_24_88__Y = shiftx_uu<1>(i_3_5c_valid_5b_1_3a_0_5d_, i_6_5c_qowner0_5b_0_3a_0_5d_);
	// cells $procmux$2904 $procmux$2901 $procmux$2899 $procmux$2774 $procmux$2648 $procmux$2552
	i_7_5c_qowner1_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_logic__and_24_receiver_2e_v_3a_76_24_66__Y ? (p_pending.curr.slice<1>().val() ? i_3_5c_qowner1_5b_0_3a_0_5d_ : (i_eq_24_receiver_2e_v_3a_81_24_75__Y ? i_3_5c_qowner1_5b_0_3a_0_5d_ : (i_eq_24_receiver_2e_v_3a_82_24_76__Y ? value<1>{0x1u} : i_3_5c_qowner1_5b_0_3a_0_5d_))) : i_3_5c_qowner1_5b_0_3a_0_5d_) : value<1>{0u}));
	// \src: receiver.v:98.38-98.44
	// cell $sub$receiver.v:98$100
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4677.slice<1,0>() = sub_uu<2>(i_5_5c_qlen_5b_1_3a_0_5d_, value<1>{0x1u});
	// cells $logic_and$receiver.v:89$86 $logic_not$receiver.v:89$84 $ne$receiver.v:89$85
	i_logic__and_24_receiver_2e_v_3a_89_24_86__Y = logic_and<1>(logic_not<1>(p_rzero.curr), reduce_bool<1>(i_5_5c_qlen_5b_1_3a_0_5d_));
	// \src: receiver.v:87.7-87.20
	// cell $eq$receiver.v:87$79
	i_eq_24_receiver_2e_v_3a_87_24_79__Y = logic_not<1>(p_cachephase.curr);
	// \src: receiver.v:104.10-104.23
	// cell $ne$receiver.v:104$105
	i_ne_24_receiver_2e_v_3a_104_24_105__Y = ne_uu<1>(p_readyphase.curr, value<1>{0x1u});
	// cells $procmux$2520 $procmux$2517 $procmux$2515 $procmux$2042 $procmux$1821
	i_9_5c_qowner0_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_eq_24_receiver_2e_v_3a_87_24_79__Y ? (i_logic__and_24_receiver_2e_v_3a_89_24_86__Y ? (i_shiftx_24_receiver_2e_v_3a_91_24_88__Y ? i_7_5c_qowner1_5b_0_3a_0_5d_ : i_6_5c_qowner0_5b_0_3a_0_5d_) : i_6_5c_qowner0_5b_0_3a_0_5d_) : i_6_5c_qowner0_5b_0_3a_0_5d_) : value<1>{0u}));
	// cells $procmux$2529 $procmux$2526 $procmux$2524 $procmux$2054 $procmux$1836
	i_7_5c_qlen_5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_eq_24_receiver_2e_v_3a_87_24_79__Y ? (i_logic__and_24_receiver_2e_v_3a_89_24_86__Y ? (i_shiftx_24_receiver_2e_v_3a_91_24_88__Y ? i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4677.slice<1,0>().val() : i_5_5c_qlen_5b_1_3a_0_5d_) : i_5_5c_qlen_5b_1_3a_0_5d_) : i_5_5c_qlen_5b_1_3a_0_5d_) : value<2>{0u}));
	// cells $procmux$1953 $procmux$1950 $procmux$1948 $procmux$1946 $procmux$1611
	i_4_5c_failed_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_eq_24_receiver_2e_v_3a_87_24_79__Y ? (i_logic__and_24_receiver_2e_v_3a_89_24_86__Y ? (i_shiftx_24_receiver_2e_v_3a_91_24_88__Y ? p_failed.curr : value<1>{0x1u}) : p_failed.curr) : value<1>{0u}) : value<1>{0u}));
	// cells $procmux$1194 $procmux$1072
	i_5_5c_evblock_5b_0_3a_0_5d_ = (p_rone.curr ? (i_ne_24_receiver_2e_v_3a_104_24_105__Y ? value<1>{0u} : value<1>{0x1u}) : value<1>{0u});
	// \src: receiver.v:126.7-126.13
	// cell $gt$receiver.v:126$146
	i_gt_24_receiver_2e_v_3a_126_24_146__Y = gt_uu<1>(i_7_5c_qlen_5b_1_3a_0_5d_, value<1>{0u});
	// cells $procmux$412 $procmux$392
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4685.slice<0>() = (i_gt_24_receiver_2e_v_3a_126_24_146__Y ? (i_9_5c_qowner0_5b_0_3a_0_5d_ ? value<1>{0u} : value<1>{0x1u}) : value<1>{0u});
	// connection
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4685.slice<2,1>() = value<2>{0u};
	// cells $procmux$403 $procmux$380
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4669.slice<0>() = (i_gt_24_receiver_2e_v_3a_126_24_146__Y ? (i_9_5c_qowner0_5b_0_3a_0_5d_ ? value<1>{0x1u} : value<1>{0u}) : value<1>{0u});
	// connection
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4669.slice<2,1>() = value<2>{0u};
	// cells $procmux$417 $procmux$414
	i_3_5c_tokensa_5b_2_3a_0_5d_ = (p_rst ? value<3>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? value<2>{0u}.concat(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4685.slice<0>()).val() : value<3>{0u}));
	// cells $procmux$1203 $procmux$1200 $procmux$1198 $procmux$1196
	i_5_5c_rone_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_eq_24_receiver_2e_v_3a_87_24_79__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? value<1>{0u} : i_5_5c_evblock_5b_0_3a_0_5d_) : value<1>{0u}) : value<1>{0u}));
	// cells $procmux$408 $procmux$405
	i_3_5c_tokensb_5b_2_3a_0_5d_ = (p_rst ? value<3>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? value<2>{0u}.concat(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4669.slice<0>()).val() : value<3>{0u}));
	// cells $procmux$2025 $procmux$2022 $procmux$2020 $procmux$2018 $procmux$1791
	i_4_5c_rzero_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_eq_24_receiver_2e_v_3a_87_24_79__Y ? (i_logic__and_24_receiver_2e_v_3a_89_24_86__Y ? (i_shiftx_24_receiver_2e_v_3a_91_24_88__Y ? value<1>{0x1u} : p_rzero.curr) : p_rzero.curr) : value<1>{0u}) : value<1>{0u}));
	// \src: receiver.v:127.7-127.13
	// cell $gt$receiver.v:127$149
	i_gt_24_receiver_2e_v_3a_127_24_149__Y = gt_uu<1>(i_7_5c_qlen_5b_1_3a_0_5d_, value<1>{0x1u});
	// cells $logic_and$receiver.v:108$107 $logic_not$receiver.v:108$106
	i_logic__and_24_receiver_2e_v_3a_108_24_107__Y = logic_and<1>(i_4_5c_rzero_5b_0_3a_0_5d_, logic_not<1>(i_5_5c_rone_5b_0_3a_0_5d_));
	// cells $procmux$2006 $procmux$1776
	i_4_5c_ownerzero_5b_0_3a_0_5d_ = (i_logic__and_24_receiver_2e_v_3a_89_24_86__Y ? (i_shiftx_24_receiver_2e_v_3a_91_24_88__Y ? i_6_5c_qowner0_5b_0_3a_0_5d_ : p_ownerzero.curr) : p_ownerzero.curr);
	// cells $procmux$375 $procmux$372 $procmux$370 $procmux$350 $add$receiver.v:127$151
	i_5_5c_tokensa_5b_2_3a_0_5d_ = (p_rst ? value<3>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_gt_24_receiver_2e_v_3a_127_24_149__Y ? (i_7_5c_qowner1_5b_0_3a_0_5d_ ? i_3_5c_tokensa_5b_2_3a_0_5d_ : add_uu<3>(i_3_5c_tokensa_5b_2_3a_0_5d_, value<1>{0x1u})) : i_3_5c_tokensa_5b_2_3a_0_5d_) : value<3>{0u}));
	// cells $procmux$1158 $procmux$1155 $procmux$1153 $procmux$1151 $procmux$1149 $procmux$1000
	i_5_5c_emitowner_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_eq_24_receiver_2e_v_3a_87_24_79__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? value<1>{0u} : (p_rone.curr ? (i_ne_24_receiver_2e_v_3a_104_24_105__Y ? p_ownerone.curr : p_emitowner.curr) : p_emitowner.curr)) : value<1>{0u}) : value<1>{0u}));
	// cells $procmux$366 $procmux$363 $procmux$361 $procmux$338 $add$receiver.v:127$150
	i_5_5c_tokensb_5b_2_3a_0_5d_ = (p_rst ? value<3>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_gt_24_receiver_2e_v_3a_127_24_149__Y ? (i_7_5c_qowner1_5b_0_3a_0_5d_ ? add_uu<3>(i_3_5c_tokensb_5b_2_3a_0_5d_, value<1>{0x1u}) : i_3_5c_tokensb_5b_2_3a_0_5d_) : i_3_5c_tokensb_5b_2_3a_0_5d_) : value<3>{0u}));
	// cells $procmux$2502 $procmux$2499 $procmux$2497
	i_3_5c_ownerzero_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_eq_24_receiver_2e_v_3a_87_24_79__Y ? i_4_5c_ownerzero_5b_0_3a_0_5d_ : p_ownerzero.curr) : value<1>{0u}));
	// \src: receiver.v:117.29-117.48
	// cell $neg$receiver.v:117$135
	i_neg_24_receiver_2e_v_3a_115_24_114__Y = neg_u<2>(i_5_5c_emitowner_5b_0_3a_0_5d_);
	// cells $procmux$2304 $procmux$2301 $procmux$2299 $procmux$1448 $procmux$870
	i_3_5c_rzero_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_eq_24_receiver_2e_v_3a_87_24_79__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? i_4_5c_rzero_5b_0_3a_0_5d_ : (i_logic__and_24_receiver_2e_v_3a_108_24_107__Y ? value<1>{0u} : i_4_5c_rzero_5b_0_3a_0_5d_)) : p_rzero.curr) : value<1>{0u}));
	// \src: receiver.v:117.29-117.48
	// cell $shift$receiver.v:117$136
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4676.slice<1,0>() = shift_us<2>(value<1>{0x1u}, i_neg_24_receiver_2e_v_3a_115_24_114__Y);
	// \src: receiver.v:119.32-119.38
	// cell $mul$receiver.v:119$140
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4666.slice<4,0>() = mul_uu<5>(value<2>{0x3u}, p_cfgp);
	// connection
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4666.slice<31,5>() = value<27>{0u};
	// \src: receiver.v:119.57-119.63
	// cell $mul$receiver.v:119$143
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4663.slice<4,0>() = mul_uu<5>(value<2>{0x2u}, p_cfgp);
	// connection
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4663.slice<31,5>() = value<27>{0u};
	// cells $procmux$3405 $procmux$3402 $procmux$3400
	i_3_5c_pending_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_logic__and_24_receiver_2e_v_3a_65_24_52__Y ? value<1>{0x1u} : p_pending.curr.slice<0>().val()) : value<1>{0u}));
	// cells $procmux$2967 $procmux$2964 $procmux$2962
	i_5_5c_pending_5b_1_3a_1_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_logic__and_24_receiver_2e_v_3a_76_24_66__Y ? value<1>{0x1u} : p_pending.curr.slice<1>().val()) : value<1>{0u}));
	// \src: receiver.v:117.29-117.48
	// cell $not$receiver.v:117$133
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4675.slice<1,0>() = not_u<2>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4676.slice<1,0>().val());
	// \src: receiver.v:117.8-117.28
	// cell $shift$receiver.v:117$129
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4673.slice<1,0>() = shift_us<2>(value<1>{0u}, i_neg_24_receiver_2e_v_3a_115_24_114__Y);
	// cells $procmux$3387 $procmux$3384 $procmux$3382 $procmux$3128
	i_3_5c_pollen_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_logic__and_24_receiver_2e_v_3a_65_24_52__Y ? (p_pending.curr.slice<0>().val() ? value<1>{0u} : p_pollen.curr.slice<0>().val()) : p_pollen.curr.slice<0>().val()) : value<1>{0u}));
	// cells $procmux$2949 $procmux$2946 $procmux$2944 $procmux$2690
	i_5_5c_pollen_5b_1_3a_1_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_logic__and_24_receiver_2e_v_3a_76_24_66__Y ? (p_pending.curr.slice<1>().val() ? value<1>{0u} : p_pollen.curr.slice<1>().val()) : p_pollen.curr.slice<1>().val()) : value<1>{0u}));
	// cells $add$receiver.v:119$142 $add$receiver.v:119$141
	i_add_24_receiver_2e_v_3a_119_24_142__Y = add_uu<16>(add_uu<16>(p_tick.curr, i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4666.slice<4,0>().val()), value<1>{0x1u});
	// cells $add$receiver.v:119$145 $add$receiver.v:119$144
	i_add_24_receiver_2e_v_3a_119_24_145__Y = add_uu<16>(add_uu<16>(p_tick.curr, i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4663.slice<4,0>().val()), value<1>{0x1u});
	// cells $procmux$333 $procmux$330 $procmux$328 $procmux$308 $add$receiver.v:128$153
	i_7_5c_tokensa_5b_2_3a_0_5d_ = (p_rst ? value<3>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_3_5c_rzero_5b_0_3a_0_5d_ ? (i_3_5c_ownerzero_5b_0_3a_0_5d_ ? i_5_5c_tokensa_5b_2_3a_0_5d_ : add_uu<3>(i_5_5c_tokensa_5b_2_3a_0_5d_, value<1>{0x1u})) : i_5_5c_tokensa_5b_2_3a_0_5d_) : value<3>{0u}));
	// cells $procmux$1188 $procmux$1185 $procmux$1183 $procmux$1181 $procmux$1179 $procmux$1018
	i_5_5c_evemit_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_eq_24_receiver_2e_v_3a_87_24_79__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? value<1>{0u} : (p_rone.curr ? (i_ne_24_receiver_2e_v_3a_104_24_105__Y ? value<1>{0x1u} : value<1>{0u}) : value<1>{0u})) : value<1>{0u}) : value<1>{0u}));
	// cells $or$receiver.v:115$120 $and$receiver.v:115$117
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4672.slice<1,0>() = or_uu<2>(and_uu<2>(i_5_5c_pending_5b_1_3a_1_5d_.concat(i_3_5c_pending_5b_0_3a_0_5d_).val(), i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4675.slice<1,0>().val()), i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4673.slice<1,0>().val());
	// cells $procmux$3396 $procmux$3393 $procmux$3391 $procmux$3140
	i_3_5c_waiting_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_logic__and_24_receiver_2e_v_3a_65_24_52__Y ? (p_pending.curr.slice<0>().val() ? value<1>{0x1u} : p_waiting.curr.slice<0>().val()) : p_waiting.curr.slice<0>().val()) : value<1>{0u}));
	// cells $procmux$2958 $procmux$2955 $procmux$2953 $procmux$2702
	i_5_5c_waiting_5b_1_3a_1_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_logic__and_24_receiver_2e_v_3a_76_24_66__Y ? (p_pending.curr.slice<1>().val() ? value<1>{0x1u} : p_waiting.curr.slice<1>().val()) : p_waiting.curr.slice<1>().val()) : value<1>{0u}));
	// cells $procmux$324 $procmux$321 $procmux$319 $procmux$296 $add$receiver.v:128$152
	i_7_5c_tokensb_5b_2_3a_0_5d_ = (p_rst ? value<3>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_3_5c_rzero_5b_0_3a_0_5d_ ? (i_3_5c_ownerzero_5b_0_3a_0_5d_ ? add_uu<3>(i_5_5c_tokensb_5b_2_3a_0_5d_, value<1>{0x1u}) : i_5_5c_tokensb_5b_2_3a_0_5d_) : i_5_5c_tokensb_5b_2_3a_0_5d_) : value<3>{0u}));
	// cells $procmux$2286 $procmux$2283 $procmux$2281 $procmux$1424 $procmux$915
	i_3_5c_ownerone_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_eq_24_receiver_2e_v_3a_87_24_79__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? p_ownerone.curr : (i_logic__and_24_receiver_2e_v_3a_108_24_107__Y ? i_4_5c_ownerzero_5b_0_3a_0_5d_ : p_ownerone.curr)) : p_ownerone.curr) : value<1>{0u}));
	// \src: receiver.v:116.17-116.28
	// cell $shiftx$receiver.v:116$121
	i_procmux_24_428__CMP = shiftx_uu<1>(i_5_5c_waiting_5b_1_3a_1_5d_.concat(i_3_5c_waiting_5b_0_3a_0_5d_).val(), i_5_5c_emitowner_5b_0_3a_0_5d_);
	// cells $or$receiver.v:117$137 $and$receiver.v:117$134
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4667.slice<1,0>() = or_uu<2>(and_uu<2>(i_5_5c_pollen_5b_1_3a_1_5d_.concat(i_3_5c_pollen_5b_0_3a_0_5d_).val(), i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4675.slice<1,0>().val()), i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4676.slice<1,0>().val());
	// cells $procmux$2935 $procmux$2822
	i_3_5c_pollb_5b_15_3a_0_5d_ = (i_logic__and_24_receiver_2e_v_3a_76_24_66__Y ? (p_pending.curr.slice<1>().val() ? p_pollb.curr : i_add_24_receiver_2e_v_3a_119_24_142__Y) : p_pollb.curr);
	// cells $procmux$3373 $procmux$3260
	i_3_5c_polla_5b_15_3a_0_5d_ = (i_logic__and_24_receiver_2e_v_3a_65_24_52__Y ? (p_pending.curr.slice<0>().val() ? p_polla.curr : i_add_24_receiver_2e_v_3a_119_24_145__Y) : p_polla.curr);
	// \src: receiver.v:69.11-69.17
	// cell $add$receiver.v:69$57
	i_add_24_receiver_2e_v_3a_69_24_57__Y = add_uu<16>(p_seqa.curr, value<1>{0x1u});
	// cells $procmux$613 $shiftx$receiver.v:114$111
	i_22_5c_fault_5b_15_3a_0_5d_.slice<4,0>() = (shiftx_uu<1>(i_5_5c_pending_5b_1_3a_1_5d_.concat(i_3_5c_pending_5b_0_3a_0_5d_).val(), i_5_5c_emitowner_5b_0_3a_0_5d_) ? i_14_5c_fault_5b_15_3a_0_5d_.curr.slice<4,0>().val() : value<1>{0x1u}.concat(i_14_5c_fault_5b_15_3a_0_5d_.curr.slice<3,0>()).val());
	// connection
	i_22_5c_fault_5b_15_3a_0_5d_.slice<15,5>() = i_14_5c_fault_5b_15_3a_0_5d_.curr.slice<15,5>().val();
	// cells $procmux$2295 $procmux$2292 $procmux$2290 $procmux$1436 $procmux$930
	i_3_5c_rone_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_eq_24_receiver_2e_v_3a_87_24_79__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? p_rone.curr : (i_logic__and_24_receiver_2e_v_3a_108_24_107__Y ? value<1>{0x1u} : i_5_5c_rone_5b_0_3a_0_5d_)) : p_rone.curr) : value<1>{0u}));
	// cells $or$receiver.v:117$130 $and$receiver.v:117$127
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4670.slice<1,0>() = or_uu<2>(and_uu<2>(i_5_5c_waiting_5b_1_3a_1_5d_.concat(i_3_5c_waiting_5b_0_3a_0_5d_).val(), i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4675.slice<1,0>().val()), i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4673.slice<1,0>().val());
	// \full_case: 1
	// \src: receiver.v:118.11-118.21|receiver.v:118.8-118.43
	// cell $procmux$467
	i_24_5c_fault_5b_15_3a_0_5d_.slice<2,0>() = (i_gt_24_receiver_2e_v_3a_118_24_138__Y ? value<1>{0x1u}.concat(i_22_5c_fault_5b_15_3a_0_5d_.slice<1,0>()).val() : i_22_5c_fault_5b_15_3a_0_5d_.slice<2,0>().val());
	// connection
	i_24_5c_fault_5b_15_3a_0_5d_.slice<15,3>() = i_14_5c_fault_5b_15_3a_0_5d_.curr.slice<15,5>().concat(i_22_5c_fault_5b_15_3a_0_5d_.slice<4,3>()).val();
	// \full_case: 1
	// \src: receiver.v:116.10-116.28|receiver.v:116.7-120.10
	// cell $procmux$523
	i_23_5c_fault_5b_15_3a_0_5d_.slice<2,0>() = (i_procmux_24_428__CMP ? i_24_5c_fault_5b_15_3a_0_5d_.slice<2,0>().val() : i_22_5c_fault_5b_15_3a_0_5d_.slice<2,0>().val());
	// connection
	i_23_5c_fault_5b_15_3a_0_5d_.slice<15,3>() = i_14_5c_fault_5b_15_3a_0_5d_.curr.slice<15,5>().concat(i_22_5c_fault_5b_15_3a_0_5d_.slice<4,3>()).val();
	// cells $procmux$3328 $procmux$3200 $procmux$3026
	i_3_5c_qid0_5b_15_3a_0_5d_ = (i_logic__and_24_receiver_2e_v_3a_65_24_52__Y ? (p_pending.curr.slice<0>().val() ? p_qid0.curr : (i_eq_24_receiver_2e_v_3a_70_24_61__Y ? i_add_24_receiver_2e_v_3a_69_24_57__Y : p_qid0.curr)) : p_qid0.curr);
	// \src: receiver.v:80.11-80.17
	// cell $add$receiver.v:80$71
	i_add_24_receiver_2e_v_3a_80_24_71__Y = add_uu<16>(p_seqb.curr, value<1>{0x1u});
	// \full_case: 1
	// \src: receiver.v:112.9-112.15|receiver.v:112.6-121.9
	// cell $procmux$660
	i_21_5c_fault_5b_15_3a_0_5d_.slice<4,0>() = (i_5_5c_evemit_5b_0_3a_0_5d_ ? i_22_5c_fault_5b_15_3a_0_5d_.slice<4,3>().concat(i_23_5c_fault_5b_15_3a_0_5d_.slice<2,0>()).val() : i_14_5c_fault_5b_15_3a_0_5d_.curr.slice<4,0>().val());
	// connection
	i_21_5c_fault_5b_15_3a_0_5d_.slice<15,5>() = i_14_5c_fault_5b_15_3a_0_5d_.curr.slice<15,5>().val();
	// cells $procmux$291 $procmux$288 $procmux$286 $procmux$266 $add$receiver.v:129$155
	i_9_5c_tokensa_5b_2_3a_0_5d_ = (p_rst ? value<3>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_3_5c_rone_5b_0_3a_0_5d_ ? (i_3_5c_ownerone_5b_0_3a_0_5d_ ? i_7_5c_tokensa_5b_2_3a_0_5d_ : add_uu<3>(i_7_5c_tokensa_5b_2_3a_0_5d_, value<1>{0x1u})) : i_7_5c_tokensa_5b_2_3a_0_5d_) : value<3>{0u}));
	// cells $procmux$2349 $procmux$2346 $procmux$2344 $procmux$1340 $procmux$735
	i_7_5c_pending_5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_eq_24_receiver_2e_v_3a_87_24_79__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? i_5_5c_pending_5b_1_3a_1_5d_.concat(i_3_5c_pending_5b_0_3a_0_5d_).val() : (i_5_5c_evemit_5b_0_3a_0_5d_ ? i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4672.slice<1,0>().val() : i_5_5c_pending_5b_1_3a_1_5d_.concat(i_3_5c_pending_5b_0_3a_0_5d_).val())) : i_5_5c_pending_5b_1_3a_1_5d_.concat(i_3_5c_pending_5b_0_3a_0_5d_).val()) : value<2>{0u}));
	// \full_case: 1
	// \src: receiver.v:101.8-101.15|receiver.v:101.5-122.8
	// cell $procmux$1280
	i_20_5c_fault_5b_15_3a_0_5d_.slice<4,0>() = (i_4_5c_failed_5b_0_3a_0_5d_ ? i_14_5c_fault_5b_15_3a_0_5d_.curr.slice<4,0>().val() : i_21_5c_fault_5b_15_3a_0_5d_.slice<4,0>().val());
	// connection
	i_20_5c_fault_5b_15_3a_0_5d_.slice<15,5>() = i_14_5c_fault_5b_15_3a_0_5d_.curr.slice<15,5>().val();
	// cells $procmux$282 $procmux$279 $procmux$277 $procmux$254 $add$receiver.v:129$154
	i_9_5c_tokensb_5b_2_3a_0_5d_ = (p_rst ? value<3>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_3_5c_rone_5b_0_3a_0_5d_ ? (i_3_5c_ownerone_5b_0_3a_0_5d_ ? add_uu<3>(i_7_5c_tokensb_5b_2_3a_0_5d_, value<1>{0x1u}) : i_7_5c_tokensb_5b_2_3a_0_5d_) : i_7_5c_tokensb_5b_2_3a_0_5d_) : value<3>{0u}));
	// cells $procmux$3319 $procmux$3188 $procmux$3071 $procmux$2972
	i_3_5c_qid1_5b_15_3a_0_5d_ = (i_logic__and_24_receiver_2e_v_3a_65_24_52__Y ? (p_pending.curr.slice<0>().val() ? p_qid1.curr : (i_eq_24_receiver_2e_v_3a_70_24_61__Y ? p_qid1.curr : (i_eq_24_receiver_2e_v_3a_71_24_62__Y ? i_add_24_receiver_2e_v_3a_69_24_57__Y : p_qid1.curr))) : p_qid1.curr);
	// \full_case: 1
	// \src: receiver.v:52.7-52.24|receiver.v:52.4-52.80
	// cell $procmux$3931
	i_3_5c_dataa_5b_7_3a_0_5d_ = (i_logic__and_24_receiver_2e_v_3a_52_24_40__Y ? p_wua : p_dataa.curr);
	// \full_case: 1
	// \src: receiver.v:53.7-53.24|receiver.v:53.4-53.80
	// cell $procmux$3895
	i_3_5c_datab_5b_7_3a_0_5d_ = (i_logic__and_24_receiver_2e_v_3a_53_24_41__Y ? p_wub : p_datab.curr);
	// \full_case: 1
	// \src: receiver.v:87.7-87.20|receiver.v:87.4-123.7
	// cell $procmux$2254
	i_procmux_24_2254__Y.slice<4,0>() = (i_eq_24_receiver_2e_v_3a_87_24_79__Y ? i_20_5c_fault_5b_15_3a_0_5d_.slice<4,0>().val() : i_14_5c_fault_5b_15_3a_0_5d_.curr.slice<4,0>().val());
	// connection
	i_procmux_24_2254__Y.slice<15,5>() = i_14_5c_fault_5b_15_3a_0_5d_.curr.slice<15,5>().val();
	// cells $procmux$2331 $procmux$2328 $procmux$2326 $procmux$1316 $procmux$705 $procmux$541
	i_7_5c_pollen_5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_eq_24_receiver_2e_v_3a_87_24_79__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? i_5_5c_pollen_5b_1_3a_1_5d_.concat(i_3_5c_pollen_5b_0_3a_0_5d_).val() : (i_5_5c_evemit_5b_0_3a_0_5d_ ? (i_procmux_24_428__CMP ? i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4667.slice<1,0>().val() : i_5_5c_pollen_5b_1_3a_1_5d_.concat(i_3_5c_pollen_5b_0_3a_0_5d_).val()) : i_5_5c_pollen_5b_1_3a_1_5d_.concat(i_3_5c_pollen_5b_0_3a_0_5d_).val())) : i_5_5c_pollen_5b_1_3a_1_5d_.concat(i_3_5c_pollen_5b_0_3a_0_5d_).val()) : value<2>{0u}));
	// \src: receiver.v:94.17-94.36
	// cell $ternary$receiver.v:94$91
	i_ternary_24_receiver_2e_v_3a_94_24_91__Y = (i_6_5c_qowner0_5b_0_3a_0_5d_ ? i_3_5c_datab_5b_7_3a_0_5d_ : i_3_5c_dataa_5b_7_3a_0_5d_);
	// cells $procmux$2890 $procmux$2762 $procmux$2588
	i_6_5c_qid0_5b_15_3a_0_5d_ = (i_logic__and_24_receiver_2e_v_3a_76_24_66__Y ? (p_pending.curr.slice<1>().val() ? i_3_5c_qid0_5b_15_3a_0_5d_ : (i_eq_24_receiver_2e_v_3a_81_24_75__Y ? i_add_24_receiver_2e_v_3a_80_24_71__Y : i_3_5c_qid0_5b_15_3a_0_5d_)) : i_3_5c_qid0_5b_15_3a_0_5d_);
	// cells $procmux$3828 $procmux$3825 $procmux$3823 $procmux$3566 $procmux$3501 $procmux$3420
	i_5_5c_enabled_5b_1_3a_0_5d_.slice<1>() = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_eq_24_receiver_2e_v_3a_54_24_42__Y ? (i_4_5c_enabled_5b_1_3a_1_5d_ ? (i_eq_24_receiver_2e_v_3a_60_24_47__Y ? value<1>{0x1u} : (i_eq_24_receiver_2e_v_3a_61_24_50__Y ? value<1>{0u} : value<1>{0x1u})) : value<1>{0u}) : i_4_5c_enabled_5b_1_3a_1_5d_) : value<1>{0u}));
	// cells $procmux$3810 $procmux$3807 $procmux$3805 $procmux$3755 $procmux$3690 $procmux$3609
	i_5_5c_enabled_5b_1_3a_0_5d_.slice<0>() = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_eq_24_receiver_2e_v_3a_54_24_42__Y ? (i_3_5c_enabled_5b_0_3a_0_5d_ ? (i_eq_24_receiver_2e_v_3a_56_24_43__Y ? value<1>{0x1u} : (i_eq_24_receiver_2e_v_3a_57_24_46__Y ? value<1>{0u} : value<1>{0x1u})) : value<1>{0u}) : i_3_5c_enabled_5b_0_3a_0_5d_) : value<1>{0u}));
	// cells $procmux$2340 $procmux$2337 $procmux$2335 $procmux$1328 $procmux$720 $procmux$577
	i_7_5c_waiting_5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_eq_24_receiver_2e_v_3a_87_24_79__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? i_5_5c_waiting_5b_1_3a_1_5d_.concat(i_3_5c_waiting_5b_0_3a_0_5d_).val() : (i_5_5c_evemit_5b_0_3a_0_5d_ ? (i_procmux_24_428__CMP ? i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4670.slice<1,0>().val() : i_5_5c_waiting_5b_1_3a_1_5d_.concat(i_3_5c_waiting_5b_0_3a_0_5d_).val()) : i_5_5c_waiting_5b_1_3a_1_5d_.concat(i_3_5c_waiting_5b_0_3a_0_5d_).val())) : i_5_5c_waiting_5b_1_3a_1_5d_.concat(i_3_5c_waiting_5b_0_3a_0_5d_).val()) : value<2>{0u}));
	// cells $procmux$2313 $procmux$2310 $procmux$2308 $procmux$1292 $procmux$675 $procmux$487 $procmux$425
	i_5_5c_pollb_5b_15_3a_0_5d_ = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_eq_24_receiver_2e_v_3a_87_24_79__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? i_3_5c_pollb_5b_15_3a_0_5d_ : (i_5_5c_evemit_5b_0_3a_0_5d_ ? (i_procmux_24_428__CMP ? (i_5_5c_emitowner_5b_0_3a_0_5d_ ? i_add_24_receiver_2e_v_3a_119_24_142__Y : i_3_5c_pollb_5b_15_3a_0_5d_) : i_3_5c_pollb_5b_15_3a_0_5d_) : i_3_5c_pollb_5b_15_3a_0_5d_)) : i_3_5c_pollb_5b_15_3a_0_5d_) : value<16>{0u}));
	// cells $procmux$2322 $procmux$2319 $procmux$2317 $procmux$1304 $procmux$690 $procmux$505 $procmux$446
	i_5_5c_polla_5b_15_3a_0_5d_ = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_eq_24_receiver_2e_v_3a_87_24_79__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? i_3_5c_polla_5b_15_3a_0_5d_ : (i_5_5c_evemit_5b_0_3a_0_5d_ ? (i_procmux_24_428__CMP ? (i_5_5c_emitowner_5b_0_3a_0_5d_ ? i_3_5c_polla_5b_15_3a_0_5d_ : i_add_24_receiver_2e_v_3a_119_24_145__Y) : i_3_5c_polla_5b_15_3a_0_5d_) : i_3_5c_polla_5b_15_3a_0_5d_)) : i_3_5c_polla_5b_15_3a_0_5d_) : value<16>{0u}));
	// cells $procmux$2259 $procmux$2256
	i_19_5c_fault_5b_15_3a_0_5d_ = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? i_14_5c_fault_5b_15_3a_0_5d_.curr.slice<15,5>().concat(i_procmux_24_2254__Y.slice<4,0>()).val() : value<16>{0u}));
	// cells $procmux$3796 $procmux$3554 $procmux$3486
	i_4_5c_countb_5b_2_3a_0_5d_ = (i_eq_24_receiver_2e_v_3a_54_24_42__Y ? (i_4_5c_enabled_5b_1_3a_1_5d_ ? (i_eq_24_receiver_2e_v_3a_60_24_47__Y ? i_3_5c_countb_5b_2_3a_0_5d_ : i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4682.slice<2,0>().val()) : i_3_5c_countb_5b_2_3a_0_5d_) : i_3_5c_countb_5b_2_3a_0_5d_);
	// cells $procmux$3832 $procmux$3743 $procmux$3675
	i_4_5c_counta_5b_2_3a_0_5d_ = (i_eq_24_receiver_2e_v_3a_54_24_42__Y ? (i_3_5c_enabled_5b_0_3a_0_5d_ ? (i_eq_24_receiver_2e_v_3a_56_24_43__Y ? i_3_5c_counta_5b_2_3a_0_5d_ : i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_4683.slice<2,0>().val()) : i_3_5c_counta_5b_2_3a_0_5d_) : i_3_5c_counta_5b_2_3a_0_5d_);
	// cells $procmux$1982 $procmux$1746
	i_4_5c_bytezero_5b_7_3a_0_5d_ = (i_logic__and_24_receiver_2e_v_3a_89_24_86__Y ? (i_shiftx_24_receiver_2e_v_3a_91_24_88__Y ? i_ternary_24_receiver_2e_v_3a_94_24_91__Y : p_bytezero.curr) : p_bytezero.curr);
	// cells $procmux$1119 $procmux$982
	i_5_5c_emitid_5b_15_3a_0_5d_ = (p_rone.curr ? (i_ne_24_receiver_2e_v_3a_104_24_105__Y ? p_idone.curr : p_emitid.curr) : p_emitid.curr);
	// cells $procmux$1994 $procmux$1761
	i_4_5c_idzero_5b_15_3a_0_5d_ = (i_logic__and_24_receiver_2e_v_3a_89_24_86__Y ? (i_shiftx_24_receiver_2e_v_3a_91_24_88__Y ? i_6_5c_qid0_5b_15_3a_0_5d_ : p_idzero.curr) : p_idzero.curr);
	// cells $procmux$244 $logic_or$receiver.v:130$163 $logic_or$receiver.v:130$160 $logic_or$receiver.v:130$158 $gt$receiver.v:130$156 $ne$receiver.v:130$157 $ne$receiver.v:130$159 $gt$receiver.v:130$162 $add$receiver.v:130$161
	i_25_5c_fault_5b_15_3a_0_5d_.slice<5,0>() = (logic_or<1>(logic_or<1>(logic_or<1>(gt_uu<1>(i_7_5c_qlen_5b_1_3a_0_5d_, value<2>{0x2u}), ne_uu<1>(i_9_5c_tokensa_5b_2_3a_0_5d_, i_7_5c_pending_5b_1_3a_0_5d_.slice<0>().val())), ne_uu<1>(i_9_5c_tokensb_5b_2_3a_0_5d_, i_7_5c_pending_5b_1_3a_0_5d_.slice<1>().val())), gt_uu<1>(add_uu<4>(i_9_5c_tokensa_5b_2_3a_0_5d_, i_9_5c_tokensb_5b_2_3a_0_5d_), value<2>{0x2u})) ? value<1>{0x1u}.concat(i_19_5c_fault_5b_15_3a_0_5d_.slice<4,0>()).val() : i_19_5c_fault_5b_15_3a_0_5d_.slice<5,0>().val());
	// connection
	i_25_5c_fault_5b_15_3a_0_5d_.slice<15,6>() = i_19_5c_fault_5b_15_3a_0_5d_.slice<15,6>().val();
	// cells $procmux$2881 $procmux$2750 $procmux$2633 $procmux$2534
	i_7_5c_qid1_5b_15_3a_0_5d_ = (i_logic__and_24_receiver_2e_v_3a_76_24_66__Y ? (p_pending.curr.slice<1>().val() ? i_3_5c_qid1_5b_15_3a_0_5d_ : (i_eq_24_receiver_2e_v_3a_81_24_75__Y ? i_3_5c_qid1_5b_15_3a_0_5d_ : (i_eq_24_receiver_2e_v_3a_82_24_76__Y ? i_add_24_receiver_2e_v_3a_80_24_71__Y : i_3_5c_qid1_5b_15_3a_0_5d_))) : i_3_5c_qid1_5b_15_3a_0_5d_);
	// \src: receiver.v:137.63-137.76
	// cell $add$receiver.v:137$190
	i_add_24_receiver_2e_v_3a_137_24_188__Y = add_uu<6>(p_expiryphase.curr, value<1>{0x1u});
	// \src: receiver.v:136.55-136.67
	// cell $add$receiver.v:136$187
	i_add_24_receiver_2e_v_3a_136_24_185__Y = add_uu<4>(p_readyphase.curr, value<1>{0x1u});
	// \src: receiver.v:135.55-135.67
	// cell $add$receiver.v:135$184
	i_add_24_receiver_2e_v_3a_135_24_182__Y = add_uu<4>(p_cachephase.curr, value<1>{0x1u});
	// cells $procmux$235 $logic_or$receiver.v:131$171 $logic_and$receiver.v:131$167 $logic_or$receiver.v:131$166 $logic_not$receiver.v:131$165 $logic_and$receiver.v:131$170 $logic_or$receiver.v:131$169 $logic_not$receiver.v:131$168
	i_26_5c_fault_5b_15_3a_0_5d_.slice<6,0>() = (logic_or<1>(logic_and<1>(i_7_5c_waiting_5b_1_3a_0_5d_.slice<0>().val(), logic_or<1>(logic_not<1>(i_7_5c_pending_5b_1_3a_0_5d_.slice<0>().val()), i_7_5c_pollen_5b_1_3a_0_5d_.slice<0>().val())), logic_and<1>(i_7_5c_waiting_5b_1_3a_0_5d_.slice<1>().val(), logic_or<1>(logic_not<1>(i_7_5c_pending_5b_1_3a_0_5d_.slice<1>().val()), i_7_5c_pollen_5b_1_3a_0_5d_.slice<1>().val()))) ? value<1>{0x1u}.concat(i_25_5c_fault_5b_15_3a_0_5d_.slice<5,0>()).val() : i_19_5c_fault_5b_15_3a_0_5d_.slice<6>().concat(i_25_5c_fault_5b_15_3a_0_5d_.slice<5,0>()).val());
	// connection
	i_26_5c_fault_5b_15_3a_0_5d_.slice<15,7>() = i_19_5c_fault_5b_15_3a_0_5d_.slice<15,7>().val();
	// cells $procmux$226 $logic_or$receiver.v:132$177 $logic_and$receiver.v:132$174 $le$receiver.v:132$173 $logic_and$receiver.v:132$176 $le$receiver.v:132$175
	i_27_5c_fault_5b_15_3a_0_5d_.slice<7,0>() = (logic_or<1>(logic_and<1>(i_7_5c_pollen_5b_1_3a_0_5d_.slice<0>().val(), le_uu<1>(i_5_5c_polla_5b_15_3a_0_5d_, p_tick.curr)), logic_and<1>(i_7_5c_pollen_5b_1_3a_0_5d_.slice<1>().val(), le_uu<1>(i_5_5c_pollb_5b_15_3a_0_5d_, p_tick.curr))) ? value<1>{0x1u}.concat(i_26_5c_fault_5b_15_3a_0_5d_.slice<6,0>()).val() : i_19_5c_fault_5b_15_3a_0_5d_.slice<7>().concat(i_26_5c_fault_5b_15_3a_0_5d_.slice<6,0>()).val());
	// connection
	i_27_5c_fault_5b_15_3a_0_5d_.slice<15,8>() = i_19_5c_fault_5b_15_3a_0_5d_.slice<15,8>().val();
	// cells $procmux$3778 $procmux$3719 $procmux$3660 $procmux$3591
	i_3_5c_evexpire_5b_1_3a_0_5d_.slice<0>() = (i_eq_24_receiver_2e_v_3a_54_24_42__Y ? (i_3_5c_enabled_5b_0_3a_0_5d_ ? (i_eq_24_receiver_2e_v_3a_56_24_43__Y ? value<1>{0u} : (i_eq_24_receiver_2e_v_3a_57_24_46__Y ? value<1>{0x1u} : value<1>{0u})) : value<1>{0u}) : value<1>{0u});
	// cells $procmux$3409 $procmux$3530 $procmux$3471 $procmux$3852
	i_3_5c_evexpire_5b_1_3a_0_5d_.slice<1>() = (i_eq_24_receiver_2e_v_3a_54_24_42__Y ? (i_4_5c_enabled_5b_1_3a_1_5d_ ? (i_eq_24_receiver_2e_v_3a_60_24_47__Y ? value<1>{0u} : (i_eq_24_receiver_2e_v_3a_61_24_50__Y ? value<1>{0x1u} : value<1>{0u})) : value<1>{0u}) : value<1>{0u});
	// cells $procmux$217 $ge$receiver.v:133$179
	i_28_5c_fault_5b_15_3a_0_5d_.slice<8,0>() = (ge_uu<1>(p_tick.curr, value<16>{0xffebu}) ? value<1>{0x1u}.concat(i_27_5c_fault_5b_15_3a_0_5d_.slice<7,0>()).val() : i_19_5c_fault_5b_15_3a_0_5d_.slice<8>().concat(i_27_5c_fault_5b_15_3a_0_5d_.slice<7,0>()).val());
	// connection
	i_28_5c_fault_5b_15_3a_0_5d_.slice<15,9>() = i_19_5c_fault_5b_15_3a_0_5d_.slice<15,9>().val();
	// cells $procmux$4344 $procmux$3904
	i_2_5c_evwu_5b_1_3a_0_5d_.slice<0>() = (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_logic__and_24_receiver_2e_v_3a_52_24_40__Y ? value<1>{0x1u} : value<1>{0u}) : p_evwu.curr.slice<0>().val());
	// cells $procmux$192 $procmux$3868
	i_2_5c_evwu_5b_1_3a_0_5d_.slice<1>() = (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_logic__and_24_receiver_2e_v_3a_53_24_41__Y ? value<1>{0x1u} : value<1>{0u}) : p_evwu.curr.slice<1>().val());
	// cells $procmux$4356 $procmux$2854 $procmux$2726
	i_2_5c_evenq_5b_1_3a_0_5d_.slice<1>() = (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_logic__and_24_receiver_2e_v_3a_76_24_66__Y ? (p_pending.curr.slice<1>().val() ? value<1>{0u} : value<1>{0x1u}) : value<1>{0u}) : p_evenq.curr.slice<1>().val());
	// cells $procmux$4269 $procmux$3292 $procmux$3164
	i_2_5c_evenq_5b_1_3a_0_5d_.slice<0>() = (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_logic__and_24_receiver_2e_v_3a_65_24_52__Y ? (p_pending.curr.slice<0>().val() ? value<1>{0u} : value<1>{0x1u}) : value<1>{0u}) : p_evenq.curr.slice<0>().val());
	// cells $procmux$4305 $procmux$2863 $procmux$2678
	i_2_5c_evwait_5b_1_3a_0_5d_.slice<1>() = (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_logic__and_24_receiver_2e_v_3a_76_24_66__Y ? (p_pending.curr.slice<1>().val() ? value<1>{0x1u} : value<1>{0u}) : value<1>{0u}) : p_evwait.curr.slice<1>().val());
	// cells $procmux$4275 $procmux$3301 $procmux$3116
	i_2_5c_evwait_5b_1_3a_0_5d_.slice<0>() = (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_logic__and_24_receiver_2e_v_3a_65_24_52__Y ? (p_pending.curr.slice<0>().val() ? value<1>{0x1u} : value<1>{0u}) : value<1>{0u}) : p_evwait.curr.slice<0>().val());
	// cells $procdff$4647 $procmux$4476 $procmux$3939 $procmux$4312 $eq$receiver.v:137$189
	if (posedge_p_clk) {
		p_expiryphase.next = (p_rst ? value<5>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (eq_uu<1>(i_add_24_receiver_2e_v_3a_137_24_188__Y, value<1>{0u}.concat(p_cfgperiod).val()) ? value<5>{0u} : i_add_24_receiver_2e_v_3a_137_24_188__Y.slice<4,0>().val()) : p_expiryphase.curr));
	}
	// cells $procdff$4646 $procmux$4479 $procmux$3945 $procmux$199 $eq$receiver.v:136$186
	if (posedge_p_clk) {
		p_readyphase.next = (p_rst ? value<3>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (eq_uu<1>(i_add_24_receiver_2e_v_3a_136_24_185__Y, value<1>{0u}.concat(p_cfgr).val()) ? value<3>{0u} : i_add_24_receiver_2e_v_3a_136_24_185__Y.slice<2,0>().val()) : p_readyphase.curr));
	}
	// cells $procdff$4645 $procmux$4482 $procmux$3951 $procmux$208 $eq$receiver.v:135$183
	if (posedge_p_clk) {
		p_cachephase.next = (p_rst ? value<3>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (eq_uu<1>(i_add_24_receiver_2e_v_3a_135_24_182__Y, value<1>{0u}.concat(p_cfgp).val()) ? value<3>{0u} : i_add_24_receiver_2e_v_3a_135_24_182__Y.slice<2,0>().val()) : p_cachephase.curr));
	}
	// cells $procdff$4644 $procmux$4383 $procmux$4005 $procmux$2128 $procmux$1352 $procmux$810
	if (posedge_p_clk) {
		p_transferbyte.next = (p_rst ? value<8>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_eq_24_receiver_2e_v_3a_87_24_79__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? p_transferbyte.curr : (i_logic__and_24_receiver_2e_v_3a_108_24_107__Y ? i_4_5c_bytezero_5b_7_3a_0_5d_ : p_transferbyte.curr)) : p_transferbyte.curr) : p_transferbyte.curr));
	}
	// cells $procdff$4643 $procmux$4386 $procmux$4011 $procmux$2137 $procmux$1460 $procmux$1089 $procmux$964
	if (posedge_p_clk) {
		p_emitbyte.next = (p_rst ? value<8>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_eq_24_receiver_2e_v_3a_87_24_79__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? p_emitbyte.curr : (p_rone.curr ? (i_ne_24_receiver_2e_v_3a_104_24_105__Y ? p_byteone.curr : p_emitbyte.curr) : p_emitbyte.curr)) : p_emitbyte.curr) : p_emitbyte.curr));
	}
	// cells $procdff$4642 $procmux$4389 $procmux$4017 $procmux$2362 $procmux$1862 $procmux$1641
	if (posedge_p_clk) {
		p_grantbyte.next = (p_rst ? value<8>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_eq_24_receiver_2e_v_3a_87_24_79__Y ? (i_logic__and_24_receiver_2e_v_3a_89_24_86__Y ? (i_shiftx_24_receiver_2e_v_3a_91_24_88__Y ? i_ternary_24_receiver_2e_v_3a_94_24_91__Y : p_grantbyte.curr) : p_grantbyte.curr) : p_grantbyte.curr) : p_grantbyte.curr));
	}
	// cells $procdff$4641 $procmux$4392 $procmux$4023 $procmux$2146 $procmux$1472 $procmux$1104 $procmux$1036
	if (posedge_p_clk) {
		p_blockid.next = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_eq_24_receiver_2e_v_3a_87_24_79__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? p_blockid.curr : (p_rone.curr ? (i_ne_24_receiver_2e_v_3a_104_24_105__Y ? p_blockid.curr : p_idone.curr) : p_blockid.curr)) : p_blockid.curr) : p_blockid.curr));
	}
	// cells $procdff$4640 $procmux$4395 $procmux$4029 $procmux$2155 $procmux$1244 $procmux$765
	if (posedge_p_clk) {
		p_callbackid.next = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_eq_24_receiver_2e_v_3a_87_24_79__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? p_callbackid.curr : (i_5_5c_evemit_5b_0_3a_0_5d_ ? i_5_5c_emitid_5b_15_3a_0_5d_ : p_callbackid.curr)) : p_callbackid.curr) : p_callbackid.curr));
	}
	// cells $procdff$4639 $procmux$4398 $procmux$4035 $procmux$2164 $procmux$1364 $procmux$825
	if (posedge_p_clk) {
		p_transferid.next = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_eq_24_receiver_2e_v_3a_87_24_79__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? p_transferid.curr : (i_logic__and_24_receiver_2e_v_3a_108_24_107__Y ? i_4_5c_idzero_5b_15_3a_0_5d_ : p_transferid.curr)) : p_transferid.curr) : p_transferid.curr));
	}
	// cells $procdff$4638 $procmux$4401 $procmux$4041 $procmux$2173 $procmux$1484
	if (posedge_p_clk) {
		p_emitid.next = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_eq_24_receiver_2e_v_3a_87_24_79__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? p_emitid.curr : i_5_5c_emitid_5b_15_3a_0_5d_) : p_emitid.curr) : p_emitid.curr));
	}
	// cells $procdff$4637 $procmux$4404 $procmux$4047 $procmux$2371 $procmux$1874 $procmux$1656
	if (posedge_p_clk) {
		p_grantid.next = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_eq_24_receiver_2e_v_3a_87_24_79__Y ? (i_logic__and_24_receiver_2e_v_3a_89_24_86__Y ? (i_shiftx_24_receiver_2e_v_3a_91_24_88__Y ? i_6_5c_qid0_5b_15_3a_0_5d_ : p_grantid.curr) : p_grantid.curr) : p_grantid.curr) : p_grantid.curr));
	}
	// cells $procdff$4636 $procmux$4407 $procmux$4053 $procmux$2380 $procmux$2066
	if (posedge_p_clk) {
		p_attemptid.next = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_eq_24_receiver_2e_v_3a_87_24_79__Y ? (i_logic__and_24_receiver_2e_v_3a_89_24_86__Y ? i_6_5c_qid0_5b_15_3a_0_5d_ : p_attemptid.curr) : p_attemptid.curr) : p_attemptid.curr));
	}
	// cells $procdff$4635 $procmux$4410 $procmux$4059 $procmux$2182 $procmux$1496 $procmux$1134 $procmux$1054
	if (posedge_p_clk) {
		p_blockowner.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_eq_24_receiver_2e_v_3a_87_24_79__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? p_blockowner.curr : (p_rone.curr ? (i_ne_24_receiver_2e_v_3a_104_24_105__Y ? p_blockowner.curr : p_ownerone.curr) : p_blockowner.curr)) : p_blockowner.curr) : p_blockowner.curr));
	}
	// cells $procdff$4634 $procmux$4413 $procmux$4065 $procmux$2191 $procmux$1256 $procmux$780
	if (posedge_p_clk) {
		p_callbackowner.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_eq_24_receiver_2e_v_3a_87_24_79__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? p_callbackowner.curr : (i_5_5c_evemit_5b_0_3a_0_5d_ ? i_5_5c_emitowner_5b_0_3a_0_5d_ : p_callbackowner.curr)) : p_callbackowner.curr) : p_callbackowner.curr));
	}
	// cells $procdff$4633 $procmux$4416 $procmux$4071 $procmux$2200 $procmux$1376 $procmux$840
	if (posedge_p_clk) {
		p_transferowner.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_eq_24_receiver_2e_v_3a_87_24_79__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? p_transferowner.curr : (i_logic__and_24_receiver_2e_v_3a_108_24_107__Y ? i_4_5c_ownerzero_5b_0_3a_0_5d_ : p_transferowner.curr)) : p_transferowner.curr) : p_transferowner.curr));
	}
	// cells $procdff$4632 $procmux$4419 $procmux$4077 $procmux$2209 $procmux$1508
	if (posedge_p_clk) {
		p_emitowner.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_eq_24_receiver_2e_v_3a_87_24_79__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? p_emitowner.curr : i_5_5c_emitowner_5b_0_3a_0_5d_) : p_emitowner.curr) : p_emitowner.curr));
	}
	// cells $procdff$4631 $procmux$4422 $procmux$4083 $procmux$2389 $procmux$1886 $procmux$1671
	if (posedge_p_clk) {
		p_grantowner.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_eq_24_receiver_2e_v_3a_87_24_79__Y ? (i_logic__and_24_receiver_2e_v_3a_89_24_86__Y ? (i_shiftx_24_receiver_2e_v_3a_91_24_88__Y ? i_6_5c_qowner0_5b_0_3a_0_5d_ : p_grantowner.curr) : p_grantowner.curr) : p_grantowner.curr) : p_grantowner.curr));
	}
	// cells $procdff$4630 $procmux$4425 $procmux$4089 $procmux$2398 $procmux$2078
	if (posedge_p_clk) {
		p_attemptowner.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_eq_24_receiver_2e_v_3a_87_24_79__Y ? (i_logic__and_24_receiver_2e_v_3a_89_24_86__Y ? i_6_5c_qowner0_5b_0_3a_0_5d_ : p_attemptowner.curr) : p_attemptowner.curr) : p_attemptowner.curr));
	}
	// cells $procdff$4629 $procmux$4428 $procmux$4095 $procmux$2218 $procmux$1520
	if (posedge_p_clk) {
		p_evblock.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_eq_24_receiver_2e_v_3a_87_24_79__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? value<1>{0u} : i_5_5c_evblock_5b_0_3a_0_5d_) : value<1>{0u}) : p_evblock.curr));
	}
	// cells $procdff$4628 $procmux$4431 $procmux$4101 $procmux$2227 $procmux$1268 $procmux$795
	if (posedge_p_clk) {
		p_evcallback.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_eq_24_receiver_2e_v_3a_87_24_79__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? value<1>{0u} : (i_5_5c_evemit_5b_0_3a_0_5d_ ? value<1>{0x1u} : value<1>{0u})) : value<1>{0u}) : p_evcallback.curr));
	}
	// cells $procdff$4627 $procmux$4434 $procmux$4107 $procmux$2236 $procmux$1388 $procmux$855
	if (posedge_p_clk) {
		p_evtransfer.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_eq_24_receiver_2e_v_3a_87_24_79__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_108_24_107__Y ? value<1>{0x1u} : value<1>{0u})) : value<1>{0u}) : p_evtransfer.curr));
	}
	// cells $procdff$4626 $procmux$4437 $procmux$4113 $procmux$2245 $procmux$1532
	if (posedge_p_clk) {
		p_evemit.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_eq_24_receiver_2e_v_3a_87_24_79__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? value<1>{0u} : i_5_5c_evemit_5b_0_3a_0_5d_) : value<1>{0u}) : p_evemit.curr));
	}
	// cells $procdff$4625 $procmux$4440 $procmux$4119 $procmux$2407 $procmux$1898 $procmux$1686
	if (posedge_p_clk) {
		p_evgrant.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_eq_24_receiver_2e_v_3a_87_24_79__Y ? (i_logic__and_24_receiver_2e_v_3a_89_24_86__Y ? (i_shiftx_24_receiver_2e_v_3a_91_24_88__Y ? value<1>{0x1u} : value<1>{0u}) : value<1>{0u}) : value<1>{0u}) : p_evgrant.curr));
	}
	// cells $procdff$4624 $procmux$4443 $procmux$4125 $procmux$2416 $procmux$2090
	if (posedge_p_clk) {
		p_evattempt.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_eq_24_receiver_2e_v_3a_87_24_79__Y ? (i_logic__and_24_receiver_2e_v_3a_89_24_86__Y ? value<1>{0x1u} : value<1>{0u}) : value<1>{0u}) : p_evattempt.curr));
	}
	// cells $procdff$4623 $procmux$4446 $procmux$4263 $procmux$2845 $procmux$2714
	if (posedge_p_clk) {
		p_enqidb.next = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_logic__and_24_receiver_2e_v_3a_76_24_66__Y ? (p_pending.curr.slice<1>().val() ? p_enqidb.curr : i_add_24_receiver_2e_v_3a_80_24_71__Y) : p_enqidb.curr) : p_enqidb.curr));
	}
	// cells $procdff$4622 $procmux$4449 $procmux$4299 $procmux$3283 $procmux$3152
	if (posedge_p_clk) {
		p_enqida.next = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_logic__and_24_receiver_2e_v_3a_65_24_52__Y ? (p_pending.curr.slice<0>().val() ? p_enqida.curr : i_add_24_receiver_2e_v_3a_69_24_57__Y) : p_enqida.curr) : p_enqida.curr));
	}
	// cells $procdff$4621 $procmux$4452
	if (posedge_p_clk) {
		p_evwu.next = (p_rst ? value<2>{0u} : i_2_5c_evwu_5b_1_3a_0_5d_);
	}
	// cells $procdff$4620 $procmux$4455 $procmux$4131 $procmux$2425 $procmux$1910 $procmux$1701 $shift$receiver.v:96$98 $shiftx$receiver.v:96$96 $neg$receiver.v:96$97
	if (posedge_p_clk) {
		p_evcancel.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_eq_24_receiver_2e_v_3a_87_24_79__Y ? (i_logic__and_24_receiver_2e_v_3a_89_24_86__Y ? (i_shiftx_24_receiver_2e_v_3a_91_24_88__Y ? shift_us<2>(shiftx_uu<1>(i_5_5c_enabled_5b_1_3a_0_5d_, i_6_5c_qowner0_5b_0_3a_0_5d_), neg_u<2>(i_6_5c_qowner0_5b_0_3a_0_5d_)) : value<2>{0u}) : value<2>{0u}) : value<2>{0u}) : p_evcancel.curr));
	}
	// cells $procdff$4619 $procmux$4458 $procmux$4326
	if (posedge_p_clk) {
		p_evexpire.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? i_3_5c_evexpire_5b_1_3a_0_5d_ : p_evexpire.curr));
	}
	// cells $procdff$4618 $procmux$4461
	if (posedge_p_clk) {
		p_evenq.next = (p_rst ? value<2>{0u} : i_2_5c_evenq_5b_1_3a_0_5d_);
	}
	// cells $procdff$4617 $procmux$4464
	if (posedge_p_clk) {
		p_evwait.next = (p_rst ? value<2>{0u} : i_2_5c_evwait_5b_1_3a_0_5d_);
	}
	// cells $procdff$4616 $procmux$4380 $procmux$3963 $procmux$4375 $logic_or$receiver.v:46$32 $logic_or$receiver.v:46$30 $logic_or$receiver.v:46$28 $logic_or$receiver.v:46$26 $logic_or$receiver.v:46$24 $logic_or$receiver.v:46$22 $logic_or$receiver.v:46$20 $logic_or$receiver.v:46$16 $lt$receiver.v:46$14 $gt$receiver.v:46$15 $logic_and$receiver.v:46$19 $ne$receiver.v:46$17 $ne$receiver.v:46$18 $ge$receiver.v:46$21 $lt$receiver.v:46$23 $gt$receiver.v:46$25 $lt$receiver.v:46$27 $gt$receiver.v:46$29 $ge$receiver.v:46$31
	if (posedge_p_clk) {
		p_fault.next = (p_rst ? value<15>{0u}.concat((logic_or<1>(logic_or<1>(logic_or<1>(logic_or<1>(logic_or<1>(logic_or<1>(logic_or<1>(logic_or<1>(lt_uu<1>(p_cfgp, value<2>{0x2u}), gt_uu<1>(p_cfgp, value<3>{0x6u})), logic_and<1>(ne_uu<1>(p_cfgr, value<2>{0x3u}), ne_uu<1>(p_cfgr, value<3>{0x5u}))), ge_uu<1>(p_cfgb, p_cfgp)), lt_uu<1>(p_cfgk, value<1>{0x1u})), gt_uu<1>(p_cfgk, value<3>{0x5u})), lt_uu<1>(p_cfgperiod, value<1>{0x1u})), gt_uu<1>(p_cfgperiod, value<5>{0x18u})), ge_uu<1>(p_cfgphi, p_cfgperiod)) ? value<1>{0x1u} : value<1>{0u})).val() : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? i_19_5c_fault_5b_15_3a_0_5d_.slice<15,9>().concat(i_28_5c_fault_5b_15_3a_0_5d_.slice<8,0>()).val() : p_fault.curr));
	}
	// cells $procdff$4615 $procmux$4485 $procmux$4137 $procmux$2434 $procmux$1922 $procmux$1596
	if (posedge_p_clk) {
		p_failtick.next = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_eq_24_receiver_2e_v_3a_87_24_79__Y ? (i_logic__and_24_receiver_2e_v_3a_89_24_86__Y ? (i_shiftx_24_receiver_2e_v_3a_91_24_88__Y ? p_failtick.curr : p_tick.curr) : p_failtick.curr) : p_failtick.curr) : p_failtick.curr));
	}
	// cells $procdff$4614 $procmux$4488 $procmux$4143 $procmux$2443 $procmux$1934 $procmux$1581
	if (posedge_p_clk) {
		p_failowner.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_eq_24_receiver_2e_v_3a_87_24_79__Y ? (i_logic__and_24_receiver_2e_v_3a_89_24_86__Y ? (i_shiftx_24_receiver_2e_v_3a_91_24_88__Y ? p_failowner.curr : i_6_5c_qowner0_5b_0_3a_0_5d_) : p_failowner.curr) : p_failowner.curr) : p_failowner.curr));
	}
	// cells $procdff$4613 $procmux$4491 $procmux$4149 $procmux$2452
	if (posedge_p_clk) {
		p_failed.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_eq_24_receiver_2e_v_3a_87_24_79__Y ? i_4_5c_failed_5b_0_3a_0_5d_ : p_failed.curr) : p_failed.curr));
	}
	// cells $procdff$4612 $procmux$4500 $procmux$4155 $procmux$2461 $procmux$1958 $procmux$1716 $procmux$1545
	if (posedge_p_clk) {
		p_countb.next = (p_rst ? value<3>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_eq_24_receiver_2e_v_3a_87_24_79__Y ? (i_logic__and_24_receiver_2e_v_3a_89_24_86__Y ? (i_shiftx_24_receiver_2e_v_3a_91_24_88__Y ? (i_6_5c_qowner0_5b_0_3a_0_5d_ ? value<3>{0u} : i_4_5c_countb_5b_2_3a_0_5d_) : i_4_5c_countb_5b_2_3a_0_5d_) : i_4_5c_countb_5b_2_3a_0_5d_) : i_4_5c_countb_5b_2_3a_0_5d_) : p_countb.curr));
	}
	// cells $procdff$4611 $procmux$4503 $procmux$4161 $procmux$2470 $procmux$1970 $procmux$1731 $procmux$1563
	if (posedge_p_clk) {
		p_counta.next = (p_rst ? value<3>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_eq_24_receiver_2e_v_3a_87_24_79__Y ? (i_logic__and_24_receiver_2e_v_3a_89_24_86__Y ? (i_shiftx_24_receiver_2e_v_3a_91_24_88__Y ? (i_6_5c_qowner0_5b_0_3a_0_5d_ ? i_4_5c_counta_5b_2_3a_0_5d_ : value<3>{0u}) : i_4_5c_counta_5b_2_3a_0_5d_) : i_4_5c_counta_5b_2_3a_0_5d_) : i_4_5c_counta_5b_2_3a_0_5d_) : p_counta.curr));
	}
	// cells $procdff$4610 $procmux$4506 $procmux$4350
	if (posedge_p_clk) {
		p_datab.next = (p_rst ? value<8>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? i_3_5c_datab_5b_7_3a_0_5d_ : p_datab.curr));
	}
	// cells $procdff$4609 $procmux$4509 $procmux$4362
	if (posedge_p_clk) {
		p_dataa.next = (p_rst ? value<8>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? i_3_5c_dataa_5b_7_3a_0_5d_ : p_dataa.curr));
	}
	// cells $procdff$4608 $procmux$4512 $procmux$4167 $procmux$2263 $procmux$1400 $procmux$885
	if (posedge_p_clk) {
		p_byteone.next = (p_rst ? value<8>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_eq_24_receiver_2e_v_3a_87_24_79__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? p_byteone.curr : (i_logic__and_24_receiver_2e_v_3a_108_24_107__Y ? i_4_5c_bytezero_5b_7_3a_0_5d_ : p_byteone.curr)) : p_byteone.curr) : p_byteone.curr));
	}
	// cells $procdff$4607 $procmux$4515 $procmux$4173 $procmux$2479
	if (posedge_p_clk) {
		p_bytezero.next = (p_rst ? value<8>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_eq_24_receiver_2e_v_3a_87_24_79__Y ? i_4_5c_bytezero_5b_7_3a_0_5d_ : p_bytezero.curr) : p_bytezero.curr));
	}
	// cells $procdff$4606 $procmux$4518 $procmux$4179 $procmux$2272 $procmux$1412 $procmux$900
	if (posedge_p_clk) {
		p_idone.next = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_eq_24_receiver_2e_v_3a_87_24_79__Y ? (i_4_5c_failed_5b_0_3a_0_5d_ ? p_idone.curr : (i_logic__and_24_receiver_2e_v_3a_108_24_107__Y ? i_4_5c_idzero_5b_15_3a_0_5d_ : p_idone.curr)) : p_idone.curr) : p_idone.curr));
	}
	// cells $procdff$4605 $procmux$4521 $procmux$4185 $procmux$2488
	if (posedge_p_clk) {
		p_idzero.next = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_eq_24_receiver_2e_v_3a_87_24_79__Y ? i_4_5c_idzero_5b_15_3a_0_5d_ : p_idzero.curr) : p_idzero.curr));
	}
	// cells $procdff$4604 $procmux$4524 $procmux$4191
	if (posedge_p_clk) {
		p_ownerone.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? i_3_5c_ownerone_5b_0_3a_0_5d_ : p_ownerone.curr));
	}
	// cells $procdff$4603 $procmux$4527 $procmux$4197
	if (posedge_p_clk) {
		p_ownerzero.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? i_3_5c_ownerzero_5b_0_3a_0_5d_ : p_ownerzero.curr));
	}
	// cells $procdff$4602 $procmux$4530 $procmux$4203
	if (posedge_p_clk) {
		p_rone.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? i_3_5c_rone_5b_0_3a_0_5d_ : p_rone.curr));
	}
	// cells $procdff$4601 $procmux$4533 $procmux$4209
	if (posedge_p_clk) {
		p_rzero.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? i_3_5c_rzero_5b_0_3a_0_5d_ : p_rzero.curr));
	}
	// cells $procdff$4600 $procmux$4536 $procmux$4281
	if (posedge_p_clk) {
		p_qid1.next = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? i_7_5c_qid1_5b_15_3a_0_5d_ : p_qid1.curr));
	}
	// cells $procdff$4599 $procmux$4539 $procmux$4215 $procmux$2506 $procmux$2030 $procmux$1806
	if (posedge_p_clk) {
		p_qid0.next = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_eq_24_receiver_2e_v_3a_87_24_79__Y ? (i_logic__and_24_receiver_2e_v_3a_89_24_86__Y ? (i_shiftx_24_receiver_2e_v_3a_91_24_88__Y ? i_7_5c_qid1_5b_15_3a_0_5d_ : i_6_5c_qid0_5b_15_3a_0_5d_) : i_6_5c_qid0_5b_15_3a_0_5d_) : i_6_5c_qid0_5b_15_3a_0_5d_) : p_qid0.curr));
	}
	// cells $procdff$4598 $procmux$4542 $procmux$4287
	if (posedge_p_clk) {
		p_qowner1.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? i_7_5c_qowner1_5b_0_3a_0_5d_ : p_qowner1.curr));
	}
	// cells $procdff$4597 $procmux$4545 $procmux$4221
	if (posedge_p_clk) {
		p_qowner0.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? i_9_5c_qowner0_5b_0_3a_0_5d_ : p_qowner0.curr));
	}
	// cells $procdff$4596 $procmux$4548 $procmux$4227
	if (posedge_p_clk) {
		p_qlen.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? i_7_5c_qlen_5b_1_3a_0_5d_ : p_qlen.curr));
	}
	// cells $procdff$4595 $procmux$4551 $procmux$4293 $procmux$2926 $procmux$2810
	if (posedge_p_clk) {
		p_seqb.next = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_logic__and_24_receiver_2e_v_3a_76_24_66__Y ? (p_pending.curr.slice<1>().val() ? p_seqb.curr : i_add_24_receiver_2e_v_3a_80_24_71__Y) : p_seqb.curr) : p_seqb.curr));
	}
	// cells $procdff$4594 $procmux$4554 $procmux$4320 $procmux$3364 $procmux$3248
	if (posedge_p_clk) {
		p_seqa.next = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? (i_logic__and_24_receiver_2e_v_3a_65_24_52__Y ? (p_pending.curr.slice<0>().val() ? p_seqa.curr : i_add_24_receiver_2e_v_3a_69_24_57__Y) : p_seqa.curr) : p_seqa.curr));
	}
	// cells $procdff$4593 $procmux$4557 $procmux$4233
	if (posedge_p_clk) {
		p_pollb.next = (p_rst ? value<13>{0u}.concat(p_cfgb).val() : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? i_5_5c_pollb_5b_15_3a_0_5d_ : p_pollb.curr));
	}
	// cells $procdff$4592 $procmux$4560 $procmux$4239
	if (posedge_p_clk) {
		p_polla.next = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? i_5_5c_polla_5b_15_3a_0_5d_ : p_polla.curr));
	}
	// cells $procdff$4591 $procmux$4494 $procmux$4332
	if (posedge_p_clk) {
		p_enabled.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? i_5_5c_enabled_5b_1_3a_0_5d_ : p_enabled.curr));
	}
	// cells $procdff$4590 $procmux$4497 $procmux$4338
	if (posedge_p_clk) {
		p_valid.next = (p_rst ? value<2>{0x3u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? i_3_5c_valid_5b_1_3a_0_5d_ : p_valid.curr));
	}
	// cells $procdff$4589 $procmux$4563 $procmux$4245
	if (posedge_p_clk) {
		p_pollen.next = (p_rst ? value<2>{0x3u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? i_7_5c_pollen_5b_1_3a_0_5d_ : p_pollen.curr));
	}
	// cells $procdff$4588 $procmux$4566 $procmux$4251
	if (posedge_p_clk) {
		p_waiting.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? i_7_5c_waiting_5b_1_3a_0_5d_ : p_waiting.curr));
	}
	// cells $procdff$4587 $procmux$4569 $procmux$4257
	if (posedge_p_clk) {
		p_pending.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? i_7_5c_pending_5b_1_3a_0_5d_ : p_pending.curr));
	}
	// cells $procdff$4586 $procmux$4572 $procmux$3957 $add$receiver.v:134$181
	if (posedge_p_clk) {
		p_tick.next = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_47_24_35__Y ? add_uu<16>(p_tick.curr, value<1>{0x1u}) : p_tick.curr));
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
		items->add(path, "14\\fault[15:0]", "src\000sreceiver.v:33.2-139.5\000", i_14_5c_fault_5b_15_3a_0_5d_, 0, debug_item::GENERATED|debug_item::DRIVEN_COMB);
		items->add(path, "15\\fault[15:0]", "src\000sreceiver.v:33.2-139.5\000", i_15_5c_fault_5b_15_3a_0_5d_, 0, debug_item::GENERATED|debug_item::DRIVEN_COMB);
		items->add(path, "9\\fault[15:0]", "src\000sreceiver.v:33.2-139.5\000", i_9_5c_fault_5b_15_3a_0_5d_, 0, debug_item::GENERATED|debug_item::DRIVEN_COMB);
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
