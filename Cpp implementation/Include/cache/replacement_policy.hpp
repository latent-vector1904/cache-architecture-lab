#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>

#include "cache_line.hpp"

namespace cache_sim {

class ReplacementPolicy {
public:
    virtual ~ReplacementPolicy() = default;

    virtual void on_access(
        std::size_t way,
        std::uint64_t cycle
    ) = 0;

    [[nodiscard]]
    virtual std::size_t select_victim(
        const std::vector<CacheLine>& lines
    ) const = 0;

    virtual void on_insert(std::size_t way) = 0;

    virtual void reset() = 0;
};

class LRUReplacement final : public ReplacementPolicy {
public:
    explicit LRUReplacement(std::size_t associativity);

    void on_access(
        std::size_t way,
        std::uint64_t cycle
    ) override;

    [[nodiscard]]
    std::size_t select_victim(
        const std::vector<CacheLine>& lines
    ) const override;

    void on_insert(std::size_t way) override;

    void reset() override;

private:
    std::vector<std::uint64_t> last_used_;
};

} // namespace cache_sim