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

#ifndef FUBUKI_FUYU_COMMAND_PIPES_HPP
#define FUBUKI_FUYU_COMMAND_PIPES_HPP

#include "fuyu/command/pipe/adaptor_closure.hpp" // IWYU pragma: export
#include "fuyu/command/pipe/barrier.hpp"         // IWYU pragma: export
#include "fuyu/command/pipe/bind.hpp"            // IWYU pragma: export
#include "fuyu/command/pipe/copy.hpp"            // IWYU pragma: export
#include "fuyu/command/pipe/custom.hpp"          // IWYU pragma: export
#include "fuyu/command/pipe/dispatch.hpp"        // IWYU pragma: export
#include "fuyu/command/pipe/draw.hpp"            // IWYU pragma: export
#include "fuyu/command/pipe/error.hpp"           // IWYU pragma: export
#include "fuyu/command/pipe/event.hpp"           // IWYU pragma: export
#include "fuyu/command/pipe/execute.hpp"         // IWYU pragma: export
#include "fuyu/command/pipe/flow.hpp"            // IWYU pragma: export
#include "fuyu/command/pipe/manipulation.hpp"    // IWYU pragma: export
#include "fuyu/command/pipe/push.hpp"            // IWYU pragma: export
#include "fuyu/command/pipe/query.hpp"           // IWYU pragma: export
#include "fuyu/command/pipe/record.hpp"          // IWYU pragma: export
#include "fuyu/command/pipe/render.hpp"          // IWYU pragma: export
#include "fuyu/command/pipe/set.hpp"             // IWYU pragma: export
#include "fuyu/command/pipe/submit.hpp"          // IWYU pragma: export
#include "fuyu/command/pipe/tag.hpp"             // IWYU pragma: export

namespace fubuki::fuyu
{

/**
 * Command pipes provide an interface to compose functions in `fuyu::command` in a way similar to `std::ranges`.
 * Under the hood, pipes are implemented using the free functions available in @see fubuki::fuyu::command, such as @see
 * fubuki::fuyu::command::set::line_width.
 *
 * @section example Example
 *
 * @code{.cpp}
 *
 * namespace cmd = fubuki::fuyu::command;
 *
 * auto command_buffer = ...;
 *
 * auto flow = cmd::pipe::record(command_buffer)
 *             | cmd::pipe::bind::pipeline(a_graphics_pipeline)
 *             | cmd::pipe::render_scope(render_target,
 *                               [=](cmd::pipe::flow f) noexcept
 *                               {
 *                                   return std::move(f)
 *                                   | pipe::push::constants(...)
 *                                   | pipe::draw::call(...)
 *                                   | ...;
 *                               })
 *             | cmd::pipe::bind::pipeline(a_compute_pipeline)
 *             | ...;
 *
 * if(const auto check = pipe::submit(queue, std::move(flow)); not check)
 * {
 *     handle(check.error());
 * }
 * @endcode
 */
namespace command::pipe
{

// NOLINTBEGIN(misc-unused-using-decls)

/**
 * Adaptor object returned by pipes, that can be used to create custom operations.
 * @section example Example
 *
 * @code{.cpp}
 * namespace external::pipe
 * {
 *
 * struct parameters
 * {
 *      something_heavy stuff = {};
 * };
 *
 * struct meow
 * {
 *     [[nodiscard]] auto operator()(parameters p) noexcept(...)
 *     {
 *         return fuyu::command::pipe::adaptor_closure
 *         {
 *             [param = std::move(p)](fuyu::command::pipe::flow f) noexcept(...)
 *             {
 *                 external::do_something(f.command_buffer(), param);
 *                 return f;
 *             }
 *         };
 *     }
 * };
 *
 * } // namespace external::pipe
 * @endcode
 *
 */
template<typename F>
using adaptor_closure = detail::adaptor_closure<F>;

/**
 * Tag indicating a command buffer used by a pipe::flow is already stopped upon submission.
 */
using already_ended = detail::already_ended;

/**
 * Tag indicating a command buffer passed to pipe::record is already started.
 */
using already_started = detail::already_started;

/**
 * An object representing a flow of commands into a command buffer.
 */
using flow = pipe::detail::flow;

/**
 * Insert a pipeline barrier. Can be used through either:
 * - fuyu::command::pipeline_barrier (for generic barriers)
 * - fuyu::command::image_memory_barrier (for a memory dependency on a single image)
 * - fuyu::command::buffer_memory_barrier (for a memory dependency on a single buffer)
 *
 * @see fubuki::fuyu::command::barrier
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdPipelineBarrier.html
 *
 * @section example Example
 *
 * @code{.cpp}
 * namespace cmd = fubuki::fuyu::command;
 *
 * auto flow = cmd::pipe::record(command_buffer)
 *             | cmd::pipe::barrier(cmd::buffer_memory_barrier{...}, {.source = ..., .destination = ..., .dependency = ...})
 *             | cmd::pipe::barrier(cmd::image_memory_barrier{...}, {.source = ..., .destination = ..., .dependency = ...})
 *             | cmd::pipe::barrier(cmd::pipeline_barrier{...});
 * @endcode
 */
inline constexpr auto barrier = detail::barrier{};

/**
 * Copy data between objects.
 *
 * @see fubuki::fuyu::command::copy
 * @see https://registry.khronos.org/vulkan/specs/1.3-extensions/man/html/vkCmdCopyBuffer.html
 * @see https://registry.khronos.org/vulkan/specs/1.3-extensions/man/html/vkCmdCopyBufferToImage.html
 * @see https://registry.khronos.org/vulkan/specs/1.3-extensions/man/html/vkCmdCopyImageToBuffer.html
 * @see https://registry.khronos.org/vulkan/specs/1.3-extensions/man/html/vkCmdCopyImage.html
 *
 * @section example Example
 *
 * @code{.cpp}
 * namespace cmd = fubuki::fuyu::command;
 *
 * auto flow = cmd::pipe::record(command_buffer)
 *             | cmd::pipe::copy(buffer_a, buffer_b, {VkBufferCopy{...}})
 *             | cmd::pipe::copy(image_a, VK_IMAGE_LAYOUT_XXX, buffer_a, {VkBufferImageCopy{...}})
 *             | cmd::pipe::copy(buffer_b, VK_IMAGE_LAYOUT_XXX, image_b, {VkBufferImageCopy{...}});
 * @endcode
 */
inline constexpr auto copy = detail::copy{};

/**
 * Insert an arbitrary operation.
 *
 * @section example Example
 *
 * @code{.cpp}
 * namespace cmd = fubuki::fuyu::command;
 *
 * auto flow = cmd::pipe::record(command_buffer)
 *          | cmd::pipe::custom([](cmd::pipe::flow f) noexcept
 *                              {
 *                                 do_something(f.command_buffer());
 *                                 return f;
 *                              };)
 * @endcode
 */
inline constexpr auto custom = detail::custom{};

/**
 * Execute secondary command buffers from a primary command buffer.
 *
 * @see fubuki::fuyu::command::execute
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdExecuteCommands.html
 *
 * @section example Example
 *
 * @code{.cpp}
 * namespace cmd = fubuki::fuyu::command;
 *
 * auto flow = cmd::pipe::record(command_buffer)
 *       | cmd::pipe::execute(secondary_command_buffer)
 *       | cmd::pipe::execute({another_secondary, a_third_secondary});
 * @endcode
 */
inline constexpr auto execute = detail::execute{};

/**
 * Fill a region of a buffer with a fixed value.
 *
 * @see fubuki::fuyu::command::fill
 * @see https://registry.khronos.org/vulkan/specs/1.3-extensions/man/html/vkCmdFillBuffer.html
 *
 * @section example Example
 *
 * @code{.cpp}
 * namespace cmd = fubuki::fuyu::command;
 *
 * auto flow = cmd::pipe::record(command_buffer)
 *       | cmd::pipe::fill(buffer, offset, size, data);
 * @endcode
 */
inline constexpr auto fill = detail::fill{};

/**
 * Update a buffer's contents from host memory.
 *
 * @see fubuki::fuyu::command::update
 * @see https://registry.khronos.org/vulkan/specs/1.3-extensions/man/html/vkCmdUpdateBuffer.html
 *
 * @section example Example
 *
 * @code{.cpp}
 * namespace cmd = fubuki::fuyu::command;
 *
 * auto flow = cmd::pipe::record(command_buffer)
 *       | cmd::pipe::update(buffer, offset, size, data);
 * @endcode
 */
inline constexpr auto update = detail::update{};

/**
 * Copy regions of an image, potentially performing format conversion.
 *
 * @see fubuki::fuyu::command::blit
 * @see https://registry.khronos.org/vulkan/specs/1.3-extensions/man/html/vkCmdBlitImage.html
 *
 * @section example Example
 *
 * @code{.cpp}
 * namespace cmd = fubuki::fuyu::command;
 *
 * auto flow = cmd::pipe::record(command_buffer)
 *       | cmd::pipe::blit(src_image, src_layout, dest_image, dest_layout, {VkImageBlit{...}}, filter);
 * @endcode
 */
inline constexpr auto blit = detail::blit{};

/**
 * Resolve regions of an image.
 *
 * @see fubuki::fuyu::command::resolve
 * @see https://registry.khronos.org/vulkan/specs/1.3-extensions/man/html/vkCmdResolveImage.html
 *
 * @section example Example
 *
 * @code{.cpp}
 * namespace cmd = fubuki::fuyu::command;
 *
 * auto flow = cmd::pipe::record(command_buffer)
 *       | cmd::pipe::resolve(src_image, src_layout, dest_image, dest_layout, {VkImageResolve{...}}, filter);
 * @endcode
 */
inline constexpr auto resolve = detail::resolve{};

/**
 * Clear regions of an image.
 *
 * @see fubuki::fuyu::command::clear
 * @see https://registry.khronos.org/vulkan/specs/1.3-extensions/man/html/vkCmdClearColorImage.html
 * @see https://registry.khronos.org/vulkan/specs/1.3-extensions/man/html/vkCmdClearDepthStencilImage.html
 *
 * @section example Example
 *
 * @code{.cpp}
 * namespace cmd = fubuki::fuyu::command;
 *
 * auto flow = cmd::pipe::record(command_buffer)
 *       | cmd::pipe::clear(colour_image, colour_image_layout, colour, {VkImageSubresourceRange{...}})                     // Colour images
 *       | cmd::pipe::clear(depth_stencil_image, depth_stencil_image_layout, depth_stencil, VkImageSubresourceRange{...}); // Depth-stencil
 * @endcode
 */
inline constexpr auto clear = detail::clear{};

/**
 * Start a command flow. Can only be called at the top of the flow.
 *
 * @section example Example
 *
 * @code{.cpp}
 * namespace cmd = fubuki::fuyu::command;
 *
 * // Puts the command buffer in a recording state.
 * auto flow = cmd::pipe::record(command_buffer)
 *       | ...;
 *
 * // Won't call attempt to put the command buffer in a recording state.
 * auto flow_2 = cmd::pipe::record(cmd::pipe::already_started{another_command_buffer})
 *               | ...;
 * @endcode
 */
inline constexpr auto record = detail::record{};

/**
 * Introduce a render scope, either through render passes or dynamic rendering based on the parameters.
 *
 * @see fububi::fuyu::command::rendering_scope
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdBeginRenderPass.html
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdEndRenderPass.html
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdBeginRendering.html
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdEndRenderingKHR.html
 *
 * @section example Example
 *
 * @code{.cpp}
 * namespace cmd = fubuki::fuyu::command;
 *
 * auto flow = cmd::pipe::record(command_buffer)
 *             | cmd::pipe::render_scope(cmd::render_target{...}, // Render passes
 *                                       VK_SUBPASS_CONTENTS_INLINE,
 *                                       [](cmd::pipe::flow f, args... arguments) noexcept
 *                                       {
 *                                          do_something(arguments);
 *                                          return std::move(f)
 *                                                 | cmd::pipe::draw::call(...)
 *                                                 | cmd::pipe::next_subpass(...)
 *                                                 | cmd::pipe::draw::call(...);
 *                                       },
 *                                       arguments)
 *             | cmd::pipe::render_scope(cmd::dynamic_render_target{...}, // Dynamic rendering
 *                                       [](cmd::pipe::flow f, args... arguments) noexcept
 *                                       {
 *                                          return std::move(f)
 *                                                 | cmd::pipe::draw::call(...);
 *                                       });
 * @endcode
 */
inline constexpr auto render_scope = detail::render_scope{};

/**
 * Transition to the next subpass of a render pass.
 *
 * @see fubuki::fuyu::command::next_subpass
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdNextSubpass.html
 */
inline constexpr auto next_subpass = detail::next_subpass{};

/**
 * Submit a flow to a queue.
 *
 * @see fubuki::fuyu::command::submit
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkQueueSubmit.html
 *
 * @section example Example
 *
 * @code{.cpp}
 * namespace cmd = fubuki::fuyu::command;
 *
 * auto flow = cmd::pipe::record(command_buffer)
 *       | ...;
 *
 * if(const auto check = pipe::submit(queue, std::move(flow)); not check)
 * {
 *     use(check.error());
 * }
 * @endcode
 */
inline constexpr auto submit = detail::submit{};

/// Command pipes allowing to bind objects (pipelines, descriptor sets, buffers...).
/// @see fubuki::fuyu::command::bind
namespace bind
{

/**
 * Bind descriptor sets to a command buffer.
 *
 * @see fubuki::fuyu::command::bind::descriptor_sets
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdBindDescriptorSets.html
 *
 * @section example Example
 *
 * @code{.cpp}
 * namespace cmd = fubuki::fuyu::command;
 *
 * auto flow = cmd::pipe::record(command_buffer)
 *             | cmd::pipe::bind::descriptor_sets(VK_PIPELINE_BIND_POINT_GRAPHICS,
 *                                                pipeline_layout,
 *                                                first_set,
 *                                                {set_0, set_1},
 *                                                {dynamic_offset_0, dynamic_offset_1});
 * @endcode
 */
inline constexpr auto descriptor_sets = detail::bind::descriptor_sets{};

/**
 * Bind an index buffer to a command buffer.
 *
 * @see fubuki::fuyu::command::bind::index_buffer
 * @see https://registry.khronos.org/vulkan/specs/1.3-extensions/man/html/vkCmdBindIndexBuffer.html
 *
 * @section example Example
 *
 * @code{.cpp}
 * namespace cmd = fubuki::fuyu::command;
 *
 * auto flow = cmd::pipe::record(command_buffer)
 *             | cmd::pipe::bind::descriptor_sets(index_buffer,
 *                                                offset,
 *                                                VK_INDEX_TYPE_UINT32);
 *             | cmd::pipe::bind::descriptor_sets(another_index_buffer,
 *                                                offset,
 *                                                size,
 *                                                VK_INDEX_TYPE_UINT32);
 * @endcode
 */
inline constexpr auto index_buffer = detail::bind::index_buffer{};

/**
 * Bind a pipeline object to a command buffer.
 *
 * @see fubuki::fuyu::command::bind::pipeline
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdBindPipeline.html
 *
 * @section example Example
 *
 * @code{.cpp}
 * namespace cmd = fubuki::fuyu::command;
 *
 * auto flow = cmd::pipe::record(command_buffer)
 *             | cmd::pipe::bind::pipeline(graphics_pipeline)
 *             | cmd::pipe::bind::pipeline(compute_pipeline)
 *             | cmd::pipe::bind::pipeline(ray_tracing_pipeline_khr)
 *             | cmd::pipe::bind::pipeline(ray_tracing_pipeline_nv);
 * @endcode
 */
inline constexpr auto pipeline = detail::bind::pipeline{};

/**
 * Bind vertex buffers to a command buffer.
 *
 * @see fubuki::fuyu::command::bind::vertex_buffers
 * @see https://registry.khronos.org/vulkan/specs/1.3-extensions/man/html/vkCmdBindVertexBuffers.html
 *
 * @code{.cpp}
 * namespace cmd = fubuki::fuyu::command;
 *
 * auto flow = cmd::pipe::record(command_buffer)
 *             | cmd::pipe::bind::vertex_buffers(first_binding,
 *                                               {vbo_a, vbo_b},
 *                                               {offset_a, offset_b});
 * @endcode
 *
 */
inline constexpr auto vertex_buffers = detail::bind::vertex_buffers{};

/**
 * Bind one vertex buffer to a command buffer.
 *
 * @see fubuki::fuyu::command::bind::vertex_buffers
 * @see https://registry.khronos.org/vulkan/specs/1.3-extensions/man/html/vkCmdBindVertexBuffers.html
 *
 * @code{.cpp}
 * namespace cmd = fubuki::fuyu::command;
 *
 * auto flow = cmd::pipe::record(command_buffer)
 *             | cmd::pipe::bind::vertex_buffer(first_binding,
 *                                              vbo,
 *                                              offset);
 * @endcode
 *
 */
inline constexpr auto vertex_buffer = detail::bind::vertex_buffer{};

#if defined(VK_VERSION_1_4)
#endif // defined(VK_VERSION_1_4)

} // namespace bind

/// Command pipes dispatching work for compute pipelines.
/// @see fubuki::fuyu::command::dispatch
namespace dispatch
{

/**
 * Dispatch compute work items.
 *
 * @see fubuki::fuyu::command::dispatch::direct
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdDispatch.html
 *
 * @section example Example
 *
 * @code{.cpp}
 * namespace cmd = fubuki::fuyu::command;
 *
 * auto flow = cmd::pipe::record(command_buffer)
 *             | cmd::pipe::bind::pipeline(compute_pipeline)
 *             | cmd::pipe::dispatch::direct(group_count_x, group_count_y, group_count_z);
 * @endcode
 */
inline constexpr auto direct = detail::dispatch::direct{};

/**
 * Dispatch compute work items with indirect parameters.
 *
 * @see fubuki::fuyu::command::dispatch::indirect
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdDispatchIndirect.html
 *
 * @section example Example
 *
 * @code{.cpp}
 * namespace cmd = fubuki::fuyu::command;
 *
 * auto flow = cmd::pipe::record(command_buffer)
 *             | cmd::pipe::bind::pipeline(compute_pipeline)
 *             | cmd::pipe::dispatch::indirect(buffer, offset);
 * @endcode
 */
inline constexpr auto indirect = detail::dispatch::indirect{};

#if defined(VK_VERSION_1_1)

/**
 * Dispatch compute work items with non-zero base values for the workgroup IDs.
 *
 * @see fubuki::fuyu::command::dispatch::direct
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdDispatchBase.html
 *
 * @section example Example
 *
 * @code{.cpp}
 * namespace cmd = fubuki::fuyu::command;
 *
 * auto flow = cmd::pipe::record(command_buffer)
 *             | cmd::pipe::bind::pipeline(compute_pipeline)
 *             | cmd::pipe::dispatch::base(base_group_x, base_group_y, base_group_z, group_count_x, group_count_y, group_count_z);
 * @endcode
 */
inline constexpr auto base = detail::dispatch::base{};

#endif // defined(VK_VERSION_1_1)

} // namespace dispatch

/// Command pipes performing draw calls.
/// @see fubuki::fuyu::command::draw
namespace draw
{

/**
 * Draw primitives.
 *
 * @see fubuki::fuyu::command::draw::call
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdDraw.html
 *
 * @section example Example
 *
 * @code{.cpp}
 * namespace cmd = fubuki::fuyu::command;
 *
 * auto flow = cmd::pipe::record(command_buffer)
 *             | cmd::pipe::bind::pipeline(...)
 *             | cmd::pipe::bind::descriptor_sets(...)
 *             | cmd::pipe::render_scope(cmd::dynamic_render_target{...}, // Dynamic rendering
 *                                       [](cmd::pipe::flow f, args... arguments) noexcept
 *                                       {
 *                                          return std::move(f)
 *                                          | cmd::pipe::draw::call(...);
 *                                       });
 * @endcode
 */
inline constexpr auto call = detail::draw::call{};

/**
 * Draw primitives with indexed vertices.
 *
 * @see fubuki::fuyu::command::draw::indexed
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdDrawIndexed.html
 *
 * @section example Example
 *
 * @code{.cpp}
 * namespace cmd = fubuki::fuyu::command;
 *
 * auto flow = cmd::pipe::record(command_buffer)
 *             | cmd::pipe::bind::pipeline(...)
 *             | cmd::pipe::bind::descriptor_sets(...)
 *             | cmd::pipe::render_scope(cmd::dynamic_render_target{...}, // Dynamic rendering
 *                                       [](cmd::pipe::flow f, args... arguments) noexcept
 *                                       {
 *                                          return std::move(f)
 *                                          | cmd::pipe::draw::indexed(...);
 *                                       });
 * @endcode
 */
inline constexpr auto indexed = detail::draw::indexed{};

/**
 * Draw primitives with indexed vertices.
 *
 * @see fubuki::fuyu::command::draw::indirect
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdDrawIndexed.html
 *
 * @section example Example
 *
 * @code{.cpp}
 * namespace cmd = fubuki::fuyu::command;
 *
 * auto flow = cmd::pipe::record(command_buffer)
 *             | cmd::pipe::bind::pipeline(...)
 *             | cmd::pipe::bind::descriptor_sets(...)
 *             | cmd::pipe::render_scope(cmd::dynamic_render_target{...}, // Dynamic rendering
 *                                       [](cmd::pipe::flow f, args... arguments) noexcept
 *                                       {
 *                                          return std::move(f)
 *                                          | cmd::pipe::draw::indirect(...);
 *                                       });
 * @endcode
 */
inline constexpr auto indirect = detail::draw::indirect{};

/**
 * Draw primitives with indirect parameters and indexed vertices.
 *
 * @see fubuki::fuyu::command::draw::indexed_indirect
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdDrawIndexedIndirect.html
 *
 * @section example Example
 *
 * @code{.cpp}
 * namespace cmd = fubuki::fuyu::command;
 *
 * auto flow = cmd::pipe::record(command_buffer)
 *             | cmd::pipe::bind::pipeline(...)
 *             | cmd::pipe::bind::descriptor_sets(...)
 *             | cmd::pipe::render_scope(cmd::dynamic_render_target{...}, // Dynamic rendering
 *                                       [](cmd::pipe::flow f, args... arguments) noexcept
 *                                       {
 *                                          return std::move(f)
 *                                          | cmd::pipe::draw::indexed_indirect(...);
 *                                       });
 * @endcode
 */
inline constexpr auto indexed_indirect = detail::draw::indexed_indirect{};

#if defined(VK_VERSION_1_2)

/**
 * Draw parameters with indirect parameters, indexed vertices, and draw count.
 *
 * @see fubuki::fuyu::command::draw::indexed_indirect_count
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdDrawIndexedIndirectCount.html
 *
 * @section example Example
 *
 * @code{.cpp}
 * namespace cmd = fubuki::fuyu::command;
 *
 * auto flow = cmd::pipe::record(command_buffer)
 *             | cmd::pipe::bind::pipeline(...)
 *             | cmd::pipe::bind::descriptor_sets(...)
 *             | cmd::pipe::render_scope(cmd::dynamic_render_target{...}, // Dynamic rendering
 *                                       [](cmd::pipe::flow f, args... arguments) noexcept
 *                                       {
 *                                          return std::move(f)
 *                                          | cmd::pipe::draw::indexed_indirect_count(...);
 *                                       });
 * @endcode
 */
inline constexpr auto indexed_indirect_count = detail::draw::indexed_indirect_count{};

/**
 *  Draw primitives with indirect parameters.
 *
 * @see fubuki::fuyu::command::draw::indirect_count
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdDrawIndirectCount.html
 *
 * @section example Example
 *
 * @code{.cpp}
 * namespace cmd = fubuki::fuyu::command;
 *
 * auto flow = cmd::pipe::record(command_buffer)
 *             | cmd::pipe::bind::pipeline(...)
 *             | cmd::pipe::bind::descriptor_sets(...)
 *             | cmd::pipe::render_scope(cmd::dynamic_render_target{...}, // Dynamic rendering
 *                                       [](cmd::pipe::flow f, args... arguments) noexcept
 *                                       {
 *                                          return std::move(f)
 *                                          | cmd::pipe::draw::indirect_count(...);
 *                                       });
 * @endcode
 */
inline constexpr auto indirect_count = detail::draw::indirect_count{};

#endif // defined(VK_VERSION_1_2)

} // namespace draw

/// Errors related to pipes.
namespace error
{

/**
 * Any error that can happen through pipes.
 */
using any = detail::error::any;

/**
 * Indicates an error occurred upon starting the command buffer recording.
 */
using begin = detail::error::begin;

/**
 * Indicates an error occurred upon ending the command buffer recording.
 */
using end = detail::error::end;

/**
 * Indicates an error occurred upon submission.
 */
using submit = detail::error::submit;

} // namespace error

/**
 * Any error that can happen through pipes.
 */
using any_error = error::any;

/// Command pipes related to event states.
namespace event
{

/**
 * Set an event object to signaled state.
 *
 * @see fubuki::fuyu::command::event::set
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetEvent.html
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetEvent2KHR.html
 *
 * @section example Example
 *
 * @code{.cpp}
 * namespace cmd = fubuki::fuyu::command;
 *
 * auto flow = cmd::pipe::record(command_buffer)
 *             | cmd::pipe::event::set(an_event, VK_PIPELINE_STAGE_VERTEX_INPUT_BIT);
 * @endcode
 */
inline constexpr auto set = detail::event::set{};

/**
 * Reset an event object to non-signaled state.
 *
 * @see fubuki::fuyu::command::event::reset
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdResetEvent.html
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdResetEvent2KHR.html
 *
 *
 * @section example Example
 *
 * @code{.cpp}
 * namespace cmd = fubuki::fuyu::command;
 *
 * auto flow = cmd::pipe::record(command_buffer)
 *             | cmd::pipe::event::reset(an_event, VK_PIPELINE_STAGE_VERTEX_INPUT_BIT);
 * @endcode
 */
inline constexpr auto reset = detail::event::reset{};

/**
 * Wait for one or more events and insert a set of memory.
 *
 * @see fubuki::fuyu::command::event::reset
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdWaitEvents.html
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdWaitEvents2KHR.html
 *
 * @section example Example
 *
 * @code{.cpp}
 * namespace cmd = fubuki::fuyu::command;
 *
 * auto flow = cmd::pipe::record(command_buffer)
 *             | cmd::pipe::event::wait(an_event, ...);
 * @endcode
 */
inline constexpr auto wait = detail::event::wait{};

} // namespace event

/// Command pipes performing push operations.
/// @see fubuki::fuyu::command::push
namespace push
{

/**
 * Update the values of push constants.
 *
 * @see fubuki::fuyu::command::push::constants
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdPushConstants.html
 *
 * @section example Example
 *
 * @code{.cpp}
 * namespace cmd = fubuki::fuyu::command;
 *
 * auto flow = cmd::pipe::record(command_buffer)
 *             | cmd::pipe::push::constants(pipeline_layout,
 *                                          VK_SHADER_STAGE_VERTEX_BIT,
 *                                          offset,
 *                                          data);
 * @endcode
 */
inline constexpr auto constants = detail::push::constants{};

/**
 * Push descriptor updates into a command buffer
 * @see fubuki::fuyu::command::push::descriptor_set
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdPushDescriptorSet.html
 *
 * @section example Example
 *
 * @code{.cpp}
 * namespace cmd = fubuki::fuyu::command;
 *
 * auto flow = cmd::pipe::record(command_buffer)
 *             | cmd::pipe::push::descriptor_set(pipeline_layout,
 *                                               bind_point,
 *                                               layout,
 *                                               set,
 *                                               writes);
 * @endcode
 *
 */
inline constexpr auto descriptor_set = detail::push::descriptor_set{};

/**
 * Push descriptor updates into a command buffer using a descriptor update template.
 * @see fubuki::fuyu::command::push::descriptor_set_with_template
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdPushDescriptorSetWithTemplate.html
 *
 * @section example Example
 *
 * @code{.cpp}
 * namespace cmd = fubuki::fuyu::command;
 *
 * auto flow = cmd::pipe::record(command_buffer)
 *             | cmd::pipe::push::descriptor_set_with_template(pipeline_layout,
 *                                                             update,
 *                                                             layout,
 *                                                             set,
 *                                                             data);
 * @endcode
 */
inline constexpr auto descriptor_set_with_template = detail::push::descriptor_set_with_template{};

} // namespace push

/// Query command pipes.
namespace query
{

/**
 * Inserts a fuyu::command::query_scope.
 *
 * @see fubuki::fuyu::command::query::scope
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdBeginQuery.html
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdEndQuery.html
 *
 * @section example Example
 *
 * @code{.cpp}
 * namespace cmd = fubuki::fuyu::command;
 *
 * auto flow = cmd::pipe::record(command_buffer)
 *             | cmd::pipe::query::scope(pool,
 *                                       query,
 *                                       [](cmd::pipe::flow flow, args... arguments) noexcept
 *                                       {
 *                                             do_something_with(arguments...);
 *                                             return std::move(flow)
 *                                                     | ...;
 *                                       },
 *                                       arguments...);
 * @endcode
 */
inline constexpr auto scope = detail::query::scope{};

/**
 * Reset queries in a query pool.
 *
 * @see fubuki::fuyu::command::query::reset_pool
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdResetQueryPool.html
 *
 * @section example Example
 *
 * @code{.cpp}
 * namespace cmd = fubuki::fuyu::command;
 *
 * auto flow = cmd::pipe::record(command_buffer)
 *             | cmd::pipe::query::reset_pool(pool,
 *                                            first_query,
 *                                            query_count);
 * @endcode
 */
inline constexpr auto reset_pool = detail::query::reset_pool{};

/**
 * Copy the results of queries in a query pool to a buffer object.
 *
 * @see fubuki::fuyu::command::query::copy_pool_results
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdCopyQueryPoolResults.html
 *
 * @section example Example
 *
 * @code{.cpp}
 * namespace cmd = fubuki::fuyu::command;
 *
 * auto flow = cmd::pipe::record(command_buffer)
 *             | cmd::pipe::query::scope(pool,
 *                                       query,
 *                                       [&](cmd::pipe::flow flow) noexcept
 *                                       {
 *                                             return std::move(flow)
 *                                                     | cmd::pipe::copy_pool_results(pool, query, 1, buffer, offset, stride);
 *                                       });
 * @endcode
 */
inline constexpr auto copy_pool_results = detail::query::copy_pool_results{};

/**
 * Write a device timestamp into a query object.
 *
 * @see fubuki::fuyu::command::query::write_timestamp
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdWriteTimestamp.html
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdWriteTimestamp2KHR.html
 *
 * @section example Example
 *
 * @code{.cpp}
 * namespace cmd = fubuki::fuyu::command;
 *
 * auto flow = cmd::pipe::record(command_buffer)
 *             | cmd::pipe::query::write_timestamp(VK_PIPELINE_STAGE_VERTEX_SHADER_BIT,
 *                                                 pool,
 *                                                 query);
 * @endcode
 */
inline constexpr auto write_timestamp = detail::query::write_timestamp{};

} // namespace query

/// Command pipes modifying dynamic states during recording of a command buffer.
namespace set
{

/**
 * Set the viewport dynamically for a command buffer.
 *
 * @see fubuki::fuyu::command::set::viewport
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetViewport.html
 *
 * @section example Example
 *
 * @code{.cpp}
 * namespace cmd = fubuki::fuyu::command;
 *
 * auto flow = cmd::pipe::record(command_buffer)
 *             | cmd::pipe::set::viewport(first,
 *                                       {VkViewport{...}});
 * @endcode
 */
inline constexpr auto viewport = detail::set::viewport{};

/**
 * Set scissor rectangles dynamically for a command buffer.
 *
 * @see fubuki::fuyu::command::set::scissor
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetScissor.html
 *
 * @section example Example
 *
 * @code{.cpp}
 * namespace cmd = fubuki::fuyu::command;
 *
 * auto flow = cmd::pipe::record(command_buffer)
 *             | cmd::pipe::set::scissor(first,
 *                                      {VkRect2D{...}});
 * @endcode
 */
inline constexpr auto scissor = detail::set::scissor{};

/**
 * Set line width dynamically for a command buffer.
 *
 * @see fubuki::fuyu::command::set::line_width
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetLineWidth.html
 *
 * @section example Example
 *
 * @code{.cpp}
 * namespace cmd = fubuki::fuyu::command;
 *
 * auto flow = cmd::pipe::record(command_buffer)
 *             | cmd::pipe::set::scissor(width);
 * @endcode
 */
inline constexpr auto line_width = detail::set::line_width{};

/**
 * Set the values of blend constants.
 *
 * @see fubuki::fuyu::command::set::line_width
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetBlendConstants.html
 *
 * @section example Example
 *
 * @code{.cpp}
 * namespace cmd = fubuki::fuyu::command;
 *
 * auto flow = cmd::pipe::record(command_buffer)
 *             | cmd::pipe::set::blend_constants({0.5f, 0.2f, 0.3f, 1.0f});
 * @endcode
 */
inline constexpr auto blend_constants = detail::set::blend_constants{};

#if defined(VK_VERSION_1_1)

/**
 * Modify device mask of a command buffer.
 *
 * @see fubuki::fuyu::command::set::device_mask
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetDeviceMask.html
 *
 * @section example Example
 *
 * @code{.cpp}
 * namespace cmd = fubuki::fuyu::command;
 *
 * auto flow = cmd::pipe::record(command_buffer)
 *             | cmd::pipe::set::device_mask(mask);
 * @endcode
 */
inline constexpr auto device_mask = detail::set::device_mask{};

#endif // defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_3)

/**
 * Set cull mode dynamically for a command buffer.
 *
 * @see fubuki::fuyu::command::set::cull_mode
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetCullMode.html
 *
 * @section example Example
 *
 * @code{.cpp}
 * namespace cmd = fubuki::fuyu::command;
 *
 * auto flow = cmd::pipe::record(command_buffer)
 *             | cmd::pipe::set::cull_mode(VK_CULL_MODE_FRONT_BIT);
 * @endcode
 */
inline constexpr auto cull_mode = detail::set::cull_mode{};

/**
 * Set front face orientation dynamically for a command buffer.
 *
 * @see fubuki::fuyu::command::set::front_face
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetFrontFace.html
 *
 * @section example Example
 *
 * @code{.cpp}
 * namespace cmd = fubuki::fuyu::command;
 *
 * auto flow = cmd::pipe::record(command_buffer)
 *             | cmd::pipe::set::front_face(VK_FRONT_FACE_COUNTER_CLOCKWISE);
 * @endcode
 */
inline constexpr auto front_face = detail::set::front_face{};

/**
 * Set primitive topology state dynamically for a command buffer.
 *
 * @see fubuki::fuyu::command::set::primitive_topology
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetPrimitiveTopology.html
 *
 * @section example Example
 *
 * @code{.cpp}
 * namespace cmd = fubuki::fuyu::command;
 *
 * auto flow = cmd::pipe::record(command_buffer)
 *             | cmd::pipe::set::primitive_topology(VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP);
 * @endcode
 */
inline constexpr auto primitive_topology = detail::set::primitive_topology{};

/**
 * Set the viewport count and viewports dynamically for a command buffer.
 *
 * @see fubuki::fuyu::command::set::viewport_with_count
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetViewportWithCount.html
 *
 * @section example Example
 *
 * @code{.cpp}
 * namespace cmd = fubuki::fuyu::command;
 *
 * auto flow = cmd::pipe::record(command_buffer)
 *             | cmd::pipe::set::viewport_with_count({VkViewport{...}, VkViewport{...}});
 * @endcode
 */
inline constexpr auto viewport_with_count = detail::set::viewport_with_count{};

/**
 *  Set the scissor count and scissor rectangular bounds dynamically for a command buffer.
 *
 * @see fubuki::fuyu::command::set::scissor_with_count
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetScissorWithCount.html
 *
 * @section example Example
 *
 * @code{.cpp}
 * namespace cmd = fubuki::fuyu::command;
 *
 * auto flow = cmd::pipe::record(command_buffer)
 *             | cmd::pipe::set::scissor_with_count({VkRect2D{...}, VkRect2D{...}});
 * @endcode
 */
inline constexpr auto scissor_with_count = detail::set::scissor_with_count{};

/**
 * Controls whether primitives are discarded before the rasterization stage dynamically for a command buffer.
 *
 * @see fubuki::fuyu::command::set::rasterizer_discard_enable
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetRasterizerDiscardEnable.html
 *
 * @section example Example
 *
 * @code{.cpp}
 * namespace cmd = fubuki::fuyu::command;
 *
 * auto flow = cmd::pipe::record(command_buffer)
 *             | cmd::pipe::set::rasterizer_discard_enable(false);
 * @endcode
 */
inline constexpr auto rasterizer_discard_enable = detail::set::rasterizer_discard_enable{};

/**
 * Set primitive assembly restart state dynamically for a command buffer.
 *
 * @see fubuki::fuyu::command::set::primitive_restart_enable
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetPrimitiveRestartEnable.html
 *
 * @section example Example
 *
 * @code{.cpp}
 * namespace cmd = fubuki::fuyu::command;
 *
 * auto flow = cmd::pipe::record(command_buffer)
 *             | cmd::pipe::set::primitive_restart_enable(false);
 * @endcode
 */
inline constexpr auto primitive_restart_enable = detail::set::primitive_restart_enable{};

#endif // defined(VK_VERSION_1_3)

namespace depth
{

/**
 * Set depth bias factors and clamp dynamically for a command buffer.
 *
 * @see fubuki::fuyu::command::set::depth::bias
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetDepthBias.html
 *
 * @section example Example
 *
 * @code{.cpp}
 * namespace cmd = fubuki::fuyu::command;
 *
 * auto flow = cmd::pipe::record(command_buffer)
 *             | cmd::pipe::set::depth::bias(constant_factor, clamp, slope_factor);
 * @endcode
 */
inline constexpr auto bias = detail::set::depth::bias{};

/**
 * Set depth bounds range dynamically for a command buffer.
 *
 * @see fubuki::fuyu::command::set::depth::bounds
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetDepthBounds.html
 *
 * @section example Example
 *
 * @code{.cpp}
 * namespace cmd = fubuki::fuyu::command;
 *
 * auto flow = cmd::pipe::record(command_buffer)
 *             | cmd::pipe::set::depth::bounds(min, max);
 * @endcode
 */
inline constexpr auto bounds = detail::set::depth::bounds{};

#if defined(VK_VERSION_1_3)

/**
 * Set depth test enable dynamically for a command buffer.
 *
 * @see fubuki::fuyu::command::set::depth::test_enable
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetDepthTestEnable.html
 *
 * @section example Example
 *
 * @code{.cpp}
 * namespace cmd = fubuki::fuyu::command;
 *
 * auto flow = cmd::pipe::record(command_buffer)
 *             | cmd::pipe::set::depth::test_enable(false);
 * @endcode
 */
inline constexpr auto test_enable = detail::set::depth::test_enable{};

/**
 * Set depth write enable dynamically for a command buffer.
 *
 * @see fubuki::fuyu::command::set::depth::write_enable
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetDepthWriteEnable.html
 *
 * @section example Example
 *
 * @code{.cpp}
 * namespace cmd = fubuki::fuyu::command;
 *
 * auto flow = cmd::pipe::record(command_buffer)
 *             | cmd::pipe::set::depth::write_enable(false);
 * @endcode
 */
inline constexpr auto write_enable = detail::set::depth::write_enable{};

/**
 * Set depth comparison operator dynamically for a command buffer.
 *
 * @see fubuki::fuyu::command::set::depth::compare_op
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetDepthCompareOp.html
 *
 * @section example Example
 *
 * @code{.cpp}
 * namespace cmd = fubuki::fuyu::command;
 *
 * auto flow = cmd::pipe::record(command_buffer)
 *             | cmd::pipe::set::depth::compare_op(VK_COMPARE_OP_GREATER);
 * @endcode
 */
inline constexpr auto compare_op = detail::set::depth::compare_op{};

/**
 * Set depth bounds test enable dynamically for a command buffer.
 *
 * @see fubuki::fuyu::command::set::depth::bounds_test_enable
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetDepthBoundsTestEnable.html
 *
 * @section example Example
 *
 * @code{.cpp}
 * namespace cmd = fubuki::fuyu::command;
 *
 * auto flow = cmd::pipe::record(command_buffer)
 *             | cmd::pipe::set::depth::bounds_test_enable(false);
 * @endcode
 */
inline constexpr auto bounds_test_enable = detail::set::depth::bounds_test_enable{};

/**
 * Control whether to bias fragment depth values dynamically for a command buffer.
 *
 * @see fubuki::fuyu::command::set::depth::bias_enable
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetDepthBiasEnable.html
 *
 * @section example Example
 *
 * @code{.cpp}
 * namespace cmd = fubuki::fuyu::command;
 *
 * auto flow = cmd::pipe::record(command_buffer)
 *             | cmd::pipe::set::depth::bias_enable(false);
 * @endcode
 */
inline constexpr auto bias_enable = detail::set::depth::bias_enable{};

#endif // defined(VK_VERSION_1_3)

} // namespace depth

namespace stencil
{

/**
 * Set stencil compare mask dynamically for a command buffer.
 *
 * @see fubuki::fuyu::command::set::stencil::compare_mask
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetStencilCompareMask.html
 *
 * @section example Example
 *
 * @code{.cpp}
 * namespace cmd = fubuki::fuyu::command;
 *
 * auto flow = cmd::pipe::record(command_buffer)
 *             | cmd::pipe::set::stencil::compare_mask(VK_STENCIL_FACE_FRONT_BIT, mask);
 * @endcode
 */
inline constexpr auto compare_mask = detail::set::stencil::compare_mask{};

/**
 * Set stencil write mask dynamically for a command buffer.
 *
 * @see fubuki::fuyu::command::set::stencil::write_mask
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetStencilWriteMask.html
 *
 * @section example Example
 *
 * @code{.cpp}
 * namespace cmd = fubuki::fuyu::command;
 *
 * auto flow = cmd::pipe::record(command_buffer)
 *             | cmd::pipe::set::stencil::write_mask(VK_STENCIL_FACE_FRONT_BIT, mask);
 * @endcode
 */
inline constexpr auto write_mask = detail::set::stencil::write_mask{};

/**
 * Set stencil reference value dynamically for a command buffer.
 *
 * @see fubuki::fuyu::command::set::stencil::reference
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetStencilReference.html
 *
 * @section example Example
 *
 * @code{.cpp}
 * namespace cmd = fubuki::fuyu::command;
 *
 * auto flow = cmd::pipe::record(command_buffer)
 *             | cmd::pipe::set::stencil::reference(VK_STENCIL_FACE_FRONT_BIT, reference);
 * @endcode
 */
inline constexpr auto reference = detail::set::stencil::reference{};

#if defined(VK_VERSION_1_3)

/**
 * Set stencil test enable dynamically for a command buffer.
 *
 * @see fubuki::fuyu::command::set::stencil::test_enable
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetStencilTestEnable.html
 *
 * @section example Example
 *
 * @code{.cpp}
 * namespace cmd = fubuki::fuyu::command;
 *
 * auto flow = cmd::pipe::record(command_buffer)
 *             | cmd::pipe::set::stencil::test_enable(false);
 * @endcode
 */
inline constexpr auto test_enable = detail::set::stencil::test_enable{};

/**
 * Set stencil test enable dynamically for a command buffer.
 *
 * @see fubuki::fuyu::command::set::stencil::op
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetStencilOp.html
 *
 * @section example Example
 *
 * @code{.cpp}
 * namespace cmd = fubuki::fuyu::command;
 *
 * auto flow = cmd::pipe::record(command_buffer)
 *             | cmd::pipe::set::stencil::op(VK_STENCIL_FACE_FRONT_BIT,
 *                                           fail,
 *                                           pass,
 *                                           depth_fail,
 *                                           compare);
 * @endcode
 */
inline constexpr auto op = detail::set::stencil::op{};

#endif // defined(VK_VERSION_1_3)

} // namespace stencil

#if defined(VK_VERSION_1_4)

/**
 * Set line stipple dynamically for a command buffer.
 *
 * @see fubuki::fuyu::command::set::line_stipple
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetLineStipple.html
 *
 * @section example Example
 *
 * @code{.cpp}
 * namespace cmd = fubuki::fuyu::command;
 *
 * auto flow = cmd::pipe::record(command_buffer)
 *             | cmd::pipe::set::line_stipple(factor, pattern);
 * @endcode
 */
inline constexpr auto line_stipple = detail::set::line_stipple{};

/**
 * Set colour attachment location mappings for a command buffer.
 *
 * @see fubuki::fuyu::command::set::rendering_attachment_locations
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetRenderingAttachmentLocations.html
 *
 * @section example Example
 *
 * @code{.cpp}
 * namespace cmd = fubuki::fuyu::command;
 *
 * auto flow = cmd::pipe::record(command_buffer)
 *             | cmd::pipe::set::rendering_attachment_locations({0, 1, 2});
 * @endcode
 */
inline constexpr auto rendering_attachment_locations = detail::set::rendering_attachment_locations{};

/**
 * Set input attachment index mappings for a command buffer.
 *
 * @see fubuki::fuyu::command::set::rendering_attachment_indices
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdSetRenderingInputAttachmentIndices.html
 *
 * @section example Example
 *
 * @code{.cpp}
 * namespace cmd = fubuki::fuyu::command;
 *
 * auto flow = cmd::pipe::record(command_buffer)
 *             | cmd::pipe::set::rendering_attachment_indices({0, 1, 2},      // Colour attachments
 *                                                            depth_index,    // Depth attachment (optional)
 *                                                            stencil_index); // Stencil attachment (optional)
 * @endcode
 */
inline constexpr auto rendering_attachment_indices = detail::set::rendering_attachment_indices{};

#endif // defined(VK_VERSION_1_4)

} // namespace set

// NOLINTEND(misc-unused-using-decls)

} // namespace command::pipe

namespace cmd = command;

} // namespace fubuki::fuyu

#endif // FUBUKI_FUYU_COMMAND_PIPES_HPPPIPES_HPP
