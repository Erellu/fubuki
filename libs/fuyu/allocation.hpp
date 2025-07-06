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

#ifndef FUBUKI_FUYU_ALLOCATION_HPP
#define FUBUKI_FUYU_ALLOCATION_HPP

#include <core/assertion.hpp>
#include <core/config/macros.hpp>
#include <core/detail/handle_traits.hpp>
#include <core/handle.hpp>
#include <core/invoke.hpp>
#include <core/result.hpp>
#include <core/traits/function.hpp>
#include <core/validate.hpp>

#include "fuyu/functions/device.hpp"   // IWYU pragma: keep
#include "fuyu/functions/instance.hpp" // IWYU pragma: keep
#include "fuyu/information/callbacks.hpp"
#include "fuyu/views/device.hpp"
#include "fuyu/views/instance.hpp"

namespace fubuki::fuyu
{

namespace detail
{

template<typename T>
concept handle_like = requires(T h) {
    typename T::underlying_type;
    { h.vk } -> std::same_as<std::add_lvalue_reference_t<typename T::underlying_type>>;
    { h = fubuki::null_handle };
};

using fubuki::detail::creatable_handle;

/// Level of indirection of create_handle overloads (so instance and device object can be factorised)
template<handle_like handle, typename parent_object, typename create_info, fubuki::traits::function::pointer pfn_type>
[[nodiscard]]
inline std::expected<handle, api_call_info> create_handle(const parent_object&               parent,
                                                          const create_info&                 info,
                                                          pfn_type                           create_func,
                                                          const VkAllocationCallbacks* const callbacks = nullptr) noexcept
{
    // Better error message when reasonnable
    if constexpr(creatable_handle<handle>)
    {
        using traits            = fubuki::detail::handle_traits<handle>;
        using expected_pfn_type = traits::pfn_create;

        static_assert(std::is_same_v<pfn_type, expected_pfn_type>, "Invalid creation function specified for this handle.");
    }

    handle result{};

    fubuki_assert(parent.handle != null_handle, "Device must not be nullptr.");
    fubuki_assert(create_func != nullptr, "Device functions must be loaded.");

    if(const auto check
       = fubuki_validate(validate_by::expected, create_func(parent.handle.vk, std::addressof(info), callbacks, std::addressof(result.vk))); not check)
    {
        return std::unexpected{check.error()};
    }

    return result;
}

/// Level of indirection of create_handle overloads (so instance and device object can be factorised)
template<handle_like handle, typename parent_object, fubuki::traits::function::pointer pfn_type>
inline void
destroy_handle(const parent_object& parent, handle& object, pfn_type destroy_func, const VkAllocationCallbacks* const callbacks = nullptr) noexcept
{
    // Better error message when reasonnable
    if constexpr(creatable_handle<handle>)
    {
        using traits            = fubuki::detail::handle_traits<handle>;
        using expected_pfn_type = traits::pfn_destroy;

        static_assert(std::is_same_v<pfn_type, expected_pfn_type>, "Invalid destruction function specified for this handle.");
    }

    fubuki_assert(parent.handle != null_handle, "Device must not be nullptr.");
    fubuki_assert(destroy_func != nullptr, "Device functions must be loaded.");

    if constexpr(std::is_same_v<handle, device_handle>)
    {
        destroy_func(object.vk, callbacks);
    }
    else
    {
        static_assert(requires {
            { destroy_func(parent.handle.vk, object.vk, callbacks) };
        });
        destroy_func(parent.handle.vk, object.vk, callbacks);
    }

    object = fubuki::null_handle;
}

/// Indirection to vkCreateInstance. Provided separately to avoid exposing vkCreateInstance with VK_NO_PROTOTYPES.
[[nodiscard]] FUBUKI_FUYU_API VkResult create_instance(const VkInstanceCreateInfo*  info,
                                                       const VkAllocationCallbacks* allocator,
                                                       VkInstance*                  instance) noexcept;

/// Indirection to vkDestroyInstance. Provided separately to avoid exposing vkDestroyInstance with VK_NO_PROTOTYPES.
FUBUKI_FUYU_API
extern void destroy_instance(VkInstance instance, const VkAllocationCallbacks* allocator) noexcept;

} // namespace detail

/********************************************************************************/
/*                                GENERIC CASES                                 */
/********************************************************************************/

/**
 * Generic function to create an handle (as defined in common/handle.hpp").
 * @param device Device on which the handle object will be allocated.
 * @param info Info required by Vulkan to create the handle object.
 * @param create_func Function creating the handle object.
 * @tparam handle Type of the handle to allocate.
 * @tparam create_info (Deduced) Type of the information structure for this handle.
 * @tparam pfn_type (Deduced) Type of the function creating the handle.
 * @pre create_func must originate from device.
 * @pre create_func must not be nullptr.
 * @pre device.handle must not be nullptr.
 * @pre handle must be an handle type-like structure matching the interface of common/handle.hpp.
 */
template<detail::handle_like handle, typename create_info, fubuki::traits::function::pointer pfn_type>
[[nodiscard]]
inline auto create_handle(const device_view& device, const create_info& info, pfn_type create_func) noexcept
{
    return detail::create_handle<handle>(device, info, create_func);
}

/**
 * Generic function to create an handle (as defined in common/handle.hpp").
 * @param instance Instance on which the handle object will be allocated.
 * @param info Info required by Vulkan to create the handle object.
 * @param create_func Function creating the handle object.
 * @tparam handle Type of the handle to allocate.
 * @tparam create_info (Deduced) Type of the information structure for this handle.
 * @tparam pfn_type (Deduced) Type of the function creating the handle.
 * @pre create_func must originate from instance.
 * @pre create_func must not be nullptr.
 * @pre instance.handle must not be nullptr.
 * @pre handle must be an handle type-like structure matching the interface of common/handle.hpp.
 */
template<detail::handle_like handle, typename create_info, fubuki::traits::function::pointer pfn_type>
[[nodiscard]]
inline auto create_handle(const instance_view& instance, const create_info& info, pfn_type create_func) noexcept
{
    return detail::create_handle<handle>(instance, info, create_func);
}

/**
 * Generic function to create an handle (as defined in common/handle.hpp").
 * @param device Device on which the handle object will be allocated.
 * @param info Info required by Vulkan to create the handle object.
 * @tparam handle Type of the handle to allocate.
 * @tparam create_info (Deduced) Type of the information structure for this handle.
 * @pre device.handle must not be nullptr.
 * @pre handle must be an handle type-like structure matching the interface of common/handle.hpp.
 */
template<detail::creatable_handle handle, typename create_info>
[[nodiscard]]
inline auto create_handle(const device_view& device, const create_info& info) noexcept
{
    using traits = fubuki::detail::handle_traits<handle>;

    auto* const create_func = fubuki::get_from<traits::pfn_create_name>(device.functions.get().core);

    return detail::create_handle<handle>(device, info, create_func);
}

//------------------------------------------------------------------------------

/**
 * Generic function to create an handle (as defined in common/handle.hpp").
 * @param device Device on which the handle object will be allocated.
 * @param info Info required by Vulkan to create the handle object.
 * @param create_func Function creating the handle object.
 * @param callbacks Callbacks functions to call after the creation.
 * @tparam handle Type of the handle to allocate.
 * @tparam create_info (Deduced) Type of the information structure for this handle.
 * @tparam pfn_type (Deduced) Type of the function creating the handle.
 * @pre create_func must originate from device.
 * @pre create_func must not be nullptr.
 * @pre device.handle must not be nullptr.
 * @pre handle must be an handle type-like structure matching the interface of common/handle.hpp.
 */
template<detail::handle_like handle, typename parent_object, typename create_info, fubuki::traits::function::pointer pfn_type>
[[nodiscard]]
inline auto create_handle(const parent_object& device, const create_info& info, pfn_type create_func, const VkAllocationCallbacks& callbacks) noexcept
{
    return detail::create_handle<handle>(device, info, create_func, std::addressof(callbacks));
}

/**
 * Generic function to create an handle (as defined in common/handle.hpp").
 * @param instance Instance on which the handle object will be allocated.
 * @param info Info required by Vulkan to create the handle object.
 * @param create_func Function creating the handle object.
 * @param callbacks Callbacks functions to call after the creation.
 * @tparam handle Type of the handle to allocate.
 * @tparam create_info (Deduced) Type of the information structure for this handle.
 * @tparam pfn_type (Deduced) Type of the function creating the handle.
 * @pre create_func must originate from instance.
 * @pre create_func must not be nullptr.
 * @pre instance.handle must not be nullptr.
 * @pre handle must be an handle type-like structure matching the interface of common/handle.hpp.
 */
template<detail::handle_like handle, typename create_info, fubuki::traits::function::pointer pfn_type>
[[nodiscard]]
inline auto
create_handle(const instance_view& instance, const create_info& info, pfn_type create_func, const VkAllocationCallbacks& callbacks) noexcept
{
    return detail::create_handle<handle>(instance, info, create_func, std::addressof(callbacks));
}

/**
 * Generic function to create an handle (as defined in common/handle.hpp").
 * @param device Device on which the handle object will be allocated.
 * @param info Info required by Vulkan to create the handle object.
 * @param callbacks Callbacks functions to call after the creation.
 * @tparam handle Type of the handle to allocate.
 * @tparam create_info (Deduced) Type of the information structure for this handle.
 * @pre device.handle must not be nullptr.
 * @pre handle must be an handle type-like structure matching the interface of common/handle.hpp.
 */
template<detail::creatable_handle handle, typename create_info>
[[nodiscard]]
inline auto create_handle(const device_view& device, const create_info& info, const VkAllocationCallbacks& callbacks) noexcept
{
    using traits            = fubuki::detail::handle_traits<handle>;
    auto* const create_func = fubuki::get_from<traits::pfn_create_name>(device.functions.get().core);
    return detail::create_handle<handle>(device, info, create_func, std::addressof(callbacks));
}

/**
 * Generic function to create an handle (as defined in common/handle.hpp").
 * @param device Device on which the handle object will be allocated.
 * @param info Info required by Vulkan to create the handle object.
 * @param callbacks Callbacks functions to call after the creation.
 * @tparam handle Type of the handle to allocate.
 * @tparam create_info (Deduced) Type of the information structure for this handle.
 * @pre device.handle must not be nullptr.
 * @pre handle must be an handle type-like structure matching the interface of common/handle.hpp.
 */
template<detail::creatable_handle handle, typename create_info>
[[nodiscard]]
inline auto create_handle(const device_view&                                                   device,
                          const create_info&                                                   info,
                          const std::optional<std::reference_wrapper<const creation_callback>> callbacks) noexcept
{
    return callbacks.has_value() ? fuyu::create_handle<handle>(device, info, (*callbacks).get().creation) : fuyu::create_handle<handle>(device, info);
}

//------------------------------------------------------------------------------

/**
 * Generic function to destroy an handle (as defined in common/handle.hpp").
 * @param device Device on which the allocation was performed.
 * @param object Handle to destroy.
 * @param destroy_func Function destroying the handle object.
 * @tparam handle (Deduced) Type of the handle to destroy.
 * @tparam pfn_type (Deduced) Type of the function destroying the handle.
 * @pre object must originate from device.
 * @pre destroy_func must originate from device.
 * @pre destroy_func must not be nullptr.
 * @pre handle must be an handle type-like structure matching the interface of common/handle.hpp.
 */
template<detail::handle_like handle, fubuki::traits::function::pointer pfn_type>
inline void destroy_handle(const device_view& device, handle& object, pfn_type destroy_func) noexcept
{
    return detail::destroy_handle<handle>(device, object, destroy_func);
}

/**
 * Generic function to destroy an handle (as defined in common/handle.hpp").
 * @param device Device on which the allocation was performed.
 * @param object Handle to destroy.
 * @tparam handle (Deduced) Type of the handle to destroy.
 * @pre object must originate from device.
 * @pre handle must be an handle type-like structure matching the interface of common/handle.hpp.
 */
template<detail::creatable_handle handle>
inline void destroy_handle(const device_view& device, handle& object) noexcept
{
    using traits = fubuki::detail::handle_traits<handle>;

    auto* const destroy_func = fubuki::get_from<traits::pfn_destroy_name>(device.functions.get().core);

    return detail::destroy_handle<handle>(device, object, destroy_func);
}

//------------------------------------------------------------------------------

/**
 * Generic function to destroy an handle (as defined in common/handle.hpp").
 * @param device Device on which the allocation was performed.
 * @param object Handle to destroy.
 * @param destroy_func Function destroying the handle object.
 * @param callbacks Callbacks functions to call after the destruction.
 * @tparam handle (Deduced) Type of the handle to destroy.
 * @tparam pfn_type (Deduced) Type of the function destroying the handle.
 * @pre object must originate from device.
 * @pre destroy_func must originate from device.
 * @pre destroy_func must not be nullptr.
 * @pre handle must be an handle type-like structure matching the interface of common/handle.hpp.
 */
template<detail::handle_like handle, fubuki::traits::function::pointer pfn_type>
inline void destroy_handle(const device_view& device, handle& object, pfn_type destroy_func, const VkAllocationCallbacks& callbacks) noexcept
{
    return detail::destroy_handle<handle>(device, object, destroy_func, std::addressof(callbacks));
}

/**
 * Generic function to destroy an handle (as defined in common/handle.hpp").
 * @param device Device on which the allocation was performed.
 * @param object Handle to destroy.
 * @param callbacks Callbacks functions to call after the destruction.
 * @tparam handle (Deduced) Type of the handle to destroy.
 * @pre object must originate from device.
 * @pre handle must be an handle type-like structure matching the interface of common/handle.hpp.
 */
template<detail::creatable_handle handle>
inline void destroy_handle(const device_view& device, handle& object, const VkAllocationCallbacks& callbacks) noexcept
{
    using traits = fubuki::detail::handle_traits<handle>;

    auto* const destroy_func = fubuki::get_from<traits::pfn_destroy_name>(device.functions.get().core);

    return detail::destroy_handle<handle>(device, object, destroy_func, std::addressof(callbacks));
}

/**
 * Generic function to destroy an handle (as defined in common/handle.hpp").
 * @param device Device on which the allocation was performed.
 * @param object Handle to destroy.
 * @param callbacks Callbacks functions to call after the destruction.
 * @tparam handle (Deduced) Type of the handle to destroy.
 * @pre object must originate from device.
 * @pre handle must be an handle type-like structure matching the interface of common/handle.hpp.
 */
template<detail::creatable_handle handle>
inline void
destroy_handle(const device_view& device, handle& object, const std::optional<std::reference_wrapper<const creation_callback>> callbacks) noexcept
{
    return callbacks.has_value() ? fuyu::destroy_handle<handle>(device, object, (*callbacks).get().destruction)
                                 : fuyu::destroy_handle<handle>(device, object);
}

/********************************************************************************/
/*                                SPECIAL CASES                                 */
/********************************************************************************/

/// Variant of create_handle for the special case of VkInstance.
[[nodiscard]]
inline std::expected<instance_handle, api_call_info> create_handle(const VkInstanceCreateInfo& info) noexcept
{
    instance_handle instance = {};

    if(const auto check = fubuki_validate(validate_by::expected, detail::create_instance(&info, nullptr, std::addressof(instance.vk))); not check)
    {
        return std::unexpected{check.error()};
    }

    return instance;
}

/// Variant of create_handle for the special case of VkInstance.
[[nodiscard]]
inline std::expected<instance_handle, api_call_info> create_handle(const VkInstanceCreateInfo& info, const VkAllocationCallbacks& callbacks) noexcept
{
    instance_handle instance = {};

    if(const auto check
       = fubuki_validate(validate_by::expected, detail::create_instance(&info, std::addressof(callbacks), std::addressof(instance.vk))); not check)
    {
        return std::unexpected{check.error()};
    }

    return instance;
}

/// Variant of create_handle for the special case of VkInstance.
[[nodiscard]]
inline auto create_handle(const VkInstanceCreateInfo& info, const std::optional<std::reference_wrapper<const creation_callback>> callbacks) noexcept
{
    return callbacks.has_value() ? create_handle(info, (*callbacks).get().creation) : create_handle(info);
}

//------------------------------------------------------------------------------

/// Variant of create_handle for the special case of VkDevice.
[[nodiscard]]
inline std::expected<device_handle, api_call_info>
create_handle(const instance_view& instance, physical_device_handle physical_device, const VkDeviceCreateInfo& info) noexcept
{
    fubuki_assert(instance.handle != null_handle, "Instance must not be nullptr.");
    fubuki_assert(instance->vk10.create_device != nullptr, "Instance functions must be loaded.");

    device_handle device{};

    if(const auto check = fubuki_validate(validate_by::expected, instance->vk10.create_device(physical_device.vk, std::addressof(info), nullptr, std::addressof(device.vk))); not check)
    {
        return std::unexpected{check.error()};
    }

    return device;
}

/// Variant of create_handle for the special case of VkDevice.
[[nodiscard]]
inline std::expected<device_handle, api_call_info> create_handle(const instance_view&         instance,
                                                                 physical_device_handle       physical_device,
                                                                 const VkDeviceCreateInfo&    info,
                                                                 const VkAllocationCallbacks& callbacks) noexcept
{
    fubuki_assert(instance.handle != null_handle, "Instance must not be nullptr.");
    fubuki_assert(instance->vk10.create_device != nullptr, "Instance functions must be loaded.");

    device_handle device = {};

    if(const auto check = fubuki_validate(validate_by::expected, instance->vk10.create_device(physical_device.vk, std::addressof(info), std::addressof(callbacks), std::addressof(device.vk))); not check)
    {
        return std::unexpected{check.error()};
    }

    return device;
}

/// Variant of create_handle for the special case of VkDevice.
[[nodiscard]]
inline std::expected<device_handle, api_call_info>
create_handle(const instance_view&                                                 instance,
              physical_device_handle                                               physical_device,
              const VkDeviceCreateInfo&                                            info,
              const std::optional<std::reference_wrapper<const creation_callback>> callbacks) noexcept
{
    return callbacks.has_value() ? create_handle(instance, physical_device, info, (*callbacks).get().creation)
                                 : create_handle(instance, physical_device, info);
}

//------------------------------------------------------------------------------

/// Variant of create_handle for the special case of pipelines.
template<typename handle_type>
requires(std::is_same_v<handle_type, graphics_pipeline_handle> or std::is_same_v<handle_type, compute_pipeline_handle>)
[[nodiscard]]
inline std::expected<handle_type, api_call_info> create_handle(const device_view&                                                  device,
                                                               pipeline_cache_handle                                               cache,
                                                               const typename fubuki::detail::handle_traits<handle_type>::vk_info& info,
                                                               const VkAllocationCallbacks&                                        callbacks) noexcept
{
    handle_type pipeline = {};

    auto pfn = fubuki::get_from<fubuki::detail::handle_traits<handle_type>::pfn_create_name>(device.functions.get().core);

    if(const auto check
       = fubuki_validate(validate_by::expected, pfn(device.handle.vk, cache.vk, 1u, std::addressof(info), std::addressof(callbacks), std::addressof(pipeline.vk))); not check)
    {
        return std::unexpected{check.error()};
    }

    return pipeline;
}

/// Variant of create_handle for the special case of pipelines.
template<typename handle_type>
requires(std::is_same_v<handle_type, graphics_pipeline_handle> or std::is_same_v<handle_type, compute_pipeline_handle>)
[[nodiscard]]
inline std::expected<handle_type, api_call_info> create_handle(const device_view&                                                  device,
                                                               pipeline_cache_handle                                               cache,
                                                               const typename fubuki::detail::handle_traits<handle_type>::vk_info& info) noexcept
{
    handle_type pipeline = {};

    auto pfn = fubuki::get_from<fubuki::detail::handle_traits<handle_type>::pfn_create_name>(device.functions.get().core);

    if(const auto check
       = fubuki_validate(validate_by::expected, pfn(device.handle.vk, cache.vk, 1u, std::addressof(info), nullptr, std::addressof(pipeline.vk))); not check)
    {
        return std::unexpected{check.error()};
    }

    return pipeline;
}

/// Variant of create_handle for the special case of pipeline.
template<typename handle_type>
requires(std::is_same_v<handle_type, graphics_pipeline_handle> or std::is_same_v<handle_type, compute_pipeline_handle>)
[[nodiscard]]
inline std::expected<handle_type, api_call_info>
create_handle(const device_view&                                                   device,
              pipeline_cache_handle                                                cache,
              const typename fubuki::detail::handle_traits<handle_type>::vk_info&  info,
              const std::optional<std::reference_wrapper<const creation_callback>> callbacks) noexcept
{
    return callbacks.has_value() ? create_handle<handle_type>(device, cache, info, (*callbacks).get().creation)
                                 : create_handle<handle_type>(device, cache, info);
}

//------------------------------------------------------------------------------

/// Variant of destroy_handle for the special case of VkInstance.
inline void destroy_handle(instance_handle& instance) noexcept
{
    detail::destroy_instance(instance.vk, nullptr);
    instance = null_handle;
}

/// Variant of destroy_handle for the special case of VkInstance.
inline void destroy_handle(instance_handle& instance, const VkAllocationCallbacks& callbacks) noexcept
{
    detail::destroy_instance(instance.vk, std::addressof(callbacks));
    instance = null_handle;
}

/// Variant of destroy_handle for the special case of VkInstance.
inline void destroy_handle(instance_handle& instance, const std::optional<std::reference_wrapper<const creation_callback>> callbacks) noexcept
{
    return callbacks.has_value() ? fuyu::destroy_handle(instance, (*callbacks).get().destruction) : fuyu::destroy_handle(instance);
}

//------------------------------------------------------------------------------

/// Variant of destroy_handle for the special case of VkDevice.
inline void destroy_handle(const instance_view& instance, device_handle& device) noexcept
{
    return detail::destroy_handle(instance, device, instance->vk10.destroy_device);
}

/// Variant of destroy_handle for the special case of VkDevice.
inline void destroy_handle(const instance_view& instance, device_handle& device, const VkAllocationCallbacks& callbacks) noexcept
{
    return detail::destroy_handle(instance, device, instance->vk10.destroy_device, std::addressof(callbacks));
}

/// Variant of destroy_handle for the special case of VkDevice.
inline void destroy_handle(const instance_view& instance, device_handle& device, const std::optional<creation_callback>& callbacks) noexcept
{
    return callbacks.has_value() ? fuyu::destroy_handle(instance, device, callbacks->destruction) : fuyu::destroy_handle(instance, device);
}

} // namespace fubuki::fuyu

#endif // FUBUKI_FUYU_ALLOCATION_HPP
