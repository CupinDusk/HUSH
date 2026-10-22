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
// \src: receiver.v:3.1-121.10
struct p_receiver : public module {
	// \src: receiver.v:39.2-120.5
	wire<32> i_13_5c_fault_5b_31_3a_0_5d_;
	// \src: receiver.v:29.26-29.35
	/*output*/ wire<32> p_attemptid;
	// \src: receiver.v:28.28-28.40
	/*output*/ wire<2> p_attemptowner;
	// \src: receiver.v:29.73-29.80
	/*output*/ wire<32> p_blockid;
	// \src: receiver.v:28.90-28.100
	/*output*/ wire<2> p_blockowner;
	// \src: receiver.v:22.28-22.35
	/*output*/ wire<8> p_byteone;
	// \src: receiver.v:14.20-14.25
	/*output*/ wire<32> p_bytes;
	// \src: receiver.v:22.19-22.27
	/*output*/ wire<8> p_bytezero;
	// \src: receiver.v:29.62-29.72
	/*output*/ wire<32> p_callbackid;
	// \src: receiver.v:28.76-28.89
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
	// \src: receiver.v:30.29-30.37
	/*output*/ wire<8> p_emitbyte;
	// \src: receiver.v:29.44-29.50
	/*output*/ wire<32> p_emitid;
	// \src: receiver.v:28.52-28.61
	/*output*/ wire<2> p_emitowner;
	// \src: receiver.v:12.25-12.32
	/*output*/ wire<4> p_enabled;
	// \src: receiver.v:29.20-29.25
	/*output*/ wire<32> p_enqid;
	// \src: receiver.v:28.19-28.27
	/*output*/ wire<2> p_enqowner;
	// \src: receiver.v:27.19-27.28
	/*output*/ wire<1> p_evattempt;
	// \src: receiver.v:27.66-27.73
	/*output*/ wire<1> p_evblock;
	// \src: receiver.v:27.55-27.65
	/*output*/ wire<1> p_evcallback;
	// \src: receiver.v:26.33-26.41
	/*output*/ wire<4> p_evcancel;
	// \src: receiver.v:27.37-27.43
	/*output*/ wire<1> p_evemit;
	// \src: receiver.v:27.13-27.18
	/*output*/ wire<1> p_evenq;
	// \src: receiver.v:26.24-26.32
	/*output*/ wire<4> p_evexpire;
	// \src: receiver.v:27.29-27.36
	/*output*/ wire<1> p_evgrant;
	// \src: receiver.v:27.44-27.54
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
	// \src: receiver.v:30.19-30.28
	/*output*/ wire<8> p_grantbyte;
	// \src: receiver.v:29.36-29.43
	/*output*/ wire<32> p_grantid;
	// \src: receiver.v:28.41-28.51
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
	// \src: receiver.v:32.32-32.34
	wire<32> p_qi_5b_0_5d_;
	// \src: receiver.v:32.32-32.34
	wire<32> p_qi_5b_1_5d_;
	// \src: receiver.v:32.32-32.34
	wire<32> p_qi_5b_2_5d_;
	// \src: receiver.v:32.32-32.34
	wire<32> p_qi_5b_3_5d_;
	// \src: receiver.v:32.32-32.34
	wire<32> p_qi_5b_4_5d_;
	// \src: receiver.v:32.32-32.34
	wire<32> p_qi_5b_5_5d_;
	// \src: receiver.v:32.32-32.34
	wire<32> p_qi_5b_6_5d_;
	// \src: receiver.v:32.32-32.34
	wire<32> p_qi_5b_7_5d_;
	// \src: receiver.v:17.17-17.21
	/*output*/ value<256> p_qids;
	// \src: receiver.v:15.19-15.23
	/*output*/ wire<4> p_qlen;
	// \src: receiver.v:32.12-32.14
	wire<2> p_qo_5b_0_5d_;
	// \src: receiver.v:32.12-32.14
	wire<2> p_qo_5b_1_5d_;
	// \src: receiver.v:32.12-32.14
	wire<2> p_qo_5b_2_5d_;
	// \src: receiver.v:32.12-32.14
	wire<2> p_qo_5b_3_5d_;
	// \src: receiver.v:32.12-32.14
	wire<2> p_qo_5b_4_5d_;
	// \src: receiver.v:32.12-32.14
	wire<2> p_qo_5b_5_5d_;
	// \src: receiver.v:32.12-32.14
	wire<2> p_qo_5b_6_5d_;
	// \src: receiver.v:32.12-32.14
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
	// \src: receiver.v:30.38-30.50
	/*output*/ wire<8> p_transferbyte;
	// \src: receiver.v:29.51-29.61
	/*output*/ wire<32> p_transferid;
	// \src: receiver.v:28.62-28.75
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
		if (i_13_5c_fault_5b_31_3a_0_5d_.commit(observer)) changed = true;
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
		if (p_enqowner.commit(observer)) changed = true;
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
	// \src: receiver.v:39.2-120.5
	value<32> i_10_5c_fault_5b_31_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<32> i_11_5c_fault_5b_31_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<4> i_11_5c_tokens0_5b_3_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<4> i_11_5c_tokens1_5b_3_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<4> i_11_5c_tokens2_5b_3_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<4> i_11_5c_tokens3_5b_3_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<32> i_12_5c_fault_5b_31_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<4> i_13_5c_tokens0_5b_3_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<4> i_13_5c_tokens1_5b_3_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<4> i_13_5c_tokens2_5b_3_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<4> i_13_5c_tokens3_5b_3_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<32> i_14_5c_fault_5b_31_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<32> i_15_5c_fault_5b_31_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<4> i_15_5c_tokens0_5b_3_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<4> i_15_5c_tokens1_5b_3_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<4> i_15_5c_tokens2_5b_3_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<4> i_15_5c_tokens3_5b_3_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<32> i_16_5c_fault_5b_31_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<32> i_17_5c_fault_5b_31_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<4> i_17_5c_tokens0_5b_3_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<4> i_17_5c_tokens1_5b_3_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<4> i_17_5c_tokens2_5b_3_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<4> i_17_5c_tokens3_5b_3_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<32> i_18_5c_fault_5b_31_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<32> i_19_5c_fault_5b_31_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<4> i_19_5c_tokens0_5b_3_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<4> i_19_5c_tokens1_5b_3_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<4> i_19_5c_tokens2_5b_3_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<4> i_19_5c_tokens3_5b_3_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<32> i_20_5c_fault_5b_31_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<32> i_2_5c_bytes_5b_31_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<4> i_2_5c_evwu_5b_3_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<8> i_3_5c_bytes_5b_7_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<8> i_3_5c_bytezero_5b_7_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<16> i_3_5c_counts_5b_15_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<1> i_3_5c_enabled_5b_0_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<4> i_3_5c_evexpire_5b_3_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<1> i_3_5c_failed_5b_0_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<32> i_3_5c_idzero_5b_31_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<32> i_3_5c_nextid_5b_31_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<16> i_3_5c_outstanding_5b_15_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<2> i_3_5c_ownerone_5b_1_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<2> i_3_5c_ownerzero_5b_1_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<32> i_3_5c_qi_5b_0_5d__5b_31_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<32> i_3_5c_qi_5b_1_5d__5b_31_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<32> i_3_5c_qi_5b_2_5d__5b_31_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<32> i_3_5c_qi_5b_3_5d__5b_31_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<32> i_3_5c_qi_5b_4_5d__5b_31_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<32> i_3_5c_qi_5b_5_5d__5b_31_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<32> i_3_5c_qi_5b_6_5d__5b_31_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<32> i_3_5c_qi_5b_7_5d__5b_31_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<4> i_3_5c_qlen_5b_3_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<2> i_3_5c_qo_5b_0_5d__5b_1_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<2> i_3_5c_qo_5b_1_5d__5b_1_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<2> i_3_5c_qo_5b_2_5d__5b_1_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<2> i_3_5c_qo_5b_3_5d__5b_1_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<2> i_3_5c_qo_5b_4_5d__5b_1_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<2> i_3_5c_qo_5b_5_5d__5b_1_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<2> i_3_5c_qo_5b_6_5d__5b_1_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<2> i_3_5c_qo_5b_7_5d__5b_1_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<1> i_3_5c_rone_5b_0_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<1> i_3_5c_rzero_5b_0_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<4> i_3_5c_tokens0_5b_3_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<4> i_3_5c_tokens1_5b_3_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<4> i_3_5c_tokens2_5b_3_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<4> i_3_5c_tokens3_5b_3_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<4> i_3_5c_valid_5b_3_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<8> i_4_5c_bytes_5b_15_3a_8_5d_;
	// \src: receiver.v:39.2-120.5
	value<16> i_4_5c_counts_5b_31_3a_16_5d_;
	// \src: receiver.v:39.2-120.5
	value<32> i_4_5c_emitid_5b_31_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<2> i_4_5c_emitowner_5b_1_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<1> i_4_5c_enabled_5b_1_3a_1_5d_;
	// \src: receiver.v:39.2-120.5
	value<1> i_4_5c_evblock_5b_0_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<1> i_4_5c_evemit_5b_0_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<32> i_4_5c_fault_5b_31_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<2> i_4_5c_releaseowner_5b_1_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<1> i_4_5c_releasevalid_5b_0_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<1> i_4_5c_rone_5b_0_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<8> i_5_5c_bytes_5b_23_3a_16_5d_;
	// \src: receiver.v:39.2-120.5
	value<16> i_5_5c_counts_5b_47_3a_32_5d_;
	// \src: receiver.v:39.2-120.5
	value<1> i_5_5c_enabled_5b_2_3a_2_5d_;
	// \src: receiver.v:39.2-120.5
	value<32> i_5_5c_fault_5b_31_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<16> i_5_5c_outstanding_5b_15_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<4> i_5_5c_qlen_5b_3_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<1> i_5_5c_rzero_5b_0_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<4> i_5_5c_tokens0_5b_3_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<4> i_5_5c_tokens1_5b_3_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<4> i_5_5c_tokens2_5b_3_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<4> i_5_5c_tokens3_5b_3_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<8> i_6_5c_bytes_5b_31_3a_24_5d_;
	// \src: receiver.v:39.2-120.5
	value<16> i_6_5c_counts_5b_63_3a_48_5d_;
	// \src: receiver.v:39.2-120.5
	value<1> i_6_5c_enabled_5b_3_3a_3_5d_;
	// \src: receiver.v:39.2-120.5
	value<32> i_6_5c_fault_5b_31_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<2> i_6_5c_qo_5b_0_5d__5b_1_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<2> i_6_5c_qo_5b_1_5d__5b_1_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<2> i_6_5c_qo_5b_2_5d__5b_1_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<2> i_6_5c_qo_5b_3_5d__5b_1_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<2> i_6_5c_qo_5b_4_5d__5b_1_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<2> i_6_5c_qo_5b_5_5d__5b_1_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<2> i_6_5c_qo_5b_6_5d__5b_1_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<2> i_6_5c_qo_5b_7_5d__5b_1_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<64> i_7_5c_counts_5b_63_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<4> i_7_5c_enabled_5b_3_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<32> i_7_5c_fault_5b_31_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<4> i_7_5c_tokens0_5b_3_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<4> i_7_5c_tokens1_5b_3_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<4> i_7_5c_tokens2_5b_3_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<4> i_7_5c_tokens3_5b_3_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<32> i_8_5c_fault_5b_31_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<32> i_9_5c_fault_5b_31_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<4> i_9_5c_tokens0_5b_3_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<4> i_9_5c_tokens1_5b_3_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<4> i_9_5c_tokens2_5b_3_3a_0_5d_;
	// \src: receiver.v:39.2-120.5
	value<4> i_9_5c_tokens3_5b_3_3a_0_5d_;
	value<6> i_add_24_receiver_2e_v_3a_100_24_179__Y;
	value<17> i_add_24_receiver_2e_v_3a_115_24_254__Y;
	value<17> i_add_24_receiver_2e_v_3a_116_24_257__Y;
	value<17> i_add_24_receiver_2e_v_3a_117_24_260__Y;
	value<17> i_add_24_receiver_2e_v_3a_118_24_263__Y;
	value<6> i_add_24_receiver_2e_v_3a_74_24_112__Y;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_5591;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_5593;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_5595;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_5597;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_5599;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_5601;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_5603;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_5605;
	// \src: receiver.v:101.11-101.68
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5742;
	// \src: receiver.v:101.11-101.68
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5743;
	// \src: receiver.v:101.39-101.68
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5744;
	// \src: receiver.v:101.11-101.68
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5746;
	// \src: receiver.v:101.11-101.68
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5747;
	// \src: receiver.v:100.21-100.32
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5749;
	// \src: receiver.v:86.27-86.33
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5750;
	// \src: receiver.v:84.61-84.69
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5752;
	// \src: receiver.v:84.37-84.53
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5753;
	// \src: receiver.v:84.37-84.53
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5754;
	// \src: receiver.v:84.37-84.53
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5756;
	// \src: receiver.v:84.37-84.53
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5757;
	// \src: receiver.v:82.63-82.70
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5759;
	// \src: receiver.v:75.6-75.69
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5760;
	// \src: receiver.v:75.6-75.69
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5761;
	// \src: receiver.v:75.6-75.69
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5764;
	// \src: receiver.v:75.6-75.69
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5765;
	// \src: receiver.v:74.21-74.35
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5767;
	// \src: receiver.v:68.57-68.62
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5769;
	// \src: receiver.v:62.35-62.53
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5770;
	// \src: receiver.v:62.35-62.53
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5771;
	// \src: receiver.v:62.35-62.53
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5772;
	// \src: receiver.v:62.35-62.53
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5773;
	// \src: receiver.v:100.9-100.39
	value<1> i_eq_24_receiver_2e_v_3a_100_24_181__Y;
	// \src: receiver.v:58.7-58.17
	value<1> i_eq_24_receiver_2e_v_3a_58_24_75__Y;
	// \src: receiver.v:61.10-61.29
	value<1> i_eq_24_receiver_2e_v_3a_61_24_76__Y;
	// \src: receiver.v:61.10-61.29
	value<1> i_eq_24_receiver_2e_v_3a_61_24_80__Y;
	// \src: receiver.v:61.10-61.29
	value<1> i_eq_24_receiver_2e_v_3a_61_24_84__Y;
	// \src: receiver.v:61.10-61.29
	value<1> i_eq_24_receiver_2e_v_3a_61_24_88__Y;
	// \src: receiver.v:62.57-62.76
	value<1> i_eq_24_receiver_2e_v_3a_62_24_79__Y;
	// \src: receiver.v:62.57-62.76
	value<1> i_eq_24_receiver_2e_v_3a_62_24_83__Y;
	// \src: receiver.v:62.57-62.76
	value<1> i_eq_24_receiver_2e_v_3a_62_24_87__Y;
	// \src: receiver.v:62.57-62.76
	value<1> i_eq_24_receiver_2e_v_3a_62_24_91__Y;
	// \src: receiver.v:70.8-70.15
	value<1> i_ge_24_receiver_2e_v_3a_70_24_102__Y;
	// \src: receiver.v:52.15-52.34
	value<1> i_logic__and_24_receiver_2e_v_3a_52_24_61__Y;
	// \src: receiver.v:56.8-56.25
	value<1> i_logic__and_24_receiver_2e_v_3a_56_24_71__Y;
	// \src: receiver.v:56.8-56.25
	value<1> i_logic__and_24_receiver_2e_v_3a_56_24_72__Y;
	// \src: receiver.v:56.8-56.25
	value<1> i_logic__and_24_receiver_2e_v_3a_56_24_73__Y;
	// \src: receiver.v:56.8-56.25
	value<1> i_logic__and_24_receiver_2e_v_3a_56_24_74__Y;
	// \src: receiver.v:68.7-68.22
	value<1> i_logic__and_24_receiver_2e_v_3a_68_24_95__Y;
	// \src: receiver.v:78.7-78.37
	value<1> i_logic__and_24_receiver_2e_v_3a_78_24_133__Y;
	// \src: receiver.v:94.8-94.22
	value<1> i_logic__and_24_receiver_2e_v_3a_94_24_176__Y;
	// \src: receiver.v:91.9-91.23
	value<1> i_logic__or_24_receiver_2e_v_3a_91_24_174__Y;
	// \src: receiver.v:106.8-106.14
	value<1> i_lt_24_receiver_2e_v_3a_106_24_197__Y;
	// \src: receiver.v:106.8-106.14
	value<1> i_lt_24_receiver_2e_v_3a_106_24_202__Y;
	// \src: receiver.v:106.8-106.14
	value<1> i_lt_24_receiver_2e_v_3a_106_24_207__Y;
	// \src: receiver.v:106.8-106.14
	value<1> i_lt_24_receiver_2e_v_3a_106_24_212__Y;
	// \src: receiver.v:106.8-106.14
	value<1> i_lt_24_receiver_2e_v_3a_106_24_217__Y;
	// \src: receiver.v:106.8-106.14
	value<1> i_lt_24_receiver_2e_v_3a_106_24_222__Y;
	// \src: receiver.v:106.8-106.14
	value<1> i_lt_24_receiver_2e_v_3a_106_24_227__Y;
	// \src: receiver.v:106.8-106.14
	value<1> i_lt_24_receiver_2e_v_3a_106_24_232__Y;
	// \src: receiver.v:67.7-67.11
	value<1> i_lt_24_receiver_2e_v_3a_67_24_92__Y;
	// \src: receiver.v:101.11-101.68
	value<33> i_neg_24_receiver_2e_v_3a_101_24_186__Y;
	// \src: receiver.v:75.6-75.69
	value<33> i_neg_24_receiver_2e_v_3a_75_24_118__Y;
	// \src: receiver.v:84.6-84.36
	value<3> i_neg_24_receiver_2e_v_3a_84_24_150__Y;
	// \src: receiver.v:84.54-84.76
	value<33> i_neg_24_receiver_2e_v_3a_84_24_162__Y;
	value<1> i_procmux_24_1006__CMP;
	value<1> i_procmux_24_1007__CMP;
	value<1> i_procmux_24_1008__CMP;
	value<1> i_procmux_24_1009__CMP;
	value<1> i_procmux_24_1056__CMP;
	value<1> i_procmux_24_1057__CMP;
	value<1> i_procmux_24_1058__CMP;
	value<1> i_procmux_24_1059__CMP;
	value<1> i_procmux_24_1148__CMP;
	value<1> i_procmux_24_1149__CMP;
	value<1> i_procmux_24_1150__CMP;
	value<1> i_procmux_24_1151__CMP;
	value<1> i_procmux_24_2677__CMP;
	value<1> i_procmux_24_2678__CMP;
	value<1> i_procmux_24_2679__CMP;
	value<1> i_procmux_24_2680__CMP;
	value<1> i_procmux_24_2681__CMP;
	value<1> i_procmux_24_2682__CMP;
	value<1> i_procmux_24_2683__CMP;
	value<1> i_procmux_24_2684__CMP;
	value<1> i_procmux_24_320__CMP;
	value<1> i_procmux_24_321__CMP;
	value<1> i_procmux_24_322__CMP;
	value<1> i_procmux_24_323__CMP;
	value<1> i_procmux_24_412__CMP;
	value<1> i_procmux_24_413__CMP;
	value<1> i_procmux_24_414__CMP;
	value<1> i_procmux_24_415__CMP;
	value<32> i_procmux_24_4400__Y;
	value<1> i_procmux_24_504__CMP;
	value<1> i_procmux_24_505__CMP;
	value<1> i_procmux_24_506__CMP;
	value<1> i_procmux_24_507__CMP;
	value<1> i_procmux_24_596__CMP;
	value<1> i_procmux_24_597__CMP;
	value<1> i_procmux_24_598__CMP;
	value<1> i_procmux_24_599__CMP;
	value<1> i_procmux_24_688__CMP;
	value<1> i_procmux_24_689__CMP;
	value<1> i_procmux_24_690__CMP;
	value<1> i_procmux_24_691__CMP;
	value<1> i_procmux_24_780__CMP;
	value<1> i_procmux_24_781__CMP;
	value<1> i_procmux_24_782__CMP;
	value<1> i_procmux_24_783__CMP;
	value<1> i_procmux_24_872__CMP;
	value<1> i_procmux_24_873__CMP;
	value<1> i_procmux_24_874__CMP;
	value<1> i_procmux_24_875__CMP;
	// \src: receiver.v:100.20-100.36
	value<4> i_shiftx_24_receiver_2e_v_3a_100_24_180__Y;
	// \src: receiver.v:74.20-74.39
	value<4> i_shiftx_24_receiver_2e_v_3a_74_24_113__Y;
	// \src: receiver.v:80.14-80.21
	value<1> i_shiftx_24_receiver_2e_v_3a_80_24_137__Y;
	// \src: receiver.v:82.62-82.74
	value<8> i_shiftx_24_receiver_2e_v_3a_82_24_144__Y;
	// connection
	i_procmux_24_4400__Y.slice<31,2>() = p_fault.curr.slice<31,2>().val();
	// connection
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5767.slice<31,5>() = value<27>{0u};
	// connection
	i_12_5c_fault_5b_31_3a_0_5d_.slice<31,2>() = p_fault.curr.slice<31,2>().val();
	// connection
	i_11_5c_fault_5b_31_3a_0_5d_.slice<31,2>() = p_fault.curr.slice<31,2>().val();
	// connection
	i_10_5c_fault_5b_31_3a_0_5d_.slice<31,2>() = p_fault.curr.slice<31,2>().val();
	// connection
	i_9_5c_fault_5b_31_3a_0_5d_.slice<31,2>() = p_fault.curr.slice<31,2>().val();
	// connection
	i_8_5c_fault_5b_31_3a_0_5d_.slice<31,2>() = p_fault.curr.slice<31,2>().val();
	// connection
	i_7_5c_fault_5b_31_3a_0_5d_.slice<31,2>() = p_fault.curr.slice<31,2>().val();
	// connection
	i_6_5c_fault_5b_31_3a_0_5d_.slice<31,2>() = p_fault.curr.slice<31,2>().val();
	// connection
	i_5_5c_fault_5b_31_3a_0_5d_.slice<31,2>() = p_fault.curr.slice<31,2>().val();
	// \src: receiver.v:67.7-67.11
	// cell $lt$receiver.v:67$92
	i_lt_24_receiver_2e_v_3a_67_24_92__Y = lt_uu<1>(p_fp.curr, value<3>{0x4u});
	// \src: receiver.v:68.57-68.62
	// cell $sub$receiver.v:68$96
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5769.slice<1,0>() = sub_uu<2>(p_fp.curr.slice<1,0>().val(), value<1>{0u});
	// \src: receiver.v:56.8-56.25
	// cell $logic_and$receiver.v:56$74
	i_logic__and_24_receiver_2e_v_3a_56_24_74__Y = logic_and<1>(p_wu.slice<3>().val(), p_valid.curr.slice<3>().val());
	// \src: receiver.v:56.8-56.25
	// cell $logic_and$receiver.v:56$73
	i_logic__and_24_receiver_2e_v_3a_56_24_73__Y = logic_and<1>(p_wu.slice<2>().val(), p_valid.curr.slice<2>().val());
	// \src: receiver.v:56.8-56.25
	// cell $logic_and$receiver.v:56$72
	i_logic__and_24_receiver_2e_v_3a_56_24_72__Y = logic_and<1>(p_wu.slice<1>().val(), p_valid.curr.slice<1>().val());
	// \src: receiver.v:56.8-56.25
	// cell $logic_and$receiver.v:56$71
	i_logic__and_24_receiver_2e_v_3a_56_24_71__Y = logic_and<1>(p_wu.slice<0>().val(), p_valid.curr.slice<0>().val());
	// \src: receiver.v:58.7-58.17
	// cell $eq$receiver.v:58$75
	i_eq_24_receiver_2e_v_3a_58_24_75__Y = eq_uu<1>(p_pp.curr, p_cfgphi);
	// \src: receiver.v:70.8-70.15
	// cell $ge$receiver.v:70$102
	i_ge_24_receiver_2e_v_3a_70_24_102__Y = ge_uu<1>(p_qlen.curr, value<4>{0x8u});
	// cells $logic_and$receiver.v:52$61 $logic_not$receiver.v:52$59 $eq$receiver.v:52$60
	i_logic__and_24_receiver_2e_v_3a_52_24_61__Y = logic_and<1>(logic_not<1>(p_failed.curr), logic_not<1>(p_fault.curr));
	// cells $logic_and$receiver.v:68$95 $ge$receiver.v:68$93 $lt$receiver.v:68$94
	i_logic__and_24_receiver_2e_v_3a_68_24_95__Y = logic_and<1>(ge_uu<1>(p_fp.curr, value<6>{0x28u}), lt_uu<1>(p_fp.curr, value<6>{0x2cu}));
	// cells $procmux$4576 $procmux$4573 $procmux$4571
	i_6_5c_enabled_5b_3_3a_3_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_logic__and_24_receiver_2e_v_3a_56_24_74__Y ? value<1>{0x1u} : p_enabled.curr.slice<3>().val()) : value<1>{0u}));
	// cells $procmux$4567 $procmux$4564 $procmux$4562
	i_6_5c_counts_5b_63_3a_48_5d_ = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_logic__and_24_receiver_2e_v_3a_56_24_74__Y ? p_cfgk : p_counts.curr.slice<63,48>().val()) : value<16>{0u}));
	// cells $procmux$4612 $procmux$4609 $procmux$4607
	i_5_5c_enabled_5b_2_3a_2_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_logic__and_24_receiver_2e_v_3a_56_24_73__Y ? value<1>{0x1u} : p_enabled.curr.slice<2>().val()) : value<1>{0u}));
	// cells $procmux$4603 $procmux$4600 $procmux$4598
	i_5_5c_counts_5b_47_3a_32_5d_ = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_logic__and_24_receiver_2e_v_3a_56_24_73__Y ? p_cfgk : p_counts.curr.slice<47,32>().val()) : value<16>{0u}));
	// cells $procmux$4648 $procmux$4645 $procmux$4643
	i_4_5c_enabled_5b_1_3a_1_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_logic__and_24_receiver_2e_v_3a_56_24_72__Y ? value<1>{0x1u} : p_enabled.curr.slice<1>().val()) : value<1>{0u}));
	// cells $procmux$4639 $procmux$4636 $procmux$4634
	i_4_5c_counts_5b_31_3a_16_5d_ = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_logic__and_24_receiver_2e_v_3a_56_24_72__Y ? p_cfgk : p_counts.curr.slice<31,16>().val()) : value<16>{0u}));
	// cells $procmux$4684 $procmux$4681 $procmux$4679
	i_3_5c_enabled_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_logic__and_24_receiver_2e_v_3a_56_24_71__Y ? value<1>{0x1u} : p_enabled.curr.slice<0>().val()) : value<1>{0u}));
	// cells $procmux$4675 $procmux$4672 $procmux$4670
	i_3_5c_counts_5b_15_3a_0_5d_ = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_logic__and_24_receiver_2e_v_3a_56_24_71__Y ? p_cfgk : p_counts.curr.slice<15,0>().val()) : value<16>{0u}));
	// cells $procmux$3605 $procmux$3602 $procmux$3600 $procmux$3618
	i_4_5c_releaseowner_5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_logic__and_24_receiver_2e_v_3a_68_24_95__Y ? i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5769.slice<1,0>().val() : (i_lt_24_receiver_2e_v_3a_67_24_92__Y ? p_fp.curr.slice<1,0>().val() : value<2>{0u})) : value<2>{0u}));
	// cells $procmux$3614 $procmux$3611 $procmux$3609 $procmux$3627
	i_4_5c_releasevalid_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_logic__and_24_receiver_2e_v_3a_68_24_95__Y ? value<1>{0x1u} : (i_lt_24_receiver_2e_v_3a_67_24_92__Y ? value<1>{0x1u} : value<1>{0u})) : value<1>{0u}));
	// \src: receiver.v:61.10-61.29
	// cell $eq$receiver.v:61$88
	i_eq_24_receiver_2e_v_3a_61_24_88__Y = logic_not<1>(i_6_5c_counts_5b_63_3a_48_5d_);
	// \src: receiver.v:61.10-61.29
	// cell $eq$receiver.v:61$84
	i_eq_24_receiver_2e_v_3a_61_24_84__Y = logic_not<1>(i_5_5c_counts_5b_47_3a_32_5d_);
	// \src: receiver.v:61.10-61.29
	// cell $eq$receiver.v:61$80
	i_eq_24_receiver_2e_v_3a_61_24_80__Y = logic_not<1>(i_4_5c_counts_5b_31_3a_16_5d_);
	// \src: receiver.v:61.10-61.29
	// cell $eq$receiver.v:61$76
	i_eq_24_receiver_2e_v_3a_61_24_76__Y = logic_not<1>(i_3_5c_counts_5b_15_3a_0_5d_);
	// \src: receiver.v:75.49-75.63
	// cell $mul$receiver.v:75$122
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5767.slice<4,0>() = mul_uu<5>(value<3>{0x4u}, i_4_5c_releaseowner_5b_1_3a_0_5d_);
	// \full_case: 1
	// \src: receiver.v:61.10-61.29|receiver.v:61.7-62.128
	// cell $procmux$4250
	i_6_5c_fault_5b_31_3a_0_5d_.slice<1,0>() = (i_eq_24_receiver_2e_v_3a_61_24_76__Y ? value<1>{0x1u}.concat(p_fault.curr.slice<0>()).val() : p_fault.curr.slice<1,0>().val());
	// \src: receiver.v:75.48-75.67
	// cell $add$receiver.v:75$123
	i_add_24_receiver_2e_v_3a_74_24_112__Y = add_uu<6>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5767.slice<4,0>().val(), value<1>{0u});
	// \full_case: 1
	// \src: receiver.v:60.9-60.19|receiver.v:60.6-63.9
	// cell $procmux$4336
	i_5_5c_fault_5b_31_3a_0_5d_.slice<1,0>() = (i_3_5c_enabled_5b_0_3a_0_5d_ ? i_6_5c_fault_5b_31_3a_0_5d_.slice<1,0>().val() : p_fault.curr.slice<1,0>().val());
	// \src: receiver.v:75.48-75.67
	// cell $shiftx$receiver.v:75$124
	i_shiftx_24_receiver_2e_v_3a_74_24_113__Y = shiftx_us<4>(p_outstanding.curr, value<1>{0u}.concat(i_add_24_receiver_2e_v_3a_74_24_112__Y).val());
	// \full_case: 1
	// \src: receiver.v:61.10-61.29|receiver.v:61.7-62.128
	// cell $procmux$4061
	i_8_5c_fault_5b_31_3a_0_5d_.slice<1,0>() = (i_eq_24_receiver_2e_v_3a_61_24_80__Y ? value<1>{0x1u}.concat(i_5_5c_fault_5b_31_3a_0_5d_.slice<0>()).val() : i_5_5c_fault_5b_31_3a_0_5d_.slice<1,0>().val());
	// \full_case: 1
	// \src: receiver.v:60.9-60.19|receiver.v:60.6-63.9
	// cell $procmux$4147
	i_7_5c_fault_5b_31_3a_0_5d_.slice<1,0>() = (i_4_5c_enabled_5b_1_3a_1_5d_ ? i_8_5c_fault_5b_31_3a_0_5d_.slice<1,0>().val() : i_5_5c_fault_5b_31_3a_0_5d_.slice<1,0>().val());
	// \full_case: 1
	// \src: receiver.v:61.10-61.29|receiver.v:61.7-62.128
	// cell $procmux$3872
	i_10_5c_fault_5b_31_3a_0_5d_.slice<1,0>() = (i_eq_24_receiver_2e_v_3a_61_24_84__Y ? value<1>{0x1u}.concat(i_7_5c_fault_5b_31_3a_0_5d_.slice<0>()).val() : i_7_5c_fault_5b_31_3a_0_5d_.slice<1,0>().val());
	// \full_case: 1
	// \src: receiver.v:60.9-60.19|receiver.v:60.6-63.9
	// cell $procmux$3958
	i_9_5c_fault_5b_31_3a_0_5d_.slice<1,0>() = (i_5_5c_enabled_5b_2_3a_2_5d_ ? i_10_5c_fault_5b_31_3a_0_5d_.slice<1,0>().val() : i_7_5c_fault_5b_31_3a_0_5d_.slice<1,0>().val());
	// \full_case: 1
	// \src: receiver.v:61.10-61.29|receiver.v:61.7-62.128
	// cell $procmux$3683
	i_12_5c_fault_5b_31_3a_0_5d_.slice<1,0>() = (i_eq_24_receiver_2e_v_3a_61_24_88__Y ? value<1>{0x1u}.concat(i_9_5c_fault_5b_31_3a_0_5d_.slice<0>()).val() : i_9_5c_fault_5b_31_3a_0_5d_.slice<1,0>().val());
	// \full_case: 1
	// \src: receiver.v:60.9-60.19|receiver.v:60.6-63.9
	// cell $procmux$3769
	i_11_5c_fault_5b_31_3a_0_5d_.slice<1,0>() = (i_6_5c_enabled_5b_3_3a_3_5d_ ? i_12_5c_fault_5b_31_3a_0_5d_.slice<1,0>().val() : i_9_5c_fault_5b_31_3a_0_5d_.slice<1,0>().val());
	// \full_case: 1
	// \src: receiver.v:58.7-58.17|receiver.v:58.4-65.7
	// cell $procmux$4400
	i_procmux_24_4400__Y.slice<1,0>() = (i_eq_24_receiver_2e_v_3a_58_24_75__Y ? i_11_5c_fault_5b_31_3a_0_5d_.slice<1,0>().val() : p_fault.curr.slice<1,0>().val());
	// cells $procmux$4405 $procmux$4402
	i_13_5c_fault_5b_31_3a_0_5d_.next.slice<31,4>().concat(i_4_5c_fault_5b_31_3a_0_5d_.slice<3,0>()) = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? p_fault.curr.slice<31,2>().concat(i_procmux_24_4400__Y.slice<1,0>()).val() : value<32>{0u}));
	// connection
	i_4_5c_fault_5b_31_3a_0_5d_.slice<31,4>() = i_13_5c_fault_5b_31_3a_0_5d_.curr.slice<31,4>().val();
	// cells $procmux$2662 $eq$receiver.v:74$114
	i_15_5c_fault_5b_31_3a_0_5d_.slice<3,0>() = (eq_uu<1>(i_shiftx_24_receiver_2e_v_3a_74_24_113__Y, value<4>{0xfu}) ? value<1>{0x1u}.concat(i_4_5c_fault_5b_31_3a_0_5d_.slice<2,0>()).val() : i_4_5c_fault_5b_31_3a_0_5d_.slice<3,0>().val());
	// connection
	i_15_5c_fault_5b_31_3a_0_5d_.slice<31,4>() = i_13_5c_fault_5b_31_3a_0_5d_.curr.slice<31,4>().val();
	// \full_case: 1
	// \src: receiver.v:70.8-70.15|receiver.v:70.5-76.8
	// cell $procmux$3013
	i_14_5c_fault_5b_31_3a_0_5d_.slice<3,0>() = (i_ge_24_receiver_2e_v_3a_70_24_102__Y ? i_4_5c_fault_5b_31_3a_0_5d_.slice<3>().concat(value<1>{0x1u}).concat(i_4_5c_fault_5b_31_3a_0_5d_.slice<1,0>()).val() : i_15_5c_fault_5b_31_3a_0_5d_.slice<3,0>().val());
	// connection
	i_14_5c_fault_5b_31_3a_0_5d_.slice<31,4>() = i_13_5c_fault_5b_31_3a_0_5d_.curr.slice<31,4>().val();
	// \full_case: 1
	// \src: receiver.v:69.7-69.19|receiver.v:69.4-77.7
	// cell $procmux$3564
	i_13_5c_fault_5b_31_3a_0_5d_.next.slice<3,0>() = (i_4_5c_releasevalid_5b_0_3a_0_5d_ ? i_14_5c_fault_5b_31_3a_0_5d_.slice<3,0>().val() : i_4_5c_fault_5b_31_3a_0_5d_.slice<3,0>().val());
	// \src: receiver.v:62.35-62.53
	// cell $sub$receiver.v:62$90
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5770.slice<15,0>() = sub_uu<16>(i_6_5c_counts_5b_63_3a_48_5d_, value<1>{0x1u});
	// \src: receiver.v:62.35-62.53
	// cell $sub$receiver.v:62$78
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5773.slice<15,0>() = sub_uu<16>(i_3_5c_counts_5b_15_3a_0_5d_, value<1>{0x1u});
	// \src: receiver.v:62.35-62.53
	// cell $sub$receiver.v:62$82
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5772.slice<15,0>() = sub_uu<16>(i_4_5c_counts_5b_31_3a_16_5d_, value<1>{0x1u});
	// \src: receiver.v:62.35-62.53
	// cell $sub$receiver.v:62$86
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5771.slice<15,0>() = sub_uu<16>(i_5_5c_counts_5b_47_3a_32_5d_, value<1>{0x1u});
	// \src: receiver.v:62.57-62.76
	// cell $eq$receiver.v:62$91
	i_eq_24_receiver_2e_v_3a_62_24_91__Y = logic_not<1>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5770.slice<15,0>().val());
	// \src: receiver.v:62.57-62.76
	// cell $eq$receiver.v:62$79
	i_eq_24_receiver_2e_v_3a_62_24_79__Y = logic_not<1>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5773.slice<15,0>().val());
	// \src: receiver.v:62.57-62.76
	// cell $eq$receiver.v:62$83
	i_eq_24_receiver_2e_v_3a_62_24_83__Y = logic_not<1>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5772.slice<15,0>().val());
	// \src: receiver.v:62.57-62.76
	// cell $eq$receiver.v:62$87
	i_eq_24_receiver_2e_v_3a_62_24_87__Y = logic_not<1>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5771.slice<15,0>().val());
	// \full_case: 1
	// \src: receiver.v:73.6-73.27
	// cell $procmux$2998_CMP0
	i_procmux_24_2683__CMP = eq_uu<1>(p_qlen.curr.slice<2,0>().val(), value<1>{0x1u});
	// \full_case: 1
	// \src: receiver.v:73.6-73.27
	// cell $procmux$2997_CMP0
	i_procmux_24_2682__CMP = eq_uu<1>(p_qlen.curr.slice<2,0>().val(), value<2>{0x2u});
	// \full_case: 1
	// \src: receiver.v:73.6-73.27
	// cell $procmux$2996_CMP0
	i_procmux_24_2681__CMP = eq_uu<1>(p_qlen.curr.slice<2,0>().val(), value<2>{0x3u});
	// \full_case: 1
	// \src: receiver.v:73.6-73.27
	// cell $procmux$2995_CMP0
	i_procmux_24_2680__CMP = eq_uu<1>(p_qlen.curr.slice<2,0>().val(), value<3>{0x4u});
	// \full_case: 1
	// \src: receiver.v:73.6-73.27
	// cell $procmux$2994_CMP0
	i_procmux_24_2679__CMP = eq_uu<1>(p_qlen.curr.slice<2,0>().val(), value<3>{0x5u});
	// \full_case: 1
	// \src: receiver.v:73.6-73.27
	// cell $procmux$2993_CMP0
	i_procmux_24_2678__CMP = eq_uu<1>(p_qlen.curr.slice<2,0>().val(), value<3>{0x6u});
	// \full_case: 1
	// \src: receiver.v:73.6-73.27
	// cell $procmux$2992_CMP0
	i_procmux_24_2677__CMP = eq_uu<1>(p_qlen.curr.slice<2,0>().val(), value<3>{0x7u});
	// \full_case: 1
	// \src: receiver.v:73.6-73.27
	// cell $procmux$2999_CMP0
	i_procmux_24_2684__CMP = logic_not<1>(p_qlen.curr.slice<2,0>().val());
	// cell $auto$opt_reduce.cc:131:opt_pmux$5618
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_5603 = reduce_or<1>(i_procmux_24_2683__CMP.concat(i_procmux_24_2682__CMP).concat(i_procmux_24_2681__CMP).concat(i_procmux_24_2680__CMP).concat(i_procmux_24_2679__CMP).concat(i_procmux_24_2678__CMP).concat(i_procmux_24_2677__CMP).val());
	// cell $auto$opt_reduce.cc:131:opt_pmux$5700
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_5605 = reduce_or<1>(i_procmux_24_2684__CMP.concat(i_procmux_24_2682__CMP).concat(i_procmux_24_2681__CMP).concat(i_procmux_24_2680__CMP).concat(i_procmux_24_2679__CMP).concat(i_procmux_24_2678__CMP).concat(i_procmux_24_2677__CMP).val());
	// cells $procmux$4531 $procmux$4528 $procmux$4526 $procmux$3805 $procmux$3743 $procmux$3665
	i_3_5c_valid_5b_3_3a_0_5d_.slice<3>() = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_eq_24_receiver_2e_v_3a_58_24_75__Y ? (i_6_5c_enabled_5b_3_3a_3_5d_ ? (i_eq_24_receiver_2e_v_3a_61_24_88__Y ? p_valid.curr.slice<3>().val() : (i_eq_24_receiver_2e_v_3a_62_24_91__Y ? value<1>{0u} : p_valid.curr.slice<3>().val())) : p_valid.curr.slice<3>().val()) : p_valid.curr.slice<3>().val()) : value<1>{0u}));
	// cells $procmux$4504 $procmux$4501 $procmux$4499 $procmux$4372 $procmux$4310 $procmux$4232
	i_3_5c_valid_5b_3_3a_0_5d_.slice<0>() = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_eq_24_receiver_2e_v_3a_58_24_75__Y ? (i_3_5c_enabled_5b_0_3a_0_5d_ ? (i_eq_24_receiver_2e_v_3a_61_24_76__Y ? p_valid.curr.slice<0>().val() : (i_eq_24_receiver_2e_v_3a_62_24_79__Y ? value<1>{0u} : p_valid.curr.slice<0>().val())) : p_valid.curr.slice<0>().val()) : p_valid.curr.slice<0>().val()) : value<1>{0u}));
	// cells $procmux$4468 $procmux$4465 $procmux$4463 $procmux$4183 $procmux$4121 $procmux$4043
	i_3_5c_valid_5b_3_3a_0_5d_.slice<1>() = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_eq_24_receiver_2e_v_3a_58_24_75__Y ? (i_4_5c_enabled_5b_1_3a_1_5d_ ? (i_eq_24_receiver_2e_v_3a_61_24_80__Y ? p_valid.curr.slice<1>().val() : (i_eq_24_receiver_2e_v_3a_62_24_83__Y ? value<1>{0u} : p_valid.curr.slice<1>().val())) : p_valid.curr.slice<1>().val()) : p_valid.curr.slice<1>().val()) : value<1>{0u}));
	// cells $procmux$4432 $procmux$4429 $procmux$4427 $procmux$3994 $procmux$3932 $procmux$3854
	i_3_5c_valid_5b_3_3a_0_5d_.slice<2>() = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_eq_24_receiver_2e_v_3a_58_24_75__Y ? (i_5_5c_enabled_5b_2_3a_2_5d_ ? (i_eq_24_receiver_2e_v_3a_61_24_84__Y ? p_valid.curr.slice<2>().val() : (i_eq_24_receiver_2e_v_3a_62_24_87__Y ? value<1>{0u} : p_valid.curr.slice<2>().val())) : p_valid.curr.slice<2>().val()) : p_valid.curr.slice<2>().val()) : value<1>{0u}));
	// cells $procmux$3524 $procmux$3521 $procmux$3519 $procmux$3253 $procmux$2844
	i_3_5c_qo_5b_0_5d__5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_4_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_70_24_102__Y ? p_qo_5b_0_5d_.curr : (i_procmux_24_2684__CMP ? i_4_5c_releaseowner_5b_1_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_5603 ? p_qo_5b_0_5d_.curr : value<2>{0u}))) : p_qo_5b_0_5d_.curr) : value<2>{0u}));
	// cells $procmux$3587 $procmux$3584 $procmux$3582 $procmux$3325 $add$receiver.v:73$109
	i_3_5c_qlen_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_4_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_70_24_102__Y ? p_qlen.curr : add_uu<4>(p_qlen.curr, value<1>{0x1u})) : p_qlen.curr) : value<4>{0u}));
	// \src: receiver.v:80.14-80.21
	// cell $shiftx$receiver.v:80$137
	i_shiftx_24_receiver_2e_v_3a_80_24_137__Y = shiftx_uu<1>(i_3_5c_valid_5b_3_3a_0_5d_, i_3_5c_qo_5b_0_5d__5b_1_3a_0_5d_);
	// cells $procmux$3510 $procmux$3241 $procmux$2991
	i_3_5c_qo_5b_1_5d__5b_1_3a_0_5d_ = (i_4_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_70_24_102__Y ? p_qo_5b_1_5d_.curr : (i_procmux_24_2683__CMP ? i_4_5c_releaseowner_5b_1_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_5605 ? p_qo_5b_1_5d_.curr : value<2>{0u}))) : p_qo_5b_1_5d_.curr);
	// cells $logic_and$receiver.v:78$133 $logic_and$receiver.v:78$131 $eq$receiver.v:78$129 $logic_not$receiver.v:78$130 $ne$receiver.v:78$132
	i_logic__and_24_receiver_2e_v_3a_78_24_133__Y = logic_and<1>(logic_and<1>(logic_not<1>(p_cp.curr), logic_not<1>(p_rzero.curr)), reduce_bool<1>(i_3_5c_qlen_5b_3_3a_0_5d_));
	// cell $auto$opt_reduce.cc:131:opt_pmux$5606
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_5591 = reduce_or<1>(i_procmux_24_2684__CMP.concat(i_procmux_24_2683__CMP).concat(i_procmux_24_2681__CMP).concat(i_procmux_24_2680__CMP).concat(i_procmux_24_2679__CMP).concat(i_procmux_24_2678__CMP).concat(i_procmux_24_2677__CMP).val());
	// \src: receiver.v:86.27-86.33
	// cell $sub$receiver.v:86$169
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5750.slice<3,0>() = sub_uu<4>(i_3_5c_qlen_5b_3_3a_0_5d_, value<1>{0x1u});
	// cells $procmux$2450 $procmux$2447 $procmux$2445 $procmux$2107
	i_6_5c_qo_5b_0_5d__5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_logic__and_24_receiver_2e_v_3a_78_24_133__Y ? (i_shiftx_24_receiver_2e_v_3a_80_24_137__Y ? i_3_5c_qo_5b_1_5d__5b_1_3a_0_5d_ : i_3_5c_qo_5b_0_5d__5b_1_3a_0_5d_) : i_3_5c_qo_5b_0_5d__5b_1_3a_0_5d_) : value<2>{0u}));
	// cells $procmux$3501 $procmux$3229 $procmux$2970
	i_3_5c_qo_5b_2_5d__5b_1_3a_0_5d_ = (i_4_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_70_24_102__Y ? p_qo_5b_2_5d_.curr : (i_procmux_24_2682__CMP ? i_4_5c_releaseowner_5b_1_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_5591 ? p_qo_5b_2_5d_.curr : value<2>{0u}))) : p_qo_5b_2_5d_.curr);
	// \full_case: 1
	// \src: receiver.v:107.37-107.37|receiver.v:107.6-107.104
	// cell $procmux$1192_CMP0
	i_procmux_24_1150__CMP = eq_uu<1>(i_6_5c_qo_5b_0_5d__5b_1_3a_0_5d_, value<1>{0x1u});
	// \full_case: 1
	// \src: receiver.v:107.57-107.57|receiver.v:107.6-107.104
	// cell $procmux$1191_CMP0
	i_procmux_24_1149__CMP = eq_uu<1>(i_6_5c_qo_5b_0_5d__5b_1_3a_0_5d_, value<2>{0x2u});
	// \full_case: 1
	// \src: receiver.v:107.77-107.77|receiver.v:107.6-107.104
	// cell $procmux$1190_CMP0
	i_procmux_24_1148__CMP = eq_uu<1>(i_6_5c_qo_5b_0_5d__5b_1_3a_0_5d_, value<2>{0x3u});
	// \full_case: 1
	// \src: receiver.v:107.17-107.17|receiver.v:107.6-107.104
	// cell $procmux$1193_CMP0
	i_procmux_24_1151__CMP = logic_not<1>(i_6_5c_qo_5b_0_5d__5b_1_3a_0_5d_);
	// cells $procmux$2612 $procmux$2609 $procmux$2607 $procmux$2275
	i_5_5c_qlen_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_logic__and_24_receiver_2e_v_3a_78_24_133__Y ? (i_shiftx_24_receiver_2e_v_3a_80_24_137__Y ? i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5750.slice<3,0>().val() : i_3_5c_qlen_5b_3_3a_0_5d_) : i_3_5c_qlen_5b_3_3a_0_5d_) : value<4>{0u}));
	// cell $auto$opt_reduce.cc:131:opt_pmux$5608
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_5593 = reduce_or<1>(i_procmux_24_2684__CMP.concat(i_procmux_24_2683__CMP).concat(i_procmux_24_2682__CMP).concat(i_procmux_24_2680__CMP).concat(i_procmux_24_2679__CMP).concat(i_procmux_24_2678__CMP).concat(i_procmux_24_2677__CMP).val());
	// \src: receiver.v:106.8-106.14
	// cell $lt$receiver.v:106$197
	i_lt_24_receiver_2e_v_3a_106_24_197__Y = lt_uu<1>(value<1>{0u}, i_5_5c_qlen_5b_3_3a_0_5d_);
	// cells $procmux$2441 $procmux$2438 $procmux$2436 $procmux$2095
	i_6_5c_qo_5b_1_5d__5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_logic__and_24_receiver_2e_v_3a_78_24_133__Y ? (i_shiftx_24_receiver_2e_v_3a_80_24_137__Y ? i_3_5c_qo_5b_2_5d__5b_1_3a_0_5d_ : i_3_5c_qo_5b_1_5d__5b_1_3a_0_5d_) : i_3_5c_qo_5b_1_5d__5b_1_3a_0_5d_) : value<2>{0u}));
	// cells $procmux$3492 $procmux$3217 $procmux$2949
	i_3_5c_qo_5b_3_5d__5b_1_3a_0_5d_ = (i_4_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_70_24_102__Y ? p_qo_5b_3_5d_.curr : (i_procmux_24_2681__CMP ? i_4_5c_releaseowner_5b_1_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_5593 ? p_qo_5b_3_5d_.curr : value<2>{0u}))) : p_qo_5b_3_5d_.curr);
	// \full_case: 1
	// \src: receiver.v:107.37-107.37|receiver.v:107.6-107.104
	// cell $procmux$1100_CMP0
	i_procmux_24_1058__CMP = eq_uu<1>(i_6_5c_qo_5b_1_5d__5b_1_3a_0_5d_, value<1>{0x1u});
	// \full_case: 1
	// \src: receiver.v:107.57-107.57|receiver.v:107.6-107.104
	// cell $procmux$1099_CMP0
	i_procmux_24_1057__CMP = eq_uu<1>(i_6_5c_qo_5b_1_5d__5b_1_3a_0_5d_, value<2>{0x2u});
	// \full_case: 1
	// \src: receiver.v:107.77-107.77|receiver.v:107.6-107.104
	// cell $procmux$1098_CMP0
	i_procmux_24_1056__CMP = eq_uu<1>(i_6_5c_qo_5b_1_5d__5b_1_3a_0_5d_, value<2>{0x3u});
	// cells $procmux$1235 $procmux$1232 $procmux$1230 $procmux$1147 $auto$opt_reduce.cc:131:opt_pmux$5626
	i_3_5c_tokens0_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_lt_24_receiver_2e_v_3a_106_24_197__Y ? (i_procmux_24_1151__CMP ? value<4>{0x1u} : (reduce_or<1>(i_procmux_24_1150__CMP.concat(i_procmux_24_1149__CMP).concat(i_procmux_24_1148__CMP).val()) ? value<4>{0u} : value<4>{0u})) : value<4>{0u}) : value<4>{0u}));
	// \full_case: 1
	// \src: receiver.v:107.17-107.17|receiver.v:107.6-107.104
	// cell $procmux$1101_CMP0
	i_procmux_24_1059__CMP = logic_not<1>(i_6_5c_qo_5b_1_5d__5b_1_3a_0_5d_);
	// cells $procmux$1226 $procmux$1223 $procmux$1221 $procmux$1189 $auto$opt_reduce.cc:131:opt_pmux$5620
	i_3_5c_tokens1_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_lt_24_receiver_2e_v_3a_106_24_197__Y ? (i_procmux_24_1150__CMP ? value<4>{0x1u} : (reduce_or<1>(i_procmux_24_1151__CMP.concat(i_procmux_24_1149__CMP).concat(i_procmux_24_1148__CMP).val()) ? value<4>{0u} : value<4>{0u})) : value<4>{0u}) : value<4>{0u}));
	// cells $procmux$1217 $procmux$1214 $procmux$1212 $procmux$1175 $auto$opt_reduce.cc:131:opt_pmux$5622
	i_3_5c_tokens2_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_lt_24_receiver_2e_v_3a_106_24_197__Y ? (i_procmux_24_1149__CMP ? value<4>{0x1u} : (reduce_or<1>(i_procmux_24_1151__CMP.concat(i_procmux_24_1150__CMP).concat(i_procmux_24_1148__CMP).val()) ? value<4>{0u} : value<4>{0u})) : value<4>{0u}) : value<4>{0u}));
	// cells $procmux$1208 $procmux$1205 $procmux$1203 $procmux$1161 $auto$opt_reduce.cc:131:opt_pmux$5624
	i_3_5c_tokens3_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_lt_24_receiver_2e_v_3a_106_24_197__Y ? (reduce_or<1>(i_procmux_24_1151__CMP.concat(i_procmux_24_1150__CMP).concat(i_procmux_24_1149__CMP).val()) ? value<4>{0u} : (i_procmux_24_1148__CMP ? value<4>{0x1u} : value<4>{0u})) : value<4>{0u}) : value<4>{0u}));
	// cell $auto$opt_reduce.cc:131:opt_pmux$5610
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_5595 = reduce_or<1>(i_procmux_24_2684__CMP.concat(i_procmux_24_2683__CMP).concat(i_procmux_24_2682__CMP).concat(i_procmux_24_2681__CMP).concat(i_procmux_24_2679__CMP).concat(i_procmux_24_2678__CMP).concat(i_procmux_24_2677__CMP).val());
	// \src: receiver.v:106.8-106.14
	// cell $lt$receiver.v:106$202
	i_lt_24_receiver_2e_v_3a_106_24_202__Y = lt_uu<1>(value<1>{0x1u}, i_5_5c_qlen_5b_3_3a_0_5d_);
	// cells $procmux$2432 $procmux$2429 $procmux$2427 $procmux$2083
	i_6_5c_qo_5b_2_5d__5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_logic__and_24_receiver_2e_v_3a_78_24_133__Y ? (i_shiftx_24_receiver_2e_v_3a_80_24_137__Y ? i_3_5c_qo_5b_3_5d__5b_1_3a_0_5d_ : i_3_5c_qo_5b_2_5d__5b_1_3a_0_5d_) : i_3_5c_qo_5b_2_5d__5b_1_3a_0_5d_) : value<2>{0u}));
	// cells $procmux$3483 $procmux$3205 $procmux$2928
	i_3_5c_qo_5b_4_5d__5b_1_3a_0_5d_ = (i_4_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_70_24_102__Y ? p_qo_5b_4_5d_.curr : (i_procmux_24_2680__CMP ? i_4_5c_releaseowner_5b_1_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_5595 ? p_qo_5b_4_5d_.curr : value<2>{0u}))) : p_qo_5b_4_5d_.curr);
	// \full_case: 1
	// \src: receiver.v:107.37-107.37|receiver.v:107.6-107.104
	// cell $procmux$1008_CMP0
	i_procmux_24_1008__CMP = eq_uu<1>(i_6_5c_qo_5b_2_5d__5b_1_3a_0_5d_, value<1>{0x1u});
	// \full_case: 1
	// \src: receiver.v:107.57-107.57|receiver.v:107.6-107.104
	// cell $procmux$1007_CMP0
	i_procmux_24_1007__CMP = eq_uu<1>(i_6_5c_qo_5b_2_5d__5b_1_3a_0_5d_, value<2>{0x2u});
	// \full_case: 1
	// \src: receiver.v:107.77-107.77|receiver.v:107.6-107.104
	// cell $procmux$1006_CMP0
	i_procmux_24_1006__CMP = eq_uu<1>(i_6_5c_qo_5b_2_5d__5b_1_3a_0_5d_, value<2>{0x3u});
	// cells $procmux$1143 $procmux$1140 $procmux$1138 $procmux$1055 $add$receiver.v:107$203 $auto$opt_reduce.cc:131:opt_pmux$5634
	i_5_5c_tokens0_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_lt_24_receiver_2e_v_3a_106_24_202__Y ? (i_procmux_24_1059__CMP ? add_uu<4>(i_3_5c_tokens0_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_1058__CMP.concat(i_procmux_24_1057__CMP).concat(i_procmux_24_1056__CMP).val()) ? i_3_5c_tokens0_5b_3_3a_0_5d_ : value<4>{0u})) : i_3_5c_tokens0_5b_3_3a_0_5d_) : value<4>{0u}));
	// \full_case: 1
	// \src: receiver.v:107.17-107.17|receiver.v:107.6-107.104
	// cell $procmux$1009_CMP0
	i_procmux_24_1009__CMP = logic_not<1>(i_6_5c_qo_5b_2_5d__5b_1_3a_0_5d_);
	// cells $procmux$1134 $procmux$1131 $procmux$1129 $procmux$1097 $add$receiver.v:107$204 $auto$opt_reduce.cc:131:opt_pmux$5628
	i_5_5c_tokens1_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_lt_24_receiver_2e_v_3a_106_24_202__Y ? (i_procmux_24_1058__CMP ? add_uu<4>(i_3_5c_tokens1_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_1059__CMP.concat(i_procmux_24_1057__CMP).concat(i_procmux_24_1056__CMP).val()) ? i_3_5c_tokens1_5b_3_3a_0_5d_ : value<4>{0u})) : i_3_5c_tokens1_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$1125 $procmux$1122 $procmux$1120 $procmux$1083 $add$receiver.v:107$205 $auto$opt_reduce.cc:131:opt_pmux$5630
	i_5_5c_tokens2_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_lt_24_receiver_2e_v_3a_106_24_202__Y ? (i_procmux_24_1057__CMP ? add_uu<4>(i_3_5c_tokens2_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_1059__CMP.concat(i_procmux_24_1058__CMP).concat(i_procmux_24_1056__CMP).val()) ? i_3_5c_tokens2_5b_3_3a_0_5d_ : value<4>{0u})) : i_3_5c_tokens2_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$1116 $procmux$1113 $procmux$1111 $procmux$1069 $add$receiver.v:107$206 $auto$opt_reduce.cc:131:opt_pmux$5632
	i_5_5c_tokens3_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_lt_24_receiver_2e_v_3a_106_24_202__Y ? (reduce_or<1>(i_procmux_24_1059__CMP.concat(i_procmux_24_1058__CMP).concat(i_procmux_24_1057__CMP).val()) ? i_3_5c_tokens3_5b_3_3a_0_5d_ : (i_procmux_24_1056__CMP ? add_uu<4>(i_3_5c_tokens3_5b_3_3a_0_5d_, value<1>{0x1u}) : value<4>{0u})) : i_3_5c_tokens3_5b_3_3a_0_5d_) : value<4>{0u}));
	// cell $auto$opt_reduce.cc:131:opt_pmux$5612
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_5597 = reduce_or<1>(i_procmux_24_2684__CMP.concat(i_procmux_24_2683__CMP).concat(i_procmux_24_2682__CMP).concat(i_procmux_24_2681__CMP).concat(i_procmux_24_2680__CMP).concat(i_procmux_24_2678__CMP).concat(i_procmux_24_2677__CMP).val());
	// \src: receiver.v:106.8-106.14
	// cell $lt$receiver.v:106$207
	i_lt_24_receiver_2e_v_3a_106_24_207__Y = lt_uu<1>(value<2>{0x2u}, i_5_5c_qlen_5b_3_3a_0_5d_);
	// cells $procmux$2423 $procmux$2420 $procmux$2418 $procmux$2071
	i_6_5c_qo_5b_3_5d__5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_logic__and_24_receiver_2e_v_3a_78_24_133__Y ? (i_shiftx_24_receiver_2e_v_3a_80_24_137__Y ? i_3_5c_qo_5b_4_5d__5b_1_3a_0_5d_ : i_3_5c_qo_5b_3_5d__5b_1_3a_0_5d_) : i_3_5c_qo_5b_3_5d__5b_1_3a_0_5d_) : value<2>{0u}));
	// cells $procmux$3474 $procmux$3193 $procmux$2907
	i_3_5c_qo_5b_5_5d__5b_1_3a_0_5d_ = (i_4_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_70_24_102__Y ? p_qo_5b_5_5d_.curr : (i_procmux_24_2679__CMP ? i_4_5c_releaseowner_5b_1_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_5597 ? p_qo_5b_5_5d_.curr : value<2>{0u}))) : p_qo_5b_5_5d_.curr);
	// \full_case: 1
	// \src: receiver.v:107.37-107.37|receiver.v:107.6-107.104
	// cell $procmux$916_CMP0
	i_procmux_24_874__CMP = eq_uu<1>(i_6_5c_qo_5b_3_5d__5b_1_3a_0_5d_, value<1>{0x1u});
	// \full_case: 1
	// \src: receiver.v:107.57-107.57|receiver.v:107.6-107.104
	// cell $procmux$915_CMP0
	i_procmux_24_873__CMP = eq_uu<1>(i_6_5c_qo_5b_3_5d__5b_1_3a_0_5d_, value<2>{0x2u});
	// \full_case: 1
	// \src: receiver.v:107.77-107.77|receiver.v:107.6-107.104
	// cell $procmux$914_CMP0
	i_procmux_24_872__CMP = eq_uu<1>(i_6_5c_qo_5b_3_5d__5b_1_3a_0_5d_, value<2>{0x3u});
	// cells $procmux$1051 $procmux$1048 $procmux$1046 $procmux$963 $add$receiver.v:107$208 $auto$opt_reduce.cc:131:opt_pmux$5642
	i_7_5c_tokens0_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_lt_24_receiver_2e_v_3a_106_24_207__Y ? (i_procmux_24_1009__CMP ? add_uu<4>(i_5_5c_tokens0_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_1008__CMP.concat(i_procmux_24_1007__CMP).concat(i_procmux_24_1006__CMP).val()) ? i_5_5c_tokens0_5b_3_3a_0_5d_ : value<4>{0u})) : i_5_5c_tokens0_5b_3_3a_0_5d_) : value<4>{0u}));
	// \full_case: 1
	// \src: receiver.v:107.17-107.17|receiver.v:107.6-107.104
	// cell $procmux$917_CMP0
	i_procmux_24_875__CMP = logic_not<1>(i_6_5c_qo_5b_3_5d__5b_1_3a_0_5d_);
	// cells $procmux$1042 $procmux$1039 $procmux$1037 $procmux$1005 $add$receiver.v:107$209 $auto$opt_reduce.cc:131:opt_pmux$5636
	i_7_5c_tokens1_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_lt_24_receiver_2e_v_3a_106_24_207__Y ? (i_procmux_24_1008__CMP ? add_uu<4>(i_5_5c_tokens1_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_1009__CMP.concat(i_procmux_24_1007__CMP).concat(i_procmux_24_1006__CMP).val()) ? i_5_5c_tokens1_5b_3_3a_0_5d_ : value<4>{0u})) : i_5_5c_tokens1_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$1033 $procmux$1030 $procmux$1028 $procmux$991 $add$receiver.v:107$210 $auto$opt_reduce.cc:131:opt_pmux$5638
	i_7_5c_tokens2_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_lt_24_receiver_2e_v_3a_106_24_207__Y ? (i_procmux_24_1007__CMP ? add_uu<4>(i_5_5c_tokens2_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_1009__CMP.concat(i_procmux_24_1008__CMP).concat(i_procmux_24_1006__CMP).val()) ? i_5_5c_tokens2_5b_3_3a_0_5d_ : value<4>{0u})) : i_5_5c_tokens2_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$1024 $procmux$1021 $procmux$1019 $procmux$977 $add$receiver.v:107$211 $auto$opt_reduce.cc:131:opt_pmux$5640
	i_7_5c_tokens3_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_lt_24_receiver_2e_v_3a_106_24_207__Y ? (reduce_or<1>(i_procmux_24_1009__CMP.concat(i_procmux_24_1008__CMP).concat(i_procmux_24_1007__CMP).val()) ? i_5_5c_tokens3_5b_3_3a_0_5d_ : (i_procmux_24_1006__CMP ? add_uu<4>(i_5_5c_tokens3_5b_3_3a_0_5d_, value<1>{0x1u}) : value<4>{0u})) : i_5_5c_tokens3_5b_3_3a_0_5d_) : value<4>{0u}));
	// cell $auto$opt_reduce.cc:131:opt_pmux$5614
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_5599 = reduce_or<1>(i_procmux_24_2684__CMP.concat(i_procmux_24_2683__CMP).concat(i_procmux_24_2682__CMP).concat(i_procmux_24_2681__CMP).concat(i_procmux_24_2680__CMP).concat(i_procmux_24_2679__CMP).concat(i_procmux_24_2677__CMP).val());
	// \src: receiver.v:106.8-106.14
	// cell $lt$receiver.v:106$212
	i_lt_24_receiver_2e_v_3a_106_24_212__Y = lt_uu<1>(value<2>{0x3u}, i_5_5c_qlen_5b_3_3a_0_5d_);
	// cells $procmux$2414 $procmux$2411 $procmux$2409 $procmux$2059
	i_6_5c_qo_5b_4_5d__5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_logic__and_24_receiver_2e_v_3a_78_24_133__Y ? (i_shiftx_24_receiver_2e_v_3a_80_24_137__Y ? i_3_5c_qo_5b_5_5d__5b_1_3a_0_5d_ : i_3_5c_qo_5b_4_5d__5b_1_3a_0_5d_) : i_3_5c_qo_5b_4_5d__5b_1_3a_0_5d_) : value<2>{0u}));
	// cells $procmux$3465 $procmux$3181 $procmux$2886
	i_3_5c_qo_5b_6_5d__5b_1_3a_0_5d_ = (i_4_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_70_24_102__Y ? p_qo_5b_6_5d_.curr : (i_procmux_24_2678__CMP ? i_4_5c_releaseowner_5b_1_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_5599 ? p_qo_5b_6_5d_.curr : value<2>{0u}))) : p_qo_5b_6_5d_.curr);
	// \full_case: 1
	// \src: receiver.v:107.37-107.37|receiver.v:107.6-107.104
	// cell $procmux$824_CMP0
	i_procmux_24_782__CMP = eq_uu<1>(i_6_5c_qo_5b_4_5d__5b_1_3a_0_5d_, value<1>{0x1u});
	// \full_case: 1
	// \src: receiver.v:107.57-107.57|receiver.v:107.6-107.104
	// cell $procmux$823_CMP0
	i_procmux_24_781__CMP = eq_uu<1>(i_6_5c_qo_5b_4_5d__5b_1_3a_0_5d_, value<2>{0x2u});
	// \full_case: 1
	// \src: receiver.v:107.77-107.77|receiver.v:107.6-107.104
	// cell $procmux$822_CMP0
	i_procmux_24_780__CMP = eq_uu<1>(i_6_5c_qo_5b_4_5d__5b_1_3a_0_5d_, value<2>{0x3u});
	// cells $procmux$959 $procmux$956 $procmux$954 $procmux$871 $add$receiver.v:107$213 $auto$opt_reduce.cc:131:opt_pmux$5650
	i_9_5c_tokens0_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_lt_24_receiver_2e_v_3a_106_24_212__Y ? (i_procmux_24_875__CMP ? add_uu<4>(i_7_5c_tokens0_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_874__CMP.concat(i_procmux_24_873__CMP).concat(i_procmux_24_872__CMP).val()) ? i_7_5c_tokens0_5b_3_3a_0_5d_ : value<4>{0u})) : i_7_5c_tokens0_5b_3_3a_0_5d_) : value<4>{0u}));
	// \full_case: 1
	// \src: receiver.v:107.17-107.17|receiver.v:107.6-107.104
	// cell $procmux$825_CMP0
	i_procmux_24_783__CMP = logic_not<1>(i_6_5c_qo_5b_4_5d__5b_1_3a_0_5d_);
	// cells $procmux$950 $procmux$947 $procmux$945 $procmux$913 $add$receiver.v:107$214 $auto$opt_reduce.cc:131:opt_pmux$5644
	i_9_5c_tokens1_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_lt_24_receiver_2e_v_3a_106_24_212__Y ? (i_procmux_24_874__CMP ? add_uu<4>(i_7_5c_tokens1_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_875__CMP.concat(i_procmux_24_873__CMP).concat(i_procmux_24_872__CMP).val()) ? i_7_5c_tokens1_5b_3_3a_0_5d_ : value<4>{0u})) : i_7_5c_tokens1_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$941 $procmux$938 $procmux$936 $procmux$899 $add$receiver.v:107$215 $auto$opt_reduce.cc:131:opt_pmux$5646
	i_9_5c_tokens2_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_lt_24_receiver_2e_v_3a_106_24_212__Y ? (i_procmux_24_873__CMP ? add_uu<4>(i_7_5c_tokens2_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_875__CMP.concat(i_procmux_24_874__CMP).concat(i_procmux_24_872__CMP).val()) ? i_7_5c_tokens2_5b_3_3a_0_5d_ : value<4>{0u})) : i_7_5c_tokens2_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$932 $procmux$929 $procmux$927 $procmux$885 $add$receiver.v:107$216 $auto$opt_reduce.cc:131:opt_pmux$5648
	i_9_5c_tokens3_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_lt_24_receiver_2e_v_3a_106_24_212__Y ? (reduce_or<1>(i_procmux_24_875__CMP.concat(i_procmux_24_874__CMP).concat(i_procmux_24_873__CMP).val()) ? i_7_5c_tokens3_5b_3_3a_0_5d_ : (i_procmux_24_872__CMP ? add_uu<4>(i_7_5c_tokens3_5b_3_3a_0_5d_, value<1>{0x1u}) : value<4>{0u})) : i_7_5c_tokens3_5b_3_3a_0_5d_) : value<4>{0u}));
	// cell $auto$opt_reduce.cc:131:opt_pmux$5616
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_5601 = reduce_or<1>(i_procmux_24_2684__CMP.concat(i_procmux_24_2683__CMP).concat(i_procmux_24_2682__CMP).concat(i_procmux_24_2681__CMP).concat(i_procmux_24_2680__CMP).concat(i_procmux_24_2679__CMP).concat(i_procmux_24_2678__CMP).val());
	// \src: receiver.v:106.8-106.14
	// cell $lt$receiver.v:106$217
	i_lt_24_receiver_2e_v_3a_106_24_217__Y = lt_uu<1>(value<3>{0x4u}, i_5_5c_qlen_5b_3_3a_0_5d_);
	// cells $procmux$2405 $procmux$2402 $procmux$2400 $procmux$2047
	i_6_5c_qo_5b_5_5d__5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_logic__and_24_receiver_2e_v_3a_78_24_133__Y ? (i_shiftx_24_receiver_2e_v_3a_80_24_137__Y ? i_3_5c_qo_5b_6_5d__5b_1_3a_0_5d_ : i_3_5c_qo_5b_5_5d__5b_1_3a_0_5d_) : i_3_5c_qo_5b_5_5d__5b_1_3a_0_5d_) : value<2>{0u}));
	// cells $procmux$3456 $procmux$3169 $procmux$2865
	i_3_5c_qo_5b_7_5d__5b_1_3a_0_5d_ = (i_4_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_70_24_102__Y ? p_qo_5b_7_5d_.curr : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_5601 ? p_qo_5b_7_5d_.curr : (i_procmux_24_2677__CMP ? i_4_5c_releaseowner_5b_1_3a_0_5d_ : value<2>{0u}))) : p_qo_5b_7_5d_.curr);
	// \full_case: 1
	// \src: receiver.v:107.37-107.37|receiver.v:107.6-107.104
	// cell $procmux$732_CMP0
	i_procmux_24_690__CMP = eq_uu<1>(i_6_5c_qo_5b_5_5d__5b_1_3a_0_5d_, value<1>{0x1u});
	// \full_case: 1
	// \src: receiver.v:107.57-107.57|receiver.v:107.6-107.104
	// cell $procmux$731_CMP0
	i_procmux_24_689__CMP = eq_uu<1>(i_6_5c_qo_5b_5_5d__5b_1_3a_0_5d_, value<2>{0x2u});
	// \full_case: 1
	// \src: receiver.v:107.77-107.77|receiver.v:107.6-107.104
	// cell $procmux$730_CMP0
	i_procmux_24_688__CMP = eq_uu<1>(i_6_5c_qo_5b_5_5d__5b_1_3a_0_5d_, value<2>{0x3u});
	// cells $procmux$867 $procmux$864 $procmux$862 $procmux$779 $add$receiver.v:107$218 $auto$opt_reduce.cc:131:opt_pmux$5658
	i_11_5c_tokens0_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_lt_24_receiver_2e_v_3a_106_24_217__Y ? (i_procmux_24_783__CMP ? add_uu<4>(i_9_5c_tokens0_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_782__CMP.concat(i_procmux_24_781__CMP).concat(i_procmux_24_780__CMP).val()) ? i_9_5c_tokens0_5b_3_3a_0_5d_ : value<4>{0u})) : i_9_5c_tokens0_5b_3_3a_0_5d_) : value<4>{0u}));
	// \full_case: 1
	// \src: receiver.v:107.17-107.17|receiver.v:107.6-107.104
	// cell $procmux$733_CMP0
	i_procmux_24_691__CMP = logic_not<1>(i_6_5c_qo_5b_5_5d__5b_1_3a_0_5d_);
	// cells $procmux$858 $procmux$855 $procmux$853 $procmux$821 $add$receiver.v:107$219 $auto$opt_reduce.cc:131:opt_pmux$5652
	i_11_5c_tokens1_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_lt_24_receiver_2e_v_3a_106_24_217__Y ? (i_procmux_24_782__CMP ? add_uu<4>(i_9_5c_tokens1_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_783__CMP.concat(i_procmux_24_781__CMP).concat(i_procmux_24_780__CMP).val()) ? i_9_5c_tokens1_5b_3_3a_0_5d_ : value<4>{0u})) : i_9_5c_tokens1_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$849 $procmux$846 $procmux$844 $procmux$807 $add$receiver.v:107$220 $auto$opt_reduce.cc:131:opt_pmux$5654
	i_11_5c_tokens2_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_lt_24_receiver_2e_v_3a_106_24_217__Y ? (i_procmux_24_781__CMP ? add_uu<4>(i_9_5c_tokens2_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_783__CMP.concat(i_procmux_24_782__CMP).concat(i_procmux_24_780__CMP).val()) ? i_9_5c_tokens2_5b_3_3a_0_5d_ : value<4>{0u})) : i_9_5c_tokens2_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$840 $procmux$837 $procmux$835 $procmux$793 $add$receiver.v:107$221 $auto$opt_reduce.cc:131:opt_pmux$5656
	i_11_5c_tokens3_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_lt_24_receiver_2e_v_3a_106_24_217__Y ? (reduce_or<1>(i_procmux_24_783__CMP.concat(i_procmux_24_782__CMP).concat(i_procmux_24_781__CMP).val()) ? i_9_5c_tokens3_5b_3_3a_0_5d_ : (i_procmux_24_780__CMP ? add_uu<4>(i_9_5c_tokens3_5b_3_3a_0_5d_, value<1>{0x1u}) : value<4>{0u})) : i_9_5c_tokens3_5b_3_3a_0_5d_) : value<4>{0u}));
	// \src: receiver.v:106.8-106.14
	// cell $lt$receiver.v:106$222
	i_lt_24_receiver_2e_v_3a_106_24_222__Y = lt_uu<1>(value<3>{0x5u}, i_5_5c_qlen_5b_3_3a_0_5d_);
	// cells $procmux$2396 $procmux$2393 $procmux$2391 $procmux$2035
	i_6_5c_qo_5b_6_5d__5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_logic__and_24_receiver_2e_v_3a_78_24_133__Y ? (i_shiftx_24_receiver_2e_v_3a_80_24_137__Y ? i_3_5c_qo_5b_7_5d__5b_1_3a_0_5d_ : i_3_5c_qo_5b_6_5d__5b_1_3a_0_5d_) : i_3_5c_qo_5b_6_5d__5b_1_3a_0_5d_) : value<2>{0u}));
	// \full_case: 1
	// \src: receiver.v:107.37-107.37|receiver.v:107.6-107.104
	// cell $procmux$640_CMP0
	i_procmux_24_598__CMP = eq_uu<1>(i_6_5c_qo_5b_6_5d__5b_1_3a_0_5d_, value<1>{0x1u});
	// \full_case: 1
	// \src: receiver.v:107.57-107.57|receiver.v:107.6-107.104
	// cell $procmux$639_CMP0
	i_procmux_24_597__CMP = eq_uu<1>(i_6_5c_qo_5b_6_5d__5b_1_3a_0_5d_, value<2>{0x2u});
	// \full_case: 1
	// \src: receiver.v:107.77-107.77|receiver.v:107.6-107.104
	// cell $procmux$638_CMP0
	i_procmux_24_596__CMP = eq_uu<1>(i_6_5c_qo_5b_6_5d__5b_1_3a_0_5d_, value<2>{0x3u});
	// cells $procmux$775 $procmux$772 $procmux$770 $procmux$687 $add$receiver.v:107$223 $auto$opt_reduce.cc:131:opt_pmux$5666
	i_13_5c_tokens0_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_lt_24_receiver_2e_v_3a_106_24_222__Y ? (i_procmux_24_691__CMP ? add_uu<4>(i_11_5c_tokens0_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_690__CMP.concat(i_procmux_24_689__CMP).concat(i_procmux_24_688__CMP).val()) ? i_11_5c_tokens0_5b_3_3a_0_5d_ : value<4>{0u})) : i_11_5c_tokens0_5b_3_3a_0_5d_) : value<4>{0u}));
	// \full_case: 1
	// \src: receiver.v:107.17-107.17|receiver.v:107.6-107.104
	// cell $procmux$641_CMP0
	i_procmux_24_599__CMP = logic_not<1>(i_6_5c_qo_5b_6_5d__5b_1_3a_0_5d_);
	// cells $procmux$766 $procmux$763 $procmux$761 $procmux$729 $add$receiver.v:107$224 $auto$opt_reduce.cc:131:opt_pmux$5660
	i_13_5c_tokens1_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_lt_24_receiver_2e_v_3a_106_24_222__Y ? (i_procmux_24_690__CMP ? add_uu<4>(i_11_5c_tokens1_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_691__CMP.concat(i_procmux_24_689__CMP).concat(i_procmux_24_688__CMP).val()) ? i_11_5c_tokens1_5b_3_3a_0_5d_ : value<4>{0u})) : i_11_5c_tokens1_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$757 $procmux$754 $procmux$752 $procmux$715 $add$receiver.v:107$225 $auto$opt_reduce.cc:131:opt_pmux$5662
	i_13_5c_tokens2_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_lt_24_receiver_2e_v_3a_106_24_222__Y ? (i_procmux_24_689__CMP ? add_uu<4>(i_11_5c_tokens2_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_691__CMP.concat(i_procmux_24_690__CMP).concat(i_procmux_24_688__CMP).val()) ? i_11_5c_tokens2_5b_3_3a_0_5d_ : value<4>{0u})) : i_11_5c_tokens2_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$748 $procmux$745 $procmux$743 $procmux$701 $add$receiver.v:107$226 $auto$opt_reduce.cc:131:opt_pmux$5664
	i_13_5c_tokens3_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_lt_24_receiver_2e_v_3a_106_24_222__Y ? (reduce_or<1>(i_procmux_24_691__CMP.concat(i_procmux_24_690__CMP).concat(i_procmux_24_689__CMP).val()) ? i_11_5c_tokens3_5b_3_3a_0_5d_ : (i_procmux_24_688__CMP ? add_uu<4>(i_11_5c_tokens3_5b_3_3a_0_5d_, value<1>{0x1u}) : value<4>{0u})) : i_11_5c_tokens3_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $logic_or$receiver.v:91$174 $eq$receiver.v:91$172 $eq$receiver.v:91$173
	i_logic__or_24_receiver_2e_v_3a_91_24_174__Y = logic_or<1>(eq_uu<1>(p_rp.curr, value<1>{0x1u}), eq_uu<1>(p_rp.curr, value<2>{0x2u}));
	// \src: receiver.v:106.8-106.14
	// cell $lt$receiver.v:106$227
	i_lt_24_receiver_2e_v_3a_106_24_227__Y = lt_uu<1>(value<3>{0x6u}, i_5_5c_qlen_5b_3_3a_0_5d_);
	// cells $procmux$2567 $procmux$2564 $procmux$2562 $procmux$1915
	i_3_5c_failed_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_logic__and_24_receiver_2e_v_3a_78_24_133__Y ? (i_shiftx_24_receiver_2e_v_3a_80_24_137__Y ? p_failed.curr : value<1>{0x1u}) : p_failed.curr) : value<1>{0u}));
	// cells $procmux$1669 $procmux$1571
	i_4_5c_evblock_5b_0_3a_0_5d_ = (p_rone.curr ? (i_logic__or_24_receiver_2e_v_3a_91_24_174__Y ? value<1>{0u} : value<1>{0x1u}) : value<1>{0u});
	// \src: receiver.v:75.6-75.69
	// cell $neg$receiver.v:75$126
	i_neg_24_receiver_2e_v_3a_75_24_118__Y = neg_u<33>(i_add_24_receiver_2e_v_3a_74_24_112__Y);
	// cells $procmux$2387 $procmux$2384 $procmux$2382 $procmux$2023
	i_6_5c_qo_5b_7_5d__5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_logic__and_24_receiver_2e_v_3a_78_24_133__Y ? (i_shiftx_24_receiver_2e_v_3a_80_24_137__Y ? value<2>{0u} : i_3_5c_qo_5b_7_5d__5b_1_3a_0_5d_) : i_3_5c_qo_5b_7_5d__5b_1_3a_0_5d_) : value<2>{0u}));
	// \src: receiver.v:75.6-75.69
	// cell $shift$receiver.v:75$119
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5765.slice<15,0>() = shift_us<16>(value<4>{0xfu}, i_neg_24_receiver_2e_v_3a_75_24_118__Y);
	// \full_case: 1
	// \src: receiver.v:107.37-107.37|receiver.v:107.6-107.104
	// cell $procmux$548_CMP0
	i_procmux_24_506__CMP = eq_uu<1>(i_6_5c_qo_5b_7_5d__5b_1_3a_0_5d_, value<1>{0x1u});
	// \full_case: 1
	// \src: receiver.v:107.57-107.57|receiver.v:107.6-107.104
	// cell $procmux$547_CMP0
	i_procmux_24_505__CMP = eq_uu<1>(i_6_5c_qo_5b_7_5d__5b_1_3a_0_5d_, value<2>{0x2u});
	// \full_case: 1
	// \src: receiver.v:107.77-107.77|receiver.v:107.6-107.104
	// cell $procmux$546_CMP0
	i_procmux_24_504__CMP = eq_uu<1>(i_6_5c_qo_5b_7_5d__5b_1_3a_0_5d_, value<2>{0x3u});
	// cells $procmux$683 $procmux$680 $procmux$678 $procmux$595 $add$receiver.v:107$228 $auto$opt_reduce.cc:131:opt_pmux$5674
	i_15_5c_tokens0_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_lt_24_receiver_2e_v_3a_106_24_227__Y ? (i_procmux_24_599__CMP ? add_uu<4>(i_13_5c_tokens0_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_598__CMP.concat(i_procmux_24_597__CMP).concat(i_procmux_24_596__CMP).val()) ? i_13_5c_tokens0_5b_3_3a_0_5d_ : value<4>{0u})) : i_13_5c_tokens0_5b_3_3a_0_5d_) : value<4>{0u}));
	// \full_case: 1
	// \src: receiver.v:107.17-107.17|receiver.v:107.6-107.104
	// cell $procmux$549_CMP0
	i_procmux_24_507__CMP = logic_not<1>(i_6_5c_qo_5b_7_5d__5b_1_3a_0_5d_);
	// cells $procmux$674 $procmux$671 $procmux$669 $procmux$637 $add$receiver.v:107$229 $auto$opt_reduce.cc:131:opt_pmux$5668
	i_15_5c_tokens1_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_lt_24_receiver_2e_v_3a_106_24_227__Y ? (i_procmux_24_598__CMP ? add_uu<4>(i_13_5c_tokens1_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_599__CMP.concat(i_procmux_24_597__CMP).concat(i_procmux_24_596__CMP).val()) ? i_13_5c_tokens1_5b_3_3a_0_5d_ : value<4>{0u})) : i_13_5c_tokens1_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$665 $procmux$662 $procmux$660 $procmux$623 $add$receiver.v:107$230 $auto$opt_reduce.cc:131:opt_pmux$5670
	i_15_5c_tokens2_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_lt_24_receiver_2e_v_3a_106_24_227__Y ? (i_procmux_24_597__CMP ? add_uu<4>(i_13_5c_tokens2_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_599__CMP.concat(i_procmux_24_598__CMP).concat(i_procmux_24_596__CMP).val()) ? i_13_5c_tokens2_5b_3_3a_0_5d_ : value<4>{0u})) : i_13_5c_tokens2_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$656 $procmux$653 $procmux$651 $procmux$609 $add$receiver.v:107$231 $auto$opt_reduce.cc:131:opt_pmux$5672
	i_15_5c_tokens3_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_lt_24_receiver_2e_v_3a_106_24_227__Y ? (reduce_or<1>(i_procmux_24_599__CMP.concat(i_procmux_24_598__CMP).concat(i_procmux_24_597__CMP).val()) ? i_13_5c_tokens3_5b_3_3a_0_5d_ : (i_procmux_24_596__CMP ? add_uu<4>(i_13_5c_tokens3_5b_3_3a_0_5d_, value<1>{0x1u}) : value<4>{0u})) : i_13_5c_tokens3_5b_3_3a_0_5d_) : value<4>{0u}));
	// \src: receiver.v:75.6-75.69
	// cell $not$receiver.v:75$120
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5764.slice<15,0>() = not_u<16>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5765.slice<15,0>().val());
	// cells $procmux$1676 $procmux$1673 $procmux$1671
	i_4_5c_rone_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? value<1>{0u} : i_4_5c_evblock_5b_0_3a_0_5d_) : value<1>{0u}));
	// cells $shift$receiver.v:75$127 $add$receiver.v:75$125
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5761.slice<15,0>() = shift_us<16>(add_uu<4>(i_shiftx_24_receiver_2e_v_3a_74_24_113__Y, value<1>{0x1u}), i_neg_24_receiver_2e_v_3a_75_24_118__Y);
	// \src: receiver.v:106.8-106.14
	// cell $lt$receiver.v:106$232
	i_lt_24_receiver_2e_v_3a_106_24_232__Y = lt_uu<1>(value<3>{0x7u}, i_5_5c_qlen_5b_3_3a_0_5d_);
	// cells $procmux$2603 $procmux$2600 $procmux$2598 $procmux$2263
	i_3_5c_rzero_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_logic__and_24_receiver_2e_v_3a_78_24_133__Y ? (i_shiftx_24_receiver_2e_v_3a_80_24_137__Y ? value<1>{0x1u} : p_rzero.curr) : p_rzero.curr) : value<1>{0u}));
	// cells $or$receiver.v:75$128 $and$receiver.v:75$121
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5760.slice<15,0>() = or_uu<16>(and_uu<16>(p_outstanding.curr, i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5764.slice<15,0>().val()), i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5761.slice<15,0>().val());
	// cells $logic_and$receiver.v:94$176 $logic_not$receiver.v:94$175
	i_logic__and_24_receiver_2e_v_3a_94_24_176__Y = logic_and<1>(i_3_5c_rzero_5b_0_3a_0_5d_, logic_not<1>(i_4_5c_rone_5b_0_3a_0_5d_));
	// cells $procmux$1640 $procmux$1637 $procmux$1635 $procmux$1633 $procmux$1511
	i_4_5c_emitowner_5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? value<2>{0u} : (p_rone.curr ? (i_logic__or_24_receiver_2e_v_3a_91_24_174__Y ? p_ownerone.curr : p_emitowner.curr) : p_emitowner.curr)) : value<2>{0u}));
	// cells $procmux$2594 $procmux$2591 $procmux$2589 $procmux$2251
	i_3_5c_ownerzero_5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_logic__and_24_receiver_2e_v_3a_78_24_133__Y ? (i_shiftx_24_receiver_2e_v_3a_80_24_137__Y ? i_3_5c_qo_5b_0_5d__5b_1_3a_0_5d_ : p_ownerzero.curr) : p_ownerzero.curr) : value<2>{0u}));
	// \src: receiver.v:101.51-101.62
	// cell $mul$receiver.v:101$190
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5749.slice<4,0>() = mul_uu<5>(value<3>{0x4u}, i_4_5c_emitowner_5b_1_3a_0_5d_);
	// connection
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5749.slice<31,5>() = value<27>{0u};
	// \full_case: 1
	// \src: receiver.v:110.48-110.48|receiver.v:110.13-110.115
	// cell $procmux$456_CMP0
	i_procmux_24_414__CMP = eq_uu<1>(i_3_5c_ownerzero_5b_1_3a_0_5d_, value<1>{0x1u});
	// \full_case: 1
	// \src: receiver.v:110.68-110.68|receiver.v:110.13-110.115
	// cell $procmux$455_CMP0
	i_procmux_24_413__CMP = eq_uu<1>(i_3_5c_ownerzero_5b_1_3a_0_5d_, value<2>{0x2u});
	// \full_case: 1
	// \src: receiver.v:110.88-110.88|receiver.v:110.13-110.115
	// cell $procmux$454_CMP0
	i_procmux_24_412__CMP = eq_uu<1>(i_3_5c_ownerzero_5b_1_3a_0_5d_, value<2>{0x3u});
	// cells $procmux$591 $procmux$588 $procmux$586 $procmux$503 $add$receiver.v:107$233 $auto$opt_reduce.cc:131:opt_pmux$5682
	i_17_5c_tokens0_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_lt_24_receiver_2e_v_3a_106_24_232__Y ? (i_procmux_24_507__CMP ? add_uu<4>(i_15_5c_tokens0_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_506__CMP.concat(i_procmux_24_505__CMP).concat(i_procmux_24_504__CMP).val()) ? i_15_5c_tokens0_5b_3_3a_0_5d_ : value<4>{0u})) : i_15_5c_tokens0_5b_3_3a_0_5d_) : value<4>{0u}));
	// \full_case: 1
	// \src: receiver.v:110.28-110.28|receiver.v:110.13-110.115
	// cell $procmux$457_CMP0
	i_procmux_24_415__CMP = logic_not<1>(i_3_5c_ownerzero_5b_1_3a_0_5d_);
	// cells $procmux$582 $procmux$579 $procmux$577 $procmux$545 $add$receiver.v:107$234 $auto$opt_reduce.cc:131:opt_pmux$5676
	i_17_5c_tokens1_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_lt_24_receiver_2e_v_3a_106_24_232__Y ? (i_procmux_24_506__CMP ? add_uu<4>(i_15_5c_tokens1_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_507__CMP.concat(i_procmux_24_505__CMP).concat(i_procmux_24_504__CMP).val()) ? i_15_5c_tokens1_5b_3_3a_0_5d_ : value<4>{0u})) : i_15_5c_tokens1_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$573 $procmux$570 $procmux$568 $procmux$531 $add$receiver.v:107$235 $auto$opt_reduce.cc:131:opt_pmux$5678
	i_17_5c_tokens2_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_lt_24_receiver_2e_v_3a_106_24_232__Y ? (i_procmux_24_505__CMP ? add_uu<4>(i_15_5c_tokens2_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_507__CMP.concat(i_procmux_24_506__CMP).concat(i_procmux_24_504__CMP).val()) ? i_15_5c_tokens2_5b_3_3a_0_5d_ : value<4>{0u})) : i_15_5c_tokens2_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$564 $procmux$561 $procmux$559 $procmux$517 $add$receiver.v:107$236 $auto$opt_reduce.cc:131:opt_pmux$5680
	i_17_5c_tokens3_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_lt_24_receiver_2e_v_3a_106_24_232__Y ? (reduce_or<1>(i_procmux_24_507__CMP.concat(i_procmux_24_506__CMP).concat(i_procmux_24_505__CMP).val()) ? i_15_5c_tokens3_5b_3_3a_0_5d_ : (i_procmux_24_504__CMP ? add_uu<4>(i_15_5c_tokens3_5b_3_3a_0_5d_, value<1>{0x1u}) : value<4>{0u})) : i_15_5c_tokens3_5b_3_3a_0_5d_) : value<4>{0u}));
	// \src: receiver.v:101.50-101.66
	// cell $add$receiver.v:101$191
	i_add_24_receiver_2e_v_3a_100_24_179__Y = add_uu<6>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5749.slice<4,0>().val(), value<1>{0u});
	// cells $procmux$3578 $procmux$3575 $procmux$3573 $procmux$3313
	i_3_5c_outstanding_5b_15_3a_0_5d_ = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_4_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_70_24_102__Y ? p_outstanding.curr : i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5760.slice<15,0>().val()) : p_outstanding.curr) : value<16>{0u}));
	// \src: receiver.v:101.11-101.68
	// cell $neg$receiver.v:101$194
	i_neg_24_receiver_2e_v_3a_101_24_186__Y = neg_u<33>(i_add_24_receiver_2e_v_3a_100_24_179__Y);
	// cells $procmux$1811 $procmux$1808 $procmux$1806 $procmux$1357
	i_5_5c_rzero_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? i_3_5c_rzero_5b_0_3a_0_5d_ : (i_logic__and_24_receiver_2e_v_3a_94_24_176__Y ? value<1>{0u} : i_3_5c_rzero_5b_0_3a_0_5d_)) : value<1>{0u}));
	// \src: receiver.v:101.50-101.66
	// cell $shiftx$receiver.v:101$192
	i_shiftx_24_receiver_2e_v_3a_100_24_180__Y = shiftx_us<4>(i_3_5c_outstanding_5b_15_3a_0_5d_, value<1>{0u}.concat(i_add_24_receiver_2e_v_3a_100_24_179__Y).val());
	// \src: receiver.v:101.11-101.68
	// cell $shift$receiver.v:101$187
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5747.slice<15,0>() = shift_us<16>(value<4>{0xfu}, i_neg_24_receiver_2e_v_3a_101_24_186__Y);
	// \src: receiver.v:101.39-101.68
	// cell $sub$receiver.v:101$193
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5744.slice<3,0>() = sub_uu<4>(i_shiftx_24_receiver_2e_v_3a_100_24_180__Y, value<1>{0x1u});
	// \src: receiver.v:101.11-101.68
	// cell $not$receiver.v:101$188
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5746.slice<15,0>() = not_u<16>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5747.slice<15,0>().val());
	// cells $procmux$1793 $procmux$1790 $procmux$1788 $procmux$1393
	i_3_5c_ownerone_5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? p_ownerone.curr : (i_logic__and_24_receiver_2e_v_3a_94_24_176__Y ? i_3_5c_ownerzero_5b_1_3a_0_5d_ : p_ownerone.curr)) : value<2>{0u}));
	// \src: receiver.v:101.11-101.68
	// cell $shift$receiver.v:101$195
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5743.slice<15,0>() = shift_us<16>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5744.slice<3,0>().val(), i_neg_24_receiver_2e_v_3a_101_24_186__Y);
	// \full_case: 1
	// \src: receiver.v:111.46-111.46|receiver.v:111.12-111.113
	// cell $procmux$364_CMP0
	i_procmux_24_322__CMP = eq_uu<1>(i_3_5c_ownerone_5b_1_3a_0_5d_, value<1>{0x1u});
	// \full_case: 1
	// \src: receiver.v:111.66-111.66|receiver.v:111.12-111.113
	// cell $procmux$363_CMP0
	i_procmux_24_321__CMP = eq_uu<1>(i_3_5c_ownerone_5b_1_3a_0_5d_, value<2>{0x2u});
	// \full_case: 1
	// \src: receiver.v:111.86-111.86|receiver.v:111.12-111.113
	// cell $procmux$362_CMP0
	i_procmux_24_320__CMP = eq_uu<1>(i_3_5c_ownerone_5b_1_3a_0_5d_, value<2>{0x3u});
	// cells $procmux$499 $procmux$496 $procmux$494 $procmux$411 $add$receiver.v:110$237 $auto$opt_reduce.cc:131:opt_pmux$5690
	i_19_5c_tokens0_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_5_5c_rzero_5b_0_3a_0_5d_ ? (i_procmux_24_415__CMP ? add_uu<4>(i_17_5c_tokens0_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_414__CMP.concat(i_procmux_24_413__CMP).concat(i_procmux_24_412__CMP).val()) ? i_17_5c_tokens0_5b_3_3a_0_5d_ : value<4>{0u})) : i_17_5c_tokens0_5b_3_3a_0_5d_) : value<4>{0u}));
	// \full_case: 1
	// \src: receiver.v:111.26-111.26|receiver.v:111.12-111.113
	// cell $procmux$365_CMP0
	i_procmux_24_323__CMP = logic_not<1>(i_3_5c_ownerone_5b_1_3a_0_5d_);
	// cells $procmux$490 $procmux$487 $procmux$485 $procmux$453 $add$receiver.v:110$238 $auto$opt_reduce.cc:131:opt_pmux$5684
	i_19_5c_tokens1_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_5_5c_rzero_5b_0_3a_0_5d_ ? (i_procmux_24_414__CMP ? add_uu<4>(i_17_5c_tokens1_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_415__CMP.concat(i_procmux_24_413__CMP).concat(i_procmux_24_412__CMP).val()) ? i_17_5c_tokens1_5b_3_3a_0_5d_ : value<4>{0u})) : i_17_5c_tokens1_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$481 $procmux$478 $procmux$476 $procmux$439 $add$receiver.v:110$239 $auto$opt_reduce.cc:131:opt_pmux$5686
	i_19_5c_tokens2_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_5_5c_rzero_5b_0_3a_0_5d_ ? (i_procmux_24_413__CMP ? add_uu<4>(i_17_5c_tokens2_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_415__CMP.concat(i_procmux_24_414__CMP).concat(i_procmux_24_412__CMP).val()) ? i_17_5c_tokens2_5b_3_3a_0_5d_ : value<4>{0u})) : i_17_5c_tokens2_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$472 $procmux$469 $procmux$467 $procmux$425 $add$receiver.v:110$240 $auto$opt_reduce.cc:131:opt_pmux$5688
	i_19_5c_tokens3_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_5_5c_rzero_5b_0_3a_0_5d_ ? (reduce_or<1>(i_procmux_24_415__CMP.concat(i_procmux_24_414__CMP).concat(i_procmux_24_413__CMP).val()) ? i_17_5c_tokens3_5b_3_3a_0_5d_ : (i_procmux_24_412__CMP ? add_uu<4>(i_17_5c_tokens3_5b_3_3a_0_5d_, value<1>{0x1u}) : value<4>{0u})) : i_17_5c_tokens3_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $or$receiver.v:101$196 $and$receiver.v:101$189
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5742.slice<15,0>() = or_uu<16>(and_uu<16>(i_3_5c_outstanding_5b_15_3a_0_5d_, i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5746.slice<15,0>().val()), i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5743.slice<15,0>().val());
	// \src: receiver.v:100.9-100.39
	// cell $eq$receiver.v:100$181
	i_eq_24_receiver_2e_v_3a_100_24_181__Y = logic_not<1>(i_shiftx_24_receiver_2e_v_3a_100_24_180__Y);
	// cells $procmux$1664 $procmux$1661 $procmux$1659 $procmux$1657 $procmux$1526
	i_4_5c_evemit_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? value<1>{0u} : (p_rone.curr ? (i_logic__or_24_receiver_2e_v_3a_91_24_174__Y ? value<1>{0x1u} : value<1>{0u}) : value<1>{0u})) : value<1>{0u}));
	// \src: receiver.v:84.61-84.69
	// cell $mul$receiver.v:84$160
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5752.slice<6,0>() = mul_uu<7>(value<5>{0x10u}, i_3_5c_qo_5b_0_5d__5b_1_3a_0_5d_);
	// connection
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5752.slice<31,7>() = value<25>{0u};
	// cells $procmux$1802 $procmux$1799 $procmux$1797 $procmux$1405
	i_3_5c_rone_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? p_rone.curr : (i_logic__and_24_receiver_2e_v_3a_94_24_176__Y ? value<1>{0x1u} : i_4_5c_rone_5b_0_3a_0_5d_)) : value<1>{0u}));
	// \src: receiver.v:82.63-82.70
	// cell $mul$receiver.v:82$142
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5759.slice<5,0>() = mul_uu<6>(value<4>{0x8u}, i_3_5c_qo_5b_0_5d__5b_1_3a_0_5d_);
	// connection
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5759.slice<31,6>() = value<26>{0u};
	// cells $neg$receiver.v:84$166 $add$receiver.v:84$161
	i_neg_24_receiver_2e_v_3a_84_24_162__Y = neg_u<33>(add_uu<8>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5752.slice<6,0>().val(), value<1>{0u}));
	// \src: receiver.v:84.37-84.53
	// cell $neg$receiver.v:84$157
	i_neg_24_receiver_2e_v_3a_84_24_150__Y = neg_u<3>(i_3_5c_qo_5b_0_5d__5b_1_3a_0_5d_);
	// cells $procmux$4693 $procmux$4690 $procmux$4688
	i_3_5c_bytes_5b_7_3a_0_5d_ = (p_rst ? value<8>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_logic__and_24_receiver_2e_v_3a_56_24_71__Y ? p_wubytes.slice<7,0>().val() : p_bytes.curr.slice<7,0>().val()) : value<8>{0u}));
	// cells $procmux$4657 $procmux$4654 $procmux$4652
	i_4_5c_bytes_5b_15_3a_8_5d_ = (p_rst ? value<8>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_logic__and_24_receiver_2e_v_3a_56_24_72__Y ? p_wubytes.slice<15,8>().val() : p_bytes.curr.slice<15,8>().val()) : value<8>{0u}));
	// cells $procmux$4621 $procmux$4618 $procmux$4616
	i_5_5c_bytes_5b_23_3a_16_5d_ = (p_rst ? value<8>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_logic__and_24_receiver_2e_v_3a_56_24_73__Y ? p_wubytes.slice<23,16>().val() : p_bytes.curr.slice<23,16>().val()) : value<8>{0u}));
	// cells $procmux$4585 $procmux$4582 $procmux$4580
	i_6_5c_bytes_5b_31_3a_24_5d_ = (p_rst ? value<8>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_logic__and_24_receiver_2e_v_3a_56_24_74__Y ? p_wubytes.slice<31,24>().val() : p_bytes.curr.slice<31,24>().val()) : value<8>{0u}));
	// \src: receiver.v:84.37-84.53
	// cell $shift$receiver.v:84$154
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5757.slice<3,0>() = shift_us<4>(value<1>{0x1u}, i_neg_24_receiver_2e_v_3a_84_24_150__Y);
	// cells $shiftx$receiver.v:82$144 $add$receiver.v:82$143
	i_shiftx_24_receiver_2e_v_3a_82_24_144__Y = shiftx_us<8>(i_6_5c_bytes_5b_31_3a_24_5d_.concat(i_5_5c_bytes_5b_23_3a_16_5d_).concat(i_4_5c_bytes_5b_15_3a_8_5d_).concat(i_3_5c_bytes_5b_7_3a_0_5d_).val(), value<1>{0u}.concat(add_uu<7>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5759.slice<5,0>().val(), value<1>{0u})).val());
	// cells $procmux$3447 $procmux$3157 $procmux$2676
	i_3_5c_qi_5b_0_5d__5b_31_3a_0_5d_ = (i_4_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_70_24_102__Y ? p_qi_5b_0_5d_.curr : (i_procmux_24_2684__CMP ? p_nextid.curr : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_5603 ? p_qi_5b_0_5d_.curr : value<32>{0u}))) : p_qi_5b_0_5d_.curr);
	// cells $procmux$4522 $procmux$4519 $procmux$4517 $procmux$3793 $procmux$3728 $procmux$3647
	i_7_5c_enabled_5b_3_3a_0_5d_.slice<3>() = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_eq_24_receiver_2e_v_3a_58_24_75__Y ? (i_6_5c_enabled_5b_3_3a_3_5d_ ? (i_eq_24_receiver_2e_v_3a_61_24_88__Y ? value<1>{0x1u} : (i_eq_24_receiver_2e_v_3a_62_24_91__Y ? value<1>{0u} : value<1>{0x1u})) : value<1>{0u}) : i_6_5c_enabled_5b_3_3a_3_5d_) : value<1>{0u}));
	// cells $procmux$4495 $procmux$4492 $procmux$4490 $procmux$4360 $procmux$4295 $procmux$4214
	i_7_5c_enabled_5b_3_3a_0_5d_.slice<0>() = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_eq_24_receiver_2e_v_3a_58_24_75__Y ? (i_3_5c_enabled_5b_0_3a_0_5d_ ? (i_eq_24_receiver_2e_v_3a_61_24_76__Y ? value<1>{0x1u} : (i_eq_24_receiver_2e_v_3a_62_24_79__Y ? value<1>{0u} : value<1>{0x1u})) : value<1>{0u}) : i_3_5c_enabled_5b_0_3a_0_5d_) : value<1>{0u}));
	// cells $procmux$4459 $procmux$4456 $procmux$4454 $procmux$4171 $procmux$4106 $procmux$4025
	i_7_5c_enabled_5b_3_3a_0_5d_.slice<1>() = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_eq_24_receiver_2e_v_3a_58_24_75__Y ? (i_4_5c_enabled_5b_1_3a_1_5d_ ? (i_eq_24_receiver_2e_v_3a_61_24_80__Y ? value<1>{0x1u} : (i_eq_24_receiver_2e_v_3a_62_24_83__Y ? value<1>{0u} : value<1>{0x1u})) : value<1>{0u}) : i_4_5c_enabled_5b_1_3a_1_5d_) : value<1>{0u}));
	// cells $procmux$4423 $procmux$4420 $procmux$4418 $procmux$3982 $procmux$3917 $procmux$3836
	i_7_5c_enabled_5b_3_3a_0_5d_.slice<2>() = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_eq_24_receiver_2e_v_3a_58_24_75__Y ? (i_5_5c_enabled_5b_2_3a_2_5d_ ? (i_eq_24_receiver_2e_v_3a_61_24_84__Y ? value<1>{0x1u} : (i_eq_24_receiver_2e_v_3a_62_24_87__Y ? value<1>{0u} : value<1>{0x1u})) : value<1>{0u}) : i_5_5c_enabled_5b_2_3a_2_5d_) : value<1>{0u}));
	// \full_case: 1
	// \src: receiver.v:100.9-100.39|receiver.v:100.6-101.69
	// cell $procmux$1241
	i_18_5c_fault_5b_31_3a_0_5d_.slice<4,0>() = (i_eq_24_receiver_2e_v_3a_100_24_181__Y ? value<1>{0x1u}.concat(i_13_5c_fault_5b_31_3a_0_5d_.curr.slice<3,0>()).val() : i_13_5c_fault_5b_31_3a_0_5d_.curr.slice<4,0>().val());
	// connection
	i_18_5c_fault_5b_31_3a_0_5d_.slice<31,5>() = i_13_5c_fault_5b_31_3a_0_5d_.curr.slice<31,5>().val();
	// cells $procmux$1730 $procmux$1727 $procmux$1725 $procmux$1309 $procmux$1271
	i_5_5c_outstanding_5b_15_3a_0_5d_ = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? i_3_5c_outstanding_5b_15_3a_0_5d_ : (i_4_5c_evemit_5b_0_3a_0_5d_ ? (i_eq_24_receiver_2e_v_3a_100_24_181__Y ? i_3_5c_outstanding_5b_15_3a_0_5d_ : i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5742.slice<15,0>().val()) : i_3_5c_outstanding_5b_15_3a_0_5d_)) : value<16>{0u}));
	// cells $procmux$4513 $procmux$4510 $procmux$4508 $procmux$3781 $procmux$3713
	i_7_5c_counts_5b_63_3a_0_5d_.slice<63,48>() = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_eq_24_receiver_2e_v_3a_58_24_75__Y ? (i_6_5c_enabled_5b_3_3a_3_5d_ ? (i_eq_24_receiver_2e_v_3a_61_24_88__Y ? i_6_5c_counts_5b_63_3a_48_5d_ : i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5770.slice<15,0>().val()) : i_6_5c_counts_5b_63_3a_48_5d_) : i_6_5c_counts_5b_63_3a_48_5d_) : value<16>{0u}));
	// cells $procmux$4486 $procmux$4483 $procmux$4481 $procmux$4348 $procmux$4280
	i_7_5c_counts_5b_63_3a_0_5d_.slice<15,0>() = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_eq_24_receiver_2e_v_3a_58_24_75__Y ? (i_3_5c_enabled_5b_0_3a_0_5d_ ? (i_eq_24_receiver_2e_v_3a_61_24_76__Y ? i_3_5c_counts_5b_15_3a_0_5d_ : i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5773.slice<15,0>().val()) : i_3_5c_counts_5b_15_3a_0_5d_) : i_3_5c_counts_5b_15_3a_0_5d_) : value<16>{0u}));
	// cells $procmux$4450 $procmux$4447 $procmux$4445 $procmux$4159 $procmux$4091
	i_7_5c_counts_5b_63_3a_0_5d_.slice<31,16>() = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_eq_24_receiver_2e_v_3a_58_24_75__Y ? (i_4_5c_enabled_5b_1_3a_1_5d_ ? (i_eq_24_receiver_2e_v_3a_61_24_80__Y ? i_4_5c_counts_5b_31_3a_16_5d_ : i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5772.slice<15,0>().val()) : i_4_5c_counts_5b_31_3a_16_5d_) : i_4_5c_counts_5b_31_3a_16_5d_) : value<16>{0u}));
	// cells $procmux$4414 $procmux$4411 $procmux$4409 $procmux$3970 $procmux$3902
	i_7_5c_counts_5b_63_3a_0_5d_.slice<47,32>() = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_eq_24_receiver_2e_v_3a_58_24_75__Y ? (i_5_5c_enabled_5b_2_3a_2_5d_ ? (i_eq_24_receiver_2e_v_3a_61_24_84__Y ? i_5_5c_counts_5b_47_3a_32_5d_ : i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5771.slice<15,0>().val()) : i_5_5c_counts_5b_47_3a_32_5d_) : i_5_5c_counts_5b_47_3a_32_5d_) : value<16>{0u}));
	// \src: receiver.v:84.37-84.53
	// cell $not$receiver.v:84$155
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5756.slice<3,0>() = not_u<4>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5757.slice<3,0>().val());
	// \full_case: 1
	// \src: receiver.v:98.8-98.14|receiver.v:98.5-102.8
	// cell $procmux$1297
	i_17_5c_fault_5b_31_3a_0_5d_.slice<4,0>() = (i_4_5c_evemit_5b_0_3a_0_5d_ ? i_18_5c_fault_5b_31_3a_0_5d_.slice<4,0>().val() : i_13_5c_fault_5b_31_3a_0_5d_.curr.slice<4,0>().val());
	// connection
	i_17_5c_fault_5b_31_3a_0_5d_.slice<31,5>() = i_13_5c_fault_5b_31_3a_0_5d_.curr.slice<31,5>().val();
	// cells $procmux$3596 $procmux$3593 $procmux$3591 $procmux$3337 $add$receiver.v:73$110
	i_3_5c_nextid_5b_31_3a_0_5d_ = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_4_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_70_24_102__Y ? p_nextid.curr : add_uu<32>(p_nextid.curr, value<1>{0x1u})) : p_nextid.curr) : value<32>{0u}));
	// \src: receiver.v:84.37-84.53
	// cell $shift$receiver.v:84$158
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5754.slice<3,0>() = shift_us<4>(value<1>{0u}, i_neg_24_receiver_2e_v_3a_84_24_150__Y);
	// cells $procmux$3384 $procmux$3073 $procmux$2697
	i_3_5c_qi_5b_7_5d__5b_31_3a_0_5d_ = (i_4_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_70_24_102__Y ? p_qi_5b_7_5d_.curr : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_5601 ? p_qi_5b_7_5d_.curr : (i_procmux_24_2677__CMP ? p_nextid.curr : value<32>{0u}))) : p_qi_5b_7_5d_.curr);
	// cells $procmux$3393 $procmux$3085 $procmux$2718
	i_3_5c_qi_5b_6_5d__5b_31_3a_0_5d_ = (i_4_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_70_24_102__Y ? p_qi_5b_6_5d_.curr : (i_procmux_24_2678__CMP ? p_nextid.curr : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_5599 ? p_qi_5b_6_5d_.curr : value<32>{0u}))) : p_qi_5b_6_5d_.curr);
	// cells $procmux$3402 $procmux$3097 $procmux$2739
	i_3_5c_qi_5b_5_5d__5b_31_3a_0_5d_ = (i_4_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_70_24_102__Y ? p_qi_5b_5_5d_.curr : (i_procmux_24_2679__CMP ? p_nextid.curr : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_5597 ? p_qi_5b_5_5d_.curr : value<32>{0u}))) : p_qi_5b_5_5d_.curr);
	// cells $procmux$3411 $procmux$3109 $procmux$2760
	i_3_5c_qi_5b_4_5d__5b_31_3a_0_5d_ = (i_4_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_70_24_102__Y ? p_qi_5b_4_5d_.curr : (i_procmux_24_2680__CMP ? p_nextid.curr : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_5595 ? p_qi_5b_4_5d_.curr : value<32>{0u}))) : p_qi_5b_4_5d_.curr);
	// cells $procmux$3420 $procmux$3121 $procmux$2781
	i_3_5c_qi_5b_3_5d__5b_31_3a_0_5d_ = (i_4_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_70_24_102__Y ? p_qi_5b_3_5d_.curr : (i_procmux_24_2681__CMP ? p_nextid.curr : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_5593 ? p_qi_5b_3_5d_.curr : value<32>{0u}))) : p_qi_5b_3_5d_.curr);
	// cells $procmux$3429 $procmux$3133 $procmux$2802
	i_3_5c_qi_5b_2_5d__5b_31_3a_0_5d_ = (i_4_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_70_24_102__Y ? p_qi_5b_2_5d_.curr : (i_procmux_24_2682__CMP ? p_nextid.curr : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_5591 ? p_qi_5b_2_5d_.curr : value<32>{0u}))) : p_qi_5b_2_5d_.curr);
	// cells $procmux$3438 $procmux$3145 $procmux$2823
	i_3_5c_qi_5b_1_5d__5b_31_3a_0_5d_ = (i_4_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_70_24_102__Y ? p_qi_5b_1_5d_.curr : (i_procmux_24_2683__CMP ? p_nextid.curr : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_5605 ? p_qi_5b_1_5d_.curr : value<32>{0u}))) : p_qi_5b_1_5d_.curr);
	// cells $procmux$2571 $procmux$2227
	i_3_5c_bytezero_5b_7_3a_0_5d_ = (i_logic__and_24_receiver_2e_v_3a_78_24_133__Y ? (i_shiftx_24_receiver_2e_v_3a_80_24_137__Y ? i_shiftx_24_receiver_2e_v_3a_82_24_144__Y : p_bytezero.curr) : p_bytezero.curr);
	// cells $procmux$1609 $procmux$1496
	i_4_5c_emitid_5b_31_3a_0_5d_ = (p_rone.curr ? (i_logic__or_24_receiver_2e_v_3a_91_24_174__Y ? p_idone.curr : p_emitid.curr) : p_emitid.curr);
	// cells $procmux$2580 $procmux$2239
	i_3_5c_idzero_5b_31_3a_0_5d_ = (i_logic__and_24_receiver_2e_v_3a_78_24_133__Y ? (i_shiftx_24_receiver_2e_v_3a_80_24_137__Y ? i_3_5c_qi_5b_0_5d__5b_31_3a_0_5d_ : p_idzero.curr) : p_idzero.curr);
	// \full_case: 1
	// \src: receiver.v:89.7-89.14|receiver.v:89.4-103.7
	// cell $procmux$1716
	i_16_5c_fault_5b_31_3a_0_5d_.slice<4,0>() = (i_3_5c_failed_5b_0_3a_0_5d_ ? i_13_5c_fault_5b_31_3a_0_5d_.curr.slice<4,0>().val() : i_17_5c_fault_5b_31_3a_0_5d_.slice<4,0>().val());
	// connection
	i_16_5c_fault_5b_31_3a_0_5d_.slice<31,5>() = i_13_5c_fault_5b_31_3a_0_5d_.curr.slice<31,5>().val();
	// cells $or$receiver.v:84$159 $and$receiver.v:84$156
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5753.slice<3,0>() = or_uu<4>(and_uu<4>(i_7_5c_enabled_5b_3_3a_0_5d_, i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5756.slice<3,0>().val()), i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5754.slice<3,0>().val());
	// \src: receiver.v:118.36-118.40
	// cell $add$receiver.v:118$265
	i_add_24_receiver_2e_v_3a_118_24_263__Y = add_uu<17>(p_pp.curr, value<1>{0x1u});
	// \src: receiver.v:117.31-117.35
	// cell $add$receiver.v:117$262
	i_add_24_receiver_2e_v_3a_117_24_260__Y = add_uu<17>(p_fp.curr, value<1>{0x1u});
	// \src: receiver.v:116.31-116.35
	// cell $add$receiver.v:116$259
	i_add_24_receiver_2e_v_3a_116_24_257__Y = add_uu<17>(p_rp.curr, value<1>{0x1u});
	// \src: receiver.v:115.31-115.35
	// cell $add$receiver.v:115$256
	i_add_24_receiver_2e_v_3a_115_24_254__Y = add_uu<17>(p_cp.curr, value<1>{0x1u});
	// cells $procmux$310 $logic_or$receiver.v:112$247 $gt$receiver.v:112$245 $ne$receiver.v:112$246 $procmux$407 $procmux$404 $procmux$402 $procmux$319 $add$receiver.v:111$241 $auto$opt_reduce.cc:131:opt_pmux$5698 $procmux$398 $procmux$395 $procmux$393 $procmux$361 $add$receiver.v:111$242 $auto$opt_reduce.cc:131:opt_pmux$5692 $procmux$389 $procmux$386 $procmux$384 $procmux$347 $add$receiver.v:111$243 $auto$opt_reduce.cc:131:opt_pmux$5694 $procmux$380 $procmux$377 $procmux$375 $procmux$333 $add$receiver.v:111$244 $auto$opt_reduce.cc:131:opt_pmux$5696
	i_19_5c_fault_5b_31_3a_0_5d_.slice<5,0>() = (logic_or<1>(gt_uu<1>(i_5_5c_qlen_5b_3_3a_0_5d_, value<4>{0x8u}), ne_uu<1>((p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_3_5c_rone_5b_0_3a_0_5d_ ? (reduce_or<1>(i_procmux_24_323__CMP.concat(i_procmux_24_322__CMP).concat(i_procmux_24_321__CMP).val()) ? i_19_5c_tokens3_5b_3_3a_0_5d_ : (i_procmux_24_320__CMP ? add_uu<4>(i_19_5c_tokens3_5b_3_3a_0_5d_, value<1>{0x1u}) : value<4>{0u})) : i_19_5c_tokens3_5b_3_3a_0_5d_) : value<4>{0u})).concat((p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_3_5c_rone_5b_0_3a_0_5d_ ? (i_procmux_24_321__CMP ? add_uu<4>(i_19_5c_tokens2_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_323__CMP.concat(i_procmux_24_322__CMP).concat(i_procmux_24_320__CMP).val()) ? i_19_5c_tokens2_5b_3_3a_0_5d_ : value<4>{0u})) : i_19_5c_tokens2_5b_3_3a_0_5d_) : value<4>{0u}))).concat((p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_3_5c_rone_5b_0_3a_0_5d_ ? (i_procmux_24_322__CMP ? add_uu<4>(i_19_5c_tokens1_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_323__CMP.concat(i_procmux_24_321__CMP).concat(i_procmux_24_320__CMP).val()) ? i_19_5c_tokens1_5b_3_3a_0_5d_ : value<4>{0u})) : i_19_5c_tokens1_5b_3_3a_0_5d_) : value<4>{0u}))).concat((p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_3_5c_rone_5b_0_3a_0_5d_ ? (i_procmux_24_323__CMP ? add_uu<4>(i_19_5c_tokens0_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_322__CMP.concat(i_procmux_24_321__CMP).concat(i_procmux_24_320__CMP).val()) ? i_19_5c_tokens0_5b_3_3a_0_5d_ : value<4>{0u})) : i_19_5c_tokens0_5b_3_3a_0_5d_) : value<4>{0u}))).val(), i_5_5c_outstanding_5b_15_3a_0_5d_)) ? value<1>{0x1u}.concat(i_16_5c_fault_5b_31_3a_0_5d_.slice<4,0>()).val() : i_13_5c_fault_5b_31_3a_0_5d_.curr.slice<5>().concat(i_16_5c_fault_5b_31_3a_0_5d_.slice<4,0>()).val());
	// connection
	i_19_5c_fault_5b_31_3a_0_5d_.slice<31,6>() = i_13_5c_fault_5b_31_3a_0_5d_.curr.slice<31,6>().val();
	// cells $procmux$4472 $procmux$4324 $procmux$4265 $procmux$4196
	i_3_5c_evexpire_5b_3_3a_0_5d_.slice<0>() = (i_eq_24_receiver_2e_v_3a_58_24_75__Y ? (i_3_5c_enabled_5b_0_3a_0_5d_ ? (i_eq_24_receiver_2e_v_3a_61_24_76__Y ? value<1>{0u} : (i_eq_24_receiver_2e_v_3a_62_24_79__Y ? value<1>{0x1u} : value<1>{0u})) : value<1>{0u}) : value<1>{0u});
	// cells $procmux$4436 $procmux$4135 $procmux$4076 $procmux$4007
	i_3_5c_evexpire_5b_3_3a_0_5d_.slice<1>() = (i_eq_24_receiver_2e_v_3a_58_24_75__Y ? (i_4_5c_enabled_5b_1_3a_1_5d_ ? (i_eq_24_receiver_2e_v_3a_61_24_80__Y ? value<1>{0u} : (i_eq_24_receiver_2e_v_3a_62_24_83__Y ? value<1>{0x1u} : value<1>{0u})) : value<1>{0u}) : value<1>{0u});
	// cells $procmux$4391 $procmux$3946 $procmux$3887 $procmux$3818
	i_3_5c_evexpire_5b_3_3a_0_5d_.slice<2>() = (i_eq_24_receiver_2e_v_3a_58_24_75__Y ? (i_5_5c_enabled_5b_2_3a_2_5d_ ? (i_eq_24_receiver_2e_v_3a_61_24_84__Y ? value<1>{0u} : (i_eq_24_receiver_2e_v_3a_62_24_87__Y ? value<1>{0x1u} : value<1>{0u})) : value<1>{0u}) : value<1>{0u});
	// cells $procmux$3636 $procmux$3757 $procmux$3698 $procmux$4537
	i_3_5c_evexpire_5b_3_3a_0_5d_.slice<3>() = (i_eq_24_receiver_2e_v_3a_58_24_75__Y ? (i_6_5c_enabled_5b_3_3a_3_5d_ ? (i_eq_24_receiver_2e_v_3a_61_24_88__Y ? value<1>{0u} : (i_eq_24_receiver_2e_v_3a_62_24_91__Y ? value<1>{0x1u} : value<1>{0u})) : value<1>{0u}) : value<1>{0u});
	// cells $procmux$301 $logic_or$receiver.v:113$251 $ge$receiver.v:113$249 $ge$receiver.v:113$250
	i_20_5c_fault_5b_31_3a_0_5d_.slice<6,0>() = (logic_or<1>(ge_uu<1>(p_tick.curr, value<31>{0x7ffffffeu}), ge_uu<1>(i_3_5c_nextid_5b_31_3a_0_5d_, value<31>{0x7ffffffeu})) ? value<1>{0x1u}.concat(i_19_5c_fault_5b_31_3a_0_5d_.slice<5,0>()).val() : i_13_5c_fault_5b_31_3a_0_5d_.curr.slice<6>().concat(i_19_5c_fault_5b_31_3a_0_5d_.slice<5,0>()).val());
	// connection
	i_20_5c_fault_5b_31_3a_0_5d_.slice<31,7>() = i_13_5c_fault_5b_31_3a_0_5d_.curr.slice<31,7>().val();
	// cells $procmux$5212 $procmux$4661
	i_2_5c_evwu_5b_3_3a_0_5d_.slice<0>() = (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_logic__and_24_receiver_2e_v_3a_56_24_71__Y ? value<1>{0x1u} : value<1>{0u}) : p_evwu.curr.slice<0>().val());
	// cells $procmux$5200 $procmux$4625
	i_2_5c_evwu_5b_3_3a_0_5d_.slice<1>() = (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_logic__and_24_receiver_2e_v_3a_56_24_72__Y ? value<1>{0x1u} : value<1>{0u}) : p_evwu.curr.slice<1>().val());
	// cells $procmux$5188 $procmux$4589
	i_2_5c_evwu_5b_3_3a_0_5d_.slice<2>() = (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_logic__and_24_receiver_2e_v_3a_56_24_73__Y ? value<1>{0x1u} : value<1>{0u}) : p_evwu.curr.slice<2>().val());
	// cells $procmux$267 $procmux$4553
	i_2_5c_evwu_5b_3_3a_0_5d_.slice<3>() = (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_logic__and_24_receiver_2e_v_3a_56_24_74__Y ? value<1>{0x1u} : value<1>{0u}) : p_evwu.curr.slice<3>().val());
	// \full_case: 1
	// \src: receiver.v:52.15-52.34|receiver.v:52.12-119.6
	// cell $procmux$5224
	i_2_5c_bytes_5b_31_3a_0_5d_.slice<31,24>() = (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? i_6_5c_bytes_5b_31_3a_24_5d_ : p_bytes.curr.slice<31,24>().val());
	// \full_case: 1
	// \src: receiver.v:52.15-52.34|receiver.v:52.12-119.6
	// cell $procmux$5218
	i_2_5c_bytes_5b_31_3a_0_5d_.slice<7,0>() = (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? i_3_5c_bytes_5b_7_3a_0_5d_ : p_bytes.curr.slice<7,0>().val());
	// \full_case: 1
	// \src: receiver.v:52.15-52.34|receiver.v:52.12-119.6
	// cell $procmux$5206
	i_2_5c_bytes_5b_31_3a_0_5d_.slice<15,8>() = (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? i_4_5c_bytes_5b_15_3a_8_5d_ : p_bytes.curr.slice<15,8>().val());
	// \full_case: 1
	// \src: receiver.v:52.15-52.34|receiver.v:52.12-119.6
	// cell $procmux$5194
	i_2_5c_bytes_5b_31_3a_0_5d_.slice<23,16>() = (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? i_5_5c_bytes_5b_23_3a_16_5d_ : p_bytes.curr.slice<23,16>().val());
	// cells $procdff$5585 $procmux$5395 $procmux$4888 $procmux$2310 $procmux$1927
	if (posedge_p_clk) {
		p_qi_5b_7_5d_.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_logic__and_24_receiver_2e_v_3a_78_24_133__Y ? (i_shiftx_24_receiver_2e_v_3a_80_24_137__Y ? value<32>{0u} : i_3_5c_qi_5b_7_5d__5b_31_3a_0_5d_) : i_3_5c_qi_5b_7_5d__5b_31_3a_0_5d_) : p_qi_5b_7_5d_.curr));
	}
	// cells $procdff$5584 $procmux$5401 $procmux$4894 $procmux$2319 $procmux$1939
	if (posedge_p_clk) {
		p_qi_5b_6_5d_.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_logic__and_24_receiver_2e_v_3a_78_24_133__Y ? (i_shiftx_24_receiver_2e_v_3a_80_24_137__Y ? i_3_5c_qi_5b_7_5d__5b_31_3a_0_5d_ : i_3_5c_qi_5b_6_5d__5b_31_3a_0_5d_) : i_3_5c_qi_5b_6_5d__5b_31_3a_0_5d_) : p_qi_5b_6_5d_.curr));
	}
	// cells $procdff$5583 $procmux$5407 $procmux$4900 $procmux$2328 $procmux$1951
	if (posedge_p_clk) {
		p_qi_5b_5_5d_.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_logic__and_24_receiver_2e_v_3a_78_24_133__Y ? (i_shiftx_24_receiver_2e_v_3a_80_24_137__Y ? i_3_5c_qi_5b_6_5d__5b_31_3a_0_5d_ : i_3_5c_qi_5b_5_5d__5b_31_3a_0_5d_) : i_3_5c_qi_5b_5_5d__5b_31_3a_0_5d_) : p_qi_5b_5_5d_.curr));
	}
	// cells $procdff$5582 $procmux$5413 $procmux$4906 $procmux$2337 $procmux$1963
	if (posedge_p_clk) {
		p_qi_5b_4_5d_.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_logic__and_24_receiver_2e_v_3a_78_24_133__Y ? (i_shiftx_24_receiver_2e_v_3a_80_24_137__Y ? i_3_5c_qi_5b_5_5d__5b_31_3a_0_5d_ : i_3_5c_qi_5b_4_5d__5b_31_3a_0_5d_) : i_3_5c_qi_5b_4_5d__5b_31_3a_0_5d_) : p_qi_5b_4_5d_.curr));
	}
	// cells $procdff$5581 $procmux$5419 $procmux$4912 $procmux$2346 $procmux$1975
	if (posedge_p_clk) {
		p_qi_5b_3_5d_.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_logic__and_24_receiver_2e_v_3a_78_24_133__Y ? (i_shiftx_24_receiver_2e_v_3a_80_24_137__Y ? i_3_5c_qi_5b_4_5d__5b_31_3a_0_5d_ : i_3_5c_qi_5b_3_5d__5b_31_3a_0_5d_) : i_3_5c_qi_5b_3_5d__5b_31_3a_0_5d_) : p_qi_5b_3_5d_.curr));
	}
	// cells $procdff$5580 $procmux$5425 $procmux$4918 $procmux$2355 $procmux$1987
	if (posedge_p_clk) {
		p_qi_5b_2_5d_.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_logic__and_24_receiver_2e_v_3a_78_24_133__Y ? (i_shiftx_24_receiver_2e_v_3a_80_24_137__Y ? i_3_5c_qi_5b_3_5d__5b_31_3a_0_5d_ : i_3_5c_qi_5b_2_5d__5b_31_3a_0_5d_) : i_3_5c_qi_5b_2_5d__5b_31_3a_0_5d_) : p_qi_5b_2_5d_.curr));
	}
	// cells $procdff$5579 $procmux$5431 $procmux$4924 $procmux$2364 $procmux$1999
	if (posedge_p_clk) {
		p_qi_5b_1_5d_.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_logic__and_24_receiver_2e_v_3a_78_24_133__Y ? (i_shiftx_24_receiver_2e_v_3a_80_24_137__Y ? i_3_5c_qi_5b_2_5d__5b_31_3a_0_5d_ : i_3_5c_qi_5b_1_5d__5b_31_3a_0_5d_) : i_3_5c_qi_5b_1_5d__5b_31_3a_0_5d_) : p_qi_5b_1_5d_.curr));
	}
	// cells $procdff$5578 $procmux$5437 $procmux$4930 $procmux$2373 $procmux$2011
	if (posedge_p_clk) {
		p_qi_5b_0_5d_.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_logic__and_24_receiver_2e_v_3a_78_24_133__Y ? (i_shiftx_24_receiver_2e_v_3a_80_24_137__Y ? i_3_5c_qi_5b_1_5d__5b_31_3a_0_5d_ : i_3_5c_qi_5b_0_5d__5b_31_3a_0_5d_) : i_3_5c_qi_5b_0_5d__5b_31_3a_0_5d_) : p_qi_5b_0_5d_.curr));
	}
	// cells $procdff$5577 $procmux$5398 $procmux$4936
	if (posedge_p_clk) {
		p_qo_5b_7_5d_.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? i_6_5c_qo_5b_7_5d__5b_1_3a_0_5d_ : p_qo_5b_7_5d_.curr));
	}
	// cells $procdff$5576 $procmux$5404 $procmux$4942
	if (posedge_p_clk) {
		p_qo_5b_6_5d_.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? i_6_5c_qo_5b_6_5d__5b_1_3a_0_5d_ : p_qo_5b_6_5d_.curr));
	}
	// cells $procdff$5575 $procmux$5410 $procmux$4948
	if (posedge_p_clk) {
		p_qo_5b_5_5d_.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? i_6_5c_qo_5b_5_5d__5b_1_3a_0_5d_ : p_qo_5b_5_5d_.curr));
	}
	// cells $procdff$5574 $procmux$5416 $procmux$4954
	if (posedge_p_clk) {
		p_qo_5b_4_5d_.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? i_6_5c_qo_5b_4_5d__5b_1_3a_0_5d_ : p_qo_5b_4_5d_.curr));
	}
	// cells $procdff$5573 $procmux$5422 $procmux$4960
	if (posedge_p_clk) {
		p_qo_5b_3_5d_.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? i_6_5c_qo_5b_3_5d__5b_1_3a_0_5d_ : p_qo_5b_3_5d_.curr));
	}
	// cells $procdff$5572 $procmux$5428 $procmux$4966
	if (posedge_p_clk) {
		p_qo_5b_2_5d_.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? i_6_5c_qo_5b_2_5d__5b_1_3a_0_5d_ : p_qo_5b_2_5d_.curr));
	}
	// cells $procdff$5571 $procmux$5434 $procmux$4972
	if (posedge_p_clk) {
		p_qo_5b_1_5d_.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? i_6_5c_qo_5b_1_5d__5b_1_3a_0_5d_ : p_qo_5b_1_5d_.curr));
	}
	// cells $procdff$5570 $procmux$5440 $procmux$4978
	if (posedge_p_clk) {
		p_qo_5b_0_5d_.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? i_6_5c_qo_5b_0_5d__5b_1_3a_0_5d_ : p_qo_5b_0_5d_.curr));
	}
	// cells $procdff$5556 $procmux$5275 $procmux$4768 $procmux$1734 $procmux$1417
	if (posedge_p_clk) {
		p_transferbyte.next = (p_rst ? value<8>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? p_transferbyte.curr : (i_logic__and_24_receiver_2e_v_3a_94_24_176__Y ? i_3_5c_bytezero_5b_7_3a_0_5d_ : p_transferbyte.curr)) : p_transferbyte.curr));
	}
	// cells $procdff$5555 $procmux$5278 $procmux$4774 $procmux$1815 $procmux$1585 $procmux$1481
	if (posedge_p_clk) {
		p_emitbyte.next = (p_rst ? value<8>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? p_emitbyte.curr : (p_rone.curr ? (i_logic__or_24_receiver_2e_v_3a_91_24_174__Y ? p_byteone.curr : p_emitbyte.curr) : p_emitbyte.curr)) : p_emitbyte.curr));
	}
	// cells $procdff$5554 $procmux$5281 $procmux$5002 $procmux$2490 $procmux$2167
	if (posedge_p_clk) {
		p_grantbyte.next = (p_rst ? value<8>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_logic__and_24_receiver_2e_v_3a_78_24_133__Y ? (i_shiftx_24_receiver_2e_v_3a_80_24_137__Y ? i_shiftx_24_receiver_2e_v_3a_82_24_144__Y : p_grantbyte.curr) : p_grantbyte.curr) : p_grantbyte.curr));
	}
	// cells $procdff$5553 $procmux$5284 $procmux$4780 $procmux$1824 $procmux$1597 $procmux$1541
	if (posedge_p_clk) {
		p_blockid.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? p_blockid.curr : (p_rone.curr ? (i_logic__or_24_receiver_2e_v_3a_91_24_174__Y ? p_blockid.curr : p_idone.curr) : p_blockid.curr)) : p_blockid.curr));
	}
	// cells $procdff$5552 $procmux$5287 $procmux$4786 $procmux$1689 $procmux$1321
	if (posedge_p_clk) {
		p_callbackid.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? p_callbackid.curr : (i_4_5c_evemit_5b_0_3a_0_5d_ ? i_4_5c_emitid_5b_31_3a_0_5d_ : p_callbackid.curr)) : p_callbackid.curr));
	}
	// cells $procdff$5551 $procmux$5290 $procmux$4792 $procmux$1743 $procmux$1429
	if (posedge_p_clk) {
		p_transferid.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? p_transferid.curr : (i_logic__and_24_receiver_2e_v_3a_94_24_176__Y ? i_3_5c_idzero_5b_31_3a_0_5d_ : p_transferid.curr)) : p_transferid.curr));
	}
	// cells $procdff$5550 $procmux$5293 $procmux$4798 $procmux$1833
	if (posedge_p_clk) {
		p_emitid.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? p_emitid.curr : i_4_5c_emitid_5b_31_3a_0_5d_) : p_emitid.curr));
	}
	// cells $procdff$5549 $procmux$5296 $procmux$5008 $procmux$2499 $procmux$2179
	if (posedge_p_clk) {
		p_grantid.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_logic__and_24_receiver_2e_v_3a_78_24_133__Y ? (i_shiftx_24_receiver_2e_v_3a_80_24_137__Y ? i_3_5c_qi_5b_0_5d__5b_31_3a_0_5d_ : p_grantid.curr) : p_grantid.curr) : p_grantid.curr));
	}
	// cells $procdff$5548 $procmux$5299 $procmux$5014 $procmux$2634
	if (posedge_p_clk) {
		p_attemptid.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_logic__and_24_receiver_2e_v_3a_78_24_133__Y ? i_3_5c_qi_5b_0_5d__5b_31_3a_0_5d_ : p_attemptid.curr) : p_attemptid.curr));
	}
	// cells $procdff$5547 $procmux$5302 $procmux$5140 $procmux$3537 $procmux$3277
	if (posedge_p_clk) {
		p_enqid.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_4_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_70_24_102__Y ? p_enqid.curr : p_nextid.curr) : p_enqid.curr) : p_enqid.curr));
	}
	// cells $procdff$5546 $procmux$5305 $procmux$4804 $procmux$1842 $procmux$1621 $procmux$1556
	if (posedge_p_clk) {
		p_blockowner.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? p_blockowner.curr : (p_rone.curr ? (i_logic__or_24_receiver_2e_v_3a_91_24_174__Y ? p_blockowner.curr : p_ownerone.curr) : p_blockowner.curr)) : p_blockowner.curr));
	}
	// cells $procdff$5545 $procmux$5308 $procmux$4810 $procmux$1698 $procmux$1333
	if (posedge_p_clk) {
		p_callbackowner.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? p_callbackowner.curr : (i_4_5c_evemit_5b_0_3a_0_5d_ ? i_4_5c_emitowner_5b_1_3a_0_5d_ : p_callbackowner.curr)) : p_callbackowner.curr));
	}
	// cells $procdff$5544 $procmux$5311 $procmux$4816 $procmux$1752 $procmux$1441
	if (posedge_p_clk) {
		p_transferowner.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? p_transferowner.curr : (i_logic__and_24_receiver_2e_v_3a_94_24_176__Y ? i_3_5c_ownerzero_5b_1_3a_0_5d_ : p_transferowner.curr)) : p_transferowner.curr));
	}
	// cells $procdff$5543 $procmux$5314 $procmux$4822 $procmux$1851
	if (posedge_p_clk) {
		p_emitowner.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? p_emitowner.curr : i_4_5c_emitowner_5b_1_3a_0_5d_) : p_emitowner.curr));
	}
	// cells $procdff$5542 $procmux$5317 $procmux$5020 $procmux$2508 $procmux$2191
	if (posedge_p_clk) {
		p_grantowner.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_logic__and_24_receiver_2e_v_3a_78_24_133__Y ? (i_shiftx_24_receiver_2e_v_3a_80_24_137__Y ? i_3_5c_qo_5b_0_5d__5b_1_3a_0_5d_ : p_grantowner.curr) : p_grantowner.curr) : p_grantowner.curr));
	}
	// cells $procdff$5541 $procmux$5320 $procmux$5026 $procmux$2643
	if (posedge_p_clk) {
		p_attemptowner.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_logic__and_24_receiver_2e_v_3a_78_24_133__Y ? i_3_5c_qo_5b_0_5d__5b_1_3a_0_5d_ : p_attemptowner.curr) : p_attemptowner.curr));
	}
	// cells $procdff$5540 $procmux$5323 $procmux$5146 $procmux$3546 $procmux$3289
	if (posedge_p_clk) {
		p_enqowner.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_4_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_70_24_102__Y ? p_enqowner.curr : i_4_5c_releaseowner_5b_1_3a_0_5d_) : p_enqowner.curr) : p_enqowner.curr));
	}
	// cells $procdff$5539 $procmux$5326 $procmux$4828 $procmux$1860
	if (posedge_p_clk) {
		p_evblock.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? value<1>{0u} : i_4_5c_evblock_5b_0_3a_0_5d_) : p_evblock.curr));
	}
	// cells $procdff$5538 $procmux$5329 $procmux$4834 $procmux$1707 $procmux$1345
	if (posedge_p_clk) {
		p_evcallback.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? value<1>{0u} : (i_4_5c_evemit_5b_0_3a_0_5d_ ? value<1>{0x1u} : value<1>{0u})) : p_evcallback.curr));
	}
	// cells $procdff$5537 $procmux$5332 $procmux$4840 $procmux$1761 $procmux$1453
	if (posedge_p_clk) {
		p_evtransfer.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_94_24_176__Y ? value<1>{0x1u} : value<1>{0u})) : p_evtransfer.curr));
	}
	// cells $procdff$5536 $procmux$5335 $procmux$4846 $procmux$1869
	if (posedge_p_clk) {
		p_evemit.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? value<1>{0u} : i_4_5c_evemit_5b_0_3a_0_5d_) : p_evemit.curr));
	}
	// cells $procdff$5535 $procmux$5338 $procmux$5032 $procmux$2517 $procmux$2203
	if (posedge_p_clk) {
		p_evgrant.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_logic__and_24_receiver_2e_v_3a_78_24_133__Y ? (i_shiftx_24_receiver_2e_v_3a_80_24_137__Y ? value<1>{0x1u} : value<1>{0u}) : value<1>{0u}) : p_evgrant.curr));
	}
	// cells $procdff$5534 $procmux$5341 $procmux$5038 $procmux$2652
	if (posedge_p_clk) {
		p_evattempt.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_logic__and_24_receiver_2e_v_3a_78_24_133__Y ? value<1>{0x1u} : value<1>{0u}) : p_evattempt.curr));
	}
	// cells $procdff$5533 $procmux$5344 $procmux$5152 $procmux$3555 $procmux$3301
	if (posedge_p_clk) {
		p_evenq.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_4_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_70_24_102__Y ? value<1>{0u} : value<1>{0x1u}) : value<1>{0u}) : p_evenq.curr));
	}
	// cells $procdff$5532 $procmux$5347 $procmux$5044 $procmux$2526 $procmux$2215 $shift$receiver.v:84$151 $shiftx$receiver.v:84$149
	if (posedge_p_clk) {
		p_evcancel.next = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_logic__and_24_receiver_2e_v_3a_78_24_133__Y ? (i_shiftx_24_receiver_2e_v_3a_80_24_137__Y ? shift_us<4>(shiftx_uu<1>(i_7_5c_enabled_5b_3_3a_0_5d_, i_3_5c_qo_5b_0_5d__5b_1_3a_0_5d_), i_neg_24_receiver_2e_v_3a_84_24_150__Y) : value<4>{0u}) : value<4>{0u}) : p_evcancel.curr));
	}
	// cells $procdff$5531 $procmux$5350 $procmux$5176
	if (posedge_p_clk) {
		p_evexpire.next = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? i_3_5c_evexpire_5b_3_3a_0_5d_ : p_evexpire.curr));
	}
	// cells $procdff$5530 $procmux$5353
	if (posedge_p_clk) {
		p_evwu.next = (p_rst ? value<4>{0u} : i_2_5c_evwu_5b_3_3a_0_5d_);
	}
	// cells $procdff$5529 $procmux$5356 $procmux$5050 $procmux$2535 $procmux$1891
	if (posedge_p_clk) {
		p_failowner.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_logic__and_24_receiver_2e_v_3a_78_24_133__Y ? (i_shiftx_24_receiver_2e_v_3a_80_24_137__Y ? p_failowner.curr : i_3_5c_qo_5b_0_5d__5b_1_3a_0_5d_) : p_failowner.curr) : p_failowner.curr));
	}
	// cells $procdff$5528 $procmux$5251 $procmux$4726 $procmux$5246 $logic_or$receiver.v:51$58 $logic_or$receiver.v:51$56 $logic_or$receiver.v:51$54 $logic_or$receiver.v:51$52 $logic_or$receiver.v:51$50 $logic_or$receiver.v:51$48 $logic_or$receiver.v:51$46 $logic_or$receiver.v:51$44 $logic_or$receiver.v:51$42 $logic_or$receiver.v:51$40 $logic_or$receiver.v:51$38 $logic_or$receiver.v:51$34 $lt$receiver.v:51$32 $gt$receiver.v:51$33 $logic_and$receiver.v:51$37 $ne$receiver.v:51$35 $ne$receiver.v:51$36 $lt$receiver.v:51$39 $gt$receiver.v:51$41 $eq$receiver.v:51$43 $eq$receiver.v:51$45 $gt$receiver.v:51$47 $ge$receiver.v:51$49 $ge$receiver.v:51$51 $ge$receiver.v:51$53 $ge$receiver.v:51$55 $ge$receiver.v:51$57
	if (posedge_p_clk) {
		p_fault.next = (p_rst ? value<31>{0u}.concat((logic_or<1>(logic_or<1>(logic_or<1>(logic_or<1>(logic_or<1>(logic_or<1>(logic_or<1>(logic_or<1>(logic_or<1>(logic_or<1>(logic_or<1>(logic_or<1>(lt_uu<1>(p_cfgp, value<2>{0x2u}), gt_uu<1>(p_cfgp, value<5>{0x11u})), logic_and<1>(ne_uu<1>(p_cfgr, value<3>{0x5u}), ne_uu<1>(p_cfgr, value<3>{0x7u}))), lt_uu<1>(p_cfgf, value<6>{0x2cu})), gt_uu<1>(p_cfgf, value<10>{0x3b8u})), logic_not<1>(p_cfgk)), logic_not<1>(p_cfgperiod)), gt_uu<1>(p_cfgperiod, value<7>{0x44u})), ge_uu<1>(p_cfgphi, p_cfgperiod)), ge_uu<1>(p_cfgcp, p_cfgp)), ge_uu<1>(p_cfgrp, p_cfgr)), ge_uu<1>(p_cfgfp, p_cfgf)), ge_uu<1>(p_cfgpp, p_cfgperiod)) ? value<1>{0x1u} : value<1>{0u})).val() : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? i_13_5c_fault_5b_31_3a_0_5d_.curr.slice<31,7>().concat(i_20_5c_fault_5b_31_3a_0_5d_.slice<6,0>()).val() : p_fault.curr));
	}
	// cells $procdff$5527 $procmux$5359 $procmux$5056 $procmux$2544 $procmux$1879
	if (posedge_p_clk) {
		p_failid.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_logic__and_24_receiver_2e_v_3a_78_24_133__Y ? (i_shiftx_24_receiver_2e_v_3a_80_24_137__Y ? p_failid.curr : i_3_5c_qi_5b_0_5d__5b_31_3a_0_5d_) : p_failid.curr) : p_failid.curr));
	}
	// cells $procdff$5526 $procmux$5362 $procmux$5062 $procmux$2553 $procmux$1903
	if (posedge_p_clk) {
		p_failtick.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_logic__and_24_receiver_2e_v_3a_78_24_133__Y ? (i_shiftx_24_receiver_2e_v_3a_80_24_137__Y ? p_failtick.curr : p_tick.curr) : p_failtick.curr) : p_failtick.curr));
	}
	// cells $procdff$5525 $procmux$5365 $procmux$5068
	if (posedge_p_clk) {
		p_failed.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? i_3_5c_failed_5b_0_3a_0_5d_ : p_failed.curr));
	}
	// cells $procdff$5524 $procmux$5368 $procmux$4852 $procmux$1770 $procmux$1369
	if (posedge_p_clk) {
		p_byteone.next = (p_rst ? value<8>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? p_byteone.curr : (i_logic__and_24_receiver_2e_v_3a_94_24_176__Y ? i_3_5c_bytezero_5b_7_3a_0_5d_ : p_byteone.curr)) : p_byteone.curr));
	}
	// cells $procdff$5523 $procmux$5371 $procmux$5074
	if (posedge_p_clk) {
		p_bytezero.next = (p_rst ? value<8>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? i_3_5c_bytezero_5b_7_3a_0_5d_ : p_bytezero.curr));
	}
	// cells $procdff$5522 $procmux$5374 $procmux$4858 $procmux$1779 $procmux$1381
	if (posedge_p_clk) {
		p_idone.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? p_idone.curr : (i_logic__and_24_receiver_2e_v_3a_94_24_176__Y ? i_3_5c_idzero_5b_31_3a_0_5d_ : p_idone.curr)) : p_idone.curr));
	}
	// cells $procdff$5521 $procmux$5377 $procmux$5080
	if (posedge_p_clk) {
		p_idzero.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? i_3_5c_idzero_5b_31_3a_0_5d_ : p_idzero.curr));
	}
	// cells $procdff$5520 $procmux$5380 $procmux$4864
	if (posedge_p_clk) {
		p_ownerone.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? i_3_5c_ownerone_5b_1_3a_0_5d_ : p_ownerone.curr));
	}
	// cells $procdff$5519 $procmux$5383 $procmux$5086
	if (posedge_p_clk) {
		p_ownerzero.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? i_3_5c_ownerzero_5b_1_3a_0_5d_ : p_ownerzero.curr));
	}
	// cells $procdff$5518 $procmux$5386 $procmux$4870
	if (posedge_p_clk) {
		p_rone.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? i_3_5c_rone_5b_0_3a_0_5d_ : p_rone.curr));
	}
	// cells $procdff$5517 $procmux$5389 $procmux$4876
	if (posedge_p_clk) {
		p_rzero.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? i_5_5c_rzero_5b_0_3a_0_5d_ : p_rzero.curr));
	}
	// cells $procdff$5516 $procmux$5443 $procmux$4882
	if (posedge_p_clk) {
		p_outstanding.next = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? i_5_5c_outstanding_5b_15_3a_0_5d_ : p_outstanding.curr));
	}
	// cells $procdff$5515 $procmux$5446 $procmux$5092
	if (posedge_p_clk) {
		p_qlen.next = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? i_5_5c_qlen_5b_3_3a_0_5d_ : p_qlen.curr));
	}
	// cells $procdff$5514 $procmux$5449
	if (posedge_p_clk) {
		p_bytes.next = (p_rst ? value<32>{0u} : i_2_5c_bytes_5b_31_3a_0_5d_);
	}
	// cells $procdff$5513 $procmux$5452 $procmux$5098 $procmux$2616 $procmux$2287 $or$receiver.v:84$168 $and$receiver.v:84$165 $not$receiver.v:84$164 $shift$receiver.v:84$163 $shift$receiver.v:84$167
	if (posedge_p_clk) {
		p_counts.next = (p_rst ? value<64>{0u,0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_logic__and_24_receiver_2e_v_3a_78_24_133__Y ? (i_shiftx_24_receiver_2e_v_3a_80_24_137__Y ? or_uu<64>(and_uu<64>(i_7_5c_counts_5b_63_3a_0_5d_, not_u<64>(shift_us<64>(value<16>{0xffffu}, i_neg_24_receiver_2e_v_3a_84_24_162__Y))), shift_us<64>(value<1>{0u}, i_neg_24_receiver_2e_v_3a_84_24_162__Y)) : i_7_5c_counts_5b_63_3a_0_5d_) : i_7_5c_counts_5b_63_3a_0_5d_) : p_counts.curr));
	}
	// cells $procdff$5512 $procmux$5455 $procmux$5104 $procmux$2625 $procmux$2299
	if (posedge_p_clk) {
		p_enabled.next = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (i_logic__and_24_receiver_2e_v_3a_78_24_133__Y ? (i_shiftx_24_receiver_2e_v_3a_80_24_137__Y ? i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_5753.slice<3,0>().val() : i_7_5c_enabled_5b_3_3a_0_5d_) : i_7_5c_enabled_5b_3_3a_0_5d_) : p_enabled.curr));
	}
	// cells $procdff$5511 $procmux$5458 $procmux$5182
	if (posedge_p_clk) {
		p_valid.next = (p_rst ? value<4>{0xfu} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? i_3_5c_valid_5b_3_3a_0_5d_ : p_valid.curr));
	}
	// cells $procdff$5510 $procmux$5461 $procmux$4696 $procmux$5231 $eq$receiver.v:118$264
	if (posedge_p_clk) {
		p_pp.next = (p_rst ? p_cfgpp : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (eq_uu<1>(i_add_24_receiver_2e_v_3a_118_24_263__Y, value<1>{0u}.concat(p_cfgperiod).val()) ? value<16>{0u} : i_add_24_receiver_2e_v_3a_118_24_263__Y.slice<15,0>().val()) : p_pp.curr));
	}
	// cells $procdff$5509 $procmux$5464 $procmux$4702 $procmux$274 $eq$receiver.v:117$261
	if (posedge_p_clk) {
		p_fp.next = (p_rst ? p_cfgfp : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (eq_uu<1>(i_add_24_receiver_2e_v_3a_117_24_260__Y, value<1>{0u}.concat(p_cfgf).val()) ? value<16>{0u} : i_add_24_receiver_2e_v_3a_117_24_260__Y.slice<15,0>().val()) : p_fp.curr));
	}
	// cells $procdff$5508 $procmux$5467 $procmux$4708 $procmux$283 $eq$receiver.v:116$258
	if (posedge_p_clk) {
		p_rp.next = (p_rst ? p_cfgrp : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (eq_uu<1>(i_add_24_receiver_2e_v_3a_116_24_257__Y, value<1>{0u}.concat(p_cfgr).val()) ? value<16>{0u} : i_add_24_receiver_2e_v_3a_116_24_257__Y.slice<15,0>().val()) : p_rp.curr));
	}
	// cells $procdff$5507 $procmux$5470 $procmux$4714 $procmux$292 $eq$receiver.v:115$255
	if (posedge_p_clk) {
		p_cp.next = (p_rst ? p_cfgcp : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? (eq_uu<1>(i_add_24_receiver_2e_v_3a_115_24_254__Y, value<1>{0u}.concat(p_cfgp).val()) ? value<16>{0u} : i_add_24_receiver_2e_v_3a_115_24_254__Y.slice<15,0>().val()) : p_cp.curr));
	}
	// cells $procdff$5506 $procmux$5473 $procmux$5158
	if (posedge_p_clk) {
		p_nextid.next = (p_rst ? value<32>{0x1u} : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? i_3_5c_nextid_5b_31_3a_0_5d_ : p_nextid.curr));
	}
	// cells $procdff$5505 $procmux$5476 $procmux$4720 $add$receiver.v:114$253
	if (posedge_p_clk) {
		p_tick.next = (p_rst ? p_cfgstart : (i_logic__and_24_receiver_2e_v_3a_52_24_61__Y ? add_uu<32>(p_tick.curr, value<1>{0x1u}) : p_tick.curr));
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
			{ "src", "receiver.v:3.1-121.10" },
		}), std::move(cell_attrs));
	}
	if (items) {
		items->add(path, "13\\fault[31:0]", "src\000sreceiver.v:39.2-120.5\000", i_13_5c_fault_5b_31_3a_0_5d_, 0, debug_item::GENERATED|debug_item::DRIVEN_COMB);
		items->add(path, "attemptid", "src\000sreceiver.v:29.26-29.35\000", p_attemptid, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "attemptowner", "src\000sreceiver.v:28.28-28.40\000", p_attemptowner, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "blockid", "src\000sreceiver.v:29.73-29.80\000", p_blockid, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "blockowner", "src\000sreceiver.v:28.90-28.100\000", p_blockowner, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "byteone", "src\000sreceiver.v:22.28-22.35\000", p_byteone, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "bytes", "src\000sreceiver.v:14.20-14.25\000", p_bytes, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "bytezero", "src\000sreceiver.v:22.19-22.27\000", p_bytezero, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "callbackid", "src\000sreceiver.v:29.62-29.72\000", p_callbackid, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "callbackowner", "src\000sreceiver.v:28.76-28.89\000", p_callbackowner, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
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
		items->add(path, "emitbyte", "src\000sreceiver.v:30.29-30.37\000", p_emitbyte, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "emitid", "src\000sreceiver.v:29.44-29.50\000", p_emitid, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "emitowner", "src\000sreceiver.v:28.52-28.61\000", p_emitowner, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "enabled", "src\000sreceiver.v:12.25-12.32\000", p_enabled, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "enqid", "src\000sreceiver.v:29.20-29.25\000", p_enqid, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "enqowner", "src\000sreceiver.v:28.19-28.27\000", p_enqowner, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "evattempt", "src\000sreceiver.v:27.19-27.28\000", p_evattempt, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "evblock", "src\000sreceiver.v:27.66-27.73\000", p_evblock, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "evcallback", "src\000sreceiver.v:27.55-27.65\000", p_evcallback, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "evcancel", "src\000sreceiver.v:26.33-26.41\000", p_evcancel, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "evemit", "src\000sreceiver.v:27.37-27.43\000", p_evemit, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "evenq", "src\000sreceiver.v:27.13-27.18\000", p_evenq, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "evexpire", "src\000sreceiver.v:26.24-26.32\000", p_evexpire, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "evgrant", "src\000sreceiver.v:27.29-27.36\000", p_evgrant, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "evtransfer", "src\000sreceiver.v:27.44-27.54\000", p_evtransfer, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "evwu", "src\000sreceiver.v:26.19-26.23\000", p_evwu, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "failed", "src\000sreceiver.v:23.13-23.19\000", p_failed, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "failid", "src\000sreceiver.v:24.29-24.35\000", p_failid, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "failowner", "src\000sreceiver.v:25.19-25.28\000", p_failowner, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "failtick", "src\000sreceiver.v:24.20-24.28\000", p_failtick, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "fault", "src\000sreceiver.v:24.36-24.41\000", p_fault, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "fp", "src\000sreceiver.v:11.26-11.28\000", p_fp, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "grantbyte", "src\000sreceiver.v:30.19-30.28\000", p_grantbyte, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "grantid", "src\000sreceiver.v:29.36-29.43\000", p_grantid, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "grantowner", "src\000sreceiver.v:28.41-28.51\000", p_grantowner, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "idone", "src\000sreceiver.v:21.27-21.32\000", p_idone, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "idzero", "src\000sreceiver.v:21.20-21.26\000", p_idzero, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "nextid", "src\000sreceiver.v:10.25-10.31\000", p_nextid, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "outstanding", "src\000sreceiver.v:18.20-18.31\000", p_outstanding, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "ownerone", "src\000sreceiver.v:20.29-20.37\000", p_ownerone, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "ownerzero", "src\000sreceiver.v:20.19-20.28\000", p_ownerzero, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "pp", "src\000sreceiver.v:11.29-11.31\000", p_pp, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "qi[0]", "src\000sreceiver.v:32.32-32.34\000", p_qi_5b_0_5d_, 0, debug_item::DRIVEN_SYNC);
		items->add(path, "qi[1]", "src\000sreceiver.v:32.32-32.34\000", p_qi_5b_1_5d_, 0, debug_item::DRIVEN_SYNC);
		items->add(path, "qi[2]", "src\000sreceiver.v:32.32-32.34\000", p_qi_5b_2_5d_, 0, debug_item::DRIVEN_SYNC);
		items->add(path, "qi[3]", "src\000sreceiver.v:32.32-32.34\000", p_qi_5b_3_5d_, 0, debug_item::DRIVEN_SYNC);
		items->add(path, "qi[4]", "src\000sreceiver.v:32.32-32.34\000", p_qi_5b_4_5d_, 0, debug_item::DRIVEN_SYNC);
		items->add(path, "qi[5]", "src\000sreceiver.v:32.32-32.34\000", p_qi_5b_5_5d_, 0, debug_item::DRIVEN_SYNC);
		items->add(path, "qi[6]", "src\000sreceiver.v:32.32-32.34\000", p_qi_5b_6_5d_, 0, debug_item::DRIVEN_SYNC);
		items->add(path, "qi[7]", "src\000sreceiver.v:32.32-32.34\000", p_qi_5b_7_5d_, 0, debug_item::DRIVEN_SYNC);
		items->add(path, "qids", "src\000sreceiver.v:17.17-17.21\000", p_qids, 0, debug_item::OUTPUT|debug_item::DRIVEN_COMB);
		items->add(path, "qlen", "src\000sreceiver.v:15.19-15.23\000", p_qlen, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "qo[0]", "src\000sreceiver.v:32.12-32.14\000", p_qo_5b_0_5d_, 0, debug_item::DRIVEN_SYNC);
		items->add(path, "qo[1]", "src\000sreceiver.v:32.12-32.14\000", p_qo_5b_1_5d_, 0, debug_item::DRIVEN_SYNC);
		items->add(path, "qo[2]", "src\000sreceiver.v:32.12-32.14\000", p_qo_5b_2_5d_, 0, debug_item::DRIVEN_SYNC);
		items->add(path, "qo[3]", "src\000sreceiver.v:32.12-32.14\000", p_qo_5b_3_5d_, 0, debug_item::DRIVEN_SYNC);
		items->add(path, "qo[4]", "src\000sreceiver.v:32.12-32.14\000", p_qo_5b_4_5d_, 0, debug_item::DRIVEN_SYNC);
		items->add(path, "qo[5]", "src\000sreceiver.v:32.12-32.14\000", p_qo_5b_5_5d_, 0, debug_item::DRIVEN_SYNC);
		items->add(path, "qo[6]", "src\000sreceiver.v:32.12-32.14\000", p_qo_5b_6_5d_, 0, debug_item::DRIVEN_SYNC);
		items->add(path, "qo[7]", "src\000sreceiver.v:32.12-32.14\000", p_qo_5b_7_5d_, 0, debug_item::DRIVEN_SYNC);
		items->add(path, "qowners", "src\000sreceiver.v:16.16-16.23\000", p_qowners, 0, debug_item::OUTPUT|debug_item::DRIVEN_COMB);
		items->add(path, "rone", "src\000sreceiver.v:19.19-19.23\000", p_rone, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "rp", "src\000sreceiver.v:11.23-11.25\000", p_rp, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "rst", "src\000sreceiver.v:4.12-4.15\000", p_rst, 0, debug_item::INPUT|debug_item::UNDRIVEN);
		items->add(path, "rzero", "src\000sreceiver.v:19.13-19.18\000", p_rzero, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "tick", "src\000sreceiver.v:10.20-10.24\000", p_tick, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "transferbyte", "src\000sreceiver.v:30.38-30.50\000", p_transferbyte, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "transferid", "src\000sreceiver.v:29.51-29.61\000", p_transferid, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
		items->add(path, "transferowner", "src\000sreceiver.v:28.62-28.75\000", p_transferowner, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC);
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
