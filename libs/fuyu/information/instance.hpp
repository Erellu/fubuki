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

#ifndef FUBUKI_FUYU_INFORMATION_INSTANCE_HPP
#define FUBUKI_FUYU_INFORMATION_INSTANCE_HPP

#include <optional>
#include <string>

#include <core/future/flat_set.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

#include "fuyu/information/callbacks.hpp"

namespace fubuki::fuyu::information
{

/// Information required to construct an instance of fuyu::instance.
/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/VkInstanceCreateInfo.html
struct instance
{
    /// Application information.
    struct app_info_type
    {
        /// Developper engine info.
        struct engine_info
        {
            std::string    name    = "<Unnamed engine>"; ///< Engine name.
            version_number version = {};                 ///< Engine version.

            [[nodiscard]] friend constexpr bool operator==(const engine_info& a, const engine_info& b) noexcept  = default;
            [[nodiscard]] friend constexpr bool operator!=(const engine_info& a, const engine_info& b) noexcept  = default;
            [[nodiscard]] friend constexpr auto operator<=>(const engine_info& a, const engine_info& b) noexcept = default;
        };

        std::string    name           = "<Unnamed application>"; ///< Application name.
        version_number version        = {};                      ///< Application version.
        version_number vulkan_version = {1, 4, 0};               ///< Highest version of Vulkan the application is designed to use.
        engine_info    engine         = {};                      ///< Engine information.

        [[nodiscard]] friend constexpr bool operator==(const app_info_type& a, const app_info_type& b) noexcept  = default;
        [[nodiscard]] friend constexpr bool operator!=(const app_info_type& a, const app_info_type& b) noexcept  = default;
        [[nodiscard]] friend constexpr auto operator<=>(const app_info_type& a, const app_info_type& b) noexcept = default;
    };

    /// Additional information required by the constructor but not kept for the lifetime of the object.
    struct complements
    {
        small_flat_set<std::string> layers     = {}; ///< Layers enabled for this application.
        small_flat_set<std::string> extensions = {}; ///< Instance extensions.

        [[nodiscard]] friend constexpr bool operator==(const complements& a, const complements& b) noexcept  = default;
        [[nodiscard]] friend constexpr bool operator!=(const complements& a, const complements& b) noexcept  = default;
        [[nodiscard]] friend constexpr auto operator<=>(const complements& a, const complements& b) noexcept = default;
    };

    app_info_type         application = {}; ///< Application information.
    VkInstanceCreateFlags flags       = {}; ///< Instance flags.

    std::optional<creation_callback> callbacks = {}; ///< (optional) Allocation callbacks.

    [[nodiscard]] friend constexpr bool operator==(const instance& a, const instance& b) noexcept = default;
    [[nodiscard]] friend constexpr bool operator!=(const instance& a, const instance& b) noexcept = default;
};

} // namespace fubuki::fuyu::information

#endif // FUBUKI_FUYU_INFORMATION_INSTANCE_HPP
