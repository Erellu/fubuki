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

#ifndef FUBUKI_TUTORIAL_04_RESOURCES_HPP
#define FUBUKI_TUTORIAL_04_RESOURCES_HPP

#include "shader.hpp"

#include <algorithm>
#include <cstddef>
#include <ranges>
#include <span>
#include <tuple>
#include <vector>

#include <fuyu/buffer.hpp>
#include <fuyu/command/pipes.hpp>
#include <fuyu/command_buffer_array.hpp>
#include <fuyu/command_pool.hpp>
#include <fuyu/fence.hpp>
#include <fuyu/graphics_pipeline.hpp>
#include <fuyu/hardware.hpp>
#include <fuyu/image.hpp>
#include <fuyu/image_view.hpp>
#include <fuyu/memory.hpp>
#include <fuyu/memory_requirements.hpp>
#include <fuyu/pipeline_layout.hpp>
#include <fuyu/semaphore.hpp>
#include <hyoka/shader/compile.hpp>

#include <support/app.hpp>

namespace tutorial::triangle
{

inline constexpr std::size_t default_frames_in_flight = 3;

struct resources
{
    struct synchronisation
    {
        struct per_frame
        {
            struct semaphores
            {
                fubuki::fuyu::semaphore present;
                fubuki::fuyu::semaphore render;
            };

            fubuki::fuyu::fence fence;
            semaphores          semaphore;

            [[nodiscard]] static std::expected<per_frame, fubuki::api_call_info> make() noexcept;
        };

        std::vector<per_frame> contents; ///< Synchronisation primitives for each synchronisation in flight.

        [[nodiscard]] static std::expected<synchronisation, fubuki::api_call_info> make(std::size_t in_flight = default_frames_in_flight) noexcept;
    };

    struct commands
    {
        fubuki::fuyu::command_pool         pool;
        fubuki::fuyu::command_buffer_array buffers;

        [[nodiscard]] static std::expected<commands, fubuki::api_call_info> make(std::size_t in_flight = default_frames_in_flight) noexcept;
    };

    struct drawing
    {
        struct target
        {
            fubuki::fuyu::image      image;
            fubuki::fuyu::memory     memory;
            fubuki::fuyu::image_view view;

            [[nodiscard]] static std::expected<target, fubuki::api_call_info> make() noexcept;
        };

        target                          render_target;
        fubuki::fuyu::pipeline_layout   pipeline_layout;
        fubuki::fuyu::graphics_pipeline pipeline;

        [[nodiscard]] static std::expected<drawing, fubuki::api_call_info> make() noexcept;
    };

    struct buffers
    {
        struct vbo
        {
            fubuki::fuyu::buffer buffer;
            fubuki::fuyu::memory memory;

            [[nodiscard]] static std::expected<vbo, fubuki::api_call_info> make() noexcept;
        };

        vbo vertex; ///< The buffer containing the data passed to the vertex shader.

        [[nodiscard]] static std::expected<buffers, fubuki::api_call_info> make() noexcept;
    };

    synchronisation frame;   ///< Resources related to frames.
    commands        command; ///< Command pool and buffers.
    drawing         draw;    ///< Resources  related to the draw operations.
    buffers         buffer;  ///< Data to draw.

    [[nodiscard]] static std::expected<resources, fubuki::api_call_info> make(std::size_t in_flight = default_frames_in_flight) noexcept;
};

[[nodiscard]] inline std::expected<void, fubuki::api_call_info> recreate_swapchain(resources& rc) noexcept
{
    namespace app = fubuki::tutorial::support::app;

    if(const auto check = fubuki::fuyu::wait_idle(app::device()); not check)
    {
        return std::unexpected{check.error()};
    }

    if(const auto check = fubuki::fuyu::recreate(app::swapchain(), app::swapchain_resources()); not check)
    {
        return std::unexpected{check.error()};
    }

    {
        auto new_render_target = resources::drawing::target::make();

        if(not new_render_target)
        {
            return std::unexpected{new_render_target.error()};
        }

        rc.draw.render_target = *std::move(new_render_target);
    }

    if(const auto check = fubuki::fuyu::wait_idle(app::device()); not check)
    {
        return std::unexpected{check.error()};
    }

    return {};
}

[[nodiscard]] inline auto resources::synchronisation::per_frame::make() noexcept -> std::expected<per_frame, fubuki::api_call_info>
{
    namespace app = fubuki::tutorial::support::app;

    auto f = fubuki::fuyu::fence::make(app::device(), {.flags = VK_FENCE_CREATE_SIGNALED_BIT});

    if(not f)
    {
        return std::unexpected{f.error()};
    }

    auto present_semaphore = fubuki::fuyu::semaphore::make(app::device(), {});

    if(not present_semaphore)
    {
        return std::unexpected{present_semaphore.error()};
    }

    auto render_semaphore = fubuki::fuyu::semaphore::make(app::device(), {});

    if(not render_semaphore)
    {
        return std::unexpected{render_semaphore.error()};
    }

    return per_frame{
        *std::move(f), {*std::move(present_semaphore), *std::move(render_semaphore)}
    };
}

[[nodiscard]] inline auto resources::synchronisation::make(std::size_t in_flight) noexcept -> std::expected<synchronisation, fubuki::api_call_info>
{
    namespace app = fubuki::tutorial::support::app;

    std::vector<synchronisation::per_frame> synchro = {};
    synchro.reserve(in_flight);

    for(const std::size_t i : std::views::iota(0u, std::max(in_flight, std::size_t{1})))
    {
        std::ignore = i;
        auto s      = synchronisation::per_frame::make();

        if(not s)
        {
            return std::unexpected{s.error()};
        }

        synchro.emplace_back(*std::move(s));
    }

    return synchronisation{
        .contents = std::move(synchro),
    };
}

[[nodiscard]] inline auto resources::commands::make(std::size_t in_flight) noexcept -> std::expected<commands, fubuki::api_call_info>
{
    namespace app = fubuki::tutorial::support::app;

    const auto queues = app::device().queues();
    const auto graphics_queue
        = std::ranges::find_if(queues.all, [](const fubuki::fuyu::queue& q) noexcept { return (q.type & VK_QUEUE_GRAPHICS_BIT) != 0; });

    if(graphics_queue == queues.all.end())
    {
        fubuki_assert(false, "No graphics queue available");
        return std::unexpected{fubuki::api_call_info{}};
    }

    auto pool = fubuki::fuyu::command_pool::make(app::device(),
                                                 {.flags = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT, .queue_family = graphics_queue->family});

    if(not pool)
    {
        return std::unexpected{pool.error()};
    }

    auto b = fubuki::fuyu::command_buffer_array::make(*pool, {.count = in_flight, .level = VK_COMMAND_BUFFER_LEVEL_PRIMARY});

    if(not b)
    {
        return std::unexpected{b.error()};
    }

    return commands{
        *std::move(pool),
        *std::move(b),
    };
}

[[nodiscard]] inline auto resources::drawing::target::make() noexcept -> std::expected<target, fubuki::api_call_info>
{
    namespace app = fubuki::tutorial::support::app;

    const auto& swapchain_image = app::swapchain().info().image;

    auto img = fubuki::fuyu::image::make(app::device(),
                                         {
                                             .flags        = {},
                                             .type         = VK_IMAGE_TYPE_2D,
                                             .format       = swapchain_image.format,
                                             .extent       = {swapchain_image.extent.width, swapchain_image.extent.height, 1},
                                             .mip_levels   = 1,
                                             .array_layers = 1,
                                             .samples      = VK_SAMPLE_COUNT_4_BIT,
                                             .usage        = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT | VK_IMAGE_USAGE_TRANSFER_SRC_BIT,
    });

    if(not img)
    {
        return std::unexpected{img.error()};
    }

    auto mem = fubuki::fuyu::memory::make(app::device(),
                                          {
                                              .requirements = fubuki::fuyu::information::memory::make_requirements(fubuki::memory_requirements(*img)),
                                              .properties   = VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT,
                                          });

    if(not mem)
    {
        return std::unexpected{mem.error()};
    }

    if(const auto bound = fubuki::fuyu::bind(*img, *mem); not bound)
    {
        return std::unexpected{bound.error()};
    }

    auto img_view = fubuki::fuyu::image_view::make(
        *img,
        {
            .flags      = {},
            .type       = VK_IMAGE_VIEW_TYPE_2D,
            .format     = img->info().format,
            .components = {},
            .subresource_range
            = {.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT, .baseMipLevel = 0, .levelCount = 1, .baseArrayLayer = 0, .layerCount = 1}
    });

    if(not img_view)
    {
        return std::unexpected{img_view.error()};
    }

    return target{*std::move(img), *std::move(mem), *std::move(img_view)};
}

[[nodiscard]] inline auto resources::drawing::make() noexcept -> std::expected<drawing, fubuki::api_call_info>
{
    namespace app        = fubuki::tutorial::support::app;
    using shader_stage   = fubuki::fuyu::shader_stage;
    using pipeline_state = fubuki::fuyu::graphics_pipeline::state;

    auto rt = target::make();

    if(not rt)
    {
        return std::unexpected{rt.error()};
    }

    auto layout = fubuki::fuyu::pipeline_layout::make(app::device(), {});

    if(not layout)
    {
        return std::unexpected{layout.error()};
    }

    auto shaders = shader::compiled::make();

    if(not shaders)
    {
        fubuki_assert(shaders.has_value(), "Internal error: failed to compile the shaders. Please open an issue.");
        return std::unexpected{fubuki::api_call_info{}};
    }

    // NOLINTBEGIN(cppcoreguidelines-avoid-magic-numbers)
    auto pipe = fubuki::fuyu::graphics_pipeline::make(
        app::pipeline_cache(),
        {
            .flags  = {},
            .layout = *layout,
    },
        {.stage = {.vertex   = {{.flags = {}, .shader = shader_stage::spirv{shaders->vertex}}},
                   .fragment = {{.flags = {}, .shader = shader_stage::spirv{shaders->fragment}}}},
         .state
         = {.vertex_input   = {{.flags      = {},
                                .bindings   = {{.binding = 0, .stride = 6u * sizeof(float), .inputRate = VK_VERTEX_INPUT_RATE_VERTEX}},
                                .attributes = {{.location = 0, .binding = 0, .format = VK_FORMAT_R32G32B32_SFLOAT, .offset = 0},
                                               {.location = 1, .binding = 0, .format = VK_FORMAT_R32G32B32_SFLOAT, .offset = 3 * sizeof(float)}}}},
            .input_assembly = {{.flags = {}, .topology = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST}},
            .tesselation    = {},
            .viewport       = {{.viewports = {VkViewport{}}, .scissors = {VkRect2D{}}}},
            .rasterisation  = {pipeline_state::rasterisation{}},
            .multisample    = {pipeline_state::multisample{.flags = {}, .samples = fubuki::fuyu::sampling_rate::sample_4{}}},
            .depth_stencil  = {pipeline_state::depth_stencil{}},
            .colour_blend   = {{.flags       = {},
                                .attachments = {{.blendEnable         = {},
                                                 .srcColorBlendFactor = {},
                                                 .dstColorBlendFactor = {},
                                                 .colorBlendOp        = {},
                                                 .srcAlphaBlendFactor = {},
                                                 .dstAlphaBlendFactor = {},
                                                 .alphaBlendOp        = {},
                                                 .colorWriteMask      = VK_COLOR_COMPONENT_R_BIT | VK_COLOR_COMPONENT_G_BIT | VK_COLOR_COMPONENT_B_BIT
                                                     | VK_COLOR_COMPONENT_A_BIT}}}},
            .dynamic        = {{.states = {VK_DYNAMIC_STATE_VIEWPORT, VK_DYNAMIC_STATE_SCISSOR}}}}},
        fubuki::owning_pnext_chain{VkPipelineRenderingCreateInfo{
                                       .sType                   = {},
                                       .pNext                   = {},
                                       .viewMask                = {},
                                       .colorAttachmentCount    = 1u,
                                       .pColorAttachmentFormats = std::addressof(rt->image.info().format),
                                       .depthAttachmentFormat   = {},
                                       .stencilAttachmentFormat = {},
                                   }}
            .chain());
    // NOLINTEND(cppcoreguidelines-avoid-magic-numbers)

    if(not pipe)
    {
        return std::unexpected{pipe.error()};
    }

    return drawing{*std::move(rt), *std::move(layout), *std::move(pipe)};
}

[[nodiscard]] inline auto resources::buffers::vbo::make() noexcept -> std::expected<vbo, fubuki::api_call_info>
{
    namespace app = fubuki::tutorial::support::app;

    // clang-format off
           // See shader::glsl::vertex
    constexpr std::array vertices =
        {
            /* Pos (vec3) */      /* Colour (vec3)*/
            0.0f, -0.5f, 0.0f,    1.0f, 0.0f, 0.0f,
            0.5f, 0.5f, 0.0f,     0.0f, 1.0f, 0.0f,
            -0.5f, 0.5f, 0.0f,    0.0f, 0.0f, 1.0f
        };
    // clang-format on

    const auto vertices_bytes = std::as_bytes(std::span{vertices});

    auto vertex_buffer
        = fubuki::fuyu::buffer::make(app::device(), {.flags = {}, .size = vertices_bytes.size_bytes(), .usage = VK_BUFFER_USAGE_VERTEX_BUFFER_BIT});

    if(not vertex_buffer)
    {
        return std::unexpected{vertex_buffer.error()};
    }

    // Obviously, real applications should rather use a staging buffer to upload the vertices to a VK_MEMORY_PROPERTY_DEVICE_LOCAL memory
    // chunk. This tutorial purposefully doesn't do this for the sake of demonstration
    auto mem = fubuki::fuyu::memory::make(
        app::device(),
        {
            .requirements = fubuki::fuyu::information::memory::make_requirements(fubuki::memory_requirements(*vertex_buffer)),
            .properties   = VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT,
        });

    if(not mem)
    {
        return std::unexpected{mem.error()};
    }

    if(const auto bound = fubuki::fuyu::bind(*vertex_buffer, *mem); not bound)
    {
        return std::unexpected{bound.error()};
    }

    // Upload the data
    {
        auto mapped_region = fubuki::fuyu::map(*mem);

        if(not mapped_region)
        {
            return std::unexpected{mapped_region.error()};
        }

        std::ranges::copy(vertices_bytes, mapped_region->begin());

        // Technically not useful, such buffers can be kept mapped for the lifetime of the buffer.
        // This is JUST for demonstration purposes.
        fubuki::fuyu::unmap(*mem);
    }

    return vbo{*std::move(vertex_buffer), *std::move(mem)};
}

[[nodiscard]] inline auto resources::buffers::make() noexcept -> std::expected<buffers, fubuki::api_call_info>
{
    auto vertex = vbo::make();

    if(not vertex)
    {
        return std::unexpected{vertex.error()};
    }

    return buffers{*std::move(vertex)};
}

[[nodiscard]] inline auto resources::make(std::size_t in_flight) noexcept -> std::expected<resources, fubuki::api_call_info>
{
    auto frame_rc = synchronisation::make(in_flight);

    if(not frame_rc)
    {
        return std::unexpected{frame_rc.error()};
    }

    auto command_rc = commands::make(in_flight);

    if(not command_rc)
    {
        return std::unexpected{command_rc.error()};
    }

    auto draw_rc = drawing::make();

    if(not draw_rc)
    {
        return std::unexpected{draw_rc.error()};
    }

    auto data_rc = buffers::make();

    if(not data_rc)
    {
        return std::unexpected{data_rc.error()};
    }

    return resources{*std::move(frame_rc), *std::move(command_rc), *std::move(draw_rc), *std::move(data_rc)};
}

} // namespace tutorial::triangle

#endif // FUBUKI_TUTORIAL_04_RESOURCES_HPP
