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

#ifndef FUBUKI_MATHS_VEC1_HPP
#define FUBUKI_MATHS_VEC1_HPP

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

#include <glm/gtc/vec1.hpp>

#if defined(__clang__)
    #pragma clang diagnostic pop
#elif defined(_MSC_VER)
    #pragma warning(pop)
#endif

namespace fubuki
{

/**
 * @brief 1-component vector of boolean.
 */
using bvec1 = glm::bvec1;

/**
 * @brief 1-component vector of boolean.
 */
using highp_bvec1 = glm::highp_bvec1;

/**
 * @brief 1-component vector of boolean.
 */
using lowp_bvec1 = glm::lowp_bvec1;

/**
 * @brief 1-component vector of boolean.
 */
using mediump_bvec1 = glm::mediump_bvec1;

//-----------------------------------------------------------------------------

/**
 * @brief 1-component vector of single-precision floating-point numbers.
 */
using vec1 = glm::vec1;

/**
 * @brief 1-component vector of single-precision floating-point numbers using high precision arithmetic in terms of ULPs.
 */
using highp_vec1 = glm::highp_vec1;

/**
 * @brief 1-component vector of single-precision floating-point numbers using medium precision arithmetic in terms of ULPs.
 */
using mediump_vec1 = glm::mediump_vec1;

/**
 * @brief 1-component vector of single-precision floating-point numbers using low precision arithmetic in terms of ULPs.
 */
using lowp_vec1 = glm::lowp_vec1;

//-----------------------------------------------------------------------------

/**
 * @brief 1-component vector of double-precision floating-point numbers.
 */
using dvec1 = glm::dvec1;

/**
 * @brief 1-component vector of double-precision floating-point numbers using high precision arithmetic in terms of ULPs.
 */
using highp_dvec1 = glm::highp_dvec1;

/**
 * @brief 1-component vector of double-precision floating-point numbers using medium precision arithmetic in terms of ULPs.
 */
using mediump_dvec1 = glm::mediump_dvec1;

/**
 * @brief 1-component vector of double-precision floating-point numbers using low precision arithmetic in terms of ULPs.
 */
using lowp_dvec1 = glm::lowp_dvec1;

//-----------------------------------------------------------------------------

/**
 * @brief 1-component vector of signed integer numbers.
 */
using ivec1 = glm::ivec1;

/**
 * @brief 1-component vector of 64-bit signed integers.
 */
using i64vec1 = glm::i64vec1;

/**
 * @brief 1-component vector of 32-bit signed integers.
 */
using i32vec1 = glm::i32vec1;

/**
 * @brief 1-component vector of 16-bit signed integers.
 */
using i16vec1 = glm::i16vec1;

/**
 * @brief 1-component vector of 8-bit signed integers.
 */
using i8vec1 = glm::i8vec1;

//-----------------------------------------------------------------------------

/**
 * @brief 1-component vector of t unsigned integers.
 */
using uvec1 = glm::uvec1;

/**
 * @brief 1-component vector of 64-bit unsigned integers.
 */
using u64vec1 = glm::u64vec1;

/**
 * @brief 1-component vector of 32-bit unsigned integers.
 */
using u32vec1 = glm::u32vec1;

/**
 * @brief 1-component vector of 16-bit unsigned integers.
 */
using u16vec1 = glm::u16vec1;

/**
 * @brief 1-component vector of 8-bit unsigned integers.
 */
using u8vec1 = glm::u8vec1;

//-----------------------------------------------------------------------------

/**
 * @brief 1-component vector of size-type integers.
 */
using size1 = glm::vec<1, std::size_t>;

} // namespace fubuki

#endif // FUBUKI_MATHS_VEC1_HPP
