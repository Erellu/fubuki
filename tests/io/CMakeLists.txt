cmake_minimum_required(VERSION 3.23)
project(fubuki_io_test LANGUAGES CXX)

#------------------------------------------------------------------------------

fubuki_add_test(NAME io_test
                   PUBLIC_DEPENDENCIES "core" "io"
                   PRIVATE_DEPENDENCIES ""
                   HEADERS ""
                   SOURCES "io_test.cpp"
                           "profile.cpp"
                   PUBLIC_LINK ""
                   PRIVATE_LINK ""
                   SYSTEM_PUBLIC_LINK ""
                   SYSTEM_PRIVATE_LINK ""
                  )
