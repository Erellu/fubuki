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

#ifndef FUBUKI_TUTORIAL_04_TRIANGLE_HPP
#define FUBUKI_TUTORIAL_04_TRIANGLE_HPP

#include "resources.hpp"

#include <support/app.hpp>

namespace tutorial::triangle
{

struct draw_error
{
    using swapchain    = fubuki::fuyu::presentation::error;
    using wait         = fubuki::fuyu::wait_error;
    using command_flow = fubuki::fuyu::cmd::pipe::error::any;
    using generic      = fubuki::api_call_info;
    using any          = std::variant<generic, wait, command_flow, swapchain>;

    any value = {};

    template<typename char_type, typename traits = std::char_traits<char_type>>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const draw_error& error)
    {
        return std::visit([&out]<typename variant>(const variant& v) -> auto& { return out << v; }, error);
    }
};

[[nodiscard]]
inline std::expected<void, draw_error> draw(const resources& rc, const std::size_t frame_index) noexcept
{
    using std::chrono_literals::operator""ns;
    namespace app = fubuki::tutorial::support::app;
    namespace cmd = fubuki::fuyu::command;

    fubuki_assert(not app::device().queues().all.empty(), "No queue to submit work.");
    fubuki_assert(not app::device().queues().presentable.empty(), "No queue can be used to present the swapchain.");

    const fubuki::fuyu::queue             graphics_queue = app::device().queues().all.front();
    const fubuki::fuyu::presentable_queue present_queue  = app::device().queues().presentable.front();

    const auto&    sync    = rc.frame.contents[frame_index];
    constexpr auto timeout = 10000000000ns;

    if(const auto check = fubuki::fuyu::wait_for(sync.fence, timeout); not check)
    {
        return std::unexpected{draw_error{check.error()}};
    }

    if(const auto check = fubuki::fuyu::reset(sync.fence); not check)
    {
        return std::unexpected{draw_error{check.error()}};
    }

    const auto next_image = fubuki::fuyu::acquire_next_image(app::swapchain(), {.timeout = timeout, .semaphore = sync.semaphore.present});

    if(not next_image)
    {
        return std::unexpected{draw_error{next_image.error()}};
    }

    auto command_buffer = rc.command.buffers[frame_index];

    if(const auto check = fubuki::fuyu::reset(command_buffer); not check)
    {
        return std::unexpected{draw_error{check.error()}};
    }

    // clang-format off
    auto flow
        = cmd::pipe::record(command_buffer, VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT)
        | cmd::pipe::barrier(
                cmd::image_memory_barrier
                {
                    .source      = {.access_mask = {}, .layout = VK_IMAGE_LAYOUT_UNDEFINED},
                    .destination = {.access_mask = VK_ACCESS_COLOR_ATTACHMENT_READ_BIT | VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT, .layout = VK_IMAGE_LAYOUT_GENERAL},
                    .target      =
                    {
                        .handle            = rc.draw.render_target.image,
                        .subresource_range =
                        {
                            .aspectMask     = VK_IMAGE_ASPECT_COLOR_BIT,
                            .baseMipLevel   = 0,
                            .levelCount     = 1,
                            .baseArrayLayer = 0,
                           .layerCount      = 1
                        }
                    }
                },
                cmd::barrier_stage
                {
                    .source      = VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                    .destination = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT,
                })
        | cmd::pipe::render_scope(
            cmd::dynamic_render_target
            {
                .flags       = {},
                .render_area = {.offset = {}, .extent = app::swapchain().info().image.extent},
                .layer_count = 1,
                .view_mask   = {},
                .attachments =
                {
                    .colour =
                    {
                        {
                            .sType              = VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_INFO,
                            .pNext              = {},
                            .imageView          = rc.draw.render_target.view.handle().vk,
                            .imageLayout        = VK_IMAGE_LAYOUT_GENERAL,
                            .resolveMode        = VK_RESOLVE_MODE_AVERAGE_BIT,
                            .resolveImageView   = app::swapchain_resources()[*next_image].view.handle.vk,
                            .resolveImageLayout = VK_IMAGE_LAYOUT_GENERAL,
                            .loadOp             = VK_ATTACHMENT_LOAD_OP_CLEAR,
                            .storeOp            = VK_ATTACHMENT_STORE_OP_STORE,
                            .clearValue         = {VkClearColorValue{{0.0f, 0.0f, 0.2f, 1.0f}}} // NOLINT(cppcoreguidelines-avoid-magic-numbers)
                        }
                    }
                }
            },
            [&rc](cmd::pipe::flow f) noexcept -> cmd::pipe::flow
            {
                const VkViewport vp
                {
                     .x        = 0.f,
                     .y        = 0.f,
                     .width    = static_cast<float>(app::swapchain().info().image.extent.width),
                     .height   = static_cast<float>(app::swapchain().info().image.extent.height),
                     .minDepth = 0.0f,
                     .maxDepth = 1.0f
                };
                const VkRect2D scissor = {.offset = {}, .extent = app::swapchain().info().image.extent};

                return std::move(f)
                       | cmd::pipe::set::viewport(0, {vp})
                       | cmd::pipe::set::scissor(0, {scissor})
                       | cmd::pipe::bind::pipeline(rc.draw.pipeline.handle())
                       | cmd::pipe::bind::vertex_buffer(0, rc.buffer.vertex.buffer, 0)
                       | cmd::pipe::draw::call(6, 1, 0, 0); // NOLINT(cppcoreguidelines-avoid-magic-numbers)
            })
        | cmd::pipe::barrier(
            cmd::image_memory_barrier
            {
                .source      = {.access_mask = VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT, .layout = VK_IMAGE_LAYOUT_UNDEFINED},
                .destination = {.access_mask = {}, .layout = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR},
                .target      =
                {
                    .handle            = app::swapchain_resources()[frame_index].image,
                    .subresource_range =
                    {
                        .aspectMask     = VK_IMAGE_ASPECT_COLOR_BIT,
                        .baseMipLevel   = 0,
                        .levelCount     = 1,
                        .baseArrayLayer = 0,
                       .layerCount      = 1
                    }
                }
            },
            cmd::barrier_stage
            {
                .source      = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT,
                .destination = VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT,
            });
    // clang-format on

    if(flow.error())
    {
        return std::unexpected{draw_error{*flow.error()}}; // NOLINT(bugprone-unchecked-optional-access): false positive
    }

    // clang-format off
    if(const auto check = cmd::pipe::submit(
           graphics_queue,
           std::move(flow),
           fubuki::fuyu::submission
           {
                .fence             = sync.fence,
                .wait_semaphores   = {{sync.semaphore.present, sync.semaphore.present.device(), VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT}},
                .signal_semaphores = {sync.semaphore.render}
           });
       not check)
    {
        return std::unexpected{draw_error{check.error()}};
    }
    // clang-format on

    if(const auto check
       = fubuki::fuyu::present(present_queue, app::swapchain(), {.wait_semaphores = {sync.semaphore.render}, .image_index = *next_image});
       not check)
    {
        return std::unexpected{draw_error{check.error()}};
    }

    return {};
}

} // namespace tutorial::triangle

#endif // FUBUKI_TUTORIAL_04_TRIANGLE_HPP
