cmake_minimum_required(VERSION 3.23)
project(fubuki_core LANGUAGES CXX)

#------------------------------------------------------------------------------

file(GLOB fubuki_core_compare "compare/*.hpp")
file(GLOB fubuki_core_enums "enum/*.hpp")
file(GLOB fubuki_core_chain_compatibility "detail/chain_compatibility/*.hpp")
file(GLOB fubuki_core_chain_validators "detail/chain_validator/*.hpp")

#------------------------------------------------------------------------------

fubuki_add_library(NAME core
                      PUBLIC_DEPENDENCIES ""
                      PRIVATE_DEPENDENCIES ""
                      HEADERS "config/macros.hpp"
                              "config/setup.hpp"

                              "detail/compare.hpp"
                              "detail/handle_traits.hpp"
                              "detail/manual_handle.hpp"
                              "detail/null_handle.hpp"
                              "detail/pfn.hpp"
                              "detail/platform_forward.hpp"
                              "detail/pnext_chain.hpp"
                              "detail/pnext_parent.hpp"

                              "functions/device_core.hpp"
                              "functions/instance_core.hpp"

                              "future/flat_set.hpp"
                              "future/inplace_vector.hpp"
                              "future/move_only_function.hpp"
                              "future/nontype.hpp"

                              "traits/function.hpp"
                              "traits/parameter_pack.hpp"
                              "traits/surface.hpp"
                              "traits/tuple.hpp"

                              "as_span.hpp"
                              "assertion.hpp"
                              "compile_time_hash.hpp"
                              "constants.hpp"
                              "collect.hpp"
                              "deduce.hpp"
                              "enums.hpp"
                              "flag_mask.hpp"
                              "format.hpp"
                              "handle.hpp"
                              "hash.hpp"
                              "invoke.hpp"
                              "md_vector.hpp"
                              "opaque_ptr.hpp"
                              "pfn.hpp"
                              "pnext_chain.hpp"
                              "result.hpp"
                              "small_vector.hpp"
                              "string_literal.hpp"
                              "structure_type.hpp"
                              "surface_data.hpp"
                              "types.hpp"
                              "unique_c_ptr.hpp"
                              "validate.hpp"
                              "version_number.hpp"
                              "vulkan.hpp"

                              "${fubuki_core_enums}"
                              "${fubuki_core_chain_compatibility}"
                              "${fubuki_core_chain_validators}"
                              "${fubuki_core_compare}"

                      SOURCES "config/setup.cpp"

                              "functions/device_core.cpp"
                              "functions/instance_core.cpp"

                              "assertion.cpp"
                              "format.cpp"
                              "pfn.cpp"
                              "validate.cpp"
                      PUBLIC_LINK "${Vulkan_LIBRARIES}"
                      PRIVATE_LINK ""
                      SYSTEM_PUBLIC_LINK ""
                      SYSTEM_PRIVATE_LINK ""
                  )
