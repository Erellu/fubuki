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

#include <iomanip> // IWYU pragma: keep
#include <memory>
#include <sstream>

#include "hyoka/shader/compile.hpp"

#include <glslang/Include/ResourceLimits.h>
#include <glslang/Public/ResourceLimits.h>
#include <glslang/Public/ShaderLang.h>
#include <glslang/SPIRV/GlslangToSpv.h>

#include <core/assertion.hpp>

namespace fubuki::hyoka::shader
{

namespace
{

//------------------------------------------------------------------------------
// GLSLANG conversion

struct glslang_input
{
    EShLanguage                       stage          = {};
    glslang::EShSource                language       = {};
    glslang::EShTargetClientVersion   client_version = {};
    glslang::EShTargetLanguageVersion target_version = {};
    EProfile                          profile        = {};
    EShMessages                       messages       = {};
};

//------------------------------------------------------------------------------

[[nodiscard]] constexpr auto to_glslang_stage(const stage::any stage) noexcept
{
    fubuki_assert(not std::holds_alternative<std::monostate>(stage), "Invalid shader stage.");

    if(const auto* const contents = std::get_if<stage::graphics>(std::addressof(stage)))
    {
        switch(*contents)
        {
            case stage::graphics::vertex                : return EShLangVertex;
            case stage::graphics::tesselation_control   : return EShLangTessControl;
            case stage::graphics::tesselation_evaluation: return EShLangTessEvaluation;
            case stage::graphics::geometry              : return EShLangGeometry;
            case stage::graphics::fragment              : return EShLangFragment;
            default                                     : fubuki_assert(false, "Invalid enumeration, perhaps static_cast?");
        }
    }

    if(std::holds_alternative<stage::detail::compute_t>(stage))
    {
        return EShLangCompute;
    }

    if(const auto* const contents = std::get_if<stage::ray_tracing>(std::addressof(stage)))
    {
        switch(*contents)
        {
            case stage::ray_tracing::ray_generation: return EShLangRayGen;
            case stage::ray_tracing::any_hit       : return EShLangAnyHit;
            case stage::ray_tracing::closest_hit   : return EShLangClosestHit;
            case stage::ray_tracing::miss          : return EShLangMiss;
            case stage::ray_tracing::intersection  : return EShLangIntersect;
            case stage::ray_tracing::callable      : return EShLangCallable;
            default                                : fubuki_assert(false, "Invalid enumeration, perhaps static_cast?");
        }
    }
    if(const auto* const contents = std::get_if<stage::mesh>(std::addressof(stage)))
    {
        switch(*contents)
        {
            case stage::mesh::task: return EShLangTask;
            case stage::mesh::mesh: return EShLangMesh;
            default               : fubuki_assert(false, "Invalid enumeration, perhaps static_cast?");
        }
    }

    return EShLangCount; // Invalid value, will trigger something in glslang
}

//------------------------------------------------------------------------------

/// Converts a lang to its corresponding glslang enum.
[[nodiscard]] constexpr auto to_glslang(const lang l) noexcept
{
    switch(l)
    {
        case lang::glsl: return glslang::EShSourceGlsl;

        case lang::hlsl: return glslang::EShSourceHlsl;

        default: fubuki_assert(false, "Invalid language. Perhaps static_cast?"); return glslang::EShSourceNone;
    }
}

//------------------------------------------------------------------------------

/// Converts a version_number to its corresponding glslang enum for client version.
[[nodiscard]] constexpr auto to_glslang_client_version(const version_number& v) noexcept
{
    using ver                    = version_number;
    const version_number version = {v.major, v.minor, 0};

    // NOLINTBEGIN(cppcoreguidelines-avoid-magic-numbers)
    switch(version)
    {
        case(ver{1, 0, 0}): return glslang::EShTargetVulkan_1_0;

        case(ver{1, 1, 0}): return glslang::EShTargetVulkan_1_1;

        case(ver{1, 2, 0}): return glslang::EShTargetVulkan_1_2;

        case(ver{1, 3, 0}): return glslang::EShTargetVulkan_1_3;

        default: fubuki_assert(false, "Unsupported Vulkan version."); return glslang::EShTargetVulkan_1_0;
    }
    // NOLINTEND(cppcoreguidelines-avoid-magic-numbers)
}

//------------------------------------------------------------------------------

/// Converts a version_number to its corresponding glslang for target version.
[[nodiscard]] constexpr auto to_glslang_target_version(const version_number& v) noexcept
{
    using ver                    = version_number;
    const version_number version = {v.major, v.minor, 0};

    // NOLINTBEGIN(cppcoreguidelines-avoid-magic-numbers)
    switch(version)
    {
        case(ver{1, 0, 0}): return glslang::EShTargetSpv_1_0;

        case(ver{1, 1, 0}): return glslang::EShTargetSpv_1_1;

        case(ver{1, 2, 0}): return glslang::EShTargetSpv_1_2;

        case(ver{1, 3, 0}): return glslang::EShTargetSpv_1_3;

        case(ver{1, 4, 0}): return glslang::EShTargetSpv_1_4;

        case(ver{1, 5, 0}): return glslang::EShTargetSpv_1_5;

        case(ver{1, 6, 0}): return glslang::EShTargetSpv_1_6;

        default: fubuki_assert(false, "Unsupported SPIR-V version"); return glslang::EShTargetSpv_1_0;
    }
    // NOLINTEND(cppcoreguidelines-avoid-magic-numbers)
}

//------------------------------------------------------------------------------

/// Converts a profile to its corresponding glslang enum.
[[nodiscard]] constexpr auto to_glslang(const profile p) noexcept
{
    switch(p)
    {
        case profile::none: return ENoProfile;

        case profile::core: return ECoreProfile;

        case profile::compatibility: return ECompatibilityProfile;

        case profile::es: return EEsProfile;

        default: return EBadProfile;
    }
}

//------------------------------------------------------------------------------

/// Converts a compilation_message_mask to its corresponding glslang enum.
[[nodiscard]] constexpr auto to_glslang(const std::optional<compilation_message_mask> m) noexcept
{
    if(!m.has_value())
    {
        return EShMessages::EShMsgDefault;
    }

    // NOLINTBEGIN(bugprone-suspicious-enum-usage, clang-analyzer-optin.core.EnumCastOutOfRange)
    // glslang uses directly the enum type as a bitmask integer (so it internally handles values made of binary 'or' of the possible values)
    constexpr auto add_glslang_flag
        = [](EShMessages& base, EShMessages flag) noexcept { base = static_cast<EShMessages>(std::to_underlying(base) | flag); };
    // NOLINTEND(bugprone-suspicious-enum-usage, clang-analyzer-optin.core.EnumCastOutOfRange)

    using message   = compilation_message;
    const auto mask = m.value();

    EShMessages result = {};

    if(mask & message::default_messages)
    {
        add_glslang_flag(result, EShMessages::EShMsgDefault);
    }

    if(mask & message::relaxed_errors)
    {
        add_glslang_flag(result, EShMessages::EShMsgRelaxedErrors);
    }

    if(mask & message::suppress_warnings)
    {
        add_glslang_flag(result, EShMessages::EShMsgSuppressWarnings);
    }

    if(mask & message::ast)
    {
        add_glslang_flag(result, EShMessages::EShMsgAST);
    }

    if(mask & message::spv_rules)
    {
        add_glslang_flag(result, EShMessages::EShMsgSpvRules);
    }

    if(mask & message::vulkan_rules)
    {
        add_glslang_flag(result, EShMessages::EShMsgVulkanRules);
    }

    if(mask & message::only_preprocessor)
    {
        add_glslang_flag(result, EShMessages::EShMsgOnlyPreprocessor);
    }

    if(mask & message::read_hlsl)
    {
        add_glslang_flag(result, EShMessages::EShMsgReadHlsl);
    }

    if(mask & message::cascading_errors)
    {
        add_glslang_flag(result, EShMessages::EShMsgCascadingErrors);
    }

    if(mask & message::keep_uncalled)
    {
        add_glslang_flag(result, EShMessages::EShMsgKeepUncalled);
    }

    if(mask & message::hlsl_offsets)
    {
        add_glslang_flag(result, EShMessages::EShMsgHlslOffsets);
    }

    if(mask & message::debug_info)
    {
        add_glslang_flag(result, EShMessages::EShMsgDebugInfo);
    }

    if(mask & message::hlsl_enable_16_bit_types)
    {
        add_glslang_flag(result, EShMessages::EShMsgHlslEnable16BitTypes);
    }

    if(mask & message::hlsl_legalisation)
    {
        add_glslang_flag(result, EShMessages::EShMsgHlslLegalization);
    }

    if(mask & message::dx9_compatible)
    {
        add_glslang_flag(result, EShMessages::EShMsgHlslDX9Compatible);
    }

    if(mask & message::builtin_symbol_table)
    {
        add_glslang_flag(result, EShMessages::EShMsgBuiltinSymbolTable);
    }

    if(mask & message::enhance)
    {
        add_glslang_flag(result, EShMessages::EShMsgEnhanced);
    }

    return result;
}

//------------------------------------------------------------------------------

[[nodiscard]] constexpr glslang_input to_glslang(const compile_info& source) noexcept
{
    return {
        .stage          = to_glslang_stage(source.stage),
        .language       = to_glslang(source.shader.language),
        .client_version = to_glslang_client_version(source.vulkan_version),
        .target_version = to_glslang_target_version(source.spirv_version),
        .profile        = to_glslang(source.compatibility),
        .messages       = to_glslang(source.options.messages),
    };
}

//------------------------------------------------------------------------------

/// Converts SPIR-V options to the corresponding glslang type.
[[nodiscard]] constexpr glslang::SpvOptions to_glslang(const compile_options::spv spv_options) noexcept
{
    return {
        .generateDebugInfo                = spv_options.generate_debug_info,
        .stripDebugInfo                   = spv_options.strip_debug_info,
        .disableOptimizer                 = spv_options.disable_optimiser,
        .optimizeSize                     = spv_options.optimise_size,
        .disassemble                      = spv_options.disassemble,
        .validate                         = spv_options.validate,
        .emitNonSemanticShaderDebugInfo   = spv_options.emit_non_semantic_debug_info,
        .emitNonSemanticShaderDebugSource = spv_options.emit_non_semantic_debug_source,
        .compileOnly                      = spv_options.compile_only,
    };
}

//------------------------------------------------------------------------------

/// Adds preprocessor '#define's directives.
[[nodiscard]]
source preprocess(const source& source, const preprocessor_define_directives& preprocessor_defines)
{
    // Sanity checks
    {
        if(source.language == lang::glsl)
        {
            fubuki_assert(source.source_code.starts_with("#version "), "A GLSL shader must start with a #version directive.");
        }
    }

    std::istringstream input{source.source_code};
    std::ostringstream output;

    std::string_view source_code = source.source_code;

    // Extract #version which MUST be the first line of a GLSL shader
    if(source.language == lang::glsl)
    {
        std::string first_line;
        std::getline(input, first_line);
        source_code.remove_prefix(first_line.size()); // Don't add it twice
        output << first_line << "\n";
    }

    // Write preprocessor #defines
    {
        for(const auto& [define, value] : preprocessor_defines)
        {
            output << "#define " << define << " " << value << "\n";
        }
    }

    // Write the rest of the shader
    output << source_code << "\n";

    return {.language = source.language, .source_code = output.str()};
}

//------------------------------------------------------------------------------

/// Singleton to handle glslang context setup.
class glslang_context final
{
public:

    /// Sets up the context. Does nothing after first call.
    static void initialise()
    {
        static glslang_context context;
        context.setup();
    }

    /// Destroys the context.
    ~glslang_context()
    {
        if(m_setup)
        {
            glslang::FinalizeProcess();
        }
    }

private:

    glslang_context() = default;

    /// Sets up the context. Does nothing after first call.
    /// Provided as workaround for some over-optimisation by some compilers which sometimes would otherwise remove static variable in initialise...
    void setup()
    {
        if(!m_setup)
        {
            [[maybe_unused]] const bool process_initialize_succeeded = glslang::InitializeProcess();
            fubuki_assert(process_initialize_succeeded, "Failed to initialize glslang context for this process.");
        }

        m_setup = true;
    }

    bool m_setup = false;
};

} // anonymous namespace

//------------------------------------------------------------------------------

class includer final : public glslang::TShader::Includer
{
public:
    includer(const resource_group& resources) : m_resources{resources} {}

    IncludeResult* includeSystem(const char* header_name, const char* includer_name, std::size_t inclusion_depth) final
    {
        return includeLocal(header_name, includer_name, inclusion_depth);
    }

    IncludeResult* includeLocal(const char* header_name, const char* /*includer_name*/, std::size_t /*inclusion_depth*/) final
    {
        if(const auto it = m_results.find(header_name); it != m_results.cend())
        {
            return it->second.get();
        }

        const auto resource_it = m_resources.get().find(header_name);
        fubuki_assert(resource_it != m_resources.get().cend(), "Invalid resource name " << std::quoted(header_name));

        const auto& resource = resource_it->second;

        auto include_result = std::make_unique<IncludeResult>(header_name,                  /* header name */
                                                              resource.source_code.c_str(), /* header contents */
                                                              resource.source_code.size(),  /* header size */
                                                              static_cast<void*>(nullptr)   /* user data */
        );

        const auto emplace_result = m_results.emplace(header_name, std::move(include_result));
        fubuki_assert(emplace_result.second, "Failed to insert resource.");

        return emplace_result.first->second.get();
    }

    void releaseInclude(IncludeResult*) override {} // Do nothing, resources are freed in the dtor

private:

    std::reference_wrapper<const resource_group>                                                                m_resources;
    std::unordered_map<std::string, std::unique_ptr<IncludeResult>, heterogeneous_string_hash, std::equal_to<>> m_results;
};

//------------------------------------------------------------------------------

std::expected<compiled, compile_error> compile(const compile_info& source)
{
    // Does nothing after first call
    glslang_context::initialise();

    const auto source_dialect_version = source.options.dialect_version.value_or(100);

    const bool include_source = source.options.include_source.value_or(false);

    static const auto default_resource_group                 = resource_group{};
    static const auto default_preprocessor_define_directives = preprocessor_define_directives{};

    const auto& group                = source.additional_resources.value_or(std::ref(default_resource_group));
    const auto& preprocessor_defines = source.preprocessor_defines.value_or(std::ref(default_preprocessor_define_directives));

    const auto include_logs = source.options.include_logs.value_or(false);

    const auto        preprocessed_shader = preprocess(source.shader, preprocessor_defines);
    const auto* const preprocessed_c_str  = preprocessed_shader.source_code.c_str();

    compiled result = {.spirv               = {},
                       .stage               = source.stage,
                       .source              = (include_source ? preprocessed_shader.source_code : std::optional<std::string>{}),
                       .preprocessed_source = {}};

    const auto glslang_input = to_glslang(source);

    glslang::TShader shader{glslang_input.stage};
    shader.setStrings(&preprocessed_c_str, 1);
    shader.setEnvInput(glslang_input.language, glslang_input.stage, glslang::EShClientVulkan, source_dialect_version);
    shader.setEnvClient(glslang::EShClientVulkan, glslang_input.client_version);
    shader.setEnvTarget(glslang::EShTargetSpv, glslang_input.target_version);

    includer glslang_includer{group};

    std::string preprocessing_result = {};

    // Preprocessing
    {
        const auto preprocess_succeeded = shader.preprocess(GetDefaultResources(),
                                                            source_dialect_version,
                                                            glslang_input.profile,
                                                            source.options.force_default_version_and_profile.value_or(false),
                                                            source.options.forward_compatible.value_or(false),
                                                            glslang_input.messages,
                                                            &preprocessing_result,
                                                            glslang_includer);

        const auto* const info_log  = shader.getInfoLog();
        const auto* const debug_log = shader.getInfoDebugLog();

        if(not preprocess_succeeded)
        {

            return std::unexpected
                {
                    compile_error
                    {
                        .value               = compile_error::preprocessing,
                        .preprocessed_source = preprocessing_result,
                        .logs                =
                        {
                            .info  = info_log != nullptr ? info_log : "<none>",
                            .debug = debug_log != nullptr ? debug_log : "<none>",
                        },
                    }
            };
        }

        if(include_logs)
        {
            result.logs.preprocessing.info  = std::string{info_log != nullptr ? info_log : "<none>"};
            result.logs.preprocessing.debug = std::string{debug_log != nullptr ? debug_log : "<none>"};
        }
    }

    if(include_source)
    {
        result.preprocessed_source = preprocessing_result;
    }

    // Parsing
    {
        const auto parse_succeeded = shader.parse(GetDefaultResources(),
                                                  source_dialect_version,
                                                  glslang_input.profile,
                                                  source.options.force_default_version_and_profile.value_or(false),
                                                  source.options.forward_compatible.value_or(false),
                                                  glslang_input.messages,
                                                  glslang_includer);

        const auto* const info_log  = shader.getInfoLog();
        const auto* const debug_log = shader.getInfoDebugLog();

        if(not parse_succeeded)
        {
            return std::unexpected
                {
                    compile_error
                    {
                        .value               = compile_error::parsing,
                        .preprocessed_source = preprocessing_result,
                        .logs                =
                        {
                            .info  = info_log != nullptr ? info_log : "<none>",
                            .debug = debug_log != nullptr ? debug_log : "<none>",
                        },
                    }
            };
        }

        if(include_logs)
        {
            result.logs.parsing.info  = std::string{info_log != nullptr ? info_log : "<none>"};
            result.logs.parsing.debug = std::string{debug_log != nullptr ? debug_log : "<none>"};
        }
    }

    glslang::TProgram program;
    program.addShader(&shader);

    // Link
    {
        const auto        link_suceeded = program.link(glslang_input.messages);
        const auto* const info_log      = program.getInfoLog();
        const auto* const debug_log     = program.getInfoDebugLog();

        if(not link_suceeded)
        {
            return std::unexpected
                {
                    compile_error
                    {
                        .value               = compile_error::linking,
                        .preprocessed_source = preprocessing_result,
                        .logs                =
                        {
                            .info  = info_log != nullptr ? info_log : "<none>",
                            .debug = debug_log != nullptr ? debug_log : "<none>",
                        },
                    }
            };
        }

        if(include_logs)
        {
            result.logs.parsing.info  = std::string{info_log != nullptr ? info_log : "<none>"};
            result.logs.parsing.debug = std::string{debug_log != nullptr ? debug_log : "<none>"};
        }
    }

    // SPIRV
    {
        spv::SpvBuildLogger logger       = {};
        const auto* const   intermediate = program.getIntermediate(glslang_input.stage);

        auto options = to_glslang(source.options.spirv.value_or(compile_options::spv{}));

        glslang::GlslangToSpv(*intermediate, result.spirv, std::addressof(logger), std::addressof(options));

        if(const auto spirv_messages = logger.getAllMessages(); not spirv_messages.empty() and include_logs)
        {
            result.logs.spirv = spirv_messages;
        }
    }

    return result;
}

} // namespace fubuki::hyoka::shader
