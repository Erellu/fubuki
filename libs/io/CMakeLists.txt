cmake_minimum_required(VERSION 3.23)
project(fubuki_io LANGUAGES CXX)

if(NOT ${FUBUKI_NO_IO})

    #------------------------------------------------------------------------------

    add_subdirectory(platform)

    #------------------------------------------------------------------------------

    fubuki_add_library(NAME io
                          PUBLIC_DEPENDENCIES "core" "io_platform"
                          PRIVATE_DEPENDENCIES
                          HEADERS "display.cpp"
                                  "event.hpp"
                                  "keyboard.hpp"
                                  "mouse.hpp"
                                  "screen.hpp"
                                  "window.hpp"

                                  "event/dispatcher.hpp"
                                  "event/handler.hpp"
                                  "event/loop.hpp"
                                  "event/queue.hpp"
                                  "event/send.hpp"

                                  "information/display.hpp"
                                  "information/window.hpp"

                          SOURCES "display.hpp"
                                  "keyboard.cpp"
                                  "mouse.cpp"
                                  "screen.cpp"
                                  "window.cpp"

                                  "event/loop.cpp"
                                  "event/send.cpp"
                          PUBLIC_LINK ""
                          PRIVATE_LINK ""
                          SYSTEM_PUBLIC_LINK ""
                          SYSTEM_PRIVATE_LINK ""
                      )
endif() # if(NOT ${FUBUKI_NO_IO})
