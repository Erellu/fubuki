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

#include "fuyu/swapchain_resources.hpp"

#include <extension/khr_swapchain.hpp>

#include "fuyu/device.hpp" // IWYU pragma: keep (required for conversion operators to view)
#include "fuyu/external_handle.hpp"
#include "fuyu/swapchain.hpp" // IWYU pragma: keep (required for conversion operators to view)

namespace fubuki::fuyu
{

swapchain_resources::swapchain_resources(token, std::reference_wrapper<const swapchain> parent, information info) noexcept
    : m_parent{parent.get().device()},
      m_info{std::move(info)}
{
}

[[nodiscard]] std::optional<api_call_info> swapchain_resources::acquire_images(const swapchain& s) noexcept
{
    const auto swapchain_images = fuyu::images(s);

    if(not swapchain_images)
    {
        return swapchain_images.error();
    }

    m_images.reserve(swapchain_images->size());

    const auto& swapchain_info = s.info();

    for(const image_handle handle : *swapchain_images)
    {
        auto image = fuyu::image::make(
            {
                fuyu::borrow{handle}
        },
            device(),
            image::information{.flags          = {},
                               .type           = VK_IMAGE_TYPE_2D,
                               .format         = swapchain_info.image.format,
                               .extent         = {swapchain_info.image.extent.width, swapchain_info.image.extent.height, 1},
                               .mip_levels     = 1,
                               .array_layers   = swapchain_info.image.array_layers,
                               .samples        = VK_SAMPLE_COUNT_1_BIT,
                               .tiling         = VK_IMAGE_TILING_OPTIMAL,
                               .usage          = swapchain_info.image.usage,
                               .sharing_mode   = swapchain_info.image.sharing_mode,
                               .initial_layout = {}

            });
        if(not image)
        {
            return image.error();
        }

        m_images.emplace_back(std::move(*image));
    }

    return {};
}

[[nodiscard]] std::expected<render_pass_handle, api_call_info> swapchain_resources::make_render_pass() noexcept
{
    fubuki_assert(not std::holds_alternative<information::dynamic_rendering>(m_info.render_target.value),
                  "Internal error. Should not have been called");

    const auto& setup = std::get<information::render_pass>(m_info.render_target.value);

    if(const auto* const info = std::get_if<render_pass::information>(std::addressof(setup.source)))
    {
        auto pass = render_pass::make(device(), *info);

        if(not pass)
        {
            return std::unexpected{pass.error()};
        }

        m_render_pass.emplace(*std::move(pass));
        return *m_render_pass;
    }

    return std::get<render_pass_handle>(setup.source);
}

[[nodiscard]]
auto swapchain_resources::rebind(parent_type p) noexcept -> std::expected<void, parent_type::error::incompatible>
{
    if(compatible(m_parent, p))
    {
        for(auto& i : m_images)
        {
            fubuki_always_assert(i.rebind(p).has_value(), "Internal error. Please open an issue at https://github.com/Erellu/fubuki/issues");
        }

        for(auto& i : m_image_views)
        {
            fubuki_always_assert(i.rebind(p).has_value(), "Internal error. Please open an issue at https://github.com/Erellu/fubuki/issues");
        }

        for(auto& f : m_framebuffers)
        {
            fubuki_always_assert(f.rebind(p).has_value(), "Internal error. Please open an issue at https://github.com/Erellu/fubuki/issues");
        }

        if(m_render_pass.has_value())
        {
            fubuki_always_assert(m_render_pass->rebind(p).has_value(), // NOLINT(bugprone-unchecked-optional-access): false positive
                                 "Internal error. Please open an issue at https://github.com/Erellu/fubuki/issues");
        }

        m_parent.swap(p);

        return {};
    }

    return std::unexpected{
        parent_type::error::incompatible{m_parent.handle, p.handle}
    };
}

} // namespace fubuki::fuyu
