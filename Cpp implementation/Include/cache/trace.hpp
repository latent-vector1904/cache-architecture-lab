#pragma once

#include <cstddef>
#include <cstdint>
#include <filesystem>
#include <vector>

#include "cache.hpp"

namespace cache_sim {

struct MemoryRequest {
    std::uint64_t address = 0;
    std::size_t size_bytes = 1;
    AccessType type = AccessType::Read;
};

class Trace {
public:
    void load_from_file(
        const std::filesystem::path& path
    );

    void add_request(const MemoryRequest& request);

    [[nodiscard]]
    const std::vector<MemoryRequest>& requests() const;

    [[nodiscard]]
    std::size_t size() const;

private:
    std::vector<MemoryRequest> requests_;
};

} // namespace cache_sim