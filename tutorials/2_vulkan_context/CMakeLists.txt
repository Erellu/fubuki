cmake_minimum_required(VERSION 3.23)
project(fubuki_tutorial_02_vulkan_context LANGUAGES CXX)

#------------------------------------------------------------------------------

fubuki_add_executable(NAME tutorial_02_vulkan_context
                      PUBLIC_DEPENDENCIES "fuyu" "io"
                      PRIVATE_DEPENDENCIES "tutorial_support"
                      HEADERS ""
                      SOURCES "tutorial_2.cpp"
                      PUBLIC_LINK ""
                      PRIVATE_LINK ""
                      SYSTEM_PUBLIC_LINK ""
                      SYSTEM_PRIVATE_LINK ""
                  )
