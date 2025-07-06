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

#include <iomanip>
#include <iostream>

#include <hyoka/shader/compile.hpp>

namespace hyoka = fubuki::hyoka;

//------------------------------------------------------------------------------
// Functions used to create the resource group

hyoka::shader::source meow_glsl()
{
    constexpr auto source_code =
        R"(
#ifndef MEOW_GLSL
#define MEOW_GLSL

int meow(){return 2;}

#endif // MEOW_GLSL
)";
    return {.language = hyoka::shader::lang::glsl, .source_code = source_code};
}

//------------------------------------------------------------------------------

hyoka::shader::source woof_struct()
{
    constexpr auto source_code =
        R"(
#ifndef WOOF_STRUCT
#define WOOF_STRUCT

// Note: cannot have empty structs in GLSL, so don't attempt it
struct woof
{
    int f;
};

#endif // WOOF_STRUCT
)";
    return {.language = hyoka::shader::lang::glsl, .source_code = source_code};
}

//------------------------------------------------------------------------------

hyoka::shader::source snake_glsl()
{
    constexpr auto source_code =
        R"(
#ifndef SNAKE_GLSL
#define SNAKE_GLSL

float snake(in vec2 f)
{
    return length(f);
}

#endif // SNAKE_GLSL
)";
    return {.language = hyoka::shader::lang::glsl, .source_code = source_code};
}

//------------------------------------------------------------------------------

hyoka::shader::source wow_glsl()
{
    constexpr auto source_code =
        R"(
#ifndef WOW_GLSL
#define WOW_GLSL

float wow(in vec4 f, in vec4 fff)
{
    return distance(f, fff);
}

#endif // WOW_GLSL
)";
    return {.language = hyoka::shader::lang::glsl, .source_code = source_code};
}

//------------------------------------------------------------------------------

int main()
{
    // [1]
    // Sample shader to compile.
    constexpr auto shader =
        R"(#version 460

#extension GL_GOOGLE_include_directive: enable

#include "meow.glsl"
#include "woof.struct"
#include <snake.glsl>
#include"nested/wow.glsl"

layout(location = 0) out vec4 fragment_colour;

void main()
{
    fragment_colour = vec4(1.f);
}
)";

    /* [2]
     * Preprocessor #define directives to add.
     * Those are added either at or after the first line of the shader (i.e., after #version directive in GLSL and directly at the first line in
     * HLSL). Concretely:
     *
     * ************************************************
     *
     * GLSL:
     *
     * #version whatever
     * #define FOO 22541
     * #define FUBUKI 1
     * #define FUNCTION_LIKE_MACRO(x) x
     *
     * ...
     *
     * ************************************************
     *
     * HLSL:
     *
     * #define FOO 22541
     * #define FUBUKI 1
     * #define FUNCTION_LIKE_MACRO(x) x
     *
     * ...
     *
     */
    const hyoka::shader::preprocessor_define_directives preprocessor_defines{
        {"FOO",                    "22541"},
        {"FUBUKI",                 "1"    },
        {"FUNCTION_LIKE_MACRO(x)", "x"    }
    };

    /* [3]
     * Other shaders that are needed for #include directives.
     * Here, it is one-shot, but you can 'cache' a bunch of those in your application and
     * reuse those resources across shaders.
     *
     * There is no mechanism for such caching in fubuki, but it is basically an
     * std::unordered_map<whatever_key_you_like, hyoka::shader::resource_group>.
     */
    const hyoka::shader::resource_group resource_group = {
        {"meow.glsl",       meow_glsl()  },
        {"woof.struct",     woof_struct()},
        {"snake.glsl",      snake_glsl() },
        {"nested/wow.glsl", wow_glsl()   }
    };

    /* [4]
     * Information needed to compile the shader.
     *
     * This sample explicitly provides all information, including bits using defaults for illustration purposes.
     *
     * The typical call looks more like:
     *
     *     const auto compiled_shader = hyoka::compile_shader({.shader = {lang, source_code}, .stage = ..., .options = {include_source = ...;}});
     */
    // clang-format off
    const hyoka::shader::compile_info source =
    {
        .shader =
        {
            .language    = hyoka::shader::lang::glsl,
            .source_code = shader
        },
        .stage                             = hyoka::shader::stage::graphics::fragment,
        .vulkan_version                    = {1, 3, 0},
        .spirv_version                     = {1, 6, 0},
        .compatibility                     = hyoka::shader::profile::none,
        .preprocessor_defines              = preprocessor_defines,  // [4-bis] Preprocessor '#define' to add. Pass {} if none are needed.
        .additional_resources              = resource_group,        // [4-ter] Shaders to use to parse the '#include' directives. Pass {} if none are needed.
        .options                           =
        {
            .dialect_version                   = {},   // Use the default dialect version. For GLSL, this is ignored if #version is provided.
            .messages                          = {},   // Enable default messages only
            .force_default_version_and_profile = {},   // Don't force anything (it's not a good idea in most cases anyway).
            .forward_compatible                = {},   // Don't make it forward-compatible. It's not useful here.
            .include_source                    = true, // [4-quater] Add a std::string containing the source passed to the compiler to the compiled_shader
            .spirv                             = {},   // Default options
        },
    };
    // clang-format on

    /* [5]
     * Result of the compilation.
     */
    const auto compiled_shader = hyoka::shader::compile(source);

    /* [6]
     * Display some information about what was done.
     * If nothing gets displayed, this means something broke, so please open an issue at https://github.com/Erellu/fubuki/issues
     */
    if(compiled_shader.has_value())
    {
        // Print the source code
        std::cout << "Source GLSL:\n"
                  << compiled_shader->source.value_or("<Empty>") << "\n--------------------------------------------------\n"
                  << "Preprocessed GLSL:\n"
                  << compiled_shader->preprocessed_source.value_or("<Empty>") << "\n--------------------------------------------------\n"
                  << "Compiled SPIR-V:\n";
        for(const std::uint32_t word : compiled_shader->spirv)
        {
            // Print as correctly formatted hexa
            std::cout << "0x" << std::setfill('0') << std::setw(sizeof(std::uint32_t) * 2) << std::hex << word << ", ";
        }

        std::cout << "\n--------------------------------------------------\n";
    }
    else
    {
        std::cout << "Hmmmmmmmm, please consider opening an issue at https://github.com/Erellu/fubuki/issues. This isn't normal.\n Error: "
                  << compiled_shader.error();
    }

    return 0;
}
