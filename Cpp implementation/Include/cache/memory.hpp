#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>

namespace cache_sim {

class Memory {
public:
    explicit Memory(std::size_t size_bytes);

    [[nodiscard]]
    std::uint8_t read_byte(std::uint64_t address) const;

    void write_byte(
        std::uint64_t address,
        std::uint8_t value
    );

    void read_block(
        std::uint64_t block_address,
        std::vector<std::uint8_t>& destination
    ) const;

    void write_block(
        std::uint64_t block_address,
        const std::vector<std::uint8_t>& source
    );

    [[nodiscard]]
    std::size_t size_bytes() const;

private:
    std::vector<std::uint8_t> data_;
};

} // namespace cache_sim