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

#ifndef FUBUKI_CORE_OPAQUE_PTR_HPP
#define FUBUKI_CORE_OPAQUE_PTR_HPP

#include <memory>

namespace fubuki
{

namespace detail::opaque_ptr
{

template<typename T>
using erased_deleter = std::conditional_t<std::is_const_v<T>, void (*)(const void*), void (*)(void*)>;

template<typename T>
using erased_type = std::conditional_t<std::is_const_v<T>, const void, void>;

// Meant to be used as custom deleters (as illustrated below)
// NOLINTBEGIN(cppcoreguidelines-owning-memory)
template<typename T, typename deleter = std::default_delete<T>>
[[nodiscard]] inline constexpr erased_deleter<T> make_erased_delete()
{
    if constexpr(std::is_const_v<T>)
    {
        return [](const void* ptr)
        {
            auto del = deleter{};
            del(static_cast<const T*>(ptr));
        };
    }
    else
    {
        return [](void* ptr)
        {
            auto del = deleter{};
            del(static_cast<T*>(ptr));
        };
    }
}
// NOLINTEND(cppcoreguidelines-owning-memory)

template<typename T>
requires(std::is_object_v<T> and not std::is_array_v<T>)
using type = std::unique_ptr<erased_type<T>, erased_deleter<T>>;

template<typename T, typename deleter>
[[nodiscard]] inline constexpr type<T> make_opaque(std::unique_ptr<T, deleter> ptr) noexcept
{
    return type<T>{ptr.release(), make_erased_delete<T, deleter>()};
}

template<typename T, typename deleter>
[[nodiscard]] inline constexpr type<const T> make_opaque(std::unique_ptr<const T, deleter> ptr) noexcept
{
    return type<const T>{ptr.release(), make_erased_delete<const T, deleter>()};
}

} // namespace detail::opaque_ptr

template<typename T>
requires(std::is_same_v<T, void> or std::is_same_v<T, const void>)
using opaque_unique_ptr = std::unique_ptr<T, detail::opaque_ptr::erased_deleter<T>>;

/// Makes a unique_ptr opaque: returns an opaque_unique_ptr, that will properly delete its contents, but only expose an opaque void* pointer.
template<typename T, typename deleter>
requires(std::is_object_v<T> and not std::is_array_v<T>)
[[nodiscard]] inline constexpr auto make_opaque(std::unique_ptr<T, deleter> ptr) noexcept
{
    return detail::opaque_ptr::make_opaque(std::move(ptr));
}

} // namespace fubuki

#endif // FUBUKI_CORE_OPAQUE_PTR_HPP
