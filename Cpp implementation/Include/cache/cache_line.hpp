#pragma once

#include <cstdint>
#include <vector>

namespace cache_sim {

struct CacheLine {
    std::uint64_t tag = 0;

    bool valid = false;
    bool dirty = false;

    std::vector<std::uint8_t> data;
};

} // namespace cache_sim