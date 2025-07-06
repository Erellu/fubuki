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

#include "context.hpp"
#include "validation.hpp"

#include <iostream>
#include <memory>

#include <fuyu/debug/messenger.hpp>
#include <fuyu/device.hpp>
#include <fuyu/hardware.hpp>
#include <fuyu/instance.hpp>
#include <fuyu/surface.hpp>
#include <io/display.hpp>
#include <io/window.hpp>

namespace fubuki::test::context
{

namespace
{

[[nodiscard]] auto instance_info()
{
    // clang-format off
    return fubuki::fuyu::instance::information
    {
        .application =
        {
            .name           = "core_test",
            .version        = {1, 0, 0},
            .vulkan_version = {1, 3, 0},
            .engine         =
            {
                .name    = "fubuki::fuyu",
                .version = {1, 3, 0}
            }
        },
        .flags      = {},
        .callbacks  = {}
    };
    // clang-format on
}

[[nodiscard]] auto first_physical_device(fuyu::instance_view instance)
{
    const auto physical_devices = fubuki::fuyu::hardware::physical_devices(instance);

    fubuki_assert(physical_devices.has_value(), "API call failed while enumerating devices: " << physical_devices.error());
    fubuki_assert(not physical_devices->empty(), "No GPU available for the tests :(.");

    return (*physical_devices)[0];
}

[[nodiscard]] auto instance_complement()
{
    // Obviously, it's insane to enable all extensions when they are not needed in a real application
    // But in unit tests, it allows to test things like pNext chains and similar.
    // DON'T DO THIS IN YOUR APPLICATION.

    auto ext = fubuki::fuyu::hardware::supported_instance_extensions();
    fubuki_assert(ext.has_value(), "API call failed while enumerating instance extensions: " << ext.error());

    return fubuki::fuyu::instance::information::complements{.layers = {"VK_LAYER_KHRONOS_validation"}, .extensions = std::move(ext)->names};
}

[[nodiscard]] auto device_complements(fuyu::instance_view instance, fuyu::surface_view surface)
{
    // Same remark as for instance_complements: obviously, you shouldn't load all available extensions in your application
    auto ext = fuyu::hardware::supported_extensions(instance, first_physical_device(instance));
    fubuki_assert(ext.has_value(), "API call failed while enumerating device extensions: " << ext.error());

    if(ext->names.contains("VK_KHR_buffer_device_address"))
    {
        ext->names.erase("VK_EXT_buffer_device_address"); // Both must not appear
    }

    // clang-format off
    return fubuki::fuyu::device::information::complements
    {
        .queues =
        {
            {
                .type      = VK_QUEUE_GRAPHICS_BIT,
                .flags     = {},
                .priority  = +0.f,
            },
            {
                .type      = VK_QUEUE_COMPUTE_BIT,
                .flags     = {},
                .priority  = +0.f,
            }
        },
        .extensions = std::move(ext)->names,
        .surfaces   = {surface},
        .features   = {},
    };
    // clang-format on
}

[[nodiscard]] constexpr auto debug_messenger_info() noexcept
{
    return fuyu::debug::messenger::information{
        .message{
                 .severity  = fuyu::debug::messenger::information::default_severity,
                 .type      = fuyu::debug::messenger::information::default_messages | VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT,
                 .callback  = validation_layer_callback,
                 .user_data = nullptr,
                 },
    };
}

class resources
{
public:

    resources(const resources&) = delete;
    resources(resources&&)      = delete;

    resources& operator=(const resources&) = delete;
    resources& operator=(resources&&)      = delete;

    ~resources() = default;

    static const auto& get() noexcept
    {
        static const resources rc;
        return rc;
    }

    [[nodiscard]] const fuyu::instance& instance() const noexcept
    {
        fubuki_always_assert(m_instance != nullptr, "Internal error. Should not happen.");
        return *m_instance;
    }

    [[nodiscard]] const fuyu::device& device() const noexcept
    {
        fubuki_always_assert(m_device != nullptr, "Internal error. Should not happen.");
        return *m_device;
    }

    [[nodiscard]] const fuyu::surface& surface() const noexcept
    {
        fubuki_always_assert(m_surface != nullptr, "Internal error. Should not happen.");
        return *m_surface;
    }

    [[nodiscard]] const fuyu::physical_device& physical_device() const noexcept { return m_physical_device; }

private:

    resources() noexcept
    {

        try
        {
            // Display
            {
                m_display = std::make_unique<io::display>();
            }

            // Window
            {
                m_window = std::make_unique<io::window>(*m_display,
                                                        io::window::information{
                                                            .title       = "Tutorial 02: Vulkan context",
                                                            .size        = {500, 500},
                                                            .coordinates = {0,   0  },
                                                            .opacity     = 0.f, // Don't show
                                                            .style       = fubuki::io::window_style::os_default,
                });

                std::ignore = m_window->hide();
            }

            // Instance
            {
                m_instance = std::make_unique<fuyu::instance>(instance_info(), instance_complement());
            }

            // Debug messenger, created BEFORE the device, because associated errors will be forwarded to the first executed test
            {
                m_debug_messenger = std::make_unique<fuyu::debug::messenger>(*m_instance, debug_messenger_info());
            }

            // Surface
            {
                m_surface = std::make_unique<fuyu::surface>(*m_instance, *m_window);
            }

            // Physical device
            {
                const auto physical_device      = first_physical_device(*m_instance);
                auto       physical_device_info = fubuki::fuyu::hardware::physical_device_information(*m_instance, physical_device);
                fubuki_always_assert(physical_device_info.has_value(),
                                     "API call failed while retrieving physical device information: " << physical_device_info.error());

                m_physical_device = *std::move(physical_device_info);
            }

            // Device
            {
                // Enable all core features supported by the device

                const fubuki::pnext_chain chain{
                    m_physical_device.features.vk11,
                    m_physical_device.features.vk12,
                    m_physical_device.features.vk13,
                };

                m_device = std::make_unique<fuyu::device>(
                    *m_instance, m_physical_device, fuyu::device::information{}, device_complements(*m_instance, *m_surface), chain);
            }
        }
        catch(const fubuki::api_call_exception& error)
        {
            std::cerr << "Error while creating the test context: " << error << "\n" << std::flush;
            std::terminate();
        }
        catch(const std::exception& e)
        {
            std::cerr << "Error while creating the test context (std::exception): " << e.what() << "\n" << std::flush;
            std::terminate();
        }
        catch(...)
        {
            std::cerr << "Error while creating the test context (unknown) \n" << std::flush;
            std::terminate();
        }
    }

    std::unique_ptr<io::display>            m_display;
    std::unique_ptr<io::window>             m_window;
    std::unique_ptr<fuyu::instance>         m_instance;
    std::unique_ptr<fuyu::surface>          m_surface;
    std::unique_ptr<fuyu::debug::messenger> m_debug_messenger;
    std::unique_ptr<fuyu::device>           m_device;

    fuyu::physical_device m_physical_device = {};
};

} // anonymous namespace

void init() noexcept { resources::get(); }

[[nodiscard]] const fuyu::instance&        instance() noexcept { return resources::get().instance(); }
[[nodiscard]] const fuyu::device&          device() noexcept { return resources::get().device(); }
[[nodiscard]] const fuyu::physical_device& physical_device() noexcept { return resources::get().physical_device(); }
[[nodiscard]] fuyu::surface_view           surface() noexcept { return resources::get().surface(); }

} // namespace fubuki::test::context
