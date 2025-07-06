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

#ifndef FUBUKI_FUYU_QUERY_POOL_HPP
#define FUBUKI_FUYU_QUERY_POOL_HPP

#include <optional>
#include <utility>

#include <core/assertion.hpp>
#include <core/config/macros.hpp>
#include <core/handle.hpp>
#include <core/pnext_chain.hpp>
#include <core/traits/parameter_pack.hpp>
#include <core/validate.hpp>
#include <core/vulkan.hpp>

#include "fuyu/external_handle.hpp"
#include "fuyu/functions/query_pool.hpp" // IWYU pragma: export
#include "fuyu/information/query_pool.hpp"
#include "fuyu/parent.hpp"
#include "fuyu/views/owning.hpp"
#include "fuyu/views/query_pool.hpp"

namespace fubuki::fuyu
{

/**
 * Queries are managed using query pool objects. Each query pool is a collection of a specific number of queries of a particular type.
 *
 * @see https://registry.khronos.org/vulkan/specs/latest/man/html/VkQueryPool.html
 */
class query_pool
{
    struct token
    {
    };

public:

    /********************************************************************************/
    /*                            PUBLIC MEMBER TYPES                               */
    /********************************************************************************/

    using handle_type = query_pool_handle;
    using parent_type = parent::device;
    using information = information::query_pool;
    using view        = any_query_pool_view;

    /********************************************************************************/
    /*                    CONSTRUCTION, ASSIGNEMENT, DESTRUCTION                    */
    /********************************************************************************/

    /**
     * Constructor.
     * @param device Device on which the query pool will be allocated.
     * @param info Information about the query pool allocation.
     * @param chain Chain extending VkQueryPoolCreateInfo.
     *
     * @throws api_call_exception This constructor throws an instance of api_call_exception if the creation failed, or of std::bad_alloc if
     * intermediate (temporary) host resource allocation failed.
     */
    template<typename... pnext_chain_members>
    // No export, inlined below
    query_pool(device_cref device, information info, const pnext_chain<pnext_chain_members...>& chain);

    /**
     * Constructor.
     * @param device Device on which the query pool will be allocated.
     * @param info Information about the query pool allocation.
     *
     * @throws api_call_exception This constructor throws an instance of api_call_exception if the creation failed, or of std::bad_alloc if
     * intermediate (temporary) host resource allocation failed.
     */
    query_pool(device_cref device, information info) : query_pool(device, std::move(info), empty_pnext_chain) {}

    /**
     * Constructor.
     * @param handle The handle this object will borrow or take ownership over.
     * @param device Device on which the handle was allocated.
     * @param info Information about the handle allocation.
     * @param performance_info (optional) Additional information provided when the query pool describes a performance query pool.
     *
     * @throws api_call_exception This constructor throws an instance of api_call_exception if an API call failed, or of std::bad_alloc if
     * intermediate (temporary) host resource allocation failed.
     */
    query_pool(external_handle<handle_type>                             handle,
               device_cref                                              device,
               information                                              info,
               std::optional<fuyu::information::performance_query_pool> performance_info = {});

    /**
     * (Almost-)Equivalent of a noexcept constructor.
     * @param device Device on which the memory will be allocated.
     * @param info Information about the memory allocation.
     * @param chain Chain extending VkMemoryAllocateInfo.
     *
     * @returns The object, or an instance of api_call_info describing the API call that failed.
     * @throws std::bad_alloc This function CAN throw an instance of std::bad_alloc if intermediate (temporary) host resource allocation failed.
     */
    template<typename... pnext_chain_members>
    [[nodiscard]]
    static std::expected<query_pool, api_call_info> make(device_cref device, information info, const pnext_chain<pnext_chain_members...>& chain);

    /**
     * (Almost-)Equivalent of a noexcept constructor.
     * @param device Device on which the memory will be allocated.
     * @param info Information about the memory allocation.
     *
     * @returns The object, or an instance of api_call_info describing the API call that failed.
     * @throws std::bad_alloc This function CAN throw an instance of std::bad_alloc if intermediate (temporary) host resource allocation failed.
     */
    [[nodiscard]]
    static std::expected<query_pool, api_call_info> make(device_cref device, information info)
    {
        return make(device, std::move(info), empty_pnext_chain);
    }

    /**
     * (Almost-)Equivalent of a noexcept constructor.
     * @param handle The handle this object will borrow or take ownership over.
     * @param device Device on which the handle was allocated.
     * @param info Information about the handle allocation.
     * @param performance_info (optional) Additional information provided when the query pool describes a performance query pool.
     *
     * @returns The object, or an instance of api_call_info describing the API call that failed.
     * @throws std::bad_alloc This function CAN throw an instance of std::bad_alloc if intermediate (temporary) host resource allocation failed.
     */
    [[nodiscard]] static std::expected<query_pool, api_call_info> make(external_handle<handle_type>                             handle,
                                                                       device_cref                                              device,
                                                                       information                                              info,
                                                                       std::optional<fuyu::information::performance_query_pool> performance_info
                                                                       = {});

    /// Destructor. Destroys the query pool if it is not VK_NULL_HANDLE.
    ~query_pool() noexcept
    {
        if(owns())
        {
            query_pool::destroy();
        }
    }

    /// Move constructor.
    query_pool(query_pool&& other) noexcept
        : m_handle{std::exchange(other.m_handle, handle_type{})},
          m_parent{other.m_parent},
          m_info{std::exchange(other.m_info, information{})},
          m_performance_query_info{std::exchange(other.m_performance_query_info, fuyu::information::performance_query_pool{})},
          m_owner{std::exchange(other.m_owner, false)}
    {
    }

    /// Move assignment operator.
    query_pool& operator=(query_pool&& other) noexcept
    {
        swap(other);
        return *this;
    }

    query_pool(const query_pool&)            = delete;
    query_pool& operator=(const query_pool&) = delete;

    /********************************************************************************/
    /*                                  OPERATORS                                   */
    /********************************************************************************/

    /// Conversion operator to underlying handle.
    [[nodiscard]] operator handle_type() const noexcept { return m_handle; }

    /// Converts the query pool to a view of its resources.
    [[nodiscard]] operator any_query_pool_view() const noexcept
    {
#if defined(VK_KHR_performance_query)
        if(m_info.type == VK_QUERY_TYPE_PERFORMANCE_QUERY_KHR)
        {
            fubuki_assert(m_performance_query_info.has_value(), "Internal error. Should have a value.");

            return performance_query_pool_view{
                .handle              = m_handle,
                .device              = m_parent,
                .count               = m_info.count,
                .pipeline_statistics = m_info.pipeline_statistics,
                .results_formats     = m_performance_query_info.has_value() ? m_performance_query_info->formats
                                                                            : std::span<const performance_query_pool_view::result_format>{},
            };
        }
#endif // defined(VK_KHR_performance_query)

        return query_pool_view{
            .handle              = m_handle,
            .device              = m_parent,
            .type                = m_info.type,
            .count               = m_info.count,
            .pipeline_statistics = m_info.pipeline_statistics,
        };
    }
    /********************************************************************************/
    /*                              ACCESSORS, MUTATORS                             */
    /********************************************************************************/

    /// Returns a const reference to the information known about this object.
    [[nodiscard]] const information& info() const noexcept { return m_info; }

    //------------------------------------------------------------------------------

    /// Returns information about performance query format. Holds a value only if the query pool type is VK_QUERY_TYPE_PERFORMANCE_QUERY_KHR.
    [[nodiscard]] const auto& performance_query_info() const noexcept { return m_performance_query_info; }

    //------------------------------------------------------------------------------

    /// Returns the underlying handle.
    [[nodiscard]] handle_type handle() const noexcept { return m_handle; }

    //------------------------------------------------------------------------------

    /// Returns a reference to the device this query pool uses.
    [[nodiscard]] const fuyu::device& device() const noexcept { return m_parent; }

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
    void swap(query_pool& other) noexcept
    {
        std::swap(m_handle, other.m_handle);
        std::swap(m_parent, other.m_parent);
        std::swap(m_info, other.m_info);
        std::swap(m_performance_query_info, other.m_performance_query_info);
        std::swap(m_owner, other.m_owner);
    }

    /// Swaps two objects.
    friend void swap(query_pool& a, query_pool& b) noexcept { a.swap(b); }

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
    friend auto rebind(query_pool& object, parent_type parent) noexcept { return object.rebind(parent); }

private:

    /// Partial constructor. Used to perform noexcept operations only, requires a call to "create" to finish the object.
    query_pool(token, device_cref device, information info) noexcept : m_parent{device}, m_info{std::move(info)} {}

    /********************************************************************************/
    /*                            PRIVATE MEMBER FUNCTIONS                          */
    /********************************************************************************/

    /// Reads the contents of a pnext chain back into the class members.
    /// Called before create() upon construction.
    template<typename... pnext_chain_members>
    void read(const pnext_chain<pnext_chain_members...>& chain) noexcept;

    /// Creates the query pool.
    /// This function CAN throw an instance of std::bad_alloc if the allocation of intermediate (temporary) resources failed.
    [[nodiscard]] FUBUKI_FUYU_API std::optional<api_call_info> create(const VkQueryPoolCreateInfo& info);

    /// Destroys the query pool if it is not VK_NULL_HANDLE.
    FUBUKI_FUYU_API
    void destroy() noexcept;

    /********************************************************************************/
    /*                                 ATTRIBUTES                                   */
    /********************************************************************************/

    handle_type                                              m_handle = {};                 ///< Underlying Vulkan handle.
    parent_type                                              m_parent;                      ///< Device on which buffer is allocated.
    information                                              m_info                   = {}; ///< Buffer information.
    std::optional<fuyu::information::performance_query_pool> m_performance_query_info = {}; ///< Extra info for performance query pools.
    bool                                                     m_owner = true; ///< Indicates if this object has ownership over its handle.
};

//------------------------------------------------------------------------------
// Inline functions

template<typename... pnext_chain_members>
inline query_pool::query_pool(device_cref device, information info, const pnext_chain<pnext_chain_members...>& chain)
    : query_pool(token{}, device, std::move(info))
{
    read(chain);

    auto vk_info = to_underlying(m_info);
    fubuki::extend(vk_info, chain);

    if(const auto error = create(vk_info))
    {
        throw api_call_exception{{*error}};
    }
}

inline query_pool::query_pool(external_handle<handle_type>                             handle,
                              device_cref                                              device,
                              information                                              info,
                              std::optional<fuyu::information::performance_query_pool> performance_info)
    : query_pool(token{}, device, std::move(info))
{
    fubuki_assert(not handle.ownership.valueless_by_exception(), "Handle must have a value");

    m_owner                  = fuyu::indicates_ownership(handle);
    m_handle                 = fuyu::handle_of(handle);
    m_performance_query_info = std::move(performance_info);

    if(auto error = create({}))
    {
        throw api_call_exception{{*error}};
    }
}

template<typename... pnext_chain_members>
[[nodiscard]]
inline std::expected<query_pool, api_call_info>
query_pool::make(device_cref device, information info, const pnext_chain<pnext_chain_members...>& chain)
{
    auto result = query_pool(token{}, device, std::move(info));

    result.read(chain);

    auto vk_info = to_underlying(result.m_info);
    fubuki::extend(vk_info, chain);

    if(auto error = result.create(vk_info))
    {
        return std::unexpected{*error};
    }

    return result;
}

[[nodiscard]]
inline std::expected<query_pool, api_call_info> query_pool::make(external_handle<handle_type>                             handle,
                                                                 device_cref                                              device,
                                                                 information                                              info,
                                                                 std::optional<fuyu::information::performance_query_pool> performance_info)
{
    fubuki_assert(not handle.ownership.valueless_by_exception(), "Handle must have a value");

    auto result                     = query_pool(token{}, device, std::move(info));
    result.m_owner                  = fuyu::indicates_ownership(handle);
    result.m_handle                 = fuyu::handle_of(handle);
    result.m_performance_query_info = std::move(performance_info);

    if(auto error = result.create({}))
    {
        return std::unexpected{*error};
    }

    return result;
}

template<typename... pnext_chain_members>
inline void query_pool::read([[maybe_unused]] const pnext_chain<pnext_chain_members...>& chain) noexcept
{
#if defined(VK_KHR_performance_query)
    fubuki_assert_if(m_info.type == VK_QUERY_TYPE_PERFORMANCE_QUERY_KHR,
                     (traits::parameter_pack::contains_v<VkQueryPoolPerformanceCreateInfoKHR, pnext_chain_members...>),
                     "You must provide a VkQueryPoolPerformanceCreateInfoKHR for such queries.");

    if constexpr(traits::parameter_pack::contains_v<VkQueryPoolPerformanceCreateInfoKHR, pnext_chain_members...>)
    {
        const auto& i                          = std::get<VkQueryPoolPerformanceCreateInfoKHR&>(chain.data());
        m_performance_query_info               = fuyu::information::performance_query_pool{};
        m_performance_query_info->queue_family = i.queueFamilyIndex;
        m_performance_query_info->counter_indices.assign(i.pCounterIndices, i.pCounterIndices + i.counterIndexCount);
    }
#endif // defined(VK_KHR_performance_query)
}

} // namespace fubuki::fuyu

#endif // FUBUKI_FUYU_QUERY_POOL_HPP
