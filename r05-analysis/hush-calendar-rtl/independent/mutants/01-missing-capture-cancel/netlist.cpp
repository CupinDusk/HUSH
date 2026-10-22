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
	wire<32> i_procmux_24_5581__Y;
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
		if (i_procmux_24_5581__Y.commit(observer)) changed = true;
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
	value<6> i_add_24_receiver_2e_v_3a_109_24_227__Y;
	value<17> i_add_24_receiver_2e_v_3a_124_24_302__Y;
	value<17> i_add_24_receiver_2e_v_3a_125_24_305__Y;
	value<17> i_add_24_receiver_2e_v_3a_126_24_308__Y;
	value<17> i_add_24_receiver_2e_v_3a_127_24_311__Y;
	value<6> i_add_24_receiver_2e_v_3a_82_24_133__Y;
	value<6> i_add_24_receiver_2e_v_3a_82_24_180__Y;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6830;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6832;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6834;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6836;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6838;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6840;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6842;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6844;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6850;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6854;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6856;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6866;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6874;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6884;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6890;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6898;
	// \src: receiver.v:110.11-110.68
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7013;
	// \src: receiver.v:110.11-110.68
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7014;
	// \src: receiver.v:110.39-110.68
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7015;
	// \src: receiver.v:110.11-110.68
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7017;
	// \src: receiver.v:110.11-110.68
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7018;
	// \src: receiver.v:109.21-109.32
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7020;
	// \src: receiver.v:95.27-95.33
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7021;
	// \src: receiver.v:91.63-91.70
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7023;
	// \src: receiver.v:83.7-83.70
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7024;
	// \src: receiver.v:83.7-83.70
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7025;
	// \src: receiver.v:83.7-83.70
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7028;
	// \src: receiver.v:83.7-83.70
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7029;
	// \src: receiver.v:82.22-82.36
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7031;
	// \src: receiver.v:74.78-74.83
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7034;
	// \src: receiver.v:83.7-83.70
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7035;
	// \src: receiver.v:83.7-83.70
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7036;
	// \src: receiver.v:83.7-83.70
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7039;
	// \src: receiver.v:83.7-83.70
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7040;
	value<2> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7041;
	// \src: receiver.v:82.22-82.36
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7043;
	// \src: receiver.v:65.35-65.53
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7046;
	// \src: receiver.v:65.35-65.53
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7047;
	// \src: receiver.v:65.35-65.53
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7048;
	// \src: receiver.v:65.35-65.53
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7049;
	// \src: receiver.v:109.9-109.39
	value<1> i_eq_24_receiver_2e_v_3a_109_24_229__Y;
	// \src: receiver.v:61.7-61.17
	value<1> i_eq_24_receiver_2e_v_3a_61_24_86__Y;
	// \src: receiver.v:64.10-64.29
	value<1> i_eq_24_receiver_2e_v_3a_64_24_87__Y;
	// \src: receiver.v:64.10-64.29
	value<1> i_eq_24_receiver_2e_v_3a_64_24_91__Y;
	// \src: receiver.v:64.10-64.29
	value<1> i_eq_24_receiver_2e_v_3a_64_24_95__Y;
	// \src: receiver.v:64.10-64.29
	value<1> i_eq_24_receiver_2e_v_3a_64_24_99__Y;
	// \src: receiver.v:65.57-65.76
	value<1> i_eq_24_receiver_2e_v_3a_65_24_102__Y;
	// \src: receiver.v:65.57-65.76
	value<1> i_eq_24_receiver_2e_v_3a_65_24_90__Y;
	// \src: receiver.v:65.57-65.76
	value<1> i_eq_24_receiver_2e_v_3a_65_24_94__Y;
	// \src: receiver.v:65.57-65.76
	value<1> i_eq_24_receiver_2e_v_3a_65_24_98__Y;
	// \src: receiver.v:78.10-78.18
	value<1> i_eq_24_receiver_2e_v_3a_78_24_175__Y;
	// \src: receiver.v:76.9-76.16
	value<1> i_ge_24_receiver_2e_v_3a_76_24_121__Y;
	// \src: receiver.v:76.9-76.16
	value<1> i_ge_24_receiver_2e_v_3a_76_24_168__Y;
	// \src: receiver.v:103.8-103.22
	value<1> i_logic__and_24_receiver_2e_v_3a_103_24_224__Y;
	// \src: receiver.v:55.15-55.34
	value<1> i_logic__and_24_receiver_2e_v_3a_55_24_69__Y;
	// \src: receiver.v:59.8-59.25
	value<1> i_logic__and_24_receiver_2e_v_3a_59_24_82__Y;
	// \src: receiver.v:59.8-59.25
	value<1> i_logic__and_24_receiver_2e_v_3a_59_24_83__Y;
	// \src: receiver.v:59.8-59.25
	value<1> i_logic__and_24_receiver_2e_v_3a_59_24_84__Y;
	// \src: receiver.v:59.8-59.25
	value<1> i_logic__and_24_receiver_2e_v_3a_59_24_85__Y;
	// \src: receiver.v:72.8-72.20
	value<1> i_logic__and_24_receiver_2e_v_3a_72_24_104__Y;
	// \src: receiver.v:73.8-73.32
	value<1> i_logic__and_24_receiver_2e_v_3a_73_24_155__Y;
	// \src: receiver.v:74.8-74.43
	value<1> i_logic__and_24_receiver_2e_v_3a_74_24_161__Y;
	// \src: receiver.v:87.7-87.37
	value<1> i_logic__and_24_receiver_2e_v_3a_87_24_201__Y;
	// \src: receiver.v:100.9-100.23
	value<1> i_logic__or_24_receiver_2e_v_3a_100_24_222__Y;
	// \src: receiver.v:115.8-115.14
	value<1> i_lt_24_receiver_2e_v_3a_115_24_245__Y;
	// \src: receiver.v:115.8-115.14
	value<1> i_lt_24_receiver_2e_v_3a_115_24_250__Y;
	// \src: receiver.v:115.8-115.14
	value<1> i_lt_24_receiver_2e_v_3a_115_24_255__Y;
	// \src: receiver.v:115.8-115.14
	value<1> i_lt_24_receiver_2e_v_3a_115_24_260__Y;
	// \src: receiver.v:115.8-115.14
	value<1> i_lt_24_receiver_2e_v_3a_115_24_265__Y;
	// \src: receiver.v:115.8-115.14
	value<1> i_lt_24_receiver_2e_v_3a_115_24_270__Y;
	// \src: receiver.v:115.8-115.14
	value<1> i_lt_24_receiver_2e_v_3a_115_24_275__Y;
	// \src: receiver.v:115.8-115.14
	value<1> i_lt_24_receiver_2e_v_3a_115_24_280__Y;
	// \src: receiver.v:110.11-110.68
	value<33> i_neg_24_receiver_2e_v_3a_110_24_234__Y;
	// \src: receiver.v:83.7-83.70
	value<33> i_neg_24_receiver_2e_v_3a_83_24_139__Y;
	// \src: receiver.v:83.7-83.70
	value<33> i_neg_24_receiver_2e_v_3a_83_24_186__Y;
	value<1> i_procmux_24_1012__CMP;
	value<1> i_procmux_24_1013__CMP;
	value<1> i_procmux_24_1014__CMP;
	value<1> i_procmux_24_1015__CMP;
	value<1> i_procmux_24_1104__CMP;
	value<1> i_procmux_24_1105__CMP;
	value<1> i_procmux_24_1106__CMP;
	value<1> i_procmux_24_1107__CMP;
	value<1> i_procmux_24_1196__CMP;
	value<1> i_procmux_24_1197__CMP;
	value<1> i_procmux_24_1198__CMP;
	value<1> i_procmux_24_1199__CMP;
	value<1> i_procmux_24_2641__CMP;
	value<1> i_procmux_24_2642__CMP;
	value<1> i_procmux_24_2643__CMP;
	value<1> i_procmux_24_2644__CMP;
	value<1> i_procmux_24_2645__CMP;
	value<1> i_procmux_24_2646__CMP;
	value<1> i_procmux_24_2647__CMP;
	value<1> i_procmux_24_2648__CMP;
	value<1> i_procmux_24_368__CMP;
	value<1> i_procmux_24_369__CMP;
	value<1> i_procmux_24_370__CMP;
	value<1> i_procmux_24_371__CMP;
	value<1> i_procmux_24_3736__CMP;
	value<1> i_procmux_24_3737__CMP;
	value<1> i_procmux_24_3738__CMP;
	value<1> i_procmux_24_3739__CMP;
	value<1> i_procmux_24_3740__CMP;
	value<1> i_procmux_24_3741__CMP;
	value<1> i_procmux_24_3742__CMP;
	value<1> i_procmux_24_3743__CMP;
	value<1> i_procmux_24_460__CMP;
	value<1> i_procmux_24_461__CMP;
	value<1> i_procmux_24_462__CMP;
	value<1> i_procmux_24_463__CMP;
	value<32> i_procmux_24_4725__Y;
	value<32> i_procmux_24_5137__Y;
	value<1> i_procmux_24_552__CMP;
	value<1> i_procmux_24_553__CMP;
	value<1> i_procmux_24_554__CMP;
	value<1> i_procmux_24_555__CMP;
	value<1> i_procmux_24_644__CMP;
	value<1> i_procmux_24_645__CMP;
	value<1> i_procmux_24_646__CMP;
	value<1> i_procmux_24_647__CMP;
	value<1> i_procmux_24_736__CMP;
	value<1> i_procmux_24_737__CMP;
	value<1> i_procmux_24_738__CMP;
	value<1> i_procmux_24_739__CMP;
	value<1> i_procmux_24_828__CMP;
	value<1> i_procmux_24_829__CMP;
	value<1> i_procmux_24_830__CMP;
	value<1> i_procmux_24_831__CMP;
	value<1> i_procmux_24_920__CMP;
	value<1> i_procmux_24_921__CMP;
	value<1> i_procmux_24_922__CMP;
	value<1> i_procmux_24_923__CMP;
	// \src: receiver.v:109.20-109.36
	value<4> i_shiftx_24_receiver_2e_v_3a_109_24_228__Y;
	// \src: receiver.v:82.21-82.40
	value<4> i_shiftx_24_receiver_2e_v_3a_82_24_134__Y;
	// \src: receiver.v:82.21-82.40
	value<4> i_shiftx_24_receiver_2e_v_3a_82_24_181__Y;
	// \src: receiver.v:89.14-89.21
	value<1> i_shiftx_24_receiver_2e_v_3a_89_24_203__Y;
	// \src: receiver.v:91.62-91.74
	value<8> i_shiftx_24_receiver_2e_v_3a_91_24_208__Y;
	// connection
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7043.slice<31,5>() = value<27>{0u};
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
	i_procmux_24_5137__Y.slice<31,2>() = p_fault.curr.slice<31,2>().val();
	// \src: receiver.v:59.8-59.25
	// cell $logic_and$receiver.v:59$85
	i_logic__and_24_receiver_2e_v_3a_59_24_85__Y = logic_and<1>(p_wu.slice<3>().val(), p_valid.curr.slice<3>().val());
	// \src: receiver.v:59.8-59.25
	// cell $logic_and$receiver.v:59$84
	i_logic__and_24_receiver_2e_v_3a_59_24_84__Y = logic_and<1>(p_wu.slice<2>().val(), p_valid.curr.slice<2>().val());
	// \src: receiver.v:59.8-59.25
	// cell $logic_and$receiver.v:59$83
	i_logic__and_24_receiver_2e_v_3a_59_24_83__Y = logic_and<1>(p_wu.slice<1>().val(), p_valid.curr.slice<1>().val());
	// \src: receiver.v:59.8-59.25
	// cell $logic_and$receiver.v:59$82
	i_logic__and_24_receiver_2e_v_3a_59_24_82__Y = logic_and<1>(p_wu.slice<0>().val(), p_valid.curr.slice<0>().val());
	// \src: receiver.v:61.7-61.17
	// cell $eq$receiver.v:61$86
	i_eq_24_receiver_2e_v_3a_61_24_86__Y = eq_uu<1>(p_pp.curr, p_cfgphi);
	// \src: receiver.v:76.9-76.16
	// cell $ge$receiver.v:76$121
	i_ge_24_receiver_2e_v_3a_76_24_121__Y = ge_uu<1>(p_qlen.curr, value<4>{0x8u});
	// \src: receiver.v:73.28-73.32
	// cell $lt$receiver.v:73$154
	i_logic__and_24_receiver_2e_v_3a_72_24_104__Y = lt_uu<1>(p_fp.curr, value<3>{0x4u});
	// cells $logic_and$receiver.v:55$69 $logic_not$receiver.v:55$67 $eq$receiver.v:55$68
	i_logic__and_24_receiver_2e_v_3a_55_24_69__Y = logic_and<1>(logic_not<1>(p_failed.curr), logic_not<1>(p_fault.curr));
	// cells $procmux$5755 $procmux$5752 $procmux$5750
	i_6_5c_enabled_5b_3_3a_3_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_logic__and_24_receiver_2e_v_3a_59_24_85__Y ? value<1>{0x1u} : p_enabled.curr.slice<3>().val()) : value<1>{0u}));
	// cells $procmux$5746 $procmux$5743 $procmux$5741
	i_6_5c_counts_5b_63_3a_48_5d_ = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_logic__and_24_receiver_2e_v_3a_59_24_85__Y ? p_cfgk : p_counts.curr.slice<63,48>().val()) : value<16>{0u}));
	// cells $procmux$5791 $procmux$5788 $procmux$5786
	i_5_5c_enabled_5b_2_3a_2_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_logic__and_24_receiver_2e_v_3a_59_24_84__Y ? value<1>{0x1u} : p_enabled.curr.slice<2>().val()) : value<1>{0u}));
	// cells $procmux$5782 $procmux$5779 $procmux$5777
	i_5_5c_counts_5b_47_3a_32_5d_ = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_logic__and_24_receiver_2e_v_3a_59_24_84__Y ? p_cfgk : p_counts.curr.slice<47,32>().val()) : value<16>{0u}));
	// cells $procmux$5827 $procmux$5824 $procmux$5822
	i_4_5c_enabled_5b_1_3a_1_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_logic__and_24_receiver_2e_v_3a_59_24_83__Y ? value<1>{0x1u} : p_enabled.curr.slice<1>().val()) : value<1>{0u}));
	// cells $procmux$5818 $procmux$5815 $procmux$5813
	i_4_5c_counts_5b_31_3a_16_5d_ = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_logic__and_24_receiver_2e_v_3a_59_24_83__Y ? p_cfgk : p_counts.curr.slice<31,16>().val()) : value<16>{0u}));
	// cells $procmux$5863 $procmux$5860 $procmux$5858
	i_3_5c_enabled_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_logic__and_24_receiver_2e_v_3a_59_24_82__Y ? value<1>{0x1u} : p_enabled.curr.slice<0>().val()) : value<1>{0u}));
	// cells $procmux$5854 $procmux$5851 $procmux$5849
	i_3_5c_counts_5b_15_3a_0_5d_ = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_logic__and_24_receiver_2e_v_3a_59_24_82__Y ? p_cfgk : p_counts.curr.slice<15,0>().val()) : value<16>{0u}));
	// cells $procmux$4766 $procmux$4763 $procmux$4797
	i_5_5c_enqowner_5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_logic__and_24_receiver_2e_v_3a_72_24_104__Y ? p_fp.curr.slice<1,0>().val() : value<2>{0u}) : value<2>{0u}));
	// \src: receiver.v:64.10-64.29
	// cell $eq$receiver.v:64$99
	i_eq_24_receiver_2e_v_3a_64_24_99__Y = logic_not<1>(i_6_5c_counts_5b_63_3a_48_5d_);
	// \src: receiver.v:64.10-64.29
	// cell $eq$receiver.v:64$95
	i_eq_24_receiver_2e_v_3a_64_24_95__Y = logic_not<1>(i_5_5c_counts_5b_47_3a_32_5d_);
	// \src: receiver.v:64.10-64.29
	// cell $eq$receiver.v:64$91
	i_eq_24_receiver_2e_v_3a_64_24_91__Y = logic_not<1>(i_4_5c_counts_5b_31_3a_16_5d_);
	// \src: receiver.v:64.10-64.29
	// cell $eq$receiver.v:64$87
	i_eq_24_receiver_2e_v_3a_64_24_87__Y = logic_not<1>(i_3_5c_counts_5b_15_3a_0_5d_);
	// \src: receiver.v:83.50-83.64
	// cell $mul$receiver.v:83$143
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7043.slice<4,0>() = mul_uu<5>(value<3>{0x4u}, i_5_5c_enqowner_5b_1_3a_0_5d_);
	// \full_case: 1
	// \src: receiver.v:64.10-64.29|receiver.v:64.7-65.128
	// cell $procmux$5429
	i_6_5c_fault_5b_31_3a_0_5d_.slice<1,0>() = (i_eq_24_receiver_2e_v_3a_64_24_87__Y ? value<1>{0x1u}.concat(p_fault.curr.slice<0>()).val() : p_fault.curr.slice<1,0>().val());
	// \src: receiver.v:83.49-83.68
	// cell $add$receiver.v:83$144
	i_add_24_receiver_2e_v_3a_82_24_133__Y = add_uu<6>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7043.slice<4,0>().val(), value<1>{0u});
	// \full_case: 1
	// \src: receiver.v:63.9-63.19|receiver.v:63.6-66.9
	// cell $procmux$5515
	i_5_5c_fault_5b_31_3a_0_5d_.slice<1,0>() = (i_3_5c_enabled_5b_0_3a_0_5d_ ? i_6_5c_fault_5b_31_3a_0_5d_.slice<1,0>().val() : p_fault.curr.slice<1,0>().val());
	// \src: receiver.v:83.49-83.68
	// cell $shiftx$receiver.v:83$145
	i_shiftx_24_receiver_2e_v_3a_82_24_134__Y = shiftx_us<4>(p_outstanding.curr, value<1>{0u}.concat(i_add_24_receiver_2e_v_3a_82_24_133__Y).val());
	// \full_case: 1
	// \src: receiver.v:64.10-64.29|receiver.v:64.7-65.128
	// cell $procmux$5240
	i_8_5c_fault_5b_31_3a_0_5d_.slice<1,0>() = (i_eq_24_receiver_2e_v_3a_64_24_91__Y ? value<1>{0x1u}.concat(i_5_5c_fault_5b_31_3a_0_5d_.slice<0>()).val() : i_5_5c_fault_5b_31_3a_0_5d_.slice<1,0>().val());
	// \full_case: 1
	// \src: receiver.v:63.9-63.19|receiver.v:63.6-66.9
	// cell $procmux$5326
	i_7_5c_fault_5b_31_3a_0_5d_.slice<1,0>() = (i_4_5c_enabled_5b_1_3a_1_5d_ ? i_8_5c_fault_5b_31_3a_0_5d_.slice<1,0>().val() : i_5_5c_fault_5b_31_3a_0_5d_.slice<1,0>().val());
	// \full_case: 1
	// \src: receiver.v:64.10-64.29|receiver.v:64.7-65.128
	// cell $procmux$5051
	i_10_5c_fault_5b_31_3a_0_5d_.slice<1,0>() = (i_eq_24_receiver_2e_v_3a_64_24_95__Y ? value<1>{0x1u}.concat(i_7_5c_fault_5b_31_3a_0_5d_.slice<0>()).val() : i_7_5c_fault_5b_31_3a_0_5d_.slice<1,0>().val());
	// \full_case: 1
	// \src: receiver.v:63.9-63.19|receiver.v:63.6-66.9
	// cell $procmux$5137
	i_procmux_24_5137__Y.slice<1,0>() = (i_5_5c_enabled_5b_2_3a_2_5d_ ? i_10_5c_fault_5b_31_3a_0_5d_.slice<1,0>().val() : i_7_5c_fault_5b_31_3a_0_5d_.slice<1,0>().val());
	// cells $procmux$5144 $procmux$5141 $procmux$5139
	i_11_5c_fault_5b_31_3a_0_5d_.next.slice<31,2>().concat(i_9_5c_fault_5b_31_3a_0_5d_.slice<1,0>()) = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_eq_24_receiver_2e_v_3a_61_24_86__Y ? p_fault.curr.slice<31,2>().concat(i_procmux_24_5137__Y.slice<1,0>()).val() : value<32>{0u}) : value<32>{0u}));
	// \full_case: 1
	// \src: receiver.v:43.6-43.9|receiver.v:43.3-128.6
	// cell $procmux$5584
	i_14_5c_fault_5b_31_3a_0_5d_.next.slice<31,4>().concat(i_4_5c_fault_5b_31_3a_0_5d_.slice<3,0>()) = (p_rst ? value<32>{0u} : i_procmux_24_5581__Y.curr);
	// connection
	i_9_5c_fault_5b_31_3a_0_5d_.slice<31,2>() = i_11_5c_fault_5b_31_3a_0_5d_.curr.slice<31,2>().val();
	// \full_case: 1
	// \src: receiver.v:64.10-64.29|receiver.v:64.7-65.128
	// cell $procmux$4862
	i_12_5c_fault_5b_31_3a_0_5d_.slice<1,0>() = (i_eq_24_receiver_2e_v_3a_64_24_99__Y ? value<1>{0x1u}.concat(i_9_5c_fault_5b_31_3a_0_5d_.slice<0>()).val() : i_9_5c_fault_5b_31_3a_0_5d_.slice<1,0>().val());
	// connection
	i_4_5c_fault_5b_31_3a_0_5d_.slice<31,4>() = i_14_5c_fault_5b_31_3a_0_5d_.curr.slice<31,4>().val();
	// cells $procmux$3721 $eq$receiver.v:82$135
	i_15_5c_fault_5b_31_3a_0_5d_.slice<3,0>() = (eq_uu<1>(i_shiftx_24_receiver_2e_v_3a_82_24_134__Y, value<4>{0xfu}) ? value<1>{0x1u}.concat(i_4_5c_fault_5b_31_3a_0_5d_.slice<2,0>()).val() : i_4_5c_fault_5b_31_3a_0_5d_.slice<3,0>().val());
	// connection
	i_12_5c_fault_5b_31_3a_0_5d_.slice<31,2>() = i_11_5c_fault_5b_31_3a_0_5d_.curr.slice<31,2>().val();
	// connection
	i_15_5c_fault_5b_31_3a_0_5d_.slice<31,4>() = i_14_5c_fault_5b_31_3a_0_5d_.curr.slice<31,4>().val();
	// \full_case: 1
	// \src: receiver.v:76.9-76.16|receiver.v:76.6-84.9
	// cell $procmux$4132
	i_14_5c_fault_5b_31_3a_0_5d_.next.slice<3,0>() = (i_ge_24_receiver_2e_v_3a_76_24_121__Y ? i_4_5c_fault_5b_31_3a_0_5d_.slice<3>().concat(value<1>{0x1u}).concat(i_4_5c_fault_5b_31_3a_0_5d_.slice<1,0>()).val() : i_15_5c_fault_5b_31_3a_0_5d_.slice<3,0>().val());
	// \full_case: 1
	// \src: receiver.v:63.9-63.19|receiver.v:63.6-66.9
	// cell $procmux$4948
	i_11_5c_fault_5b_31_3a_0_5d_.next.slice<1,0>() = (i_6_5c_enabled_5b_3_3a_3_5d_ ? i_12_5c_fault_5b_31_3a_0_5d_.slice<1,0>().val() : i_9_5c_fault_5b_31_3a_0_5d_.slice<1,0>().val());
	// cells $procmux$5581 $procmux$5579
	i_procmux_24_5581__Y.next = (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_eq_24_receiver_2e_v_3a_61_24_86__Y ? i_11_5c_fault_5b_31_3a_0_5d_.curr : p_fault.curr) : value<32>{0u});
	// cells $procmux$4775 $procmux$4772 $procmux$4806
	i_5_5c_releasevalid_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_logic__and_24_receiver_2e_v_3a_72_24_104__Y ? value<1>{0x1u} : value<1>{0u}) : value<1>{0u}));
	// \full_case: 1
	// \src: receiver.v:81.7-81.28
	// cell $procmux$4057_CMP0
	i_procmux_24_3742__CMP = eq_uu<1>(p_qlen.curr.slice<2,0>().val(), value<1>{0x1u});
	// \full_case: 1
	// \src: receiver.v:81.7-81.28
	// cell $procmux$4056_CMP0
	i_procmux_24_3741__CMP = eq_uu<1>(p_qlen.curr.slice<2,0>().val(), value<2>{0x2u});
	// \full_case: 1
	// \src: receiver.v:81.7-81.28
	// cell $procmux$4055_CMP0
	i_procmux_24_3740__CMP = eq_uu<1>(p_qlen.curr.slice<2,0>().val(), value<2>{0x3u});
	// \full_case: 1
	// \src: receiver.v:81.7-81.28
	// cell $procmux$4054_CMP0
	i_procmux_24_3739__CMP = eq_uu<1>(p_qlen.curr.slice<2,0>().val(), value<3>{0x4u});
	// \full_case: 1
	// \src: receiver.v:81.7-81.28
	// cell $procmux$4053_CMP0
	i_procmux_24_3738__CMP = eq_uu<1>(p_qlen.curr.slice<2,0>().val(), value<3>{0x5u});
	// \full_case: 1
	// \src: receiver.v:81.7-81.28
	// cell $procmux$4052_CMP0
	i_procmux_24_3737__CMP = eq_uu<1>(p_qlen.curr.slice<2,0>().val(), value<3>{0x6u});
	// \full_case: 1
	// \src: receiver.v:81.7-81.28
	// cell $procmux$4051_CMP0
	i_procmux_24_3736__CMP = eq_uu<1>(p_qlen.curr.slice<2,0>().val(), value<3>{0x7u});
	// cells $logic_and$receiver.v:73$155 $eq$receiver.v:73$152
	i_logic__and_24_receiver_2e_v_3a_73_24_155__Y = logic_and<1>(eq_uu<1>(p_cfgf, value<6>{0x28u}), i_logic__and_24_receiver_2e_v_3a_72_24_104__Y);
	// \full_case: 1
	// \src: receiver.v:81.7-81.28
	// cell $procmux$4058_CMP0
	i_procmux_24_3743__CMP = logic_not<1>(p_qlen.curr.slice<2,0>().val());
	// cell $auto$opt_reduce.cc:131:opt_pmux$6931
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6844 = reduce_or<1>(i_procmux_24_3742__CMP.concat(i_procmux_24_3741__CMP).concat(i_procmux_24_3740__CMP).concat(i_procmux_24_3739__CMP).concat(i_procmux_24_3738__CMP).concat(i_procmux_24_3737__CMP).concat(i_procmux_24_3736__CMP).val());
	// \src: receiver.v:74.78-74.83
	// cell $sub$receiver.v:74$162
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7034.slice<1,0>() = sub_uu<2>(p_fp.curr.slice<1,0>().val(), value<1>{0u});
	// cells $logic_and$receiver.v:74$161 $logic_and$receiver.v:74$159 $ne$receiver.v:74$156 $ge$receiver.v:74$158 $lt$receiver.v:74$160
	i_logic__and_24_receiver_2e_v_3a_74_24_161__Y = logic_and<1>(logic_and<1>(ne_uu<1>(p_cfgf, value<6>{0x28u}), ge_uu<1>(p_fp.curr, value<6>{0x28u})), lt_uu<1>(p_fp.curr, value<6>{0x2cu}));
	// \src: receiver.v:65.35-65.53
	// cell $sub$receiver.v:65$101
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7046.slice<15,0>() = sub_uu<16>(i_6_5c_counts_5b_63_3a_48_5d_, value<1>{0x1u});
	// \src: receiver.v:65.35-65.53
	// cell $sub$receiver.v:65$89
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7049.slice<15,0>() = sub_uu<16>(i_3_5c_counts_5b_15_3a_0_5d_, value<1>{0x1u});
	// \src: receiver.v:65.35-65.53
	// cell $sub$receiver.v:65$93
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7048.slice<15,0>() = sub_uu<16>(i_4_5c_counts_5b_31_3a_16_5d_, value<1>{0x1u});
	// \src: receiver.v:65.35-65.53
	// cell $sub$receiver.v:65$97
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7047.slice<15,0>() = sub_uu<16>(i_5_5c_counts_5b_47_3a_32_5d_, value<1>{0x1u});
	// cells $procmux$4748 $procmux$4745 $procmux$4743 $procmux$4468 $add$receiver.v:81$130
	i_3_5c_qlen_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_5_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_121__Y ? p_qlen.curr : add_uu<4>(p_qlen.curr, value<1>{0x1u})) : p_qlen.curr) : value<4>{0u}));
	// \src: receiver.v:65.57-65.76
	// cell $eq$receiver.v:65$102
	i_eq_24_receiver_2e_v_3a_65_24_102__Y = logic_not<1>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7046.slice<15,0>().val());
	// \src: receiver.v:65.57-65.76
	// cell $eq$receiver.v:65$90
	i_eq_24_receiver_2e_v_3a_65_24_90__Y = logic_not<1>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7049.slice<15,0>().val());
	// \src: receiver.v:65.57-65.76
	// cell $eq$receiver.v:65$94
	i_eq_24_receiver_2e_v_3a_65_24_94__Y = logic_not<1>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7048.slice<15,0>().val());
	// \src: receiver.v:65.57-65.76
	// cell $eq$receiver.v:65$98
	i_eq_24_receiver_2e_v_3a_65_24_98__Y = logic_not<1>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7047.slice<15,0>().val());
	// \full_case: 1
	// \src: receiver.v:81.7-81.28
	// cell $procmux$2962_CMP0
	i_procmux_24_2647__CMP = eq_uu<1>(i_3_5c_qlen_5b_3_3a_0_5d_.slice<2,0>().val(), value<1>{0x1u});
	// \full_case: 1
	// \src: receiver.v:81.7-81.28
	// cell $procmux$2961_CMP0
	i_procmux_24_2646__CMP = eq_uu<1>(i_3_5c_qlen_5b_3_3a_0_5d_.slice<2,0>().val(), value<2>{0x2u});
	// \full_case: 1
	// \src: receiver.v:81.7-81.28
	// cell $procmux$2960_CMP0
	i_procmux_24_2645__CMP = eq_uu<1>(i_3_5c_qlen_5b_3_3a_0_5d_.slice<2,0>().val(), value<2>{0x3u});
	// \full_case: 1
	// \src: receiver.v:81.7-81.28
	// cell $procmux$2959_CMP0
	i_procmux_24_2644__CMP = eq_uu<1>(i_3_5c_qlen_5b_3_3a_0_5d_.slice<2,0>().val(), value<3>{0x4u});
	// \full_case: 1
	// \src: receiver.v:81.7-81.28
	// cell $procmux$2958_CMP0
	i_procmux_24_2643__CMP = eq_uu<1>(i_3_5c_qlen_5b_3_3a_0_5d_.slice<2,0>().val(), value<3>{0x5u});
	// \full_case: 1
	// \src: receiver.v:81.7-81.28
	// cell $procmux$2957_CMP0
	i_procmux_24_2642__CMP = eq_uu<1>(i_3_5c_qlen_5b_3_3a_0_5d_.slice<2,0>().val(), value<3>{0x6u});
	// \full_case: 1
	// \src: receiver.v:81.7-81.28
	// cell $procmux$2956_CMP0
	i_procmux_24_2641__CMP = eq_uu<1>(i_3_5c_qlen_5b_3_3a_0_5d_.slice<2,0>().val(), value<3>{0x7u});
	// cells $procmux$4662 $procmux$4372 $procmux$3903
	i_3_5c_qo_5b_0_5d__5b_1_3a_0_5d_ = (i_5_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_121__Y ? p_qo_5b_0_5d_.curr : (i_procmux_24_3743__CMP ? i_5_5c_enqowner_5b_1_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6844 ? p_qo_5b_0_5d_.curr : value<2>{0u}))) : p_qo_5b_0_5d_.curr);
	// cells $procmux$3671 $procmux$3668 $procmux$3666 $procmux$3684
	i_8_5c_releaseowner_5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_logic__and_24_receiver_2e_v_3a_74_24_161__Y ? i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7034.slice<1,0>().val() : (i_logic__and_24_receiver_2e_v_3a_73_24_155__Y ? p_fp.curr.slice<1,0>().val() : value<2>{0u})) : value<2>{0u}));
	// \full_case: 1
	// \src: receiver.v:81.7-81.28
	// cell $procmux$2963_CMP0
	i_procmux_24_2648__CMP = logic_not<1>(i_3_5c_qlen_5b_3_3a_0_5d_.slice<2,0>().val());
	// cell $auto$opt_reduce.cc:131:opt_pmux$6959
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6898 = reduce_or<1>(i_procmux_24_2647__CMP.concat(i_procmux_24_2646__CMP).concat(i_procmux_24_2645__CMP).concat(i_procmux_24_2644__CMP).concat(i_procmux_24_2643__CMP).concat(i_procmux_24_2642__CMP).concat(i_procmux_24_2641__CMP).val());
	// cell $auto$opt_reduce.cc:131:opt_pmux$6845
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6830 = reduce_or<1>(i_procmux_24_3743__CMP.concat(i_procmux_24_3741__CMP).concat(i_procmux_24_3740__CMP).concat(i_procmux_24_3739__CMP).concat(i_procmux_24_3738__CMP).concat(i_procmux_24_3737__CMP).concat(i_procmux_24_3736__CMP).val());
	// \src: receiver.v:76.9-76.16
	// cell $ge$receiver.v:76$168
	i_ge_24_receiver_2e_v_3a_76_24_168__Y = ge_uu<1>(i_3_5c_qlen_5b_3_3a_0_5d_, value<4>{0x8u});
	// cells $procmux$3680 $procmux$3677 $procmux$3675 $procmux$3693
	i_8_5c_releasevalid_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_logic__and_24_receiver_2e_v_3a_74_24_161__Y ? value<1>{0x1u} : (i_logic__and_24_receiver_2e_v_3a_73_24_155__Y ? value<1>{0x1u} : value<1>{0u})) : value<1>{0u}));
	// cells $procmux$4653 $procmux$4360 $procmux$4050
	i_3_5c_qo_5b_1_5d__5b_1_3a_0_5d_ = (i_5_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_121__Y ? p_qo_5b_1_5d_.curr : (i_procmux_24_3742__CMP ? i_5_5c_enqowner_5b_1_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6830 ? p_qo_5b_1_5d_.curr : value<2>{0u}))) : p_qo_5b_1_5d_.curr);
	// cell $auto$opt_reduce.cc:131:opt_pmux$6905
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6850 = reduce_or<1>(i_procmux_24_2648__CMP.concat(i_procmux_24_2646__CMP).concat(i_procmux_24_2645__CMP).concat(i_procmux_24_2644__CMP).concat(i_procmux_24_2643__CMP).concat(i_procmux_24_2642__CMP).concat(i_procmux_24_2641__CMP).val());
	// cell $auto$opt_reduce.cc:131:opt_pmux$6847
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6832 = reduce_or<1>(i_procmux_24_3743__CMP.concat(i_procmux_24_3742__CMP).concat(i_procmux_24_3740__CMP).concat(i_procmux_24_3739__CMP).concat(i_procmux_24_3738__CMP).concat(i_procmux_24_3737__CMP).concat(i_procmux_24_3736__CMP).val());
	// cells $procmux$5710 $procmux$5707 $procmux$5705 $procmux$4984 $procmux$4922 $procmux$4844
	i_3_5c_valid_5b_3_3a_0_5d_.slice<3>() = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_eq_24_receiver_2e_v_3a_61_24_86__Y ? (i_6_5c_enabled_5b_3_3a_3_5d_ ? (i_eq_24_receiver_2e_v_3a_64_24_99__Y ? p_valid.curr.slice<3>().val() : (i_eq_24_receiver_2e_v_3a_65_24_102__Y ? value<1>{0u} : p_valid.curr.slice<3>().val())) : p_valid.curr.slice<3>().val()) : p_valid.curr.slice<3>().val()) : value<1>{0u}));
	// cells $procmux$5683 $procmux$5680 $procmux$5678 $procmux$5551 $procmux$5489 $procmux$5411
	i_3_5c_valid_5b_3_3a_0_5d_.slice<0>() = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_eq_24_receiver_2e_v_3a_61_24_86__Y ? (i_3_5c_enabled_5b_0_3a_0_5d_ ? (i_eq_24_receiver_2e_v_3a_64_24_87__Y ? p_valid.curr.slice<0>().val() : (i_eq_24_receiver_2e_v_3a_65_24_90__Y ? value<1>{0u} : p_valid.curr.slice<0>().val())) : p_valid.curr.slice<0>().val()) : p_valid.curr.slice<0>().val()) : value<1>{0u}));
	// cells $procmux$5647 $procmux$5644 $procmux$5642 $procmux$5362 $procmux$5300 $procmux$5222
	i_3_5c_valid_5b_3_3a_0_5d_.slice<1>() = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_eq_24_receiver_2e_v_3a_61_24_86__Y ? (i_4_5c_enabled_5b_1_3a_1_5d_ ? (i_eq_24_receiver_2e_v_3a_64_24_91__Y ? p_valid.curr.slice<1>().val() : (i_eq_24_receiver_2e_v_3a_65_24_94__Y ? value<1>{0u} : p_valid.curr.slice<1>().val())) : p_valid.curr.slice<1>().val()) : p_valid.curr.slice<1>().val()) : value<1>{0u}));
	// cells $procmux$5611 $procmux$5608 $procmux$5606 $procmux$5173 $procmux$5111 $procmux$5033
	i_3_5c_valid_5b_3_3a_0_5d_.slice<2>() = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_eq_24_receiver_2e_v_3a_61_24_86__Y ? (i_5_5c_enabled_5b_2_3a_2_5d_ ? (i_eq_24_receiver_2e_v_3a_64_24_95__Y ? p_valid.curr.slice<2>().val() : (i_eq_24_receiver_2e_v_3a_65_24_98__Y ? value<1>{0u} : p_valid.curr.slice<2>().val())) : p_valid.curr.slice<2>().val()) : p_valid.curr.slice<2>().val()) : value<1>{0u}));
	// cells $procmux$3572 $procmux$3569 $procmux$3567 $procmux$3277 $procmux$2808
	i_6_5c_qo_5b_0_5d__5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_168__Y ? i_3_5c_qo_5b_0_5d__5b_1_3a_0_5d_ : (i_procmux_24_2648__CMP ? i_8_5c_releaseowner_5b_1_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6898 ? i_3_5c_qo_5b_0_5d__5b_1_3a_0_5d_ : value<2>{0u}))) : i_3_5c_qo_5b_0_5d__5b_1_3a_0_5d_) : value<2>{0u}));
	// cells $procmux$3653 $procmux$3650 $procmux$3648 $procmux$3373 $add$receiver.v:81$177
	i_5_5c_qlen_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_168__Y ? i_3_5c_qlen_5b_3_3a_0_5d_ : add_uu<4>(i_3_5c_qlen_5b_3_3a_0_5d_, value<1>{0x1u})) : i_3_5c_qlen_5b_3_3a_0_5d_) : value<4>{0u}));
	// \src: receiver.v:89.14-89.21
	// cell $shiftx$receiver.v:89$203
	i_shiftx_24_receiver_2e_v_3a_89_24_203__Y = shiftx_uu<1>(i_3_5c_valid_5b_3_3a_0_5d_, i_6_5c_qo_5b_0_5d__5b_1_3a_0_5d_);
	// cells $procmux$3558 $procmux$3265 $procmux$2955
	i_6_5c_qo_5b_1_5d__5b_1_3a_0_5d_ = (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_168__Y ? i_3_5c_qo_5b_1_5d__5b_1_3a_0_5d_ : (i_procmux_24_2647__CMP ? i_8_5c_releaseowner_5b_1_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6850 ? i_3_5c_qo_5b_1_5d__5b_1_3a_0_5d_ : value<2>{0u}))) : i_3_5c_qo_5b_1_5d__5b_1_3a_0_5d_);
	// cells $logic_and$receiver.v:87$201 $logic_and$receiver.v:87$199 $eq$receiver.v:87$197 $logic_not$receiver.v:87$198 $ne$receiver.v:87$200
	i_logic__and_24_receiver_2e_v_3a_87_24_201__Y = logic_and<1>(logic_and<1>(logic_not<1>(p_cp.curr), logic_not<1>(p_rzero.curr)), reduce_bool<1>(i_5_5c_qlen_5b_3_3a_0_5d_));
	// cells $procmux$4644 $procmux$4348 $procmux$4029
	i_3_5c_qo_5b_2_5d__5b_1_3a_0_5d_ = (i_5_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_121__Y ? p_qo_5b_2_5d_.curr : (i_procmux_24_3741__CMP ? i_5_5c_enqowner_5b_1_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6832 ? p_qo_5b_2_5d_.curr : value<2>{0u}))) : p_qo_5b_2_5d_.curr);
	// cell $auto$opt_reduce.cc:131:opt_pmux$6913
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6854 = reduce_or<1>(i_procmux_24_2648__CMP.concat(i_procmux_24_2647__CMP).concat(i_procmux_24_2645__CMP).concat(i_procmux_24_2644__CMP).concat(i_procmux_24_2643__CMP).concat(i_procmux_24_2642__CMP).concat(i_procmux_24_2641__CMP).val());
	// \src: receiver.v:95.27-95.33
	// cell $sub$receiver.v:95$217
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7021.slice<3,0>() = sub_uu<4>(i_5_5c_qlen_5b_3_3a_0_5d_, value<1>{0x1u});
	// cell $auto$opt_reduce.cc:131:opt_pmux$6851
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6834 = reduce_or<1>(i_procmux_24_3743__CMP.concat(i_procmux_24_3742__CMP).concat(i_procmux_24_3741__CMP).concat(i_procmux_24_3739__CMP).concat(i_procmux_24_3738__CMP).concat(i_procmux_24_3737__CMP).concat(i_procmux_24_3736__CMP).val());
	// cells $procmux$2450 $procmux$2447 $procmux$2445 $procmux$2155
	i_9_5c_qo_5b_0_5d__5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_201__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_203__Y ? i_6_5c_qo_5b_1_5d__5b_1_3a_0_5d_ : i_6_5c_qo_5b_0_5d__5b_1_3a_0_5d_) : i_6_5c_qo_5b_0_5d__5b_1_3a_0_5d_) : value<2>{0u}));
	// cells $procmux$3549 $procmux$3253 $procmux$2934
	i_6_5c_qo_5b_2_5d__5b_1_3a_0_5d_ = (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_168__Y ? i_3_5c_qo_5b_2_5d__5b_1_3a_0_5d_ : (i_procmux_24_2646__CMP ? i_8_5c_releaseowner_5b_1_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6854 ? i_3_5c_qo_5b_2_5d__5b_1_3a_0_5d_ : value<2>{0u}))) : i_3_5c_qo_5b_2_5d__5b_1_3a_0_5d_);
	// \full_case: 1
	// \src: receiver.v:116.37-116.37|receiver.v:116.6-116.104
	// cell $procmux$1240_CMP0
	i_procmux_24_1198__CMP = eq_uu<1>(i_9_5c_qo_5b_0_5d__5b_1_3a_0_5d_, value<1>{0x1u});
	// \full_case: 1
	// \src: receiver.v:116.57-116.57|receiver.v:116.6-116.104
	// cell $procmux$1239_CMP0
	i_procmux_24_1197__CMP = eq_uu<1>(i_9_5c_qo_5b_0_5d__5b_1_3a_0_5d_, value<2>{0x2u});
	// \full_case: 1
	// \src: receiver.v:116.77-116.77|receiver.v:116.6-116.104
	// cell $procmux$1238_CMP0
	i_procmux_24_1196__CMP = eq_uu<1>(i_9_5c_qo_5b_0_5d__5b_1_3a_0_5d_, value<2>{0x3u});
	// \full_case: 1
	// \src: receiver.v:116.17-116.17|receiver.v:116.6-116.104
	// cell $procmux$1241_CMP0
	i_procmux_24_1199__CMP = logic_not<1>(i_9_5c_qo_5b_0_5d__5b_1_3a_0_5d_);
	// cells $procmux$2594 $procmux$2591 $procmux$2589 $procmux$2299
	i_7_5c_qlen_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_201__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_203__Y ? i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7021.slice<3,0>().val() : i_5_5c_qlen_5b_3_3a_0_5d_) : i_5_5c_qlen_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$4635 $procmux$4336 $procmux$4008
	i_3_5c_qo_5b_3_5d__5b_1_3a_0_5d_ = (i_5_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_121__Y ? p_qo_5b_3_5d_.curr : (i_procmux_24_3740__CMP ? i_5_5c_enqowner_5b_1_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6834 ? p_qo_5b_3_5d_.curr : value<2>{0u}))) : p_qo_5b_3_5d_.curr);
	// cell $auto$opt_reduce.cc:131:opt_pmux$6921
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6856 = reduce_or<1>(i_procmux_24_2648__CMP.concat(i_procmux_24_2647__CMP).concat(i_procmux_24_2646__CMP).concat(i_procmux_24_2644__CMP).concat(i_procmux_24_2643__CMP).concat(i_procmux_24_2642__CMP).concat(i_procmux_24_2641__CMP).val());
	// \src: receiver.v:115.8-115.14
	// cell $lt$receiver.v:115$245
	i_lt_24_receiver_2e_v_3a_115_24_245__Y = lt_uu<1>(value<1>{0u}, i_7_5c_qlen_5b_3_3a_0_5d_);
	// cell $auto$opt_reduce.cc:131:opt_pmux$6861
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6836 = reduce_or<1>(i_procmux_24_3743__CMP.concat(i_procmux_24_3742__CMP).concat(i_procmux_24_3741__CMP).concat(i_procmux_24_3740__CMP).concat(i_procmux_24_3738__CMP).concat(i_procmux_24_3737__CMP).concat(i_procmux_24_3736__CMP).val());
	// cells $procmux$2441 $procmux$2438 $procmux$2436 $procmux$2143
	i_9_5c_qo_5b_1_5d__5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_201__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_203__Y ? i_6_5c_qo_5b_2_5d__5b_1_3a_0_5d_ : i_6_5c_qo_5b_1_5d__5b_1_3a_0_5d_) : i_6_5c_qo_5b_1_5d__5b_1_3a_0_5d_) : value<2>{0u}));
	// cells $procmux$3540 $procmux$3241 $procmux$2913
	i_6_5c_qo_5b_3_5d__5b_1_3a_0_5d_ = (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_168__Y ? i_3_5c_qo_5b_3_5d__5b_1_3a_0_5d_ : (i_procmux_24_2645__CMP ? i_8_5c_releaseowner_5b_1_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6856 ? i_3_5c_qo_5b_3_5d__5b_1_3a_0_5d_ : value<2>{0u}))) : i_3_5c_qo_5b_3_5d__5b_1_3a_0_5d_);
	// \full_case: 1
	// \src: receiver.v:116.37-116.37|receiver.v:116.6-116.104
	// cell $procmux$1148_CMP0
	i_procmux_24_1106__CMP = eq_uu<1>(i_9_5c_qo_5b_1_5d__5b_1_3a_0_5d_, value<1>{0x1u});
	// \full_case: 1
	// \src: receiver.v:116.57-116.57|receiver.v:116.6-116.104
	// cell $procmux$1147_CMP0
	i_procmux_24_1105__CMP = eq_uu<1>(i_9_5c_qo_5b_1_5d__5b_1_3a_0_5d_, value<2>{0x2u});
	// \full_case: 1
	// \src: receiver.v:116.77-116.77|receiver.v:116.6-116.104
	// cell $procmux$1146_CMP0
	i_procmux_24_1104__CMP = eq_uu<1>(i_9_5c_qo_5b_1_5d__5b_1_3a_0_5d_, value<2>{0x3u});
	// cells $procmux$1283 $procmux$1280 $procmux$1278 $procmux$1195 $auto$opt_reduce.cc:131:opt_pmux$6867
	i_3_5c_tokens0_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_lt_24_receiver_2e_v_3a_115_24_245__Y ? (i_procmux_24_1199__CMP ? value<4>{0x1u} : (reduce_or<1>(i_procmux_24_1198__CMP.concat(i_procmux_24_1197__CMP).concat(i_procmux_24_1196__CMP).val()) ? value<4>{0u} : value<4>{0u})) : value<4>{0u}) : value<4>{0u}));
	// \full_case: 1
	// \src: receiver.v:116.17-116.17|receiver.v:116.6-116.104
	// cell $procmux$1149_CMP0
	i_procmux_24_1107__CMP = logic_not<1>(i_9_5c_qo_5b_1_5d__5b_1_3a_0_5d_);
	// cells $procmux$1274 $procmux$1271 $procmux$1269 $procmux$1237 $auto$opt_reduce.cc:131:opt_pmux$6857
	i_3_5c_tokens1_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_lt_24_receiver_2e_v_3a_115_24_245__Y ? (i_procmux_24_1198__CMP ? value<4>{0x1u} : (reduce_or<1>(i_procmux_24_1199__CMP.concat(i_procmux_24_1197__CMP).concat(i_procmux_24_1196__CMP).val()) ? value<4>{0u} : value<4>{0u})) : value<4>{0u}) : value<4>{0u}));
	// cells $procmux$1265 $procmux$1262 $procmux$1260 $procmux$1223 $auto$opt_reduce.cc:131:opt_pmux$6859
	i_3_5c_tokens2_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_lt_24_receiver_2e_v_3a_115_24_245__Y ? (i_procmux_24_1197__CMP ? value<4>{0x1u} : (reduce_or<1>(i_procmux_24_1199__CMP.concat(i_procmux_24_1198__CMP).concat(i_procmux_24_1196__CMP).val()) ? value<4>{0u} : value<4>{0u})) : value<4>{0u}) : value<4>{0u}));
	// cells $procmux$1256 $procmux$1253 $procmux$1251 $procmux$1209 $auto$opt_reduce.cc:131:opt_pmux$6863
	i_3_5c_tokens3_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_lt_24_receiver_2e_v_3a_115_24_245__Y ? (reduce_or<1>(i_procmux_24_1199__CMP.concat(i_procmux_24_1198__CMP).concat(i_procmux_24_1197__CMP).val()) ? value<4>{0u} : (i_procmux_24_1196__CMP ? value<4>{0x1u} : value<4>{0u})) : value<4>{0u}) : value<4>{0u}));
	// cells $procmux$4626 $procmux$4324 $procmux$3987
	i_3_5c_qo_5b_4_5d__5b_1_3a_0_5d_ = (i_5_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_121__Y ? p_qo_5b_4_5d_.curr : (i_procmux_24_3739__CMP ? i_5_5c_enqowner_5b_1_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6836 ? p_qo_5b_4_5d_.curr : value<2>{0u}))) : p_qo_5b_4_5d_.curr);
	// cell $auto$opt_reduce.cc:131:opt_pmux$6927
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6866 = reduce_or<1>(i_procmux_24_2648__CMP.concat(i_procmux_24_2647__CMP).concat(i_procmux_24_2646__CMP).concat(i_procmux_24_2645__CMP).concat(i_procmux_24_2643__CMP).concat(i_procmux_24_2642__CMP).concat(i_procmux_24_2641__CMP).val());
	// \src: receiver.v:115.8-115.14
	// cell $lt$receiver.v:115$250
	i_lt_24_receiver_2e_v_3a_115_24_250__Y = lt_uu<1>(value<1>{0x1u}, i_7_5c_qlen_5b_3_3a_0_5d_);
	// cell $auto$opt_reduce.cc:131:opt_pmux$6879
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6838 = reduce_or<1>(i_procmux_24_3743__CMP.concat(i_procmux_24_3742__CMP).concat(i_procmux_24_3741__CMP).concat(i_procmux_24_3740__CMP).concat(i_procmux_24_3739__CMP).concat(i_procmux_24_3737__CMP).concat(i_procmux_24_3736__CMP).val());
	// cells $procmux$2432 $procmux$2429 $procmux$2427 $procmux$2131
	i_9_5c_qo_5b_2_5d__5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_201__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_203__Y ? i_6_5c_qo_5b_3_5d__5b_1_3a_0_5d_ : i_6_5c_qo_5b_2_5d__5b_1_3a_0_5d_) : i_6_5c_qo_5b_2_5d__5b_1_3a_0_5d_) : value<2>{0u}));
	// cells $procmux$3531 $procmux$3229 $procmux$2892
	i_6_5c_qo_5b_4_5d__5b_1_3a_0_5d_ = (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_168__Y ? i_3_5c_qo_5b_4_5d__5b_1_3a_0_5d_ : (i_procmux_24_2644__CMP ? i_8_5c_releaseowner_5b_1_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6866 ? i_3_5c_qo_5b_4_5d__5b_1_3a_0_5d_ : value<2>{0u}))) : i_3_5c_qo_5b_4_5d__5b_1_3a_0_5d_);
	// \full_case: 1
	// \src: receiver.v:116.37-116.37|receiver.v:116.6-116.104
	// cell $procmux$1056_CMP0
	i_procmux_24_1014__CMP = eq_uu<1>(i_9_5c_qo_5b_2_5d__5b_1_3a_0_5d_, value<1>{0x1u});
	// \full_case: 1
	// \src: receiver.v:116.57-116.57|receiver.v:116.6-116.104
	// cell $procmux$1055_CMP0
	i_procmux_24_1013__CMP = eq_uu<1>(i_9_5c_qo_5b_2_5d__5b_1_3a_0_5d_, value<2>{0x2u});
	// \full_case: 1
	// \src: receiver.v:116.77-116.77|receiver.v:116.6-116.104
	// cell $procmux$1054_CMP0
	i_procmux_24_1012__CMP = eq_uu<1>(i_9_5c_qo_5b_2_5d__5b_1_3a_0_5d_, value<2>{0x3u});
	// cells $procmux$1191 $procmux$1188 $procmux$1186 $procmux$1103 $add$receiver.v:116$251 $auto$opt_reduce.cc:131:opt_pmux$6877
	i_5_5c_tokens0_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_lt_24_receiver_2e_v_3a_115_24_250__Y ? (i_procmux_24_1107__CMP ? add_uu<4>(i_3_5c_tokens0_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_1106__CMP.concat(i_procmux_24_1105__CMP).concat(i_procmux_24_1104__CMP).val()) ? i_3_5c_tokens0_5b_3_3a_0_5d_ : value<4>{0u})) : i_3_5c_tokens0_5b_3_3a_0_5d_) : value<4>{0u}));
	// \full_case: 1
	// \src: receiver.v:116.17-116.17|receiver.v:116.6-116.104
	// cell $procmux$1057_CMP0
	i_procmux_24_1015__CMP = logic_not<1>(i_9_5c_qo_5b_2_5d__5b_1_3a_0_5d_);
	// cells $procmux$1182 $procmux$1179 $procmux$1177 $procmux$1145 $add$receiver.v:116$252 $auto$opt_reduce.cc:131:opt_pmux$6869
	i_5_5c_tokens1_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_lt_24_receiver_2e_v_3a_115_24_250__Y ? (i_procmux_24_1106__CMP ? add_uu<4>(i_3_5c_tokens1_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_1107__CMP.concat(i_procmux_24_1105__CMP).concat(i_procmux_24_1104__CMP).val()) ? i_3_5c_tokens1_5b_3_3a_0_5d_ : value<4>{0u})) : i_3_5c_tokens1_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$1173 $procmux$1170 $procmux$1168 $procmux$1131 $add$receiver.v:116$253 $auto$opt_reduce.cc:131:opt_pmux$6871
	i_5_5c_tokens2_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_lt_24_receiver_2e_v_3a_115_24_250__Y ? (i_procmux_24_1105__CMP ? add_uu<4>(i_3_5c_tokens2_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_1107__CMP.concat(i_procmux_24_1106__CMP).concat(i_procmux_24_1104__CMP).val()) ? i_3_5c_tokens2_5b_3_3a_0_5d_ : value<4>{0u})) : i_3_5c_tokens2_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$1164 $procmux$1161 $procmux$1159 $procmux$1117 $add$receiver.v:116$254 $auto$opt_reduce.cc:131:opt_pmux$6875
	i_5_5c_tokens3_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_lt_24_receiver_2e_v_3a_115_24_250__Y ? (reduce_or<1>(i_procmux_24_1107__CMP.concat(i_procmux_24_1106__CMP).concat(i_procmux_24_1105__CMP).val()) ? i_3_5c_tokens3_5b_3_3a_0_5d_ : (i_procmux_24_1104__CMP ? add_uu<4>(i_3_5c_tokens3_5b_3_3a_0_5d_, value<1>{0x1u}) : value<4>{0u})) : i_3_5c_tokens3_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$4617 $procmux$4312 $procmux$3966
	i_3_5c_qo_5b_5_5d__5b_1_3a_0_5d_ = (i_5_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_121__Y ? p_qo_5b_5_5d_.curr : (i_procmux_24_3738__CMP ? i_5_5c_enqowner_5b_1_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6838 ? p_qo_5b_5_5d_.curr : value<2>{0u}))) : p_qo_5b_5_5d_.curr);
	// cell $auto$opt_reduce.cc:131:opt_pmux$6937
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6874 = reduce_or<1>(i_procmux_24_2648__CMP.concat(i_procmux_24_2647__CMP).concat(i_procmux_24_2646__CMP).concat(i_procmux_24_2645__CMP).concat(i_procmux_24_2644__CMP).concat(i_procmux_24_2642__CMP).concat(i_procmux_24_2641__CMP).val());
	// \src: receiver.v:115.8-115.14
	// cell $lt$receiver.v:115$255
	i_lt_24_receiver_2e_v_3a_115_24_255__Y = lt_uu<1>(value<2>{0x2u}, i_7_5c_qlen_5b_3_3a_0_5d_);
	// cell $auto$opt_reduce.cc:131:opt_pmux$6901
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6840 = reduce_or<1>(i_procmux_24_3743__CMP.concat(i_procmux_24_3742__CMP).concat(i_procmux_24_3741__CMP).concat(i_procmux_24_3740__CMP).concat(i_procmux_24_3739__CMP).concat(i_procmux_24_3738__CMP).concat(i_procmux_24_3736__CMP).val());
	// cells $procmux$2423 $procmux$2420 $procmux$2418 $procmux$2119
	i_9_5c_qo_5b_3_5d__5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_201__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_203__Y ? i_6_5c_qo_5b_4_5d__5b_1_3a_0_5d_ : i_6_5c_qo_5b_3_5d__5b_1_3a_0_5d_) : i_6_5c_qo_5b_3_5d__5b_1_3a_0_5d_) : value<2>{0u}));
	// cells $procmux$3522 $procmux$3217 $procmux$2871
	i_6_5c_qo_5b_5_5d__5b_1_3a_0_5d_ = (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_168__Y ? i_3_5c_qo_5b_5_5d__5b_1_3a_0_5d_ : (i_procmux_24_2643__CMP ? i_8_5c_releaseowner_5b_1_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6874 ? i_3_5c_qo_5b_5_5d__5b_1_3a_0_5d_ : value<2>{0u}))) : i_3_5c_qo_5b_5_5d__5b_1_3a_0_5d_);
	// \full_case: 1
	// \src: receiver.v:116.37-116.37|receiver.v:116.6-116.104
	// cell $procmux$964_CMP0
	i_procmux_24_922__CMP = eq_uu<1>(i_9_5c_qo_5b_3_5d__5b_1_3a_0_5d_, value<1>{0x1u});
	// \full_case: 1
	// \src: receiver.v:116.57-116.57|receiver.v:116.6-116.104
	// cell $procmux$963_CMP0
	i_procmux_24_921__CMP = eq_uu<1>(i_9_5c_qo_5b_3_5d__5b_1_3a_0_5d_, value<2>{0x2u});
	// \full_case: 1
	// \src: receiver.v:116.77-116.77|receiver.v:116.6-116.104
	// cell $procmux$962_CMP0
	i_procmux_24_920__CMP = eq_uu<1>(i_9_5c_qo_5b_3_5d__5b_1_3a_0_5d_, value<2>{0x3u});
	// cells $procmux$1099 $procmux$1096 $procmux$1094 $procmux$1011 $add$receiver.v:116$256 $auto$opt_reduce.cc:131:opt_pmux$6891
	i_7_5c_tokens0_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_lt_24_receiver_2e_v_3a_115_24_255__Y ? (i_procmux_24_1015__CMP ? add_uu<4>(i_5_5c_tokens0_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_1014__CMP.concat(i_procmux_24_1013__CMP).concat(i_procmux_24_1012__CMP).val()) ? i_5_5c_tokens0_5b_3_3a_0_5d_ : value<4>{0u})) : i_5_5c_tokens0_5b_3_3a_0_5d_) : value<4>{0u}));
	// \full_case: 1
	// \src: receiver.v:116.17-116.17|receiver.v:116.6-116.104
	// cell $procmux$965_CMP0
	i_procmux_24_923__CMP = logic_not<1>(i_9_5c_qo_5b_3_5d__5b_1_3a_0_5d_);
	// cells $procmux$1090 $procmux$1087 $procmux$1085 $procmux$1053 $add$receiver.v:116$257 $auto$opt_reduce.cc:131:opt_pmux$6881
	i_7_5c_tokens1_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_lt_24_receiver_2e_v_3a_115_24_255__Y ? (i_procmux_24_1014__CMP ? add_uu<4>(i_5_5c_tokens1_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_1015__CMP.concat(i_procmux_24_1013__CMP).concat(i_procmux_24_1012__CMP).val()) ? i_5_5c_tokens1_5b_3_3a_0_5d_ : value<4>{0u})) : i_5_5c_tokens1_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$1081 $procmux$1078 $procmux$1076 $procmux$1039 $add$receiver.v:116$258 $auto$opt_reduce.cc:131:opt_pmux$6885
	i_7_5c_tokens2_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_lt_24_receiver_2e_v_3a_115_24_255__Y ? (i_procmux_24_1013__CMP ? add_uu<4>(i_5_5c_tokens2_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_1015__CMP.concat(i_procmux_24_1014__CMP).concat(i_procmux_24_1012__CMP).val()) ? i_5_5c_tokens2_5b_3_3a_0_5d_ : value<4>{0u})) : i_5_5c_tokens2_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$1072 $procmux$1069 $procmux$1067 $procmux$1025 $add$receiver.v:116$259 $auto$opt_reduce.cc:131:opt_pmux$6887
	i_7_5c_tokens3_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_lt_24_receiver_2e_v_3a_115_24_255__Y ? (reduce_or<1>(i_procmux_24_1015__CMP.concat(i_procmux_24_1014__CMP).concat(i_procmux_24_1013__CMP).val()) ? i_5_5c_tokens3_5b_3_3a_0_5d_ : (i_procmux_24_1012__CMP ? add_uu<4>(i_5_5c_tokens3_5b_3_3a_0_5d_, value<1>{0x1u}) : value<4>{0u})) : i_5_5c_tokens3_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$4608 $procmux$4300 $procmux$3945
	i_3_5c_qo_5b_6_5d__5b_1_3a_0_5d_ = (i_5_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_121__Y ? p_qo_5b_6_5d_.curr : (i_procmux_24_3737__CMP ? i_5_5c_enqowner_5b_1_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6840 ? p_qo_5b_6_5d_.curr : value<2>{0u}))) : p_qo_5b_6_5d_.curr);
	// cell $auto$opt_reduce.cc:131:opt_pmux$6943
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6884 = reduce_or<1>(i_procmux_24_2648__CMP.concat(i_procmux_24_2647__CMP).concat(i_procmux_24_2646__CMP).concat(i_procmux_24_2645__CMP).concat(i_procmux_24_2644__CMP).concat(i_procmux_24_2643__CMP).concat(i_procmux_24_2641__CMP).val());
	// \src: receiver.v:115.8-115.14
	// cell $lt$receiver.v:115$260
	i_lt_24_receiver_2e_v_3a_115_24_260__Y = lt_uu<1>(value<2>{0x3u}, i_7_5c_qlen_5b_3_3a_0_5d_);
	// cell $auto$opt_reduce.cc:131:opt_pmux$6917
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6842 = reduce_or<1>(i_procmux_24_3743__CMP.concat(i_procmux_24_3742__CMP).concat(i_procmux_24_3741__CMP).concat(i_procmux_24_3740__CMP).concat(i_procmux_24_3739__CMP).concat(i_procmux_24_3738__CMP).concat(i_procmux_24_3737__CMP).val());
	// cells $procmux$2414 $procmux$2411 $procmux$2409 $procmux$2107
	i_9_5c_qo_5b_4_5d__5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_201__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_203__Y ? i_6_5c_qo_5b_5_5d__5b_1_3a_0_5d_ : i_6_5c_qo_5b_4_5d__5b_1_3a_0_5d_) : i_6_5c_qo_5b_4_5d__5b_1_3a_0_5d_) : value<2>{0u}));
	// cells $procmux$3513 $procmux$3205 $procmux$2850
	i_6_5c_qo_5b_6_5d__5b_1_3a_0_5d_ = (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_168__Y ? i_3_5c_qo_5b_6_5d__5b_1_3a_0_5d_ : (i_procmux_24_2642__CMP ? i_8_5c_releaseowner_5b_1_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6884 ? i_3_5c_qo_5b_6_5d__5b_1_3a_0_5d_ : value<2>{0u}))) : i_3_5c_qo_5b_6_5d__5b_1_3a_0_5d_);
	// \full_case: 1
	// \src: receiver.v:116.37-116.37|receiver.v:116.6-116.104
	// cell $procmux$872_CMP0
	i_procmux_24_830__CMP = eq_uu<1>(i_9_5c_qo_5b_4_5d__5b_1_3a_0_5d_, value<1>{0x1u});
	// \full_case: 1
	// \src: receiver.v:116.57-116.57|receiver.v:116.6-116.104
	// cell $procmux$871_CMP0
	i_procmux_24_829__CMP = eq_uu<1>(i_9_5c_qo_5b_4_5d__5b_1_3a_0_5d_, value<2>{0x2u});
	// \full_case: 1
	// \src: receiver.v:116.77-116.77|receiver.v:116.6-116.104
	// cell $procmux$870_CMP0
	i_procmux_24_828__CMP = eq_uu<1>(i_9_5c_qo_5b_4_5d__5b_1_3a_0_5d_, value<2>{0x3u});
	// cells $procmux$1007 $procmux$1004 $procmux$1002 $procmux$919 $add$receiver.v:116$261 $auto$opt_reduce.cc:131:opt_pmux$6903
	i_9_5c_tokens0_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_lt_24_receiver_2e_v_3a_115_24_260__Y ? (i_procmux_24_923__CMP ? add_uu<4>(i_7_5c_tokens0_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_922__CMP.concat(i_procmux_24_921__CMP).concat(i_procmux_24_920__CMP).val()) ? i_7_5c_tokens0_5b_3_3a_0_5d_ : value<4>{0u})) : i_7_5c_tokens0_5b_3_3a_0_5d_) : value<4>{0u}));
	// \full_case: 1
	// \src: receiver.v:116.17-116.17|receiver.v:116.6-116.104
	// cell $procmux$873_CMP0
	i_procmux_24_831__CMP = logic_not<1>(i_9_5c_qo_5b_4_5d__5b_1_3a_0_5d_);
	// cells $procmux$998 $procmux$995 $procmux$993 $procmux$961 $add$receiver.v:116$262 $auto$opt_reduce.cc:131:opt_pmux$6893
	i_9_5c_tokens1_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_lt_24_receiver_2e_v_3a_115_24_260__Y ? (i_procmux_24_922__CMP ? add_uu<4>(i_7_5c_tokens1_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_923__CMP.concat(i_procmux_24_921__CMP).concat(i_procmux_24_920__CMP).val()) ? i_7_5c_tokens1_5b_3_3a_0_5d_ : value<4>{0u})) : i_7_5c_tokens1_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$989 $procmux$986 $procmux$984 $procmux$947 $add$receiver.v:116$263 $auto$opt_reduce.cc:131:opt_pmux$6895
	i_9_5c_tokens2_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_lt_24_receiver_2e_v_3a_115_24_260__Y ? (i_procmux_24_921__CMP ? add_uu<4>(i_7_5c_tokens2_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_923__CMP.concat(i_procmux_24_922__CMP).concat(i_procmux_24_920__CMP).val()) ? i_7_5c_tokens2_5b_3_3a_0_5d_ : value<4>{0u})) : i_7_5c_tokens2_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$980 $procmux$977 $procmux$975 $procmux$933 $add$receiver.v:116$264 $auto$opt_reduce.cc:131:opt_pmux$6899
	i_9_5c_tokens3_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_lt_24_receiver_2e_v_3a_115_24_260__Y ? (reduce_or<1>(i_procmux_24_923__CMP.concat(i_procmux_24_922__CMP).concat(i_procmux_24_921__CMP).val()) ? i_7_5c_tokens3_5b_3_3a_0_5d_ : (i_procmux_24_920__CMP ? add_uu<4>(i_7_5c_tokens3_5b_3_3a_0_5d_, value<1>{0x1u}) : value<4>{0u})) : i_7_5c_tokens3_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$4599 $procmux$4288 $procmux$3924
	i_3_5c_qo_5b_7_5d__5b_1_3a_0_5d_ = (i_5_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_121__Y ? p_qo_5b_7_5d_.curr : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6842 ? p_qo_5b_7_5d_.curr : (i_procmux_24_3736__CMP ? i_5_5c_enqowner_5b_1_3a_0_5d_ : value<2>{0u}))) : p_qo_5b_7_5d_.curr);
	// cell $auto$opt_reduce.cc:131:opt_pmux$6951
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6890 = reduce_or<1>(i_procmux_24_2648__CMP.concat(i_procmux_24_2647__CMP).concat(i_procmux_24_2646__CMP).concat(i_procmux_24_2645__CMP).concat(i_procmux_24_2644__CMP).concat(i_procmux_24_2643__CMP).concat(i_procmux_24_2642__CMP).val());
	// \src: receiver.v:115.8-115.14
	// cell $lt$receiver.v:115$265
	i_lt_24_receiver_2e_v_3a_115_24_265__Y = lt_uu<1>(value<3>{0x4u}, i_7_5c_qlen_5b_3_3a_0_5d_);
	// cells $procmux$2405 $procmux$2402 $procmux$2400 $procmux$2095
	i_9_5c_qo_5b_5_5d__5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_201__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_203__Y ? i_6_5c_qo_5b_6_5d__5b_1_3a_0_5d_ : i_6_5c_qo_5b_5_5d__5b_1_3a_0_5d_) : i_6_5c_qo_5b_5_5d__5b_1_3a_0_5d_) : value<2>{0u}));
	// cells $procmux$3504 $procmux$3193 $procmux$2829
	i_6_5c_qo_5b_7_5d__5b_1_3a_0_5d_ = (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_168__Y ? i_3_5c_qo_5b_7_5d__5b_1_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6890 ? i_3_5c_qo_5b_7_5d__5b_1_3a_0_5d_ : (i_procmux_24_2641__CMP ? i_8_5c_releaseowner_5b_1_3a_0_5d_ : value<2>{0u}))) : i_3_5c_qo_5b_7_5d__5b_1_3a_0_5d_);
	// \full_case: 1
	// \src: receiver.v:116.37-116.37|receiver.v:116.6-116.104
	// cell $procmux$780_CMP0
	i_procmux_24_738__CMP = eq_uu<1>(i_9_5c_qo_5b_5_5d__5b_1_3a_0_5d_, value<1>{0x1u});
	// \full_case: 1
	// \src: receiver.v:116.57-116.57|receiver.v:116.6-116.104
	// cell $procmux$779_CMP0
	i_procmux_24_737__CMP = eq_uu<1>(i_9_5c_qo_5b_5_5d__5b_1_3a_0_5d_, value<2>{0x2u});
	// \full_case: 1
	// \src: receiver.v:116.77-116.77|receiver.v:116.6-116.104
	// cell $procmux$778_CMP0
	i_procmux_24_736__CMP = eq_uu<1>(i_9_5c_qo_5b_5_5d__5b_1_3a_0_5d_, value<2>{0x3u});
	// cells $procmux$915 $procmux$912 $procmux$910 $procmux$827 $add$receiver.v:116$266 $auto$opt_reduce.cc:131:opt_pmux$6915
	i_11_5c_tokens0_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_lt_24_receiver_2e_v_3a_115_24_265__Y ? (i_procmux_24_831__CMP ? add_uu<4>(i_9_5c_tokens0_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_830__CMP.concat(i_procmux_24_829__CMP).concat(i_procmux_24_828__CMP).val()) ? i_9_5c_tokens0_5b_3_3a_0_5d_ : value<4>{0u})) : i_9_5c_tokens0_5b_3_3a_0_5d_) : value<4>{0u}));
	// \full_case: 1
	// \src: receiver.v:116.17-116.17|receiver.v:116.6-116.104
	// cell $procmux$781_CMP0
	i_procmux_24_739__CMP = logic_not<1>(i_9_5c_qo_5b_5_5d__5b_1_3a_0_5d_);
	// cells $procmux$906 $procmux$903 $procmux$901 $procmux$869 $add$receiver.v:116$267 $auto$opt_reduce.cc:131:opt_pmux$6907
	i_11_5c_tokens1_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_lt_24_receiver_2e_v_3a_115_24_265__Y ? (i_procmux_24_830__CMP ? add_uu<4>(i_9_5c_tokens1_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_831__CMP.concat(i_procmux_24_829__CMP).concat(i_procmux_24_828__CMP).val()) ? i_9_5c_tokens1_5b_3_3a_0_5d_ : value<4>{0u})) : i_9_5c_tokens1_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$897 $procmux$894 $procmux$892 $procmux$855 $add$receiver.v:116$268 $auto$opt_reduce.cc:131:opt_pmux$6909
	i_11_5c_tokens2_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_lt_24_receiver_2e_v_3a_115_24_265__Y ? (i_procmux_24_829__CMP ? add_uu<4>(i_9_5c_tokens2_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_831__CMP.concat(i_procmux_24_830__CMP).concat(i_procmux_24_828__CMP).val()) ? i_9_5c_tokens2_5b_3_3a_0_5d_ : value<4>{0u})) : i_9_5c_tokens2_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$888 $procmux$885 $procmux$883 $procmux$841 $add$receiver.v:116$269 $auto$opt_reduce.cc:131:opt_pmux$6911
	i_11_5c_tokens3_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_lt_24_receiver_2e_v_3a_115_24_265__Y ? (reduce_or<1>(i_procmux_24_831__CMP.concat(i_procmux_24_830__CMP).concat(i_procmux_24_829__CMP).val()) ? i_9_5c_tokens3_5b_3_3a_0_5d_ : (i_procmux_24_828__CMP ? add_uu<4>(i_9_5c_tokens3_5b_3_3a_0_5d_, value<1>{0x1u}) : value<4>{0u})) : i_9_5c_tokens3_5b_3_3a_0_5d_) : value<4>{0u}));
	// \src: receiver.v:83.7-83.70
	// cell $neg$receiver.v:83$147
	i_neg_24_receiver_2e_v_3a_83_24_139__Y = neg_u<33>(i_add_24_receiver_2e_v_3a_82_24_133__Y);
	// \src: receiver.v:83.7-83.70
	// cell $shift$receiver.v:83$140
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7040.slice<15,0>() = shift_us<16>(value<4>{0xfu}, i_neg_24_receiver_2e_v_3a_83_24_139__Y);
	// \src: receiver.v:115.8-115.14
	// cell $lt$receiver.v:115$270
	i_lt_24_receiver_2e_v_3a_115_24_270__Y = lt_uu<1>(value<3>{0x5u}, i_7_5c_qlen_5b_3_3a_0_5d_);
	// \src: receiver.v:83.7-83.70
	// cell $not$receiver.v:83$141
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7039.slice<15,0>() = not_u<16>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7040.slice<15,0>().val());
	// cells $shift$receiver.v:83$148 $add$receiver.v:83$146
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7036.slice<15,0>() = shift_us<16>(add_uu<4>(i_shiftx_24_receiver_2e_v_3a_82_24_134__Y, value<1>{0x1u}), i_neg_24_receiver_2e_v_3a_83_24_139__Y);
	// cells $procmux$2396 $procmux$2393 $procmux$2391 $procmux$2083
	i_9_5c_qo_5b_6_5d__5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_201__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_203__Y ? i_6_5c_qo_5b_7_5d__5b_1_3a_0_5d_ : i_6_5c_qo_5b_6_5d__5b_1_3a_0_5d_) : i_6_5c_qo_5b_6_5d__5b_1_3a_0_5d_) : value<2>{0u}));
	// cells $or$receiver.v:83$149 $and$receiver.v:83$142
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7035.slice<15,0>() = or_uu<16>(and_uu<16>(p_outstanding.curr, i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7039.slice<15,0>().val()), i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7036.slice<15,0>().val());
	// \full_case: 1
	// \src: receiver.v:116.37-116.37|receiver.v:116.6-116.104
	// cell $procmux$688_CMP0
	i_procmux_24_646__CMP = eq_uu<1>(i_9_5c_qo_5b_6_5d__5b_1_3a_0_5d_, value<1>{0x1u});
	// \full_case: 1
	// \src: receiver.v:116.57-116.57|receiver.v:116.6-116.104
	// cell $procmux$687_CMP0
	i_procmux_24_645__CMP = eq_uu<1>(i_9_5c_qo_5b_6_5d__5b_1_3a_0_5d_, value<2>{0x2u});
	// \full_case: 1
	// \src: receiver.v:116.77-116.77|receiver.v:116.6-116.104
	// cell $procmux$686_CMP0
	i_procmux_24_644__CMP = eq_uu<1>(i_9_5c_qo_5b_6_5d__5b_1_3a_0_5d_, value<2>{0x3u});
	// cells $procmux$823 $procmux$820 $procmux$818 $procmux$735 $add$receiver.v:116$271 $auto$opt_reduce.cc:131:opt_pmux$6929
	i_13_5c_tokens0_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_lt_24_receiver_2e_v_3a_115_24_270__Y ? (i_procmux_24_739__CMP ? add_uu<4>(i_11_5c_tokens0_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_738__CMP.concat(i_procmux_24_737__CMP).concat(i_procmux_24_736__CMP).val()) ? i_11_5c_tokens0_5b_3_3a_0_5d_ : value<4>{0u})) : i_11_5c_tokens0_5b_3_3a_0_5d_) : value<4>{0u}));
	// \full_case: 1
	// \src: receiver.v:116.17-116.17|receiver.v:116.6-116.104
	// cell $procmux$689_CMP0
	i_procmux_24_647__CMP = logic_not<1>(i_9_5c_qo_5b_6_5d__5b_1_3a_0_5d_);
	// cells $procmux$814 $procmux$811 $procmux$809 $procmux$777 $add$receiver.v:116$272 $auto$opt_reduce.cc:131:opt_pmux$6919
	i_13_5c_tokens1_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_lt_24_receiver_2e_v_3a_115_24_270__Y ? (i_procmux_24_738__CMP ? add_uu<4>(i_11_5c_tokens1_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_739__CMP.concat(i_procmux_24_737__CMP).concat(i_procmux_24_736__CMP).val()) ? i_11_5c_tokens1_5b_3_3a_0_5d_ : value<4>{0u})) : i_11_5c_tokens1_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$805 $procmux$802 $procmux$800 $procmux$763 $add$receiver.v:116$273 $auto$opt_reduce.cc:131:opt_pmux$6923
	i_13_5c_tokens2_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_lt_24_receiver_2e_v_3a_115_24_270__Y ? (i_procmux_24_737__CMP ? add_uu<4>(i_11_5c_tokens2_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_739__CMP.concat(i_procmux_24_738__CMP).concat(i_procmux_24_736__CMP).val()) ? i_11_5c_tokens2_5b_3_3a_0_5d_ : value<4>{0u})) : i_11_5c_tokens2_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$796 $procmux$793 $procmux$791 $procmux$749 $add$receiver.v:116$274 $auto$opt_reduce.cc:131:opt_pmux$6925
	i_13_5c_tokens3_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_lt_24_receiver_2e_v_3a_115_24_270__Y ? (reduce_or<1>(i_procmux_24_739__CMP.concat(i_procmux_24_738__CMP).concat(i_procmux_24_737__CMP).val()) ? i_11_5c_tokens3_5b_3_3a_0_5d_ : (i_procmux_24_736__CMP ? add_uu<4>(i_11_5c_tokens3_5b_3_3a_0_5d_, value<1>{0x1u}) : value<4>{0u})) : i_11_5c_tokens3_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $logic_or$receiver.v:100$222 $eq$receiver.v:100$220 $eq$receiver.v:100$221
	i_logic__or_24_receiver_2e_v_3a_100_24_222__Y = logic_or<1>(eq_uu<1>(p_rp.curr, value<1>{0x1u}), eq_uu<1>(p_rp.curr, value<2>{0x2u}));
	// \src: receiver.v:83.50-83.64
	// cell $mul$receiver.v:83$190
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7031.slice<4,0>() = mul_uu<5>(value<3>{0x4u}, i_8_5c_releaseowner_5b_1_3a_0_5d_);
	// connection
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7031.slice<31,5>() = value<27>{0u};
	// \src: receiver.v:115.8-115.14
	// cell $lt$receiver.v:115$275
	i_lt_24_receiver_2e_v_3a_115_24_275__Y = lt_uu<1>(value<3>{0x6u}, i_7_5c_qlen_5b_3_3a_0_5d_);
	// \src: receiver.v:83.49-83.68
	// cell $add$receiver.v:83$191
	i_add_24_receiver_2e_v_3a_82_24_180__Y = add_uu<6>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7031.slice<4,0>().val(), value<1>{0u});
	// cells $procmux$2549 $procmux$2546 $procmux$2544 $procmux$1963
	i_3_5c_failed_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_201__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_203__Y ? p_failed.curr : value<1>{0x1u}) : p_failed.curr) : value<1>{0u}));
	// cells $procmux$1717 $procmux$1619
	i_4_5c_evblock_5b_0_3a_0_5d_ = (p_rone.curr ? (i_logic__or_24_receiver_2e_v_3a_100_24_222__Y ? value<1>{0u} : value<1>{0x1u}) : value<1>{0u});
	// cells $procmux$4739 $procmux$4736 $procmux$4734 $procmux$4456
	i_3_5c_outstanding_5b_15_3a_0_5d_ = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_5_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_121__Y ? p_outstanding.curr : i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7035.slice<15,0>().val()) : p_outstanding.curr) : value<16>{0u}));
	// \src: receiver.v:83.7-83.70
	// cell $neg$receiver.v:83$194
	i_neg_24_receiver_2e_v_3a_83_24_186__Y = neg_u<33>(i_add_24_receiver_2e_v_3a_82_24_180__Y);
	// cells $procmux$2387 $procmux$2384 $procmux$2382 $procmux$2071
	i_9_5c_qo_5b_7_5d__5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_201__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_203__Y ? value<2>{0u} : i_6_5c_qo_5b_7_5d__5b_1_3a_0_5d_) : i_6_5c_qo_5b_7_5d__5b_1_3a_0_5d_) : value<2>{0u}));
	// \src: receiver.v:83.49-83.68
	// cell $shiftx$receiver.v:83$192
	i_shiftx_24_receiver_2e_v_3a_82_24_181__Y = shiftx_us<4>(i_3_5c_outstanding_5b_15_3a_0_5d_, value<1>{0u}.concat(i_add_24_receiver_2e_v_3a_82_24_180__Y).val());
	// \src: receiver.v:83.7-83.70
	// cell $shift$receiver.v:83$187
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7029.slice<15,0>() = shift_us<16>(value<4>{0xfu}, i_neg_24_receiver_2e_v_3a_83_24_186__Y);
	// \full_case: 1
	// \src: receiver.v:116.37-116.37|receiver.v:116.6-116.104
	// cell $procmux$596_CMP0
	i_procmux_24_554__CMP = eq_uu<1>(i_9_5c_qo_5b_7_5d__5b_1_3a_0_5d_, value<1>{0x1u});
	// \full_case: 1
	// \src: receiver.v:116.57-116.57|receiver.v:116.6-116.104
	// cell $procmux$595_CMP0
	i_procmux_24_553__CMP = eq_uu<1>(i_9_5c_qo_5b_7_5d__5b_1_3a_0_5d_, value<2>{0x2u});
	// \full_case: 1
	// \src: receiver.v:116.77-116.77|receiver.v:116.6-116.104
	// cell $procmux$594_CMP0
	i_procmux_24_552__CMP = eq_uu<1>(i_9_5c_qo_5b_7_5d__5b_1_3a_0_5d_, value<2>{0x3u});
	// cells $procmux$731 $procmux$728 $procmux$726 $procmux$643 $add$receiver.v:116$276 $auto$opt_reduce.cc:131:opt_pmux$6941
	i_15_5c_tokens0_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_lt_24_receiver_2e_v_3a_115_24_275__Y ? (i_procmux_24_647__CMP ? add_uu<4>(i_13_5c_tokens0_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_646__CMP.concat(i_procmux_24_645__CMP).concat(i_procmux_24_644__CMP).val()) ? i_13_5c_tokens0_5b_3_3a_0_5d_ : value<4>{0u})) : i_13_5c_tokens0_5b_3_3a_0_5d_) : value<4>{0u}));
	// \full_case: 1
	// \src: receiver.v:116.17-116.17|receiver.v:116.6-116.104
	// cell $procmux$597_CMP0
	i_procmux_24_555__CMP = logic_not<1>(i_9_5c_qo_5b_7_5d__5b_1_3a_0_5d_);
	// cells $procmux$722 $procmux$719 $procmux$717 $procmux$685 $add$receiver.v:116$277 $auto$opt_reduce.cc:131:opt_pmux$6933
	i_15_5c_tokens1_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_lt_24_receiver_2e_v_3a_115_24_275__Y ? (i_procmux_24_646__CMP ? add_uu<4>(i_13_5c_tokens1_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_647__CMP.concat(i_procmux_24_645__CMP).concat(i_procmux_24_644__CMP).val()) ? i_13_5c_tokens1_5b_3_3a_0_5d_ : value<4>{0u})) : i_13_5c_tokens1_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$713 $procmux$710 $procmux$708 $procmux$671 $add$receiver.v:116$278 $auto$opt_reduce.cc:131:opt_pmux$6935
	i_15_5c_tokens2_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_lt_24_receiver_2e_v_3a_115_24_275__Y ? (i_procmux_24_645__CMP ? add_uu<4>(i_13_5c_tokens2_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_647__CMP.concat(i_procmux_24_646__CMP).concat(i_procmux_24_644__CMP).val()) ? i_13_5c_tokens2_5b_3_3a_0_5d_ : value<4>{0u})) : i_13_5c_tokens2_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$704 $procmux$701 $procmux$699 $procmux$657 $add$receiver.v:116$279 $auto$opt_reduce.cc:131:opt_pmux$6939
	i_15_5c_tokens3_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_lt_24_receiver_2e_v_3a_115_24_275__Y ? (reduce_or<1>(i_procmux_24_647__CMP.concat(i_procmux_24_646__CMP).concat(i_procmux_24_645__CMP).val()) ? i_13_5c_tokens3_5b_3_3a_0_5d_ : (i_procmux_24_644__CMP ? add_uu<4>(i_13_5c_tokens3_5b_3_3a_0_5d_, value<1>{0x1u}) : value<4>{0u})) : i_13_5c_tokens3_5b_3_3a_0_5d_) : value<4>{0u}));
	// \src: receiver.v:83.7-83.70
	// cell $not$receiver.v:83$188
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7028.slice<15,0>() = not_u<16>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7029.slice<15,0>().val());
	// cells $procmux$1724 $procmux$1721 $procmux$1719
	i_4_5c_rone_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? value<1>{0u} : i_4_5c_evblock_5b_0_3a_0_5d_) : value<1>{0u}));
	// cells $shift$receiver.v:83$195 $add$receiver.v:83$193
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7025.slice<15,0>() = shift_us<16>(add_uu<4>(i_shiftx_24_receiver_2e_v_3a_82_24_181__Y, value<1>{0x1u}), i_neg_24_receiver_2e_v_3a_83_24_186__Y);
	// \src: receiver.v:115.8-115.14
	// cell $lt$receiver.v:115$280
	i_lt_24_receiver_2e_v_3a_115_24_280__Y = lt_uu<1>(value<3>{0x7u}, i_7_5c_qlen_5b_3_3a_0_5d_);
	// cells $procmux$2585 $procmux$2582 $procmux$2580 $procmux$2287
	i_3_5c_rzero_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_201__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_203__Y ? value<1>{0x1u} : p_rzero.curr) : p_rzero.curr) : value<1>{0u}));
	// cells $or$receiver.v:83$196 $and$receiver.v:83$189
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7024.slice<15,0>() = or_uu<16>(and_uu<16>(i_3_5c_outstanding_5b_15_3a_0_5d_, i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7028.slice<15,0>().val()), i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7025.slice<15,0>().val());
	// cells $logic_and$receiver.v:103$224 $logic_not$receiver.v:103$223
	i_logic__and_24_receiver_2e_v_3a_103_24_224__Y = logic_and<1>(i_3_5c_rzero_5b_0_3a_0_5d_, logic_not<1>(i_4_5c_rone_5b_0_3a_0_5d_));
	// cells $procmux$1688 $procmux$1685 $procmux$1683 $procmux$1681 $procmux$1559
	i_4_5c_emitowner_5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? value<2>{0u} : (p_rone.curr ? (i_logic__or_24_receiver_2e_v_3a_100_24_222__Y ? p_ownerone.curr : p_emitowner.curr) : p_emitowner.curr)) : value<2>{0u}));
	// cells $procmux$2576 $procmux$2573 $procmux$2571 $procmux$2275
	i_3_5c_ownerzero_5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_201__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_203__Y ? i_6_5c_qo_5b_0_5d__5b_1_3a_0_5d_ : p_ownerzero.curr) : p_ownerzero.curr) : value<2>{0u}));
	// \src: receiver.v:110.51-110.62
	// cell $mul$receiver.v:110$238
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7020.slice<4,0>() = mul_uu<5>(value<3>{0x4u}, i_4_5c_emitowner_5b_1_3a_0_5d_);
	// connection
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7020.slice<31,5>() = value<27>{0u};
	// \full_case: 1
	// \src: receiver.v:119.48-119.48|receiver.v:119.13-119.115
	// cell $procmux$504_CMP0
	i_procmux_24_462__CMP = eq_uu<1>(i_3_5c_ownerzero_5b_1_3a_0_5d_, value<1>{0x1u});
	// \full_case: 1
	// \src: receiver.v:119.68-119.68|receiver.v:119.13-119.115
	// cell $procmux$503_CMP0
	i_procmux_24_461__CMP = eq_uu<1>(i_3_5c_ownerzero_5b_1_3a_0_5d_, value<2>{0x2u});
	// \full_case: 1
	// \src: receiver.v:119.88-119.88|receiver.v:119.13-119.115
	// cell $procmux$502_CMP0
	i_procmux_24_460__CMP = eq_uu<1>(i_3_5c_ownerzero_5b_1_3a_0_5d_, value<2>{0x3u});
	// cells $procmux$639 $procmux$636 $procmux$634 $procmux$551 $add$receiver.v:116$281 $auto$opt_reduce.cc:131:opt_pmux$6953
	i_17_5c_tokens0_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_lt_24_receiver_2e_v_3a_115_24_280__Y ? (i_procmux_24_555__CMP ? add_uu<4>(i_15_5c_tokens0_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_554__CMP.concat(i_procmux_24_553__CMP).concat(i_procmux_24_552__CMP).val()) ? i_15_5c_tokens0_5b_3_3a_0_5d_ : value<4>{0u})) : i_15_5c_tokens0_5b_3_3a_0_5d_) : value<4>{0u}));
	// \full_case: 1
	// \src: receiver.v:119.28-119.28|receiver.v:119.13-119.115
	// cell $procmux$505_CMP0
	i_procmux_24_463__CMP = logic_not<1>(i_3_5c_ownerzero_5b_1_3a_0_5d_);
	// cells $procmux$630 $procmux$627 $procmux$625 $procmux$593 $add$receiver.v:116$282 $auto$opt_reduce.cc:131:opt_pmux$6945
	i_17_5c_tokens1_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_lt_24_receiver_2e_v_3a_115_24_280__Y ? (i_procmux_24_554__CMP ? add_uu<4>(i_15_5c_tokens1_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_555__CMP.concat(i_procmux_24_553__CMP).concat(i_procmux_24_552__CMP).val()) ? i_15_5c_tokens1_5b_3_3a_0_5d_ : value<4>{0u})) : i_15_5c_tokens1_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$621 $procmux$618 $procmux$616 $procmux$579 $add$receiver.v:116$283 $auto$opt_reduce.cc:131:opt_pmux$6947
	i_17_5c_tokens2_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_lt_24_receiver_2e_v_3a_115_24_280__Y ? (i_procmux_24_553__CMP ? add_uu<4>(i_15_5c_tokens2_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_555__CMP.concat(i_procmux_24_554__CMP).concat(i_procmux_24_552__CMP).val()) ? i_15_5c_tokens2_5b_3_3a_0_5d_ : value<4>{0u})) : i_15_5c_tokens2_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$612 $procmux$609 $procmux$607 $procmux$565 $add$receiver.v:116$284 $auto$opt_reduce.cc:131:opt_pmux$6949
	i_17_5c_tokens3_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_lt_24_receiver_2e_v_3a_115_24_280__Y ? (reduce_or<1>(i_procmux_24_555__CMP.concat(i_procmux_24_554__CMP).concat(i_procmux_24_553__CMP).val()) ? i_15_5c_tokens3_5b_3_3a_0_5d_ : (i_procmux_24_552__CMP ? add_uu<4>(i_15_5c_tokens3_5b_3_3a_0_5d_, value<1>{0x1u}) : value<4>{0u})) : i_15_5c_tokens3_5b_3_3a_0_5d_) : value<4>{0u}));
	// \src: receiver.v:110.50-110.66
	// cell $add$receiver.v:110$239
	i_add_24_receiver_2e_v_3a_109_24_227__Y = add_uu<6>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7020.slice<4,0>().val(), value<1>{0u});
	// cells $procmux$3644 $procmux$3641 $procmux$3639 $procmux$3361
	i_5_5c_outstanding_5b_15_3a_0_5d_ = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_168__Y ? i_3_5c_outstanding_5b_15_3a_0_5d_ : i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7024.slice<15,0>().val()) : i_3_5c_outstanding_5b_15_3a_0_5d_) : value<16>{0u}));
	// \src: receiver.v:110.11-110.68
	// cell $neg$receiver.v:110$242
	i_neg_24_receiver_2e_v_3a_110_24_234__Y = neg_u<33>(i_add_24_receiver_2e_v_3a_109_24_227__Y);
	// cells $procmux$1859 $procmux$1856 $procmux$1854 $procmux$1405
	i_5_5c_rzero_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? i_3_5c_rzero_5b_0_3a_0_5d_ : (i_logic__and_24_receiver_2e_v_3a_103_24_224__Y ? value<1>{0u} : i_3_5c_rzero_5b_0_3a_0_5d_)) : value<1>{0u}));
	// \src: receiver.v:110.50-110.66
	// cell $shiftx$receiver.v:110$240
	i_shiftx_24_receiver_2e_v_3a_109_24_228__Y = shiftx_us<4>(i_5_5c_outstanding_5b_15_3a_0_5d_, value<1>{0u}.concat(i_add_24_receiver_2e_v_3a_109_24_227__Y).val());
	// \src: receiver.v:110.11-110.68
	// cell $shift$receiver.v:110$235
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7018.slice<15,0>() = shift_us<16>(value<4>{0xfu}, i_neg_24_receiver_2e_v_3a_110_24_234__Y);
	// \src: receiver.v:110.39-110.68
	// cell $sub$receiver.v:110$241
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7015.slice<3,0>() = sub_uu<4>(i_shiftx_24_receiver_2e_v_3a_109_24_228__Y, value<1>{0x1u});
	// \src: receiver.v:110.11-110.68
	// cell $not$receiver.v:110$236
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7017.slice<15,0>() = not_u<16>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7018.slice<15,0>().val());
	// \full_case: 1
	// \src: receiver.v:75.8-75.20|receiver.v:75.5-85.8
	// cell $procmux$4725
	i_procmux_24_4725__Y.slice<3,0>() = (i_5_5c_releasevalid_5b_0_3a_0_5d_ ? i_14_5c_fault_5b_31_3a_0_5d_.curr.slice<3,0>().val() : i_4_5c_fault_5b_31_3a_0_5d_.slice<3,0>().val());
	// connection
	i_procmux_24_4725__Y.slice<31,4>() = i_14_5c_fault_5b_31_3a_0_5d_.curr.slice<31,4>().val();
	// cells $procmux$1841 $procmux$1838 $procmux$1836 $procmux$1441
	i_3_5c_ownerone_5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? p_ownerone.curr : (i_logic__and_24_receiver_2e_v_3a_103_24_224__Y ? i_3_5c_ownerzero_5b_1_3a_0_5d_ : p_ownerone.curr)) : value<2>{0u}));
	// \src: receiver.v:110.11-110.68
	// cell $shift$receiver.v:110$243
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7014.slice<15,0>() = shift_us<16>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7015.slice<3,0>().val(), i_neg_24_receiver_2e_v_3a_110_24_234__Y);
	// \full_case: 1
	// \src: receiver.v:120.46-120.46|receiver.v:120.12-120.113
	// cell $procmux$412_CMP0
	i_procmux_24_370__CMP = eq_uu<1>(i_3_5c_ownerone_5b_1_3a_0_5d_, value<1>{0x1u});
	// \full_case: 1
	// \src: receiver.v:120.66-120.66|receiver.v:120.12-120.113
	// cell $procmux$411_CMP0
	i_procmux_24_369__CMP = eq_uu<1>(i_3_5c_ownerone_5b_1_3a_0_5d_, value<2>{0x2u});
	// \full_case: 1
	// \src: receiver.v:120.86-120.86|receiver.v:120.12-120.113
	// cell $procmux$410_CMP0
	i_procmux_24_368__CMP = eq_uu<1>(i_3_5c_ownerone_5b_1_3a_0_5d_, value<2>{0x3u});
	// cells $procmux$547 $procmux$544 $procmux$542 $procmux$459 $add$receiver.v:119$285 $auto$opt_reduce.cc:131:opt_pmux$6963
	i_19_5c_tokens0_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_5_5c_rzero_5b_0_3a_0_5d_ ? (i_procmux_24_463__CMP ? add_uu<4>(i_17_5c_tokens0_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_462__CMP.concat(i_procmux_24_461__CMP).concat(i_procmux_24_460__CMP).val()) ? i_17_5c_tokens0_5b_3_3a_0_5d_ : value<4>{0u})) : i_17_5c_tokens0_5b_3_3a_0_5d_) : value<4>{0u}));
	// \full_case: 1
	// \src: receiver.v:120.26-120.26|receiver.v:120.12-120.113
	// cell $procmux$413_CMP0
	i_procmux_24_371__CMP = logic_not<1>(i_3_5c_ownerone_5b_1_3a_0_5d_);
	// cells $procmux$538 $procmux$535 $procmux$533 $procmux$501 $add$receiver.v:119$286 $auto$opt_reduce.cc:131:opt_pmux$6955
	i_19_5c_tokens1_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_5_5c_rzero_5b_0_3a_0_5d_ ? (i_procmux_24_462__CMP ? add_uu<4>(i_17_5c_tokens1_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_463__CMP.concat(i_procmux_24_461__CMP).concat(i_procmux_24_460__CMP).val()) ? i_17_5c_tokens1_5b_3_3a_0_5d_ : value<4>{0u})) : i_17_5c_tokens1_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$529 $procmux$526 $procmux$524 $procmux$487 $add$receiver.v:119$287 $auto$opt_reduce.cc:131:opt_pmux$6957
	i_19_5c_tokens2_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_5_5c_rzero_5b_0_3a_0_5d_ ? (i_procmux_24_461__CMP ? add_uu<4>(i_17_5c_tokens2_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_463__CMP.concat(i_procmux_24_462__CMP).concat(i_procmux_24_460__CMP).val()) ? i_17_5c_tokens2_5b_3_3a_0_5d_ : value<4>{0u})) : i_17_5c_tokens2_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$520 $procmux$517 $procmux$515 $procmux$473 $add$receiver.v:119$288 $auto$opt_reduce.cc:131:opt_pmux$6961
	i_19_5c_tokens3_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_5_5c_rzero_5b_0_3a_0_5d_ ? (reduce_or<1>(i_procmux_24_463__CMP.concat(i_procmux_24_462__CMP).concat(i_procmux_24_461__CMP).val()) ? i_17_5c_tokens3_5b_3_3a_0_5d_ : (i_procmux_24_460__CMP ? add_uu<4>(i_17_5c_tokens3_5b_3_3a_0_5d_, value<1>{0x1u}) : value<4>{0u})) : i_17_5c_tokens3_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $or$receiver.v:110$244 $and$receiver.v:110$237
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7013.slice<15,0>() = or_uu<16>(and_uu<16>(i_5_5c_outstanding_5b_15_3a_0_5d_, i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7017.slice<15,0>().val()), i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7014.slice<15,0>().val());
	// \src: receiver.v:109.9-109.39
	// cell $eq$receiver.v:109$229
	i_eq_24_receiver_2e_v_3a_109_24_229__Y = logic_not<1>(i_shiftx_24_receiver_2e_v_3a_109_24_228__Y);
	// cells $procmux$4730 $procmux$4727
	i_13_5c_fault_5b_31_3a_0_5d_ = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? i_14_5c_fault_5b_31_3a_0_5d_.curr.slice<31,4>().concat(i_procmux_24_4725__Y.slice<3,0>()).val() : value<32>{0u}));
	// cells $procmux$1712 $procmux$1709 $procmux$1707 $procmux$1705 $procmux$1574
	i_4_5c_evemit_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? value<1>{0u} : (p_rone.curr ? (i_logic__or_24_receiver_2e_v_3a_100_24_222__Y ? value<1>{0x1u} : value<1>{0u}) : value<1>{0u})) : value<1>{0u}));
	// cells $procmux$4757 $procmux$4754 $procmux$4752 $procmux$4480 $add$receiver.v:81$131
	i_3_5c_nextid_5b_31_3a_0_5d_ = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_5_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_121__Y ? p_nextid.curr : add_uu<32>(p_nextid.curr, value<1>{0x1u})) : p_nextid.curr) : value<32>{0u}));
	// cells $procmux$4590 $procmux$4276 $procmux$3735
	i_3_5c_qi_5b_0_5d__5b_31_3a_0_5d_ = (i_5_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_121__Y ? p_qi_5b_0_5d_.curr : (i_procmux_24_3743__CMP ? p_nextid.curr : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6844 ? p_qi_5b_0_5d_.curr : value<32>{0u}))) : p_qi_5b_0_5d_.curr);
	// cells $procmux$2626 $eq$receiver.v:82$182
	i_18_5c_fault_5b_31_3a_0_5d_.slice<3,0>() = (eq_uu<1>(i_shiftx_24_receiver_2e_v_3a_82_24_181__Y, value<4>{0xfu}) ? value<1>{0x1u}.concat(i_13_5c_fault_5b_31_3a_0_5d_.slice<2,0>()).val() : i_13_5c_fault_5b_31_3a_0_5d_.slice<3,0>().val());
	// connection
	i_18_5c_fault_5b_31_3a_0_5d_.slice<31,4>() = i_13_5c_fault_5b_31_3a_0_5d_.slice<31,4>().val();
	// cells $procmux$1850 $procmux$1847 $procmux$1845 $procmux$1453
	i_3_5c_rone_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? p_rone.curr : (i_logic__and_24_receiver_2e_v_3a_103_24_224__Y ? value<1>{0x1u} : i_4_5c_rone_5b_0_3a_0_5d_)) : value<1>{0u}));
	// \src: receiver.v:91.63-91.70
	// cell $mul$receiver.v:91$206
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7023.slice<5,0>() = mul_uu<6>(value<4>{0x8u}, i_6_5c_qo_5b_0_5d__5b_1_3a_0_5d_);
	// connection
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7023.slice<31,6>() = value<26>{0u};
	// cells $procmux$4716 $procmux$4444
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7041.slice<0>() = (i_5_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_121__Y ? value<1>{0u} : value<1>{0x1u}) : value<1>{0u});
	// connection
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7041.slice<1>() = value<1>{0u};
	// \full_case: 1
	// \src: receiver.v:76.9-76.16|receiver.v:76.6-84.9
	// cell $procmux$3037
	i_17_5c_fault_5b_31_3a_0_5d_.slice<3,0>() = (i_ge_24_receiver_2e_v_3a_76_24_168__Y ? i_13_5c_fault_5b_31_3a_0_5d_.slice<3>().concat(value<1>{0x1u}).concat(i_13_5c_fault_5b_31_3a_0_5d_.slice<1,0>()).val() : i_18_5c_fault_5b_31_3a_0_5d_.slice<3,0>().val());
	// connection
	i_17_5c_fault_5b_31_3a_0_5d_.slice<31,4>() = i_13_5c_fault_5b_31_3a_0_5d_.slice<31,4>().val();
	// cells $procmux$4527 $procmux$4192 $procmux$3756
	i_3_5c_qi_5b_7_5d__5b_31_3a_0_5d_ = (i_5_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_121__Y ? p_qi_5b_7_5d_.curr : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6842 ? p_qi_5b_7_5d_.curr : (i_procmux_24_3736__CMP ? p_nextid.curr : value<32>{0u}))) : p_qi_5b_7_5d_.curr);
	// cells $procmux$4536 $procmux$4204 $procmux$3777
	i_3_5c_qi_5b_6_5d__5b_31_3a_0_5d_ = (i_5_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_121__Y ? p_qi_5b_6_5d_.curr : (i_procmux_24_3737__CMP ? p_nextid.curr : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6840 ? p_qi_5b_6_5d_.curr : value<32>{0u}))) : p_qi_5b_6_5d_.curr);
	// cells $procmux$4545 $procmux$4216 $procmux$3798
	i_3_5c_qi_5b_5_5d__5b_31_3a_0_5d_ = (i_5_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_121__Y ? p_qi_5b_5_5d_.curr : (i_procmux_24_3738__CMP ? p_nextid.curr : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6838 ? p_qi_5b_5_5d_.curr : value<32>{0u}))) : p_qi_5b_5_5d_.curr);
	// cells $procmux$4554 $procmux$4228 $procmux$3819
	i_3_5c_qi_5b_4_5d__5b_31_3a_0_5d_ = (i_5_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_121__Y ? p_qi_5b_4_5d_.curr : (i_procmux_24_3739__CMP ? p_nextid.curr : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6836 ? p_qi_5b_4_5d_.curr : value<32>{0u}))) : p_qi_5b_4_5d_.curr);
	// cells $procmux$4563 $procmux$4240 $procmux$3840
	i_3_5c_qi_5b_3_5d__5b_31_3a_0_5d_ = (i_5_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_121__Y ? p_qi_5b_3_5d_.curr : (i_procmux_24_3740__CMP ? p_nextid.curr : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6834 ? p_qi_5b_3_5d_.curr : value<32>{0u}))) : p_qi_5b_3_5d_.curr);
	// cells $procmux$4572 $procmux$4252 $procmux$3861
	i_3_5c_qi_5b_2_5d__5b_31_3a_0_5d_ = (i_5_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_121__Y ? p_qi_5b_2_5d_.curr : (i_procmux_24_3741__CMP ? p_nextid.curr : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6832 ? p_qi_5b_2_5d_.curr : value<32>{0u}))) : p_qi_5b_2_5d_.curr);
	// cells $procmux$4581 $procmux$4264 $procmux$3882
	i_3_5c_qi_5b_1_5d__5b_31_3a_0_5d_ = (i_5_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_121__Y ? p_qi_5b_1_5d_.curr : (i_procmux_24_3742__CMP ? p_nextid.curr : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6830 ? p_qi_5b_1_5d_.curr : value<32>{0u}))) : p_qi_5b_1_5d_.curr);
	// cells $procmux$5872 $procmux$5869 $procmux$5867
	i_3_5c_bytes_5b_7_3a_0_5d_ = (p_rst ? value<8>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_logic__and_24_receiver_2e_v_3a_59_24_82__Y ? p_wubytes.slice<7,0>().val() : p_bytes.curr.slice<7,0>().val()) : value<8>{0u}));
	// cells $procmux$5836 $procmux$5833 $procmux$5831
	i_4_5c_bytes_5b_15_3a_8_5d_ = (p_rst ? value<8>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_logic__and_24_receiver_2e_v_3a_59_24_83__Y ? p_wubytes.slice<15,8>().val() : p_bytes.curr.slice<15,8>().val()) : value<8>{0u}));
	// cells $procmux$5800 $procmux$5797 $procmux$5795
	i_5_5c_bytes_5b_23_3a_16_5d_ = (p_rst ? value<8>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_logic__and_24_receiver_2e_v_3a_59_24_84__Y ? p_wubytes.slice<23,16>().val() : p_bytes.curr.slice<23,16>().val()) : value<8>{0u}));
	// cells $procmux$5764 $procmux$5761 $procmux$5759
	i_6_5c_bytes_5b_31_3a_24_5d_ = (p_rst ? value<8>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_logic__and_24_receiver_2e_v_3a_59_24_85__Y ? p_wubytes.slice<31,24>().val() : p_bytes.curr.slice<31,24>().val()) : value<8>{0u}));
	// \full_case: 1
	// \src: receiver.v:75.8-75.20|receiver.v:75.5-85.8
	// cell $procmux$3630
	i_16_5c_fault_5b_31_3a_0_5d_.slice<3,0>() = (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? i_17_5c_fault_5b_31_3a_0_5d_.slice<3,0>().val() : i_13_5c_fault_5b_31_3a_0_5d_.slice<3,0>().val());
	// connection
	i_16_5c_fault_5b_31_3a_0_5d_.slice<31,4>() = i_13_5c_fault_5b_31_3a_0_5d_.slice<31,4>().val();
	// cells $shiftx$receiver.v:91$208 $add$receiver.v:91$207
	i_shiftx_24_receiver_2e_v_3a_91_24_208__Y = shiftx_us<8>(i_6_5c_bytes_5b_31_3a_24_5d_.concat(i_5_5c_bytes_5b_23_3a_16_5d_).concat(i_4_5c_bytes_5b_15_3a_8_5d_).concat(i_3_5c_bytes_5b_7_3a_0_5d_).val(), value<1>{0u}.concat(add_uu<7>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7023.slice<5,0>().val(), value<1>{0u})).val());
	// cells $procmux$4721 $procmux$4718
	i_3_5c_evenq_5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? value<1>{0u}.concat(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7041.slice<0>()).val() : value<2>{0u}));
	// cells $procmux$3495 $procmux$3181 $procmux$2640
	i_6_5c_qi_5b_0_5d__5b_31_3a_0_5d_ = (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_168__Y ? i_3_5c_qi_5b_0_5d__5b_31_3a_0_5d_ : (i_procmux_24_2648__CMP ? i_3_5c_nextid_5b_31_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6898 ? i_3_5c_qi_5b_0_5d__5b_31_3a_0_5d_ : value<32>{0u}))) : i_3_5c_qi_5b_0_5d__5b_31_3a_0_5d_);
	// cells $procmux$5701 $procmux$5698 $procmux$5696 $procmux$4972 $procmux$4907 $procmux$4826
	i_7_5c_enabled_5b_3_3a_0_5d_.slice<3>() = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_eq_24_receiver_2e_v_3a_61_24_86__Y ? (i_6_5c_enabled_5b_3_3a_3_5d_ ? (i_eq_24_receiver_2e_v_3a_64_24_99__Y ? value<1>{0x1u} : (i_eq_24_receiver_2e_v_3a_65_24_102__Y ? value<1>{0u} : value<1>{0x1u})) : value<1>{0u}) : i_6_5c_enabled_5b_3_3a_3_5d_) : value<1>{0u}));
	// cells $procmux$5674 $procmux$5671 $procmux$5669 $procmux$5539 $procmux$5474 $procmux$5393
	i_7_5c_enabled_5b_3_3a_0_5d_.slice<0>() = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_eq_24_receiver_2e_v_3a_61_24_86__Y ? (i_3_5c_enabled_5b_0_3a_0_5d_ ? (i_eq_24_receiver_2e_v_3a_64_24_87__Y ? value<1>{0x1u} : (i_eq_24_receiver_2e_v_3a_65_24_90__Y ? value<1>{0u} : value<1>{0x1u})) : value<1>{0u}) : i_3_5c_enabled_5b_0_3a_0_5d_) : value<1>{0u}));
	// cells $procmux$5638 $procmux$5635 $procmux$5633 $procmux$5350 $procmux$5285 $procmux$5204
	i_7_5c_enabled_5b_3_3a_0_5d_.slice<1>() = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_eq_24_receiver_2e_v_3a_61_24_86__Y ? (i_4_5c_enabled_5b_1_3a_1_5d_ ? (i_eq_24_receiver_2e_v_3a_64_24_91__Y ? value<1>{0x1u} : (i_eq_24_receiver_2e_v_3a_65_24_94__Y ? value<1>{0u} : value<1>{0x1u})) : value<1>{0u}) : i_4_5c_enabled_5b_1_3a_1_5d_) : value<1>{0u}));
	// cells $procmux$5602 $procmux$5599 $procmux$5597 $procmux$5161 $procmux$5096 $procmux$5015
	i_7_5c_enabled_5b_3_3a_0_5d_.slice<2>() = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_eq_24_receiver_2e_v_3a_61_24_86__Y ? (i_5_5c_enabled_5b_2_3a_2_5d_ ? (i_eq_24_receiver_2e_v_3a_64_24_95__Y ? value<1>{0x1u} : (i_eq_24_receiver_2e_v_3a_65_24_98__Y ? value<1>{0u} : value<1>{0x1u})) : value<1>{0u}) : i_5_5c_enabled_5b_2_3a_2_5d_) : value<1>{0u}));
	// \full_case: 1
	// \src: receiver.v:109.9-109.39|receiver.v:109.6-110.69
	// cell $procmux$1289
	i_21_5c_fault_5b_31_3a_0_5d_.slice<4,0>() = (i_eq_24_receiver_2e_v_3a_109_24_229__Y ? value<1>{0x1u}.concat(i_16_5c_fault_5b_31_3a_0_5d_.slice<3,0>()).val() : i_13_5c_fault_5b_31_3a_0_5d_.slice<4>().concat(i_16_5c_fault_5b_31_3a_0_5d_.slice<3,0>()).val());
	// connection
	i_21_5c_fault_5b_31_3a_0_5d_.slice<31,5>() = i_13_5c_fault_5b_31_3a_0_5d_.slice<31,5>().val();
	// cells $procmux$1778 $procmux$1775 $procmux$1773 $procmux$1357 $procmux$1319
	i_7_5c_outstanding_5b_15_3a_0_5d_ = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? i_5_5c_outstanding_5b_15_3a_0_5d_ : (i_4_5c_evemit_5b_0_3a_0_5d_ ? (i_eq_24_receiver_2e_v_3a_109_24_229__Y ? i_5_5c_outstanding_5b_15_3a_0_5d_ : i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7013.slice<15,0>().val()) : i_5_5c_outstanding_5b_15_3a_0_5d_)) : value<16>{0u}));
	// \src: receiver.v:78.10-78.18
	// cell $eq$receiver.v:78$175
	i_eq_24_receiver_2e_v_3a_78_24_175__Y = logic_not<1>(i_3_5c_evenq_5b_1_3a_0_5d_);
	// cells $procmux$4698 $procmux$4420
	i_3_5c_enqid_5b_31_3a_0_5d_ = (i_5_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_121__Y ? p_enqid.curr : p_nextid.curr) : p_enqid.curr);
	// cells $procmux$4707 $procmux$4432
	i_3_5c_enqowner_5b_1_3a_0_5d_ = (i_5_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_121__Y ? p_enqowner.curr : i_5_5c_enqowner_5b_1_3a_0_5d_) : p_enqowner.curr);
	// \full_case: 1
	// \src: receiver.v:107.8-107.14|receiver.v:107.5-111.8
	// cell $procmux$1345
	i_20_5c_fault_5b_31_3a_0_5d_.slice<4,0>() = (i_4_5c_evemit_5b_0_3a_0_5d_ ? i_21_5c_fault_5b_31_3a_0_5d_.slice<4,0>().val() : i_13_5c_fault_5b_31_3a_0_5d_.slice<4>().concat(i_16_5c_fault_5b_31_3a_0_5d_.slice<3,0>()).val());
	// connection
	i_20_5c_fault_5b_31_3a_0_5d_.slice<31,5>() = i_13_5c_fault_5b_31_3a_0_5d_.slice<31,5>().val();
	// cells $procmux$3662 $procmux$3659 $procmux$3657 $procmux$3385 $add$receiver.v:81$178
	i_5_5c_nextid_5b_31_3a_0_5d_ = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_168__Y ? i_3_5c_nextid_5b_31_3a_0_5d_ : add_uu<32>(i_3_5c_nextid_5b_31_3a_0_5d_, value<1>{0x1u})) : i_3_5c_nextid_5b_31_3a_0_5d_) : value<32>{0u}));
	// cells $procmux$3432 $procmux$3097 $procmux$2661
	i_6_5c_qi_5b_7_5d__5b_31_3a_0_5d_ = (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_168__Y ? i_3_5c_qi_5b_7_5d__5b_31_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6890 ? i_3_5c_qi_5b_7_5d__5b_31_3a_0_5d_ : (i_procmux_24_2641__CMP ? i_3_5c_nextid_5b_31_3a_0_5d_ : value<32>{0u}))) : i_3_5c_qi_5b_7_5d__5b_31_3a_0_5d_);
	// cells $procmux$3441 $procmux$3109 $procmux$2682
	i_6_5c_qi_5b_6_5d__5b_31_3a_0_5d_ = (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_168__Y ? i_3_5c_qi_5b_6_5d__5b_31_3a_0_5d_ : (i_procmux_24_2642__CMP ? i_3_5c_nextid_5b_31_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6884 ? i_3_5c_qi_5b_6_5d__5b_31_3a_0_5d_ : value<32>{0u}))) : i_3_5c_qi_5b_6_5d__5b_31_3a_0_5d_);
	// cells $procmux$3450 $procmux$3121 $procmux$2703
	i_6_5c_qi_5b_5_5d__5b_31_3a_0_5d_ = (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_168__Y ? i_3_5c_qi_5b_5_5d__5b_31_3a_0_5d_ : (i_procmux_24_2643__CMP ? i_3_5c_nextid_5b_31_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6874 ? i_3_5c_qi_5b_5_5d__5b_31_3a_0_5d_ : value<32>{0u}))) : i_3_5c_qi_5b_5_5d__5b_31_3a_0_5d_);
	// cells $procmux$3459 $procmux$3133 $procmux$2724
	i_6_5c_qi_5b_4_5d__5b_31_3a_0_5d_ = (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_168__Y ? i_3_5c_qi_5b_4_5d__5b_31_3a_0_5d_ : (i_procmux_24_2644__CMP ? i_3_5c_nextid_5b_31_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6866 ? i_3_5c_qi_5b_4_5d__5b_31_3a_0_5d_ : value<32>{0u}))) : i_3_5c_qi_5b_4_5d__5b_31_3a_0_5d_);
	// cells $procmux$3468 $procmux$3145 $procmux$2745
	i_6_5c_qi_5b_3_5d__5b_31_3a_0_5d_ = (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_168__Y ? i_3_5c_qi_5b_3_5d__5b_31_3a_0_5d_ : (i_procmux_24_2645__CMP ? i_3_5c_nextid_5b_31_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6856 ? i_3_5c_qi_5b_3_5d__5b_31_3a_0_5d_ : value<32>{0u}))) : i_3_5c_qi_5b_3_5d__5b_31_3a_0_5d_);
	// cells $procmux$3477 $procmux$3157 $procmux$2766
	i_6_5c_qi_5b_2_5d__5b_31_3a_0_5d_ = (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_168__Y ? i_3_5c_qi_5b_2_5d__5b_31_3a_0_5d_ : (i_procmux_24_2646__CMP ? i_3_5c_nextid_5b_31_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6854 ? i_3_5c_qi_5b_2_5d__5b_31_3a_0_5d_ : value<32>{0u}))) : i_3_5c_qi_5b_2_5d__5b_31_3a_0_5d_);
	// cells $procmux$3486 $procmux$3169 $procmux$2787
	i_6_5c_qi_5b_1_5d__5b_31_3a_0_5d_ = (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_168__Y ? i_3_5c_qi_5b_1_5d__5b_31_3a_0_5d_ : (i_procmux_24_2647__CMP ? i_3_5c_nextid_5b_31_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6850 ? i_3_5c_qi_5b_1_5d__5b_31_3a_0_5d_ : value<32>{0u}))) : i_3_5c_qi_5b_1_5d__5b_31_3a_0_5d_);
	// cells $procmux$2553 $procmux$2251
	i_3_5c_bytezero_5b_7_3a_0_5d_ = (i_logic__and_24_receiver_2e_v_3a_87_24_201__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_203__Y ? i_shiftx_24_receiver_2e_v_3a_91_24_208__Y : p_bytezero.curr) : p_bytezero.curr);
	// cells $procmux$1657 $procmux$1544
	i_4_5c_emitid_5b_31_3a_0_5d_ = (p_rone.curr ? (i_logic__or_24_receiver_2e_v_3a_100_24_222__Y ? p_idone.curr : p_emitid.curr) : p_emitid.curr);
	// cells $procmux$2562 $procmux$2263
	i_3_5c_idzero_5b_31_3a_0_5d_ = (i_logic__and_24_receiver_2e_v_3a_87_24_201__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_203__Y ? i_6_5c_qi_5b_0_5d__5b_31_3a_0_5d_ : p_idzero.curr) : p_idzero.curr);
	// \full_case: 1
	// \src: receiver.v:98.7-98.14|receiver.v:98.4-112.7
	// cell $procmux$1764
	i_19_5c_fault_5b_31_3a_0_5d_.slice<4,0>() = (i_3_5c_failed_5b_0_3a_0_5d_ ? i_13_5c_fault_5b_31_3a_0_5d_.slice<4>().concat(i_16_5c_fault_5b_31_3a_0_5d_.slice<3,0>()).val() : i_20_5c_fault_5b_31_3a_0_5d_.slice<4,0>().val());
	// connection
	i_19_5c_fault_5b_31_3a_0_5d_.slice<31,5>() = i_13_5c_fault_5b_31_3a_0_5d_.slice<31,5>().val();
	// \src: receiver.v:127.36-127.40
	// cell $add$receiver.v:127$313
	i_add_24_receiver_2e_v_3a_127_24_311__Y = add_uu<17>(p_pp.curr, value<1>{0x1u});
	// \src: receiver.v:126.31-126.35
	// cell $add$receiver.v:126$310
	i_add_24_receiver_2e_v_3a_126_24_308__Y = add_uu<17>(p_fp.curr, value<1>{0x1u});
	// \src: receiver.v:125.31-125.35
	// cell $add$receiver.v:125$307
	i_add_24_receiver_2e_v_3a_125_24_305__Y = add_uu<17>(p_rp.curr, value<1>{0x1u});
	// \src: receiver.v:124.31-124.35
	// cell $add$receiver.v:124$304
	i_add_24_receiver_2e_v_3a_124_24_302__Y = add_uu<17>(p_cp.curr, value<1>{0x1u});
	// cells $procmux$358 $logic_or$receiver.v:121$295 $gt$receiver.v:121$293 $ne$receiver.v:121$294 $procmux$455 $procmux$452 $procmux$450 $procmux$367 $add$receiver.v:120$289 $auto$opt_reduce.cc:131:opt_pmux$6971 $procmux$446 $procmux$443 $procmux$441 $procmux$409 $add$receiver.v:120$290 $auto$opt_reduce.cc:131:opt_pmux$6965 $procmux$437 $procmux$434 $procmux$432 $procmux$395 $add$receiver.v:120$291 $auto$opt_reduce.cc:131:opt_pmux$6967 $procmux$428 $procmux$425 $procmux$423 $procmux$381 $add$receiver.v:120$292 $auto$opt_reduce.cc:131:opt_pmux$6969
	i_22_5c_fault_5b_31_3a_0_5d_.slice<5,0>() = (logic_or<1>(gt_uu<1>(i_7_5c_qlen_5b_3_3a_0_5d_, value<4>{0x8u}), ne_uu<1>((p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_3_5c_rone_5b_0_3a_0_5d_ ? (reduce_or<1>(i_procmux_24_371__CMP.concat(i_procmux_24_370__CMP).concat(i_procmux_24_369__CMP).val()) ? i_19_5c_tokens3_5b_3_3a_0_5d_ : (i_procmux_24_368__CMP ? add_uu<4>(i_19_5c_tokens3_5b_3_3a_0_5d_, value<1>{0x1u}) : value<4>{0u})) : i_19_5c_tokens3_5b_3_3a_0_5d_) : value<4>{0u})).concat((p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_3_5c_rone_5b_0_3a_0_5d_ ? (i_procmux_24_369__CMP ? add_uu<4>(i_19_5c_tokens2_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_371__CMP.concat(i_procmux_24_370__CMP).concat(i_procmux_24_368__CMP).val()) ? i_19_5c_tokens2_5b_3_3a_0_5d_ : value<4>{0u})) : i_19_5c_tokens2_5b_3_3a_0_5d_) : value<4>{0u}))).concat((p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_3_5c_rone_5b_0_3a_0_5d_ ? (i_procmux_24_370__CMP ? add_uu<4>(i_19_5c_tokens1_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_371__CMP.concat(i_procmux_24_369__CMP).concat(i_procmux_24_368__CMP).val()) ? i_19_5c_tokens1_5b_3_3a_0_5d_ : value<4>{0u})) : i_19_5c_tokens1_5b_3_3a_0_5d_) : value<4>{0u}))).concat((p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_3_5c_rone_5b_0_3a_0_5d_ ? (i_procmux_24_371__CMP ? add_uu<4>(i_19_5c_tokens0_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_370__CMP.concat(i_procmux_24_369__CMP).concat(i_procmux_24_368__CMP).val()) ? i_19_5c_tokens0_5b_3_3a_0_5d_ : value<4>{0u})) : i_19_5c_tokens0_5b_3_3a_0_5d_) : value<4>{0u}))).val(), i_7_5c_outstanding_5b_15_3a_0_5d_)) ? value<1>{0x1u}.concat(i_19_5c_fault_5b_31_3a_0_5d_.slice<4,0>()).val() : i_13_5c_fault_5b_31_3a_0_5d_.slice<5>().concat(i_19_5c_fault_5b_31_3a_0_5d_.slice<4,0>()).val());
	// connection
	i_22_5c_fault_5b_31_3a_0_5d_.slice<31,6>() = i_13_5c_fault_5b_31_3a_0_5d_.slice<31,6>().val();
	// cells $procmux$5651 $procmux$5503 $procmux$5444 $procmux$5375
	i_3_5c_evexpire_5b_3_3a_0_5d_.slice<0>() = (i_eq_24_receiver_2e_v_3a_61_24_86__Y ? (i_3_5c_enabled_5b_0_3a_0_5d_ ? (i_eq_24_receiver_2e_v_3a_64_24_87__Y ? value<1>{0u} : (i_eq_24_receiver_2e_v_3a_65_24_90__Y ? value<1>{0x1u} : value<1>{0u})) : value<1>{0u}) : value<1>{0u});
	// cells $procmux$5615 $procmux$5314 $procmux$5255 $procmux$5186
	i_3_5c_evexpire_5b_3_3a_0_5d_.slice<1>() = (i_eq_24_receiver_2e_v_3a_61_24_86__Y ? (i_4_5c_enabled_5b_1_3a_1_5d_ ? (i_eq_24_receiver_2e_v_3a_64_24_91__Y ? value<1>{0u} : (i_eq_24_receiver_2e_v_3a_65_24_94__Y ? value<1>{0x1u} : value<1>{0u})) : value<1>{0u}) : value<1>{0u});
	// cells $procmux$5570 $procmux$5125 $procmux$5066 $procmux$4997
	i_3_5c_evexpire_5b_3_3a_0_5d_.slice<2>() = (i_eq_24_receiver_2e_v_3a_61_24_86__Y ? (i_5_5c_enabled_5b_2_3a_2_5d_ ? (i_eq_24_receiver_2e_v_3a_64_24_95__Y ? value<1>{0u} : (i_eq_24_receiver_2e_v_3a_65_24_98__Y ? value<1>{0x1u} : value<1>{0u})) : value<1>{0u}) : value<1>{0u});
	// cells $procmux$4815 $procmux$4936 $procmux$4877 $procmux$5716
	i_3_5c_evexpire_5b_3_3a_0_5d_.slice<3>() = (i_eq_24_receiver_2e_v_3a_61_24_86__Y ? (i_6_5c_enabled_5b_3_3a_3_5d_ ? (i_eq_24_receiver_2e_v_3a_64_24_99__Y ? value<1>{0u} : (i_eq_24_receiver_2e_v_3a_65_24_102__Y ? value<1>{0x1u} : value<1>{0u})) : value<1>{0u}) : value<1>{0u});
	// cells $procmux$349 $logic_or$receiver.v:122$299 $ge$receiver.v:122$297 $ge$receiver.v:122$298
	i_23_5c_fault_5b_31_3a_0_5d_.slice<6,0>() = (logic_or<1>(ge_uu<1>(p_tick.curr, value<31>{0x7ffffffeu}), ge_uu<1>(i_5_5c_nextid_5b_31_3a_0_5d_, value<31>{0x7ffffffeu})) ? value<1>{0x1u}.concat(i_22_5c_fault_5b_31_3a_0_5d_.slice<5,0>()).val() : i_13_5c_fault_5b_31_3a_0_5d_.slice<6>().concat(i_22_5c_fault_5b_31_3a_0_5d_.slice<5,0>()).val());
	// connection
	i_23_5c_fault_5b_31_3a_0_5d_.slice<31,7>() = i_13_5c_fault_5b_31_3a_0_5d_.slice<31,7>().val();
	// cells $procmux$5687 $procmux$4960 $procmux$4892
	i_7_5c_counts_5b_63_3a_0_5d_.slice<63,48>() = (i_eq_24_receiver_2e_v_3a_61_24_86__Y ? (i_6_5c_enabled_5b_3_3a_3_5d_ ? (i_eq_24_receiver_2e_v_3a_64_24_99__Y ? i_6_5c_counts_5b_63_3a_48_5d_ : i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7046.slice<15,0>().val()) : i_6_5c_counts_5b_63_3a_48_5d_) : i_6_5c_counts_5b_63_3a_48_5d_);
	// cells $procmux$5660 $procmux$5527 $procmux$5459
	i_7_5c_counts_5b_63_3a_0_5d_.slice<15,0>() = (i_eq_24_receiver_2e_v_3a_61_24_86__Y ? (i_3_5c_enabled_5b_0_3a_0_5d_ ? (i_eq_24_receiver_2e_v_3a_64_24_87__Y ? i_3_5c_counts_5b_15_3a_0_5d_ : i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7049.slice<15,0>().val()) : i_3_5c_counts_5b_15_3a_0_5d_) : i_3_5c_counts_5b_15_3a_0_5d_);
	// cells $procmux$5624 $procmux$5338 $procmux$5270
	i_7_5c_counts_5b_63_3a_0_5d_.slice<31,16>() = (i_eq_24_receiver_2e_v_3a_61_24_86__Y ? (i_4_5c_enabled_5b_1_3a_1_5d_ ? (i_eq_24_receiver_2e_v_3a_64_24_91__Y ? i_4_5c_counts_5b_31_3a_16_5d_ : i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7048.slice<15,0>().val()) : i_4_5c_counts_5b_31_3a_16_5d_) : i_4_5c_counts_5b_31_3a_16_5d_);
	// cells $procmux$5588 $procmux$5149 $procmux$5081
	i_7_5c_counts_5b_63_3a_0_5d_.slice<47,32>() = (i_eq_24_receiver_2e_v_3a_61_24_86__Y ? (i_5_5c_enabled_5b_2_3a_2_5d_ ? (i_eq_24_receiver_2e_v_3a_64_24_95__Y ? i_5_5c_counts_5b_47_3a_32_5d_ : i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7047.slice<15,0>().val()) : i_5_5c_counts_5b_47_3a_32_5d_) : i_5_5c_counts_5b_47_3a_32_5d_);
	// cells $procmux$6427 $procmux$5840
	i_2_5c_evwu_5b_3_3a_0_5d_.slice<0>() = (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_logic__and_24_receiver_2e_v_3a_59_24_82__Y ? value<1>{0x1u} : value<1>{0u}) : p_evwu.curr.slice<0>().val());
	// cells $procmux$6415 $procmux$5804
	i_2_5c_evwu_5b_3_3a_0_5d_.slice<1>() = (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_logic__and_24_receiver_2e_v_3a_59_24_83__Y ? value<1>{0x1u} : value<1>{0u}) : p_evwu.curr.slice<1>().val());
	// cells $procmux$6403 $procmux$5768
	i_2_5c_evwu_5b_3_3a_0_5d_.slice<2>() = (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_logic__and_24_receiver_2e_v_3a_59_24_84__Y ? value<1>{0x1u} : value<1>{0u}) : p_evwu.curr.slice<2>().val());
	// cells $procmux$315 $procmux$5732
	i_2_5c_evwu_5b_3_3a_0_5d_.slice<3>() = (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_logic__and_24_receiver_2e_v_3a_59_24_85__Y ? value<1>{0x1u} : value<1>{0u}) : p_evwu.curr.slice<3>().val());
	// \full_case: 1
	// \src: receiver.v:55.15-55.34|receiver.v:55.12-128.6
	// cell $procmux$6439
	i_2_5c_bytes_5b_31_3a_0_5d_.slice<31,24>() = (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? i_6_5c_bytes_5b_31_3a_24_5d_ : p_bytes.curr.slice<31,24>().val());
	// \full_case: 1
	// \src: receiver.v:55.15-55.34|receiver.v:55.12-128.6
	// cell $procmux$6433
	i_2_5c_bytes_5b_31_3a_0_5d_.slice<7,0>() = (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? i_3_5c_bytes_5b_7_3a_0_5d_ : p_bytes.curr.slice<7,0>().val());
	// \full_case: 1
	// \src: receiver.v:55.15-55.34|receiver.v:55.12-128.6
	// cell $procmux$6421
	i_2_5c_bytes_5b_31_3a_0_5d_.slice<15,8>() = (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? i_4_5c_bytes_5b_15_3a_8_5d_ : p_bytes.curr.slice<15,8>().val());
	// \full_case: 1
	// \src: receiver.v:55.15-55.34|receiver.v:55.12-128.6
	// cell $procmux$6409
	i_2_5c_bytes_5b_31_3a_0_5d_.slice<23,16>() = (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? i_5_5c_bytes_5b_23_3a_16_5d_ : p_bytes.curr.slice<23,16>().val());
	// cells $procdff$6820 $procmux$6616 $procmux$6067 $procmux$2310 $procmux$1975
	if (posedge_p_clk) {
		p_qi_5b_7_5d_.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_201__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_203__Y ? value<32>{0u} : i_6_5c_qi_5b_7_5d__5b_31_3a_0_5d_) : i_6_5c_qi_5b_7_5d__5b_31_3a_0_5d_) : p_qi_5b_7_5d_.curr));
	}
	// cells $procdff$6819 $procmux$6622 $procmux$6073 $procmux$2319 $procmux$1987
	if (posedge_p_clk) {
		p_qi_5b_6_5d_.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_201__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_203__Y ? i_6_5c_qi_5b_7_5d__5b_31_3a_0_5d_ : i_6_5c_qi_5b_6_5d__5b_31_3a_0_5d_) : i_6_5c_qi_5b_6_5d__5b_31_3a_0_5d_) : p_qi_5b_6_5d_.curr));
	}
	// cells $procdff$6818 $procmux$6628 $procmux$6079 $procmux$2328 $procmux$1999
	if (posedge_p_clk) {
		p_qi_5b_5_5d_.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_201__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_203__Y ? i_6_5c_qi_5b_6_5d__5b_31_3a_0_5d_ : i_6_5c_qi_5b_5_5d__5b_31_3a_0_5d_) : i_6_5c_qi_5b_5_5d__5b_31_3a_0_5d_) : p_qi_5b_5_5d_.curr));
	}
	// cells $procdff$6817 $procmux$6634 $procmux$6085 $procmux$2337 $procmux$2011
	if (posedge_p_clk) {
		p_qi_5b_4_5d_.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_201__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_203__Y ? i_6_5c_qi_5b_5_5d__5b_31_3a_0_5d_ : i_6_5c_qi_5b_4_5d__5b_31_3a_0_5d_) : i_6_5c_qi_5b_4_5d__5b_31_3a_0_5d_) : p_qi_5b_4_5d_.curr));
	}
	// cells $procdff$6816 $procmux$6640 $procmux$6091 $procmux$2346 $procmux$2023
	if (posedge_p_clk) {
		p_qi_5b_3_5d_.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_201__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_203__Y ? i_6_5c_qi_5b_4_5d__5b_31_3a_0_5d_ : i_6_5c_qi_5b_3_5d__5b_31_3a_0_5d_) : i_6_5c_qi_5b_3_5d__5b_31_3a_0_5d_) : p_qi_5b_3_5d_.curr));
	}
	// cells $procdff$6815 $procmux$6646 $procmux$6097 $procmux$2355 $procmux$2035
	if (posedge_p_clk) {
		p_qi_5b_2_5d_.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_201__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_203__Y ? i_6_5c_qi_5b_3_5d__5b_31_3a_0_5d_ : i_6_5c_qi_5b_2_5d__5b_31_3a_0_5d_) : i_6_5c_qi_5b_2_5d__5b_31_3a_0_5d_) : p_qi_5b_2_5d_.curr));
	}
	// cells $procdff$6814 $procmux$6652 $procmux$6103 $procmux$2364 $procmux$2047
	if (posedge_p_clk) {
		p_qi_5b_1_5d_.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_201__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_203__Y ? i_6_5c_qi_5b_2_5d__5b_31_3a_0_5d_ : i_6_5c_qi_5b_1_5d__5b_31_3a_0_5d_) : i_6_5c_qi_5b_1_5d__5b_31_3a_0_5d_) : p_qi_5b_1_5d_.curr));
	}
	// cells $procdff$6813 $procmux$6658 $procmux$6109 $procmux$2373 $procmux$2059
	if (posedge_p_clk) {
		p_qi_5b_0_5d_.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_201__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_203__Y ? i_6_5c_qi_5b_1_5d__5b_31_3a_0_5d_ : i_6_5c_qi_5b_0_5d__5b_31_3a_0_5d_) : i_6_5c_qi_5b_0_5d__5b_31_3a_0_5d_) : p_qi_5b_0_5d_.curr));
	}
	// cells $procdff$6812 $procmux$6619 $procmux$6115
	if (posedge_p_clk) {
		p_qo_5b_7_5d_.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? i_9_5c_qo_5b_7_5d__5b_1_3a_0_5d_ : p_qo_5b_7_5d_.curr));
	}
	// cells $procdff$6811 $procmux$6625 $procmux$6121
	if (posedge_p_clk) {
		p_qo_5b_6_5d_.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? i_9_5c_qo_5b_6_5d__5b_1_3a_0_5d_ : p_qo_5b_6_5d_.curr));
	}
	// cells $procdff$6810 $procmux$6631 $procmux$6127
	if (posedge_p_clk) {
		p_qo_5b_5_5d_.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? i_9_5c_qo_5b_5_5d__5b_1_3a_0_5d_ : p_qo_5b_5_5d_.curr));
	}
	// cells $procdff$6809 $procmux$6637 $procmux$6133
	if (posedge_p_clk) {
		p_qo_5b_4_5d_.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? i_9_5c_qo_5b_4_5d__5b_1_3a_0_5d_ : p_qo_5b_4_5d_.curr));
	}
	// cells $procdff$6808 $procmux$6643 $procmux$6139
	if (posedge_p_clk) {
		p_qo_5b_3_5d_.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? i_9_5c_qo_5b_3_5d__5b_1_3a_0_5d_ : p_qo_5b_3_5d_.curr));
	}
	// cells $procdff$6807 $procmux$6649 $procmux$6145
	if (posedge_p_clk) {
		p_qo_5b_2_5d_.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? i_9_5c_qo_5b_2_5d__5b_1_3a_0_5d_ : p_qo_5b_2_5d_.curr));
	}
	// cells $procdff$6806 $procmux$6655 $procmux$6151
	if (posedge_p_clk) {
		p_qo_5b_1_5d_.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? i_9_5c_qo_5b_1_5d__5b_1_3a_0_5d_ : p_qo_5b_1_5d_.curr));
	}
	// cells $procdff$6805 $procmux$6661 $procmux$6157
	if (posedge_p_clk) {
		p_qo_5b_0_5d_.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? i_9_5c_qo_5b_0_5d__5b_1_3a_0_5d_ : p_qo_5b_0_5d_.curr));
	}
	// cells $procdff$6791 $procmux$6496 $procmux$5947 $procmux$1782 $procmux$1465
	if (posedge_p_clk) {
		p_transferbyte.next = (p_rst ? value<8>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? p_transferbyte.curr : (i_logic__and_24_receiver_2e_v_3a_103_24_224__Y ? i_3_5c_bytezero_5b_7_3a_0_5d_ : p_transferbyte.curr)) : p_transferbyte.curr));
	}
	// cells $procdff$6790 $procmux$6499 $procmux$5953 $procmux$1863 $procmux$1633 $procmux$1529
	if (posedge_p_clk) {
		p_emitbyte.next = (p_rst ? value<8>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? p_emitbyte.curr : (p_rone.curr ? (i_logic__or_24_receiver_2e_v_3a_100_24_222__Y ? p_byteone.curr : p_emitbyte.curr) : p_emitbyte.curr)) : p_emitbyte.curr));
	}
	// cells $procdff$6789 $procmux$6502 $procmux$6169 $procmux$2472 $procmux$2191
	if (posedge_p_clk) {
		p_grantbyte.next = (p_rst ? value<8>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_201__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_203__Y ? i_shiftx_24_receiver_2e_v_3a_91_24_208__Y : p_grantbyte.curr) : p_grantbyte.curr) : p_grantbyte.curr));
	}
	// cells $procdff$6788 $procmux$6490 $procmux$6301 $procmux$3585 $procmux$3301 $procmux$3007
	if (posedge_p_clk) {
		p_enqid2.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_168__Y ? p_enqid2.curr : (i_eq_24_receiver_2e_v_3a_78_24_175__Y ? p_enqid2.curr : i_3_5c_nextid_5b_31_3a_0_5d_)) : p_enqid2.curr) : p_enqid2.curr));
	}
	// cells $procdff$6787 $procmux$6493 $procmux$6307 $procmux$3594 $procmux$3313 $procmux$3022
	if (posedge_p_clk) {
		p_enqowner2.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_168__Y ? p_enqowner2.curr : (i_eq_24_receiver_2e_v_3a_78_24_175__Y ? p_enqowner2.curr : i_8_5c_releaseowner_5b_1_3a_0_5d_)) : p_enqowner2.curr) : p_enqowner2.curr));
	}
	// cells $procdff$6786 $procmux$6505 $procmux$5959 $procmux$1872 $procmux$1645 $procmux$1589
	if (posedge_p_clk) {
		p_blockid.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? p_blockid.curr : (p_rone.curr ? (i_logic__or_24_receiver_2e_v_3a_100_24_222__Y ? p_blockid.curr : p_idone.curr) : p_blockid.curr)) : p_blockid.curr));
	}
	// cells $procdff$6785 $procmux$6508 $procmux$5965 $procmux$1737 $procmux$1369
	if (posedge_p_clk) {
		p_callbackid.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? p_callbackid.curr : (i_4_5c_evemit_5b_0_3a_0_5d_ ? i_4_5c_emitid_5b_31_3a_0_5d_ : p_callbackid.curr)) : p_callbackid.curr));
	}
	// cells $procdff$6784 $procmux$6511 $procmux$5971 $procmux$1791 $procmux$1477
	if (posedge_p_clk) {
		p_transferid.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? p_transferid.curr : (i_logic__and_24_receiver_2e_v_3a_103_24_224__Y ? i_3_5c_idzero_5b_31_3a_0_5d_ : p_transferid.curr)) : p_transferid.curr));
	}
	// cells $procdff$6783 $procmux$6514 $procmux$5977 $procmux$1881
	if (posedge_p_clk) {
		p_emitid.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? p_emitid.curr : i_4_5c_emitid_5b_31_3a_0_5d_) : p_emitid.curr));
	}
	// cells $procdff$6782 $procmux$6517 $procmux$6175 $procmux$2481 $procmux$2203
	if (posedge_p_clk) {
		p_grantid.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_201__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_203__Y ? i_6_5c_qi_5b_0_5d__5b_31_3a_0_5d_ : p_grantid.curr) : p_grantid.curr) : p_grantid.curr));
	}
	// cells $procdff$6781 $procmux$6520 $procmux$6181 $procmux$2598
	if (posedge_p_clk) {
		p_attemptid.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_201__Y ? i_6_5c_qi_5b_0_5d__5b_31_3a_0_5d_ : p_attemptid.curr) : p_attemptid.curr));
	}
	// cells $procdff$6780 $procmux$6523 $procmux$6313 $procmux$3603 $procmux$3325 $procmux$2977
	if (posedge_p_clk) {
		p_enqid.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_168__Y ? i_3_5c_enqid_5b_31_3a_0_5d_ : (i_eq_24_receiver_2e_v_3a_78_24_175__Y ? i_3_5c_nextid_5b_31_3a_0_5d_ : i_3_5c_enqid_5b_31_3a_0_5d_)) : i_3_5c_enqid_5b_31_3a_0_5d_) : p_enqid.curr));
	}
	// cells $procdff$6779 $procmux$6526 $procmux$5983 $procmux$1890 $procmux$1669 $procmux$1604
	if (posedge_p_clk) {
		p_blockowner.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? p_blockowner.curr : (p_rone.curr ? (i_logic__or_24_receiver_2e_v_3a_100_24_222__Y ? p_blockowner.curr : p_ownerone.curr) : p_blockowner.curr)) : p_blockowner.curr));
	}
	// cells $procdff$6778 $procmux$6529 $procmux$5989 $procmux$1746 $procmux$1381
	if (posedge_p_clk) {
		p_callbackowner.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? p_callbackowner.curr : (i_4_5c_evemit_5b_0_3a_0_5d_ ? i_4_5c_emitowner_5b_1_3a_0_5d_ : p_callbackowner.curr)) : p_callbackowner.curr));
	}
	// cells $procdff$6777 $procmux$6532 $procmux$5995 $procmux$1800 $procmux$1489
	if (posedge_p_clk) {
		p_transferowner.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? p_transferowner.curr : (i_logic__and_24_receiver_2e_v_3a_103_24_224__Y ? i_3_5c_ownerzero_5b_1_3a_0_5d_ : p_transferowner.curr)) : p_transferowner.curr));
	}
	// cells $procdff$6776 $procmux$6535 $procmux$6001 $procmux$1899
	if (posedge_p_clk) {
		p_emitowner.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? p_emitowner.curr : i_4_5c_emitowner_5b_1_3a_0_5d_) : p_emitowner.curr));
	}
	// cells $procdff$6775 $procmux$6538 $procmux$6187 $procmux$2490 $procmux$2215
	if (posedge_p_clk) {
		p_grantowner.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_201__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_203__Y ? i_6_5c_qo_5b_0_5d__5b_1_3a_0_5d_ : p_grantowner.curr) : p_grantowner.curr) : p_grantowner.curr));
	}
	// cells $procdff$6774 $procmux$6541 $procmux$6193 $procmux$2607
	if (posedge_p_clk) {
		p_attemptowner.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_201__Y ? i_6_5c_qo_5b_0_5d__5b_1_3a_0_5d_ : p_attemptowner.curr) : p_attemptowner.curr));
	}
	// cells $procdff$6773 $procmux$6544 $procmux$6319 $procmux$3612 $procmux$3337 $procmux$2992
	if (posedge_p_clk) {
		p_enqowner.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_168__Y ? i_3_5c_enqowner_5b_1_3a_0_5d_ : (i_eq_24_receiver_2e_v_3a_78_24_175__Y ? i_8_5c_releaseowner_5b_1_3a_0_5d_ : i_3_5c_enqowner_5b_1_3a_0_5d_)) : i_3_5c_enqowner_5b_1_3a_0_5d_) : p_enqowner.curr));
	}
	// cells $procdff$6772 $procmux$6547 $procmux$6007 $procmux$1908
	if (posedge_p_clk) {
		p_evblock.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? value<1>{0u} : i_4_5c_evblock_5b_0_3a_0_5d_) : p_evblock.curr));
	}
	// cells $procdff$6771 $procmux$6550 $procmux$6013 $procmux$1755 $procmux$1393
	if (posedge_p_clk) {
		p_evcallback.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? value<1>{0u} : (i_4_5c_evemit_5b_0_3a_0_5d_ ? value<1>{0x1u} : value<1>{0u})) : p_evcallback.curr));
	}
	// cells $procdff$6770 $procmux$6553 $procmux$6019 $procmux$1809 $procmux$1501
	if (posedge_p_clk) {
		p_evtransfer.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_103_24_224__Y ? value<1>{0x1u} : value<1>{0u})) : p_evtransfer.curr));
	}
	// cells $procdff$6769 $procmux$6556 $procmux$6025 $procmux$1917
	if (posedge_p_clk) {
		p_evemit.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? value<1>{0u} : i_4_5c_evemit_5b_0_3a_0_5d_) : p_evemit.curr));
	}
	// cells $procdff$6768 $procmux$6559 $procmux$6199 $procmux$2499 $procmux$2227
	if (posedge_p_clk) {
		p_evgrant.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_201__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_203__Y ? value<1>{0x1u} : value<1>{0u}) : value<1>{0u}) : p_evgrant.curr));
	}
	// cells $procdff$6767 $procmux$6562 $procmux$6205 $procmux$2616
	if (posedge_p_clk) {
		p_evattempt.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_201__Y ? value<1>{0x1u} : value<1>{0u}) : p_evattempt.curr));
	}
	// cells $procdff$6766 $procmux$6565 $procmux$6325 $procmux$3621 $procmux$3349 $add$receiver.v:80$176
	if (posedge_p_clk) {
		p_evenq.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_168__Y ? i_3_5c_evenq_5b_1_3a_0_5d_ : add_uu<2>(i_3_5c_evenq_5b_1_3a_0_5d_, value<1>{0x1u})) : i_3_5c_evenq_5b_1_3a_0_5d_) : p_evenq.curr));
	}
	// cells $procdff$6765 $procmux$6568 $procmux$6211 $procmux$2508 $procmux$2239 $shift$receiver.v:93$215 $shiftx$receiver.v:93$213 $neg$receiver.v:93$214
	if (posedge_p_clk) {
		p_evcancel.next = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_201__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_203__Y ? shift_us<4>(shiftx_uu<1>(i_7_5c_enabled_5b_3_3a_0_5d_, i_6_5c_qo_5b_0_5d__5b_1_3a_0_5d_), neg_u<3>(i_6_5c_qo_5b_0_5d__5b_1_3a_0_5d_)) : value<4>{0u}) : value<4>{0u}) : p_evcancel.curr));
	}
	// cells $procdff$6764 $procmux$6571 $procmux$6379
	if (posedge_p_clk) {
		p_evexpire.next = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? i_3_5c_evexpire_5b_3_3a_0_5d_ : p_evexpire.curr));
	}
	// cells $procdff$6763 $procmux$6574
	if (posedge_p_clk) {
		p_evwu.next = (p_rst ? value<4>{0u} : i_2_5c_evwu_5b_3_3a_0_5d_);
	}
	// cells $procdff$6762 $procmux$6577 $procmux$6217 $procmux$2517 $procmux$1939
	if (posedge_p_clk) {
		p_failowner.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_201__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_203__Y ? p_failowner.curr : i_6_5c_qo_5b_0_5d__5b_1_3a_0_5d_) : p_failowner.curr) : p_failowner.curr));
	}
	// cells $procdff$6761 $procmux$6466 $procmux$5905 $procmux$6461 $logic_or$receiver.v:54$66 $logic_or$receiver.v:54$64 $logic_or$receiver.v:54$62 $logic_or$receiver.v:54$60 $logic_or$receiver.v:54$58 $logic_or$receiver.v:54$56 $logic_or$receiver.v:54$54 $logic_or$receiver.v:54$52 $logic_or$receiver.v:54$50 $logic_or$receiver.v:54$48 $logic_or$receiver.v:54$46 $logic_or$receiver.v:54$42 $lt$receiver.v:54$40 $gt$receiver.v:54$41 $logic_and$receiver.v:54$45 $ne$receiver.v:54$43 $ne$receiver.v:54$44 $lt$receiver.v:54$47 $gt$receiver.v:54$49 $eq$receiver.v:54$51 $eq$receiver.v:54$53 $gt$receiver.v:54$55 $ge$receiver.v:54$57 $ge$receiver.v:54$59 $ge$receiver.v:54$61 $ge$receiver.v:54$63 $ge$receiver.v:54$65
	if (posedge_p_clk) {
		p_fault.next = (p_rst ? value<31>{0u}.concat((logic_or<1>(logic_or<1>(logic_or<1>(logic_or<1>(logic_or<1>(logic_or<1>(logic_or<1>(logic_or<1>(logic_or<1>(logic_or<1>(logic_or<1>(logic_or<1>(lt_uu<1>(p_cfgp, value<2>{0x2u}), gt_uu<1>(p_cfgp, value<5>{0x11u})), logic_and<1>(ne_uu<1>(p_cfgr, value<3>{0x5u}), ne_uu<1>(p_cfgr, value<3>{0x7u}))), lt_uu<1>(p_cfgf, value<6>{0x28u})), gt_uu<1>(p_cfgf, value<10>{0x3b8u})), logic_not<1>(p_cfgk)), logic_not<1>(p_cfgperiod)), gt_uu<1>(p_cfgperiod, value<7>{0x44u})), ge_uu<1>(p_cfgphi, p_cfgperiod)), ge_uu<1>(p_cfgcp, p_cfgp)), ge_uu<1>(p_cfgrp, p_cfgr)), ge_uu<1>(p_cfgfp, p_cfgf)), ge_uu<1>(p_cfgpp, p_cfgperiod)) ? value<1>{0x1u} : value<1>{0u})).val() : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? i_13_5c_fault_5b_31_3a_0_5d_.slice<31,7>().concat(i_23_5c_fault_5b_31_3a_0_5d_.slice<6,0>()).val() : p_fault.curr));
	}
	// cells $procdff$6760 $procmux$6580 $procmux$6223 $procmux$2526 $procmux$1927
	if (posedge_p_clk) {
		p_failid.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_201__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_203__Y ? p_failid.curr : i_6_5c_qi_5b_0_5d__5b_31_3a_0_5d_) : p_failid.curr) : p_failid.curr));
	}
	// cells $procdff$6759 $procmux$6583 $procmux$6229 $procmux$2535 $procmux$1951
	if (posedge_p_clk) {
		p_failtick.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_201__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_203__Y ? p_failtick.curr : p_tick.curr) : p_failtick.curr) : p_failtick.curr));
	}
	// cells $procdff$6758 $procmux$6586 $procmux$6235
	if (posedge_p_clk) {
		p_failed.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? i_3_5c_failed_5b_0_3a_0_5d_ : p_failed.curr));
	}
	// cells $procdff$6757 $procmux$6589 $procmux$6031 $procmux$1818 $procmux$1417
	if (posedge_p_clk) {
		p_byteone.next = (p_rst ? value<8>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? p_byteone.curr : (i_logic__and_24_receiver_2e_v_3a_103_24_224__Y ? i_3_5c_bytezero_5b_7_3a_0_5d_ : p_byteone.curr)) : p_byteone.curr));
	}
	// cells $procdff$6756 $procmux$6592 $procmux$6241
	if (posedge_p_clk) {
		p_bytezero.next = (p_rst ? value<8>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? i_3_5c_bytezero_5b_7_3a_0_5d_ : p_bytezero.curr));
	}
	// cells $procdff$6755 $procmux$6595 $procmux$6037 $procmux$1827 $procmux$1429
	if (posedge_p_clk) {
		p_idone.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? p_idone.curr : (i_logic__and_24_receiver_2e_v_3a_103_24_224__Y ? i_3_5c_idzero_5b_31_3a_0_5d_ : p_idone.curr)) : p_idone.curr));
	}
	// cells $procdff$6754 $procmux$6598 $procmux$6247
	if (posedge_p_clk) {
		p_idzero.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? i_3_5c_idzero_5b_31_3a_0_5d_ : p_idzero.curr));
	}
	// cells $procdff$6753 $procmux$6601 $procmux$6043
	if (posedge_p_clk) {
		p_ownerone.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? i_3_5c_ownerone_5b_1_3a_0_5d_ : p_ownerone.curr));
	}
	// cells $procdff$6752 $procmux$6604 $procmux$6253
	if (posedge_p_clk) {
		p_ownerzero.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? i_3_5c_ownerzero_5b_1_3a_0_5d_ : p_ownerzero.curr));
	}
	// cells $procdff$6751 $procmux$6607 $procmux$6049
	if (posedge_p_clk) {
		p_rone.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? i_3_5c_rone_5b_0_3a_0_5d_ : p_rone.curr));
	}
	// cells $procdff$6750 $procmux$6610 $procmux$6055
	if (posedge_p_clk) {
		p_rzero.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? i_5_5c_rzero_5b_0_3a_0_5d_ : p_rzero.curr));
	}
	// cells $procdff$6749 $procmux$6664 $procmux$6061
	if (posedge_p_clk) {
		p_outstanding.next = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? i_7_5c_outstanding_5b_15_3a_0_5d_ : p_outstanding.curr));
	}
	// cells $procdff$6748 $procmux$6667 $procmux$6259
	if (posedge_p_clk) {
		p_qlen.next = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? i_7_5c_qlen_5b_3_3a_0_5d_ : p_qlen.curr));
	}
	// cells $procdff$6747 $procmux$6670
	if (posedge_p_clk) {
		p_bytes.next = (p_rst ? value<32>{0u} : i_2_5c_bytes_5b_31_3a_0_5d_);
	}
	// cells $procdff$6746 $procmux$6673 $procmux$6385
	if (posedge_p_clk) {
		p_counts.next = (p_rst ? value<64>{0u,0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? i_7_5c_counts_5b_63_3a_0_5d_ : p_counts.curr));
	}
	// cells $procdff$6745 $procmux$6676 $procmux$6391
	if (posedge_p_clk) {
		p_enabled.next = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? i_7_5c_enabled_5b_3_3a_0_5d_ : p_enabled.curr));
	}
	// cells $procdff$6744 $procmux$6679 $procmux$6397
	if (posedge_p_clk) {
		p_valid.next = (p_rst ? value<4>{0xfu} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? i_3_5c_valid_5b_3_3a_0_5d_ : p_valid.curr));
	}
	// cells $procdff$6743 $procmux$6682 $procmux$5875 $procmux$6446 $eq$receiver.v:127$312
	if (posedge_p_clk) {
		p_pp.next = (p_rst ? p_cfgpp : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (eq_uu<1>(i_add_24_receiver_2e_v_3a_127_24_311__Y, value<1>{0u}.concat(p_cfgperiod).val()) ? value<16>{0u} : i_add_24_receiver_2e_v_3a_127_24_311__Y.slice<15,0>().val()) : p_pp.curr));
	}
	// cells $procdff$6742 $procmux$6685 $procmux$5881 $procmux$322 $eq$receiver.v:126$309
	if (posedge_p_clk) {
		p_fp.next = (p_rst ? p_cfgfp : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (eq_uu<1>(i_add_24_receiver_2e_v_3a_126_24_308__Y, value<1>{0u}.concat(p_cfgf).val()) ? value<16>{0u} : i_add_24_receiver_2e_v_3a_126_24_308__Y.slice<15,0>().val()) : p_fp.curr));
	}
	// cells $procdff$6741 $procmux$6688 $procmux$5887 $procmux$331 $eq$receiver.v:125$306
	if (posedge_p_clk) {
		p_rp.next = (p_rst ? p_cfgrp : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (eq_uu<1>(i_add_24_receiver_2e_v_3a_125_24_305__Y, value<1>{0u}.concat(p_cfgr).val()) ? value<16>{0u} : i_add_24_receiver_2e_v_3a_125_24_305__Y.slice<15,0>().val()) : p_rp.curr));
	}
	// cells $procdff$6740 $procmux$6691 $procmux$5893 $procmux$340 $eq$receiver.v:124$303
	if (posedge_p_clk) {
		p_cp.next = (p_rst ? p_cfgcp : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? (eq_uu<1>(i_add_24_receiver_2e_v_3a_124_24_302__Y, value<1>{0u}.concat(p_cfgp).val()) ? value<16>{0u} : i_add_24_receiver_2e_v_3a_124_24_302__Y.slice<15,0>().val()) : p_cp.curr));
	}
	// cells $procdff$6739 $procmux$6694 $procmux$6331
	if (posedge_p_clk) {
		p_nextid.next = (p_rst ? value<32>{0x1u} : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? i_5_5c_nextid_5b_31_3a_0_5d_ : p_nextid.curr));
	}
	// cells $procdff$6738 $procmux$6697 $procmux$5899 $add$receiver.v:123$301
	if (posedge_p_clk) {
		p_tick.next = (p_rst ? p_cfgstart : (i_logic__and_24_receiver_2e_v_3a_55_24_69__Y ? add_uu<32>(p_tick.curr, value<1>{0x1u}) : p_tick.curr));
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
		items->add(path, "procmux$5581_Y", "", i_procmux_24_5581__Y, 0, debug_item::GENERATED|debug_item::DRIVEN_COMB);
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
