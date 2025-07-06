cmake_minimum_required(VERSION 3.23)
project(fubuki_io_platform LANGUAGES CXX)

#------------------------------------------------------------------------------

if(WIN32)
    set(fubuki_io_platform_headers
        "win32/display.hpp"
        "win32/error.hpp"
        "win32/event_loop.hpp"
        "win32/keyboard.hpp"
        "win32/mouse.hpp"
        "win32/screen.hpp"
        "win32/send_event.hpp"
        "win32/window.hpp"
        "win32/window_data.hpp"
        "win32/window_registry.hpp"

        "win32/detail/send_event.hpp"
        )

    set(fubuki_io_platform_sources
        "win32/event_loop.cpp"
        "win32/screen.cpp"
        "win32/window.cpp"
        "win32/window_data.cpp"
        "win32/window_registry.cpp"
        )
    set(fubuki_io_platform_public_system_link_libs "")
    set(fubuki_io_platform_public_link_libs "")
    set(fubuki_io_platform_private_system_link_libs "")
    set(fubuki_io_platform_private_link_libs "")

elseif(UNIX)

    include(cmake/code_gen.cmake)
    fubuki_generate_wayland_headers("." ${CMAKE_CURRENT_LIST_DIR}/linux/wayland)

    add_library(fubuki_io_platform_wayland_generated
                STATIC
                "linux/wayland/generated/xdg/shell-client-protocol.h"
                "linux/wayland/generated/xdg/shell-protocol.c"
                "linux/wayland/generated/zxdg/decoration-client-protocol.h"
                "linux/wayland/generated/zxdg/decoration-protocol.c"
            )

    set(fubuki_io_platform_headers
        "linux/display.hpp"
        "linux/fd_timer.hpp"
        "linux/file_descriptor.hpp"
        "linux/keyboard.hpp"
        "linux/mouse.hpp"
        "linux/scoped_mmap.hpp"
        "linux/screen.hpp"
        "linux/send_event.hpp"
        "linux/window.hpp"
        "linux/window_registry.hpp"

        "linux/detail/evdev.hpp"

        "linux/event/mouse_state.hpp"
        "linux/event/loop.hpp"
        "linux/event/stop_loop.hpp"

        "linux/wayland/display.hpp"
        "linux/wayland/display_global.hpp"
        "linux/wayland/decoration.hpp"
        "linux/wayland/error.hpp"
        "linux/wayland/event_loop.hpp"
        "linux/wayland/fixed.hpp"
        "linux/wayland/interface.hpp"
        "linux/wayland/keyboard.hpp"
        "linux/wayland/pointer.hpp"
        "linux/wayland/registry.hpp"
        "linux/wayland/screen.hpp"
        "linux/wayland/seat.hpp"
        "linux/wayland/shm_buffer.hpp"
        "linux/wayland/shm_pool.hpp"
        "linux/wayland/surface.hpp"
        "linux/wayland/window.hpp"

        "linux/wayland/window_parts.hpp"

        "linux/wayland/display/global_handles.hpp"
        "linux/wayland/display/input.hpp"
        "linux/wayland/display/input_state.hpp"
        "linux/wayland/display/properties.hpp"

        "linux/wayland/xdg/interface.hpp"
        "linux/wayland/xdg/surface.hpp"
        "linux/wayland/xdg/toplevel.hpp"
        "linux/wayland/xdg/wm_base.hpp"

        "linux/wayland/zxdg/decoration.hpp"
        "linux/wayland/zxdg/interface.hpp"

        "linux/xkb/context.hpp"
        "linux/xkb/keymap.hpp"
        "linux/xkb/key_code.hpp"
        "linux/xkb/state.hpp"

        "linux/xlib/display.hpp"
        "linux/xlib/display_lock.hpp"
        "linux/xlib/error.hpp"
        "linux/xlib/event_loop.hpp"
        "linux/xlib/keyboard.hpp"
        "linux/xlib/mouse.hpp"
        "linux/xlib/screen.hpp"
        "linux/xlib/unique_ptr.hpp"
        "linux/xlib/window.hpp"

        "linux/xlib/detail/code.hpp"
        "linux/xlib/detail/keyboard.hpp"

        "linux/xlib/xrandr/crtc.hpp"
        "linux/xlib/xrandr/output.hpp"
        "linux/xlib/xrandr/screen_config.hpp"
        "linux/xlib/xrandr/screen_resource.hpp"
        )


    set(fubuki_io_platform_sources
        "linux/fd_timer.cpp"
        "linux/file_descriptor.cpp"
        "linux/scoped_mmap.cpp"
        "linux/screen.cpp"
        "linux/window_registry.cpp"

        "linux/event/loop.cpp"
        "linux/event/stop_loop.cpp"

        "linux/wayland/display.cpp"
        "linux/wayland/event_loop.cpp"
        "linux/wayland/keyboard.cpp"
        "linux/wayland/pointer.cpp"
        "linux/wayland/registry.cpp"
        "linux/wayland/shm_buffer.cpp"
        "linux/wayland/shm_pool.cpp"
        "linux/wayland/screen.cpp"
        "linux/wayland/seat.cpp"
        "linux/wayland/surface.cpp"
        "linux/wayland/window.cpp"
        "linux/wayland/window_parts.cpp"

        "linux/wayland/xdg/surface.cpp"
        "linux/wayland/xdg/toplevel.cpp"
        "linux/wayland/xdg/wm_base.cpp"

        "linux/wayland/zxdg/decoration.cpp"

        "linux/xkb/context.cpp"
        "linux/xkb/keymap.cpp"
        "linux/xkb/state.cpp"

        "linux/xlib/display.cpp"
        "linux/xlib/display_lock.cpp"
        "linux/xlib/event_loop.cpp"
        "linux/xlib/keyboard.cpp"
        "linux/xlib/mouse.cpp"
        "linux/xlib/screen.cpp"
        "linux/xlib/window.cpp"
    )

    set(fubuki_io_platform_public_system_link_libs "")
    set(fubuki_io_platform_public_link_libs "")
    set(fubuki_io_platform_private_system_link_libs "fubuki_io_platform_wayland_generated")
    set(fubuki_io_platform_private_link_libs X11::X11 X11::Xrandr X11::xkbcommon ${wayland_client_LIBRARIES})

else()
    message(FATAL_ERROR "Platform not supported.")
endif()

#------------------------------------------------------------------------------

fubuki_add_library(NAME io_platform
                      PUBLIC_DEPENDENCIES "core"
                      PRIVATE_DEPENDENCIES ""
                      HEADERS "current_platform.hpp"
                              "display_info.hpp"
                              "error.hpp"
                              "keyboard_key.hpp"
                              "mouse_button.hpp"
                              "mouse_state.hpp"
                              "screen_properties.hpp"

                              "event/dispatcher.hpp"
                              "event/events.hpp"
                              "event/handler.hpp"
                              "event/key.hpp"
                              "event/loop_routines.hpp"
                              "event/mouse.hpp"
                              "event/queue.hpp"
                              "event/source.hpp"
                              "event/send_error.hpp"
                              "event/user.hpp"
                              "event/window.hpp"

                              "linux/error.hpp"
                              "linux/wayland/code.hpp"
                              "linux/xlib/code.hpp"

                              "views/display.hpp"

                              "win32/code.hpp"

                              "${fubuki_io_platform_headers}"
                      SOURCES "event/queue.cpp"

                              "${fubuki_io_platform_sources}"
                      PUBLIC_LINK "${fubuki_io_platform_public_link_libs}"
                      PRIVATE_LINK "${fubuki_io_platform_private_link_libs}"
                      SYSTEM_PUBLIC_LINK "${fubuki_io_platform_public_system_link_libs}"
                      SYSTEM_PRIVATE_LINK "${fubuki_io_platform_private_system_link_libs}"
                  )

if(UNIX)

    include(CheckFunctionExists)
    check_function_exists(memfd_create FUBUKI_HAS_MEMFD_CREATE)
    if (FUBUKI_HAS_MEMFD_CREATE)
        target_compile_definitions(fubuki_io_platform PRIVATE FUBUKI_HAS_MEMFD_CREATE)
    endif()

endif()
