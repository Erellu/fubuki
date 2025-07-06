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

#ifndef FUBUKI_FUYU_INFORMATION_DESCRIPTOR_POOL_HPP
#define FUBUKI_FUYU_INFORMATION_DESCRIPTOR_POOL_HPP

#include <functional>

#include <core/collect.hpp>
#include <core/enum/descriptor_type.hpp>
#include <core/structure_type.hpp>
#include <core/vulkan.hpp>

#include "fuyu/detail/descriptor_pool_size.hpp"
#include "fuyu/information/callbacks.hpp"

namespace fubuki::fuyu
{

namespace descriptor_type
{

using sampler                = detail::descriptor_type::sampler;
using combined_image_sampler = detail::descriptor_type::combined_image_sampler;
using sampled_image          = detail::descriptor_type::sampled_image;
using storage_image          = detail::descriptor_type::storage_image;
using uniform_texel_buffer   = detail::descriptor_type::uniform_texel_buffer;
using storage_texel_buffer   = detail::descriptor_type::storage_texel_buffer;
using uniform_buffer         = detail::descriptor_type::uniform_buffer;
using ubo                    = uniform_buffer;
using storage_buffer         = detail::descriptor_type::storage_buffer;
using ssbo                   = storage_buffer;
using dynamic_uniform_buffer = detail::descriptor_type::dynamic_uniform_buffer;
using dynamic_ubo            = dynamic_uniform_buffer;
using dynamic_storage_buffer = detail::descriptor_type::dynamic_storage_buffer;
using dynamic_ssbo           = dynamic_storage_buffer;
using input_attachment       = detail::descriptor_type::input_attachment;

#if defined(VK_VERSION_1_3)
using inline_uniform_block = detail::descriptor_type::inline_uniform_block;
#endif // defined(VK_VERSION_1_3)

#if defined(VK_KHR_acceleration_structure)
using acceleration_structure_khr = detail::descriptor_type::acceleration_structure_khr;
#endif // defined(VK_KHR_acceleration_structure)

#if defined(VK_NV_ray_tracing)
using acceleration_structure_nv = detail::descriptor_type::acceleration_structure_nv;
#endif // defined(VK_NV_ray_tracing)

#if defined(VK_QCOM_image_processing)
using sample_weight_image_qcom = detail::descriptor_type::sample_weight_image_qcom;
#endif // defined(VK_QCOM_image_processing)

#if defined(VK_QCOM_image_processing)
using block_match_image_qcom = detail::descriptor_type::block_match_image_qcom;
#endif // defined(VK_QCOM_image_processing)

#if defined(VK_EXT_mutable_descriptor_type)
using mutable_ext = detail::descriptor_type::mutable_ext;
#endif // defined(VK_EXT_mutable_descriptor_type)

inline constexpr auto alternatives = detail::descriptor_type::count;

} // namespace descriptor_type

/// @copydoc detail::descriptor_pool_size
using descriptor_pool_size = detail::descriptor_pool_size::type;

namespace information
{
/// Information required to create an instance of a fuyu::descriptor_pool.
struct descriptor_pool
{
    using underlying_type = VkDescriptorPoolCreateInfo;

    VkDescriptorPoolCreateFlags flags   = {}; ///< Flags for this pool.
    std::uint32_t               max_set = {}; ///< The maximum number of sets that can be allocated from this pool.
    descriptor_pool_size        size    = {}; ///< Number of descriptor this pool contains for each type.

    std::optional<creation_callback> callbacks = {}; ///< Callbacks.
    std::optional<std::string>       name      = {}; ///< (optional) Name passed to debug markers.

    [[nodiscard]] friend constexpr bool operator==(const descriptor_pool& a, const descriptor_pool& b) noexcept = default;
    [[nodiscard]] friend constexpr bool operator!=(const descriptor_pool& a, const descriptor_pool& b) noexcept = default;

    [[nodiscard]] friend constexpr underlying_type to_underlying(std::reference_wrapper<const descriptor_pool>                       cref1,
                                                                 std::reference_wrapper<const descriptor_pool_size::underlying_type> cref2)
    {
        // Avoids having to introduce deleted overloads for temporaries
        const auto& s1 = cref1.get();
        const auto& s2 = cref2.get();

        return {
            .sType         = structure_type_v<underlying_type>,
            .pNext         = {},
            .flags         = s1.flags,
            .maxSets       = s1.max_set,
            .poolSizeCount = vk_size(s2),
            .pPoolSizes    = s2.data(),
        };
    }
};

} // namespace information

} // namespace fubuki::fuyu

#endif // FUBUKI_FUYU_INFORMATION_DESCRIPTOR_POOL_HPP
