project(fubuki_dependencies LANGUAGES CXX)

#------------------------------------------------------------------------------
# Previous state of options

if(DEFINED BUILD_SHARED_LIBS)
    set(old_BUILD_SHARED_LIBS ${BUILD_SHARED_LIBS})
endif()

if(DEFINED BUILD_TESTING)
    set(old_BUILD_TESTING ${BUILD_TESTING})
endif()

# Disable all warnings for dependencies
if(MINGW OR CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -w")
elseif(MSVC)
    # Avoid D9025 command line warning
    string(REPLACE "/W3" "/w" CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS})
endif()

#------------------------------------------------------------------------------
# GLM
# GLM does not provide a full CMake install when added as dependency.
# To be precise, it only installs when ${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR}.
# So we do it here for them, because we expose their headers (hence need that)

add_subdirectory(glm)

# No need to expose these to the user
unset(GLM_BUILD_INSTALL CACHE)
unset(GLM_BUILD_LIBRARY CACHE)
unset(GLM_BUILD_TESTS CACHE)

include(CPack)
include(CMakePackageConfigHelpers)

# GLM_VERSION does not get exported to parent direction, so we do it manually here again

file(READ "glm/glm/detail/setup.hpp" GLM_SETUP_FILE)
string(REGEX MATCH "#define[ ]+GLM_VERSION_MAJOR[ ]+([0-9]+)" _ ${GLM_SETUP_FILE})
set(GLM_VERSION_MAJOR "${CMAKE_MATCH_1}")
string(REGEX MATCH "#define[ ]+GLM_VERSION_MINOR[ ]+([0-9]+)" _ ${GLM_SETUP_FILE})
set(GLM_VERSION_MINOR "${CMAKE_MATCH_1}")
string(REGEX MATCH "#define[ ]+GLM_VERSION_PATCH[ ]+([0-9]+)" _ ${GLM_SETUP_FILE})
set(GLM_VERSION_PATCH "${CMAKE_MATCH_1}")
string(REGEX MATCH "#define[ ]+GLM_VERSION_REVISION[ ]+([0-9]+)" _ ${GLM_SETUP_FILE})
set(GLM_VERSION_REVISION "${CMAKE_MATCH_1}")

set(GLM_VERSION ${GLM_VERSION_MAJOR}.${GLM_VERSION_MINOR}.${GLM_VERSION_PATCH}.${GLM_VERSION_REVISION})

install(
    DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/glm/glm/"
    DESTINATION "${${FUBUKI_PROJECT}_INCLUDES_INSTALL_DIR}/${FUBUKI_PROJECT}/dependencies/glm"
    PATTERN "CMakeLists.txt" EXCLUDE
)

install(TARGETS glm-header-only glm EXPORT glm)

install(EXPORT glm
        FILE glmConfig.cmake
        DESTINATION "${${FUBUKI_PROJECT}_INSTALL_LIBRARY_DESTINATION}/cmake/${FUBUKI_PROJECT}/dependencies/glm"
        NAMESPACE glm::)

write_basic_package_version_file(
    "glmConfigVersion.cmake"
    VERSION ${GLM_VERSION}
    COMPATIBILITY AnyNewerVersion
)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/glmConfigVersion.cmake
        DESTINATION ${${FUBUKI_PROJECT}_INSTALL_LIBRARY_DESTINATION}/cmake/${FUBUKI_PROJECT}/dependencies/glm)

#------------------------------------------------------------------------------
# GLSLANG
# We have no reason to install glslang as we link with static libraries and do not expose its headers.
# We also hide glslang options, as we do not want to allow the user to set some special options

set(update_glslang_sources ${FUBUKI_REFRESH_GLSLANG_SOURCES})

if(NOT DEFINED FUBUKI_GLSLANG_SOURCES)
    set(update_glslang_sources TRUE)
    set(FUBUKI_REFRESH_GLSLANG_SOURCES OFF CACHE BOOL "Keep current glslang external sources. Setting this option to ON will re-run glslang's update_sources.py.")
    mark_as_advanced(FORCE FUBUKI_GLSLANG_SOURCES)
endif()

if(update_glslang_sources)
    message(STATUS "Updating glslang sources...")
    find_package(Git REQUIRED) # glslang scripts perform git command, that must be accessible to the shell

    set(glslang_update_src_result 1)

    if(${FUBUKI_VERBOSE_BUILD})
        execute_process(
            WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/glslang
            COMMAND ${Python3_EXECUTABLE} update_glslang_sources.py
            RESULT_VARIABLE glslang_update_src_result
        )
        if(glslang_update_src_result AND NOT glslang_update_src_result EQUAL 0)
            message(FATAL_ERROR "Failed to generate update glslang sources. See the previous messages for more detail.")
        endif()

    else()
        # Redirect output to a CMake variable to avoid having stuff printed to stdout
        set(SILENCE "")
        execute_process(
            WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/glslang
            COMMAND ${Python3_EXECUTABLE} update_glslang_sources.py
            OUTPUT_VARIABLE SILENCE
            RESULT_VARIABLE glslang_update_src_result
        )

        # Except when the call failed, in which case it's cool to get logs
        if(glslang_update_src_result AND NOT glslang_update_src_result EQUAL 0)
            message(FATAL_ERROR "Failed to generate update glslang sources. Log: ${SILENCE}")
        endif()
    endif()

    unset(glslang_update_src_result)

    message(STATUS "Done.")
endif()

set(FUBUKI_REFRESH_GLSLANG_SOURCES OFF CACHE BOOL "Keep current glslang external sources. Setting this option to ON will re-run glslang's update_sources.py.")

# glslang is too painful to have as a shared library.
# fubuki::render_tools is a shared library making the interface anyway
set(ALLOW_EXTERNAL_SPIRV_TOOLS OFF)
set(BUILD_EXTERNAL ON)
set(BUILD_GMOCK OFF)
set(BUILD_SHARED_LIBS OFF)
set(BUILD_TESTING OFF)
set(SKIP_GLSLANG_INSTALL ON)
set(ENABLE_SPVREMAPPER OFF)
set(ENABLE_GLSLANG_BINARIES OFF)
set(ENABLE_GLSLANG_JS OFF)
set(ENABLE_GLSLANG_WEBMIN OFF)
set(ENABLE_GLSLANG_WEBMIN_DEVEL OFF)
set(ENABLE_EMSCRIPTEN_SINGLE_FILE OFF)
set(ENABLE_EMSCRIPTEN_ENVIRONMENT_NODE OFF)
set(ENABLE_HLSL ON)
set(ENABLE_RTTI OFF)
set(ENABLE_EXCEPTIONS OFF)
set(ENABLE_OPT ON)

if(MINGW OR (CMAKE_SYSTEM_NAME STREQUAL "Darwin" AND ${CMAKE_CXX_COMPILER_ID} MATCHES "GNU"))
    set(ENABLE_PCH OFF)
else()
    set(ENABLE_PCH ON)
endif()

set(ENABLE_CTEST OFF) # We don't need to build glslang tests
set(USE_CCACHE OFF)

# SPIR-V tools options
set(SPIRV_ALLOW_TIMERS ON)
set(SKIP_SPIRV_TOOLS_INSTALL ON)
set(SPIRV_BUILD_COMPRESSION OFF)
set(SPIRV_BUILD_FUZZER OFF)
set(SPIRV_BUILD_LIBFUZZER_TARGETS OFF)
set(SPIRV_WERROR OFF)
set(SPIRV_WARN_EVERYTHING OFF)
set(SPIRV_COLOR_TERMINAL ON)
set(SPIRV_LOG_DEBUG OFF)
set(ENABLE_EXCEPTIONS_ON_MSVC ON)
set(SPIRV_TOOLS_BUILD_STATIC ON)
set(SPIRV_SKIP_EXECUTABLES ON)
set(SPIRV_SKIP_TESTS ON)
set(SPIRV_CHECK_CONTEXT ON)
set(SPIRV_TOOLS_INSTALL_EMACS_HELPERS OFF)
set(SPIRV_LIB_FUZZING_ENGINE_LINK_OPTIONS "")
set(BUILD_WERROR OFF)

add_subdirectory(glslang)

# No need to expose this to the user
unset(SPIRV_LIB_FUZZING_ENGINE_LINK_OPTIONS CACHE)
unset(SPIRV_SKIP_TESTS CACHE)

# Taken from https://github.com/KhronosGroup/Vulkan-ExtensionLayer/blob/master/CMakeLists.txt
# Available under the terms of the Apache 2.0 license
# See https://github.com/KhronosGroup/Vulkan-ExtensionLayer/blob/master/LICENSE
# for detailed information.

set(GLSLANG_LIBRARIES GenericCodeGen
                      glslang
                      glslang-default-resource-limits
                      MachineIndependent
                      OSDependent
                      SPIRV)

# Circular dependencies exist between glslang static libs, add them all as link dependencies for each other
# See https://github.com/KhronosGroup/Vulkan-ExtensionLayer/blob/master/CMakeLists.txt
foreach(GLSLANG_LIBRARY ${GLSLANG_LIBRARIES})
    set_target_properties(${GLSLANG_LIBRARY}
                          PROPERTIES INTERFACE_LINK_LIBRARIES
                                     "${GLSLANG_LIBRARIES}")
endforeach()

#------------------------------------------------------------------------------
# GTEST
# We only build googletest if tests are build

if(DEFINED gtest_force_shared_crt)
    set(old_gtest_force_shared_crt ${gtest_force_shared_crt})
endif()

if(DEFINED gtest_hide_internal_symbols)
    set(old_gtest_hide_internal_symbols ${gtest_hide_internal_symbols})
endif()

if(DEFINED INSTALL_GTEST)
    set(old_INSTALL_GTEST ${INSTALL_GTEST})
endif()

if(FUBUKI_BUILD_TESTS)
    set(gtest_force_shared_crt ON)
    set(gtest_hide_internal_symbols ON)
    set(INSTALL_GTEST OFF)
    set(GTEST_HAS_ABSL OFF)

    add_subdirectory(googletest)
endif()

#------------------------------------------------------------------------------
# Restore old options for the current scope

if(DEFINED old_BUILD_SHARED_LIBS)
    set(BUILD_SHARED_LIBS ${old_BUILD_SHARED_LIBS})
endif()

if(DEFINED old_BUILD_TESTING)
    set(BUILD_TESTING ${old_BUILD_TESTING})
endif()

if(DEFINED old_gtest_force_shared_crt)
    set(gtest_force_shared_crt ${old_gtest_force_shared_crt})
endif()

if(DEFINED old_gtest_hide_internal_symbols)
    set(gtest_hide_internal_symbols ${old_gtest_hide_internal_symbols})
endif()

if(DEFINED old_INSTALL_GTEST)
    set(INSTALL_GTEST ${old_INSTALL_GTEST})
endif()
