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

#include <gtest/gtest.h>

#include <core/collect.hpp>
#include <core/handle.hpp>

#define STATIC_EXPECT_TRUE(x) \
    static_assert((x));       \
    EXPECT_TRUE((x))

namespace
{

TEST(collect, vk_size)
{
    // Free variable
    {
        // std::size_t
        {
            constexpr std::size_t a_size    = 2562;
            constexpr auto        a_size_vk = fubuki::vk_size(a_size);

            using a_vk_size_t = std::decay_t<decltype(a_size_vk)>;

            STATIC_EXPECT_TRUE((std::is_same_v<a_vk_size_t, std::uint32_t>) );
            STATIC_EXPECT_TRUE((static_cast<std::size_t>(a_size_vk) == a_size));
        }

        // struct convertible to std::size_t
        {
            struct foo
            {
                [[nodiscard]] constexpr operator std::size_t() const noexcept { return 32u; }
            };

            constexpr foo  b_size    = {};
            constexpr auto b_size_vk = fubuki::vk_size(b_size);

            using b_size_vk_t = std::decay_t<decltype(b_size_vk)>;

            STATIC_EXPECT_TRUE((std::is_same_v<b_size_vk_t, std::uint32_t>) );
            STATIC_EXPECT_TRUE((static_cast<std::size_t>(b_size_vk) == b_size));
        }
    }

    // Container
    {
        constexpr std::array array     = {1, 2, 3, 4, 5};
        constexpr auto       a_vk_size = fubuki::vk_size(array);

        using a_vk_size_t = std::decay_t<decltype(a_vk_size)>;

        STATIC_EXPECT_TRUE((std::is_same_v<a_vk_size_t, std::uint32_t>) );
        STATIC_EXPECT_TRUE((static_cast<std::size_t>(a_vk_size) == array.size()));
    }
}

TEST(collect, host_size)
{
    // Free variable
    {
        // std::size_t
        {
            constexpr std::uint32_t a_vk_size   = 2562;
            constexpr auto          a_size_host = fubuki::host_size(a_vk_size);

            using a_size_host_t = std::decay_t<decltype(a_size_host)>;

            STATIC_EXPECT_TRUE((std::is_same_v<a_size_host_t, std::size_t>) );
            STATIC_EXPECT_TRUE((static_cast<std::uint32_t>(a_size_host) == a_vk_size));
        }

        // struct convertible to std::uint32_t
        {
            struct foo
            {
                [[nodiscard]] constexpr operator std::uint32_t() const noexcept { return 32u; }
            };

            constexpr foo  b_size_vk   = {};
            constexpr auto b_size_host = fubuki::host_size(b_size_vk);

            using b_size_host_t = std::decay_t<decltype(b_size_host)>;

            STATIC_EXPECT_TRUE((std::is_same_v<b_size_host_t, std::size_t>) );
            STATIC_EXPECT_TRUE((static_cast<std::uint32_t>(b_size_host) == b_size_vk));
        }
    }

    // Container
    {
        constexpr std::array array     = {1, 2, 3, 4, 5};
        constexpr auto       a_vk_size = fubuki::host_size(array);

        using a_vk_size_t = std::decay_t<decltype(a_vk_size)>;

        STATIC_EXPECT_TRUE((std::is_same_v<a_vk_size_t, std::size_t>) );
        STATIC_EXPECT_TRUE((static_cast<std::size_t>(a_vk_size) == array.size()));
    }
}

TEST(collect, device_size)
{
    // Free variable
    {
        // std::size_t
        {
            constexpr std::uint64_t a_vk_size   = 2562;
            constexpr auto          a_size_host = fubuki::device_size(a_vk_size);

            using a_size_host_t = std::decay_t<decltype(a_size_host)>;

            STATIC_EXPECT_TRUE((std::is_same_v<a_size_host_t, std::size_t>) );
            STATIC_EXPECT_TRUE((static_cast<std::uint64_t>(a_size_host) == a_vk_size));
        }

        // struct convertible to std::uint64_t
        {
            struct foo
            {
                [[nodiscard]] constexpr operator std::uint64_t() const noexcept { return 64u; }
            };

            constexpr foo  b_size_vk   = {};
            constexpr auto b_size_host = fubuki::device_size(b_size_vk);

            using b_size_host_t = std::decay_t<decltype(b_size_host)>;

            STATIC_EXPECT_TRUE((std::is_same_v<b_size_host_t, std::size_t>) );
            STATIC_EXPECT_TRUE((static_cast<std::uint64_t>(b_size_host) == b_size_vk));
        }
    }

    // Container
    {
        constexpr std::array array     = {1, 2, 3, 4, 5};
        constexpr auto       a_vk_size = fubuki::device_size(array);

        using a_vk_size_t = std::decay_t<decltype(a_vk_size)>;

        STATIC_EXPECT_TRUE((std::is_same_v<a_vk_size_t, std::size_t>) );
        STATIC_EXPECT_TRUE((static_cast<std::size_t>(a_vk_size) == array.size()));
    }
}

TEST(collect, handles)
{
    // std::convertible_to
    {
        struct convertible
        {
            fubuki::buffer_handle buffer;

            [[nodiscard]] constexpr operator VkBuffer() const noexcept { return buffer.vk; }
        };

        // Fixed range
        {
            // Generate garbage handles for the purpose of testing
            const std::array handles = {
                convertible{fubuki::buffer_handle{reinterpret_cast<VkBuffer>(678987ULL)}}, // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
                convertible{fubuki::buffer_handle{reinterpret_cast<VkBuffer>(545616ULL)}}, // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
                convertible{fubuki::buffer_handle{reinterpret_cast<VkBuffer>(543252ULL)}}, // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
            };

            const std::span as_span = handles;

            const auto vk_handles = fubuki::collect<VkBuffer>(as_span);

            EXPECT_EQ(handles.size(), vk_handles.size());

            for(std::size_t i = 0; i < handles.size(); ++i)
            {
                EXPECT_EQ(handles[i].buffer.vk, vk_handles[i]); // NOLINT(cppcoreguidelines-pro-bounds-constant-array-index)
            }
        }

        // Dynamic range
        {
            // Generate garbage handles for the purpose of testing
            const std::vector handles = {
                convertible{fubuki::buffer_handle{reinterpret_cast<VkBuffer>(256481ULL)}}, // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
                convertible{fubuki::buffer_handle{reinterpret_cast<VkBuffer>(145544ULL)}}, // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
                convertible{fubuki::buffer_handle{reinterpret_cast<VkBuffer>(488562ULL)}}, // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
            };

            const std::span as_span = handles;

            const auto vk_handles = fubuki::collect<VkBuffer>(as_span);

            EXPECT_EQ(handles.size(), vk_handles.size());

            for(std::size_t i = 0; i < handles.size(); ++i)
            {
                EXPECT_EQ(handles[i].buffer.vk, vk_handles[i]); // NOLINT(cppcoreguidelines-pro-bounds-constant-array-index)
            }
        }
    }

    // .handle.vk
    {
        struct wrapper
        {
            fubuki::buffer_handle handle;
        };

        // Fixed range
        {
            // Generate garbage handles for the purpose of testing
            const std::array handles = {
                wrapper{fubuki::buffer_handle{reinterpret_cast<VkBuffer>(678987ULL)}}, // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
                wrapper{fubuki::buffer_handle{reinterpret_cast<VkBuffer>(545616ULL)}}, // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
                wrapper{fubuki::buffer_handle{reinterpret_cast<VkBuffer>(543252ULL)}}, // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
            };

            const std::span as_span = handles;

            const auto vk_handles = fubuki::collect<VkBuffer>(as_span);

            EXPECT_EQ(handles.size(), vk_handles.size());

            for(std::size_t i = 0; i < handles.size(); ++i)
            {
                EXPECT_EQ(handles[i].handle.vk, vk_handles[i]); // NOLINT(cppcoreguidelines-pro-bounds-constant-array-index)
            }
        }

        // Dynamic range
        {
            // Generate garbage handles for the purpose of testing
            const std::vector handles = {
                wrapper{fubuki::buffer_handle{reinterpret_cast<VkBuffer>(256481ULL)}}, // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
                wrapper{fubuki::buffer_handle{reinterpret_cast<VkBuffer>(145544ULL)}}, // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
                wrapper{fubuki::buffer_handle{reinterpret_cast<VkBuffer>(488562ULL)}}, // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
            };

            const std::span as_span = handles;

            const auto vk_handles = fubuki::collect<VkBuffer>(as_span);

            EXPECT_EQ(handles.size(), vk_handles.size());

            for(std::size_t i = 0; i < handles.size(); ++i)
            {
                EXPECT_EQ(handles[i].handle.vk, vk_handles[i]); // NOLINT(cppcoreguidelines-pro-bounds-constant-array-index)
            }
        }
    }

    // .handle()
    {
        struct accessible
        {
            fubuki::image_handle image;

            [[nodiscard]] constexpr fubuki::image_handle handle() const noexcept { return image; }
        };

        // Fixed range
        {
            // Generate garbage handles for the purpose of testing
            const std::array handles = {
                accessible{fubuki::image_handle{reinterpret_cast<VkImage>(678917ULL)}}, // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
                accessible{fubuki::image_handle{reinterpret_cast<VkImage>(521498ULL)}}, // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
                accessible{fubuki::image_handle{reinterpret_cast<VkImage>(816553ULL)}}, // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
            };

            const std::span as_span = handles;

            const auto vk_handles = fubuki::collect<VkImage>(as_span);

            EXPECT_EQ(handles.size(), vk_handles.size());

            for(std::size_t i = 0; i < handles.size(); ++i)
            {
                EXPECT_EQ(handles[i].handle().vk, vk_handles[i]); // NOLINT(cppcoreguidelines-pro-bounds-constant-array-index)
            }
        }

        // Dynamic range
        {
            // Generate garbage handles for the purpose of testing
            const std::vector handles = {
                accessible{fubuki::image_handle{reinterpret_cast<VkImage>(1514541ULL)}}, // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
                accessible{fubuki::image_handle{reinterpret_cast<VkImage>(5641354ULL)}}, // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
                accessible{fubuki::image_handle{reinterpret_cast<VkImage>(1515786ULL)}}, // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
            };

            const std::span as_span = handles;

            const auto vk_handles = fubuki::collect<VkImage>(as_span);

            EXPECT_EQ(handles.size(), vk_handles.size());

            for(std::size_t i = 0; i < handles.size(); ++i)
            {
                EXPECT_EQ(handles[i].handle().vk, vk_handles[i]);
            }
        }
    }
}

} // anonymous namespace

#undef STATIC_EXPECT_TRUE
