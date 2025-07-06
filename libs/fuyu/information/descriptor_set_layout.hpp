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

#ifndef FUBUKI_FUYU_INFORMATION_DESCRIPTOR_SET_LAYOUT_HPP
#define FUBUKI_FUYU_INFORMATION_DESCRIPTOR_SET_LAYOUT_HPP

#include <functional>
#include <optional>

#include <core/collect.hpp>
#include <core/compare/descriptor_set_layout_binding.hpp>
#include <core/handle.hpp>
#include <core/small_vector.hpp>
#include <core/structure_type.hpp>
#include <core/vulkan.hpp>

#include "fuyu/information/callbacks.hpp"

namespace fubuki::fuyu
{

namespace detail::descriptor_binding
{

template<VkDescriptorType t>
struct type
{
    using underlying_type = VkDescriptorSetLayoutBinding;

    static constexpr auto descriptor = t;

    std::uint32_t      binding     = 0;
    std::uint32_t      count       = 1;
    VkShaderStageFlags stage_flags = {};

    [[nodiscard]] constexpr operator VkDescriptorSetLayoutBinding() const noexcept
    {
        return {.binding = binding, .descriptorType = descriptor, .descriptorCount = count, .stageFlags = stage_flags, .pImmutableSamplers = nullptr};
    }

    [[nodiscard]] friend constexpr bool operator==(const type& a, const type& b) noexcept  = default;
    [[nodiscard]] friend constexpr bool operator!=(const type& a, const type& b) noexcept  = default;
    [[nodiscard]] friend constexpr auto operator<=>(const type& a, const type& b) noexcept = default;
};

template<>
struct type<VK_DESCRIPTOR_TYPE_SAMPLER>
{
    using underlying_type = VkDescriptorSetLayoutBinding;

    static constexpr auto descriptor = VK_DESCRIPTOR_TYPE_SAMPLER;

    std::uint32_t      binding           = 0;
    std::uint32_t      count             = 1;
    VkShaderStageFlags stage_flags       = {};
    sampler_handle     immutable_sampler = null_handle;

    [[nodiscard]] constexpr operator VkDescriptorSetLayoutBinding() const noexcept
    {
        return {
            .binding            = binding,
            .descriptorType     = descriptor,
            .descriptorCount    = count,
            .stageFlags         = stage_flags,
            .pImmutableSamplers = immutable_sampler != null_handle ? std::addressof(immutable_sampler.vk) : nullptr,
        };
    }

    [[nodiscard]] friend constexpr bool operator==(const type& a, const type& b) noexcept  = default;
    [[nodiscard]] friend constexpr bool operator!=(const type& a, const type& b) noexcept  = default;
    [[nodiscard]] friend constexpr auto operator<=>(const type& a, const type& b) noexcept = default;
};

template<>
struct type<VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER>
{
    using underlying_type = VkDescriptorSetLayoutBinding;

    static constexpr auto descriptor = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;

    std::uint32_t      binding           = 0;
    std::uint32_t      count             = 1;
    VkShaderStageFlags stage_flags       = {};
    sampler_handle     immutable_sampler = null_handle;

    [[nodiscard]] constexpr operator VkDescriptorSetLayoutBinding() const noexcept
    {
        return {
            .binding            = binding,
            .descriptorType     = descriptor,
            .descriptorCount    = count,
            .stageFlags         = stage_flags,
            .pImmutableSamplers = immutable_sampler != null_handle ? std::addressof(immutable_sampler.vk) : nullptr,
        };
    }

    [[nodiscard]] friend constexpr bool operator==(const type& a, const type& b) noexcept  = default;
    [[nodiscard]] friend constexpr bool operator!=(const type& a, const type& b) noexcept  = default;
    [[nodiscard]] friend constexpr auto operator<=>(const type& a, const type& b) noexcept = default;
};

} // namespace detail::descriptor_binding

namespace descriptor_binding
{

using sampler                = detail::descriptor_binding::type<VK_DESCRIPTOR_TYPE_SAMPLER>;
using combined_image_sampler = detail::descriptor_binding::type<VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER>;
using sampled_image          = detail::descriptor_binding::type<VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE>;
using storage_image          = detail::descriptor_binding::type<VK_DESCRIPTOR_TYPE_STORAGE_IMAGE>;
using uniform_texel_buffer   = detail::descriptor_binding::type<VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER>;
using storage_texel_buffer   = detail::descriptor_binding::type<VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER>;
using uniform_buffer         = detail::descriptor_binding::type<VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER>;
using ubo                    = uniform_buffer;
using storage_buffer         = detail::descriptor_binding::type<VK_DESCRIPTOR_TYPE_STORAGE_BUFFER>;
using ssbo                   = storage_buffer;
using dynamic_uniform_buffer = detail::descriptor_binding::type<VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC>;
using dynamic_ubo            = dynamic_uniform_buffer;
using dynamic_storage_buffer = detail::descriptor_binding::type<VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC>;
using dynamic_ssbo           = dynamic_storage_buffer;
using input_attachment       = detail::descriptor_binding::type<VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT>;

#if defined(VK_VERSION_1_3)
using inline_uniform_block = detail::descriptor_binding::type<VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK>;
#endif // defined(VK_VERSION_1_3)

#if defined(VK_KHR_acceleration_structure)
using acceleration_structure_khr = detail::descriptor_binding::type<VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR>;
#endif // defined(VK_KHR_acceleration_structure)
#if defined(VK_NV_ray_tracing)
using acceleration_structure_nv = detail::descriptor_binding::type<VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_NV>;
#endif // defined(VK_NV_ray_tracing)

#if defined(VK_QCOM_image_processing)
using sample_weight_image_qcom = detail::descriptor_binding::type<VK_DESCRIPTOR_TYPE_SAMPLE_WEIGHT_IMAGE_QCOM>;
#endif // defined(VK_QCOM_image_processing)

#if defined(VK_QCOM_image_processing)
using block_match_image_qcom = detail::descriptor_binding::type<VK_DESCRIPTOR_TYPE_BLOCK_MATCH_IMAGE_QCOM>;
#endif // defined(VK_QCOM_image_processing)

#if defined(VK_EXT_mutable_descriptor_type)
using mutable_ext = detail::descriptor_binding::type<VK_DESCRIPTOR_TYPE_MUTABLE_EXT>;
#endif // defined(VK_EXT_mutable_descriptor_type)

#if defined(VK_NV_partitioned_acceleration_structure)
using partitioned_acceleration_structure = detail::descriptor_binding::type<VK_DESCRIPTOR_TYPE_PARTITIONED_ACCELERATION_STRUCTURE_NV>;
#endif // defined(VK_EXT_mutable_descriptor_type)

struct any
{
    using underlying_type = std::variant<sampler,
                                         combined_image_sampler,
                                         sampled_image,
                                         storage_image,
                                         uniform_texel_buffer,
                                         storage_texel_buffer,
                                         uniform_buffer,
                                         storage_buffer,
                                         dynamic_uniform_buffer,
                                         dynamic_storage_buffer,
                                         input_attachment

#if defined(VK_VERSION_1_3)
                                         ,
                                         inline_uniform_block
#endif // defined(VK_VERSION_1_3)

#if defined(VK_KHR_acceleration_structure)
                                         ,
                                         acceleration_structure_khr
#endif // defined(VK_KHR_acceleration_structure)
#if defined(VK_NV_ray_tracing)
                                         ,
                                         acceleration_structure_nv
#endif // defined(VK_NV_ray_tracing)

#if defined(VK_QCOM_image_processing)
                                         ,
                                         sample_weight_image_qcom
#endif // defined(VK_QCOM_image_processing)

#if defined(VK_QCOM_image_processing)
                                         ,
                                         block_match_image_qcom
#endif // defined(VK_QCOM_image_processing)

#if defined(VK_EXT_mutable_descriptor_type)
                                         ,
                                         mutable_ext
#endif // defined(VK_EXT_mutable_descriptor_type)

#if defined(VK_NV_partitioned_acceleration_structure)
                                         ,
                                         partitioned_acceleration_structure
#endif // defined(VK_EXT_mutable_descriptor_type)

                                         >;

    [[nodiscard]] constexpr operator VkDescriptorSetLayoutBinding() const noexcept
    {
        return std::visit([](const auto& variant) constexpr noexcept -> VkDescriptorSetLayoutBinding { return variant; }, value);
    }

    underlying_type value = {};
};

/// The number of different descriptor types supported.
constexpr auto count = std::variant_size_v<any::underlying_type>;

/// Size of the small buffer for descriptor_set_layout_information.
inline constexpr std::size_t sbo_size = 6;

} // namespace descriptor_binding

namespace information
{

/// Inforation required to create an instance of fuyu::descriptor_set_layout.
struct descriptor_set_layout
{
    using underlying_type = VkDescriptorSetLayoutCreateInfo;

    VkDescriptorSetLayoutCreateFlags                                    flags    = {}; ///< Flags for this descriptor set layout.
    small_vector<descriptor_binding::any, descriptor_binding::sbo_size> bindings = {}; ///< Descriptor bindings.

    std::optional<creation_callback> callbacks = {}; ///< (optional) Callback functions upon allocation/free.
    std::optional<std::string>       name      = {}; ///< (optional) Name passed to debug markers.

    [[nodiscard]] friend constexpr bool operator==(const descriptor_set_layout& a, const descriptor_set_layout& b) noexcept
    {
        return (a.flags == b.flags)
            and std::ranges::equal(
                   a.bindings, b.bindings, [](const descriptor_binding::any& x, const descriptor_binding::any& y) noexcept { return x == y; })
            and (a.callbacks == b.callbacks) and (a.name == b.name);
    }

    [[nodiscard]] friend constexpr bool operator!=(const descriptor_set_layout& a, const descriptor_set_layout& b) noexcept { return not(a == b); }

    [[nodiscard]] friend constexpr underlying_type to_underlying(std::reference_wrapper<const descriptor_set_layout> cref,
                                                                 std::span<const VkDescriptorSetLayoutBinding>       vk_bindings)
    {
        // Avoids having to introduce deleted overloads for temporaries
        const auto& s = cref.get();

        return {
            .sType        = structure_type_v<underlying_type>,
            .pNext        = nullptr,
            .flags        = s.flags,
            .bindingCount = vk_size(vk_bindings),
            .pBindings    = vk_bindings.data(),
        };
    }
};

} // namespace information

} // namespace fubuki::fuyu

#endif // FUBUKI_FUYU_INFORMATION_DESCRIPTOR_SET_LAYOUT_HPP
