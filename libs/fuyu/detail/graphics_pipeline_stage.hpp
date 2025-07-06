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

#ifndef FUBUKI_FUYU_DETAIl_GRAPHICS_PIPELINE_STAGE_HPP
#define FUBUKI_FUYU_DETAIl_GRAPHICS_PIPELINE_STAGE_HPP

#include <optional>
#include <variant>

#include <core/collect.hpp>
#include <core/handle.hpp>
#include <core/pnext_chain.hpp>

#include "fuyu/shader_module.hpp"
#include "fuyu/shader_stage.hpp"
#include "fuyu/views/device_ref.hpp"

namespace fubuki::fuyu::detail::graphics_pipeline
{

// TODO: separate process for mesh shaders (different object than graphics_pipeline)

/// Describes the different programmable stages of a graphics pipeline.
struct stages
{
    static constexpr std::size_t count = 5; ///< The maximum number of stages in a classical graphics pipeline.

    struct tesselation_stage
    {
        shader_stage control    = {}; ///< The tesselation control stage.
        shader_stage evaluation = {}; ///< The tesselation evaluation stage.

        [[nodiscard]] friend constexpr bool operator==(const tesselation_stage& a, const tesselation_stage& b) noexcept = default;
        [[nodiscard]] friend constexpr bool operator!=(const tesselation_stage& a, const tesselation_stage& b) noexcept = default;
    };

    struct underlying_type
    {

        inplace_vector<shader_module, count>                   on_the_fly_modules = {};
        inplace_vector<VkPipelineShaderStageCreateInfo, count> stages             = {};
        inplace_vector<VkSpecializationInfo, count>            specialisations    = {};
    };

    std::optional<shader_stage>      vertex      = {}; ///< The vertex shader stage.
    std::optional<tesselation_stage> tesselation = {}; ///< The tesselation shader stages.
    std::optional<shader_stage>      geometry    = {}; ///< The geometry shader stage.
    std::optional<shader_stage>      fragment    = {}; ///< The fragment shader stage.

    [[nodiscard]] friend constexpr bool operator==(const stages& a, const stages& b) noexcept = default;
    [[nodiscard]] friend constexpr bool operator!=(const stages& a, const stages& b) noexcept = default;
};

template<fubuki::traits::pnext_chain::type stage_vertex_pnext                 = fubuki::pnext_chain<>,
         fubuki::traits::pnext_chain::type stage_tesselation_control_pnext    = fubuki::pnext_chain<>,
         fubuki::traits::pnext_chain::type stage_tessalation_evaluation_pnext = fubuki::pnext_chain<>,
         fubuki::traits::pnext_chain::type stage_geometry_pnext               = fubuki::pnext_chain<>,
         fubuki::traits::pnext_chain::type stage_fragment_pnext               = fubuki::pnext_chain<>>
struct stages_extension
{
    template<traits::pnext_chain::type chain>
    struct desc
    {
        chain                                       pnext          = {}; ///< Chain extending VkPipelineShaderStageCreateInfo for this stage.
        std::optional<shader_stage::specialisation> specialisation = {}; ///< Specialisation information for this stage.
    };

    struct tesselation_stage
    {
        desc<stage_tesselation_control_pnext>    control    = {}; ///< Complement information for the tesselation control stage.
        desc<stage_tessalation_evaluation_pnext> evaluation = {}; ///< Complement information for the tesselation evaluation stage.
    };

    desc<stage_vertex_pnext>   vertex      = {}; ///< Complement information for the vertex stage.
    tesselation_stage          tesselation = {}; ///< Complement information for the tesselation stages.
    desc<stage_geometry_pnext> geometry    = {}; ///< Complement information for the geometry stage.
    desc<stage_fragment_pnext> fragment    = {}; ///< Complement information for the fragment stage.
};

//------------------------------------------------------------------------------
// Traits

namespace traits
{

template<typename...>
struct is_stages_extension;

template<typename...>
struct is_stages_extension : std::false_type
{
};

template<typename stage_vertex_pnext,
         typename stage_tesselation_control_pnext,
         typename stage_tessalation_evaluation_pnext,
         typename stage_geometry_pnext,
         typename stage_fragment_pnext>
struct is_stages_extension<stages_extension<stage_vertex_pnext,
                                            stage_tesselation_control_pnext,
                                            stage_tessalation_evaluation_pnext,
                                            stage_geometry_pnext,
                                            stage_fragment_pnext>> : std::true_type
{
};

template<typename T>
concept stages_extension = is_stages_extension<T>::value;

} // namespace traits

//------------------------------------------------------------------------------
// Deduction guides

stages_extension() -> stages_extension<pnext_chain<>, pnext_chain<>, pnext_chain<>, pnext_chain<>, pnext_chain<>>;

template<typename... stage_vertex_pnext_elements,
         typename... stage_tesselation_control_pnext_elements,
         typename... stage_tessalation_evaluation_pnext_elements,
         typename... stage_geometry_pnext_elements,
         typename... stage_fragment_pnext_elements>
stages_extension(pnext_chain<stage_vertex_pnext_elements...>,
                 pnext_chain<stage_tesselation_control_pnext_elements...>,
                 pnext_chain<stage_tessalation_evaluation_pnext_elements...>,
                 pnext_chain<stage_geometry_pnext_elements...>,
                 pnext_chain<stage_fragment_pnext_elements...>) -> stages_extension<pnext_chain<stage_vertex_pnext_elements...>,
                                                                                    pnext_chain<stage_tesselation_control_pnext_elements...>,
                                                                                    pnext_chain<stage_tessalation_evaluation_pnext_elements...>,
                                                                                    pnext_chain<stage_geometry_pnext_elements...>,
                                                                                    pnext_chain<stage_fragment_pnext_elements...>>;

//------------------------------------------------------------------------------
// Inline functions

template<traits::stages_extension extension>
[[nodiscard]] inline auto to_underlying(device_cref, const stages&&, const extension&) noexcept = delete; // Forbid temporaries

template<traits::stages_extension extension>
[[nodiscard]] inline std::expected<stages::underlying_type, api_call_info>
to_underlying(device_cref device, const stages& s, const extension& ext) noexcept
{
    stages::underlying_type result = {};

    const auto produce
        = [&device, &result]<typename pnext>(const std::optional<shader_stage>&     src,
                                             const VkShaderStageFlagBits            id,
                                             std::string                            name,
                                             const extension::template desc<pnext>& chain) noexcept -> std::expected<void, api_call_info>
    {
        if(not src.has_value())
        {
            return {};
        }

        auto& vk_stage = result.stages.emplace_back(VkPipelineShaderStageCreateInfo{
            .sType               = structure_type_v<VkPipelineShaderStageCreateInfo>,
            .pNext               = {},
            .flags               = src->flags,
            .stage               = id,
            .module              = {},
            .pName               = src->entry_point.has_value() ? src->entry_point->c_str() : "main",
            .pSpecializationInfo = nullptr,
        });

        fubuki::extend(vk_stage, chain.pnext);

        if(std::holds_alternative<shader_module_handle>(src->shader))
        {
            vk_stage.module = std::get<shader_module_handle>(src->shader).vk;
        }

        if(std::holds_alternative<shader_stage::spirv>(src->shader))
        {
            auto module = shader_module::make(device, {.name = std::move(name)}, {.spirv = std::get<shader_stage::spirv>(src->shader).code});

            if(not module)
            {
                return std::unexpected{module.error()};
            }

            vk_stage.module = module->handle().vk;
            result.on_the_fly_modules.emplace_back(*std::move(module));
        }

        if(chain.specialisation.has_value())
        {
            auto& specialisation = result.specialisations.emplace_back(VkSpecializationInfo{

                .mapEntryCount = vk_size(chain.specialisation->map_entries),
                .pMapEntries   = chain.specialisation->map_entries.data(),
                .dataSize      = chain.specialisation->data.size(),
                .pData         = chain.specialisation->data.data(),
            });

            vk_stage.pSpecializationInfo = std::addressof(specialisation);
        }

        return {};
    };

    if(const auto stage = produce(s.vertex, VK_SHADER_STAGE_VERTEX_BIT, "<On-the-fly vertex shader module>", ext.vertex); not stage)
    {
        return std::unexpected{stage.error()};
    }

    if(s.tesselation.has_value())
    {
        if(const auto stage = produce(s.tesselation->control,
                                      VK_SHADER_STAGE_TESSELLATION_CONTROL_BIT,
                                      "<On-the-fly tesselation control shader module>",
                                      ext.tesselation.control);
           not stage)
        {
            return std::unexpected{stage.error()};
        }

        if(const auto stage = produce(s.tesselation->evaluation,
                                      VK_SHADER_STAGE_TESSELLATION_EVALUATION_BIT,
                                      "<On-the-fly tesselation evaluation shader module>",
                                      ext.tesselation.evaluation);
           not stage)
        {
            return std::unexpected{stage.error()};
        }
    }

    if(const auto stage = produce(s.geometry, VK_SHADER_STAGE_GEOMETRY_BIT, "<On-the-fly geometry shader module>", ext.geometry); not stage)
    {
        return std::unexpected{stage.error()};
    }

    if(const auto stage = produce(s.fragment, VK_SHADER_STAGE_FRAGMENT_BIT, "<On-the-fly fragment shader module>", ext.fragment); not stage)
    {
        return std::unexpected{stage.error()};
    }

    return result;
}

[[nodiscard]] inline auto to_underlying(device_cref device, const stages&& s) noexcept = delete; // Forbid temporaries
[[nodiscard]] inline auto to_underlying(device_cref device, const stages& s) noexcept { return to_underlying(device, s, stages_extension{}); }

} // namespace fubuki::fuyu::detail::graphics_pipeline

#endif // FUBUKI_FUYU_DETAIl_GRAPHICS_PIPELINE_STAGE_HPP
