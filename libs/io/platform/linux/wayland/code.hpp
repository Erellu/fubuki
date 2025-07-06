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

#ifndef FUBUKI_IO_PLATFORM_LINUX_WAYLAND_CODE_HPP
#define FUBUKI_IO_PLATFORM_LINUX_WAYLAND_CODE_HPP

#include <ostream>
#include <utility>
#include <variant>

namespace fubuki::io::platform::linux_bsd::wayland
{

namespace code
{

enum class success
{
};

enum class display
{
    invalid_object = 0,
    invalid_method = 1,
    no_memory      = 2,
    implementation = 3,
    unknown,
};

enum class shm
{
    invalid_format = 0,
    invalid_stride = 1,
    invalid_fd     = 2,
    unknown,
};

enum class data_offer
{
    invalid_finish      = 0,
    invalid_action_mask = 1,
    invalid_action      = 2,
    invalid_offer       = 3,
    unknown,
};

enum class source
{
    invalid_action_mask = 0,
    invalid_source      = 1,
    unknown,
};

enum class data_device
{
    invalid_data_role = 0,
    unknown,
};

enum class shell
{
    role = 0,
    unknown,
};

enum class surface
{
    invalid_scale       = 0,
    invalid_transform   = 1,
    invalid_size        = 2,
    invalid_offset      = 3,
    invalid_role_object = 4,
    unknown,
};

enum class seat
{
    missing_capability = 0,
    unknown,
};

enum class pointer
{
    role = 0,
    unknown,
};

enum class subcompositor
{
    bad_surface = 0,
    bad_parent  = 1,
    unknown,
};

enum class subsurface
{
    bad_surface = 0,
    unknown,
};

/// Error codes Fubuki doesn't use or isn't aware of.
enum class unknown
{
};

template<typename char_type, typename traits = std::char_traits<char_type>>
inline std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, display c)
{
    switch(c)
    {
        case display::invalid_object: return out << "wayland::code::display::invalid_object";
        case display::invalid_method: return out << "wayland::code::display::invalid_method";
        case display::no_memory     : return out << "wayland::code::display::no_memory";
        case display::implementation: return out << "wayland::code::display::implementation";
        case display::unknown       :
        default                     : return out << "wayland::code::display::unknown";
    }
}

template<typename char_type, typename traits = std::char_traits<char_type>>
inline std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, shm c)
{
    switch(c)
    {

        case shm::invalid_format: return out << "wayland::code::shm::invalid_format";
        case shm::invalid_stride: return out << "wayland::code::shm::invalid_stride";
        case shm::invalid_fd    : return out << "wayland::code::shm::invalid_fd";
        case shm::unknown       :
        default                 : return out << "wayland::code::shm::unknown";
    }
}

template<typename char_type, typename traits = std::char_traits<char_type>>
inline std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, data_offer c)
{
    switch(c)
    {
        case data_offer::invalid_finish     : return out << "wayland::code::data_offer::invalid_finish";
        case data_offer::invalid_action_mask: return out << "wayland::code::data_offer::invalid_action_mask";
        case data_offer::invalid_action     : return out << "wayland::code::data_offer::invalid_action";
        case data_offer::invalid_offer      : return out << "wayland::code::data_offer::invalid_offer";
        case data_offer::unknown            :
        default                             : return out << "wayland::code::data_offer::unknown";
    }
}

template<typename char_type, typename traits = std::char_traits<char_type>>
inline std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, source c)
{
    switch(c)
    {
        case source::invalid_action_mask: return out << "wayland::code::source::invalid_action_mask";
        case source::invalid_source     : return out << "wayland::code::source::invalid_source";
        case source::unknown            :
        default                         : return out << "wayland::code::source::unknown";
    }
}

template<typename char_type, typename traits = std::char_traits<char_type>>
inline std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, data_device c)
{
    switch(c)
    {
        case data_device::invalid_data_role: return out << "wayland::code::data_device::invalid_data_role";
        case data_device::unknown          :
        default                            : return out << "wayland::code::data_device::unknown";
    }
}

template<typename char_type, typename traits = std::char_traits<char_type>>
inline std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, shell c)
{
    switch(c)
    {
        case shell::role   : return out << "wayland::code::shell::role";
        case shell::unknown:
        default            : return out << "wayland::code::shell::unknown";
    }
}

template<typename char_type, typename traits = std::char_traits<char_type>>
inline std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, surface c)
{
    switch(c)
    {
        case surface::invalid_scale      : return out << "wayland::code::surface::invalid_scale";
        case surface::invalid_transform  : return out << "wayland::code::surface::invalid_transform";
        case surface::invalid_size       : return out << "wayland::code::surface::invalid_size";
        case surface::invalid_offset     : return out << "wayland::code::surface::invalid_offset";
        case surface::invalid_role_object: return out << "wayland::code::surface::invalid_role_object";
        case surface::unknown            :
        default                          : return out << "wayland::code::surface::unknown";
    }
}

template<typename char_type, typename traits = std::char_traits<char_type>>
inline std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, seat c)
{
    switch(c)
    {
        case seat::missing_capability: return out << "wayland::code::surface::missing_capability";
        case seat::unknown           :
        default                      : return out << "wayland::code::seat::unknown";
    }
}

template<typename char_type, typename traits = std::char_traits<char_type>>
inline std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, pointer c)
{
    switch(c)
    {
        case pointer::role   : return out << "wayland::code::pointer::role";
        case pointer::unknown:
        default              : return out << "wayland::code::pointer::unknown";
    }
}

template<typename char_type, typename traits = std::char_traits<char_type>>
inline std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, subcompositor c)
{
    switch(c)
    {
        case subcompositor::bad_surface: return out << "wayland::code::subcompositor::bad_surface";
        case subcompositor::bad_parent : return out << "wayland::code::subcompositor::bad_parent";
        case subcompositor::unknown    :
        default                        : return out << "wayland::code::subcompositor::unknown";
    }
}

template<typename char_type, typename traits = std::char_traits<char_type>>
inline std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, subsurface c)
{
    switch(c)
    {
        case subsurface::bad_surface: return out << "wayland::code::subsurface::bad_surface";
        case subsurface::unknown    :
        default                     : return out << "wayland::code::subsurface::unknown";
    }
}

template<typename char_type, typename traits = std::char_traits<char_type>>
inline std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, success)
{
    return out << "wayland::code::success{}";
}

template<typename char_type, typename traits = std::char_traits<char_type>>
inline std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, unknown c)
{
    return out << "wayland::code::unknown{" << std::to_underlying(c) << "}";
}

class any
{
public:
    using value_type
        = std::variant<success, unknown, display, shm, data_offer, source, data_device, shell, surface, seat, pointer, subcompositor, subsurface>;

    constexpr any(value_type v) noexcept : m_value{v} {}

    constexpr any(success v) noexcept : m_value{v} {}
    constexpr any(unknown v) noexcept : m_value{v} {}
    constexpr any(display v) noexcept : m_value{v} {}
    constexpr any(shm v) noexcept : m_value{v} {}
    constexpr any(source v) noexcept : m_value{v} {}
    constexpr any(data_device v) noexcept : m_value{v} {}
    constexpr any(shell v) noexcept : m_value{v} {}
    constexpr any(surface v) noexcept : m_value{v} {}
    constexpr any(seat v) noexcept : m_value{v} {}
    constexpr any(pointer v) noexcept : m_value{v} {}
    constexpr any(subcompositor v) noexcept : m_value{v} {}
    constexpr any(subsurface v) noexcept : m_value{v} {}

    constexpr any() noexcept                      = default;
    constexpr any(const any&) noexcept            = default;
    constexpr any(any&&) noexcept                 = default;
    constexpr any& operator=(const any&) noexcept = default;
    constexpr any& operator=(any&&) noexcept      = default;
    constexpr ~any() noexcept                     = default;

    [[nodiscard]] constexpr const auto& value() const noexcept { return m_value; }

    [[nodiscard]] constexpr operator bool() const noexcept { return std::holds_alternative<code::success>(m_value); }

    template<typename char_type, typename traits = std::char_traits<char_type>>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const any& c)
    {
        return std::visit([&out](const auto& var) -> std::basic_ostream<char_type, traits>& { return out << var; }, c.m_value);
    }

private:
    value_type m_value = {};
};

} // namespace code

struct result
{
    code::any c = {};

    [[nodiscard]] friend constexpr bool operator==(const result& a, const result& b) noexcept  = default;
    [[nodiscard]] friend constexpr bool operator!=(const result& a, const result& b) noexcept  = default;
    [[nodiscard]] friend constexpr auto operator<=>(const result& a, const result& b) noexcept = default;

    [[nodiscard]] constexpr operator bool() const noexcept { return c.operator bool(); }

    template<typename char_type, typename traits = std::char_traits<char_type>>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const result& r)
    {
        return out << "wayland::result{" << r.c << "}";
    }
};

} // namespace fubuki::io::platform::linux_bsd::wayland

#endif // FUBUKI_IO_PLATFORM_LINUX_WAYLAND_CODE_HPP
