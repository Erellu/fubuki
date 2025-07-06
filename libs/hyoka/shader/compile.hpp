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

#ifndef FUBUKI_HYOKA_SHADER_COMPILE_HPP
#define FUBUKI_HYOKA_SHADER_COMPILE_HPP

#include <expected>
#include <optional>
#include <ostream>
#include <string>
#include <unordered_map>
#include <vector>

#include <core/config/macros.hpp>
#include <core/flag_mask.hpp>
#include <core/small_vector.hpp>
#include <core/string_literal.hpp>
#include <core/structure_type.hpp>
#include <core/version_number.hpp>
#include <core/vulkan.hpp>

namespace fubuki::hyoka::shader
{

/// Shader language.
enum class lang
{
    glsl, ///< OpenGL Shading Language
    hlsl  ///< High Level Shading Language
};

/**
 * Shader stages types.
 */
namespace stage
{

namespace detail
{

struct compute_t
{
};

} // namespace detail

/// Stages for classical graphics pipelines.
enum class graphics
{
    vertex,                 ///< The 'vertex' stage of a graphics pipeline.
    tesselation_control,    ///< The 'tesselation control' stage of a graphics pipeline
    tesselation_evaluation, ///< The 'tesselation evalution' stage of a graphics pipeline
    geometry,               ///< The 'geometry' stage of a graphics pipeline
    fragment,               ///< The 'fragment' stage of a graphics pipeline
};

/// Compute shader stage
inline constexpr auto compute = detail::compute_t{};

/// Stages for ray tracing shaders.
enum class ray_tracing
{
    ray_generation, ///< The 'ray generation' stage of a ray tracing pipeline.
    any_hit,        ///< The 'any hit' stage of a ray tracing pipeline.
    closest_hit,    ///< The 'closest hit' stage of a ray tracing pipeline.
    miss,           ///< The 'miss' stage of a ray tracing pipeline.
    intersection,   ///< The 'intersection' stage of a ray tracing pipeline.
    callable,       ///< The 'callable' stage of a ray tracing pipeline.
};

/// Stages for mesh shaders.
enum class mesh
{
    task, ///< The 'task' stage of a mesh shading pipeline.
    mesh, ///< The 'mesh' stage of a mesh shading pipeline.
};

/// Any shader stage.
using any = std::variant<std::monostate, graphics, detail::compute_t, ray_tracing, mesh>;

} // namespace stage

/// Messages that can be enabled when compiling a shader.
// Adapatation of glslang EShMessages,
// see https://github.com/KhronosGroup/glslang/blob/master/glslang/Public/ShaderLang.h#L254
enum class compilation_message : std::uint32_t
{
    default_messages         = 0,         ///< All errors and warning required by the language specifications.
    relaxed_errors           = (1 << 0),  ///< Some flexibility on error regarding inputs.
    suppress_warnings        = (1 << 1),  ///< Suppress all warnings, EXCEPT those required by the language specifications.
    ast                      = (1 << 2),  ///< Prints the AST intermediate representation when compiling.
    spv_rules                = (1 << 3),  ///< Issue messages for SPIR-V generation.
    vulkan_rules             = (1 << 4),  ///< Issue messages for Vulkan requirement of GLSL for SPIR-V.
    only_preprocessor        = (1 << 5),  ///< Only get errors related to preprocessor.
    read_hlsl                = (1 << 6),  ///< Use HLSL parsing rules and semantics.
    cascading_errors         = (1 << 7),  ///< Outputs cascading errors. Risks error-recovery issues instead of an early exit.
    keep_uncalled            = (1 << 8),  ///< FOR TESTING YOUR CODE. Do not eliminate uncalled functions.
    hlsl_offsets             = (1 << 9),  ///< Allows block offsets to follow HLSL rules instead of GLSL rules.
    debug_info               = (1 << 10), ///< Saves debug information in the output file.
    hlsl_enable_16_bit_types = (1 << 11), ///< Enables use of 16-bit types in SPIR-V for HLSL.
    hlsl_legalisation        = (1 << 12), ///< Enables HLSL legalisation messages.
    dx9_compatible           = (1 << 13), ///< Enables HLSL DX9-compatible mode for samplers and semantics.
    builtin_symbol_table     = (1 << 14), ///< Prints the builtin symbol table when compiling
    enhance                  = (1 << 15), ///< Enhance message readability.
};

using compilation_message_mask = flag_mask<compilation_message>;

//------------------------------------------------------------------------------

/// Profile mode to enable when compiling a shader.
enum class profile
{
    none,          ///< Disable all profiling.
    core,          ///< Enable core profiling.
    compatibility, ///< Enable compatibility profiling.
    es             ///< Enable ES profiling.
};

//------------------------------------------------------------------------------

/// Shader source information.
struct source
{
    lang        language;    ///< Language the shader is written in.
    std::string source_code; ///< Shader source code in native language (GLSL, HLSL).
};

//------------------------------------------------------------------------------

/// A set of shaders which you can reuse to compile different shaders.
using resource_group = std::unordered_map<std::string, source, heterogeneous_string_hash, std::equal_to<>>;
using group_cref     = std::reference_wrapper<const resource_group>;

/**
 * @brief A preprocessor #define directive prefixed to the shader source before compilation.
 */
struct preprocessor_define_directive
{
    std::string declare_token; ///< The token passed after '#define', with or without parenthesis.
    std::string value_token;   ///< The token passes after the declaration token.
};

/// Preprocessor #define directives.
using preprocessor_define_directives = small_vector<preprocessor_define_directive>;

//------------------------------------------------------------------------------

// clang-format off

/// Options that can be enabled for the compilation process.
struct compile_options
{
    /// Options when generating SPIR-V.
    struct spv
    {
        bool generate_debug_info            = false;
        bool strip_debug_info               = false;
        bool disable_optimiser              = true;
        bool optimise_size                  = false;
        bool disassemble                    = false;
        bool validate                       = false;
        bool emit_non_semantic_debug_info   = false;
        bool emit_non_semantic_debug_source = false;
        bool compile_only                   = false;
    };

    std::optional<std::int32_t>             dialect_version = {}; ///< Version of the source shader langage. For GLSL, this is an integer between 100 and 460.
    std::optional<compilation_message_mask> messages        = {}; ///< Compilation messages to enable when compiling this shader.

    std::optional<bool> force_default_version_and_profile = {}; ///< Indicates if the shader must be compiled with forced-default version and profiling. Default is 'false'.
    std::optional<bool> forward_compatible                = {}; ///< Indicates if the shader must be compiled as forward-compatible. Default is 'false'.
    std::optional<bool> include_source                    = {}; ///< Indicates if the result compiled_shader '.source' member must be filled.
    std::optional<bool> include_logs                      = {}; ///< Indicates if the result compiled_shader needs to retrieve the compiler logs emitted during the process.

    std::optional<spv> spirv = {}; ///< (optional) SPIRV-options.
};

/// Information required to compile a shader.
struct compile_info
{
    using option = compile_options;

    // NOLINTBEGIN(cppcoreguidelines-avoid-magic-numbers)
    source                                              shader               = {};            ///< Shader to compile.
    stage::any                                          stage                = {};            ///< Stage this shader is used in.
    version_number                                      vulkan_version       = {1, 3, 0};     ///< Version of Vulkan this shader must be compiled for.
    version_number                                      spirv_version        = {1, 6, 0};     ///< Version of SPIR-V this shader must be compiled to.
    profile                                             compatibility        = profile::none; ///< Indicates what kind of profiling must be enabled.
    std::optional<const preprocessor_define_directives> preprocessor_defines = {};            ///< #define directives to pass to the preprocessor and their values.
    std::optional<group_cref>                           additional_resources = {};            ///< Additional shaders to fill the  #include directives.
    option                                              options              = {};            ///<  Options that can be enabled for the compilation process.
    // NOLINTEND(cppcoreguidelines-avoid-magic-numbers)
};

//------------------------------------------------------------------------------

/// Compiled shader.
struct compiled
{
    /// Compiler logs.
    struct compiler_logs
    {
        struct step
        {
            std::optional<std::string> info  = {}; ///< Informative log returned by the compiler.
            std::optional<std::string> debug = {}; ///< Debug log returned by the compiler.
        };

        step preprocessing               = {}; ///< Logs emitted during the preprocessing step.
        step parsing                     = {}; ///< Logs emitted during the parsing step.
        step linking                     = {}; ///< Logs emitted during the linking step.
        std::optional<std::string> spirv = {}; ///< Logs emitted during the spirv step.
    };

    std::vector<std::uint32_t> spirv               = {}; ///< SPIR-V source code.
    stage::any                 stage               = {}; ///< Stage this shader is used in.
    std::optional<std::string> source              = {}; ///< Source code used to compile this shader. Filled when setting include_source to true in shader_compile_info.
    std::optional<std::string> preprocessed_source = {}; ///< Source code parsed by the compiler, all preprocessing directives resolved. Filled when setting include_source to true in shader_compile_info.
    compiler_logs              logs                = {}; ///< Compiler logs emitted during the compilation.

    inline operator VkShaderModuleCreateInfo() const
    {
        return
        {
            .sType    = structure_type_v<VkShaderModuleCreateInfo>,
            .pNext    = nullptr,
            .flags    = 0, // Imposed by the specs
            .codeSize = spirv.size() * sizeof(std::uint32_t) / sizeof(std::uint8_t),
            .pCode    = spirv.data(),
        };
    }
};

struct compile_error
{
    /// The different stages that may fail when attempting to compile a shader.
    enum class code
    {
        preprocessing, ///< An error occurred in the preprocessing phase.
        parsing,       ///< An error occurred in the parsing phase, after the preprocessing.
        linking,       ///< An error occurred in the linking phase, after the parsing.
    };

    /// Compiler logs.
    struct compiler_logs
    {
        std::optional<std::string> info  = {}; ///< Informative log returned by the compiler.
        std::optional<std::string> debug = {}; ///< Debug log returned by the compiler.

        template<typename char_type, typename traits = std::char_traits<char_type>>
        friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const compiler_logs& l)
        {
            out << "logs:{ info:" << l.info.value_or("");
            out << ", debug:" << l.debug.value_or("");
            out << "}";
            return out;
        }
    };

    using enum code;

    std::optional<code> value                      = {}; ///< The error code, if known, describing the error.
    std::optional<std::string> preprocessed_source = {}; ///< Source code parsed by the compiler, all preprocessing directives resolved. Filled when setting include_source to true in shader_compile_info.
    compiler_logs logs                             = {}; ///< Compiler logs emitted up to the failing point.

    template<typename char_type, typename traits = std::char_traits<char_type>>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const code& error)
    {
        switch(error)
        {
            case compile_error::code::preprocessing: return out << "compile_error::code::preprocessing";
            case compile_error::code::parsing      : return out << "compile_error::code::parsing";
            case compile_error::code::linking      : return out << "compile_error::code::linking";
            default                                : return out << "compile_error::code::unknown";
        }
    }

    template<typename char_type, typename traits = std::char_traits<char_type>>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const compile_error& error)
    {
        constexpr auto print_optional = []<typename U>(std::basic_ostream<char_type, traits>& stream, const std::optional<U>& opt)
        {
            if(opt)
            {
                stream << *opt;
            }
            else
            {
                stream << "unknown";
            }
        };

        out << "compile_error:{code: ";
        print_optional(out, error.value);
        out << ", preprocessed_source:";
        print_optional(out, error.preprocessed_source);
        out << "," << error.logs << "}";

        return out ;
    }
};
// clang-format on

//------------------------------------------------------------------------------

/// Compiles a shader to SPIR-V.
/// @throws This function CAN throw an instance of std::bad_alloc if some resource allocation failed.
FUBUKI_HYOKA_API
extern std::expected<compiled, compile_error> compile(const compile_info&);

} // namespace fubuki::hyoka::shader

#endif // FUBUKI_HYOKA_SHADER_COMPILE_HPP
