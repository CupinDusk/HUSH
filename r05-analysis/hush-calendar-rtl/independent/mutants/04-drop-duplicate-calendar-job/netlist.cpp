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
	wire<32> i_procmux_24_5649__Y;
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
		if (i_procmux_24_5649__Y.commit(observer)) changed = true;
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
	value<2> i_4_5c_releaseowner_5b_1_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<1> i_4_5c_releasevalid_5b_0_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<1> i_4_5c_rone_5b_0_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<8> i_5_5c_bytes_5b_23_3a_16_5d_;
	// \src: receiver.v:42.2-129.5
	value<16> i_5_5c_counts_5b_47_3a_32_5d_;
	// \src: receiver.v:42.2-129.5
	value<1> i_5_5c_enabled_5b_2_3a_2_5d_;
	// \src: receiver.v:42.2-129.5
	value<32> i_5_5c_fault_5b_31_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<32> i_5_5c_nextid_5b_31_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<16> i_5_5c_outstanding_5b_15_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<4> i_5_5c_qlen_5b_3_3a_0_5d_;
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
	value<2> i_6_5c_releaseowner_5b_1_3a_0_5d_;
	// \src: receiver.v:42.2-129.5
	value<1> i_6_5c_releasevalid_5b_0_3a_0_5d_;
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
	value<6> i_add_24_receiver_2e_v_3a_109_24_247__Y;
	value<17> i_add_24_receiver_2e_v_3a_124_24_322__Y;
	value<17> i_add_24_receiver_2e_v_3a_125_24_325__Y;
	value<17> i_add_24_receiver_2e_v_3a_126_24_328__Y;
	value<17> i_add_24_receiver_2e_v_3a_127_24_331__Y;
	value<6> i_add_24_receiver_2e_v_3a_82_24_137__Y;
	value<6> i_add_24_receiver_2e_v_3a_82_24_180__Y;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6918;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6920;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6922;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6924;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6926;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6928;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6930;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6932;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6938;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6940;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6944;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6946;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6954;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6962;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6972;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6980;
	// \src: receiver.v:110.11-110.68
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7101;
	// \src: receiver.v:110.11-110.68
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7102;
	// \src: receiver.v:110.39-110.68
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7103;
	value<2> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7104;
	// \src: receiver.v:110.11-110.68
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7106;
	// \src: receiver.v:110.11-110.68
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7107;
	// \src: receiver.v:109.21-109.32
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7109;
	// \src: receiver.v:95.27-95.33
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7110;
	// \src: receiver.v:93.61-93.69
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7112;
	// \src: receiver.v:93.37-93.53
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7113;
	// \src: receiver.v:93.37-93.53
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7114;
	// \src: receiver.v:93.37-93.53
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7116;
	// \src: receiver.v:93.37-93.53
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7117;
	// \src: receiver.v:91.63-91.70
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7119;
	// \src: receiver.v:83.7-83.70
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7120;
	// \src: receiver.v:83.7-83.70
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7121;
	// \src: receiver.v:83.7-83.70
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7124;
	// \src: receiver.v:83.7-83.70
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7125;
	// \src: receiver.v:82.22-82.36
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7127;
	// \src: receiver.v:74.78-74.83
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7130;
	// \src: receiver.v:83.7-83.70
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7131;
	// \src: receiver.v:83.7-83.70
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7132;
	// \src: receiver.v:83.7-83.70
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7135;
	// \src: receiver.v:83.7-83.70
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7136;
	// \src: receiver.v:82.22-82.36
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7138;
	// \src: receiver.v:65.35-65.53
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7141;
	// \src: receiver.v:65.35-65.53
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7142;
	// \src: receiver.v:65.35-65.53
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7143;
	// \src: receiver.v:65.35-65.53
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7144;
	// \src: receiver.v:109.9-109.39
	value<1> i_eq_24_receiver_2e_v_3a_109_24_249__Y;
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
	value<1> i_eq_24_receiver_2e_v_3a_78_24_175__Y;
	// \src: receiver.v:76.9-76.16
	value<1> i_ge_24_receiver_2e_v_3a_76_24_125__Y;
	// \src: receiver.v:76.9-76.16
	value<1> i_ge_24_receiver_2e_v_3a_76_24_168__Y;
	// \src: receiver.v:103.8-103.22
	value<1> i_logic__and_24_receiver_2e_v_3a_103_24_244__Y;
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
	// \src: receiver.v:74.8-74.43
	value<1> i_logic__and_24_receiver_2e_v_3a_74_24_161__Y;
	// \src: receiver.v:87.7-87.37
	value<1> i_logic__and_24_receiver_2e_v_3a_87_24_201__Y;
	// \src: receiver.v:100.9-100.23
	value<1> i_logic__or_24_receiver_2e_v_3a_100_24_242__Y;
	// \src: receiver.v:115.8-115.14
	value<1> i_lt_24_receiver_2e_v_3a_115_24_265__Y;
	// \src: receiver.v:115.8-115.14
	value<1> i_lt_24_receiver_2e_v_3a_115_24_270__Y;
	// \src: receiver.v:115.8-115.14
	value<1> i_lt_24_receiver_2e_v_3a_115_24_275__Y;
	// \src: receiver.v:115.8-115.14
	value<1> i_lt_24_receiver_2e_v_3a_115_24_280__Y;
	// \src: receiver.v:115.8-115.14
	value<1> i_lt_24_receiver_2e_v_3a_115_24_285__Y;
	// \src: receiver.v:115.8-115.14
	value<1> i_lt_24_receiver_2e_v_3a_115_24_290__Y;
	// \src: receiver.v:115.8-115.14
	value<1> i_lt_24_receiver_2e_v_3a_115_24_295__Y;
	// \src: receiver.v:115.8-115.14
	value<1> i_lt_24_receiver_2e_v_3a_115_24_300__Y;
	// \src: receiver.v:110.11-110.68
	value<33> i_neg_24_receiver_2e_v_3a_110_24_254__Y;
	// \src: receiver.v:83.7-83.70
	value<33> i_neg_24_receiver_2e_v_3a_83_24_143__Y;
	// \src: receiver.v:83.7-83.70
	value<33> i_neg_24_receiver_2e_v_3a_83_24_186__Y;
	// \src: receiver.v:93.6-93.36
	value<3> i_neg_24_receiver_2e_v_3a_93_24_218__Y;
	// \src: receiver.v:93.54-93.76
	value<33> i_neg_24_receiver_2e_v_3a_93_24_230__Y;
	value<1> i_procmux_24_1032__CMP;
	value<1> i_procmux_24_1033__CMP;
	value<1> i_procmux_24_1034__CMP;
	value<1> i_procmux_24_1035__CMP;
	value<1> i_procmux_24_1124__CMP;
	value<1> i_procmux_24_1125__CMP;
	value<1> i_procmux_24_1126__CMP;
	value<1> i_procmux_24_1127__CMP;
	value<1> i_procmux_24_1216__CMP;
	value<1> i_procmux_24_1217__CMP;
	value<1> i_procmux_24_1218__CMP;
	value<1> i_procmux_24_1219__CMP;
	value<1> i_procmux_24_2745__CMP;
	value<1> i_procmux_24_2746__CMP;
	value<1> i_procmux_24_2747__CMP;
	value<1> i_procmux_24_2748__CMP;
	value<1> i_procmux_24_2749__CMP;
	value<1> i_procmux_24_2750__CMP;
	value<1> i_procmux_24_2751__CMP;
	value<1> i_procmux_24_2752__CMP;
	value<1> i_procmux_24_3822__CMP;
	value<1> i_procmux_24_3823__CMP;
	value<1> i_procmux_24_3824__CMP;
	value<1> i_procmux_24_3825__CMP;
	value<1> i_procmux_24_3826__CMP;
	value<1> i_procmux_24_3827__CMP;
	value<1> i_procmux_24_3828__CMP;
	value<1> i_procmux_24_3829__CMP;
	value<1> i_procmux_24_388__CMP;
	value<1> i_procmux_24_389__CMP;
	value<1> i_procmux_24_390__CMP;
	value<1> i_procmux_24_391__CMP;
	value<1> i_procmux_24_480__CMP;
	value<32> i_procmux_24_4811__Y;
	value<1> i_procmux_24_481__CMP;
	value<1> i_procmux_24_482__CMP;
	value<1> i_procmux_24_483__CMP;
	value<32> i_procmux_24_5205__Y;
	value<1> i_procmux_24_572__CMP;
	value<1> i_procmux_24_573__CMP;
	value<1> i_procmux_24_574__CMP;
	value<1> i_procmux_24_575__CMP;
	value<1> i_procmux_24_664__CMP;
	value<1> i_procmux_24_665__CMP;
	value<1> i_procmux_24_666__CMP;
	value<1> i_procmux_24_667__CMP;
	value<1> i_procmux_24_756__CMP;
	value<1> i_procmux_24_757__CMP;
	value<1> i_procmux_24_758__CMP;
	value<1> i_procmux_24_759__CMP;
	value<1> i_procmux_24_848__CMP;
	value<1> i_procmux_24_849__CMP;
	value<1> i_procmux_24_850__CMP;
	value<1> i_procmux_24_851__CMP;
	value<1> i_procmux_24_940__CMP;
	value<1> i_procmux_24_941__CMP;
	value<1> i_procmux_24_942__CMP;
	value<1> i_procmux_24_943__CMP;
	// \src: receiver.v:109.20-109.36
	value<4> i_shiftx_24_receiver_2e_v_3a_109_24_248__Y;
	// \src: receiver.v:82.21-82.40
	value<4> i_shiftx_24_receiver_2e_v_3a_82_24_138__Y;
	// \src: receiver.v:82.21-82.40
	value<4> i_shiftx_24_receiver_2e_v_3a_82_24_181__Y;
	// \src: receiver.v:89.14-89.21
	value<1> i_shiftx_24_receiver_2e_v_3a_89_24_205__Y;
	// \src: receiver.v:91.62-91.74
	value<8> i_shiftx_24_receiver_2e_v_3a_91_24_212__Y;
	// connection
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7138.slice<31,5>() = value<27>{0u};
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
	i_procmux_24_5205__Y.slice<31,2>() = p_fault.curr.slice<31,2>().val();
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
	// cell $ge$receiver.v:76$125
	i_ge_24_receiver_2e_v_3a_76_24_125__Y = ge_uu<1>(p_qlen.curr, value<4>{0x8u});
	// \src: receiver.v:72.16-72.20
	// cell $lt$receiver.v:72$111
	i_logic__and_24_receiver_2e_v_3a_72_24_112__Y = lt_uu<1>(p_fp.curr, value<3>{0x4u});
	// cells $logic_and$receiver.v:55$75 $logic_not$receiver.v:55$73 $eq$receiver.v:55$74
	i_logic__and_24_receiver_2e_v_3a_55_24_75__Y = logic_and<1>(logic_not<1>(p_failed.curr), logic_not<1>(p_fault.curr));
	// cells $procmux$5823 $procmux$5820 $procmux$5818
	i_6_5c_enabled_5b_3_3a_3_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_59_24_93__Y ? value<1>{0x1u} : p_enabled.curr.slice<3>().val()) : value<1>{0u}));
	// cells $procmux$5814 $procmux$5811 $procmux$5809
	i_6_5c_counts_5b_63_3a_48_5d_ = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_59_24_93__Y ? p_cfgk : p_counts.curr.slice<63,48>().val()) : value<16>{0u}));
	// cells $procmux$5859 $procmux$5856 $procmux$5854
	i_5_5c_enabled_5b_2_3a_2_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_59_24_92__Y ? value<1>{0x1u} : p_enabled.curr.slice<2>().val()) : value<1>{0u}));
	// cells $procmux$5850 $procmux$5847 $procmux$5845
	i_5_5c_counts_5b_47_3a_32_5d_ = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_59_24_92__Y ? p_cfgk : p_counts.curr.slice<47,32>().val()) : value<16>{0u}));
	// cells $procmux$5895 $procmux$5892 $procmux$5890
	i_4_5c_enabled_5b_1_3a_1_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_59_24_91__Y ? value<1>{0x1u} : p_enabled.curr.slice<1>().val()) : value<1>{0u}));
	// cells $procmux$5886 $procmux$5883 $procmux$5881
	i_4_5c_counts_5b_31_3a_16_5d_ = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_59_24_91__Y ? p_cfgk : p_counts.curr.slice<31,16>().val()) : value<16>{0u}));
	// cells $procmux$5931 $procmux$5928 $procmux$5926
	i_3_5c_enabled_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_59_24_90__Y ? value<1>{0x1u} : p_enabled.curr.slice<0>().val()) : value<1>{0u}));
	// cells $procmux$5922 $procmux$5919 $procmux$5917
	i_3_5c_counts_5b_15_3a_0_5d_ = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_59_24_90__Y ? p_cfgk : p_counts.curr.slice<15,0>().val()) : value<16>{0u}));
	// cells $procmux$4852 $procmux$4849 $procmux$4865
	i_4_5c_releaseowner_5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_72_24_112__Y ? p_fp.curr.slice<1,0>().val() : value<2>{0u}) : value<2>{0u}));
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
	// cell $mul$receiver.v:83$147
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7138.slice<4,0>() = mul_uu<5>(value<3>{0x4u}, i_4_5c_releaseowner_5b_1_3a_0_5d_);
	// \full_case: 1
	// \src: receiver.v:64.10-64.29|receiver.v:64.7-65.128
	// cell $procmux$5497
	i_6_5c_fault_5b_31_3a_0_5d_.slice<1,0>() = (i_eq_24_receiver_2e_v_3a_64_24_95__Y ? value<1>{0x1u}.concat(p_fault.curr.slice<0>()).val() : p_fault.curr.slice<1,0>().val());
	// \src: receiver.v:83.49-83.68
	// cell $add$receiver.v:83$148
	i_add_24_receiver_2e_v_3a_82_24_137__Y = add_uu<6>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7138.slice<4,0>().val(), value<1>{0u});
	// \full_case: 1
	// \src: receiver.v:63.9-63.19|receiver.v:63.6-66.9
	// cell $procmux$5583
	i_5_5c_fault_5b_31_3a_0_5d_.slice<1,0>() = (i_3_5c_enabled_5b_0_3a_0_5d_ ? i_6_5c_fault_5b_31_3a_0_5d_.slice<1,0>().val() : p_fault.curr.slice<1,0>().val());
	// \src: receiver.v:83.49-83.68
	// cell $shiftx$receiver.v:83$149
	i_shiftx_24_receiver_2e_v_3a_82_24_138__Y = shiftx_us<4>(p_outstanding.curr, value<1>{0u}.concat(i_add_24_receiver_2e_v_3a_82_24_137__Y).val());
	// \full_case: 1
	// \src: receiver.v:64.10-64.29|receiver.v:64.7-65.128
	// cell $procmux$5308
	i_8_5c_fault_5b_31_3a_0_5d_.slice<1,0>() = (i_eq_24_receiver_2e_v_3a_64_24_99__Y ? value<1>{0x1u}.concat(i_5_5c_fault_5b_31_3a_0_5d_.slice<0>()).val() : i_5_5c_fault_5b_31_3a_0_5d_.slice<1,0>().val());
	// \full_case: 1
	// \src: receiver.v:63.9-63.19|receiver.v:63.6-66.9
	// cell $procmux$5394
	i_7_5c_fault_5b_31_3a_0_5d_.slice<1,0>() = (i_4_5c_enabled_5b_1_3a_1_5d_ ? i_8_5c_fault_5b_31_3a_0_5d_.slice<1,0>().val() : i_5_5c_fault_5b_31_3a_0_5d_.slice<1,0>().val());
	// \full_case: 1
	// \src: receiver.v:64.10-64.29|receiver.v:64.7-65.128
	// cell $procmux$5119
	i_10_5c_fault_5b_31_3a_0_5d_.slice<1,0>() = (i_eq_24_receiver_2e_v_3a_64_24_103__Y ? value<1>{0x1u}.concat(i_7_5c_fault_5b_31_3a_0_5d_.slice<0>()).val() : i_7_5c_fault_5b_31_3a_0_5d_.slice<1,0>().val());
	// \full_case: 1
	// \src: receiver.v:63.9-63.19|receiver.v:63.6-66.9
	// cell $procmux$5205
	i_procmux_24_5205__Y.slice<1,0>() = (i_5_5c_enabled_5b_2_3a_2_5d_ ? i_10_5c_fault_5b_31_3a_0_5d_.slice<1,0>().val() : i_7_5c_fault_5b_31_3a_0_5d_.slice<1,0>().val());
	// cells $procmux$5212 $procmux$5209 $procmux$5207
	i_11_5c_fault_5b_31_3a_0_5d_.next.slice<31,2>().concat(i_9_5c_fault_5b_31_3a_0_5d_.slice<1,0>()) = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_eq_24_receiver_2e_v_3a_61_24_94__Y ? p_fault.curr.slice<31,2>().concat(i_procmux_24_5205__Y.slice<1,0>()).val() : value<32>{0u}) : value<32>{0u}));
	// \full_case: 1
	// \src: receiver.v:43.6-43.9|receiver.v:43.3-128.6
	// cell $procmux$5652
	i_14_5c_fault_5b_31_3a_0_5d_.next.slice<31,4>().concat(i_4_5c_fault_5b_31_3a_0_5d_.slice<3,0>()) = (p_rst ? value<32>{0u} : i_procmux_24_5649__Y.curr);
	// connection
	i_9_5c_fault_5b_31_3a_0_5d_.slice<31,2>() = i_11_5c_fault_5b_31_3a_0_5d_.curr.slice<31,2>().val();
	// \full_case: 1
	// \src: receiver.v:64.10-64.29|receiver.v:64.7-65.128
	// cell $procmux$4930
	i_12_5c_fault_5b_31_3a_0_5d_.slice<1,0>() = (i_eq_24_receiver_2e_v_3a_64_24_107__Y ? value<1>{0x1u}.concat(i_9_5c_fault_5b_31_3a_0_5d_.slice<0>()).val() : i_9_5c_fault_5b_31_3a_0_5d_.slice<1,0>().val());
	// connection
	i_4_5c_fault_5b_31_3a_0_5d_.slice<31,4>() = i_14_5c_fault_5b_31_3a_0_5d_.curr.slice<31,4>().val();
	// cells $procmux$3807 $eq$receiver.v:82$139
	i_15_5c_fault_5b_31_3a_0_5d_.slice<3,0>() = (eq_uu<1>(i_shiftx_24_receiver_2e_v_3a_82_24_138__Y, value<4>{0xfu}) ? value<1>{0x1u}.concat(i_4_5c_fault_5b_31_3a_0_5d_.slice<2,0>()).val() : i_4_5c_fault_5b_31_3a_0_5d_.slice<3,0>().val());
	// connection
	i_12_5c_fault_5b_31_3a_0_5d_.slice<31,2>() = i_11_5c_fault_5b_31_3a_0_5d_.curr.slice<31,2>().val();
	// connection
	i_15_5c_fault_5b_31_3a_0_5d_.slice<31,4>() = i_14_5c_fault_5b_31_3a_0_5d_.curr.slice<31,4>().val();
	// \full_case: 1
	// \src: receiver.v:76.9-76.16|receiver.v:76.6-84.9
	// cell $procmux$4218
	i_14_5c_fault_5b_31_3a_0_5d_.next.slice<3,0>() = (i_ge_24_receiver_2e_v_3a_76_24_125__Y ? i_4_5c_fault_5b_31_3a_0_5d_.slice<3>().concat(value<1>{0x1u}).concat(i_4_5c_fault_5b_31_3a_0_5d_.slice<1,0>()).val() : i_15_5c_fault_5b_31_3a_0_5d_.slice<3,0>().val());
	// \full_case: 1
	// \src: receiver.v:63.9-63.19|receiver.v:63.6-66.9
	// cell $procmux$5016
	i_11_5c_fault_5b_31_3a_0_5d_.next.slice<1,0>() = (i_6_5c_enabled_5b_3_3a_3_5d_ ? i_12_5c_fault_5b_31_3a_0_5d_.slice<1,0>().val() : i_9_5c_fault_5b_31_3a_0_5d_.slice<1,0>().val());
	// cells $procmux$5649 $procmux$5647
	i_procmux_24_5649__Y.next = (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_eq_24_receiver_2e_v_3a_61_24_94__Y ? i_11_5c_fault_5b_31_3a_0_5d_.curr : p_fault.curr) : value<32>{0u});
	// cells $procmux$4861 $procmux$4858 $procmux$4874
	i_4_5c_releasevalid_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_72_24_112__Y ? value<1>{0x1u} : value<1>{0u}) : value<1>{0u}));
	// \full_case: 1
	// \src: receiver.v:81.7-81.28
	// cell $procmux$4143_CMP0
	i_procmux_24_3828__CMP = eq_uu<1>(p_qlen.curr.slice<2,0>().val(), value<1>{0x1u});
	// \full_case: 1
	// \src: receiver.v:81.7-81.28
	// cell $procmux$4142_CMP0
	i_procmux_24_3827__CMP = eq_uu<1>(p_qlen.curr.slice<2,0>().val(), value<2>{0x2u});
	// \full_case: 1
	// \src: receiver.v:81.7-81.28
	// cell $procmux$4141_CMP0
	i_procmux_24_3826__CMP = eq_uu<1>(p_qlen.curr.slice<2,0>().val(), value<2>{0x3u});
	// \full_case: 1
	// \src: receiver.v:81.7-81.28
	// cell $procmux$4140_CMP0
	i_procmux_24_3825__CMP = eq_uu<1>(p_qlen.curr.slice<2,0>().val(), value<3>{0x4u});
	// \full_case: 1
	// \src: receiver.v:81.7-81.28
	// cell $procmux$4139_CMP0
	i_procmux_24_3824__CMP = eq_uu<1>(p_qlen.curr.slice<2,0>().val(), value<3>{0x5u});
	// \full_case: 1
	// \src: receiver.v:81.7-81.28
	// cell $procmux$4138_CMP0
	i_procmux_24_3823__CMP = eq_uu<1>(p_qlen.curr.slice<2,0>().val(), value<3>{0x6u});
	// \full_case: 1
	// \src: receiver.v:81.7-81.28
	// cell $procmux$4137_CMP0
	i_procmux_24_3822__CMP = eq_uu<1>(p_qlen.curr.slice<2,0>().val(), value<3>{0x7u});
	// \full_case: 1
	// \src: receiver.v:81.7-81.28
	// cell $procmux$4144_CMP0
	i_procmux_24_3829__CMP = logic_not<1>(p_qlen.curr.slice<2,0>().val());
	// cell $auto$opt_reduce.cc:131:opt_pmux$7011
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6930 = reduce_or<1>(i_procmux_24_3828__CMP.concat(i_procmux_24_3827__CMP).concat(i_procmux_24_3826__CMP).concat(i_procmux_24_3825__CMP).concat(i_procmux_24_3824__CMP).concat(i_procmux_24_3823__CMP).concat(i_procmux_24_3822__CMP).val());
	// \src: receiver.v:74.78-74.83
	// cell $sub$receiver.v:74$162
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7130.slice<1,0>() = sub_uu<2>(p_fp.curr.slice<1,0>().val(), value<1>{0u});
	// cells $logic_and$receiver.v:74$161 $logic_and$receiver.v:74$159 $ne$receiver.v:74$156 $ge$receiver.v:74$158 $lt$receiver.v:74$160
	i_logic__and_24_receiver_2e_v_3a_74_24_161__Y = logic_and<1>(logic_and<1>(ne_uu<1>(p_cfgf, value<6>{0x28u}), ge_uu<1>(p_fp.curr, value<6>{0x28u})), lt_uu<1>(p_fp.curr, value<6>{0x2cu}));
	// \src: receiver.v:65.35-65.53
	// cell $sub$receiver.v:65$109
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7141.slice<15,0>() = sub_uu<16>(i_6_5c_counts_5b_63_3a_48_5d_, value<1>{0x1u});
	// \src: receiver.v:65.35-65.53
	// cell $sub$receiver.v:65$97
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7144.slice<15,0>() = sub_uu<16>(i_3_5c_counts_5b_15_3a_0_5d_, value<1>{0x1u});
	// \src: receiver.v:65.35-65.53
	// cell $sub$receiver.v:65$101
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7143.slice<15,0>() = sub_uu<16>(i_4_5c_counts_5b_31_3a_16_5d_, value<1>{0x1u});
	// \src: receiver.v:65.35-65.53
	// cell $sub$receiver.v:65$105
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7142.slice<15,0>() = sub_uu<16>(i_5_5c_counts_5b_47_3a_32_5d_, value<1>{0x1u});
	// cells $procmux$4834 $procmux$4831 $procmux$4829 $procmux$4554 $add$receiver.v:81$134
	i_3_5c_qlen_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_4_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_125__Y ? p_qlen.curr : add_uu<4>(p_qlen.curr, value<1>{0x1u})) : p_qlen.curr) : value<4>{0u}));
	// \src: receiver.v:65.57-65.76
	// cell $eq$receiver.v:65$110
	i_eq_24_receiver_2e_v_3a_65_24_110__Y = logic_not<1>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7141.slice<15,0>().val());
	// \src: receiver.v:65.57-65.76
	// cell $eq$receiver.v:65$98
	i_eq_24_receiver_2e_v_3a_65_24_98__Y = logic_not<1>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7144.slice<15,0>().val());
	// \src: receiver.v:65.57-65.76
	// cell $eq$receiver.v:65$102
	i_eq_24_receiver_2e_v_3a_65_24_102__Y = logic_not<1>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7143.slice<15,0>().val());
	// \src: receiver.v:65.57-65.76
	// cell $eq$receiver.v:65$106
	i_eq_24_receiver_2e_v_3a_65_24_106__Y = logic_not<1>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7142.slice<15,0>().val());
	// \full_case: 1
	// \src: receiver.v:81.7-81.28
	// cell $procmux$3066_CMP0
	i_procmux_24_2751__CMP = eq_uu<1>(i_3_5c_qlen_5b_3_3a_0_5d_.slice<2,0>().val(), value<1>{0x1u});
	// \full_case: 1
	// \src: receiver.v:81.7-81.28
	// cell $procmux$3065_CMP0
	i_procmux_24_2750__CMP = eq_uu<1>(i_3_5c_qlen_5b_3_3a_0_5d_.slice<2,0>().val(), value<2>{0x2u});
	// \full_case: 1
	// \src: receiver.v:81.7-81.28
	// cell $procmux$3064_CMP0
	i_procmux_24_2749__CMP = eq_uu<1>(i_3_5c_qlen_5b_3_3a_0_5d_.slice<2,0>().val(), value<2>{0x3u});
	// \full_case: 1
	// \src: receiver.v:81.7-81.28
	// cell $procmux$3063_CMP0
	i_procmux_24_2748__CMP = eq_uu<1>(i_3_5c_qlen_5b_3_3a_0_5d_.slice<2,0>().val(), value<3>{0x4u});
	// \full_case: 1
	// \src: receiver.v:81.7-81.28
	// cell $procmux$3062_CMP0
	i_procmux_24_2747__CMP = eq_uu<1>(i_3_5c_qlen_5b_3_3a_0_5d_.slice<2,0>().val(), value<3>{0x5u});
	// \full_case: 1
	// \src: receiver.v:81.7-81.28
	// cell $procmux$3061_CMP0
	i_procmux_24_2746__CMP = eq_uu<1>(i_3_5c_qlen_5b_3_3a_0_5d_.slice<2,0>().val(), value<3>{0x6u});
	// \full_case: 1
	// \src: receiver.v:81.7-81.28
	// cell $procmux$3060_CMP0
	i_procmux_24_2745__CMP = eq_uu<1>(i_3_5c_qlen_5b_3_3a_0_5d_.slice<2,0>().val(), value<3>{0x7u});
	// cells $procmux$4748 $procmux$4458 $procmux$3989
	i_3_5c_qo_5b_0_5d__5b_1_3a_0_5d_ = (i_4_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_125__Y ? p_qo_5b_0_5d_.curr : (i_procmux_24_3829__CMP ? i_4_5c_releaseowner_5b_1_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6930 ? p_qo_5b_0_5d_.curr : value<2>{0u}))) : p_qo_5b_0_5d_.curr);
	// cells $procmux$3775 $procmux$3772 $procmux$3770
	i_6_5c_releaseowner_5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_74_24_161__Y ? i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7130.slice<1,0>().val() : value<2>{0u}) : value<2>{0u}));
	// \full_case: 1
	// \src: receiver.v:81.7-81.28
	// cell $procmux$3067_CMP0
	i_procmux_24_2752__CMP = logic_not<1>(i_3_5c_qlen_5b_3_3a_0_5d_.slice<2,0>().val());
	// cell $auto$opt_reduce.cc:131:opt_pmux$7039
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6980 = reduce_or<1>(i_procmux_24_2751__CMP.concat(i_procmux_24_2750__CMP).concat(i_procmux_24_2749__CMP).concat(i_procmux_24_2748__CMP).concat(i_procmux_24_2747__CMP).concat(i_procmux_24_2746__CMP).concat(i_procmux_24_2745__CMP).val());
	// cell $auto$opt_reduce.cc:131:opt_pmux$6931
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6932 = reduce_or<1>(i_procmux_24_3829__CMP.concat(i_procmux_24_3827__CMP).concat(i_procmux_24_3826__CMP).concat(i_procmux_24_3825__CMP).concat(i_procmux_24_3824__CMP).concat(i_procmux_24_3823__CMP).concat(i_procmux_24_3822__CMP).val());
	// \src: receiver.v:76.9-76.16
	// cell $ge$receiver.v:76$168
	i_ge_24_receiver_2e_v_3a_76_24_168__Y = ge_uu<1>(i_3_5c_qlen_5b_3_3a_0_5d_, value<4>{0x8u});
	// cells $procmux$3784 $procmux$3781 $procmux$3779
	i_6_5c_releasevalid_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_74_24_161__Y ? value<1>{0x1u} : value<1>{0u}) : value<1>{0u}));
	// cells $procmux$4739 $procmux$4446 $procmux$4136
	i_3_5c_qo_5b_1_5d__5b_1_3a_0_5d_ = (i_4_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_125__Y ? p_qo_5b_1_5d_.curr : (i_procmux_24_3828__CMP ? i_4_5c_releaseowner_5b_1_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6932 ? p_qo_5b_1_5d_.curr : value<2>{0u}))) : p_qo_5b_1_5d_.curr);
	// cell $auto$opt_reduce.cc:131:opt_pmux$6985
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6938 = reduce_or<1>(i_procmux_24_2752__CMP.concat(i_procmux_24_2750__CMP).concat(i_procmux_24_2749__CMP).concat(i_procmux_24_2748__CMP).concat(i_procmux_24_2747__CMP).concat(i_procmux_24_2746__CMP).concat(i_procmux_24_2745__CMP).val());
	// cell $auto$opt_reduce.cc:131:opt_pmux$6933
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6918 = reduce_or<1>(i_procmux_24_3829__CMP.concat(i_procmux_24_3828__CMP).concat(i_procmux_24_3826__CMP).concat(i_procmux_24_3825__CMP).concat(i_procmux_24_3824__CMP).concat(i_procmux_24_3823__CMP).concat(i_procmux_24_3822__CMP).val());
	// cells $procmux$5778 $procmux$5775 $procmux$5773 $procmux$5052 $procmux$4990 $procmux$4912
	i_3_5c_valid_5b_3_3a_0_5d_.slice<3>() = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_eq_24_receiver_2e_v_3a_61_24_94__Y ? (i_6_5c_enabled_5b_3_3a_3_5d_ ? (i_eq_24_receiver_2e_v_3a_64_24_107__Y ? p_valid.curr.slice<3>().val() : (i_eq_24_receiver_2e_v_3a_65_24_110__Y ? value<1>{0u} : p_valid.curr.slice<3>().val())) : p_valid.curr.slice<3>().val()) : p_valid.curr.slice<3>().val()) : value<1>{0u}));
	// cells $procmux$5751 $procmux$5748 $procmux$5746 $procmux$5619 $procmux$5557 $procmux$5479
	i_3_5c_valid_5b_3_3a_0_5d_.slice<0>() = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_eq_24_receiver_2e_v_3a_61_24_94__Y ? (i_3_5c_enabled_5b_0_3a_0_5d_ ? (i_eq_24_receiver_2e_v_3a_64_24_95__Y ? p_valid.curr.slice<0>().val() : (i_eq_24_receiver_2e_v_3a_65_24_98__Y ? value<1>{0u} : p_valid.curr.slice<0>().val())) : p_valid.curr.slice<0>().val()) : p_valid.curr.slice<0>().val()) : value<1>{0u}));
	// cells $procmux$5715 $procmux$5712 $procmux$5710 $procmux$5430 $procmux$5368 $procmux$5290
	i_3_5c_valid_5b_3_3a_0_5d_.slice<1>() = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_eq_24_receiver_2e_v_3a_61_24_94__Y ? (i_4_5c_enabled_5b_1_3a_1_5d_ ? (i_eq_24_receiver_2e_v_3a_64_24_99__Y ? p_valid.curr.slice<1>().val() : (i_eq_24_receiver_2e_v_3a_65_24_102__Y ? value<1>{0u} : p_valid.curr.slice<1>().val())) : p_valid.curr.slice<1>().val()) : p_valid.curr.slice<1>().val()) : value<1>{0u}));
	// cells $procmux$5679 $procmux$5676 $procmux$5674 $procmux$5241 $procmux$5179 $procmux$5101
	i_3_5c_valid_5b_3_3a_0_5d_.slice<2>() = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_eq_24_receiver_2e_v_3a_61_24_94__Y ? (i_5_5c_enabled_5b_2_3a_2_5d_ ? (i_eq_24_receiver_2e_v_3a_64_24_103__Y ? p_valid.curr.slice<2>().val() : (i_eq_24_receiver_2e_v_3a_65_24_106__Y ? value<1>{0u} : p_valid.curr.slice<2>().val())) : p_valid.curr.slice<2>().val()) : p_valid.curr.slice<2>().val()) : value<1>{0u}));
	// cells $procmux$3676 $procmux$3673 $procmux$3671 $procmux$3381 $procmux$2912
	i_6_5c_qo_5b_0_5d__5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_6_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_168__Y ? i_3_5c_qo_5b_0_5d__5b_1_3a_0_5d_ : (i_procmux_24_2752__CMP ? i_6_5c_releaseowner_5b_1_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6980 ? i_3_5c_qo_5b_0_5d__5b_1_3a_0_5d_ : value<2>{0u}))) : i_3_5c_qo_5b_0_5d__5b_1_3a_0_5d_) : value<2>{0u}));
	// cells $procmux$3757 $procmux$3754 $procmux$3752 $procmux$3477 $add$receiver.v:81$177
	i_5_5c_qlen_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_6_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_168__Y ? i_3_5c_qlen_5b_3_3a_0_5d_ : add_uu<4>(i_3_5c_qlen_5b_3_3a_0_5d_, value<1>{0x1u})) : i_3_5c_qlen_5b_3_3a_0_5d_) : value<4>{0u}));
	// \src: receiver.v:89.14-89.21
	// cell $shiftx$receiver.v:89$205
	i_shiftx_24_receiver_2e_v_3a_89_24_205__Y = shiftx_uu<1>(i_3_5c_valid_5b_3_3a_0_5d_, i_6_5c_qo_5b_0_5d__5b_1_3a_0_5d_);
	// cells $procmux$3662 $procmux$3369 $procmux$3059
	i_6_5c_qo_5b_1_5d__5b_1_3a_0_5d_ = (i_6_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_168__Y ? i_3_5c_qo_5b_1_5d__5b_1_3a_0_5d_ : (i_procmux_24_2751__CMP ? i_6_5c_releaseowner_5b_1_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6938 ? i_3_5c_qo_5b_1_5d__5b_1_3a_0_5d_ : value<2>{0u}))) : i_3_5c_qo_5b_1_5d__5b_1_3a_0_5d_);
	// cells $logic_and$receiver.v:87$201 $logic_and$receiver.v:87$199 $eq$receiver.v:87$197 $logic_not$receiver.v:87$198 $ne$receiver.v:87$200
	i_logic__and_24_receiver_2e_v_3a_87_24_201__Y = logic_and<1>(logic_and<1>(logic_not<1>(p_cp.curr), logic_not<1>(p_rzero.curr)), reduce_bool<1>(i_5_5c_qlen_5b_3_3a_0_5d_));
	// cells $procmux$4730 $procmux$4434 $procmux$4115
	i_3_5c_qo_5b_2_5d__5b_1_3a_0_5d_ = (i_4_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_125__Y ? p_qo_5b_2_5d_.curr : (i_procmux_24_3827__CMP ? i_4_5c_releaseowner_5b_1_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6918 ? p_qo_5b_2_5d_.curr : value<2>{0u}))) : p_qo_5b_2_5d_.curr);
	// cell $auto$opt_reduce.cc:131:opt_pmux$6993
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6940 = reduce_or<1>(i_procmux_24_2752__CMP.concat(i_procmux_24_2751__CMP).concat(i_procmux_24_2749__CMP).concat(i_procmux_24_2748__CMP).concat(i_procmux_24_2747__CMP).concat(i_procmux_24_2746__CMP).concat(i_procmux_24_2745__CMP).val());
	// \src: receiver.v:95.27-95.33
	// cell $sub$receiver.v:95$237
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7110.slice<3,0>() = sub_uu<4>(i_5_5c_qlen_5b_3_3a_0_5d_, value<1>{0x1u});
	// cell $auto$opt_reduce.cc:131:opt_pmux$6935
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6920 = reduce_or<1>(i_procmux_24_3829__CMP.concat(i_procmux_24_3828__CMP).concat(i_procmux_24_3827__CMP).concat(i_procmux_24_3825__CMP).concat(i_procmux_24_3824__CMP).concat(i_procmux_24_3823__CMP).concat(i_procmux_24_3822__CMP).val());
	// cells $procmux$2518 $procmux$2515 $procmux$2513 $procmux$2175
	i_9_5c_qo_5b_0_5d__5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_201__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_205__Y ? i_6_5c_qo_5b_1_5d__5b_1_3a_0_5d_ : i_6_5c_qo_5b_0_5d__5b_1_3a_0_5d_) : i_6_5c_qo_5b_0_5d__5b_1_3a_0_5d_) : value<2>{0u}));
	// cells $procmux$3653 $procmux$3357 $procmux$3038
	i_6_5c_qo_5b_2_5d__5b_1_3a_0_5d_ = (i_6_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_168__Y ? i_3_5c_qo_5b_2_5d__5b_1_3a_0_5d_ : (i_procmux_24_2750__CMP ? i_6_5c_releaseowner_5b_1_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6940 ? i_3_5c_qo_5b_2_5d__5b_1_3a_0_5d_ : value<2>{0u}))) : i_3_5c_qo_5b_2_5d__5b_1_3a_0_5d_);
	// \full_case: 1
	// \src: receiver.v:116.37-116.37|receiver.v:116.6-116.104
	// cell $procmux$1260_CMP0
	i_procmux_24_1218__CMP = eq_uu<1>(i_9_5c_qo_5b_0_5d__5b_1_3a_0_5d_, value<1>{0x1u});
	// \full_case: 1
	// \src: receiver.v:116.57-116.57|receiver.v:116.6-116.104
	// cell $procmux$1259_CMP0
	i_procmux_24_1217__CMP = eq_uu<1>(i_9_5c_qo_5b_0_5d__5b_1_3a_0_5d_, value<2>{0x2u});
	// \full_case: 1
	// \src: receiver.v:116.77-116.77|receiver.v:116.6-116.104
	// cell $procmux$1258_CMP0
	i_procmux_24_1216__CMP = eq_uu<1>(i_9_5c_qo_5b_0_5d__5b_1_3a_0_5d_, value<2>{0x3u});
	// \full_case: 1
	// \src: receiver.v:116.17-116.17|receiver.v:116.6-116.104
	// cell $procmux$1261_CMP0
	i_procmux_24_1219__CMP = logic_not<1>(i_9_5c_qo_5b_0_5d__5b_1_3a_0_5d_);
	// cells $procmux$2680 $procmux$2677 $procmux$2675 $procmux$2343
	i_7_5c_qlen_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_201__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_205__Y ? i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7110.slice<3,0>().val() : i_5_5c_qlen_5b_3_3a_0_5d_) : i_5_5c_qlen_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$4721 $procmux$4422 $procmux$4094
	i_3_5c_qo_5b_3_5d__5b_1_3a_0_5d_ = (i_4_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_125__Y ? p_qo_5b_3_5d_.curr : (i_procmux_24_3826__CMP ? i_4_5c_releaseowner_5b_1_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6920 ? p_qo_5b_3_5d_.curr : value<2>{0u}))) : p_qo_5b_3_5d_.curr);
	// cell $auto$opt_reduce.cc:131:opt_pmux$7001
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6944 = reduce_or<1>(i_procmux_24_2752__CMP.concat(i_procmux_24_2751__CMP).concat(i_procmux_24_2750__CMP).concat(i_procmux_24_2748__CMP).concat(i_procmux_24_2747__CMP).concat(i_procmux_24_2746__CMP).concat(i_procmux_24_2745__CMP).val());
	// \src: receiver.v:115.8-115.14
	// cell $lt$receiver.v:115$265
	i_lt_24_receiver_2e_v_3a_115_24_265__Y = lt_uu<1>(value<1>{0u}, i_7_5c_qlen_5b_3_3a_0_5d_);
	// cell $auto$opt_reduce.cc:131:opt_pmux$6941
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6922 = reduce_or<1>(i_procmux_24_3829__CMP.concat(i_procmux_24_3828__CMP).concat(i_procmux_24_3827__CMP).concat(i_procmux_24_3826__CMP).concat(i_procmux_24_3824__CMP).concat(i_procmux_24_3823__CMP).concat(i_procmux_24_3822__CMP).val());
	// cells $procmux$2509 $procmux$2506 $procmux$2504 $procmux$2163
	i_9_5c_qo_5b_1_5d__5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_201__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_205__Y ? i_6_5c_qo_5b_2_5d__5b_1_3a_0_5d_ : i_6_5c_qo_5b_1_5d__5b_1_3a_0_5d_) : i_6_5c_qo_5b_1_5d__5b_1_3a_0_5d_) : value<2>{0u}));
	// cells $procmux$3644 $procmux$3345 $procmux$3017
	i_6_5c_qo_5b_3_5d__5b_1_3a_0_5d_ = (i_6_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_168__Y ? i_3_5c_qo_5b_3_5d__5b_1_3a_0_5d_ : (i_procmux_24_2749__CMP ? i_6_5c_releaseowner_5b_1_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6944 ? i_3_5c_qo_5b_3_5d__5b_1_3a_0_5d_ : value<2>{0u}))) : i_3_5c_qo_5b_3_5d__5b_1_3a_0_5d_);
	// \full_case: 1
	// \src: receiver.v:116.37-116.37|receiver.v:116.6-116.104
	// cell $procmux$1168_CMP0
	i_procmux_24_1126__CMP = eq_uu<1>(i_9_5c_qo_5b_1_5d__5b_1_3a_0_5d_, value<1>{0x1u});
	// \full_case: 1
	// \src: receiver.v:116.57-116.57|receiver.v:116.6-116.104
	// cell $procmux$1167_CMP0
	i_procmux_24_1125__CMP = eq_uu<1>(i_9_5c_qo_5b_1_5d__5b_1_3a_0_5d_, value<2>{0x2u});
	// \full_case: 1
	// \src: receiver.v:116.77-116.77|receiver.v:116.6-116.104
	// cell $procmux$1166_CMP0
	i_procmux_24_1124__CMP = eq_uu<1>(i_9_5c_qo_5b_1_5d__5b_1_3a_0_5d_, value<2>{0x3u});
	// cells $procmux$1303 $procmux$1300 $procmux$1298 $procmux$1215 $auto$opt_reduce.cc:131:opt_pmux$6957
	i_3_5c_tokens0_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_265__Y ? (i_procmux_24_1219__CMP ? value<4>{0x1u} : (reduce_or<1>(i_procmux_24_1218__CMP.concat(i_procmux_24_1217__CMP).concat(i_procmux_24_1216__CMP).val()) ? value<4>{0u} : value<4>{0u})) : value<4>{0u}) : value<4>{0u}));
	// \full_case: 1
	// \src: receiver.v:116.17-116.17|receiver.v:116.6-116.104
	// cell $procmux$1169_CMP0
	i_procmux_24_1127__CMP = logic_not<1>(i_9_5c_qo_5b_1_5d__5b_1_3a_0_5d_);
	// cells $procmux$1294 $procmux$1291 $procmux$1289 $procmux$1257 $auto$opt_reduce.cc:131:opt_pmux$6947
	i_3_5c_tokens1_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_265__Y ? (i_procmux_24_1218__CMP ? value<4>{0x1u} : (reduce_or<1>(i_procmux_24_1219__CMP.concat(i_procmux_24_1217__CMP).concat(i_procmux_24_1216__CMP).val()) ? value<4>{0u} : value<4>{0u})) : value<4>{0u}) : value<4>{0u}));
	// cells $procmux$1285 $procmux$1282 $procmux$1280 $procmux$1243 $auto$opt_reduce.cc:131:opt_pmux$6949
	i_3_5c_tokens2_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_265__Y ? (i_procmux_24_1217__CMP ? value<4>{0x1u} : (reduce_or<1>(i_procmux_24_1219__CMP.concat(i_procmux_24_1218__CMP).concat(i_procmux_24_1216__CMP).val()) ? value<4>{0u} : value<4>{0u})) : value<4>{0u}) : value<4>{0u}));
	// cells $procmux$1276 $procmux$1273 $procmux$1271 $procmux$1229 $auto$opt_reduce.cc:131:opt_pmux$6951
	i_3_5c_tokens3_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_265__Y ? (reduce_or<1>(i_procmux_24_1219__CMP.concat(i_procmux_24_1218__CMP).concat(i_procmux_24_1217__CMP).val()) ? value<4>{0u} : (i_procmux_24_1216__CMP ? value<4>{0x1u} : value<4>{0u})) : value<4>{0u}) : value<4>{0u}));
	// cells $procmux$4712 $procmux$4410 $procmux$4073
	i_3_5c_qo_5b_4_5d__5b_1_3a_0_5d_ = (i_4_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_125__Y ? p_qo_5b_4_5d_.curr : (i_procmux_24_3825__CMP ? i_4_5c_releaseowner_5b_1_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6922 ? p_qo_5b_4_5d_.curr : value<2>{0u}))) : p_qo_5b_4_5d_.curr);
	// cell $auto$opt_reduce.cc:131:opt_pmux$7007
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6946 = reduce_or<1>(i_procmux_24_2752__CMP.concat(i_procmux_24_2751__CMP).concat(i_procmux_24_2750__CMP).concat(i_procmux_24_2749__CMP).concat(i_procmux_24_2747__CMP).concat(i_procmux_24_2746__CMP).concat(i_procmux_24_2745__CMP).val());
	// \src: receiver.v:115.8-115.14
	// cell $lt$receiver.v:115$270
	i_lt_24_receiver_2e_v_3a_115_24_270__Y = lt_uu<1>(value<1>{0x1u}, i_7_5c_qlen_5b_3_3a_0_5d_);
	// cell $auto$opt_reduce.cc:131:opt_pmux$6955
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6924 = reduce_or<1>(i_procmux_24_3829__CMP.concat(i_procmux_24_3828__CMP).concat(i_procmux_24_3827__CMP).concat(i_procmux_24_3826__CMP).concat(i_procmux_24_3825__CMP).concat(i_procmux_24_3823__CMP).concat(i_procmux_24_3822__CMP).val());
	// cells $procmux$2500 $procmux$2497 $procmux$2495 $procmux$2151
	i_9_5c_qo_5b_2_5d__5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_201__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_205__Y ? i_6_5c_qo_5b_3_5d__5b_1_3a_0_5d_ : i_6_5c_qo_5b_2_5d__5b_1_3a_0_5d_) : i_6_5c_qo_5b_2_5d__5b_1_3a_0_5d_) : value<2>{0u}));
	// cells $procmux$3635 $procmux$3333 $procmux$2996
	i_6_5c_qo_5b_4_5d__5b_1_3a_0_5d_ = (i_6_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_168__Y ? i_3_5c_qo_5b_4_5d__5b_1_3a_0_5d_ : (i_procmux_24_2748__CMP ? i_6_5c_releaseowner_5b_1_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6946 ? i_3_5c_qo_5b_4_5d__5b_1_3a_0_5d_ : value<2>{0u}))) : i_3_5c_qo_5b_4_5d__5b_1_3a_0_5d_);
	// \full_case: 1
	// \src: receiver.v:116.37-116.37|receiver.v:116.6-116.104
	// cell $procmux$1076_CMP0
	i_procmux_24_1034__CMP = eq_uu<1>(i_9_5c_qo_5b_2_5d__5b_1_3a_0_5d_, value<1>{0x1u});
	// \full_case: 1
	// \src: receiver.v:116.57-116.57|receiver.v:116.6-116.104
	// cell $procmux$1075_CMP0
	i_procmux_24_1033__CMP = eq_uu<1>(i_9_5c_qo_5b_2_5d__5b_1_3a_0_5d_, value<2>{0x2u});
	// \full_case: 1
	// \src: receiver.v:116.77-116.77|receiver.v:116.6-116.104
	// cell $procmux$1074_CMP0
	i_procmux_24_1032__CMP = eq_uu<1>(i_9_5c_qo_5b_2_5d__5b_1_3a_0_5d_, value<2>{0x3u});
	// cells $procmux$1211 $procmux$1208 $procmux$1206 $procmux$1123 $add$receiver.v:116$271 $auto$opt_reduce.cc:131:opt_pmux$6967
	i_5_5c_tokens0_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_270__Y ? (i_procmux_24_1127__CMP ? add_uu<4>(i_3_5c_tokens0_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_1126__CMP.concat(i_procmux_24_1125__CMP).concat(i_procmux_24_1124__CMP).val()) ? i_3_5c_tokens0_5b_3_3a_0_5d_ : value<4>{0u})) : i_3_5c_tokens0_5b_3_3a_0_5d_) : value<4>{0u}));
	// \full_case: 1
	// \src: receiver.v:116.17-116.17|receiver.v:116.6-116.104
	// cell $procmux$1077_CMP0
	i_procmux_24_1035__CMP = logic_not<1>(i_9_5c_qo_5b_2_5d__5b_1_3a_0_5d_);
	// cells $procmux$1202 $procmux$1199 $procmux$1197 $procmux$1165 $add$receiver.v:116$272 $auto$opt_reduce.cc:131:opt_pmux$6959
	i_5_5c_tokens1_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_270__Y ? (i_procmux_24_1126__CMP ? add_uu<4>(i_3_5c_tokens1_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_1127__CMP.concat(i_procmux_24_1125__CMP).concat(i_procmux_24_1124__CMP).val()) ? i_3_5c_tokens1_5b_3_3a_0_5d_ : value<4>{0u})) : i_3_5c_tokens1_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$1193 $procmux$1190 $procmux$1188 $procmux$1151 $add$receiver.v:116$273 $auto$opt_reduce.cc:131:opt_pmux$6963
	i_5_5c_tokens2_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_270__Y ? (i_procmux_24_1125__CMP ? add_uu<4>(i_3_5c_tokens2_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_1127__CMP.concat(i_procmux_24_1126__CMP).concat(i_procmux_24_1124__CMP).val()) ? i_3_5c_tokens2_5b_3_3a_0_5d_ : value<4>{0u})) : i_3_5c_tokens2_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$1184 $procmux$1181 $procmux$1179 $procmux$1137 $add$receiver.v:116$274 $auto$opt_reduce.cc:131:opt_pmux$6965
	i_5_5c_tokens3_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_270__Y ? (reduce_or<1>(i_procmux_24_1127__CMP.concat(i_procmux_24_1126__CMP).concat(i_procmux_24_1125__CMP).val()) ? i_3_5c_tokens3_5b_3_3a_0_5d_ : (i_procmux_24_1124__CMP ? add_uu<4>(i_3_5c_tokens3_5b_3_3a_0_5d_, value<1>{0x1u}) : value<4>{0u})) : i_3_5c_tokens3_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$4703 $procmux$4398 $procmux$4052
	i_3_5c_qo_5b_5_5d__5b_1_3a_0_5d_ = (i_4_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_125__Y ? p_qo_5b_5_5d_.curr : (i_procmux_24_3824__CMP ? i_4_5c_releaseowner_5b_1_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6924 ? p_qo_5b_5_5d_.curr : value<2>{0u}))) : p_qo_5b_5_5d_.curr);
	// cell $auto$opt_reduce.cc:131:opt_pmux$7017
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6954 = reduce_or<1>(i_procmux_24_2752__CMP.concat(i_procmux_24_2751__CMP).concat(i_procmux_24_2750__CMP).concat(i_procmux_24_2749__CMP).concat(i_procmux_24_2748__CMP).concat(i_procmux_24_2746__CMP).concat(i_procmux_24_2745__CMP).val());
	// \src: receiver.v:115.8-115.14
	// cell $lt$receiver.v:115$275
	i_lt_24_receiver_2e_v_3a_115_24_275__Y = lt_uu<1>(value<2>{0x2u}, i_7_5c_qlen_5b_3_3a_0_5d_);
	// cell $auto$opt_reduce.cc:131:opt_pmux$6973
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6926 = reduce_or<1>(i_procmux_24_3829__CMP.concat(i_procmux_24_3828__CMP).concat(i_procmux_24_3827__CMP).concat(i_procmux_24_3826__CMP).concat(i_procmux_24_3825__CMP).concat(i_procmux_24_3824__CMP).concat(i_procmux_24_3822__CMP).val());
	// cells $procmux$2491 $procmux$2488 $procmux$2486 $procmux$2139
	i_9_5c_qo_5b_3_5d__5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_201__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_205__Y ? i_6_5c_qo_5b_4_5d__5b_1_3a_0_5d_ : i_6_5c_qo_5b_3_5d__5b_1_3a_0_5d_) : i_6_5c_qo_5b_3_5d__5b_1_3a_0_5d_) : value<2>{0u}));
	// cells $procmux$3626 $procmux$3321 $procmux$2975
	i_6_5c_qo_5b_5_5d__5b_1_3a_0_5d_ = (i_6_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_168__Y ? i_3_5c_qo_5b_5_5d__5b_1_3a_0_5d_ : (i_procmux_24_2747__CMP ? i_6_5c_releaseowner_5b_1_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6954 ? i_3_5c_qo_5b_5_5d__5b_1_3a_0_5d_ : value<2>{0u}))) : i_3_5c_qo_5b_5_5d__5b_1_3a_0_5d_);
	// \full_case: 1
	// \src: receiver.v:116.37-116.37|receiver.v:116.6-116.104
	// cell $procmux$984_CMP0
	i_procmux_24_942__CMP = eq_uu<1>(i_9_5c_qo_5b_3_5d__5b_1_3a_0_5d_, value<1>{0x1u});
	// \full_case: 1
	// \src: receiver.v:116.57-116.57|receiver.v:116.6-116.104
	// cell $procmux$983_CMP0
	i_procmux_24_941__CMP = eq_uu<1>(i_9_5c_qo_5b_3_5d__5b_1_3a_0_5d_, value<2>{0x2u});
	// \full_case: 1
	// \src: receiver.v:116.77-116.77|receiver.v:116.6-116.104
	// cell $procmux$982_CMP0
	i_procmux_24_940__CMP = eq_uu<1>(i_9_5c_qo_5b_3_5d__5b_1_3a_0_5d_, value<2>{0x3u});
	// cells $procmux$1119 $procmux$1116 $procmux$1114 $procmux$1031 $add$receiver.v:116$276 $auto$opt_reduce.cc:131:opt_pmux$6981
	i_7_5c_tokens0_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_275__Y ? (i_procmux_24_1035__CMP ? add_uu<4>(i_5_5c_tokens0_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_1034__CMP.concat(i_procmux_24_1033__CMP).concat(i_procmux_24_1032__CMP).val()) ? i_5_5c_tokens0_5b_3_3a_0_5d_ : value<4>{0u})) : i_5_5c_tokens0_5b_3_3a_0_5d_) : value<4>{0u}));
	// \full_case: 1
	// \src: receiver.v:116.17-116.17|receiver.v:116.6-116.104
	// cell $procmux$985_CMP0
	i_procmux_24_943__CMP = logic_not<1>(i_9_5c_qo_5b_3_5d__5b_1_3a_0_5d_);
	// cells $procmux$1110 $procmux$1107 $procmux$1105 $procmux$1073 $add$receiver.v:116$277 $auto$opt_reduce.cc:131:opt_pmux$6969
	i_7_5c_tokens1_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_275__Y ? (i_procmux_24_1034__CMP ? add_uu<4>(i_5_5c_tokens1_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_1035__CMP.concat(i_procmux_24_1033__CMP).concat(i_procmux_24_1032__CMP).val()) ? i_5_5c_tokens1_5b_3_3a_0_5d_ : value<4>{0u})) : i_5_5c_tokens1_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$1101 $procmux$1098 $procmux$1096 $procmux$1059 $add$receiver.v:116$278 $auto$opt_reduce.cc:131:opt_pmux$6975
	i_7_5c_tokens2_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_275__Y ? (i_procmux_24_1033__CMP ? add_uu<4>(i_5_5c_tokens2_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_1035__CMP.concat(i_procmux_24_1034__CMP).concat(i_procmux_24_1032__CMP).val()) ? i_5_5c_tokens2_5b_3_3a_0_5d_ : value<4>{0u})) : i_5_5c_tokens2_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$1092 $procmux$1089 $procmux$1087 $procmux$1045 $add$receiver.v:116$279 $auto$opt_reduce.cc:131:opt_pmux$6977
	i_7_5c_tokens3_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_275__Y ? (reduce_or<1>(i_procmux_24_1035__CMP.concat(i_procmux_24_1034__CMP).concat(i_procmux_24_1033__CMP).val()) ? i_5_5c_tokens3_5b_3_3a_0_5d_ : (i_procmux_24_1032__CMP ? add_uu<4>(i_5_5c_tokens3_5b_3_3a_0_5d_, value<1>{0x1u}) : value<4>{0u})) : i_5_5c_tokens3_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$4694 $procmux$4386 $procmux$4031
	i_3_5c_qo_5b_6_5d__5b_1_3a_0_5d_ = (i_4_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_125__Y ? p_qo_5b_6_5d_.curr : (i_procmux_24_3823__CMP ? i_4_5c_releaseowner_5b_1_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6926 ? p_qo_5b_6_5d_.curr : value<2>{0u}))) : p_qo_5b_6_5d_.curr);
	// cell $auto$opt_reduce.cc:131:opt_pmux$7023
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6962 = reduce_or<1>(i_procmux_24_2752__CMP.concat(i_procmux_24_2751__CMP).concat(i_procmux_24_2750__CMP).concat(i_procmux_24_2749__CMP).concat(i_procmux_24_2748__CMP).concat(i_procmux_24_2747__CMP).concat(i_procmux_24_2745__CMP).val());
	// \src: receiver.v:115.8-115.14
	// cell $lt$receiver.v:115$280
	i_lt_24_receiver_2e_v_3a_115_24_280__Y = lt_uu<1>(value<2>{0x3u}, i_7_5c_qlen_5b_3_3a_0_5d_);
	// cell $auto$opt_reduce.cc:131:opt_pmux$6991
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6928 = reduce_or<1>(i_procmux_24_3829__CMP.concat(i_procmux_24_3828__CMP).concat(i_procmux_24_3827__CMP).concat(i_procmux_24_3826__CMP).concat(i_procmux_24_3825__CMP).concat(i_procmux_24_3824__CMP).concat(i_procmux_24_3823__CMP).val());
	// cells $procmux$2482 $procmux$2479 $procmux$2477 $procmux$2127
	i_9_5c_qo_5b_4_5d__5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_201__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_205__Y ? i_6_5c_qo_5b_5_5d__5b_1_3a_0_5d_ : i_6_5c_qo_5b_4_5d__5b_1_3a_0_5d_) : i_6_5c_qo_5b_4_5d__5b_1_3a_0_5d_) : value<2>{0u}));
	// cells $procmux$3617 $procmux$3309 $procmux$2954
	i_6_5c_qo_5b_6_5d__5b_1_3a_0_5d_ = (i_6_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_168__Y ? i_3_5c_qo_5b_6_5d__5b_1_3a_0_5d_ : (i_procmux_24_2746__CMP ? i_6_5c_releaseowner_5b_1_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6962 ? i_3_5c_qo_5b_6_5d__5b_1_3a_0_5d_ : value<2>{0u}))) : i_3_5c_qo_5b_6_5d__5b_1_3a_0_5d_);
	// \full_case: 1
	// \src: receiver.v:116.37-116.37|receiver.v:116.6-116.104
	// cell $procmux$892_CMP0
	i_procmux_24_850__CMP = eq_uu<1>(i_9_5c_qo_5b_4_5d__5b_1_3a_0_5d_, value<1>{0x1u});
	// \full_case: 1
	// \src: receiver.v:116.57-116.57|receiver.v:116.6-116.104
	// cell $procmux$891_CMP0
	i_procmux_24_849__CMP = eq_uu<1>(i_9_5c_qo_5b_4_5d__5b_1_3a_0_5d_, value<2>{0x2u});
	// \full_case: 1
	// \src: receiver.v:116.77-116.77|receiver.v:116.6-116.104
	// cell $procmux$890_CMP0
	i_procmux_24_848__CMP = eq_uu<1>(i_9_5c_qo_5b_4_5d__5b_1_3a_0_5d_, value<2>{0x3u});
	// cells $procmux$1027 $procmux$1024 $procmux$1022 $procmux$939 $add$receiver.v:116$281 $auto$opt_reduce.cc:131:opt_pmux$6995
	i_9_5c_tokens0_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_280__Y ? (i_procmux_24_943__CMP ? add_uu<4>(i_7_5c_tokens0_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_942__CMP.concat(i_procmux_24_941__CMP).concat(i_procmux_24_940__CMP).val()) ? i_7_5c_tokens0_5b_3_3a_0_5d_ : value<4>{0u})) : i_7_5c_tokens0_5b_3_3a_0_5d_) : value<4>{0u}));
	// \full_case: 1
	// \src: receiver.v:116.17-116.17|receiver.v:116.6-116.104
	// cell $procmux$893_CMP0
	i_procmux_24_851__CMP = logic_not<1>(i_9_5c_qo_5b_4_5d__5b_1_3a_0_5d_);
	// cells $procmux$1018 $procmux$1015 $procmux$1013 $procmux$981 $add$receiver.v:116$282 $auto$opt_reduce.cc:131:opt_pmux$6983
	i_9_5c_tokens1_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_280__Y ? (i_procmux_24_942__CMP ? add_uu<4>(i_7_5c_tokens1_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_943__CMP.concat(i_procmux_24_941__CMP).concat(i_procmux_24_940__CMP).val()) ? i_7_5c_tokens1_5b_3_3a_0_5d_ : value<4>{0u})) : i_7_5c_tokens1_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$1009 $procmux$1006 $procmux$1004 $procmux$967 $add$receiver.v:116$283 $auto$opt_reduce.cc:131:opt_pmux$6987
	i_9_5c_tokens2_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_280__Y ? (i_procmux_24_941__CMP ? add_uu<4>(i_7_5c_tokens2_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_943__CMP.concat(i_procmux_24_942__CMP).concat(i_procmux_24_940__CMP).val()) ? i_7_5c_tokens2_5b_3_3a_0_5d_ : value<4>{0u})) : i_7_5c_tokens2_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$1000 $procmux$997 $procmux$995 $procmux$953 $add$receiver.v:116$284 $auto$opt_reduce.cc:131:opt_pmux$6989
	i_9_5c_tokens3_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_280__Y ? (reduce_or<1>(i_procmux_24_943__CMP.concat(i_procmux_24_942__CMP).concat(i_procmux_24_941__CMP).val()) ? i_7_5c_tokens3_5b_3_3a_0_5d_ : (i_procmux_24_940__CMP ? add_uu<4>(i_7_5c_tokens3_5b_3_3a_0_5d_, value<1>{0x1u}) : value<4>{0u})) : i_7_5c_tokens3_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$4685 $procmux$4374 $procmux$4010
	i_3_5c_qo_5b_7_5d__5b_1_3a_0_5d_ = (i_4_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_125__Y ? p_qo_5b_7_5d_.curr : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6928 ? p_qo_5b_7_5d_.curr : (i_procmux_24_3822__CMP ? i_4_5c_releaseowner_5b_1_3a_0_5d_ : value<2>{0u}))) : p_qo_5b_7_5d_.curr);
	// cell $auto$opt_reduce.cc:131:opt_pmux$7031
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6972 = reduce_or<1>(i_procmux_24_2752__CMP.concat(i_procmux_24_2751__CMP).concat(i_procmux_24_2750__CMP).concat(i_procmux_24_2749__CMP).concat(i_procmux_24_2748__CMP).concat(i_procmux_24_2747__CMP).concat(i_procmux_24_2746__CMP).val());
	// \src: receiver.v:115.8-115.14
	// cell $lt$receiver.v:115$285
	i_lt_24_receiver_2e_v_3a_115_24_285__Y = lt_uu<1>(value<3>{0x4u}, i_7_5c_qlen_5b_3_3a_0_5d_);
	// cells $procmux$2473 $procmux$2470 $procmux$2468 $procmux$2115
	i_9_5c_qo_5b_5_5d__5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_201__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_205__Y ? i_6_5c_qo_5b_6_5d__5b_1_3a_0_5d_ : i_6_5c_qo_5b_5_5d__5b_1_3a_0_5d_) : i_6_5c_qo_5b_5_5d__5b_1_3a_0_5d_) : value<2>{0u}));
	// cells $procmux$3608 $procmux$3297 $procmux$2933
	i_6_5c_qo_5b_7_5d__5b_1_3a_0_5d_ = (i_6_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_168__Y ? i_3_5c_qo_5b_7_5d__5b_1_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6972 ? i_3_5c_qo_5b_7_5d__5b_1_3a_0_5d_ : (i_procmux_24_2745__CMP ? i_6_5c_releaseowner_5b_1_3a_0_5d_ : value<2>{0u}))) : i_3_5c_qo_5b_7_5d__5b_1_3a_0_5d_);
	// \full_case: 1
	// \src: receiver.v:116.37-116.37|receiver.v:116.6-116.104
	// cell $procmux$800_CMP0
	i_procmux_24_758__CMP = eq_uu<1>(i_9_5c_qo_5b_5_5d__5b_1_3a_0_5d_, value<1>{0x1u});
	// \full_case: 1
	// \src: receiver.v:116.57-116.57|receiver.v:116.6-116.104
	// cell $procmux$799_CMP0
	i_procmux_24_757__CMP = eq_uu<1>(i_9_5c_qo_5b_5_5d__5b_1_3a_0_5d_, value<2>{0x2u});
	// \full_case: 1
	// \src: receiver.v:116.77-116.77|receiver.v:116.6-116.104
	// cell $procmux$798_CMP0
	i_procmux_24_756__CMP = eq_uu<1>(i_9_5c_qo_5b_5_5d__5b_1_3a_0_5d_, value<2>{0x3u});
	// cells $procmux$935 $procmux$932 $procmux$930 $procmux$847 $add$receiver.v:116$286 $auto$opt_reduce.cc:131:opt_pmux$7005
	i_11_5c_tokens0_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_285__Y ? (i_procmux_24_851__CMP ? add_uu<4>(i_9_5c_tokens0_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_850__CMP.concat(i_procmux_24_849__CMP).concat(i_procmux_24_848__CMP).val()) ? i_9_5c_tokens0_5b_3_3a_0_5d_ : value<4>{0u})) : i_9_5c_tokens0_5b_3_3a_0_5d_) : value<4>{0u}));
	// \full_case: 1
	// \src: receiver.v:116.17-116.17|receiver.v:116.6-116.104
	// cell $procmux$801_CMP0
	i_procmux_24_759__CMP = logic_not<1>(i_9_5c_qo_5b_5_5d__5b_1_3a_0_5d_);
	// cells $procmux$926 $procmux$923 $procmux$921 $procmux$889 $add$receiver.v:116$287 $auto$opt_reduce.cc:131:opt_pmux$6997
	i_11_5c_tokens1_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_285__Y ? (i_procmux_24_850__CMP ? add_uu<4>(i_9_5c_tokens1_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_851__CMP.concat(i_procmux_24_849__CMP).concat(i_procmux_24_848__CMP).val()) ? i_9_5c_tokens1_5b_3_3a_0_5d_ : value<4>{0u})) : i_9_5c_tokens1_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$917 $procmux$914 $procmux$912 $procmux$875 $add$receiver.v:116$288 $auto$opt_reduce.cc:131:opt_pmux$6999
	i_11_5c_tokens2_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_285__Y ? (i_procmux_24_849__CMP ? add_uu<4>(i_9_5c_tokens2_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_851__CMP.concat(i_procmux_24_850__CMP).concat(i_procmux_24_848__CMP).val()) ? i_9_5c_tokens2_5b_3_3a_0_5d_ : value<4>{0u})) : i_9_5c_tokens2_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$908 $procmux$905 $procmux$903 $procmux$861 $add$receiver.v:116$289 $auto$opt_reduce.cc:131:opt_pmux$7003
	i_11_5c_tokens3_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_285__Y ? (reduce_or<1>(i_procmux_24_851__CMP.concat(i_procmux_24_850__CMP).concat(i_procmux_24_849__CMP).val()) ? i_9_5c_tokens3_5b_3_3a_0_5d_ : (i_procmux_24_848__CMP ? add_uu<4>(i_9_5c_tokens3_5b_3_3a_0_5d_, value<1>{0x1u}) : value<4>{0u})) : i_9_5c_tokens3_5b_3_3a_0_5d_) : value<4>{0u}));
	// \src: receiver.v:83.7-83.70
	// cell $neg$receiver.v:83$151
	i_neg_24_receiver_2e_v_3a_83_24_143__Y = neg_u<33>(i_add_24_receiver_2e_v_3a_82_24_137__Y);
	// \src: receiver.v:83.7-83.70
	// cell $shift$receiver.v:83$144
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7136.slice<15,0>() = shift_us<16>(value<4>{0xfu}, i_neg_24_receiver_2e_v_3a_83_24_143__Y);
	// \src: receiver.v:115.8-115.14
	// cell $lt$receiver.v:115$290
	i_lt_24_receiver_2e_v_3a_115_24_290__Y = lt_uu<1>(value<3>{0x5u}, i_7_5c_qlen_5b_3_3a_0_5d_);
	// \src: receiver.v:83.7-83.70
	// cell $not$receiver.v:83$145
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7135.slice<15,0>() = not_u<16>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7136.slice<15,0>().val());
	// cells $shift$receiver.v:83$152 $add$receiver.v:83$150
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7132.slice<15,0>() = shift_us<16>(add_uu<4>(i_shiftx_24_receiver_2e_v_3a_82_24_138__Y, value<1>{0x1u}), i_neg_24_receiver_2e_v_3a_83_24_143__Y);
	// cells $procmux$2464 $procmux$2461 $procmux$2459 $procmux$2103
	i_9_5c_qo_5b_6_5d__5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_201__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_205__Y ? i_6_5c_qo_5b_7_5d__5b_1_3a_0_5d_ : i_6_5c_qo_5b_6_5d__5b_1_3a_0_5d_) : i_6_5c_qo_5b_6_5d__5b_1_3a_0_5d_) : value<2>{0u}));
	// cells $or$receiver.v:83$153 $and$receiver.v:83$146
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7131.slice<15,0>() = or_uu<16>(and_uu<16>(p_outstanding.curr, i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7135.slice<15,0>().val()), i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7132.slice<15,0>().val());
	// \full_case: 1
	// \src: receiver.v:116.37-116.37|receiver.v:116.6-116.104
	// cell $procmux$708_CMP0
	i_procmux_24_666__CMP = eq_uu<1>(i_9_5c_qo_5b_6_5d__5b_1_3a_0_5d_, value<1>{0x1u});
	// \full_case: 1
	// \src: receiver.v:116.57-116.57|receiver.v:116.6-116.104
	// cell $procmux$707_CMP0
	i_procmux_24_665__CMP = eq_uu<1>(i_9_5c_qo_5b_6_5d__5b_1_3a_0_5d_, value<2>{0x2u});
	// \full_case: 1
	// \src: receiver.v:116.77-116.77|receiver.v:116.6-116.104
	// cell $procmux$706_CMP0
	i_procmux_24_664__CMP = eq_uu<1>(i_9_5c_qo_5b_6_5d__5b_1_3a_0_5d_, value<2>{0x3u});
	// cells $procmux$843 $procmux$840 $procmux$838 $procmux$755 $add$receiver.v:116$291 $auto$opt_reduce.cc:131:opt_pmux$7019
	i_13_5c_tokens0_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_290__Y ? (i_procmux_24_759__CMP ? add_uu<4>(i_11_5c_tokens0_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_758__CMP.concat(i_procmux_24_757__CMP).concat(i_procmux_24_756__CMP).val()) ? i_11_5c_tokens0_5b_3_3a_0_5d_ : value<4>{0u})) : i_11_5c_tokens0_5b_3_3a_0_5d_) : value<4>{0u}));
	// \full_case: 1
	// \src: receiver.v:116.17-116.17|receiver.v:116.6-116.104
	// cell $procmux$709_CMP0
	i_procmux_24_667__CMP = logic_not<1>(i_9_5c_qo_5b_6_5d__5b_1_3a_0_5d_);
	// cells $procmux$834 $procmux$831 $procmux$829 $procmux$797 $add$receiver.v:116$292 $auto$opt_reduce.cc:131:opt_pmux$7009
	i_13_5c_tokens1_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_290__Y ? (i_procmux_24_758__CMP ? add_uu<4>(i_11_5c_tokens1_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_759__CMP.concat(i_procmux_24_757__CMP).concat(i_procmux_24_756__CMP).val()) ? i_11_5c_tokens1_5b_3_3a_0_5d_ : value<4>{0u})) : i_11_5c_tokens1_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$825 $procmux$822 $procmux$820 $procmux$783 $add$receiver.v:116$293 $auto$opt_reduce.cc:131:opt_pmux$7013
	i_13_5c_tokens2_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_290__Y ? (i_procmux_24_757__CMP ? add_uu<4>(i_11_5c_tokens2_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_759__CMP.concat(i_procmux_24_758__CMP).concat(i_procmux_24_756__CMP).val()) ? i_11_5c_tokens2_5b_3_3a_0_5d_ : value<4>{0u})) : i_11_5c_tokens2_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$816 $procmux$813 $procmux$811 $procmux$769 $add$receiver.v:116$294 $auto$opt_reduce.cc:131:opt_pmux$7015
	i_13_5c_tokens3_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_290__Y ? (reduce_or<1>(i_procmux_24_759__CMP.concat(i_procmux_24_758__CMP).concat(i_procmux_24_757__CMP).val()) ? i_11_5c_tokens3_5b_3_3a_0_5d_ : (i_procmux_24_756__CMP ? add_uu<4>(i_11_5c_tokens3_5b_3_3a_0_5d_, value<1>{0x1u}) : value<4>{0u})) : i_11_5c_tokens3_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $logic_or$receiver.v:100$242 $eq$receiver.v:100$240 $eq$receiver.v:100$241
	i_logic__or_24_receiver_2e_v_3a_100_24_242__Y = logic_or<1>(eq_uu<1>(p_rp.curr, value<1>{0x1u}), eq_uu<1>(p_rp.curr, value<2>{0x2u}));
	// \src: receiver.v:83.50-83.64
	// cell $mul$receiver.v:83$190
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7127.slice<4,0>() = mul_uu<5>(value<3>{0x4u}, i_6_5c_releaseowner_5b_1_3a_0_5d_);
	// connection
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7127.slice<31,5>() = value<27>{0u};
	// \src: receiver.v:115.8-115.14
	// cell $lt$receiver.v:115$295
	i_lt_24_receiver_2e_v_3a_115_24_295__Y = lt_uu<1>(value<3>{0x6u}, i_7_5c_qlen_5b_3_3a_0_5d_);
	// \src: receiver.v:83.49-83.68
	// cell $add$receiver.v:83$191
	i_add_24_receiver_2e_v_3a_82_24_180__Y = add_uu<6>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7127.slice<4,0>().val(), value<1>{0u});
	// cells $procmux$2635 $procmux$2632 $procmux$2630 $procmux$1983
	i_3_5c_failed_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_201__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_205__Y ? p_failed.curr : value<1>{0x1u}) : p_failed.curr) : value<1>{0u}));
	// cells $procmux$1737 $procmux$1639
	i_4_5c_evblock_5b_0_3a_0_5d_ = (p_rone.curr ? (i_logic__or_24_receiver_2e_v_3a_100_24_242__Y ? value<1>{0u} : value<1>{0x1u}) : value<1>{0u});
	// cells $procmux$4825 $procmux$4822 $procmux$4820 $procmux$4542
	i_3_5c_outstanding_5b_15_3a_0_5d_ = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_4_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_125__Y ? p_outstanding.curr : i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7131.slice<15,0>().val()) : p_outstanding.curr) : value<16>{0u}));
	// \src: receiver.v:83.7-83.70
	// cell $neg$receiver.v:83$194
	i_neg_24_receiver_2e_v_3a_83_24_186__Y = neg_u<33>(i_add_24_receiver_2e_v_3a_82_24_180__Y);
	// cells $procmux$2455 $procmux$2452 $procmux$2450 $procmux$2091
	i_9_5c_qo_5b_7_5d__5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_201__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_205__Y ? value<2>{0u} : i_6_5c_qo_5b_7_5d__5b_1_3a_0_5d_) : i_6_5c_qo_5b_7_5d__5b_1_3a_0_5d_) : value<2>{0u}));
	// \src: receiver.v:83.49-83.68
	// cell $shiftx$receiver.v:83$192
	i_shiftx_24_receiver_2e_v_3a_82_24_181__Y = shiftx_us<4>(i_3_5c_outstanding_5b_15_3a_0_5d_, value<1>{0u}.concat(i_add_24_receiver_2e_v_3a_82_24_180__Y).val());
	// \src: receiver.v:83.7-83.70
	// cell $shift$receiver.v:83$187
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7125.slice<15,0>() = shift_us<16>(value<4>{0xfu}, i_neg_24_receiver_2e_v_3a_83_24_186__Y);
	// \full_case: 1
	// \src: receiver.v:116.37-116.37|receiver.v:116.6-116.104
	// cell $procmux$616_CMP0
	i_procmux_24_574__CMP = eq_uu<1>(i_9_5c_qo_5b_7_5d__5b_1_3a_0_5d_, value<1>{0x1u});
	// \full_case: 1
	// \src: receiver.v:116.57-116.57|receiver.v:116.6-116.104
	// cell $procmux$615_CMP0
	i_procmux_24_573__CMP = eq_uu<1>(i_9_5c_qo_5b_7_5d__5b_1_3a_0_5d_, value<2>{0x2u});
	// \full_case: 1
	// \src: receiver.v:116.77-116.77|receiver.v:116.6-116.104
	// cell $procmux$614_CMP0
	i_procmux_24_572__CMP = eq_uu<1>(i_9_5c_qo_5b_7_5d__5b_1_3a_0_5d_, value<2>{0x3u});
	// cells $procmux$751 $procmux$748 $procmux$746 $procmux$663 $add$receiver.v:116$296 $auto$opt_reduce.cc:131:opt_pmux$7029
	i_15_5c_tokens0_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_295__Y ? (i_procmux_24_667__CMP ? add_uu<4>(i_13_5c_tokens0_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_666__CMP.concat(i_procmux_24_665__CMP).concat(i_procmux_24_664__CMP).val()) ? i_13_5c_tokens0_5b_3_3a_0_5d_ : value<4>{0u})) : i_13_5c_tokens0_5b_3_3a_0_5d_) : value<4>{0u}));
	// \full_case: 1
	// \src: receiver.v:116.17-116.17|receiver.v:116.6-116.104
	// cell $procmux$617_CMP0
	i_procmux_24_575__CMP = logic_not<1>(i_9_5c_qo_5b_7_5d__5b_1_3a_0_5d_);
	// cells $procmux$742 $procmux$739 $procmux$737 $procmux$705 $add$receiver.v:116$297 $auto$opt_reduce.cc:131:opt_pmux$7021
	i_15_5c_tokens1_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_295__Y ? (i_procmux_24_666__CMP ? add_uu<4>(i_13_5c_tokens1_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_667__CMP.concat(i_procmux_24_665__CMP).concat(i_procmux_24_664__CMP).val()) ? i_13_5c_tokens1_5b_3_3a_0_5d_ : value<4>{0u})) : i_13_5c_tokens1_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$733 $procmux$730 $procmux$728 $procmux$691 $add$receiver.v:116$298 $auto$opt_reduce.cc:131:opt_pmux$7025
	i_15_5c_tokens2_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_295__Y ? (i_procmux_24_665__CMP ? add_uu<4>(i_13_5c_tokens2_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_667__CMP.concat(i_procmux_24_666__CMP).concat(i_procmux_24_664__CMP).val()) ? i_13_5c_tokens2_5b_3_3a_0_5d_ : value<4>{0u})) : i_13_5c_tokens2_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$724 $procmux$721 $procmux$719 $procmux$677 $add$receiver.v:116$299 $auto$opt_reduce.cc:131:opt_pmux$7027
	i_15_5c_tokens3_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_295__Y ? (reduce_or<1>(i_procmux_24_667__CMP.concat(i_procmux_24_666__CMP).concat(i_procmux_24_665__CMP).val()) ? i_13_5c_tokens3_5b_3_3a_0_5d_ : (i_procmux_24_664__CMP ? add_uu<4>(i_13_5c_tokens3_5b_3_3a_0_5d_, value<1>{0x1u}) : value<4>{0u})) : i_13_5c_tokens3_5b_3_3a_0_5d_) : value<4>{0u}));
	// \src: receiver.v:83.7-83.70
	// cell $not$receiver.v:83$188
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7124.slice<15,0>() = not_u<16>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7125.slice<15,0>().val());
	// cells $procmux$1744 $procmux$1741 $procmux$1739
	i_4_5c_rone_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? value<1>{0u} : i_4_5c_evblock_5b_0_3a_0_5d_) : value<1>{0u}));
	// cells $shift$receiver.v:83$195 $add$receiver.v:83$193
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7121.slice<15,0>() = shift_us<16>(add_uu<4>(i_shiftx_24_receiver_2e_v_3a_82_24_181__Y, value<1>{0x1u}), i_neg_24_receiver_2e_v_3a_83_24_186__Y);
	// \src: receiver.v:115.8-115.14
	// cell $lt$receiver.v:115$300
	i_lt_24_receiver_2e_v_3a_115_24_300__Y = lt_uu<1>(value<3>{0x7u}, i_7_5c_qlen_5b_3_3a_0_5d_);
	// cells $procmux$2671 $procmux$2668 $procmux$2666 $procmux$2331
	i_3_5c_rzero_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_201__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_205__Y ? value<1>{0x1u} : p_rzero.curr) : p_rzero.curr) : value<1>{0u}));
	// cells $or$receiver.v:83$196 $and$receiver.v:83$189
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7120.slice<15,0>() = or_uu<16>(and_uu<16>(i_3_5c_outstanding_5b_15_3a_0_5d_, i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7124.slice<15,0>().val()), i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7121.slice<15,0>().val());
	// cells $logic_and$receiver.v:103$244 $logic_not$receiver.v:103$243
	i_logic__and_24_receiver_2e_v_3a_103_24_244__Y = logic_and<1>(i_3_5c_rzero_5b_0_3a_0_5d_, logic_not<1>(i_4_5c_rone_5b_0_3a_0_5d_));
	// cells $procmux$1708 $procmux$1705 $procmux$1703 $procmux$1701 $procmux$1579
	i_4_5c_emitowner_5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? value<2>{0u} : (p_rone.curr ? (i_logic__or_24_receiver_2e_v_3a_100_24_242__Y ? p_ownerone.curr : p_emitowner.curr) : p_emitowner.curr)) : value<2>{0u}));
	// cells $procmux$2662 $procmux$2659 $procmux$2657 $procmux$2319
	i_3_5c_ownerzero_5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_201__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_205__Y ? i_6_5c_qo_5b_0_5d__5b_1_3a_0_5d_ : p_ownerzero.curr) : p_ownerzero.curr) : value<2>{0u}));
	// \src: receiver.v:110.51-110.62
	// cell $mul$receiver.v:110$258
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7109.slice<4,0>() = mul_uu<5>(value<3>{0x4u}, i_4_5c_emitowner_5b_1_3a_0_5d_);
	// connection
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7109.slice<31,5>() = value<27>{0u};
	// \full_case: 1
	// \src: receiver.v:119.48-119.48|receiver.v:119.13-119.115
	// cell $procmux$524_CMP0
	i_procmux_24_482__CMP = eq_uu<1>(i_3_5c_ownerzero_5b_1_3a_0_5d_, value<1>{0x1u});
	// \full_case: 1
	// \src: receiver.v:119.68-119.68|receiver.v:119.13-119.115
	// cell $procmux$523_CMP0
	i_procmux_24_481__CMP = eq_uu<1>(i_3_5c_ownerzero_5b_1_3a_0_5d_, value<2>{0x2u});
	// \full_case: 1
	// \src: receiver.v:119.88-119.88|receiver.v:119.13-119.115
	// cell $procmux$522_CMP0
	i_procmux_24_480__CMP = eq_uu<1>(i_3_5c_ownerzero_5b_1_3a_0_5d_, value<2>{0x3u});
	// cells $procmux$659 $procmux$656 $procmux$654 $procmux$571 $add$receiver.v:116$301 $auto$opt_reduce.cc:131:opt_pmux$7041
	i_17_5c_tokens0_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_300__Y ? (i_procmux_24_575__CMP ? add_uu<4>(i_15_5c_tokens0_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_574__CMP.concat(i_procmux_24_573__CMP).concat(i_procmux_24_572__CMP).val()) ? i_15_5c_tokens0_5b_3_3a_0_5d_ : value<4>{0u})) : i_15_5c_tokens0_5b_3_3a_0_5d_) : value<4>{0u}));
	// \full_case: 1
	// \src: receiver.v:119.28-119.28|receiver.v:119.13-119.115
	// cell $procmux$525_CMP0
	i_procmux_24_483__CMP = logic_not<1>(i_3_5c_ownerzero_5b_1_3a_0_5d_);
	// cells $procmux$650 $procmux$647 $procmux$645 $procmux$613 $add$receiver.v:116$302 $auto$opt_reduce.cc:131:opt_pmux$7033
	i_17_5c_tokens1_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_300__Y ? (i_procmux_24_574__CMP ? add_uu<4>(i_15_5c_tokens1_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_575__CMP.concat(i_procmux_24_573__CMP).concat(i_procmux_24_572__CMP).val()) ? i_15_5c_tokens1_5b_3_3a_0_5d_ : value<4>{0u})) : i_15_5c_tokens1_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$641 $procmux$638 $procmux$636 $procmux$599 $add$receiver.v:116$303 $auto$opt_reduce.cc:131:opt_pmux$7035
	i_17_5c_tokens2_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_300__Y ? (i_procmux_24_573__CMP ? add_uu<4>(i_15_5c_tokens2_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_575__CMP.concat(i_procmux_24_574__CMP).concat(i_procmux_24_572__CMP).val()) ? i_15_5c_tokens2_5b_3_3a_0_5d_ : value<4>{0u})) : i_15_5c_tokens2_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$632 $procmux$629 $procmux$627 $procmux$585 $add$receiver.v:116$304 $auto$opt_reduce.cc:131:opt_pmux$7037
	i_17_5c_tokens3_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_300__Y ? (reduce_or<1>(i_procmux_24_575__CMP.concat(i_procmux_24_574__CMP).concat(i_procmux_24_573__CMP).val()) ? i_15_5c_tokens3_5b_3_3a_0_5d_ : (i_procmux_24_572__CMP ? add_uu<4>(i_15_5c_tokens3_5b_3_3a_0_5d_, value<1>{0x1u}) : value<4>{0u})) : i_15_5c_tokens3_5b_3_3a_0_5d_) : value<4>{0u}));
	// \src: receiver.v:110.50-110.66
	// cell $add$receiver.v:110$259
	i_add_24_receiver_2e_v_3a_109_24_247__Y = add_uu<6>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7109.slice<4,0>().val(), value<1>{0u});
	// cells $procmux$3748 $procmux$3745 $procmux$3743 $procmux$3465
	i_5_5c_outstanding_5b_15_3a_0_5d_ = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_6_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_168__Y ? i_3_5c_outstanding_5b_15_3a_0_5d_ : i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7120.slice<15,0>().val()) : i_3_5c_outstanding_5b_15_3a_0_5d_) : value<16>{0u}));
	// \src: receiver.v:110.11-110.68
	// cell $neg$receiver.v:110$262
	i_neg_24_receiver_2e_v_3a_110_24_254__Y = neg_u<33>(i_add_24_receiver_2e_v_3a_109_24_247__Y);
	// cells $procmux$1879 $procmux$1876 $procmux$1874 $procmux$1425
	i_5_5c_rzero_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? i_3_5c_rzero_5b_0_3a_0_5d_ : (i_logic__and_24_receiver_2e_v_3a_103_24_244__Y ? value<1>{0u} : i_3_5c_rzero_5b_0_3a_0_5d_)) : value<1>{0u}));
	// \src: receiver.v:110.50-110.66
	// cell $shiftx$receiver.v:110$260
	i_shiftx_24_receiver_2e_v_3a_109_24_248__Y = shiftx_us<4>(i_5_5c_outstanding_5b_15_3a_0_5d_, value<1>{0u}.concat(i_add_24_receiver_2e_v_3a_109_24_247__Y).val());
	// \src: receiver.v:110.11-110.68
	// cell $shift$receiver.v:110$255
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7107.slice<15,0>() = shift_us<16>(value<4>{0xfu}, i_neg_24_receiver_2e_v_3a_110_24_254__Y);
	// \src: receiver.v:110.39-110.68
	// cell $sub$receiver.v:110$261
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7103.slice<3,0>() = sub_uu<4>(i_shiftx_24_receiver_2e_v_3a_109_24_248__Y, value<1>{0x1u});
	// \src: receiver.v:110.11-110.68
	// cell $not$receiver.v:110$256
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7106.slice<15,0>() = not_u<16>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7107.slice<15,0>().val());
	// \full_case: 1
	// \src: receiver.v:75.8-75.20|receiver.v:75.5-85.8
	// cell $procmux$4811
	i_procmux_24_4811__Y.slice<3,0>() = (i_4_5c_releasevalid_5b_0_3a_0_5d_ ? i_14_5c_fault_5b_31_3a_0_5d_.curr.slice<3,0>().val() : i_4_5c_fault_5b_31_3a_0_5d_.slice<3,0>().val());
	// connection
	i_procmux_24_4811__Y.slice<31,4>() = i_14_5c_fault_5b_31_3a_0_5d_.curr.slice<31,4>().val();
	// cells $procmux$1861 $procmux$1858 $procmux$1856 $procmux$1461
	i_3_5c_ownerone_5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? p_ownerone.curr : (i_logic__and_24_receiver_2e_v_3a_103_24_244__Y ? i_3_5c_ownerzero_5b_1_3a_0_5d_ : p_ownerone.curr)) : value<2>{0u}));
	// \src: receiver.v:110.11-110.68
	// cell $shift$receiver.v:110$263
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7102.slice<15,0>() = shift_us<16>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7103.slice<3,0>().val(), i_neg_24_receiver_2e_v_3a_110_24_254__Y);
	// \full_case: 1
	// \src: receiver.v:120.46-120.46|receiver.v:120.12-120.113
	// cell $procmux$432_CMP0
	i_procmux_24_390__CMP = eq_uu<1>(i_3_5c_ownerone_5b_1_3a_0_5d_, value<1>{0x1u});
	// \full_case: 1
	// \src: receiver.v:120.66-120.66|receiver.v:120.12-120.113
	// cell $procmux$431_CMP0
	i_procmux_24_389__CMP = eq_uu<1>(i_3_5c_ownerone_5b_1_3a_0_5d_, value<2>{0x2u});
	// \full_case: 1
	// \src: receiver.v:120.86-120.86|receiver.v:120.12-120.113
	// cell $procmux$430_CMP0
	i_procmux_24_388__CMP = eq_uu<1>(i_3_5c_ownerone_5b_1_3a_0_5d_, value<2>{0x3u});
	// cells $procmux$567 $procmux$564 $procmux$562 $procmux$479 $add$receiver.v:119$305 $auto$opt_reduce.cc:131:opt_pmux$7049
	i_19_5c_tokens0_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_5_5c_rzero_5b_0_3a_0_5d_ ? (i_procmux_24_483__CMP ? add_uu<4>(i_17_5c_tokens0_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_482__CMP.concat(i_procmux_24_481__CMP).concat(i_procmux_24_480__CMP).val()) ? i_17_5c_tokens0_5b_3_3a_0_5d_ : value<4>{0u})) : i_17_5c_tokens0_5b_3_3a_0_5d_) : value<4>{0u}));
	// \full_case: 1
	// \src: receiver.v:120.26-120.26|receiver.v:120.12-120.113
	// cell $procmux$433_CMP0
	i_procmux_24_391__CMP = logic_not<1>(i_3_5c_ownerone_5b_1_3a_0_5d_);
	// cells $procmux$558 $procmux$555 $procmux$553 $procmux$521 $add$receiver.v:119$306 $auto$opt_reduce.cc:131:opt_pmux$7043
	i_19_5c_tokens1_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_5_5c_rzero_5b_0_3a_0_5d_ ? (i_procmux_24_482__CMP ? add_uu<4>(i_17_5c_tokens1_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_483__CMP.concat(i_procmux_24_481__CMP).concat(i_procmux_24_480__CMP).val()) ? i_17_5c_tokens1_5b_3_3a_0_5d_ : value<4>{0u})) : i_17_5c_tokens1_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$549 $procmux$546 $procmux$544 $procmux$507 $add$receiver.v:119$307 $auto$opt_reduce.cc:131:opt_pmux$7045
	i_19_5c_tokens2_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_5_5c_rzero_5b_0_3a_0_5d_ ? (i_procmux_24_481__CMP ? add_uu<4>(i_17_5c_tokens2_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_483__CMP.concat(i_procmux_24_482__CMP).concat(i_procmux_24_480__CMP).val()) ? i_17_5c_tokens2_5b_3_3a_0_5d_ : value<4>{0u})) : i_17_5c_tokens2_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$540 $procmux$537 $procmux$535 $procmux$493 $add$receiver.v:119$308 $auto$opt_reduce.cc:131:opt_pmux$7047
	i_19_5c_tokens3_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_5_5c_rzero_5b_0_3a_0_5d_ ? (reduce_or<1>(i_procmux_24_483__CMP.concat(i_procmux_24_482__CMP).concat(i_procmux_24_481__CMP).val()) ? i_17_5c_tokens3_5b_3_3a_0_5d_ : (i_procmux_24_480__CMP ? add_uu<4>(i_17_5c_tokens3_5b_3_3a_0_5d_, value<1>{0x1u}) : value<4>{0u})) : i_17_5c_tokens3_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $or$receiver.v:110$264 $and$receiver.v:110$257
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7101.slice<15,0>() = or_uu<16>(and_uu<16>(i_5_5c_outstanding_5b_15_3a_0_5d_, i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7106.slice<15,0>().val()), i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7102.slice<15,0>().val());
	// \src: receiver.v:109.9-109.39
	// cell $eq$receiver.v:109$249
	i_eq_24_receiver_2e_v_3a_109_24_249__Y = logic_not<1>(i_shiftx_24_receiver_2e_v_3a_109_24_248__Y);
	// cells $procmux$4816 $procmux$4813
	i_13_5c_fault_5b_31_3a_0_5d_ = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_14_5c_fault_5b_31_3a_0_5d_.curr.slice<31,4>().concat(i_procmux_24_4811__Y.slice<3,0>()).val() : value<32>{0u}));
	// cells $procmux$1732 $procmux$1729 $procmux$1727 $procmux$1725 $procmux$1594
	i_4_5c_evemit_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? value<1>{0u} : (p_rone.curr ? (i_logic__or_24_receiver_2e_v_3a_100_24_242__Y ? value<1>{0x1u} : value<1>{0u}) : value<1>{0u})) : value<1>{0u}));
	// cells $procmux$4843 $procmux$4840 $procmux$4838 $procmux$4566 $add$receiver.v:81$135
	i_3_5c_nextid_5b_31_3a_0_5d_ = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_4_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_125__Y ? p_nextid.curr : add_uu<32>(p_nextid.curr, value<1>{0x1u})) : p_nextid.curr) : value<32>{0u}));
	// \src: receiver.v:93.61-93.69
	// cell $mul$receiver.v:93$228
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7112.slice<6,0>() = mul_uu<7>(value<5>{0x10u}, i_6_5c_qo_5b_0_5d__5b_1_3a_0_5d_);
	// connection
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7112.slice<31,7>() = value<25>{0u};
	// cells $procmux$4676 $procmux$4362 $procmux$3821
	i_3_5c_qi_5b_0_5d__5b_31_3a_0_5d_ = (i_4_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_125__Y ? p_qi_5b_0_5d_.curr : (i_procmux_24_3829__CMP ? p_nextid.curr : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6930 ? p_qi_5b_0_5d_.curr : value<32>{0u}))) : p_qi_5b_0_5d_.curr);
	// cells $procmux$2730 $eq$receiver.v:82$182
	i_18_5c_fault_5b_31_3a_0_5d_.slice<3,0>() = (eq_uu<1>(i_shiftx_24_receiver_2e_v_3a_82_24_181__Y, value<4>{0xfu}) ? value<1>{0x1u}.concat(i_13_5c_fault_5b_31_3a_0_5d_.slice<2,0>()).val() : i_13_5c_fault_5b_31_3a_0_5d_.slice<3,0>().val());
	// connection
	i_18_5c_fault_5b_31_3a_0_5d_.slice<31,4>() = i_13_5c_fault_5b_31_3a_0_5d_.slice<31,4>().val();
	// cells $procmux$1870 $procmux$1867 $procmux$1865 $procmux$1473
	i_3_5c_rone_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? p_rone.curr : (i_logic__and_24_receiver_2e_v_3a_103_24_244__Y ? value<1>{0x1u} : i_4_5c_rone_5b_0_3a_0_5d_)) : value<1>{0u}));
	// \src: receiver.v:91.63-91.70
	// cell $mul$receiver.v:91$210
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7119.slice<5,0>() = mul_uu<6>(value<4>{0x8u}, i_6_5c_qo_5b_0_5d__5b_1_3a_0_5d_);
	// connection
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7119.slice<31,6>() = value<26>{0u};
	// cells $procmux$4802 $procmux$4530
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7104.slice<0>() = (i_4_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_125__Y ? value<1>{0u} : value<1>{0x1u}) : value<1>{0u});
	// connection
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7104.slice<1>() = value<1>{0u};
	// \full_case: 1
	// \src: receiver.v:76.9-76.16|receiver.v:76.6-84.9
	// cell $procmux$3141
	i_17_5c_fault_5b_31_3a_0_5d_.slice<3,0>() = (i_ge_24_receiver_2e_v_3a_76_24_168__Y ? i_13_5c_fault_5b_31_3a_0_5d_.slice<3>().concat(value<1>{0x1u}).concat(i_13_5c_fault_5b_31_3a_0_5d_.slice<1,0>()).val() : i_18_5c_fault_5b_31_3a_0_5d_.slice<3,0>().val());
	// connection
	i_17_5c_fault_5b_31_3a_0_5d_.slice<31,4>() = i_13_5c_fault_5b_31_3a_0_5d_.slice<31,4>().val();
	// cells $neg$receiver.v:93$234 $add$receiver.v:93$229
	i_neg_24_receiver_2e_v_3a_93_24_230__Y = neg_u<33>(add_uu<8>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7112.slice<6,0>().val(), value<1>{0u}));
	// \src: receiver.v:93.37-93.53
	// cell $neg$receiver.v:93$225
	i_neg_24_receiver_2e_v_3a_93_24_218__Y = neg_u<3>(i_6_5c_qo_5b_0_5d__5b_1_3a_0_5d_);
	// cells $procmux$4613 $procmux$4278 $procmux$3842
	i_3_5c_qi_5b_7_5d__5b_31_3a_0_5d_ = (i_4_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_125__Y ? p_qi_5b_7_5d_.curr : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6928 ? p_qi_5b_7_5d_.curr : (i_procmux_24_3822__CMP ? p_nextid.curr : value<32>{0u}))) : p_qi_5b_7_5d_.curr);
	// cells $procmux$4622 $procmux$4290 $procmux$3863
	i_3_5c_qi_5b_6_5d__5b_31_3a_0_5d_ = (i_4_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_125__Y ? p_qi_5b_6_5d_.curr : (i_procmux_24_3823__CMP ? p_nextid.curr : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6926 ? p_qi_5b_6_5d_.curr : value<32>{0u}))) : p_qi_5b_6_5d_.curr);
	// cells $procmux$4631 $procmux$4302 $procmux$3884
	i_3_5c_qi_5b_5_5d__5b_31_3a_0_5d_ = (i_4_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_125__Y ? p_qi_5b_5_5d_.curr : (i_procmux_24_3824__CMP ? p_nextid.curr : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6924 ? p_qi_5b_5_5d_.curr : value<32>{0u}))) : p_qi_5b_5_5d_.curr);
	// cells $procmux$4640 $procmux$4314 $procmux$3905
	i_3_5c_qi_5b_4_5d__5b_31_3a_0_5d_ = (i_4_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_125__Y ? p_qi_5b_4_5d_.curr : (i_procmux_24_3825__CMP ? p_nextid.curr : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6922 ? p_qi_5b_4_5d_.curr : value<32>{0u}))) : p_qi_5b_4_5d_.curr);
	// cells $procmux$4649 $procmux$4326 $procmux$3926
	i_3_5c_qi_5b_3_5d__5b_31_3a_0_5d_ = (i_4_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_125__Y ? p_qi_5b_3_5d_.curr : (i_procmux_24_3826__CMP ? p_nextid.curr : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6920 ? p_qi_5b_3_5d_.curr : value<32>{0u}))) : p_qi_5b_3_5d_.curr);
	// cells $procmux$4658 $procmux$4338 $procmux$3947
	i_3_5c_qi_5b_2_5d__5b_31_3a_0_5d_ = (i_4_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_125__Y ? p_qi_5b_2_5d_.curr : (i_procmux_24_3827__CMP ? p_nextid.curr : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6918 ? p_qi_5b_2_5d_.curr : value<32>{0u}))) : p_qi_5b_2_5d_.curr);
	// cells $procmux$4667 $procmux$4350 $procmux$3968
	i_3_5c_qi_5b_1_5d__5b_31_3a_0_5d_ = (i_4_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_125__Y ? p_qi_5b_1_5d_.curr : (i_procmux_24_3828__CMP ? p_nextid.curr : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6932 ? p_qi_5b_1_5d_.curr : value<32>{0u}))) : p_qi_5b_1_5d_.curr);
	// cells $procmux$5940 $procmux$5937 $procmux$5935
	i_3_5c_bytes_5b_7_3a_0_5d_ = (p_rst ? value<8>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_59_24_90__Y ? p_wubytes.slice<7,0>().val() : p_bytes.curr.slice<7,0>().val()) : value<8>{0u}));
	// cells $procmux$5904 $procmux$5901 $procmux$5899
	i_4_5c_bytes_5b_15_3a_8_5d_ = (p_rst ? value<8>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_59_24_91__Y ? p_wubytes.slice<15,8>().val() : p_bytes.curr.slice<15,8>().val()) : value<8>{0u}));
	// cells $procmux$5868 $procmux$5865 $procmux$5863
	i_5_5c_bytes_5b_23_3a_16_5d_ = (p_rst ? value<8>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_59_24_92__Y ? p_wubytes.slice<23,16>().val() : p_bytes.curr.slice<23,16>().val()) : value<8>{0u}));
	// cells $procmux$5832 $procmux$5829 $procmux$5827
	i_6_5c_bytes_5b_31_3a_24_5d_ = (p_rst ? value<8>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_59_24_93__Y ? p_wubytes.slice<31,24>().val() : p_bytes.curr.slice<31,24>().val()) : value<8>{0u}));
	// \full_case: 1
	// \src: receiver.v:75.8-75.20|receiver.v:75.5-85.8
	// cell $procmux$3734
	i_16_5c_fault_5b_31_3a_0_5d_.slice<3,0>() = (i_6_5c_releasevalid_5b_0_3a_0_5d_ ? i_17_5c_fault_5b_31_3a_0_5d_.slice<3,0>().val() : i_13_5c_fault_5b_31_3a_0_5d_.slice<3,0>().val());
	// connection
	i_16_5c_fault_5b_31_3a_0_5d_.slice<31,4>() = i_13_5c_fault_5b_31_3a_0_5d_.slice<31,4>().val();
	// \src: receiver.v:93.37-93.53
	// cell $shift$receiver.v:93$222
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7117.slice<3,0>() = shift_us<4>(value<1>{0x1u}, i_neg_24_receiver_2e_v_3a_93_24_218__Y);
	// cells $shiftx$receiver.v:91$212 $add$receiver.v:91$211
	i_shiftx_24_receiver_2e_v_3a_91_24_212__Y = shiftx_us<8>(i_6_5c_bytes_5b_31_3a_24_5d_.concat(i_5_5c_bytes_5b_23_3a_16_5d_).concat(i_4_5c_bytes_5b_15_3a_8_5d_).concat(i_3_5c_bytes_5b_7_3a_0_5d_).val(), value<1>{0u}.concat(add_uu<7>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7119.slice<5,0>().val(), value<1>{0u})).val());
	// cells $procmux$4807 $procmux$4804
	i_3_5c_evenq_5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? value<1>{0u}.concat(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7104.slice<0>()).val() : value<2>{0u}));
	// cells $procmux$3599 $procmux$3285 $procmux$2744
	i_6_5c_qi_5b_0_5d__5b_31_3a_0_5d_ = (i_6_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_168__Y ? i_3_5c_qi_5b_0_5d__5b_31_3a_0_5d_ : (i_procmux_24_2752__CMP ? i_3_5c_nextid_5b_31_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6980 ? i_3_5c_qi_5b_0_5d__5b_31_3a_0_5d_ : value<32>{0u}))) : i_3_5c_qi_5b_0_5d__5b_31_3a_0_5d_);
	// cells $procmux$5769 $procmux$5766 $procmux$5764 $procmux$5040 $procmux$4975 $procmux$4894
	i_7_5c_enabled_5b_3_3a_0_5d_.slice<3>() = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_eq_24_receiver_2e_v_3a_61_24_94__Y ? (i_6_5c_enabled_5b_3_3a_3_5d_ ? (i_eq_24_receiver_2e_v_3a_64_24_107__Y ? value<1>{0x1u} : (i_eq_24_receiver_2e_v_3a_65_24_110__Y ? value<1>{0u} : value<1>{0x1u})) : value<1>{0u}) : i_6_5c_enabled_5b_3_3a_3_5d_) : value<1>{0u}));
	// cells $procmux$5742 $procmux$5739 $procmux$5737 $procmux$5607 $procmux$5542 $procmux$5461
	i_7_5c_enabled_5b_3_3a_0_5d_.slice<0>() = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_eq_24_receiver_2e_v_3a_61_24_94__Y ? (i_3_5c_enabled_5b_0_3a_0_5d_ ? (i_eq_24_receiver_2e_v_3a_64_24_95__Y ? value<1>{0x1u} : (i_eq_24_receiver_2e_v_3a_65_24_98__Y ? value<1>{0u} : value<1>{0x1u})) : value<1>{0u}) : i_3_5c_enabled_5b_0_3a_0_5d_) : value<1>{0u}));
	// cells $procmux$5706 $procmux$5703 $procmux$5701 $procmux$5418 $procmux$5353 $procmux$5272
	i_7_5c_enabled_5b_3_3a_0_5d_.slice<1>() = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_eq_24_receiver_2e_v_3a_61_24_94__Y ? (i_4_5c_enabled_5b_1_3a_1_5d_ ? (i_eq_24_receiver_2e_v_3a_64_24_99__Y ? value<1>{0x1u} : (i_eq_24_receiver_2e_v_3a_65_24_102__Y ? value<1>{0u} : value<1>{0x1u})) : value<1>{0u}) : i_4_5c_enabled_5b_1_3a_1_5d_) : value<1>{0u}));
	// cells $procmux$5670 $procmux$5667 $procmux$5665 $procmux$5229 $procmux$5164 $procmux$5083
	i_7_5c_enabled_5b_3_3a_0_5d_.slice<2>() = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_eq_24_receiver_2e_v_3a_61_24_94__Y ? (i_5_5c_enabled_5b_2_3a_2_5d_ ? (i_eq_24_receiver_2e_v_3a_64_24_103__Y ? value<1>{0x1u} : (i_eq_24_receiver_2e_v_3a_65_24_106__Y ? value<1>{0u} : value<1>{0x1u})) : value<1>{0u}) : i_5_5c_enabled_5b_2_3a_2_5d_) : value<1>{0u}));
	// \full_case: 1
	// \src: receiver.v:109.9-109.39|receiver.v:109.6-110.69
	// cell $procmux$1309
	i_21_5c_fault_5b_31_3a_0_5d_.slice<4,0>() = (i_eq_24_receiver_2e_v_3a_109_24_249__Y ? value<1>{0x1u}.concat(i_16_5c_fault_5b_31_3a_0_5d_.slice<3,0>()).val() : i_13_5c_fault_5b_31_3a_0_5d_.slice<4>().concat(i_16_5c_fault_5b_31_3a_0_5d_.slice<3,0>()).val());
	// connection
	i_21_5c_fault_5b_31_3a_0_5d_.slice<31,5>() = i_13_5c_fault_5b_31_3a_0_5d_.slice<31,5>().val();
	// cells $procmux$1798 $procmux$1795 $procmux$1793 $procmux$1377 $procmux$1339
	i_7_5c_outstanding_5b_15_3a_0_5d_ = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? i_5_5c_outstanding_5b_15_3a_0_5d_ : (i_4_5c_evemit_5b_0_3a_0_5d_ ? (i_eq_24_receiver_2e_v_3a_109_24_249__Y ? i_5_5c_outstanding_5b_15_3a_0_5d_ : i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7101.slice<15,0>().val()) : i_5_5c_outstanding_5b_15_3a_0_5d_)) : value<16>{0u}));
	// cells $procmux$5760 $procmux$5757 $procmux$5755 $procmux$5028 $procmux$4960
	i_7_5c_counts_5b_63_3a_0_5d_.slice<63,48>() = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_eq_24_receiver_2e_v_3a_61_24_94__Y ? (i_6_5c_enabled_5b_3_3a_3_5d_ ? (i_eq_24_receiver_2e_v_3a_64_24_107__Y ? i_6_5c_counts_5b_63_3a_48_5d_ : i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7141.slice<15,0>().val()) : i_6_5c_counts_5b_63_3a_48_5d_) : i_6_5c_counts_5b_63_3a_48_5d_) : value<16>{0u}));
	// cells $procmux$5733 $procmux$5730 $procmux$5728 $procmux$5595 $procmux$5527
	i_7_5c_counts_5b_63_3a_0_5d_.slice<15,0>() = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_eq_24_receiver_2e_v_3a_61_24_94__Y ? (i_3_5c_enabled_5b_0_3a_0_5d_ ? (i_eq_24_receiver_2e_v_3a_64_24_95__Y ? i_3_5c_counts_5b_15_3a_0_5d_ : i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7144.slice<15,0>().val()) : i_3_5c_counts_5b_15_3a_0_5d_) : i_3_5c_counts_5b_15_3a_0_5d_) : value<16>{0u}));
	// cells $procmux$5697 $procmux$5694 $procmux$5692 $procmux$5406 $procmux$5338
	i_7_5c_counts_5b_63_3a_0_5d_.slice<31,16>() = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_eq_24_receiver_2e_v_3a_61_24_94__Y ? (i_4_5c_enabled_5b_1_3a_1_5d_ ? (i_eq_24_receiver_2e_v_3a_64_24_99__Y ? i_4_5c_counts_5b_31_3a_16_5d_ : i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7143.slice<15,0>().val()) : i_4_5c_counts_5b_31_3a_16_5d_) : i_4_5c_counts_5b_31_3a_16_5d_) : value<16>{0u}));
	// cells $procmux$5661 $procmux$5658 $procmux$5656 $procmux$5217 $procmux$5149
	i_7_5c_counts_5b_63_3a_0_5d_.slice<47,32>() = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_eq_24_receiver_2e_v_3a_61_24_94__Y ? (i_5_5c_enabled_5b_2_3a_2_5d_ ? (i_eq_24_receiver_2e_v_3a_64_24_103__Y ? i_5_5c_counts_5b_47_3a_32_5d_ : i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7142.slice<15,0>().val()) : i_5_5c_counts_5b_47_3a_32_5d_) : i_5_5c_counts_5b_47_3a_32_5d_) : value<16>{0u}));
	// \src: receiver.v:93.37-93.53
	// cell $not$receiver.v:93$223
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7116.slice<3,0>() = not_u<4>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7117.slice<3,0>().val());
	// \src: receiver.v:78.10-78.18
	// cell $eq$receiver.v:78$175
	i_eq_24_receiver_2e_v_3a_78_24_175__Y = logic_not<1>(i_3_5c_evenq_5b_1_3a_0_5d_);
	// cells $procmux$4784 $procmux$4506
	i_3_5c_enqid_5b_31_3a_0_5d_ = (i_4_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_125__Y ? p_enqid.curr : p_nextid.curr) : p_enqid.curr);
	// cells $procmux$4793 $procmux$4518
	i_3_5c_enqowner_5b_1_3a_0_5d_ = (i_4_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_125__Y ? p_enqowner.curr : i_4_5c_releaseowner_5b_1_3a_0_5d_) : p_enqowner.curr);
	// \full_case: 1
	// \src: receiver.v:107.8-107.14|receiver.v:107.5-111.8
	// cell $procmux$1365
	i_20_5c_fault_5b_31_3a_0_5d_.slice<4,0>() = (i_4_5c_evemit_5b_0_3a_0_5d_ ? i_21_5c_fault_5b_31_3a_0_5d_.slice<4,0>().val() : i_13_5c_fault_5b_31_3a_0_5d_.slice<4>().concat(i_16_5c_fault_5b_31_3a_0_5d_.slice<3,0>()).val());
	// connection
	i_20_5c_fault_5b_31_3a_0_5d_.slice<31,5>() = i_13_5c_fault_5b_31_3a_0_5d_.slice<31,5>().val();
	// cells $procmux$3766 $procmux$3763 $procmux$3761 $procmux$3489 $add$receiver.v:81$178
	i_5_5c_nextid_5b_31_3a_0_5d_ = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_6_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_168__Y ? i_3_5c_nextid_5b_31_3a_0_5d_ : add_uu<32>(i_3_5c_nextid_5b_31_3a_0_5d_, value<1>{0x1u})) : i_3_5c_nextid_5b_31_3a_0_5d_) : value<32>{0u}));
	// \src: receiver.v:93.37-93.53
	// cell $shift$receiver.v:93$226
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7114.slice<3,0>() = shift_us<4>(value<1>{0u}, i_neg_24_receiver_2e_v_3a_93_24_218__Y);
	// cells $procmux$3536 $procmux$3201 $procmux$2765
	i_6_5c_qi_5b_7_5d__5b_31_3a_0_5d_ = (i_6_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_168__Y ? i_3_5c_qi_5b_7_5d__5b_31_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6972 ? i_3_5c_qi_5b_7_5d__5b_31_3a_0_5d_ : (i_procmux_24_2745__CMP ? i_3_5c_nextid_5b_31_3a_0_5d_ : value<32>{0u}))) : i_3_5c_qi_5b_7_5d__5b_31_3a_0_5d_);
	// cells $procmux$3545 $procmux$3213 $procmux$2786
	i_6_5c_qi_5b_6_5d__5b_31_3a_0_5d_ = (i_6_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_168__Y ? i_3_5c_qi_5b_6_5d__5b_31_3a_0_5d_ : (i_procmux_24_2746__CMP ? i_3_5c_nextid_5b_31_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6962 ? i_3_5c_qi_5b_6_5d__5b_31_3a_0_5d_ : value<32>{0u}))) : i_3_5c_qi_5b_6_5d__5b_31_3a_0_5d_);
	// cells $procmux$3554 $procmux$3225 $procmux$2807
	i_6_5c_qi_5b_5_5d__5b_31_3a_0_5d_ = (i_6_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_168__Y ? i_3_5c_qi_5b_5_5d__5b_31_3a_0_5d_ : (i_procmux_24_2747__CMP ? i_3_5c_nextid_5b_31_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6954 ? i_3_5c_qi_5b_5_5d__5b_31_3a_0_5d_ : value<32>{0u}))) : i_3_5c_qi_5b_5_5d__5b_31_3a_0_5d_);
	// cells $procmux$3563 $procmux$3237 $procmux$2828
	i_6_5c_qi_5b_4_5d__5b_31_3a_0_5d_ = (i_6_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_168__Y ? i_3_5c_qi_5b_4_5d__5b_31_3a_0_5d_ : (i_procmux_24_2748__CMP ? i_3_5c_nextid_5b_31_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6946 ? i_3_5c_qi_5b_4_5d__5b_31_3a_0_5d_ : value<32>{0u}))) : i_3_5c_qi_5b_4_5d__5b_31_3a_0_5d_);
	// cells $procmux$3572 $procmux$3249 $procmux$2849
	i_6_5c_qi_5b_3_5d__5b_31_3a_0_5d_ = (i_6_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_168__Y ? i_3_5c_qi_5b_3_5d__5b_31_3a_0_5d_ : (i_procmux_24_2749__CMP ? i_3_5c_nextid_5b_31_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6944 ? i_3_5c_qi_5b_3_5d__5b_31_3a_0_5d_ : value<32>{0u}))) : i_3_5c_qi_5b_3_5d__5b_31_3a_0_5d_);
	// cells $procmux$3581 $procmux$3261 $procmux$2870
	i_6_5c_qi_5b_2_5d__5b_31_3a_0_5d_ = (i_6_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_168__Y ? i_3_5c_qi_5b_2_5d__5b_31_3a_0_5d_ : (i_procmux_24_2750__CMP ? i_3_5c_nextid_5b_31_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6940 ? i_3_5c_qi_5b_2_5d__5b_31_3a_0_5d_ : value<32>{0u}))) : i_3_5c_qi_5b_2_5d__5b_31_3a_0_5d_);
	// cells $procmux$3590 $procmux$3273 $procmux$2891
	i_6_5c_qi_5b_1_5d__5b_31_3a_0_5d_ = (i_6_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_168__Y ? i_3_5c_qi_5b_1_5d__5b_31_3a_0_5d_ : (i_procmux_24_2751__CMP ? i_3_5c_nextid_5b_31_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6938 ? i_3_5c_qi_5b_1_5d__5b_31_3a_0_5d_ : value<32>{0u}))) : i_3_5c_qi_5b_1_5d__5b_31_3a_0_5d_);
	// cells $procmux$2639 $procmux$2295
	i_3_5c_bytezero_5b_7_3a_0_5d_ = (i_logic__and_24_receiver_2e_v_3a_87_24_201__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_205__Y ? i_shiftx_24_receiver_2e_v_3a_91_24_212__Y : p_bytezero.curr) : p_bytezero.curr);
	// cells $procmux$1677 $procmux$1564
	i_4_5c_emitid_5b_31_3a_0_5d_ = (p_rone.curr ? (i_logic__or_24_receiver_2e_v_3a_100_24_242__Y ? p_idone.curr : p_emitid.curr) : p_emitid.curr);
	// cells $procmux$2648 $procmux$2307
	i_3_5c_idzero_5b_31_3a_0_5d_ = (i_logic__and_24_receiver_2e_v_3a_87_24_201__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_205__Y ? i_6_5c_qi_5b_0_5d__5b_31_3a_0_5d_ : p_idzero.curr) : p_idzero.curr);
	// \full_case: 1
	// \src: receiver.v:98.7-98.14|receiver.v:98.4-112.7
	// cell $procmux$1784
	i_19_5c_fault_5b_31_3a_0_5d_.slice<4,0>() = (i_3_5c_failed_5b_0_3a_0_5d_ ? i_13_5c_fault_5b_31_3a_0_5d_.slice<4>().concat(i_16_5c_fault_5b_31_3a_0_5d_.slice<3,0>()).val() : i_20_5c_fault_5b_31_3a_0_5d_.slice<4,0>().val());
	// connection
	i_19_5c_fault_5b_31_3a_0_5d_.slice<31,5>() = i_13_5c_fault_5b_31_3a_0_5d_.slice<31,5>().val();
	// cells $or$receiver.v:93$227 $and$receiver.v:93$224
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7113.slice<3,0>() = or_uu<4>(and_uu<4>(i_7_5c_enabled_5b_3_3a_0_5d_, i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7116.slice<3,0>().val()), i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7114.slice<3,0>().val());
	// \src: receiver.v:127.36-127.40
	// cell $add$receiver.v:127$333
	i_add_24_receiver_2e_v_3a_127_24_331__Y = add_uu<17>(p_pp.curr, value<1>{0x1u});
	// \src: receiver.v:126.31-126.35
	// cell $add$receiver.v:126$330
	i_add_24_receiver_2e_v_3a_126_24_328__Y = add_uu<17>(p_fp.curr, value<1>{0x1u});
	// \src: receiver.v:125.31-125.35
	// cell $add$receiver.v:125$327
	i_add_24_receiver_2e_v_3a_125_24_325__Y = add_uu<17>(p_rp.curr, value<1>{0x1u});
	// \src: receiver.v:124.31-124.35
	// cell $add$receiver.v:124$324
	i_add_24_receiver_2e_v_3a_124_24_322__Y = add_uu<17>(p_cp.curr, value<1>{0x1u});
	// cells $procmux$378 $logic_or$receiver.v:121$315 $gt$receiver.v:121$313 $ne$receiver.v:121$314 $procmux$475 $procmux$472 $procmux$470 $procmux$387 $add$receiver.v:120$309 $auto$opt_reduce.cc:131:opt_pmux$7057 $procmux$466 $procmux$463 $procmux$461 $procmux$429 $add$receiver.v:120$310 $auto$opt_reduce.cc:131:opt_pmux$7051 $procmux$457 $procmux$454 $procmux$452 $procmux$415 $add$receiver.v:120$311 $auto$opt_reduce.cc:131:opt_pmux$7053 $procmux$448 $procmux$445 $procmux$443 $procmux$401 $add$receiver.v:120$312 $auto$opt_reduce.cc:131:opt_pmux$7055
	i_22_5c_fault_5b_31_3a_0_5d_.slice<5,0>() = (logic_or<1>(gt_uu<1>(i_7_5c_qlen_5b_3_3a_0_5d_, value<4>{0x8u}), ne_uu<1>((p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_rone_5b_0_3a_0_5d_ ? (reduce_or<1>(i_procmux_24_391__CMP.concat(i_procmux_24_390__CMP).concat(i_procmux_24_389__CMP).val()) ? i_19_5c_tokens3_5b_3_3a_0_5d_ : (i_procmux_24_388__CMP ? add_uu<4>(i_19_5c_tokens3_5b_3_3a_0_5d_, value<1>{0x1u}) : value<4>{0u})) : i_19_5c_tokens3_5b_3_3a_0_5d_) : value<4>{0u})).concat((p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_rone_5b_0_3a_0_5d_ ? (i_procmux_24_389__CMP ? add_uu<4>(i_19_5c_tokens2_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_391__CMP.concat(i_procmux_24_390__CMP).concat(i_procmux_24_388__CMP).val()) ? i_19_5c_tokens2_5b_3_3a_0_5d_ : value<4>{0u})) : i_19_5c_tokens2_5b_3_3a_0_5d_) : value<4>{0u}))).concat((p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_rone_5b_0_3a_0_5d_ ? (i_procmux_24_390__CMP ? add_uu<4>(i_19_5c_tokens1_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_391__CMP.concat(i_procmux_24_389__CMP).concat(i_procmux_24_388__CMP).val()) ? i_19_5c_tokens1_5b_3_3a_0_5d_ : value<4>{0u})) : i_19_5c_tokens1_5b_3_3a_0_5d_) : value<4>{0u}))).concat((p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_rone_5b_0_3a_0_5d_ ? (i_procmux_24_391__CMP ? add_uu<4>(i_19_5c_tokens0_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_390__CMP.concat(i_procmux_24_389__CMP).concat(i_procmux_24_388__CMP).val()) ? i_19_5c_tokens0_5b_3_3a_0_5d_ : value<4>{0u})) : i_19_5c_tokens0_5b_3_3a_0_5d_) : value<4>{0u}))).val(), i_7_5c_outstanding_5b_15_3a_0_5d_)) ? value<1>{0x1u}.concat(i_19_5c_fault_5b_31_3a_0_5d_.slice<4,0>()).val() : i_13_5c_fault_5b_31_3a_0_5d_.slice<5>().concat(i_19_5c_fault_5b_31_3a_0_5d_.slice<4,0>()).val());
	// connection
	i_22_5c_fault_5b_31_3a_0_5d_.slice<31,6>() = i_13_5c_fault_5b_31_3a_0_5d_.slice<31,6>().val();
	// cells $procmux$5719 $procmux$5571 $procmux$5512 $procmux$5443
	i_3_5c_evexpire_5b_3_3a_0_5d_.slice<0>() = (i_eq_24_receiver_2e_v_3a_61_24_94__Y ? (i_3_5c_enabled_5b_0_3a_0_5d_ ? (i_eq_24_receiver_2e_v_3a_64_24_95__Y ? value<1>{0u} : (i_eq_24_receiver_2e_v_3a_65_24_98__Y ? value<1>{0x1u} : value<1>{0u})) : value<1>{0u}) : value<1>{0u});
	// cells $procmux$5683 $procmux$5382 $procmux$5323 $procmux$5254
	i_3_5c_evexpire_5b_3_3a_0_5d_.slice<1>() = (i_eq_24_receiver_2e_v_3a_61_24_94__Y ? (i_4_5c_enabled_5b_1_3a_1_5d_ ? (i_eq_24_receiver_2e_v_3a_64_24_99__Y ? value<1>{0u} : (i_eq_24_receiver_2e_v_3a_65_24_102__Y ? value<1>{0x1u} : value<1>{0u})) : value<1>{0u}) : value<1>{0u});
	// cells $procmux$5638 $procmux$5193 $procmux$5134 $procmux$5065
	i_3_5c_evexpire_5b_3_3a_0_5d_.slice<2>() = (i_eq_24_receiver_2e_v_3a_61_24_94__Y ? (i_5_5c_enabled_5b_2_3a_2_5d_ ? (i_eq_24_receiver_2e_v_3a_64_24_103__Y ? value<1>{0u} : (i_eq_24_receiver_2e_v_3a_65_24_106__Y ? value<1>{0x1u} : value<1>{0u})) : value<1>{0u}) : value<1>{0u});
	// cells $procmux$4883 $procmux$5004 $procmux$4945 $procmux$5784
	i_3_5c_evexpire_5b_3_3a_0_5d_.slice<3>() = (i_eq_24_receiver_2e_v_3a_61_24_94__Y ? (i_6_5c_enabled_5b_3_3a_3_5d_ ? (i_eq_24_receiver_2e_v_3a_64_24_107__Y ? value<1>{0u} : (i_eq_24_receiver_2e_v_3a_65_24_110__Y ? value<1>{0x1u} : value<1>{0u})) : value<1>{0u}) : value<1>{0u});
	// cells $procmux$369 $logic_or$receiver.v:122$319 $ge$receiver.v:122$317 $ge$receiver.v:122$318
	i_23_5c_fault_5b_31_3a_0_5d_.slice<6,0>() = (logic_or<1>(ge_uu<1>(p_tick.curr, value<31>{0x7ffffffeu}), ge_uu<1>(i_5_5c_nextid_5b_31_3a_0_5d_, value<31>{0x7ffffffeu})) ? value<1>{0x1u}.concat(i_22_5c_fault_5b_31_3a_0_5d_.slice<5,0>()).val() : i_13_5c_fault_5b_31_3a_0_5d_.slice<6>().concat(i_22_5c_fault_5b_31_3a_0_5d_.slice<5,0>()).val());
	// connection
	i_23_5c_fault_5b_31_3a_0_5d_.slice<31,7>() = i_13_5c_fault_5b_31_3a_0_5d_.slice<31,7>().val();
	// cells $procmux$6507 $procmux$5908
	i_2_5c_evwu_5b_3_3a_0_5d_.slice<0>() = (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_59_24_90__Y ? value<1>{0x1u} : value<1>{0u}) : p_evwu.curr.slice<0>().val());
	// cells $procmux$6495 $procmux$5872
	i_2_5c_evwu_5b_3_3a_0_5d_.slice<1>() = (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_59_24_91__Y ? value<1>{0x1u} : value<1>{0u}) : p_evwu.curr.slice<1>().val());
	// cells $procmux$6483 $procmux$5836
	i_2_5c_evwu_5b_3_3a_0_5d_.slice<2>() = (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_59_24_92__Y ? value<1>{0x1u} : value<1>{0u}) : p_evwu.curr.slice<2>().val());
	// cells $procmux$335 $procmux$5800
	i_2_5c_evwu_5b_3_3a_0_5d_.slice<3>() = (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_59_24_93__Y ? value<1>{0x1u} : value<1>{0u}) : p_evwu.curr.slice<3>().val());
	// \full_case: 1
	// \src: receiver.v:55.15-55.34|receiver.v:55.12-128.6
	// cell $procmux$6519
	i_2_5c_bytes_5b_31_3a_0_5d_.slice<31,24>() = (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_6_5c_bytes_5b_31_3a_24_5d_ : p_bytes.curr.slice<31,24>().val());
	// \full_case: 1
	// \src: receiver.v:55.15-55.34|receiver.v:55.12-128.6
	// cell $procmux$6513
	i_2_5c_bytes_5b_31_3a_0_5d_.slice<7,0>() = (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_3_5c_bytes_5b_7_3a_0_5d_ : p_bytes.curr.slice<7,0>().val());
	// \full_case: 1
	// \src: receiver.v:55.15-55.34|receiver.v:55.12-128.6
	// cell $procmux$6501
	i_2_5c_bytes_5b_31_3a_0_5d_.slice<15,8>() = (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_4_5c_bytes_5b_15_3a_8_5d_ : p_bytes.curr.slice<15,8>().val());
	// \full_case: 1
	// \src: receiver.v:55.15-55.34|receiver.v:55.12-128.6
	// cell $procmux$6489
	i_2_5c_bytes_5b_31_3a_0_5d_.slice<23,16>() = (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_5_5c_bytes_5b_23_3a_16_5d_ : p_bytes.curr.slice<23,16>().val());
	// cells $procdff$6908 $procmux$6696 $procmux$6135 $procmux$2378 $procmux$1995
	if (posedge_p_clk) {
		p_qi_5b_7_5d_.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_201__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_205__Y ? value<32>{0u} : i_6_5c_qi_5b_7_5d__5b_31_3a_0_5d_) : i_6_5c_qi_5b_7_5d__5b_31_3a_0_5d_) : p_qi_5b_7_5d_.curr));
	}
	// cells $procdff$6907 $procmux$6702 $procmux$6141 $procmux$2387 $procmux$2007
	if (posedge_p_clk) {
		p_qi_5b_6_5d_.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_201__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_205__Y ? i_6_5c_qi_5b_7_5d__5b_31_3a_0_5d_ : i_6_5c_qi_5b_6_5d__5b_31_3a_0_5d_) : i_6_5c_qi_5b_6_5d__5b_31_3a_0_5d_) : p_qi_5b_6_5d_.curr));
	}
	// cells $procdff$6906 $procmux$6708 $procmux$6147 $procmux$2396 $procmux$2019
	if (posedge_p_clk) {
		p_qi_5b_5_5d_.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_201__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_205__Y ? i_6_5c_qi_5b_6_5d__5b_31_3a_0_5d_ : i_6_5c_qi_5b_5_5d__5b_31_3a_0_5d_) : i_6_5c_qi_5b_5_5d__5b_31_3a_0_5d_) : p_qi_5b_5_5d_.curr));
	}
	// cells $procdff$6905 $procmux$6714 $procmux$6153 $procmux$2405 $procmux$2031
	if (posedge_p_clk) {
		p_qi_5b_4_5d_.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_201__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_205__Y ? i_6_5c_qi_5b_5_5d__5b_31_3a_0_5d_ : i_6_5c_qi_5b_4_5d__5b_31_3a_0_5d_) : i_6_5c_qi_5b_4_5d__5b_31_3a_0_5d_) : p_qi_5b_4_5d_.curr));
	}
	// cells $procdff$6904 $procmux$6720 $procmux$6159 $procmux$2414 $procmux$2043
	if (posedge_p_clk) {
		p_qi_5b_3_5d_.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_201__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_205__Y ? i_6_5c_qi_5b_4_5d__5b_31_3a_0_5d_ : i_6_5c_qi_5b_3_5d__5b_31_3a_0_5d_) : i_6_5c_qi_5b_3_5d__5b_31_3a_0_5d_) : p_qi_5b_3_5d_.curr));
	}
	// cells $procdff$6903 $procmux$6726 $procmux$6165 $procmux$2423 $procmux$2055
	if (posedge_p_clk) {
		p_qi_5b_2_5d_.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_201__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_205__Y ? i_6_5c_qi_5b_3_5d__5b_31_3a_0_5d_ : i_6_5c_qi_5b_2_5d__5b_31_3a_0_5d_) : i_6_5c_qi_5b_2_5d__5b_31_3a_0_5d_) : p_qi_5b_2_5d_.curr));
	}
	// cells $procdff$6902 $procmux$6732 $procmux$6171 $procmux$2432 $procmux$2067
	if (posedge_p_clk) {
		p_qi_5b_1_5d_.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_201__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_205__Y ? i_6_5c_qi_5b_2_5d__5b_31_3a_0_5d_ : i_6_5c_qi_5b_1_5d__5b_31_3a_0_5d_) : i_6_5c_qi_5b_1_5d__5b_31_3a_0_5d_) : p_qi_5b_1_5d_.curr));
	}
	// cells $procdff$6901 $procmux$6738 $procmux$6177 $procmux$2441 $procmux$2079
	if (posedge_p_clk) {
		p_qi_5b_0_5d_.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_201__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_205__Y ? i_6_5c_qi_5b_1_5d__5b_31_3a_0_5d_ : i_6_5c_qi_5b_0_5d__5b_31_3a_0_5d_) : i_6_5c_qi_5b_0_5d__5b_31_3a_0_5d_) : p_qi_5b_0_5d_.curr));
	}
	// cells $procdff$6900 $procmux$6699 $procmux$6183
	if (posedge_p_clk) {
		p_qo_5b_7_5d_.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_9_5c_qo_5b_7_5d__5b_1_3a_0_5d_ : p_qo_5b_7_5d_.curr));
	}
	// cells $procdff$6899 $procmux$6705 $procmux$6189
	if (posedge_p_clk) {
		p_qo_5b_6_5d_.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_9_5c_qo_5b_6_5d__5b_1_3a_0_5d_ : p_qo_5b_6_5d_.curr));
	}
	// cells $procdff$6898 $procmux$6711 $procmux$6195
	if (posedge_p_clk) {
		p_qo_5b_5_5d_.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_9_5c_qo_5b_5_5d__5b_1_3a_0_5d_ : p_qo_5b_5_5d_.curr));
	}
	// cells $procdff$6897 $procmux$6717 $procmux$6201
	if (posedge_p_clk) {
		p_qo_5b_4_5d_.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_9_5c_qo_5b_4_5d__5b_1_3a_0_5d_ : p_qo_5b_4_5d_.curr));
	}
	// cells $procdff$6896 $procmux$6723 $procmux$6207
	if (posedge_p_clk) {
		p_qo_5b_3_5d_.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_9_5c_qo_5b_3_5d__5b_1_3a_0_5d_ : p_qo_5b_3_5d_.curr));
	}
	// cells $procdff$6895 $procmux$6729 $procmux$6213
	if (posedge_p_clk) {
		p_qo_5b_2_5d_.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_9_5c_qo_5b_2_5d__5b_1_3a_0_5d_ : p_qo_5b_2_5d_.curr));
	}
	// cells $procdff$6894 $procmux$6735 $procmux$6219
	if (posedge_p_clk) {
		p_qo_5b_1_5d_.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_9_5c_qo_5b_1_5d__5b_1_3a_0_5d_ : p_qo_5b_1_5d_.curr));
	}
	// cells $procdff$6893 $procmux$6741 $procmux$6225
	if (posedge_p_clk) {
		p_qo_5b_0_5d_.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_9_5c_qo_5b_0_5d__5b_1_3a_0_5d_ : p_qo_5b_0_5d_.curr));
	}
	// cells $procdff$6877 $procmux$6576 $procmux$6015 $procmux$1802 $procmux$1485
	if (posedge_p_clk) {
		p_transferbyte.next = (p_rst ? value<8>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? p_transferbyte.curr : (i_logic__and_24_receiver_2e_v_3a_103_24_244__Y ? i_3_5c_bytezero_5b_7_3a_0_5d_ : p_transferbyte.curr)) : p_transferbyte.curr));
	}
	// cells $procdff$6876 $procmux$6579 $procmux$6021 $procmux$1883 $procmux$1653 $procmux$1549
	if (posedge_p_clk) {
		p_emitbyte.next = (p_rst ? value<8>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? p_emitbyte.curr : (p_rone.curr ? (i_logic__or_24_receiver_2e_v_3a_100_24_242__Y ? p_byteone.curr : p_emitbyte.curr) : p_emitbyte.curr)) : p_emitbyte.curr));
	}
	// cells $procdff$6875 $procmux$6582 $procmux$6249 $procmux$2558 $procmux$2235
	if (posedge_p_clk) {
		p_grantbyte.next = (p_rst ? value<8>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_201__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_205__Y ? i_shiftx_24_receiver_2e_v_3a_91_24_212__Y : p_grantbyte.curr) : p_grantbyte.curr) : p_grantbyte.curr));
	}
	// cells $procdff$6874 $procmux$6570 $procmux$6393 $procmux$3689 $procmux$3405 $procmux$3111
	if (posedge_p_clk) {
		p_enqid2.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_6_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_168__Y ? p_enqid2.curr : (i_eq_24_receiver_2e_v_3a_78_24_175__Y ? p_enqid2.curr : i_3_5c_nextid_5b_31_3a_0_5d_)) : p_enqid2.curr) : p_enqid2.curr));
	}
	// cells $procdff$6873 $procmux$6573 $procmux$6399 $procmux$3698 $procmux$3417 $procmux$3126
	if (posedge_p_clk) {
		p_enqowner2.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_6_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_168__Y ? p_enqowner2.curr : (i_eq_24_receiver_2e_v_3a_78_24_175__Y ? p_enqowner2.curr : i_6_5c_releaseowner_5b_1_3a_0_5d_)) : p_enqowner2.curr) : p_enqowner2.curr));
	}
	// cells $procdff$6872 $procmux$6585 $procmux$6027 $procmux$1892 $procmux$1665 $procmux$1609
	if (posedge_p_clk) {
		p_blockid.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? p_blockid.curr : (p_rone.curr ? (i_logic__or_24_receiver_2e_v_3a_100_24_242__Y ? p_blockid.curr : p_idone.curr) : p_blockid.curr)) : p_blockid.curr));
	}
	// cells $procdff$6871 $procmux$6588 $procmux$6033 $procmux$1757 $procmux$1389
	if (posedge_p_clk) {
		p_callbackid.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? p_callbackid.curr : (i_4_5c_evemit_5b_0_3a_0_5d_ ? i_4_5c_emitid_5b_31_3a_0_5d_ : p_callbackid.curr)) : p_callbackid.curr));
	}
	// cells $procdff$6870 $procmux$6591 $procmux$6039 $procmux$1811 $procmux$1497
	if (posedge_p_clk) {
		p_transferid.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? p_transferid.curr : (i_logic__and_24_receiver_2e_v_3a_103_24_244__Y ? i_3_5c_idzero_5b_31_3a_0_5d_ : p_transferid.curr)) : p_transferid.curr));
	}
	// cells $procdff$6869 $procmux$6594 $procmux$6045 $procmux$1901
	if (posedge_p_clk) {
		p_emitid.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? p_emitid.curr : i_4_5c_emitid_5b_31_3a_0_5d_) : p_emitid.curr));
	}
	// cells $procdff$6868 $procmux$6597 $procmux$6255 $procmux$2567 $procmux$2247
	if (posedge_p_clk) {
		p_grantid.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_201__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_205__Y ? i_6_5c_qi_5b_0_5d__5b_31_3a_0_5d_ : p_grantid.curr) : p_grantid.curr) : p_grantid.curr));
	}
	// cells $procdff$6867 $procmux$6600 $procmux$6261 $procmux$2702
	if (posedge_p_clk) {
		p_attemptid.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_201__Y ? i_6_5c_qi_5b_0_5d__5b_31_3a_0_5d_ : p_attemptid.curr) : p_attemptid.curr));
	}
	// cells $procdff$6866 $procmux$6603 $procmux$6405 $procmux$3707 $procmux$3429 $procmux$3081
	if (posedge_p_clk) {
		p_enqid.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_6_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_168__Y ? i_3_5c_enqid_5b_31_3a_0_5d_ : (i_eq_24_receiver_2e_v_3a_78_24_175__Y ? i_3_5c_nextid_5b_31_3a_0_5d_ : i_3_5c_enqid_5b_31_3a_0_5d_)) : i_3_5c_enqid_5b_31_3a_0_5d_) : p_enqid.curr));
	}
	// cells $procdff$6865 $procmux$6606 $procmux$6051 $procmux$1910 $procmux$1689 $procmux$1624
	if (posedge_p_clk) {
		p_blockowner.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? p_blockowner.curr : (p_rone.curr ? (i_logic__or_24_receiver_2e_v_3a_100_24_242__Y ? p_blockowner.curr : p_ownerone.curr) : p_blockowner.curr)) : p_blockowner.curr));
	}
	// cells $procdff$6864 $procmux$6609 $procmux$6057 $procmux$1766 $procmux$1401
	if (posedge_p_clk) {
		p_callbackowner.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? p_callbackowner.curr : (i_4_5c_evemit_5b_0_3a_0_5d_ ? i_4_5c_emitowner_5b_1_3a_0_5d_ : p_callbackowner.curr)) : p_callbackowner.curr));
	}
	// cells $procdff$6863 $procmux$6612 $procmux$6063 $procmux$1820 $procmux$1509
	if (posedge_p_clk) {
		p_transferowner.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? p_transferowner.curr : (i_logic__and_24_receiver_2e_v_3a_103_24_244__Y ? i_3_5c_ownerzero_5b_1_3a_0_5d_ : p_transferowner.curr)) : p_transferowner.curr));
	}
	// cells $procdff$6862 $procmux$6615 $procmux$6069 $procmux$1919
	if (posedge_p_clk) {
		p_emitowner.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? p_emitowner.curr : i_4_5c_emitowner_5b_1_3a_0_5d_) : p_emitowner.curr));
	}
	// cells $procdff$6861 $procmux$6618 $procmux$6267 $procmux$2576 $procmux$2259
	if (posedge_p_clk) {
		p_grantowner.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_201__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_205__Y ? i_6_5c_qo_5b_0_5d__5b_1_3a_0_5d_ : p_grantowner.curr) : p_grantowner.curr) : p_grantowner.curr));
	}
	// cells $procdff$6860 $procmux$6621 $procmux$6273 $procmux$2711
	if (posedge_p_clk) {
		p_attemptowner.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_201__Y ? i_6_5c_qo_5b_0_5d__5b_1_3a_0_5d_ : p_attemptowner.curr) : p_attemptowner.curr));
	}
	// cells $procdff$6859 $procmux$6624 $procmux$6411 $procmux$3716 $procmux$3441 $procmux$3096
	if (posedge_p_clk) {
		p_enqowner.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_6_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_168__Y ? i_3_5c_enqowner_5b_1_3a_0_5d_ : (i_eq_24_receiver_2e_v_3a_78_24_175__Y ? i_6_5c_releaseowner_5b_1_3a_0_5d_ : i_3_5c_enqowner_5b_1_3a_0_5d_)) : i_3_5c_enqowner_5b_1_3a_0_5d_) : p_enqowner.curr));
	}
	// cells $procdff$6858 $procmux$6627 $procmux$6075 $procmux$1928
	if (posedge_p_clk) {
		p_evblock.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? value<1>{0u} : i_4_5c_evblock_5b_0_3a_0_5d_) : p_evblock.curr));
	}
	// cells $procdff$6857 $procmux$6630 $procmux$6081 $procmux$1775 $procmux$1413
	if (posedge_p_clk) {
		p_evcallback.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? value<1>{0u} : (i_4_5c_evemit_5b_0_3a_0_5d_ ? value<1>{0x1u} : value<1>{0u})) : p_evcallback.curr));
	}
	// cells $procdff$6856 $procmux$6633 $procmux$6087 $procmux$1829 $procmux$1521
	if (posedge_p_clk) {
		p_evtransfer.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_103_24_244__Y ? value<1>{0x1u} : value<1>{0u})) : p_evtransfer.curr));
	}
	// cells $procdff$6855 $procmux$6636 $procmux$6093 $procmux$1937
	if (posedge_p_clk) {
		p_evemit.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? value<1>{0u} : i_4_5c_evemit_5b_0_3a_0_5d_) : p_evemit.curr));
	}
	// cells $procdff$6854 $procmux$6639 $procmux$6279 $procmux$2585 $procmux$2271
	if (posedge_p_clk) {
		p_evgrant.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_201__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_205__Y ? value<1>{0x1u} : value<1>{0u}) : value<1>{0u}) : p_evgrant.curr));
	}
	// cells $procdff$6853 $procmux$6642 $procmux$6285 $procmux$2720
	if (posedge_p_clk) {
		p_evattempt.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_201__Y ? value<1>{0x1u} : value<1>{0u}) : p_evattempt.curr));
	}
	// cells $procdff$6852 $procmux$6645 $procmux$6417 $procmux$3725 $procmux$3453 $add$receiver.v:80$176
	if (posedge_p_clk) {
		p_evenq.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_6_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_168__Y ? i_3_5c_evenq_5b_1_3a_0_5d_ : add_uu<2>(i_3_5c_evenq_5b_1_3a_0_5d_, value<1>{0x1u})) : i_3_5c_evenq_5b_1_3a_0_5d_) : p_evenq.curr));
	}
	// cells $procdff$6851 $procmux$6648 $procmux$6291 $procmux$2594 $procmux$2283 $shift$receiver.v:93$219 $shiftx$receiver.v:93$217
	if (posedge_p_clk) {
		p_evcancel.next = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_201__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_205__Y ? shift_us<4>(shiftx_uu<1>(i_7_5c_enabled_5b_3_3a_0_5d_, i_6_5c_qo_5b_0_5d__5b_1_3a_0_5d_), i_neg_24_receiver_2e_v_3a_93_24_218__Y) : value<4>{0u}) : value<4>{0u}) : p_evcancel.curr));
	}
	// cells $procdff$6850 $procmux$6651 $procmux$6471
	if (posedge_p_clk) {
		p_evexpire.next = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_3_5c_evexpire_5b_3_3a_0_5d_ : p_evexpire.curr));
	}
	// cells $procdff$6849 $procmux$6654
	if (posedge_p_clk) {
		p_evwu.next = (p_rst ? value<4>{0u} : i_2_5c_evwu_5b_3_3a_0_5d_);
	}
	// cells $procdff$6848 $procmux$6657 $procmux$6297 $procmux$2603 $procmux$1959
	if (posedge_p_clk) {
		p_failowner.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_201__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_205__Y ? p_failowner.curr : i_6_5c_qo_5b_0_5d__5b_1_3a_0_5d_) : p_failowner.curr) : p_failowner.curr));
	}
	// cells $procdff$6847 $procmux$6546 $procmux$5973 $procmux$6541 $logic_or$receiver.v:54$72 $logic_or$receiver.v:54$70 $logic_or$receiver.v:54$68 $logic_or$receiver.v:54$66 $logic_or$receiver.v:54$64 $logic_or$receiver.v:54$62 $logic_or$receiver.v:54$60 $logic_or$receiver.v:54$58 $logic_or$receiver.v:54$56 $logic_or$receiver.v:54$54 $logic_or$receiver.v:54$52 $logic_or$receiver.v:54$48 $lt$receiver.v:54$46 $gt$receiver.v:54$47 $logic_and$receiver.v:54$51 $ne$receiver.v:54$49 $ne$receiver.v:54$50 $lt$receiver.v:54$53 $gt$receiver.v:54$55 $eq$receiver.v:54$57 $eq$receiver.v:54$59 $gt$receiver.v:54$61 $ge$receiver.v:54$63 $ge$receiver.v:54$65 $ge$receiver.v:54$67 $ge$receiver.v:54$69 $ge$receiver.v:54$71
	if (posedge_p_clk) {
		p_fault.next = (p_rst ? value<31>{0u}.concat((logic_or<1>(logic_or<1>(logic_or<1>(logic_or<1>(logic_or<1>(logic_or<1>(logic_or<1>(logic_or<1>(logic_or<1>(logic_or<1>(logic_or<1>(logic_or<1>(lt_uu<1>(p_cfgp, value<2>{0x2u}), gt_uu<1>(p_cfgp, value<5>{0x11u})), logic_and<1>(ne_uu<1>(p_cfgr, value<3>{0x5u}), ne_uu<1>(p_cfgr, value<3>{0x7u}))), lt_uu<1>(p_cfgf, value<6>{0x28u})), gt_uu<1>(p_cfgf, value<10>{0x3b8u})), logic_not<1>(p_cfgk)), logic_not<1>(p_cfgperiod)), gt_uu<1>(p_cfgperiod, value<7>{0x44u})), ge_uu<1>(p_cfgphi, p_cfgperiod)), ge_uu<1>(p_cfgcp, p_cfgp)), ge_uu<1>(p_cfgrp, p_cfgr)), ge_uu<1>(p_cfgfp, p_cfgf)), ge_uu<1>(p_cfgpp, p_cfgperiod)) ? value<1>{0x1u} : value<1>{0u})).val() : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_13_5c_fault_5b_31_3a_0_5d_.slice<31,7>().concat(i_23_5c_fault_5b_31_3a_0_5d_.slice<6,0>()).val() : p_fault.curr));
	}
	// cells $procdff$6846 $procmux$6660 $procmux$6303 $procmux$2612 $procmux$1947
	if (posedge_p_clk) {
		p_failid.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_201__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_205__Y ? p_failid.curr : i_6_5c_qi_5b_0_5d__5b_31_3a_0_5d_) : p_failid.curr) : p_failid.curr));
	}
	// cells $procdff$6845 $procmux$6663 $procmux$6309 $procmux$2621 $procmux$1971
	if (posedge_p_clk) {
		p_failtick.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_201__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_205__Y ? p_failtick.curr : p_tick.curr) : p_failtick.curr) : p_failtick.curr));
	}
	// cells $procdff$6844 $procmux$6666 $procmux$6315
	if (posedge_p_clk) {
		p_failed.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_3_5c_failed_5b_0_3a_0_5d_ : p_failed.curr));
	}
	// cells $procdff$6843 $procmux$6669 $procmux$6099 $procmux$1838 $procmux$1437
	if (posedge_p_clk) {
		p_byteone.next = (p_rst ? value<8>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? p_byteone.curr : (i_logic__and_24_receiver_2e_v_3a_103_24_244__Y ? i_3_5c_bytezero_5b_7_3a_0_5d_ : p_byteone.curr)) : p_byteone.curr));
	}
	// cells $procdff$6842 $procmux$6672 $procmux$6321
	if (posedge_p_clk) {
		p_bytezero.next = (p_rst ? value<8>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_3_5c_bytezero_5b_7_3a_0_5d_ : p_bytezero.curr));
	}
	// cells $procdff$6841 $procmux$6675 $procmux$6105 $procmux$1847 $procmux$1449
	if (posedge_p_clk) {
		p_idone.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? p_idone.curr : (i_logic__and_24_receiver_2e_v_3a_103_24_244__Y ? i_3_5c_idzero_5b_31_3a_0_5d_ : p_idone.curr)) : p_idone.curr));
	}
	// cells $procdff$6840 $procmux$6678 $procmux$6327
	if (posedge_p_clk) {
		p_idzero.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_3_5c_idzero_5b_31_3a_0_5d_ : p_idzero.curr));
	}
	// cells $procdff$6839 $procmux$6681 $procmux$6111
	if (posedge_p_clk) {
		p_ownerone.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_3_5c_ownerone_5b_1_3a_0_5d_ : p_ownerone.curr));
	}
	// cells $procdff$6838 $procmux$6684 $procmux$6333
	if (posedge_p_clk) {
		p_ownerzero.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_3_5c_ownerzero_5b_1_3a_0_5d_ : p_ownerzero.curr));
	}
	// cells $procdff$6837 $procmux$6687 $procmux$6117
	if (posedge_p_clk) {
		p_rone.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_3_5c_rone_5b_0_3a_0_5d_ : p_rone.curr));
	}
	// cells $procdff$6836 $procmux$6690 $procmux$6123
	if (posedge_p_clk) {
		p_rzero.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_5_5c_rzero_5b_0_3a_0_5d_ : p_rzero.curr));
	}
	// cells $procdff$6835 $procmux$6744 $procmux$6129
	if (posedge_p_clk) {
		p_outstanding.next = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_7_5c_outstanding_5b_15_3a_0_5d_ : p_outstanding.curr));
	}
	// cells $procdff$6834 $procmux$6747 $procmux$6339
	if (posedge_p_clk) {
		p_qlen.next = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_7_5c_qlen_5b_3_3a_0_5d_ : p_qlen.curr));
	}
	// cells $procdff$6833 $procmux$6750
	if (posedge_p_clk) {
		p_bytes.next = (p_rst ? value<32>{0u} : i_2_5c_bytes_5b_31_3a_0_5d_);
	}
	// cells $procdff$6832 $procmux$6753 $procmux$6345 $procmux$2684 $procmux$2355 $or$receiver.v:93$236 $and$receiver.v:93$233 $not$receiver.v:93$232 $shift$receiver.v:93$231 $shift$receiver.v:93$235
	if (posedge_p_clk) {
		p_counts.next = (p_rst ? value<64>{0u,0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_201__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_205__Y ? or_uu<64>(and_uu<64>(i_7_5c_counts_5b_63_3a_0_5d_, not_u<64>(shift_us<64>(value<16>{0xffffu}, i_neg_24_receiver_2e_v_3a_93_24_230__Y))), shift_us<64>(value<1>{0u}, i_neg_24_receiver_2e_v_3a_93_24_230__Y)) : i_7_5c_counts_5b_63_3a_0_5d_) : i_7_5c_counts_5b_63_3a_0_5d_) : p_counts.curr));
	}
	// cells $procdff$6831 $procmux$6756 $procmux$6351 $procmux$2693 $procmux$2367
	if (posedge_p_clk) {
		p_enabled.next = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_201__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_205__Y ? i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7113.slice<3,0>().val() : i_7_5c_enabled_5b_3_3a_0_5d_) : i_7_5c_enabled_5b_3_3a_0_5d_) : p_enabled.curr));
	}
	// cells $procdff$6830 $procmux$6759 $procmux$6477
	if (posedge_p_clk) {
		p_valid.next = (p_rst ? value<4>{0xfu} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_3_5c_valid_5b_3_3a_0_5d_ : p_valid.curr));
	}
	// cells $procdff$6829 $procmux$6762 $procmux$5943 $procmux$6526 $eq$receiver.v:127$332
	if (posedge_p_clk) {
		p_pp.next = (p_rst ? p_cfgpp : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (eq_uu<1>(i_add_24_receiver_2e_v_3a_127_24_331__Y, value<1>{0u}.concat(p_cfgperiod).val()) ? value<16>{0u} : i_add_24_receiver_2e_v_3a_127_24_331__Y.slice<15,0>().val()) : p_pp.curr));
	}
	// cells $procdff$6828 $procmux$6765 $procmux$5949 $procmux$342 $eq$receiver.v:126$329
	if (posedge_p_clk) {
		p_fp.next = (p_rst ? p_cfgfp : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (eq_uu<1>(i_add_24_receiver_2e_v_3a_126_24_328__Y, value<1>{0u}.concat(p_cfgf).val()) ? value<16>{0u} : i_add_24_receiver_2e_v_3a_126_24_328__Y.slice<15,0>().val()) : p_fp.curr));
	}
	// cells $procdff$6827 $procmux$6768 $procmux$5955 $procmux$351 $eq$receiver.v:125$326
	if (posedge_p_clk) {
		p_rp.next = (p_rst ? p_cfgrp : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (eq_uu<1>(i_add_24_receiver_2e_v_3a_125_24_325__Y, value<1>{0u}.concat(p_cfgr).val()) ? value<16>{0u} : i_add_24_receiver_2e_v_3a_125_24_325__Y.slice<15,0>().val()) : p_rp.curr));
	}
	// cells $procdff$6826 $procmux$6771 $procmux$5961 $procmux$360 $eq$receiver.v:124$323
	if (posedge_p_clk) {
		p_cp.next = (p_rst ? p_cfgcp : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (eq_uu<1>(i_add_24_receiver_2e_v_3a_124_24_322__Y, value<1>{0u}.concat(p_cfgp).val()) ? value<16>{0u} : i_add_24_receiver_2e_v_3a_124_24_322__Y.slice<15,0>().val()) : p_cp.curr));
	}
	// cells $procdff$6825 $procmux$6774 $procmux$6423
	if (posedge_p_clk) {
		p_nextid.next = (p_rst ? value<32>{0x1u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_5_5c_nextid_5b_31_3a_0_5d_ : p_nextid.curr));
	}
	// cells $procdff$6824 $procmux$6777 $procmux$5967 $add$receiver.v:123$321
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
		items->add(path, "procmux$5649_Y", "", i_procmux_24_5649__Y, 0, debug_item::GENERATED|debug_item::DRIVEN_COMB);
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
