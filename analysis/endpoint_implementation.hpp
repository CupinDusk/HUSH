// Constructed logical one-line endpoint; not the historical native HUSH cache.
// A two-register response pipeline, dedicated WU/output lanes and one timer.
// This code contains no computed response deadline or service-to-response formula.
#pragma once
#include <cassert>
#include <cstdint>
#include <optional>

struct EndpointConfig {
    unsigned cache_period, load, expiry_period, expiry_phase;
};
struct EndpointRegister {
    bool occupied=false;
    uint64_t id=0;
    uint8_t value=0;
};
struct Endpoint {
    EndpointConfig config;
    bool valid=true, enabled=false;
    unsigned count=0;
    uint8_t value=0;
    EndpointRegister register0, register1;

    explicit Endpoint(EndpointConfig c, bool initially_valid=true)
        :config(c),valid(initially_valid) {
        assert(c.cache_period && c.load && c.expiry_period);
        assert(c.expiry_phase<c.expiry_period);
    }
    // Revoke -> valid-only WU -> decrement. Return whether this tick expires.
    bool begin_tick(uint64_t tick, bool wu, uint8_t update=0, bool revoke=false) {
        if(revoke){valid=false;enabled=false;count=0;}
        if(wu && valid){value=update;enabled=true;count=config.load;}
        if(enabled && tick%config.expiry_period==config.expiry_phase){
            assert(count>0);
            if(--count==0){valid=false;enabled=false;return true;}
        }
        return false;
    }
    // Immediate tag/read decision, cancellation, and response snapshot/latch.
    bool accept_read(uint64_t id, uint64_t tag=64) {
        if(!valid || tag!=64)return false;
        // The admitted one-outstanding source must satisfy this capacity guard.
        assert(!register0.occupied && !register1.occupied && id);
        enabled=false;count=0;
        register0={true,id,value};
        return true;
    }
    // Dedicated response sink; output old register1, then shift register0.
    std::optional<EndpointRegister> finish_tick(uint64_t tick) {
        if(tick%config.cache_period)return std::nullopt;
        std::optional<EndpointRegister> output;
        if(register1.occupied)output=register1;
        register1=register0;register0={};
        return output;
    }
};
