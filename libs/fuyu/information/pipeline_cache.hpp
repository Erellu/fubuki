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

#ifndef FUBUKI_FUYU_INFORMATION_PIPELINE_CACHE_HPP
#define FUBUKI_FUYU_INFORMATION_PIPELINE_CACHE_HPP

#include <algorithm>
#include <cstddef>
#include <functional>
#include <optional>
#include <span>
#include <string>

#include <core/structure_type.hpp>
#include <core/vulkan.hpp>

#include "fuyu/information/callbacks.hpp"

namespace fubuki::fuyu::information
{

/// Information required to construct an instance of fuyu::pipeline_cache.
/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/VkPipelineCacheCreateInfo.html
struct pipeline_cache
{
    using underlying_type = VkPipelineCacheCreateInfo;

    /// Information required upon construction but not kept for the lifetime of the object.
    struct complements
    {
        std::span<const std::byte> initial_data = {};

        [[nodiscard]] friend constexpr bool operator==(const complements& a, const complements& b) noexcept
        {
            return std::ranges::equal(a.initial_data, b.initial_data);
        }

        [[nodiscard]] friend constexpr bool operator!=(const complements& a, const complements& b) noexcept { return not(a == b); }
    };

    VkPipelineCacheCreateFlags flags = {}; ///< A bitmask of VkPipelineCacheCreateFlagBits specifying the behaviour of the pipeline cache.

    std::optional<creation_callback> callbacks = {}; ///< (optional) Callbacks.
    std::optional<std::string>       name      = {}; ///< (optional) Name passed to debug markers.

    [[nodiscard]] friend constexpr bool operator==(const pipeline_cache& a, const pipeline_cache& b) noexcept = default;
    [[nodiscard]] friend constexpr bool operator!=(const pipeline_cache& a, const pipeline_cache& b) noexcept = default;

    [[nodiscard]] friend constexpr underlying_type to_underlying(std::reference_wrapper<const pipeline_cache> cref,
                                                                 std::optional<complements>                   c) noexcept
    {
        // Avoids having to introduce deleted overloads for temporaries
        const auto& s = cref.get();

        return {
            .sType           = structure_type_v<VkPipelineCacheCreateInfo>,
            .pNext           = {},
            .flags           = s.flags,
            .initialDataSize = c.has_value() ? c->initial_data.size_bytes() : 0,
            .pInitialData    = c.has_value() ? c->initial_data.data() : nullptr,
        };
    }
};

} // namespace fubuki::fuyu::information

#endif // FUBUKI_FUYU_INFORMATION_PIPELINE_CACHE_HPP
