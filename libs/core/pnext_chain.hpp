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

#ifndef FUBUKI_CORE_PNEXT_CHAIN_HPP
#define FUBUKI_CORE_PNEXT_CHAIN_HPP

#include <ranges>
#include <tuple>
#include <utility>

#include "core/detail/pnext_chain.hpp"
#include "core/structure_type.hpp"

namespace fubuki
{

/// A chain of structures to pass to the pNext member of a structure.
template<typename... structures>
class pnext_chain
{
public:

    static constexpr std::size_t size = sizeof...(structures);     ///< Number of structures in this chain.
    using elements                    = std::tuple<structures...>; ///< Types of the elements of this chain.

    constexpr pnext_chain(pnext_chain&&) noexcept            = default;
    constexpr pnext_chain& operator=(pnext_chain&&) noexcept = default;

    constexpr pnext_chain(structures&... s) noexcept : m_data{std::tie(s...)} { build(m_data); }

    [[nodiscard]] constexpr auto*       front() noexcept { return std::addressof(std::get<0>(m_data)); }
    [[nodiscard]] constexpr const auto* front() const noexcept { return std::addressof(std::get<0>(m_data)); }

    [[nodiscard]] constexpr auto*       back() noexcept { return std::addressof(std::get<size - 1u>(m_data)); }
    [[nodiscard]] constexpr const auto* back() const noexcept { return std::addressof(std::get<size - 1u>(m_data)); }

    [[nodiscard]] constexpr const auto& data() const noexcept { return m_data; }

private:

    using value_type = std::tuple<std::add_lvalue_reference_t<structures>...>;

    template<std::size_t index = 0>
    inline static constexpr void build(value_type& tuple) noexcept
    {
        auto& current = std::get<index>(tuple);
        current.sType = structure_type_v<decltype(current)>; // Correct mistakes

        if constexpr(index < sizeof...(structures) - 1)
        {
            auto& next    = std::get<index + 1>(tuple);
            current.pNext = std::addressof(next);
            build<index + 1>(tuple);
        }
        else
        {
            current.pNext = nullptr;
        }
    }

    /// Underlying pNext chain.
    value_type m_data;
};

/// Empty pNext chain type.
template<> // Provided for compatility in templates.
class pnext_chain<>
{
public:
    static constexpr std::size_t size = 0;            ///< Number of structures in this chain.
    using elements                    = std::tuple<>; ///< Elements of this chain.

    static inline constexpr void           data() noexcept {}
    static inline constexpr std::nullptr_t front() noexcept { return nullptr; }
    static inline constexpr std::nullptr_t back() noexcept { return nullptr; }
};

template<typename... pnext_elements>
pnext_chain(pnext_elements...) -> pnext_chain<pnext_elements...>;

/// Tag for constructing objects without pnext chains.
inline constexpr pnext_chain<> empty_pnext_chain = {};

/**
 * Equivalent of fubuki::pnext_chain, but with ownership over its elements.
 * Its is implicitely convertible to pnext_chain.
 */
template<typename... structures>
struct owning_pnext_chain
{
    static constexpr std::size_t size = sizeof...(structures);      ///< Number of structures in this chain.
    using elements                    = std::tuple<structures...>;  ///< Types of the elements of this chain.
    using view                        = pnext_chain<structures...>; ///< A view of the elements of this chain.

    // Move default
    constexpr owning_pnext_chain(owning_pnext_chain&&) noexcept            = default;
    constexpr owning_pnext_chain& operator=(owning_pnext_chain&&) noexcept = default;

    constexpr owning_pnext_chain(structures... s) noexcept : m_data{std::forward<structures>(s)...} {}

    [[nodiscard]] constexpr auto*       front() noexcept { return std::addressof(std::get<0>(m_data)); }
    [[nodiscard]] constexpr const auto* front() const noexcept { return std::addressof(std::get<0>(m_data)); }

    [[nodiscard]] constexpr auto*       back() noexcept { return std::addressof(std::get<size - 1u>(m_data)); }
    [[nodiscard]] constexpr const auto* back() const noexcept { return std::addressof(std::get<size - 1u>(m_data)); }

    [[nodiscard]] constexpr const auto& data() const noexcept { return m_data; }
    [[nodiscard]] constexpr auto&       data() noexcept { return m_data; }

    [[nodiscard]] constexpr operator view() const noexcept
    {
        return std::apply([](auto&... x) constexpr noexcept { return pnext_chain{x...}; }, m_data);
    }
    [[nodiscard]] constexpr view chain() const noexcept { return *this; }

    /// Returns a reference to the structure specfied. Requires that only one instance of this structures figures in this chain.
    template<typename T>
    requires(traits::parameter_pack::count_v<T, structures...> == 1)
    [[nodiscard]] constexpr const auto& get() const noexcept
    {
        return std::get<T>(m_data);
    }

    /// Returns a reference to the structure specfied. Requires that only one instance of this structures figures in this chain.
    template<typename T>
    requires(traits::parameter_pack::count_v<T, structures...> == 1)
    [[nodiscard]] constexpr auto& get() noexcept
    {
        return std::get<T>(m_data);
    }

    /// Returns a reference to the structure at the given index.
    template<std::size_t index>
    [[nodiscard]] constexpr const auto& get() const noexcept
    {
        return std::get<index>(m_data);
    }

    /// Returns a reference to the structure at the given index.
    template<std::size_t index>
    [[nodiscard]] constexpr auto& get() noexcept
    {
        return std::get<index>(m_data);
    }

private:

    /// Elements in the chain.
    mutable elements m_data;
    // This is mutable to enable corrections of sType members in pnext_chain::build()
};

template<typename... pnext_elements>
owning_pnext_chain(pnext_elements...) -> owning_pnext_chain<pnext_elements...>;

namespace traits::pnext_chain
{

namespace detail
{

template<typename... members>
struct is_pnext_chain;

template<typename... members>
struct is_pnext_chain : std::false_type
{
};

template<typename... T>
struct is_pnext_chain<fubuki::pnext_chain<T...>> : std::true_type
{
};

} // namespace detail

template<typename T>
concept type = detail::is_pnext_chain<std::decay_t<T>>::value;

using fubuki::detail::pnext_chain::can_extend; // NOLINT(misc-unused-using-decls)

} // namespace traits::pnext_chain

/// Extends a Vulkan structure with a pNext chain.
template<typename base_type, typename... members>
requires(detail::pnext_chain::can_extend_v<base_type, members...>)
inline constexpr base_type& extend(base_type& base, [[maybe_unused]] const pnext_chain<members...>&& chain) noexcept
{
    base.sType = structure_type_v<base_type>;
    base.pNext = std::forward<pnext_chain<members...>>(chain).front(); // Rest is done when constructing the object

    return base;
}

/// Extends a Vulkan structure with a pNext chain.
template<typename base_type, typename... members>
requires(detail::pnext_chain::can_extend_v<base_type, members...>)
inline constexpr base_type& extend(base_type& base, [[maybe_unused]] const pnext_chain<members...>& chain) noexcept
{
    base.sType = structure_type_v<base_type>;
    base.pNext = chain.front(); // Rest is done when constructing the object

    return base;
}

/// Extends a range of structures.
template<std::ranges::random_access_range range_type, traits::pnext_chain::type... pnext_chains_types>
inline void extend_range(range_type range, pnext_chains_types&&... chains) noexcept
{
    constexpr auto impl
        = []<std::size_t... idx>(const std::index_sequence<idx...>, // Not directly used. This is a placeholder for template parameter deduction
                                 range_type in,
                                 pnext_chains_types&&... pnexts) noexcept
    {
        const auto extend_at = [&in]<typename chain_type>(std::size_t i, chain_type&& pnext) noexcept
        {
            if(i < std::ranges::size(in))
            {
                fubuki::extend(in[i], std::forward<chain_type>(pnext));
            }
        };

        [[maybe_unused]] auto chains_tuple = std::make_tuple(std::forward<pnext_chains_types>(pnexts)...); // Unused when chain is empty
        (extend_at(idx, std::get<idx>(chains_tuple)), ...);
    };

    impl(std::make_index_sequence<sizeof...(chains)>{}, range, std::forward<pnext_chains_types>(chains)...);
}

} // namespace fubuki

#endif // FUBUKI_CORE_PNEXT_CHAIN_HPP
