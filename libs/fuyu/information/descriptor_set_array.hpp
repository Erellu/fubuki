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

#ifndef FUBUKI_FUYU_INFORMATION_DESCRIPTOR_SET_ARRAY_HPP
#define FUBUKI_FUYU_INFORMATION_DESCRIPTOR_SET_ARRAY_HPP

#include <functional>

#include <core/collect.hpp>
#include <core/handle.hpp>
#include <core/small_vector.hpp>
#include <core/structure_type.hpp>

namespace fubuki::fuyu::information
{

/**
 * Information required to construct an instance of fuyu::descriptor_set_array.
 */
struct descriptor_set_array
{
    using underlying_type = VkDescriptorSetAllocateInfo;

    small_vector<descriptor_set_layout_handle> layouts = {}; ///< Layouts from which the sets will be created.

    [[nodiscard]] friend constexpr bool operator==(const descriptor_set_array& a, const descriptor_set_array& b) noexcept  = default;
    [[nodiscard]] friend constexpr bool operator!=(const descriptor_set_array& a, const descriptor_set_array& b) noexcept  = default;
    [[nodiscard]] friend constexpr auto operator<=>(const descriptor_set_array& a, const descriptor_set_array& b) noexcept = default;

    [[nodiscard]] friend constexpr underlying_type to_underlying(std::reference_wrapper<const descriptor_set_array> /*disambiguation*/,
                                                                 std::span<const VkDescriptorSetLayout> handles,
                                                                 descriptor_pool_handle                 parent) noexcept
    {
        return {
            .sType              = structure_type_v<underlying_type>,
            .pNext              = {},
            .descriptorPool     = parent.vk,
            .descriptorSetCount = vk_size(handles),
            .pSetLayouts        = handles.data(),
        };
    }
};

} // namespace fubuki::fuyu::information

#endif // FUBUKI_FUYU_INFORMATION_DESCRIPTOR_SET_ARRAY_HPP
