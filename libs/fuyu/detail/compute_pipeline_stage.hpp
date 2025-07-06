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

#ifndef FUBUKI_FUYU_DETAIL_COMPUTE_PIPELINE_STAGE_HPP
#define FUBUKI_FUYU_DETAIL_COMPUTE_PIPELINE_STAGE_HPP

#include <optional>

#include <core/collect.hpp>
#include <core/pnext_chain.hpp>

#include "fuyu/shader_module.hpp"
#include "fuyu/shader_stage.hpp"
#include "fuyu/views/device_ref.hpp"

namespace fubuki::fuyu::detail::compute_pipeline
{

template<fubuki::traits::pnext_chain::type chain = pnext_chain<>>
struct stage_extension
{
    chain                                       pnext          = {}; ///< Chain extending VkPipelineShaderStageCreateInfo.
    std::optional<shader_stage::specialisation> specialisation = {}; ///< Specialisation information for this stage.
};

struct stage
{
    shader_stage shader = {}; ///< The shader used by this compute pipeline.

    struct underlying_type
    {
        std::optional<shader_module>        on_the_fly_module = {};
        VkPipelineShaderStageCreateInfo     stage             = {};
        std::optional<VkSpecializationInfo> specialisation    = {};
    };
};

//------------------------------------------------------------------------------
// Traits

namespace traits
{
template<typename...>
struct is_stage_extension : std::false_type
{
};

template<typename pnext>
struct is_stage_extension<stage_extension<pnext>> : std::true_type
{
};

template<typename T>
concept stage_extension = is_stage_extension<T>::value;

} // namespace traits

//------------------------------------------------------------------------------
// Deduction guides

stage_extension() -> stage_extension<pnext_chain<>>;

template<typename... elements>
stage_extension(pnext_chain<elements...>) -> stage_extension<pnext_chain<elements...>>;

//------------------------------------------------------------------------------
// Inline functions

template<traits::stage_extension extension>
[[nodiscard]] std::expected<stage::underlying_type, api_call_info> to_underlying(device_cref, const stage&&, const extension&) = delete;

template<traits::stage_extension extension>
[[nodiscard]] std::expected<stage::underlying_type, api_call_info> to_underlying(device_cref device, const stage& s, const extension& ext)
{
    stage::underlying_type result =
    {
        .on_the_fly_module = {},
        .stage             =
        {
            .sType               = structure_type_v<VkPipelineShaderStageCreateInfo>,
            .pNext               = {},
            .flags               = s.shader.flags,
            .stage               = VK_SHADER_STAGE_COMPUTE_BIT,
            .module              = {},
            .pName               = s.shader.entry_point.has_value() ? s.shader.entry_point->c_str() : "main",
            .pSpecializationInfo = nullptr,
        },
        .specialisation = {}
    };

    fubuki::extend(result.stage, ext.pnext);

    if(std::holds_alternative<shader_module_handle>(s.shader.shader))
    {
        result.stage.module = std::get<shader_module_handle>(s.shader.shader).vk;
    }

    if(std::holds_alternative<shader_stage::spirv>(s.shader.shader))
    {
        auto module = shader_module::make(
            device, {.name = {"<On-the-fly compute shader module>"}}, {.spirv = std::get<shader_stage::spirv>(s.shader.shader).code});

        if(not module)
        {
            return std::unexpected{module.error()};
        }

        result.stage.module = module->handle().vk;
        result.on_the_fly_module.emplace(*std::move(module));
    }

    if(ext.specialisation.has_value())
    {
        result.specialisation = VkSpecializationInfo{
            .mapEntryCount = vk_size(ext.specialisation->map_entries),
            .pMapEntries   = ext.specialisation->map_entries.data(),
            .dataSize      = ext.specialisation->data.size(),
            .pData         = ext.specialisation->data.data(),
        };

        result.stage.pSpecializationInfo = std::addressof(*result.specialisation);
    }

    return result;
}

[[nodiscard]] inline std::expected<stage::underlying_type, api_call_info> to_underlying(device_cref d, const stage& s)
{
    return to_underlying(d, s, stage_extension{});
}

} // namespace fubuki::fuyu::detail::compute_pipeline

#endif // FUBUKI_FUYU_DETAIL_COMPUTE_PIPELINE_STAGE_HPP
