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

#ifndef FUBUKI_FUYU_DEBUG_NAME_HPP
#define FUBUKI_FUYU_DEBUG_NAME_HPP

#include <extension/ext_debug_utils.hpp>

#include "fuyu/device.hpp"   // IWYU pragma: keep (required for conversion operators to be available)
#include "fuyu/instance.hpp" // IWYU pragma: keep (required for conversion operators to be available)

namespace fubuki::fuyu::debug
{

/**
 * Names a handle.
 * @param funcs Instance functions.
 * @param device The device the handle has been allocated from.
 * @param handle The handle to name.
 * @param object_name The handle name.
 *
 * @pre funcs Must have the functions of ext_debug_utils loaded.
 *
 * @tparam hash (deduced) The hash of the Vulkan handle type name.
 * @tparam T (deduced) The underlying Vulkan handle type.
 */
template<std::uint64_t hash, typename T>
inline auto name([[maybe_unused]] const instance_ext_functions& funcs,
                 [[maybe_unused]] device_handle                 device,
                 [[maybe_unused]] handle<hash, T>               handle,
                 [[maybe_unused]] const std::string&            object_name) noexcept
{
#if defined(VK_EXT_debug_utils)
    return extension::ext_debug_utils::object::set_name(funcs, device, handle, object_name);
#endif // #if defined(VK_EXT_debug_utils
}

/**
 * Names a handle.
 * @param instance The instance from which the handle's parent comes from.
 * @param device The device the handle has been allocated from.
 * @param handle The handle to name.
 * @param object_name The handle name.
 *
 * @pre funcs Must have the functions of ext_debug_utils loaded.
 *
 * @tparam hash (deduced) The hash of the Vulkan handle type name.
 * @tparam T (deduced) The underlying Vulkan handle type.
 */
template<std::uint64_t hash, typename T>
inline auto name(const instance_view& instance, device_handle device, handle<hash, T> handle, const std::string& object_name) noexcept
{
    return name(instance.functions.get().ext, device, handle, object_name);
}

/**
 * Names a handle.
 * @param device The device the handle has been allocated from.
 * @param handle The handle to name.
 * @param object_name The handle name.
 *
 * @pre funcs Must have the functions of ext_debug_utils loaded.
 *
 * @tparam hash (deduced) The hash of the Vulkan handle type name.
 * @tparam T (deduced) The underlying Vulkan handle type.
 */
template<typename device_type, std::uint64_t hash, typename T>
inline auto name(device_type&& device, handle<hash, T> handle, const std::string& object_name) noexcept
{
    return name(std::forward<device_type>(device).instance(), std::forward<device_type>(device), handle, object_name);
}

/**
 * Names a handle if the ext_debug_utils extension is loaded.
 * @param funcs Instance functions.
 * @param device The device the handle has been allocated from.
 * @param handle The handle to name.
 * @param object_name The handle name.
 *
 * @pre funcs Must have the functions of ext_debug_utils loaded.
 *
 * @tparam hash (deduced) The hash of the Vulkan handle type name.
 * @tparam T (deduced) The underlying Vulkan handle type.
 */
template<std::uint64_t hash, typename T>
inline auto name_if_loaded(const instance_ext_functions& funcs, device_handle device, handle<hash, T> handle, const std::string& object_name) noexcept
{
    if(funcs.ext_debug_utils)
    {
        return extension::ext_debug_utils::object::set_name(funcs, device, handle, object_name);
    }

    return std::expected<void, api_call_info>{};
}

/**
 * Names a handle if the ext_debug_utils extension is loaded.
 * @param instance The instance from which the handle's parent comes from.
 * @param device The device the handle has been allocated from.
 * @param handle The handle to name.
 * @param object_name The handle name.
 *
 * @pre funcs Must have the functions of ext_debug_utils loaded.
 *
 * @tparam hash (deduced) The hash of the Vulkan handle type name.
 * @tparam T (deduced) The underlying Vulkan handle type.
 */
template<std::uint64_t hash, typename T>
inline auto name_if_loaded(const instance_view& instance, device_handle device, handle<hash, T> handle, const std::string& object_name) noexcept
{
    if(instance.functions.get().ext.ext_debug_utils)
    {
        return name(instance.functions.get().ext, device, handle, object_name);
    }

    return std::expected<void, api_call_info>{};
}

/**
 * Names a handle.
 * @param dev The device the handle has been allocated from.
 * @param handle The handle to name.
 * @param object_name The handle name.
 *
 * @pre funcs Must have the functions of ext_debug_utils loaded.
 *
 * @tparam hash (deduced) The hash of the Vulkan handle type name.
 * @tparam T (deduced) The underlying Vulkan handle type.
 */
template<typename device_type, std::uint64_t hash, typename T>
requires(std::is_same_v<std::decay_t<device_type>, fuyu::device>)
inline auto name_if_loaded(device_type&& dev, handle<hash, T> handle, const std::string& object_name) noexcept
{
    return name_if_loaded(std::forward<device_type>(dev).instance(), std::forward<device_type>(dev).handle(), handle, object_name);
}

} // namespace fubuki::fuyu::debug

#endif // FUBUKI_FUYU_DEBUG_NAME_HPP
