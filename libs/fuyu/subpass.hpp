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

#ifndef FUBUKI_FUYU_SUBPASS_HPP
#define FUBUKI_FUYU_SUBPASS_HPP

#include <cstdint>
#include <optional>

#include <core/assertion.hpp>
#include <core/collect.hpp>
#include <core/compare/attachment_reference.hpp>
#include <core/handle.hpp>
#include <core/small_vector.hpp>
#include <core/vulkan.hpp>

namespace fubuki::fuyu
{

/// Description of a subpass setup.
struct subpass
{
    /// Description of a dependency between two subpasses.
    struct dependency
    {
        /// Description of a dependency stage (source or destination) for subpasses. @see subpass_dependency.
        struct stage
        {
            /// Indicates the dependency expands the synchronisation scope outside the subpass.
            static constexpr std::uint32_t external = VK_SUBPASS_EXTERNAL;

            std::uint32_t        subpass     = {};
            VkPipelineStageFlags stage_mask  = {};
            VkAccessFlags        access_mask = {};

            [[nodiscard]] friend constexpr bool operator==(const stage& a, const stage& b) noexcept  = default;
            [[nodiscard]] friend constexpr bool operator!=(const stage& a, const stage& b) noexcept  = default;
            [[nodiscard]] friend constexpr auto operator<=>(const stage& a, const stage& b) noexcept = default;
        };

        using underlying_type = VkSubpassDependency;

        stage             source           = {};
        stage             destination      = {};
        VkDependencyFlags dependency_flags = {};

        [[nodiscard]] constexpr operator underlying_type() const noexcept
        {
            return underlying_type{
                .srcSubpass      = source.subpass,
                .dstSubpass      = destination.subpass,
                .srcStageMask    = source.stage_mask,
                .dstStageMask    = destination.stage_mask,
                .srcAccessMask   = source.access_mask,
                .dstAccessMask   = destination.access_mask,
                .dependencyFlags = dependency_flags,
            };
        }

        [[nodiscard]] friend constexpr bool operator==(const dependency& a, const dependency& b) noexcept  = default;
        [[nodiscard]] friend constexpr bool operator!=(const dependency& a, const dependency& b) noexcept  = default;
        [[nodiscard]] friend constexpr auto operator<=>(const dependency& a, const dependency& b) noexcept = default;
    };

    struct attachment_contents
    {
        small_vector<VkAttachmentReference>  input         = {}; ///< Input attachments.
        small_vector<VkAttachmentReference>  colour        = {}; ///< Colour attachments.
        small_vector<VkAttachmentReference>  resolve       = {}; ///< Resolve attachments. WARNING: size MUST match colour.size().
        std::optional<VkAttachmentReference> depth_stencil = {}; ///< Depth stencil attachment.
        small_vector<std::uint32_t>          preserve      = {}; ///< Preserved attachments (not modified, but preserved throughout the subpass).

        [[nodiscard]] friend constexpr bool operator==(const attachment_contents& a, const attachment_contents& b) noexcept
        {
            // Required because we have operator== for Vulkan structures in namespace fubuki (so they can't be used through the facilities of the
            // Standard Library)
            constexpr auto compare = [](const VkAttachmentReference& x, const VkAttachmentReference& y) constexpr noexcept { return x == y; };

            return std::ranges::equal(a.input, b.input, compare) and std::ranges::equal(a.colour, b.colour, compare)
                and std::ranges::equal(a.resolve, b.resolve, compare)
                and ((a.depth_stencil.has_value() and b.depth_stencil.has_value() and *a.depth_stencil == *b.depth_stencil)
                     or (not(a.depth_stencil.has_value()) and not(b.depth_stencil.has_value())))
                and std::ranges::equal(a.preserve, b.preserve);
        }

        [[nodiscard]] friend constexpr bool operator!=(const attachment_contents& a, const attachment_contents& b) noexcept { return not(a == b); }

        [[nodiscard]] friend constexpr std::strong_ordering operator<=>(const attachment_contents& a, const attachment_contents& b) noexcept
        {
            // Required because we have operator<=> for Vulkan structures in namespace fubuki (so they can't be used through the facilities of the
            // Standard Library)
            constexpr auto compare = [](const VkAttachmentReference& x, const VkAttachmentReference& y) constexpr noexcept { return x <=> y; };

            constexpr auto compare_optional
                = [](const std::optional<VkAttachmentReference>& x, const std::optional<VkAttachmentReference>& y) constexpr noexcept
            { return x.has_value() and y.has_value() ? *x <=> *y : x.has_value() <=> y.has_value(); };

            if(const auto cmp = std::lexicographical_compare_three_way(a.input.begin(), a.input.end(), b.input.begin(), b.input.end(), compare);
               cmp != std::strong_ordering::equal)
            {
                return cmp;
            }

            if(const auto cmp = std::lexicographical_compare_three_way(a.colour.begin(), a.colour.end(), b.colour.begin(), b.colour.end(), compare);
               cmp != std::strong_ordering::equal)
            {
                return cmp;
            }

            if(const auto cmp
               = std::lexicographical_compare_three_way(a.resolve.begin(), a.resolve.end(), b.resolve.begin(), b.resolve.end(), compare);
               cmp != std::strong_ordering::equal)
            {
                return cmp;
            }

            if(const auto cmp = compare_optional(a.depth_stencil, b.depth_stencil); cmp != std::strong_ordering::equal)
            {
                return cmp;
            }

            if(const auto cmp = std::lexicographical_compare_three_way(a.preserve.begin(), a.preserve.end(), b.preserve.begin(), b.preserve.end());
               cmp != std::strong_ordering::equal)
            {
                return cmp;
            }

            return std::strong_ordering ::equal;
        }
    };

    using underlying_type = VkSubpassDescription;

    VkSubpassDescriptionFlags flags       = {};
    VkPipelineBindPoint       bind_point  = {};
    attachment_contents       attachments = {};

    [[nodiscard]] friend constexpr bool operator==(const subpass& a, const subpass& b) noexcept  = default;
    [[nodiscard]] friend constexpr bool operator!=(const subpass& a, const subpass& b) noexcept  = default;
    [[nodiscard]] friend constexpr auto operator<=>(const subpass& a, const subpass& b) noexcept = default;

    [[nodiscard]] constexpr operator underlying_type() const noexcept
    {
        fubuki_assert(attachments.colour.size() == attachments.resolve.size() or attachments.resolve.empty(), "Size mismatch.");

        return underlying_type{
            .flags                   = flags,
            .pipelineBindPoint       = bind_point,
            .inputAttachmentCount    = vk_size(attachments.input),
            .pInputAttachments       = attachments.input.data(),
            .colorAttachmentCount    = vk_size(attachments.colour),
            .pColorAttachments       = attachments.colour.data(),
            .pResolveAttachments     = attachments.resolve.empty() ? nullptr : attachments.resolve.data(),
            .pDepthStencilAttachment = attachments.depth_stencil.has_value() ? std::addressof(*attachments.depth_stencil) : nullptr,
            .preserveAttachmentCount = vk_size(attachments.preserve),
            .pPreserveAttachments    = attachments.preserve.data(),
        };
    }
};

} // namespace fubuki::fuyu

#endif // FUBUKI_FUYU_SUBPASS_HPP
