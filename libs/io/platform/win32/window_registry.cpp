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

#include "io/platform/win32/window_registry.hpp"

#include "io/platform/win32/window.hpp" // IWYU pragma: keep (false positive, required for remove_closed())

#include <windows.h>

namespace fubuki::io::platform::win32::window_registry
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

bool empty() noexcept
{
    const std::scoped_lock<std::mutex> lock(synchro().access);
    return windows().empty();
}

void add(surface_handle h, window_ref w) noexcept
{
    const std::scoped_lock<std::mutex> lock(synchro().access);
    [[maybe_unused]] const auto        r = windows().insert({h, w});

    fubuki_always_assert(r.second,
                         "Internal error: failed to add window - window_registry::add probably shouldn't have been called. Please submit an issue at "
                         "https://github.com/Erellu/fubuki/issues");
}

void swap(surface_handle h, window_ref w) noexcept
{
    const std::scoped_lock<std::mutex> lock(synchro().access);

    if(auto it = windows().find(h); it != windows().end())
    {
        it->second = w;
    }
}

void remove(surface_handle h) noexcept
{
    const std::scoped_lock<std::mutex> lock(synchro().access);
    windows().erase(h);
}

void clear() noexcept
{
    const std::scoped_lock<std::mutex> lock(synchro().access);
    windows().clear();
}

[[nodiscard]]
std::size_t remove_closed() noexcept
{
    const std::scoped_lock<std::mutex> lock(synchro().access);

    std::erase_if(windows(), [](auto& w) noexcept { return w.second.get().state().closed; });

    return windows().size();
}

[[nodiscard]]
std::optional<window_ref> window_of(surface_handle hwnd) noexcept
{
    const std::scoped_lock<std::mutex> lock(synchro().access);

    if(const auto it = windows().find(hwnd); it != windows().end())
    {
        return it->second;
    }

    return std::nullopt;
}

[[nodiscard]] std::optional<int> peek_messages() noexcept
{
    if(MSG msg{}; PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE) >= 0)
    {
        if(msg.message == WM_QUIT)
        {
            window_registry::clear();
            return static_cast<int>(msg.wParam);
        }

        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return {};
}

[[nodiscard]] bool event_pending(platform::views::display) noexcept
{
    if(MSG msg{}; PeekMessage(&msg, nullptr, 0, 0, PM_NOREMOVE) >= 0)
    {
        return true;
    }

    return false;
}

} // namespace fubuki::io::platform::win32::window_registry
