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

#include "fuyu/memory.hpp"

#include <core/assertion.hpp>
#include <core/result.hpp>
#include <core/vulkan.hpp> // Platform-specific headers required here
#include <extension/ext_debug_utils.hpp>

#include "fuyu/allocation.hpp"
#include "fuyu/debug/name.hpp"
#include "fuyu/device.hpp" // IWYU pragma: keep
#include "fuyu/hardware.hpp"

namespace fubuki::fuyu
{

/*
 * Because we need to now what type of memory we need to allocate for each kind of buffers,
 * we first need to create the VkBuffer handles.
 *
 * This means we can't have a pyramidal relation like:
 *
 * Memory        \\\      ///
 *   |            \\\    ///
 *   | allocates   \\\  ///
 *   v              \\\///
 * Buffer            \\//  DON'T
 *   |              ///\\\
 *   | stores      ///  \\\
 *   v            ///    \\\
 * Data          ///      \\\
 *
 * Thus the relevance of the "level" system, which first gathers every information about required allocations,
 * and then packs everything together like:
 *
 * |                             Memory A                             |                 Memory B               |
 * | Buffer with memory type A  | Other buffer with same memory type  |    ...    |    Analogue    |    ...    |
 * | Stuff      | Other stuff   | More stuff | Stuff again | Things   |    ...    |    Analogue    |    ...    |
 *
 * This is why 'memory' is not a standalone thing you can allocate and then give to a buffer, but instead something that
 * requires you to first know what you are going to put into it.
 */

/********************************************************************************/
/*                            PRIVATE MEMBER FUNCTIONS                          */
/********************************************************************************/

[[nodiscard]] FUBUKI_SEMI_PURE std::expected<std::uint32_t, api_call_info> memory::find_memory_index() const noexcept
{
    const auto index = fuyu::hardware::memory_index(device(), m_info.requirements, m_info.properties);

    if(not index)
    {
        return api_call_info{.result       = {VK_ERROR_FEATURE_NOT_PRESENT},
                             .call_literal = "fuyu::hardware::memory_index - No matching memory type for the given requirements"_literal,
                             .location     = std::source_location::current()};
    }

    return *index;
}

[[nodiscard]]
std::optional<api_call_info> memory::create(const VkMemoryAllocateInfo& vk_info) noexcept
{
    if(m_handle == null_handle)
    {
        if(auto success = fuyu::create_handle<handle_type>(device(), vk_info, m_info.callbacks))
        {
            m_handle = *success;
        }
        else
        {
            return success.error();
        }
    }

    // Debug markers
    if(const auto check = debug::name_if_loaded(device(), m_handle, m_info.name.value_or("<Unnamed memory>")); not check)
    {
        return check.error();
    }

    return {};
}

//------------------------------------------------------------------------------

void memory::destroy() noexcept
{
    if(m_handle != null_handle)
    {
        fuyu::destroy_handle(device(), m_handle, m_info.callbacks);
    }
}

} // namespace fubuki::fuyu
