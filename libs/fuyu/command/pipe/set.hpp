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

#ifndef FUBUKI_FUYU_COMMAND_PIPE_SET_HPP
#define FUBUKI_FUYU_COMMAND_PIPE_SET_HPP

#include "fuyu/command/pipe/adaptor_closure.hpp"
#include "fuyu/command/pipe/flow.hpp"
#include "fuyu/command/set.hpp"

namespace fubuki::fuyu::command::pipe::detail::set
{

struct viewport
{
    auto operator()(std::uint32_t first, std::span<const VkViewport> viewports) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::set::viewport(f.command_buffer(), first, viewports);
                                   return f;
                               }};
    }

    auto operator()(std::uint32_t first, std::initializer_list<VkViewport> viewports) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::set::viewport(f.command_buffer(), first, viewports);
                                   return f;
                               }};
    }
};

struct scissor
{
    auto operator()(std::uint32_t first, std::span<const VkRect2D> scissors) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::set::scissor(f.command_buffer(), first, scissors);
                                   return f;
                               }};
    }

    auto operator()(std::uint32_t first, std::initializer_list<VkRect2D> scissors) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::set::scissor(f.command_buffer(), first, scissors);
                                   return f;
                               }};
    }
};

struct line_width
{
    auto operator()(float width) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::set::line_width(f.command_buffer(), width);
                                   return f;
                               }};
    }
};

struct blend_constants
{
    auto operator()(std::span<const float, 4> constants) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::set::blend_constants(f.command_buffer(), constants);
                                   return f;
                               }};
    }

    auto operator()(std::array<float, 4> constants) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::set::blend_constants(f.command_buffer(), constants);
                                   return f;
                               }};
    }
};

namespace depth
{

struct bias
{
    auto operator()(float constant_factor, float clamp, float slope_factor) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::set::depth::bias(f.command_buffer(), constant_factor, clamp, slope_factor);
                                   return f;
                               }};
    }
};

struct bounds
{
    auto operator()(float min, float max) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::set::depth::bounds(f.command_buffer(), min, max);
                                   return f;
                               }};
    }
};

#if defined(VK_VERSION_1_3)
struct test_enable
{
    auto operator()(bool enable) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::set::depth::test_enable(f.command_buffer(), enable);
                                   return f;
                               }};
    }
};

struct write_enable
{
    auto operator()(bool enable) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::set::depth::write_enable(f.command_buffer(), enable);
                                   return f;
                               }};
    }
};

struct compare_op
{
    auto operator()(VkCompareOp op) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::set::depth::compare_op(f.command_buffer(), op);
                                   return f;
                               }};
    }
};

struct bounds_test_enable
{
    auto operator()(bool enable) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::set::depth::bounds_test_enable(f.command_buffer(), enable);
                                   return f;
                               }};
    }
};

struct bias_enable
{
    auto operator()(bool enable) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::set::depth::bias_enable(f.command_buffer(), enable);
                                   return f;
                               }};
    }
};
#endif // defined(VK_VERSION_1_3)

} // namespace depth

namespace stencil
{

struct compare_mask
{
    auto operator()(VkStencilFaceFlags face, std::uint32_t mask) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::set::stencil::compare_mask(f.command_buffer(), face, mask);
                                   return f;
                               }};
    }
};

struct write_mask
{
    auto operator()(VkStencilFaceFlags face, std::uint32_t mask) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::set::stencil::write_mask(f.command_buffer(), face, mask);
                                   return f;
                               }};
    }
};

struct reference
{
    auto operator()(VkStencilFaceFlags face, std::uint32_t r) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::set::stencil::reference(f.command_buffer(), face, r);
                                   return f;
                               }};
    }
};

#if defined(VK_VERSION_1_3)

struct test_enable
{
    auto operator()(bool enable) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::set::stencil::test_enable(f.command_buffer(), enable);
                                   return f;
                               }};
    }
};

struct op
{
    auto operator()(VkStencilFaceFlags face, VkStencilOp fail, VkStencilOp pass, VkStencilOp depth_fail, VkCompareOp compare) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::set::stencil::op(f.command_buffer(), face, fail, pass, depth_fail, compare);
                                   return f;
                               }};
    }
};

#endif // defined(VK_VERSION_1_3)

} // namespace stencil

#if defined(VK_VERSION_1_1)

struct device_mask
{
    auto operator()(std::uint32_t mask) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::set::device_mask(f.command_buffer(), mask);
                                   return f;
                               }};
    }
};

#endif // defined(VK_VERSION_1_1)

#if defined(VK_VERSION_1_3)

struct cull_mode
{
    auto operator()(VkCullModeFlags flags) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::set::cull_mode(f.command_buffer(), flags);
                                   return f;
                               }};
    }
};

struct front_face
{
    auto operator()(VkFrontFace face) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::set::front_face(f.command_buffer(), face);
                                   return f;
                               }};
    }
};

struct primitive_topology
{
    auto operator()(VkPrimitiveTopology topology) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::set::primitive_topology(f.command_buffer(), topology);
                                   return f;
                               }};
    }
};

struct viewport_with_count
{
    auto operator()(std::span<const VkViewport> viewports) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::set::viewport_with_count(f.command_buffer(), viewports);
                                   return f;
                               }};
    }

    auto operator()(std::initializer_list<VkViewport> viewports) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::set::viewport_with_count(f.command_buffer(), viewports);
                                   return f;
                               }};
    }
};

struct scissor_with_count
{
    auto operator()(std::span<const VkRect2D> scissors) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::set::scissor_with_count(f.command_buffer(), scissors);
                                   return f;
                               }};
    }

    auto operator()(std::initializer_list<VkRect2D> scissors) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::set::scissor_with_count(f.command_buffer(), scissors);
                                   return f;
                               }};
    }
};

struct rasterizer_discard_enable
{
    auto operator()(bool enable) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::set::rasterizer_discard_enable(f.command_buffer(), enable);
                                   return f;
                               }};
    }
};

struct primitive_restart_enable
{
    auto operator()(bool enable) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::set::primitive_restart_enable(f.command_buffer(), enable);
                                   return f;
                               }};
    }
};
#endif // defined(VK_VERSION_1_3)

#if defined(VK_VERSION_1_4)
struct line_stipple
{
    auto operator()(std::uint32_t factor, std::uint16_t pattern) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::set::line_stipple(f.command_buffer(), factor, pattern);
                                   return f;
                               }};
    }
};

struct rendering_attachment_locations
{
    template<typename... elements>
    auto operator()(std::span<const std::uint32_t> locations, const pnext_chain<elements...>& pnext) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::set::rendering_attachment_locations(f.command_buffer(), locations, pnext);
                                   return f;
                               }};
    }

    template<typename... elements>
    auto operator()(std::initializer_list<std::uint32_t> locations, const pnext_chain<elements...>& pnext) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::set::rendering_attachment_locations(f.command_buffer(), locations, pnext);
                                   return f;
                               }};
    }

    auto operator()(std::span<const std::uint32_t> locations) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::set::rendering_attachment_locations(f.command_buffer(), locations);
                                   return f;
                               }};
    }

    auto operator()(std::initializer_list<std::uint32_t> locations) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::set::rendering_attachment_locations(f.command_buffer(), locations);
                                   return f;
                               }};
    }
};

struct rendering_attachment_indices
{
    template<typename... elements>
    auto operator()(std::span<const std::uint32_t>  colour_attachment_indices,
                    std::optional<std::uint32_t>    depth_index,
                    std::optional<std::uint32_t>    stencil_index,
                    const pnext_chain<elements...>& pnext) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::set::rendering_attachment_indices(
                                       f.command_buffer(), colour_attachment_indices, depth_index, stencil_index, pnext);
                                   return f;
                               }};
    }

    template<typename... elements>
    auto operator()(std::initializer_list<std::uint32_t> colour_attachment_indices,
                    std::optional<std::uint32_t>         depth_index,
                    std::optional<std::uint32_t>         stencil_index,
                    const pnext_chain<elements...>&      pnext) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::set::rendering_attachment_indices(
                                       f.command_buffer(), colour_attachment_indices, depth_index, stencil_index, pnext);
                                   return f;
                               }};
    }

    auto operator()(std::span<const std::uint32_t> colour_attachment_indices,
                    std::optional<std::uint32_t>   depth_index,
                    std::optional<std::uint32_t>   stencil_index) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::set::rendering_attachment_indices(
                                       f.command_buffer(), colour_attachment_indices, depth_index, stencil_index);
                                   return f;
                               }};
    }

    auto operator()(std::initializer_list<std::uint32_t> colour_attachment_indices,
                    std::optional<std::uint32_t>         depth_index,
                    std::optional<std::uint32_t>         stencil_index) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::set::rendering_attachment_indices(
                                       f.command_buffer(), colour_attachment_indices, depth_index, stencil_index);
                                   return f;
                               }};
    }
};

#endif // defined(VK_VERSION_1_4)

} // namespace fubuki::fuyu::command::pipe::detail::set

#endif // FUBUKI_FUYU_COMMAND_PIPE_SET_HPP
