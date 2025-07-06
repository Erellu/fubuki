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

#include <map>
#include <mutex>

#include "io/platform/linux/window_registry.hpp"

#include "io/platform/linux/wayland/interface.hpp"
#include "io/platform/linux/wayland/window.hpp" // IWYU pragma: keep (false positive, required for remove_closed())
#include "io/platform/linux/xlib/window.hpp"    // IWYU pragma: keep (false positive, required for remove_closed())

#include <X11/Xlib.h>

namespace fubuki::io::platform::linux_bsd::window_registry
{

namespace
{

struct sync
{
    std::mutex access;
};

auto& synchro()
{
    static sync m = {};
    return m;
}

auto& windows()
{
    static std::map<surface_handle, window_ref> m;
    return m;
}

} // anonymous namespace

[[nodiscard]]
std::size_t size() noexcept
{
    const std::scoped_lock<std::mutex> lock(synchro().access);
    return windows().size();
}

[[nodiscard]] bool empty() noexcept
{
    const std::scoped_lock<std::mutex> lock(synchro().access);
    return windows().empty();
}

void add(surface_handle data, window_ref w) noexcept
{
    const std::scoped_lock<std::mutex> lock(synchro().access);
    [[maybe_unused]] const auto        r = windows().insert({data, w});

    fubuki_always_assert(r.second,
                         "Internal error: failed to add window - window_registry::add probably shouldn't have been called. Please submit an issue at "
                         "https://github.com/Erellu/fubuki/issues");
}

void swap(surface_handle data, window_ref w) noexcept
{
    const std::scoped_lock<std::mutex> lock(synchro().access);

    if(auto it = windows().find(data); it != windows().end())
    {
        it->second = w;
    }
}

void remove(surface_handle data) noexcept
{
    const std::scoped_lock<std::mutex> lock(synchro().access);
    windows().erase(data);
}

[[nodiscard]]
std::size_t remove_closed() noexcept
{
    const std::scoped_lock<std::mutex> lock(synchro().access);

    std::erase_if(windows(),
                  [](const std::pair<surface_handle, window_ref>& e) noexcept -> bool
                  { return std::visit([](const auto& w) noexcept -> bool { return w.get().state().closed; }, e.second); });

    return windows().size();
}

void clear()
{
    const std::scoped_lock<std::mutex> lock(synchro().access);
    windows().clear();
}

[[nodiscard]] std::optional<window_ref> window_of(surface_handle data) noexcept
{
    const std::scoped_lock<std::mutex> lock(synchro().access);

    if(const auto it = windows().find(data); it != windows().end())
    {
        return it->second;
    }

    return std::nullopt;
}

[[nodiscard]] bool event_pending(platform::views::display d) noexcept
{
    using dp = platform::views::display;

    if(const auto* const xlib_display = std::get_if<dp::xlib>(std::addressof(d.value)))
    {
        return XPending(xlib_display->handle);
    }

    if(const auto* const wayland_display = std::get_if<dp::wayland>(std::addressof(d.value)))
    {
        // @see https://wayland.freedesktop.org/docs/html/apb.html#Client-classwl__display_1a040dca18775e3177883f06bd6fdf395f
        if(wl_display_prepare_read(wayland_display->handle) != -1)
        {
            wl_display_cancel_read(wayland_display->handle);
            return false;
        }

        return true;
    }

    return false;
}

} // namespace fubuki::io::platform::linux_bsd::window_registry
