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

#ifndef FUBUKI_FUYU_INFORMATION_DEVICE_HPP
#define FUBUKI_FUYU_INFORMATION_DEVICE_HPP

#include <optional>

#include <core/compare/device_queue_global_priority_create_info.hpp>
#include <core/future/flat_set.hpp>
#include <core/handle.hpp>
#include <core/small_vector.hpp>
#include <core/string_literal.hpp>
#include <core/vulkan.hpp>

#include "fuyu/information/callbacks.hpp"

namespace fubuki::fuyu::information
{

/// Information required to create an instance of fuyu::device.
/// @see https://registry.khronos.org/vulkan/specs/1.3-extensions/man/html/VkDeviceCreateInfo.html
struct device
{
    /// Information about a queue.
    struct queue_info
    {
        VkQueueFlags             type     = {};   ///< Queue type.
        VkDeviceQueueCreateFlags flags    = {};   ///< Queue flags. Default is VkDeviceQueueCreateFlags{}.
        float                    priority = +0.f; ///< Queue priority. Default is 0.f.

        [[nodiscard]] friend constexpr bool operator==(const queue_info& a, const queue_info& b) noexcept = default;
        [[nodiscard]] friend constexpr bool operator!=(const queue_info& a, const queue_info& b) noexcept = default;
    };

    /// Additional information required by the constructor but not kept for the lifetime of the object.
    struct complements
    {
        small_vector<queue_info>    queues     = {}; ///< Queues to create.
        small_flat_set<std::string> extensions = {}; ///< Extensions to load.

#if defined(VK_KHR_surface)
        small_flat_set<surface_khr_handle> surfaces; ///< Surfaces this device will render to.
#endif                                               // if defined(VK_KHR_surface)s

        std::optional<VkPhysicalDeviceFeatures> features
            = {}; ///< (optional) Features to enable. As of Vulkan 1.1 and above, you can use a pNext chain to enable them.
    };

    std::optional<creation_callback> callbacks = {}; ///< (optional) Allocation callbacks.
    std::optional<std::string>       name      = {}; ///< (optional) Name for debug markers.

    [[nodiscard]] friend constexpr bool operator==(const device& a, const device& b) noexcept = default;
    [[nodiscard]] friend constexpr bool operator!=(const device& a, const device& b) noexcept = default;
};

} // namespace fubuki::fuyu::information

#endif // FUBUKI_FUYU_INFORMATION_DEVICE_HPP
