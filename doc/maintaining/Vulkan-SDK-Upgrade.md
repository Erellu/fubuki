# Upgrading the Vulkan SDK

> [!IMPORTANT]
> The following contents for _maintainers_.
> It does not provide any documentation of Fubuki's API.

The goal of this file is to describe the steps to follow when updating the Vulkan SDK version.

# Premilinaries

1. Delete the cached registry, located in `py/code_generation/cache` as `vk.xml.formatted.cache`.
2. Download and install the [newest SDK](https://vulkan.lunarg.com/).
3. Make sure you have a `clang-format` executable that can be "seen" from your `$ENV{PATH}` (in the CMake meaning of the term).

## `fubuki::core`

1. Delete all files in the following directories (**but do not delete the directories themselves**):
    - `libs/core/compare/*`
    - `libs/core/detail/chain_compatibility/*`
    - `libs/core/detail/chain_validator/*`
    - `libs/core/detail/enum/*`
2. Delete the following file(s):
    - `libs/core/detail/handle_traits.hpp`
    - `libs/core/detail/pfn.hpp`
    - `libs/core/detail/pnext_chain.hpp`
    - `libs/core/functions/device_core.hpp`
    - `libs/core/functions/device_core.cpp`
    - `libs/core/functions/instance_core.hpp`
    - `libs/core/functions/instance_core.cpp`
    - `libs/core/enum.hpp`
    - `libs/core/format.hpp`
    - `libs/core/handle.hpp`
    - `libs/core/structure_type.hpp`
    - `libs/core/result.hpp`

### Tests

1. Delete the following file(s):
    - `tests/core/enum.cpp`
    - `tests/core/pnext_chain.cpp`
    - `tests/core/result.cpp`
    - `tests/core/structure_type.cpp`

## `fubuki::extension`

1. Delete all files in the following directories (**but do not delete the directories themselves**):
    - `libs/extension/functions/*`
2. Delete the following file(s):
    - `libs/extension/README.md`

# Regenerate the code

1. Launch CMake configure step with `FUBUKI_SKIP_GENERATION` set to `OFF`.
2. Wait until the generation completes. It can take some time, depending on your machine.

# Add new extensions

1. Inspect the diff to check the extensions that changed (which functions were added, which extension is new, etc.).
2. Add the bindings to the newly added functions for all extensions that already existed.
3. Adapt the bindings that were automatically generated for new extensions following the patterns in existing ones:
    - Replace pairs of parameters `T* array, std::uint32_t size` by `span`
    - Add overloads accepting `std::initializer_list`.
    - Add or remove `noexcept` qualifiers based on what you must do to implement the binding.
    - Replace result of `VkResult` by `std::expected`
    - Replace "return parameters" (non-`const` pointers that are written to) by `std::expected`.
    - Replace `const VkAllocationCallbacks*` parameters by two overloads: one with a `const VkAllocationCallbacks&` parameter and one without that parameter.
        - Either add a `namespace detail` and a function with the same name exposed in the header (for pnext chain support)
        - Or add a function with internal linkage in an anonymous `namespace` in the source file when no pnext chain is involved.
