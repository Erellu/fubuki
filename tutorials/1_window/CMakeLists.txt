cmake_minimum_required(VERSION 3.23)
project(fubuki_tutorial_01_window LANGUAGES CXX)

#------------------------------------------------------------------------------

fubuki_add_executable(NAME tutorial_01_window
                      PUBLIC_DEPENDENCIES "io"
                      PRIVATE_DEPENDENCIES ""
                      HEADERS ""
                      SOURCES "tutorial_1.cpp"
                      PUBLIC_LINK ""
                      PRIVATE_LINK ""
                      SYSTEM_PUBLIC_LINK ""
                      SYSTEM_PRIVATE_LINK ""
                  )
