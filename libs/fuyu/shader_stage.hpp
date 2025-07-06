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

#ifndef FUBUKI_FUYU_SHADER_STAGE_HPP
#define FUBUKI_FUYU_SHADER_STAGE_HPP

#include <algorithm>
#include <cstdint>
#include <span>
#include <variant>

#include <core/handle.hpp>
#include <core/small_vector.hpp>

namespace fubuki::fuyu
{

/**
 * Description of a shader stage, used in a fuyu::graphics_pipeline, or a fuyu::compute_pipeline.
 */
struct shader_stage
{
    /// Indicates a shader module has to be compiled from the provided code when constructing the pipeline.
    struct spirv
    {
        std::span<const std::uint32_t> code = {}; ///< The SPIR-V code to feed to the shader module.

        [[nodiscard]] friend constexpr bool operator==(const spirv& a, const spirv& b) noexcept { return std::ranges::equal(a.code, b.code); }
        [[nodiscard]] friend constexpr bool operator!=(const spirv& a, const spirv& b) noexcept { return not(a == b); }
        [[nodiscard]] friend constexpr auto operator<=>(const spirv& a, const spirv& b) noexcept
        {
            return std::lexicographical_compare_three_way(a.code.begin(), a.code.end(), b.code.begin(), b.code.end());
        }
    };

    /// Describes specialisation information for unidentified shader stages.
    /// @see https://registry.khronos.org/vulkan/specs/latest/man/html/VkSpecializationInfo.html
    struct specialisation
    {
        small_vector<VkSpecializationMapEntry> map_entries = {}; ///< A description of the contents of the byte buffer, data.
        std::span<const std::byte>             data        = {}; ///< A byte buffer, which contents are described by map_entries.
    };

    using provenance = std::variant<shader_module_handle, spirv>;

    /// A bitmask of VkPipelineShaderStageCreateFlagBits specifying how the pipeline shader stage will be generated.
    VkPipelineShaderStageCreateFlags flags = {};

    /// The source of the shader stage, either as a pre-created module or directly as SPIR-V source-code.
    provenance shader = {};

    /// Name of the entry point of the shader. Must be null-terminated. Defaults to "main".
    std::optional<std::string> entry_point = {};

    [[nodiscard]] friend constexpr bool operator==(const shader_stage&, const shader_stage&) noexcept = default;
    [[nodiscard]] friend constexpr bool operator!=(const shader_stage&, const shader_stage&) noexcept = default;
};

} // namespace fubuki::fuyu

#endif // FUBUKI_FUYU_SHADER_STAGE_HPP
