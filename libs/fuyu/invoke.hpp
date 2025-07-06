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

#ifndef FUBUKI_FUYU_INVOKE_HPP
#define FUBUKI_FUYU_INVOKE_HPP

#include <functional>

#include <core/constants.hpp>
#include <core/invoke.hpp>

#include "fuyu/device.hpp"   // IWYU pragma: keep
#include "fuyu/instance.hpp" // IWYU pragma: keep
#include "fuyu/queue.hpp"
#include "fuyu/views/command_buffer.hpp"
#include "fuyu/views/device_ref.hpp"

namespace fubuki::fuyu
{

template<fubuki::detail::vk_function_hash f, typename... args>
requires requires(args&&... arguments) {
    requires fubuki::detail::traits::valid_pfn_name<f.hash>;
    requires fubuki::detail::get_from<instance_core_functions, f>::valid or fubuki::detail::get_from<instance_ext_functions, f>::valid;
    requires std::invocable<typename fubuki::detail::traits::vk_function<f.hash>::type,
                            instance_handle::underlying_type,
                            decltype(std::forward<args>(arguments))...>;
}
inline decltype(auto) invoke(const instance_functions& funcs, args&&... arguments) noexcept
{
    if constexpr(fubuki::detail::get_from<instance_core_functions, f>::valid)
    {
        return fubuki::invoke<f>(funcs.core, std::forward<args>(arguments)...);
    }
    else if constexpr(fubuki::detail::get_from<instance_ext_functions, f>::valid)
    {
        return fubuki::invoke<f>(funcs.ext, std::forward<args>(arguments)...);
    }
    else
    {
        static_assert(fubuki::detail::always_false<int>,
                      "Internal error."
                      " This template should not have been called. Please consider opening an issue at "
                      "https://github.com/Erellu/fubuki/issues"
                      " and joining the code triggering this assert.");
    }
}

template<fubuki::detail::vk_function_hash f, typename... args>
requires requires(args&&... arguments) {
    requires fubuki::detail::traits::valid_pfn_name<f.hash>;
    requires std::invocable<typename fubuki::detail::traits::vk_function<f.hash>::type,
                            instance_handle::underlying_type,
                            decltype(std::forward<args>(arguments))...>;
}
inline decltype(auto) invoke(const instance_view instance, args&&... arguments) noexcept
{
    return fuyu::invoke<f>(instance.functions.get(), instance.handle.vk, std::forward<args>(arguments)...);
}

template<fubuki::detail::vk_function_hash f, typename... args>
requires requires(args&&... arguments) {
    requires fubuki::detail::traits::valid_pfn_name<f.hash>;
    requires std::invocable<typename fubuki::detail::traits::vk_function<f.hash>::type,
                            instance_handle::underlying_type,
                            decltype(std::forward<args>(arguments))...>;
}
inline decltype(auto) invoke(const instance& instance, args&&... arguments) noexcept
{
    return fuyu::invoke<f>(instance.function(), instance.handle().vk, std::forward<args>(arguments)...);
}

template<fubuki::detail::vk_function_hash f, typename... args>
requires requires(args&&... arguments) {
    requires fubuki::detail::traits::valid_pfn_name<f.hash>;
    requires fubuki::detail::get_from<device_core_functions, f>::valid or fubuki::detail::get_from<device_ext_functions, f>::valid;
    requires std::invocable<typename fubuki::detail::traits::vk_function<f.hash>::type, decltype(std::forward<args>(arguments))...>;
}
inline decltype(auto) invoke(const device_functions& funcs, args&&... arguments) noexcept
{
    if constexpr(fubuki::detail::get_from<device_core_functions, f>::valid)
    {
        return fubuki::invoke<f>(funcs.core, std::forward<args>(arguments)...);
    }
    else if constexpr(fubuki::detail::get_from<device_ext_functions, f>::valid)
    {
        return fubuki::invoke<f>(funcs.ext, std::forward<args>(arguments)...);
    }
    else
    {
        static_assert(fubuki::detail::always_false<int>,
                      "Internal error."
                      " This template should not have been called. Please consider opening an issue at "
                      "https://github.com/Erellu/fubuki/issues"
                      " and joining the code triggering this assert.");
    }
}

template<fubuki::detail::vk_function_hash f, typename... args>
requires requires(args&&... arguments) {
    requires fubuki::detail::traits::valid_pfn_name<f.hash>;
    requires std::invocable<typename fubuki::detail::traits::vk_function<f.hash>::type,
                            command_buffer_handle::underlying_type,
                            decltype(std::forward<args>(arguments))...>;
}
inline decltype(auto) invoke(command_buffer_view command_buffer, args&&... arguments) noexcept
{
    return fuyu::invoke<f>(command_buffer.device.get().function(), command_buffer.handle.vk, std::forward<args>(arguments)...);
}

template<fubuki::detail::vk_function_hash f, typename... args>
requires requires(args&&... arguments) {
    requires fubuki::detail::traits::valid_pfn_name<f.hash>;
    requires std::invocable<typename fubuki::detail::traits::vk_function<f.hash>::type,
                            queue_handle::underlying_type,
                            decltype(std::forward<args>(arguments))...>;
}
inline decltype(auto) invoke(const queue& queue, args&&... arguments) noexcept
{
    return fuyu::invoke<f>(queue.device.get().function(), queue.handle.vk, std::forward<args>(arguments)...);
}

template<fubuki::detail::vk_function_hash f, typename... args>
requires requires(args&&... arguments) {
    requires fubuki::detail::traits::valid_pfn_name<f.hash>;
    requires std::invocable<typename fubuki::detail::traits::vk_function<f.hash>::type,
                            device_handle::underlying_type,
                            decltype(std::forward<args>(arguments))...>;
}
inline decltype(auto) invoke(device_view d, args&&... arguments) noexcept
{
    return fuyu::invoke<f>(d.functions.get(), d.handle.vk, std::forward<args>(arguments)...);
}

template<fubuki::detail::vk_function_hash f, typename... args>
requires requires(args&&... arguments) {
    requires fubuki::detail::traits::valid_pfn_name<f.hash>;
    requires std::invocable<typename fubuki::detail::traits::vk_function<f.hash>::type,
                            device_handle::underlying_type,
                            decltype(std::forward<args>(arguments))...>;
}
inline decltype(auto) invoke(const device& d, args&&... arguments) noexcept
{
    return fuyu::invoke<f>(d.function(), d.handle().vk, std::forward<args>(arguments)...);
}

} // namespace fubuki::fuyu

#endif // FUBUKI_FUYU_INVOKE_HPP
