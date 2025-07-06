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

/*
 * WARNING : This file is GENERATED.
 * Changes performed manually will be undone next generation.
 */

#ifndef FUBUKI_CORE_ENUM_QUEUE_GLOBAL_PRIORITY_HPP
#define FUBUKI_CORE_ENUM_QUEUE_GLOBAL_PRIORITY_HPP

#include <string>
#include <string_view>

#include "core/vulkan.hpp"

namespace fubuki
{

// clang-format off
#if defined(VK_VERSION_1_4)

/// Returns a std::string_view corresponding to a VkQueueGlobalPriority.
[[nodiscard]] inline constexpr std::string_view to_string_view(const VkQueueGlobalPriority e) noexcept
{
    #if defined(FUBUKI_MAKE_CASE)
        #error Internal error. Should not be defined.
    #endif

    #define FUBUKI_MAKE_CASE(enum_value) \
        case enum_value: return #enum_value

    switch(e)
    {

#if defined(VK_VERSION_1_4) 
        FUBUKI_MAKE_CASE(VK_QUEUE_GLOBAL_PRIORITY_LOW);
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_VERSION_1_4) 
        FUBUKI_MAKE_CASE(VK_QUEUE_GLOBAL_PRIORITY_MEDIUM);
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_VERSION_1_4) 
        FUBUKI_MAKE_CASE(VK_QUEUE_GLOBAL_PRIORITY_HIGH);
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_VERSION_1_4) 
        FUBUKI_MAKE_CASE(VK_QUEUE_GLOBAL_PRIORITY_REALTIME);
#endif // #if defined (VK_VERSION_1_4)

#if defined(VK_EXT_global_priority) && !(defined(VK_VERSION_1_4))
        FUBUKI_MAKE_CASE(VK_QUEUE_GLOBAL_PRIORITY_LOW_EXT);
#endif // #if defined (VK_EXT_global_priority)

#if defined(VK_EXT_global_priority) && !(defined(VK_VERSION_1_4))
        FUBUKI_MAKE_CASE(VK_QUEUE_GLOBAL_PRIORITY_MEDIUM_EXT);
#endif // #if defined (VK_EXT_global_priority)

#if defined(VK_EXT_global_priority) && !(defined(VK_VERSION_1_4))
        FUBUKI_MAKE_CASE(VK_QUEUE_GLOBAL_PRIORITY_HIGH_EXT);
#endif // #if defined (VK_EXT_global_priority)

#if defined(VK_EXT_global_priority) && !(defined(VK_VERSION_1_4))
        FUBUKI_MAKE_CASE(VK_QUEUE_GLOBAL_PRIORITY_REALTIME_EXT);
#endif // #if defined (VK_EXT_global_priority)

#if defined(VK_KHR_global_priority) && !(defined(VK_VERSION_1_4))
        FUBUKI_MAKE_CASE(VK_QUEUE_GLOBAL_PRIORITY_LOW_KHR);
#endif // #if defined (VK_KHR_global_priority)

#if defined(VK_KHR_global_priority) && !(defined(VK_VERSION_1_4))
        FUBUKI_MAKE_CASE(VK_QUEUE_GLOBAL_PRIORITY_MEDIUM_KHR);
#endif // #if defined (VK_KHR_global_priority)

#if defined(VK_KHR_global_priority) && !(defined(VK_VERSION_1_4))
        FUBUKI_MAKE_CASE(VK_QUEUE_GLOBAL_PRIORITY_HIGH_KHR);
#endif // #if defined (VK_KHR_global_priority)

#if defined(VK_KHR_global_priority) && !(defined(VK_VERSION_1_4))
        FUBUKI_MAKE_CASE(VK_QUEUE_GLOBAL_PRIORITY_REALTIME_KHR);
#endif // #if defined (VK_KHR_global_priority)

        FUBUKI_MAKE_CASE(VK_QUEUE_GLOBAL_PRIORITY_MAX_ENUM);

        default: return "";
    }

    #undef FUBUKI_MAKE_CASE
}

/// Returns a std::string corresponding to a VkQueueGlobalPriority.
[[nodiscard]] inline auto to_string(VkQueueGlobalPriority e) { return std::string{to_string_view(e)}; }

//------------------------------------------------------------------------------

#endif // #if defined(VK_VERSION_1_4)
// clang-format on

} // namespace fubuki

#endif // FUBUKI_CORE_ENUM_QUEUE_GLOBAL_PRIORITY_HPP
