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

#ifndef FUBUKI_FUYU_INFORMATION_SHADER_MODULE_HPP
#define FUBUKI_FUYU_INFORMATION_SHADER_MODULE_HPP

#include <algorithm>
#include <cstdint>
#include <functional>
#include <optional>
#include <span>
#include <string>

#include <core/structure_type.hpp>

#include "fuyu/information/callbacks.hpp"

namespace fubuki::fuyu::information
{

/// Information required to create an instance of a fuyu::shader_module.
/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/VkShaderModuleCreateInfo.html
struct shader_module
{
    using underlying_type = VkShaderModuleCreateInfo;

    /// Additional information required upon construction, but not kept for the lifetime of the object.
    struct complements
    {
        std::span<const std::uint32_t> spirv; ///< SPIR-V source code to provide to the driver.

        [[nodiscard]] friend constexpr bool operator==(const complements& a, const complements& b) noexcept
        {
            return std::ranges::equal(a.spirv, b.spirv);
        }

        [[nodiscard]] friend constexpr bool operator!=(const complements& a, const complements& b) noexcept { return not(a == b); }
    };

    std::optional<creation_callback> callbacks = {}; ///< (optional) Callbacks.
    std::optional<std::string>       name      = {}; ///< (optional) Name passed to debug markers.

    [[nodiscard]] friend constexpr bool operator==(const shader_module& a, const shader_module& b) noexcept = default;
    [[nodiscard]] friend constexpr bool operator!=(const shader_module& a, const shader_module& b) noexcept = default;

    [[nodiscard]] friend constexpr underlying_type to_underlying(std::reference_wrapper<const shader_module> /*disambiguation*/,
                                                                 complements c) noexcept
    {
        return {
            .sType    = structure_type_v<VkShaderModuleCreateInfo>,
            .pNext    = nullptr,
            .flags    = 0,
            .codeSize = c.spirv.size_bytes(),
            .pCode    = c.spirv.data(),
        };
    }
};

} // namespace fubuki::fuyu::information

#endif // FUBUKI_FUYU_INFORMATION_SHADER_MODULE_HPP
