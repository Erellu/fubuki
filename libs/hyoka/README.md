# fubuki::hyoka

> [!IMPORTANT]
> This file is _not_ a substitue for the in-code documentation.
> Its goal is to advertise the features available through `fubuki::hyoka`.
> For examples and detailed documentation, see the `doxygen`.

## CMake

### Externally

```cmake
target_link_libraries(your_target <PUBLIC|PRIVATE> fubuki::hyoka)
```

### Internally

```cmake
fubuki_add_library(NAME                 target_name
                   PUBLIC_DEPENDENCIES  "hyoka"
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

`fubuki::hyoka` provides abstractions not directly related to Vulkan, meant to be higher-level than `fuyu`.

## Public API

### Shader compilation


> [!NOTE]
> These facilities are based on [`glslang`](https://github.com/KhronosGroup/glslang).
> `glslang` is available under the license [here](https://github.com/KhronosGroup/glslang/blob/main/LICENSE.txt).
> Note that Fubuki falls under the `Bison Exception`.

> [!NOTE]
> The following facilities are in **`fubuki::hyoka::shader`**.

| Name                             | Type          | Category                           | Description                                                                                          | Notes                                       |
| -------------------------------- | ------------- | ---------------------------------- | ---------------------------------------------------------------------------------------------------- | ------------------------------------------- |
| `compilation_message`            | `enum`        | Shader compilation, parameter      | Shader compiler messages to include upon errors.                                                     | N.A.                                        |
| `compilation_message_mask`       | Type alias    | Shader compilation, parameter      | Mask of   `compilation_message`                                                                      | N.A.                                        |
| `compile`                        | Free function | Shader compilation                 | Compiles a shader to SPIR-V.                                                                         | CAN `throw` an instance of `std::bad_alloc` |
| `compiled`                       | `struct`      | Shader compilation, result         | Result of `shader::compile`: SPIR-V binaries and additional information depending on the parameters. | N.A.                                        |
| `compile_error`                  | `struct`      | Shader compilation, error handling | Errors that can occur while compiling a shader.                                                      | N.A.                                        |
| `compile_info`                   | `struct`      | Shader compilation, input          | Parameters for `shader::compile`.                                                                    | N.A.                                        |
| `compile_options`                | `struct`      | Shader compilation, parameter      | Various compilation options.                                                                         | N.A.                                        |
| `group_cref`                     | Type alias    | Shader compilation, parameter      | `const` reference to a `resource_group`.                                                             | N.A.                                        |
| `lang`                           | `enum`        | Shader compilation, parameter      | Shader language                                                                                      | N.A.                                        |
| `preprocessor_define_directive`  | `struct`      | Shader compilation, parameter      | Preprocessor directives to add to the shader source before compilation.                              | N.A.                                        |
| `preprocessor_define_directives` | Type alias    | Shader compilation, parameter      | Array (`small_vector`) of `preprocessor_define_directive`.                                           | N.A.                                        |
| `profile`                        | `enum`        | Shader compilation, parameter      | Compatibility profile for the compiled shader.                                                       | N.A.                                        |
| `resource_group`                 | `struct`      | Shader compilation, parameter      | Shaders that can be used to resolve an `#include` directive.                                         | N.A.                                        |
| `source`                         | `struct`      | Shader compilation, input          | Shader source code and language.                                                                     | N.A.                                        |
| `stage::any`                     | Type alias    | Shader compilation, parameter      | Any shader stage.                                                                                    | N.A.                                        |
| `stage::compute`                 | Constant      | Shader compilation, parameter      | Indicates a shader source is executed as a compute shader.                                           | N.A.                                        |
| `stage::graphics`                | `enum`        | Shader compilation, parameter      | Indicates a shader source is executed during a stage of a graphics pipeline.                         | N.A.                                        |
| `stage::mesh`                    | `enum`        | Shader compilation, parameter      | Indicates a shader source is executed during a stage of a mesh shader pipeline.                      | N.A.                                        |
| `stage::ray_tracing`             | `enum`        | Shader compilation, parameter      | Indicates a shader source is executed during a stage of a ray tracing pipeline.                      | N.A.                                        |

> [!NOTE]
> See also: [Tutorial 03: Compiling shaders](https://github.com/Erellu/fubuki/tree/master/tutorials/3_compiling_shaders)
