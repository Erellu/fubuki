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

#ifndef FUBUKI_FUYU_GRAPHICS_PIPELINE_HPP
#define FUBUKI_FUYU_GRAPHICS_PIPELINE_HPP

#include <core/pnext_chain.hpp>
#include <core/validate.hpp>

#include "fuyu/external_handle.hpp"
#include "fuyu/information/graphics_pipeline.hpp"
#include "fuyu/parent.hpp"
#include "fuyu/views/graphics_pipeline.hpp"
#include "fuyu/views/owning.hpp"
#include "fuyu/views/pipeline_cache.hpp"

namespace fubuki::fuyu
{

/**
 * An object representing a graphics pipeline.
 */
class graphics_pipeline
{
    struct token
    {
    };

public:

    /********************************************************************************/
    /*                            PUBLIC MEMBER TYPES                               */
    /********************************************************************************/

    using handle_type = graphics_pipeline_handle;
    using parent_type = parent::device;
    using information = information::graphics_pipeline;
    using view        = views::graphics_pipeline;

    struct state
    {
        using vertex_input   = detail::graphics_pipeline::vertex_input_state;
        using input_assembly = detail::graphics_pipeline::input_assembly_state;
        using tesselation    = detail::graphics_pipeline::tesselation_state;
        using viewport       = detail::graphics_pipeline::viewport_state;
        using rasterisation  = detail::graphics_pipeline::rasterisation_state;
        using multisample    = detail::graphics_pipeline::multisample_state;
        using depth_stencil  = detail::graphics_pipeline::depth_stencil_state;
        using colour_blend   = detail::graphics_pipeline::colour_blend_state;
        using dynamic        = detail::graphics_pipeline::dynamic_state;
    };

    /********************************************************************************/
    /*                    CONSTRUCTION, ASSIGNEMENT, DESTRUCTION                    */
    /********************************************************************************/

    /**
     * Constructor.
     * @param cache Cache that will keep the result of this pipeline construction for reuse.
     * @param info Information about the resource allocation.
     * @param complements Complementary information required upon creation, but not kept for the lifetime of the object.
     * @param chain Chain extending VkGraphicsPipelineCreateInfo.
     * @param ext Extension of the information given in info and complements.
     *
     * @throws api_call_exception This constructor throws an instance of api_call_exception if the creation failed.
     * @throws std::bad_alloc This function CAN throw an instance of std::bad_alloc if intermediate (temporary) host resource allocation failed.
     */
    template<fuyu::information::traits::graphics_pipeline_extension extension, typename... pnext_chain_members>
    // No export, inlined below
    graphics_pipeline(pipeline_cache_view                        cache,
                      information                                info,
                      const information::complements&            complements,
                      const pnext_chain<pnext_chain_members...>& chain,
                      const extension&                           ext);

    /**
     * Constructor.
     * @param cache Cache that will keep the result of this pipeline construction for reuse.
     * @param info Information about the resource allocation.
     * @param complements Complementary information required upon creation, but not kept for the lifetime of the object.
     * @param chain Chain extending VkGraphicsPipelineCreateInfo.
     *
     * @throws api_call_exception This constructor throws an instance of api_call_exception if the creation failed.
     * @throws std::bad_alloc This function CAN throw an instance of std::bad_alloc if intermediate (temporary) host resource allocation failed.
     */
    template<typename... pnext_chain_members>
    graphics_pipeline(pipeline_cache_view                        cache,
                      information                                info,
                      const information::complements&            complements,
                      const pnext_chain<pnext_chain_members...>& chain)
        : graphics_pipeline{cache, std::move(info), complements, chain, fuyu::information::graphics_pipeline_extension{}}
    {
    }

    /**
     * Constructor.
     * @param cache Cache that will keep the result of this pipeline construction for reuse.
     * @param info Information about the resource allocation.
     * @param complements Complementary information required upon creation, but not kept for the lifetime of the object.
     * @param ext Extension of the information given in info and complements.
     *
     * @throws api_call_exception This constructor throws an instance of api_call_exception if the creation failed.
     * @throws std::bad_alloc This function CAN throw an instance of std::bad_alloc if intermediate (temporary) host resource allocation failed.
     */
    template<fuyu::information::traits::graphics_pipeline_extension extension>
    graphics_pipeline(pipeline_cache_view cache, information info, const information::complements& complements, const extension& ext)
        : graphics_pipeline{cache, std::move(info), complements, empty_pnext_chain, ext}
    {
    }

    /**
     * Constructor.
     * @param cache Cache that will keep the result of this pipeline construction for reuse.
     * @param info Information about the resource allocation.
     * @param complements Complementary information required upon creation, but not kept for the lifetime of the object.
     *
     * @throws api_call_exception This constructor throws an instance of api_call_exception if the creation failed.
     * @throws std::bad_alloc This function CAN throw an instance of std::bad_alloc if intermediate (temporary) host resource allocation failed.
     */
    graphics_pipeline(pipeline_cache_view cache, information info, const information::complements& complements)
        : graphics_pipeline{cache, std::move(info), complements, empty_pnext_chain, fuyu::information::graphics_pipeline_extension{}}
    {
    }

    /**
     * Constructor.
     * @param handle The handle this object will borrow or take ownership over.
     * @param cache Cache that will keep the result of this pipeline construction for reuse.
     * @param info Information about the handle allocation.
     *
     * @throws api_call_exception This constructor throws an instance of api_call_exception if an API call failed.
     */
    graphics_pipeline(external_handle<handle_type> handle, pipeline_cache_view cache, information info);

    /**
     * (Almost-) Equivalent of a noexcept constructor.
     * @param cache Cache that will keep the result of this pipeline construction for reuse.
     * @param info Information about the resource allocation.
     * @param complements Complementary information required upon creation, but not kept for the lifetime of the object.
     * @param chain Chain extending VkGraphicsPipelineCreateInfo.
     * @param ext Extension of the information given in info and complements.
     *
     * @returns The object, or an instance of api_call_info describing the API call that failed.
     * @throws std::bad_alloc This function CAN throw an instance of std::bad_alloc if intermediate (temporary) host resource allocation failed.
     */
    template<fuyu::information::traits::graphics_pipeline_extension extension, typename... pnext_chain_members>
    // No export, inlined below
    [[nodiscard]]
    static std::expected<graphics_pipeline, api_call_info> make(pipeline_cache_view                        cache,
                                                                information                                info,
                                                                const information::complements&            complements,
                                                                const pnext_chain<pnext_chain_members...>& chain,
                                                                const extension&                           ext);

    /**
     * (Almost-) Equivalent of a noexcept constructor.
     * @param cache Cache that will keep the result of this pipeline construction for reuse.
     * @param info Information about the resource allocation.
     * @param complements Complementary information required upon creation, but not kept for the lifetime of the object.
     * @param chain Chain extending VkGraphicsPipelineCreateInfo.
     *
     * @returns The object, or an instance of api_call_info describing the API call that failed.
     * @throws std::bad_alloc This function CAN throw an instance of std::bad_alloc if intermediate (temporary) host resource allocation failed.
     */
    template<typename... pnext_chain_members>
    [[nodiscard]]
    static std::expected<graphics_pipeline, api_call_info>
    make(pipeline_cache_view cache, information info, const information::complements& complements, const pnext_chain<pnext_chain_members...>& chain)
    {
        return make(cache, std::move(info), complements, chain, fuyu::information::graphics_pipeline_extension{});
    }

    /**
     * (Almost-) Equivalent of a noexcept constructor.
     * @param cache Cache that will keep the result of this pipeline construction for reuse.
     * @param info Information about the resource allocation.
     * @param complements Complementary information required upon creation, but not kept for the lifetime of the object.
     * @param ext Extension of the information given in info and complements.
     *
     * @returns The object, or an instance of api_call_info describing the API call that failed.
     * @throws std::bad_alloc This function CAN throw an instance of std::bad_alloc if intermediate (temporary) host resource allocation failed.
     */
    template<fuyu::information::traits::graphics_pipeline_extension extension>
    [[nodiscard]]
    static std::expected<graphics_pipeline, api_call_info>
    make(pipeline_cache_view cache, information info, const information::complements& complements, const extension& ext)
    {
        return make(cache, std::move(info), complements, empty_pnext_chain, ext);
    }

    /**
     * (Almost-) Equivalent of a noexcept constructor.
     * @param cache Cache that will keep the result of this pipeline construction for reuse.
     * @param info Information about the resource allocation.
     * @param complements Complementary information required upon creation, but not kept for the lifetime of the object.
     *
     * @returns The object, or an instance of api_call_info describing the API call that failed.
     * @throws std::bad_alloc This function CAN throw an instance of std::bad_alloc if intermediate (temporary) host resource allocation failed.
     */
    [[nodiscard]]
    static std::expected<graphics_pipeline, api_call_info>
    make(pipeline_cache_view cache, information info, const information::complements& complements)
    {
        return make(cache, std::move(info), complements, empty_pnext_chain, fuyu::information::graphics_pipeline_extension{});
    }

    /**
     * Equivalent of a noexcept constructor.
     * @param handle The handle this object will borrow or take ownership over.
     * @param cache Cache that will keep the result of this pipeline construction for reuse.
     * @param info Information about the handle allocation.
     *
     * @returns The object, or an instance of api_call_info describing the API call that failed.
     */
    [[nodiscard]]
    static std::expected<graphics_pipeline, api_call_info>
    make(external_handle<handle_type> handle, pipeline_cache_view cache, information info) noexcept;

    /// Destructor. Destroys the resource if it is not VK_NULL_HANDLE and this object owns its handle.
    ~graphics_pipeline() noexcept
    {
        if(owns())
        {
            graphics_pipeline::destroy();
        }
    }

    /// Move constructor.
    graphics_pipeline(graphics_pipeline&& other) noexcept
        : m_handle{std::exchange(other.m_handle, handle_type{})},
          m_parent{other.m_parent},
          m_cache{other.m_cache},
          m_info{std::exchange(other.m_info, information{})},
          m_owner{std::exchange(other.m_owner, false)}
    {
    }

    /// Move assignment operator.
    graphics_pipeline& operator=(graphics_pipeline&& other) noexcept
    {
        swap(other);
        return *this;
    }

    graphics_pipeline(const graphics_pipeline&)            = delete;
    graphics_pipeline& operator=(const graphics_pipeline&) = delete;

    /********************************************************************************/
    /*                                  OPERATORS                                   */
    /********************************************************************************/

    /// Conversion operator to underlying handle.
    [[nodiscard]] operator handle_type() const noexcept { return m_handle; }

    /// Converts the buffer to a view of its resources.
    [[nodiscard]] operator view() const noexcept { return {.handle = m_handle, .device = m_parent, .cache = m_cache, .layout = m_info.layout}; }

    /********************************************************************************/
    /*                              ACCESSORS, MUTATORS                             */
    /********************************************************************************/

    /// Returns a const reference to the information known about this object.
    [[nodiscard]] const information& info() const noexcept { return m_info; }

    //------------------------------------------------------------------------------

    /// Returns the underlying handle.
    [[nodiscard]] handle_type handle() const noexcept { return m_handle; }

    //------------------------------------------------------------------------------

    /// Returns a reference to the device this graphics pipeline uses.
    [[nodiscard]] const fuyu::device& device() const noexcept { return m_parent; }

    /// Returns the handle of the pipeline cache used to create this pipeline.
    [[nodiscard]] pipeline_cache_view cache() const noexcept { return {m_cache, m_parent}; }

    //------------------------------------------------------------------------------

    /**
     * @brief Releases the ownership over the underlying Vulkan handle.
     * The caller becomes responsible of properly managing the lifetime of the Vulkan handle.
     */
    [[nodiscard("The caller becomes responsible of destroying the handle")]] owning_view<view> release() noexcept
    {
        owning_view<view> result = {.value = {*this}};

        m_handle = null_handle;

        return result;
    }

    //------------------------------------------------------------------------------

    /// Indicates if this object has ownership over its handle and will destroy it when the destructor runs.
    [[nodiscard]] bool owns() const noexcept { return m_owner; }

    /// Indicates if the object borrows its handle and will NOT destroy it when the destructor runs.
    [[nodiscard]] bool borrows() const noexcept { return not owns(); }

    //------------------------------------------------------------------------------

    /// Swaps two objects.
    void swap(graphics_pipeline& other) noexcept
    {
        std::swap(m_handle, other.m_handle);
        std::swap(m_parent, other.m_parent);
        std::swap(m_cache, other.m_cache);
        std::swap(m_info, other.m_info);
        std::swap(m_owner, other.m_owner);
    }

    /// Swaps two objects.
    friend void swap(graphics_pipeline& a, graphics_pipeline& b) noexcept { a.swap(b); }

    /**
     * @brief Changes the parent, if the underlying Vulkan handle is the same as the previous one.
     * @param p The new parent.
     * @returns Nothing, or an instance of fuyu::parent::error::incompatible indicating that the two handles were different.
     */
    [[nodiscard]]
    std::expected<void, parent_type::error::incompatible> rebind(parent_type p) noexcept
    {
        if(compatible(m_parent, p))
        {
            m_parent.swap(p);
            return {};
        }
        return std::unexpected{
            parent_type::error::incompatible{m_parent.handle, p.handle}
        };
    }

    /**
     * @brief Changes the parent, if the underlying Vulkan handle is the same as the previous one.
     * @param object The object to rebind.
     * @param parent The new parent.
     * @returns Nothing, or an instance of fuyu::parent::error::incompatible indicating that the two handles were different.
     */
    friend auto rebind(graphics_pipeline& object, parent_type parent) noexcept { return object.rebind(parent); }

private:

    /// Partial constructor. Used to perform noexcept operations only, requires a call to "create" to finish the object.
    graphics_pipeline(token, pipeline_cache_view cache, information info) noexcept
        : m_parent{cache.device},
          m_cache{cache.handle},
          m_info{std::move(info)}
    {
    }

    /********************************************************************************/
    /*                            PRIVATE MEMBER FUNCTIONS                          */
    /********************************************************************************/

    /// Creates the resource.
    [[nodiscard]] FUBUKI_FUYU_API std::optional<api_call_info> create(const VkGraphicsPipelineCreateInfo&) noexcept;

    /// Destroys the resource if it is not VK_NULL_HANDLE and this object owns its handle.
    FUBUKI_FUYU_API void destroy() noexcept;

    /********************************************************************************/
    /*                                 ATTRIBUTES                                   */
    /********************************************************************************/

    handle_type           m_handle = {};         ///< Underlying Vulkan handle.
    parent_type           m_parent;              ///< Device on which the graphics pipeline is allocated.
    pipeline_cache_handle m_cache = null_handle; ///< The pipeline cache used to create this pipeline.
    information           m_info  = {};          ///< Information known about this object.
    bool                  m_owner = true;        ///< Indicates if this object has ownership over its handle.
};

//------------------------------------------------------------------------------
// Inline functions

template<fuyu::information::traits::graphics_pipeline_extension extension, typename... pnext_chain_members>
inline graphics_pipeline::graphics_pipeline(pipeline_cache_view                        cache,
                                            information                                info,
                                            const information::complements&            complements,
                                            const pnext_chain<pnext_chain_members...>& chain,
                                            const extension&                           ext)
    : graphics_pipeline{token{}, cache, std::move(info)}
{
    auto stages = detail::graphics_pipeline::to_underlying(m_parent, complements.stage, ext.stage);
    auto states = detail::graphics_pipeline::to_underlying(complements.state, ext.state);

    if(not stages)
    {
        throw api_call_exception{{stages.error()}};
    }

    auto vk_info = to_underlying(m_info, *stages, states);
    fubuki::extend(vk_info, chain);

    if(auto error = create(vk_info))
    {
        throw api_call_exception{{*error}};
    }
}

inline graphics_pipeline::graphics_pipeline(external_handle<handle_type> handle, pipeline_cache_view cache, information info)
    : graphics_pipeline{token{}, cache, std::move(info)}
{
    fubuki_assert(not handle.ownership.valueless_by_exception(), "Handle must have a value");

    m_owner  = fuyu::indicates_ownership(handle);
    m_handle = fuyu::handle_of(handle);

    if(auto error = create({}))
    {
        throw api_call_exception{{*error}};
    }
}

template<fuyu::information::traits::graphics_pipeline_extension extension, typename... pnext_chain_members>
[[nodiscard]]
inline std::expected<graphics_pipeline, api_call_info> graphics_pipeline::make(pipeline_cache_view                        cache,
                                                                               information                                info,
                                                                               const information::complements&            complements,
                                                                               const pnext_chain<pnext_chain_members...>& chain,
                                                                               const extension&                           ext)
{
    auto result = graphics_pipeline(token{}, cache, std::move(info));

    auto states = detail::graphics_pipeline::to_underlying(complements.state, ext.state);
    auto stages = detail::graphics_pipeline::to_underlying(result.m_parent, complements.stage, ext.stage);

    if(not stages)
    {
        return std::unexpected{stages.error()};
    }

    auto vk_info = to_underlying(result.m_info, *stages, states);
    fubuki::extend(vk_info, chain);

    if(auto error = result.create(vk_info))
    {
        return std::unexpected{*error};
    }

    return result;
}

[[nodiscard]]
inline std::expected<graphics_pipeline, api_call_info>
graphics_pipeline::make(external_handle<handle_type> handle, pipeline_cache_view cache, information info) noexcept
{
    fubuki_assert(not handle.ownership.valueless_by_exception(), "Handle must have a value");

    auto result     = graphics_pipeline(token{}, cache, std::move(info));
    result.m_owner  = fuyu::indicates_ownership(handle);
    result.m_handle = fuyu::handle_of(handle);

    if(auto error = result.create({}))
    {
        return std::unexpected{*error};
    }

    return result;
}

} // namespace fubuki::fuyu

#endif // FUBUKI_FUYU_GRAPHICS_PIPELINE_HPP
