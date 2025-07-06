cmake_minimum_required(VERSION 3.23)
project(fubuki_tutorial_03_compiling_shaders LANGUAGES CXX)

#------------------------------------------------------------------------------

fubuki_add_executable(NAME tutorial_03_compiling_shaders
                      PUBLIC_DEPENDENCIES "hyoka"
                      PRIVATE_DEPENDENCIES ""
                      HEADERS ""
                      SOURCES "tutorial_3.cpp"
                      PUBLIC_LINK ""
                      PRIVATE_LINK ""
                      SYSTEM_PUBLIC_LINK ""
                      SYSTEM_PRIVATE_LINK ""
                  )
