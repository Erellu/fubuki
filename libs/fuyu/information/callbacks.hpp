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

#ifndef FUBUKI_FUYU_INFORMATION_CREATION_CALLBACKS_HPP
#define FUBUKI_FUYU_INFORMATION_CREATION_CALLBACKS_HPP

#include <core/compare/allocation_callbacks.hpp>
#include <core/vulkan.hpp>

namespace fubuki::fuyu
{

/// Callback for instance creation and destruction.
struct creation_callback
{
    VkAllocationCallbacks creation    = {}; ///< Callbacks when an object is is created / allocated.
    VkAllocationCallbacks destruction = {}; ///< Callbacks when an object is is destroyed / freed.

    [[nodiscard]] friend constexpr bool operator==(const creation_callback& a, const creation_callback& b) noexcept
    {
        // Required to bring fubuki::operator== in the current scope
        return (a.creation == b.creation) and (a.destruction == b.destruction);
    }

    [[nodiscard]] friend constexpr bool operator!=(const creation_callback& a, const creation_callback& b) noexcept { return not(a == b); }
};

} // namespace fubuki::fuyu

#endif // FUBUKI_FUYU_INFORMATION_CREATION_CALLBACKS_HPP
