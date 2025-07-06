# https://github.com/rpavlik/cmake-modules/blob/main/FindWayland.cmake

# - Try to Find Wayland
#
# Copyright 2015, Vlad Zagorodniy
#
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#
# SPDX-License-Identifier: BSL-1.0
#
# Will be defined:
# WAYLAND_CLIENT_FOUND
# WAYLAND_CLIENT_INCLUDE_DIR
# WAYLAND_CLIENT_LIBRARIES
#

find_package(PkgConfig)
pkg_check_modules(PKG_WAYLAND_CLIENT REQUIRED wayland-client)

if (NOT PKG_WAYLAND_CLIENT_FOUND)
    message(FATAL_ERROR "No wayland-client")
endif(NOT PKG_WAYLAND_CLIENT_FOUND)

find_path(wayland_client_INCLUDE_DIR wayland-client.h ${PKG_WAYLAND_CLIENT_INCLUDE_DIRS})
find_library(wayland_client_LIBRARIES NAMES wayland-client PATHS ${PKG_WAYLAND_CLIENT_LIBRARY_DIRS})
set(wayland_client_FOUND TRUE)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(wayland_client DEFAULT_MSG wayland_client_INCLUDE_DIR wayland_client_LIBRARIES)
mark_as_advanced(wayland_client_INCLUDE_DIR wayland_client_LIBRARIES)
