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

#ifndef FUBUKI_CORE_FUTURE_MOVE_ONLY_FUNCTION_HPP
#define FUBUKI_CORE_FUTURE_MOVE_ONLY_FUNCTION_HPP

#include <functional>
#include <memory>
#include <type_traits>
#include <utility>
#include <variant>

#include "core/assertion.hpp"
#include "core/future/nontype.hpp"
#include "core/opaque_ptr.hpp"

/*
 * This implementation of std::move_only_function is based on
 * https://github.com/zhihaoy/nontype_functional
 * License: BSD-2 (https://github.com/zhihaoy/nontype_functional/blob/main/LICENSE)
 * ____________________________________________________________________________
 * BSD 2-Clause License
 *
 * Copyright (c) 2022, Zhihao Yuan
 * All rights reserved.
 * [...]
 * ____________________________________________________________________________
 */

namespace fubuki
{

namespace future
{

/**
 * @brief Implementation details for move_only_function.
 * ____________________________________________________________________________
 * This implementation of std::move_only_function is based on
 * https://github.com/zhihaoy/nontype_functional
 * License: BSD-2 (https://github.com/zhihaoy/nontype_functional/blob/main/LICENSE)
 * ____________________________________________________________________________
 * BSD 2-Clause License
 *
 * Copyright (c) 2022, Zhihao Yuan
 * All rights reserved.
 * [...]
 * ____________________________________________________________________________
 */
namespace detail::move_only_function
{

// See also: https://www.agner.org/optimize/calling_conventions.pdf
template<typename T>
inline constexpr auto select_param_type = []
{
    if constexpr(std::is_trivially_copyable_v<T>)
    {
        return std::type_identity<T>();
    }
    else
    {
        return std::add_rvalue_reference<T>();
    }
};

template<typename T>
using param_t = std::invoke_result_t<decltype(select_param_type<T>)>::type;

template<typename T, typename self>
inline constexpr bool is_not_self = not std::is_same_v<std::remove_cvref_t<T>, self>;

template<typename T, template<typename...> typename>
inline constexpr bool looks_nullable_to_impl = std::is_member_pointer_v<T>;

template<typename F, template<typename...> typename self>
inline constexpr bool looks_nullable_to_impl<F*, self> = std::is_function_v<F>;

template<typename... S, template<typename...> typename self>
inline constexpr bool looks_nullable_to_impl<self<S...>, self> = true;

template<typename S, template<typename...> typename self>
inline constexpr bool looks_nullable_to = looks_nullable_to_impl<std::remove_cvref_t<S>, self>;

template<typename sig>
struct cv_fn_sig
{
};

template<typename R, typename... args>
struct cv_fn_sig<R(args...)>
{
    using function = R(args...);
    template<typename T>
    using cv = T;
};

template<typename R, typename... args>
struct cv_fn_sig<R(args...) const>
{
    using function = R(args...);
    template<typename T>
    using cv = T const;
};

template<typename sig>
struct ref_quals_fn_sig : cv_fn_sig<sig>
{
    template<typename T>
    using ref = T;
};

template<typename R, typename... args>
struct ref_quals_fn_sig<R(args...)&> : cv_fn_sig<R(args...)>
{
    template<typename T>
    using ref = T&;
};

template<typename R, typename... args>
struct ref_quals_fn_sig<R(args...) const&> : cv_fn_sig<R(args...) const>
{
    template<typename T>
    using ref = T&;
};

template<typename R, typename... args>
struct ref_quals_fn_sig<R(args...) &&> : cv_fn_sig<R(args...)>
{
    template<typename T>
    using ref = T&&;
};

template<typename R, typename... args>
struct ref_quals_fn_sig<R(args...) const&&> : cv_fn_sig<R(args...) const>
{
    template<typename T>
    using ref = T&&;
};

template<bool V>
struct noex_traits
{
    static constexpr bool is_noexcept = V;
};

template<typename sig>
struct full_fn_sig : ref_quals_fn_sig<sig>,
                     noex_traits<false>
{
};

template<typename R, typename... args>
struct full_fn_sig<R(args...) noexcept> : ref_quals_fn_sig<R(args...)>,
                                          noex_traits<true>
{
};

template<typename R, typename... args>
struct full_fn_sig<R(args...) & noexcept> : ref_quals_fn_sig<R(args...)&>,
                                            noex_traits<true>
{
};

template<typename R, typename... args>
struct full_fn_sig<R(args...) && noexcept> : ref_quals_fn_sig<R(args...) &&>,
                                             noex_traits<true>
{
};

template<typename R, typename... args>
struct full_fn_sig<R(args...) const noexcept> : ref_quals_fn_sig<R(args...) const>,
                                                noex_traits<true>
{
};

template<typename R, typename... args>
struct full_fn_sig<R(args...) const & noexcept> : ref_quals_fn_sig<R(args...) const&>,
                                                  noex_traits<true>
{
};

template<typename R, typename... args>
struct full_fn_sig<R(args...) const && noexcept> : ref_quals_fn_sig<R(args...) const&&>,
                                                   noex_traits<true>
{
};

namespace storage_alternative
{

struct owning_ptr
{
    template<typename T>
    requires std::is_object_v<T>
    owning_ptr(std::unique_ptr<T> p) noexcept : value{make_opaque(std::move(p))}
    {
    }

    opaque_unique_ptr<void> value;
};

struct owning_const_ptr
{
    template<typename T>
    requires std::is_object_v<T>
    owning_const_ptr(std::unique_ptr<const T> p) noexcept : value{make_opaque(std::move(p))}
    {
    }

    opaque_unique_ptr<const void> value;
};

struct non_owning_ptr
{
    void* value = nullptr;
};

struct non_owning_const_ptr
{
    const void* value = nullptr;
};

template<bool noexcept_callable, typename result, typename... args>
using function = auto(args...) noexcept(noexcept_callable) -> result;

template<bool noexcept_callable, typename result, typename... args>
struct pfn
{
    function<noexcept_callable, result, args...>* value = nullptr;
    using type                                          = decltype(value);
};

// FIXME: required to be split in two deduction guides for MSVC

// This is however supposed to suffice
// template<bool noexcept_callable, typename result, typename... args>
// pfn(function<noexcept_callable, result, args...>*) -> pfn<noexcept_callable, result, args...>;

template<typename result, typename... args>
pfn(result (*)(args...)) -> pfn<false, result, args...>;

template<typename result, typename... args>
pfn(result (*)(args...) noexcept) -> pfn<true, result, args...>;

template<bool noexcept_callable, typename result, typename... args>
using any = std::variant<std::monostate, non_owning_ptr, non_owning_const_ptr, owning_ptr, owning_const_ptr, pfn<noexcept_callable, result, args...>>;

template<typename T, bool noexcept_callable, typename result, typename... args>
[[nodiscard]]
inline constexpr auto get(const any<noexcept_callable, result, args...>& val)
{
    constexpr auto visit = []<typename variant>(const variant& var) noexcept -> T*
    {
        if constexpr(requires { static_cast<T*>(var.value); })
        {
            return static_cast<T*>(var.value);
        }
        else if constexpr(requires { static_cast<T*>(var.value.get()); })
        {
            return static_cast<T*>(var.value.get());
        }
        else
        {
            return nullptr;
        }
    };

    T* const ptr = std::visit(visit, val);
    fubuki_assert(ptr != nullptr, "The function is empty and cannot be called");
    return ptr;
}

} // namespace storage_alternative

template<bool noexcept_callable, typename result, typename... args>
struct storage_for
{
    using owning_ptr           = storage_alternative::owning_ptr;
    using owning_const_ptr     = storage_alternative::owning_const_ptr;
    using non_owning_ptr       = storage_alternative::non_owning_ptr;
    using non_owning_const_ptr = storage_alternative::non_owning_const_ptr;
    using pfn                  = storage_alternative::pfn<noexcept_callable, result, args...>;

    using value_type = storage_alternative::any<noexcept_callable, result, args...>;

    value_type val = {};

    storage_for() = default;

    storage_for(storage_for&& other) noexcept            = default;
    storage_for& operator=(storage_for&& other) noexcept = default;

    storage_for& operator=(storage_for const&) = delete;
    storage_for(storage_for const&)            = delete;

    explicit storage_for(non_owning_ptr p) noexcept : val{p} {}

    explicit storage_for(non_owning_const_ptr p) noexcept : val{p} {}

    explicit storage_for(owning_ptr p) noexcept : val{std::in_place_type<owning_ptr>, std::move(p)} {}

    explicit storage_for(owning_const_ptr p) noexcept : val{std::in_place_type<owning_const_ptr>, std::move(p)} {}

    explicit storage_for(pfn p) noexcept : val{p} {}

    template<typename T>
    requires std::is_object_v<T>
    explicit storage_for(const T* p) noexcept : val{non_owning_const_ptr{p}}
    {
    }

    template<typename T>
    requires(std::is_function_v<T> and std::convertible_to<T, typename pfn::type>)
    explicit storage_for(T* p) noexcept : val{pfn{static_cast<pfn::type>(p)}}
    {
    }

    storage_for& operator=(non_owning_ptr p) noexcept
    {
        val = p;
        return *this;
    }

    storage_for& operator=(non_owning_const_ptr p) noexcept
    {
        val = p;
        return *this;
    }

    storage_for& operator=(owning_ptr p) noexcept
    {
        val.template emplace<owning_ptr>(std::move(p));
        return *this;
    }

    storage_for& operator=(owning_const_ptr p) noexcept
    {
        val.template emplace<owning_const_ptr>(std::move(p));
        return *this;
    }

    storage_for& operator=(pfn p) noexcept
    {
        val = p;
        return *this;
    }
};

template<bool noexcept_callable, typename result, typename... args>
struct callable_trait
{
    using storage = storage_for<noexcept_callable, result, args...>;
    using handle  = storage::value_type;

    using call_t = auto(const handle&, args...) noexcept(noexcept_callable) -> result;

    struct vtable
    {
        call_t* call = nullptr;
    };

    template<typename T, template<typename> typename quals>
    struct callable_target_vtable
    {
        static result call(const handle& self, args... arguments) noexcept(noexcept_callable)
        {
            if constexpr(std::is_lvalue_reference_v<T> or std::is_pointer_v<T>)
            {
                using tp = std::remove_reference_t<std::remove_pointer_t<T>>;
                return std::invoke_r<result>(*storage_alternative::get<tp>(self), std::forward<args>(arguments)...);
            }
            else
            {
                using fp = quals<T>::type;
                return std::invoke_r<result>(static_cast<fp>(*storage_alternative::get<T>(self)), std::forward<args>(arguments)...);
            }
        }
    };

    template<auto f>
    struct unbound_callable_target_vtable
    {
        static result call(const handle&, args... arguments) noexcept(noexcept_callable)
        {
            return std::invoke_r<result>(f, std::forward<args>(arguments)...);
        }
    };

    template<auto f, typename T, template<typename> typename quals>
    struct bound_callable_target_vtable
    {
        static result call(const handle& self, args... arguments) noexcept(noexcept_callable)
        {
            if constexpr(std::is_pointer_v<T>)
            {
                using tp = std::remove_pointer_t<T>;
                return std::invoke_r<result>(f, storage_alternative::get<tp>(self), std::forward<args>(arguments)...);
            }
            else if constexpr(std::is_lvalue_reference_v<T>)
            {
                using tp = std::remove_reference_t<T>;
                return std::invoke_r<result>(f, *storage_alternative::get<tp>(self), std::forward<args>(arguments)...);
            }
            else
            {
                using fp = quals<T>::type;
                return std::invoke_r<result>(f, static_cast<fp>(*storage_alternative::get<T>(self)), std::forward<args>(arguments)...);
            }
        }
    };

    template<auto f, typename T>
    struct boxed_callable_target_vtable
    {
        static result call(const handle& self, args... arguments) noexcept(noexcept_callable)
        {
            return std::invoke_r<result>(f, storage_alternative::get<T>(self), std::forward<args>(arguments)...);
        }
    };

    static inline constexpr vtable const empty = {};

    // See also: https://gcc.gnu.org/bugzilla/show_bug.cgi?id=71954
    template<typename T, template<typename> typename quals>
    static inline constexpr vtable callable_target{
        .call = callable_target_vtable<T, quals>::call,
    };

    template<auto f>
    static inline constexpr vtable unbound_callable_target{
        .call = unbound_callable_target_vtable<f>::call,
    };

    template<auto f, typename T, template<typename> typename quals>
    static inline constexpr vtable bound_callable_target{
        .call = bound_callable_target_vtable<f, T, quals>::call,
    };

    template<auto f, typename T>
    static inline constexpr vtable boxed_callable_target{
        .call = boxed_callable_target_vtable<f, T>::call,
    };
};

template<typename T, template<typename...> typename primary>
inline constexpr bool is_specialization_of = false;

template<template<typename...> typename primary, typename... args>
inline constexpr bool is_specialization_of<primary<args...>, primary> = true;

template<typename T, template<typename...> typename primary>
inline constexpr bool does_not_specialize = not is_specialization_of<std::remove_cvref_t<T>, primary>;

struct take_reference_t
{
    template<typename T>
    requires(std::is_function_v<T>)
    [[nodiscard]] constexpr auto operator()(T* rhs) const noexcept
    {
        return storage_alternative::pfn{rhs};
    }

    template<typename T>
    requires(std::is_object_v<T>)
    [[nodiscard]] constexpr auto operator()(T&& rhs) const
    {
        if constexpr(std::is_const_v<T>)
        {
            return storage_alternative::owning_const_ptr{std::make_unique<const T>(T(std::forward<T>(rhs)))}; // Explicit copy
        }
        else
        {
            return storage_alternative::owning_ptr{std::make_unique<T>(T(std::forward<T>(rhs)))}; // Explicit copy
        }
    }

    template<typename T>
    requires(not std::is_function_v<T>)
    [[nodiscard]] constexpr auto operator()(T* rhs) const noexcept
    {
        return storage_alternative::non_owning_ptr{rhs};
    }

    template<typename T>
    requires(not std::is_function_v<T>)
    [[nodiscard]] constexpr auto operator()(const T* rhs) const noexcept
    {
        return storage_alternative::non_owning_const_ptr{rhs};
    }

    template<typename T>
    [[nodiscard]] constexpr auto operator()(std::reference_wrapper<T> rhs) const noexcept
    {
        return storage_alternative::non_owning_ptr{std::addressof(rhs.get())};
    }

    template<typename T>
    [[nodiscard]] constexpr auto operator()(std::reference_wrapper<const T> rhs) const noexcept
    {
        return storage_alternative::non_owning_const_ptr{std::addressof(rhs.get())};
    }

    template<typename T>
    [[nodiscard]] constexpr auto operator()(T& rhs) const noexcept
    {
        return (*this)(std::ref(rhs));
    }

    template<typename T>
    [[nodiscard]] constexpr auto operator()(const T& rhs) const noexcept
    {
        return (*this)(std::cref(rhs));
    }
};

inline constexpr take_reference_t take_reference = {};

template<typename T>
inline constexpr auto build_reference = [](auto&&... args)
requires(std::is_object_v<T>)
{
    if constexpr(std::is_const_v<T>)
    {
        return storage_alternative::owning_const_ptr{std::make_unique<const T>(std::forward<decltype(args)>(args)...)};
    }
    else
    {
        return storage_alternative::owning_ptr{std::make_unique<T>(std::forward<decltype(args)>(args)...)};
    }
};

template<typename T>
inline constexpr auto build_reference<T*> = [](auto&&... args) noexcept -> T*
requires(std::is_object_v<T>) { return storage_alternative::non_owning_ptr{{std::forward<decltype(args)>(args)...}}; };

template<typename T>
inline constexpr auto build_reference<const T*> = [](auto&&... args) noexcept -> T*
requires(std::is_object_v<T>) { return storage_alternative::non_owning_const_ptr{{std::forward<decltype(args)>(args)...}}; };

template<typename T>
inline constexpr auto build_reference<std::reference_wrapper<T>> = [](auto& rhs) noexcept
{ return storage_alternative::non_owning_ptr{std::addressof(rhs)}; };

template<typename T>
inline constexpr auto build_reference<std::reference_wrapper<const T>> = [](auto& rhs) noexcept
{ return storage_alternative::non_owning_const_ptr{std::addressof(rhs)}; };

} // namespace detail::move_only_function

/**
 * An implementation of C++23's move_only_function.
 * ____________________________________________________________________________
 * This implementation of std::move_only_function is based on
 * https://github.com/zhihaoy/nontype_functional
 * License: BSD-2 (https://github.com/zhihaoy/nontype_functional/blob/main/LICENSE).
 * ____________________________________________________________________________
 * BSD 2-Clause License
 *
 * Copyright (c) 2022, Zhihao Yuan
 * All rights reserved.
 * [...]
 * ____________________________________________________________________________
 */
template<typename S, typename = typename detail::move_only_function::full_fn_sig<S>::function>
class move_only_function;

template<typename S, typename R, typename... args>
class move_only_function<S, R(args...)>
{
    using signature = detail::move_only_function::full_fn_sig<S>;

    template<typename T>
    using cv = signature::template cv<T>;

    template<typename T>
    using ref = signature::template ref<T>;

    static constexpr bool is_noexcept    = signature::is_noexcept;
    static constexpr bool is_const       = std::is_same_v<cv<void>, void const>;
    static constexpr bool is_lvalue_only = std::is_same_v<ref<int>, int&>;
    static constexpr bool is_rvalue_only = std::is_same_v<ref<int>, int&&>;

    template<typename T>
    using cvref = ref<cv<T>>;

    template<typename T>
    struct inv_quals_f : std::conditional<is_lvalue_only or is_rvalue_only, cvref<T>, cv<T>&>
    {
    };

    template<typename T>
    using inv_quals = inv_quals_f<T>::type;

    template<typename... T>
    static constexpr bool is_invocable_using
        = std::conditional_t<is_noexcept, std::is_nothrow_invocable_r<R, T..., args...>, std::is_invocable_r<R, T..., args...>>::value;

    template<typename VT>
    static constexpr bool is_callable_from = is_invocable_using<cvref<VT>> and is_invocable_using<inv_quals<VT>>;

    template<auto f, typename VT>
    static constexpr bool is_callable_as_if_from = is_invocable_using<decltype(f), inv_quals<VT>>;

    using trait  = detail::move_only_function::callable_trait<is_noexcept, R, detail::move_only_function::param_t<args>...>;
    using vtable = trait::vtable;

    std::reference_wrapper<const vtable> m_vtable = trait::empty;
    trait::storage                       m_obj;

public:
    using result_type = R;

    move_only_function() = default;
    move_only_function(std::nullptr_t) noexcept : move_only_function() {}

    template<typename F, typename VT = std::decay_t<F>>
    move_only_function(F&& f) noexcept(std::is_nothrow_invocable_v<decltype(detail::move_only_function::take_reference), F>)
    requires detail::move_only_function::is_not_self<F, move_only_function>
        and detail::move_only_function::does_not_specialize<F, std::in_place_type_t> and is_callable_from<VT> and std::is_constructible_v<VT, F>
    {
        if constexpr(detail::move_only_function::looks_nullable_to<F, move_only_function>)
        {
            if(f == nullptr)
            {
                return;
            }
        }

        m_vtable = trait::template callable_target<std::unwrap_reference_t<F>, inv_quals_f>;
        m_obj    = detail::move_only_function::take_reference(std::forward<F>(f));
    }

    template<auto f>
    move_only_function(nontype_t<f>) noexcept
    requires is_invocable_using<decltype(f)>
        : m_vtable(trait::template unbound_callable_target<f>)
    {
    }

    template<auto f, typename T, typename VT = std::decay_t<T>>
    move_only_function(nontype_t<f>, T&& x) noexcept(std::is_nothrow_invocable_v<decltype(detail::move_only_function::take_reference), T>)
    requires is_callable_as_if_from<f, VT> and std::is_constructible_v<VT, T>
        : m_vtable(trait::template bound_callable_target<f, std::unwrap_ref_decay_t<T>, inv_quals_f>),
          m_obj(detail::move_only_function::take_reference(std::forward<T>(x)))
    {
    }

    template<typename M, typename C, M C::* f, typename T>
    move_only_function(nontype_t<f>, std::unique_ptr<T>&& x) noexcept
    requires std::is_base_of_v<C, T> and is_callable_as_if_from<f, T*>
        : m_vtable(trait::template boxed_callable_target<f, T>),
          m_obj(std::move(x).release())
    {
    }

    template<typename T, typename... inits>
    explicit move_only_function(std::in_place_type_t<T>, inits&&... initials) noexcept(
        std::is_nothrow_invocable_v<decltype(detail::move_only_function::build_reference<T>), inits...>)
    requires is_callable_from<T> and std::is_constructible_v<T, inits...>
        : m_vtable(trait::template callable_target<std::unwrap_reference_t<T>, inv_quals_f>),
          m_obj(detail::move_only_function::build_reference<T>(std::forward<inits>(initials)...))
    {
        static_assert(std::is_same_v<std::decay_t<T>, T>);
    }

    template<typename T, typename U, typename... inits>
    explicit move_only_function(std::in_place_type_t<T>,
                                std::initializer_list<U> ilist,
                                inits&&... initals) noexcept( //
        std::is_nothrow_invocable_v<decltype(detail::move_only_function::build_reference<T>), decltype((ilist)), inits...>)
    requires is_callable_from<T> and std::is_constructible_v<T, decltype((ilist)), inits...>
        : m_vtable(trait::template callable_target<std::unwrap_reference_t<T>, inv_quals_f>),
          m_obj(detail::move_only_function::build_reference<T>(ilist, std::forward<inits>(initals)...))
    {
        static_assert(std::is_same_v<std::decay_t<T>, T>);
    }

    template<auto f, typename T, typename... inits>
    explicit move_only_function(nontype_t<f>,
                                std::in_place_type_t<T>,
                                inits&&... initials) noexcept( //
        std::is_nothrow_invocable_v<decltype(detail::move_only_function::build_reference<T>), inits...>)
    requires is_callable_as_if_from<f, T> and std::is_constructible_v<T, inits...>
        : m_vtable(trait::template bound_callable_target<f, std::unwrap_reference_t<T>, inv_quals_f>),
          m_obj(detail::move_only_function::build_reference<T>(std::forward<inits>(initials)...))
    {
        static_assert(std::is_same_v<std::decay_t<T>, T>);
    }

    template<typename M, typename C, M C::* f, typename T, typename... inits>
    explicit move_only_function(nontype_t<f> t,
                                std::in_place_type_t<std::unique_ptr<T>>,
                                inits&&... initials) noexcept( //
        std::is_nothrow_constructible_v<std::unique_ptr<T>, inits...>)
    requires std::is_base_of_v<C, T> and is_callable_as_if_from<f, T*> and std::is_constructible_v<std::unique_ptr<T>, inits...>
        : move_only_function(t, std::unique_ptr<T>(std::forward<inits>(initials)...))
    {
    }

    template<auto f, typename T, typename U, typename... inits>
    explicit move_only_function(nontype_t<f>,
                                std::in_place_type_t<T>,
                                std::initializer_list<U> ilist,
                                inits&&... initials) noexcept( //
        std::is_nothrow_invocable_v<decltype(detail::move_only_function::build_reference<T>), decltype((ilist)), inits...>)
    requires is_callable_as_if_from<f, T> and std::is_constructible_v<T, decltype((ilist)), inits...>
        : m_vtable(trait::template bound_callable_target<f, std::unwrap_reference_t<T>, inv_quals_f>),
          m_obj(detail::move_only_function::build_reference<T>(ilist, std::forward<inits>(initials)...))
    {
        static_assert(std::is_same_v<std::decay_t<T>, T>);
    }

    ~move_only_function() = default;

    move_only_function(move_only_function&&) noexcept            = default;
    move_only_function& operator=(move_only_function&&) noexcept = default;

    move_only_function(const move_only_function&)            = delete;
    move_only_function& operator=(const move_only_function&) = delete;

    void        swap(move_only_function& other) noexcept { std::swap<move_only_function>(*this, other); }
    friend void swap(move_only_function& lhs, move_only_function& rhs) noexcept { lhs.swap(rhs); }

    explicit operator bool() const noexcept { return std::addressof(m_vtable.get()) != std::addressof(trait::empty); }

    friend bool operator==(const move_only_function& f, std::nullptr_t) noexcept { return !f; }
    friend bool operator==(std::nullptr_t, const move_only_function& f) noexcept { return !f; }

    R operator()(args... arguments) noexcept(is_noexcept)
    requires(!is_const and !is_lvalue_only and !is_rvalue_only)
    {
        return m_vtable.get().call(m_obj.val, std::forward<args>(arguments)...);
    }

    R operator()(args... arguments) const noexcept(is_noexcept)
    requires(is_const and !is_lvalue_only and !is_rvalue_only)
    {
        return m_vtable.get().call(m_obj.val, std::forward<args>(arguments)...);
    }

    R operator()(args... arguments) & noexcept(is_noexcept)
    requires(!is_const and is_lvalue_only and !is_rvalue_only)
    {
        return m_vtable.get().call(m_obj.val, std::forward<args>(arguments)...);
    }

    R operator()(args... arguments) const& noexcept(is_noexcept)
    requires(is_const and is_lvalue_only and !is_rvalue_only)
    {
        return m_vtable.get().call(m_obj.val, std::forward<args>(arguments)...);
    }

    R operator()(args... arguments) && noexcept(is_noexcept)
    requires(!is_const and !is_lvalue_only and is_rvalue_only)
    {
        return m_vtable.get().call(m_obj.val, std::forward<args>(arguments)...);
    }

    R operator()(args... arguments) const&& noexcept(is_noexcept)
    requires(is_const and !is_lvalue_only and is_rvalue_only)
    {
        return m_vtable.get().call(m_obj.val, std::forward<args>(arguments)...);
    }
};

} // namespace future

using future::move_only_function;

} // namespace fubuki

#endif // FUBUKI_CORE_FUTURE_MOVE_ONLY_FUNCTION_HPP
