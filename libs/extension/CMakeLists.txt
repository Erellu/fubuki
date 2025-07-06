cmake_minimum_required(VERSION 3.23)
project(fubuki_extension LANGUAGES CXX)

#------------------------------------------------------------------------------

file(GLOB fubuki_extension_headers "*.hpp")
file(GLOB fubuki_extension_sources "*.cpp")
file(GLOB fubuki_extension_functions_headers "functions/*.hpp")
file(GLOB fubuki_extension_functions_sources "functions/*.cpp")

#------------------------------------------------------------------------------

fubuki_add_library(NAME extension
                      PUBLIC_DEPENDENCIES "core"
                      PRIVATE_DEPENDENCIES ""
                      HEADERS
                      "${fubuki_extension_functions_headers}"
                      "${fubuki_extension_headers}"
                      SOURCES
                      "${fubuki_extension_functions_sources}"
                      "${fubuki_extension_sources}"
                      PUBLIC_LINK    "${Vulkan_LIBRARIES}"
                      PRIVATE_LINK   ""
                      SYSTEM_PUBLIC_LINK ""
                      SYSTEM_PRIVATE_LINK ""
                    )

