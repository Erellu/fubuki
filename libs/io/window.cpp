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

#if defined(_WIN32)
    #include <io/platform/win32/window.hpp>
#elif defined(__unix__)
    #include <io/platform/linux/window.hpp>
#endif

#include "io/window.hpp"

namespace fubuki::io
{

/********************************************************************************/
/*                           PRIVATE MEMBER TYPES                               */
/********************************************************************************/

struct window::implementation
{
    implementation(platform::current::window win) noexcept : w{std::move(win)} {}

    implementation(platform::views::display d, information info) noexcept : w(d, std::move(info)) {}

    static std::expected<std::unique_ptr<implementation>, platform::error::api_call> make_unique(platform::views::display d,
                                                                                                 information              info) noexcept
    {
        auto window = platform::current::window::make(d, std::move(info));

        if(not window)
        {
            return std::unexpected{window.error()};
        }

        return std::make_unique<implementation>(*std::move(window));
    }

    platform::current::window w;
};

/********************************************************************************/
/*                    CONSTRUCTION, ASSIGNEMENT, DESTRUCTION                    */
/********************************************************************************/

window::window(token) noexcept {}

window::window(platform::views::display parent, information info) : m_implementation{std::make_unique<implementation>(parent, std::move(info))} {}

[[nodiscard]] std::expected<window, platform::error::api_call> window::make(platform::views::display parent, information info) noexcept
{
    window result{token{}};

    auto impl = implementation::make_unique(parent, std::move(info));

    if(not impl)
    {
        return std::unexpected{impl.error()};
    }

    result.m_implementation = *std::move(impl);

    return result;
}

window::~window() noexcept = default;

window::window(window&& other) noexcept : m_implementation{std::move(other.m_implementation)} {}

window& window::operator=(window&& other) noexcept
{
    m_implementation = std::move(other.m_implementation);
    return *this;
}

/********************************************************************************/
/*                              ACCESSORS, MUTATORS                             */
/********************************************************************************/

[[nodiscard]] FUBUKI_SEMI_PURE platform::current::surface_handle window::handle() const noexcept { return m_implementation->w.handle(); }
[[nodiscard]] FUBUKI_SEMI_PURE platform::current::platform_data window::platform_data() const noexcept { return m_implementation->w.platform_data(); }
[[nodiscard]] FUBUKI_SEMI_PURE surface_data                     window::data() const noexcept { return m_implementation->w.data(); }
[[nodiscard]] FUBUKI_SEMI_PURE const window::information& window::info() const noexcept { return m_implementation->w.info(); }
[[nodiscard]] FUBUKI_SEMI_PURE const window_state&        window::state() const noexcept { return m_implementation->w.state(); }

//------------------------------------------------------------------------------

[[nodiscard]] FUBUKI_SEMI_PURE event::dispatcher& window::event_dispatcher() noexcept { return m_implementation->w.event_dispatcher(); }
[[nodiscard]] FUBUKI_SEMI_PURE const event::dispatcher& window::event_dispatcher() const noexcept { return m_implementation->w.event_dispatcher(); }
[[nodiscard]] FUBUKI_SEMI_PURE const platform::current::window& window::underlying() const { return m_implementation->w; }
[[nodiscard]] FUBUKI_SEMI_PURE platform::views::display window::parent() const noexcept { return m_implementation->w.parent(); }

/********************************************************************************/
/*                          PUBLIC MEMBER FUNCTIONS                             */
/********************************************************************************/

std::expected<void, platform::error::any> window::show() noexcept { return m_implementation->w.show(); }
std::expected<void, platform::error::any> window::hide() noexcept { return m_implementation->w.hide(); }
std::expected<void, platform::error::any> window::close() noexcept { return m_implementation->w.close(); }
std::expected<void, platform::error::any> window::enable(bool b) noexcept { return m_implementation->w.enable(b); }
std::expected<void, platform::error::any> window::set_opacity(float o) noexcept { return m_implementation->w.set_opacity(o); }
std::expected<void, platform::error::any> window::move(position2d p) noexcept { return m_implementation->w.move(p); }
std::expected<void, platform::error::any> window::resize(dimension2d d) noexcept { return m_implementation->w.resize(d); }
std::expected<void, platform::error::any> window::rename(std::string s) { return m_implementation->w.rename(std::move(s)); }

void window::swap(window& other) noexcept { m_implementation.swap(other.m_implementation); }

} // namespace fubuki::io
