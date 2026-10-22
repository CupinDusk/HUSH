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
	wire<32> i_procmux_24_5696__Y;
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
		if (i_procmux_24_5696__Y.commit(observer)) changed = true;
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
	value<6> i_add_24_receiver_2e_v_3a_109_24_258__Y;
	value<17> i_add_24_receiver_2e_v_3a_124_24_333__Y;
	value<17> i_add_24_receiver_2e_v_3a_125_24_336__Y;
	value<17> i_add_24_receiver_2e_v_3a_126_24_339__Y;
	value<17> i_add_24_receiver_2e_v_3a_127_24_342__Y;
	value<6> i_add_24_receiver_2e_v_3a_82_24_141__Y;
	value<6> i_add_24_receiver_2e_v_3a_82_24_188__Y;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6965;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6967;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6969;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6971;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6973;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6975;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6977;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6979;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6985;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6987;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6991;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6993;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_7001;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_7011;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_7019;
	value<1> i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_7025;
	// \src: receiver.v:110.11-110.68
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7148;
	// \src: receiver.v:110.11-110.68
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7149;
	// \src: receiver.v:110.39-110.68
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7150;
	// \src: receiver.v:110.11-110.68
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7152;
	// \src: receiver.v:110.11-110.68
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7153;
	// \src: receiver.v:109.21-109.32
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7155;
	// \src: receiver.v:100.86-100.96
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7157;
	// \src: receiver.v:95.27-95.33
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7158;
	// \src: receiver.v:93.61-93.69
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7160;
	// \src: receiver.v:93.37-93.53
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7161;
	// \src: receiver.v:93.37-93.53
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7162;
	// \src: receiver.v:93.37-93.53
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7164;
	// \src: receiver.v:93.37-93.53
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7165;
	// \src: receiver.v:91.63-91.70
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7167;
	// \src: receiver.v:83.7-83.70
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7168;
	// \src: receiver.v:83.7-83.70
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7169;
	// \src: receiver.v:83.7-83.70
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7172;
	// \src: receiver.v:83.7-83.70
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7173;
	// \src: receiver.v:82.22-82.36
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7175;
	// \src: receiver.v:74.78-74.83
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7178;
	// \src: receiver.v:83.7-83.70
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7179;
	// \src: receiver.v:83.7-83.70
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7180;
	// \src: receiver.v:83.7-83.70
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7183;
	// \src: receiver.v:83.7-83.70
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7184;
	// \src: receiver.v:82.22-82.36
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7186;
	// \src: receiver.v:65.35-65.53
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7189;
	// \src: receiver.v:65.35-65.53
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7190;
	// \src: receiver.v:65.35-65.53
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7191;
	// \src: receiver.v:65.35-65.53
	value<32> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7192;
	value<2> i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7193;
	// \src: receiver.v:109.9-109.39
	value<1> i_eq_24_receiver_2e_v_3a_109_24_260__Y;
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
	value<1> i_logic__and_24_receiver_2e_v_3a_103_24_255__Y;
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
	value<1> i_lt_24_receiver_2e_v_3a_115_24_276__Y;
	// \src: receiver.v:115.8-115.14
	value<1> i_lt_24_receiver_2e_v_3a_115_24_281__Y;
	// \src: receiver.v:115.8-115.14
	value<1> i_lt_24_receiver_2e_v_3a_115_24_286__Y;
	// \src: receiver.v:115.8-115.14
	value<1> i_lt_24_receiver_2e_v_3a_115_24_291__Y;
	// \src: receiver.v:115.8-115.14
	value<1> i_lt_24_receiver_2e_v_3a_115_24_296__Y;
	// \src: receiver.v:115.8-115.14
	value<1> i_lt_24_receiver_2e_v_3a_115_24_301__Y;
	// \src: receiver.v:115.8-115.14
	value<1> i_lt_24_receiver_2e_v_3a_115_24_306__Y;
	// \src: receiver.v:115.8-115.14
	value<1> i_lt_24_receiver_2e_v_3a_115_24_311__Y;
	// \src: receiver.v:110.11-110.68
	value<33> i_neg_24_receiver_2e_v_3a_110_24_265__Y;
	// \src: receiver.v:83.7-83.70
	value<33> i_neg_24_receiver_2e_v_3a_83_24_147__Y;
	// \src: receiver.v:83.7-83.70
	value<33> i_neg_24_receiver_2e_v_3a_83_24_194__Y;
	// \src: receiver.v:93.6-93.36
	value<3> i_neg_24_receiver_2e_v_3a_93_24_226__Y;
	// \src: receiver.v:93.54-93.76
	value<33> i_neg_24_receiver_2e_v_3a_93_24_238__Y;
	value<1> i_procmux_24_1043__CMP;
	value<1> i_procmux_24_1044__CMP;
	value<1> i_procmux_24_1045__CMP;
	value<1> i_procmux_24_1046__CMP;
	value<1> i_procmux_24_1135__CMP;
	value<1> i_procmux_24_1136__CMP;
	value<1> i_procmux_24_1137__CMP;
	value<1> i_procmux_24_1138__CMP;
	value<1> i_procmux_24_1227__CMP;
	value<1> i_procmux_24_1228__CMP;
	value<1> i_procmux_24_1229__CMP;
	value<1> i_procmux_24_1230__CMP;
	value<1> i_procmux_24_2756__CMP;
	value<1> i_procmux_24_2757__CMP;
	value<1> i_procmux_24_2758__CMP;
	value<1> i_procmux_24_2759__CMP;
	value<1> i_procmux_24_2760__CMP;
	value<1> i_procmux_24_2761__CMP;
	value<1> i_procmux_24_2762__CMP;
	value<1> i_procmux_24_2763__CMP;
	value<1> i_procmux_24_3851__CMP;
	value<1> i_procmux_24_3852__CMP;
	value<1> i_procmux_24_3853__CMP;
	value<1> i_procmux_24_3854__CMP;
	value<1> i_procmux_24_3855__CMP;
	value<1> i_procmux_24_3856__CMP;
	value<1> i_procmux_24_3857__CMP;
	value<1> i_procmux_24_3858__CMP;
	value<1> i_procmux_24_399__CMP;
	value<1> i_procmux_24_400__CMP;
	value<1> i_procmux_24_401__CMP;
	value<1> i_procmux_24_402__CMP;
	value<32> i_procmux_24_4840__Y;
	value<1> i_procmux_24_491__CMP;
	value<1> i_procmux_24_492__CMP;
	value<1> i_procmux_24_493__CMP;
	value<1> i_procmux_24_494__CMP;
	value<32> i_procmux_24_5252__Y;
	value<1> i_procmux_24_583__CMP;
	value<1> i_procmux_24_584__CMP;
	value<1> i_procmux_24_585__CMP;
	value<1> i_procmux_24_586__CMP;
	value<1> i_procmux_24_675__CMP;
	value<1> i_procmux_24_676__CMP;
	value<1> i_procmux_24_677__CMP;
	value<1> i_procmux_24_678__CMP;
	value<1> i_procmux_24_767__CMP;
	value<1> i_procmux_24_768__CMP;
	value<1> i_procmux_24_769__CMP;
	value<1> i_procmux_24_770__CMP;
	value<1> i_procmux_24_859__CMP;
	value<1> i_procmux_24_860__CMP;
	value<1> i_procmux_24_861__CMP;
	value<1> i_procmux_24_862__CMP;
	value<1> i_procmux_24_951__CMP;
	value<1> i_procmux_24_952__CMP;
	value<1> i_procmux_24_953__CMP;
	value<1> i_procmux_24_954__CMP;
	// \src: receiver.v:109.20-109.36
	value<4> i_shiftx_24_receiver_2e_v_3a_109_24_259__Y;
	// \src: receiver.v:82.21-82.40
	value<4> i_shiftx_24_receiver_2e_v_3a_82_24_142__Y;
	// \src: receiver.v:82.21-82.40
	value<4> i_shiftx_24_receiver_2e_v_3a_82_24_189__Y;
	// \src: receiver.v:89.14-89.21
	value<1> i_shiftx_24_receiver_2e_v_3a_89_24_213__Y;
	// \src: receiver.v:91.62-91.74
	value<8> i_shiftx_24_receiver_2e_v_3a_91_24_220__Y;
	// connection
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7186.slice<31,5>() = value<27>{0u};
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
	i_procmux_24_5252__Y.slice<31,2>() = p_fault.curr.slice<31,2>().val();
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
	// cells $procmux$5870 $procmux$5867 $procmux$5865
	i_6_5c_enabled_5b_3_3a_3_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_59_24_93__Y ? value<1>{0x1u} : p_enabled.curr.slice<3>().val()) : value<1>{0u}));
	// cells $procmux$5861 $procmux$5858 $procmux$5856
	i_6_5c_counts_5b_63_3a_48_5d_ = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_59_24_93__Y ? p_cfgk : p_counts.curr.slice<63,48>().val()) : value<16>{0u}));
	// cells $procmux$5906 $procmux$5903 $procmux$5901
	i_5_5c_enabled_5b_2_3a_2_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_59_24_92__Y ? value<1>{0x1u} : p_enabled.curr.slice<2>().val()) : value<1>{0u}));
	// cells $procmux$5897 $procmux$5894 $procmux$5892
	i_5_5c_counts_5b_47_3a_32_5d_ = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_59_24_92__Y ? p_cfgk : p_counts.curr.slice<47,32>().val()) : value<16>{0u}));
	// cells $procmux$5942 $procmux$5939 $procmux$5937
	i_4_5c_enabled_5b_1_3a_1_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_59_24_91__Y ? value<1>{0x1u} : p_enabled.curr.slice<1>().val()) : value<1>{0u}));
	// cells $procmux$5933 $procmux$5930 $procmux$5928
	i_4_5c_counts_5b_31_3a_16_5d_ = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_59_24_91__Y ? p_cfgk : p_counts.curr.slice<31,16>().val()) : value<16>{0u}));
	// cells $procmux$5978 $procmux$5975 $procmux$5973
	i_3_5c_enabled_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_59_24_90__Y ? value<1>{0x1u} : p_enabled.curr.slice<0>().val()) : value<1>{0u}));
	// cells $procmux$5969 $procmux$5966 $procmux$5964
	i_3_5c_counts_5b_15_3a_0_5d_ = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_59_24_90__Y ? p_cfgk : p_counts.curr.slice<15,0>().val()) : value<16>{0u}));
	// cells $procmux$4881 $procmux$4878 $procmux$4912
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
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7186.slice<4,0>() = mul_uu<5>(value<3>{0x4u}, i_5_5c_enqowner_5b_1_3a_0_5d_);
	// \full_case: 1
	// \src: receiver.v:64.10-64.29|receiver.v:64.7-65.128
	// cell $procmux$5544
	i_6_5c_fault_5b_31_3a_0_5d_.slice<1,0>() = (i_eq_24_receiver_2e_v_3a_64_24_95__Y ? value<1>{0x1u}.concat(p_fault.curr.slice<0>()).val() : p_fault.curr.slice<1,0>().val());
	// \src: receiver.v:83.49-83.68
	// cell $add$receiver.v:83$152
	i_add_24_receiver_2e_v_3a_82_24_141__Y = add_uu<6>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7186.slice<4,0>().val(), value<1>{0u});
	// \full_case: 1
	// \src: receiver.v:63.9-63.19|receiver.v:63.6-66.9
	// cell $procmux$5630
	i_5_5c_fault_5b_31_3a_0_5d_.slice<1,0>() = (i_3_5c_enabled_5b_0_3a_0_5d_ ? i_6_5c_fault_5b_31_3a_0_5d_.slice<1,0>().val() : p_fault.curr.slice<1,0>().val());
	// \src: receiver.v:83.49-83.68
	// cell $shiftx$receiver.v:83$153
	i_shiftx_24_receiver_2e_v_3a_82_24_142__Y = shiftx_us<4>(p_outstanding.curr, value<1>{0u}.concat(i_add_24_receiver_2e_v_3a_82_24_141__Y).val());
	// \full_case: 1
	// \src: receiver.v:64.10-64.29|receiver.v:64.7-65.128
	// cell $procmux$5355
	i_8_5c_fault_5b_31_3a_0_5d_.slice<1,0>() = (i_eq_24_receiver_2e_v_3a_64_24_99__Y ? value<1>{0x1u}.concat(i_5_5c_fault_5b_31_3a_0_5d_.slice<0>()).val() : i_5_5c_fault_5b_31_3a_0_5d_.slice<1,0>().val());
	// \full_case: 1
	// \src: receiver.v:63.9-63.19|receiver.v:63.6-66.9
	// cell $procmux$5441
	i_7_5c_fault_5b_31_3a_0_5d_.slice<1,0>() = (i_4_5c_enabled_5b_1_3a_1_5d_ ? i_8_5c_fault_5b_31_3a_0_5d_.slice<1,0>().val() : i_5_5c_fault_5b_31_3a_0_5d_.slice<1,0>().val());
	// \full_case: 1
	// \src: receiver.v:64.10-64.29|receiver.v:64.7-65.128
	// cell $procmux$5166
	i_10_5c_fault_5b_31_3a_0_5d_.slice<1,0>() = (i_eq_24_receiver_2e_v_3a_64_24_103__Y ? value<1>{0x1u}.concat(i_7_5c_fault_5b_31_3a_0_5d_.slice<0>()).val() : i_7_5c_fault_5b_31_3a_0_5d_.slice<1,0>().val());
	// \full_case: 1
	// \src: receiver.v:63.9-63.19|receiver.v:63.6-66.9
	// cell $procmux$5252
	i_procmux_24_5252__Y.slice<1,0>() = (i_5_5c_enabled_5b_2_3a_2_5d_ ? i_10_5c_fault_5b_31_3a_0_5d_.slice<1,0>().val() : i_7_5c_fault_5b_31_3a_0_5d_.slice<1,0>().val());
	// cells $procmux$5259 $procmux$5256 $procmux$5254
	i_11_5c_fault_5b_31_3a_0_5d_.next.slice<31,2>().concat(i_9_5c_fault_5b_31_3a_0_5d_.slice<1,0>()) = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_eq_24_receiver_2e_v_3a_61_24_94__Y ? p_fault.curr.slice<31,2>().concat(i_procmux_24_5252__Y.slice<1,0>()).val() : value<32>{0u}) : value<32>{0u}));
	// \full_case: 1
	// \src: receiver.v:43.6-43.9|receiver.v:43.3-128.6
	// cell $procmux$5699
	i_14_5c_fault_5b_31_3a_0_5d_.next.slice<31,4>().concat(i_4_5c_fault_5b_31_3a_0_5d_.slice<3,0>()) = (p_rst ? value<32>{0u} : i_procmux_24_5696__Y.curr);
	// connection
	i_9_5c_fault_5b_31_3a_0_5d_.slice<31,2>() = i_11_5c_fault_5b_31_3a_0_5d_.curr.slice<31,2>().val();
	// \full_case: 1
	// \src: receiver.v:64.10-64.29|receiver.v:64.7-65.128
	// cell $procmux$4977
	i_12_5c_fault_5b_31_3a_0_5d_.slice<1,0>() = (i_eq_24_receiver_2e_v_3a_64_24_107__Y ? value<1>{0x1u}.concat(i_9_5c_fault_5b_31_3a_0_5d_.slice<0>()).val() : i_9_5c_fault_5b_31_3a_0_5d_.slice<1,0>().val());
	// connection
	i_4_5c_fault_5b_31_3a_0_5d_.slice<31,4>() = i_14_5c_fault_5b_31_3a_0_5d_.curr.slice<31,4>().val();
	// cells $procmux$3836 $eq$receiver.v:82$143
	i_15_5c_fault_5b_31_3a_0_5d_.slice<3,0>() = (eq_uu<1>(i_shiftx_24_receiver_2e_v_3a_82_24_142__Y, value<4>{0xfu}) ? value<1>{0x1u}.concat(i_4_5c_fault_5b_31_3a_0_5d_.slice<2,0>()).val() : i_4_5c_fault_5b_31_3a_0_5d_.slice<3,0>().val());
	// connection
	i_12_5c_fault_5b_31_3a_0_5d_.slice<31,2>() = i_11_5c_fault_5b_31_3a_0_5d_.curr.slice<31,2>().val();
	// connection
	i_15_5c_fault_5b_31_3a_0_5d_.slice<31,4>() = i_14_5c_fault_5b_31_3a_0_5d_.curr.slice<31,4>().val();
	// \full_case: 1
	// \src: receiver.v:76.9-76.16|receiver.v:76.6-84.9
	// cell $procmux$4247
	i_14_5c_fault_5b_31_3a_0_5d_.next.slice<3,0>() = (i_ge_24_receiver_2e_v_3a_76_24_129__Y ? i_4_5c_fault_5b_31_3a_0_5d_.slice<3>().concat(value<1>{0x1u}).concat(i_4_5c_fault_5b_31_3a_0_5d_.slice<1,0>()).val() : i_15_5c_fault_5b_31_3a_0_5d_.slice<3,0>().val());
	// \full_case: 1
	// \src: receiver.v:63.9-63.19|receiver.v:63.6-66.9
	// cell $procmux$5063
	i_11_5c_fault_5b_31_3a_0_5d_.next.slice<1,0>() = (i_6_5c_enabled_5b_3_3a_3_5d_ ? i_12_5c_fault_5b_31_3a_0_5d_.slice<1,0>().val() : i_9_5c_fault_5b_31_3a_0_5d_.slice<1,0>().val());
	// cells $procmux$5696 $procmux$5694
	i_procmux_24_5696__Y.next = (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_eq_24_receiver_2e_v_3a_61_24_94__Y ? i_11_5c_fault_5b_31_3a_0_5d_.curr : p_fault.curr) : value<32>{0u});
	// cells $procmux$4890 $procmux$4887 $procmux$4921
	i_5_5c_releasevalid_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_72_24_112__Y ? value<1>{0x1u} : value<1>{0u}) : value<1>{0u}));
	// \full_case: 1
	// \src: receiver.v:81.7-81.28
	// cell $procmux$4172_CMP0
	i_procmux_24_3857__CMP = eq_uu<1>(p_qlen.curr.slice<2,0>().val(), value<1>{0x1u});
	// \full_case: 1
	// \src: receiver.v:81.7-81.28
	// cell $procmux$4171_CMP0
	i_procmux_24_3856__CMP = eq_uu<1>(p_qlen.curr.slice<2,0>().val(), value<2>{0x2u});
	// \full_case: 1
	// \src: receiver.v:81.7-81.28
	// cell $procmux$4170_CMP0
	i_procmux_24_3855__CMP = eq_uu<1>(p_qlen.curr.slice<2,0>().val(), value<2>{0x3u});
	// \full_case: 1
	// \src: receiver.v:81.7-81.28
	// cell $procmux$4169_CMP0
	i_procmux_24_3854__CMP = eq_uu<1>(p_qlen.curr.slice<2,0>().val(), value<3>{0x4u});
	// \full_case: 1
	// \src: receiver.v:81.7-81.28
	// cell $procmux$4168_CMP0
	i_procmux_24_3853__CMP = eq_uu<1>(p_qlen.curr.slice<2,0>().val(), value<3>{0x5u});
	// \full_case: 1
	// \src: receiver.v:81.7-81.28
	// cell $procmux$4167_CMP0
	i_procmux_24_3852__CMP = eq_uu<1>(p_qlen.curr.slice<2,0>().val(), value<3>{0x6u});
	// \full_case: 1
	// \src: receiver.v:81.7-81.28
	// cell $procmux$4166_CMP0
	i_procmux_24_3851__CMP = eq_uu<1>(p_qlen.curr.slice<2,0>().val(), value<3>{0x7u});
	// cells $logic_and$receiver.v:73$163 $eq$receiver.v:73$160
	i_logic__and_24_receiver_2e_v_3a_73_24_163__Y = logic_and<1>(eq_uu<1>(p_cfgf, value<6>{0x28u}), i_logic__and_24_receiver_2e_v_3a_72_24_112__Y);
	// \full_case: 1
	// \src: receiver.v:81.7-81.28
	// cell $procmux$4173_CMP0
	i_procmux_24_3858__CMP = logic_not<1>(p_qlen.curr.slice<2,0>().val());
	// cell $auto$opt_reduce.cc:131:opt_pmux$7050
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6977 = reduce_or<1>(i_procmux_24_3857__CMP.concat(i_procmux_24_3856__CMP).concat(i_procmux_24_3855__CMP).concat(i_procmux_24_3854__CMP).concat(i_procmux_24_3853__CMP).concat(i_procmux_24_3852__CMP).concat(i_procmux_24_3851__CMP).val());
	// \src: receiver.v:74.78-74.83
	// cell $sub$receiver.v:74$170
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7178.slice<1,0>() = sub_uu<2>(p_fp.curr.slice<1,0>().val(), value<1>{0u});
	// cells $logic_and$receiver.v:74$169 $logic_and$receiver.v:74$167 $ne$receiver.v:74$164 $ge$receiver.v:74$166 $lt$receiver.v:74$168
	i_logic__and_24_receiver_2e_v_3a_74_24_169__Y = logic_and<1>(logic_and<1>(ne_uu<1>(p_cfgf, value<6>{0x28u}), ge_uu<1>(p_fp.curr, value<6>{0x28u})), lt_uu<1>(p_fp.curr, value<6>{0x2cu}));
	// \src: receiver.v:65.35-65.53
	// cell $sub$receiver.v:65$109
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7189.slice<15,0>() = sub_uu<16>(i_6_5c_counts_5b_63_3a_48_5d_, value<1>{0x1u});
	// \src: receiver.v:65.35-65.53
	// cell $sub$receiver.v:65$97
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7192.slice<15,0>() = sub_uu<16>(i_3_5c_counts_5b_15_3a_0_5d_, value<1>{0x1u});
	// \src: receiver.v:65.35-65.53
	// cell $sub$receiver.v:65$101
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7191.slice<15,0>() = sub_uu<16>(i_4_5c_counts_5b_31_3a_16_5d_, value<1>{0x1u});
	// \src: receiver.v:65.35-65.53
	// cell $sub$receiver.v:65$105
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7190.slice<15,0>() = sub_uu<16>(i_5_5c_counts_5b_47_3a_32_5d_, value<1>{0x1u});
	// cells $procmux$4863 $procmux$4860 $procmux$4858 $procmux$4583 $add$receiver.v:81$138
	i_3_5c_qlen_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_5_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_129__Y ? p_qlen.curr : add_uu<4>(p_qlen.curr, value<1>{0x1u})) : p_qlen.curr) : value<4>{0u}));
	// \src: receiver.v:65.57-65.76
	// cell $eq$receiver.v:65$110
	i_eq_24_receiver_2e_v_3a_65_24_110__Y = logic_not<1>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7189.slice<15,0>().val());
	// \src: receiver.v:65.57-65.76
	// cell $eq$receiver.v:65$98
	i_eq_24_receiver_2e_v_3a_65_24_98__Y = logic_not<1>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7192.slice<15,0>().val());
	// \src: receiver.v:65.57-65.76
	// cell $eq$receiver.v:65$102
	i_eq_24_receiver_2e_v_3a_65_24_102__Y = logic_not<1>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7191.slice<15,0>().val());
	// \src: receiver.v:65.57-65.76
	// cell $eq$receiver.v:65$106
	i_eq_24_receiver_2e_v_3a_65_24_106__Y = logic_not<1>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7190.slice<15,0>().val());
	// \full_case: 1
	// \src: receiver.v:81.7-81.28
	// cell $procmux$3077_CMP0
	i_procmux_24_2762__CMP = eq_uu<1>(i_3_5c_qlen_5b_3_3a_0_5d_.slice<2,0>().val(), value<1>{0x1u});
	// \full_case: 1
	// \src: receiver.v:81.7-81.28
	// cell $procmux$3076_CMP0
	i_procmux_24_2761__CMP = eq_uu<1>(i_3_5c_qlen_5b_3_3a_0_5d_.slice<2,0>().val(), value<2>{0x2u});
	// \full_case: 1
	// \src: receiver.v:81.7-81.28
	// cell $procmux$3075_CMP0
	i_procmux_24_2760__CMP = eq_uu<1>(i_3_5c_qlen_5b_3_3a_0_5d_.slice<2,0>().val(), value<2>{0x3u});
	// \full_case: 1
	// \src: receiver.v:81.7-81.28
	// cell $procmux$3074_CMP0
	i_procmux_24_2759__CMP = eq_uu<1>(i_3_5c_qlen_5b_3_3a_0_5d_.slice<2,0>().val(), value<3>{0x4u});
	// \full_case: 1
	// \src: receiver.v:81.7-81.28
	// cell $procmux$3073_CMP0
	i_procmux_24_2758__CMP = eq_uu<1>(i_3_5c_qlen_5b_3_3a_0_5d_.slice<2,0>().val(), value<3>{0x5u});
	// \full_case: 1
	// \src: receiver.v:81.7-81.28
	// cell $procmux$3072_CMP0
	i_procmux_24_2757__CMP = eq_uu<1>(i_3_5c_qlen_5b_3_3a_0_5d_.slice<2,0>().val(), value<3>{0x6u});
	// \full_case: 1
	// \src: receiver.v:81.7-81.28
	// cell $procmux$3071_CMP0
	i_procmux_24_2756__CMP = eq_uu<1>(i_3_5c_qlen_5b_3_3a_0_5d_.slice<2,0>().val(), value<3>{0x7u});
	// cells $procmux$4777 $procmux$4487 $procmux$4018
	i_3_5c_qo_5b_0_5d__5b_1_3a_0_5d_ = (i_5_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_129__Y ? p_qo_5b_0_5d_.curr : (i_procmux_24_3858__CMP ? i_5_5c_enqowner_5b_1_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6977 ? p_qo_5b_0_5d_.curr : value<2>{0u}))) : p_qo_5b_0_5d_.curr);
	// cells $procmux$3786 $procmux$3783 $procmux$3781 $procmux$3799
	i_8_5c_releaseowner_5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_74_24_169__Y ? i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7178.slice<1,0>().val() : (i_logic__and_24_receiver_2e_v_3a_73_24_163__Y ? p_fp.curr.slice<1,0>().val() : value<2>{0u})) : value<2>{0u}));
	// \full_case: 1
	// \src: receiver.v:81.7-81.28
	// cell $procmux$3078_CMP0
	i_procmux_24_2763__CMP = logic_not<1>(i_3_5c_qlen_5b_3_3a_0_5d_.slice<2,0>().val());
	// cell $auto$opt_reduce.cc:131:opt_pmux$7084
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_7025 = reduce_or<1>(i_procmux_24_2762__CMP.concat(i_procmux_24_2761__CMP).concat(i_procmux_24_2760__CMP).concat(i_procmux_24_2759__CMP).concat(i_procmux_24_2758__CMP).concat(i_procmux_24_2757__CMP).concat(i_procmux_24_2756__CMP).val());
	// cell $auto$opt_reduce.cc:131:opt_pmux$7102
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6979 = reduce_or<1>(i_procmux_24_3858__CMP.concat(i_procmux_24_3856__CMP).concat(i_procmux_24_3855__CMP).concat(i_procmux_24_3854__CMP).concat(i_procmux_24_3853__CMP).concat(i_procmux_24_3852__CMP).concat(i_procmux_24_3851__CMP).val());
	// \src: receiver.v:76.9-76.16
	// cell $ge$receiver.v:76$176
	i_ge_24_receiver_2e_v_3a_76_24_176__Y = ge_uu<1>(i_3_5c_qlen_5b_3_3a_0_5d_, value<4>{0x8u});
	// cells $procmux$3795 $procmux$3792 $procmux$3790 $procmux$3808
	i_8_5c_releasevalid_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_74_24_169__Y ? value<1>{0x1u} : (i_logic__and_24_receiver_2e_v_3a_73_24_163__Y ? value<1>{0x1u} : value<1>{0u})) : value<1>{0u}));
	// cells $procmux$4768 $procmux$4475 $procmux$4165
	i_3_5c_qo_5b_1_5d__5b_1_3a_0_5d_ = (i_5_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_129__Y ? p_qo_5b_1_5d_.curr : (i_procmux_24_3857__CMP ? i_5_5c_enqowner_5b_1_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6979 ? p_qo_5b_1_5d_.curr : value<2>{0u}))) : p_qo_5b_1_5d_.curr);
	// cell $auto$opt_reduce.cc:131:opt_pmux$7034
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6985 = reduce_or<1>(i_procmux_24_2763__CMP.concat(i_procmux_24_2761__CMP).concat(i_procmux_24_2760__CMP).concat(i_procmux_24_2759__CMP).concat(i_procmux_24_2758__CMP).concat(i_procmux_24_2757__CMP).concat(i_procmux_24_2756__CMP).val());
	// cell $auto$opt_reduce.cc:131:opt_pmux$6980
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6965 = reduce_or<1>(i_procmux_24_3858__CMP.concat(i_procmux_24_3857__CMP).concat(i_procmux_24_3855__CMP).concat(i_procmux_24_3854__CMP).concat(i_procmux_24_3853__CMP).concat(i_procmux_24_3852__CMP).concat(i_procmux_24_3851__CMP).val());
	// cells $procmux$5825 $procmux$5822 $procmux$5820 $procmux$5099 $procmux$5037 $procmux$4959
	i_3_5c_valid_5b_3_3a_0_5d_.slice<3>() = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_eq_24_receiver_2e_v_3a_61_24_94__Y ? (i_6_5c_enabled_5b_3_3a_3_5d_ ? (i_eq_24_receiver_2e_v_3a_64_24_107__Y ? p_valid.curr.slice<3>().val() : (i_eq_24_receiver_2e_v_3a_65_24_110__Y ? value<1>{0u} : p_valid.curr.slice<3>().val())) : p_valid.curr.slice<3>().val()) : p_valid.curr.slice<3>().val()) : value<1>{0u}));
	// cells $procmux$5798 $procmux$5795 $procmux$5793 $procmux$5666 $procmux$5604 $procmux$5526
	i_3_5c_valid_5b_3_3a_0_5d_.slice<0>() = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_eq_24_receiver_2e_v_3a_61_24_94__Y ? (i_3_5c_enabled_5b_0_3a_0_5d_ ? (i_eq_24_receiver_2e_v_3a_64_24_95__Y ? p_valid.curr.slice<0>().val() : (i_eq_24_receiver_2e_v_3a_65_24_98__Y ? value<1>{0u} : p_valid.curr.slice<0>().val())) : p_valid.curr.slice<0>().val()) : p_valid.curr.slice<0>().val()) : value<1>{0u}));
	// cells $procmux$5762 $procmux$5759 $procmux$5757 $procmux$5477 $procmux$5415 $procmux$5337
	i_3_5c_valid_5b_3_3a_0_5d_.slice<1>() = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_eq_24_receiver_2e_v_3a_61_24_94__Y ? (i_4_5c_enabled_5b_1_3a_1_5d_ ? (i_eq_24_receiver_2e_v_3a_64_24_99__Y ? p_valid.curr.slice<1>().val() : (i_eq_24_receiver_2e_v_3a_65_24_102__Y ? value<1>{0u} : p_valid.curr.slice<1>().val())) : p_valid.curr.slice<1>().val()) : p_valid.curr.slice<1>().val()) : value<1>{0u}));
	// cells $procmux$5726 $procmux$5723 $procmux$5721 $procmux$5288 $procmux$5226 $procmux$5148
	i_3_5c_valid_5b_3_3a_0_5d_.slice<2>() = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_eq_24_receiver_2e_v_3a_61_24_94__Y ? (i_5_5c_enabled_5b_2_3a_2_5d_ ? (i_eq_24_receiver_2e_v_3a_64_24_103__Y ? p_valid.curr.slice<2>().val() : (i_eq_24_receiver_2e_v_3a_65_24_106__Y ? value<1>{0u} : p_valid.curr.slice<2>().val())) : p_valid.curr.slice<2>().val()) : p_valid.curr.slice<2>().val()) : value<1>{0u}));
	// cells $procmux$3687 $procmux$3684 $procmux$3682 $procmux$3392 $procmux$2923
	i_6_5c_qo_5b_0_5d__5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_176__Y ? i_3_5c_qo_5b_0_5d__5b_1_3a_0_5d_ : (i_procmux_24_2763__CMP ? i_8_5c_releaseowner_5b_1_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_7025 ? i_3_5c_qo_5b_0_5d__5b_1_3a_0_5d_ : value<2>{0u}))) : i_3_5c_qo_5b_0_5d__5b_1_3a_0_5d_) : value<2>{0u}));
	// cells $procmux$3768 $procmux$3765 $procmux$3763 $procmux$3488 $add$receiver.v:81$185
	i_5_5c_qlen_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_176__Y ? i_3_5c_qlen_5b_3_3a_0_5d_ : add_uu<4>(i_3_5c_qlen_5b_3_3a_0_5d_, value<1>{0x1u})) : i_3_5c_qlen_5b_3_3a_0_5d_) : value<4>{0u}));
	// \src: receiver.v:89.14-89.21
	// cell $shiftx$receiver.v:89$213
	i_shiftx_24_receiver_2e_v_3a_89_24_213__Y = shiftx_uu<1>(i_3_5c_valid_5b_3_3a_0_5d_, i_6_5c_qo_5b_0_5d__5b_1_3a_0_5d_);
	// cells $procmux$3673 $procmux$3380 $procmux$3070
	i_6_5c_qo_5b_1_5d__5b_1_3a_0_5d_ = (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_176__Y ? i_3_5c_qo_5b_1_5d__5b_1_3a_0_5d_ : (i_procmux_24_2762__CMP ? i_8_5c_releaseowner_5b_1_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6985 ? i_3_5c_qo_5b_1_5d__5b_1_3a_0_5d_ : value<2>{0u}))) : i_3_5c_qo_5b_1_5d__5b_1_3a_0_5d_);
	// cells $logic_and$receiver.v:87$209 $logic_and$receiver.v:87$207 $eq$receiver.v:87$205 $logic_not$receiver.v:87$206 $ne$receiver.v:87$208
	i_logic__and_24_receiver_2e_v_3a_87_24_209__Y = logic_and<1>(logic_and<1>(logic_not<1>(p_cp.curr), logic_not<1>(p_rzero.curr)), reduce_bool<1>(i_5_5c_qlen_5b_3_3a_0_5d_));
	// cells $procmux$4759 $procmux$4463 $procmux$4144
	i_3_5c_qo_5b_2_5d__5b_1_3a_0_5d_ = (i_5_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_129__Y ? p_qo_5b_2_5d_.curr : (i_procmux_24_3856__CMP ? i_5_5c_enqowner_5b_1_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6965 ? p_qo_5b_2_5d_.curr : value<2>{0u}))) : p_qo_5b_2_5d_.curr);
	// cell $auto$opt_reduce.cc:131:opt_pmux$7040
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6987 = reduce_or<1>(i_procmux_24_2763__CMP.concat(i_procmux_24_2762__CMP).concat(i_procmux_24_2760__CMP).concat(i_procmux_24_2759__CMP).concat(i_procmux_24_2758__CMP).concat(i_procmux_24_2757__CMP).concat(i_procmux_24_2756__CMP).val());
	// \src: receiver.v:95.27-95.33
	// cell $sub$receiver.v:95$245
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7158.slice<3,0>() = sub_uu<4>(i_5_5c_qlen_5b_3_3a_0_5d_, value<1>{0x1u});
	// cell $auto$opt_reduce.cc:131:opt_pmux$6982
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6967 = reduce_or<1>(i_procmux_24_3858__CMP.concat(i_procmux_24_3857__CMP).concat(i_procmux_24_3856__CMP).concat(i_procmux_24_3854__CMP).concat(i_procmux_24_3853__CMP).concat(i_procmux_24_3852__CMP).concat(i_procmux_24_3851__CMP).val());
	// cells $procmux$2529 $procmux$2526 $procmux$2524 $procmux$2186
	i_9_5c_qo_5b_0_5d__5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_209__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_213__Y ? i_6_5c_qo_5b_1_5d__5b_1_3a_0_5d_ : i_6_5c_qo_5b_0_5d__5b_1_3a_0_5d_) : i_6_5c_qo_5b_0_5d__5b_1_3a_0_5d_) : value<2>{0u}));
	// cells $procmux$3664 $procmux$3368 $procmux$3049
	i_6_5c_qo_5b_2_5d__5b_1_3a_0_5d_ = (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_176__Y ? i_3_5c_qo_5b_2_5d__5b_1_3a_0_5d_ : (i_procmux_24_2761__CMP ? i_8_5c_releaseowner_5b_1_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6987 ? i_3_5c_qo_5b_2_5d__5b_1_3a_0_5d_ : value<2>{0u}))) : i_3_5c_qo_5b_2_5d__5b_1_3a_0_5d_);
	// \full_case: 1
	// \src: receiver.v:116.37-116.37|receiver.v:116.6-116.104
	// cell $procmux$1271_CMP0
	i_procmux_24_1229__CMP = eq_uu<1>(i_9_5c_qo_5b_0_5d__5b_1_3a_0_5d_, value<1>{0x1u});
	// \full_case: 1
	// \src: receiver.v:116.57-116.57|receiver.v:116.6-116.104
	// cell $procmux$1270_CMP0
	i_procmux_24_1228__CMP = eq_uu<1>(i_9_5c_qo_5b_0_5d__5b_1_3a_0_5d_, value<2>{0x2u});
	// \full_case: 1
	// \src: receiver.v:116.77-116.77|receiver.v:116.6-116.104
	// cell $procmux$1269_CMP0
	i_procmux_24_1227__CMP = eq_uu<1>(i_9_5c_qo_5b_0_5d__5b_1_3a_0_5d_, value<2>{0x3u});
	// \full_case: 1
	// \src: receiver.v:116.17-116.17|receiver.v:116.6-116.104
	// cell $procmux$1272_CMP0
	i_procmux_24_1230__CMP = logic_not<1>(i_9_5c_qo_5b_0_5d__5b_1_3a_0_5d_);
	// cells $procmux$2691 $procmux$2688 $procmux$2686 $procmux$2354
	i_7_5c_qlen_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_209__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_213__Y ? i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7158.slice<3,0>().val() : i_5_5c_qlen_5b_3_3a_0_5d_) : i_5_5c_qlen_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$4750 $procmux$4451 $procmux$4123
	i_3_5c_qo_5b_3_5d__5b_1_3a_0_5d_ = (i_5_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_129__Y ? p_qo_5b_3_5d_.curr : (i_procmux_24_3855__CMP ? i_5_5c_enqowner_5b_1_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6967 ? p_qo_5b_3_5d_.curr : value<2>{0u}))) : p_qo_5b_3_5d_.curr);
	// cell $auto$opt_reduce.cc:131:opt_pmux$7048
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6991 = reduce_or<1>(i_procmux_24_2763__CMP.concat(i_procmux_24_2762__CMP).concat(i_procmux_24_2761__CMP).concat(i_procmux_24_2759__CMP).concat(i_procmux_24_2758__CMP).concat(i_procmux_24_2757__CMP).concat(i_procmux_24_2756__CMP).val());
	// \src: receiver.v:115.8-115.14
	// cell $lt$receiver.v:115$276
	i_lt_24_receiver_2e_v_3a_115_24_276__Y = lt_uu<1>(value<1>{0u}, i_7_5c_qlen_5b_3_3a_0_5d_);
	// cell $auto$opt_reduce.cc:131:opt_pmux$6988
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6969 = reduce_or<1>(i_procmux_24_3858__CMP.concat(i_procmux_24_3857__CMP).concat(i_procmux_24_3856__CMP).concat(i_procmux_24_3855__CMP).concat(i_procmux_24_3853__CMP).concat(i_procmux_24_3852__CMP).concat(i_procmux_24_3851__CMP).val());
	// cells $procmux$2520 $procmux$2517 $procmux$2515 $procmux$2174
	i_9_5c_qo_5b_1_5d__5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_209__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_213__Y ? i_6_5c_qo_5b_2_5d__5b_1_3a_0_5d_ : i_6_5c_qo_5b_1_5d__5b_1_3a_0_5d_) : i_6_5c_qo_5b_1_5d__5b_1_3a_0_5d_) : value<2>{0u}));
	// cells $procmux$3655 $procmux$3356 $procmux$3028
	i_6_5c_qo_5b_3_5d__5b_1_3a_0_5d_ = (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_176__Y ? i_3_5c_qo_5b_3_5d__5b_1_3a_0_5d_ : (i_procmux_24_2760__CMP ? i_8_5c_releaseowner_5b_1_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6991 ? i_3_5c_qo_5b_3_5d__5b_1_3a_0_5d_ : value<2>{0u}))) : i_3_5c_qo_5b_3_5d__5b_1_3a_0_5d_);
	// \full_case: 1
	// \src: receiver.v:116.37-116.37|receiver.v:116.6-116.104
	// cell $procmux$1179_CMP0
	i_procmux_24_1137__CMP = eq_uu<1>(i_9_5c_qo_5b_1_5d__5b_1_3a_0_5d_, value<1>{0x1u});
	// \full_case: 1
	// \src: receiver.v:116.57-116.57|receiver.v:116.6-116.104
	// cell $procmux$1178_CMP0
	i_procmux_24_1136__CMP = eq_uu<1>(i_9_5c_qo_5b_1_5d__5b_1_3a_0_5d_, value<2>{0x2u});
	// \full_case: 1
	// \src: receiver.v:116.77-116.77|receiver.v:116.6-116.104
	// cell $procmux$1177_CMP0
	i_procmux_24_1135__CMP = eq_uu<1>(i_9_5c_qo_5b_1_5d__5b_1_3a_0_5d_, value<2>{0x3u});
	// cells $procmux$1314 $procmux$1311 $procmux$1309 $procmux$1226 $auto$opt_reduce.cc:131:opt_pmux$7004
	i_3_5c_tokens0_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_276__Y ? (i_procmux_24_1230__CMP ? value<4>{0x1u} : (reduce_or<1>(i_procmux_24_1229__CMP.concat(i_procmux_24_1228__CMP).concat(i_procmux_24_1227__CMP).val()) ? value<4>{0u} : value<4>{0u})) : value<4>{0u}) : value<4>{0u}));
	// \full_case: 1
	// \src: receiver.v:116.17-116.17|receiver.v:116.6-116.104
	// cell $procmux$1180_CMP0
	i_procmux_24_1138__CMP = logic_not<1>(i_9_5c_qo_5b_1_5d__5b_1_3a_0_5d_);
	// cells $procmux$1305 $procmux$1302 $procmux$1300 $procmux$1268 $auto$opt_reduce.cc:131:opt_pmux$6994
	i_3_5c_tokens1_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_276__Y ? (i_procmux_24_1229__CMP ? value<4>{0x1u} : (reduce_or<1>(i_procmux_24_1230__CMP.concat(i_procmux_24_1228__CMP).concat(i_procmux_24_1227__CMP).val()) ? value<4>{0u} : value<4>{0u})) : value<4>{0u}) : value<4>{0u}));
	// cells $procmux$1296 $procmux$1293 $procmux$1291 $procmux$1254 $auto$opt_reduce.cc:131:opt_pmux$6998
	i_3_5c_tokens2_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_276__Y ? (i_procmux_24_1228__CMP ? value<4>{0x1u} : (reduce_or<1>(i_procmux_24_1230__CMP.concat(i_procmux_24_1229__CMP).concat(i_procmux_24_1227__CMP).val()) ? value<4>{0u} : value<4>{0u})) : value<4>{0u}) : value<4>{0u}));
	// cells $procmux$1287 $procmux$1284 $procmux$1282 $procmux$1240 $auto$opt_reduce.cc:131:opt_pmux$7002
	i_3_5c_tokens3_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_276__Y ? (reduce_or<1>(i_procmux_24_1230__CMP.concat(i_procmux_24_1229__CMP).concat(i_procmux_24_1228__CMP).val()) ? value<4>{0u} : (i_procmux_24_1227__CMP ? value<4>{0x1u} : value<4>{0u})) : value<4>{0u}) : value<4>{0u}));
	// cells $procmux$4741 $procmux$4439 $procmux$4102
	i_3_5c_qo_5b_4_5d__5b_1_3a_0_5d_ = (i_5_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_129__Y ? p_qo_5b_4_5d_.curr : (i_procmux_24_3854__CMP ? i_5_5c_enqowner_5b_1_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6969 ? p_qo_5b_4_5d_.curr : value<2>{0u}))) : p_qo_5b_4_5d_.curr);
	// cell $auto$opt_reduce.cc:131:opt_pmux$7056
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6993 = reduce_or<1>(i_procmux_24_2763__CMP.concat(i_procmux_24_2762__CMP).concat(i_procmux_24_2761__CMP).concat(i_procmux_24_2760__CMP).concat(i_procmux_24_2758__CMP).concat(i_procmux_24_2757__CMP).concat(i_procmux_24_2756__CMP).val());
	// \src: receiver.v:115.8-115.14
	// cell $lt$receiver.v:115$281
	i_lt_24_receiver_2e_v_3a_115_24_281__Y = lt_uu<1>(value<1>{0x1u}, i_7_5c_qlen_5b_3_3a_0_5d_);
	// cell $auto$opt_reduce.cc:131:opt_pmux$6996
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6971 = reduce_or<1>(i_procmux_24_3858__CMP.concat(i_procmux_24_3857__CMP).concat(i_procmux_24_3856__CMP).concat(i_procmux_24_3855__CMP).concat(i_procmux_24_3854__CMP).concat(i_procmux_24_3852__CMP).concat(i_procmux_24_3851__CMP).val());
	// cells $procmux$2511 $procmux$2508 $procmux$2506 $procmux$2162
	i_9_5c_qo_5b_2_5d__5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_209__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_213__Y ? i_6_5c_qo_5b_3_5d__5b_1_3a_0_5d_ : i_6_5c_qo_5b_2_5d__5b_1_3a_0_5d_) : i_6_5c_qo_5b_2_5d__5b_1_3a_0_5d_) : value<2>{0u}));
	// cells $procmux$3646 $procmux$3344 $procmux$3007
	i_6_5c_qo_5b_4_5d__5b_1_3a_0_5d_ = (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_176__Y ? i_3_5c_qo_5b_4_5d__5b_1_3a_0_5d_ : (i_procmux_24_2759__CMP ? i_8_5c_releaseowner_5b_1_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6993 ? i_3_5c_qo_5b_4_5d__5b_1_3a_0_5d_ : value<2>{0u}))) : i_3_5c_qo_5b_4_5d__5b_1_3a_0_5d_);
	// \full_case: 1
	// \src: receiver.v:116.37-116.37|receiver.v:116.6-116.104
	// cell $procmux$1087_CMP0
	i_procmux_24_1045__CMP = eq_uu<1>(i_9_5c_qo_5b_2_5d__5b_1_3a_0_5d_, value<1>{0x1u});
	// \full_case: 1
	// \src: receiver.v:116.57-116.57|receiver.v:116.6-116.104
	// cell $procmux$1086_CMP0
	i_procmux_24_1044__CMP = eq_uu<1>(i_9_5c_qo_5b_2_5d__5b_1_3a_0_5d_, value<2>{0x2u});
	// \full_case: 1
	// \src: receiver.v:116.77-116.77|receiver.v:116.6-116.104
	// cell $procmux$1085_CMP0
	i_procmux_24_1043__CMP = eq_uu<1>(i_9_5c_qo_5b_2_5d__5b_1_3a_0_5d_, value<2>{0x3u});
	// cells $procmux$1222 $procmux$1219 $procmux$1217 $procmux$1134 $add$receiver.v:116$282 $auto$opt_reduce.cc:131:opt_pmux$7014
	i_5_5c_tokens0_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_281__Y ? (i_procmux_24_1138__CMP ? add_uu<4>(i_3_5c_tokens0_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_1137__CMP.concat(i_procmux_24_1136__CMP).concat(i_procmux_24_1135__CMP).val()) ? i_3_5c_tokens0_5b_3_3a_0_5d_ : value<4>{0u})) : i_3_5c_tokens0_5b_3_3a_0_5d_) : value<4>{0u}));
	// \full_case: 1
	// \src: receiver.v:116.17-116.17|receiver.v:116.6-116.104
	// cell $procmux$1088_CMP0
	i_procmux_24_1046__CMP = logic_not<1>(i_9_5c_qo_5b_2_5d__5b_1_3a_0_5d_);
	// cells $procmux$1213 $procmux$1210 $procmux$1208 $procmux$1176 $add$receiver.v:116$283 $auto$opt_reduce.cc:131:opt_pmux$7006
	i_5_5c_tokens1_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_281__Y ? (i_procmux_24_1137__CMP ? add_uu<4>(i_3_5c_tokens1_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_1138__CMP.concat(i_procmux_24_1136__CMP).concat(i_procmux_24_1135__CMP).val()) ? i_3_5c_tokens1_5b_3_3a_0_5d_ : value<4>{0u})) : i_3_5c_tokens1_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$1204 $procmux$1201 $procmux$1199 $procmux$1162 $add$receiver.v:116$284 $auto$opt_reduce.cc:131:opt_pmux$7008
	i_5_5c_tokens2_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_281__Y ? (i_procmux_24_1136__CMP ? add_uu<4>(i_3_5c_tokens2_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_1138__CMP.concat(i_procmux_24_1137__CMP).concat(i_procmux_24_1135__CMP).val()) ? i_3_5c_tokens2_5b_3_3a_0_5d_ : value<4>{0u})) : i_3_5c_tokens2_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$1195 $procmux$1192 $procmux$1190 $procmux$1148 $add$receiver.v:116$285 $auto$opt_reduce.cc:131:opt_pmux$7012
	i_5_5c_tokens3_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_281__Y ? (reduce_or<1>(i_procmux_24_1138__CMP.concat(i_procmux_24_1137__CMP).concat(i_procmux_24_1136__CMP).val()) ? i_3_5c_tokens3_5b_3_3a_0_5d_ : (i_procmux_24_1135__CMP ? add_uu<4>(i_3_5c_tokens3_5b_3_3a_0_5d_, value<1>{0x1u}) : value<4>{0u})) : i_3_5c_tokens3_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$4732 $procmux$4427 $procmux$4081
	i_3_5c_qo_5b_5_5d__5b_1_3a_0_5d_ = (i_5_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_129__Y ? p_qo_5b_5_5d_.curr : (i_procmux_24_3853__CMP ? i_5_5c_enqowner_5b_1_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6971 ? p_qo_5b_5_5d_.curr : value<2>{0u}))) : p_qo_5b_5_5d_.curr);
	// cell $auto$opt_reduce.cc:131:opt_pmux$7062
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_7001 = reduce_or<1>(i_procmux_24_2763__CMP.concat(i_procmux_24_2762__CMP).concat(i_procmux_24_2761__CMP).concat(i_procmux_24_2760__CMP).concat(i_procmux_24_2759__CMP).concat(i_procmux_24_2757__CMP).concat(i_procmux_24_2756__CMP).val());
	// \src: receiver.v:115.8-115.14
	// cell $lt$receiver.v:115$286
	i_lt_24_receiver_2e_v_3a_115_24_286__Y = lt_uu<1>(value<2>{0x2u}, i_7_5c_qlen_5b_3_3a_0_5d_);
	// cell $auto$opt_reduce.cc:131:opt_pmux$7016
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6973 = reduce_or<1>(i_procmux_24_3858__CMP.concat(i_procmux_24_3857__CMP).concat(i_procmux_24_3856__CMP).concat(i_procmux_24_3855__CMP).concat(i_procmux_24_3854__CMP).concat(i_procmux_24_3853__CMP).concat(i_procmux_24_3851__CMP).val());
	// cells $procmux$2502 $procmux$2499 $procmux$2497 $procmux$2150
	i_9_5c_qo_5b_3_5d__5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_209__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_213__Y ? i_6_5c_qo_5b_4_5d__5b_1_3a_0_5d_ : i_6_5c_qo_5b_3_5d__5b_1_3a_0_5d_) : i_6_5c_qo_5b_3_5d__5b_1_3a_0_5d_) : value<2>{0u}));
	// cells $procmux$3637 $procmux$3332 $procmux$2986
	i_6_5c_qo_5b_5_5d__5b_1_3a_0_5d_ = (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_176__Y ? i_3_5c_qo_5b_5_5d__5b_1_3a_0_5d_ : (i_procmux_24_2758__CMP ? i_8_5c_releaseowner_5b_1_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_7001 ? i_3_5c_qo_5b_5_5d__5b_1_3a_0_5d_ : value<2>{0u}))) : i_3_5c_qo_5b_5_5d__5b_1_3a_0_5d_);
	// \full_case: 1
	// \src: receiver.v:116.37-116.37|receiver.v:116.6-116.104
	// cell $procmux$995_CMP0
	i_procmux_24_953__CMP = eq_uu<1>(i_9_5c_qo_5b_3_5d__5b_1_3a_0_5d_, value<1>{0x1u});
	// \full_case: 1
	// \src: receiver.v:116.57-116.57|receiver.v:116.6-116.104
	// cell $procmux$994_CMP0
	i_procmux_24_952__CMP = eq_uu<1>(i_9_5c_qo_5b_3_5d__5b_1_3a_0_5d_, value<2>{0x2u});
	// \full_case: 1
	// \src: receiver.v:116.77-116.77|receiver.v:116.6-116.104
	// cell $procmux$993_CMP0
	i_procmux_24_951__CMP = eq_uu<1>(i_9_5c_qo_5b_3_5d__5b_1_3a_0_5d_, value<2>{0x3u});
	// cells $procmux$1130 $procmux$1127 $procmux$1125 $procmux$1042 $add$receiver.v:116$287 $auto$opt_reduce.cc:131:opt_pmux$7028
	i_7_5c_tokens0_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_286__Y ? (i_procmux_24_1046__CMP ? add_uu<4>(i_5_5c_tokens0_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_1045__CMP.concat(i_procmux_24_1044__CMP).concat(i_procmux_24_1043__CMP).val()) ? i_5_5c_tokens0_5b_3_3a_0_5d_ : value<4>{0u})) : i_5_5c_tokens0_5b_3_3a_0_5d_) : value<4>{0u}));
	// \full_case: 1
	// \src: receiver.v:116.17-116.17|receiver.v:116.6-116.104
	// cell $procmux$996_CMP0
	i_procmux_24_954__CMP = logic_not<1>(i_9_5c_qo_5b_3_5d__5b_1_3a_0_5d_);
	// cells $procmux$1121 $procmux$1118 $procmux$1116 $procmux$1084 $add$receiver.v:116$288 $auto$opt_reduce.cc:131:opt_pmux$7020
	i_7_5c_tokens1_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_286__Y ? (i_procmux_24_1045__CMP ? add_uu<4>(i_5_5c_tokens1_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_1046__CMP.concat(i_procmux_24_1044__CMP).concat(i_procmux_24_1043__CMP).val()) ? i_5_5c_tokens1_5b_3_3a_0_5d_ : value<4>{0u})) : i_5_5c_tokens1_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$1112 $procmux$1109 $procmux$1107 $procmux$1070 $add$receiver.v:116$289 $auto$opt_reduce.cc:131:opt_pmux$7022
	i_7_5c_tokens2_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_286__Y ? (i_procmux_24_1044__CMP ? add_uu<4>(i_5_5c_tokens2_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_1046__CMP.concat(i_procmux_24_1045__CMP).concat(i_procmux_24_1043__CMP).val()) ? i_5_5c_tokens2_5b_3_3a_0_5d_ : value<4>{0u})) : i_5_5c_tokens2_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$1103 $procmux$1100 $procmux$1098 $procmux$1056 $add$receiver.v:116$290 $auto$opt_reduce.cc:131:opt_pmux$7026
	i_7_5c_tokens3_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_286__Y ? (reduce_or<1>(i_procmux_24_1046__CMP.concat(i_procmux_24_1045__CMP).concat(i_procmux_24_1044__CMP).val()) ? i_5_5c_tokens3_5b_3_3a_0_5d_ : (i_procmux_24_1043__CMP ? add_uu<4>(i_5_5c_tokens3_5b_3_3a_0_5d_, value<1>{0x1u}) : value<4>{0u})) : i_5_5c_tokens3_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$4723 $procmux$4415 $procmux$4060
	i_3_5c_qo_5b_6_5d__5b_1_3a_0_5d_ = (i_5_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_129__Y ? p_qo_5b_6_5d_.curr : (i_procmux_24_3852__CMP ? i_5_5c_enqowner_5b_1_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6973 ? p_qo_5b_6_5d_.curr : value<2>{0u}))) : p_qo_5b_6_5d_.curr);
	// cell $auto$opt_reduce.cc:131:opt_pmux$7070
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_7011 = reduce_or<1>(i_procmux_24_2763__CMP.concat(i_procmux_24_2762__CMP).concat(i_procmux_24_2761__CMP).concat(i_procmux_24_2760__CMP).concat(i_procmux_24_2759__CMP).concat(i_procmux_24_2758__CMP).concat(i_procmux_24_2756__CMP).val());
	// \src: receiver.v:115.8-115.14
	// cell $lt$receiver.v:115$291
	i_lt_24_receiver_2e_v_3a_115_24_291__Y = lt_uu<1>(value<2>{0x3u}, i_7_5c_qlen_5b_3_3a_0_5d_);
	// cell $auto$opt_reduce.cc:131:opt_pmux$7032
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6975 = reduce_or<1>(i_procmux_24_3858__CMP.concat(i_procmux_24_3857__CMP).concat(i_procmux_24_3856__CMP).concat(i_procmux_24_3855__CMP).concat(i_procmux_24_3854__CMP).concat(i_procmux_24_3853__CMP).concat(i_procmux_24_3852__CMP).val());
	// cells $procmux$2493 $procmux$2490 $procmux$2488 $procmux$2138
	i_9_5c_qo_5b_4_5d__5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_209__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_213__Y ? i_6_5c_qo_5b_5_5d__5b_1_3a_0_5d_ : i_6_5c_qo_5b_4_5d__5b_1_3a_0_5d_) : i_6_5c_qo_5b_4_5d__5b_1_3a_0_5d_) : value<2>{0u}));
	// cells $procmux$3628 $procmux$3320 $procmux$2965
	i_6_5c_qo_5b_6_5d__5b_1_3a_0_5d_ = (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_176__Y ? i_3_5c_qo_5b_6_5d__5b_1_3a_0_5d_ : (i_procmux_24_2757__CMP ? i_8_5c_releaseowner_5b_1_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_7011 ? i_3_5c_qo_5b_6_5d__5b_1_3a_0_5d_ : value<2>{0u}))) : i_3_5c_qo_5b_6_5d__5b_1_3a_0_5d_);
	// \full_case: 1
	// \src: receiver.v:116.37-116.37|receiver.v:116.6-116.104
	// cell $procmux$903_CMP0
	i_procmux_24_861__CMP = eq_uu<1>(i_9_5c_qo_5b_4_5d__5b_1_3a_0_5d_, value<1>{0x1u});
	// \full_case: 1
	// \src: receiver.v:116.57-116.57|receiver.v:116.6-116.104
	// cell $procmux$902_CMP0
	i_procmux_24_860__CMP = eq_uu<1>(i_9_5c_qo_5b_4_5d__5b_1_3a_0_5d_, value<2>{0x2u});
	// \full_case: 1
	// \src: receiver.v:116.77-116.77|receiver.v:116.6-116.104
	// cell $procmux$901_CMP0
	i_procmux_24_859__CMP = eq_uu<1>(i_9_5c_qo_5b_4_5d__5b_1_3a_0_5d_, value<2>{0x3u});
	// cells $procmux$1038 $procmux$1035 $procmux$1033 $procmux$950 $add$receiver.v:116$292 $auto$opt_reduce.cc:131:opt_pmux$7042
	i_9_5c_tokens0_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_291__Y ? (i_procmux_24_954__CMP ? add_uu<4>(i_7_5c_tokens0_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_953__CMP.concat(i_procmux_24_952__CMP).concat(i_procmux_24_951__CMP).val()) ? i_7_5c_tokens0_5b_3_3a_0_5d_ : value<4>{0u})) : i_7_5c_tokens0_5b_3_3a_0_5d_) : value<4>{0u}));
	// \full_case: 1
	// \src: receiver.v:116.17-116.17|receiver.v:116.6-116.104
	// cell $procmux$904_CMP0
	i_procmux_24_862__CMP = logic_not<1>(i_9_5c_qo_5b_4_5d__5b_1_3a_0_5d_);
	// cells $procmux$1029 $procmux$1026 $procmux$1024 $procmux$992 $add$receiver.v:116$293 $auto$opt_reduce.cc:131:opt_pmux$7030
	i_9_5c_tokens1_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_291__Y ? (i_procmux_24_953__CMP ? add_uu<4>(i_7_5c_tokens1_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_954__CMP.concat(i_procmux_24_952__CMP).concat(i_procmux_24_951__CMP).val()) ? i_7_5c_tokens1_5b_3_3a_0_5d_ : value<4>{0u})) : i_7_5c_tokens1_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$1020 $procmux$1017 $procmux$1015 $procmux$978 $add$receiver.v:116$294 $auto$opt_reduce.cc:131:opt_pmux$7036
	i_9_5c_tokens2_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_291__Y ? (i_procmux_24_952__CMP ? add_uu<4>(i_7_5c_tokens2_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_954__CMP.concat(i_procmux_24_953__CMP).concat(i_procmux_24_951__CMP).val()) ? i_7_5c_tokens2_5b_3_3a_0_5d_ : value<4>{0u})) : i_7_5c_tokens2_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$1011 $procmux$1008 $procmux$1006 $procmux$964 $add$receiver.v:116$295 $auto$opt_reduce.cc:131:opt_pmux$7038
	i_9_5c_tokens3_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_291__Y ? (reduce_or<1>(i_procmux_24_954__CMP.concat(i_procmux_24_953__CMP).concat(i_procmux_24_952__CMP).val()) ? i_7_5c_tokens3_5b_3_3a_0_5d_ : (i_procmux_24_951__CMP ? add_uu<4>(i_7_5c_tokens3_5b_3_3a_0_5d_, value<1>{0x1u}) : value<4>{0u})) : i_7_5c_tokens3_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$4714 $procmux$4403 $procmux$4039
	i_3_5c_qo_5b_7_5d__5b_1_3a_0_5d_ = (i_5_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_129__Y ? p_qo_5b_7_5d_.curr : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6975 ? p_qo_5b_7_5d_.curr : (i_procmux_24_3851__CMP ? i_5_5c_enqowner_5b_1_3a_0_5d_ : value<2>{0u}))) : p_qo_5b_7_5d_.curr);
	// cell $auto$opt_reduce.cc:131:opt_pmux$7078
	i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_7019 = reduce_or<1>(i_procmux_24_2763__CMP.concat(i_procmux_24_2762__CMP).concat(i_procmux_24_2761__CMP).concat(i_procmux_24_2760__CMP).concat(i_procmux_24_2759__CMP).concat(i_procmux_24_2758__CMP).concat(i_procmux_24_2757__CMP).val());
	// \src: receiver.v:115.8-115.14
	// cell $lt$receiver.v:115$296
	i_lt_24_receiver_2e_v_3a_115_24_296__Y = lt_uu<1>(value<3>{0x4u}, i_7_5c_qlen_5b_3_3a_0_5d_);
	// cells $procmux$2484 $procmux$2481 $procmux$2479 $procmux$2126
	i_9_5c_qo_5b_5_5d__5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_209__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_213__Y ? i_6_5c_qo_5b_6_5d__5b_1_3a_0_5d_ : i_6_5c_qo_5b_5_5d__5b_1_3a_0_5d_) : i_6_5c_qo_5b_5_5d__5b_1_3a_0_5d_) : value<2>{0u}));
	// cells $procmux$3619 $procmux$3308 $procmux$2944
	i_6_5c_qo_5b_7_5d__5b_1_3a_0_5d_ = (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_176__Y ? i_3_5c_qo_5b_7_5d__5b_1_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_7019 ? i_3_5c_qo_5b_7_5d__5b_1_3a_0_5d_ : (i_procmux_24_2756__CMP ? i_8_5c_releaseowner_5b_1_3a_0_5d_ : value<2>{0u}))) : i_3_5c_qo_5b_7_5d__5b_1_3a_0_5d_);
	// \full_case: 1
	// \src: receiver.v:116.37-116.37|receiver.v:116.6-116.104
	// cell $procmux$811_CMP0
	i_procmux_24_769__CMP = eq_uu<1>(i_9_5c_qo_5b_5_5d__5b_1_3a_0_5d_, value<1>{0x1u});
	// \full_case: 1
	// \src: receiver.v:116.57-116.57|receiver.v:116.6-116.104
	// cell $procmux$810_CMP0
	i_procmux_24_768__CMP = eq_uu<1>(i_9_5c_qo_5b_5_5d__5b_1_3a_0_5d_, value<2>{0x2u});
	// \full_case: 1
	// \src: receiver.v:116.77-116.77|receiver.v:116.6-116.104
	// cell $procmux$809_CMP0
	i_procmux_24_767__CMP = eq_uu<1>(i_9_5c_qo_5b_5_5d__5b_1_3a_0_5d_, value<2>{0x3u});
	// cells $procmux$946 $procmux$943 $procmux$941 $procmux$858 $add$receiver.v:116$297 $auto$opt_reduce.cc:131:opt_pmux$7054
	i_11_5c_tokens0_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_296__Y ? (i_procmux_24_862__CMP ? add_uu<4>(i_9_5c_tokens0_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_861__CMP.concat(i_procmux_24_860__CMP).concat(i_procmux_24_859__CMP).val()) ? i_9_5c_tokens0_5b_3_3a_0_5d_ : value<4>{0u})) : i_9_5c_tokens0_5b_3_3a_0_5d_) : value<4>{0u}));
	// \full_case: 1
	// \src: receiver.v:116.17-116.17|receiver.v:116.6-116.104
	// cell $procmux$812_CMP0
	i_procmux_24_770__CMP = logic_not<1>(i_9_5c_qo_5b_5_5d__5b_1_3a_0_5d_);
	// cells $procmux$937 $procmux$934 $procmux$932 $procmux$900 $add$receiver.v:116$298 $auto$opt_reduce.cc:131:opt_pmux$7044
	i_11_5c_tokens1_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_296__Y ? (i_procmux_24_861__CMP ? add_uu<4>(i_9_5c_tokens1_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_862__CMP.concat(i_procmux_24_860__CMP).concat(i_procmux_24_859__CMP).val()) ? i_9_5c_tokens1_5b_3_3a_0_5d_ : value<4>{0u})) : i_9_5c_tokens1_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$928 $procmux$925 $procmux$923 $procmux$886 $add$receiver.v:116$299 $auto$opt_reduce.cc:131:opt_pmux$7046
	i_11_5c_tokens2_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_296__Y ? (i_procmux_24_860__CMP ? add_uu<4>(i_9_5c_tokens2_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_862__CMP.concat(i_procmux_24_861__CMP).concat(i_procmux_24_859__CMP).val()) ? i_9_5c_tokens2_5b_3_3a_0_5d_ : value<4>{0u})) : i_9_5c_tokens2_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$919 $procmux$916 $procmux$914 $procmux$872 $add$receiver.v:116$300 $auto$opt_reduce.cc:131:opt_pmux$7052
	i_11_5c_tokens3_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_296__Y ? (reduce_or<1>(i_procmux_24_862__CMP.concat(i_procmux_24_861__CMP).concat(i_procmux_24_860__CMP).val()) ? i_9_5c_tokens3_5b_3_3a_0_5d_ : (i_procmux_24_859__CMP ? add_uu<4>(i_9_5c_tokens3_5b_3_3a_0_5d_, value<1>{0x1u}) : value<4>{0u})) : i_9_5c_tokens3_5b_3_3a_0_5d_) : value<4>{0u}));
	// \src: receiver.v:83.7-83.70
	// cell $neg$receiver.v:83$155
	i_neg_24_receiver_2e_v_3a_83_24_147__Y = neg_u<33>(i_add_24_receiver_2e_v_3a_82_24_141__Y);
	// \src: receiver.v:83.7-83.70
	// cell $shift$receiver.v:83$148
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7184.slice<15,0>() = shift_us<16>(value<4>{0xfu}, i_neg_24_receiver_2e_v_3a_83_24_147__Y);
	// \src: receiver.v:115.8-115.14
	// cell $lt$receiver.v:115$301
	i_lt_24_receiver_2e_v_3a_115_24_301__Y = lt_uu<1>(value<3>{0x5u}, i_7_5c_qlen_5b_3_3a_0_5d_);
	// \src: receiver.v:83.7-83.70
	// cell $not$receiver.v:83$149
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7183.slice<15,0>() = not_u<16>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7184.slice<15,0>().val());
	// cells $shift$receiver.v:83$156 $add$receiver.v:83$154
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7180.slice<15,0>() = shift_us<16>(add_uu<4>(i_shiftx_24_receiver_2e_v_3a_82_24_142__Y, value<1>{0x1u}), i_neg_24_receiver_2e_v_3a_83_24_147__Y);
	// cells $procmux$2475 $procmux$2472 $procmux$2470 $procmux$2114
	i_9_5c_qo_5b_6_5d__5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_209__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_213__Y ? i_6_5c_qo_5b_7_5d__5b_1_3a_0_5d_ : i_6_5c_qo_5b_6_5d__5b_1_3a_0_5d_) : i_6_5c_qo_5b_6_5d__5b_1_3a_0_5d_) : value<2>{0u}));
	// cells $or$receiver.v:83$157 $and$receiver.v:83$150
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7179.slice<15,0>() = or_uu<16>(and_uu<16>(p_outstanding.curr, i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7183.slice<15,0>().val()), i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7180.slice<15,0>().val());
	// \full_case: 1
	// \src: receiver.v:116.37-116.37|receiver.v:116.6-116.104
	// cell $procmux$719_CMP0
	i_procmux_24_677__CMP = eq_uu<1>(i_9_5c_qo_5b_6_5d__5b_1_3a_0_5d_, value<1>{0x1u});
	// \full_case: 1
	// \src: receiver.v:116.57-116.57|receiver.v:116.6-116.104
	// cell $procmux$718_CMP0
	i_procmux_24_676__CMP = eq_uu<1>(i_9_5c_qo_5b_6_5d__5b_1_3a_0_5d_, value<2>{0x2u});
	// \full_case: 1
	// \src: receiver.v:116.77-116.77|receiver.v:116.6-116.104
	// cell $procmux$717_CMP0
	i_procmux_24_675__CMP = eq_uu<1>(i_9_5c_qo_5b_6_5d__5b_1_3a_0_5d_, value<2>{0x3u});
	// cells $procmux$854 $procmux$851 $procmux$849 $procmux$766 $add$receiver.v:116$302 $auto$opt_reduce.cc:131:opt_pmux$7066
	i_13_5c_tokens0_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_301__Y ? (i_procmux_24_770__CMP ? add_uu<4>(i_11_5c_tokens0_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_769__CMP.concat(i_procmux_24_768__CMP).concat(i_procmux_24_767__CMP).val()) ? i_11_5c_tokens0_5b_3_3a_0_5d_ : value<4>{0u})) : i_11_5c_tokens0_5b_3_3a_0_5d_) : value<4>{0u}));
	// \full_case: 1
	// \src: receiver.v:116.17-116.17|receiver.v:116.6-116.104
	// cell $procmux$720_CMP0
	i_procmux_24_678__CMP = logic_not<1>(i_9_5c_qo_5b_6_5d__5b_1_3a_0_5d_);
	// cells $procmux$845 $procmux$842 $procmux$840 $procmux$808 $add$receiver.v:116$303 $auto$opt_reduce.cc:131:opt_pmux$7058
	i_13_5c_tokens1_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_301__Y ? (i_procmux_24_769__CMP ? add_uu<4>(i_11_5c_tokens1_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_770__CMP.concat(i_procmux_24_768__CMP).concat(i_procmux_24_767__CMP).val()) ? i_11_5c_tokens1_5b_3_3a_0_5d_ : value<4>{0u})) : i_11_5c_tokens1_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$836 $procmux$833 $procmux$831 $procmux$794 $add$receiver.v:116$304 $auto$opt_reduce.cc:131:opt_pmux$7060
	i_13_5c_tokens2_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_301__Y ? (i_procmux_24_768__CMP ? add_uu<4>(i_11_5c_tokens2_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_770__CMP.concat(i_procmux_24_769__CMP).concat(i_procmux_24_767__CMP).val()) ? i_11_5c_tokens2_5b_3_3a_0_5d_ : value<4>{0u})) : i_11_5c_tokens2_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$827 $procmux$824 $procmux$822 $procmux$780 $add$receiver.v:116$305 $auto$opt_reduce.cc:131:opt_pmux$7064
	i_13_5c_tokens3_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_301__Y ? (reduce_or<1>(i_procmux_24_770__CMP.concat(i_procmux_24_769__CMP).concat(i_procmux_24_768__CMP).val()) ? i_11_5c_tokens3_5b_3_3a_0_5d_ : (i_procmux_24_767__CMP ? add_uu<4>(i_11_5c_tokens3_5b_3_3a_0_5d_, value<1>{0x1u}) : value<4>{0u})) : i_11_5c_tokens3_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $logic_or$receiver.v:100$250 $eq$receiver.v:100$248 $eq$receiver.v:100$249
	i_logic__or_24_receiver_2e_v_3a_100_24_250__Y = logic_or<1>(eq_uu<1>(p_rp.curr, value<1>{0x1u}), eq_uu<1>(p_rp.curr, value<2>{0x2u}));
	// \src: receiver.v:83.50-83.64
	// cell $mul$receiver.v:83$198
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7175.slice<4,0>() = mul_uu<5>(value<3>{0x4u}, i_8_5c_releaseowner_5b_1_3a_0_5d_);
	// connection
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7175.slice<31,5>() = value<27>{0u};
	// \src: receiver.v:115.8-115.14
	// cell $lt$receiver.v:115$306
	i_lt_24_receiver_2e_v_3a_115_24_306__Y = lt_uu<1>(value<3>{0x6u}, i_7_5c_qlen_5b_3_3a_0_5d_);
	// \src: receiver.v:83.49-83.68
	// cell $add$receiver.v:83$199
	i_add_24_receiver_2e_v_3a_82_24_188__Y = add_uu<6>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7175.slice<4,0>().val(), value<1>{0u});
	// cells $procmux$2646 $procmux$2643 $procmux$2641 $procmux$1994
	i_3_5c_failed_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_209__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_213__Y ? p_failed.curr : value<1>{0x1u}) : p_failed.curr) : value<1>{0u}));
	// cells $procmux$1748 $procmux$1650
	i_4_5c_evblock_5b_0_3a_0_5d_ = (p_rone.curr ? (i_logic__or_24_receiver_2e_v_3a_100_24_250__Y ? value<1>{0u} : value<1>{0x1u}) : value<1>{0u});
	// cells $procmux$4854 $procmux$4851 $procmux$4849 $procmux$4571
	i_3_5c_outstanding_5b_15_3a_0_5d_ = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_5_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_129__Y ? p_outstanding.curr : i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7179.slice<15,0>().val()) : p_outstanding.curr) : value<16>{0u}));
	// \src: receiver.v:83.7-83.70
	// cell $neg$receiver.v:83$202
	i_neg_24_receiver_2e_v_3a_83_24_194__Y = neg_u<33>(i_add_24_receiver_2e_v_3a_82_24_188__Y);
	// cells $procmux$2466 $procmux$2463 $procmux$2461 $procmux$2102
	i_9_5c_qo_5b_7_5d__5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_209__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_213__Y ? value<2>{0u} : i_6_5c_qo_5b_7_5d__5b_1_3a_0_5d_) : i_6_5c_qo_5b_7_5d__5b_1_3a_0_5d_) : value<2>{0u}));
	// \src: receiver.v:83.49-83.68
	// cell $shiftx$receiver.v:83$200
	i_shiftx_24_receiver_2e_v_3a_82_24_189__Y = shiftx_us<4>(i_3_5c_outstanding_5b_15_3a_0_5d_, value<1>{0u}.concat(i_add_24_receiver_2e_v_3a_82_24_188__Y).val());
	// \src: receiver.v:83.7-83.70
	// cell $shift$receiver.v:83$195
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7173.slice<15,0>() = shift_us<16>(value<4>{0xfu}, i_neg_24_receiver_2e_v_3a_83_24_194__Y);
	// \full_case: 1
	// \src: receiver.v:116.37-116.37|receiver.v:116.6-116.104
	// cell $procmux$627_CMP0
	i_procmux_24_585__CMP = eq_uu<1>(i_9_5c_qo_5b_7_5d__5b_1_3a_0_5d_, value<1>{0x1u});
	// \full_case: 1
	// \src: receiver.v:116.57-116.57|receiver.v:116.6-116.104
	// cell $procmux$626_CMP0
	i_procmux_24_584__CMP = eq_uu<1>(i_9_5c_qo_5b_7_5d__5b_1_3a_0_5d_, value<2>{0x2u});
	// \full_case: 1
	// \src: receiver.v:116.77-116.77|receiver.v:116.6-116.104
	// cell $procmux$625_CMP0
	i_procmux_24_583__CMP = eq_uu<1>(i_9_5c_qo_5b_7_5d__5b_1_3a_0_5d_, value<2>{0x3u});
	// cells $procmux$762 $procmux$759 $procmux$757 $procmux$674 $add$receiver.v:116$307 $auto$opt_reduce.cc:131:opt_pmux$7076
	i_15_5c_tokens0_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_306__Y ? (i_procmux_24_678__CMP ? add_uu<4>(i_13_5c_tokens0_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_677__CMP.concat(i_procmux_24_676__CMP).concat(i_procmux_24_675__CMP).val()) ? i_13_5c_tokens0_5b_3_3a_0_5d_ : value<4>{0u})) : i_13_5c_tokens0_5b_3_3a_0_5d_) : value<4>{0u}));
	// \full_case: 1
	// \src: receiver.v:116.17-116.17|receiver.v:116.6-116.104
	// cell $procmux$628_CMP0
	i_procmux_24_586__CMP = logic_not<1>(i_9_5c_qo_5b_7_5d__5b_1_3a_0_5d_);
	// cells $procmux$753 $procmux$750 $procmux$748 $procmux$716 $add$receiver.v:116$308 $auto$opt_reduce.cc:131:opt_pmux$7068
	i_15_5c_tokens1_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_306__Y ? (i_procmux_24_677__CMP ? add_uu<4>(i_13_5c_tokens1_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_678__CMP.concat(i_procmux_24_676__CMP).concat(i_procmux_24_675__CMP).val()) ? i_13_5c_tokens1_5b_3_3a_0_5d_ : value<4>{0u})) : i_13_5c_tokens1_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$744 $procmux$741 $procmux$739 $procmux$702 $add$receiver.v:116$309 $auto$opt_reduce.cc:131:opt_pmux$7072
	i_15_5c_tokens2_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_306__Y ? (i_procmux_24_676__CMP ? add_uu<4>(i_13_5c_tokens2_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_678__CMP.concat(i_procmux_24_677__CMP).concat(i_procmux_24_675__CMP).val()) ? i_13_5c_tokens2_5b_3_3a_0_5d_ : value<4>{0u})) : i_13_5c_tokens2_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$735 $procmux$732 $procmux$730 $procmux$688 $add$receiver.v:116$310 $auto$opt_reduce.cc:131:opt_pmux$7074
	i_15_5c_tokens3_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_306__Y ? (reduce_or<1>(i_procmux_24_678__CMP.concat(i_procmux_24_677__CMP).concat(i_procmux_24_676__CMP).val()) ? i_13_5c_tokens3_5b_3_3a_0_5d_ : (i_procmux_24_675__CMP ? add_uu<4>(i_13_5c_tokens3_5b_3_3a_0_5d_, value<1>{0x1u}) : value<4>{0u})) : i_13_5c_tokens3_5b_3_3a_0_5d_) : value<4>{0u}));
	// \src: receiver.v:83.7-83.70
	// cell $not$receiver.v:83$196
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7172.slice<15,0>() = not_u<16>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7173.slice<15,0>().val());
	// cells $procmux$1755 $procmux$1752 $procmux$1750
	i_4_5c_rone_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? value<1>{0u} : i_4_5c_evblock_5b_0_3a_0_5d_) : value<1>{0u}));
	// cells $shift$receiver.v:83$203 $add$receiver.v:83$201
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7169.slice<15,0>() = shift_us<16>(add_uu<4>(i_shiftx_24_receiver_2e_v_3a_82_24_189__Y, value<1>{0x1u}), i_neg_24_receiver_2e_v_3a_83_24_194__Y);
	// \src: receiver.v:115.8-115.14
	// cell $lt$receiver.v:115$311
	i_lt_24_receiver_2e_v_3a_115_24_311__Y = lt_uu<1>(value<3>{0x7u}, i_7_5c_qlen_5b_3_3a_0_5d_);
	// cells $procmux$2682 $procmux$2679 $procmux$2677 $procmux$2342
	i_3_5c_rzero_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_209__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_213__Y ? value<1>{0x1u} : p_rzero.curr) : p_rzero.curr) : value<1>{0u}));
	// cells $or$receiver.v:83$204 $and$receiver.v:83$197
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7168.slice<15,0>() = or_uu<16>(and_uu<16>(i_3_5c_outstanding_5b_15_3a_0_5d_, i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7172.slice<15,0>().val()), i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7169.slice<15,0>().val());
	// cells $logic_and$receiver.v:103$255 $logic_not$receiver.v:103$254
	i_logic__and_24_receiver_2e_v_3a_103_24_255__Y = logic_and<1>(i_3_5c_rzero_5b_0_3a_0_5d_, logic_not<1>(i_4_5c_rone_5b_0_3a_0_5d_));
	// cells $procmux$1719 $procmux$1716 $procmux$1714 $procmux$1712 $procmux$1590
	i_4_5c_emitowner_5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? value<2>{0u} : (p_rone.curr ? (i_logic__or_24_receiver_2e_v_3a_100_24_250__Y ? p_ownerone.curr : p_emitowner.curr) : p_emitowner.curr)) : value<2>{0u}));
	// cells $procmux$2673 $procmux$2670 $procmux$2668 $procmux$2330
	i_3_5c_ownerzero_5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_209__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_213__Y ? i_6_5c_qo_5b_0_5d__5b_1_3a_0_5d_ : p_ownerzero.curr) : p_ownerzero.curr) : value<2>{0u}));
	// \src: receiver.v:110.51-110.62
	// cell $mul$receiver.v:110$269
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7155.slice<4,0>() = mul_uu<5>(value<3>{0x4u}, i_4_5c_emitowner_5b_1_3a_0_5d_);
	// connection
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7155.slice<31,5>() = value<27>{0u};
	// \full_case: 1
	// \src: receiver.v:119.48-119.48|receiver.v:119.13-119.115
	// cell $procmux$535_CMP0
	i_procmux_24_493__CMP = eq_uu<1>(i_3_5c_ownerzero_5b_1_3a_0_5d_, value<1>{0x1u});
	// \full_case: 1
	// \src: receiver.v:119.68-119.68|receiver.v:119.13-119.115
	// cell $procmux$534_CMP0
	i_procmux_24_492__CMP = eq_uu<1>(i_3_5c_ownerzero_5b_1_3a_0_5d_, value<2>{0x2u});
	// \full_case: 1
	// \src: receiver.v:119.88-119.88|receiver.v:119.13-119.115
	// cell $procmux$533_CMP0
	i_procmux_24_491__CMP = eq_uu<1>(i_3_5c_ownerzero_5b_1_3a_0_5d_, value<2>{0x3u});
	// cells $procmux$670 $procmux$667 $procmux$665 $procmux$582 $add$receiver.v:116$312 $auto$opt_reduce.cc:131:opt_pmux$7088
	i_17_5c_tokens0_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_311__Y ? (i_procmux_24_586__CMP ? add_uu<4>(i_15_5c_tokens0_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_585__CMP.concat(i_procmux_24_584__CMP).concat(i_procmux_24_583__CMP).val()) ? i_15_5c_tokens0_5b_3_3a_0_5d_ : value<4>{0u})) : i_15_5c_tokens0_5b_3_3a_0_5d_) : value<4>{0u}));
	// \full_case: 1
	// \src: receiver.v:119.28-119.28|receiver.v:119.13-119.115
	// cell $procmux$536_CMP0
	i_procmux_24_494__CMP = logic_not<1>(i_3_5c_ownerzero_5b_1_3a_0_5d_);
	// cells $procmux$661 $procmux$658 $procmux$656 $procmux$624 $add$receiver.v:116$313 $auto$opt_reduce.cc:131:opt_pmux$7080
	i_17_5c_tokens1_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_311__Y ? (i_procmux_24_585__CMP ? add_uu<4>(i_15_5c_tokens1_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_586__CMP.concat(i_procmux_24_584__CMP).concat(i_procmux_24_583__CMP).val()) ? i_15_5c_tokens1_5b_3_3a_0_5d_ : value<4>{0u})) : i_15_5c_tokens1_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$652 $procmux$649 $procmux$647 $procmux$610 $add$receiver.v:116$314 $auto$opt_reduce.cc:131:opt_pmux$7082
	i_17_5c_tokens2_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_311__Y ? (i_procmux_24_584__CMP ? add_uu<4>(i_15_5c_tokens2_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_586__CMP.concat(i_procmux_24_585__CMP).concat(i_procmux_24_583__CMP).val()) ? i_15_5c_tokens2_5b_3_3a_0_5d_ : value<4>{0u})) : i_15_5c_tokens2_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$643 $procmux$640 $procmux$638 $procmux$596 $add$receiver.v:116$315 $auto$opt_reduce.cc:131:opt_pmux$7086
	i_17_5c_tokens3_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_lt_24_receiver_2e_v_3a_115_24_311__Y ? (reduce_or<1>(i_procmux_24_586__CMP.concat(i_procmux_24_585__CMP).concat(i_procmux_24_584__CMP).val()) ? i_15_5c_tokens3_5b_3_3a_0_5d_ : (i_procmux_24_583__CMP ? add_uu<4>(i_15_5c_tokens3_5b_3_3a_0_5d_, value<1>{0x1u}) : value<4>{0u})) : i_15_5c_tokens3_5b_3_3a_0_5d_) : value<4>{0u}));
	// \src: receiver.v:110.50-110.66
	// cell $add$receiver.v:110$270
	i_add_24_receiver_2e_v_3a_109_24_258__Y = add_uu<6>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7155.slice<4,0>().val(), value<1>{0u});
	// cells $procmux$3759 $procmux$3756 $procmux$3754 $procmux$3476
	i_5_5c_outstanding_5b_15_3a_0_5d_ = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_176__Y ? i_3_5c_outstanding_5b_15_3a_0_5d_ : i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7168.slice<15,0>().val()) : i_3_5c_outstanding_5b_15_3a_0_5d_) : value<16>{0u}));
	// \src: receiver.v:110.11-110.68
	// cell $neg$receiver.v:110$273
	i_neg_24_receiver_2e_v_3a_110_24_265__Y = neg_u<33>(i_add_24_receiver_2e_v_3a_109_24_258__Y);
	// cells $procmux$1890 $procmux$1887 $procmux$1885 $procmux$1436
	i_5_5c_rzero_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? i_3_5c_rzero_5b_0_3a_0_5d_ : (i_logic__and_24_receiver_2e_v_3a_103_24_255__Y ? value<1>{0u} : i_3_5c_rzero_5b_0_3a_0_5d_)) : value<1>{0u}));
	// \src: receiver.v:110.50-110.66
	// cell $shiftx$receiver.v:110$271
	i_shiftx_24_receiver_2e_v_3a_109_24_259__Y = shiftx_us<4>(i_5_5c_outstanding_5b_15_3a_0_5d_, value<1>{0u}.concat(i_add_24_receiver_2e_v_3a_109_24_258__Y).val());
	// \src: receiver.v:110.11-110.68
	// cell $shift$receiver.v:110$266
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7153.slice<15,0>() = shift_us<16>(value<4>{0xfu}, i_neg_24_receiver_2e_v_3a_110_24_265__Y);
	// \src: receiver.v:110.39-110.68
	// cell $sub$receiver.v:110$272
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7150.slice<3,0>() = sub_uu<4>(i_shiftx_24_receiver_2e_v_3a_109_24_259__Y, value<1>{0x1u});
	// \src: receiver.v:110.11-110.68
	// cell $not$receiver.v:110$267
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7152.slice<15,0>() = not_u<16>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7153.slice<15,0>().val());
	// \full_case: 1
	// \src: receiver.v:75.8-75.20|receiver.v:75.5-85.8
	// cell $procmux$4840
	i_procmux_24_4840__Y.slice<3,0>() = (i_5_5c_releasevalid_5b_0_3a_0_5d_ ? i_14_5c_fault_5b_31_3a_0_5d_.curr.slice<3,0>().val() : i_4_5c_fault_5b_31_3a_0_5d_.slice<3,0>().val());
	// connection
	i_procmux_24_4840__Y.slice<31,4>() = i_14_5c_fault_5b_31_3a_0_5d_.curr.slice<31,4>().val();
	// cells $procmux$1872 $procmux$1869 $procmux$1867 $procmux$1472
	i_3_5c_ownerone_5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? p_ownerone.curr : (i_logic__and_24_receiver_2e_v_3a_103_24_255__Y ? i_3_5c_ownerzero_5b_1_3a_0_5d_ : p_ownerone.curr)) : value<2>{0u}));
	// \src: receiver.v:110.11-110.68
	// cell $shift$receiver.v:110$274
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7149.slice<15,0>() = shift_us<16>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7150.slice<3,0>().val(), i_neg_24_receiver_2e_v_3a_110_24_265__Y);
	// \full_case: 1
	// \src: receiver.v:120.46-120.46|receiver.v:120.12-120.113
	// cell $procmux$443_CMP0
	i_procmux_24_401__CMP = eq_uu<1>(i_3_5c_ownerone_5b_1_3a_0_5d_, value<1>{0x1u});
	// \full_case: 1
	// \src: receiver.v:120.66-120.66|receiver.v:120.12-120.113
	// cell $procmux$442_CMP0
	i_procmux_24_400__CMP = eq_uu<1>(i_3_5c_ownerone_5b_1_3a_0_5d_, value<2>{0x2u});
	// \full_case: 1
	// \src: receiver.v:120.86-120.86|receiver.v:120.12-120.113
	// cell $procmux$441_CMP0
	i_procmux_24_399__CMP = eq_uu<1>(i_3_5c_ownerone_5b_1_3a_0_5d_, value<2>{0x3u});
	// cells $procmux$578 $procmux$575 $procmux$573 $procmux$490 $add$receiver.v:119$316 $auto$opt_reduce.cc:131:opt_pmux$7096
	i_19_5c_tokens0_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_5_5c_rzero_5b_0_3a_0_5d_ ? (i_procmux_24_494__CMP ? add_uu<4>(i_17_5c_tokens0_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_493__CMP.concat(i_procmux_24_492__CMP).concat(i_procmux_24_491__CMP).val()) ? i_17_5c_tokens0_5b_3_3a_0_5d_ : value<4>{0u})) : i_17_5c_tokens0_5b_3_3a_0_5d_) : value<4>{0u}));
	// \full_case: 1
	// \src: receiver.v:120.26-120.26|receiver.v:120.12-120.113
	// cell $procmux$444_CMP0
	i_procmux_24_402__CMP = logic_not<1>(i_3_5c_ownerone_5b_1_3a_0_5d_);
	// cells $procmux$569 $procmux$566 $procmux$564 $procmux$532 $add$receiver.v:119$317 $auto$opt_reduce.cc:131:opt_pmux$7090
	i_19_5c_tokens1_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_5_5c_rzero_5b_0_3a_0_5d_ ? (i_procmux_24_493__CMP ? add_uu<4>(i_17_5c_tokens1_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_494__CMP.concat(i_procmux_24_492__CMP).concat(i_procmux_24_491__CMP).val()) ? i_17_5c_tokens1_5b_3_3a_0_5d_ : value<4>{0u})) : i_17_5c_tokens1_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$560 $procmux$557 $procmux$555 $procmux$518 $add$receiver.v:119$318 $auto$opt_reduce.cc:131:opt_pmux$7092
	i_19_5c_tokens2_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_5_5c_rzero_5b_0_3a_0_5d_ ? (i_procmux_24_492__CMP ? add_uu<4>(i_17_5c_tokens2_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_494__CMP.concat(i_procmux_24_493__CMP).concat(i_procmux_24_491__CMP).val()) ? i_17_5c_tokens2_5b_3_3a_0_5d_ : value<4>{0u})) : i_17_5c_tokens2_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $procmux$551 $procmux$548 $procmux$546 $procmux$504 $add$receiver.v:119$319 $auto$opt_reduce.cc:131:opt_pmux$7094
	i_19_5c_tokens3_5b_3_3a_0_5d_ = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_5_5c_rzero_5b_0_3a_0_5d_ ? (reduce_or<1>(i_procmux_24_494__CMP.concat(i_procmux_24_493__CMP).concat(i_procmux_24_492__CMP).val()) ? i_17_5c_tokens3_5b_3_3a_0_5d_ : (i_procmux_24_491__CMP ? add_uu<4>(i_17_5c_tokens3_5b_3_3a_0_5d_, value<1>{0x1u}) : value<4>{0u})) : i_17_5c_tokens3_5b_3_3a_0_5d_) : value<4>{0u}));
	// cells $or$receiver.v:110$275 $and$receiver.v:110$268
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7148.slice<15,0>() = or_uu<16>(and_uu<16>(i_5_5c_outstanding_5b_15_3a_0_5d_, i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7152.slice<15,0>().val()), i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7149.slice<15,0>().val());
	// \src: receiver.v:109.9-109.39
	// cell $eq$receiver.v:109$260
	i_eq_24_receiver_2e_v_3a_109_24_260__Y = logic_not<1>(i_shiftx_24_receiver_2e_v_3a_109_24_259__Y);
	// cells $procmux$4845 $procmux$4842
	i_13_5c_fault_5b_31_3a_0_5d_ = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_14_5c_fault_5b_31_3a_0_5d_.curr.slice<31,4>().concat(i_procmux_24_4840__Y.slice<3,0>()).val() : value<32>{0u}));
	// cells $procmux$1743 $procmux$1740 $procmux$1738 $procmux$1736 $procmux$1605
	i_4_5c_evemit_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? value<1>{0u} : (p_rone.curr ? (i_logic__or_24_receiver_2e_v_3a_100_24_250__Y ? value<1>{0x1u} : value<1>{0u}) : value<1>{0u})) : value<1>{0u}));
	// cells $procmux$4872 $procmux$4869 $procmux$4867 $procmux$4595 $add$receiver.v:81$139
	i_3_5c_nextid_5b_31_3a_0_5d_ = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_5_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_129__Y ? p_nextid.curr : add_uu<32>(p_nextid.curr, value<1>{0x1u})) : p_nextid.curr) : value<32>{0u}));
	// \src: receiver.v:93.61-93.69
	// cell $mul$receiver.v:93$236
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7160.slice<6,0>() = mul_uu<7>(value<5>{0x10u}, i_6_5c_qo_5b_0_5d__5b_1_3a_0_5d_);
	// connection
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7160.slice<31,7>() = value<25>{0u};
	// cells $procmux$4705 $procmux$4391 $procmux$3850
	i_3_5c_qi_5b_0_5d__5b_31_3a_0_5d_ = (i_5_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_129__Y ? p_qi_5b_0_5d_.curr : (i_procmux_24_3858__CMP ? p_nextid.curr : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6977 ? p_qi_5b_0_5d_.curr : value<32>{0u}))) : p_qi_5b_0_5d_.curr);
	// cells $procmux$2741 $eq$receiver.v:82$190
	i_18_5c_fault_5b_31_3a_0_5d_.slice<3,0>() = (eq_uu<1>(i_shiftx_24_receiver_2e_v_3a_82_24_189__Y, value<4>{0xfu}) ? value<1>{0x1u}.concat(i_13_5c_fault_5b_31_3a_0_5d_.slice<2,0>()).val() : i_13_5c_fault_5b_31_3a_0_5d_.slice<3,0>().val());
	// connection
	i_18_5c_fault_5b_31_3a_0_5d_.slice<31,4>() = i_13_5c_fault_5b_31_3a_0_5d_.slice<31,4>().val();
	// cells $procmux$1881 $procmux$1878 $procmux$1876 $procmux$1484
	i_3_5c_rone_5b_0_3a_0_5d_ = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? p_rone.curr : (i_logic__and_24_receiver_2e_v_3a_103_24_255__Y ? value<1>{0x1u} : i_4_5c_rone_5b_0_3a_0_5d_)) : value<1>{0u}));
	// \src: receiver.v:91.63-91.70
	// cell $mul$receiver.v:91$218
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7167.slice<5,0>() = mul_uu<6>(value<4>{0x8u}, i_6_5c_qo_5b_0_5d__5b_1_3a_0_5d_);
	// connection
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7167.slice<31,6>() = value<26>{0u};
	// cells $procmux$4831 $procmux$4559
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7193.slice<0>() = (i_5_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_129__Y ? value<1>{0u} : value<1>{0x1u}) : value<1>{0u});
	// connection
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7193.slice<1>() = value<1>{0u};
	// \full_case: 1
	// \src: receiver.v:76.9-76.16|receiver.v:76.6-84.9
	// cell $procmux$3152
	i_17_5c_fault_5b_31_3a_0_5d_.slice<3,0>() = (i_ge_24_receiver_2e_v_3a_76_24_176__Y ? i_13_5c_fault_5b_31_3a_0_5d_.slice<3>().concat(value<1>{0x1u}).concat(i_13_5c_fault_5b_31_3a_0_5d_.slice<1,0>()).val() : i_18_5c_fault_5b_31_3a_0_5d_.slice<3,0>().val());
	// connection
	i_17_5c_fault_5b_31_3a_0_5d_.slice<31,4>() = i_13_5c_fault_5b_31_3a_0_5d_.slice<31,4>().val();
	// cells $neg$receiver.v:93$242 $add$receiver.v:93$237
	i_neg_24_receiver_2e_v_3a_93_24_238__Y = neg_u<33>(add_uu<8>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7160.slice<6,0>().val(), value<1>{0u}));
	// \src: receiver.v:93.37-93.53
	// cell $neg$receiver.v:93$233
	i_neg_24_receiver_2e_v_3a_93_24_226__Y = neg_u<3>(i_6_5c_qo_5b_0_5d__5b_1_3a_0_5d_);
	// cells $procmux$4642 $procmux$4307 $procmux$3871
	i_3_5c_qi_5b_7_5d__5b_31_3a_0_5d_ = (i_5_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_129__Y ? p_qi_5b_7_5d_.curr : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6975 ? p_qi_5b_7_5d_.curr : (i_procmux_24_3851__CMP ? p_nextid.curr : value<32>{0u}))) : p_qi_5b_7_5d_.curr);
	// cells $procmux$4651 $procmux$4319 $procmux$3892
	i_3_5c_qi_5b_6_5d__5b_31_3a_0_5d_ = (i_5_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_129__Y ? p_qi_5b_6_5d_.curr : (i_procmux_24_3852__CMP ? p_nextid.curr : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6973 ? p_qi_5b_6_5d_.curr : value<32>{0u}))) : p_qi_5b_6_5d_.curr);
	// cells $procmux$4660 $procmux$4331 $procmux$3913
	i_3_5c_qi_5b_5_5d__5b_31_3a_0_5d_ = (i_5_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_129__Y ? p_qi_5b_5_5d_.curr : (i_procmux_24_3853__CMP ? p_nextid.curr : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6971 ? p_qi_5b_5_5d_.curr : value<32>{0u}))) : p_qi_5b_5_5d_.curr);
	// cells $procmux$4669 $procmux$4343 $procmux$3934
	i_3_5c_qi_5b_4_5d__5b_31_3a_0_5d_ = (i_5_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_129__Y ? p_qi_5b_4_5d_.curr : (i_procmux_24_3854__CMP ? p_nextid.curr : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6969 ? p_qi_5b_4_5d_.curr : value<32>{0u}))) : p_qi_5b_4_5d_.curr);
	// cells $procmux$4678 $procmux$4355 $procmux$3955
	i_3_5c_qi_5b_3_5d__5b_31_3a_0_5d_ = (i_5_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_129__Y ? p_qi_5b_3_5d_.curr : (i_procmux_24_3855__CMP ? p_nextid.curr : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6967 ? p_qi_5b_3_5d_.curr : value<32>{0u}))) : p_qi_5b_3_5d_.curr);
	// cells $procmux$4687 $procmux$4367 $procmux$3976
	i_3_5c_qi_5b_2_5d__5b_31_3a_0_5d_ = (i_5_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_129__Y ? p_qi_5b_2_5d_.curr : (i_procmux_24_3856__CMP ? p_nextid.curr : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6965 ? p_qi_5b_2_5d_.curr : value<32>{0u}))) : p_qi_5b_2_5d_.curr);
	// cells $procmux$4696 $procmux$4379 $procmux$3997
	i_3_5c_qi_5b_1_5d__5b_31_3a_0_5d_ = (i_5_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_129__Y ? p_qi_5b_1_5d_.curr : (i_procmux_24_3857__CMP ? p_nextid.curr : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6979 ? p_qi_5b_1_5d_.curr : value<32>{0u}))) : p_qi_5b_1_5d_.curr);
	// cells $procmux$5987 $procmux$5984 $procmux$5982
	i_3_5c_bytes_5b_7_3a_0_5d_ = (p_rst ? value<8>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_59_24_90__Y ? p_wubytes.slice<7,0>().val() : p_bytes.curr.slice<7,0>().val()) : value<8>{0u}));
	// cells $procmux$5951 $procmux$5948 $procmux$5946
	i_4_5c_bytes_5b_15_3a_8_5d_ = (p_rst ? value<8>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_59_24_91__Y ? p_wubytes.slice<15,8>().val() : p_bytes.curr.slice<15,8>().val()) : value<8>{0u}));
	// cells $procmux$5915 $procmux$5912 $procmux$5910
	i_5_5c_bytes_5b_23_3a_16_5d_ = (p_rst ? value<8>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_59_24_92__Y ? p_wubytes.slice<23,16>().val() : p_bytes.curr.slice<23,16>().val()) : value<8>{0u}));
	// cells $procmux$5879 $procmux$5876 $procmux$5874
	i_6_5c_bytes_5b_31_3a_24_5d_ = (p_rst ? value<8>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_59_24_93__Y ? p_wubytes.slice<31,24>().val() : p_bytes.curr.slice<31,24>().val()) : value<8>{0u}));
	// \src: receiver.v:100.86-100.96
	// cell $mul$receiver.v:100$251
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7157.slice<5,0>() = mul_uu<6>(value<4>{0x8u}, p_ownerone.curr);
	// connection
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7157.slice<31,6>() = value<26>{0u};
	// \full_case: 1
	// \src: receiver.v:75.8-75.20|receiver.v:75.5-85.8
	// cell $procmux$3745
	i_16_5c_fault_5b_31_3a_0_5d_.slice<3,0>() = (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? i_17_5c_fault_5b_31_3a_0_5d_.slice<3,0>().val() : i_13_5c_fault_5b_31_3a_0_5d_.slice<3,0>().val());
	// connection
	i_16_5c_fault_5b_31_3a_0_5d_.slice<31,4>() = i_13_5c_fault_5b_31_3a_0_5d_.slice<31,4>().val();
	// \src: receiver.v:93.37-93.53
	// cell $shift$receiver.v:93$230
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7165.slice<3,0>() = shift_us<4>(value<1>{0x1u}, i_neg_24_receiver_2e_v_3a_93_24_226__Y);
	// cells $shiftx$receiver.v:91$220 $add$receiver.v:91$219
	i_shiftx_24_receiver_2e_v_3a_91_24_220__Y = shiftx_us<8>(i_6_5c_bytes_5b_31_3a_24_5d_.concat(i_5_5c_bytes_5b_23_3a_16_5d_).concat(i_4_5c_bytes_5b_15_3a_8_5d_).concat(i_3_5c_bytes_5b_7_3a_0_5d_).val(), value<1>{0u}.concat(add_uu<7>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7167.slice<5,0>().val(), value<1>{0u})).val());
	// cells $procmux$4836 $procmux$4833
	i_3_5c_evenq_5b_1_3a_0_5d_ = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? value<1>{0u}.concat(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7193.slice<0>()).val() : value<2>{0u}));
	// cells $procmux$3610 $procmux$3296 $procmux$2755
	i_6_5c_qi_5b_0_5d__5b_31_3a_0_5d_ = (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_176__Y ? i_3_5c_qi_5b_0_5d__5b_31_3a_0_5d_ : (i_procmux_24_2763__CMP ? i_3_5c_nextid_5b_31_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_7025 ? i_3_5c_qi_5b_0_5d__5b_31_3a_0_5d_ : value<32>{0u}))) : i_3_5c_qi_5b_0_5d__5b_31_3a_0_5d_);
	// cells $procmux$5816 $procmux$5813 $procmux$5811 $procmux$5087 $procmux$5022 $procmux$4941
	i_7_5c_enabled_5b_3_3a_0_5d_.slice<3>() = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_eq_24_receiver_2e_v_3a_61_24_94__Y ? (i_6_5c_enabled_5b_3_3a_3_5d_ ? (i_eq_24_receiver_2e_v_3a_64_24_107__Y ? value<1>{0x1u} : (i_eq_24_receiver_2e_v_3a_65_24_110__Y ? value<1>{0u} : value<1>{0x1u})) : value<1>{0u}) : i_6_5c_enabled_5b_3_3a_3_5d_) : value<1>{0u}));
	// cells $procmux$5789 $procmux$5786 $procmux$5784 $procmux$5654 $procmux$5589 $procmux$5508
	i_7_5c_enabled_5b_3_3a_0_5d_.slice<0>() = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_eq_24_receiver_2e_v_3a_61_24_94__Y ? (i_3_5c_enabled_5b_0_3a_0_5d_ ? (i_eq_24_receiver_2e_v_3a_64_24_95__Y ? value<1>{0x1u} : (i_eq_24_receiver_2e_v_3a_65_24_98__Y ? value<1>{0u} : value<1>{0x1u})) : value<1>{0u}) : i_3_5c_enabled_5b_0_3a_0_5d_) : value<1>{0u}));
	// cells $procmux$5753 $procmux$5750 $procmux$5748 $procmux$5465 $procmux$5400 $procmux$5319
	i_7_5c_enabled_5b_3_3a_0_5d_.slice<1>() = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_eq_24_receiver_2e_v_3a_61_24_94__Y ? (i_4_5c_enabled_5b_1_3a_1_5d_ ? (i_eq_24_receiver_2e_v_3a_64_24_99__Y ? value<1>{0x1u} : (i_eq_24_receiver_2e_v_3a_65_24_102__Y ? value<1>{0u} : value<1>{0x1u})) : value<1>{0u}) : i_4_5c_enabled_5b_1_3a_1_5d_) : value<1>{0u}));
	// cells $procmux$5717 $procmux$5714 $procmux$5712 $procmux$5276 $procmux$5211 $procmux$5130
	i_7_5c_enabled_5b_3_3a_0_5d_.slice<2>() = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_eq_24_receiver_2e_v_3a_61_24_94__Y ? (i_5_5c_enabled_5b_2_3a_2_5d_ ? (i_eq_24_receiver_2e_v_3a_64_24_103__Y ? value<1>{0x1u} : (i_eq_24_receiver_2e_v_3a_65_24_106__Y ? value<1>{0u} : value<1>{0x1u})) : value<1>{0u}) : i_5_5c_enabled_5b_2_3a_2_5d_) : value<1>{0u}));
	// \full_case: 1
	// \src: receiver.v:109.9-109.39|receiver.v:109.6-110.69
	// cell $procmux$1320
	i_21_5c_fault_5b_31_3a_0_5d_.slice<4,0>() = (i_eq_24_receiver_2e_v_3a_109_24_260__Y ? value<1>{0x1u}.concat(i_16_5c_fault_5b_31_3a_0_5d_.slice<3,0>()).val() : i_13_5c_fault_5b_31_3a_0_5d_.slice<4>().concat(i_16_5c_fault_5b_31_3a_0_5d_.slice<3,0>()).val());
	// connection
	i_21_5c_fault_5b_31_3a_0_5d_.slice<31,5>() = i_13_5c_fault_5b_31_3a_0_5d_.slice<31,5>().val();
	// cells $procmux$1809 $procmux$1806 $procmux$1804 $procmux$1388 $procmux$1350
	i_7_5c_outstanding_5b_15_3a_0_5d_ = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? i_5_5c_outstanding_5b_15_3a_0_5d_ : (i_4_5c_evemit_5b_0_3a_0_5d_ ? (i_eq_24_receiver_2e_v_3a_109_24_260__Y ? i_5_5c_outstanding_5b_15_3a_0_5d_ : i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7148.slice<15,0>().val()) : i_5_5c_outstanding_5b_15_3a_0_5d_)) : value<16>{0u}));
	// cells $procmux$5807 $procmux$5804 $procmux$5802 $procmux$5075 $procmux$5007
	i_7_5c_counts_5b_63_3a_0_5d_.slice<63,48>() = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_eq_24_receiver_2e_v_3a_61_24_94__Y ? (i_6_5c_enabled_5b_3_3a_3_5d_ ? (i_eq_24_receiver_2e_v_3a_64_24_107__Y ? i_6_5c_counts_5b_63_3a_48_5d_ : i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7189.slice<15,0>().val()) : i_6_5c_counts_5b_63_3a_48_5d_) : i_6_5c_counts_5b_63_3a_48_5d_) : value<16>{0u}));
	// cells $procmux$5780 $procmux$5777 $procmux$5775 $procmux$5642 $procmux$5574
	i_7_5c_counts_5b_63_3a_0_5d_.slice<15,0>() = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_eq_24_receiver_2e_v_3a_61_24_94__Y ? (i_3_5c_enabled_5b_0_3a_0_5d_ ? (i_eq_24_receiver_2e_v_3a_64_24_95__Y ? i_3_5c_counts_5b_15_3a_0_5d_ : i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7192.slice<15,0>().val()) : i_3_5c_counts_5b_15_3a_0_5d_) : i_3_5c_counts_5b_15_3a_0_5d_) : value<16>{0u}));
	// cells $procmux$5744 $procmux$5741 $procmux$5739 $procmux$5453 $procmux$5385
	i_7_5c_counts_5b_63_3a_0_5d_.slice<31,16>() = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_eq_24_receiver_2e_v_3a_61_24_94__Y ? (i_4_5c_enabled_5b_1_3a_1_5d_ ? (i_eq_24_receiver_2e_v_3a_64_24_99__Y ? i_4_5c_counts_5b_31_3a_16_5d_ : i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7191.slice<15,0>().val()) : i_4_5c_counts_5b_31_3a_16_5d_) : i_4_5c_counts_5b_31_3a_16_5d_) : value<16>{0u}));
	// cells $procmux$5708 $procmux$5705 $procmux$5703 $procmux$5264 $procmux$5196
	i_7_5c_counts_5b_63_3a_0_5d_.slice<47,32>() = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_eq_24_receiver_2e_v_3a_61_24_94__Y ? (i_5_5c_enabled_5b_2_3a_2_5d_ ? (i_eq_24_receiver_2e_v_3a_64_24_103__Y ? i_5_5c_counts_5b_47_3a_32_5d_ : i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7190.slice<15,0>().val()) : i_5_5c_counts_5b_47_3a_32_5d_) : i_5_5c_counts_5b_47_3a_32_5d_) : value<16>{0u}));
	// \src: receiver.v:93.37-93.53
	// cell $not$receiver.v:93$231
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7164.slice<3,0>() = not_u<4>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7165.slice<3,0>().val());
	// \src: receiver.v:78.10-78.18
	// cell $eq$receiver.v:78$183
	i_eq_24_receiver_2e_v_3a_78_24_183__Y = logic_not<1>(i_3_5c_evenq_5b_1_3a_0_5d_);
	// cells $procmux$4813 $procmux$4535
	i_3_5c_enqid_5b_31_3a_0_5d_ = (i_5_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_129__Y ? p_enqid.curr : p_nextid.curr) : p_enqid.curr);
	// cells $procmux$4822 $procmux$4547
	i_3_5c_enqowner_5b_1_3a_0_5d_ = (i_5_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_129__Y ? p_enqowner.curr : i_5_5c_enqowner_5b_1_3a_0_5d_) : p_enqowner.curr);
	// \full_case: 1
	// \src: receiver.v:107.8-107.14|receiver.v:107.5-111.8
	// cell $procmux$1376
	i_20_5c_fault_5b_31_3a_0_5d_.slice<4,0>() = (i_4_5c_evemit_5b_0_3a_0_5d_ ? i_21_5c_fault_5b_31_3a_0_5d_.slice<4,0>().val() : i_13_5c_fault_5b_31_3a_0_5d_.slice<4>().concat(i_16_5c_fault_5b_31_3a_0_5d_.slice<3,0>()).val());
	// connection
	i_20_5c_fault_5b_31_3a_0_5d_.slice<31,5>() = i_13_5c_fault_5b_31_3a_0_5d_.slice<31,5>().val();
	// cells $procmux$3777 $procmux$3774 $procmux$3772 $procmux$3500 $add$receiver.v:81$186
	i_5_5c_nextid_5b_31_3a_0_5d_ = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_176__Y ? i_3_5c_nextid_5b_31_3a_0_5d_ : add_uu<32>(i_3_5c_nextid_5b_31_3a_0_5d_, value<1>{0x1u})) : i_3_5c_nextid_5b_31_3a_0_5d_) : value<32>{0u}));
	// \src: receiver.v:93.37-93.53
	// cell $shift$receiver.v:93$234
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7162.slice<3,0>() = shift_us<4>(value<1>{0u}, i_neg_24_receiver_2e_v_3a_93_24_226__Y);
	// cells $procmux$3547 $procmux$3212 $procmux$2776
	i_6_5c_qi_5b_7_5d__5b_31_3a_0_5d_ = (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_176__Y ? i_3_5c_qi_5b_7_5d__5b_31_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_7019 ? i_3_5c_qi_5b_7_5d__5b_31_3a_0_5d_ : (i_procmux_24_2756__CMP ? i_3_5c_nextid_5b_31_3a_0_5d_ : value<32>{0u}))) : i_3_5c_qi_5b_7_5d__5b_31_3a_0_5d_);
	// cells $procmux$3556 $procmux$3224 $procmux$2797
	i_6_5c_qi_5b_6_5d__5b_31_3a_0_5d_ = (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_176__Y ? i_3_5c_qi_5b_6_5d__5b_31_3a_0_5d_ : (i_procmux_24_2757__CMP ? i_3_5c_nextid_5b_31_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_7011 ? i_3_5c_qi_5b_6_5d__5b_31_3a_0_5d_ : value<32>{0u}))) : i_3_5c_qi_5b_6_5d__5b_31_3a_0_5d_);
	// cells $procmux$3565 $procmux$3236 $procmux$2818
	i_6_5c_qi_5b_5_5d__5b_31_3a_0_5d_ = (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_176__Y ? i_3_5c_qi_5b_5_5d__5b_31_3a_0_5d_ : (i_procmux_24_2758__CMP ? i_3_5c_nextid_5b_31_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_7001 ? i_3_5c_qi_5b_5_5d__5b_31_3a_0_5d_ : value<32>{0u}))) : i_3_5c_qi_5b_5_5d__5b_31_3a_0_5d_);
	// cells $procmux$3574 $procmux$3248 $procmux$2839
	i_6_5c_qi_5b_4_5d__5b_31_3a_0_5d_ = (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_176__Y ? i_3_5c_qi_5b_4_5d__5b_31_3a_0_5d_ : (i_procmux_24_2759__CMP ? i_3_5c_nextid_5b_31_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6993 ? i_3_5c_qi_5b_4_5d__5b_31_3a_0_5d_ : value<32>{0u}))) : i_3_5c_qi_5b_4_5d__5b_31_3a_0_5d_);
	// cells $procmux$3583 $procmux$3260 $procmux$2860
	i_6_5c_qi_5b_3_5d__5b_31_3a_0_5d_ = (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_176__Y ? i_3_5c_qi_5b_3_5d__5b_31_3a_0_5d_ : (i_procmux_24_2760__CMP ? i_3_5c_nextid_5b_31_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6991 ? i_3_5c_qi_5b_3_5d__5b_31_3a_0_5d_ : value<32>{0u}))) : i_3_5c_qi_5b_3_5d__5b_31_3a_0_5d_);
	// cells $procmux$3592 $procmux$3272 $procmux$2881
	i_6_5c_qi_5b_2_5d__5b_31_3a_0_5d_ = (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_176__Y ? i_3_5c_qi_5b_2_5d__5b_31_3a_0_5d_ : (i_procmux_24_2761__CMP ? i_3_5c_nextid_5b_31_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6987 ? i_3_5c_qi_5b_2_5d__5b_31_3a_0_5d_ : value<32>{0u}))) : i_3_5c_qi_5b_2_5d__5b_31_3a_0_5d_);
	// cells $procmux$3601 $procmux$3284 $procmux$2902
	i_6_5c_qi_5b_1_5d__5b_31_3a_0_5d_ = (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_176__Y ? i_3_5c_qi_5b_1_5d__5b_31_3a_0_5d_ : (i_procmux_24_2762__CMP ? i_3_5c_nextid_5b_31_3a_0_5d_ : (i_auto_24_opt__reduce_2e_cc_3a_137_3a_opt__pmux_24_6985 ? i_3_5c_qi_5b_1_5d__5b_31_3a_0_5d_ : value<32>{0u}))) : i_3_5c_qi_5b_1_5d__5b_31_3a_0_5d_);
	// cells $procmux$2650 $procmux$2306
	i_3_5c_bytezero_5b_7_3a_0_5d_ = (i_logic__and_24_receiver_2e_v_3a_87_24_209__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_213__Y ? i_shiftx_24_receiver_2e_v_3a_91_24_220__Y : p_bytezero.curr) : p_bytezero.curr);
	// cells $procmux$1688 $procmux$1575
	i_4_5c_emitid_5b_31_3a_0_5d_ = (p_rone.curr ? (i_logic__or_24_receiver_2e_v_3a_100_24_250__Y ? p_idone.curr : p_emitid.curr) : p_emitid.curr);
	// cells $procmux$2659 $procmux$2318
	i_3_5c_idzero_5b_31_3a_0_5d_ = (i_logic__and_24_receiver_2e_v_3a_87_24_209__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_213__Y ? i_6_5c_qi_5b_0_5d__5b_31_3a_0_5d_ : p_idzero.curr) : p_idzero.curr);
	// \full_case: 1
	// \src: receiver.v:98.7-98.14|receiver.v:98.4-112.7
	// cell $procmux$1795
	i_19_5c_fault_5b_31_3a_0_5d_.slice<4,0>() = (i_3_5c_failed_5b_0_3a_0_5d_ ? i_13_5c_fault_5b_31_3a_0_5d_.slice<4>().concat(i_16_5c_fault_5b_31_3a_0_5d_.slice<3,0>()).val() : i_20_5c_fault_5b_31_3a_0_5d_.slice<4,0>().val());
	// connection
	i_19_5c_fault_5b_31_3a_0_5d_.slice<31,5>() = i_13_5c_fault_5b_31_3a_0_5d_.slice<31,5>().val();
	// cells $or$receiver.v:93$235 $and$receiver.v:93$232
	i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7161.slice<3,0>() = or_uu<4>(and_uu<4>(i_7_5c_enabled_5b_3_3a_0_5d_, i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7164.slice<3,0>().val()), i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7162.slice<3,0>().val());
	// \src: receiver.v:127.36-127.40
	// cell $add$receiver.v:127$344
	i_add_24_receiver_2e_v_3a_127_24_342__Y = add_uu<17>(p_pp.curr, value<1>{0x1u});
	// \src: receiver.v:126.31-126.35
	// cell $add$receiver.v:126$341
	i_add_24_receiver_2e_v_3a_126_24_339__Y = add_uu<17>(p_fp.curr, value<1>{0x1u});
	// \src: receiver.v:125.31-125.35
	// cell $add$receiver.v:125$338
	i_add_24_receiver_2e_v_3a_125_24_336__Y = add_uu<17>(p_rp.curr, value<1>{0x1u});
	// \src: receiver.v:124.31-124.35
	// cell $add$receiver.v:124$335
	i_add_24_receiver_2e_v_3a_124_24_333__Y = add_uu<17>(p_cp.curr, value<1>{0x1u});
	// cells $procmux$389 $logic_or$receiver.v:121$326 $gt$receiver.v:121$324 $ne$receiver.v:121$325 $procmux$486 $procmux$483 $procmux$481 $procmux$398 $add$receiver.v:120$320 $auto$opt_reduce.cc:131:opt_pmux$7106 $procmux$477 $procmux$474 $procmux$472 $procmux$440 $add$receiver.v:120$321 $auto$opt_reduce.cc:131:opt_pmux$7098 $procmux$468 $procmux$465 $procmux$463 $procmux$426 $add$receiver.v:120$322 $auto$opt_reduce.cc:131:opt_pmux$7100 $procmux$459 $procmux$456 $procmux$454 $procmux$412 $add$receiver.v:120$323 $auto$opt_reduce.cc:131:opt_pmux$7104
	i_22_5c_fault_5b_31_3a_0_5d_.slice<5,0>() = (logic_or<1>(gt_uu<1>(i_7_5c_qlen_5b_3_3a_0_5d_, value<4>{0x8u}), ne_uu<1>((p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_rone_5b_0_3a_0_5d_ ? (reduce_or<1>(i_procmux_24_402__CMP.concat(i_procmux_24_401__CMP).concat(i_procmux_24_400__CMP).val()) ? i_19_5c_tokens3_5b_3_3a_0_5d_ : (i_procmux_24_399__CMP ? add_uu<4>(i_19_5c_tokens3_5b_3_3a_0_5d_, value<1>{0x1u}) : value<4>{0u})) : i_19_5c_tokens3_5b_3_3a_0_5d_) : value<4>{0u})).concat((p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_rone_5b_0_3a_0_5d_ ? (i_procmux_24_400__CMP ? add_uu<4>(i_19_5c_tokens2_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_402__CMP.concat(i_procmux_24_401__CMP).concat(i_procmux_24_399__CMP).val()) ? i_19_5c_tokens2_5b_3_3a_0_5d_ : value<4>{0u})) : i_19_5c_tokens2_5b_3_3a_0_5d_) : value<4>{0u}))).concat((p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_rone_5b_0_3a_0_5d_ ? (i_procmux_24_401__CMP ? add_uu<4>(i_19_5c_tokens1_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_402__CMP.concat(i_procmux_24_400__CMP).concat(i_procmux_24_399__CMP).val()) ? i_19_5c_tokens1_5b_3_3a_0_5d_ : value<4>{0u})) : i_19_5c_tokens1_5b_3_3a_0_5d_) : value<4>{0u}))).concat((p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_rone_5b_0_3a_0_5d_ ? (i_procmux_24_402__CMP ? add_uu<4>(i_19_5c_tokens0_5b_3_3a_0_5d_, value<1>{0x1u}) : (reduce_or<1>(i_procmux_24_401__CMP.concat(i_procmux_24_400__CMP).concat(i_procmux_24_399__CMP).val()) ? i_19_5c_tokens0_5b_3_3a_0_5d_ : value<4>{0u})) : i_19_5c_tokens0_5b_3_3a_0_5d_) : value<4>{0u}))).val(), i_7_5c_outstanding_5b_15_3a_0_5d_)) ? value<1>{0x1u}.concat(i_19_5c_fault_5b_31_3a_0_5d_.slice<4,0>()).val() : i_13_5c_fault_5b_31_3a_0_5d_.slice<5>().concat(i_19_5c_fault_5b_31_3a_0_5d_.slice<4,0>()).val());
	// connection
	i_22_5c_fault_5b_31_3a_0_5d_.slice<31,6>() = i_13_5c_fault_5b_31_3a_0_5d_.slice<31,6>().val();
	// cells $procmux$5766 $procmux$5618 $procmux$5559 $procmux$5490
	i_3_5c_evexpire_5b_3_3a_0_5d_.slice<0>() = (i_eq_24_receiver_2e_v_3a_61_24_94__Y ? (i_3_5c_enabled_5b_0_3a_0_5d_ ? (i_eq_24_receiver_2e_v_3a_64_24_95__Y ? value<1>{0u} : (i_eq_24_receiver_2e_v_3a_65_24_98__Y ? value<1>{0x1u} : value<1>{0u})) : value<1>{0u}) : value<1>{0u});
	// cells $procmux$5730 $procmux$5429 $procmux$5370 $procmux$5301
	i_3_5c_evexpire_5b_3_3a_0_5d_.slice<1>() = (i_eq_24_receiver_2e_v_3a_61_24_94__Y ? (i_4_5c_enabled_5b_1_3a_1_5d_ ? (i_eq_24_receiver_2e_v_3a_64_24_99__Y ? value<1>{0u} : (i_eq_24_receiver_2e_v_3a_65_24_102__Y ? value<1>{0x1u} : value<1>{0u})) : value<1>{0u}) : value<1>{0u});
	// cells $procmux$5685 $procmux$5240 $procmux$5181 $procmux$5112
	i_3_5c_evexpire_5b_3_3a_0_5d_.slice<2>() = (i_eq_24_receiver_2e_v_3a_61_24_94__Y ? (i_5_5c_enabled_5b_2_3a_2_5d_ ? (i_eq_24_receiver_2e_v_3a_64_24_103__Y ? value<1>{0u} : (i_eq_24_receiver_2e_v_3a_65_24_106__Y ? value<1>{0x1u} : value<1>{0u})) : value<1>{0u}) : value<1>{0u});
	// cells $procmux$4930 $procmux$5051 $procmux$4992 $procmux$5831
	i_3_5c_evexpire_5b_3_3a_0_5d_.slice<3>() = (i_eq_24_receiver_2e_v_3a_61_24_94__Y ? (i_6_5c_enabled_5b_3_3a_3_5d_ ? (i_eq_24_receiver_2e_v_3a_64_24_107__Y ? value<1>{0u} : (i_eq_24_receiver_2e_v_3a_65_24_110__Y ? value<1>{0x1u} : value<1>{0u})) : value<1>{0u}) : value<1>{0u});
	// cells $procmux$380 $logic_or$receiver.v:122$330 $ge$receiver.v:122$328 $ge$receiver.v:122$329
	i_23_5c_fault_5b_31_3a_0_5d_.slice<6,0>() = (logic_or<1>(ge_uu<1>(p_tick.curr, value<31>{0x7ffffffeu}), ge_uu<1>(i_5_5c_nextid_5b_31_3a_0_5d_, value<31>{0x7ffffffeu})) ? value<1>{0x1u}.concat(i_22_5c_fault_5b_31_3a_0_5d_.slice<5,0>()).val() : i_13_5c_fault_5b_31_3a_0_5d_.slice<6>().concat(i_22_5c_fault_5b_31_3a_0_5d_.slice<5,0>()).val());
	// connection
	i_23_5c_fault_5b_31_3a_0_5d_.slice<31,7>() = i_13_5c_fault_5b_31_3a_0_5d_.slice<31,7>().val();
	// cells $procmux$6554 $procmux$5955
	i_2_5c_evwu_5b_3_3a_0_5d_.slice<0>() = (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_59_24_90__Y ? value<1>{0x1u} : value<1>{0u}) : p_evwu.curr.slice<0>().val());
	// cells $procmux$6542 $procmux$5919
	i_2_5c_evwu_5b_3_3a_0_5d_.slice<1>() = (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_59_24_91__Y ? value<1>{0x1u} : value<1>{0u}) : p_evwu.curr.slice<1>().val());
	// cells $procmux$6530 $procmux$5883
	i_2_5c_evwu_5b_3_3a_0_5d_.slice<2>() = (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_59_24_92__Y ? value<1>{0x1u} : value<1>{0u}) : p_evwu.curr.slice<2>().val());
	// cells $procmux$346 $procmux$5847
	i_2_5c_evwu_5b_3_3a_0_5d_.slice<3>() = (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_59_24_93__Y ? value<1>{0x1u} : value<1>{0u}) : p_evwu.curr.slice<3>().val());
	// \full_case: 1
	// \src: receiver.v:55.15-55.34|receiver.v:55.12-128.6
	// cell $procmux$6566
	i_2_5c_bytes_5b_31_3a_0_5d_.slice<31,24>() = (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_6_5c_bytes_5b_31_3a_24_5d_ : p_bytes.curr.slice<31,24>().val());
	// \full_case: 1
	// \src: receiver.v:55.15-55.34|receiver.v:55.12-128.6
	// cell $procmux$6560
	i_2_5c_bytes_5b_31_3a_0_5d_.slice<7,0>() = (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_3_5c_bytes_5b_7_3a_0_5d_ : p_bytes.curr.slice<7,0>().val());
	// \full_case: 1
	// \src: receiver.v:55.15-55.34|receiver.v:55.12-128.6
	// cell $procmux$6548
	i_2_5c_bytes_5b_31_3a_0_5d_.slice<15,8>() = (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_4_5c_bytes_5b_15_3a_8_5d_ : p_bytes.curr.slice<15,8>().val());
	// \full_case: 1
	// \src: receiver.v:55.15-55.34|receiver.v:55.12-128.6
	// cell $procmux$6536
	i_2_5c_bytes_5b_31_3a_0_5d_.slice<23,16>() = (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_5_5c_bytes_5b_23_3a_16_5d_ : p_bytes.curr.slice<23,16>().val());
	// cells $procdff$6955 $procmux$6743 $procmux$6182 $procmux$2389 $procmux$2006
	if (posedge_p_clk) {
		p_qi_5b_7_5d_.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_209__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_213__Y ? value<32>{0u} : i_6_5c_qi_5b_7_5d__5b_31_3a_0_5d_) : i_6_5c_qi_5b_7_5d__5b_31_3a_0_5d_) : p_qi_5b_7_5d_.curr));
	}
	// cells $procdff$6954 $procmux$6749 $procmux$6188 $procmux$2398 $procmux$2018
	if (posedge_p_clk) {
		p_qi_5b_6_5d_.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_209__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_213__Y ? i_6_5c_qi_5b_7_5d__5b_31_3a_0_5d_ : i_6_5c_qi_5b_6_5d__5b_31_3a_0_5d_) : i_6_5c_qi_5b_6_5d__5b_31_3a_0_5d_) : p_qi_5b_6_5d_.curr));
	}
	// cells $procdff$6953 $procmux$6755 $procmux$6194 $procmux$2407 $procmux$2030
	if (posedge_p_clk) {
		p_qi_5b_5_5d_.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_209__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_213__Y ? i_6_5c_qi_5b_6_5d__5b_31_3a_0_5d_ : i_6_5c_qi_5b_5_5d__5b_31_3a_0_5d_) : i_6_5c_qi_5b_5_5d__5b_31_3a_0_5d_) : p_qi_5b_5_5d_.curr));
	}
	// cells $procdff$6952 $procmux$6761 $procmux$6200 $procmux$2416 $procmux$2042
	if (posedge_p_clk) {
		p_qi_5b_4_5d_.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_209__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_213__Y ? i_6_5c_qi_5b_5_5d__5b_31_3a_0_5d_ : i_6_5c_qi_5b_4_5d__5b_31_3a_0_5d_) : i_6_5c_qi_5b_4_5d__5b_31_3a_0_5d_) : p_qi_5b_4_5d_.curr));
	}
	// cells $procdff$6951 $procmux$6767 $procmux$6206 $procmux$2425 $procmux$2054
	if (posedge_p_clk) {
		p_qi_5b_3_5d_.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_209__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_213__Y ? i_6_5c_qi_5b_4_5d__5b_31_3a_0_5d_ : i_6_5c_qi_5b_3_5d__5b_31_3a_0_5d_) : i_6_5c_qi_5b_3_5d__5b_31_3a_0_5d_) : p_qi_5b_3_5d_.curr));
	}
	// cells $procdff$6950 $procmux$6773 $procmux$6212 $procmux$2434 $procmux$2066
	if (posedge_p_clk) {
		p_qi_5b_2_5d_.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_209__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_213__Y ? i_6_5c_qi_5b_3_5d__5b_31_3a_0_5d_ : i_6_5c_qi_5b_2_5d__5b_31_3a_0_5d_) : i_6_5c_qi_5b_2_5d__5b_31_3a_0_5d_) : p_qi_5b_2_5d_.curr));
	}
	// cells $procdff$6949 $procmux$6779 $procmux$6218 $procmux$2443 $procmux$2078
	if (posedge_p_clk) {
		p_qi_5b_1_5d_.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_209__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_213__Y ? i_6_5c_qi_5b_2_5d__5b_31_3a_0_5d_ : i_6_5c_qi_5b_1_5d__5b_31_3a_0_5d_) : i_6_5c_qi_5b_1_5d__5b_31_3a_0_5d_) : p_qi_5b_1_5d_.curr));
	}
	// cells $procdff$6948 $procmux$6785 $procmux$6224 $procmux$2452 $procmux$2090
	if (posedge_p_clk) {
		p_qi_5b_0_5d_.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_209__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_213__Y ? i_6_5c_qi_5b_1_5d__5b_31_3a_0_5d_ : i_6_5c_qi_5b_0_5d__5b_31_3a_0_5d_) : i_6_5c_qi_5b_0_5d__5b_31_3a_0_5d_) : p_qi_5b_0_5d_.curr));
	}
	// cells $procdff$6947 $procmux$6746 $procmux$6230
	if (posedge_p_clk) {
		p_qo_5b_7_5d_.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_9_5c_qo_5b_7_5d__5b_1_3a_0_5d_ : p_qo_5b_7_5d_.curr));
	}
	// cells $procdff$6946 $procmux$6752 $procmux$6236
	if (posedge_p_clk) {
		p_qo_5b_6_5d_.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_9_5c_qo_5b_6_5d__5b_1_3a_0_5d_ : p_qo_5b_6_5d_.curr));
	}
	// cells $procdff$6945 $procmux$6758 $procmux$6242
	if (posedge_p_clk) {
		p_qo_5b_5_5d_.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_9_5c_qo_5b_5_5d__5b_1_3a_0_5d_ : p_qo_5b_5_5d_.curr));
	}
	// cells $procdff$6944 $procmux$6764 $procmux$6248
	if (posedge_p_clk) {
		p_qo_5b_4_5d_.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_9_5c_qo_5b_4_5d__5b_1_3a_0_5d_ : p_qo_5b_4_5d_.curr));
	}
	// cells $procdff$6943 $procmux$6770 $procmux$6254
	if (posedge_p_clk) {
		p_qo_5b_3_5d_.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_9_5c_qo_5b_3_5d__5b_1_3a_0_5d_ : p_qo_5b_3_5d_.curr));
	}
	// cells $procdff$6942 $procmux$6776 $procmux$6260
	if (posedge_p_clk) {
		p_qo_5b_2_5d_.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_9_5c_qo_5b_2_5d__5b_1_3a_0_5d_ : p_qo_5b_2_5d_.curr));
	}
	// cells $procdff$6941 $procmux$6782 $procmux$6266
	if (posedge_p_clk) {
		p_qo_5b_1_5d_.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_9_5c_qo_5b_1_5d__5b_1_3a_0_5d_ : p_qo_5b_1_5d_.curr));
	}
	// cells $procdff$6940 $procmux$6788 $procmux$6272
	if (posedge_p_clk) {
		p_qo_5b_0_5d_.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_9_5c_qo_5b_0_5d__5b_1_3a_0_5d_ : p_qo_5b_0_5d_.curr));
	}
	// cells $procdff$6924 $procmux$6623 $procmux$6062 $procmux$1813 $procmux$1496
	if (posedge_p_clk) {
		p_transferbyte.next = (p_rst ? value<8>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? p_transferbyte.curr : (i_logic__and_24_receiver_2e_v_3a_103_24_255__Y ? i_3_5c_bytezero_5b_7_3a_0_5d_ : p_transferbyte.curr)) : p_transferbyte.curr));
	}
	// cells $procdff$6923 $procmux$6626 $procmux$6068 $procmux$1894 $procmux$1664 $procmux$1560 $shiftx$receiver.v:100$253 $add$receiver.v:100$252
	if (posedge_p_clk) {
		p_emitbyte.next = (p_rst ? value<8>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? p_emitbyte.curr : (p_rone.curr ? (i_logic__or_24_receiver_2e_v_3a_100_24_250__Y ? shiftx_us<8>(i_6_5c_bytes_5b_31_3a_24_5d_.concat(i_5_5c_bytes_5b_23_3a_16_5d_).concat(i_4_5c_bytes_5b_15_3a_8_5d_).concat(i_3_5c_bytes_5b_7_3a_0_5d_).val(), value<1>{0u}.concat(add_uu<7>(i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7157.slice<5,0>().val(), value<1>{0u})).val()) : p_emitbyte.curr) : p_emitbyte.curr)) : p_emitbyte.curr));
	}
	// cells $procdff$6922 $procmux$6629 $procmux$6296 $procmux$2569 $procmux$2246
	if (posedge_p_clk) {
		p_grantbyte.next = (p_rst ? value<8>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_209__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_213__Y ? i_shiftx_24_receiver_2e_v_3a_91_24_220__Y : p_grantbyte.curr) : p_grantbyte.curr) : p_grantbyte.curr));
	}
	// cells $procdff$6921 $procmux$6617 $procmux$6440 $procmux$3700 $procmux$3416 $procmux$3122
	if (posedge_p_clk) {
		p_enqid2.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_176__Y ? p_enqid2.curr : (i_eq_24_receiver_2e_v_3a_78_24_183__Y ? p_enqid2.curr : i_3_5c_nextid_5b_31_3a_0_5d_)) : p_enqid2.curr) : p_enqid2.curr));
	}
	// cells $procdff$6920 $procmux$6620 $procmux$6446 $procmux$3709 $procmux$3428 $procmux$3137
	if (posedge_p_clk) {
		p_enqowner2.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_176__Y ? p_enqowner2.curr : (i_eq_24_receiver_2e_v_3a_78_24_183__Y ? p_enqowner2.curr : i_8_5c_releaseowner_5b_1_3a_0_5d_)) : p_enqowner2.curr) : p_enqowner2.curr));
	}
	// cells $procdff$6919 $procmux$6632 $procmux$6074 $procmux$1903 $procmux$1676 $procmux$1620
	if (posedge_p_clk) {
		p_blockid.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? p_blockid.curr : (p_rone.curr ? (i_logic__or_24_receiver_2e_v_3a_100_24_250__Y ? p_blockid.curr : p_idone.curr) : p_blockid.curr)) : p_blockid.curr));
	}
	// cells $procdff$6918 $procmux$6635 $procmux$6080 $procmux$1768 $procmux$1400
	if (posedge_p_clk) {
		p_callbackid.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? p_callbackid.curr : (i_4_5c_evemit_5b_0_3a_0_5d_ ? i_4_5c_emitid_5b_31_3a_0_5d_ : p_callbackid.curr)) : p_callbackid.curr));
	}
	// cells $procdff$6917 $procmux$6638 $procmux$6086 $procmux$1822 $procmux$1508
	if (posedge_p_clk) {
		p_transferid.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? p_transferid.curr : (i_logic__and_24_receiver_2e_v_3a_103_24_255__Y ? i_3_5c_idzero_5b_31_3a_0_5d_ : p_transferid.curr)) : p_transferid.curr));
	}
	// cells $procdff$6916 $procmux$6641 $procmux$6092 $procmux$1912
	if (posedge_p_clk) {
		p_emitid.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? p_emitid.curr : i_4_5c_emitid_5b_31_3a_0_5d_) : p_emitid.curr));
	}
	// cells $procdff$6915 $procmux$6644 $procmux$6302 $procmux$2578 $procmux$2258
	if (posedge_p_clk) {
		p_grantid.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_209__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_213__Y ? i_6_5c_qi_5b_0_5d__5b_31_3a_0_5d_ : p_grantid.curr) : p_grantid.curr) : p_grantid.curr));
	}
	// cells $procdff$6914 $procmux$6647 $procmux$6308 $procmux$2713
	if (posedge_p_clk) {
		p_attemptid.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_209__Y ? i_6_5c_qi_5b_0_5d__5b_31_3a_0_5d_ : p_attemptid.curr) : p_attemptid.curr));
	}
	// cells $procdff$6913 $procmux$6650 $procmux$6452 $procmux$3718 $procmux$3440 $procmux$3092
	if (posedge_p_clk) {
		p_enqid.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_176__Y ? i_3_5c_enqid_5b_31_3a_0_5d_ : (i_eq_24_receiver_2e_v_3a_78_24_183__Y ? i_3_5c_nextid_5b_31_3a_0_5d_ : i_3_5c_enqid_5b_31_3a_0_5d_)) : i_3_5c_enqid_5b_31_3a_0_5d_) : p_enqid.curr));
	}
	// cells $procdff$6912 $procmux$6653 $procmux$6098 $procmux$1921 $procmux$1700 $procmux$1635
	if (posedge_p_clk) {
		p_blockowner.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? p_blockowner.curr : (p_rone.curr ? (i_logic__or_24_receiver_2e_v_3a_100_24_250__Y ? p_blockowner.curr : p_ownerone.curr) : p_blockowner.curr)) : p_blockowner.curr));
	}
	// cells $procdff$6911 $procmux$6656 $procmux$6104 $procmux$1777 $procmux$1412
	if (posedge_p_clk) {
		p_callbackowner.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? p_callbackowner.curr : (i_4_5c_evemit_5b_0_3a_0_5d_ ? i_4_5c_emitowner_5b_1_3a_0_5d_ : p_callbackowner.curr)) : p_callbackowner.curr));
	}
	// cells $procdff$6910 $procmux$6659 $procmux$6110 $procmux$1831 $procmux$1520
	if (posedge_p_clk) {
		p_transferowner.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? p_transferowner.curr : (i_logic__and_24_receiver_2e_v_3a_103_24_255__Y ? i_3_5c_ownerzero_5b_1_3a_0_5d_ : p_transferowner.curr)) : p_transferowner.curr));
	}
	// cells $procdff$6909 $procmux$6662 $procmux$6116 $procmux$1930
	if (posedge_p_clk) {
		p_emitowner.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? p_emitowner.curr : i_4_5c_emitowner_5b_1_3a_0_5d_) : p_emitowner.curr));
	}
	// cells $procdff$6908 $procmux$6665 $procmux$6314 $procmux$2587 $procmux$2270
	if (posedge_p_clk) {
		p_grantowner.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_209__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_213__Y ? i_6_5c_qo_5b_0_5d__5b_1_3a_0_5d_ : p_grantowner.curr) : p_grantowner.curr) : p_grantowner.curr));
	}
	// cells $procdff$6907 $procmux$6668 $procmux$6320 $procmux$2722
	if (posedge_p_clk) {
		p_attemptowner.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_209__Y ? i_6_5c_qo_5b_0_5d__5b_1_3a_0_5d_ : p_attemptowner.curr) : p_attemptowner.curr));
	}
	// cells $procdff$6906 $procmux$6671 $procmux$6458 $procmux$3727 $procmux$3452 $procmux$3107
	if (posedge_p_clk) {
		p_enqowner.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_176__Y ? i_3_5c_enqowner_5b_1_3a_0_5d_ : (i_eq_24_receiver_2e_v_3a_78_24_183__Y ? i_8_5c_releaseowner_5b_1_3a_0_5d_ : i_3_5c_enqowner_5b_1_3a_0_5d_)) : i_3_5c_enqowner_5b_1_3a_0_5d_) : p_enqowner.curr));
	}
	// cells $procdff$6905 $procmux$6674 $procmux$6122 $procmux$1939
	if (posedge_p_clk) {
		p_evblock.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? value<1>{0u} : i_4_5c_evblock_5b_0_3a_0_5d_) : p_evblock.curr));
	}
	// cells $procdff$6904 $procmux$6677 $procmux$6128 $procmux$1786 $procmux$1424
	if (posedge_p_clk) {
		p_evcallback.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? value<1>{0u} : (i_4_5c_evemit_5b_0_3a_0_5d_ ? value<1>{0x1u} : value<1>{0u})) : p_evcallback.curr));
	}
	// cells $procdff$6903 $procmux$6680 $procmux$6134 $procmux$1840 $procmux$1532
	if (posedge_p_clk) {
		p_evtransfer.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_103_24_255__Y ? value<1>{0x1u} : value<1>{0u})) : p_evtransfer.curr));
	}
	// cells $procdff$6902 $procmux$6683 $procmux$6140 $procmux$1948
	if (posedge_p_clk) {
		p_evemit.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? value<1>{0u} : i_4_5c_evemit_5b_0_3a_0_5d_) : p_evemit.curr));
	}
	// cells $procdff$6901 $procmux$6686 $procmux$6326 $procmux$2596 $procmux$2282
	if (posedge_p_clk) {
		p_evgrant.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_209__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_213__Y ? value<1>{0x1u} : value<1>{0u}) : value<1>{0u}) : p_evgrant.curr));
	}
	// cells $procdff$6900 $procmux$6689 $procmux$6332 $procmux$2731
	if (posedge_p_clk) {
		p_evattempt.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_209__Y ? value<1>{0x1u} : value<1>{0u}) : p_evattempt.curr));
	}
	// cells $procdff$6899 $procmux$6692 $procmux$6464 $procmux$3736 $procmux$3464 $add$receiver.v:80$184
	if (posedge_p_clk) {
		p_evenq.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_8_5c_releasevalid_5b_0_3a_0_5d_ ? (i_ge_24_receiver_2e_v_3a_76_24_176__Y ? i_3_5c_evenq_5b_1_3a_0_5d_ : add_uu<2>(i_3_5c_evenq_5b_1_3a_0_5d_, value<1>{0x1u})) : i_3_5c_evenq_5b_1_3a_0_5d_) : p_evenq.curr));
	}
	// cells $procdff$6898 $procmux$6695 $procmux$6338 $procmux$2605 $procmux$2294 $shift$receiver.v:93$227 $shiftx$receiver.v:93$225
	if (posedge_p_clk) {
		p_evcancel.next = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_209__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_213__Y ? shift_us<4>(shiftx_uu<1>(i_7_5c_enabled_5b_3_3a_0_5d_, i_6_5c_qo_5b_0_5d__5b_1_3a_0_5d_), i_neg_24_receiver_2e_v_3a_93_24_226__Y) : value<4>{0u}) : value<4>{0u}) : p_evcancel.curr));
	}
	// cells $procdff$6897 $procmux$6698 $procmux$6518
	if (posedge_p_clk) {
		p_evexpire.next = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_3_5c_evexpire_5b_3_3a_0_5d_ : p_evexpire.curr));
	}
	// cells $procdff$6896 $procmux$6701
	if (posedge_p_clk) {
		p_evwu.next = (p_rst ? value<4>{0u} : i_2_5c_evwu_5b_3_3a_0_5d_);
	}
	// cells $procdff$6895 $procmux$6704 $procmux$6344 $procmux$2614 $procmux$1970
	if (posedge_p_clk) {
		p_failowner.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_209__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_213__Y ? p_failowner.curr : i_6_5c_qo_5b_0_5d__5b_1_3a_0_5d_) : p_failowner.curr) : p_failowner.curr));
	}
	// cells $procdff$6894 $procmux$6593 $procmux$6020 $procmux$6588 $logic_or$receiver.v:54$72 $logic_or$receiver.v:54$70 $logic_or$receiver.v:54$68 $logic_or$receiver.v:54$66 $logic_or$receiver.v:54$64 $logic_or$receiver.v:54$62 $logic_or$receiver.v:54$60 $logic_or$receiver.v:54$58 $logic_or$receiver.v:54$56 $logic_or$receiver.v:54$54 $logic_or$receiver.v:54$52 $logic_or$receiver.v:54$48 $lt$receiver.v:54$46 $gt$receiver.v:54$47 $logic_and$receiver.v:54$51 $ne$receiver.v:54$49 $ne$receiver.v:54$50 $lt$receiver.v:54$53 $gt$receiver.v:54$55 $eq$receiver.v:54$57 $eq$receiver.v:54$59 $gt$receiver.v:54$61 $ge$receiver.v:54$63 $ge$receiver.v:54$65 $ge$receiver.v:54$67 $ge$receiver.v:54$69 $ge$receiver.v:54$71
	if (posedge_p_clk) {
		p_fault.next = (p_rst ? value<31>{0u}.concat((logic_or<1>(logic_or<1>(logic_or<1>(logic_or<1>(logic_or<1>(logic_or<1>(logic_or<1>(logic_or<1>(logic_or<1>(logic_or<1>(logic_or<1>(logic_or<1>(lt_uu<1>(p_cfgp, value<2>{0x2u}), gt_uu<1>(p_cfgp, value<5>{0x11u})), logic_and<1>(ne_uu<1>(p_cfgr, value<3>{0x5u}), ne_uu<1>(p_cfgr, value<3>{0x7u}))), lt_uu<1>(p_cfgf, value<6>{0x28u})), gt_uu<1>(p_cfgf, value<10>{0x3b8u})), logic_not<1>(p_cfgk)), logic_not<1>(p_cfgperiod)), gt_uu<1>(p_cfgperiod, value<7>{0x44u})), ge_uu<1>(p_cfgphi, p_cfgperiod)), ge_uu<1>(p_cfgcp, p_cfgp)), ge_uu<1>(p_cfgrp, p_cfgr)), ge_uu<1>(p_cfgfp, p_cfgf)), ge_uu<1>(p_cfgpp, p_cfgperiod)) ? value<1>{0x1u} : value<1>{0u})).val() : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_13_5c_fault_5b_31_3a_0_5d_.slice<31,7>().concat(i_23_5c_fault_5b_31_3a_0_5d_.slice<6,0>()).val() : p_fault.curr));
	}
	// cells $procdff$6893 $procmux$6707 $procmux$6350 $procmux$2623 $procmux$1958
	if (posedge_p_clk) {
		p_failid.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_209__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_213__Y ? p_failid.curr : i_6_5c_qi_5b_0_5d__5b_31_3a_0_5d_) : p_failid.curr) : p_failid.curr));
	}
	// cells $procdff$6892 $procmux$6710 $procmux$6356 $procmux$2632 $procmux$1982
	if (posedge_p_clk) {
		p_failtick.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_209__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_213__Y ? p_failtick.curr : p_tick.curr) : p_failtick.curr) : p_failtick.curr));
	}
	// cells $procdff$6891 $procmux$6713 $procmux$6362
	if (posedge_p_clk) {
		p_failed.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_3_5c_failed_5b_0_3a_0_5d_ : p_failed.curr));
	}
	// cells $procdff$6890 $procmux$6716 $procmux$6146 $procmux$1849 $procmux$1448
	if (posedge_p_clk) {
		p_byteone.next = (p_rst ? value<8>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? p_byteone.curr : (i_logic__and_24_receiver_2e_v_3a_103_24_255__Y ? i_3_5c_bytezero_5b_7_3a_0_5d_ : p_byteone.curr)) : p_byteone.curr));
	}
	// cells $procdff$6889 $procmux$6719 $procmux$6368
	if (posedge_p_clk) {
		p_bytezero.next = (p_rst ? value<8>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_3_5c_bytezero_5b_7_3a_0_5d_ : p_bytezero.curr));
	}
	// cells $procdff$6888 $procmux$6722 $procmux$6152 $procmux$1858 $procmux$1460
	if (posedge_p_clk) {
		p_idone.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_3_5c_failed_5b_0_3a_0_5d_ ? p_idone.curr : (i_logic__and_24_receiver_2e_v_3a_103_24_255__Y ? i_3_5c_idzero_5b_31_3a_0_5d_ : p_idone.curr)) : p_idone.curr));
	}
	// cells $procdff$6887 $procmux$6725 $procmux$6374
	if (posedge_p_clk) {
		p_idzero.next = (p_rst ? value<32>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_3_5c_idzero_5b_31_3a_0_5d_ : p_idzero.curr));
	}
	// cells $procdff$6886 $procmux$6728 $procmux$6158
	if (posedge_p_clk) {
		p_ownerone.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_3_5c_ownerone_5b_1_3a_0_5d_ : p_ownerone.curr));
	}
	// cells $procdff$6885 $procmux$6731 $procmux$6380
	if (posedge_p_clk) {
		p_ownerzero.next = (p_rst ? value<2>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_3_5c_ownerzero_5b_1_3a_0_5d_ : p_ownerzero.curr));
	}
	// cells $procdff$6884 $procmux$6734 $procmux$6164
	if (posedge_p_clk) {
		p_rone.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_3_5c_rone_5b_0_3a_0_5d_ : p_rone.curr));
	}
	// cells $procdff$6883 $procmux$6737 $procmux$6170
	if (posedge_p_clk) {
		p_rzero.next = (p_rst ? value<1>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_5_5c_rzero_5b_0_3a_0_5d_ : p_rzero.curr));
	}
	// cells $procdff$6882 $procmux$6791 $procmux$6176
	if (posedge_p_clk) {
		p_outstanding.next = (p_rst ? value<16>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_7_5c_outstanding_5b_15_3a_0_5d_ : p_outstanding.curr));
	}
	// cells $procdff$6881 $procmux$6794 $procmux$6386
	if (posedge_p_clk) {
		p_qlen.next = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_7_5c_qlen_5b_3_3a_0_5d_ : p_qlen.curr));
	}
	// cells $procdff$6880 $procmux$6797
	if (posedge_p_clk) {
		p_bytes.next = (p_rst ? value<32>{0u} : i_2_5c_bytes_5b_31_3a_0_5d_);
	}
	// cells $procdff$6879 $procmux$6800 $procmux$6392 $procmux$2695 $procmux$2366 $or$receiver.v:93$244 $and$receiver.v:93$241 $not$receiver.v:93$240 $shift$receiver.v:93$239 $shift$receiver.v:93$243
	if (posedge_p_clk) {
		p_counts.next = (p_rst ? value<64>{0u,0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_209__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_213__Y ? or_uu<64>(and_uu<64>(i_7_5c_counts_5b_63_3a_0_5d_, not_u<64>(shift_us<64>(value<16>{0xffffu}, i_neg_24_receiver_2e_v_3a_93_24_238__Y))), shift_us<64>(value<1>{0u}, i_neg_24_receiver_2e_v_3a_93_24_238__Y)) : i_7_5c_counts_5b_63_3a_0_5d_) : i_7_5c_counts_5b_63_3a_0_5d_) : p_counts.curr));
	}
	// cells $procdff$6878 $procmux$6803 $procmux$6398 $procmux$2704 $procmux$2378
	if (posedge_p_clk) {
		p_enabled.next = (p_rst ? value<4>{0u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (i_logic__and_24_receiver_2e_v_3a_87_24_209__Y ? (i_shiftx_24_receiver_2e_v_3a_89_24_213__Y ? i_auto_24_wreduce_2e_cc_3a_513_3a_run_24_7161.slice<3,0>().val() : i_7_5c_enabled_5b_3_3a_0_5d_) : i_7_5c_enabled_5b_3_3a_0_5d_) : p_enabled.curr));
	}
	// cells $procdff$6877 $procmux$6806 $procmux$6524
	if (posedge_p_clk) {
		p_valid.next = (p_rst ? value<4>{0xfu} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_3_5c_valid_5b_3_3a_0_5d_ : p_valid.curr));
	}
	// cells $procdff$6876 $procmux$6809 $procmux$5990 $procmux$6573 $eq$receiver.v:127$343
	if (posedge_p_clk) {
		p_pp.next = (p_rst ? p_cfgpp : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (eq_uu<1>(i_add_24_receiver_2e_v_3a_127_24_342__Y, value<1>{0u}.concat(p_cfgperiod).val()) ? value<16>{0u} : i_add_24_receiver_2e_v_3a_127_24_342__Y.slice<15,0>().val()) : p_pp.curr));
	}
	// cells $procdff$6875 $procmux$6812 $procmux$5996 $procmux$353 $eq$receiver.v:126$340
	if (posedge_p_clk) {
		p_fp.next = (p_rst ? p_cfgfp : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (eq_uu<1>(i_add_24_receiver_2e_v_3a_126_24_339__Y, value<1>{0u}.concat(p_cfgf).val()) ? value<16>{0u} : i_add_24_receiver_2e_v_3a_126_24_339__Y.slice<15,0>().val()) : p_fp.curr));
	}
	// cells $procdff$6874 $procmux$6815 $procmux$6002 $procmux$362 $eq$receiver.v:125$337
	if (posedge_p_clk) {
		p_rp.next = (p_rst ? p_cfgrp : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (eq_uu<1>(i_add_24_receiver_2e_v_3a_125_24_336__Y, value<1>{0u}.concat(p_cfgr).val()) ? value<16>{0u} : i_add_24_receiver_2e_v_3a_125_24_336__Y.slice<15,0>().val()) : p_rp.curr));
	}
	// cells $procdff$6873 $procmux$6818 $procmux$6008 $procmux$371 $eq$receiver.v:124$334
	if (posedge_p_clk) {
		p_cp.next = (p_rst ? p_cfgcp : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? (eq_uu<1>(i_add_24_receiver_2e_v_3a_124_24_333__Y, value<1>{0u}.concat(p_cfgp).val()) ? value<16>{0u} : i_add_24_receiver_2e_v_3a_124_24_333__Y.slice<15,0>().val()) : p_cp.curr));
	}
	// cells $procdff$6872 $procmux$6821 $procmux$6470
	if (posedge_p_clk) {
		p_nextid.next = (p_rst ? value<32>{0x1u} : (i_logic__and_24_receiver_2e_v_3a_55_24_75__Y ? i_5_5c_nextid_5b_31_3a_0_5d_ : p_nextid.curr));
	}
	// cells $procdff$6871 $procmux$6824 $procmux$6014 $add$receiver.v:123$332
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
		items->add(path, "procmux$5696_Y", "", i_procmux_24_5696__Y, 0, debug_item::GENERATED|debug_item::DRIVEN_COMB);
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
