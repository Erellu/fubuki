# fubuki::maths

> [!IMPORTANT]
> This file is _not_ a substitue for the in-code documentation.
> Its goal is to advertise the features available through `fubuki::maths`.
> For examples and detailed documentation, see the `doxygen`.

## CMake

### Externally

```cmake
target_link_libraries(your_target <PUBLIC|PRIVATE> fubuki::maths)
```

### Internally

```cmake
fubuki_add_library(NAME                 target_name
                   PUBLIC_DEPENDENCIES  "maths"
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

`fubuki::maths` is a wrapper library around [`glm`](https://github.com/g-truc/glm).
It provides headers that silences all warning from this dependency, and aliases in the `fubuki` `namespace`.

## Public API

>[!NOTE]
> These facilities are based on [`glm`](https://github.com/g-truc/glm).
> `glm` is available under the license [here](https://github.com/g-truc/glm/blob/master/copying.txt), employed here according to the conditions of the MIT License.

| Name               | Type       | Category | Description                             | Notes |
| ------------------ | ---------- | -------- | --------------------------------------- | ----- |
| `<type>mat<n>x<m>` | Type alias | Helper   | `n`x`m` matrix holding `type`           | N.A.  |
| `size<n>x<m>`      | Type alias | Helper   | `n`x`m` matrix holding `std::size_t`    | N.A.  |
| `<type>vec<n>`     | Type alias | Helper   | `n`-length vector holding `type`        | N.A.  |
| `size<n>`          | Type alias | Helper   | `n`-length vector holding `std::size_t` | N.A.  |
