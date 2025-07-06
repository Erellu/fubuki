cmake_minimum_required(VERSION 3.24)
project(fubuki_hyoka LANGUAGES CXX)

#------------------------------------------------------------------------------
# glslang

set(GLSLANG_LIBRARIES GenericCodeGen
                      glslang
                      glslang-default-resource-limits
                      MachineIndependent
                      OSDependent
                      SPIRV
                      SPIRV-Tools-opt
                  )

#------------------------------------------------------------------------------
# Library

fubuki_add_library(NAME hyoka
                      PUBLIC_DEPENDENCIES "core"
                      PRIVATE_DEPENDENCIES ""
                      HEADERS "shader/compile.hpp"
                      SOURCES "shader/compile.cpp"
                      PUBLIC_LINK "${Vulkan_LIBRARIES}"
                      PRIVATE_LINK ""
                      SYSTEM_PUBLIC_LINK ""
                      SYSTEM_PRIVATE_LINK "${GLSLANG_LIBRARIES}"
                  )

# glslang options
target_compile_definitions(fubuki_hyoka PRIVATE ENABLE_OPT=1 ENABLE_HLSL=1)

add_dependencies(fubuki_hyoka
                 "glslang"
                 "glslang-default-resource-limits"
                 "MachineIndependent"
                 "OSDependent"
                 "SPIRV"
                 "SPIRV-Tools-opt"
             )
