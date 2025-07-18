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

#ifndef FUBUKI_FUYU_FUNCTIONS_SURFACE_HPP
#define FUBUKI_FUYU_FUNCTIONS_SURFACE_HPP

#include <core/config/macros.hpp>
#include <core/small_vector.hpp>
#include <core/validate.hpp>

#include "fuyu/views/surface.hpp"

namespace fubuki::fuyu
{

#if defined(VK_KHR_surface)

/// Properties of a Vulkan surface (the formats it supports, the presentation modes, etc.).
struct surface_properties
{
    VkSurfaceCapabilitiesKHR         capabilities  = {}; ///< Suface capabilities.
    small_vector<VkSurfaceFormatKHR> formats       = {}; ///< Formats supported by a surface.
    small_vector<VkPresentModeKHR>   present_modes = {}; ///< Present mode supported by a surface.
};

/**
 * Fetches the current capabilities of a surface.
 *
 * @returns The current surface capabilities, or the call that failed during the fetch.
 */
[[nodiscard]] FUBUKI_FUYU_API std::expected<VkSurfaceCapabilitiesKHR, api_call_info> capabilities(physical_device_handle physical_device,
                                                                                                  fuyu::surface_view     s) noexcept;

/**
 * Fetches formats supported by a surface.
 *
 * @returns The current surface capabilities, or the call that failed during the fetch.
 * @throws std::bad_alloc This function CAN throw an instance of std::bad_alloc if host resource allocation failed.
 */
[[nodiscard]] FUBUKI_FUYU_API std::expected<small_vector<VkSurfaceFormatKHR>, api_call_info> formats(physical_device_handle physical_device,
                                                                                                     fuyu::surface_view     s);

/**
 * Fetches present modes supported for a surface.
 *
 * @returns The current surface capabilities, or the call that failed during the fetch.
 * @throws std::bad_alloc This function CAN throw an instance of std::bad_alloc if host resource allocation failed.
 */
[[nodiscard]] FUBUKI_FUYU_API std::expected<small_vector<VkPresentModeKHR>, api_call_info> present_modes(physical_device_handle physical_device,
                                                                                                         fuyu::surface_view     s);

/**
 * Fetches all the properties of a surface.
 *
 * @returns The current surface capabilities, or the call that failed during the fetch.
 * @throws std::bad_alloc This function CAN throw an instance of std::bad_alloc if host resource allocation failed.
 */
[[nodiscard]] FUBUKI_FUYU_API std::expected<fuyu::surface_properties, api_call_info> properties(physical_device_handle physical_device,
                                                                                                fuyu::surface_view     s);

#endif // defined(VK_KHR_surface)

} // namespace fubuki::fuyu

#endif // FUBUKI_FUYU_FUNCTIONS_SURFACE_HPP
