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

#ifndef FUBUKI_CORE_PFN_HPP
#define FUBUKI_CORE_PFN_HPP

#include "core/config/macros.hpp"
#include "core/detail/pfn.hpp"
#include "core/handle.hpp"
#include "core/vulkan.hpp"

namespace fubuki
{

namespace detail
{

/**
 * Equivalent of vkGetInstanceProcAddr.
 * Provided as a separated function to avoid exposing vkGetInstanceProcAddr when compiling with VK_NO_PROTOTYPES.
 */
[[nodiscard]] FUBUKI_CORE_API extern PFN_vkVoidFunction pfn(instance_handle, const char* name) noexcept;

} // namespace detail

// There is no way to silence properly Wcast-function-type for vkGetInstanceProcAddr/vkGetDeviceProcAddr.
// This warning is therefore silenced locally.

#if defined(__clang__)
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wcast-function-type"
#elif defined(__GNUC__)
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wcast-function-type"
#elif defined(_MSC_VER)
    #pragma warning(push)
    #pragma warning(disable : 4191)
#endif

//------------------------------------------------------------------------------

/**
 * Loads an instance function pointer.
 * Returns nullptr on failure.
 * @param instance Vulkan instance.
 * @tparam f Hash of the function name. Must be a valid hash, as defined per detail::traits::vk_function.
 * @pre instance Must not be nullptr.
 *
 * @section example Example
 * @code{.cpp}
 * auto* create_device = pfn<"vkCreateDevice">(instance);
 * @endcode
 */
template<detail::vk_function_hash f>
requires(detail::traits::valid_pfn_name<f.hash>)
[[nodiscard]]
inline auto* pfn(instance_handle instance) noexcept
{
    using vk_function = detail::traits::vk_function<f.hash>;
    using pfn_type    = vk_function::type;

    auto* const function = detail::pfn(instance, vk_function::name.c_str());

    return reinterpret_cast<pfn_type>(function); // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
}

//------------------------------------------------------------------------------

/**
 * Loads a device function pointer, and tries to falls back to instance function pointer if failed.
 * Returns nullptr on failure.
 * @param instance Vulkan instance.
 * @param device Vulkan device.
 * @param device_get Function pointer to vkGetDeviceProcAddr.
 * @tparam f Hash of the function name. Must be a valid hash, as defined per detail::traits::vk_function.
 * @pre 'device' must originate from 'instance.
 * @pre 'device_get' must not be 'nullptr'.
 * @pre None of 'instance', 'device', 'device_get', must be nullptr.
 *
 * @section example Example
 * @code{.cpp}
 * auto* create_buffer = pfn<"vkCreateBuffer">(instance, device, device_get);
 * @endcode
 */
template<detail::vk_function_hash f>
requires(detail::traits::valid_pfn_name<f.hash>)
[[nodiscard]]
auto* pfn(instance_handle instance, device_handle device, PFN_vkGetDeviceProcAddr device_get) noexcept
{
    using vk_function = detail::traits::vk_function<f.hash>;
    using pfn_type    = vk_function::type;

    auto* const function = device_get(device.vk, vk_function::name.c_str());

    if(function == nullptr)
    {
        return pfn<f>(instance); // Fall back to instance function
    }

    return reinterpret_cast<pfn_type>(function); // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
}

//------------------------------------------------------------------------------

#if defined(__clang__)
    #pragma clang diagnostic pop
#elif defined(__GNUC__)
    #pragma GCC diagnostic pop
#elif defined(_MSC_VER)
    #pragma warning(pop)
#endif

} // namespace fubuki

#endif // FUBUKI_CORE_PFN_HPP
