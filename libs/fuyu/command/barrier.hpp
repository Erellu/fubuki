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

#ifndef FUBUKI_FUYU_COMMAND_BARRIER_HPP
#define FUBUKI_FUYU_COMMAND_BARRIER_HPP

#include <algorithm>

#include <core/compare/buffer_memory_barrier.hpp>
#include <core/compare/image_memory_barrier.hpp>
#include <core/compare/memory_barrier.hpp>
#include <core/handle.hpp>
#include <core/pnext_chain.hpp>
#include <core/small_vector.hpp>
#include <core/structure_type.hpp>
#include <core/vulkan.hpp>

#include "fuyu/views/command_buffer.hpp"

namespace fubuki::fuyu
{

namespace command
{

struct barrier_stage
{
    VkPipelineStageFlags source      = {}; ///< Source barrier_stage of the pipeline barrier.
    VkPipelineStageFlags destination = {}; ///< Destination barrier_stage of the pipeline barrier.
    VkDependencyFlags    dependency  = {}; ///< Specificies how execution and memory dependencies are formed.

    [[nodiscard]] friend constexpr bool operator==(const barrier_stage& a, const barrier_stage& b) noexcept  = default;
    [[nodiscard]] friend constexpr bool operator!=(const barrier_stage& a, const barrier_stage& b) noexcept  = default;
    [[nodiscard]] friend constexpr auto operator<=>(const barrier_stage& a, const barrier_stage& b) noexcept = default;
};

/// A description of a pipeline barrier.
/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdPipelineBarrier.html
struct pipeline_barrier
{
    using stages = barrier_stage;

    struct barriers
    {
        small_vector<VkMemoryBarrier>       memory        = {}; ///< The memory barriers to install.
        small_vector<VkBufferMemoryBarrier> buffer_memory = {}; ///< The buffer memory barriers to install.
        small_vector<VkImageMemoryBarrier>  image_memory  = {}; ///< The image memory barriers to install.

        [[nodiscard]] friend constexpr bool operator==(const barriers& a, const barriers& b) noexcept
        {
            // Bring fubuki::operator== in the current scope
            constexpr auto cmp = []<typename U>(const U& x, const U& y) constexpr noexcept { return x == y; };

            return std::ranges::equal(a.memory, b.memory, cmp) and std::ranges::equal(a.buffer_memory, b.buffer_memory, cmp)
                and std::ranges::equal(a.image_memory, b.image_memory, cmp);
        }

        [[nodiscard]] friend constexpr bool operator!=(const barriers& a, const barriers& b) noexcept { return not(a == b); }
    };

    stages   stage   = {}; ///< Specifies where the barrier is inserted.
    barriers barrier = {}; ///< The barriers to insert.

    [[nodiscard]] friend constexpr bool operator==(const pipeline_barrier& a, const pipeline_barrier& b) noexcept = default;
    [[nodiscard]] friend constexpr bool operator!=(const pipeline_barrier& a, const pipeline_barrier& b) noexcept = default;
};

/// A description of an image memory barrier.
/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/VkImageMemoryBarrier.html
struct image_memory_barrier
{
    using underlying_type = VkImageMemoryBarrier;

    struct stage
    {
        VkAccessFlags access_mask        = {};
        std::uint32_t queue_family_index = {};
        VkImageLayout layout             = {};

        [[nodiscard]] friend constexpr bool operator==(const stage& a, const stage& b) noexcept = default;
        [[nodiscard]] friend constexpr bool operator!=(const stage& a, const stage& b) noexcept = default;
    };

    struct target_resource
    {
        image_handle            handle            = {};
        VkImageSubresourceRange subresource_range = {};

        [[nodiscard]] friend constexpr bool operator==(const target_resource& a, const target_resource& b) noexcept = default;
        [[nodiscard]] friend constexpr bool operator!=(const target_resource& a, const target_resource& b) noexcept = default;
    };

    stage           source      = {};
    stage           destination = {};
    target_resource target      = {};

    [[nodiscard]] friend constexpr underlying_type to_underlying(std::reference_wrapper<const image_memory_barrier> cref) noexcept
    {
        // Avoids having to introduce deleted overloads for temporaries
        const auto& s = cref.get();

        return {
            .sType               = structure_type_v<underlying_type>,
            .pNext               = {},
            .srcAccessMask       = s.source.access_mask,
            .dstAccessMask       = s.destination.access_mask,
            .oldLayout           = s.source.layout,
            .newLayout           = s.destination.layout,
            .srcQueueFamilyIndex = s.source.queue_family_index,
            .dstQueueFamilyIndex = s.destination.queue_family_index,
            .image               = s.target.handle.vk,
            .subresourceRange    = s.target.subresource_range,
        };
    }
};

/// A description of a buffer memory barrier.
/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/VkBufferMemoryBarrier.html
struct buffer_memory_barrier
{
    using underlying_type = VkBufferMemoryBarrier;

    struct stage
    {
        VkAccessFlags access_mask        = {};
        std::uint32_t queue_family_index = {};

        [[nodiscard]] friend constexpr bool operator==(const stage& a, const stage& b) noexcept = default;
        [[nodiscard]] friend constexpr bool operator!=(const stage& a, const stage& b) noexcept = default;
    };

    struct target_resource
    {
        buffer_handle handle = {};
        VkDeviceSize  offset = {};
        VkDeviceSize  size   = {};

        [[nodiscard]] friend constexpr bool operator==(const target_resource& a, const target_resource& b) noexcept = default;
        [[nodiscard]] friend constexpr bool operator!=(const target_resource& a, const target_resource& b) noexcept = default;
    };

    stage           source      = {};
    stage           destination = {};
    target_resource target      = {};

    [[nodiscard]] friend constexpr underlying_type to_underlying(std::reference_wrapper<const buffer_memory_barrier> cref) noexcept
    {
        // Avoids having to introduce deleted overloads for temporaries
        const auto& s = cref.get();

        return {
            .sType               = structure_type_v<underlying_type>,
            .pNext               = {},
            .srcAccessMask       = s.source.access_mask,
            .dstAccessMask       = s.destination.access_mask,
            .srcQueueFamilyIndex = s.source.queue_family_index,
            .dstQueueFamilyIndex = s.destination.queue_family_index,
            .buffer              = s.target.handle.vk,
            .offset              = s.target.offset,
            .size                = s.target.size,
        };
    }
};

/**
 * Insert a memory dependency.
 * @param command_buffer The command buffer that will execute this command.
 * @param b The barrier setup.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdPipelineBarrier.html
 */
FUBUKI_FUYU_API void barrier(command_buffer_view command_buffer, const pipeline_barrier& b) noexcept;

/**
 * Insert a single memory dependency for an image.
 * @param command_buffer The command buffer that will execute this command.
 * @param b The barrier setup.
 * @param stages Where the barrier is inserted.
 * @param pnext Chain extending VkImageMemoryBarrier.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdPipelineBarrier.html
 */
template<typename... pnext_elements>
inline void barrier(command_buffer_view                   command_buffer,
                    const image_memory_barrier&           b,
                    const barrier_stage                   stages,
                    const pnext_chain<pnext_elements...>& pnext) noexcept
{
    auto vk_barrier = to_underlying(b);
    fubuki::extend(vk_barrier, pnext);

    return barrier(command_buffer,
                   pipeline_barrier{
                       .stage   = stages,
                       .barrier = {.image_memory = {vk_barrier}},
                   });
}

/**
 * Insert a single memory dependency for an image.
 * @param command_buffer The command buffer that will execute this command.
 * @param b The barrier setup.
 * @param stages Where the barrier is inserted.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdPipelineBarrier.html
 */
inline void barrier(command_buffer_view command_buffer, const image_memory_barrier& b, const barrier_stage stages) noexcept
{
    return barrier(command_buffer, b, stages, empty_pnext_chain);
}

/**
 * Insert a single memory dependency for a buffer.
 * @param command_buffer The command buffer that will execute this command.
 * @param b The barrier setup.
 * @param stages Where the barrier is inserted.
 * @param pnext Chain extending VkBufferMemoryBarrier.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdPipelineBarrier.html
 */
template<typename... pnext_elements>
inline void barrier(command_buffer_view                   command_buffer,
                    const buffer_memory_barrier&          b,
                    const barrier_stage                   stages,
                    const pnext_chain<pnext_elements...>& pnext) noexcept
{
    auto vk_barrier = to_underlying(b);
    fubuki::extend(vk_barrier, pnext);

    return barrier(command_buffer,
                   pipeline_barrier{
                       .stage   = stages,
                       .barrier = {.buffer_memory = {vk_barrier}},
                   });
}

/**
 * Insert a single memory dependency for a buffer.
 * @param command_buffer The command buffer that will execute this command.
 * @param b The barrier setup.
 * @param stages Where the barrier is inserted.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdPipelineBarrier.html
 */
inline void barrier(command_buffer_view command_buffer, const buffer_memory_barrier& b, const barrier_stage stages) noexcept
{
    return barrier(command_buffer, b, stages, empty_pnext_chain);
}

} // namespace command

namespace cmd = command;

} // namespace fubuki::fuyu

#endif // FUBUKI_FUYU_COMMAND_BARRIER_HPP
