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

#ifndef FUBUKI_MATHS_VEC2_HPP
#define FUBUKI_MATHS_VEC2_HPP

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

#include <glm/vec2.hpp>

#if defined(__clang__)
    #pragma clang diagnostic pop
#elif defined(_MSC_VER)
    #pragma warning(pop)
#endif

namespace fubuki
{

/**
 * @brief 2-components vector of boolean.
 */
using bvec2 = glm::bvec2;

/**
 * @brief 2-components vector of boolean.
 */
using highp_bvec2 = glm::highp_bvec2;

/**
 * @brief 2-components vector of boolean.
 */
using lowp_bvec2 = glm::lowp_bvec2;

/**
 * @brief 2-components vector of boolean.
 */
using mediump_bvec2 = glm::mediump_bvec2;

//-----------------------------------------------------------------------------

/**
 * @brief 2-components vector of single-precision floating-point numbers.
 */
using vec2 = glm::vec2;

/**
 * @brief 2-components vector of single-precision floating-point numbers using high precision arithmetic in terms of ULPs.
 */
using highp_vec2 = glm::highp_vec2;

/**
 * @brief 2-components vector of single-precision floating-point numbers using medium precision arithmetic in terms of ULPs.
 */
using mediump_vec2 = glm::mediump_vec2;

/**
 * @brief 2-components vector of single-precision floating-point numbers using low precision arithmetic in terms of ULPs.
 */
using lowp_vec2 = glm::lowp_vec2;

//-----------------------------------------------------------------------------

/**
 * @brief 2-components vector of double-precision floating-point numbers.
 */
using dvec2 = glm::dvec2;

/**
 * @brief 2-components vector of double-precision floating-point numbers using high precision arithmetic in terms of ULPs.
 */
using highp_dvec2 = glm::highp_dvec2;

/**
 * @brief 2-components vector of double-precision floating-point numbers using medium precision arithmetic in terms of ULPs.
 */
using mediump_dvec2 = glm::mediump_dvec2;

/**
 * @brief 2-components vector of double-precision floating-point numbers using low precision arithmetic in terms of ULPs.
 */
using lowp_dvec2 = glm::lowp_dvec2;

//-----------------------------------------------------------------------------

/**
 * @brief 2-components vector of signed integer numbers.
 */
using ivec2 = glm::ivec2;

/**
 * @brief 2-components vector of 64-bit signed integers.
 */
using i64vec2 = glm::i64vec2;

/**
 * @brief 2-components vector of 32-bit signed integers.
 */
using i32vec2 = glm::i32vec2;

/**
 * @brief 2-components vector of 16-bit signed integers.
 */
using i16vec2 = glm::i16vec2;

/**
 * @brief 2-components vector of 8-bit signed integers.
 */
using i8vec2 = glm::i8vec2;

//-----------------------------------------------------------------------------

/**
 * @brief 2-components vector of t unsigned integers.
 */
using uvec2 = glm::uvec2;

/**
 * @brief 2-components vector of 64-bit unsigned integers.
 */
using u64vec2 = glm::u64vec2;

/**
 * @brief 2-components vector of 32-bit unsigned integers.
 */
using u32vec2 = glm::u32vec2;

/**
 * @brief 2-components vector of 16-bit unsigned integers.
 */
using u16vec2 = glm::u16vec2;

/**
 * @brief 2-components vector of 8-bit unsigned integers.
 */
using u8vec2 = glm::u8vec2;

//-----------------------------------------------------------------------------

/**
 * @brief 2-components vector of size-type integers.
 */
using size2 = glm::vec<2, std::size_t>;

} // namespace fubuki

#endif // FUBUKI_MATHS_VEC4_HPP
