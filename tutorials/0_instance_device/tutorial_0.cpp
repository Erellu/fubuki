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

#include <iostream>

#include <core/config/setup.hpp>
#include <core/pfn.hpp>
#include <core/vulkan.hpp>
#include <fuyu/debug/layers.hpp>
#include <fuyu/device.hpp>
#include <fuyu/hardware.hpp>
#include <fuyu/instance.hpp>

namespace fuyu = fubuki::fuyu;

int main()
{
    std::cout << "Fubuki is built in the following " << fubuki::build_configuration() << "\n---------------------------------------------\n";

    // [1] Display some information about supported extensions for instance
    {
        const auto extensions = fuyu::hardware::supported_instance_extensions();

        if(not extensions.has_value())
        {
            std::cout << "An error occurred while fetching available extensions: " << extensions.error();
            return 1;
        }

        std::cout << "Instance supports the following extensions:\n";

        for(const auto& ext : extensions->properties)
        {
            std::cout << static_cast<const char*>(ext.extensionName) << "(" << ext.specVersion << ")" << ", ";
        }

        std::cout << "\n++++++++++++++++++++++++++++++++++\n"
                  << "Following validation layers are available:\n";

        const auto layers = fuyu::debug::layers();

        if(not layers.has_value())
        {
            std::cout << "An error occurred while fetching available validation layers: " << layers.error();
            return 1;
        }

        for(const auto& layer : *layers)
        {
            std::cout << static_cast<const char*>(layer.layerName) << " (v." << layer.implementationVersion << ")" << ", ";
        }

        std::cout << "\n---------------------------------------------\n";
    }

    // [2]
    const fuyu::instance instance{
        {.application = {.name           = "Tutorial 00: instance and device",
                         .version        = {1, 0, 0},
                         .vulkan_version = {1, 3, 0},
                         .engine         = {.name = "Engine", .version = {1, 3, 0}}},
         .flags       = {},
         .callbacks   = {}},
        {
         .layers     = {"VK_LAYER_KHRONOS_validation"},
         .extensions = {},
         }
    };

    std::cout << "Successfully created instance " << instance.handle().vk << "\n";

    // [3] Load
    {
        // Example of loading pointers to Vulkan function (PFN).
        // Fubuki loads *automatically* the ones in Vulkan core and in supported extensions.
        // These are accessible in fuyu::instance/fuyu::instance_view (resp. fuyu::device/fuyu::device_view).
        // This snippet demonstrates how you can load functions of extensions not supported by Fubuki.
        {
            if(auto* a_pfn = fubuki::pfn<"vkCreateDevice">(instance); a_pfn != nullptr)
            {
                static_assert(std::is_same_v<decltype(a_pfn), PFN_vkCreateDevice>);
                std::cout << "Successfully retrieved pfn for vkCreateDevice!" << std::endl;
            }

            if(auto* b_pfn = fubuki::pfn<"vkDestroyDevice">(instance); b_pfn != nullptr)
            {
                static_assert(std::is_same_v<decltype(b_pfn), PFN_vkDestroyDevice>);
                std::cout << "Successfully retrieved pfn for vkDestroyDevice!" << std::endl;
            }
        }

        std::cout << "\n---------------------------------------------" << std::endl;
    }

    // [4]
    const auto physical_devices = fuyu::hardware::physical_devices(instance);

    if(not physical_devices.has_value())
    {
        std::cout << "An error occurred while retrieving the devices  " << physical_devices.error();
        return 1;
    }

    for(const auto device : *physical_devices)
    {
        const auto info = fuyu::hardware::physical_device_information(instance, device);

        if(not info.has_value())
        {
            std::cout << "An error occurred while retrieving physical device properties  " << info.error();
            return 1;
        }

        std::cout << "device: " << static_cast<const char*>(info->properties.vk10.deviceName) << "\n";
        for(const auto& ext : info->extensions)
        {
            std::cout << static_cast<const char*>(ext.extensionName) << "(" << ext.specVersion << ")"
                      << ", ";
        }
        std::cout << "\n++++++++++++++++++++++++++++++++++\n";
    }

    std::cout << "\n---------------------------------------------\n";

    if(physical_devices->empty())
    {
        std::cout << "No available physical device :(\n";
        return 1;
    }

    fuyu::unsupported_features device_unsupported_features = {};
    const auto                 physical_device             = physical_devices->front();

    // clang-format off
    const fuyu::device device(instance,
                              physical_device,
                              {},
                              {.queues     = {{
                                                  .type     = VK_QUEUE_GRAPHICS_BIT,
                                                  .flags    = {},
                                                  .priority = +0.f
                                          },
                                              {
                                                  .type     = VK_QUEUE_COMPUTE_BIT,
                                                  .flags    = {},
                                                  .priority = +0.f
                                          }},
                               .extensions = {VK_KHR_DEFERRED_HOST_OPERATIONS_EXTENSION_NAME, VK_KHR_SWAPCHAIN_EXTENSION_NAME},
                               .surfaces   = {},
                               .features   = {}},
                              device_unsupported_features);
    // clang-format on

    std::cout << "Successfully created device " << device.handle().vk << "\n";

    for(const auto& q : device.queues().all)
    {
        std::cout << "queue " << q.handle.vk << ", type: " << q.type << ", family:" << q.family << ", index: " << q.index << "\n";
    }

    if(not device_unsupported_features.extensions.hardware.empty())
    {
        std::cout << "The following extensions were required but are not available. You will have to find workarounds for this hardware:"
                  << "{";

        for(const auto& ext : device_unsupported_features.extensions.hardware)
        {
            std::cout << ext << ", ";
        }
        std::cout << "}";
    }

    return 0;
}
