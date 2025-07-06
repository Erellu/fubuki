#------------------------------------------------------------------------------
# Links against a library as if it were a SYSTEM library.
# From https://stackoverflow.com/a/52136398
# License: CC BY-SA 4.0
########################################
# param: target - Targets to link
#
# option: PUBLIC | PRIVATE | INTEFACE - Scope of the link
function(target_link_libraries_system target)
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
endfunction(target_link_libraries_system)

#------------------------------------------------------------------------------
# Sets up variables used for the building process (install directory, compiler, etc)
# WARNING: calling this function twice with different arguments will result in libraries being
# considered as from different projects, hence installed at different places and in a different export set.
# You should usually call it only once from the main CMakeLists.txt.
# If you need to call it twice (for subprojects for example), call fubuki_finalise() first.
########################################
# param: current_project_name    - Name of the current project, as STRING.
# param: current_project_version - Version of the project.
#
# output: sets the following variables:
#    Variables (constants):
#       FUBUKI_PROJECT                          --- Project name. Value of 'current_project_name'.
#       FUBUKI_VULKAN_LIB_REGEX                 --- The value of ${Vulkan_LIBRARIES} formatted to work as a CMake REGEX.
#       ${FUBUKI_PROJECT}_NAMESPACE             --- Namespace of the exported targets.
#
#       ${FUBUKI_PROJECT}_INSTALL_PREFIX                --- Where the installation is performed.
#       ${FUBUKI_PROJECT}_INSTALL_RUNTIME_DESTINATION   --- Where the binaries are installed.
#       ${FUBUKI_PROJECT}_INSTALL_ARCHIVE_DESTINATION   --- Where the libraries are installed.
#       ${FUBUKI_PROJECT}_INSTALL_LIBRARY_DESTINATION   --- Where the libraries are installed (also).
#       ${FUBUKI_PROJECT}_INSTALL_INCLUDES_DESTINATION  --- Where the headers are installed.
#       ${FUBUKI_PROJECT}_INCLUDES_INSTALL_DIR          --- Where the headers are installed.
#       ${FUBUKI_PROJECT}_GENERATED_DIR                 --- Where the CMake-generated files are put.
#       ${FUBUKI_PROJECT}_OUTPUT_DIR                    --- Where the binaries (.dll/.so, .exe, etc.) are put.
#
#       ${FUBUKI_PROJECT}_VERSION_CONFIG        --- Name of the CMake version config file.
#       ${FUBUKI_PROJECT}_PROJECT_CONFIG        --- Name of the CMake config file.
#
#       ${FUBUKI_PROJECT}_TARGETS_EXPORT_NAME   --- Export set for the targets added using fubuki_add_library.
#       ${FUBUKI_PROJECT}_EXPORT_NAME           --- Name of CMake Targets file.
#       ${FUBUKI_PROJECT}_CONFIG_INSTALL_DIR    --- Where to install cmake "Targets" files.
#
#        FUBUKI_WARNINGS                        --- A list of warnings enabled by Fubuki for the compiler in use.
#    Flags:
#        FUBUKI_SETUP                           --- A flag indicating this function was call. Unsetting it or setting a value that is not 'TRUE' will lead to the impossibility to call fubuki_finalise().
#    Properties:
#        ${FUBUKI_PROJECT}_components           --- Global property to which target added through fubuki_add_library are added.
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

    if(DEFINED FUBUKI_SETUP)
        message(FATAL_ERROR "fubuki_setup already called. If this is intentional, please call fubuki_finalise first.")
    endif()

    if("${fubuki_setup_NAME}" STREQUAL "")
        message(FATAL_ERROR "Project name must not be empty.")
    endif()

    if(NOT "${fubuki_setup_INSTALLATION}" STREQUAL "ON" AND NOT "${fubuki_setup_INSTALLATION}" STREQUAL "OFF")
        message(FATAL_ERROR "Invalid argument for INSTALLATION. Expected ON or OFF")
    endif()

    if(DEFINED FUBUKI_PROJECT AND FUBUKI_VERBOSE_BUILD)
        message(WARNING "Variable 'FUBUKI_PROJECT' is already set. It will be overriden by macro fubuki_setup.")
    endif()

    # Set again later for readability
    set(FUBUKI_PROJECT "${fubuki_setup_NAME}")

    if(DEFINED ${FUBUKI_PROJECT}_NAMESPACE AND FUBUKI_VERBOSE_BUILD)
        message(WARNING "Variable '${FUBUKI_PROJECT}_NAMESPACE' is already set. It will be overriden by macro fubuki_setup.")
    endif()

    if(DEFINED ${FUBUKI_PROJECT}_INSTALL_RUNTIME_DESTINATION AND FUBUKI_VERBOSE_BUILD)
        message(WARNING "Variable '${FUBUKI_PROJECT}_INSTALL_RUNTIME_DESTINATION' is already set. It will be overriden by macro fubuki_setup.")
    endif()

    if(DEFINED ${FUBUKI_PROJECT}_INSTALL_ARCHIVE_DESTINATION AND FUBUKI_VERBOSE_BUILD)
        message(WARNING "Variable '${FUBUKI_PROJECT}_INSTALL_ARCHIVE_DESTINATION' is already set. It will be overriden by macro fubuki_setup.")
    endif()

    if(DEFINED ${FUBUKI_PROJECT}_INSTALL_INCLUDES_DESTINATION AND FUBUKI_VERBOSE_BUILD)
        message(WARNING "Variable '${FUBUKI_PROJECT}_INSTALL_INCLUDES_DESTINATION' is already set. It will be overriden by macro fubuki_setup.")
    endif()

    if(DEFINED ${FUBUKI_PROJECT}_INCLUDES_INSTALL_DIR  AND FUBUKI_VERBOSE_BUILD)
        message(WARNING "Variable '${FUBUKI_PROJECT}_INCLUDES_INSTALL_DIR' is already set. It will be overriden by macro fubuki_setup.")
    endif()

    if(DEFINED ${FUBUKI_PROJECT}_GENERATED_DIR AND FUBUKI_VERBOSE_BUILD)
        message(WARNING "Variable '${FUBUKI_PROJECT}_GENERATED_DIR' is already set. It will be overriden by macro fubuki_setup.")
    endif()

    if(DEFINED ${FUBUKI_PROJECT}_VERSION_CONFIG AND FUBUKI_VERBOSE_BUILD)
        message(WARNING "Variable '${FUBUKI_PROJECT}_VERSION_CONFIG' is already set. It will be overriden by macro fubuki_setup.")
    endif()

    if(DEFINED ${FUBUKI_PROJECT}_PROJECT_CONFIG AND FUBUKI_VERBOSE_BUILD)
        message(WARNING "Variable '${FUBUKI_PROJECT}_PROJECT_CONFIG' is already set. It will be overriden by macro fubuki_setup.")
    endif()

    if(DEFINED ${FUBUKI_PROJECT}_TARGETS_EXPORT_NAME AND FUBUKI_VERBOSE_BUILD)
        message(WARNING "Variable '${FUBUKI_PROJECT}_TARGETS_EXPORT_NAME' is already set. It will be overriden by macro fubuki_setup.")
    endif()

    if(DEFINED ${FUBUKI_PROJECT}_EXPORT_NAME AND FUBUKI_VERBOSE_BUILD)
        message(WARNING "Variable '${FUBUKI_PROJECT}_EXPORT_NAME' is already set. It will be overriden by macro fubuki_setup.")
    endif()

    if(DEFINED ${FUBUKI_PROJECT}_CONFIG_INSTALL_DIR AND FUBUKI_VERBOSE_BUILD)
        message(WARNING "Variable '${FUBUKI_PROJECT}_CONFIG_INSTALL_DIR' is already set. It will be overriden by macro fubuki_setup.")
    endif()

    # No check for ${FUBUKI_PROJECT}_components, since it's allowed to inherit that value for compatibility purposes

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

    fubuki_setup_warning_list()

    #----------------------------------------------------------------
    # Vulkan

    if(PROJECT_IS_TOP_LEVEL)
        find_package(Vulkan REQUIRED)
    endif()

    if (NOT Vulkan_FOUND)
        message(FATAL_ERROR
                "Could not find Vulkan! "
                "Can you confirm you downloaded the SDK? https://www.lunarg.com/vulkan-sdk/"
                "\nNOTE: if Fubuki is a subproject (added via add_subdirectory), you must perform your own find_package(Vulkan)."
                "This is to enable the user (you) to provide hints to CMake."
            )
    endif()

    string(REPLACE "/" "\/" FUBUKI_VULKAN_LIB_REGEX "${Vulkan_LIBRARIES}")
    string(REPLACE "." "\." FUBUKI_VULKAN_LIB_REGEX "${FUBUKI_VULKAN_LIB_REGEX}")

    #----------------------------------------------------------------
    # Flags

    set(FUBUKI_SETUP TRUE)

endmacro() # fubuki_setup

#------------------------------------------------------------------------------
# Finalises the build process for the current project.
########################################
#
# output: unsets FUBUKI_SETUP and FUBUKI_PROJECT, allowing to call fubuki_setup again for another subproject.
# Other variables set by fubuki_setup are left untouched.

macro(fubuki_finalise)

    if(NOT DEFINED FUBUKI_SETUP OR NOT ${FUBUKI_SETUP})
        message(FATAL_ERROR "fubuki_setup(...) not called yet.")
    endif()

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
        message(STATUS "The following components (available in property ${FUBUKI_PROJECT}_components) will be exported: ${FUBUKI_PROJECT_components_value}")
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
    # Unset flags

    unset(FUBUKI_SETUP)
    unset(FUBUKI_PROJECT)

    #----------------------------------------------------------------
    # Clear

    unset(FUBUKI_PROJECT_components_value)

endmacro() # fubuki_finalise

#------------------------------------------------------------------------------
# Creates a target from the sources given, links it to the libraries
# given, installs it and updates the target list.
########################################
# param: NAME                 - Name of the library. Prefix "${FUBUKI_PROJECT}_" is appended automatically.
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
#   - (PRIVATE) FUBUKI_TRANSLATION_UNIT
#  -  (PRIVATE) VK_NO_PROTOTYPES
#  -  (PRIVATE) "${current_target_upper}_COMPILE"
macro(fubuki_add_target)

    #----------------------------------------------------------------
    # Sanity checks

    if(NOT DEFINED FUBUKI_SETUP)
        message(FATAL_ERROR "fubuki_setup(...) not called yet.")
    endif()

    if(DEFINED current_project AND FUBUKI_VERBOSE_BUILD)
        message(WARNING "Variable 'current_project' is already set. It will be overriden by macro fubuki_add_library.")
    endif()

    if(DEFINED current_target_upper AND FUBUKI_VERBOSE_BUILD)
        message(WARNING "Variable 'current_target_upper' is already set. It will be overriden by macro fubuki_add_library.")
    endif()

    if(DEFINED current_source_dir_relative_path AND FUBUKI_VERBOSE_BUILD)
        message(WARNING "Variable 'current_source_dir_relative_path' is already set. It will be overriden by macro fubuki_add_library.")
    endif()

    if(DEFINED current_source_dirs AND FUBUKI_VERBOSE_BUILD)
        message(WARNING "Variable 'current_source_dirs' is already set. It will be overriden by macro fubuki_add_library.")
    endif()

    if(DEFINED path_root AND FUBUKI_VERBOSE_BUILD)
        message(WARNING "Variable 'path_root' is already set. It will be overriden by macro fubuki_add_library.")
    endif()

    if(DEFINED headers_destination_relative_path AND FUBUKI_VERBOSE_BUILD)
        message(WARNING "Variable 'headers_destination_relative_path' is already set. It will be overriden by macro fubuki_add_library.")
    endif()

    if(DEFINED stripped_relative_path AND FUBUKI_VERBOSE_BUILD)
        message(WARNING "Variable 'stripped_relative_path' is already set. It will be overriden by macro fubuki_add_library.")
    endif()

    if(DEFINED components AND FUBUKI_VERBOSE_BUILD)
        message(WARNING "Variable 'stripped_relative_path' is already set. It will be overriden by macro fubuki_add_library.")
    endif()

    if(DEFINED public_deps AND FUBUKI_VERBOSE_BUILD)
        message(WARNING "Variable 'public_deps' is already set. It will be overriden by macro fubuki_add_library.")
    endif()

    if(DEFINED private_deps AND FUBUKI_VERBOSE_BUILD)
        message(WARNING "Variable 'private_deps' is already set. It will be overriden by macro fubuki_add_library.")
    endif()

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

    #----------------------------------------------------------------
    # Project name

    set(current_project "${fubuki_target_NAME}")
    string(TOUPPER "${FUBUKI_PROJECT}_${current_project}" current_target_upper)

    if(current_project STREQUAL "")
        message(FATAL_ERROR "Cannot configure a project with an empty name.")
    endif()

    if(FUBUKI_VERBOSE_BUILD)
        message(STATUS "Configuring ${FUBUKI_PROJECT}::${current_project}...")
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
        target_compile_options(${FUBUKI_PROJECT}_${current_project} PRIVATE /bigobj)
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
        # Used to toggle warnings about private API and similar things
        target_compile_definitions(${FUBUKI_PROJECT}_${current_project} PRIVATE FUBUKI_TRANSLATION_UNIT)
    endif()

    # Libraries to link against
    target_link_libraries(${FUBUKI_PROJECT}_${current_project} PUBLIC ${fubuki_target_PUBLIC_LINK})
    target_link_libraries(${FUBUKI_PROJECT}_${current_project} PRIVATE ${fubuki_target_PRIVATE_LINK})
    target_link_libraries_system(${FUBUKI_PROJECT}_${current_project} PUBLIC ${fubuki_target_SYSTEM_PUBLIC_LINK})
    target_link_libraries_system(${FUBUKI_PROJECT}_${current_project} PRIVATE ${fubuki_target_SYSTEM_PRIVATE_LINK})

    if("${fubuki_target_PUBLIC_LINK}" MATCHES "${FUBUKI_VULKAN_LIB_REGEX}")
        target_include_directories(${FUBUKI_PROJECT}_${current_project} SYSTEM PUBLIC ${Vulkan_INCLUDE_DIRS})
    endif()

    if("${fubuki_target_PRIVATE_LINK}" MATCHES "${FUBUKI_VULKAN_LIB_REGEX}")
        target_include_directories(${FUBUKI_PROJECT}_${current_project} SYSTEM PRIVATE ${Vulkan_INCLUDE_DIRS})
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
                message("    -- Installing to: ${${FUBUKI_PROJECT}_INCLUDES_INSTALL_DIR}/${headers_destination_relative_path}")
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
        install(
            TARGETS ${FUBUKI_PROJECT}_${current_project}
            EXPORT ${${FUBUKI_PROJECT}_TARGETS_EXPORT_NAME}
            RUNTIME DESTINATION ${${FUBUKI_PROJECT}_INSTALL_RUNTIME_DESTINATION}
            ARCHIVE DESTINATION ${${FUBUKI_PROJECT}_INSTALL_ARCHIVE_DESTINATION}
            LIBRARY DESTINATION ${${FUBUKI_PROJECT}_INSTALL_LIBRARY_DESTINATION}
            INCLUDES DESTINATION ${${FUBUKI_PROJECT}_INCLUDES_INSTALL_DIR}
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

    unset(current_project)
    unset(current_target_upper)
    unset(current_source_dir_relative_path)
    unset(current_source_dirs)
    unset(path_root)
    unset(headers_destination_relative_path)
    unset(stripped_relative_path)
    unset(components)

    if(FUBUKI_VERBOSE_BUILD)
        message(STATUS "Done.")
    endif()

endmacro()

#------------------------------------------------------------------------------
# Creates a shared library from the sources given, links it to the libraries
# given, installs it and updates the target list.
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
# Also handles installation and components updates.
#
# prerequisites: fubuki_setup must have been called before.
macro(fubuki_add_library)

    #----------------------------------------------------------------
    # Arguments

    set(fubuki_add_library_optional_args_identifiers)

    set(fubuki_add_library_single_value_args_identifiers)

    set(fubuki_add_library_multi_value_args_identifiers
        NAME
        PUBLIC_DEPENDENCIES
        PRIVATE_DEPENDENCIES
        HEADERS
        SOURCES
        PUBLIC_LINK
        PRIVATE_LINK
        SYSTEM_PUBLIC_LINK
        SYSTEM_PRIVATE_LINK
    )

    cmake_parse_arguments(fubuki_library
                          "${fubuki_add_library_optional_args_identifiers}"
                          "${fubuki_add_library_single_value_args_identifiers}"
                          "${fubuki_add_library_multi_value_args_identifiers}"
                          ${ARGN})

    #----------------------------------------------------------------
    # Target

    fubuki_add_target(NAME "${fubuki_library_NAME}"
                      TYPE "LIBRARY"
                      PUBLIC_DEPENDENCIES "${fubuki_library_PUBLIC_DEPENDENCIES}"
                      PRIVATE_DEPENDENCIES "${fubuki_library_PRIVATE_DEPENDENCIES}"
                      HEADERS "${fubuki_library_HEADERS}"
                      SOURCES "${fubuki_library_SOURCES}"
                      PUBLIC_LINK "${fubuki_library_PUBLIC_LINK}"
                      PRIVATE_LINK "${fubuki_library_PRIVATE_LINK}"
                      SYSTEM_PUBLIC_LINK "${fubuki_library_SYSTEM_PUBLIC_LINK}"
                      SYSTEM_PRIVATE_LINK "${fubuki_library_SYSTEM_PRIVATE_LINK}"
                    )

endmacro() # fubuki_add_library

#------------------------------------------------------------------------------
# Creates an executable from the sources given, links it to the libraries
# given, installs it and updates the target list.
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
macro(fubuki_add_executable)

    #----------------------------------------------------------------
    # Arguments

    set(fubuki_add_executable_optional_args_identifiers)

    set(fubuki_add_executable_single_value_args_identifiers)

    set(fubuki_add_executable_multi_value_args_identifiers
        NAME
        PUBLIC_DEPENDENCIES
        PRIVATE_DEPENDENCIES
        HEADERS
        SOURCES
        PUBLIC_LINK
        PRIVATE_LINK
        SYSTEM_PUBLIC_LINK
        SYSTEM_PRIVATE_LINK
    )

    cmake_parse_arguments(fubuki_executable
                          "${fubuki_add_executable_optional_args_identifiers}"
                          "${fubuki_add_executable_single_value_args_identifiers}"
                          "${fubuki_add_executable_multi_value_args_identifiers}"
                          ${ARGN})


    #----------------------------------------------------------------
    # Target

    fubuki_add_target(NAME "${fubuki_executable_NAME}"
                      TYPE "EXECUTABLE"
                      PUBLIC_DEPENDENCIES "${fubuki_executable_PUBLIC_DEPENDENCIES}"
                      PRIVATE_DEPENDENCIES "${fubuki_executable_PRIVATE_DEPENDENCIES}"
                      HEADERS "${fubuki_executable_HEADERS}"
                      SOURCES "${fubuki_executable_SOURCES}"
                      PUBLIC_LINK "${fubuki_executable_PUBLIC_LINK}"
                      PRIVATE_LINK "${fubuki_executable_PRIVATE_LINK}"
                      SYSTEM_PUBLIC_LINK "${fubuki_executable_SYSTEM_PUBLIC_LINK}"
                      SYSTEM_PRIVATE_LINK "${fubuki_executable_SYSTEM_PRIVATE_LINK}"
                    )

endmacro() # fubuki_add_executable

#------------------------------------------------------------------------------
# Creates a test target from the sources given, links it to the libraries
# given (also adds GTest::gtest_main), and adds it to the test set.
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

    #----------------------------------------------------------------
    # Arguments

    set(fubuki_add_test_optional_args_identifiers)

    set(fubuki_add_test_single_value_args_identifiers)

    set(fubuki_add_test_multi_value_args_identifiers
        NAME
        PUBLIC_DEPENDENCIES
        PRIVATE_DEPENDENCIES
        HEADERS
        SOURCES
        PUBLIC_LINK
        PRIVATE_LINK
        SYSTEM_PUBLIC_LINK
        SYSTEM_PRIVATE_LINK
    )

    cmake_parse_arguments(fubuki_test
                          "${fubuki_add_test_optional_args_identifiers}"
                          "${fubuki_add_test_single_value_args_identifiers}"
                          "${fubuki_add_test_multi_value_args_identifiers}"
                          ${ARGN})


    #----------------------------------------------------------------
    # Target

    fubuki_add_target(NAME "${fubuki_test_NAME}"
                      TYPE "TEST"
                      PUBLIC_DEPENDENCIES "${fubuki_test_PUBLIC_DEPENDENCIES}"
                      PRIVATE_DEPENDENCIES "${fubuki_test_PRIVATE_DEPENDENCIES}"
                      HEADERS "${fubuki_test_HEADERS}"
                      SOURCES "${fubuki_test_SOURCES}"
                      PUBLIC_LINK "${fubuki_test_PUBLIC_LINK}"
                      PRIVATE_LINK "${fubuki_test_PRIVATE_LINK}"
                      SYSTEM_PUBLIC_LINK "${fubuki_test_SYSTEM_PUBLIC_LINK}"
                      SYSTEM_PRIVATE_LINK "${fubuki_test_SYSTEM_PRIVATE_LINK};GTest::gtest_main"
                    )

endmacro() # fubuki_add_executable

#------------------------------------------------------------------------------
