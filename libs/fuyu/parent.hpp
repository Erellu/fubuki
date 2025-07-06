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

#ifndef FUBUKI_FUYU_PARENT_HPP
#define FUBUKI_FUYU_PARENT_HPP

#include <ostream>
#include <utility>

#include <core/config/macros.hpp>
#include <core/detail/handle_traits.hpp>
#include <core/handle.hpp>

#include "fuyu/views/device_ref.hpp"
#include "fuyu/views/instance_ref.hpp"

namespace fubuki::fuyu::parent
{

namespace error
{

template<typename T>
requires(fubuki::detail::is_handle_v<T>)
struct incompatible
{
    T current   = {};
    T attempted = {};

    friend constexpr bool operator==(const incompatible&, const incompatible&) noexcept  = default;
    friend constexpr bool operator!=(const incompatible&, const incompatible&) noexcept  = default;
    friend constexpr auto operator<=>(const incompatible&, const incompatible&) noexcept = default;

    /// Swaps two objects.
    void swap(incompatible& other) noexcept
    {
        std::swap(current, other.current);
        std::swap(attempted, other.attempted);
    }

    /// Swaps two objects.
    friend void swap(incompatible& a, incompatible& b) noexcept { a.swap(b); }

    template<typename char_type, typename traits = std::char_traits<char_type> >
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const incompatible& e)
    {
        return out << "fuyu::parent::error::incompatible: {"
                   << "current: " << e.current.vk << ", "
                   << "attempted: " << e.attempted.vk << "}";
    }
};

} // namespace error

namespace detail
{

template<typename owning_object, typename fbk_handle>
struct base
{
    using handle_type = fbk_handle;
    using ref_type    = std::reference_wrapper<const owning_object>;

    struct error
    {
        using incompatible = parent::error::incompatible<handle_type>;
    };

    [[nodiscard]] operator handle_type() const noexcept { return handle; }
    [[nodiscard]] operator ref_type() const noexcept { return ref; }
    [[nodiscard]] operator const owning_object&() const noexcept { return ref.get(); }
    [[nodiscard]] const auto* operator->() const noexcept { return std::addressof(ref.get()); }

    void swap(base& other) noexcept
    {
        std::swap(ref, other.ref);
        std::swap(handle, other.handle);
    }

    friend void swap(base& a, base& b) noexcept { return a.swap(b); }

    [[nodiscard]] friend bool compatible(const base& a, const base& b) noexcept { return a.handle == b.handle; }

    ref_type    ref;
    handle_type handle;
};

} // namespace detail

struct device : detail::base<fuyu::device, device_handle>
{
    using base = detail::base<fuyu::device, device_handle>;

    FUBUKI_FUYU_API
    device(fuyu::device_cref) noexcept;
};

struct instance : detail::base<fuyu::instance, instance_handle>
{
    using base = detail::base<fuyu::instance, instance_handle>;

    FUBUKI_FUYU_API
    instance(fuyu::instance_cref) noexcept;
};

} // namespace fubuki::fuyu::parent

#endif // FUBUKI_FUYU_PARENT_HPP
