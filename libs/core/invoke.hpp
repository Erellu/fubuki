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

#ifndef FUBUKI_CORE_INVOKE_HPP
#define FUBUKI_CORE_INVOKE_HPP

#include <functional>

#include "core/assertion.hpp"
#include "core/detail/pfn.hpp"

namespace fubuki
{

namespace detail
{

template<typename functions_type, fubuki::detail::vk_function_hash pfn>
struct get_from;

template<typename functions_type, fubuki::detail::vk_function_hash pfn>
struct get_from
{
    static constexpr bool valid = false;

    [[nodiscard]] constexpr static std::nullptr_t get(const functions_type&) noexcept
    {
        return nullptr; // Invalid generic specialisation to trigger a compile error
    }
};

// get_from gets specialised for instance|device_core_functions, instance|device_ext_functions and each individual fubuki::extension::<>::functions

} // namespace detail

/**
 * Returns a Vulkan function pointer by name.
 * @param functions The functions structure from which the Vulkan function will be retrieved.
 * @tparam f Name of the function to retrieve.
 * @tparam functions_type (deduced) Type of the functions structure.
 *
 * @section example Example
 *
 * @code{.cpp}
 * const fubuki::instance_core_functions funcs = ...;
 * auto* const pfn = fubuki::get_from<"vkCreateDevice">(funcs);
 * @endcode
 */
template<fubuki::detail::vk_function_hash f, typename functions_type>
requires(detail::get_from<functions_type, f>::valid)
[[nodiscard]]
inline constexpr auto* get_from(const functions_type& functions) noexcept
{
    return detail::get_from<functions_type, f>::get(functions);
}

/**
 * Invokes a Vulkan function by name.
 * @param funcs The functions structure from which the Vulkan function will be retrieved.
 * @param arguments (variadic) The arguments with which the Vulkan function will be invoked.
 * @tparam pfn Name of the function to retrieve.
 * @tparam functions_type (deduced) Type of the functions structure.
 *
 * @pre The Vulkan function must be loaded. If it is `nullptr`, then the behaviour of this function is undefined.
 *
 * @section example Example
 *
 * @code{.cpp}
 * const fubuki::instance_core_functions funcs = ...;
 * VkDevice d = fubuki::invoke<"vkCreateDevice">(funcs, ...);
 * @endcode
 */
template<fubuki::detail::vk_function_hash pfn, typename functions_type, typename... args>
requires(detail::get_from<functions_type, pfn>::valid)
inline decltype(auto) invoke(const functions_type& funcs, args&&... arguments) noexcept
{
    auto* const vk_func = fubuki::get_from<pfn, functions_type>(funcs);
    fubuki_assert(vk_func != nullptr, "Function '" << fubuki::detail::traits::vk_function<pfn.hash>::name << "' is not loaded.");

    return std::invoke(vk_func, std::forward<args>(arguments)...);
}

} // namespace fubuki

#endif // FUBUKI_CORE_INVOKE_HPP
