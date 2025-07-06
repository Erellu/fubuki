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

#ifndef FUBUKI_FUYU_INFORMATION_SAMPLER_HPP
#define FUBUKI_FUYU_INFORMATION_SAMPLER_HPP

#include <functional>
#include <optional>
#include <string>

#include <core/structure_type.hpp>
#include <core/vulkan.hpp>

#include "fuyu/information/callbacks.hpp"

namespace fubuki::fuyu::information
{

/// Information required to create an instance of fuyu::sampler.
/// https://registry.khronos.org/vulkan/specs/1.3-extensions/man/html/VkSamplerCreateInfo.html
struct sampler
{
    using underlying_type = VkSamplerCreateInfo;

    struct filtering
    {
        VkFilter mag = {}; ///< Magnification filter to apply to lookups.
        VkFilter min = {}; ///< Minification  filter to apply to lookups

        [[nodiscard]] friend constexpr bool operator==(const filtering& a, const filtering& b) noexcept  = default;
        [[nodiscard]] friend constexpr bool operator!=(const filtering& a, const filtering& b) noexcept  = default;
        [[nodiscard]] friend constexpr auto operator<=>(const filtering& a, const filtering& b) noexcept = default;
    };

#if defined(__clang__)
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wfloat-equal"
#elif defined(__GNUC__)
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wfloat-equal"
#endif

    struct mipmapping
    {
        VkSamplerMipmapMode mode     = {}; ///< The mipmap filter to apply to lookups.
        float               lod_bias = {}; ///< The bias to be added to mipmap LOD calculation and bias provided by image sampling functions.

        [[nodiscard]] friend constexpr bool operator==(const mipmapping& a, const mipmapping& b) noexcept  = default;
        [[nodiscard]] friend constexpr bool operator!=(const mipmapping& a, const mipmapping& b) noexcept  = default;
        [[nodiscard]] friend constexpr auto operator<=>(const mipmapping& a, const mipmapping& b) noexcept = default;
    };

    struct address
    {
        VkSamplerAddressMode u = {}; ///< Addressing mode for U coordinates outside [0,1).
        VkSamplerAddressMode v = {}; ///< Addressing mode for V coordinates outside [0,1).
        VkSamplerAddressMode w = {}; ///< Addressing mode for W coordinates outside [0,1).

        [[nodiscard]] friend constexpr bool operator==(const address& a, const address& b) noexcept  = default;
        [[nodiscard]] friend constexpr bool operator!=(const address& a, const address& b) noexcept  = default;
        [[nodiscard]] friend constexpr auto operator<=>(const address& a, const address& b) noexcept = default;
    };

    struct aniso
    {
        bool  enable = {}; ///< Toggle anisotropy filtering.
        float max    = {}; ///< Anisotropy value clamp used by the sampler (only used when enable is true).

        [[nodiscard]] friend constexpr bool operator==(const aniso& a, const aniso& b) noexcept  = default;
        [[nodiscard]] friend constexpr bool operator!=(const aniso& a, const aniso& b) noexcept  = default;
        [[nodiscard]] friend constexpr auto operator<=>(const aniso& a, const aniso& b) noexcept = default;
    };

    struct level_of_detail
    {
        float min = {}; ///< Indicates how to clamp the minimum of the computed LOD value.
        float max = {}; ///< Indicates how to clamp the maximum of the computed LOD value. To avoid clamping the maximum value, set maxLod to the
                        ///< constant VK_LOD_CLAMP_NONE.

        [[nodiscard]] friend constexpr bool operator==(const level_of_detail& a, const level_of_detail& b) noexcept  = default;
        [[nodiscard]] friend constexpr bool operator!=(const level_of_detail& a, const level_of_detail& b) noexcept  = default;
        [[nodiscard]] friend constexpr auto operator<=>(const level_of_detail& a, const level_of_detail& b) noexcept = default;
    };

#if defined(__clang__)
    #pragma clang diagnostic pop
#elif defined(__GNUC__)
    #pragma GCC diagnostic pop)
#endif

    struct comparison
    {
        bool        enable = {}; ///< Enables comparison against a reference value during lookups.
        VkCompareOp op     = {}; ///< The comparison operator to apply to fetched data before filtering.

        [[nodiscard]] friend constexpr bool operator==(const comparison& a, const comparison& b) noexcept  = default;
        [[nodiscard]] friend constexpr bool operator!=(const comparison& a, const comparison& b) noexcept  = default;
        [[nodiscard]] friend constexpr auto operator<=>(const comparison& a, const comparison& b) noexcept = default;
    };

    VkSamplerCreateFlags flags      = {}; ///< Flags.
    filtering            filter     = {}; ///< Filtering settings.
    mipmapping           mipmap     = {}; ///< Mipmap settings.
    address              addressing = {}; ///< Addressing settings.
    aniso                anisotropy = {}; ///< Anisotropy settings.
    comparison           compare    = {}; ///< Compare operation settings.
    level_of_detail      lod        = {}; ///< Level of detail settings.
    VkBorderColor        border     = {}; ///< The predefined border colour to use.
    bool unnormalised_coordinates   = {}; ///< Controls whether to use unnormalized or normalized texel coordinates to address texels of the image.

    std::optional<creation_callback> callbacks = {}; ///< Callbacks.
    std::optional<std::string>       name      = {}; ///< (optional) Name passed to debug markers.

    [[nodiscard]] friend constexpr bool operator==(const sampler& a, const sampler& b) noexcept = default;
    [[nodiscard]] friend constexpr bool operator!=(const sampler& a, const sampler& b) noexcept = default;

    [[nodiscard]] friend constexpr underlying_type to_underlying(std::reference_wrapper<const sampler> cref) noexcept
    {
        // Avoids having to introduce deleted overloads for temporaries
        const auto& s = cref.get();

        return {
            .sType                   = structure_type_v<underlying_type>,
            .pNext                   = nullptr,
            .flags                   = s.flags,
            .magFilter               = s.filter.mag,
            .minFilter               = s.filter.min,
            .mipmapMode              = s.mipmap.mode,
            .addressModeU            = s.addressing.u,
            .addressModeV            = s.addressing.v,
            .addressModeW            = s.addressing.w,
            .mipLodBias              = s.mipmap.lod_bias,
            .anisotropyEnable        = s.anisotropy.enable,
            .maxAnisotropy           = s.anisotropy.max,
            .compareEnable           = s.compare.enable,
            .compareOp               = s.compare.op,
            .minLod                  = s.lod.min,
            .maxLod                  = s.lod.max,
            .borderColor             = s.border,
            .unnormalizedCoordinates = s.unnormalised_coordinates,
        };
    }
};

} // namespace fubuki::fuyu::information

#endif // FUBUKI_FUYU_INFORMATION_SAMPLER_HPP
