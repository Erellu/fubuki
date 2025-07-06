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

#ifndef FUBUKI_FUYU_VIEWS_OWNING_HPP
#define FUBUKI_FUYU_VIEWS_OWNING_HPP

#include <optional>

namespace fubuki::fuyu
{

namespace views
{

/// Wrapper struct indicating the view it contains owns a Vulkan resource.
/// Instances of this object are obtained by calling release() on fuyu RAII object (fuyu::buffer, fuyu::image, etc.).
/// Use this intermediate struct to:
/// - transfer to ownership to another API
/// - when calling vkResetStuff on pools (command buffer pools, descriptor pools, etc.) to handle the lifetime of associated handles.
template<typename view_type>
struct owning
{
    /// Vulkan handle and information about how it was created owned by this object.
    /// It is NOT freed upon destruction: the caller is responsible to manage its lifetime.
    std::optional<view_type> value = {};
};

} // namespace views

template<typename view_type>
using owning_view = views::owning<view_type>;

} // namespace fubuki::fuyu

#endif // FUBUKI_FUYU_VIEWS_OWNING_HPP
