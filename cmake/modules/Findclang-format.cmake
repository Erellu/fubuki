﻿# Adapted from https://cmake.org/pipermail/cmake/2014-January/056677.html

foreach(p $ENV{PATH})
    file(GLOB cand ${p}/clang-format*)
    if(cand)
        set(CLANG_FORMAT_EXECUTABLE ${cand})
        set(CLANG_FORMAT_FOUND ON)
        execute_process(COMMAND ${CLANG_FORMAT_EXECUTABLE} -version OUTPUT_VARIABLE clang_out )
        string(REGEX MATCH .*\(version[^\n]*\)\n version ${clang_out})
        set(CLANG_FORMAT_VERSION ${CMAKE_MATCH_1})
        break()
    else()
        set(CLANG_FORMAT_FOUND OFF)
    endif()
endforeach()
