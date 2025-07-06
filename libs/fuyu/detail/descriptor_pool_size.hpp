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

#ifndef FUBUKI_FUYU_DETAIL_DESCRIPTOR_POOL_SIZE_HPP
#define FUBUKI_FUYU_DETAIL_DESCRIPTOR_POOL_SIZE_HPP

#include <algorithm>
#include <array>
#include <initializer_list>
#include <ranges>
#include <span>
#include <variant>

#include <core/assertion.hpp>
#include <core/enum/descriptor_type.hpp>
#include <core/future/inplace_vector.hpp>
#include <core/vulkan.hpp>

namespace fubuki::fuyu::detail
{

namespace descriptor_type
{

template<VkDescriptorType t>
struct type
{
    static constexpr auto id    = t;
    std::uint32_t         count = 1;

    [[nodiscard]] friend constexpr bool operator==(const type& a, const type& b) noexcept  = default;
    [[nodiscard]] friend constexpr bool operator!=(const type& a, const type& b) noexcept  = default;
    [[nodiscard]] friend constexpr auto operator<=>(const type& a, const type& b) noexcept = default;
};

using sampler                = type<VK_DESCRIPTOR_TYPE_SAMPLER>;
using combined_image_sampler = type<VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER>;
using sampled_image          = type<VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE>;
using storage_image          = type<VK_DESCRIPTOR_TYPE_STORAGE_IMAGE>;
using uniform_texel_buffer   = type<VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER>;
using storage_texel_buffer   = type<VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER>;
using uniform_buffer         = type<VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER>;
using ubo                    = uniform_buffer;
using storage_buffer         = type<VK_DESCRIPTOR_TYPE_STORAGE_BUFFER>;
using ssbo                   = storage_buffer;
using dynamic_uniform_buffer = type<VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC>;
using dynamic_ubo            = dynamic_uniform_buffer;
using dynamic_storage_buffer = type<VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC>;
using dynamic_ssbo           = dynamic_storage_buffer;
using input_attachment       = type<VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT>;

#if defined(VK_VERSION_1_3)
using inline_uniform_block = type<VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK>;
#endif // defined(VK_VERSION_1_3)

#if defined(VK_KHR_acceleration_structure)
using acceleration_structure_khr = type<VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR>;
#endif // defined(VK_KHR_acceleration_structure)

#if defined(VK_NV_ray_tracing)
using acceleration_structure_nv = type<VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_NV>;
#endif // defined(VK_NV_ray_tracing)

#if defined(VK_QCOM_image_processing)
using sample_weight_image_qcom = type<VK_DESCRIPTOR_TYPE_SAMPLE_WEIGHT_IMAGE_QCOM>;
#endif // defined(VK_QCOM_image_processing)

#if defined(VK_QCOM_image_processing)
using block_match_image_qcom = type<VK_DESCRIPTOR_TYPE_BLOCK_MATCH_IMAGE_QCOM>;
#endif // defined(VK_QCOM_image_processing)

#if defined(VK_EXT_mutable_descriptor_type)
using mutable_ext = type<VK_DESCRIPTOR_TYPE_MUTABLE_EXT>;
#endif // defined(VK_EXT_mutable_descriptor_type)

#if defined(VK_NV_partitioned_acceleration_structure)
using partitioned_acceleration_structure = type<VK_DESCRIPTOR_TYPE_PARTITIONED_ACCELERATION_STRUCTURE_NV>;
#endif // defined(VK_EXT_mutable_descriptor_type)

using any = std::variant<sampler,
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

/// The number of different descriptor types supported.
constexpr auto count = std::variant_size_v<any>;

} // namespace descriptor_type

namespace descriptor_pool_size
{

/**
 *  Size of a descriptor pool, expressed in terms of elements that can be allocated for each VkDescriptorType.
 *
 * You can either initialise it directly (like any struct) when you know you many pool types you need in advance.
 * However, when you cannot know the size directly, you may:
 * - Built in incrementally, using `operator+=(VkDescriptorPoolSize)` or a similar overload.
 * - Built in from a range, using an overload of `from_range`.
 *
 * @section example Example
 * @code{.cpp}
 *
 * // Known size
 * {
 *     constexpr descriptor_pool_size s1 =
 *     {
 *         .sampler        = 2,
 *         .uniform_buffer = 4,
 *         .storage_buffer = 1,
 *     };
 *
 *     use(s1);
 * }
 *
 * // Size retrieved separately as VkDescriptorPoolSize (e.g, from a file)
 * {
 *     const std::vector<VkDescriptorPoolSize> size = read_some_file();
 *
 *     const auto s2 = descriptor_pool_size::from_vk(size);
 *     use(s2);
 * }
 *
 * // From a generic range
 * {
 *      // Typically something external you don't control
 *      struct data
 *      {
 *          VkDescriptorPoolSize needs = {};
 *          std::size_t id             = {};
 *          external::whatever other   = {};
 *      };
 *
 *      const std::vector<data> d = external::from_file(...);
 *
 *      constexpr auto filter = [](const data& d) noexcept{return data.id == something_relevant};
 *      constexpr auto project = [](const data& d) noexcept -> const auto& {return d.needs;};
 *
 *      const auto s3 = descriptor_pool_size::from_range(d
 *                                                       | std::views::filter(filter)
 *                                                       | std::views::transform(project));
 *      use(s3);
 * }
 *
 * // Incrementally (manually)
 * {
 *     descriptor_pool_size s4 = {};
 *
 *     for(const auto& something : a_range)
 *     {
 *         s4 += something.descriptor_needs; // Or whatever you need to obtain the needs in terms of descriptors
 *     }
 *
 *     use(s4);
 * }
 * @endcode
 */
struct type
{
    using underlying_type = inplace_vector<VkDescriptorPoolSize, descriptor_type::count>;

    std::uint32_t sampler                = {}; ///< Number of VK_DESCRIPTOR_TYPE_SAMPLER descriptors that can be allocated.
    std::uint32_t combined_image_sampler = {}; ///< Number of VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER descriptors that can be allocated.
    std::uint32_t sampled_image          = {}; ///< Number of VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE descriptors that can be allocated.
    std::uint32_t storage_image          = {}; ///< Number of VK_DESCRIPTOR_TYPE_STORAGE_IMAGE descriptors that can be allocated.
    std::uint32_t uniform_texel_buffer   = {}; ///< Number of VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER descriptors that can be allocated.
    std::uint32_t storage_texel_buffer   = {}; ///< Number of VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER descriptors that can be allocated.
    std::uint32_t uniform_buffer         = {}; ///< Number of VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER descriptors that can be allocated.
    std::uint32_t storage_buffer         = {}; ///< Number of VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER descriptors that can be allocated.
    std::uint32_t dynamic_uniform_buffer = {}; ///< Number of VK_DESCRIPTOR_TYPE_STORAGE_BUFFER descriptors that can be allocated.
    std::uint32_t dynamic_storage_buffer = {}; ///< Number of VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC descriptors that can be allocated.
    std::uint32_t input_attachment       = {}; ///< Number of VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC descriptors that can be allocated.

#if defined(VK_VERSION_1_3)
    std::uint32_t inline_uniform_block = {}; ///< Number of VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK descriptors that can be allocated.
#endif                                       // defined(VK_VERSION_1_3)

#if defined(VK_KHR_acceleration_structure)
    std::uint32_t acceleration_structure_khr = {}; ///< Number of VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR descriptors that can be allocated.
#endif                                             // defined(VK_KHR_acceleration_structure)

#if defined(VK_NV_ray_tracing)
    std::uint32_t acceleration_structure_nv = {}; ///< Number of VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_NV descriptors that can be allocated.
#endif                                            // defined(VK_NV_ray_tracing)

#if defined(VK_QCOM_image_processing)
    std::uint32_t sample_weight_image_qcom = {}; ///< Number of VK_DESCRIPTOR_TYPE_SAMPLE_WEIGHT_IMAGE_QCOM descriptors that can be allocated.
#endif                                           // defined(VK_QCOM_image_processing)

#if defined(VK_QCOM_image_processing)
    std::uint32_t block_match_image_qcom = {}; ///< Number of VK_DESCRIPTOR_TYPE_BLOCK_MATCH_IMAGE_QCOM descriptors that can be allocated.
#endif                                         // defined(VK_QCOM_image_processing)

#if defined(VK_EXT_mutable_descriptor_type)
    std::uint32_t mutable_ext = {}; ///< Number of VK_DESCRIPTOR_TYPE_MUTABLE_EXT descriptors that can be allocated.
#endif                              // defined(VK_EXT_mutable_descriptor_type)

#if defined(VK_NV_partitioned_acceleration_structure)
    std::uint32_t partitioned_acceleration_structure
        = {}; ///< Number of VK_DESCRIPTOR_TYPE_PARTITIONED_ACCELERATION_STRUCTURE_NV  descriptors that can be allocated.
#endif        // defined(VK_EXT_mutable_descriptor_type)

    [[nodiscard]] friend constexpr bool operator==(const type& a, const type& b) noexcept  = default;
    [[nodiscard]] friend constexpr bool operator!=(const type& a, const type& b) noexcept  = default;
    [[nodiscard]] friend constexpr auto operator<=>(const type& a, const type& b) noexcept = default;

    /// Adds the information held by a VkDescriptorPoolSize.
    constexpr type& operator+=(const VkDescriptorPoolSize& s) noexcept
    {
        switch(s.type)
        {
            case VK_DESCRIPTOR_TYPE_SAMPLER               : sampler += s.descriptorCount; break;
            case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER: combined_image_sampler += s.descriptorCount; break;
            case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE         : sampled_image += s.descriptorCount; break;
            case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE         : storage_image += s.descriptorCount; break;
            case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER  : uniform_texel_buffer += s.descriptorCount; break;
            case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER  : storage_texel_buffer += s.descriptorCount; break;
            case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER        : uniform_buffer += s.descriptorCount; break;
            case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER        : storage_buffer += s.descriptorCount; break;
            case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC: dynamic_uniform_buffer += s.descriptorCount; break;
            case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC: dynamic_storage_buffer += s.descriptorCount; break;
            case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT      : input_attachment += s.descriptorCount; break;

#if defined(VK_VERSION_1_3)
            case VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK: inline_uniform_block += s.descriptorCount; break;
#endif // defined(VK_VERSION_1_3)

#if defined(VK_KHR_acceleration_structure)
            case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR: acceleration_structure_khr += s.descriptorCount; break;
#endif // defined(VK_KHR_acceleration_structure)

#if defined(VK_NV_ray_tracing)
            case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_NV: acceleration_structure_nv += s.descriptorCount; break;
#endif // defined(VK_NV_ray_tracing)

#if defined(VK_QCOM_image_processing)
            case VK_DESCRIPTOR_TYPE_SAMPLE_WEIGHT_IMAGE_QCOM: sample_weight_image_qcom += s.descriptorCount; break;
#endif // defined(VK_QCOM_image_processing)

#if defined(VK_QCOM_image_processing)
            case VK_DESCRIPTOR_TYPE_BLOCK_MATCH_IMAGE_QCOM: block_match_image_qcom += s.descriptorCount; break;
#endif // defined(VK_QCOM_image_processing)

#if defined(VK_EXT_mutable_descriptor_type)
            case VK_DESCRIPTOR_TYPE_MUTABLE_EXT: mutable_ext += s.descriptorCount; break;

#endif // defined(VK_EXT_mutable_descriptor_type)
#if defined(VK_NV_partitioned_acceleration_structure)
            case VK_DESCRIPTOR_TYPE_PARTITIONED_ACCELERATION_STRUCTURE_NV: partitioned_acceleration_structure += s.descriptorCount; break;
#endif // defined(VK_NV_partitioned_acceleration_structure)

            default:
            case VK_DESCRIPTOR_TYPE_MAX_ENUM: fubuki_assert(false, "Invalid descriptor type"); break;
        }

        return *this;
    }

    /// Removes the information held by a VkDescriptorPoolSize.
    constexpr type& operator-=(const VkDescriptorPoolSize& s) noexcept
    {
        switch(s.type)
        {
            case VK_DESCRIPTOR_TYPE_SAMPLER               : sampler -= s.descriptorCount; break;
            case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER: combined_image_sampler -= s.descriptorCount; break;
            case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE         : sampled_image -= s.descriptorCount; break;
            case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE         : storage_image -= s.descriptorCount; break;
            case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER  : uniform_texel_buffer -= s.descriptorCount; break;
            case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER  : storage_texel_buffer -= s.descriptorCount; break;
            case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER        : uniform_buffer -= s.descriptorCount; break;
            case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER        : storage_buffer -= s.descriptorCount; break;
            case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC: dynamic_uniform_buffer -= s.descriptorCount; break;
            case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC: dynamic_storage_buffer -= s.descriptorCount; break;
            case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT      : input_attachment -= s.descriptorCount; break;

#if defined(VK_VERSION_1_3)
            case VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK: inline_uniform_block -= s.descriptorCount; break;
#endif // defined(VK_VERSION_1_3)

#if defined(VK_KHR_acceleration_structure)
            case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR: acceleration_structure_khr -= s.descriptorCount; break;
#endif // defined(VK_KHR_acceleration_structure)

#if defined(VK_NV_ray_tracing)
            case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_NV: acceleration_structure_nv -= s.descriptorCount; break;
#endif // defined(VK_NV_ray_tracing)

#if defined(VK_QCOM_image_processing)
            case VK_DESCRIPTOR_TYPE_SAMPLE_WEIGHT_IMAGE_QCOM: sample_weight_image_qcom -= s.descriptorCount; break;
#endif // defined(VK_QCOM_image_processing)

#if defined(VK_QCOM_image_processing)
            case VK_DESCRIPTOR_TYPE_BLOCK_MATCH_IMAGE_QCOM: block_match_image_qcom -= s.descriptorCount; break;
#endif // defined(VK_QCOM_image_processing)

#if defined(VK_EXT_mutable_descriptor_type)
            case VK_DESCRIPTOR_TYPE_MUTABLE_EXT: mutable_ext -= s.descriptorCount; break;
#endif // defined(VK_EXT_mutable_descriptor_type)

#if defined(VK_NV_partitioned_acceleration_structure)
            case VK_DESCRIPTOR_TYPE_PARTITIONED_ACCELERATION_STRUCTURE_NV: partitioned_acceleration_structure -= s.descriptorCount; break;
#endif // defined(VK_NV_partitioned_acceleration_structure)

            default:
            case VK_DESCRIPTOR_TYPE_MAX_ENUM: fubuki_assert(false, "Invalid descriptor type"); break;
        }

        return *this;
    }

    /// Adds the information held by a descriptor_type provided by fubuki::fuyu::descriptor_type.
    template<VkDescriptorType descriptor_type>
    constexpr type& operator+=(const detail::descriptor_type::type<descriptor_type>& s) noexcept
    {
        return *this += VkDescriptorPoolSize{descriptor_type, s.count};
    }

    /// Removes the information held by a descriptor_type provided by fubuki::fuyu::descriptor_type.
    template<VkDescriptorType descriptor_type>
    constexpr type& operator-=(const detail::descriptor_type::type<descriptor_type>& s) noexcept
    {
        return *this -= VkDescriptorPoolSize{descriptor_type, s.count};
    }

    /// Constructs a type from a range of VkDescriptorPoolSize.
    template<std::ranges::range range>
    requires(std::constructible_from<VkDescriptorPoolSize, std::ranges::range_reference_t<range>>)
    [[nodiscard]] static constexpr auto from_range(range r) noexcept
    {
        type result = {};

        std::ranges::for_each(std::forward<range>(r), [&result](const auto& size) noexcept { result += size; });

        return result;
    }

    /// Constructs a descriptor_pool_size from an initializer list of VkDescriptorPoolSize.
    [[nodiscard]] static constexpr auto from_range(std::initializer_list<VkDescriptorPoolSize> range) noexcept
    {
        return from_range(std::span{range});
    }

    /// Indicates the total size of indicated by this object, that is, the sum of all its members.
    [[nodiscard]] constexpr auto total() const noexcept
    {
        // clang-format off
        return sampler
               + combined_image_sampler
               + sampled_image
               + storage_image
               + uniform_texel_buffer
               + storage_texel_buffer
               + uniform_buffer
               + storage_buffer
               + dynamic_uniform_buffer
               + dynamic_storage_buffer
               + input_attachment

               #if defined(VK_VERSION_1_3)
               + inline_uniform_block
               #endif // defined(VK_VERSION_1_3)

               #if defined(VK_KHR_acceleration_structure)
               + acceleration_structure_khr
               #endif // defined(VK_KHR_acceleration_structure)

               #if defined(VK_NV_ray_tracing)
               + acceleration_structure_nv
               #endif // defined(VK_NV_ray_tracing)

               #if defined(VK_QCOM_image_processing)
               + sample_weight_image_qcom
               #endif // defined(VK_QCOM_image_processing)

               #if defined(VK_QCOM_image_processing)
               + block_match_image_qcom
               #endif // defined(VK_QCOM_image_processing)

               #if defined(VK_EXT_mutable_descriptor_type)
               + mutable_ext
               #endif        // defined(VK_EXT_mutable_descriptor_type)

               #if defined(VK_NV_partitioned_acceleration_structure)
               + partitioned_acceleration_structure
               #endif        // defined(VK_NV_partitioned_acceleration_structure)
            // clang-format on
            ; // Return statement
    }

    /// Indicates if this object describes a 0-sized pool.
    [[nodiscard]] constexpr bool empty() const noexcept { return total() == 0; }

    [[nodiscard]]
    friend constexpr auto as_array(const type& size) noexcept
    {
        struct entry
        {
            std::uint32_t    count = 0;
            VkDescriptorType id    = {};
        };

        return std::array{
            entry{size.sampler,                            descriptor_type::sampler::id                           },
            entry{size.combined_image_sampler,             descriptor_type::combined_image_sampler::id            },
            entry{size.sampled_image,                      descriptor_type::sampled_image::id                     },
            entry{size.storage_image,                      descriptor_type::storage_image::id                     },
            entry{size.uniform_texel_buffer,               descriptor_type::uniform_texel_buffer::id              },
            entry{size.storage_texel_buffer,               descriptor_type::storage_texel_buffer::id              },
            entry{size.uniform_buffer,                     descriptor_type::uniform_buffer::id                    },
            entry{size.storage_buffer,                     descriptor_type::storage_buffer::id                    },
            entry{size.dynamic_uniform_buffer,             descriptor_type::dynamic_uniform_buffer::id            },
            entry{size.dynamic_storage_buffer,             descriptor_type::dynamic_storage_buffer::id            },
            entry{size.input_attachment,                   descriptor_type::input_attachment::id                  }

#if defined(VK_VERSION_1_3)
            ,
            entry{size.inline_uniform_block,               descriptor_type::inline_uniform_block::id              }
#endif  // defined(VK_VERSION_1_3)

#if defined(VK_KHR_acceleration_structure)
            ,
            entry{size.acceleration_structure_khr,         descriptor_type::acceleration_structure_khr::id        }
#endif  // defined(VK_KHR_acceleration_structure)
#if defined(VK_NV_ray_tracing)
            ,
            entry{size.acceleration_structure_nv,          descriptor_type::acceleration_structure_nv::id         }
#endif  // defined(VK_NV_ray_tracing)

#if defined(VK_QCOM_image_processing)
            ,
            entry{size.sample_weight_image_qcom,           descriptor_type::sample_weight_image_qcom::id          }
#endif  // defined(VK_QCOM_image_processing)

#if defined(VK_QCOM_image_processing)
            ,
            entry{size.block_match_image_qcom,             descriptor_type::block_match_image_qcom::id            }
#endif  // defined(VK_QCOM_image_processing)

#if defined(VK_EXT_mutable_descriptor_type)
            ,
            entry{size.mutable_ext,                        descriptor_type::mutable_ext::id                       }
#endif  // defined(VK_EXT_mutable_descriptor_type)

#if defined(VK_NV_partitioned_acceleration_structure)
            ,
            entry{size.partitioned_acceleration_structure, descriptor_type::partitioned_acceleration_structure::id}
#endif  // defined(VK_NV_partitioned_acceleration_structure
        };
    }

    /// Packs a descriptor pool size into an inplace_vector<VkDescriptorPoolSize, descriptor_type::count>
    [[nodiscard]]
    friend constexpr underlying_type to_underlying(const type& size) noexcept
    {
        underlying_type result = {};

        for(const auto [count, type] : as_array(size))
        {
            if(count > 0)
            {
                result.emplace_back(type, count);
            }
        }

        return result;
    }
};

} // namespace descriptor_pool_size

} // namespace fubuki::fuyu::detail

#endif // FUBUKI_FUYU_DETAIL_DESCRIPTOR_POOL_SIZE_HPP
