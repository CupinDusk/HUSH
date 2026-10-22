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
// \src: receiver.v:3.1-130.10
struct p_receiver : public module {
	// \src: receiver.v:42.2-129.5
	wire<32> i_11_5c_fault_5b_31_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	wire<32> i_14_5c_fault_5b_31_3a_0_5d_;
	wire<32> i_procmux_24_5693__Y;
	// \src: receiver.v:30.26-30.35
	/*output*/ wire<32> p_attemptid;
	// \src: receiver.v:29.28-29.40
	/*output*/ wire<2> p_attemptowner;
	// \src: receiver.v:30.73-30.80
	/*output*/ wire<32> p_blockid;
	// \src: receiver.v:29.90-29.100
	/*output*/ wire<2> p_blockowner;
	// \src: receiver.v:22.28-22.35
	/*output*/ wire<8> p_byteone;
	// \src: receiver.v:14.20-14.25
	/*output*/ wire<32> p_bytes;
	// \src: receiver.v:22.19-22.27
	/*output*/ wire<8> p_bytezero;
	// \src: receiver.v:30.62-30.72
	/*output*/ wire<32> p_callbackid;
	// \src: receiver.v:29.76-29.89
	/*output*/ wire<2> p_callbackowner;
	// \src: receiver.v:7.15-7.20
	/*input*/ value<16> p_cfgcp;
	// \src: receiver.v:5.25-5.29
	/*input*/ value<16> p_cfgf;
	// \src: receiver.v:7.27-7.32
	/*input*/ value<16> p_cfgfp;
	// \src: receiver.v:5.30-5.34
	/*input*/ value<16> p_cfgk;
	// \src: receiver.v:5.15-5.19
	/*input*/ value<16> p_cfgp;
	// \src: receiver.v:5.35-5.44
	/*input*/ value<16> p_cfgperiod;
	// \src: receiver.v:5.45-5.51
	/*input*/ value<16> p_cfgphi;
	// \src: receiver.v:7.33-7.38
	/*input*/ value<16> p_cfgpp;
	// \src: receiver.v:5.20-5.24
	/*input*/ value<16> p_cfgr;
	// \src: receiver.v:7.21-7.26
	/*input*/ value<16> p_cfgrp;
	// \src: receiver.v:6.15-6.23
	/*input*/ value<32> p_cfgstart;
	// \src: receiver.v:4.8-4.11
	/*input*/ value<1> p_clk;
	value<1> prev_p_clk;
	bool posedge_p_clk() const {
		return !prev_p_clk.slice<0>().val() && p_clk.slice<0>().val();
	}
	// \src: receiver.v:13.20-13.26
	/*output*/ wire<64> p_counts;
	// \src: receiver.v:11.20-11.22
	/*output*/ wire<16> p_cp;
	// \src: receiver.v:33.29-33.37
	/*output*/ wire<8> p_emitbyte;
	// \src: receiver.v:30.44-30.50
	/*output*/ wire<32> p_emitid;
	// \src: receiver.v:29.52-29.61
	/*output*/ wire<2> p_emitowner;
	// \src: receiver.v:12.25-12.32
	/*output*/ wire<4> p_enabled;
	// \src: receiver.v:30.20-30.25
	/*output*/ wire<32> p_enqid;
	// \src: receiver.v:32.20-32.26
	/*output*/ wire<32> p_enqid2;
	// \src: receiver.v:29.19-29.27
	/*output*/ wire<2> p_enqowner;
	// \src: receiver.v:31.19-31.28
	/*output*/ wire<2> p_enqowner2;
	// \src: receiver.v:28.13-28.22
	/*output*/ wire<1> p_evattempt;
	// \src: receiver.v:28.60-28.67
	/*output*/ wire<1> p_evblock;
	// \src: receiver.v:28.49-28.59
	/*output*/ wire<1> p_evcallback;
	// \src: receiver.v:26.33-26.41
	/*output*/ wire<4> p_evcancel;
	// \src: receiver.v:28.31-28.37
	/*output*/ wire<1> p_evemit;
	// \src: receiver.v:27.19-27.24
	/*output*/ wire<2> p_evenq;
	// \src: receiver.v:26.24-26.32
	/*output*/ wire<4> p_evexpire;
	// \src: receiver.v:28.23-28.30
	/*output*/ wire<1> p_evgrant;
	// \src: receiver.v:28.38-28.48
	/*output*/ wire<1> p_evtransfer;
	// \src: receiver.v:26.19-26.23
	/*output*/ wire<4> p_evwu;
	// \src: receiver.v:23.13-23.19
	/*output*/ wire<1> p_failed;
	// \src: receiver.v:24.29-24.35
	/*output*/ wire<32> p_failid;
	// \src: receiver.v:25.19-25.28
	/*output*/ wire<2> p_failowner;
	// \src: receiver.v:24.20-24.28
	/*output*/ wire<32> p_failtick;
	// \src: receiver.v:24.36-24.41
	/*output*/ wire<32> p_fault;
	// \src: receiver.v:11.26-11.28
	/*output*/ wire<16> p_fp;
	// \src: receiver.v:33.19-33.28
	/*output*/ wire<8> p_grantbyte;
	// \src: receiver.v:30.36-30.43
	/*output*/ wire<32> p_grantid;
	// \src: receiver.v:29.41-29.51
	/*output*/ wire<2> p_grantowner;
	// \src: receiver.v:21.27-21.32
	/*output*/ wire<32> p_idone;
	// \src: receiver.v:21.20-21.26
	/*output*/ wire<32> p_idzero;
	// \src: receiver.v:10.25-10.31
	/*output*/ wire<32> p_nextid;
	// \src: receiver.v:18.20-18.31
	/*output*/ wire<16> p_outstanding;
	// \src: receiver.v:20.29-20.37
	/*output*/ wire<2> p_ownerone;
	// \src: receiver.v:20.19-20.28
	/*output*/ wire<2> p_ownerzero;
	// \src: receiver.v:11.29-11.31
	/*output*/ wire<16> p_pp;
	// \src: receiver.v:35.32-35.34
	wire<32> p_qi_5b_0_5d_;
	// \src: receiver.v:35.32-35.34
	wire<32> p_qi_5b_1_5d_;
	// \src: receiver.v:35.32-35.34
	wire<32> p_qi_5b_2_5d_;
	// \src: receiver.v:35.32-35.34
	wire<32> p_qi_5b_3_5d_;
	// \src: receiver.v:35.32-35.34
	wire<32> p_qi_5b_4_5d_;
	// \src: receiver.v:35.32-35.34
	wire<32> p_qi_5b_5_5d_;
	// \src: receiver.v:35.32-35.34
	wire<32> p_qi_5b_6_5d_;
	// \src: receiver.v:35.32-35.34
	wire<32> p_qi_5b_7_5d_;
	// \src: receiver.v:17.17-17.21
	/*output*/ value<256> p_qids;
	// \src: receiver.v:15.19-15.23
	/*output*/ wire<4> p_qlen;
	// \src: receiver.v:35.12-35.14
	wire<2> p_qo_5b_0_5d_;
	// \src: receiver.v:35.12-35.14
	wire<2> p_qo_5b_1_5d_;
	// \src: receiver.v:35.12-35.14
	wire<2> p_qo_5b_2_5d_;
	// \src: receiver.v:35.12-35.14
	wire<2> p_qo_5b_3_5d_;
	// \src: receiver.v:35.12-35.14
	wire<2> p_qo_5b_4_5d_;
	// \src: receiver.v:35.12-35.14
	wire<2> p_qo_5b_5_5d_;
	// \src: receiver.v:35.12-35.14
	wire<2> p_qo_5b_6_5d_;
	// \src: receiver.v:35.12-35.14
	wire<2> p_qo_5b_7_5d_;
	// \src: receiver.v:16.16-16.23
	/*output*/ value<16> p_qowners;
	// \src: receiver.v:19.19-19.23
	/*output*/ wire<1> p_rone;
	// \src: receiver.v:11.23-11.25
	/*output*/ wire<16> p_rp;
	// \src: receiver.v:4.12-4.15
	/*input*/ value<1> p_rst;
	// \src: receiver.v:19.13-19.18
	/*output*/ wire<1> p_rzero;
	// \src: receiver.v:10.20-10.24
	/*output*/ wire<32> p_tick;
	// \src: receiver.v:33.38-33.50
	/*output*/ wire<8> p_transferbyte;
	// \src: receiver.v:30.51-30.61
	/*output*/ wire<32> p_transferid;
	// \src: receiver.v:29.62-29.75
	/*output*/ wire<2> p_transferowner;
	// \src: receiver.v:12.19-12.24
	/*output*/ wire<4> p_valid;
	// \src: receiver.v:8.14-8.16
	/*input*/ value<4> p_wu;
	// \src: receiver.v:9.15-9.22
	/*input*/ value<32> p_wubytes;
	p_receiver(interior) {}
	p_receiver() {
		reset();
	};

	void reset() override;

	bool eval(performer *performer = nullptr) override;

	template<class ObserverT>
	bool commit(ObserverT &observer) {
		bool changed = false;
		if (i_11_5c_fault_5b_31_3a_0_5d_.commit(observer)) changed = true;
		if (i_14_5c_fault_5b_31_3a_0_5d_.commit(observer)) changed = true;
		if (i_procmux_24_5693__Y.commit(observer)) changed = true;
		if (p_attemptid.commit(observer)) changed = true;
		if (p_attemptowner.commit(observer)) changed = true;
		if (p_blockid.commit(observer)) changed = true;
		if (p_blockowner.commit(observer)) changed = true;
		if (p_byteone.commit(observer)) changed = true;
		if (p_bytes.commit(observer)) changed = true;
		if (p_bytezero.commit(observer)) changed = true;
		if (p_callbackid.commit(observer)) changed = true;
		if (p_callbackowner.commit(observer)) changed = true;
		prev_p_clk = p_clk;
		if (p_counts.commit(observer)) changed = true;
		if (p_cp.commit(observer)) changed = true;
		if (p_emitbyte.commit(observer)) changed = true;
		if (p_emitid.commit(observer)) changed = true;
		if (p_emitowner.commit(observer)) changed = true;
		if (p_enabled.commit(observer)) changed = true;
		if (p_enqid.commit(observer)) changed = true;
		if (p_enqid2.commit(observer)) changed = true;
		if (p_enqowner.commit(observer)) changed = true;
		if (p_enqowner2.commit(observer)) changed = true;
		if (p_evattempt.commit(observer)) changed = true;
		if (p_evblock.commit(observer)) changed = true;
		if (p_evcallback.commit(observer)) changed = true;
		if (p_evcancel.commit(observer)) changed = true;
		if (p_evemit.commit(observer)) changed = true;
		if (p_evenq.commit(observer)) changed = true;
		if (p_evexpire.commit(observer)) changed = true;
		if (p_evgrant.commit(observer)) changed = true;
		if (p_evtransfer.commit(observer)) changed = true;
		if (p_evwu.commit(observer)) changed = true;
		if (p_failed.commit(observer)) changed = true;
		if (p_failid.commit(observer)) changed = true;
		if (p_failowner.commit(observer)) changed = true;
		if (p_failtick.commit(observer)) changed = true;
		if (p_fault.commit(observer)) changed = true;
		if (p_fp.commit(observer)) changed = true;
		if (p_grantbyte.commit(observer)) changed = true;
		if (p_grantid.commit(observer)) changed = true;
		if (p_grantowner.commit(observer)) changed = true;
		if (p_idone.commit(observer)) changed = true;
		if (p_idzero.commit(observer)) changed = true;
		if (p_nextid.commit(observer)) changed = true;
		if (p_outstanding.commit(observer)) changed = true;
		if (p_ownerone.commit(observer)) changed = true;
		if (p_ownerzero.commit(observer)) changed = true;
		if (p_pp.commit(observer)) changed = true;
		if (p_qi_5b_0_5d_.commit(observer)) changed = true;
		if (p_qi_5b_1_5d_.commit(observer)) changed = true;
		if (p_qi_5b_2_5d_.commit(observer)) changed = true;
		if (p_qi_5b_3_5d_.commit(observer)) changed = true;
		if (p_qi_5b_4_5d_.commit(observer)) changed = true;
		if (p_qi_5b_5_5d_.commit(observer)) changed = true;
		if (p_qi_5b_6_5d_.commit(observer)) changed = true;
		if (p_qi_5b_7_5d_.commit(observer)) changed = true;
		if (p_qlen.commit(observer)) changed = true;
		if (p_qo_5b_0_5d_.commit(observer)) changed = true;
		if (p_qo_5b_1_5d_.commit(observer)) changed = true;
		if (p_qo_5b_2_5d_.commit(observer)) changed = true;
		if (p_qo_5b_3_5d_.commit(observer)) changed = true;
		if (p_qo_5b_4_5d_.commit(observer)) changed = true;
		if (p_qo_5b_5_5d_.commit(observer)) changed = true;
		if (p_qo_5b_6_5d_.commit(observer)) changed = true;
		if (p_qo_5b_7_5d_.commit(observer)) changed = true;
		if (p_rone.commit(observer)) changed = true;
		if (p_rp.commit(observer)) changed = true;
		if (p_rzero.commit(observer)) changed = true;
		if (p_tick.commit(observer)) changed = true;
		if (p_transferbyte.commit(observer)) changed = true;
		if (p_transferid.commit(observer)) changed = true;
		if (p_transferowner.commit(observer)) changed = true;
		if (p_valid.commit(observer)) changed = true;
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
	// \src: receiver.v:42.2-129.5
	value<32> i_10_5c_fault_5b_31_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<4> i_11_5c_tokens0_5b_3_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<4> i_11_5c_tokens1_5b_3_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<4> i_11_5c_tokens2_5b_3_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<4> i_11_5c_tokens3_5b_3_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<32> i_12_5c_fault_5b_31_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<32> i_13_5c_fault_5b_31_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<4> i_13_5c_tokens0_5b_3_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<4> i_13_5c_tokens1_5b_3_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<4> i_13_5c_tokens2_5b_3_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<4> i_13_5c_tokens3_5b_3_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<32> i_15_5c_fault_5b_31_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<4> i_15_5c_tokens0_5b_3_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<4> i_15_5c_tokens1_5b_3_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<4> i_15_5c_tokens2_5b_3_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<4> i_15_5c_tokens3_5b_3_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<32> i_16_5c_fault_5b_31_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<32> i_17_5c_fault_5b_31_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<4> i_17_5c_tokens0_5b_3_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<4> i_17_5c_tokens1_5b_3_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<4> i_17_5c_tokens2_5b_3_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<4> i_17_5c_tokens3_5b_3_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<32> i_18_5c_fault_5b_31_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<32> i_19_5c_fault_5b_31_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<4> i_19_5c_tokens0_5b_3_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<4> i_19_5c_tokens1_5b_3_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<4> i_19_5c_tokens2_5b_3_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<4> i_19_5c_tokens3_5b_3_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<32> i_20_5c_fault_5b_31_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<32> i_21_5c_fault_5b_31_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<32> i_22_5c_fault_5b_31_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<32> i_23_5c_fault_5b_31_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<32> i_2_5c_bytes_5b_31_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<4> i_2_5c_evwu_5b_3_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<8> i_3_5c_bytes_5b_7_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<8> i_3_5c_bytezero_5b_7_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<16> i_3_5c_counts_5b_15_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<1> i_3_5c_enabled_5b_0_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<32> i_3_5c_enqid_5b_31_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<2> i_3_5c_enqowner_5b_1_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<2> i_3_5c_evenq_5b_1_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<4> i_3_5c_evexpire_5b_3_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<1> i_3_5c_failed_5b_0_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<32> i_3_5c_idzero_5b_31_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<32> i_3_5c_nextid_5b_31_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<16> i_3_5c_outstanding_5b_15_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<2> i_3_5c_ownerone_5b_1_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<2> i_3_5c_ownerzero_5b_1_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<32> i_3_5c_qi_5b_0_5d__5b_31_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<32> i_3_5c_qi_5b_1_5d__5b_31_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<32> i_3_5c_qi_5b_2_5d__5b_31_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<32> i_3_5c_qi_5b_3_5d__5b_31_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<32> i_3_5c_qi_5b_4_5d__5b_31_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<32> i_3_5c_qi_5b_5_5d__5b_31_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<32> i_3_5c_qi_5b_6_5d__5b_31_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<32> i_3_5c_qi_5b_7_5d__5b_31_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<4> i_3_5c_qlen_5b_3_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<2> i_3_5c_qo_5b_0_5d__5b_1_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<2> i_3_5c_qo_5b_1_5d__5b_1_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<2> i_3_5c_qo_5b_2_5d__5b_1_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<2> i_3_5c_qo_5b_3_5d__5b_1_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<2> i_3_5c_qo_5b_4_5d__5b_1_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<2> i_3_5c_qo_5b_5_5d__5b_1_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<2> i_3_5c_qo_5b_6_5d__5b_1_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<2> i_3_5c_qo_5b_7_5d__5b_1_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<1> i_3_5c_rone_5b_0_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<1> i_3_5c_rzero_5b_0_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<4> i_3_5c_tokens0_5b_3_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<4> i_3_5c_tokens1_5b_3_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<4> i_3_5c_tokens2_5b_3_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<4> i_3_5c_tokens3_5b_3_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<4> i_3_5c_valid_5b_3_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<8> i_4_5c_bytes_5b_15_3a_8_5d_;
	// \src: receiver.v:42.2-129.5
	value<16> i_4_5c_counts_5b_31_3a_16_5d_;
	// \src: receiver.v:42.2-129.5
	value<32> i_4_5c_emitid_5b_31_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<2> i_4_5c_emitowner_5b_1_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<1> i_4_5c_enabled_5b_1_3a_1_5d_;
	// \src: receiver.v:42.2-129.5
	value<1> i_4_5c_evblock_5b_0_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<1> i_4_5c_evemit_5b_0_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<32> i_4_5c_fault_5b_31_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<1> i_4_5c_rone_5b_0_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<8> i_5_5c_bytes_5b_23_3a_16_5d_;
	// \src: receiver.v:42.2-129.5
	value<16> i_5_5c_counts_5b_47_3a_32_5d_;
	// \src: receiver.v:42.2-129.5
	value<1> i_5_5c_enabled_5b_2_3a_2_5d_;
	// \src: receiver.v:42.2-129.5
	value<2> i_5_5c_enqowner_5b_1_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<32> i_5_5c_fault_5b_31_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<32> i_5_5c_nextid_5b_31_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<16> i_5_5c_outstanding_5b_15_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<4> i_5_5c_qlen_5b_3_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<1> i_5_5c_releasevalid_5b_0_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<1> i_5_5c_rzero_5b_0_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<4> i_5_5c_tokens0_5b_3_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<4> i_5_5c_tokens1_5b_3_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<4> i_5_5c_tokens2_5b_3_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<4> i_5_5c_tokens3_5b_3_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<8> i_6_5c_bytes_5b_31_3a_24_5d_;
	// \src: receiver.v:42.2-129.5
	value<16> i_6_5c_counts_5b_63_3a_48_5d_;
	// \src: receiver.v:42.2-129.5
	value<1> i_6_5c_enabled_5b_3_3a_3_5d_;
	// \src: receiver.v:42.2-129.5
	value<32> i_6_5c_fault_5b_31_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<32> i_6_5c_qi_5b_0_5d__5b_31_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<32> i_6_5c_qi_5b_1_5d__5b_31_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<32> i_6_5c_qi_5b_2_5d__5b_31_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<32> i_6_5c_qi_5b_3_5d__5b_31_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<32> i_6_5c_qi_5b_4_5d__5b_31_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<32> i_6_5c_qi_5b_5_5d__5b_31_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<32> i_6_5c_qi_5b_6_5d__5b_31_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<32> i_6_5c_qi_5b_7_5d__5b_31_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<2> i_6_5c_qo_5b_0_5d__5b_1_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<2> i_6_5c_qo_5b_1_5d__5b_1_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<2> i_6_5c_qo_5b_2_5d__5b_1_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<2> i_6_5c_qo_5b_3_5d__5b_1_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<2> i_6_5c_qo_5b_4_5d__5b_1_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<2> i_6_5c_qo_5b_5_5d__5b_1_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<2> i_6_5c_qo_5b_6_5d__5b_1_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<2> i_6_5c_qo_5b_7_5d__5b_1_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<64> i_7_5c_counts_5b_63_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<4> i_7_5c_enabled_5b_3_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<32> i_7_5c_fault_5b_31_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<16> i_7_5c_outstanding_5b_15_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<4> i_7_5c_qlen_5b_3_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<4> i_7_5c_tokens0_5b_3_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<4> i_7_5c_tokens1_5b_3_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<4> i_7_5c_tokens2_5b_3_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<4> i_7_5c_tokens3_5b_3_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<32> i_8_5c_fault_5b_31_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<2> i_8_5c_releaseowner_5b_1_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<1> i_8_5c_releasevalid_5b_0_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<32> i_9_5c_fault_5b_31_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<2> i_9_5c_qo_5b_0_5d__5b_1_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<2> i_9_5c_qo_5b_1_5d__5b_1_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<2> i_9_5c_qo_5b_2_5d__5b_1_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<2> i_9_5c_qo_5b_3_5d__5b_1_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<2> i_9_5c_qo_5b_4_5d__5b_1_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<2> i_9_5c_qo_5b_5_5d__5b_1_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<2> i_9_5c_qo_5b_6_5d__5b_1_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<2> i_9_5c_qo_5b_7_5d__5b_1_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<4> i_9_5c_tokens0_5b_3_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<4> i_9_5c_tokens1_5b_3_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<4> i_9_5c_tokens2_5b_3_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<4> i_9_5c_tokens3_5b_3_3a_0_5d_;
	value<6> i_add_24_receiver_2e_v_3a_109_24_255__Y;
	value<17> i_add_24_receiver_2e_v_3a_124_24_330__Y;
	value<17> i_add_24_receiver_2e_v_3a_125_24_333__Y;
	value<17> i_add_24_receiver_2e_v_3a_126_24_336__Y;
	value<17> i_add_24_receiver_2e_v_3a_127_24_339__Y;
	value<6> i_add_24_receiver_2e_v_3a_82_24_141__Y;
	value<6> i_add_24_receiver_2e_v_3a_82_24_188__Y;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6962;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6964;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6966;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6968;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6970;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6972;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6974;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6976;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6982;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6984;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6988;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6990;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6998;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_7008;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_7016;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_7022;
	// \src: receiver.v:110.11-110.68
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7145;
	// \src: receiver.v:110.11-110.68
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7146;
	// \src: receiver.v:110.39-110.68
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7147;
	// \src: receiver.v:110.11-110.68
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7149;
	// \src: receiver.v:110.11-110.68
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7150;
	// \src: receiver.v:109.21-109.32
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7152;
	// \src: receiver.v:95.27-95.33
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7153;
	// \src: receiver.v:93.61-93.69
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7155;
	// \src: receiver.v:93.37-93.53
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7156;
	// \src: receiver.v:93.37-93.53
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7157;
	// \src: receiver.v:93.37-93.53
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7159;
	// \src: receiver.v:93.37-93.53
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7160;
	// \src: receiver.v:91.63-91.70
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7162;
	// \src: receiver.v:83.7-83.70
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7163;
	// \src: receiver.v:83.7-83.70
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7164;
	// \src: receiver.v:83.7-83.70
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7167;
	// \src: receiver.v:83.7-83.70
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7168;
	// \src: receiver.v:82.22-82.36
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7170;
	// \src: receiver.v:74.78-74.83
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7173;
	// \src: receiver.v:83.7-83.70
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7174;
	// \src: receiver.v:83.7-83.70
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7175;
	// \src: receiver.v:83.7-83.70
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7178;
	// \src: receiver.v:83.7-83.70
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7179;
	// \src: receiver.v:82.22-82.36
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7181;
	// \src: receiver.v:65.35-65.53
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7184;
	// \src: receiver.v:65.35-65.53
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7185;
	// \src: receiver.v:65.35-65.53
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7186;
	// \src: receiver.v:65.35-65.53
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7187;
	value<2> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7188;
	// \src: receiver.v:109.9-109.39
	value<1> i_eq_24_receiver_2e_v_3a_109_24_257__Y;
	// \src: receiver.v:61.7-61.17
	value<1> i_eq_24_receiver_2e_v_3a_61_24_94__Y;
	// \src: receiver.v:64.10-64.29
	value<1> i_eq_24_receiver_2e_v_3a_64_24_103__Y;
	// \src: receiver.v:64.10-64.29
	value<1> i_eq_24_receiver_2e_v_3a_64_24_107__Y;
	// \src: receiver.v:64.10-64.29
	value<1> i_eq_24_receiver_2e_v_3a_64_24_95__Y;
	// \src: receiver.v:64.10-64.29
	value<1> i_eq_24_receiver_2e_v_3a_64_24_99__Y;
	// \src: receiver.v:65.57-65.76
	value<1> i_eq_24_receiver_2e_v_3a_65_24_102__Y;
	// \src: receiver.v:65.57-65.76
	value<1> i_eq_24_receiver_2e_v_3a_65_24_106__Y;
	// \src: receiver.v:65.57-65.76
	value<1> i_eq_24_receiver_2e_v_3a_65_24_110__Y;
	// \src: receiver.v:65.57-65.76
	value<1> i_eq_24_receiver_2e_v_3a_65_24_98__Y;
	// \src: receiver.v:78.10-78.18
	value<1> i_eq_24_receiver_2e_v_3a_78_24_183__Y;
	// \src: receiver.v:76.9-76.16
	value<1> i_ge_24_receiver_2e_v_3a_76_24_129__Y;
	// \src: receiver.v:76.9-76.16
	value<1> i_ge_24_receiver_2e_v_3a_76_24_176__Y;
	// \src: receiver.v:103.8-103.22
	value<1> i_logic__and_24_receiver_2e_v_3a_103_24_252__Y;
	// \src: receiver.v:55.15-55.34
	value<1> i_logic__and_24_receiver_2e_v_3a_55_24_75__Y;
	// \src: receiver.v:59.8-59.25
	value<1> i_logic__and_24_receiver_2e_v_3a_59_24_90__Y;
	// \src: receiver.v:59.8-59.25
	value<1> i_logic__and_24_receiver_2e_v_3a_59_24_91__Y;
	// \src: receiver.v:59.8-59.25
	value<1> i_logic__and_24_receiver_2e_v_3a_59_24_92__Y;
	// \src: receiver.v:59.8-59.25
	value<1> i_logic__and_24_receiver_2e_v_3a_59_24_93__Y;
	// \src: receiver.v:72.8-72.20
	value<1> i_logic__and_24_receiver_2e_v_3a_72_24_112__Y;
	// \src: receiver.v:73.8-73.32
	value<1> i_logic__and_24_receiver_2e_v_3a_73_24_163__Y;
	// \src: receiver.v:74.8-74.43
	value<1> i_logic__and_24_receiver_2e_v_3a_74_24_169__Y;
	// \src: receiver.v:87.7-87.37
	value<1> i_logic__and_24_receiver_2e_v_3a_87_24_209__Y;
	// \src: receiver.v:100.9-100.23
	value<1> i_logic__or_24_receiver_2e_v_3a_100_24_250__Y;
	// \src: receiver.v:115.8-115.14
	value<1> i_lt_24_receiver_2e_v_3a_115_24_273__Y;
	// \src: receiver.v:115.8-115.14
	value<1> i_lt_24_receiver_2e_v_3a_115_24_278__Y;
	// \src: receiver.v:115.8-115.14
	value<1> i_lt_24_receiver_2e_v_3a_115_24_283__Y;
	// \src: receiver.v:115.8-115.14
	value<1> i_lt_24_receiver_2e_v_3a_115_24_288__Y;
	// \src: receiver.v:115.8-115.14
	value<1> i_lt_24_receiver_2e_v_3a_115_24_293__Y;
	// \src: receiver.v:115.8-115.14
	value<1> i_lt_24_receiver_2e_v_3a_115_24_298__Y;
	// \src: receiver.v:115.8-115.14
	value<1> i_lt_24_receiver_2e_v_3a_115_24_303__Y;
	// \src: receiver.v:115.8-115.14
	value<1> i_lt_24_receiver_2e_v_3a_115_24_308__Y;
	// \src: receiver.v:110.11-110.68
	value<33> i_neg_24_receiver_2e_v_3a_110_24_262__Y;
	// \src: receiver.v:83.7-83.70
	value<33> i_neg_24_receiver_2e_v_3a_83_24_147__Y;
	// \src: receiver.v:83.7-83.70
	value<33> i_neg_24_receiver_2e_v_3a_83_24_194__Y;
	// \src: receiver.v:93.6-93.36
	value<3> i_neg_24_receiver_2e_v_3a_93_24_226__Y;
	// \src: receiver.v:93.54-93.76
	value<33> i_neg_24_receiver_2e_v_3a_93_24_238__Y;
	value<1> i_procmux_24_1040__CMP;
	value<1> i_procmux_24_1041__CMP;
	value<1> i_procmux_24_1042__CMP;
	value<1> i_procmux_24_1043__CMP;
	value<1> i_procmux_24_1132__CMP;
	value<1> i_procmux_24_1133__CMP;
	value<1> i_procmux_24_1134__CMP;
	value<1> i_procmux_24_1135__CMP;
	value<1> i_procmux_24_1224__CMP;
	value<1> i_procmux_24_1225__CMP;
	value<1> i_procmux_24_1226__CMP;
	value<1> i_procmux_24_1227__CMP;
	value<1> i_procmux_24_2753__CMP;
	value<1> i_procmux_24_2754__CMP;
	value<1> i_procmux_24_2755__CMP;
	value<1> i_procmux_24_2756__CMP;
	value<1> i_procmux_24_2757__CMP;
	value<1> i_procmux_24_2758__CMP;
	value<1> i_procmux_24_2759__CMP;
	value<1> i_procmux_24_2760__CMP;
	value<1> i_procmux_24_3848__CMP;
	value<1> i_procmux_24_3849__CMP;
	value<1> i_procmux_24_3850__CMP;
	value<1> i_procmux_24_3851__CMP;
	value<1> i_procmux_24_3852__CMP;
	value<1> i_procmux_24_3853__CMP;
	value<1> i_procmux_24_3854__CMP;
	value<1> i_procmux_24_3855__CMP;
	value<1> i_procmux_24_396__CMP;
	value<1> i_procmux_24_397__CMP;
	value<1> i_procmux_24_398__CMP;
	value<1> i_procmux_24_399__CMP;
	value<32> i_procmux_24_4837__Y;
	value<1> i_procmux_24_488__CMP;
	value<1> i_procmux_24_489__CMP;
	value<1> i_procmux_24_490__CMP;
	value<1> i_procmux_24_491__CMP;
	value<32> i_procmux_24_5249__Y;
	value<1> i_procmux_24_580__CMP;
	value<1> i_procmux_24_581__CMP;
	value<1> i_procmux_24_582__CMP;
	value<1> i_procmux_24_583__CMP;
	value<1> i_procmux_24_672__CMP;
	value<1> i_procmux_24_673__CMP;
	value<1> i_procmux_24_674__CMP;
	value<1> i_procmux_24_675__CMP;
	value<1> i_procmux_24_764__CMP;
	value<1> i_procmux_24_765__CMP;
	value<1> i_procmux_24_766__CMP;
	value<1> i_procmux_24_767__CMP;
	value<1> i_procmux_24_856__CMP;
	value<1> i_procmux_24_857__CMP;
	value<1> i_procmux_24_858__CMP;
	value<1> i_procmux_24_859__CMP;
	value<1> i_procmux_24_948__CMP;
	value<1> i_procmux_24_949__CMP;
	value<1> i_procmux_24_950__CMP;
	value<1> i_procmux_24_951__CMP;
	// \src: receiver.v:109.20-109.36
	value<4> i_shiftx_24_receiver_2e_v_3a_109_24_256__Y;
	// \src: receiver.v:82.21-82.40
	value<4> i_shiftx_24_receiver_2e_v_3a_82_24_142__Y;
	// \src: receiver.v:82.21-82.40
	value<4> i_shiftx_24_receiver_2e_v_3a_82_24_189__Y;
	// \src: receiver.v:89.14-89.21
	value<1> i_shiftx_24_receiver_2e_v_3a_89_24_213__Y;
	// \src: receiver.v:91.62-91.74
	value<8> i_shiftx_24_receiver_2e_v_3a_91_24_220__Y;
	// connection
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7181.slice<31,5>() = value<27>{0u};
	// connection
	i_10_5c_fault_5b_31_3a_0_5d_.slice<31,2>() = p_fault.curr.slice<31,2>().val();
	// connection
	i_8_5c_fault_5b_31_3a_0_5d_.slice<31,2>() = p_fault.curr.slice<31,2>().val();
	// connection
	i_7_5c_fault_5b_31_3a_0_5d_.slice<31,2>() = p_fault.curr.slice<31,2>().val();
	// connection
	i_6_5c_fault_5b_31_3a_0_5d_.slice<31,2>() = p_fault.curr.slice<31,2>().val();
	// connection
	i_5_5c_fault_5b_31_3a_0_5d_.slice<31,2>() = p_fault.curr.slice<31,2>().val();
	// connection
	i_procmux_24_5249__Y.slice<31,2>() = p_fault.curr.slice<31,2>().val();
	// \src: receiver.v:59.8-59.25
	// cell $logic_and$receiver.v:59$93
	i_logic__and_24_receiver_2e_v_3a_59_24_93__Y = logic_and<1>(p_wu.slice<3>().val(), p_valid.curr.slice<3>().val());
	// \src: receiver.v:59.8-59.25
	// cell $logic_and$receiver.v:59$92
	i_logic__and_24_receiver_2e_v_3a_59_24_92__Y = logic_and<1>(p_wu.slice<2>().val(), p_valid.curr.slice<2>().val());
	// \src: receiver.v:59.8-59.25
	// cell $logic_and$receiver.v:59$91
	i_logic__and_24_receiver_2e_v_3a_59_24_91__Y = logic_and<1>(p_wu.slice<1>().val(), p_valid.curr.slice<1>().val());
	// \src: receiver.v:59.8-59.25
	// cell $logic_and$receiver.v:59$90
	i_logic__and_24_receiver_2e_v_3a_59_24_90__Y = logic_and<1>(p_wu.slice<0>().val(), p_valid.curr.slice<0>().val());
	// \src: receiver.v:61.7-61.17
	// cell $eq$receiver.v:61$94
	i_eq_24_receiver_2e_v_3a_61_24_94__Y = eq_uu<1>(p_pp.curr, p_cfgphi);
	// \src: receiver.v:76.9-76.16
	// cell $ge$receiver.v:76$129
	i_ge_24_receiver_2e_v_3a_76_24_129__Y = ge_uu<1>(p_qlen.curr, value<4>{0x8u});
	// \src: receiver.v:73.28-73.32
	// cell $lt$receiver.v:73$162
	i_logic__and_24_receiver_2e_v_3a_72_24_112__Y = lt_uu<1>(p_fp.curr, value<3>{0x4u});
	// cells $logic_and$receiver.v:55$75 $logic_not$receiver.v:55$73 $eq$receiver.v:55$74
	i_logic__and_24_receiver_2e_v_3a_55_24_75__Y = logic_and<1>(logic_not<1>(p_failed.curr), logic_not<1>(p_fault.curr));
	// cells $procmux$5867 $procmux$5864 $procmux$5862
	i_6_5c_enabled_5b_3_3a_3_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_59_24_93__Y ? value<1>{0x1u} : p_enabled.curr.slice<3>().val()) : value<1>{0u}));
	// cells $procmux$5858 $procmux$5855 $procmux$5853
	i_6_5c_counts_5b_63_3a_48_5d_ = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_59_24_93__Y ? p_cfgk : p_counts.curr.slice<63,48>().val()) : value<16>{0u}));
	// cells $procmux$5903 $procmux$5900 $procmux$5898
	i_5_5c_enabled_5b_2_3a_2_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_59_24_92__Y ? value<1>{0x1u} : p_enabled.curr.slice<2>().val()) : value<1>{0u}));
	// cells $procmux$5894 $procmux$5891 $procmux$5889
	i_5_5c_counts_5b_47_3a_32_5d_ = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_59_24_92__Y ? p_cfgk : p_counts.curr.slice<47,32>().val()) : value<16>{0u}));
	// cells $procmux$5939 $procmux$5936 $procmux$5934
	i_4_5c_enabled_5b_1_3a_1_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_59_24_91__Y ? value<1>{0x1u} : p_enabled.curr.slice<1>().val()) : value<1>{0u}));
	// cells $procmux$5930 $procmux$5927 $procmux$5925
	i_4_5c_counts_5b_31_3a_16_5d_ = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_59_24_91__Y ? p_cfgk : p_counts.curr.slice<31,16>().val()) : value<16>{0u}));
	// cells $procmux$5975 $procmux$5972 $procmux$5970
	i_3_5c_enabled_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_59_24_90__Y ? value<1>{0x1u} : p_enabled.curr.slice<0>().val()) : value<1>{0u}));
	// cells $procmux$5966 $procmux$5963 $procmux$5961
	i_3_5c_counts_5b_15_3a_0_5d_ = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_59_24_90__Y ? p_cfgk : p_counts.curr.slice<15,0>().val()) : value<16>{0u}));
	// cells $procmux$4878 $procmux$4875 $procmux$4909
	i_5_5c_enqowner_5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_72_24_112__Y ? p_fp.curr.slice<1,0>().val() : value<2>{0u}) : value<2>{0u}));
	// \src: receiver.v:64.10-64.29
	// cell $eq$receiver.v:64$107
	i_eq_24_receiver_2e_v_3a_64_24_107__Y = logic_not<1>(i_6_5c_counts_5b_63_3a_48_5d_);
	// \src: receiver.v:64.10-64.29
	// cell $eq$receiver.v:64$103
	i_eq_24_receiver_2e_v_3a_64_24_103__Y = logic_not<1>(i_5_5c_counts_5b_47_3a_32_5d_);
	// \src: receiver.v:64.10-64.29
	// cell $eq$receiver.v:64$99
	i_eq_24_receiver_2e_v_3a_64_24_99__Y = logic_not<1>(i_4_5c_counts_5b_31_3a_16_5d_);
	// \src: receiver.v:64.10-64.29
	// cell $eq$receiver.v:64$95
	i_eq_24_receiver_2e_v_3a_64_24_95__Y = logic_not<1>(i_3_5c_counts_5b_15_3a_0_5d_);
	// \src: receiver.v:83.50-83.64
	// cell $mul$receiver.v:83$151
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7181.slice<4,0>() = mul_uu<5>(value<3>{0x4u}, i_5_5c_enqowner_5b_1_3a_0_5d_);
	// \full_case: 1
	// \src: receiver.v:64.10-64.29|receiver.v:64.7-65.128
	// cell $procmux$5541
	i_6_5c_fault_5b_31_3a_0_5d_.slice<1,0>() = (i_eq_24_receiver_2e_v_3a_64_24_95__Y ? value<1>{0x1u}.concat(p_fault.curr.slice<0>()).val() : p_fault.curr.slice<1,0>().val());
	// \src: receiver.v:83.49-83.68
	// cell $add$receiver.v:83$152
	i_add_24_receiver_2e_v_3a_82_24_141__Y = add_uu<6>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7181.slice<4,0>().val(), value<1>{0u});
	// \full_case: 1
	// \src: receiver.v:63.9-63.19|receiver.v:63.6-66.9
	// cell $procmux$5627
	i_5_5c_fault_5b_31_3a_0_5d_.slice<1,0>() = (i_3_5c_enabled_5b_0_3a_0_5d_ ? i_6_5c_fault_5b_31_3a_0_5d_.slice<1,0>().val() : p_fault.curr.slice<1,0>().val());
	// \src: receiver.v:83.49-83.68
	// cell $shiftx$receiver.v:83$153
	i_shiftx_24_receiver_2e_v_3a_82_24_142__Y = shiftx_us<4>(p_outstanding.curr, value<1>{0u}.concat(i_add_24_receiver_2e_v_3a_82_24_141__Y).val());
	// \full_case: 1
	// \src: receiver.v:64.10-64.29|receiver.v:64.7-65.128
	// cell $procmux$5352
	i_8_5c_fault_5b_31_3a_0_5d_.slice<1,0>() = (i_eq_24_receiver_2e_v_3a_64_24_99__Y ? value<1>{0x1u}.concat(i_5_5c_fault_5b_31_3a_0_5d_.slice<0>()).val() : i_5_5c_fault_5b_31_3a_0_5d_.slice<1,0>().val());
	// \full_case: 1
	// \src: receiver.v:63.9-63.19|receiver.v:63.6-66.9
	// cell $procmux$5438
	i_7_5c_fault_5b_31_3a_0_5d_.slice<1,0>() = (i_4_5c_enabled_5b_1_3a_1_5d_ ? i_8_5c_fault_5b_31_3a_0_5d_.slice<1,0>().val() : i_5_5c_fault_5b_31_3a_0_5d_.slice<1,0>().val());
	// \full_case: 1
	// \src: receiver.v:64.10-64.29|receiver.v:64.7-65.128
	// cell $procmux$5163
	i_10_5c_fault_5b_31_3a_0_5d_.slice<1,0>() = (i_eq_24_receiver_2e_v_3a_64_24_103__Y ? value<1>{0x1u}.concat(i_7_5c_fault_5b_31_3a_0_5d_.slice<0>()).val() : i_7_5c_fault_5b_31_3a_0_5d_.slice<1,0>().val());
	// \full_case: 1
	// \src: receiver.v:63.9-63.19|receiver.v:63.6-66.9
	// cell $procmux$5249
	i_procmux_24_5249__Y.slice<1,0>() = (i_5_5c_enabled_5b_2_3a_2_5d_ ? i_10_5c_fault_5b_31_3a_0_5d_.slice<1,0>().val() : i_7_5c_fault_5b_31_3a_0_5d_.slice<1,0>().val());
	// cells $procmux$5256 $procmux$5253 $procmux$5251
	i_11_5c_fault_5b_31_3a_0_5d_.next.slice<31,2>().concat(i_9_5c_fault_5b_31_3a_0_5d_.slice<1,0>()) = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_eq_24_receiver_2e_v_3a_61_24_94__Y ? p_fault.curr.slice<31,2>().concat(i_procmux_24_5249__Y.slice<1,0>()).val() : value<32>{0u}) : value<32>{0u}));
	// \full_case: 1
	// \src: receiver.v:43.6-43.9|receiver.v:43.3-128.6
	// cell $procmux$5696
	i_14_5c_fault_5b_31_3a_0_5d_.next.slice<31,4>().concat(i_4_5c_fault_5b_31_3a_0_5d_.slice<3,0>()) = (p_rst ? value<32>{0u} : i_procmux_24_5693__Y.curr);
	// connection
	i_9_5c_fault_5b_31_3a_0_5d_.slice<31,2>() = i_11_5c_fault_5b_31_3a_0_5d_.curr.slice<31,2>().val();
	// \full_case: 1
	// \src: receiver.v:64.10-64.29|receiver.v:64.7-65.128
	// cell $procmux$4974
	i_12_5c_fault_5b_31_3a_0_5d_.slice<1,0>() = (i_eq_24_receiver_2e_v_3a_64_24_107__Y ? value<1>{0x1u}.concat(i_9_5c_fault_5b_31_3a_0_5d_.slice<0>()).val() : i_9_5c_fault_5b_31_3a_0_5d_.slice<1,0>().val());
	// connection
	i_4_5c_fault_5b_31_3a_0_5d_.slice<31,4>() = i_14_5c_fault_5b_31_3a_0_5d_.curr.slice<31,4>().val();
	// cells $procmux$3833 $eq$receiver.v:82$143
	i_15_5c_fault_5b_31_3a_0_5d_.slice<3,0>() = (eq_uu<1>(i_shiftx_24_receiver_2e_v_3a_82_24_142__Y, value<4>{0xfu}) ? value<1>{0x1u}.concat(i_4_5c_fault_5b_31_3a_0_5d_.slice<2,0>()).val() : i_4_5c_fault_5b_31_3a_0_5d_.slice<3,0>().val());
	// connection
	i_12_5c_fault_5b_31_3a_0_5d_.slice<31,2>() = i_11_5c_fault_5b_31_3a_0_5d_.curr.slice<31,2>().val();
	// connection
	i_15_5c_fault_5b_31_3a_0_5d_.slice<31,4>() = i_14_5c_fault_5b_31_3a_0_5d_.curr.slice<31,4>().val();
	// \full_case: 1
	// \src: receiver.v:76.9-76.16|receiver.v:76.6-84.9
	// cell $procmux$4244
	i_14_5c_fault_5b_31_3a_0_5d_.next.slice<3,0>() = (i_ge_24_receiver_2e_v_3a_76_24_129__Y ? i_4_5c_fault_5b_31_3a_0_5d_.slice<3>().concat(value<1>{0x1u}).concat(i_4_5c_fault_5b_31_3a_0_5d_.slice<1,0>()).val() : i_15_5c_fault_5b_31_3a_0_5d_.slice<3,0>().val());
	// \full_case: 1
	// \src: receiver.v:63.9-63.19|receiver.v:63.6-66.9
	// cell $procmux$5060
	i_11_5c_fault_5b_31_3a_0_5d_.next.slice<1,0>() = (i_6_5c_enabled_5b_3_3a_3_5d_ ? i_12_5c_fault_5b_31_3a_0_5d_.slice<1,0>().val() : i_9_5c_fault_5b_31_3a_0_5d_.slice<1,0>().val());
	// cells $procmux$5693 $procmux$5691
	i_procmux_24_5693__Y.next = (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_eq_24_receiver_2e_v_3a_61_24_94__Y ? i_11_5c_fault_5b_31_3a_0_5d_.curr : p_fault.curr) : value<32>{0u});
	// cells $procmux$4887 $procmux$4884 $procmux$4918
	i_5_5c_releasevalid_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_72_24_112__Y ? value<1>{0x1u} : value<1>{0u}) : value<1>{0u}));
	// \full_case: 1
	// \src: receiver.v:81.7-81.28
	// cell $procmux$4169_CMP0
	i_procmux_24_3854__CMP = eq_uu<1>(p_qlen.curr.slice<2,0>().val(), value<1>{0x1u});
	// \full_case: 1
	// \src: receiver.v:81.7-81.28
	// cell $procmux$4168_CMP0
	i_procmux_24_3853__CMP = eq_uu<1>(p_qlen.curr.slice<2,0>().val(), value<2>{0x2u});
	// \full_case: 1
	// \src: receiver.v:81.7-81.28
	// cell $procmux$4167_CMP0
	i_procmux_24_3852__CMP = eq_uu<1>(p_qlen.curr.slice<2,0>().val(), value<2>{0x3u});
	// \full_case: 1
	// \src: receiver.v:81.7-81.28
	// cell $procmux$4166_CMP0
	i_procmux_24_3851__CMP = eq_uu<1>(p_qlen.curr.slice<2,0>().val(), value<3>{0x4u});
	// \full_case: 1
	// \src: receiver.v:81.7-81.28
	// cell $procmux$4165_CMP0
	i_procmux_24_3850__CMP = eq_uu<1>(p_qlen.curr.slice<2,0>().val(), value<3>{0x5u});
	// \full_case: 1
	// \src: receiver.v:81.7-81.28
	// cell $procmux$4164_CMP0
	i_procmux_24_3849__CMP = eq_uu<1>(p_qlen.curr.slice<2,0>().val(), value<3>{0x6u});
	// \full_case: 1
	// \src: receiver.v:81.7-81.28
	// cell $procmux$4163_CMP0
	i_procmux_24_3848__CMP = eq_uu<1>(p_qlen.curr.slice<2,0>().val(), value<3>{0x7u});
	// cells $logic_and$receiver.v:73$163 $eq$receiver.v:73$160
	i_logic__and_24_receiver_2e_v_3a_73_24_163__Y = logic_and<1>(eq_uu<1>(p_cfgf, value<6>{0x28u}), i_logic__and_24_receiver_2e_v_3a_72_24_112__Y);
	// \full_case: 1
	// \src: receiver.v:81.7-81.28
	// cell $procmux$4170_CMP0
	i_procmux_24_3855__CMP = logic_not<1>(p_qlen.curr.slice<2,0>().val());
	// cell $auto$opt_reduce.cc:131:opt_pmux$7047
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6974 = reduce_or<1>(i_procmux_24_3854__CMP.concat(i_procmux_24_3853__CMP).concat(i_procmux_24_3852__CMP).concat(i_procmux_24_3851__CMP).concat(i_procmux_24_3850__CMP).concat(i_procmux_24_3849__CMP).concat(i_procmux_24_3848__CMP).val());
	// \src: receiver.v:74.78-74.83
	// cell $sub$receiver.v:74$170
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7173.slice<1,0>() = sub_uu<2>(p_fp.curr.slice<1,0>().val(), value<1>{0u});
	// cells $logic_and$receiver.v:74$169 $logic_and$receiver.v:74$167 $ne$receiver.v:74$164 $ge$receiver.v:74$166 $lt$receiver.v:74$168
	i_logic__and_24_receiver_2e_v_3a_74_24_169__Y = logic_and<1>(logic_and<1>(ne_uu<1>(p_cfgf, value<6>{0x28u}), ge_uu<1>(p_fp.curr, value<6>{0x28u})), lt_uu<1>(p_fp.curr, value<6>{0x2cu}));
	// \src: receiver.v:65.35-65.53
	// cell $sub$receiver.v:65$109
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7184.slice<15,0>() = sub_uu<16>(i_6_5c_counts_5b_63_3a_48_5d_, value<1>{0x1u});
	// \src: receiver.v:65.35-65.53
	// cell $sub$receiver.v:65$97
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7187.slice<15,0>() = sub_uu<16>(i_3_5c_counts_5b_15_3a_0_5d_, value<1>{0x1u});
	// \src: receiver.v:65.35-65.53
	// cell $sub$receiver.v:65$101
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7186.slice<15,0>() = sub_uu<16>(i_4_5c_counts_5b_31_3a_16_5d_, value<1>{0x1u});
	// \src: receiver.v:65.35-65.53
	// cell $sub$receiver.v:65$105
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7185.slice<15,0>() = sub_uu<16>(i_5_5c_counts_5b_47_3a_32_5d_, value<1>{0x1u});
	// cells $procmux$4860 $procmux$4857 $procmux$4855 $procmux$4580 $add$receiver.v:81$138
	i_3_5c_qlen_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_5_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_129__Y ? p_qlen.curr : add_uu<4>(p_qlen.curr, value<1>{0x1u})) : p_qlen.curr) : value<4>{0u}));
	// \src: receiver.v:65.57-65.76
	// cell $eq$receiver.v:65$110
	i_eq_24_receiver_2e_v_3a_65_24_110__Y = logic_not<1>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7184.slice<15,0>().val());
	// \src: receiver.v:65.57-65.76
	// cell $eq$receiver.v:65$98
	i_eq_24_receiver_2e_v_3a_65_24_98__Y = logic_not<1>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7187.slice<15,0>().val());
	// \src: receiver.v:65.57-65.76
	// cell $eq$receiver.v:65$102
	i_eq_24_receiver_2e_v_3a_65_24_102__Y = logic_not<1>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7186.slice<15,0>().val());
	// \src: receiver.v:65.57-65.76
	// cell $eq$receiver.v:65$106
	i_eq_24_receiver_2e_v_3a_65_24_106__Y = logic_not<1>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7185.slice<15,0>().val());
	// \full_case: 1
	// \src: receiver.v:81.7-81.28
	// cell $procmux$3074_CMP0
	i_procmux_24_2759__CMP = eq_uu<1>(i_3_5c_qlen_5b_3_3a_0_5d_.slice<2,0>().val(), value<1>{0x1u});
	// \full_case: 1
	// \src: receiver.v:81.7-81.28
	// cell $procmux$3073_CMP0
	i_procmux_24_2758__CMP = eq_uu<1>(i_3_5c_qlen_5b_3_3a_0_5d_.slice<2,0>().val(), value<2>{0x2u});
	// \full_case: 1
	// \src: receiver.v:81.7-81.28
	// cell $procmux$3072_CMP0
	i_procmux_24_2757__CMP = eq_uu<1>(i_3_5c_qlen_5b_3_3a_0_5d_.slice<2,0>().val(), value<2>{0x3u});
	// \full_case: 1
	// \src: receiver.v:81.7-81.28
	// cell $procmux$3071_CMP0
	i_procmux_24_2756__CMP = eq_uu<1>(i_3_5c_qlen_5b_3_3a_0_5d_.slice<2,0>().val(), value<3>{0x4u});
	// \full_case: 1
	// \src: receiver.v:81.7-81.28
	// cell $procmux$3070_CMP0
	i_procmux_24_2755__CMP = eq_uu<1>(i_3_5c_qlen_5b_3_3a_0_5d_.slice<2,0>().val(), value<3>{0x5u});
	// \full_case: 1
	// \src: receiver.v:81.7-81.28
	// cell $procmux$3069_CMP0
	i_procmux_24_2754__CMP = eq_uu<1>(i_3_5c_qlen_5b_3_3a_0_5d_.slice<2,0>().val(), value<3>{0x6u});
	// \full_case: 1
	// \src: receiver.v:81.7-81.28
	// cell $procmux$3068_CMP0
	i_procmux_24_2753__CMP = eq_uu<1>(i_3_5c_qlen_5b_3_3a_0_5d_.slice<2,0>().val(), value<3>{0x7u});
	// cells $procmux$4774 $procmux$4484 $procmux$4015
	i_3_5c_qo_5b_0_5d__5b_1_3a_0_5d_ = (i_5_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_129__Y ? p_qo_5b_0_5d_.curr : (i_procmux_24_3855__CMP ? i_5_5c_enqowner_5b_1_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6974 ? p_qo_5b_0_5d_.curr : value<2>{0u}))) : p_qo_5b_0_5d_.curr);
	// cells $procmux$3783 $procmux$3780 $procmux$3778 $procmux$3796
	i_8_5c_releaseowner_5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_74_24_169__Y ? i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7173.slice<1,0>().val() : (i_logic__and_24_receiver_2e_v_3a_73_24_163__Y ? p_fp.curr.slice<1,0>().val() : value<2>{0u})) : value<2>{0u}));
	// \full_case: 1
	// \src: receiver.v:81.7-81.28
	// cell $procmux$3075_CMP0
	i_procmux_24_2760__CMP = logic_not<1>(i_3_5c_qlen_5b_3_3a_0_5d_.slice<2,0>().val());
	// cell $auto$opt_reduce.cc:131:opt_pmux$7081
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_7022 = reduce_or<1>(i_procmux_24_2759__CMP.concat(i_procmux_24_2758__CMP).concat(i_procmux_24_2757__CMP).concat(i_procmux_24_2756__CMP).concat(i_procmux_24_2755__CMP).concat(i_procmux_24_2754__CMP).concat(i_procmux_24_2753__CMP).val());
	// cell $auto$opt_reduce.cc:131:opt_pmux$7099
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6976 = reduce_or<1>(i_procmux_24_3855__CMP.concat(i_procmux_24_3853__CMP).concat(i_procmux_24_3852__CMP).concat(i_procmux_24_3851__CMP).concat(i_procmux_24_3850__CMP).concat(i_procmux_24_3849__CMP).concat(i_procmux_24_3848__CMP).val());
	// \src: receiver.v:76.9-76.16
	// cell $ge$receiver.v:76$176
	i_ge_24_receiver_2e_v_3a_76_24_176__Y = ge_uu<1>(i_3_5c_qlen_5b_3_3a_0_5d_, value<4>{0x8u});
	// cells $procmux$3792 $procmux$3789 $procmux$3787 $procmux$3805
	i_8_5c_releasevalid_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_74_24_169__Y ? value<1>{0x1u} : (i_logic__and_24_receiver_2e_v_3a_73_24_163__Y ? value<1>{0x1u} : value<1>{0u})) : value<1>{0u}));
	// cells $procmux$4765 $procmux$4472 $procmux$4162
	i_3_5c_qo_5b_1_5d__5b_1_3a_0_5d_ = (i_5_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_129__Y ? p_qo_5b_1_5d_.curr : (i_procmux_24_3854__CMP ? i_5_5c_enqowner_5b_1_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6976 ? p_qo_5b_1_5d_.curr : value<2>{0u}))) : p_qo_5b_1_5d_.curr);
	// cell $auto$opt_reduce.cc:131:opt_pmux$7031
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6982 = reduce_or<1>(i_procmux_24_2760__CMP.concat(i_procmux_24_2758__CMP).concat(i_procmux_24_2757__CMP).concat(i_procmux_24_2756__CMP).concat(i_procmux_24_2755__CMP).concat(i_procmux_24_2754__CMP).concat(i_procmux_24_2753__CMP).val());
	// cell $auto$opt_reduce.cc:131:opt_pmux$6977
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6962 = reduce_or<1>(i_procmux_24_3855__CMP.concat(i_procmux_24_3854__CMP).concat(i_procmux_24_3852__CMP).concat(i_procmux_24_3851__CMP).concat(i_procmux_24_3850__CMP).concat(i_procmux_24_3849__CMP).concat(i_procmux_24_3848__CMP).val());
	// cells $procmux$5822 $procmux$5819 $procmux$5817 $procmux$5096 $procmux$5034 $procmux$4956
	i_3_5c_valid_5b_3_3a_0_5d_.slice<3>() = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_eq_24_receiver_2e_v_3a_61_24_94__Y ? (i_6_5c_enabled_5b_3_3a_3_5d_ ? (i_eq_24_receiver_2e_v_3a_64_24_107__Y ? p_valid.curr.slice<3>().val() : (i_eq_24_receiver_2e_v_3a_65_24_110__Y ? value<1>{0u} : p_valid.curr.slice<3>().val())) : p_valid.curr.slice<3>().val()) : p_valid.curr.slice<3>().val()) : value<1>{0u}));
	// cells $procmux$5795 $procmux$5792 $procmux$5790 $procmux$5663 $procmux$5601 $procmux$5523
	i_3_5c_valid_5b_3_3a_0_5d_.slice<0>() = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_eq_24_receiver_2e_v_3a_61_24_94__Y ? (i_3_5c_enabled_5b_0_3a_0_5d_ ? (i_eq_24_receiver_2e_v_3a_64_24_95__Y ? p_valid.curr.slice<0>().val() : (i_eq_24_receiver_2e_v_3a_65_24_98__Y ? value<1>{0u} : p_valid.curr.slice<0>().val())) : p_valid.curr.slice<0>().val()) : p_valid.curr.slice<0>().val()) : value<1>{0u}));
	// cells $procmux$5759 $procmux$5756 $procmux$5754 $procmux$5474 $procmux$5412 $procmux$5334
	i_3_5c_valid_5b_3_3a_0_5d_.slice<1>() = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_eq_24_receiver_2e_v_3a_61_24_94__Y ? (i_4_5c_enabled_5b_1_3a_1_5d_ ? (i_eq_24_receiver_2e_v_3a_64_24_99__Y ? p_valid.curr.slice<1>().val() : (i_eq_24_receiver_2e_v_3a_65_24_102__Y ? value<1>{0u} : p_valid.curr.slice<1>().val())) : p_valid.curr.slice<1>().val()) : p_valid.curr.slice<1>().val()) : value<1>{0u}));
	// cells $procmux$5723 $procmux$5720 $procmux$5718 $procmux$5285 $procmux$5223 $procmux$5145
	i_3_5c_valid_5b_3_3a_0_5d_.slice<2>() = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_eq_24_receiver_2e_v_3a_61_24_94__Y ? (i_5_5c_enabled_5b_2_3a_2_5d_ ? (i_eq_24_receiver_2e_v_3a_64_24_103__Y ? p_valid.curr.slice<2>().val() : (i_eq_24_receiver_2e_v_3a_65_24_106__Y ? value<1>{0u} : p_valid.curr.slice<2>().val())) : p_valid.curr.slice<2>().val()) : p_valid.curr.slice<2>().val()) : value<1>{0u}));
	// cells $procmux$3684 $procmux$3681 $procmux$3679 $procmux$3389 $procmux$2920
	i_6_5c_qo_5b_0_5d__5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_176__Y ? i_3_5c_qo_5b_0_5d__5b_1_3a_0_5d_ : (i_procmux_24_2760__CMP ? i_8_5c_releaseowner_5b_1_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_7022 ? i_3_5c_qo_5b_0_5d__5b_1_3a_0_5d_ : value<2>{0u}))) : i_3_5c_qo_5b_0_5d__5b_1_3a_0_5d_) : value<2>{0u}));
	// cells $procmux$3765 $procmux$3762 $procmux$3760 $procmux$3485 $add$receiver.v:81$185
	i_5_5c_qlen_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_176__Y ? i_3_5c_qlen_5b_3_3a_0_5d_ : add_uu<4>(i_3_5c_qlen_5b_3_3a_0_5d_, value<1>{0x1u})) : i_3_5c_qlen_5b_3_3a_0_5d_) : value<4>{0u}));
	// \src: receiver.v:89.14-89.21
	// cell $shiftx$receiver.v:89$213
	i_shiftx_24_receiver_2e_v_3a_89_24_213__Y = shiftx_uu<1>(i_3_5c_valid_5b_3_3a_0_5d_, i_6_5c_qo_5b_0_5d__5b_1_3a_0_5d_);
	// cells $procmux$3670 $procmux$3377 $procmux$3067
	i_6_5c_qo_5b_1_5d__5b_1_3a_0_5d_ = (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_176__Y ? i_3_5c_qo_5b_1_5d__5b_1_3a_0_5d_ : (i_procmux_24_2759__CMP ? i_8_5c_releaseowner_5b_1_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6982 ? i_3_5c_qo_5b_1_5d__5b_1_3a_0_5d_ : value<2>{0u}))) : i_3_5c_qo_5b_1_5d__5b_1_3a_0_5d_);
	// cells $logic_and$receiver.v:87$209 $logic_and$receiver.v:87$207 $eq$receiver.v:87$205 $logic_not$receiver.v:87$206 $ne$receiver.v:87$208
	i_logic__and_24_receiver_2e_v_3a_87_24_209__Y = logic_and<1>(logic_and<1>(logic_not<1>(p_cp.curr), logic_not<1>(p_rzero.curr)), reduce_bool<1>(i_5_5c_qlen_5b_3_3a_0_5d_));
	// cells $procmux$4756 $procmux$4460 $procmux$4141
	i_3_5c_qo_5b_2_5d__5b_1_3a_0_5d_ = (i_5_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_129__Y ? p_qo_5b_2_5d_.curr : (i_procmux_24_3853__CMP ? i_5_5c_enqowner_5b_1_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6962 ? p_qo_5b_2_5d_.curr : value<2>{0u}))) : p_qo_5b_2_5d_.curr);
	// cell $auto$opt_reduce.cc:131:opt_pmux$7037
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6984 = reduce_or<1>(i_procmux_24_2760__CMP.concat(i_procmux_24_2759__CMP).concat(i_procmux_24_2757__CMP).concat(i_procmux_24_2756__CMP).concat(i_procmux_24_2755__CMP).concat(i_procmux_24_2754__CMP).concat(i_procmux_24_2753__CMP).val());
	// \src: receiver.v:95.27-95.33
	// cell $sub$receiver.v:95$245
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7153.slice<3,0>() = sub_uu<4>(i_5_5c_qlen_5b_3_3a_0_5d_, value<1>{0x1u});
	// cell $auto$opt_reduce.cc:131:opt_pmux$6979
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6964 = reduce_or<1>(i_procmux_24_3855__CMP.concat(i_procmux_24_3854__CMP).concat(i_procmux_24_3853__CMP).concat(i_procmux_24_3851__CMP).concat(i_procmux_24_3850__CMP).concat(i_procmux_24_3849__CMP).concat(i_procmux_24_3848__CMP).val());
	// cells $procmux$2526 $procmux$2523 $procmux$2521 $procmux$2183
	i_9_5c_qo_5b_0_5d__5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_209__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_213__Y ? i_6_5c_qo_5b_1_5d__5b_1_3a_0_5d_ : i_6_5c_qo_5b_0_5d__5b_1_3a_0_5d_) : i_6_5c_qo_5b_0_5d__5b_1_3a_0_5d_) : value<2>{0u}));
	// cells $procmux$3661 $procmux$3365 $procmux$3046
	i_6_5c_qo_5b_2_5d__5b_1_3a_0_5d_ = (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_176__Y ? i_3_5c_qo_5b_2_5d__5b_1_3a_0_5d_ : (i_procmux_24_2758__CMP ? i_8_5c_releaseowner_5b_1_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6984 ? i_3_5c_qo_5b_2_5d__5b_1_3a_0_5d_ : value<2>{0u}))) : i_3_5c_qo_5b_2_5d__5b_1_3a_0_5d_);
	// \full_case: 1
	// \src: receiver.v:116.37-116.37|receiver.v:116.6-116.104
	// cell $procmux$1268_CMP0
	i_procmux_24_1226__CMP = eq_uu<1>(i_9_5c_qo_5b_0_5d__5b_1_3a_0_5d_, value<1>{0x1u});
	// \full_case: 1
	// \src: receiver.v:116.57-116.57|receiver.v:116.6-116.104
	// cell $procmux$1267_CMP0
	i_procmux_24_1225__CMP = eq_uu<1>(i_9_5c_qo_5b_0_5d__5b_1_3a_0_5d_, value<2>{0x2u});
	// \full_case: 1
	// \src: receiver.v:116.77-116.77|receiver.v:116.6-116.104
	// cell $procmux$1266_CMP0
	i_procmux_24_1224__CMP = eq_uu<1>(i_9_5c_qo_5b_0_5d__5b_1_3a_0_5d_, value<2>{0x3u});
	// \full_case: 1
	// \src: receiver.v:116.17-116.17|receiver.v:116.6-116.104
	// cell $procmux$1269_CMP0
	i_procmux_24_1227__CMP = logic_not<1>(i_9_5c_qo_5b_0_5d__5b_1_3a_0_5d_);
	// cells $procmux$2688 $procmux$2685 $procmux$2683 $procmux$2351
	i_7_5c_qlen_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_209__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_213__Y ? i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7153.slice<3,0>().val() : i_5_5c_qlen_5b_3_3a_0_5d_) : i_5_5c_qlen_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$4747 $procmux$4448 $procmux$4120
	i_3_5c_qo_5b_3_5d__5b_1_3a_0_5d_ = (i_5_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_129__Y ? p_qo_5b_3_5d_.curr : (i_procmux_24_3852__CMP ? i_5_5c_enqowner_5b_1_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6964 ? p_qo_5b_3_5d_.curr : value<2>{0u}))) : p_qo_5b_3_5d_.curr);
	// cell $auto$opt_reduce.cc:131:opt_pmux$7045
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6988 = reduce_or<1>(i_procmux_24_2760__CMP.concat(i_procmux_24_2759__CMP).concat(i_procmux_24_2758__CMP).concat(i_procmux_24_2756__CMP).concat(i_procmux_24_2755__CMP).concat(i_procmux_24_2754__CMP).concat(i_procmux_24_2753__CMP).val());
	// \src: receiver.v:115.8-115.14
	// cell $lt$receiver.v:115$273
	i_lt_24_receiver_2e_v_3a_115_24_273__Y = lt_uu<1>(value<1>{0u}, i_7_5c_qlen_5b_3_3a_0_5d_);
	// cell $auto$opt_reduce.cc:131:opt_pmux$6985
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6966 = reduce_or<1>(i_procmux_24_3855__CMP.concat(i_procmux_24_3854__CMP).concat(i_procmux_24_3853__CMP).concat(i_procmux_24_3852__CMP).concat(i_procmux_24_3850__CMP).concat(i_procmux_24_3849__CMP).concat(i_procmux_24_3848__CMP).val());
	// cells $procmux$2517 $procmux$2514 $procmux$2512 $procmux$2171
	i_9_5c_qo_5b_1_5d__5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_209__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_213__Y ? i_6_5c_qo_5b_2_5d__5b_1_3a_0_5d_ : i_6_5c_qo_5b_1_5d__5b_1_3a_0_5d_) : i_6_5c_qo_5b_1_5d__5b_1_3a_0_5d_) : value<2>{0u}));
	// cells $procmux$3652 $procmux$3353 $procmux$3025
	i_6_5c_qo_5b_3_5d__5b_1_3a_0_5d_ = (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_176__Y ? i_3_5c_qo_5b_3_5d__5b_1_3a_0_5d_ : (i_procmux_24_2757__CMP ? i_8_5c_releaseowner_5b_1_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6988 ? i_3_5c_qo_5b_3_5d__5b_1_3a_0_5d_ : value<2>{0u}))) : i_3_5c_qo_5b_3_5d__5b_1_3a_0_5d_);
	// \full_case: 1
	// \src: receiver.v:116.37-116.37|receiver.v:116.6-116.104
	// cell $procmux$1176_CMP0
	i_procmux_24_1134__CMP = eq_uu<1>(i_9_5c_qo_5b_1_5d__5b_1_3a_0_5d_, value<1>{0x1u});
	// \full_case: 1
	// \src: receiver.v:116.57-116.57|receiver.v:116.6-116.104
	// cell $procmux$1175_CMP0
	i_procmux_24_1133__CMP = eq_uu<1>(i_9_5c_qo_5b_1_5d__5b_1_3a_0_5d_, value<2>{0x2u});
	// \full_case: 1
	// \src: receiver.v:116.77-116.77|receiver.v:116.6-116.104
	// cell $procmux$1174_CMP0
	i_procmux_24_1132__CMP = eq_uu<1>(i_9_5c_qo_5b_1_5d__5b_1_3a_0_5d_, value<2>{0x3u});
	// cells $procmux$1311 $procmux$1308 $procmux$1306 $procmux$1223 $auto$opt_reduce.cc:131:opt_pmux$7001
	i_3_5c_tokens0_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_273__Y ? (i_procmux_24_1227__CMP ? value<4>{0x1u} : (reduce_or<1>(i_procmux_24_1226__CMP.concat(i_procmux_24_1225__CMP).concat(i_procmux_24_1224__CMP).val()) ? value<4>{0u} : value<4>{0u})) : value<4>{0u}) : value<4>{0u}));
	// \full_case: 1
	// \src: receiver.v:116.17-116.17|receiver.v:116.6-116.104
	// cell $procmux$1177_CMP0
	i_procmux_24_1135__CMP = logic_not<1>(i_9_5c_qo_5b_1_5d__5b_1_3a_0_5d_);
	// cells $procmux$1302 $procmux$1299 $procmux$1297 $procmux$1265 $auto$opt_reduce.cc:131:opt_pmux$6991
	i_3_5c_tokens1_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_273__Y ? (i_procmux_24_1226__CMP ? value<4>{0x1u} : (reduce_or<1>(i_procmux_24_1227__CMP.concat(i_procmux_24_1225__CMP).concat(i_procmux_24_1224__CMP).val()) ? value<4>{0u} : value<4>{0u})) : value<4>{0u}) : value<4>{0u}));
	// cells $procmux$1293 $procmux$1290 $procmux$1288 $procmux$1251 $auto$opt_reduce.cc:131:opt_pmux$6995
	i_3_5c_tokens2_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_273__Y ? (i_procmux_24_1225__CMP ? value<4>{0x1u} : (reduce_or<1>(i_procmux_24_1227__CMP.concat(i_procmux_24_1226__CMP).concat(i_procmux_24_1224__CMP).val()) ? value<4>{0u} : value<4>{0u})) : value<4>{0u}) : value<4>{0u}));
	// cells $procmux$1284 $procmux$1281 $procmux$1279 $procmux$1237 $auto$opt_reduce.cc:131:opt_pmux$6999
	i_3_5c_tokens3_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_273__Y ? (reduce_or<1>(i_procmux_24_1227__CMP.concat(i_procmux_24_1226__CMP).concat(i_procmux_24_1225__CMP).val()) ? value<4>{0u} : (i_procmux_24_1224__CMP ? value<4>{0x1u} : value<4>{0u})) : value<4>{0u}) : value<4>{0u}));
	// cells $procmux$4738 $procmux$4436 $procmux$4099
	i_3_5c_qo_5b_4_5d__5b_1_3a_0_5d_ = (i_5_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_129__Y ? p_qo_5b_4_5d_.curr : (i_procmux_24_3851__CMP ? i_5_5c_enqowner_5b_1_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6966 ? p_qo_5b_4_5d_.curr : value<2>{0u}))) : p_qo_5b_4_5d_.curr);
	// cell $auto$opt_reduce.cc:131:opt_pmux$7053
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6990 = reduce_or<1>(i_procmux_24_2760__CMP.concat(i_procmux_24_2759__CMP).concat(i_procmux_24_2758__CMP).concat(i_procmux_24_2757__CMP).concat(i_procmux_24_2755__CMP).concat(i_procmux_24_2754__CMP).concat(i_procmux_24_2753__CMP).val());
	// \src: receiver.v:115.8-115.14
	// cell $lt$receiver.v:115$278
	i_lt_24_receiver_2e_v_3a_115_24_278__Y = lt_uu<1>(value<1>{0x1u}, i_7_5c_qlen_5b_3_3a_0_5d_);
	// cell $auto$opt_reduce.cc:131:opt_pmux$6993
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6968 = reduce_or<1>(i_procmux_24_3855__CMP.concat(i_procmux_24_3854__CMP).concat(i_procmux_24_3853__CMP).concat(i_procmux_24_3852__CMP).concat(i_procmux_24_3851__CMP).concat(i_procmux_24_3849__CMP).concat(i_procmux_24_3848__CMP).val());
	// cells $procmux$2508 $procmux$2505 $procmux$2503 $procmux$2159
	i_9_5c_qo_5b_2_5d__5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_209__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_213__Y ? i_6_5c_qo_5b_3_5d__5b_1_3a_0_5d_ : i_6_5c_qo_5b_2_5d__5b_1_3a_0_5d_) : i_6_5c_qo_5b_2_5d__5b_1_3a_0_5d_) : value<2>{0u}));
	// cells $procmux$3643 $procmux$3341 $procmux$3004
	i_6_5c_qo_5b_4_5d__5b_1_3a_0_5d_ = (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_176__Y ? i_3_5c_qo_5b_4_5d__5b_1_3a_0_5d_ : (i_procmux_24_2756__CMP ? i_8_5c_releaseowner_5b_1_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6990 ? i_3_5c_qo_5b_4_5d__5b_1_3a_0_5d_ : value<2>{0u}))) : i_3_5c_qo_5b_4_5d__5b_1_3a_0_5d_);
	// \full_case: 1
	// \src: receiver.v:116.37-116.37|receiver.v:116.6-116.104
	// cell $procmux$1084_CMP0
	i_procmux_24_1042__CMP = eq_uu<1>(i_9_5c_qo_5b_2_5d__5b_1_3a_0_5d_, value<1>{0x1u});
	// \full_case: 1
	// \src: receiver.v:116.57-116.57|receiver.v:116.6-116.104
	// cell $procmux$1083_CMP0
	i_procmux_24_1041__CMP = eq_uu<1>(i_9_5c_qo_5b_2_5d__5b_1_3a_0_5d_, value<2>{0x2u});
	// \full_case: 1
	// \src: receiver.v:116.77-116.77|receiver.v:116.6-116.104
	// cell $procmux$1082_CMP0
	i_procmux_24_1040__CMP = eq_uu<1>(i_9_5c_qo_5b_2_5d__5b_1_3a_0_5d_, value<2>{0x3u});
	// cells $procmux$1219 $procmux$1216 $procmux$1214 $procmux$1131 $add$receiver.v:116$279 $auto$opt_reduce.cc:131:opt_pmux$7011
	i_5_5c_tokens0_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_278__Y ? (i_procmux_24_1135__CMP ? add_uu<4>(i_3_5c_tokens0_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_1134__CMP.concat(i_procmux_24_1133__CMP).concat(i_procmux_24_1132__CMP).val()) ? i_3_5c_tokens0_5b_3_3a_0_5d_ : value<4>{0u})) : i_3_5c_tokens0_5b_3_3a_0_5d_) : value<4>{0u}));
	// \full_case: 1
	// \src: receiver.v:116.17-116.17|receiver.v:116.6-116.104
	// cell $procmux$1085_CMP0
	i_procmux_24_1043__CMP = logic_not<1>(i_9_5c_qo_5b_2_5d__5b_1_3a_0_5d_);
	// cells $procmux$1210 $procmux$1207 $procmux$1205 $procmux$1173 $add$receiver.v:116$280 $auto$opt_reduce.cc:131:opt_pmux$7003
	i_5_5c_tokens1_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_278__Y ? (i_procmux_24_1134__CMP ? add_uu<4>(i_3_5c_tokens1_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_1135__CMP.concat(i_procmux_24_1133__CMP).concat(i_procmux_24_1132__CMP).val()) ? i_3_5c_tokens1_5b_3_3a_0_5d_ : value<4>{0u})) : i_3_5c_tokens1_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$1201 $procmux$1198 $procmux$1196 $procmux$1159 $add$receiver.v:116$281 $auto$opt_reduce.cc:131:opt_pmux$7005
	i_5_5c_tokens2_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_278__Y ? (i_procmux_24_1133__CMP ? add_uu<4>(i_3_5c_tokens2_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_1135__CMP.concat(i_procmux_24_1134__CMP).concat(i_procmux_24_1132__CMP).val()) ? i_3_5c_tokens2_5b_3_3a_0_5d_ : value<4>{0u})) : i_3_5c_tokens2_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$1192 $procmux$1189 $procmux$1187 $procmux$1145 $add$receiver.v:116$282 $auto$opt_reduce.cc:131:opt_pmux$7009
	i_5_5c_tokens3_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_278__Y ? (reduce_or<1>(i_procmux_24_1135__CMP.concat(i_procmux_24_1134__CMP).concat(i_procmux_24_1133__CMP).val()) ? i_3_5c_tokens3_5b_3_3a_0_5d_ : (i_procmux_24_1132__CMP ? add_uu<4>(i_3_5c_tokens3_5b_3_3a_0_5d_, value<1>{0x1u}) : value<4>{0u})) : i_3_5c_tokens3_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$4729 $procmux$4424 $procmux$4078
	i_3_5c_qo_5b_5_5d__5b_1_3a_0_5d_ = (i_5_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_129__Y ? p_qo_5b_5_5d_.curr : (i_procmux_24_3850__CMP ? i_5_5c_enqowner_5b_1_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6968 ? p_qo_5b_5_5d_.curr : value<2>{0u}))) : p_qo_5b_5_5d_.curr);
	// cell $auto$opt_reduce.cc:131:opt_pmux$7059
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6998 = reduce_or<1>(i_procmux_24_2760__CMP.concat(i_procmux_24_2759__CMP).concat(i_procmux_24_2758__CMP).concat(i_procmux_24_2757__CMP).concat(i_procmux_24_2756__CMP).concat(i_procmux_24_2754__CMP).concat(i_procmux_24_2753__CMP).val());
	// \src: receiver.v:115.8-115.14
	// cell $lt$receiver.v:115$283
	i_lt_24_receiver_2e_v_3a_115_24_283__Y = lt_uu<1>(value<2>{0x2u}, i_7_5c_qlen_5b_3_3a_0_5d_);
	// cell $auto$opt_reduce.cc:131:opt_pmux$7013
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6970 = reduce_or<1>(i_procmux_24_3855__CMP.concat(i_procmux_24_3854__CMP).concat(i_procmux_24_3853__CMP).concat(i_procmux_24_3852__CMP).concat(i_procmux_24_3851__CMP).concat(i_procmux_24_3850__CMP).concat(i_procmux_24_3848__CMP).val());
	// cells $procmux$2499 $procmux$2496 $procmux$2494 $procmux$2147
	i_9_5c_qo_5b_3_5d__5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_209__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_213__Y ? i_6_5c_qo_5b_4_5d__5b_1_3a_0_5d_ : i_6_5c_qo_5b_3_5d__5b_1_3a_0_5d_) : i_6_5c_qo_5b_3_5d__5b_1_3a_0_5d_) : value<2>{0u}));
	// cells $procmux$3634 $procmux$3329 $procmux$2983
	i_6_5c_qo_5b_5_5d__5b_1_3a_0_5d_ = (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_176__Y ? i_3_5c_qo_5b_5_5d__5b_1_3a_0_5d_ : (i_procmux_24_2755__CMP ? i_8_5c_releaseowner_5b_1_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6998 ? i_3_5c_qo_5b_5_5d__5b_1_3a_0_5d_ : value<2>{0u}))) : i_3_5c_qo_5b_5_5d__5b_1_3a_0_5d_);
	// \full_case: 1
	// \src: receiver.v:116.37-116.37|receiver.v:116.6-116.104
	// cell $procmux$992_CMP0
	i_procmux_24_950__CMP = eq_uu<1>(i_9_5c_qo_5b_3_5d__5b_1_3a_0_5d_, value<1>{0x1u});
	// \full_case: 1
	// \src: receiver.v:116.57-116.57|receiver.v:116.6-116.104
	// cell $procmux$991_CMP0
	i_procmux_24_949__CMP = eq_uu<1>(i_9_5c_qo_5b_3_5d__5b_1_3a_0_5d_, value<2>{0x2u});
	// \full_case: 1
	// \src: receiver.v:116.77-116.77|receiver.v:116.6-116.104
	// cell $procmux$990_CMP0
	i_procmux_24_948__CMP = eq_uu<1>(i_9_5c_qo_5b_3_5d__5b_1_3a_0_5d_, value<2>{0x3u});
	// cells $procmux$1127 $procmux$1124 $procmux$1122 $procmux$1039 $add$receiver.v:116$284 $auto$opt_reduce.cc:131:opt_pmux$7025
	i_7_5c_tokens0_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_283__Y ? (i_procmux_24_1043__CMP ? add_uu<4>(i_5_5c_tokens0_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_1042__CMP.concat(i_procmux_24_1041__CMP).concat(i_procmux_24_1040__CMP).val()) ? i_5_5c_tokens0_5b_3_3a_0_5d_ : value<4>{0u})) : i_5_5c_tokens0_5b_3_3a_0_5d_) : value<4>{0u}));
	// \full_case: 1
	// \src: receiver.v:116.17-116.17|receiver.v:116.6-116.104
	// cell $procmux$993_CMP0
	i_procmux_24_951__CMP = logic_not<1>(i_9_5c_qo_5b_3_5d__5b_1_3a_0_5d_);
	// cells $procmux$1118 $procmux$1115 $procmux$1113 $procmux$1081 $add$receiver.v:116$285 $auto$opt_reduce.cc:131:opt_pmux$7017
	i_7_5c_tokens1_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_283__Y ? (i_procmux_24_1042__CMP ? add_uu<4>(i_5_5c_tokens1_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_1043__CMP.concat(i_procmux_24_1041__CMP).concat(i_procmux_24_1040__CMP).val()) ? i_5_5c_tokens1_5b_3_3a_0_5d_ : value<4>{0u})) : i_5_5c_tokens1_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$1109 $procmux$1106 $procmux$1104 $procmux$1067 $add$receiver.v:116$286 $auto$opt_reduce.cc:131:opt_pmux$7019
	i_7_5c_tokens2_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_283__Y ? (i_procmux_24_1041__CMP ? add_uu<4>(i_5_5c_tokens2_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_1043__CMP.concat(i_procmux_24_1042__CMP).concat(i_procmux_24_1040__CMP).val()) ? i_5_5c_tokens2_5b_3_3a_0_5d_ : value<4>{0u})) : i_5_5c_tokens2_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$1100 $procmux$1097 $procmux$1095 $procmux$1053 $add$receiver.v:116$287 $auto$opt_reduce.cc:131:opt_pmux$7023
	i_7_5c_tokens3_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_283__Y ? (reduce_or<1>(i_procmux_24_1043__CMP.concat(i_procmux_24_1042__CMP).concat(i_procmux_24_1041__CMP).val()) ? i_5_5c_tokens3_5b_3_3a_0_5d_ : (i_procmux_24_1040__CMP ? add_uu<4>(i_5_5c_tokens3_5b_3_3a_0_5d_, value<1>{0x1u}) : value<4>{0u})) : i_5_5c_tokens3_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$4720 $procmux$4412 $procmux$4057
	i_3_5c_qo_5b_6_5d__5b_1_3a_0_5d_ = (i_5_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_129__Y ? p_qo_5b_6_5d_.curr : (i_procmux_24_3849__CMP ? i_5_5c_enqowner_5b_1_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6970 ? p_qo_5b_6_5d_.curr : value<2>{0u}))) : p_qo_5b_6_5d_.curr);
	// cell $auto$opt_reduce.cc:131:opt_pmux$7067
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_7008 = reduce_or<1>(i_procmux_24_2760__CMP.concat(i_procmux_24_2759__CMP).concat(i_procmux_24_2758__CMP).concat(i_procmux_24_2757__CMP).concat(i_procmux_24_2756__CMP).concat(i_procmux_24_2755__CMP).concat(i_procmux_24_2753__CMP).val());
	// \src: receiver.v:115.8-115.14
	// cell $lt$receiver.v:115$288
	i_lt_24_receiver_2e_v_3a_115_24_288__Y = lt_uu<1>(value<2>{0x3u}, i_7_5c_qlen_5b_3_3a_0_5d_);
	// cell $auto$opt_reduce.cc:131:opt_pmux$7029
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6972 = reduce_or<1>(i_procmux_24_3855__CMP.concat(i_procmux_24_3854__CMP).concat(i_procmux_24_3853__CMP).concat(i_procmux_24_3852__CMP).concat(i_procmux_24_3851__CMP).concat(i_procmux_24_3850__CMP).concat(i_procmux_24_3849__CMP).val());
	// cells $procmux$2490 $procmux$2487 $procmux$2485 $procmux$2135
	i_9_5c_qo_5b_4_5d__5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_209__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_213__Y ? i_6_5c_qo_5b_5_5d__5b_1_3a_0_5d_ : i_6_5c_qo_5b_4_5d__5b_1_3a_0_5d_) : i_6_5c_qo_5b_4_5d__5b_1_3a_0_5d_) : value<2>{0u}));
	// cells $procmux$3625 $procmux$3317 $procmux$2962
	i_6_5c_qo_5b_6_5d__5b_1_3a_0_5d_ = (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_176__Y ? i_3_5c_qo_5b_6_5d__5b_1_3a_0_5d_ : (i_procmux_24_2754__CMP ? i_8_5c_releaseowner_5b_1_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_7008 ? i_3_5c_qo_5b_6_5d__5b_1_3a_0_5d_ : value<2>{0u}))) : i_3_5c_qo_5b_6_5d__5b_1_3a_0_5d_);
	// \full_case: 1
	// \src: receiver.v:116.37-116.37|receiver.v:116.6-116.104
	// cell $procmux$900_CMP0
	i_procmux_24_858__CMP = eq_uu<1>(i_9_5c_qo_5b_4_5d__5b_1_3a_0_5d_, value<1>{0x1u});
	// \full_case: 1
	// \src: receiver.v:116.57-116.57|receiver.v:116.6-116.104
	// cell $procmux$899_CMP0
	i_procmux_24_857__CMP = eq_uu<1>(i_9_5c_qo_5b_4_5d__5b_1_3a_0_5d_, value<2>{0x2u});
	// \full_case: 1
	// \src: receiver.v:116.77-116.77|receiver.v:116.6-116.104
	// cell $procmux$898_CMP0
	i_procmux_24_856__CMP = eq_uu<1>(i_9_5c_qo_5b_4_5d__5b_1_3a_0_5d_, value<2>{0x3u});
	// cells $procmux$1035 $procmux$1032 $procmux$1030 $procmux$947 $add$receiver.v:116$289 $auto$opt_reduce.cc:131:opt_pmux$7039
	i_9_5c_tokens0_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_288__Y ? (i_procmux_24_951__CMP ? add_uu<4>(i_7_5c_tokens0_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_950__CMP.concat(i_procmux_24_949__CMP).concat(i_procmux_24_948__CMP).val()) ? i_7_5c_tokens0_5b_3_3a_0_5d_ : value<4>{0u})) : i_7_5c_tokens0_5b_3_3a_0_5d_) : value<4>{0u}));
	// \full_case: 1
	// \src: receiver.v:116.17-116.17|receiver.v:116.6-116.104
	// cell $procmux$901_CMP0
	i_procmux_24_859__CMP = logic_not<1>(i_9_5c_qo_5b_4_5d__5b_1_3a_0_5d_);
	// cells $procmux$1026 $procmux$1023 $procmux$1021 $procmux$989 $add$receiver.v:116$290 $auto$opt_reduce.cc:131:opt_pmux$7027
	i_9_5c_tokens1_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_288__Y ? (i_procmux_24_950__CMP ? add_uu<4>(i_7_5c_tokens1_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_951__CMP.concat(i_procmux_24_949__CMP).concat(i_procmux_24_948__CMP).val()) ? i_7_5c_tokens1_5b_3_3a_0_5d_ : value<4>{0u})) : i_7_5c_tokens1_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$1017 $procmux$1014 $procmux$1012 $procmux$975 $add$receiver.v:116$291 $auto$opt_reduce.cc:131:opt_pmux$7033
	i_9_5c_tokens2_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_288__Y ? (i_procmux_24_949__CMP ? add_uu<4>(i_7_5c_tokens2_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_951__CMP.concat(i_procmux_24_950__CMP).concat(i_procmux_24_948__CMP).val()) ? i_7_5c_tokens2_5b_3_3a_0_5d_ : value<4>{0u})) : i_7_5c_tokens2_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$1008 $procmux$1005 $procmux$1003 $procmux$961 $add$receiver.v:116$292 $auto$opt_reduce.cc:131:opt_pmux$7035
	i_9_5c_tokens3_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_288__Y ? (reduce_or<1>(i_procmux_24_951__CMP.concat(i_procmux_24_950__CMP).concat(i_procmux_24_949__CMP).val()) ? i_7_5c_tokens3_5b_3_3a_0_5d_ : (i_procmux_24_948__CMP ? add_uu<4>(i_7_5c_tokens3_5b_3_3a_0_5d_, value<1>{0x1u}) : value<4>{0u})) : i_7_5c_tokens3_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$4711 $procmux$4400 $procmux$4036
	i_3_5c_qo_5b_7_5d__5b_1_3a_0_5d_ = (i_5_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_129__Y ? p_qo_5b_7_5d_.curr : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6972 ? p_qo_5b_7_5d_.curr : (i_procmux_24_3848__CMP ? i_5_5c_enqowner_5b_1_3a_0_5d_ : value<2>{0u}))) : p_qo_5b_7_5d_.curr);
	// cell $auto$opt_reduce.cc:131:opt_pmux$7075
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_7016 = reduce_or<1>(i_procmux_24_2760__CMP.concat(i_procmux_24_2759__CMP).concat(i_procmux_24_2758__CMP).concat(i_procmux_24_2757__CMP).concat(i_procmux_24_2756__CMP).concat(i_procmux_24_2755__CMP).concat(i_procmux_24_2754__CMP).val());
	// \src: receiver.v:115.8-115.14
	// cell $lt$receiver.v:115$293
	i_lt_24_receiver_2e_v_3a_115_24_293__Y = lt_uu<1>(value<3>{0x4u}, i_7_5c_qlen_5b_3_3a_0_5d_);
	// cells $procmux$2481 $procmux$2478 $procmux$2476 $procmux$2123
	i_9_5c_qo_5b_5_5d__5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_209__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_213__Y ? i_6_5c_qo_5b_6_5d__5b_1_3a_0_5d_ : i_6_5c_qo_5b_5_5d__5b_1_3a_0_5d_) : i_6_5c_qo_5b_5_5d__5b_1_3a_0_5d_) : value<2>{0u}));
	// cells $procmux$3616 $procmux$3305 $procmux$2941
	i_6_5c_qo_5b_7_5d__5b_1_3a_0_5d_ = (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_176__Y ? i_3_5c_qo_5b_7_5d__5b_1_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_7016 ? i_3_5c_qo_5b_7_5d__5b_1_3a_0_5d_ : (i_procmux_24_2753__CMP ? i_8_5c_releaseowner_5b_1_3a_0_5d_ : value<2>{0u}))) : i_3_5c_qo_5b_7_5d__5b_1_3a_0_5d_);
	// \full_case: 1
	// \src: receiver.v:116.37-116.37|receiver.v:116.6-116.104
	// cell $procmux$808_CMP0
	i_procmux_24_766__CMP = eq_uu<1>(i_9_5c_qo_5b_5_5d__5b_1_3a_0_5d_, value<1>{0x1u});
	// \full_case: 1
	// \src: receiver.v:116.57-116.57|receiver.v:116.6-116.104
	// cell $procmux$807_CMP0
	i_procmux_24_765__CMP = eq_uu<1>(i_9_5c_qo_5b_5_5d__5b_1_3a_0_5d_, value<2>{0x2u});
	// \full_case: 1
	// \src: receiver.v:116.77-116.77|receiver.v:116.6-116.104
	// cell $procmux$806_CMP0
	i_procmux_24_764__CMP = eq_uu<1>(i_9_5c_qo_5b_5_5d__5b_1_3a_0_5d_, value<2>{0x3u});
	// cells $procmux$943 $procmux$940 $procmux$938 $procmux$855 $add$receiver.v:116$294 $auto$opt_reduce.cc:131:opt_pmux$7051
	i_11_5c_tokens0_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_293__Y ? (i_procmux_24_859__CMP ? add_uu<4>(i_9_5c_tokens0_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_858__CMP.concat(i_procmux_24_857__CMP).concat(i_procmux_24_856__CMP).val()) ? i_9_5c_tokens0_5b_3_3a_0_5d_ : value<4>{0u})) : i_9_5c_tokens0_5b_3_3a_0_5d_) : value<4>{0u}));
	// \full_case: 1
	// \src: receiver.v:116.17-116.17|receiver.v:116.6-116.104
	// cell $procmux$809_CMP0
	i_procmux_24_767__CMP = logic_not<1>(i_9_5c_qo_5b_5_5d__5b_1_3a_0_5d_);
	// cells $procmux$934 $procmux$931 $procmux$929 $procmux$897 $add$receiver.v:116$295 $auto$opt_reduce.cc:131:opt_pmux$7041
	i_11_5c_tokens1_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_293__Y ? (i_procmux_24_858__CMP ? add_uu<4>(i_9_5c_tokens1_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_859__CMP.concat(i_procmux_24_857__CMP).concat(i_procmux_24_856__CMP).val()) ? i_9_5c_tokens1_5b_3_3a_0_5d_ : value<4>{0u})) : i_9_5c_tokens1_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$925 $procmux$922 $procmux$920 $procmux$883 $add$receiver.v:116$296 $auto$opt_reduce.cc:131:opt_pmux$7043
	i_11_5c_tokens2_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_293__Y ? (i_procmux_24_857__CMP ? add_uu<4>(i_9_5c_tokens2_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_859__CMP.concat(i_procmux_24_858__CMP).concat(i_procmux_24_856__CMP).val()) ? i_9_5c_tokens2_5b_3_3a_0_5d_ : value<4>{0u})) : i_9_5c_tokens2_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$916 $procmux$913 $procmux$911 $procmux$869 $add$receiver.v:116$297 $auto$opt_reduce.cc:131:opt_pmux$7049
	i_11_5c_tokens3_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_293__Y ? (reduce_or<1>(i_procmux_24_859__CMP.concat(i_procmux_24_858__CMP).concat(i_procmux_24_857__CMP).val()) ? i_9_5c_tokens3_5b_3_3a_0_5d_ : (i_procmux_24_856__CMP ? add_uu<4>(i_9_5c_tokens3_5b_3_3a_0_5d_, value<1>{0x1u}) : value<4>{0u})) : i_9_5c_tokens3_5b_3_3a_0_5d_) : value<4>{0u}));
	// \src: receiver.v:83.7-83.70
	// cell $neg$receiver.v:83$155
	i_neg_24_receiver_2e_v_3a_83_24_147__Y = neg_u<33>(i_add_24_receiver_2e_v_3a_82_24_141__Y);
	// \src: receiver.v:83.7-83.70
	// cell $shift$receiver.v:83$148
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7179.slice<15,0>() = shift_us<16>(value<4>{0xfu}, i_neg_24_receiver_2e_v_3a_83_24_147__Y);
	// \src: receiver.v:115.8-115.14
	// cell $lt$receiver.v:115$298
	i_lt_24_receiver_2e_v_3a_115_24_298__Y = lt_uu<1>(value<3>{0x5u}, i_7_5c_qlen_5b_3_3a_0_5d_);
	// \src: receiver.v:83.7-83.70
	// cell $not$receiver.v:83$149
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7178.slice<15,0>() = not_u<16>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7179.slice<15,0>().val());
	// cells $shift$receiver.v:83$156 $add$receiver.v:83$154
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7175.slice<15,0>() = shift_us<16>(add_uu<4>(i_shiftx_24_receiver_2e_v_3a_82_24_142__Y, value<1>{0x1u}), i_neg_24_receiver_2e_v_3a_83_24_147__Y);
	// cells $procmux$2472 $procmux$2469 $procmux$2467 $procmux$2111
	i_9_5c_qo_5b_6_5d__5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_209__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_213__Y ? i_6_5c_qo_5b_7_5d__5b_1_3a_0_5d_ : i_6_5c_qo_5b_6_5d__5b_1_3a_0_5d_) : i_6_5c_qo_5b_6_5d__5b_1_3a_0_5d_) : value<2>{0u}));
	// cells $or$receiver.v:83$157 $and$receiver.v:83$150
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7174.slice<15,0>() = or_uu<16>(and_uu<16>(p_outstanding.curr, i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7178.slice<15,0>().val()), i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7175.slice<15,0>().val());
	// \full_case: 1
	// \src: receiver.v:116.37-116.37|receiver.v:116.6-116.104
	// cell $procmux$716_CMP0
	i_procmux_24_674__CMP = eq_uu<1>(i_9_5c_qo_5b_6_5d__5b_1_3a_0_5d_, value<1>{0x1u});
	// \full_case: 1
	// \src: receiver.v:116.57-116.57|receiver.v:116.6-116.104
	// cell $procmux$715_CMP0
	i_procmux_24_673__CMP = eq_uu<1>(i_9_5c_qo_5b_6_5d__5b_1_3a_0_5d_, value<2>{0x2u});
	// \full_case: 1
	// \src: receiver.v:116.77-116.77|receiver.v:116.6-116.104
	// cell $procmux$714_CMP0
	i_procmux_24_672__CMP = eq_uu<1>(i_9_5c_qo_5b_6_5d__5b_1_3a_0_5d_, value<2>{0x3u});
	// cells $procmux$851 $procmux$848 $procmux$846 $procmux$763 $add$receiver.v:116$299 $auto$opt_reduce.cc:131:opt_pmux$7063
	i_13_5c_tokens0_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_298__Y ? (i_procmux_24_767__CMP ? add_uu<4>(i_11_5c_tokens0_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_766__CMP.concat(i_procmux_24_765__CMP).concat(i_procmux_24_764__CMP).val()) ? i_11_5c_tokens0_5b_3_3a_0_5d_ : value<4>{0u})) : i_11_5c_tokens0_5b_3_3a_0_5d_) : value<4>{0u}));
	// \full_case: 1
	// \src: receiver.v:116.17-116.17|receiver.v:116.6-116.104
	// cell $procmux$717_CMP0
	i_procmux_24_675__CMP = logic_not<1>(i_9_5c_qo_5b_6_5d__5b_1_3a_0_5d_);
	// cells $procmux$842 $procmux$839 $procmux$837 $procmux$805 $add$receiver.v:116$300 $auto$opt_reduce.cc:131:opt_pmux$7055
	i_13_5c_tokens1_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_298__Y ? (i_procmux_24_766__CMP ? add_uu<4>(i_11_5c_tokens1_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_767__CMP.concat(i_procmux_24_765__CMP).concat(i_procmux_24_764__CMP).val()) ? i_11_5c_tokens1_5b_3_3a_0_5d_ : value<4>{0u})) : i_11_5c_tokens1_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$833 $procmux$830 $procmux$828 $procmux$791 $add$receiver.v:116$301 $auto$opt_reduce.cc:131:opt_pmux$7057
	i_13_5c_tokens2_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_298__Y ? (i_procmux_24_765__CMP ? add_uu<4>(i_11_5c_tokens2_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_767__CMP.concat(i_procmux_24_766__CMP).concat(i_procmux_24_764__CMP).val()) ? i_11_5c_tokens2_5b_3_3a_0_5d_ : value<4>{0u})) : i_11_5c_tokens2_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$824 $procmux$821 $procmux$819 $procmux$777 $add$receiver.v:116$302 $auto$opt_reduce.cc:131:opt_pmux$7061
	i_13_5c_tokens3_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_298__Y ? (reduce_or<1>(i_procmux_24_767__CMP.concat(i_procmux_24_766__CMP).concat(i_procmux_24_765__CMP).val()) ? i_11_5c_tokens3_5b_3_3a_0_5d_ : (i_procmux_24_764__CMP ? add_uu<4>(i_11_5c_tokens3_5b_3_3a_0_5d_, value<1>{0x1u}) : value<4>{0u})) : i_11_5c_tokens3_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $logic_or$receiver.v:100$250 $eq$receiver.v:100$248 $eq$receiver.v:100$249
	i_logic__or_24_receiver_2e_v_3a_100_24_250__Y = logic_or<1>(eq_uu<1>(p_rp.curr, value<1>{0x1u}), eq_uu<1>(p_rp.curr, value<2>{0x2u}));
	// \src: receiver.v:83.50-83.64
	// cell $mul$receiver.v:83$198
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7170.slice<4,0>() = mul_uu<5>(value<3>{0x4u}, i_8_5c_releaseowner_5b_1_3a_0_5d_);
	// connection
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7170.slice<31,5>() = value<27>{0u};
	// \src: receiver.v:115.8-115.14
	// cell $lt$receiver.v:115$303
	i_lt_24_receiver_2e_v_3a_115_24_303__Y = lt_uu<1>(value<3>{0x6u}, i_7_5c_qlen_5b_3_3a_0_5d_);
	// \src: receiver.v:83.49-83.68
	// cell $add$receiver.v:83$199
	i_add_24_receiver_2e_v_3a_82_24_188__Y = add_uu<6>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7170.slice<4,0>().val(), value<1>{0u});
	// cells $procmux$2643 $procmux$2640 $procmux$2638 $procmux$1991
	i_3_5c_failed_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_209__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_213__Y ? p_failed.curr : value<1>{0x1u}) : p_failed.curr) : value<1>{0u}));
	// cells $procmux$1745 $procmux$1647
	i_4_5c_evblock_5b_0_3a_0_5d_ = (p_rone.curr ? (i_logic__or_24_receiver_2e_v_3a_100_24_250__Y ? value<1>{0u} : value<1>{0x1u}) : value<1>{0u});
	// cells $procmux$4851 $procmux$4848 $procmux$4846 $procmux$4568
	i_3_5c_outstanding_5b_15_3a_0_5d_ = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_5_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_129__Y ? p_outstanding.curr : i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7174.slice<15,0>().val()) : p_outstanding.curr) : value<16>{0u}));
	// \src: receiver.v:83.7-83.70
	// cell $neg$receiver.v:83$202
	i_neg_24_receiver_2e_v_3a_83_24_194__Y = neg_u<33>(i_add_24_receiver_2e_v_3a_82_24_188__Y);
	// cells $procmux$2463 $procmux$2460 $procmux$2458 $procmux$2099
	i_9_5c_qo_5b_7_5d__5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_209__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_213__Y ? value<2>{0u} : i_6_5c_qo_5b_7_5d__5b_1_3a_0_5d_) : i_6_5c_qo_5b_7_5d__5b_1_3a_0_5d_) : value<2>{0u}));
	// \src: receiver.v:83.49-83.68
	// cell $shiftx$receiver.v:83$200
	i_shiftx_24_receiver_2e_v_3a_82_24_189__Y = shiftx_us<4>(i_3_5c_outstanding_5b_15_3a_0_5d_, value<1>{0u}.concat(i_add_24_receiver_2e_v_3a_82_24_188__Y).val());
	// \src: receiver.v:83.7-83.70
	// cell $shift$receiver.v:83$195
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7168.slice<15,0>() = shift_us<16>(value<4>{0xfu}, i_neg_24_receiver_2e_v_3a_83_24_194__Y);
	// \full_case: 1
	// \src: receiver.v:116.37-116.37|receiver.v:116.6-116.104
	// cell $procmux$624_CMP0
	i_procmux_24_582__CMP = eq_uu<1>(i_9_5c_qo_5b_7_5d__5b_1_3a_0_5d_, value<1>{0x1u});
	// \full_case: 1
	// \src: receiver.v:116.57-116.57|receiver.v:116.6-116.104
	// cell $procmux$623_CMP0
	i_procmux_24_581__CMP = eq_uu<1>(i_9_5c_qo_5b_7_5d__5b_1_3a_0_5d_, value<2>{0x2u});
	// \full_case: 1
	// \src: receiver.v:116.77-116.77|receiver.v:116.6-116.104
	// cell $procmux$622_CMP0
	i_procmux_24_580__CMP = eq_uu<1>(i_9_5c_qo_5b_7_5d__5b_1_3a_0_5d_, value<2>{0x3u});
	// cells $procmux$759 $procmux$756 $procmux$754 $procmux$671 $add$receiver.v:116$304 $auto$opt_reduce.cc:131:opt_pmux$7073
	i_15_5c_tokens0_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_303__Y ? (i_procmux_24_675__CMP ? add_uu<4>(i_13_5c_tokens0_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_674__CMP.concat(i_procmux_24_673__CMP).concat(i_procmux_24_672__CMP).val()) ? i_13_5c_tokens0_5b_3_3a_0_5d_ : value<4>{0u})) : i_13_5c_tokens0_5b_3_3a_0_5d_) : value<4>{0u}));
	// \full_case: 1
	// \src: receiver.v:116.17-116.17|receiver.v:116.6-116.104
	// cell $procmux$625_CMP0
	i_procmux_24_583__CMP = logic_not<1>(i_9_5c_qo_5b_7_5d__5b_1_3a_0_5d_);
	// cells $procmux$750 $procmux$747 $procmux$745 $procmux$713 $add$receiver.v:116$305 $auto$opt_reduce.cc:131:opt_pmux$7065
	i_15_5c_tokens1_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_303__Y ? (i_procmux_24_674__CMP ? add_uu<4>(i_13_5c_tokens1_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_675__CMP.concat(i_procmux_24_673__CMP).concat(i_procmux_24_672__CMP).val()) ? i_13_5c_tokens1_5b_3_3a_0_5d_ : value<4>{0u})) : i_13_5c_tokens1_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$741 $procmux$738 $procmux$736 $procmux$699 $add$receiver.v:116$306 $auto$opt_reduce.cc:131:opt_pmux$7069
	i_15_5c_tokens2_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_303__Y ? (i_procmux_24_673__CMP ? add_uu<4>(i_13_5c_tokens2_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_675__CMP.concat(i_procmux_24_674__CMP).concat(i_procmux_24_672__CMP).val()) ? i_13_5c_tokens2_5b_3_3a_0_5d_ : value<4>{0u})) : i_13_5c_tokens2_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$732 $procmux$729 $procmux$727 $procmux$685 $add$receiver.v:116$307 $auto$opt_reduce.cc:131:opt_pmux$7071
	i_15_5c_tokens3_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_303__Y ? (reduce_or<1>(i_procmux_24_675__CMP.concat(i_procmux_24_674__CMP).concat(i_procmux_24_673__CMP).val()) ? i_13_5c_tokens3_5b_3_3a_0_5d_ : (i_procmux_24_672__CMP ? add_uu<4>(i_13_5c_tokens3_5b_3_3a_0_5d_, value<1>{0x1u}) : value<4>{0u})) : i_13_5c_tokens3_5b_3_3a_0_5d_) : value<4>{0u}));
	// \src: receiver.v:83.7-83.70
	// cell $not$receiver.v:83$196
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7167.slice<15,0>() = not_u<16>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7168.slice<15,0>().val());
	// cells $procmux$1752 $procmux$1749 $procmux$1747
	i_4_5c_rone_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? value<1>{0u} : i_4_5c_evblock_5b_0_3a_0_5d_) : value<1>{0u}));
	// cells $shift$receiver.v:83$203 $add$receiver.v:83$201
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7164.slice<15,0>() = shift_us<16>(add_uu<4>(i_shiftx_24_receiver_2e_v_3a_82_24_189__Y, value<1>{0x1u}), i_neg_24_receiver_2e_v_3a_83_24_194__Y);
	// \src: receiver.v:115.8-115.14
	// cell $lt$receiver.v:115$308
	i_lt_24_receiver_2e_v_3a_115_24_308__Y = lt_uu<1>(value<3>{0x7u}, i_7_5c_qlen_5b_3_3a_0_5d_);
	// cells $procmux$2679 $procmux$2676 $procmux$2674 $procmux$2339
	i_3_5c_rzero_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_209__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_213__Y ? value<1>{0x1u} : p_rzero.curr) : p_rzero.curr) : value<1>{0u}));
	// cells $or$receiver.v:83$204 $and$receiver.v:83$197
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7163.slice<15,0>() = or_uu<16>(and_uu<16>(i_3_5c_outstanding_5b_15_3a_0_5d_, i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7167.slice<15,0>().val()), i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7164.slice<15,0>().val());
	// cells $logic_and$receiver.v:103$252 $logic_not$receiver.v:103$251
	i_logic__and_24_receiver_2e_v_3a_103_24_252__Y = logic_and<1>(i_3_5c_rzero_5b_0_3a_0_5d_, logic_not<1>(i_4_5c_rone_5b_0_3a_0_5d_));
	// cells $procmux$1716 $procmux$1713 $procmux$1711 $procmux$1709 $procmux$1587
	i_4_5c_emitowner_5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? value<2>{0u} : (p_rone.curr ? (i_logic__or_24_receiver_2e_v_3a_100_24_250__Y ? p_ownerone.curr : p_emitowner.curr) : p_emitowner.curr)) : value<2>{0u}));
	// cells $procmux$2670 $procmux$2667 $procmux$2665 $procmux$2327
	i_3_5c_ownerzero_5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_209__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_213__Y ? i_6_5c_qo_5b_0_5d__5b_1_3a_0_5d_ : p_ownerzero.curr) : p_ownerzero.curr) : value<2>{0u}));
	// \src: receiver.v:110.51-110.62
	// cell $mul$receiver.v:110$266
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7152.slice<4,0>() = mul_uu<5>(value<3>{0x4u}, i_4_5c_emitowner_5b_1_3a_0_5d_);
	// connection
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7152.slice<31,5>() = value<27>{0u};
	// \full_case: 1
	// \src: receiver.v:119.48-119.48|receiver.v:119.13-119.115
	// cell $procmux$532_CMP0
	i_procmux_24_490__CMP = eq_uu<1>(i_3_5c_ownerzero_5b_1_3a_0_5d_, value<1>{0x1u});
	// \full_case: 1
	// \src: receiver.v:119.68-119.68|receiver.v:119.13-119.115
	// cell $procmux$531_CMP0
	i_procmux_24_489__CMP = eq_uu<1>(i_3_5c_ownerzero_5b_1_3a_0_5d_, value<2>{0x2u});
	// \full_case: 1
	// \src: receiver.v:119.88-119.88|receiver.v:119.13-119.115
	// cell $procmux$530_CMP0
	i_procmux_24_488__CMP = eq_uu<1>(i_3_5c_ownerzero_5b_1_3a_0_5d_, value<2>{0x3u});
	// cells $procmux$667 $procmux$664 $procmux$662 $procmux$579 $add$receiver.v:116$309 $auto$opt_reduce.cc:131:opt_pmux$7085
	i_17_5c_tokens0_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_308__Y ? (i_procmux_24_583__CMP ? add_uu<4>(i_15_5c_tokens0_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_582__CMP.concat(i_procmux_24_581__CMP).concat(i_procmux_24_580__CMP).val()) ? i_15_5c_tokens0_5b_3_3a_0_5d_ : value<4>{0u})) : i_15_5c_tokens0_5b_3_3a_0_5d_) : value<4>{0u}));
	// \full_case: 1
	// \src: receiver.v:119.28-119.28|receiver.v:119.13-119.115
	// cell $procmux$533_CMP0
	i_procmux_24_491__CMP = logic_not<1>(i_3_5c_ownerzero_5b_1_3a_0_5d_);
	// cells $procmux$658 $procmux$655 $procmux$653 $procmux$621 $add$receiver.v:116$310 $auto$opt_reduce.cc:131:opt_pmux$7077
	i_17_5c_tokens1_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_308__Y ? (i_procmux_24_582__CMP ? add_uu<4>(i_15_5c_tokens1_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_583__CMP.concat(i_procmux_24_581__CMP).concat(i_procmux_24_580__CMP).val()) ? i_15_5c_tokens1_5b_3_3a_0_5d_ : value<4>{0u})) : i_15_5c_tokens1_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$649 $procmux$646 $procmux$644 $procmux$607 $add$receiver.v:116$311 $auto$opt_reduce.cc:131:opt_pmux$7079
	i_17_5c_tokens2_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_308__Y ? (i_procmux_24_581__CMP ? add_uu<4>(i_15_5c_tokens2_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_583__CMP.concat(i_procmux_24_582__CMP).concat(i_procmux_24_580__CMP).val()) ? i_15_5c_tokens2_5b_3_3a_0_5d_ : value<4>{0u})) : i_15_5c_tokens2_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$640 $procmux$637 $procmux$635 $procmux$593 $add$receiver.v:116$312 $auto$opt_reduce.cc:131:opt_pmux$7083
	i_17_5c_tokens3_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_308__Y ? (reduce_or<1>(i_procmux_24_583__CMP.concat(i_procmux_24_582__CMP).concat(i_procmux_24_581__CMP).val()) ? i_15_5c_tokens3_5b_3_3a_0_5d_ : (i_procmux_24_580__CMP ? add_uu<4>(i_15_5c_tokens3_5b_3_3a_0_5d_, value<1>{0x1u}) : value<4>{0u})) : i_15_5c_tokens3_5b_3_3a_0_5d_) : value<4>{0u}));
	// \src: receiver.v:110.50-110.66
	// cell $add$receiver.v:110$267
	i_add_24_receiver_2e_v_3a_109_24_255__Y = add_uu<6>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7152.slice<4,0>().val(), value<1>{0u});
	// cells $procmux$3756 $procmux$3753 $procmux$3751 $procmux$3473
	i_5_5c_outstanding_5b_15_3a_0_5d_ = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_176__Y ? i_3_5c_outstanding_5b_15_3a_0_5d_ : i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7163.slice<15,0>().val()) : i_3_5c_outstanding_5b_15_3a_0_5d_) : value<16>{0u}));
	// \src: receiver.v:110.11-110.68
	// cell $neg$receiver.v:110$270
	i_neg_24_receiver_2e_v_3a_110_24_262__Y = neg_u<33>(i_add_24_receiver_2e_v_3a_109_24_255__Y);
	// cells $procmux$1887 $procmux$1884 $procmux$1882 $procmux$1433
	i_5_5c_rzero_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? i_3_5c_rzero_5b_0_3a_0_5d_ : (i_logic__and_24_receiver_2e_v_3a_103_24_252__Y ? value<1>{0u} : i_3_5c_rzero_5b_0_3a_0_5d_)) : value<1>{0u}));
	// \src: receiver.v:110.50-110.66
	// cell $shiftx$receiver.v:110$268
	i_shiftx_24_receiver_2e_v_3a_109_24_256__Y = shiftx_us<4>(i_5_5c_outstanding_5b_15_3a_0_5d_, value<1>{0u}.concat(i_add_24_receiver_2e_v_3a_109_24_255__Y).val());
	// \src: receiver.v:110.11-110.68
	// cell $shift$receiver.v:110$263
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7150.slice<15,0>() = shift_us<16>(value<4>{0xfu}, i_neg_24_receiver_2e_v_3a_110_24_262__Y);
	// \src: receiver.v:110.39-110.68
	// cell $sub$receiver.v:110$269
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7147.slice<3,0>() = sub_uu<4>(i_shiftx_24_receiver_2e_v_3a_109_24_256__Y, value<1>{0x1u});
	// \src: receiver.v:110.11-110.68
	// cell $not$receiver.v:110$264
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7149.slice<15,0>() = not_u<16>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7150.slice<15,0>().val());
	// \full_case: 1
	// \src: receiver.v:75.8-75.20|receiver.v:75.5-85.8
	// cell $procmux$4837
	i_procmux_24_4837__Y.slice<3,0>() = (i_5_5c_releasevalid_5b_0_3a_0_5d_ ? i_14_5c_fault_5b_31_3a_0_5d_.curr.slice<3,0>().val() : i_4_5c_fault_5b_31_3a_0_5d_.slice<3,0>().val());
	// connection
	i_procmux_24_4837__Y.slice<31,4>() = i_14_5c_fault_5b_31_3a_0_5d_.curr.slice<31,4>().val();
	// cells $procmux$1869 $procmux$1866 $procmux$1864 $procmux$1469
	i_3_5c_ownerone_5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? p_ownerone.curr : (i_logic__and_24_receiver_2e_v_3a_103_24_252__Y ? i_3_5c_ownerzero_5b_1_3a_0_5d_ : p_ownerone.curr)) : value<2>{0u}));
	// \src: receiver.v:110.11-110.68
	// cell $shift$receiver.v:110$271
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7146.slice<15,0>() = shift_us<16>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7147.slice<3,0>().val(), i_neg_24_receiver_2e_v_3a_110_24_262__Y);
	// \full_case: 1
	// \src: receiver.v:120.46-120.46|receiver.v:120.12-120.113
	// cell $procmux$440_CMP0
	i_procmux_24_398__CMP = eq_uu<1>(i_3_5c_ownerone_5b_1_3a_0_5d_, value<1>{0x1u});
	// \full_case: 1
	// \src: receiver.v:120.66-120.66|receiver.v:120.12-120.113
	// cell $procmux$439_CMP0
	i_procmux_24_397__CMP = eq_uu<1>(i_3_5c_ownerone_5b_1_3a_0_5d_, value<2>{0x2u});
	// \full_case: 1
	// \src: receiver.v:120.86-120.86|receiver.v:120.12-120.113
	// cell $procmux$438_CMP0
	i_procmux_24_396__CMP = eq_uu<1>(i_3_5c_ownerone_5b_1_3a_0_5d_, value<2>{0x3u});
	// cells $procmux$575 $procmux$572 $procmux$570 $procmux$487 $add$receiver.v:119$313 $auto$opt_reduce.cc:131:opt_pmux$7093
	i_19_5c_tokens0_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_5_5c_rzero_5b_0_3a_0_5d_ ? (i_procmux_24_491__CMP ? add_uu<4>(i_17_5c_tokens0_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_490__CMP.concat(i_procmux_24_489__CMP).concat(i_procmux_24_488__CMP).val()) ? i_17_5c_tokens0_5b_3_3a_0_5d_ : value<4>{0u})) : i_17_5c_tokens0_5b_3_3a_0_5d_) : value<4>{0u}));
	// \full_case: 1
	// \src: receiver.v:120.26-120.26|receiver.v:120.12-120.113
	// cell $procmux$441_CMP0
	i_procmux_24_399__CMP = logic_not<1>(i_3_5c_ownerone_5b_1_3a_0_5d_);
	// cells $procmux$566 $procmux$563 $procmux$561 $procmux$529 $add$receiver.v:119$314 $auto$opt_reduce.cc:131:opt_pmux$7087
	i_19_5c_tokens1_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_5_5c_rzero_5b_0_3a_0_5d_ ? (i_procmux_24_490__CMP ? add_uu<4>(i_17_5c_tokens1_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_491__CMP.concat(i_procmux_24_489__CMP).concat(i_procmux_24_488__CMP).val()) ? i_17_5c_tokens1_5b_3_3a_0_5d_ : value<4>{0u})) : i_17_5c_tokens1_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$557 $procmux$554 $procmux$552 $procmux$515 $add$receiver.v:119$315 $auto$opt_reduce.cc:131:opt_pmux$7089
	i_19_5c_tokens2_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_5_5c_rzero_5b_0_3a_0_5d_ ? (i_procmux_24_489__CMP ? add_uu<4>(i_17_5c_tokens2_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_491__CMP.concat(i_procmux_24_490__CMP).concat(i_procmux_24_488__CMP).val()) ? i_17_5c_tokens2_5b_3_3a_0_5d_ : value<4>{0u})) : i_17_5c_tokens2_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$548 $procmux$545 $procmux$543 $procmux$501 $add$receiver.v:119$316 $auto$opt_reduce.cc:131:opt_pmux$7091
	i_19_5c_tokens3_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_5_5c_rzero_5b_0_3a_0_5d_ ? (reduce_or<1>(i_procmux_24_491__CMP.concat(i_procmux_24_490__CMP).concat(i_procmux_24_489__CMP).val()) ? i_17_5c_tokens3_5b_3_3a_0_5d_ : (i_procmux_24_488__CMP ? add_uu<4>(i_17_5c_tokens3_5b_3_3a_0_5d_, value<1>{0x1u}) : value<4>{0u})) : i_17_5c_tokens3_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $or$receiver.v:110$272 $and$receiver.v:110$265
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7145.slice<15,0>() = or_uu<16>(and_uu<16>(i_5_5c_outstanding_5b_15_3a_0_5d_, i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7149.slice<15,0>().val()), i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7146.slice<15,0>().val());
	// \src: receiver.v:109.9-109.39
	// cell $eq$receiver.v:109$257
	i_eq_24_receiver_2e_v_3a_109_24_257__Y = logic_not<1>(i_shiftx_24_receiver_2e_v_3a_109_24_256__Y);
	// cells $procmux$4842 $procmux$4839
	i_13_5c_fault_5b_31_3a_0_5d_ = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_14_5c_fault_5b_31_3a_0_5d_.curr.slice<31,4>().concat(i_procmux_24_4837__Y.slice<3,0>()).val() : value<32>{0u}));
	// cells $procmux$1740 $procmux$1737 $procmux$1735 $procmux$1733 $procmux$1602
	i_4_5c_evemit_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? value<1>{0u} : (p_rone.curr ? (i_logic__or_24_receiver_2e_v_3a_100_24_250__Y ? value<1>{0x1u} : value<1>{0u}) : value<1>{0u})) : value<1>{0u}));
	// cells $procmux$4869 $procmux$4866 $procmux$4864 $procmux$4592 $add$receiver.v:81$139
	i_3_5c_nextid_5b_31_3a_0_5d_ = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_5_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_129__Y ? p_nextid.curr : add_uu<32>(p_nextid.curr, value<1>{0x1u})) : p_nextid.curr) : value<32>{0u}));
	// \src: receiver.v:93.61-93.69
	// cell $mul$receiver.v:93$236
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7155.slice<6,0>() = mul_uu<7>(value<5>{0x10u}, i_6_5c_qo_5b_0_5d__5b_1_3a_0_5d_);
	// connection
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7155.slice<31,7>() = value<25>{0u};
	// cells $procmux$4702 $procmux$4388 $procmux$3847
	i_3_5c_qi_5b_0_5d__5b_31_3a_0_5d_ = (i_5_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_129__Y ? p_qi_5b_0_5d_.curr : (i_procmux_24_3855__CMP ? p_nextid.curr : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6974 ? p_qi_5b_0_5d_.curr : value<32>{0u}))) : p_qi_5b_0_5d_.curr);
	// cells $procmux$2738 $eq$receiver.v:82$190
	i_18_5c_fault_5b_31_3a_0_5d_.slice<3,0>() = (eq_uu<1>(i_shiftx_24_receiver_2e_v_3a_82_24_189__Y, value<4>{0xfu}) ? value<1>{0x1u}.concat(i_13_5c_fault_5b_31_3a_0_5d_.slice<2,0>()).val() : i_13_5c_fault_5b_31_3a_0_5d_.slice<3,0>().val());
	// connection
	i_18_5c_fault_5b_31_3a_0_5d_.slice<31,4>() = i_13_5c_fault_5b_31_3a_0_5d_.slice<31,4>().val();
	// cells $procmux$1878 $procmux$1875 $procmux$1873 $procmux$1481
	i_3_5c_rone_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? p_rone.curr : (i_logic__and_24_receiver_2e_v_3a_103_24_252__Y ? value<1>{0x1u} : i_4_5c_rone_5b_0_3a_0_5d_)) : value<1>{0u}));
	// \src: receiver.v:91.63-91.70
	// cell $mul$receiver.v:91$218
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7162.slice<5,0>() = mul_uu<6>(value<4>{0x8u}, i_6_5c_qo_5b_0_5d__5b_1_3a_0_5d_);
	// connection
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7162.slice<31,6>() = value<26>{0u};
	// cells $procmux$4828 $procmux$4556
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7188.slice<0>() = (i_5_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_129__Y ? value<1>{0u} : value<1>{0x1u}) : value<1>{0u});
	// connection
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7188.slice<1>() = value<1>{0u};
	// \full_case: 1
	// \src: receiver.v:76.9-76.16|receiver.v:76.6-84.9
	// cell $procmux$3149
	i_17_5c_fault_5b_31_3a_0_5d_.slice<3,0>() = (i_ge_24_receiver_2e_v_3a_76_24_176__Y ? i_13_5c_fault_5b_31_3a_0_5d_.slice<3>().concat(value<1>{0x1u}).concat(i_13_5c_fault_5b_31_3a_0_5d_.slice<1,0>()).val() : i_18_5c_fault_5b_31_3a_0_5d_.slice<3,0>().val());
	// connection
	i_17_5c_fault_5b_31_3a_0_5d_.slice<31,4>() = i_13_5c_fault_5b_31_3a_0_5d_.slice<31,4>().val();
	// cells $neg$receiver.v:93$242 $add$receiver.v:93$237
	i_neg_24_receiver_2e_v_3a_93_24_238__Y = neg_u<33>(add_uu<8>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7155.slice<6,0>().val(), value<1>{0u}));
	// \src: receiver.v:93.37-93.53
	// cell $neg$receiver.v:93$233
	i_neg_24_receiver_2e_v_3a_93_24_226__Y = neg_u<3>(i_6_5c_qo_5b_0_5d__5b_1_3a_0_5d_);
	// cells $procmux$4639 $procmux$4304 $procmux$3868
	i_3_5c_qi_5b_7_5d__5b_31_3a_0_5d_ = (i_5_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_129__Y ? p_qi_5b_7_5d_.curr : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6972 ? p_qi_5b_7_5d_.curr : (i_procmux_24_3848__CMP ? p_nextid.curr : value<32>{0u}))) : p_qi_5b_7_5d_.curr);
	// cells $procmux$4648 $procmux$4316 $procmux$3889
	i_3_5c_qi_5b_6_5d__5b_31_3a_0_5d_ = (i_5_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_129__Y ? p_qi_5b_6_5d_.curr : (i_procmux_24_3849__CMP ? p_nextid.curr : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6970 ? p_qi_5b_6_5d_.curr : value<32>{0u}))) : p_qi_5b_6_5d_.curr);
	// cells $procmux$4657 $procmux$4328 $procmux$3910
	i_3_5c_qi_5b_5_5d__5b_31_3a_0_5d_ = (i_5_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_129__Y ? p_qi_5b_5_5d_.curr : (i_procmux_24_3850__CMP ? p_nextid.curr : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6968 ? p_qi_5b_5_5d_.curr : value<32>{0u}))) : p_qi_5b_5_5d_.curr);
	// cells $procmux$4666 $procmux$4340 $procmux$3931
	i_3_5c_qi_5b_4_5d__5b_31_3a_0_5d_ = (i_5_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_129__Y ? p_qi_5b_4_5d_.curr : (i_procmux_24_3851__CMP ? p_nextid.curr : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6966 ? p_qi_5b_4_5d_.curr : value<32>{0u}))) : p_qi_5b_4_5d_.curr);
	// cells $procmux$4675 $procmux$4352 $procmux$3952
	i_3_5c_qi_5b_3_5d__5b_31_3a_0_5d_ = (i_5_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_129__Y ? p_qi_5b_3_5d_.curr : (i_procmux_24_3852__CMP ? p_nextid.curr : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6964 ? p_qi_5b_3_5d_.curr : value<32>{0u}))) : p_qi_5b_3_5d_.curr);
	// cells $procmux$4684 $procmux$4364 $procmux$3973
	i_3_5c_qi_5b_2_5d__5b_31_3a_0_5d_ = (i_5_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_129__Y ? p_qi_5b_2_5d_.curr : (i_procmux_24_3853__CMP ? p_nextid.curr : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6962 ? p_qi_5b_2_5d_.curr : value<32>{0u}))) : p_qi_5b_2_5d_.curr);
	// cells $procmux$4693 $procmux$4376 $procmux$3994
	i_3_5c_qi_5b_1_5d__5b_31_3a_0_5d_ = (i_5_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_129__Y ? p_qi_5b_1_5d_.curr : (i_procmux_24_3854__CMP ? p_nextid.curr : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6976 ? p_qi_5b_1_5d_.curr : value<32>{0u}))) : p_qi_5b_1_5d_.curr);
	// cells $procmux$5984 $procmux$5981 $procmux$5979
	i_3_5c_bytes_5b_7_3a_0_5d_ = (p_rst ? value<8>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_59_24_90__Y ? p_wubytes.slice<7,0>().val() : p_bytes.curr.slice<7,0>().val()) : value<8>{0u}));
	// cells $procmux$5948 $procmux$5945 $procmux$5943
	i_4_5c_bytes_5b_15_3a_8_5d_ = (p_rst ? value<8>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_59_24_91__Y ? p_wubytes.slice<15,8>().val() : p_bytes.curr.slice<15,8>().val()) : value<8>{0u}));
	// cells $procmux$5912 $procmux$5909 $procmux$5907
	i_5_5c_bytes_5b_23_3a_16_5d_ = (p_rst ? value<8>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_59_24_92__Y ? p_wubytes.slice<23,16>().val() : p_bytes.curr.slice<23,16>().val()) : value<8>{0u}));
	// cells $procmux$5876 $procmux$5873 $procmux$5871
	i_6_5c_bytes_5b_31_3a_24_5d_ = (p_rst ? value<8>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_59_24_93__Y ? p_wubytes.slice<31,24>().val() : p_bytes.curr.slice<31,24>().val()) : value<8>{0u}));
	// \full_case: 1
	// \src: receiver.v:75.8-75.20|receiver.v:75.5-85.8
	// cell $procmux$3742
	i_16_5c_fault_5b_31_3a_0_5d_.slice<3,0>() = (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? i_17_5c_fault_5b_31_3a_0_5d_.slice<3,0>().val() : i_13_5c_fault_5b_31_3a_0_5d_.slice<3,0>().val());
	// connection
	i_16_5c_fault_5b_31_3a_0_5d_.slice<31,4>() = i_13_5c_fault_5b_31_3a_0_5d_.slice<31,4>().val();
	// \src: receiver.v:93.37-93.53
	// cell $shift$receiver.v:93$230
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7160.slice<3,0>() = shift_us<4>(value<1>{0x1u}, i_neg_24_receiver_2e_v_3a_93_24_226__Y);
	// cells $shiftx$receiver.v:91$220 $add$receiver.v:91$219
	i_shiftx_24_receiver_2e_v_3a_91_24_220__Y = shiftx_us<8>(i_6_5c_bytes_5b_31_3a_24_5d_.concat(i_5_5c_bytes_5b_23_3a_16_5d_).concat(i_4_5c_bytes_5b_15_3a_8_5d_).concat(i_3_5c_bytes_5b_7_3a_0_5d_).val(), value<1>{0u}.concat(add_uu<7>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7162.slice<5,0>().val(), value<1>{0u})).val());
	// cells $procmux$4833 $procmux$4830
	i_3_5c_evenq_5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? value<1>{0u}.concat(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7188.slice<0>()).val() : value<2>{0u}));
	// cells $procmux$3607 $procmux$3293 $procmux$2752
	i_6_5c_qi_5b_0_5d__5b_31_3a_0_5d_ = (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_176__Y ? i_3_5c_qi_5b_0_5d__5b_31_3a_0_5d_ : (i_procmux_24_2760__CMP ? i_3_5c_nextid_5b_31_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_7022 ? i_3_5c_qi_5b_0_5d__5b_31_3a_0_5d_ : value<32>{0u}))) : i_3_5c_qi_5b_0_5d__5b_31_3a_0_5d_);
	// cells $procmux$5813 $procmux$5810 $procmux$5808 $procmux$5084 $procmux$5019 $procmux$4938
	i_7_5c_enabled_5b_3_3a_0_5d_.slice<3>() = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_eq_24_receiver_2e_v_3a_61_24_94__Y ? (i_6_5c_enabled_5b_3_3a_3_5d_ ? (i_eq_24_receiver_2e_v_3a_64_24_107__Y ? value<1>{0x1u} : (i_eq_24_receiver_2e_v_3a_65_24_110__Y ? value<1>{0u} : value<1>{0x1u})) : value<1>{0u}) : i_6_5c_enabled_5b_3_3a_3_5d_) : value<1>{0u}));
	// cells $procmux$5786 $procmux$5783 $procmux$5781 $procmux$5651 $procmux$5586 $procmux$5505
	i_7_5c_enabled_5b_3_3a_0_5d_.slice<0>() = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_eq_24_receiver_2e_v_3a_61_24_94__Y ? (i_3_5c_enabled_5b_0_3a_0_5d_ ? (i_eq_24_receiver_2e_v_3a_64_24_95__Y ? value<1>{0x1u} : (i_eq_24_receiver_2e_v_3a_65_24_98__Y ? value<1>{0u} : value<1>{0x1u})) : value<1>{0u}) : i_3_5c_enabled_5b_0_3a_0_5d_) : value<1>{0u}));
	// cells $procmux$5750 $procmux$5747 $procmux$5745 $procmux$5462 $procmux$5397 $procmux$5316
	i_7_5c_enabled_5b_3_3a_0_5d_.slice<1>() = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_eq_24_receiver_2e_v_3a_61_24_94__Y ? (i_4_5c_enabled_5b_1_3a_1_5d_ ? (i_eq_24_receiver_2e_v_3a_64_24_99__Y ? value<1>{0x1u} : (i_eq_24_receiver_2e_v_3a_65_24_102__Y ? value<1>{0u} : value<1>{0x1u})) : value<1>{0u}) : i_4_5c_enabled_5b_1_3a_1_5d_) : value<1>{0u}));
	// cells $procmux$5714 $procmux$5711 $procmux$5709 $procmux$5273 $procmux$5208 $procmux$5127
	i_7_5c_enabled_5b_3_3a_0_5d_.slice<2>() = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_eq_24_receiver_2e_v_3a_61_24_94__Y ? (i_5_5c_enabled_5b_2_3a_2_5d_ ? (i_eq_24_receiver_2e_v_3a_64_24_103__Y ? value<1>{0x1u} : (i_eq_24_receiver_2e_v_3a_65_24_106__Y ? value<1>{0u} : value<1>{0x1u})) : value<1>{0u}) : i_5_5c_enabled_5b_2_3a_2_5d_) : value<1>{0u}));
	// \full_case: 1
	// \src: receiver.v:109.9-109.39|receiver.v:109.6-110.69
	// cell $procmux$1317
	i_21_5c_fault_5b_31_3a_0_5d_.slice<4,0>() = (i_eq_24_receiver_2e_v_3a_109_24_257__Y ? value<1>{0x1u}.concat(i_16_5c_fault_5b_31_3a_0_5d_.slice<3,0>()).val() : i_13_5c_fault_5b_31_3a_0_5d_.slice<4>().concat(i_16_5c_fault_5b_31_3a_0_5d_.slice<3,0>()).val());
	// connection
	i_21_5c_fault_5b_31_3a_0_5d_.slice<31,5>() = i_13_5c_fault_5b_31_3a_0_5d_.slice<31,5>().val();
	// cells $procmux$1806 $procmux$1803 $procmux$1801 $procmux$1385 $procmux$1347
	i_7_5c_outstanding_5b_15_3a_0_5d_ = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? i_5_5c_outstanding_5b_15_3a_0_5d_ : (i_4_5c_evemit_5b_0_3a_0_5d_ ? (i_eq_24_receiver_2e_v_3a_109_24_257__Y ? i_5_5c_outstanding_5b_15_3a_0_5d_ : i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7145.slice<15,0>().val()) : i_5_5c_outstanding_5b_15_3a_0_5d_)) : value<16>{0u}));
	// cells $procmux$5804 $procmux$5801 $procmux$5799 $procmux$5072 $procmux$5004
	i_7_5c_counts_5b_63_3a_0_5d_.slice<63,48>() = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_eq_24_receiver_2e_v_3a_61_24_94__Y ? (i_6_5c_enabled_5b_3_3a_3_5d_ ? (i_eq_24_receiver_2e_v_3a_64_24_107__Y ? i_6_5c_counts_5b_63_3a_48_5d_ : i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7184.slice<15,0>().val()) : i_6_5c_counts_5b_63_3a_48_5d_) : i_6_5c_counts_5b_63_3a_48_5d_) : value<16>{0u}));
	// cells $procmux$5777 $procmux$5774 $procmux$5772 $procmux$5639 $procmux$5571
	i_7_5c_counts_5b_63_3a_0_5d_.slice<15,0>() = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_eq_24_receiver_2e_v_3a_61_24_94__Y ? (i_3_5c_enabled_5b_0_3a_0_5d_ ? (i_eq_24_receiver_2e_v_3a_64_24_95__Y ? i_3_5c_counts_5b_15_3a_0_5d_ : i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7187.slice<15,0>().val()) : i_3_5c_counts_5b_15_3a_0_5d_) : i_3_5c_counts_5b_15_3a_0_5d_) : value<16>{0u}));
	// cells $procmux$5741 $procmux$5738 $procmux$5736 $procmux$5450 $procmux$5382
	i_7_5c_counts_5b_63_3a_0_5d_.slice<31,16>() = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_eq_24_receiver_2e_v_3a_61_24_94__Y ? (i_4_5c_enabled_5b_1_3a_1_5d_ ? (i_eq_24_receiver_2e_v_3a_64_24_99__Y ? i_4_5c_counts_5b_31_3a_16_5d_ : i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7186.slice<15,0>().val()) : i_4_5c_counts_5b_31_3a_16_5d_) : i_4_5c_counts_5b_31_3a_16_5d_) : value<16>{0u}));
	// cells $procmux$5705 $procmux$5702 $procmux$5700 $procmux$5261 $procmux$5193
	i_7_5c_counts_5b_63_3a_0_5d_.slice<47,32>() = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_eq_24_receiver_2e_v_3a_61_24_94__Y ? (i_5_5c_enabled_5b_2_3a_2_5d_ ? (i_eq_24_receiver_2e_v_3a_64_24_103__Y ? i_5_5c_counts_5b_47_3a_32_5d_ : i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7185.slice<15,0>().val()) : i_5_5c_counts_5b_47_3a_32_5d_) : i_5_5c_counts_5b_47_3a_32_5d_) : value<16>{0u}));
	// \src: receiver.v:93.37-93.53
	// cell $not$receiver.v:93$231
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7159.slice<3,0>() = not_u<4>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7160.slice<3,0>().val());
	// \src: receiver.v:78.10-78.18
	// cell $eq$receiver.v:78$183
	i_eq_24_receiver_2e_v_3a_78_24_183__Y = logic_not<1>(i_3_5c_evenq_5b_1_3a_0_5d_);
	// cells $procmux$4810 $procmux$4532
	i_3_5c_enqid_5b_31_3a_0_5d_ = (i_5_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_129__Y ? p_enqid.curr : p_nextid.curr) : p_enqid.curr);
	// cells $procmux$4819 $procmux$4544
	i_3_5c_enqowner_5b_1_3a_0_5d_ = (i_5_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_129__Y ? p_enqowner.curr : i_5_5c_enqowner_5b_1_3a_0_5d_) : p_enqowner.curr);
	// \full_case: 1
	// \src: receiver.v:107.8-107.14|receiver.v:107.5-111.8
	// cell $procmux$1373
	i_20_5c_fault_5b_31_3a_0_5d_.slice<4,0>() = (i_4_5c_evemit_5b_0_3a_0_5d_ ? i_21_5c_fault_5b_31_3a_0_5d_.slice<4,0>().val() : i_13_5c_fault_5b_31_3a_0_5d_.slice<4>().concat(i_16_5c_fault_5b_31_3a_0_5d_.slice<3,0>()).val());
	// connection
	i_20_5c_fault_5b_31_3a_0_5d_.slice<31,5>() = i_13_5c_fault_5b_31_3a_0_5d_.slice<31,5>().val();
	// cells $procmux$3774 $procmux$3771 $procmux$3769 $procmux$3497 $add$receiver.v:81$186
	i_5_5c_nextid_5b_31_3a_0_5d_ = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_176__Y ? i_3_5c_nextid_5b_31_3a_0_5d_ : add_uu<32>(i_3_5c_nextid_5b_31_3a_0_5d_, value<1>{0x1u})) : i_3_5c_nextid_5b_31_3a_0_5d_) : value<32>{0u}));
	// \src: receiver.v:93.37-93.53
	// cell $shift$receiver.v:93$234
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7157.slice<3,0>() = shift_us<4>(value<1>{0u}, i_neg_24_receiver_2e_v_3a_93_24_226__Y);
	// cells $procmux$3544 $procmux$3209 $procmux$2773
	i_6_5c_qi_5b_7_5d__5b_31_3a_0_5d_ = (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_176__Y ? i_3_5c_qi_5b_7_5d__5b_31_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_7016 ? i_3_5c_qi_5b_7_5d__5b_31_3a_0_5d_ : (i_procmux_24_2753__CMP ? i_3_5c_nextid_5b_31_3a_0_5d_ : value<32>{0u}))) : i_3_5c_qi_5b_7_5d__5b_31_3a_0_5d_);
	// cells $procmux$3553 $procmux$3221 $procmux$2794
	i_6_5c_qi_5b_6_5d__5b_31_3a_0_5d_ = (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_176__Y ? i_3_5c_qi_5b_6_5d__5b_31_3a_0_5d_ : (i_procmux_24_2754__CMP ? i_3_5c_nextid_5b_31_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_7008 ? i_3_5c_qi_5b_6_5d__5b_31_3a_0_5d_ : value<32>{0u}))) : i_3_5c_qi_5b_6_5d__5b_31_3a_0_5d_);
	// cells $procmux$3562 $procmux$3233 $procmux$2815
	i_6_5c_qi_5b_5_5d__5b_31_3a_0_5d_ = (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_176__Y ? i_3_5c_qi_5b_5_5d__5b_31_3a_0_5d_ : (i_procmux_24_2755__CMP ? i_3_5c_nextid_5b_31_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6998 ? i_3_5c_qi_5b_5_5d__5b_31_3a_0_5d_ : value<32>{0u}))) : i_3_5c_qi_5b_5_5d__5b_31_3a_0_5d_);
	// cells $procmux$3571 $procmux$3245 $procmux$2836
	i_6_5c_qi_5b_4_5d__5b_31_3a_0_5d_ = (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_176__Y ? i_3_5c_qi_5b_4_5d__5b_31_3a_0_5d_ : (i_procmux_24_2756__CMP ? i_3_5c_nextid_5b_31_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6990 ? i_3_5c_qi_5b_4_5d__5b_31_3a_0_5d_ : value<32>{0u}))) : i_3_5c_qi_5b_4_5d__5b_31_3a_0_5d_);
	// cells $procmux$3580 $procmux$3257 $procmux$2857
	i_6_5c_qi_5b_3_5d__5b_31_3a_0_5d_ = (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_176__Y ? i_3_5c_qi_5b_3_5d__5b_31_3a_0_5d_ : (i_procmux_24_2757__CMP ? i_3_5c_nextid_5b_31_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6988 ? i_3_5c_qi_5b_3_5d__5b_31_3a_0_5d_ : value<32>{0u}))) : i_3_5c_qi_5b_3_5d__5b_31_3a_0_5d_);
	// cells $procmux$3589 $procmux$3269 $procmux$2878
	i_6_5c_qi_5b_2_5d__5b_31_3a_0_5d_ = (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_176__Y ? i_3_5c_qi_5b_2_5d__5b_31_3a_0_5d_ : (i_procmux_24_2758__CMP ? i_3_5c_nextid_5b_31_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6984 ? i_3_5c_qi_5b_2_5d__5b_31_3a_0_5d_ : value<32>{0u}))) : i_3_5c_qi_5b_2_5d__5b_31_3a_0_5d_);
	// cells $procmux$3598 $procmux$3281 $procmux$2899
	i_6_5c_qi_5b_1_5d__5b_31_3a_0_5d_ = (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_176__Y ? i_3_5c_qi_5b_1_5d__5b_31_3a_0_5d_ : (i_procmux_24_2759__CMP ? i_3_5c_nextid_5b_31_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6982 ? i_3_5c_qi_5b_1_5d__5b_31_3a_0_5d_ : value<32>{0u}))) : i_3_5c_qi_5b_1_5d__5b_31_3a_0_5d_);
	// cells $procmux$2647 $procmux$2303
	i_3_5c_bytezero_5b_7_3a_0_5d_ = (i_logic__and_24_receiver_2e_v_3a_87_24_209__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_213__Y ? i_shiftx_24_receiver_2e_v_3a_91_24_220__Y : p_bytezero.curr) : p_bytezero.curr);
	// cells $procmux$1685 $procmux$1572
	i_4_5c_emitid_5b_31_3a_0_5d_ = (p_rone.curr ? (i_logic__or_24_receiver_2e_v_3a_100_24_250__Y ? p_idone.curr : p_emitid.curr) : p_emitid.curr);
	// cells $procmux$2656 $procmux$2315
	i_3_5c_idzero_5b_31_3a_0_5d_ = (i_logic__and_24_receiver_2e_v_3a_87_24_209__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_213__Y ? i_6_5c_qi_5b_0_5d__5b_31_3a_0_5d_ : p_idzero.curr) : p_idzero.curr);
	// \full_case: 1
	// \src: receiver.v:98.7-98.14|receiver.v:98.4-112.7
	// cell $procmux$1792
	i_19_5c_fault_5b_31_3a_0_5d_.slice<4,0>() = (i_3_5c_failed_5b_0_3a_0_5d_ ? i_13_5c_fault_5b_31_3a_0_5d_.slice<4>().concat(i_16_5c_fault_5b_31_3a_0_5d_.slice<3,0>()).val() : i_20_5c_fault_5b_31_3a_0_5d_.slice<4,0>().val());
	// connection
	i_19_5c_fault_5b_31_3a_0_5d_.slice<31,5>() = i_13_5c_fault_5b_31_3a_0_5d_.slice<31,5>().val();
	// cells $or$receiver.v:93$235 $and$receiver.v:93$232
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7156.slice<3,0>() = or_uu<4>(and_uu<4>(i_7_5c_enabled_5b_3_3a_0_5d_, i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7159.slice<3,0>().val()), i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7157.slice<3,0>().val());
	// \src: receiver.v:127.36-127.40
	// cell $add$receiver.v:127$341
	i_add_24_receiver_2e_v_3a_127_24_339__Y = add_uu<17>(p_pp.curr, value<1>{0x1u});
	// \src: receiver.v:126.31-126.35
	// cell $add$receiver.v:126$338
	i_add_24_receiver_2e_v_3a_126_24_336__Y = add_uu<17>(p_fp.curr, value<1>{0x1u});
	// \src: receiver.v:125.31-125.35
	// cell $add$receiver.v:125$335
	i_add_24_receiver_2e_v_3a_125_24_333__Y = add_uu<17>(p_rp.curr, value<1>{0x1u});
	// \src: receiver.v:124.31-124.35
	// cell $add$receiver.v:124$332
	i_add_24_receiver_2e_v_3a_124_24_330__Y = add_uu<17>(p_cp.curr, value<1>{0x1u});
	// cells $procmux$386 $logic_or$receiver.v:121$323 $gt$receiver.v:121$321 $ne$receiver.v:121$322 $procmux$483 $procmux$480 $procmux$478 $procmux$395 $add$receiver.v:120$317 $auto$opt_reduce.cc:131:opt_pmux$7103 $procmux$474 $procmux$471 $procmux$469 $procmux$437 $add$receiver.v:120$318 $auto$opt_reduce.cc:131:opt_pmux$7095 $procmux$465 $procmux$462 $procmux$460 $procmux$423 $add$receiver.v:120$319 $auto$opt_reduce.cc:131:opt_pmux$7097 $procmux$456 $procmux$453 $procmux$451 $procmux$409 $add$receiver.v:120$320 $auto$opt_reduce.cc:131:opt_pmux$7101
	i_22_5c_fault_5b_31_3a_0_5d_.slice<5,0>() = (logic_or<1>(gt_uu<1>(i_7_5c_qlen_5b_3_3a_0_5d_, value<4>{0x8u}), ne_uu<1>((p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_rone_5b_0_3a_0_5d_ ? (reduce_or<1>(i_procmux_24_399__CMP.concat(i_procmux_24_398__CMP).concat(i_procmux_24_397__CMP).val()) ? i_19_5c_tokens3_5b_3_3a_0_5d_ : (i_procmux_24_396__CMP ? add_uu<4>(i_19_5c_tokens3_5b_3_3a_0_5d_, value<1>{0x1u}) : value<4>{0u})) : i_19_5c_tokens3_5b_3_3a_0_5d_) : value<4>{0u})).concat((p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_rone_5b_0_3a_0_5d_ ? (i_procmux_24_397__CMP ? add_uu<4>(i_19_5c_tokens2_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_399__CMP.concat(i_procmux_24_398__CMP).concat(i_procmux_24_396__CMP).val()) ? i_19_5c_tokens2_5b_3_3a_0_5d_ : value<4>{0u})) : i_19_5c_tokens2_5b_3_3a_0_5d_) : value<4>{0u}))).concat((p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_rone_5b_0_3a_0_5d_ ? (i_procmux_24_398__CMP ? add_uu<4>(i_19_5c_tokens1_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_399__CMP.concat(i_procmux_24_397__CMP).concat(i_procmux_24_396__CMP).val()) ? i_19_5c_tokens1_5b_3_3a_0_5d_ : value<4>{0u})) : i_19_5c_tokens1_5b_3_3a_0_5d_) : value<4>{0u}))).concat((p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_rone_5b_0_3a_0_5d_ ? (i_procmux_24_399__CMP ? add_uu<4>(i_19_5c_tokens0_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_398__CMP.concat(i_procmux_24_397__CMP).concat(i_procmux_24_396__CMP).val()) ? i_19_5c_tokens0_5b_3_3a_0_5d_ : value<4>{0u})) : i_19_5c_tokens0_5b_3_3a_0_5d_) : value<4>{0u}))).val(), i_7_5c_outstanding_5b_15_3a_0_5d_)) ? value<1>{0x1u}.concat(i_19_5c_fault_5b_31_3a_0_5d_.slice<4,0>()).val() : i_13_5c_fault_5b_31_3a_0_5d_.slice<5>().concat(i_19_5c_fault_5b_31_3a_0_5d_.slice<4,0>()).val());
	// connection
	i_22_5c_fault_5b_31_3a_0_5d_.slice<31,6>() = i_13_5c_fault_5b_31_3a_0_5d_.slice<31,6>().val();
	// cells $procmux$5763 $procmux$5615 $procmux$5556 $procmux$5487
	i_3_5c_evexpire_5b_3_3a_0_5d_.slice<0>() = (i_eq_24_receiver_2e_v_3a_61_24_94__Y ? (i_3_5c_enabled_5b_0_3a_0_5d_ ? (i_eq_24_receiver_2e_v_3a_64_24_95__Y ? value<1>{0u} : (i_eq_24_receiver_2e_v_3a_65_24_98__Y ? value<1>{0x1u} : value<1>{0u})) : value<1>{0u}) : value<1>{0u});
	// cells $procmux$5727 $procmux$5426 $procmux$5367 $procmux$5298
	i_3_5c_evexpire_5b_3_3a_0_5d_.slice<1>() = (i_eq_24_receiver_2e_v_3a_61_24_94__Y ? (i_4_5c_enabled_5b_1_3a_1_5d_ ? (i_eq_24_receiver_2e_v_3a_64_24_99__Y ? value<1>{0u} : (i_eq_24_receiver_2e_v_3a_65_24_102__Y ? value<1>{0x1u} : value<1>{0u})) : value<1>{0u}) : value<1>{0u});
	// cells $procmux$5682 $procmux$5237 $procmux$5178 $procmux$5109
	i_3_5c_evexpire_5b_3_3a_0_5d_.slice<2>() = (i_eq_24_receiver_2e_v_3a_61_24_94__Y ? (i_5_5c_enabled_5b_2_3a_2_5d_ ? (i_eq_24_receiver_2e_v_3a_64_24_103__Y ? value<1>{0u} : (i_eq_24_receiver_2e_v_3a_65_24_106__Y ? value<1>{0x1u} : value<1>{0u})) : value<1>{0u}) : value<1>{0u});
	// cells $procmux$4927 $procmux$5048 $procmux$4989 $procmux$5828
	i_3_5c_evexpire_5b_3_3a_0_5d_.slice<3>() = (i_eq_24_receiver_2e_v_3a_61_24_94__Y ? (i_6_5c_enabled_5b_3_3a_3_5d_ ? (i_eq_24_receiver_2e_v_3a_64_24_107__Y ? value<1>{0u} : (i_eq_24_receiver_2e_v_3a_65_24_110__Y ? value<1>{0x1u} : value<1>{0u})) : value<1>{0u}) : value<1>{0u});
	// cells $procmux$377 $logic_or$receiver.v:122$327 $ge$receiver.v:122$325 $ge$receiver.v:122$326
	i_23_5c_fault_5b_31_3a_0_5d_.slice<6,0>() = (logic_or<1>(ge_uu<1>(p_tick.curr, value<31>{0x7ffffffeu}), ge_uu<1>(i_5_5c_nextid_5b_31_3a_0_5d_, value<31>{0x7ffffffeu})) ? value<1>{0x1u}.concat(i_22_5c_fault_5b_31_3a_0_5d_.slice<5,0>()).val() : i_13_5c_fault_5b_31_3a_0_5d_.slice<6>().concat(i_22_5c_fault_5b_31_3a_0_5d_.slice<5,0>()).val());
	// connection
	i_23_5c_fault_5b_31_3a_0_5d_.slice<31,7>() = i_13_5c_fault_5b_31_3a_0_5d_.slice<31,7>().val();
	// cells $procmux$6551 $procmux$5952
	i_2_5c_evwu_5b_3_3a_0_5d_.slice<0>() = (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_59_24_90__Y ? value<1>{0x1u} : value<1>{0u}) : p_evwu.curr.slice<0>().val());
	// cells $procmux$6539 $procmux$5916
	i_2_5c_evwu_5b_3_3a_0_5d_.slice<1>() = (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_59_24_91__Y ? value<1>{0x1u} : value<1>{0u}) : p_evwu.curr.slice<1>().val());
	// cells $procmux$6527 $procmux$5880
	i_2_5c_evwu_5b_3_3a_0_5d_.slice<2>() = (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_59_24_92__Y ? value<1>{0x1u} : value<1>{0u}) : p_evwu.curr.slice<2>().val());
	// cells $procmux$343 $procmux$5844
	i_2_5c_evwu_5b_3_3a_0_5d_.slice<3>() = (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_59_24_93__Y ? value<1>{0x1u} : value<1>{0u}) : p_evwu.curr.slice<3>().val());
	// \full_case: 1
	// \src: receiver.v:55.15-55.34|receiver.v:55.12-128.6
	// cell $procmux$6563
	i_2_5c_bytes_5b_31_3a_0_5d_.slice<31,24>() = (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_6_5c_bytes_5b_31_3a_24_5d_ : p_bytes.curr.slice<31,24>().val());
	// \full_case: 1
	// \src: receiver.v:55.15-55.34|receiver.v:55.12-128.6
	// cell $procmux$6557
	i_2_5c_bytes_5b_31_3a_0_5d_.slice<7,0>() = (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_3_5c_bytes_5b_7_3a_0_5d_ : p_bytes.curr.slice<7,0>().val());
	// \full_case: 1
	// \src: receiver.v:55.15-55.34|receiver.v:55.12-128.6
	// cell $procmux$6545
	i_2_5c_bytes_5b_31_3a_0_5d_.slice<15,8>() = (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_4_5c_bytes_5b_15_3a_8_5d_ : p_bytes.curr.slice<15,8>().val());
	// \full_case: 1
	// \src: receiver.v:55.15-55.34|receiver.v:55.12-128.6
	// cell $procmux$6533
	i_2_5c_bytes_5b_31_3a_0_5d_.slice<23,16>() = (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_5_5c_bytes_5b_23_3a_16_5d_ : p_bytes.curr.slice<23,16>().val());
	// cells $procdff$6952 $procmux$6740 $procmux$6179 $procmux$2386 $procmux$2003
	if (posedge_p_clk) {
		p_qi_5b_7_5d_.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_209__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_213__Y ? value<32>{0u} : i_6_5c_qi_5b_7_5d__5b_31_3a_0_5d_) : i_6_5c_qi_5b_7_5d__5b_31_3a_0_5d_) : p_qi_5b_7_5d_.curr));
	}
	// cells $procdff$6951 $procmux$6746 $procmux$6185 $procmux$2395 $procmux$2015
	if (posedge_p_clk) {
		p_qi_5b_6_5d_.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_209__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_213__Y ? i_6_5c_qi_5b_7_5d__5b_31_3a_0_5d_ : i_6_5c_qi_5b_6_5d__5b_31_3a_0_5d_) : i_6_5c_qi_5b_6_5d__5b_31_3a_0_5d_) : p_qi_5b_6_5d_.curr));
	}
	// cells $procdff$6950 $procmux$6752 $procmux$6191 $procmux$2404 $procmux$2027
	if (posedge_p_clk) {
		p_qi_5b_5_5d_.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_209__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_213__Y ? i_6_5c_qi_5b_6_5d__5b_31_3a_0_5d_ : i_6_5c_qi_5b_5_5d__5b_31_3a_0_5d_) : i_6_5c_qi_5b_5_5d__5b_31_3a_0_5d_) : p_qi_5b_5_5d_.curr));
	}
	// cells $procdff$6949 $procmux$6758 $procmux$6197 $procmux$2413 $procmux$2039
	if (posedge_p_clk) {
		p_qi_5b_4_5d_.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_209__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_213__Y ? i_6_5c_qi_5b_5_5d__5b_31_3a_0_5d_ : i_6_5c_qi_5b_4_5d__5b_31_3a_0_5d_) : i_6_5c_qi_5b_4_5d__5b_31_3a_0_5d_) : p_qi_5b_4_5d_.curr));
	}
	// cells $procdff$6948 $procmux$6764 $procmux$6203 $procmux$2422 $procmux$2051
	if (posedge_p_clk) {
		p_qi_5b_3_5d_.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_209__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_213__Y ? i_6_5c_qi_5b_4_5d__5b_31_3a_0_5d_ : i_6_5c_qi_5b_3_5d__5b_31_3a_0_5d_) : i_6_5c_qi_5b_3_5d__5b_31_3a_0_5d_) : p_qi_5b_3_5d_.curr));
	}
	// cells $procdff$6947 $procmux$6770 $procmux$6209 $procmux$2431 $procmux$2063
	if (posedge_p_clk) {
		p_qi_5b_2_5d_.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_209__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_213__Y ? i_6_5c_qi_5b_3_5d__5b_31_3a_0_5d_ : i_6_5c_qi_5b_2_5d__5b_31_3a_0_5d_) : i_6_5c_qi_5b_2_5d__5b_31_3a_0_5d_) : p_qi_5b_2_5d_.curr));
	}
	// cells $procdff$6946 $procmux$6776 $procmux$6215 $procmux$2440 $procmux$2075
	if (posedge_p_clk) {
		p_qi_5b_1_5d_.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_209__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_213__Y ? i_6_5c_qi_5b_2_5d__5b_31_3a_0_5d_ : i_6_5c_qi_5b_1_5d__5b_31_3a_0_5d_) : i_6_5c_qi_5b_1_5d__5b_31_3a_0_5d_) : p_qi_5b_1_5d_.curr));
	}
	// cells $procdff$6945 $procmux$6782 $procmux$6221 $procmux$2449 $procmux$2087
	if (posedge_p_clk) {
		p_qi_5b_0_5d_.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_209__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_213__Y ? i_6_5c_qi_5b_1_5d__5b_31_3a_0_5d_ : i_6_5c_qi_5b_0_5d__5b_31_3a_0_5d_) : i_6_5c_qi_5b_0_5d__5b_31_3a_0_5d_) : p_qi_5b_0_5d_.curr));
	}
	// cells $procdff$6944 $procmux$6743 $procmux$6227
	if (posedge_p_clk) {
		p_qo_5b_7_5d_.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_9_5c_qo_5b_7_5d__5b_1_3a_0_5d_ : p_qo_5b_7_5d_.curr));
	}
	// cells $procdff$6943 $procmux$6749 $procmux$6233
	if (posedge_p_clk) {
		p_qo_5b_6_5d_.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_9_5c_qo_5b_6_5d__5b_1_3a_0_5d_ : p_qo_5b_6_5d_.curr));
	}
	// cells $procdff$6942 $procmux$6755 $procmux$6239
	if (posedge_p_clk) {
		p_qo_5b_5_5d_.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_9_5c_qo_5b_5_5d__5b_1_3a_0_5d_ : p_qo_5b_5_5d_.curr));
	}
	// cells $procdff$6941 $procmux$6761 $procmux$6245
	if (posedge_p_clk) {
		p_qo_5b_4_5d_.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_9_5c_qo_5b_4_5d__5b_1_3a_0_5d_ : p_qo_5b_4_5d_.curr));
	}
	// cells $procdff$6940 $procmux$6767 $procmux$6251
	if (posedge_p_clk) {
		p_qo_5b_3_5d_.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_9_5c_qo_5b_3_5d__5b_1_3a_0_5d_ : p_qo_5b_3_5d_.curr));
	}
	// cells $procdff$6939 $procmux$6773 $procmux$6257
	if (posedge_p_clk) {
		p_qo_5b_2_5d_.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_9_5c_qo_5b_2_5d__5b_1_3a_0_5d_ : p_qo_5b_2_5d_.curr));
	}
	// cells $procdff$6938 $procmux$6779 $procmux$6263
	if (posedge_p_clk) {
		p_qo_5b_1_5d_.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_9_5c_qo_5b_1_5d__5b_1_3a_0_5d_ : p_qo_5b_1_5d_.curr));
	}
	// cells $procdff$6937 $procmux$6785 $procmux$6269
	if (posedge_p_clk) {
		p_qo_5b_0_5d_.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_9_5c_qo_5b_0_5d__5b_1_3a_0_5d_ : p_qo_5b_0_5d_.curr));
	}
	// cells $procdff$6921 $procmux$6620 $procmux$6059 $procmux$1810 $procmux$1493
	if (posedge_p_clk) {
		p_transferbyte.next = (p_rst ? value<8>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? p_transferbyte.curr : (i_logic__and_24_receiver_2e_v_3a_103_24_252__Y ? i_3_5c_bytezero_5b_7_3a_0_5d_ : p_transferbyte.curr)) : p_transferbyte.curr));
	}
	// cells $procdff$6920 $procmux$6623 $procmux$6065 $procmux$1891 $procmux$1661 $procmux$1557
	if (posedge_p_clk) {
		p_emitbyte.next = (p_rst ? value<8>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? p_emitbyte.curr : (p_rone.curr ? (i_logic__or_24_receiver_2e_v_3a_100_24_250__Y ? p_byteone.curr : p_emitbyte.curr) : p_emitbyte.curr)) : p_emitbyte.curr));
	}
	// cells $procdff$6919 $procmux$6626 $procmux$6293 $procmux$2566 $procmux$2243
	if (posedge_p_clk) {
		p_grantbyte.next = (p_rst ? value<8>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_209__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_213__Y ? i_shiftx_24_receiver_2e_v_3a_91_24_220__Y : p_grantbyte.curr) : p_grantbyte.curr) : p_grantbyte.curr));
	}
	// cells $procdff$6918 $procmux$6614 $procmux$6437 $procmux$3697 $procmux$3413 $procmux$3119
	if (posedge_p_clk) {
		p_enqid2.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_176__Y ? p_enqid2.curr : (i_eq_24_receiver_2e_v_3a_78_24_183__Y ? p_enqid2.curr : i_3_5c_nextid_5b_31_3a_0_5d_)) : p_enqid2.curr) : p_enqid2.curr));
	}
	// cells $procdff$6917 $procmux$6617 $procmux$6443 $procmux$3706 $procmux$3425 $procmux$3134
	if (posedge_p_clk) {
		p_enqowner2.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_176__Y ? p_enqowner2.curr : (i_eq_24_receiver_2e_v_3a_78_24_183__Y ? p_enqowner2.curr : i_8_5c_releaseowner_5b_1_3a_0_5d_)) : p_enqowner2.curr) : p_enqowner2.curr));
	}
	// cells $procdff$6916 $procmux$6629 $procmux$6071 $procmux$1900 $procmux$1673 $procmux$1617
	if (posedge_p_clk) {
		p_blockid.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? p_blockid.curr : (p_rone.curr ? (i_logic__or_24_receiver_2e_v_3a_100_24_250__Y ? p_blockid.curr : p_idone.curr) : p_blockid.curr)) : p_blockid.curr));
	}
	// cells $procdff$6915 $procmux$6632 $procmux$6077 $procmux$1765 $procmux$1397
	if (posedge_p_clk) {
		p_callbackid.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? p_callbackid.curr : (i_4_5c_evemit_5b_0_3a_0_5d_ ? i_4_5c_emitid_5b_31_3a_0_5d_ : p_callbackid.curr)) : p_callbackid.curr));
	}
	// cells $procdff$6914 $procmux$6635 $procmux$6083 $procmux$1819 $procmux$1505
	if (posedge_p_clk) {
		p_transferid.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? p_transferid.curr : (i_logic__and_24_receiver_2e_v_3a_103_24_252__Y ? i_3_5c_idzero_5b_31_3a_0_5d_ : p_transferid.curr)) : p_transferid.curr));
	}
	// cells $procdff$6913 $procmux$6638 $procmux$6089 $procmux$1909
	if (posedge_p_clk) {
		p_emitid.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? p_emitid.curr : i_4_5c_emitid_5b_31_3a_0_5d_) : p_emitid.curr));
	}
	// cells $procdff$6912 $procmux$6641 $procmux$6299 $procmux$2575 $procmux$2255
	if (posedge_p_clk) {
		p_grantid.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_209__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_213__Y ? i_6_5c_qi_5b_0_5d__5b_31_3a_0_5d_ : p_grantid.curr) : p_grantid.curr) : p_grantid.curr));
	}
	// cells $procdff$6911 $procmux$6644 $procmux$6305 $procmux$2710
	if (posedge_p_clk) {
		p_attemptid.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_209__Y ? i_6_5c_qi_5b_0_5d__5b_31_3a_0_5d_ : p_attemptid.curr) : p_attemptid.curr));
	}
	// cells $procdff$6910 $procmux$6647 $procmux$6449 $procmux$3715 $procmux$3437 $procmux$3089
	if (posedge_p_clk) {
		p_enqid.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_176__Y ? i_3_5c_enqid_5b_31_3a_0_5d_ : (i_eq_24_receiver_2e_v_3a_78_24_183__Y ? i_3_5c_nextid_5b_31_3a_0_5d_ : i_3_5c_enqid_5b_31_3a_0_5d_)) : i_3_5c_enqid_5b_31_3a_0_5d_) : p_enqid.curr));
	}
	// cells $procdff$6909 $procmux$6650 $procmux$6095 $procmux$1918 $procmux$1697 $procmux$1632
	if (posedge_p_clk) {
		p_blockowner.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? p_blockowner.curr : (p_rone.curr ? (i_logic__or_24_receiver_2e_v_3a_100_24_250__Y ? p_blockowner.curr : p_ownerone.curr) : p_blockowner.curr)) : p_blockowner.curr));
	}
	// cells $procdff$6908 $procmux$6653 $procmux$6101 $procmux$1774 $procmux$1409
	if (posedge_p_clk) {
		p_callbackowner.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? p_callbackowner.curr : (i_4_5c_evemit_5b_0_3a_0_5d_ ? i_4_5c_emitowner_5b_1_3a_0_5d_ : p_callbackowner.curr)) : p_callbackowner.curr));
	}
	// cells $procdff$6907 $procmux$6656 $procmux$6107 $procmux$1828 $procmux$1517
	if (posedge_p_clk) {
		p_transferowner.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? p_transferowner.curr : (i_logic__and_24_receiver_2e_v_3a_103_24_252__Y ? i_3_5c_ownerzero_5b_1_3a_0_5d_ : p_transferowner.curr)) : p_transferowner.curr));
	}
	// cells $procdff$6906 $procmux$6659 $procmux$6113 $procmux$1927
	if (posedge_p_clk) {
		p_emitowner.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? p_emitowner.curr : i_4_5c_emitowner_5b_1_3a_0_5d_) : p_emitowner.curr));
	}
	// cells $procdff$6905 $procmux$6662 $procmux$6311 $procmux$2584 $procmux$2267
	if (posedge_p_clk) {
		p_grantowner.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_209__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_213__Y ? i_6_5c_qo_5b_0_5d__5b_1_3a_0_5d_ : p_grantowner.curr) : p_grantowner.curr) : p_grantowner.curr));
	}
	// cells $procdff$6904 $procmux$6665 $procmux$6317 $procmux$2719
	if (posedge_p_clk) {
		p_attemptowner.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_209__Y ? i_6_5c_qo_5b_0_5d__5b_1_3a_0_5d_ : p_attemptowner.curr) : p_attemptowner.curr));
	}
	// cells $procdff$6903 $procmux$6668 $procmux$6455 $procmux$3724 $procmux$3449 $procmux$3104
	if (posedge_p_clk) {
		p_enqowner.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_176__Y ? i_3_5c_enqowner_5b_1_3a_0_5d_ : (i_eq_24_receiver_2e_v_3a_78_24_183__Y ? i_8_5c_releaseowner_5b_1_3a_0_5d_ : i_3_5c_enqowner_5b_1_3a_0_5d_)) : i_3_5c_enqowner_5b_1_3a_0_5d_) : p_enqowner.curr));
	}
	// cells $procdff$6902 $procmux$6671 $procmux$6119 $procmux$1936
	if (posedge_p_clk) {
		p_evblock.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? value<1>{0u} : i_4_5c_evblock_5b_0_3a_0_5d_) : p_evblock.curr));
	}
	// cells $procdff$6901 $procmux$6674 $procmux$6125 $procmux$1783 $procmux$1421
	if (posedge_p_clk) {
		p_evcallback.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? value<1>{0u} : (i_4_5c_evemit_5b_0_3a_0_5d_ ? value<1>{0x1u} : value<1>{0u})) : p_evcallback.curr));
	}
	// cells $procdff$6900 $procmux$6677 $procmux$6131 $procmux$1837 $procmux$1529
	if (posedge_p_clk) {
		p_evtransfer.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_103_24_252__Y ? value<1>{0x1u} : value<1>{0u})) : p_evtransfer.curr));
	}
	// cells $procdff$6899 $procmux$6680 $procmux$6137 $procmux$1945
	if (posedge_p_clk) {
		p_evemit.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? value<1>{0u} : i_4_5c_evemit_5b_0_3a_0_5d_) : p_evemit.curr));
	}
	// cells $procdff$6898 $procmux$6683 $procmux$6323 $procmux$2593 $procmux$2279
	if (posedge_p_clk) {
		p_evgrant.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_209__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_213__Y ? value<1>{0x1u} : value<1>{0u}) : value<1>{0u}) : p_evgrant.curr));
	}
	// cells $procdff$6897 $procmux$6686 $procmux$6329 $procmux$2728
	if (posedge_p_clk) {
		p_evattempt.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_209__Y ? value<1>{0x1u} : value<1>{0u}) : p_evattempt.curr));
	}
	// cells $procdff$6896 $procmux$6689 $procmux$6461 $procmux$3733 $procmux$3461 $add$receiver.v:80$184
	if (posedge_p_clk) {
		p_evenq.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_176__Y ? i_3_5c_evenq_5b_1_3a_0_5d_ : add_uu<2>(i_3_5c_evenq_5b_1_3a_0_5d_, value<1>{0x1u})) : i_3_5c_evenq_5b_1_3a_0_5d_) : p_evenq.curr));
	}
	// cells $procdff$6895 $procmux$6692 $procmux$6335 $procmux$2602 $procmux$2291 $shift$receiver.v:93$227 $shiftx$receiver.v:93$225
	if (posedge_p_clk) {
		p_evcancel.next = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_209__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_213__Y ? shift_us<4>(shiftx_uu<1>(i_7_5c_enabled_5b_3_3a_0_5d_, i_6_5c_qo_5b_0_5d__5b_1_3a_0_5d_), i_neg_24_receiver_2e_v_3a_93_24_226__Y) : value<4>{0u}) : value<4>{0u}) : p_evcancel.curr));
	}
	// cells $procdff$6894 $procmux$6695 $procmux$6515
	if (posedge_p_clk) {
		p_evexpire.next = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_3_5c_evexpire_5b_3_3a_0_5d_ : p_evexpire.curr));
	}
	// cells $procdff$6893 $procmux$6698
	if (posedge_p_clk) {
		p_evwu.next = (p_rst ? value<4>{0u} : i_2_5c_evwu_5b_3_3a_0_5d_);
	}
	// cells $procdff$6892 $procmux$6701 $procmux$6341 $procmux$2611 $procmux$1967
	if (posedge_p_clk) {
		p_failowner.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_209__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_213__Y ? p_failowner.curr : i_6_5c_qo_5b_0_5d__5b_1_3a_0_5d_) : p_failowner.curr) : p_failowner.curr));
	}
	// cells $procdff$6891 $procmux$6590 $procmux$6017 $procmux$6585 $logic_or$receiver.v:54$72 $logic_or$receiver.v:54$70 $logic_or$receiver.v:54$68 $logic_or$receiver.v:54$66 $logic_or$receiver.v:54$64 $logic_or$receiver.v:54$62 $logic_or$receiver.v:54$60 $logic_or$receiver.v:54$58 $logic_or$receiver.v:54$56 $logic_or$receiver.v:54$54 $logic_or$receiver.v:54$52 $logic_or$receiver.v:54$48 $lt$receiver.v:54$46 $gt$receiver.v:54$47 $logic_and$receiver.v:54$51 $ne$receiver.v:54$49 $ne$receiver.v:54$50 $lt$receiver.v:54$53 $gt$receiver.v:54$55 $eq$receiver.v:54$57 $eq$receiver.v:54$59 $gt$receiver.v:54$61 $ge$receiver.v:54$63 $ge$receiver.v:54$65 $ge$receiver.v:54$67 $ge$receiver.v:54$69 $ge$receiver.v:54$71
	if (posedge_p_clk) {
		p_fault.next = (p_rst ? value<31>{0u}.concat((logic_or<1>(logic_or<1>(logic_or<1>(logic_or<1>(logic_or<1>(logic_or<1>(logic_or<1>(logic_or<1>(logic_or<1>(logic_or<1>(logic_or<1>(logic_or<1>(lt_uu<1>(p_cfgp, value<2>{0x2u}), gt_uu<1>(p_cfgp, value<5>{0x11u})), logic_and<1>(ne_uu<1>(p_cfgr, value<3>{0x5u}), ne_uu<1>(p_cfgr, value<3>{0x7u}))), lt_uu<1>(p_cfgf, value<6>{0x28u})), gt_uu<1>(p_cfgf, value<10>{0x3b8u})), logic_not<1>(p_cfgk)), logic_not<1>(p_cfgperiod)), gt_uu<1>(p_cfgperiod, value<7>{0x44u})), ge_uu<1>(p_cfgphi, p_cfgperiod)), ge_uu<1>(p_cfgcp, p_cfgp)), ge_uu<1>(p_cfgrp, p_cfgr)), ge_uu<1>(p_cfgfp, p_cfgf)), ge_uu<1>(p_cfgpp, p_cfgperiod)) ? value<1>{0x1u} : value<1>{0u})).val() : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_13_5c_fault_5b_31_3a_0_5d_.slice<31,7>().concat(i_23_5c_fault_5b_31_3a_0_5d_.slice<6,0>()).val() : p_fault.curr));
	}
	// cells $procdff$6890 $procmux$6704 $procmux$6347 $procmux$2620 $procmux$1955
	if (posedge_p_clk) {
		p_failid.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_209__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_213__Y ? p_failid.curr : i_6_5c_qi_5b_0_5d__5b_31_3a_0_5d_) : p_failid.curr) : p_failid.curr));
	}
	// cells $procdff$6889 $procmux$6707 $procmux$6353 $procmux$2629 $procmux$1979
	if (posedge_p_clk) {
		p_failtick.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_209__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_213__Y ? p_failtick.curr : p_tick.curr) : p_failtick.curr) : p_failtick.curr));
	}
	// cells $procdff$6888 $procmux$6710 $procmux$6359
	if (posedge_p_clk) {
		p_failed.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_3_5c_failed_5b_0_3a_0_5d_ : p_failed.curr));
	}
	// cells $procdff$6887 $procmux$6713 $procmux$6143 $procmux$1846 $procmux$1445
	if (posedge_p_clk) {
		p_byteone.next = (p_rst ? value<8>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? p_byteone.curr : (i_logic__and_24_receiver_2e_v_3a_103_24_252__Y ? i_3_5c_bytezero_5b_7_3a_0_5d_ : p_byteone.curr)) : p_byteone.curr));
	}
	// cells $procdff$6886 $procmux$6716 $procmux$6365
	if (posedge_p_clk) {
		p_bytezero.next = (p_rst ? value<8>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_3_5c_bytezero_5b_7_3a_0_5d_ : p_bytezero.curr));
	}
	// cells $procdff$6885 $procmux$6719 $procmux$6149 $procmux$1855 $procmux$1457
	if (posedge_p_clk) {
		p_idone.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? p_idone.curr : (i_logic__and_24_receiver_2e_v_3a_103_24_252__Y ? i_3_5c_idzero_5b_31_3a_0_5d_ : p_idone.curr)) : p_idone.curr));
	}
	// cells $procdff$6884 $procmux$6722 $procmux$6371
	if (posedge_p_clk) {
		p_idzero.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_3_5c_idzero_5b_31_3a_0_5d_ : p_idzero.curr));
	}
	// cells $procdff$6883 $procmux$6725 $procmux$6155
	if (posedge_p_clk) {
		p_ownerone.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_3_5c_ownerone_5b_1_3a_0_5d_ : p_ownerone.curr));
	}
	// cells $procdff$6882 $procmux$6728 $procmux$6377
	if (posedge_p_clk) {
		p_ownerzero.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_3_5c_ownerzero_5b_1_3a_0_5d_ : p_ownerzero.curr));
	}
	// cells $procdff$6881 $procmux$6731 $procmux$6161
	if (posedge_p_clk) {
		p_rone.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_3_5c_rone_5b_0_3a_0_5d_ : p_rone.curr));
	}
	// cells $procdff$6880 $procmux$6734 $procmux$6167
	if (posedge_p_clk) {
		p_rzero.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_5_5c_rzero_5b_0_3a_0_5d_ : p_rzero.curr));
	}
	// cells $procdff$6879 $procmux$6788 $procmux$6173
	if (posedge_p_clk) {
		p_outstanding.next = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_7_5c_outstanding_5b_15_3a_0_5d_ : p_outstanding.curr));
	}
	// cells $procdff$6878 $procmux$6791 $procmux$6383
	if (posedge_p_clk) {
		p_qlen.next = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_7_5c_qlen_5b_3_3a_0_5d_ : p_qlen.curr));
	}
	// cells $procdff$6877 $procmux$6794
	if (posedge_p_clk) {
		p_bytes.next = (p_rst ? value<32>{0u} : i_2_5c_bytes_5b_31_3a_0_5d_);
	}
	// cells $procdff$6876 $procmux$6797 $procmux$6389 $procmux$2692 $procmux$2363 $or$receiver.v:93$244 $and$receiver.v:93$241 $not$receiver.v:93$240 $shift$receiver.v:93$239 $shift$receiver.v:93$243
	if (posedge_p_clk) {
		p_counts.next = (p_rst ? value<64>{0u,0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_209__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_213__Y ? or_uu<64>(and_uu<64>(i_7_5c_counts_5b_63_3a_0_5d_, not_u<64>(shift_us<64>(value<16>{0xffffu}, i_neg_24_receiver_2e_v_3a_93_24_238__Y))), shift_us<64>(value<1>{0u}, i_neg_24_receiver_2e_v_3a_93_24_238__Y)) : i_7_5c_counts_5b_63_3a_0_5d_) : i_7_5c_counts_5b_63_3a_0_5d_) : p_counts.curr));
	}
	// cells $procdff$6875 $procmux$6800 $procmux$6395 $procmux$2701 $procmux$2375
	if (posedge_p_clk) {
		p_enabled.next = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_209__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_213__Y ? i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7156.slice<3,0>().val() : i_7_5c_enabled_5b_3_3a_0_5d_) : i_7_5c_enabled_5b_3_3a_0_5d_) : p_enabled.curr));
	}
	// cells $procdff$6874 $procmux$6803 $procmux$6521
	if (posedge_p_clk) {
		p_valid.next = (p_rst ? value<4>{0xfu} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_3_5c_valid_5b_3_3a_0_5d_ : p_valid.curr));
	}
	// cells $procdff$6873 $procmux$6806 $procmux$5987 $procmux$6570 $eq$receiver.v:127$340
	if (posedge_p_clk) {
		p_pp.next = (p_rst ? p_cfgpp : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (eq_uu<1>(i_add_24_receiver_2e_v_3a_127_24_339__Y, value<1>{0u}.concat(p_cfgperiod).val()) ? value<16>{0u} : i_add_24_receiver_2e_v_3a_127_24_339__Y.slice<15,0>().val()) : p_pp.curr));
	}
	// cells $procdff$6872 $procmux$6809 $procmux$5993 $procmux$350 $eq$receiver.v:126$337
	if (posedge_p_clk) {
		p_fp.next = (p_rst ? p_cfgfp : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (eq_uu<1>(i_add_24_receiver_2e_v_3a_126_24_336__Y, value<1>{0u}.concat(p_cfgf).val()) ? value<16>{0u} : i_add_24_receiver_2e_v_3a_126_24_336__Y.slice<15,0>().val()) : p_fp.curr));
	}
	// cells $procdff$6871 $procmux$6812 $procmux$5999 $procmux$359 $eq$receiver.v:125$334
	if (posedge_p_clk) {
		p_rp.next = (p_rst ? p_cfgrp : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (eq_uu<1>(i_add_24_receiver_2e_v_3a_125_24_333__Y, value<1>{0u}.concat(p_cfgr).val()) ? value<16>{0u} : i_add_24_receiver_2e_v_3a_125_24_333__Y.slice<15,0>().val()) : p_rp.curr));
	}
	// cells $procdff$6870 $procmux$6815 $procmux$6005 $procmux$368 $eq$receiver.v:124$331
	if (posedge_p_clk) {
		p_cp.next = (p_rst ? p_cfgcp : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (eq_uu<1>(i_add_24_receiver_2e_v_3a_124_24_330__Y, value<1>{0u}.concat(p_cfgp).val()) ? value<16>{0u} : i_add_24_receiver_2e_v_3a_124_24_330__Y.slice<15,0>().val()) : p_cp.curr));
	}
	// cells $procdff$6869 $procmux$6818 $procmux$6467
	if (posedge_p_clk) {
		p_nextid.next = (p_rst ? value<32>{0x1u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_5_5c_nextid_5b_31_3a_0_5d_ : p_nextid.curr));
	}
	// cells $procdff$6868 $procmux$6821 $procmux$6011 $add$receiver.v:123$329
	if (posedge_p_clk) {
		p_tick.next = (p_rst ? p_cfgstart : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? add_uu<32>(p_tick.curr, value<1>{0x1u}) : p_tick.curr));
	}
	// connection
	p_qowners = p_qo_5b_7_5d_.curr.concat(p_qo_5b_6_5d_.curr).concat(p_qo_5b_5_5d_.curr).concat(p_qo_5b_4_5d_.curr).concat(p_qo_5b_3_5d_.curr).concat(p_qo_5b_2_5d_.curr).concat(p_qo_5b_1_5d_.curr).concat(p_qo_5b_0_5d_.curr).val();
	// connection
	p_qids = p_qi_5b_7_5d_.curr.concat(p_qi_5b_6_5d_.curr).concat(p_qi_5b_5_5d_.curr).concat(p_qi_5b_4_5d_.curr).concat(p_qi_5b_3_5d_.curr).concat(p_qi_5b_2_5d_.curr).concat(p_qi_5b_1_5d_.curr).concat(p_qi_5b_0_5d_.curr).val();
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
			{ "src", "receiver.v:3.1-130.10" },
		}), std::move(cell_attrs));
	}
	if (items) {
		items->add(path, "11\\fault[31:0]", "src\000sreceiver.v:42.2-129.5\000", i_11_5c_fault_5b_31_3a_0_5d_, 0, debug_item::GENERATED|debug_item::DRIVEN_COMB);
		items->add(path, "14\\fault[31:0]", "src\000sreceiver.v:42.2-129.5\000", i_14_5c_fault_5b_31_3a_0_5d_, 0, debug_item::GENERATED|debug_item::DRIVEN_COMB);
		items->add(path, "procmux$5693_Y", "", i_procmux_24_5693__Y, 0, debug_item::GENERATED|debug_item::DRIVEN_COMB);
		items->add(path, "attemptid", "src\000sreceiver.v:30.26-30.35\000", p_attemptid, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "attemptowner", "src\000sreceiver.v:29.28-29.40\000", p_attemptowner, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "blockid", "src\000sreceiver.v:30.73-30.80\000", p_blockid, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "blockowner", "src\000sreceiver.v:29.90-29.100\000", p_blockowner, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "byteone", "src\000sreceiver.v:22.28-22.35\000", p_byteone, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "bytes", "src\000sreceiver.v:14.20-14.25\000", p_bytes, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "bytezero", "src\000sreceiver.v:22.19-22.27\000", p_bytezero, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "callbackid", "src\000sreceiver.v:30.62-30.72\000", p_callbackid, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "callbackowner", "src\000sreceiver.v:29.76-29.89\000", p_callbackowner, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "cfgcp", "src\000sreceiver.v:7.15-7.20\000", p_cfgcp, 0, debug_item::INPUT|debug_item::UNDRIVEN);
		items->add(path, "cfgf", "src\000sreceiver.v:5.25-5.29\000", p_cfgf, 0, debug_item::INPUT|debug_item::UNDRIVEN);
		items->add(path, "cfgfp", "src\000sreceiver.v:7.27-7.32\000", p_cfgfp, 0, debug_item::INPUT|debug_item::UNDRIVEN);
		items->add(path, "cfgk", "src\000sreceiver.v:5.30-5.34\000", p_cfgk, 0, debug_item::INPUT|debug_item::UNDRIVEN);
		items->add(path, "cfgp", "src\000sreceiver.v:5.15-5.19\000", p_cfgp, 0, debug_item::INPUT|debug_item::UNDRIVEN);
		items->add(path, "cfgperiod", "src\000sreceiver.v:5.35-5.44\000", p_cfgperiod, 0, debug_item::INPUT|debug_item::UNDRIVEN);
		items->add(path, "cfgphi", "src\000sreceiver.v:5.45-5.51\000", p_cfgphi, 0, debug_item::INPUT|debug_item::UNDRIVEN);
		items->add(path, "cfgpp", "src\000sreceiver.v:7.33-7.38\000", p_cfgpp, 0, debug_item::INPUT|debug_item::UNDRIVEN);
		items->add(path, "cfgr", "src\000sreceiver.v:5.20-5.24\000", p_cfgr, 0, debug_item::INPUT|debug_item::UNDRIVEN);
		items->add(path, "cfgrp", "src\000sreceiver.v:7.21-7.26\000", p_cfgrp, 0, debug_item::INPUT|debug_item::UNDRIVEN);
		items->add(path, "cfgstart", "src\000sreceiver.v:6.15-6.23\000", p_cfgstart, 0, debug_item::INPUT|debug_item::UNDRIVEN);
		items->add(path, "clk", "src\000sreceiver.v:4.8-4.11\000", p_clk, 0, debug_item::INPUT|debug_item::UNDRIVEN);
		items->add(path, "counts", "src\000sreceiver.v:13.20-13.26\000", p_counts, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "cp", "src\000sreceiver.v:11.20-11.22\000", p_cp, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "emitbyte", "src\000sreceiver.v:33.29-33.37\000", p_emitbyte, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "emitid", "src\000sreceiver.v:30.44-30.50\000", p_emitid, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "emitowner", "src\000sreceiver.v:29.52-29.61\000", p_emitowner, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "enabled", "src\000sreceiver.v:12.25-12.32\000", p_enabled, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "enqid", "src\000sreceiver.v:30.20-30.25\000", p_enqid, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "enqid2", "src\000sreceiver.v:32.20-32.26\000", p_enqid2, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "enqowner", "src\000sreceiver.v:29.19-29.27\000", p_enqowner, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "enqowner2", "src\000sreceiver.v:31.19-31.28\000", p_enqowner2, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "evattempt", "src\000sreceiver.v:28.13-28.22\000", p_evattempt, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "evblock", "src\000sreceiver.v:28.60-28.67\000", p_evblock, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "evcallback", "src\000sreceiver.v:28.49-28.59\000", p_evcallback, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "evcancel", "src\000sreceiver.v:26.33-26.41\000", p_evcancel, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "evemit", "src\000sreceiver.v:28.31-28.37\000", p_evemit, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "evenq", "src\000sreceiver.v:27.19-27.24\000", p_evenq, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "evexpire", "src\000sreceiver.v:26.24-26.32\000", p_evexpire, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "evgrant", "src\000sreceiver.v:28.23-28.30\000", p_evgrant, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "evtransfer", "src\000sreceiver.v:28.38-28.48\000", p_evtransfer, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "evwu", "src\000sreceiver.v:26.19-26.23\000", p_evwu, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "failed", "src\000sreceiver.v:23.13-23.19\000", p_failed, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "failid", "src\000sreceiver.v:24.29-24.35\000", p_failid, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "failowner", "src\000sreceiver.v:25.19-25.28\000", p_failowner, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "failtick", "src\000sreceiver.v:24.20-24.28\000", p_failtick, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "fault", "src\000sreceiver.v:24.36-24.41\000", p_fault, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "fp", "src\000sreceiver.v:11.26-11.28\000", p_fp, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "grantbyte", "src\000sreceiver.v:33.19-33.28\000", p_grantbyte, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "grantid", "src\000sreceiver.v:30.36-30.43\000", p_grantid, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "grantowner", "src\000sreceiver.v:29.41-29.51\000", p_grantowner, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "idone", "src\000sreceiver.v:21.27-21.32\000", p_idone, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "idzero", "src\000sreceiver.v:21.20-21.26\000", p_idzero, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "nextid", "src\000sreceiver.v:10.25-10.31\000", p_nextid, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "outstanding", "src\000sreceiver.v:18.20-18.31\000", p_outstanding, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "ownerone", "src\000sreceiver.v:20.29-20.37\000", p_ownerone, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "ownerzero", "src\000sreceiver.v:20.19-20.28\000", p_ownerzero, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "pp", "src\000sreceiver.v:11.29-11.31\000", p_pp, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "qi[0]", "src\000sreceiver.v:35.32-35.34\000", p_qi_5b_0_5d_, 0, debug_item::DRIVEN_SYNC);
		items->add(path, "qi[1]", "src\000sreceiver.v:35.32-35.34\000", p_qi_5b_1_5d_, 0, debug_item::DRIVEN_SYNC);
		items->add(path, "qi[2]", "src\000sreceiver.v:35.32-35.34\000", p_qi_5b_2_5d_, 0, debug_item::DRIVEN_SYNC);
		items->add(path, "qi[3]", "src\000sreceiver.v:35.32-35.34\000", p_qi_5b_3_5d_, 0, debug_item::DRIVEN_SYNC);
		items->add(path, "qi[4]", "src\000sreceiver.v:35.32-35.34\000", p_qi_5b_4_5d_, 0, debug_item::DRIVEN_SYNC);
		items->add(path, "qi[5]", "src\000sreceiver.v:35.32-35.34\000", p_qi_5b_5_5d_, 0, debug_item::DRIVEN_SYNC);
		items->add(path, "qi[6]", "src\000sreceiver.v:35.32-35.34\000", p_qi_5b_6_5d_, 0, debug_item::DRIVEN_SYNC);
		items->add(path, "qi[7]", "src\000sreceiver.v:35.32-35.34\000", p_qi_5b_7_5d_, 0, debug_item::DRIVEN_SYNC);
		items->add(path, "qids", "src\000sreceiver.v:17.17-17.21\000", p_qids, 0, debug_item::OUTPUT|debug_item::DRIVEN_COMB);
		items->add(path, "qlen", "src\000sreceiver.v:15.19-15.23\000", p_qlen, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "qo[0]", "src\000sreceiver.v:35.12-35.14\000", p_qo_5b_0_5d_, 0, debug_item::DRIVEN_SYNC);
		items->add(path, "qo[1]", "src\000sreceiver.v:35.12-35.14\000", p_qo_5b_1_5d_, 0, debug_item::DRIVEN_SYNC);
		items->add(path, "qo[2]", "src\000sreceiver.v:35.12-35.14\000", p_qo_5b_2_5d_, 0, debug_item::DRIVEN_SYNC);
		items->add(path, "qo[3]", "src\000sreceiver.v:35.12-35.14\000", p_qo_5b_3_5d_, 0, debug_item::DRIVEN_SYNC);
		items->add(path, "qo[4]", "src\000sreceiver.v:35.12-35.14\000", p_qo_5b_4_5d_, 0, debug_item::DRIVEN_SYNC);
		items->add(path, "qo[5]", "src\000sreceiver.v:35.12-35.14\000", p_qo_5b_5_5d_, 0, debug_item::DRIVEN_SYNC);
		items->add(path, "qo[6]", "src\000sreceiver.v:35.12-35.14\000", p_qo_5b_6_5d_, 0, debug_item::DRIVEN_SYNC);
		items->add(path, "qo[7]", "src\000sreceiver.v:35.12-35.14\000", p_qo_5b_7_5d_, 0, debug_item::DRIVEN_SYNC);
		items->add(path, "qowners", "src\000sreceiver.v:16.16-16.23\000", p_qowners, 0, debug_item::OUTPUT|debug_item::DRIVEN_COMB);
		items->add(path, "rone", "src\000sreceiver.v:19.19-19.23\000", p_rone, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "rp", "src\000sreceiver.v:11.23-11.25\000", p_rp, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "rst", "src\000sreceiver.v:4.12-4.15\000", p_rst, 0, debug_item::INPUT|debug_item::UNDRIVEN);
		items->add(path, "rzero", "src\000sreceiver.v:19.13-19.18\000", p_rzero, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "tick", "src\000sreceiver.v:10.20-10.24\000", p_tick, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "transferbyte", "src\000sreceiver.v:33.38-33.50\000", p_transferbyte, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "transferid", "src\000sreceiver.v:30.51-30.61\000", p_transferid, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "transferowner", "src\000sreceiver.v:29.62-29.75\000", p_transferowner, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "valid", "src\000sreceiver.v:12.19-12.24\000", p_valid, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "wu", "src\000sreceiver.v:8.14-8.16\000", p_wu, 0, debug_item::INPUT|debug_item::UNDRIVEN);
		items->add(path, "wubytes", "src\000sreceiver.v:9.15-9.22\000", p_wubytes, 0, debug_item::INPUT|debug_item::UNDRIVEN);
	}
}

} // namespace cxxrtl_design

extern "C"
cxxrtl_toplevel cxxrtl_design_create() {
	return new _cxxrtl_toplevel { std::unique_ptr<cxxrtl_design::p_receiver>(new cxxrtl_design::p_receiver) };
}
