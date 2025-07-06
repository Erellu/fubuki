cmake_minimum_required(VERSION 3.23)
project(fubuki_core_test LANGUAGES CXX)

#------------------------------------------------------------------------------

fubuki_add_test(NAME core_test
                   PUBLIC_DEPENDENCIES "core"
                   PRIVATE_DEPENDENCIES ""
                   HEADERS "contiguous_container_test_types.hpp"
                   SOURCES "assertion.cpp"
                           "collect.cpp"
                           "core_test.cpp"
                           "compile_time_hash.cpp"
                           "enum.cpp"
                           "flag_mask.cpp"
                           "handle.cpp"
                           "md_vector.cpp"
                           "opaque_ptr.cpp"
                           "parameter_pack.cpp"
                           "pfn.cpp"
                           "pnext_chain.cpp"
                           "result.cpp"
                           "small_vector.cpp"
                           "string_literal.cpp"
                           "structure_type.cpp"
                           "tuple_traits.cpp"
                           "types.cpp"
                           "version_number.cpp"

                           "future/flat_set.cpp"
                           "future/inplace_vector.cpp"
                           "future/move_only_function.cpp"
                   PUBLIC_LINK ""
                   PRIVATE_LINK ""
                   SYSTEM_PUBLIC_LINK ""
                   SYSTEM_PRIVATE_LINK ""
                  )

if(MSVC)
    # /utf-8: to test the behaviour of compile_time_hash the same way for all compilers
    # C4868: compiler may not enforce left-to-right evaluation order in braced initializer list
    #     It's OK in tests, because we want to test the behaviour of the same code on different compilers
    target_compile_options(fubuki_core_test
                           PRIVATE
                           "/utf-8"
                           "/wd4868"
                       )
endif()
