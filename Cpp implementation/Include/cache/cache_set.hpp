#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>

#include "cache_line.hpp"
#include "replacement_policy.hpp"

namespace cache_sim {

class CacheSet {
public:
    explicit CacheSet(std::size_t associativity);

    [[nodiscard]]
    std::size_t find_way(std::uint64_t tag) const;

    [[nodiscard]]
    std::size_t find_invalid_way() const;

    [[nodiscard]]
    std::size_t select_victim() const;

    CacheLine& line_at(std::size_t way);

    [[nodiscard]]
    const CacheLine& line_at(std::size_t way) const;

    void record_access(
        std::size_t way,
        std::uint64_t cycle
    );

    void record_insertion(std::size_t way);

    [[nodiscard]]
    std::size_t associativity() const;

private:
    std::vector<CacheLine> lines_;
    LRUReplacement replacement_;
};

} // namespace cache_sim