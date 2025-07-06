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

#ifndef FUBUKI_EXTENSION_FUNCTION_FUCHSIA_EXTERNAL_SEMAPHORE_HPP
#define FUBUKI_EXTENSION_FUNCTION_FUCHSIA_EXTERNAL_SEMAPHORE_HPP

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

struct fuchsia_external_semaphore
{
#if defined(VK_FUCHSIA_external_semaphore)

    struct command
    {
    };

    PFN_vkImportSemaphoreZirconHandleFUCHSIA import_semaphore_zircon_handle_fuchsia = nullptr;
    PFN_vkGetSemaphoreZirconHandleFUCHSIA    get_semaphore_zircon_handle_fuchsia    = nullptr;

    command cmd = {};

#endif // defined(VK_FUCHSIA_external_semaphore)

    /// Loads the extension.
    [[nodiscard]] FUBUKI_EXTENSION_API static fuchsia_external_semaphore
    load([[maybe_unused]] instance_handle instance, [[maybe_unused]] version_number vk_version, [[maybe_unused]] device_handle device) noexcept;
};

} // namespace functions

/**
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/VK_FUCHSIA_external_semaphore.html
 */
namespace fuchsia_external_semaphore
{

/// Name of the extension.
inline constexpr auto name = "VK_FUCHSIA_external_semaphore";

using functions = extension::functions::fuchsia_external_semaphore;

/// Loads the extension.
[[nodiscard]] inline functions
load([[maybe_unused]] instance_handle instance, [[maybe_unused]] version_number vk_version, [[maybe_unused]] device_handle device) noexcept
{
    return functions::load(instance, vk_version, device);
}

} // namespace fuchsia_external_semaphore

} // namespace extension

namespace detail
{

template<typename functions_type, fubuki::detail::vk_function_hash pfn>
struct get_from;

/// An helper struct to retrieve the correct member of a extension::functions::fuchsia_external_semaphore struct knowing its name in Vulkan.
template<fubuki::detail::vk_function_hash pfn>
struct get_from<extension::functions::fuchsia_external_semaphore, pfn>
{
    static constexpr auto valid = false;

    [[nodiscard]] constexpr static std::nullptr_t get(const extension::functions::fuchsia_external_semaphore&) noexcept
    {
        return nullptr; // Invalid generic specialisation to trigger a compile error
    }
};

#if defined(FUBUKI_MAKE_GET_FROM)
    #error Internal error. Should not be defined.
#endif

#define FUBUKI_MAKE_GET_FROM(vk_function_name, fubuki_name)                                                                  \
    template<>                                                                                                               \
    struct get_from<extension::functions::fuchsia_external_semaphore, #vk_function_name>                                     \
    {                                                                                                                        \
        static constexpr bool valid = true;                                                                                  \
                                                                                                                             \
        [[nodiscard]] constexpr static auto* get(const extension::functions::fuchsia_external_semaphore& functions) noexcept \
        {                                                                                                                    \
            static_assert(                                                                                                   \
                requires {                                                                                                   \
                    {                                                                                                        \
                        functions.fubuki_name                                                                                \
                    };                                                                                                       \
                }, "Internal error. Bad name or version structure.");                                                        \
                                                                                                                             \
            auto pfn = functions.fubuki_name;                                                                                \
                                                                                                                             \
            using expected_pfn_type = PFN_##vk_function_name;                                                                \
            using pfn_type          = std::decay_t<decltype(pfn)>;                                                           \
                                                                                                                             \
            static_assert(std::is_same_v<pfn_type, expected_pfn_type>, "Internal error. Type mismatch.");                    \
                                                                                                                             \
            return pfn;                                                                                                      \
        }                                                                                                                    \
    }

#if defined(VK_FUCHSIA_external_semaphore)
FUBUKI_MAKE_GET_FROM(vkImportSemaphoreZirconHandleFUCHSIA, import_semaphore_zircon_handle_fuchsia);
FUBUKI_MAKE_GET_FROM(vkGetSemaphoreZirconHandleFUCHSIA, get_semaphore_zircon_handle_fuchsia);

#endif // defined(VK_FUCHSIA_external_semaphore)

#undef FUBUKI_MAKE_GET_FROM

} // namespace detail

} // namespace fubuki

#endif // FUBUKI_EXTENSION_FUCHSIA_EXTERNAL_SEMAPHORE_HPP
