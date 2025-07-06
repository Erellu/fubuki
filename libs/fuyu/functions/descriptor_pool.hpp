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

#ifndef FUBUKI_FUYU_FUNCTIONS_DESCRIPTOR_POOL_HPP
#define FUBUKI_FUYU_FUNCTIONS_DESCRIPTOR_POOL_HPP

#include <core/config/macros.hpp>
#include <core/validate.hpp>
#include <core/vulkan.hpp>

#include "fuyu/views/descriptor_pool.hpp"

namespace fubuki::fuyu
{

/**
 * Resets a descriptor pool object: returns all descriptor sets allocated from a given pool to the pool.
 * @warning All descriptor sets previously allocated from this pool become dangling handles and must be freed manually.
 * Typically, call descriptor_set_array::release() and descriptor_set_layout::release().
 *
 * @param pool The descriptor pool to reset.
 * @param flags Reset flags.
 */
[[nodiscard]] FUBUKI_FUYU_API std::expected<void, api_call_info> reset(fuyu::descriptor_pool_view pool, VkDescriptorPoolResetFlags flags = {});

} // namespace fubuki::fuyu

#endif // FUBUKI_FUYU_FUNCTIONS_DESCRIPTOR_POOL_HPP
