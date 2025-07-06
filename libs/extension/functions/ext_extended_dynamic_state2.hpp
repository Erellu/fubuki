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

#ifndef FUBUKI_EXTENSION_FUNCTION_EXT_EXTENDED_DYNAMIC_STATE2_HPP
#define FUBUKI_EXTENSION_FUNCTION_EXT_EXTENDED_DYNAMIC_STATE2_HPP

#include <core/config/macros.hpp>
#include <core/detail/pfn.hpp>
#include <core/handle.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

namespace fubuki
{

namespace extension
{

namespace functions
{

struct ext_extended_dynamic_state2
{
#if defined(VK_EXT_extended_dynamic_state2)

    struct command
    {
        PFN_vkCmdSetPatchControlPointsEXT      set_patch_control_points_ext      = nullptr;
        PFN_vkCmdSetRasterizerDiscardEnableEXT set_rasterizer_discard_enable_ext = nullptr;
        PFN_vkCmdSetDepthBiasEnableEXT         set_depth_bias_enable_ext         = nullptr;
        PFN_vkCmdSetLogicOpEXT                 set_logic_op_ext                  = nullptr;
        PFN_vkCmdSetPrimitiveRestartEnableEXT  set_primitive_restart_enable_ext  = nullptr;
    };

    command cmd = {};

#endif // defined(VK_EXT_extended_dynamic_state2)

    /// Loads the extension.
    [[nodiscard]] FUBUKI_EXTENSION_API static ext_extended_dynamic_state2
    load([[maybe_unused]] instance_handle instance, [[maybe_unused]] version_number vk_version, [[maybe_unused]] device_handle device) noexcept;
};

} // namespace functions

/**
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/VK_EXT_extended_dynamic_state2.html
 */
namespace ext_extended_dynamic_state2
{

/// Name of the extension.
inline constexpr auto name = "VK_EXT_extended_dynamic_state2";

using functions = extension::functions::ext_extended_dynamic_state2;

/// Loads the extension.
[[nodiscard]] inline functions
load([[maybe_unused]] instance_handle instance, [[maybe_unused]] version_number vk_version, [[maybe_unused]] device_handle device) noexcept
{
    return functions::load(instance, vk_version, device);
}

} // namespace ext_extended_dynamic_state2

} // namespace extension

namespace detail
{

template<typename functions_type, fubuki::detail::vk_function_hash pfn>
struct get_from;

/// An helper struct to retrieve the correct member of a extension::functions::ext_extended_dynamic_state2 struct knowing its name in Vulkan.
template<fubuki::detail::vk_function_hash pfn>
struct get_from<extension::functions::ext_extended_dynamic_state2, pfn>
{
    static constexpr auto valid = false;

    [[nodiscard]] constexpr static std::nullptr_t get(const extension::functions::ext_extended_dynamic_state2&) noexcept
    {
        return nullptr; // Invalid generic specialisation to trigger a compile error
    }
};

#if defined(FUBUKI_MAKE_GET_FROM)
    #error Internal error. Should not be defined.
#endif

#define FUBUKI_MAKE_GET_FROM(vk_function_name, fubuki_name)                                                                   \
    template<>                                                                                                                \
    struct get_from<extension::functions::ext_extended_dynamic_state2, #vk_function_name>                                     \
    {                                                                                                                         \
        static constexpr bool valid = true;                                                                                   \
                                                                                                                              \
        [[nodiscard]] constexpr static auto* get(const extension::functions::ext_extended_dynamic_state2& functions) noexcept \
        {                                                                                                                     \
            static_assert(                                                                                                    \
                requires {                                                                                                    \
                    {                                                                                                         \
                        functions.fubuki_name                                                                                 \
                    };                                                                                                        \
                }, "Internal error. Bad name or version structure.");                                                         \
                                                                                                                              \
            auto pfn = functions.fubuki_name;                                                                                 \
                                                                                                                              \
            using expected_pfn_type = PFN_##vk_function_name;                                                                 \
            using pfn_type          = std::decay_t<decltype(pfn)>;                                                            \
                                                                                                                              \
            static_assert(std::is_same_v<pfn_type, expected_pfn_type>, "Internal error. Type mismatch.");                     \
                                                                                                                              \
            return pfn;                                                                                                       \
        }                                                                                                                     \
    }

#if defined(VK_EXT_extended_dynamic_state2)
FUBUKI_MAKE_GET_FROM(vkCmdSetPatchControlPointsEXT, cmd.set_patch_control_points_ext);
FUBUKI_MAKE_GET_FROM(vkCmdSetRasterizerDiscardEnableEXT, cmd.set_rasterizer_discard_enable_ext);
FUBUKI_MAKE_GET_FROM(vkCmdSetDepthBiasEnableEXT, cmd.set_depth_bias_enable_ext);
FUBUKI_MAKE_GET_FROM(vkCmdSetLogicOpEXT, cmd.set_logic_op_ext);
FUBUKI_MAKE_GET_FROM(vkCmdSetPrimitiveRestartEnableEXT, cmd.set_primitive_restart_enable_ext);

#endif // defined(VK_EXT_extended_dynamic_state2)

#undef FUBUKI_MAKE_GET_FROM

} // namespace detail

} // namespace fubuki

#endif // FUBUKI_EXTENSION_EXT_EXTENDED_DYNAMIC_STATE2_HPP
