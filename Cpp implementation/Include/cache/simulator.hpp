#pragma once

#include <cstdint>

#include "cache.hpp"
#include "trace.hpp"

namespace cache_sim {

struct SimulationResult {
    std::uint64_t total_cycles = 0;
    CacheStats stats;
};

class Simulator {
public:
    explicit Simulator(Cache& cache);

    [[nodiscard]]
    SimulationResult run(const Trace& trace);

    [[nodiscard]]
    std::uint64_t current_cycle() const;

    void reset();

private:
    Cache& cache_;
    std::uint64_t current_cycle_ = 0;
};

} // namespace cache_sim