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

#ifndef FUBUKI_FUYU_VIEWS_GRAPHICS_PIPELINE_HPP
#define FUBUKI_FUYU_VIEWS_GRAPHICS_PIPELINE_HPP

#include <functional>

#include <core/handle.hpp>

#include "fuyu/views/device_ref.hpp"

namespace fubuki::fuyu
{

namespace views
{

// NOLINTBEGIN(cppcoreguidelines-pro-type-member-init)
struct graphics_pipeline
{
    graphics_pipeline_handle handle = {}; ///< Graphics pipeline handle.
    device_cref              device;      ///< Device the handle comes from.
    pipeline_cache_handle    cache  = {}; ///< The pipeline cache used to create this pipeline.
    pipeline_layout_handle   layout = {}; ///< The pipeline layout this pipeline uses.

    [[nodiscard]] constexpr operator graphics_pipeline_handle() const noexcept { return handle; }

    [[nodiscard]] friend constexpr bool operator==(const graphics_pipeline& a, const graphics_pipeline& b) noexcept { return a.handle == b.handle; }
    [[nodiscard]] friend constexpr bool operator!=(const graphics_pipeline& a, const graphics_pipeline& b) noexcept { return a.handle != b.handle; }
    [[nodiscard]] friend constexpr auto operator<=>(const graphics_pipeline& a, const graphics_pipeline& b) noexcept { return a.handle <=> b.handle; }
};
// NOLINTEND(cppcoreguidelines-pro-type-member-init)

} // namespace views

using graphics_pipeline_view = views::graphics_pipeline;

} // namespace fubuki::fuyu

namespace std
{

template<>
struct hash<fubuki::fuyu::graphics_pipeline_view>
{
    [[nodiscard]] auto operator()(const fubuki::fuyu::graphics_pipeline_view& v) const noexcept
    {
        return std::hash<decltype(v.handle.vk)>{}(v.handle.vk);
    }
};

} // namespace std

#endif // FUBUKI_FUYU_VIEWS_GRAPHICS_PIPELINE_HPP
