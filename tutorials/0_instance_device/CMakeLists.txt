cmake_minimum_required(VERSION 3.23)
project(fubuki_tutorial_00_instance_device LANGUAGES CXX)

#------------------------------------------------------------------------------

fubuki_add_executable(NAME tutorial_00_instance_device
                      PUBLIC_DEPENDENCIES "fuyu"
                      PRIVATE_DEPENDENCIES ""
                      HEADERS ""
                      SOURCES "tutorial_0.cpp"
                      PUBLIC_LINK "${Vulkan_LIBRARIES}"
                      PRIVATE_LINK ""
                      SYSTEM_PUBLIC_LINK ""
                      SYSTEM_PRIVATE_LINK ""
                  )
