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

#ifndef FUBUKI_FUYU_DETAIL_FORMATTED_STORAGE_HPP
#define FUBUKI_FUYU_DETAIL_FORMATTED_STORAGE_HPP

#include <cstdint>
#include <cstring>
#include <functional>
#include <span>
#include <variant>
#include <vector>

#include <core/assertion.hpp>
#include <core/config/macros.hpp>
#include <core/vulkan.hpp>
#include <maths/vec2.hpp>
#include <maths/vec3.hpp>
#include <maths/vec4.hpp>

namespace fubuki::fuyu::detail
{

static_assert(alignof(vec3) == alignof(vec4),
              "Invalid GLM configuration. Fubuki requires vec3 to be aligned to vec4 to stay compatible with standard layout rules.");

template<typename T>
concept storage_element = std::is_same_v<T, std::span<std::byte>> or std::is_same_v<T, std::uint8_t> or std::is_same_v<T, std::uint16_t>
    or std::is_same_v<T, std::uint32_t> or std::is_same_v<T, std::uint64_t> or std::is_same_v<T, std::int8_t> or std::is_same_v<T, std::int16_t>
    or std::is_same_v<T, std::int32_t> or std::is_same_v<T, std::int64_t> or std::is_same_v<T, float> or std::is_same_v<T, double>

    or std::is_same_v<T, vec2> or std::is_same_v<T, dvec2> or std::is_same_v<T, i8vec2> or std::is_same_v<T, i16vec2> or std::is_same_v<T, i32vec2>
    or std::is_same_v<T, i64vec2> or std::is_same_v<T, u8vec2> or std::is_same_v<T, u16vec2> or std::is_same_v<T, u32vec2>
    or std::is_same_v<T, u64vec2>

    or std::is_same_v<T, vec3> or std::is_same_v<T, dvec3> or std::is_same_v<T, i8vec3> or std::is_same_v<T, i16vec3> or std::is_same_v<T, i32vec3>
    or std::is_same_v<T, i64vec3> or std::is_same_v<T, u8vec3> or std::is_same_v<T, u16vec3> or std::is_same_v<T, u32vec3>
    or std::is_same_v<T, u64vec3>

    or std::is_same_v<T, vec4> or std::is_same_v<T, dvec4> or std::is_same_v<T, i8vec4> or std::is_same_v<T, i16vec4> or std::is_same_v<T, i32vec4>
    or std::is_same_v<T, i64vec4> or std::is_same_v<T, u8vec4> or std::is_same_v<T, u16vec4> or std::is_same_v<T, u32vec4>
    or std::is_same_v<T, u64vec4>;

/// All possibles element for buffers and CPU-side storage.
using any_storage_element = std::variant<std::span<const std::byte>,

                                         std::uint8_t,
                                         std::uint16_t,
                                         std::uint32_t,
                                         std::uint64_t,
                                         std::int8_t,
                                         std::int16_t,
                                         std::int32_t,
                                         std::int64_t,
                                         float,
                                         double,

                                         vec2,
                                         dvec2,
                                         i8vec2,
                                         i16vec2,
                                         i32vec2,
                                         i64vec2,
                                         u8vec2,
                                         u16vec2,
                                         u32vec2,
                                         u64vec2,

                                         vec3,
                                         dvec3,
                                         i8vec3,
                                         i16vec3,
                                         i32vec3,
                                         i64vec3,
                                         u8vec3,
                                         u16vec3,
                                         u32vec3,
                                         u64vec3,

                                         vec4,
                                         dvec4,
                                         i8vec4,
                                         i16vec4,
                                         i32vec4,
                                         i64vec4,
                                         u8vec4,
                                         u16vec4,
                                         u32vec4,
                                         u64vec4>;

class any_element_ref
{
private:
    using underlying_type = std::variant<std::monostate, // To allow default initialisation

                                         // For formats we allocate raw byte storage, return the bytes themselves to the user can
                                         std::span<std::byte>,

                                         std::reference_wrapper<std::uint8_t>,
                                         std::reference_wrapper<std::uint16_t>,
                                         std::reference_wrapper<std::uint32_t>,
                                         std::reference_wrapper<std::uint64_t>,
                                         std::reference_wrapper<std::int8_t>,
                                         std::reference_wrapper<std::int16_t>,
                                         std::reference_wrapper<std::int32_t>,
                                         std::reference_wrapper<std::int64_t>,
                                         std::reference_wrapper<float>,
                                         std::reference_wrapper<double>,

                                         std::reference_wrapper<vec2>,
                                         std::reference_wrapper<dvec2>,
                                         std::reference_wrapper<i8vec2>,
                                         std::reference_wrapper<i16vec2>,
                                         std::reference_wrapper<i32vec2>,
                                         std::reference_wrapper<i64vec2>,
                                         std::reference_wrapper<u8vec2>,
                                         std::reference_wrapper<u16vec2>,
                                         std::reference_wrapper<u32vec2>,
                                         std::reference_wrapper<u64vec2>,

                                         std::reference_wrapper<vec3>,
                                         std::reference_wrapper<dvec3>,
                                         std::reference_wrapper<i8vec3>,
                                         std::reference_wrapper<i16vec3>,
                                         std::reference_wrapper<i32vec3>,
                                         std::reference_wrapper<i64vec3>,
                                         std::reference_wrapper<u8vec3>,
                                         std::reference_wrapper<u16vec3>,
                                         std::reference_wrapper<u32vec3>,
                                         std::reference_wrapper<u64vec3>,

                                         std::reference_wrapper<vec4>,
                                         std::reference_wrapper<dvec4>,
                                         std::reference_wrapper<i8vec4>,
                                         std::reference_wrapper<i16vec4>,
                                         std::reference_wrapper<i32vec4>,
                                         std::reference_wrapper<i64vec4>,
                                         std::reference_wrapper<u8vec4>,
                                         std::reference_wrapper<u16vec4>,
                                         std::reference_wrapper<u32vec4>,
                                         std::reference_wrapper<u64vec4>>;

    underlying_type m_value = {};

public:

    template<storage_element T>
    constexpr any_element_ref(T& v) noexcept : m_value{v}
    {
    }

    constexpr any_element_ref(std::span<std::byte> v) noexcept : m_value{v} {}

    constexpr any_element_ref() noexcept                                  = default;
    constexpr any_element_ref(const any_element_ref&) noexcept            = default;
    constexpr any_element_ref& operator=(const any_element_ref&) noexcept = default;

    template<storage_element T>
    inline constexpr any_element_ref& operator=(const T& v)
    {
        const auto visitor = [&v](auto& var) constexpr noexcept
        {
            using variant_type = std::decay_t<decltype(var)>;

            constexpr auto valid_assignment = requires {
                { var = variant_type(v) };
            };

            if constexpr(valid_assignment)
            {
                var = variant_type(v);
            }

            fubuki_assert(valid_assignment, "Type mistmatch between the argument and the contents.");
        };

        std::visit(visitor, m_value);

        return *this;
    }
};

/// All possibles storage for buffers and CPU-side storage.
using any_storage = std::variant<std::vector<std::byte>,

                                 std::vector<std::uint8_t>,
                                 std::vector<std::uint16_t>,
                                 std::vector<std::uint32_t>,
                                 std::vector<std::uint64_t>,
                                 std::vector<std::int8_t>,
                                 std::vector<std::int16_t>,
                                 std::vector<std::int32_t>,
                                 std::vector<std::int64_t>,
                                 std::vector<float>,
                                 std::vector<double>,

                                 std::vector<vec2>,
                                 std::vector<dvec2>,
                                 std::vector<i8vec2>,
                                 std::vector<i16vec2>,
                                 std::vector<i32vec2>,
                                 std::vector<i64vec2>,
                                 std::vector<u8vec2>,
                                 std::vector<u16vec2>,
                                 std::vector<u32vec2>,
                                 std::vector<u64vec2>,

                                 std::vector<vec3>,
                                 std::vector<dvec3>,
                                 std::vector<i8vec3>,
                                 std::vector<i16vec3>,
                                 std::vector<i32vec3>,
                                 std::vector<i64vec3>,
                                 std::vector<u8vec3>,
                                 std::vector<u16vec3>,
                                 std::vector<u32vec3>,
                                 std::vector<u64vec3>,

                                 std::vector<vec4>,
                                 std::vector<dvec4>,
                                 std::vector<i8vec4>,
                                 std::vector<i16vec4>,
                                 std::vector<i32vec4>,
                                 std::vector<i64vec4>,
                                 std::vector<u8vec4>,
                                 std::vector<u16vec4>,
                                 std::vector<u32vec4>,
                                 std::vector<u64vec4>>;

using any_storage_span = std::variant<std::span<std::byte>,

                                      std::span<std::uint8_t>,
                                      std::span<std::uint16_t>,
                                      std::span<std::uint32_t>,
                                      std::span<std::uint64_t>,
                                      std::span<std::int8_t>,
                                      std::span<std::int16_t>,
                                      std::span<std::int32_t>,
                                      std::span<std::int64_t>,
                                      std::span<float>,
                                      std::span<double>,

                                      std::span<vec2>,
                                      std::span<dvec2>,
                                      std::span<i8vec2>,
                                      std::span<i16vec2>,
                                      std::span<i32vec2>,
                                      std::span<i64vec2>,
                                      std::span<u8vec2>,
                                      std::span<u16vec2>,
                                      std::span<u32vec2>,
                                      std::span<u64vec2>,

                                      std::span<vec3>,
                                      std::span<dvec3>,
                                      std::span<i8vec3>,
                                      std::span<i16vec3>,
                                      std::span<i32vec3>,
                                      std::span<i64vec3>,
                                      std::span<u8vec3>,
                                      std::span<u16vec3>,
                                      std::span<u32vec3>,
                                      std::span<u64vec3>,

                                      std::span<vec4>,
                                      std::span<dvec4>,
                                      std::span<i8vec4>,
                                      std::span<i16vec4>,
                                      std::span<i32vec4>,
                                      std::span<i64vec4>,
                                      std::span<u8vec4>,
                                      std::span<u16vec4>,
                                      std::span<u32vec4>,
                                      std::span<u64vec4>>;

using any_const_storage_span = std::variant<std::span<const std::byte>,

                                            std::span<const std::uint8_t>,
                                            std::span<const std::uint16_t>,
                                            std::span<const std::uint32_t>,
                                            std::span<const std::uint64_t>,
                                            std::span<const std::int8_t>,
                                            std::span<const std::int16_t>,
                                            std::span<const std::int32_t>,
                                            std::span<const std::int64_t>,
                                            std::span<const float>,
                                            std::span<const double>,

                                            std::span<const vec2>,
                                            std::span<const dvec2>,
                                            std::span<const i8vec2>,
                                            std::span<const i16vec2>,
                                            std::span<const i32vec2>,
                                            std::span<const i64vec2>,
                                            std::span<const u8vec2>,
                                            std::span<const u16vec2>,
                                            std::span<const u32vec2>,
                                            std::span<const u64vec2>,

                                            std::span<const vec3>,
                                            std::span<const dvec3>,
                                            std::span<const i8vec3>,
                                            std::span<const i16vec3>,
                                            std::span<const i32vec3>,
                                            std::span<const i64vec3>,
                                            std::span<const u8vec3>,
                                            std::span<const u16vec3>,
                                            std::span<const u32vec3>,
                                            std::span<const u64vec3>,

                                            std::span<const vec4>,
                                            std::span<const dvec4>,
                                            std::span<const i8vec4>,
                                            std::span<const i16vec4>,
                                            std::span<const i32vec4>,
                                            std::span<const i64vec4>,
                                            std::span<const u8vec4>,
                                            std::span<const u16vec4>,
                                            std::span<const u32vec4>,
                                            std::span<const u64vec4>>;

//------------------------------------------------------------------------------

inline constexpr any_storage_element storage_element_for(const VkFormat f) noexcept
{
    // NOLINTBEGIN(bugprone-branch-clone)
    switch(f)
    {
        //---------------------------------------
        // 8-bit

#if defined(VK_KHR_maintenance5)
        case(VK_FORMAT_A8_UNORM_KHR):
#endif
        case(VK_FORMAT_R4G4_UNORM_PACK8):
        case(VK_FORMAT_R8_UNORM):
        case(VK_FORMAT_R8_USCALED):
        case(VK_FORMAT_R8_UINT):
        case(VK_FORMAT_R8_SRGB):
        {
            return std::uint8_t{};
        }

        case(VK_FORMAT_R8_SNORM):
        case(VK_FORMAT_R8_SSCALED):
        case(VK_FORMAT_R8_SINT):
        {
            return std::int8_t{};
        }

        //---------------------------------------
        // 16-bit

#if defined(VK_KHR_maintenance5)
        case(VK_FORMAT_A1B5G5R5_UNORM_PACK16_KHR):
#endif

        case(VK_FORMAT_R10X6_UNORM_PACK16):
        case(VK_FORMAT_R12X4_UNORM_PACK16):
        case(VK_FORMAT_A4R4G4B4_UNORM_PACK16):
        case(VK_FORMAT_A4B4G4R4_UNORM_PACK16):
        case(VK_FORMAT_R4G4B4A4_UNORM_PACK16):
        case(VK_FORMAT_B4G4R4A4_UNORM_PACK16):
        case(VK_FORMAT_R5G6B5_UNORM_PACK16):
        case(VK_FORMAT_B5G6R5_UNORM_PACK16):
        case(VK_FORMAT_R5G5B5A1_UNORM_PACK16):
        case(VK_FORMAT_B5G5R5A1_UNORM_PACK16):
        case(VK_FORMAT_A1R5G5B5_UNORM_PACK16):
        {
            return std::uint16_t{};
        }

        case(VK_FORMAT_R8G8_UNORM):
        case(VK_FORMAT_R8G8_SNORM):
        case(VK_FORMAT_R8G8_UINT):
        case(VK_FORMAT_R8G8_SRGB):
        {
            return u8vec2{};
        }

        case(VK_FORMAT_R8G8_SSCALED):
        case(VK_FORMAT_R8G8_USCALED):
        case(VK_FORMAT_R8G8_SINT):
        {
            return i8vec2{};
        }

        case(VK_FORMAT_R16_UNORM):
        case(VK_FORMAT_R16_USCALED):
        case(VK_FORMAT_R16_UINT):
        {
            return std::uint16_t{};
        }

        case(VK_FORMAT_R16_SNORM):
        case(VK_FORMAT_R16_SSCALED):
        case(VK_FORMAT_R16_SINT):
        {
            return std::int16_t{};
        }

        case(VK_FORMAT_R16_SFLOAT):
        {
            return std::span<const std::byte>{}; // TODO: [C++23] use std::float16
        }

            //---------------------------------------
            // 24-bit

        case(VK_FORMAT_R8G8B8_SNORM):
        case(VK_FORMAT_R8G8B8_SSCALED):
        case(VK_FORMAT_R8G8B8_SINT):
        case(VK_FORMAT_B8G8R8_SNORM):
        case(VK_FORMAT_B8G8R8_SSCALED):
        case(VK_FORMAT_B8G8R8_SINT):
        {
            return i8vec3{};
        }

        case(VK_FORMAT_R8G8B8_SRGB):
        case(VK_FORMAT_R8G8B8_UNORM):
        case(VK_FORMAT_R8G8B8_USCALED):
        case(VK_FORMAT_R8G8B8_UINT):
        case(VK_FORMAT_B8G8R8_UNORM):
        case(VK_FORMAT_B8G8R8_USCALED):
        case(VK_FORMAT_B8G8R8_UINT):
        case(VK_FORMAT_B8G8R8_SRGB):
        {
            return u8vec3{};
        }

            //---------------------------------------
            // 32-bit

        case(VK_FORMAT_R10X6G10X6_UNORM_2PACK16):
        case(VK_FORMAT_R12X4G12X4_UNORM_2PACK16):
        {
            return u16vec2{};
        }

        case(VK_FORMAT_R8G8B8A8_UNORM):
        case(VK_FORMAT_R8G8B8A8_USCALED):
        case(VK_FORMAT_R8G8B8A8_UINT):
        case(VK_FORMAT_B8G8R8A8_UNORM):
        case(VK_FORMAT_B8G8R8A8_USCALED):
        case(VK_FORMAT_B8G8R8A8_UINT):
        case(VK_FORMAT_R8G8B8A8_SRGB):
        case(VK_FORMAT_B8G8R8A8_SRGB):
        {
            return u8vec4{};
        }

        case(VK_FORMAT_R8G8B8A8_SNORM):
        case(VK_FORMAT_R8G8B8A8_SSCALED):
        case(VK_FORMAT_R8G8B8A8_SINT):
        case(VK_FORMAT_B8G8R8A8_SNORM):
        case(VK_FORMAT_B8G8R8A8_SSCALED):
        case(VK_FORMAT_B8G8R8A8_SINT):
        {
            return i8vec4{};
        }

        case(VK_FORMAT_A8B8G8R8_UNORM_PACK32):
        case(VK_FORMAT_A8B8G8R8_USCALED_PACK32):
        case(VK_FORMAT_A8B8G8R8_UINT_PACK32):
        case(VK_FORMAT_A2R10G10B10_UNORM_PACK32):
        case(VK_FORMAT_A2R10G10B10_USCALED_PACK32):
        case(VK_FORMAT_A2R10G10B10_UINT_PACK32):
        case(VK_FORMAT_A2B10G10R10_UNORM_PACK32):
        case(VK_FORMAT_A2B10G10R10_USCALED_PACK32):
        case(VK_FORMAT_A2B10G10R10_UINT_PACK32):
        case(VK_FORMAT_A8B8G8R8_SRGB_PACK32):
        {
            return std::uint32_t{};
        }

        case(VK_FORMAT_A8B8G8R8_SNORM_PACK32):
        case(VK_FORMAT_A8B8G8R8_SSCALED_PACK32):
        case(VK_FORMAT_A8B8G8R8_SINT_PACK32):
        case(VK_FORMAT_A2R10G10B10_SNORM_PACK32):
        case(VK_FORMAT_A2R10G10B10_SSCALED_PACK32):
        case(VK_FORMAT_A2R10G10B10_SINT_PACK32):
        case(VK_FORMAT_A2B10G10R10_SNORM_PACK32):
        case(VK_FORMAT_A2B10G10R10_SSCALED_PACK32):
        case(VK_FORMAT_A2B10G10R10_SINT_PACK32):
        {
            return std::int32_t{};
        }

        case(VK_FORMAT_R16G16_UNORM):
        case(VK_FORMAT_R16G16_USCALED):
        case(VK_FORMAT_R16G16_UINT):
        {
            return u16vec2{};
        }

        case(VK_FORMAT_R16G16_SNORM):
        case(VK_FORMAT_R16G16_SSCALED):
        case(VK_FORMAT_R16G16_SINT):
        {
            return i16vec2{};
        }

        case(VK_FORMAT_R16G16_SFLOAT):
        {
            return u16vec2{}; // TODO: [C++23] use glm::vec<std::float16, 2>
        }

        case(VK_FORMAT_R32_UINT):
        {
            return std::uint32_t{};
        }

        case(VK_FORMAT_R32_SINT):
        {
            return std::int32_t{};
        }

        case(VK_FORMAT_R32_SFLOAT):
        {
            return float{};
        }

        case(VK_FORMAT_B10G11R11_UFLOAT_PACK32):
        case(VK_FORMAT_E5B9G9R9_UFLOAT_PACK32):
        {
            return std::uint32_t{};
        }

            //---------------------------------------
            // 48-bit

        case(VK_FORMAT_R16G16B16_SNORM):
        case(VK_FORMAT_R16G16B16_SSCALED):
        case(VK_FORMAT_R16G16B16_SINT):
        {
            return i16vec3{};
        }

        case(VK_FORMAT_R16G16B16_UNORM):
        case(VK_FORMAT_R16G16B16_USCALED):
        case(VK_FORMAT_R16G16B16_UINT):
        {
            return u16vec3{};
        }

        case(VK_FORMAT_R16G16B16_SFLOAT):
        {
            return u16vec3{}; // TODO: [C++23] use glm::vec<std::float16, 3>
        }

            //---------------------------------------
            // 64-bit

        case(VK_FORMAT_R16G16B16A16_UNORM):
        case(VK_FORMAT_R16G16B16A16_USCALED):
        case(VK_FORMAT_R16G16B16A16_UINT):
        {
            return u16vec4{};
        }

        case(VK_FORMAT_R16G16B16A16_SNORM):
        case(VK_FORMAT_R16G16B16A16_SSCALED):
        case(VK_FORMAT_R16G16B16A16_SINT):
        {
            return i16vec4{};
        }

        case(VK_FORMAT_R16G16B16A16_SFLOAT):
        {
            return u16vec4{}; // TODO: [C++23] use glm::vec<std::float16, 4>
        }

        case(VK_FORMAT_R32G32_UINT):
        {
            return u32vec2{};
        }

        case(VK_FORMAT_R32G32_SINT):
        {
            return i32vec2{};
        }

        case(VK_FORMAT_R32G32_SFLOAT):
        {
            return vec2{};
        }

        case(VK_FORMAT_R64_UINT):
        {
            return std::uint64_t{};
        }

        case(VK_FORMAT_R64_SINT):
        {
            return std::int64_t{};
        }

        case(VK_FORMAT_R64_SFLOAT):
        {
            return double{};
        }

            //---------------------------------------
            // 96-bit

        case(VK_FORMAT_R32G32B32_UINT):
        {
            return u32vec3{};
        }

        case(VK_FORMAT_R32G32B32_SINT):
        {
            return i32vec3{};
        }

        case(VK_FORMAT_R32G32B32_SFLOAT):
        {
            return vec3{};
        }

            //---------------------------------------
            // 128-bit

        case(VK_FORMAT_R32G32B32A32_UINT):
        {
            return u32vec4{};
        }

        case(VK_FORMAT_R32G32B32A32_SINT):
        {
            return i32vec4{};
        }

        case(VK_FORMAT_R32G32B32A32_SFLOAT):
        {
            return vec4{};
        }

        case(VK_FORMAT_R64G64_UINT):
        {
            return u64vec2{};
        }

        case(VK_FORMAT_R64G64_SINT):
        {
            return i64vec2{};
        }

        case(VK_FORMAT_R64G64_SFLOAT):
        {
            return dvec2{};
        }

            //---------------------------------------
            // 192-bit

        case(VK_FORMAT_R64G64B64_UINT):
        {
            return u64vec3{};
        }

        case(VK_FORMAT_R64G64B64_SINT):
        {
            return i64vec3{};
        }

        case(VK_FORMAT_R64G64B64_SFLOAT):
        {
            return dvec3{};
        }

            //---------------------------------------
            // 256-bit

        case(VK_FORMAT_R64G64B64A64_UINT):
        {
            return u64vec4{};
        }

        case(VK_FORMAT_R64G64B64A64_SINT):
        {
            return i64vec4{};
        }

        case(VK_FORMAT_R64G64B64A64_SFLOAT):
        {
            return dvec4{};
        }

            //---------------------------------------
            // D16

        case(VK_FORMAT_D16_UNORM):
        {
            return std::uint16_t{}; // TODO: [C++23] Use std::float16
        }

            //---------------------------------------
            // D24

        case(VK_FORMAT_X8_D24_UNORM_PACK32):
        {
            return std::uint32_t{};
        }

            //---------------------------------------
            // D32

        case(VK_FORMAT_D32_SFLOAT):
        {
            return float{};
        }

            //---------------------------------------
            // S8

        case(VK_FORMAT_S8_UINT):
        {
            return std::uint8_t{};
        }

            //---------------------------------------
            // D16S8

        case(VK_FORMAT_D16_UNORM_S8_UINT):
        {
            return std::span<const std::byte>{};
        }

            //---------------------------------------
            // D24S8

        case(VK_FORMAT_D24_UNORM_S8_UINT):
        {
            return std::span<const std::byte>{};
        }

            //---------------------------------------
            // D32S8

        case(VK_FORMAT_D32_SFLOAT_S8_UINT):
        {
            return std::span<const std::byte>{};
        }

            //---------------------------------------
            // BC1_RGB

        case(VK_FORMAT_BC1_RGB_UNORM_BLOCK):
        case(VK_FORMAT_BC1_RGB_SRGB_BLOCK):
        {
            return std::span<const std::byte>{};
        }

            //---------------------------------------
            // BC1_RGBA

        case(VK_FORMAT_BC1_RGBA_UNORM_BLOCK):
        case(VK_FORMAT_BC1_RGBA_SRGB_BLOCK):
        {
            return std::span<const std::byte>{};
        }

            //---------------------------------------
            // BC2

        case(VK_FORMAT_BC2_UNORM_BLOCK):
        case(VK_FORMAT_BC2_SRGB_BLOCK):
        {
            return std::span<const std::byte>{};
        }

            //---------------------------------------
            // BC3

        case(VK_FORMAT_BC3_UNORM_BLOCK):
        case(VK_FORMAT_BC3_SRGB_BLOCK):
        {
            return std::span<const std::byte>{};
        }

            //---------------------------------------
            // BC4

        case(VK_FORMAT_BC4_UNORM_BLOCK):
        case(VK_FORMAT_BC4_SNORM_BLOCK):
        {
            return std::span<const std::byte>{};
        }

            //---------------------------------------
            // BC5

        case(VK_FORMAT_BC5_UNORM_BLOCK):
        case(VK_FORMAT_BC5_SNORM_BLOCK):
        {
            return std::span<const std::byte>{};
        }

            //---------------------------------------
            // BC6H

        case(VK_FORMAT_BC6H_UFLOAT_BLOCK):
        case(VK_FORMAT_BC6H_SFLOAT_BLOCK):
        {
            return std::span<const std::byte>{};
        }

            //---------------------------------------
            // BC7

        case(VK_FORMAT_BC7_UNORM_BLOCK):
        case(VK_FORMAT_BC7_SRGB_BLOCK):
        {
            return std::span<const std::byte>{};
        }

            //---------------------------------------
            // ETC2_RGB

        case(VK_FORMAT_ETC2_R8G8B8_UNORM_BLOCK):
        case(VK_FORMAT_ETC2_R8G8B8_SRGB_BLOCK):
        {
            return std::span<const std::byte>{};
        }

            //---------------------------------------
            // ETC2_RGBA

        case(VK_FORMAT_ETC2_R8G8B8A1_UNORM_BLOCK):
        case(VK_FORMAT_ETC2_R8G8B8A1_SRGB_BLOCK):
        {
            return std::span<const std::byte>{};
        }

            //---------------------------------------
            // ETC2_EAC_RGBA

        case(VK_FORMAT_ETC2_R8G8B8A8_UNORM_BLOCK):
        case(VK_FORMAT_ETC2_R8G8B8A8_SRGB_BLOCK):
        {
            return std::span<const std::byte>{};
        }

            //---------------------------------------
            // EAC_R

        case(VK_FORMAT_EAC_R11_UNORM_BLOCK):
        case(VK_FORMAT_EAC_R11_SNORM_BLOCK):
        {
            return std::span<const std::byte>{};
        }

            //---------------------------------------
            // EAC_RG

        case(VK_FORMAT_EAC_R11G11_UNORM_BLOCK):
        case(VK_FORMAT_EAC_R11G11_SNORM_BLOCK):
        {
            return std::span<const std::byte>{};
        }

            //---------------------------------------
            // ASTC_4x4

        case(VK_FORMAT_ASTC_4x4_SFLOAT_BLOCK):
        case(VK_FORMAT_ASTC_4x4_UNORM_BLOCK):
        case(VK_FORMAT_ASTC_4x4_SRGB_BLOCK):
        {
            return std::span<const std::byte>{};
        }

            //---------------------------------------
            // ASTC_5x4

        case(VK_FORMAT_ASTC_5x4_SFLOAT_BLOCK):
        case(VK_FORMAT_ASTC_5x4_UNORM_BLOCK):
        case(VK_FORMAT_ASTC_5x4_SRGB_BLOCK):
        {
            return std::span<const std::byte>{};
        }

            //---------------------------------------
            // ASTC_5x5

        case(VK_FORMAT_ASTC_5x5_SFLOAT_BLOCK):
        case(VK_FORMAT_ASTC_5x5_UNORM_BLOCK):
        case(VK_FORMAT_ASTC_5x5_SRGB_BLOCK):
        {
            return std::span<const std::byte>{};
        }

            //---------------------------------------
            // ASTC_6x5

        case(VK_FORMAT_ASTC_6x5_SFLOAT_BLOCK):
        case(VK_FORMAT_ASTC_6x5_UNORM_BLOCK):
        case(VK_FORMAT_ASTC_6x5_SRGB_BLOCK):
        {
            return std::span<const std::byte>{};
        }

            //---------------------------------------
            // ASTC_6x6

        case(VK_FORMAT_ASTC_6x6_SFLOAT_BLOCK):
        case(VK_FORMAT_ASTC_6x6_UNORM_BLOCK):
        case(VK_FORMAT_ASTC_6x6_SRGB_BLOCK):
        {
            return std::span<const std::byte>{};
        }

            //---------------------------------------
            // ASTC_8x5

        case(VK_FORMAT_ASTC_8x5_SFLOAT_BLOCK):
        case(VK_FORMAT_ASTC_8x5_UNORM_BLOCK):
        case(VK_FORMAT_ASTC_8x5_SRGB_BLOCK):
        {
            return std::span<const std::byte>{};
        }

            //---------------------------------------
            // ASTC_8x6

        case(VK_FORMAT_ASTC_8x6_SFLOAT_BLOCK):
        case(VK_FORMAT_ASTC_8x6_UNORM_BLOCK):
        case(VK_FORMAT_ASTC_8x6_SRGB_BLOCK):
        {
            return std::span<const std::byte>{};
        }

            //---------------------------------------
            // ASTC_8x8

        case(VK_FORMAT_ASTC_8x8_SFLOAT_BLOCK):
        case(VK_FORMAT_ASTC_8x8_UNORM_BLOCK):
        case(VK_FORMAT_ASTC_8x8_SRGB_BLOCK):
        {
            return std::span<const std::byte>{};
        }

            //---------------------------------------
            // ASTC_10x5

        case(VK_FORMAT_ASTC_10x5_SFLOAT_BLOCK):
        case(VK_FORMAT_ASTC_10x5_UNORM_BLOCK):
        case(VK_FORMAT_ASTC_10x5_SRGB_BLOCK):
        {
            return std::span<const std::byte>{};
        }

            //---------------------------------------
            // ASTC_10x6

        case(VK_FORMAT_ASTC_10x6_SFLOAT_BLOCK):
        case(VK_FORMAT_ASTC_10x6_UNORM_BLOCK):
        case(VK_FORMAT_ASTC_10x6_SRGB_BLOCK):
        {
            return std::span<const std::byte>{};
        }

            //---------------------------------------
            // ASTC_10x8

        case(VK_FORMAT_ASTC_10x8_SFLOAT_BLOCK):
        case(VK_FORMAT_ASTC_10x8_UNORM_BLOCK):
        case(VK_FORMAT_ASTC_10x8_SRGB_BLOCK):
        {
            return std::span<const std::byte>{};
        }

            //---------------------------------------
            // ASTC_10x10

        case(VK_FORMAT_ASTC_10x10_SFLOAT_BLOCK):
        case(VK_FORMAT_ASTC_10x10_UNORM_BLOCK):
        case(VK_FORMAT_ASTC_10x10_SRGB_BLOCK):
        {
            return std::span<const std::byte>{};
        }

            //---------------------------------------
            // ASTC_12x10

        case(VK_FORMAT_ASTC_12x10_SFLOAT_BLOCK):
        case(VK_FORMAT_ASTC_12x10_UNORM_BLOCK):
        case(VK_FORMAT_ASTC_12x10_SRGB_BLOCK):
        {
            return std::span<const std::byte>{};
        }

            //---------------------------------------
            // ASTC_12x12

        case(VK_FORMAT_ASTC_12x12_SFLOAT_BLOCK):
        case(VK_FORMAT_ASTC_12x12_UNORM_BLOCK):
        case(VK_FORMAT_ASTC_12x12_SRGB_BLOCK):
        {
            return std::span<const std::byte>{};
        }

            //---------------------------------------
            // 32-bit G8B8G8R8

        case(VK_FORMAT_G8B8G8R8_422_UNORM):
        {
            return std::span<const std::byte>{};
        }

            //---------------------------------------
            // 32-bit B8G8R8G8

        case(VK_FORMAT_B8G8R8G8_422_UNORM):
        {
            return std::span<const std::byte>{};
        }

            //---------------------------------------
            // 8-bit 3-plane 420

        case(VK_FORMAT_G8_B8_R8_3PLANE_420_UNORM):
        {
            return std::span<const std::byte>{};
        }

            //---------------------------------------
            // 8-bit 2-plane 420

        case(VK_FORMAT_G8_B8R8_2PLANE_420_UNORM):
        {
            return std::span<const std::byte>{};
        }

            //---------------------------------------
            // 8-bit 3-plane 422

        case(VK_FORMAT_G8_B8_R8_3PLANE_422_UNORM):
        {
            return std::span<const std::byte>{};
        }

            //---------------------------------------
            // 8-bit 2-plane 422

        case(VK_FORMAT_G8_B8R8_2PLANE_422_UNORM):
        {
            return std::span<const std::byte>{};
        }

            //---------------------------------------
            // 8-bit 3-plane 444

        case(VK_FORMAT_G8_B8_R8_3PLANE_444_UNORM):
        {
            return std::span<const std::byte>{};
        }

            //---------------------------------------
            // 64-bit R10G10B10A10

        case(VK_FORMAT_R10X6G10X6B10X6A10X6_UNORM_4PACK16):
        {
            return std::span<const std::byte>{};
        }

            //---------------------------------------
            // 64-bit G10B10G10R10

        case(VK_FORMAT_G10X6B10X6G10X6R10X6_422_UNORM_4PACK16):
        {
            return std::span<const std::byte>{};
        }

            //---------------------------------------
            // 64-bit B10G10R10G10

        case(VK_FORMAT_B10X6G10X6R10X6G10X6_422_UNORM_4PACK16):
        {
            return std::span<const std::byte>{};
        }

            //---------------------------------------
            // 10-bit 3-plane 420

        case(VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_420_UNORM_3PACK16):
        {
            return std::span<const std::byte>{};
        }

            //---------------------------------------
            // 10-bit 2-plane 420

        case(VK_FORMAT_G10X6_B10X6R10X6_2PLANE_420_UNORM_3PACK16):
        {
            return std::span<const std::byte>{};
        }

            //---------------------------------------
            // 10-bit 3-plane 422

        case VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_422_UNORM_3PACK16:
        {
            return std::span<const std::byte>{};
        }

            //---------------------------------------
            // 10-bit 2-plane 422

        case(VK_FORMAT_G10X6_B10X6R10X6_2PLANE_422_UNORM_3PACK16):
        {
            return std::span<const std::byte>{};
        }

            //---------------------------------------
            // 10-bit 3-plane 444

        case(VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_444_UNORM_3PACK16):
        {
            return std::span<const std::byte>{};
        }

            //---------------------------------------
            // 64-bit R12G12B12A12

        case(VK_FORMAT_R12X4G12X4B12X4A12X4_UNORM_4PACK16):
        {
            return std::span<const std::byte>{};
        }

            //---------------------------------------
            // 64-bit G12B12G12R12

        case(VK_FORMAT_G12X4B12X4G12X4R12X4_422_UNORM_4PACK16):
        {
            return std::span<const std::byte>{};
        }

            //---------------------------------------
            // 64-bit B12G12R12G12

        case(VK_FORMAT_B12X4G12X4R12X4G12X4_422_UNORM_4PACK16):
        {
            return std::span<const std::byte>{};
        }

            //---------------------------------------
            // 12-bit 3-plane 420

        case(VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_420_UNORM_3PACK16):
        {
            return std::span<const std::byte>{};
        }

            //---------------------------------------
            // 12-bit 2-plane 420

        case(VK_FORMAT_G12X4_B12X4R12X4_2PLANE_420_UNORM_3PACK16):
        {
            return std::span<const std::byte>{};
        }

            //---------------------------------------
            // 12-bit 3-plane 422

        case(VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_422_UNORM_3PACK16):
        {
            return std::span<const std::byte>{};
        }

            //---------------------------------------
            // 12-bit 2-plane 422

        case(VK_FORMAT_G12X4_B12X4R12X4_2PLANE_422_UNORM_3PACK16):
        {
            return std::span<const std::byte>{};
        }

            //---------------------------------------
            // 12-bit 3-plane 444

        case(VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_444_UNORM_3PACK16):
        {
            return std::span<const std::byte>{};
        }

            //---------------------------------------
            // 64-bit G16B16G16R16

        case(VK_FORMAT_G16B16G16R16_422_UNORM):
        {
            return std::span<const std::byte>{};
        }

            //---------------------------------------
            // 64-bit B16G16R16G16

        case(VK_FORMAT_B16G16R16G16_422_UNORM):
        {
            return std::span<const std::byte>{};
        }

            //---------------------------------------
            // 16-bit 3-plane 420

        case(VK_FORMAT_G16_B16_R16_3PLANE_420_UNORM):
        {
            return std::span<const std::byte>{};
        }

            //---------------------------------------
            // 16-bit 2-plane 420

        case(VK_FORMAT_G16_B16R16_2PLANE_420_UNORM):
        {
            return std::span<const std::byte>{};
        }

            //---------------------------------------
            // 16-bit 3-plane 422

        case(VK_FORMAT_G16_B16_R16_3PLANE_422_UNORM):
        {
            return std::span<const std::byte>{};
        }

            //---------------------------------------
            // 16-bit 2-plane 422

        case(VK_FORMAT_G16_B16R16_2PLANE_422_UNORM):
        {
            return std::span<const std::byte>{};
        }

            //---------------------------------------
            // 16-bit 3-plane 444

        case(VK_FORMAT_G16_B16_R16_3PLANE_444_UNORM):
        {
            return std::span<const std::byte>{};
        }

            //---------------------------------------
            // 8-bit 2-plane 444

        case(VK_FORMAT_G8_B8R8_2PLANE_444_UNORM):
        {
            return std::span<const std::byte>{};
        }

            //---------------------------------------
            // 10-bit 2-plane 444

        case(VK_FORMAT_G10X6_B10X6R10X6_2PLANE_444_UNORM_3PACK16):
        {
            return std::span<const std::byte>{};
        }

            //---------------------------------------
            // 12-bit 2-plane 444

        case(VK_FORMAT_G12X4_B12X4R12X4_2PLANE_444_UNORM_3PACK16):
        {
            return std::span<const std::byte>{};
        }

            //---------------------------------------
            // 16-bit 2-plane 444

        case(VK_FORMAT_G16_B16R16_2PLANE_444_UNORM):
        {
            return std::span<const std::byte>{};
        }

        //---------------------------------------
        // PVRTC formats

#if defined(VK_IMG_format_pvrtc)
        case(VK_FORMAT_PVRTC1_2BPP_UNORM_BLOCK_IMG):
        case(VK_FORMAT_PVRTC1_4BPP_UNORM_BLOCK_IMG):
        case(VK_FORMAT_PVRTC2_2BPP_UNORM_BLOCK_IMG):
        case(VK_FORMAT_PVRTC2_4BPP_UNORM_BLOCK_IMG):
        case(VK_FORMAT_PVRTC1_2BPP_SRGB_BLOCK_IMG):
        case(VK_FORMAT_PVRTC1_4BPP_SRGB_BLOCK_IMG):
        case(VK_FORMAT_PVRTC2_2BPP_SRGB_BLOCK_IMG):
        case(VK_FORMAT_PVRTC2_4BPP_SRGB_BLOCK_IMG):
        {
            return std::span<const std::byte>{};
        }
#endif // defined(VK_IMG_format_pvrtc)

        //---------------------------------------
        // VK_NV_optical_flow

#if defined(VK_NV_optical_flow)
        case(VK_FORMAT_R16G16_S10_5_NV):
        {
            return u16vec2{};
        }
#endif // defined(VK_NV_optical_flow)

            //---------------------------------------
            // Invalid values

        default:
        case(VK_FORMAT_UNDEFINED):
        case(VK_FORMAT_MAX_ENUM):
        {
            return std::span<const std::byte>{};
        }
    }
    // NOLINTEND(bugprone-branch-clone)
}

//------------------------------------------------------------------------------

[[nodiscard]] FUBUKI_FUYU_API any_storage storage_for(VkFormat f, std::size_t size = 0) noexcept(false);

[[nodiscard]] FUBUKI_FUYU_API any_storage storage_for(VkFormat f, std::size_t size, any_storage_element initial) noexcept;

//------------------------------------------------------------------------------

} // namespace fubuki::fuyu::detail

#endif // FUBUKI_FUYU_DETAIL_FORMATTED_STORAGE_HPP
