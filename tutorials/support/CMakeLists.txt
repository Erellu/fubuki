cmake_minimum_required(VERSION 3.23)
project(fubuki_tutorial_support LANGUAGES CXX)

#------------------------------------------------------------------------------

fubuki_add_library(NAME tutorial_support
                   PUBLIC_DEPENDENCIES "fuyu" "io"
                   PRIVATE_DEPENDENCIES ""
                   HEADERS "app.hpp"
                           "error.hpp"
                           "export.hpp"
                           "resources.hpp"
                           "setup.hpp"
                   SOURCES "app.cpp"
                   PUBLIC_LINK ""
                   PRIVATE_LINK ""
                   SYSTEM_PUBLIC_LINK ""
                   SYSTEM_PRIVATE_LINK ""
                   )
