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

#ifndef FUBUKI_FUYU_INFORMATION_PIPELINE_LAYOUT_HPP
#define FUBUKI_FUYU_INFORMATION_PIPELINE_LAYOUT_HPP

#include <functional>
#include <optional>
#include <string>

#include <core/collect.hpp>
#include <core/compare/push_constant_range.hpp>
#include <core/handle.hpp>
#include <core/small_vector.hpp>
#include <core/structure_type.hpp>
#include <core/vulkan.hpp>

#include "fuyu/information/callbacks.hpp"

namespace fubuki::fuyu::information
{

/// Information required to construct an instance of fuyu::pipeline_layout.
/// @see https://registry.khronos.org/VulkanSC/specs/1.0-extensions/man/html/VkPipelineLayoutCreateInfo.html
struct pipeline_layout
{
    using underlying_type = VkPipelineLayoutCreateInfo;

    VkPipelineLayoutCreateFlags                flags          = {}; ///< A bitmask of VkPipelineLayoutCreateFlagBits specifying options.
    small_vector<descriptor_set_layout_handle> set_layouts    = {}; ///< The descriptor set layouts accessible by this pipeline layout.
    small_vector<VkPushConstantRange>          push_constants = {}; ///< The push constants accessible by this pipeline layout.

    std::optional<creation_callback> callbacks = {}; ///< (optional) Callbacks for allocation calls.
    std::optional<std::string>       name      = {}; ///< (optional) Name for debug markers.

    [[nodiscard]] friend constexpr bool operator==(const pipeline_layout& a, const pipeline_layout& b) noexcept
    {
        constexpr auto compare = [](const VkPushConstantRange& x, const VkPushConstantRange& y) constexpr noexcept
        {
            using fubuki::operator==;
            return x == y;
        };

        return (a.flags == b.flags) and (a.set_layouts == b.set_layouts) and std::ranges::equal(a.push_constants, b.push_constants, compare)
            and (a.callbacks == b.callbacks) and (a.name == b.name);
    }

    [[nodiscard]] friend constexpr bool operator!=(const pipeline_layout& a, const pipeline_layout& b) noexcept { return not(a == b); }

    [[nodiscard]] friend constexpr underlying_type to_underlying(std::reference_wrapper<const pipeline_layout> cref,
                                                                 std::span<const VkDescriptorSetLayout>        vk_layouts) noexcept
    {
        // Avoids having to introduce deleted overloads for temporaries
        const auto& s = cref.get();

        return {
            .sType                  = structure_type_v<underlying_type>,
            .pNext                  = {},
            .flags                  = s.flags,
            .setLayoutCount         = vk_size(vk_layouts),
            .pSetLayouts            = vk_layouts.data(),
            .pushConstantRangeCount = vk_size(s.push_constants),
            .pPushConstantRanges    = s.push_constants.data(),
        };
    }
};

} // namespace fubuki::fuyu::information

#endif // FUBUKI_FUYU_INFORMATION_PIPELINE_LAYOUT_HPP
