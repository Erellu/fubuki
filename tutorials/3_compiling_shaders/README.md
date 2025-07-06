# Fubuki tutorials: 03 - Compiling shaders

## Overview

Depending on your application, you are more or less likely to need a way to recompile your shaders on-the-fly. Typical applications include compensating a missing hardware feature by some code, or toggling some options in your lighting computations.

`hyoka` embeds [`glslang`](https://github.com/KhronosGroup/glslang), and provides an API to compile GLSL and HLSL shaders through `glslang`'s C++ API.

> [!NOTE]
> No symbol from `glslang` is exposed through `hyoka`.

## Basic usage

```cpp
const auto compiled_shader = hyoka::shader::compile
({
    .shader = {hyoka::shader::lang::..., source_code}, 
    .stage = hyoka::shader::stage::...
});

if(not compiled_shader)
{
    use(compiled_shader.error());
}
```

`compiled_shader` is an instance of `hyoka::shader::compiled`, which holds the SPIR-V binaries and (optionally) other debug information (logs, preprocessed source...) based on the information given to `hyoka::compile_shader`. See [`Options`](#options) below.

## Support for `#include`

`hyoka` performs on a `std::string` shader source, and therefore doesn't attempt to resolve `#include` directives by reading from the disk. Instead, `hyoka::shader_compile_info` accepts a `hyoka::shader_resource_group`, an associative container mapping file names to `hyoka::shader_source`s.

```cpp
const hyoka::shader::resource_group resource_group = 
{
    {"meow.glsl",       meow_glsl()  }, // Replaces #include "meow.glsl" or #include <meow.hlsl> by the value of 'meow_glsl()' at the shader preprocessing
    {"woof.struct",     woof_struct()},
    {"snake.glsl",      snake_glsl() },
    {"nested/wow.glsl", wow_glsl()   }, // 'Nested' path work as any other
};

hyoka::shader_compile_info i{..., .additional_resources = resource_group,};
```

> [!NOTE]
> `#include "xxx.hlsl"` and `#include <xxx.glsl>` are handled identically.

## Preprocessor `#define` directives

Additional `#define` directives can be added at the top of the shader (in GLSL, after the `#version` directive) through `hyoka::shader::preprocessor_define_directives`. Each `#define` is added in the order specified in this list

```cpp
const hyoka::shader::preprocessor_define_directives preprocessor_defines
{
    {"FOO",                    "22541"},
    {"HYOKA",                  "1"    },
    {"FUNCTION_LIKE_MACRO(x)", "x"    }
};

hyoka::shader::compile_info i{..., .preprocessor_defines = preprocessor_defines,};
```

Produces:

**GLSL:**
```glsl
#version ...
#define FOO 22541
#define HYOKA 1
#define FUNCTION_LIKE_MACRO(x) x

/* The rest of the shader source */
```

**HLSL:**
```hlsl
#define FOO 22541
#define HYOKA 1
#define FUNCTION_LIKE_MACRO(x) x

/* The rest of the shader source */
```

## Options

`hyoka::shader_compile_info` has several optional fields that can be used to influence the SPIR-V code generation, retrieve debug information and logs, ...
This section provides an overview of the different options available.

### Target API

| Member                         | Description                                      | Default |
| ------------------------------ | ------------------------------------------------ | ------- |
| `compile_info::vulkan_version` | The target Vulkan version for the SPIR-V binary. | `1.3.0` |
| `compile_info::spirv_version`  | The target SPIR-V version.                       | `1.6.0` |
| `compile_info::compatibility`  | Compatibility profile for the source code.       | `none`  |

### Source language-specific

| Member                                                  | Description                                                                                 | Default       |
| ------------------------------------------------------- | ------------------------------------------------------------------------------------------- | ------------- |
| `compile_options::dialect_version`                      | The default dialect when not provided through `#version` (GLSL).                            | `1.00` (100). |
| `compile_options::force_default_version_and_profile`    | Ignore `#version` and similar directives, use the value provided through `dialect_version`. | No            |
| `compile_options::forward_compatible`                   | Emits errors when using deprecated features.                                                | No            |

### Debug

| Member                             | Description                                                                                | Default |
| ---------------------------------- | ------------------------------------------------------------------------------------------ | ------- |
| `compile_options::messages`        | Specifies the nature of the compilation messages included the logs (when enabled).         | None    |
| `compile_options::include_source`  | Include the completely preprocessed source code in the resulting `hyoka::compiled_shader`. | No      |
| `compile_options::include_logs`    | Include compiler logs and warnings in the resulting `hyoka::compiled_shader`.              | No      |

### SPIRV

| Member                                                 | Description                                                                        | Default    |
| ------------------------------------------------------ | ---------------------------------------------------------------------------------- | ---------- |
| `compile_options::spv::generate_debug_info`            | Add debug information in the SPIR-V code. Equivalent to `glslang -g`               | `false`    |
| `compile_options::spv::strip_debug_info`               | Remove debug information from the SPIR-V code. Equivalent to `glslang -g0`.        | `false`    |
| `compile_options::spv::disable_optimiser`              | Disable optimisations on SPIR-V. Equivalent to `glslang -Od`.                      | **`true`** |
| `compile_options::spv::optimise_size                   | Optimise the size of the SPIR-V code. Equivalent to `glslang -Os`.                 | `false`    |
| `compile_options::spv::disassemble`                    | Output standard-form disassembly. Equivalent to `glslang --spriv-dis`              | `false`    |
| `compile_options::spv::validate`                       | Validate the SPIR-V code after generation. Equivalent to `glslang --spirv-val`.    | `false`    |
| `compile_options::spv::emit_non_semantic_debug_info`   | Generate non-semantic debug information. Equivalent to `glslang -gV`.              | `false`    |
| `compile_options::spv::emit_non_semantic_debug_source` | Generate non-semantic debug information with source. Equivalent to `glslang -gVS`. | `false`    |
| `compile_options::spv::compile_only`                   | Only compile shader; do not link (GLSL-only). Equivalent to `glslang --nolink`     | `false`    |

_______________________________________________

[Next tutorial](https://github.com/Erellu/fubuki/tree/master/tutorials/4_triangle)
