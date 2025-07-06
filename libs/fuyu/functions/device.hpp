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

#ifndef FUBUKI_FUYU_FUNCTIONS_DEVICE_HPP
#define FUBUKI_FUYU_FUNCTIONS_DEVICE_HPP

#include <core/functions/device_core.hpp>
#include <core/handle.hpp>
#include <core/vulkan.hpp>
#include <extension/functions/device_ext.hpp>

#include "fuyu/views/instance.hpp"

namespace fubuki::fuyu
{

/// Device function pointers for both core and extension functions.
struct device_functions
{
    fubuki::device_core_functions core = {}; ///< Core function pointers.
    fubuki::device_ext_functions  ext  = {}; ///< Extension function pointers.

    [[nodiscard]] operator const fubuki::device_core_functions&() const noexcept { return core; }
    [[nodiscard]] operator const fubuki::device_ext_functions&() const noexcept { return ext; }
};

/**
 * Loads device core  function pointers.
 * @param instance The device instance.
 * @param device The device which function pointers must be loaded.
 * @pre 'device' must has been allocated on 'instance'.
 */
inline void load(device_functions& funcs, instance_view instance, device_handle device) noexcept
{
    funcs.core = fubuki::load(instance.handle, instance.version, device);
}

/// Loads an extension functions, if Fubuki supports it.
/// @throws CAN throw an instance of std::bad_alloc.
[[nodiscard]]
inline bool load(device_functions& functions, instance_view instance, device_handle device, std::string_view extension)
{
    return fubuki::extension::load(functions.ext, instance.handle, instance.version, device, extension);
}

} // namespace fubuki::fuyu

#endif // FUBUKI_FUYU_FUNCTIONS_DEVICE_HPP
