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

#ifndef FUBUKI_TUTORIAL_SUPPORT_RESOURCES_HPP
#define FUBUKI_TUTORIAL_SUPPORT_RESOURCES_HPP

#include "error.hpp"
#include "setup.hpp"

#include <utility>

#include <core/assertion.hpp>
#include <core/config/setup.hpp>
#include <core/future/move_only_function.hpp>
#include <core/validate.hpp>
#include <fuyu/debug/messenger.hpp>
#include <fuyu/device.hpp>
#include <fuyu/hardware.hpp>
#include <fuyu/instance.hpp>
#include <fuyu/physical_device.hpp>
#include <fuyu/pipeline_cache.hpp>
#include <fuyu/surface.hpp>
#include <fuyu/swapchain.hpp>
#include <fuyu/swapchain_resources.hpp>
#include <io/display.hpp>
#include <io/event/queue.hpp>
#include <io/window.hpp>

namespace fubuki::tutorial::support::app
{

/// The resources required during the application lifetime.
class resources
{
public:

    resources& operator=(const resources&) = delete;
    resources(const resources&)            = delete;

    resources(resources&& other) noexcept
        : m_display{std::move(other.m_display)},
          m_window{std::move(other.m_window)},
          m_instance{std::move(other.m_instance)},
          m_debug_messenger{std::move(other.m_debug_messenger)},
          m_surface{std::move(other.m_surface)},
          m_device{std::move(other.m_device)},
          m_pipeline_cache{std::move(other.m_pipeline_cache)},
          m_swapchain{std::move(other.m_swapchain)},
          m_swapchain_resources{std::move(other.m_swapchain_resources)}
    {
        rebind();
    }

    resources& operator=(resources&&) = delete;

    ~resources() noexcept
    {
        // False if moved
        if(m_pipeline_cache.handle() != null_handle)
        {
            const auto pipeline_cache_data = fubuki::fuyu::data(m_pipeline_cache);

            if(pipeline_cache_data.has_value())
            {
                for(const auto byte : *pipeline_cache_data)
                {
                    // A more complete application would serialise this to the disk for future runs
                    std::ignore = byte;
                }
            }

            // Remove event handlers that are susceptible to reference app::surface(), app::device(), app::instance() or other resources after they
            // are already destroyed
            m_window.event_dispatcher().clear();
        }
    }

    template<fubuki::traits::pnext_chain::type instance_pnext = fubuki::pnext_chain<>,
             fubuki::traits::pnext_chain::type device_pnext   = fubuki::pnext_chain<>>
    static std::expected<resources, error::any> make(setup s, setup::pnext<instance_pnext, device_pnext> pnext) noexcept
    {
        return make(std::move(s.display).value_or(setup::display_requirements{}),
                    std::move(s.instance).value_or(setup::instance_requirements{}),
                    std::move(s.device).value_or(setup::device_requirements{}),
                    std::move(s.swapchain).value_or(setup::swapchain_requirements{}),
                    std::move(pnext));
    }

    template<fubuki::traits::pnext_chain::type instance_pnext = fubuki::pnext_chain<>,
             fubuki::traits::pnext_chain::type device_pnext   = fubuki::pnext_chain<>>
    static std::expected<std::unique_ptr<resources>, error::any> make_unique(setup s, setup::pnext<instance_pnext, device_pnext> pnext)
    {
        return make(std::move(s.display).value_or(setup::display_requirements{}),
                    std::move(s.instance).value_or(setup::instance_requirements{}),
                    std::move(s.device).value_or(setup::device_requirements{}),
                    std::move(s.swapchain).value_or(setup::swapchain_requirements{}),
                    std::move(pnext))
            .and_then([](resources r) -> std::expected<std::unique_ptr<resources>, error::any> { return std::make_unique<resources>(std::move(r)); });
    }

    [[nodiscard]] auto&       display() noexcept { return m_display; }
    [[nodiscard]] auto&       window() noexcept { return m_window; }
    [[nodiscard]] auto&       event_queue() noexcept { return m_event_queue; }
    [[nodiscard]] const auto& instance() const noexcept { return m_instance; }
    [[nodiscard]] const auto& surface() const noexcept { return m_surface; }
    [[nodiscard]] const auto& device() const noexcept { return m_device; }
    [[nodiscard]] const auto& pipeline_cache() const noexcept { return m_pipeline_cache; }
    [[nodiscard]] auto&       swapchain() noexcept { return m_swapchain; }
    [[nodiscard]] auto&       swapchain_resources() noexcept { return m_swapchain_resources; }

    void swap(resources& other) noexcept
    {
        m_display.swap(other.m_display);
        m_window.swap(other.m_window);
        m_event_queue.swap(other.m_event_queue);
        m_instance.swap(other.m_instance);
        m_debug_messenger.swap(other.m_debug_messenger);
        m_surface.swap(other.m_surface);
        m_device.swap(other.m_device);
        m_pipeline_cache.swap(other.m_pipeline_cache);
        m_swapchain.swap(other.m_swapchain);
        m_swapchain_resources.swap(other.m_swapchain_resources);
    }

    friend void swap(resources& a, resources& b) noexcept { return a.swap(b); }

private:

    void rebind() noexcept
    {
        // Fuyu objects keep references to their parent objects, they must be rebound
        if(m_debug_messenger)
        {
            fubuki_always_assert(m_debug_messenger->rebind({m_instance}).has_value(), "Internal error. Handles should match");
        }

        fubuki_always_assert(m_device.rebind({m_instance}).has_value(), "Internal error. Handles should match");
        fubuki_always_assert(m_surface.rebind({m_instance}).has_value(), "Internal error. Handles should match");

        fubuki_always_assert(m_pipeline_cache.rebind({m_device}).has_value(), "Internal error. Handles should match");
        fubuki_always_assert(m_swapchain.rebind({m_device}).has_value(), "Internal error. Handles should match");
        fubuki_always_assert(m_swapchain_resources.rebind({m_device}).has_value(), "Internal error. Handles should match");
    }

    resources(fubuki::io::display                           display,
              fubuki::io::window                            window,
              fubuki::fuyu::instance                        instance,
              std::optional<fubuki::fuyu::debug::messenger> debug_messenger,
              fubuki::fuyu::surface                         surface,
              fubuki::fuyu::device                          device,
              fubuki::fuyu::pipeline_cache                  pipeline_cache,
              fubuki::fuyu::swapchain                       swapchain,
              fubuki::fuyu::swapchain_resources             swapchain_resources) noexcept
        : m_display{std::move(display)},
          m_window{std::move(window)},
          m_event_queue{},
          m_instance{std::move(instance)},
          m_debug_messenger{std::move(debug_messenger)},
          m_surface{std::move(surface)},
          m_device{std::move(device)},
          m_pipeline_cache{std::move(pipeline_cache)},
          m_swapchain{std::move(swapchain)},
          m_swapchain_resources{std::move(swapchain_resources)}
    {
        rebind();
    }

    template<fubuki::traits::pnext_chain::type instance_pnext = fubuki::pnext_chain<>,
             fubuki::traits::pnext_chain::type device_pnext   = fubuki::pnext_chain<>>
    static std::expected<resources, error::any> make(setup::display_requirements                display_reqs,
                                                     setup::instance_requirements               instance_reqs,
                                                     setup::device_requirements                 device_reqs,
                                                     setup::swapchain_requirements              swapchain_reqs,
                                                     setup::pnext<instance_pnext, device_pnext> pnext) noexcept
    {
        auto dp = fubuki::io::display::make(display_reqs.display);

        if(not dp)
        {
            return std::unexpected{error::any{dp.error()}};
        }

        auto window = fubuki::io::window::make(*dp, std::move(display_reqs.window));

        if(not window)
        {
            return std::unexpected{error::any{window.error()}};
        }

        auto instance = fubuki::fuyu::instance::make(std::move(instance_reqs.info), instance_reqs.complements, pnext.instance);

        if(not instance)
        {
            return std::unexpected{error::any{instance.error()}};
        }

        auto debug_messenger = make_messenger(*instance);

        if(not debug_messenger)
        {
            return std::unexpected{error::any{debug_messenger.error()}};
        }

        auto surface = fubuki::fuyu::surface::make(*instance, *window);

        if(not surface)
        {
            return std::unexpected{error::any{surface.error()}};
        }

        auto device = fubuki::fuyu::device::make(
            *instance,
            find_physical_device(*instance, std::move(device_reqs.physical_device)),
            {},
            {.queues = std::move(device_reqs.queues), .extensions = std::move(device_reqs.extensions), .surfaces = {{surface->handle()}}},
            pnext.device);

        if(not device)
        {
            return std::unexpected{error::any{device.error()}};
        }

        auto pipeline_cache = fubuki::fuyu::pipeline_cache::make(*device, fubuki::fuyu::pipeline_cache::information{});

        if(not pipeline_cache)
        {
            return std::unexpected{error::any{pipeline_cache.error()}};
        }

        auto swapchain = fubuki::fuyu::swapchain::make(*device, *surface, std::move(swapchain_reqs.info));

        if(not swapchain)
        {
            return std::unexpected{error::any{swapchain.error()}};
        }

        auto swapchain_resources = fubuki::fuyu::swapchain_resources::make(*swapchain, swapchain_reqs.resources);

        if(not swapchain_resources)
        {
            return std::unexpected{error::any{swapchain_resources.error()}};
        }

        return resources(*std::move(dp),
                         *std::move(window),
                         *std::move(instance),
                         *std::move(debug_messenger),
                         *std::move(surface),
                         *std::move(device),
                         *std::move(pipeline_cache),
                         *std::move(swapchain),
                         *std::move(swapchain_resources));
    }

    template<fubuki::configuration::build_type build_type = fubuki::configuration::current().build>
    [[nodiscard]]
    static std::expected<std::optional<fubuki::fuyu::debug::messenger>, fubuki::api_call_info> make_messenger(fubuki::fuyu::instance_cref instance)
    {
        // Debug messenger
        if constexpr(build_type == fubuki::configuration::build_type::debug)
        {
            return fubuki::fuyu::debug::messenger::make(
                instance,
                {
                    .message{
                             .severity  = fubuki::fuyu::debug::messenger::information::default_severity,
                             .type      = fubuki::fuyu::debug::messenger::information::default_messages | VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT,
                             .callback  = fubuki::fuyu::debug::layer_callback::standard_output,
                             .user_data = nullptr,
                             },
            });
        }
        else
        {
            return std::nullopt;
        }
    }

    [[nodiscard]]
    fubuki::physical_device_handle static find_physical_device(
        fubuki::fuyu::instance_view instance, fubuki::move_only_function<bool(const fubuki::fuyu::physical_device&) noexcept> criterum) noexcept
    {
        const auto physical_devices = fubuki::fuyu::hardware::physical_devices(instance);
        fubuki_assert(physical_devices.has_value(), "API call failed while enumerating devices: " << physical_devices.error());
        fubuki_assert(not physical_devices->empty(), "No GPU available for the tests :(.");

        std::optional<fubuki::physical_device_handle> physical_device = {};

        /*
         * Perform some selection based on the needs of the application.
         * Here, we just pick the first one matching the criterum
         */
        for(const auto& d : *physical_devices)
        {
            const auto info = fubuki::fuyu::hardware::physical_device_information(instance, d);
            fubuki_assert(info.has_value(), "Failed to get information about a physical device");

            if(criterum(*info))
            {
                physical_device = d;
                break;
            }
        }

        if(not physical_device.has_value())
        {
            fubuki::crash("No available physical device matches the requirements.", "physical_device.has_value()");
        }

        return *physical_device; // NOLINT(bugprone-unchecked-optional-access): false positive
    }

    fubuki::io::display      m_display;
    fubuki::io::window       m_window;
    fubuki::io::event::queue m_event_queue;

    fubuki::fuyu::instance                        m_instance;
    std::optional<fubuki::fuyu::debug::messenger> m_debug_messenger;
    fubuki::fuyu::surface                         m_surface;

    fubuki::fuyu::device              m_device;
    fubuki::fuyu::pipeline_cache      m_pipeline_cache;
    fubuki::fuyu::swapchain           m_swapchain;
    fubuki::fuyu::swapchain_resources m_swapchain_resources;
};

} // namespace fubuki::tutorial::support::app

#endif // FUBUKI_TUTORIAL_SUPPORT_RESOURCES_HPP
