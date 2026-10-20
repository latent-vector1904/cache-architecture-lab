#pragma once

#include <cstdint>

namespace cache_sim {

struct CacheStats {
    std::uint64_t total_accesses = 0;
    std::uint64_t hits = 0;
    std::uint64_t misses = 0;

    std::uint64_t reads = 0;
    std::uint64_t writes = 0;

    std::uint64_t writebacks = 0;
    std::uint64_t memory_reads = 0;
    std::uint64_t memory_writes = 0;

    std::uint64_t total_latency_cycles = 0;

    [[nodiscard]]
    double hit_rate() const;

    [[nodiscard]]
    double miss_rate() const;

    [[nodiscard]]
    double average_latency_cycles() const;

    void reset();
};

} // namespace cache_sim