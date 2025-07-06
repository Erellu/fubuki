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

#ifndef FUBUKI_FUYU_SAMPLING_RATE_HPP
#define FUBUKI_FUYU_SAMPLING_RATE_HPP

#include <array>
#include <variant>

#include <core/vulkan.hpp>

/// Types specifying the sampling rate for multisampling facilities.
namespace fubuki::fuyu::sampling_rate
{

/// Indicates there will be only one  sample per fragment (no multisampling).
struct sample_1
{
    static constexpr auto vk = VK_SAMPLE_COUNT_1_BIT;

    [[nodiscard]] friend constexpr bool operator==(const sample_1& a, const sample_1& b) noexcept  = default;
    [[nodiscard]] friend constexpr bool operator!=(const sample_1& a, const sample_1& b) noexcept  = default;
    [[nodiscard]] friend constexpr auto operator<=>(const sample_1& a, const sample_1& b) noexcept = default;
};

/// Indicates there will be two samples per fragment.
struct sample_2
{
    static constexpr auto vk = VK_SAMPLE_COUNT_2_BIT;

    [[nodiscard]] friend constexpr bool operator==(const sample_2& a, const sample_2& b) noexcept  = default;
    [[nodiscard]] friend constexpr bool operator!=(const sample_2& a, const sample_2& b) noexcept  = default;
    [[nodiscard]] friend constexpr auto operator<=>(const sample_2& a, const sample_2& b) noexcept = default;
};

/// Indicates there will be four samples per fragment.
struct sample_4
{
    static constexpr auto vk = VK_SAMPLE_COUNT_4_BIT;

    [[nodiscard]] friend constexpr bool operator==(const sample_4& a, const sample_4& b) noexcept  = default;
    [[nodiscard]] friend constexpr bool operator!=(const sample_4& a, const sample_4& b) noexcept  = default;
    [[nodiscard]] friend constexpr auto operator<=>(const sample_4& a, const sample_4& b) noexcept = default;
};

/// Indicates there will be eight samples per fragment.
struct sample_8
{
    static constexpr auto vk = VK_SAMPLE_COUNT_8_BIT;

    [[nodiscard]] friend constexpr bool operator==(const sample_8& a, const sample_8& b) noexcept  = default;
    [[nodiscard]] friend constexpr bool operator!=(const sample_8& a, const sample_8& b) noexcept  = default;
    [[nodiscard]] friend constexpr auto operator<=>(const sample_8& a, const sample_8& b) noexcept = default;
};

/// Indicates there will be sixteen samples per fragment.
struct sample_16
{
    static constexpr auto vk = VK_SAMPLE_COUNT_16_BIT;

    [[nodiscard]] friend constexpr bool operator==(const sample_16& a, const sample_16& b) noexcept  = default;
    [[nodiscard]] friend constexpr bool operator!=(const sample_16& a, const sample_16& b) noexcept  = default;
    [[nodiscard]] friend constexpr auto operator<=>(const sample_16& a, const sample_16& b) noexcept = default;
};

/// Indicates there will be thirty-two samples per fragment.
struct sample_32
{
    static constexpr auto vk = VK_SAMPLE_COUNT_32_BIT;

    std::array<VkSampleMask, 1> mask = {}; ///< The sample mask.

    [[nodiscard]] friend constexpr bool operator==(const sample_32& a, const sample_32& b) noexcept  = default;
    [[nodiscard]] friend constexpr bool operator!=(const sample_32& a, const sample_32& b) noexcept  = default;
    [[nodiscard]] friend constexpr auto operator<=>(const sample_32& a, const sample_32& b) noexcept = default;
};

/// Indicates there will be sixty-four samples per fragment.
struct sample_64
{
    static constexpr auto vk = VK_SAMPLE_COUNT_64_BIT;

    std::array<VkSampleMask, 2> mask = {}; ///< The two sample masks.

    [[nodiscard]] friend constexpr bool operator==(const sample_64& a, const sample_64& b) noexcept  = default;
    [[nodiscard]] friend constexpr bool operator!=(const sample_64& a, const sample_64& b) noexcept  = default;
    [[nodiscard]] friend constexpr auto operator<=>(const sample_64& a, const sample_64& b) noexcept = default;
};

/// Any sampling rate. Use this to specify the sampling rate of a graphics pipeline.
using any = std::variant<sample_1, sample_2, sample_4, sample_8, sample_16, sample_32, sample_64>;

} // namespace fubuki::fuyu::sampling_rate

#endif // FUBUKI_FUYU_SAMPLING_RATE_HPP
