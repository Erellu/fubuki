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

#ifndef FUBUKI_FUYU_INFORMATION_MEMORY_HPP
#define FUBUKI_FUYU_INFORMATION_MEMORY_HPP

#include <cstdint>
#include <functional>
#include <optional>
#include <string>
#include <variant>

#include <core/compare/memory_requirements.hpp>
#include <core/compare/memory_requirements2.hpp>
#include <core/structure_type.hpp>
#include <core/vulkan.hpp>

#include "fuyu/information/callbacks.hpp"

namespace fubuki::fuyu::information
{

/// Information required to create an instance of fuyu::memory.
/// @see https://registry.khronos.org/vulkan/specs/1.3-extensions/man/html/VkMemoryAllocateInfo.html
struct memory
{
    using underlying_type = VkMemoryAllocateInfo;

#if defined(VK_VERSION_1_1)
    using requirements_type = VkMemoryRequirements2;
#else
    using requirements_type = VkMemoryRequirements;
#endif // defined(VK_VERSION_1_1)

    [[nodiscard]] static constexpr requirements_type make_requirements(VkMemoryRequirements r) noexcept
    {
#if defined(VK_VERSION_1_1)
        return {.sType = structure_type_v<requirements_type>, .pNext = nullptr, .memoryRequirements = r};
#else
        return r;
#endif // defined(VK_VERSION_1_1)
    }

    /// Additional information provided by extensions.
    struct extension
    {
        struct flags_information
        {
            VkMemoryAllocateFlags flags       = {}; ///< Flags provided for memory allocation.
            std::uint32_t         device_mask = {}; /**< Mask of physical devices in the logical device, indicating that memory must be allocated on
                                                    each device in the mask, if VK_MEMORY_ALLOCATE_DEVICE_MASK_BIT is set in flags. */

            [[nodiscard]] friend constexpr bool operator==(const flags_information& a, const flags_information& b) noexcept  = default;
            [[nodiscard]] friend constexpr bool operator!=(const flags_information& a, const flags_information& b) noexcept  = default;
            [[nodiscard]] friend constexpr auto operator<=>(const flags_information& a, const flags_information& b) noexcept = default;
        };

        std::optional<flags_information>               allocation_flags       = {}; ///< Allocation flags.
        std::optional<std::uint64_t>                   opaque_capture_address = {}; ///< Opaque capture address.
        std::optional<std::variant<VkImage, VkBuffer>> dedication             = {}; ///< Handle this memory is dedicated to.

#if defined(VK_VERSION_1_1)
        std::optional<VkExternalMemoryHandleTypeFlags> external_memory_handle_types = {}; /**< Zero or a bitmask specifying one or more memory handle
                                                                                               types the application can export from the resulting
                                                                                                allocation. */
#endif                                                                                    // defined(VK_VERSION_1_1)

        [[nodiscard]] friend constexpr bool operator==(const extension& a, const extension& b) noexcept  = default;
        [[nodiscard]] friend constexpr bool operator!=(const extension& a, const extension& b) noexcept  = default;
        [[nodiscard]] friend constexpr auto operator<=>(const extension& a, const extension& b) noexcept = default;
    };

    requirements_type     requirements = {}; ///< Memory requirements.
    VkMemoryPropertyFlags properties   = {}; ///< Memory properties.

    std::optional<creation_callback> callbacks = {}; ///< Callbacks.
    std::optional<std::string>       name      = {}; ///< (optional) Name passed to debug markers.

    [[nodiscard]] friend constexpr bool operator==(const memory& a, const memory& b) noexcept
    {
        return (a.requirements == b.requirements) and (a.properties == b.properties) and (a.callbacks == b.callbacks) and (a.name == b.name);
    }

    [[nodiscard]] friend constexpr bool operator!=(const memory& a, const memory& b) noexcept { return not(a == b); }

    [[nodiscard]] friend constexpr underlying_type to_underlying(std::reference_wrapper<const memory> cref, std::uint32_t index) noexcept
    {
        // Avoids having to introduce deleted overloads for temporaries
        const auto& s = cref.get();

#if defined(VK_VERSION_1_1)
        const auto size = s.requirements.memoryRequirements.size;
#else
        const auto size = s.requirements.size;
#endif // defined(VK_VERSION_1_1)

        return {
            .sType           = structure_type_v<underlying_type>,
            .pNext           = nullptr,
            .allocationSize  = size,
            .memoryTypeIndex = index,
        };
    }
};

} // namespace fubuki::fuyu::information

#endif // FUBUKI_FUYU_INFORMATION_MEMORY_HPP
