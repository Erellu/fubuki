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

#ifndef FUBUKI_TUTORIAL_SUPPORT_SETUP_HPP
#define FUBUKI_TUTORIAL_SUPPORT_SETUP_HPP

#include <core/config/setup.hpp>
#include <core/future/flat_set.hpp>
#include <core/future/move_only_function.hpp>
#include <core/pnext_chain.hpp>
#include <fuyu/information/device.hpp>
#include <fuyu/information/instance.hpp>
#include <fuyu/information/swapchain.hpp>
#include <fuyu/information/swapchain_resources.hpp>
#include <fuyu/physical_device.hpp>
#include <io/information/display.hpp>
#include <io/information/window.hpp>

namespace fubuki::tutorial::support::app
{

template<fubuki::traits::pnext_chain::type instance_pnext = fubuki::pnext_chain<>,
         fubuki::traits::pnext_chain::type device_pnext   = fubuki::pnext_chain<>>
struct setup_pnext
{
    instance_pnext instance = {};
    device_pnext   device   = {};
};

/// Application setup.
struct setup
{
    struct display_requirements
    {
        fubuki::io::information::display display = {};
        fubuki::io::information::window  window  = {};
    };

    struct instance_requirements
    {
        template<fubuki::configuration::build_type build_type = fubuki::configuration::current().build>
        [[nodiscard]] static fubuki::fuyu::information::instance::complements default_complements()
        {
            fubuki::fuyu::information::instance::complements complements = {};

            if constexpr(build_type == fubuki::configuration::build_type::debug)
            {
                complements.layers.emplace("VK_LAYER_KHRONOS_validation");
            }

            return complements;
        }

        fubuki::fuyu::information::instance              info        = {};
        fubuki::fuyu::information::instance::complements complements = default_complements();
    };

    struct device_requirements
    {
        using queue = fubuki::fuyu::information::device::queue_info;

        [[nodiscard]] static constexpr bool default_physical_device(const fubuki::fuyu::physical_device&) noexcept { return true; } // Pick the first

        [[nodiscard]] static fubuki::small_vector<queue> default_queues()
        {
            return {
                {
                 .type     = VK_QUEUE_GRAPHICS_BIT,
                 .flags    = {},
                 .priority = +0.f,
                 },
                {
                 .type     = VK_QUEUE_COMPUTE_BIT,
                 .flags    = {},
                 .priority = +0.f,
                 }
            };
        }

        fubuki::move_only_function<bool(const fubuki::fuyu::physical_device&) noexcept> physical_device = default_physical_device;

        fubuki::small_vector<queue>         queues     = default_queues();
        fubuki::small_flat_set<std::string> extensions = {};
    };

    struct swapchain_requirements
    {
        fubuki::fuyu::information::swapchain           info      = {};
        fubuki::fuyu::information::swapchain_resources resources = {fubuki::fuyu::information::swapchain_resources::dynamic_rendering{}};
    };

    template<fubuki::traits::pnext_chain::type instance_pnext = fubuki::pnext_chain<>,
             fubuki::traits::pnext_chain::type device_pnext   = fubuki::pnext_chain<>>
    using pnext = setup_pnext<instance_pnext, device_pnext>;

    std::optional<display_requirements>   display   = {};
    std::optional<instance_requirements>  instance  = {};
    std::optional<device_requirements>    device    = {};
    std::optional<swapchain_requirements> swapchain = {};
};

setup_pnext() -> setup_pnext<fubuki::pnext_chain<>, fubuki::pnext_chain<>>;

template<typename... instance_pnext_elements, typename... device_pnext_elements>
setup_pnext(fubuki::pnext_chain<instance_pnext_elements...>, fubuki::pnext_chain<device_pnext_elements...>)
    -> setup_pnext<fubuki::pnext_chain<instance_pnext_elements...>, fubuki::pnext_chain<device_pnext_elements...>>;

} // namespace fubuki::tutorial::support::app

#endif // FUBUKI_TUTORIAL_SUPPORT_SETUP_HPP
