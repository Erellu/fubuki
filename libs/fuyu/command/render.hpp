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

#ifndef FUBUKI_FUYU_COMMAND_RENDER_HPP
#define FUBUKI_FUYU_COMMAND_RENDER_HPP

#include <core/collect.hpp>
#include <core/config/macros.hpp>
#include <core/pnext_chain.hpp>
#include <core/small_vector.hpp>

#include "fuyu/views/command_buffer.hpp"

namespace fubuki::fuyu
{

namespace command
{

/**
 * Describes a target a render pass uses.
 *
 * @see command::begin_render_pass, @see command::rendering_scope.
 */
struct render_target
{
    using underlying_type = VkRenderPassBeginInfo;

    framebuffer_handle         framebuffer = {}; ///< The framebuffer that will hold the result of the draw calls.
    render_pass_handle         render_pass = {}; ///< The render pass that render to render_target::framebuffer.
    VkRect2D                   render_area = {}; ///< The area of the render target that will be targeted.
    small_vector<VkClearValue> clear       = {}; ///< The clear colours/values used.

    [[nodiscard]] friend constexpr underlying_type to_underlying(std::reference_wrapper<const render_target> cref) noexcept
    {
        // Avoids having to introduce deleted overloads for temporaries
        const auto& s = cref.get();

        return {
            .sType           = structure_type_v<underlying_type>,
            .pNext           = nullptr,
            .renderPass      = s.render_pass.vk,
            .framebuffer     = s.framebuffer.vk,
            .renderArea      = s.render_area,
            .clearValueCount = vk_size(s.clear),
            .pClearValues    = s.clear.data(),
        };
    }
};

#if defined(VK_VERSION_1_3)

/**
 * Describes a target a dynamic rendering scope uses.
 *
 * @see command::begin_rendering, @see command::rendering_scope.
 */
struct dynamic_render_target
{
    using underlying_type = VkRenderingInfo;

    struct attachment
    {
        small_vector<VkRenderingAttachmentInfo>  colour  = {}; ///< The colour attachments used.
        std::optional<VkRenderingAttachmentInfo> depth   = {}; ///< The depth attachment used.
        std::optional<VkRenderingAttachmentInfo> stencil = {}; ///< The stencil attachment used.
    };

    VkRenderingFlags flags       = {}; ///< A bitmask of VkRenderingFlagBits describing additional properties.
    VkRect2D         render_area = {}; ///< The render area that is affected by the render pass instance.
    std::uint32_t    layer_count = {}; ///< The number of layers rendered to in each attachment when view_mask is 0.
    std::uint32_t    view_mask   = {}; ///< The view mask indicating the indices of attachment layers that will be rendered when it is not 0.
    attachment       attachments = {}; ///< The attachments the render pass instances uses.

    [[nodiscard]] friend constexpr underlying_type to_underlying(std::reference_wrapper<const dynamic_render_target> cref) noexcept
    {
        // Avoids having to introduce deleted overloads for temporaries
        const auto& s = cref.get();

        return {
            .sType                = structure_type_v<underlying_type>,
            .pNext                = nullptr,
            .flags                = s.flags,
            .renderArea           = s.render_area,
            .layerCount           = s.layer_count,
            .viewMask             = s.view_mask,
            .colorAttachmentCount = vk_size(s.attachments.colour),
            .pColorAttachments    = s.attachments.colour.data(),
            .pDepthAttachment     = s.attachments.depth.has_value() ? std::addressof(*s.attachments.depth) : nullptr,
            .pStencilAttachment   = s.attachments.stencil.has_value() ? std::addressof(*s.attachments.stencil) : nullptr,
        };
    }
};

#endif // defined(VK_VERSION_1_3)

namespace detail
{

/**
 * Begin a new render pass, that ends when command::end_render_pass is called.
 *
 * @param command_buffer Command buffer that will record this command.
 * @param target Render target used.
 * @param subpass_contents Indicates how the commands in the first subpass will be provided.
 * @warning Must be matched by a call to end_render_pass. @see fuyu::command::rendering_scope for a RAII alternative.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdBeginRenderPass.html
 */
FUBUKI_FUYU_API
void begin_render_pass(command_buffer_view command_buffer, const VkRenderPassBeginInfo& target, VkSubpassContents subpass_contents) noexcept;

/**
 * Begin a dynamic render pass instance.
 *
 * @param command_buffer  Command buffer that will record this command.
 * @param target Render target used.
 * @warning Must be matched by a call to end_rendering. @see fuyu::command::rendering_scope for a RAII alternative.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdBeginRendering.html
 * @pre The device the command buffer comes from must be created with support for Vulkan 1.3.
 */
#if defined(VK_VERSION_1_3)
FUBUKI_FUYU_API
void begin_rendering(command_buffer_view command_buffer, const VkRenderingInfo& target);
#endif // defined(VK_VERSION_1_3)

} // namespace detail

/********************************************************************************/
/*                                  VULKAN 1.0                                  */
/********************************************************************************/

/**
 * Begin a new render pass, that ends when command::end_render_pass is called.
 *
 * @param command_buffer Command buffer that will record this command.
 * @param target Render target used.
 * @param subpass_contents Indicates how the commands in the first subpass will be provided.
 * @param pnext A pnext chain extending VkRenderPassBeginInfo.
 * @warning Must be matched by a call to end_render_pass. @see fuyu::command::rendering_scope for a RAII alternative.
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdBeginRenderPass.html
 */
template<typename... pnext_elements>
inline void begin_render_pass(command_buffer_view                   command_buffer,
                              const render_target&                  target,
                              VkSubpassContents                     subpass_contents,
                              const pnext_chain<pnext_elements...>& pnext) noexcept
{
    auto vk_info = to_underlying(target);
    fubuki::extend(vk_info, pnext);

    return detail::begin_render_pass(command_buffer, vk_info, subpass_contents);
}

/**
 * Begin a new render pass, that ends when command::end_render_pass is called.
 *
 * @param command_buffer Command buffer that will record this command.
 * @param target Render target used.
 * @param subpass_contents Indicates how the commands in the first subpass will be provided.
 * @warning Must be matched by a call to end_render_pass. @see fuyu::command::rendering_scope for a RAII alternative.
 *
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdBeginRenderPass.html
 */
inline void begin_render_pass(command_buffer_view command_buffer, const render_target& target, VkSubpassContents subpass_contents) noexcept
{
    return begin_render_pass(command_buffer, target, subpass_contents, empty_pnext_chain);
}

/**
 * End the current render pass.
 * @param command_buffer The command buffer that will record this command.
 *
 * @warning Must be preceeded by a call to command::begin_render_pass. @see fuyu::command::rendering_scope for a RAII alternative.
 *
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdEndRenderPass.html
 */
FUBUKI_FUYU_API
void end_render_pass(command_buffer_view command_buffer) noexcept;

/**
 * Transition to the next subpass of a render pass.
 * @param command_buffer The command buffer that will record this command.
 * @param contents Indicates how the commands in the next subpass will be provided.
 *
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdNextSubpass.html
 */
FUBUKI_FUYU_API
void next_subpass(command_buffer_view command_buffer, VkSubpassContents contents) noexcept;

/********************************************************************************/
/*                                  VULKAN 1.3                                  */
/********************************************************************************/

#if defined(VK_VERSION_1_3)

/**
 * Start a dynamic rendering pass instance.
 * @param command_buffer The command buffer that will record this command.
 * @param target The description of the dynamic rendering target used in this instance.
 * @param pnext A pnext chain extending VkRenderingInfo.
 * @warning MUST be matched by a call to command::end_rendering. @see command::rendering_scope for a RAII alternative.
 * @pre The device the command buffer comes from must be created with support for Vulkan 1.3.
 *
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdBeginRendering.html
 */
template<typename... pnext_elements>
inline void
begin_rendering(command_buffer_view command_buffer, const dynamic_render_target& target, const pnext_chain<pnext_elements...>& pnext) noexcept
{
    auto vk_info = to_underlying(target);
    fubuki::extend(vk_info, pnext);

    return detail::begin_rendering(command_buffer, vk_info);
}

/**
 * Start a dynamic rendering pass instance.
 * @param command_buffer The command buffer that will record this command.
 * @param target The description of the dynamic rendering target used in this instance.
 * @warning MUST be matched by a call to command::end_rendering. @see command::rendering_scope for a RAII alternative.
 * @pre The device the command buffer comes from must be created with support for Vulkan 1.3.
 *
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdBeginRendering.html
 */
inline void begin_rendering(command_buffer_view command_buffer, const dynamic_render_target& target) noexcept
{
    return begin_rendering(command_buffer, target, empty_pnext_chain);
}

/**
 * End a dynamic rendering pass instance.
 * @param command_buffer The command buffer that will record this command.
 * @warning MUST be preceeded by a matching call of command::begin_rendering. @see command::rendering_scope for a RAII alternative.
 * @pre The device the command buffer comes from must be created with support for Vulkan 1.3.
 *
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/vkCmdEndRenderingKHR.html
 */
FUBUKI_FUYU_API
void end_rendering(command_buffer_view command_buffer);

#endif // defined(VK_VERSION_1_3)

/**
 * A RAII object equivalent to an immediate call to command::begin_render_pass and a call to command::end_render_pass upon its destruction, or to
 * command::begin_rendering/command::end_rendering (depending on the arguments of the constructor).
 */
class rendering_scope
{

public:

    /// Constructor. Begins a render pass. @see command::begin_render_pass
    template<typename... pnext_elements>
    rendering_scope(command_buffer_view                   command_buffer,
                    const render_target&                  target,
                    VkSubpassContents                     subpass_contents,
                    const pnext_chain<pnext_elements...>& pnext) noexcept
        : m_command_buffer{command_buffer},
          m_type{which::render_pass}
    {
        command::begin_render_pass(m_command_buffer, target, subpass_contents, pnext);
    }

    /// Constructor. Begins a render pass. @see command::begin_render_pass
    rendering_scope(command_buffer_view command_buffer, const render_target& target, VkSubpassContents subpass_contents) noexcept
        : rendering_scope{command_buffer, target, subpass_contents, empty_pnext_chain}
    {
    }

#if defined(VK_VERSION_1_3)
    /// Constructor. Begins a dynamic rendering instance. @see command::begin_rendering.
    template<typename... pnext_elements>
    rendering_scope(command_buffer_view command_buffer, const dynamic_render_target& target, const pnext_chain<pnext_elements...>& pnext) noexcept
        : m_command_buffer{command_buffer},
          m_type{which::dynamic_rendering}
    {
        command::begin_rendering(m_command_buffer, target, pnext);
    }

    /// Constructor. Begins a dynamic rendering instance. @see command::begin_rendering.
    rendering_scope(command_buffer_view command_buffer, const dynamic_render_target& target) noexcept
        : rendering_scope{command_buffer, target, empty_pnext_chain}
    {
    }
#endif // defined(VK_VERSION_1_3)

    /// Destructor. @see command::end_render_pass, @see command::end_rendering.
    ~rendering_scope() noexcept
    {
        if(m_type == which::render_pass)
        {
            command::end_render_pass(m_command_buffer);
        }
#if defined(VK_VERSION_1_3)
        if(m_type == which::dynamic_rendering)
        {
            command::end_rendering(m_command_buffer);
        }
#endif // defined(VK_VERSION_1_3)
    }

    rendering_scope(rendering_scope&&) noexcept            = delete;
    rendering_scope& operator=(rendering_scope&&) noexcept = delete;

    rendering_scope(const rendering_scope&) noexcept            = delete;
    rendering_scope& operator=(const rendering_scope&) noexcept = delete;

    /// Indicates the type of rendering scope this object maintains.
    [[nodiscard]] constexpr auto type() const noexcept { return m_type; }

private:

    enum class which
    {
        render_pass,
        dynamic_rendering
    };

    command_buffer_view m_command_buffer; ///< The command buffer that will record the commands.
    which               m_type = {};      ///< The type of rendering scope this object maintains.
};

} // namespace command

namespace cmd = command;

} // namespace fubuki::fuyu

#endif // FUBUKI_FUYU_COMMAND_RENDER_HPP
