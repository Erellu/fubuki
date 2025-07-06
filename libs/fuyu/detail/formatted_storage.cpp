/*
 * BSD 2-Clause License
 *
 * Copyright (c) 2025, Erwan DUHAMEL
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "fuyu/detail/formatted_storage.hpp"

#include <core/format.hpp>

// NOTE: ideally, these functions should be inlined in a header. There aren't for the following reasons:
// - It longers compilation times by a non-negligible amount, especially with MinGW-gcc
// - Hidding it in a source file allows to specify -O2 on this target only , which circumvents a "string table overflow at offset xxx"
// when compiling with MinGW. Otherwise, everyone would need to specify this flag just for these functions.
// (Though this obviously doesn't help when similar logic is implemented by the user, of course)

namespace fubuki::fuyu::detail
{

[[nodiscard]]
any_storage storage_for(const VkFormat f, std::size_t size) noexcept(false)
{
    const auto visitor = [f, size](const auto& element) noexcept(false) -> any_storage
    {
        using element_type = std::decay_t<decltype(element)>;

        if constexpr(std::is_same_v<element_type, std::span<const std::byte>>)
        {
            return std::vector<std::byte>(size * description(f).block_size);
        }
        else
        {
            return any_storage{std::vector<element_type>(size)};
        }
    };

    return std::visit(visitor, storage_element_for(f));
}

[[nodiscard]]
any_storage storage_for(const VkFormat f, std::size_t size, any_storage_element initial) noexcept
{
    const auto visit_storage_element = [f, size, &initial](const auto& element) noexcept -> any_storage
    {
        using storage_element_type = std::decay_t<decltype(element)>;

        const auto visit_initial_value = [element_byte_size = description(f).block_size, size](const auto& initial_value) noexcept -> any_storage
        {
            using initial_value_type = std::decay_t<decltype(initial_value)>;

            if constexpr(std::is_same_v<storage_element_type, std::span<const std::byte>>)
            {
                std::vector<std::byte> result(size * element_byte_size);

                std::span<const std::byte> bytes_to_write = {};

                // Copy the bytes manually
                if constexpr(std::is_same_v<initial_value_type, std::span<const std::byte>>)
                {
                    bytes_to_write = initial_value;
                }
                else
                {
                    auto span = std::span<const initial_value_type, 1>{std::addressof(initial_value), 1};

                    bytes_to_write = std::as_bytes(span);
                }
// Clang isn't able to infer it's safe in this context
#if defined(__clang__)
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
#endif
                // Only copy relevant parts for padded formats
                const std::size_t valid_byte_range = std::min(bytes_to_write.size(), element_byte_size);

                for(std::size_t i = 0; i < size; ++i)
                {
                    const std::size_t byte_offset = i * element_byte_size;

                    std::memcpy(result.data() + byte_offset, bytes_to_write.data(), valid_byte_range);
                }
#if defined(__clang__)
    #pragma clang diagnostic pop
#endif

                return result;
            }
            else
            {
                constexpr bool same = std::is_same_v<initial_value_type, storage_element_type>;
                fubuki_assert(same, "Invalid initial value. Cannot initialise storage in this format with this type.");

                // Must be guarded for all instantiations
                if constexpr(same)
                {
                    return any_storage{std::vector<storage_element_type>(size, initial_value)};
                }
                else
                {
                    return any_storage{}; // Silence warnings
                }
            }
        };

        return std::visit(visit_initial_value, initial);
    };

    return std::visit(visit_storage_element, storage_element_for(f));
}

} // namespace fubuki::fuyu::detail
