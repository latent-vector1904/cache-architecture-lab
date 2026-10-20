#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>

#include "cache_config.hpp"
#include "cache_line.hpp"
#include "cache_set.hpp"
#include "cache_stats.hpp"
#include "memory.hpp"

namespace cache_sim {

enum class AccessType {
    Read,
    Write
};

struct AccessResult {
    bool hit = false;

    std::uint64_t latency_cycles = 0;
    std::uint64_t completion_cycle = 0;
};

class Cache {
public:
    Cache(
        CacheConfig config,
        Memory& memory
    );

    [[nodiscard]]
    AccessResult access(
        std::uint64_t address,
        std::size_t size_bytes,
        AccessType type,
        std::uint64_t start_cycle
    );

    [[nodiscard]]
    const CacheStats& stats() const;

    [[nodiscard]]
    const CacheConfig& config() const;

    void flush();

    void reset();

private:
    CacheConfig config_;
    Memory& memory_;

    std::vector<CacheSet> sets_;
    CacheStats stats_;

    [[nodiscard]]
    std::uint64_t extract_tag(std::uint64_t address) const;

    [[nodiscard]]
    std::size_t extract_set_index(std::uint64_t address) const;

    [[nodiscard]]
    std::uint64_t align_to_line(std::uint64_t address) const;
};

} // namespace cache_sim