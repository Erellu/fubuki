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

/*
 * WARNING : This file is GENERATED.
 * Changes performed manually will be undone next generation.
 */

#ifndef FUBUKI_CORE_ENUM_DESCRIPTOR_TYPE_HPP
#define FUBUKI_CORE_ENUM_DESCRIPTOR_TYPE_HPP

#include <string>
#include <string_view>

#include "core/vulkan.hpp"

namespace fubuki
{

// clang-format off
#if defined(VK_VERSION_1_0)

/// Returns a std::string_view corresponding to a VkDescriptorType.
[[nodiscard]] inline constexpr std::string_view to_string_view(const VkDescriptorType e) noexcept
{
    #if defined(FUBUKI_MAKE_CASE)
        #error Internal error. Should not be defined.
    #endif

    #define FUBUKI_MAKE_CASE(enum_value) \
        case enum_value: return #enum_value

    switch(e)
    {

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_DESCRIPTOR_TYPE_SAMPLER);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_DESCRIPTOR_TYPE_STORAGE_IMAGE);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_DESCRIPTOR_TYPE_STORAGE_BUFFER);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_0) 
        FUBUKI_MAKE_CASE(VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT);
#endif // #if defined (VK_VERSION_1_0)

#if defined(VK_VERSION_1_3) 
        FUBUKI_MAKE_CASE(VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK);
#endif // #if defined (VK_VERSION_1_3)

#if defined(VK_EXT_inline_uniform_block) && !(defined(VK_VERSION_1_3))
        FUBUKI_MAKE_CASE(VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK_EXT);
#endif // #if defined (VK_EXT_inline_uniform_block)

#if defined(VK_KHR_acceleration_structure) 
        FUBUKI_MAKE_CASE(VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR);
#endif // #if defined (VK_KHR_acceleration_structure)

#if defined(VK_NV_ray_tracing) 
        FUBUKI_MAKE_CASE(VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_NV);
#endif // #if defined (VK_NV_ray_tracing)

#if defined(VK_VALVE_mutable_descriptor_type) && !(defined(VK_EXT_mutable_descriptor_type))
        FUBUKI_MAKE_CASE(VK_DESCRIPTOR_TYPE_MUTABLE_VALVE);
#endif // #if defined (VK_VALVE_mutable_descriptor_type)

#if defined(VK_QCOM_image_processing) 
        FUBUKI_MAKE_CASE(VK_DESCRIPTOR_TYPE_SAMPLE_WEIGHT_IMAGE_QCOM);
#endif // #if defined (VK_QCOM_image_processing)

#if defined(VK_QCOM_image_processing) 
        FUBUKI_MAKE_CASE(VK_DESCRIPTOR_TYPE_BLOCK_MATCH_IMAGE_QCOM);
#endif // #if defined (VK_QCOM_image_processing)

#if defined(VK_EXT_mutable_descriptor_type) 
        FUBUKI_MAKE_CASE(VK_DESCRIPTOR_TYPE_MUTABLE_EXT);
#endif // #if defined (VK_EXT_mutable_descriptor_type)

#if defined(VK_NV_partitioned_acceleration_structure) 
        FUBUKI_MAKE_CASE(VK_DESCRIPTOR_TYPE_PARTITIONED_ACCELERATION_STRUCTURE_NV);
#endif // #if defined (VK_NV_partitioned_acceleration_structure)

        FUBUKI_MAKE_CASE(VK_DESCRIPTOR_TYPE_MAX_ENUM);

        default: return "";
    }

    #undef FUBUKI_MAKE_CASE
}

/// Returns a std::string corresponding to a VkDescriptorType.
[[nodiscard]] inline auto to_string(VkDescriptorType e) { return std::string{to_string_view(e)}; }

//------------------------------------------------------------------------------

#endif // #if defined(VK_VERSION_1_0)
// clang-format on

} // namespace fubuki

#endif // FUBUKI_CORE_ENUM_DESCRIPTOR_TYPE_HPP
