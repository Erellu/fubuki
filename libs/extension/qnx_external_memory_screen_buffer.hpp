﻿/*
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

#ifndef FUBUKI_EXTENSION_QNX_EXTERNAL_MEMORY_SCREEN_BUFFER_HPP
#define FUBUKI_EXTENSION_QNX_EXTERNAL_MEMORY_SCREEN_BUFFER_HPP

#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/validate.hpp>
#include <core/vulkan.hpp>

#include "extension/functions/qnx_external_memory_screen_buffer.hpp" // IWYU pragma: export

namespace fubuki::extension::qnx_external_memory_screen_buffer
{

#if defined(VK_QNX_external_memory_screen_buffer)

///@see https://registry.khronos.org/vulkan/specs/latest/man/html/vkGetScreenBufferPropertiesQNX.html
[[nodiscard]] FUBUKI_EXTENSION_API std::expected<void, api_call_info> get_screen_buffer_properties(const functions&             ext,
                                                                                                   device_handle                device,
                                                                                                   const _screen_buffer*        buffer,
                                                                                                   VkScreenBufferPropertiesQNX& properties) noexcept;

#endif // defined(VK_QNX_external_memory_screen_buffer)

} // namespace fubuki::extension::qnx_external_memory_screen_buffer

#endif // FUBUKI_EXTENSION_QNX_EXTERNAL_MEMORY_SCREEN_BUFFER_HPP
