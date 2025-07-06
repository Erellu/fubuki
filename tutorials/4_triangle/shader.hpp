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

#ifndef FUBUKI_TUTORIAL_04_SHADER_HPP
#define FUBUKI_TUTORIAL_04_SHADER_HPP

#include <string_view>

#include <hyoka/shader/compile.hpp>

namespace tutorial::triangle::shader
{

namespace glsl
{

inline constexpr std::string_view vertex = R"(#version 450

layout (location = 0) in vec3 in_pos;
layout (location = 1) in vec3 in_colour;

layout(location = 0) out vec4 out_colour;

out gl_PerVertex
{
    vec4 gl_Position;
};

void main()
{
    out_colour  = vec4(in_colour, 1.0);
    gl_Position = vec4(in_pos, 1.0);
}
)";

inline constexpr std::string_view fragment = R"(#version 450

layout(location = 0) in vec4 in_colour;

layout(location = 0) out vec4 out_colour;

void main()
{
    out_colour = in_colour;
}
)";

} // namespace glsl

struct compiled
{
    std::vector<std::uint32_t> vertex   = {};
    std::vector<std::uint32_t> fragment = {};

    [[nodiscard]] static std::expected<compiled, fubuki::hyoka::shader::compile_error> make()
    {
        constexpr fubuki::version_number vk    = {1, 3, 0};
        constexpr fubuki::version_number spirv = {1, 5, 0};

        namespace hyoka = fubuki::hyoka;

        auto vertex_spirv = fubuki::hyoka::shader::compile({
            .shader         = {hyoka::shader::lang::glsl, std::string{glsl::vertex}},
            .stage          = hyoka::shader::stage::graphics::vertex,
            .vulkan_version = vk,
            .spirv_version  = spirv
        });

        if(not vertex_spirv)
        {
            return std::unexpected{vertex_spirv.error()};
        }

        auto fragment_spirv = fubuki::hyoka::shader::compile({
            .shader         = {hyoka::shader::lang::glsl, std::string{glsl::fragment}},
            .stage          = hyoka::shader::stage::graphics::fragment,
            .vulkan_version = vk,
            .spirv_version  = spirv
        });

        if(not fragment_spirv)
        {
            return std::unexpected{fragment_spirv.error()};
        }

        return compiled{
            std::move(vertex_spirv)->spirv,
            std::move(fragment_spirv)->spirv,
        };
    }
};

} // namespace tutorial::triangle::shader

#endif // FUBUKI_TUTORIAL_04_SHADER_HPP
