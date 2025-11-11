#------------------------------------------------------------------------------
# Links against a library as if it were a SYSTEM library.
# From https://stackoverflow.com/a/52136398
# License: CC BY-SA 4.0
########################################
# param: target - Targets to link
#
# option: PUBLIC | PRIVATE | INTEFACE - Scope of the link
function(fubuki_target_link_libraries_system target)
  set(options PRIVATE PUBLIC INTERFACE)
  cmake_parse_arguments(TLLS "${options}" "" "" ${ARGN})
  foreach(op ${options})
    if(TLLS_${op})
      set(scope ${op})
    endif()
  endforeach(op)
  set(libs ${TLLS_UNPARSED_ARGUMENTS})

  foreach(lib ${libs})
    get_target_property(lib_include_dirs ${lib} INTERFACE_INCLUDE_DIRECTORIES)
    if(lib_include_dirs)
      if(scope)
        target_include_directories(${target} SYSTEM ${scope} ${lib_include_dirs})
      else()
        target_include_directories(${target} SYSTEM PRIVATE ${lib_include_dirs})
      endif()
    else()
        if(${FUBUKI_VERBOSE_BUILD})
            message("Warning: ${lib} doesn't set INTERFACE_INCLUDE_DIRECTORIES. No include_directories set.")
        endif()
    endif()
    if(scope)
      target_link_libraries(${target} ${scope} ${lib})
    else()
      target_link_libraries(${target} ${lib})
    endif()
  endforeach()
endfunction(fubuki_target_link_libraries_system)

#------------------------------------------------------------------------------
# Installs DLLs of CMake targets linked to a target.
# Requires a call to fubuki_setup.
########################################
# param: TARGET - The target name.
# param: LIBS  - The libraries to install.

function(fubuki_install_dlls_of)

    cmake_parse_arguments(fubuki_install_dlls_of
                          "" # Optional
                          "TARGET" # Single values
                          "LIBS" # Multiple values
                          ${ARGN})

    if(FUBUKI_VERBOSE_BUILD)
        message(STATUS "[Fubuki]: installing deps of ${fubuki_install_dlls_of_TARGET} (${fubuki_install_dlls_of_LIBS})")
    endif()

    foreach(lib IN ITEMS ${fubuki_install_dlls_of_LIBS})
        get_target_property(lib_type ${lib} TYPE)
        if(NOT ${lib_type} STREQUAL "STATIC_LIBRARY")
            if(FUBUKI_VERBOSE_BUILD)

                if(FUBUKI_VERBOSE_BUILD)
                    message(STATUS "[Fubuki:] Dependency '${lib}' that links with ${fubuki_install_dlls_of_TARGET} WILL be installed.")
                endif()

                add_custom_command(
                    TARGET ${fubuki_install_dlls_of_TARGET} POST_BUILD
                    COMMAND ${CMAKE_COMMAND} -E echo "[Fubuki]: ${fubuki_install_dlls_of_TARGET} installation: copy_if_different $<TARGET_FILE:${lib}> $<TARGET_FILE_DIR:${fubuki_install_dlls_of_TARGET}>"
                    COMMAND_EXPAND_LISTS
                )

                add_custom_command(
                    TARGET ${fubuki_install_dlls_of_TARGET} POST_BUILD
                    COMMAND ${CMAKE_COMMAND} -E echo "[Fubuki]: ${fubuki_install_dlls_of_TARGET} installation: copy $<TARGET_FILE:${lib}> ${${FUBUKI_PROJECT}_INSTALL_RUNTIME_DESTINATION}"
                    COMMAND_EXPAND_LISTS
                )
            endif()

            add_custom_command(TARGET ${fubuki_install_dlls_of_TARGET} POST_BUILD
                               COMMAND ${CMAKE_COMMAND} -E copy_if_different
                                       $<TARGET_FILE:${lib}>
                                       $<TARGET_FILE_DIR:${fubuki_install_dlls_of_TARGET}>)

            add_custom_command(TARGET ${fubuki_install_dlls_of_TARGET} POST_BUILD
                               COMMAND ${CMAKE_COMMAND} -E copy
                                       $<TARGET_FILE:${lib}>
                                       ${${FUBUKI_PROJECT}_INSTALL_RUNTIME_DESTINATION})
        else()
            if(FUBUKI_VERBOSE_BUILD)
                message(STATUS "[Fubuki:] Dependency '${lib}' that links with ${fubuki_install_dlls_of_TARGET} is a static library and WILL NOT be installed.")
            endif()
        endif()

    endforeach()

endfunction()

#------------------------------------------------------------------------------
# Issues a message if an identifier exists in the current scope.
########################################
# param: NAMES - The names to check, as a list of strings
# param: TYPE  - The type of the message, directlty forwarded to CMake's message().

macro(fubuki_warn_if_defined)
  cmake_parse_arguments(fubuki_warn_if_defined
                        "" # Optional
                        "TYPE" # Single values
                        "NAMES" # Multiple values
                        ${ARGN})

    foreach(NAME ${fubuki_warn_if_defined_NAMES})
        if(DEFINED ${NAME})
            message(${fubuki_warn_if_defined_TYPE} "The identifier '${NAME}' is already defined in the current scope and may be overriden.")
        endif()
    endforeach()
endmacro()

#------------------------------------------------------------------------------
# Sets up variables used for the building process (install directory, compiler, etc)
# WARNING: calling this function twice with different arguments will result in libraries being
# considered as from different projects, hence installed at different places and in a different export set.
# You should usually call it only once from the main CMakeLists.txt.
# If you need to call it twice (for subprojects for example), call fubuki_finalise() first.
########################################
# param: NAME         - Name of the current project, as STRING.
# param: INSTALLATION - Indicates if the project must be installed.
#
# output: sets the following variables, in which ${NAME} is the value of the NAME argument fubuki_setup:
#    Variables (constants):
#       FUBUKI_SETUP_PROJECT_LIST            - List of the project names.
#                                              The project name is appended at the front.
#                                              Modifying this value outside fubuki macros may result in expected behaviour.
#       ${NAME}_NAMESPACE                    - Namespace of the exported targets.
#
#       ${NAME}_INSTALL_PREFIX               - Where the installation is performed.
#       ${NAME}_INSTALL_RUNTIME_DESTINATION  - Where the binaries are installed.
#       ${NAME}_INSTALL_ARCHIVE_DESTINATION  - Where the libraries are installed.
#       ${NAME}_INSTALL_LIBRARY_DESTINATION  - Where the libraries are installed (also).
#       ${NAME}_INSTALL_INCLUDES_DESTINATION - Where the headers are installed.
#       ${NAME}_INCLUDES_INSTALL_DIR         - Where the headers are installed.
#       ${NAME}_GENERATED_DIR                - Where the CMake-generated files are put.
#       ${NAME}_OUTPUT_DIR                   - Where the binaries (.dll/.so, .exe, etc.) are put.
#
#       ${NAME}_VERSION_CONFIG               - Name of the CMake version config file.
#       ${NAME}_PROJECT_CONFIG               - Name of the CMake config file.
#
#       ${NAME}_TARGETS_EXPORT_NAME          - Export set for the targets added using fubuki_add_library.
#       ${NAME}_EXPORT_NAME                  - Name of CMake Targets file.
#       ${NAME}_CONFIG_INSTALL_DIR           - Where to install cmake "Targets" files.
#
#    Properties:
#        ${NAME}_components                  - Global property to which target added through fubuki_add_library are added.
#
# These names are RESERVED and **MUST NOT** be changed manually (read-only access is fine).

macro(fubuki_setup)

    #----------------------------------------------------------------
    # Arguments

    set(fubuki_setup_optional_value_args_identifiers)

    set(fubuki_setup_single_value_args_identifiers
        NAME
        INSTALLATION
    )

    set(fubuki_setup_multi_value_args_identifiers)

    cmake_parse_arguments(fubuki_setup
                          "${fubuki_setup_optional_value_args_identifiers}"
                          "${fubuki_setup_single_value_args_identifiers}"
                          "${fubuki_setup_multi_value_args_identifiers}"
                          ${ARGN})

    # See https://github.com/schweitzer/modern-cmake-tutorial
    # https://github.com/IRCAD/modern-cmake-tutorial
    # From https://github.com/schweitzer/modern-cmake-tutorial/blob/master/library/CMakeLists.txt

    #----------------------------------------------------------------
    # Sanity checks

    if("${fubuki_setup_NAME}" STREQUAL "")
        message(FATAL_ERROR "Project name must not be empty.")
    endif()

    if(NOT "${fubuki_setup_INSTALLATION}" STREQUAL "ON" AND NOT "${fubuki_setup_INSTALLATION}" STREQUAL "OFF")
        message(FATAL_ERROR "Invalid argument for INSTALLATION. Expected ON or OFF")
    endif()

    fubuki_warn_if_defined(NAMES "FUBUKI_PROJECT" TYPE AUTHOR_WARNING)

    # Copy to this variable name for readability
    set(FUBUKI_PROJECT "${fubuki_setup_NAME}")

    if(NOT DEFINED FUBUKI_SETUP_PROJECT_LIST)
        set(FUBUKI_SETUP_PROJECT_LIST ${FUBUKI_PROJECT})
    else()
        if(${FUBUKI_PROJECT} IN_LIST FUBUKI_SETUP_PROJECT_LIST)
            message(FATAL_ERROR "fubuki_setup has already been called for project " ${FUBUKI_PROJECT} ".")
        endif()
        list(PREPEND FUBUKI_SETUP_PROJECT_LIST ${FUBUKI_PROJECT})
    endif()

    # No check for ${FUBUKI_PROJECT}_components, since it's allowed to inherit that value for compatibility purposes
    fubuki_warn_if_defined(NAMES "${FUBUKI_PROJECT}_NAMESPACE"
                                 "${FUBUKI_PROJECT}_INSTALL_RUNTIME_DESTINATION"
                                 "${FUBUKI_PROJECT}_INSTALL_ARCHIVE_DESTINATION"
                                 "${FUBUKI_PROJECT}_INSTALL_INCLUDES_DESTINATION"
                                 "${FUBUKI_PROJECT}_INCLUDES_INSTALL_DIR"
                                 "${FUBUKI_PROJECT}_GENERATED_DIR"
                                 "${FUBUKI_PROJECT}_VERSION_CONFIG"
                                 "${FUBUKI_PROJECT}_PROJECT_CONFIG"
                                 "${FUBUKI_PROJECT}_TARGETS_EXPORT_NAME"
                                 "${FUBUKI_PROJECT}_EXPORT_NAME"
                                 "${FUBUKI_PROJECT}_CONFIG_INSTALL_DIR"
                           TYPE AUTHOR_WARNING)

    #----------------------------------------------------------------
    # General setup

    set(FUBUKI_PROJECT "${fubuki_setup_NAME}")             # Project name
    set(${FUBUKI_PROJECT}_NAMESPACE "${FUBUKI_PROJECT}::") # Namespace of the exported targets

    set(${FUBUKI_PROJECT}_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")
    set(${FUBUKI_PROJECT}_INSTALL_RUNTIME_DESTINATION "${CMAKE_INSTALL_PREFIX}/bin")      # Where the binaries are installed
    set(${FUBUKI_PROJECT}_INSTALL_ARCHIVE_DESTINATION "${CMAKE_INSTALL_PREFIX}/lib")      # Where the libraries are installed
    set(${FUBUKI_PROJECT}_INSTALL_LIBRARY_DESTINATION "${CMAKE_INSTALL_PREFIX}/lib")      # Same
    set(${FUBUKI_PROJECT}_INSTALL_INCLUDES_DESTINATION "${CMAKE_INSTALL_PREFIX}/include") # Where the headers are installed
    set(${FUBUKI_PROJECT}_GENERATED_DIR "${CMAKE_CURRENT_BINARY_DIR}/generated")  # Where the CMake-generated files are put
    set(${FUBUKI_PROJECT}_OUTPUT_DIR "${CMAKE_BINARY_DIR}/bin")

    # Windows compatibility, CMake wants UNIX-style paths
    string(REPLACE "\\" "/" ${FUBUKI_PROJECT}_INSTALL_PREFIX               "${${FUBUKI_PROJECT}_INSTALL_PREFIX}")
    string(REPLACE "\\" "/" ${FUBUKI_PROJECT}_INSTALL_RUNTIME_DESTINATION  "${${FUBUKI_PROJECT}_INSTALL_RUNTIME_DESTINATION}")
    string(REPLACE "\\" "/" ${FUBUKI_PROJECT}_INSTALL_ARCHIVE_DESTINATION  "${${FUBUKI_PROJECT}_INSTALL_ARCHIVE_DESTINATION}")
    string(REPLACE "\\" "/" ${FUBUKI_PROJECT}_INSTALL_LIBRARY_DESTINATION  "${${FUBUKI_PROJECT}_INSTALL_LIBRARY_DESTINATION}")
    string(REPLACE "\\" "/" ${FUBUKI_PROJECT}_INSTALL_INCLUDES_DESTINATION "${${FUBUKI_PROJECT}_INSTALL_INCLUDES_DESTINATION}")
    string(REPLACE "\\" "/" ${FUBUKI_PROJECT}_GENERATED_DIR                "${${FUBUKI_PROJECT}_GENERATED_DIR}")
    string(REPLACE "\\" "/" ${FUBUKI_PROJECT}_OUTPUT_DIR                   "${${FUBUKI_PROJECT}_OUTPUT_DIR}")

    set(${FUBUKI_PROJECT}_INCLUDES_INSTALL_DIR "${${FUBUKI_PROJECT}_INSTALL_INCLUDES_DESTINATION}")                              # Where the headers are installed
    set(${FUBUKI_PROJECT}_VERSION_CONFIG "${${FUBUKI_PROJECT}_GENERATED_DIR}/${FUBUKI_PROJECT}-config-version.cmake") # Name of the CMake version config file.
    set(${FUBUKI_PROJECT}_PROJECT_CONFIG "${${FUBUKI_PROJECT}_GENERATED_DIR}/${FUBUKI_PROJECT}-config.cmake")         # Name of the CMake config file.

    set(${FUBUKI_PROJECT}_TARGETS_EXPORT_NAME "${FUBUKI_PROJECT}_targets")  # Export set for the targets added using fubuki_add_library.
    set(${FUBUKI_PROJECT}_EXPORT_NAME "${FUBUKI_PROJECT}-targets")          # Name of CMake Targets file
    set(${FUBUKI_PROJECT}_CONFIG_INSTALL_DIR "lib/cmake/${FUBUKI_PROJECT}") # Where to install cmake "Targets" files

    get_property(current_${FUBUKI_PROJECT}_components GLOBAL PROPERTY ${FUBUKI_PROJECT}_components)

    if("${current_${FUBUKI_PROJECT}_components}" STREQUAL "")
        set_property(GLOBAL PROPERTY ${FUBUKI_PROJECT}_components "") # Don't override user contents in this context
    endif()

    if("${fubuki_setup_INSTALLATION}" STREQUAL "ON")
        set(${FUBUKI_PROJECT}_INSTALLATION TRUE)
    else()
        set(${FUBUKI_PROJECT}_INSTALLATION FALSE)
    endif()

    unset(current_${FUBUKI_PROJECT}_components)

    #----------------------------------------------------------------
    # Compiler

    if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")

        if(MINGW)
            get_filename_component(Mingw_Path ${CMAKE_CXX_COMPILER} PATH)
            set(CMAKE_INSTALL_SYSTEM_RUNTIME_LIBS
                ${Mingw_Path}/libgcc_s_seh-1.dll ${Mingw_Path}/libstdc++-6.dll ${Mingw_Path}/libwinpthread-1.dll
            )
        endif()

    elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")

        if(MINGW)

            get_filename_component(Mingw_Path ${CMAKE_CXX_COMPILER} PATH)
            set(CMAKE_INSTALL_SYSTEM_RUNTIME_LIBS
                ${Mingw_Path}/libc++.dll ${Mingw_Path}/libunwind.dll ${Mingw_Path}/libwinpthread-1.dll
            )
        endif()

    endif()

    if(${${FUBUKI_PROJECT}_INSTALLATION})
        include(InstallRequiredSystemLibraries)
    endif()

    #----------------------------------------------------------------
    # Flags

    set(FUBUKI_SETUP TRUE)

    #----------------------------------------------------------------
    # Cleanup
    unset(FUBUKI_PROJECT)

endmacro() # fubuki_setup

#------------------------------------------------------------------------------
# Finalises the build process for the current project.
########################################
#
# output: Removes the last item added to FUBUKI_SETUP_PROJECT_LIST (by the last call of fubuki_setup).
# Other variables set by fubuki_setup are left untouched.

macro(fubuki_finalise)

    if(NOT FUBUKI_SETUP_PROJECT_LIST)
        message(FATAL_ERROR "fubuki_setup(...) has no active project.")
    endif()
    fubuki_warn_if_defined(NAMES "FUBUKI_PROJECT" TYPE AUTHOR_WARNING)

    list(GET FUBUKI_SETUP_PROJECT_LIST 0 FUBUKI_PROJECT)

    #----------------------------------------------------------------
    # Compiler runtime

    if(MINGW AND WIN32)
        file(COPY ${CMAKE_INSTALL_SYSTEM_RUNTIME_LIBS} DESTINATION ${${FUBUKI_PROJECT}_OUTPUT_DIR})
    endif()

    #----------------------------------------------------------------
    # Display all installed targets for project

    get_property(FUBUKI_PROJECT_components_value GLOBAL PROPERTY ${FUBUKI_PROJECT}_components)
    if("${FUBUKI_PROJECT}_components_value}" STREQUAL "")
        message(FATAL_ERROR "No targets to export. Something went wrong :(")
    elseif(FUBUKI_VERBOSE_BUILD)
        message(STATUS "[Fubuki]: The following components (available in property ${FUBUKI_PROJECT}_components) will be exported: ${FUBUKI_PROJECT_components_value}")
    endif()

    #----------------------------------------------------------------
    # Configure file

    # See
    # https://github.com/schweitzer/modern-cmake-tutorial
    # https://github.com/IRCAD/modern-cmake-tutorial
    # From https://github.com/schweitzer/modern-cmake-tutorial/blob/master/library/CMakeLists.txt

    if(${${FUBUKI_PROJECT}_INSTALLATION})
        write_basic_package_version_file(
            "${${FUBUKI_PROJECT}_VERSION_CONFIG}"
            VERSION ${${FUBUKI_PROJECT}_VERSION}
            COMPATIBILITY SameMajorVersion
        )

        # Configure the config.cmake.in
        configure_file(
            "${${FUBUKI_PROJECT}_SOURCE_DIR}/cmake/config.cmake.in"
            "${${FUBUKI_PROJECT}_PROJECT_CONFIG}"
            @ONLY
        )

        # Install cmake config files
        install(
            FILES "${${FUBUKI_PROJECT}_PROJECT_CONFIG}" "${${FUBUKI_PROJECT}_VERSION_CONFIG}"
            DESTINATION "${${FUBUKI_PROJECT}_CONFIG_INSTALL_DIR}"
        )

        # Install cmake targets files
        install(
            EXPORT "${${FUBUKI_PROJECT}_TARGETS_EXPORT_NAME}"
            NAMESPACE "${${FUBUKI_PROJECT}_NAMESPACE}"
            DESTINATION "${${FUBUKI_PROJECT}_CONFIG_INSTALL_DIR}"
        )

        # Install compiler-specific runtime libs (required for MinGW)
        if(CMAKE_INSTALL_SYSTEM_RUNTIME_LIBS)
            install(PROGRAMS ${CMAKE_INSTALL_SYSTEM_RUNTIME_LIBS}
                    DESTINATION ${${FUBUKI_PROJECT}_INSTALL_RUNTIME_DESTINATION}
                    COMPONENT System
            )
        endif()
    endif()

    #----------------------------------------------------------------
    # Clear

    list(POP_FRONT FUBUKI_SETUP_PROJECT_LIST)

    unset(FUBUKI_PROJECT)
    unset(FUBUKI_PROJECT_components_value)

endmacro() # fubuki_finalise

#------------------------------------------------------------------------------
# Creates a target from the sources given, links it to the libraries
# given, installs it and updates the target list.
########################################
# param: NAME                 - Name of the library. Prefix "${FUBUKI_PROJECT}_" is appended automatically, in which FUBUKI_PROJECT is the name of the last project registered through fubuki_setup.
#                               EXPORT_NAME property is set to ${NAME}.
# param: TYPE                 - Target type. Either "LIBRARY" or "EXECUTABLE"
# param: PUBLIC_DEPENDENCIES  - Targets that must be build before this one and linked publicly.
# param: PRIVATE_DEPENDENCIES - Targets that must be build before this one and linked privately.
# param: HEADERS              - Library headers.
# param: SOURCES              - Library sources.
# param: PUBLIC_LINK          - Libraries to link publicly.
# param: PRIVATE_LINK         - Libraries to link privately.
# param: SYSTEM_PUBLIC_LINK   - Libraries to link publicly as system headers. Use it to silence warnings in header-only external libraries.
# param: SYSTEM_PRIVATE_LINK  - Libraries to link privately as system headers. Use it to silence warnings in header-only external libraries.
# output: Creates a shared library according to the given information.
# Also handles installation and components updates.
#
# prerequisites: fubuki_setup must have been called before.
#
# side effect: adds the following private definition(s):
#   - (PRIVATE) ${FUBUKI_PROJECT}_TRANSLATION_UNIT
#  -  (PRIVATE) VK_NO_PROTOTYPES
#  -  (PRIVATE) "${current_target_upper}_COMPILE"
macro(fubuki_add_target)

    #----------------------------------------------------------------
    # Sanity checks

    if(NOT FUBUKI_SETUP_PROJECT_LIST)
        message(FATAL_ERROR "fubuki_setup(...) has no active project.")
    endif()

    fubuki_warn_if_defined(NAMES "current_project"
                                 "current_target_upper"
                                 "current_source_dir_relative_path"
                                 "current_source_dirs"
                                 "path_root"
                                 "headers_destination_relative_path"
                                 "stripped_relative_path"
                                 "components"
                                 "public_deps"
                                 "private_deps"
                           TYPE AUTHOR_WARNING)

    #----------------------------------------------------------------
    # Arguments

    set(fubuki_add_target_optional_args_identifiers)

    set(fubuki_add_target_single_value_args_identifiers)

    set(fubuki_add_target_multi_value_args_identifiers
        NAME
        TYPE
        PUBLIC_DEPENDENCIES
        PRIVATE_DEPENDENCIES
        HEADERS
        SOURCES
        PUBLIC_LINK
        PRIVATE_LINK
        SYSTEM_PUBLIC_LINK
        SYSTEM_PRIVATE_LINK
    )

    cmake_parse_arguments(fubuki_target
                          "${fubuki_add_target_optional_args_identifiers}"
                          "${fubuki_add_target_single_value_args_identifiers}"
                          "${fubuki_add_target_multi_value_args_identifiers}"
                          ${ARGN})

    fubuki_warn_if_defined(NAMES "FUBUKI_PROJECT" TYPE AUTHOR_WARNING)

    list(GET FUBUKI_SETUP_PROJECT_LIST 0 FUBUKI_PROJECT)

    #----------------------------------------------------------------
    # Project name

    set(current_project "${fubuki_target_NAME}")
    string(TOUPPER "${FUBUKI_PROJECT}_${current_project}" current_target_upper)

    if(current_project STREQUAL "")
        message(FATAL_ERROR "Cannot configure a project with an empty name.")
    endif()

    if(FUBUKI_VERBOSE_BUILD)
        message(STATUS "[Fubuki]: Configuring ${FUBUKI_PROJECT}::${current_project}...")
    endif()

    #----------------------------------------------------------------
    # Build

    if(fubuki_target_TYPE STREQUAL "LIBRARY")

        add_library(${FUBUKI_PROJECT}_${current_project} SHARED
                    ${fubuki_target_HEADERS}
                    ${fubuki_target_SOURCES}
        )

        set_property(TARGET ${FUBUKI_PROJECT}_${current_project}
                     PROPERTY EXPORT_NAME ${current_project})

        # Note: works because we only build shared libraries
        # We put everything at the same place so that the DLLs don't need to be copied in all directories on Windows

        # See https://stackoverflow.com/a/56514534 (CC BY-SA 4.0)
        if(WIN32)
            set_property(TARGET ${FUBUKI_PROJECT}_${current_project}
                         PROPERTY RUNTIME_OUTPUT_DIRECTORY ${${FUBUKI_PROJECT}_OUTPUT_DIR})
        else()
            set_property(TARGET ${FUBUKI_PROJECT}_${current_project}
                         PROPERTY LIBRARY_OUTPUT_DIRECTORY ${${FUBUKI_PROJECT}_OUTPUT_DIR})
        endif()


    elseif(fubuki_target_TYPE STREQUAL "EXECUTABLE" OR fubuki_target_TYPE STREQUAL "TEST")

        add_executable(${FUBUKI_PROJECT}_${current_project}
                       ${fubuki_target_HEADERS}
                       ${fubuki_target_SOURCES}
        )

        # We put everything at the same place so that the DLLs don't need to be copied in all directories on Windows
        set_property(TARGET ${FUBUKI_PROJECT}_${current_project}
                     PROPERTY RUNTIME_OUTPUT_DIRECTORY ${${FUBUKI_PROJECT}_OUTPUT_DIR})

    else()
        message(FATAL_ERROR "Invalid argument (${fubuki_target_TYPE}) for TYPE. Must be 'LIBRARY' or 'EXECUTABLE' (case-sensitive).")
    endif()

    # Public dependencies (public link dependency)
    if(NOT "${fubuki_target_PUBLIC_DEPENDENCIES}" STREQUAL "")

        string(REPLACE ";" ";" public_deps "${fubuki_target_PUBLIC_DEPENDENCIES}")

        foreach(dependency ${public_deps})
            add_dependencies(${FUBUKI_PROJECT}_${current_project} "${FUBUKI_PROJECT}_${dependency}")
            target_link_libraries(${FUBUKI_PROJECT}_${current_project} PUBLIC "${FUBUKI_PROJECT}_${dependency}")
        endforeach()

        unset(public_deps)

    endif()

    # Private dependencies (private link dependency)
    if(NOT "${fubuki_target_PRIVATE_DEPENDENCIES}" STREQUAL "")

        string(REPLACE ";" ";" private_deps "${fubuki_target_PRIVATE_DEPENDENCIES}")

        foreach(dependency ${private_deps})
            add_dependencies(${FUBUKI_PROJECT}_${current_project} "${FUBUKI_PROJECT}_${dependency}")
            target_link_libraries(${FUBUKI_PROJECT}_${current_project} PRIVATE "${FUBUKI_PROJECT}_${dependency}")
        endforeach()

        unset(private_deps)

    endif()

    # Header locations
    target_include_directories(
        ${FUBUKI_PROJECT}_${current_project}
        PUBLIC $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/libs/>
               $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/dependencies/>
               $<INSTALL_INTERFACE:include>
               $<INSTALL_INTERFACE:include/${FUBUKI_PROJECT}>
               $<INSTALL_INTERFACE:include/${FUBUKI_PROJECT}/dependencies>
    )

    # Compiler-specific
    if(MINGW AND CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        # Allow (very) big object files. This is needed for extension functions
        target_compile_options(${FUBUKI_PROJECT}_${current_project} PRIVATE -Wa,-mbig-obj)
    endif()

    if(fubuki_target_TYPE STREQUAL "TEST" AND CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
        # gtest uses global objects that trigger this warning
        target_compile_options(${FUBUKI_PROJECT}_${current_project} PRIVATE -Wno-global-constructors)
    endif()

    if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
        target_compile_options(${FUBUKI_PROJECT}_${current_project} PRIVATE -pedantic-errors)
    endif()

    if(MSVC)
        target_compile_definitions(${FUBUKI_PROJECT}_${current_project} PRIVATE -DNOMINMAX -DWIN32_LEAN_AND_MEAN)
    endif()

    # Preprocess defines
    target_compile_definitions(${FUBUKI_PROJECT}_${current_project}
                               PUBLIC
                               $<$<CONFIG:Debug>:FUBUKI_DEBUG_BUILD>
                               $<$<CONFIG:Release>:FUBUKI_RELEASE_BUILD>
                               $<$<CONFIG:RelWithDebInfo>:FUBUKI_RELEASE_WITH_DEBUG_INFO_BUILD>
                               $<$<CONFIG:MinSizeRel>:FUBUKI_MIN_SIZE_RELEASE_BUILD>
                             )

    # Export macros (Windows) really on this mechanism, see core/config/macros.hpp
    target_compile_definitions(${FUBUKI_PROJECT}_${current_project} PRIVATE "${current_target_upper}_COMPILE")

    # Fubuki specific
    if("${FUBUKI_PROJECT}" STREQUAL "fubuki")
        # Ensures Fubuki compiles in such conditions
        target_compile_definitions(${FUBUKI_PROJECT}_${current_project} PRIVATE VK_NO_PROTOTYPES)
    endif()

    # Libraries to link against
    target_link_libraries(${FUBUKI_PROJECT}_${current_project} PUBLIC ${fubuki_target_PUBLIC_LINK})
    target_link_libraries(${FUBUKI_PROJECT}_${current_project} PRIVATE ${fubuki_target_PRIVATE_LINK})
    fubuki_target_link_libraries_system(${FUBUKI_PROJECT}_${current_project} PUBLIC ${fubuki_target_SYSTEM_PUBLIC_LINK})
    fubuki_target_link_libraries_system(${FUBUKI_PROJECT}_${current_project} PRIVATE ${fubuki_target_SYSTEM_PRIVATE_LINK})

    if(fubuki_target_TYPE STREQUAL "TEST")
        fubuki_target_link_libraries_system(${FUBUKI_PROJECT}_${current_project} PRIVATE GTest::gtest GTest::gmock)
    endif()

    # Target warnings
    target_compile_options(${FUBUKI_PROJECT}_${current_project} PRIVATE ${FUBUKI_WARNINGS})

    #----------------------------------------------------------------
    # Install

    if(fubuki_target_TYPE STREQUAL "LIBRARY")

        # Get the directory names from project root
        file(RELATIVE_PATH current_source_dir_relative_path ${CMAKE_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR})
        string(REPLACE "/" ";" current_source_dirs ${current_source_dir_relative_path})
        list(GET current_source_dirs 0 path_root)

        # Headers of libs used for demonstration purposes in tutorials are not exposed in the installation
        if("${path_root}" STREQUAL "libs")

            # Install path, same as current directory but in installation directory
            list(POP_FRONT current_source_dirs)
            string(REPLACE ";" "/" stripped_relative_path "${current_source_dirs}")

            set(headers_destination_relative_path "${FUBUKI_PROJECT}/${stripped_relative_path}")
            file(TO_CMAKE_PATH "${headers_destination_relative_path}" headers_destination_relative_path)

            if(FUBUKI_VERBOSE_BUILD)
                message("[Fubuki]:     -- Installing to: ${${FUBUKI_PROJECT}_INCLUDES_INSTALL_DIR}/${headers_destination_relative_path}")
            endif()

            if(${${FUBUKI_PROJECT}_INSTALLATION})
                install(
                    DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/
                    DESTINATION ${${FUBUKI_PROJECT}_INCLUDES_INSTALL_DIR}/${headers_destination_relative_path}
                    FILES_MATCHING
                    PATTERN "*.h"
                    PATTERN "*.hpp"
                    PATTERN "*.hxx"
                    PATTERN "*.cuh"
                    PATTERN "*.cuxx"
                    PATTERN "doxygen/*" EXCLUDE
                )
            endif()

            # Targets update
            get_property(components GLOBAL PROPERTY ${FUBUKI_PROJECT}_components)

            if("${components}" STREQUAL "")
                set_property(GLOBAL PROPERTY ${FUBUKI_PROJECT}_components "${current_project}")
            else()
                set_property(GLOBAL PROPERTY ${FUBUKI_PROJECT}_components "${components};${current_project}")
            endif()
        elseif("${path_root}" STREQUAL "tutorials")
            # Header locations
            target_include_directories(
                ${FUBUKI_PROJECT}_${current_project}
                PUBLIC $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/tutorials/>
            )
        endif()

    endif()

    if(${${FUBUKI_PROJECT}_INSTALLATION})

        fubuki_install_dlls_of(TARGET ${FUBUKI_PROJECT}_${current_project}
                               LIBS ${fubuki_target_PUBLIC_LINK}
                                    ${fubuki_target_PRIVATE_LINK}
                                    ${fubuki_target_SYSTEM_PUBLIC_LINK}
                                    ${fubuki_target_SYSTEM_PRIVATE_LINK})

        install(
            TARGETS ${FUBUKI_PROJECT}_${current_project}
            EXPORT ${${FUBUKI_PROJECT}_TARGETS_EXPORT_NAME}
            RUNTIME DESTINATION ${${FUBUKI_PROJECT}_INSTALL_RUNTIME_DESTINATION}
            ARCHIVE DESTINATION ${${FUBUKI_PROJECT}_INSTALL_ARCHIVE_DESTINATION}
            LIBRARY DESTINATION ${${FUBUKI_PROJECT}_INSTALL_LIBRARY_DESTINATION}
            INCLUDES DESTINATION ${${FUBUKI_PROJECT}_INCLUDES_INSTALL_DIR}
        )

        if(FUBUKI_VERBOSE_BUILD)
            add_custom_command(
                TARGET ${FUBUKI_PROJECT}_${current_project} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E echo "[Fubuki]: ${FUBUKI_PROJECT}_${current_project} installation: copy -t ${${FUBUKI_PROJECT}_INSTALL_RUNTIME_DESTINATION} $<TARGET_RUNTIME_DLLS:${FUBUKI_PROJECT}_${current_project}>"
                COMMAND_EXPAND_LISTS
            )
        endif()

        add_custom_command(
            TARGET ${FUBUKI_PROJECT}_${current_project} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy -t ${${FUBUKI_PROJECT}_INSTALL_RUNTIME_DESTINATION} $<TARGET_RUNTIME_DLLS:${FUBUKI_PROJECT}_${current_project}>
            COMMAND_EXPAND_LISTS
        )
    endif()

    #----------------------------------------------------------------
    # Test

    if(fubuki_target_TYPE STREQUAL "TEST")
        include(GoogleTest)
        add_test(NAME ${FUBUKI_PROJECT}_${current_project} COMMAND ${FUBUKI_PROJECT}_${current_project})
        gtest_discover_tests(${FUBUKI_PROJECT}_${current_project} DISCOVERY_MODE PRE_TEST PROPERTIES TEST_DISCOVERY_TIMEOUT 10)
    endif()

    #----------------------------------------------------------------
    # Cleanup

    unset(FUBUKI_PROJECT)
    unset(current_project)
    unset(current_target_upper)
    unset(current_source_dir_relative_path)
    unset(current_source_dirs)
    unset(path_root)
    unset(headers_destination_relative_path)
    unset(stripped_relative_path)
    unset(components)

    if(FUBUKI_VERBOSE_BUILD)
        message(STATUS "[Fubuki]: Done.")
    endif()

endmacro()

#------------------------------------------------------------------------------
# Creates a shared library from the sources given, links it to the libraries
# given, installs it and updates the target list.
########################################
# param: NAME                 - Name of the library.
#                               A prefix "${FUBUKI_PROJECT}_" is appended automatically, in which FUBUKI_PROJECT is the name of the last project registered through fubuki_setup.
#                               EXPORT_NAME property is set to ${NAME}.
# param: PUBLIC_DEPENDENCIES  - Targets that must be build before this one and linked publicly.
# param: PRIVATE_DEPENDENCIES - Targets that must be build before this one and linked privately.
# param: HEADERS              - Library headers.
# param: SOURCES              - Library sources.
# param: PUBLIC_LINK          - Libraries to link publicly.
# param: PRIVATE_LINK         - Libraries to link privately.
# output: Creates a shared library according to the given information.
# Also handles installation and components updates.
#
# prerequisites: fubuki_setup must have been called before.
macro(fubuki_add_library)
    fubuki_add_target(TYPE "LIBRARY" ${ARGN})
endmacro() # fubuki_add_library

#------------------------------------------------------------------------------
# Creates an executable from the sources given, links it to the libraries
# given, installs it and updates the target list.
########################################
# param: NAME                 - Name of the library.
#                               A prefix "${FUBUKI_PROJECT}_" is appended automatically, in which FUBUKI_PROJECT is the name of the last project registered through fubuki_setup.
#                               EXPORT_NAME property is set to ${NAME}.
# param: PUBLIC_DEPENDENCIES  - Targets that must be build before this one and linked publicly.
# param: PRIVATE_DEPENDENCIES - Targets that must be build before this one and linked privately.
# param: HEADERS              - Library headers.
# param: SOURCES              - Library sources.
# param: PUBLIC_LINK          - Libraries to link publicly.
# param: PRIVATE_LINK         - Libraries to link privately.
# output: Creates a shared library according to the given information.
#
# Also handles installation and components updates.
#
# prerequisites: fubuki_setup must have been called before.
#
macro(fubuki_add_executable)
    fubuki_add_target(TYPE "EXECUTABLE" ${ARGN})
endmacro() # fubuki_add_executable

#------------------------------------------------------------------------------
# Creates a test target from the sources given, links it to the libraries
# given (also adds GTest::gtest), and adds it to the test set.
########################################
# param: NAME                 - Name of the library. Prefix "${FUBUKI_PROJECT}_" is appended automatically.
#                               EXPORT_NAME property is set to ${NAME}.
# param: PUBLIC_DEPENDENCIES  - Targets that must be build before this one and linked publicly.
# param: PRIVATE_DEPENDENCIES - Targets that must be build before this one and linked privately.
# param: HEADERS              - Library headers.
# param: SOURCES              - Library sources.
# param: PUBLIC_LINK          - Libraries to link publicly.
# param: PRIVATE_LINK         - Libraries to link privately.
# output: Creates a shared library according to the given information.
#
# Also handles installation and components updates.
#
# prerequisites: fubuki_setup must have been called before.
#
macro(fubuki_add_test)
    fubuki_add_target(TYPE "TEST" ${ARGN})
endmacro() # fubuki_add_test

#------------------------------------------------------------------------------
