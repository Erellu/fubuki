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

#ifndef FUBUKI_MATHS_MAT4X4_HPP
#define FUBUKI_MATHS_MAT4X4_HPP

#include <cstddef>

// Disable all glm warnings
#if defined(__clang__)
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Weverything"
#elif defined(__GNUC__)
    #pragma GCC system_header // No equivalent to the above for GCC, but this does the trick...
#elif defined(_MSC_VER)
    #pragma warning(push, 0)
#endif

#include <glm/ext/matrix_int4x4.hpp>
#include <glm/ext/matrix_int4x4_sized.hpp>
#include <glm/ext/matrix_uint4x4.hpp>
#include <glm/ext/matrix_uint4x4_sized.hpp>
#include <glm/mat4x4.hpp>

#if defined(__clang__)
    #pragma clang diagnostic pop
#elif defined(_MSC_VER)
    #pragma warning(pop)
#endif

namespace fubuki
{

/**
 * @brief 4 columns of 2 components matrix of single-precision floating-point numbers.
 * @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.1.6 Matrices</a>
 */
using mat4x4 = glm::mat4x4;

/**
 * @brief 4 columns of 2 components matrix of single-precision floating-point numbers using high precision arithmetic in terms.
 * @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.1.6 Matrices</a>
 * @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.7.2 Precision Qualifier</a>
 */
using highp_mat4x4 = glm::highp_mat4x4;

/**
 * @brief 4 columns of 2 components matrix of single-precision floating-point numbers using medium precision arithmetic in terms.
 * @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.1.6 Matrices</a>
 * @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.7.2 Precision Qualifier</a>
 */
using mediump_mat4x4 = glm::mediump_mat4x4;

/**
 * @brief 4 columns of 2 components matrix of single-precision floating-point numbers using low precision arithmetic in terms.
 * @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.1.6 Matrices</a>
 * @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.7.2 Precision Qualifier</a>
 */
using lowp_mat4x4 = glm::lowp_mat4x4;

//-----------------------------------------------------------------------------

/**
 * @brief 4 columns of 2 components matrix of double-precision floating-point numbers.
 * @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.1.6 Matrices</a>
 */
using dmat4x4 = glm::dmat4x4;

/**
 * @brief 4 columns of 2 components matrix of double-precision floating-point numbers using high precision arithmetic in terms.
 * @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.1.6 Matrices</a>
 * @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.7.2 Precision Qualifier</a>
 */
using highp_dmat4x4 = glm::highp_dmat4x4;

/**
 * @brief 4 columns of 2 components matrix of double-precision floating-point numbers using medium precision arithmetic in terms.
 * @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.1.6 Matrices</a>
 * @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.7.2 Precision Qualifier</a>
 */
using lowp_dmat4x4 = glm::lowp_dmat4x4;

/**
 * @brief 4 columns of 2 components matrix of double-precision floating-point numbers using medium precision arithmetic in terms.
 * @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.1.6 Matrices</a>
 * @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.7.2 Precision Qualifier</a>
 */
using mediump_dmat4x4 = glm::mediump_dmat4x4;

//-----------------------------------------------------------------------------

/**
 * @brief Signed integer 4x4 matrix.
 */
using imat4x4 = glm::imat4x4;

/**
 * @brief 64-bit signed integer 4x4 matrix.
 */
using i64mat4x4 = glm::i64mat4x4;

/**
 * @brief 32-bit signed integer 4x4 matrix.
 */
using i32mat4x4 = glm::i32mat4x4;

/**
 * @brief 16-bit signed integer 4x4 matrix.
 */
using i16mat4x4 = glm::i16mat4x4;

/**
 * @brief 8-bit signed integer 4x4 matrix.
 */
using i8mat4x4 = glm::i8mat4x4;

//-----------------------------------------------------------------------------

/**
 * @brief Unsigned integer 4x4 matrix.
 */
using umat4x4 = glm::umat4x4;

/**
 * @brief 64-bit unsigned integer 4x4 matrix.
 */
using u64mat4x4 = glm::u64mat4x4;

/**
 * @brief 32-bit unsigned integer 4x4 matrix.
 */
using u32mat4x4 = glm::u32mat4x4;

/**
 * @brief 16-bit unsigned integer 4x4 matrix.
 */
using u16mat4x4 = glm::u16mat4x4;

/**
 * @brief 8-bit unsigned integer 4x4 matrix.
 */
using u8mat4x4 = glm::u8mat4x4;

//-----------------------------------------------------------------------------

/**
 * @brief Size type 4x4 matrix.
 */
using size4x4 = glm::mat<4, 4, std::size_t>;

} // namespace fubuki

#endif // FUBUKI_MATHS_MAT4X4_HPP
