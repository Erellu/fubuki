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

#ifndef FUBUKI_CORE_HASH_HPP
#define FUBUKI_CORE_HASH_HPP

#include <cstddef>
#include <ranges>
#include <utility>

namespace fubuki
{

/**
 * Hashes a range which elements are hashable through std::hash. Limited to sized ranges.
 * @param range The range to hash.
 *
 * @author https://stackoverflow.com/a/12996028, Thomas Mueller (https://stackoverflow.com/users/382763/thomas-mueller), available under CC BY-SA 4.0
 */
template<std::ranges::sized_range r>
requires requires(std::ranges::range_reference_t<r> x) {
    { std::hash<std::ranges::range_value_t<r>>{}(x) } -> std::same_as<std::size_t>;
}
[[nodiscard]]
inline constexpr auto hash_range(r&& range)
{
    constexpr std::size_t magic      = 0x45d9f3b;
    constexpr std::size_t more_magic = 0x9e3779b9;

    std::size_t seed = std::ranges::size(range);

    for(auto&& x : std::forward<r>(range))
    {
        using x_type = decltype(x);

        // NOLINTBEGIN(cppcoreguidelines-avoid-magic-numbers)
        std::size_t hash = std::hash<std::decay_t<x_type>>{}(std::forward<x_type>(x));
        hash             = ((hash >> 16) ^ hash) * magic;
        hash             = ((hash >> 16) ^ hash) * magic;
        hash             = (hash >> 16) ^ hash;
        seed ^= hash + more_magic + (seed << 6) + (seed >> 2);
        // NOLINTEND(cppcoreguidelines-avoid-magic-numbers)
    }

    return seed;
}

} // namespace fubuki

#endif // FUBUKI_CORE_HASH_HPP
