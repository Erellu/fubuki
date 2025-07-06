cmake_minimum_required(VERSION 3.23)
project(fubuki_tutorial_04_triangle LANGUAGES CXX)

#------------------------------------------------------------------------------

fubuki_add_executable(NAME tutorial_04_triangle
                      PUBLIC_DEPENDENCIES "fuyu" "io" "hyoka"
                      PRIVATE_DEPENDENCIES "tutorial_support"
                      HEADERS "event_handling.hpp"
                              "resources.hpp"
                              "shader.hpp"
                              "triangle.hpp"
                      SOURCES "tutorial_4.cpp"
                      PUBLIC_LINK ""
                      PRIVATE_LINK ""
                      SYSTEM_PUBLIC_LINK ""
                      SYSTEM_PRIVATE_LINK ""
                  )
