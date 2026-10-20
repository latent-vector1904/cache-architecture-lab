#pragma once

#include <cstddef>
#include <cstdint>

namespace cache_sim {

struct CacheConfig {
    std::size_t capacity_bytes = 4096;
    std::size_t line_size_bytes = 64;
    std::size_t associativity = 2;

    std::uint64_t hit_latency_cycles = 1;
    std::uint64_t memory_latency_cycles = 100;

    void validate() const;

    [[nodiscard]]
    std::size_t number_of_sets() const;

    [[nodiscard]]
    std::size_t offset_bits() const;

    [[nodiscard]]
    std::size_t index_bits() const;

    [[nodiscard]]
    std::size_t tag_bits() const;
};

} // namespace cache_sim