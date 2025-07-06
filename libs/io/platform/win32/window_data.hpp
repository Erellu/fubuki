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

#ifndef FUBUKI_IO_PLATFORM_WIN32_WINDOW_DATA_HPP
#define FUBUKI_IO_PLATFORM_WIN32_WINDOW_DATA_HPP

#include <string>

#include <core/config/macros.hpp>
#include <core/detail/platform_forward.hpp>

namespace fubuki::io::platform::win32
{

/// Makes a unique class identifier for Windows API.
[[nodiscard]] FUBUKI_IO_PLATFORM_API std::string make_class_id();

/// Gets the default module handle, equivalent to Windows's API ::GetModuleHandle(nullptr).
[[nodiscard]] FUBUKI_IO_PLATFORM_API HINSTANCE module_handle() noexcept;

//------------------------------------------------------------------------------

struct window_data
{
    HINSTANCE   hinstance  = module_handle(); ///< Underlying hinstance, i.e. file used to create the process (executable).
    HWND        hwnd       = nullptr;         ///< Underlying window handle.
    std::string class_name = make_class_id(); ///< Windows API class name.

    void swap(window_data& other) noexcept
    {
        std::swap(hinstance, other.hinstance);
        std::swap(hwnd, other.hwnd);
        class_name.swap(other.class_name);
    }

    friend void swap(window_data& a, window_data& b) noexcept { a.swap(b); }
};

} // namespace fubuki::io::platform::win32

#endif // FUBUKI_IO_PLATFORM_WIN32_WINDOW_DATA_HPP
