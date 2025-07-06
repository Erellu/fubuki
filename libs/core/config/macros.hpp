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

#ifndef FUBUKI_CORE_CONFIG_MACROS_HPP
#define FUBUKI_CORE_CONFIG_MACROS_HPP

/********************************************************************************/
/*                              FUNCTION ATTRIBUTES                             */
/********************************************************************************/

// Since C++17, implementations are *required* to ignore attributes it does not understand.
// But this triggers a warning with both GCC and clang, so we use the good'old macro trick.
// Note that in theory, GCC, clang and MSVC support empty [[]] attributes (see https://godbolt.org/z/ra7Eo9n85)
// Though I could not find where this is allowed in the ISO Standard.
// So once again, we stick to good'old macros for these attributes.

#if defined(__clang__) // Clang
    #define FUBUKI_SEMI_PURE [[gnu::pure]]
    #define FUBUKI_TRUE_PURE [[gnu::const]]
#elif defined(__GNUC__) // GCC, MinGW
    #define FUBUKI_SEMI_PURE [[gnu::pure]]
    #define FUBUKI_TRUE_PURE [[gnu::const]]
#elif defined(_MSC_VER) // MSVC
    #define FUBUKI_SEMI_PURE
    #define FUBUKI_TRUE_PURE
#else // Other
    #define FUBUKI_SEMI_PURE
    #define FUBUKI_TRUE_PURE
#endif

/********************************************************************************/
/*                                ASSERTION TOGGLE                              */
/********************************************************************************/

#ifndef FUBUKI_ENABLE_ASSERTION
    #if defined(FUBUKI_DEBUG_BUILD)
        #define FUBUKI_ENABLE_ASSERTION
    #endif // defined(FUBUKI_DEBUG_BUILD)
#endif

/********************************************************************************/
/*                          EXPORT / IMPORT / VISIBILITY                        */
/********************************************************************************/

#if defined(_MSC_VER) || defined(WIN64) || defined(_WIN64) || defined(__WIN64__) || defined(WIN32) || defined(_WIN32) || defined(__WIN32__) \
    || defined(__NT__)
    #define FUBUKI_DECL_EXPORT __declspec(dllexport)
    #define FUBUKI_DECL_IMPORT __declspec(dllimport)
#else
    #define FUBUKI_DECL_EXPORT __attribute__((visibility("default")))
    #define FUBUKI_DECL_IMPORT __attribute__((visibility("default")))
#endif

// CMake macro fubuki_add_target adds a private definition, corresponding to the upper-case name of the target
// plus _COMPILE (so no point into looking for where FUBUKI_CORE_COMPILE & co. are #defined).

//------------------------------------------------------------------------------
// core

#if defined(FUBUKI_CORE_COMPILE)
    #define FUBUKI_CORE_API FUBUKI_DECL_EXPORT
#else
    #define FUBUKI_CORE_API FUBUKI_DECL_IMPORT
#endif

//------------------------------------------------------------------------------
// fuyu

#if defined(FUBUKI_FUYU_COMPILE)
    #define FUBUKI_FUYU_API FUBUKI_DECL_EXPORT
#else
    #define FUBUKI_FUYU_API FUBUKI_DECL_IMPORT
#endif

//------------------------------------------------------------------------------
// extension

#if defined(FUBUKI_EXTENSION_COMPILE)
    #define FUBUKI_EXTENSION_API FUBUKI_DECL_EXPORT
#else
    #define FUBUKI_EXTENSION_API FUBUKI_DECL_IMPORT
#endif

//------------------------------------------------------------------------------
// io / io_platform

#if defined(FUBUKI_IO_PLATFORM_COMPILE)
    #define FUBUKI_IO_PLATFORM_API FUBUKI_DECL_EXPORT
#else
    #define FUBUKI_IO_PLATFORM_API FUBUKI_DECL_IMPORT
#endif

#if defined(FUBUKI_IO_COMPILE)
    #define FUBUKI_IO_API FUBUKI_DECL_EXPORT
#else
    #define FUBUKI_IO_API FUBUKI_DECL_IMPORT
#endif

//------------------------------------------------------------------------------
// maths

#if defined(FUBUKI_MATHS_COMPILE)
    #define FUBUKI_MATHS_API FUBUKI_DECL_EXPORT
#else
    #define FUBUKI_MATHS_API FUBUKI_DECL_IMPORT
#endif

//------------------------------------------------------------------------------
// hyoka

#if defined(FUBUKI_HYOKA_COMPILE)
    #define FUBUKI_HYOKA_API FUBUKI_DECL_EXPORT
#else
    #define FUBUKI_HYOKA_API FUBUKI_DECL_IMPORT
#endif

//------------------------------------------------------------------------------

#endif // FUBUKI_CORE_CONFIG_MACROS_HPP
