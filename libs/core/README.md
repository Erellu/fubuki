# fubuki::core

> [!IMPORTANT]
> This file is _not_ a substitue for the in-code documentation.
> Its goal is to advertise the features available through `fubuki::core`.
> For examples and detailed documentation, see the `doxygen`.

## CMake

### Externally

```cmake
target_link_libraries(your_target <PUBLIC|PRIVATE> fubuki::core)
```

### Internally

```cmake
fubuki_add_library(NAME                 target_name
                   PUBLIC_DEPENDENCIES  "core"
                   PRIVATE_DEPENDENCIES "..."
                   HEADERS              "..."
                   SOURCES              "..."
                   PUBLIC_LINK          "..."
                   PRIVATE_LINK         "..."
                   SYSTEM_PUBLIC_LINK   "..." 
                   SYSTEM_PRIVATE_LINK  "..."
                  )
```

## Nomenclature

| Name                 | Type                     | Category                       | Description    | Notes                  |
| -------------------- | ------------------------ | ------------------------------ | -------------- | ---------------------- |
| Name of the facility | Type, in the C++ meaning | What this facility relates to. | What this does | Additional information |

## Overview

`fubuki::core` contains the building blocks for all the other libraries provided by Fubuki: containers, commonly-used types, and abstractions.
All targets depend on `fubuki::core`, which itself only depends on the Standard Library and Vulkan.

## Public API

### Algorithms

| Name                          | Type          | Category        | Description                                                     | Notes                    |
| ----------------------------- | ------------- | --------------- | --------------------------------------------------------------- | ------------------------ |
| `as_span`                     | Free function | Type conversion | Wraps a variable into a span containing one element.            | N.A.                     |
| `collect`                     | Free function | Type conversion | Converts a span of a type to a `small_vector` of another type.  | N.A.                     |
| `compile_time_hash`           | Free function | Type conversion | Hashes a string literal known at compile time with CRC.         | N.A.                     |
| `hash_range`                  | Free function | Type conversion | Hashes a range which elements are hashable through `std::hash`. | Limited to sized ranges. |
| `heterogeneous_string_hash`   | `class`       | Helper          | Heterogeneous hash for containers (`map`, etc.)                 | N.A.                     |
| `heterogenous_string_compare` | `class`       | Helper          | Heterogeneous compare for containers (`map`, etc.)              | N.A.                     |
| `heterogenous_string_greater` | `class`       | Helper          | Heterogeneous compare for containers (`map`, etc.)              | N.A.                     |
| `heterogenous_string_less`    | `class`       | Helper          | Heterogeneous compare for containers (`map`, etc.)              | N.A.                     |

### Containers

| Name                     | Type       | Category                        | Description                                                                                                | Notes                                                             |
| ------------------------ | ---------- | ------------------------------- | ---------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------- |
| `flat_set`               | Type alias | Container, contiguous container | Alias to `future::flat_set`                                                                                | _May_ become an alias to the Standard Library type in the future. |
| `future::flat_set`       | `class`    | Container, contiguous container | Implementation of [`std::flat_set`](https://en.cppreference.com/w/cpp/container/flat_set.html)             | N.A                                                               |
| `future::inplace_vector` | `class`    | Container, contiguous container | Implementation of [`std::inplace_vector`](https://en.cppreference.com/w/cpp/container/inplace_vector.html) | N.A.                                                              |
| `inplace_vector`         | Type alias | Container, contiguous container | Alias to `future::inplace_vector`                                                                          | _May_ become an alias to the Standard Library type in the future. |
| `md_vector`              | `class`    | Container                       | A RAII wrapper around a C-array `T[][]...` (with the number of dimensions known at compile-time).          | **Avoid** unless you need a `T**`.                                |
| `md_vector_view`         | `class`    | View                            | View of a `md_vector` or of the corresponding C storage type.                                              | N.A.                                                              |
| `operator""_literal`     | `class`    | Helper                          | Constructs a string literal.                                                                               | N.A.                                                              |
| `small_vector`           | `class`    | Container, contiguous container | `vector` with SBO (Small Buffer Optimisation).                                                             | Use as default container.                                         |
| `string_literal`         | `class`    | Container, contiguous container | Ensures a raw C string parameter is from a string literal.                                                 | Use as default container for string literals.                     |

### Memory

| Name                | Type          | Category        | Description                                                                                                                                     | Notes |
| ------------------- | ------------- | --------------- | ----------------------------------------------------------------------------------------------------------------------------------------------- | ----- |
| `as_span`           | Free function | Type conversion | Wraps a variable into a span containing one element.                                                                                            | N.A.  |
| `collect`           | Free function | Type conversion | Converts a span of a type to a `small_vector` of another type.                                                                                  | N.A.  |
| `make_opaque`       | Free function | Helper          | Makes a `unique_ptr` opaque: returns an `opaque_unique_ptr`, that will properly delete its contents, but only expose an opaque `void*` pointer. | N.A.  |
| `opaque_unique_ptr` | Type alias    | Helper          | Alias to a corresponding opaque pointer.                                                                                                        | N.A.  |
| `u_dimension<n>d`   | Type alias    | Helper          | Unsigned integer n-D dimension.                                                                                                                 | N.A.  |
| `unique_c_ptr`      | Type alias    | Storage         | Takes ownership over a `malloc`-allocated storage, and `free`s it upon destruction.                                                             | N.A.  |

### Error handling

| Name                                       | Type          | Category                   | Description                                                                                                         | Notes                                                               |
| ------------------------------------------ | ------------- | -------------------------- | ------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------- |
| `api_call_exception`                       | Type alias    | Error handling, exceptions | An exception that CAN be thrown when an API call fails.                                                             | N.A.                                                                |
| `api_call_info`                            | Type alias    | Error handling             | Information about a Vulkan API call.                                                                                | N.A.                                                                |
| `assertion`                                | Free function | Assertion                  | Asserts condition is true. Calls terminate() and displays the error message otherwise.                              | Prefer `fubuki_assert` or `fubuki_always_assert.` to a direct call. |
| `call_exception`                           | `class`       | Error handling, exceptions | An exception that carries an instance of `call_info`.                                                               | N.A.                                                                |
| `call_info`                                | `class`       | Error handling             | Information about an API call.                                                                                      | Also used in `io` in non-Vulkan context.                            |
| `crash`                                    | Free function | Assertion                  | Crashes after displaying an error message.                                                                          | N.A.                                                                |
| `fubuki_always_assert(expr)`               | Macro         | Assertion                  | Same as `fubuki_assert`, but this assertion is always enabled, even if `FUBUKI_ENABLE_ASSERTION` is not defined.    | N.A.                                                                |
| `fubuki_always_assert_if(condition, expr)` | Macro         | Assertion                  | Same as `fubuki_assert_if`, but this assertion is always enabled, even if `FUBUKI_ENABLE_ASSERTION` is not defined. | N.A.                                                                |
| `fubuki_assert(expr)`                      | Macro         | Assertion                  | Asserts condition is true. Calls terminate() and displays the error message otherwise.                              | Has no effect if `FUBUKI_ENABLE_ASSERTION` is not `#define`d.       |
| `fubuki_assert_if(condition, expr)`        | Macro         | Assertion                  | Asserts condition is true. Calls terminate() and displays the error message otherwise.                              | Has no effect if `FUBUKI_ENABLE_ASSERTION` is not `#define`d.       |
| `fubuki_validate(method, expr)`            | Macro         | Error handling             | Validates a `VkResult` according to the method passed as first parameter.                                           | N.A.                                                                |
| `validate_call(method, ...)`               | Free function | Error handling             | Validates a `VkResult` according to the method passed as first parameter.                                           | Prefer the `fubuki_validate` macro                                  |

### Type traits

| Name                        | Type      | Category | Description                                                       | Notes |
| --------------------------- | --------- | -------- | ----------------------------------------------------------------- | ----- |
| `traits::pnext_chain::type` | `concept` | Traits   | Indicates if a type is a specialisation of `fubuki::pnext_chain`. | N.A.  | 

### Utility

| Name                         | Type          | Category        | Description                                                                                                                                     | Notes                                                                 |
| ---------------------------- | ------------- | --------------- | ----------------------------------------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------- |
| `build_configuration`        | Free function | Build           | Returns the configuration in which Fubuki has been (or is being) built.                                                                         | N.A.                                                                  |
| `configuration`              | `struct`      | Build           | A structure specifying build configuration.                                                                                                     | N.A.                                                                  |
| `crash`                      | Free function | Assertion       | Crashes after displaying an error message.                                                                                                      | N.A.                                                                  |
| `deduce`                     | Constant      | Helper          | A tag struct that can be used to indicate a parameter or a behaviour must be deduced from something.                                            | N.A.                                                                  |
| `dim<n>D`                    | `struct`      | Helper          | 1, 2, or 3 dimension of any type.                                                                                                               | N.A.                                                                  |
| `dimension<n>D`              | Type alias    | Helper          | Signed integer n-D dimension.                                                                                                                   | N.A.                                                                  |
| `flag_mask`                  | `class`       | Enumeration     | A mask of `enum` values.                                                                                                                        | The template parameter `enum` must be a bitmask.                      |
| `future::move_only_function` | `class`       | Function object | Implementation of [`std::move_only_function`](https://en.cppreference.com/w/cpp/utility/functional/move_only_function.html)                     | Also has support for `nontype_t`. See the unit tests for examples.    |
| `future::nontype`            | Constant      | Utility         | Implementation of `[std::nontype`](https://en.cppreference.com/w/cpp/utility/nontype)                                                           | N.A.                                                                  |
| `future::nontype_t`          | `struct`      | Utility         | Implementation of `[std::nontype_t`](https://en.cppreference.com/w/cpp/utility/nontype)                                                         | N.A.                                                                  |
| `make_opaque`                | Free function | Helper          | Makes a `unique_ptr` opaque: returns an `opaque_unique_ptr`, that will properly delete its contents, but only expose an opaque `void*` pointer. | N.A.                                                                  |
| `move_only_function`         | Type alias    | Function object | Alias to `future::move_only_function`                                                                                                           | _May_ become an alias to the Standard Library type in the future.     |
| `nontype`                    | Constant      | Utility         | Alias to `future::nontype`                                                                                                                      | _May_ become an alias to the Standard Library constant in the future. |
| `nontype_t`                  | Type alias    | Utility         | Alias to `future::nontype_t`                                                                                                                    | _May_ become an alias to the Standard Library type in the future.     |
| `pos<n>d`                    | `struct`      | Helper          | 1, 2, or 3 position of any type.                                                                                                                | N.A.                                                                  |
| `position<n>d`               | Type alias    | Helper          | Signed integer n-D position.                                                                                                                    | N.A.                                                                  |
| `rectangle<n>d`              | `struct`      | Helper          | n-D rectangle.                                                                                                                                  | N.A.                                                                  |
| `u_dimension<n>d`            | Type alias    | Helper          | Unsigned integer n-D dimension.                                                                                                                 | N.A.                                                                  |
| `u_position<n>d`             | Type alias    | Helper          | Unsigned integer n-D position.                                                                                                                  | N.A.                                                                  |
| `version_number`             | `struct`      | Version         | Version number providing a valid (implicit) conversion to a Vulkan-like encoded version number.                                                 | N.A.                                                                  |

### Vulkan adaptors

| Name                 | Type          | Category                       | Description                                                                               | Notes                                                                                         |
| -------------------- | ------------- | ------------------------------ | ----------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------- |
| `description`        | Free function | Format                         | Returns information about a VkFormat.                                                     | N.A.                                                                                          |
| `device_size`        | Free function | Type conversion                | Converts a type to the type the device (GPU) uses as a size type, aka `std::uint64_t`.    | N.A.                                                                                          |
| `extend`             | Free function | pNext chain validation         | Extends a Vulkan structure with a pNext chain.                                            | The validation is performed at compile-time.                                                  |
| `extend_range`       | Free function | pNext chain validation         | Extends a range of structures.                                                            | The validation is performed at compile-time.                                                  |
| `format_description` | `class`       | Format                         | Structure storing the description of a format (`VkFormat`).                               | Obtained through `fubuki::description`.                                                       |
| `get_from`           | Free function | Helper                         | Returns a Vulkan function pointer by name from a `struct` providing the `get_from` trait. | N.A.                                                                                          |
| `handle<>`           | `class`       | Vulkan handles                 | Type-safe Vulkan handles                                                                  | Use through the provided aliases: `name` + `_handle` (ex: `VkInstance` -> `instance_handle`.) |
| `host_size`          | Free function | Type conversion                | Converts a type to the type the host (CPU) uses as a size type, aka `std::size_t`.        | N.A.                                                                                          |
| `invoke`             | Free function | Helper                         | Invokes a Vulkan function by name from a `struct` providing the `get_from` trait.         | N.A.                                                                                          |
| `owning_pnext_chain` | `class`       | Helper, pNext chain validation | Same as `pnext_chain`, but owns the structures it keeps.                                  | This object is **compile-time validated** upon call to `fubuki::extend`.                      |
| `pfn`                | Free function | Helper                         | Loads an instance or device function pointer.                                             | N.A.                                                                                          |
| `pnext_chain`        | `class`       | Helper, pNext chain validation | A chain of structures to pass to the pNext member of a structure.                         | This object is **compile-time validated** upon call to `fubuki::extend`.                      |
| `properties`         | Free function | Format, wrapper                | Returns information about the features supported by a device for a format.                | N.A.                                                                                          |
| `result`             | `class`       | Wrapper                        | Wraps a `VkResult`.                                                                       | N.A.                                                                                          |
| `structure_type`     | `class`       | Traits                         | Maps a Vulkan structure to the corresponding `VkStructureType`.                           | N.A.                                                                                          |
| `structure_type_v`   | Constant      | Traits                         | Equivalent of `structure_type::value`.                                                    | N.A.                                                                                          |
| `surface_data`       | `class`       | Platform data, surface         | Platform-specific data required to create a surface.                                      | N.A.                                                                                          |
| `vk_size`            | Free function | Type conversion                | Converts a type to the type Vulkan uses as a size type, aka `std::uint32_t`.              | N.A.                                                                                          |

### Generated

> [!NOTE]
> The facilities described below are directly generated from the Vulkan registry.
> See `py/code_generation/fubuki/generate/core.py`.

| Name                                                   | Type          | Category         | Description                                                                               | Notes                                          |
| ------------------------------------------------------ | ------------- | ---------------- | ----------------------------------------------------------------------------------------- | ---------------------------------------------- |
| `device_core_functions`                                | `struct`      | Vulkan functions | A structure holding an instance of each Vulkan core device function.                      | N.A.                                           |
| `instance_core_functions`                              | `struct`      | Vulkan functions | A structure holding an instance of each Vulkan core instance function.                    | N.A.                                           |
| `load(instance_handle, version_number)`                | Free function | Vulkan functions | Loads the Vulkan function pointers into a new instance of `instance_core_functions`.      | N.A.                                           |
| `load(instance_handle, version_number, device_handle)` | Free function | Vulkan functions | Loads the Vulkan function pointers into a new instance of `device_handle_core_functions`. | N.A.                                           |
| `operator!=(const vk_struct&, const vk_struct&)`       | Free function | Comparison       | Generated for all Vulkan structures defined in the C API that are not `union`.            | N.A.                                           |
| `operator<=>(const vk_struct&, const vk_struct&)`      | Free function | Comparison       | Generated for all Vulkan structures defined in the C API that are not `union`.            | N.A.                                           |
| `operator==(const vk_struct&, const vk_struct&)`       | Free function | Comparison       | Generated for all Vulkan structures defined in the C API that are not `union`.            | N.A.                                           |
| `to_string(vk_enum)`                                   | Free function | Type conversion  | Generated for all Vulkan `enum`s. Transforms a value into a `std::string`.                | **Not** available for `enum` masks (`VkFlags`) |
| `to_string_view(vk_enum)`                              | Free function | Type conversion  | Generated for all Vulkan `enum`s. Transforms a value into a `std::string_view`.           | **Not** available for `enum` masks (`VkFlags`) |

## Private API

> [!CAUTION]
> Facilities described here are **not** meant to be called directly by client code. 
> The **interfaces, the names and the very existence may change without notice**. 

| Name                                          | Type          | Category        | Description                                                                                                         | Notes |
| --------------------------------------------- | ------------- | --------------- | ------------------------------------------------------------------------------------------------------------------- | ----- |
| `detail::always_false`                        | Constant      | Helper          | A workaround for `static_assert(false)`.                                                                            | N.A.  |
| `detail::always_true`                         | Constant      | Helper          | Analogue to `always_false`.                                                                                         | N.A.  |
| `detail::collect::perform`                    | Free function | Type conversion | Convert a range of objects that can convert to a Vulkan handle into a `small_vector` of Vulkan handles.             | N.A.  |
| `detail::crc_table`                           | Constant      | Hash            | Compile-time hash table for `compile_time_hash`.                                                                    | N.A.  |
| `detail::deduce_type`                         | `struct`      | Helper          | A tag struct that can be used to indicate a parameter or a behaviour must be deduced from something.                | N.A.  |
| `detail::dummy_stream`                        | `struct`      | Helper          | Dummy type default-constructible used to replace std::ostringstream in constexpr evaluation of `fubuki::assertion`. | N.A.  |
| `detail::null_handle_type`                    | `struct`      | Vuklan handles  | Type-safe `VK_NULL_HANDLE`.                                                                                         | N.A.  |
| `traits::detail::pnext_chain::is_pnext_chain` | `struct`      | Traits          | Implementation of `traits::pnext_chain::type`                                                                       | N.A.  |

### Generated

> [!NOTE]
> The facilities described below are directly generated from the Vulkan registry.
> See `py/code_generation/fubuki/generate/core.py`.

| Name                                       | Type      | Category                       | Description                                                                                                       | Notes |
| ------------------------------------------ | --------- | ------------------------------ | ----------------------------------------------------------------------------------------------------------------- | ----- |
| `detail::compare::three_way_result`        | `struct`  | Traits, Comparison             | Used as part of the `operator<=>` provided for Vulkan C structures.                                               | N.A.  |
| `detail::get_from`                         | `struct`  | Traits                         | Used as part of Vulkan function name validation to call the correct function through `fubuki::invoke<"vkName">`.  | N.A.  |
| `detail::handle_traits`                    | `struct`  | Traits, Vuklan handles         | Traits that map `fubuki::handle`s to the Vulkan types, the functions to call to allocate/free them, etc.          | N.A.  |
| `detail::is_handle`                        | `struct`  | Traits, Vuklan handles         | Trait indicating if a type is an instance of `fubuki::handle` or one of its specialisation.                       | N.A.  |
| `detail::pnext_chain::chain_compatibility` | `struct`  | Traits, pNext chain validation | Parts of the traits to determine if two structures are compatible for `fubuki::extend`.                           | N.A.  |
| `detail::pnext_chain::chain_validator`     | `struct`  | Traits, pNext chain validation | Parts of the traits to determine if a structure can be used in a pNext chain for `fubuki::extend`.                | N.A.  |
| `detail::pnext_chain::make_parents`        | `struct`  | Traits, pNext chain validation | Parts of the traits to determine if two structures are compatible for `fubuki::extend`.                           | N.A.  |
| `detail::traits::valid_pfn_name`           | `concept` | Traits                         | Used as part of Vulkan function name validation to retrieve the correct function through `fubuki::pfn<"vkName">`. | N.A.  |
| `detail::traits::vk_function`              | `struct`  | Traits                         | Used as part of Vulkan function name validation to retrieve the correct function through `fubuki::pfn<"vkName">`. | N.A.  |
| `detail::vk_function_hash`                 | `struct`  | Helper                         | Mock to allow pfn<"vkStuff"> syntax.                                                                              | N.A.  |
