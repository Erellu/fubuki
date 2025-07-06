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

#ifndef FUBUKI_FUYU_COMMAND_PIPE_MANIPULATION_HPP
#define FUBUKI_FUYU_COMMAND_PIPE_MANIPULATION_HPP

#include "fuyu/command/manipulation.hpp"
#include "fuyu/command/pipe/adaptor_closure.hpp"
#include "fuyu/command/pipe/flow.hpp"

namespace fubuki::fuyu::command::pipe::detail
{

struct fill
{
    auto operator()(buffer_handle buffer, VkDeviceSize offset, VkDeviceSize size, std::uint32_t data) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::fill(f.command_buffer(), buffer, offset, size, data);
                                   return f;
                               }};
    }
};

struct update
{
    auto operator()(buffer_handle buffer, VkDeviceSize offset, VkDeviceSize size, const void* data) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::update(f.command_buffer(), buffer, offset, size, data);
                                   return f;
                               }};
    }

    auto operator()(buffer_handle buffer, VkDeviceSize offset, std::span<const std::byte> data) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::update(f.command_buffer(), buffer, offset, data);
                                   return f;
                               }};
    }
};

struct blit
{
    auto operator()(image_handle                 source,
                    VkImageLayout                source_layout,
                    image_handle                 dest,
                    VkImageLayout                dest_layout,
                    std::span<const VkImageBlit> regions,
                    VkFilter                     filter) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::blit(f.command_buffer(), source, source_layout, dest, dest_layout, regions, filter);
                                   return f;
                               }};
    }

    auto operator()(image_handle                       source,
                    VkImageLayout                      source_layout,
                    image_handle                       dest,
                    VkImageLayout                      dest_layout,
                    std::initializer_list<VkImageBlit> regions,
                    VkFilter                           filter) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::blit(f.command_buffer(), source, source_layout, dest, dest_layout, regions, filter);
                                   return f;
                               }};
    }
};

struct resolve
{
    auto operator()(image_handle                    source,
                    VkImageLayout                   source_layout,
                    image_handle                    dest,
                    VkImageLayout                   dest_layout,
                    std::span<const VkImageResolve> regions) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::resolve(f.command_buffer(), source, source_layout, dest, dest_layout, regions);
                                   return f;
                               }};
    }

    auto operator()(image_handle                          source,
                    VkImageLayout                         source_layout,
                    image_handle                          dest,
                    VkImageLayout                         dest_layout,
                    std::initializer_list<VkImageResolve> regions) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::resolve(f.command_buffer(), source, source_layout, dest, dest_layout, regions);
                                   return f;
                               }};
    }
};

struct clear
{
    auto operator()(image_handle                             image,
                    VkImageLayout                            image_layout,
                    const VkClearColorValue&                 colour,
                    std::span<const VkImageSubresourceRange> ranges) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::clear(f.command_buffer(), image, image_layout, colour, ranges);
                                   return f;
                               }};
    }

    auto operator()(image_handle                                   image,
                    VkImageLayout                                  image_layout,
                    const VkClearColorValue&                       colour,
                    std::initializer_list<VkImageSubresourceRange> ranges) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::clear(f.command_buffer(), image, image_layout, colour, ranges);
                                   return f;
                               }};
    }

    auto
    operator()(image_handle image, VkImageLayout image_layout, const VkClearColorValue& colour, const VkImageSubresourceRange& range) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::clear(f.command_buffer(), image, image_layout, colour, range);
                                   return f;
                               }};
    }

    auto operator()(image_handle                             image,
                    VkImageLayout                            image_layout,
                    const VkClearDepthStencilValue&          depth_stencil,
                    std::span<const VkImageSubresourceRange> ranges) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::clear(f.command_buffer(), image, image_layout, depth_stencil, ranges);
                                   return f;
                               }};
    }

    auto operator()(image_handle                                   image,
                    VkImageLayout                                  image_layout,
                    const VkClearDepthStencilValue&                depth_stencil,
                    std::initializer_list<VkImageSubresourceRange> ranges) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::clear(f.command_buffer(), image, image_layout, depth_stencil, ranges);
                                   return f;
                               }};
    }

    auto operator()(image_handle                    image,
                    VkImageLayout                   image_layout,
                    const VkClearDepthStencilValue& depth_stencil,
                    VkImageSubresourceRange         range) const noexcept
    {
        return adaptor_closure{[=](flow f) mutable noexcept -> flow
                               {
                                   fuyu::cmd::clear(f.command_buffer(), image, image_layout, depth_stencil, range);
                                   return f;
                               }};
    }
};

} // namespace fubuki::fuyu::command::pipe::detail

#endif // FUBUKI_FUYU_COMMAND_PIPE_MANIPULATION_HPP
