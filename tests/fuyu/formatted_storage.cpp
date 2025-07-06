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

#include <array>
#include <ranges>

#include <gtest/gtest.h>

#include <core/vulkan.hpp>
#include <fuyu/formatted_storage.hpp>

namespace
{

using namespace fubuki;

using byte_span = std::span<const std::byte>;
using fuyu::detail::any_storage_element;

struct format
{
    VkFormat            id      = {};
    any_storage_element storage = {};
};

// Only test the most common... For now
// We disable the tests using glm types for MinGW-gcc: for some reason, this compiler goes wild when compiling this (makes by 64GB config swap)
// I am not sure I understand why this occurs... This looks like a compiler bug.
constexpr std::array formats = {
    format{VK_FORMAT_R8_UINT,             std::uint8_t{1} },
    format{VK_FORMAT_R16_UINT,            std::uint16_t{2}},
    format{VK_FORMAT_R32_UINT,            std::uint32_t{3}},
    format{VK_FORMAT_R64_UINT,            std::uint64_t{4}},
    format{VK_FORMAT_R8_UNORM,            std::uint8_t{5} },
    format{VK_FORMAT_R8_SINT,             std::int8_t{6}  },
    format{VK_FORMAT_R16_SINT,            std::int16_t{7} },
    format{VK_FORMAT_R32_SINT,            std::int32_t{8} },
    format{VK_FORMAT_R64_SINT,            std::int64_t{9} },
    format{VK_FORMAT_R8_SNORM,            std::int8_t{10} },
    format{VK_FORMAT_R32_SFLOAT,          float{11}       },
    format{VK_FORMAT_R64_SFLOAT,          double{12}      },

#if not defined(__MINGW32__) or (defined(__MINGW32__) and defined(__clang__))
    format{VK_FORMAT_R8G8_UINT,           u8vec2{13}      },
    format{VK_FORMAT_R16G16_UINT,         u16vec2{14}     },
    format{VK_FORMAT_R32G32_UINT,         u32vec2{15}     },
    format{VK_FORMAT_R64G64_UINT,         u64vec2{16}     },
    format{VK_FORMAT_R8G8_SINT,           i8vec2{17}      },
    format{VK_FORMAT_R16G16_SINT,         i16vec2{18}     },
    format{VK_FORMAT_R32G32_SINT,         i32vec2{19}     },
    format{VK_FORMAT_R64G64_SINT,         i64vec2{20}     },
    format{VK_FORMAT_R32G32_SFLOAT,       vec2{21}        },
    format{VK_FORMAT_R64G64_SFLOAT,       dvec2{22}       },

    format{VK_FORMAT_R8G8B8_UINT,         u8vec3{23}      },
    format{VK_FORMAT_R16G16B16_UINT,      u16vec3{24}     },
    format{VK_FORMAT_R32G32B32_UINT,      u32vec3{25}     },
    format{VK_FORMAT_R64G64B64_UINT,      u64vec3{26}     },
    format{VK_FORMAT_R8G8B8_SINT,         i8vec3{27}      },
    format{VK_FORMAT_R16G16B16_SINT,      i16vec3{28}     },
    format{VK_FORMAT_R32G32B32_SINT,      i32vec3{29}     },
    format{VK_FORMAT_R64G64B64_SINT,      i64vec3{30}     },
    format{VK_FORMAT_R32G32B32_SFLOAT,    vec3{31}        },
    format{VK_FORMAT_R64G64B64_SFLOAT,    dvec3{32}       },

    format{VK_FORMAT_R8G8B8A8_UINT,       u8vec4{33}      },
    format{VK_FORMAT_R16G16B16A16_UINT,   u16vec4{34}     },
    format{VK_FORMAT_R32G32B32A32_UINT,   u32vec4{35}     },
    format{VK_FORMAT_R64G64B64A64_UINT,   u64vec4{36}     },
    format{VK_FORMAT_R8G8B8A8_SINT,       i8vec4{37}      },
    format{VK_FORMAT_R16G16B16A16_SINT,   i16vec4{38}     },
    format{VK_FORMAT_R32G32B32A32_SINT,   i32vec4{39}     },
    format{VK_FORMAT_R64G64B64A64_SINT,   i64vec4{40}     },
    format{VK_FORMAT_R32G32B32A32_SFLOAT, vec4{41}        },
    format{VK_FORMAT_R64G64B64A64_SFLOAT, dvec4{42}       },
#endif  // #if (defined(__MINGW32__) and defined(__clang__))
    format{VK_FORMAT_D24_UNORM_S8_UINT,   byte_span{}     },
    format{VK_FORMAT_D32_SFLOAT_S8_UINT,  byte_span{}     },
    format{VK_FORMAT_BC1_RGB_UNORM_BLOCK, byte_span{}     }
};

TEST(formatted_storage, ctor)
{
    constexpr VkExtent3D extent        = {2, 2, 8};
    constexpr auto       element_count = extent.width * extent.height * extent.depth;

    for(const auto& format : formats)
    {

        // No initial extent, no initial value
        {
            fuyu::formatted_storage storage{format.id}; // NOLINT(misc-const-correctness): that's the purpose

            EXPECT_EQ(storage.format(), format.id);
            EXPECT_EQ(storage.extent().width, 0u);
            EXPECT_EQ(storage.extent().height, 0u);
            EXPECT_EQ(storage.extent().depth, 0u);
            EXPECT_EQ(storage.size(), 0u);
            EXPECT_TRUE(storage.empty());
        }

        // Initial extent, no initial value
        {
            fuyu::formatted_storage storage{
                {extent, format.id}
            };

            EXPECT_EQ(storage.format(), format.id);
            EXPECT_EQ(storage.extent().width, extent.width);
            EXPECT_EQ(storage.extent().height, extent.height);
            EXPECT_EQ(storage.extent().depth, extent.depth);
            EXPECT_EQ(storage.size(), element_count);
            EXPECT_FALSE(storage.empty());

            // Non-const returns a ref, which isn't the same type
            EXPECT_EQ(std::as_const(storage)[0].index(), format.storage.index()) << "Failure for VkFormat{" << format.id << "}";
        }

        // Initial extent, initial value
        {
            fuyu::formatted_storage storage{
                {extent, format.id},
                format.storage
            };

            const auto expected_fill_value = format.storage;

            // Cannot use operator== of std::variant, because std::span doesn't provide operator==
            const auto eq_visitor = [&, &fill = std::as_const(expected_fill_value)](const auto& inspected_value) noexcept -> bool
            {
                using inspected_value_type = std::decay_t<decltype(inspected_value)>;

                // Skip span<byte>
                if constexpr(std::is_same_v<inspected_value_type, byte_span>)
                {
                    return true;
                }
                else
                {
                    const auto visit_fill = [&](const auto& fill_v) noexcept -> bool
                    {
                        using fill_value_type = std::decay_t<decltype(fill_v)>;

                        if constexpr(std::is_same_v<fill_value_type, inspected_value_type>)
                        {
                            EXPECT_EQ(fill_v, inspected_value) << "Failure for VkFormat{" << format.id << "}";

                            // For some reason, this silences Wfloat-equal
                            return std::equal_to<fill_value_type>{}(fill_v, inspected_value);
                        }
                        else
                        {
                            return false;
                        }
                    };

                    return std::visit(visit_fill, fill);
                }
            };

            EXPECT_EQ(storage.format(), format.id);
            EXPECT_EQ(storage.extent().width, extent.width);
            EXPECT_EQ(storage.extent().height, extent.height);
            EXPECT_EQ(storage.extent().depth, extent.depth);
            EXPECT_EQ(storage.size(), element_count);
            EXPECT_FALSE(storage.empty());

            for(const auto i : std::views::iota(0u, storage.size()))
            {
                EXPECT_TRUE(std::visit(eq_visitor, std::as_const(storage)[i])) << "Failure for VkFormat{" << format.id << "} at i = " << i;
            }
        }
    }
}

} // anonymous namespace
