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

#ifndef FUBUKI_FUYU_FUNCTIONS_INSTANCE_HPP
#define FUBUKI_FUYU_FUNCTIONS_INSTANCE_HPP

#include <core/functions/instance_core.hpp>
#include <core/handle.hpp>
#include <core/vulkan.hpp>
#include <extension/functions/instance_ext.hpp>

namespace fubuki::fuyu
{

/// Instance function pointers for both core and extension functions.
struct instance_functions
{
    fubuki::instance_core_functions core = {}; ///< Core function pointers.
    fubuki::instance_ext_functions  ext  = {}; ///< Extension function pointers.

    [[nodiscard]] operator const fubuki::instance_core_functions&() const noexcept { return core; }
    [[nodiscard]] operator const fubuki::instance_ext_functions&() const noexcept { return ext; }
};

/**
 * Loads instance core  function pointers.
 * @param funcs The functions to load.
 * @param instance The instance which function pointers must be loaded.
 * @pre 'instance' must has been allocated on 'instance'.
 */
inline void load(instance_functions& funcs, instance_handle instance, version_number version) noexcept
{
    funcs.core = fubuki::load(instance, version);
}

/// Loads an extension functions, if Fubuki supports it.
[[nodiscard]]
inline bool load(instance_functions& functions, instance_handle instance, version_number version, std::string_view extension)
{
    return fubuki::extension::load(functions.ext, instance, version, extension);
}

} // namespace fubuki::fuyu

#endif // FUBUKI_FUYU_FUNCTIONS_INSTANCE_HPP
