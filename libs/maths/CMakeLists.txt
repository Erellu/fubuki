cmake_minimum_required(VERSION 3.23)
project(fubuki_maths LANGUAGES CXX)

#------------------------------------------------------------------------------

fubuki_add_library(NAME maths
                      PUBLIC_DEPENDENCIES ""
                      PRIVATE_DEPENDENCIES ""
                      HEADERS "detail/mock.hpp"

                              "mat4x4.hpp"
                              "mat4x3.hpp"
                              "mat4x2.hpp"

                              "vec1.hpp"
                              "vec2.hpp"
                              "vec3.hpp"
                              "vec4.hpp"

                      SOURCES "detail/mock.cpp"
                      PUBLIC_LINK ""
                      PRIVATE_LINK ""
                      SYSTEM_PUBLIC_LINK "glm" # Disable warnings from GLM
                      SYSTEM_PRIVATE_LINK ""
                  )
