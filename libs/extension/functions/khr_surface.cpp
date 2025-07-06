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

#include "extension/functions/khr_surface.hpp"

#include <core/assertion.hpp>
#include <core/pfn.hpp>

namespace fubuki::extension::functions
{

[[nodiscard]]
khr_surface khr_surface::load([[maybe_unused]] instance_handle instance, [[maybe_unused]] version_number vk_version) noexcept
{
    fubuki_assert(instance != null_handle, "Instance cannot be null_handle.");

           // clang-format off
    return
        {
#if defined(VK_KHR_surface)
            .create_surface_khr = [](instance_handle i, const traits::platform::surface::underlying& platform_info, const VkAllocationCallbacks* callbacks, VkSurfaceKHR* surface) noexcept -> VkResult
            {
                fubuki_assert(i != null_handle, "Instance cannot be nullptr.");
                fubuki_assert(surface != nullptr, "Surface cannot be nullptr."); // This is a pointer to a surface (what it points to may be nullptr)

                const auto create_visitor = [i, callbacks, &surface]<typename T>(const T& info) noexcept -> VkResult
                {
                    using type_traits = traits::platform::surface::reverse<T>;

                           // std::monostate, invalid state
                    if constexpr(std::is_same_v<std::monostate, T>)
                    {
                        return VK_ERROR_OUT_OF_HOST_MEMORY; // One of the error code the "real" functions return
                    }
                    else if constexpr(detail::traits::valid_pfn_name<detail::vk_function_hash{type_traits::pfn}.hash>)
                    {
                        auto* const create = pfn<type_traits::pfn>(i);

                        return create(i.vk, std::addressof(info), callbacks, surface);
                    }
                };

                return std::visit(create_visitor, platform_info);
            },
            .destroy_surface_khr = pfn<"vkDestroySurfaceKHR">(instance),
            .get_physical_device_surface_support_khr = pfn<"vkGetPhysicalDeviceSurfaceSupportKHR">(instance),
            .get_physical_device_surface_capabilities_khr = pfn<"vkGetPhysicalDeviceSurfaceCapabilitiesKHR">(instance),
            .get_physical_device_surface_formats_khr = pfn<"vkGetPhysicalDeviceSurfaceFormatsKHR">(instance),
            .get_physical_device_surface_present_modes_khr = pfn<"vkGetPhysicalDeviceSurfacePresentModesKHR">(instance),

            .cmd =
            {

},
#endif // defined(VK_KHR_surface)
};
// clang-format on
}

} // namespace fubuki::extension::functions
