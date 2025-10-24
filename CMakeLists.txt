cmake_minimum_required(VERSION 3.26)
include(cmake/warning_setup.cmake)
include(cmake/macros.cmake)

file(READ ${CMAKE_CURRENT_LIST_DIR}/cmake/macros.cmake FUBUKI_CMAKE_MACROS)
file(READ ${CMAKE_CURRENT_LIST_DIR}/cmake/warning_setup.cmake FUBUKI_SETUP_WARNING_LIST)

#------------------------------------------------------------------------------
# CMake options

set(CMAKE_BUILD_TYPE ${CMAKE_BUILD_TYPE} CACHE STRING "Build type (Debug, Release, RelWithDebInfo, MinSizeRel)")
set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug;Release;RelWithDebInfo;MinSizeRel")

if(NOT CMAKE_BUILD_TYPE STREQUAL "Debug" AND NOT CMAKE_BUILD_TYPE STREQUAL "Release" AND NOT CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo" AND NOT CMAKE_BUILD_TYPE STREQUAL "MinSizeRel" )
    message(FATAL_ERROR "Invalid value for CMAKE_BUILD_TYPE: '${CMAKE_BUILD_TYPE}' (required one of 'Debug', 'Release', 'RelWithDebInfo', 'MinSizeRel')")
endif()

option(FUBUKI_BUILD_TESTS "Build Fubuki unit tests." OFF)
option(FUBUKI_BUILD_TUTORIALS "Build Fubuki tutorials." ON)
option(FUBUKI_INSTALL "Install Fubuki to directory set in CMAKE_INSTALL_PREFIX." ON)
option(FUBUKI_NO_IO "Do not build fubuki::io. This also disables tutorials and tests that depend on this target." OFF)
option(FUBUKI_SKIP_GENERATION "Skip code generations processes. Put it on OFF when changing the Vulkan SDK version." ON)
option(FUBUKI_VERBOSE_BUILD "Display detailed messages when configuring Fubuki." OFF)

mark_as_advanced(FUBUKI_SKIP_GENERATION)

if(${FUBUKI_NO_IO} AND ${FUBUKI_BUILD_TUTORIALS})
    set(FUBUKI_BUILD_TUTORIALS OFF)
    message(WARNING "FUBUKI_BUILD_TUTORIALS is not compatible with FUBUKI_NO_IO: the tutorials depend on fubuki::io."
                     " They won't be built. To silence this warning, set FUBUKI_BUILD_TUTORIALS to OFF")
endif()

if(${FUBUKI_NO_IO} AND ${FUBUKI_BUILD_TESTS})
    set(FUBUKI_BUILD_TUTORIALS OFF)
    message(WARNING "Some tests that depend on fubuki::io won't be build. To silence this warning, set FUBUKI_BUILD_TESTS to OFF.")
endif()

#------------------------------------------------------------------------------
# Project

project(fubuki
        LANGUAGES CXX C
        VERSION 1.0.0
        DESCRIPTION "Fubuki is a low-level general-purpose cross-platform engine written in C++23 for and with Vulkan."
        HOMEPAGE_URL "https://github.com/Erellu/fubuki"
)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

fubuki_setup_warning_list()

#------------------------------------------------------------------------------
# Dependencies

include(CMakePackageConfigHelpers)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_LIST_DIR}/cmake/modules")

if(PROJECT_IS_TOP_LEVEL)
    find_package(Vulkan REQUIRED)
endif()

if (NOT Vulkan_FOUND)
    message(FATAL_ERROR
            "Could not find Vulkan! "
            "Can you confirm you downloaded the SDK? https://www.lunarg.com/vulkan-sdk/"
            "\nNOTE: if Fubuki is a subproject (added via add_subdirectory), you must perform your own find_package(Vulkan)."
            "This is to enable the user (you) to provide hints to CMake."
        )
endif()

if(UNIX)
    find_package(X11 REQUIRED)
    find_package(wayland_client 1.10.0 REQUIRED)
endif()

#------------------------------------------------------------------------------
# Code generation

# Always required for glslang's update_sources.py
find_package(Python3 COMPONENTS Interpreter REQUIRED)

if(NOT ${FUBUKI_SKIP_GENERATION})

    # Only required for code generation
    set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_LIST_DIR}/cmake/modules")
    find_package(clang-format)

    if(CLANG_FORMAT_FOUND)
        if(${FUBUKI_VERBOSE_BUILD})
            message("clang-format executable: ${CLANG_FORMAT_EXECUTABLE}")
            message("clang-format version: ${CLANG_FORMAT_VERSION}")
        endif()
    else()
        message(FATAL_ERROR "clang-format executable not found. Please export the path to the executable to your PATH env. variable")
    endif()

    cmake_path(GET Vulkan_INCLUDE_DIRS PARENT_PATH VULKAN_SDK_PATH)

    set(FUBUKI_CODEGEN_STDOUT "")
    execute_process(
        WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
        COMMAND ${Python3_EXECUTABLE} py/code_generation/main.py
                --license ${CMAKE_CURRENT_LIST_DIR}/LICENSE.txt
                --libs ${CMAKE_CURRENT_LIST_DIR}/libs
                --tests ${CMAKE_CURRENT_LIST_DIR}/tests
                --templates ${CMAKE_CURRENT_LIST_DIR}/py/code_generation/templates
                --cache ${CMAKE_CURRENT_LIST_DIR}/py/code_generation/cache
                --vulkan-sdk "${VULKAN_SDK_PATH}"
                --clang-format-exe ${CLANG_FORMAT_EXECUTABLE}
                --clang-format-file ${CMAKE_CURRENT_LIST_DIR}/.clang-format

        OUTPUT_VARIABLE FUBUKI_CODEGEN_STDOUT
        RESULT_VARIABLE FUBUKI_CODE_GEN_SUCCESS
    )

    if(${FUBUKI_VERBOSE_BUILD})
        message(STATUS "${FUBUKI_CODEGEN_STDOUT}")
    endif()

    if(FUBUKI_CODE_GEN_SUCCESS AND NOT FUBUKI_CODE_GEN_SUCCESS EQUAL 0)
        message(FATAL_ERROR "Code generation failed with code ${FUBUKI_CODE_GEN_SUCCESS}. Output:\n${FUBUKI_CODEGEN_STDOUT}")
    endif()
else()
    message(STATUS "Skipping code generation. To enable it, set FUBUKI_SKIP_GENERATION to OFF.")
endif()

#------------------------------------------------------------------------------
# Targets

fubuki_setup(
    NAME "fubuki"
    INSTALLATION ${FUBUKI_INSTALL}
)

add_subdirectory(dependencies)
add_subdirectory(libs)

if(FUBUKI_BUILD_TUTORIALS)
     add_subdirectory(tutorials)
endif()

if(FUBUKI_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

fubuki_finalise()
