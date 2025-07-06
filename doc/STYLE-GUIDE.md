# Fubuki's style guidelines

> [!IMPORTANT]
> The following style guide is for _developpers_.
> It does not provide any documentation of Fubuki's API.

The goal of this file is to describe the least ambiguously possible the style in which Fubuki is written.
If you are interested in contributing to Fubuki, please conform to these guidelines.

> [!IMPORTANT]
> **These guidelines are not set in stone**.
> They are susceptible to change as C++ changes, as Vulkan changes, and as the author(s) deepen their understanding of the aspects of the framework.
> To discuss a guideline change, **please open an issue**.

## Nomenclature

This file uses the following nomenclature:

- **Use/Provide/Add/Be/(any verb)**: do that. No need to explain why you did this like that.
- **DO NOT use/provide/add/(_any verb_)**: don't do that. A contribution that does this is likely to be rejected. If done, will be asked to motivate the choices.
- **Prefer**: Attempt to do. Don't do if necessary, document why. Mostly related to design decisions.
- **Avoid**: attempt not to do. Do if necessary, document why. Mostly related to design decisions.

Each section name is followed by a tag of the format:

> **`[style.category.subcategory]`**

Use this to refer to a particular section when writing an issue. 
To refer to a particular point, use **`[style.category.subcategory#number]`**. 
For example: **`[style.cpp.semantics#1]`**  refers to the first style rule of the category "C++" concerning semantics.

## Language `[style.lang]`

1. **Code** in English.
2. **Comment** in English.
3. **Prefer** British English.
4. **Avoid** any kind of vulgarism in both code and comments.

## Formatting `[style.format]`

### Generalities `[style.format.general]`

1. **Use** `clang-format` with the provided `.clang-format`
2. **Use** `//clang-format off`/`//clang-format on` tags when the formatted code is not readable as-is. 

> Example:
> ```cpp
> // Bad, hard to tell the groups apart
> bool all_conditions_met(const T& a, const T& b) noexcept
> {
>     return a.meow() or (b.bark() and a.big()) or (b.small() and b.white() and a.green() and a.big());
> }
>
> // Better, possible to visually split the logical groups
> bool all_conditions_met(const T& a, const T& b) noexcept
> {
>     // clang-format off
>     return a.meow()
>            or (b.bark() and a.big()) 
>            or (b.small() and b.white() and a.green() and a.big());
>    // clang-format on
> }
> ```
3. **DO NOT** abuse `//clang-format off`/`//clang-format on` to manually format code according to a different style guide.
4. **Use** `and`, `or`, `not` tokens for boolean logic.
5. **DO NOT use** `&&`, `||`, `!` for boolean logic, _except_ when working with the preprocessor.
6. **DO NOT use** `and` for forwarding references. Use `T&&`.
7. **DO NOT** use Hungarian notation. Give meaningful names instead.
8. **Use** `clang-tidy` for complementary formatting rules.

### Preprocessor `[style.format.preprocessor]`

1. **Use** include guards.
2. **DO NOT use** `#pragma once`.
3. **Do** name include guards according to the path of the file.
    - Examples:
        - `libs/fuyu/meow.hpp` -> `FUBUKI_FUYU_MEOW_HPP`
        - `libs/core/bark.hpp` -> `FUBUKI_FUYU_BARK_HPP`
        - `test/core/pss.hpp` -> `FUBUKI_CORE_TEST_PSS_HPP`
4. **Do** `#undef` macros before the end of the file if they are not meant to be used outside.
5. **Avoid** macros leaking outside the file they are `#defined`.
6. **Do** prepend `FUBUKI_` (or `fubuki_`) to all preprocessor identifiers.

### Case `[style.format.case]`

1. **Use** `snake_case` for _everything_ unless specified otherwise.
2. **Use** `SCREAMING_SNAKE_CASE` for include guards.
3. **Use** `SCREAMING_SNAKE_CASE` for file-local macros (that are `#undef`ed before the end of the file).
    - Examples: `FUBUKI_MAKE_HANDLE(...)`, `FUBUKI_MAKE_PFN(...)`
4. **Use** `snake_case` for macros still `#define`d after the end of the file.
    - Examples: `fubuki_assert(...)`, `fubuki_validate(...)`
5. **Use** `// NOLINT(readability-identifier-naming)` when forward-declarating external types and functions.

### File extensions `[style.format.file]`

1. **Use** `.cpp` for C++ source files.
2. **Use** `.hpp` for C++ header files.
3. **Use** `.c` for C source files.
4. **Use** `.h` for C header files.
5. **Use** `.cu` for CUDA source files.
6. **Use** `.cuh` for CUDA header files.
7. **Use** `.md` for Markdown files.
8. **Use** `.py` for Python files.
9. **Use** `.cmake` for CMake files that are not `CMakeLists.txt`
10. **Use** `.in` for template files used to generate code.
    - **Use** the extension the generated file will have before adding `.in`.
    - Example: `enum.cpp.in`: a template file used to generate a C++ source file related to `enum`s.
11. **Use** `.txt` for raw text files.

## C++ Coding `[style.cpp]`

### Generalities `[style.cpp.general]`

1. **Use** C++23.
2. **Use** the Standard Library.
3. **DO NOT** write C-style code.
4. **Use** the containers provided by the Standard Library.
5. **Prefer** contiguous-memory containers.
6. **Prefer** `fubuki::small_vector` as a default-container.
7. **Use** RAII.
8. **Avoid** RTTI if there is a sane compile-time alternative.
9. **Use** RTTI otherwise.
10. **Use** `const`.
11. **Be** `const`-correct.
12. **Avoid** use `volatile`.
13. **Prefer** literals over braces-init when available.
14. **Prefer** braces-init over `()`-init.
    - Exceptions: code causing [MSVC warning C4868](https://learn.microsoft.com/en-us/cpp/error-messages/compiler-warnings/compiler-warning-c4868?view=msvc-170)

### Dependencies `[style.cpp.deps]`

1. **Avoid** extra dependencies, or open an issue to discuss it.
2. **DO NOT** expose headers from dependencies in Fubuki's headers.
    - Exception: Vulkan headers.
    - Exception: `io::platform` headers providing `constexpr` conversion between `enum` types. Such Fubuki headers **MUST NOT** be exposed in other headers.
3. **Use** forward declarations for external types.
    - Example: `core/detail/platform_forward.hpp`.
    - Exception: `io::platform` headers providing `constexpr` conversion between `enum` types. Such Fubuki headers **MUST NOT** be exposed in other headers.
4. **DO NOT** forward declare external functions in header files.
    - Exception: `io::platform` headers providing RAII resource handling that needs to call a custom `free`/`delete` from an external library (e.g., Xlib).
5. **Do** silence dependencies warnings.
    - Examples: `maths/*.hpp`, `io/platform/wayland/interface.hpp`, `hyoka/compile.cpp`.

### Compiler diagnostic policy `[style.cpp.diagnostic]`

1. **Avoid** warnings.
2. **DO NOT** remove warnings from the current setup, or open an issue to discuss that.
3. **DO NOT** ignore compiler warnings.
4. **DO NOT** silence warnings, unless there is no other way to avoid them.
5. **ALWAYS** document why a warning is locally disabled through a comment.

### Static analysis `[style.cpp.static-analysis]`

1. **Use** `clang-tidy` with the setup provided by the `.clang-tidy` file at the top of the project
2. **DO NOT** ignore static analysis warnings.
3. **DO NOT** silence warnings, unless there is no other way to avoid them.
4. **ALWAYS** document why a warning is locally disabled through a comment.

### Documentation `[style.cpp.doc]`

1. **Provide** [doxygen](https://www.doxygen.nl/)\-style comments for in-code documentation.
2. **Add** newly-added features to the existing documentation in per-lib `README.md`.
    - Exceptions:
        - Any generated function, e.g., `core/enum/*` defines `to_string_view` and `to_string` for every `enum`s. A word about that is enough.
        - `fubuki::extension`, which is mostly generated from the registry.
3. **Use** `@` as the doxygen tag delimiter (`@param`, etc.)

### Namespace `[style.cpp.namespace]`

1. **Use** `namespace`s.
2. **DO NOT** use `using namespace` outside functions scopes.
3. **Use** `using namespace` in functions scopes.
4. **Prefer** `using meow::func` over pulling the entire `namespace meow`.
5. **Prefer** `namespace short = external::very::long::name::that::could::be::shorten;` over pulling the entire `namespace`.
6. **Use** anonymous `namespace` to define functions with internal linkage in source files.
7. **DO NOT** use anonymous `namespace`s in header files.

### Semantics `[style.cpp.semantics]`

1. **Prefer** pass-by-view.

> Example:
> ```cpp
> // Bad, forces the caller to use a specific container.
> auto meow(const std::vector<int>& v) noexcept
> {
>     return do_something_with(v);
> }
>
> // Better, the caller can use any contiguous storage, like fubuki::small_vector.
> auto meow(std::span<const int> v) noexcept
> {
>     return do_something_with(v);
> }
> 
> //-----------------------------------------------------------------------------
> 
> struct data
> {
>     fubuki::small_vector<fubuki::vec3> vertices = {};
>     fubuki::small_vector<std::size_t>  indicies = {};
> };
> 
> // Bad: forces the caller to use struct data because it uses owning containers.
> // Callers that used an equivalent representation from another library or internal code cannot use
> // this API directly, because it requires refactoring to change the ownership model.
> void process(const data&) noexcept;
> 
> //-----------------------------------------------------------------------------
> 
> struct data
> {
>     fubuki::small_vector<fubuki::vec3> vertices = {};
>     fubuki::small_vector<std::size_t>  indicies = {};
>
>     struct mutable_view
>     {
>         std::span<fubuki::vec3> vertices = {};
>         std::span<std::size_t>  indicies = {};
>     };
>
>     struct const_view
>     {
>         std::span<const fubuki::vec3> vertices = {};
>         std::span<const std::size_t>  indicies = {};
>     };
>
>     [[nodiscard]] operator mutable_view() noexcept{ ... }
>     [[nodiscard]] operator const_view() const noexcept{ ... }
> };
> 
> // Better: caller can use a custom type to hold the data (custom allocators, etc.) and can still use the API
> // by simply filling a view, even if the data is not stored in a struct data, but in an equivalent representation in existing code.
> void process(data::mutable_view d);
> void process(data::const_view d);
> ```

2. **DO NOT** pass owning objects as functions parameters.
    - Rationale: this forces an ownership model over the user.
    - Instead: pass views when possible.
3. **DO NOT** pass raw pointers.
    - Rationale: can they be `nullptr`? Do they refer to an array or a single element? Must I `delete` or `free` it in the function?
    - Instead:
        - Pass views of the underlying content when possible.
        - Pass wrapper `struct`s when forwarding parameters to a C API that at least expresses the intent.
        - Pass a reference or `std::optional` or `std::optional<reference_wrapper>` to pass an optional.
4. **DO NOT** pass references to smart pointers as functions parameters.
    - Rationale: this forces an ownership model over the user.
    - Instead: pass references instead of smart pointers for functions processing the input otherwise.

> Example:
> ```cpp
> // Bad, forces the caller to use a specific container.
> // Bad, actually like passing T* const and not const T*.
> auto meow(const std::unique_ptr<data>& v) noexcept
> {
>     return do_something_with(v);
> }
>
> // Better, the caller can allocate on the stack, on the free store through unique_ptr, use a shared ownership model with shared_ptr, etc.
> auto meow(const data& v) noexcept
> {
>     return do_something_with(v);
> }
>
> // Ok, meant to transmit the ownership
> auto bark(std::unique_ptr<interface> d) 
> {
>     return object{std::move(d)};
> }
> ```

5. **Avoid** shared ownership models and `shared_ptr`, unless you are implementing an allocator
6. **Prefer** data-oriented APIs over polymorphic objects.
    - Rationale: such interfaces _compose_ better and express intent in the workflow.
        - This _does not_ mean polymorphism is banned in this code base.
7. **Avoid** `virtual` functions.
    - Rationale: pass-by-view data-driven API are more likely to need _predicates_ defined on-the-fly through capturing lambdas.
    - Instead:
        - Prefer `template`d user-defined predicates as `template<typename predicate, typename... args> requires(std::invocable<predicate, args...>) auto meow(data d, predicate&& p, args&&... a) noexcept(...){...}`
        - Prefer `fubuki::move_only_function` or `std::function`.
    - Exceptions: when implementing an interface object (example: `io::event::handler`).
8. **Prefer** composition over inheritance.
9. **Use** `private` inheritance _if_ it simplifies the code.
10. **Use** inheritance to share common members and behaviour between objects. (example: `fuyu::parent::detail::base`).
11. **Prefer** `noexcept` move assignment and construction. 
    - Exceptions: when implementing containers. Then, the `noexcept`ness must depend on the stored type.
12. **DO NOT** provide implicit conversion `operator`s to primitive types.
13. **DO NOT** provide multiple implicit conversion `operator`s to potentially conflicting types

> Example:
> ```cpp
> // Bad, conversion to primitive types
> // Bad, these implicit conversion may conflict and produce ambiguous function call errors at best, or call the wrong function at worst
> struct bad
> {
>     operator int() const noexcept{return 0;}
>     operator float() const noexcept{return 0.1f;}
> };
>
> // Better, conversions are explicit and cannot conflict
> struct better
> {
>     explicit operator int() const noexcept{return 0;}
>     explicit operator float() const noexcept{return 0.1f;}
> };
>
> // Best: conversions to type-safe unambiguous types.
> // Operators can be implicit or explicit based on the needs.
> struct best
> {
>     struct integer{int value = {};};
>     struct floating{float value = {};};
>
>     operator integer() const noexcept{return {0};}
>     operator floating() const noexcept{return {0.1f};}
> };
> ```

14. **DO NOT** pass type-unsafe C handles.
    - Instead: pass wrapper `struct`s.

> Example:
> ```cpp
> // Bad, may be called like bad(0) and does not express type or intent.
> auto bad(int fd)
> {
>     c_api_do_something_with(fd);
> };
>
> struct fd_handle
> {
>     explicit(int h) noexcept : value{h}{}
>
>     int value = {};
>
>     // swap, operator==, operator!=, operator<=>, 
>     // If rule of 5: copy, move, destructor (all =default for view/like types)
> };
>
> // Better, calls are of the form better(fd_handle{an_int}) and expresses both type and intent
> auto better(fd_handle fd)
> {
>     c_api_do_something_with(fd.value);
> };
> ```

15. **Use** dev-defined aggregates to pack data by meaning.
16. **DO NOT** use `std::pair` or `std::tuple` to pack data in one object.

> Example:
> ```cpp
> auto bad_default_pool_size() noexcept
> {
>     // Bad, the reader can't tell what corresponds to what
>     return std::make_tuple(0, 1, 2, 4, 5 , 6);
> }
> 
> struct pool_size
> {
>     std::uint32_t sampler                = {};
>     std::uint32_t combined_image_sampler = {};
>     std::uint32_t sampled_image          = {};
>     std::uint32_t storage_image          = {};
>     std::uint32_t uniform_texel_buffer   = {};
>     std::uint32_t storage_texel_buffer   = {};
> 
>     // swap (optional here), ==, !=, <=>
> };
> 
> auto good_default_pool_size() noexcept
> {
>     // Better: members are named, the reader can directly tell what number corresponds to what.
>     return pool_size
>     {
>         .sampler                = 0,
>         .combined_image_sampler = 1,
>         .sampled_image          = 2,
>         .storage_image          = 4,
>         .uniform_texel_buffer   = 5,
>         .storage_texel_buffer   = 6
>     };
> };
> ```

17. **Avoid** passing more than **7** parameters to a function or a constructor.
    - Instead: **prefer** `struct`s with named members.
    - Rationale: this expresses intent, and avoids having to remember to order of argument.
18. **Avoid** parameters with types that can be converted from one another
    - Exceptions: functions that must fit a certain signature to match an external API (Wayland, etc.)

### Error handling `[style.cpp.errors]`

1. **DO NOT use** exceptions as the primary way to report errors.
2. **Prefer** `std::expected` if reasonable.
3. **Do** always provide a `noexcept` equivalent a function that can `throw` or fail.
4. **Do** implement the throwing version in terms of the `noexcept` one when possible, and avoid the opposite.

> Example:
> ```cpp
> [[nodiscard]] std::expected<result, error> process(arg x) noexcept;
>
> [[nodiscard]] inline auto process(fubuki::detail::validate_by::throw_call_exception, arg x)
> {
>     auto r = process(x);
>
>    if(not r)
>    {
>        throw call_exception{r.error()};
>    }
>
>    return *r;
> }
> ```

5. **Do** mark functions `noexcept` when relevant.
6. **DO NOT** mark functions `noexcept` if they can `throw`, **unless** it signifies an internal error that is not recoverable on the caller-side.

### Assertions `[style.cpp.assert]`

1. **Use** `fubuki_assert` and `fubuki_always_assert` to respectively trigger assertions in debug only, and both in debug and release builds. 
2. **Use** `fubuki_assert` to validate input that **signifies a developper error**.
3. **Use** a `return std::unexpected{...}` statement after an assert when the error is not fatal **or** could occur from non-dev error.
4. **DO NOT** validate through `fubuki_assert` user input.
5. **Avoid** `fubuki_always_assert` to validate **dev** and **user** input.
    - Instead: **prefer** `std::expected`.
6. **Avoid** `fubuki_always_assert` unless it guards an internal error that cannot be recovered from the user-side.
7. **DO NOT** put code in `fubuki_assert`.

### Validation `[style.cpp.validation]`

1. **Prefer** `fubuki_validate(fubuki::validate_by::expected, expression)` to other variants of `fubuki_validate`.
2. **Use** `fubuki::call_info` to give information about a call that failed.
3. **Prefer** wrapping `call_info` in a `struct` giving a meaningful name (example: `error::api_call`).
    - Exception: code `fubuki::fuyu` should return `api_call_info` on error.
4. **Provide** a string literal of the call that failed when not using `fubuki_validate` as part of the `call_info<T>`.

### `class` and `struct` `[style.cpp.class]`

1. **Use** `struct` for objects which all members are `public`.
2. **Use** `class` for objects with at least one `private` or `protected` member.
3. **Avoid** `protected` members.
4. **Use** `friend operator` for `==`, `!=`, `<=>`.
5. **Use** `=default` for constructors and `operator`s that qualify.
6. **Avoid** `throw`ing from destructors.
7. **Use** exceptions when a constructor fails.
8. **Use** a factory function with matching parameters that returns `std::expected<T, error>` named `make` to provide an alternative to the caller.
9. **DO NOT** provide a factory `make` if the matching constructor is `noexcept` and cannot `throw`.
10. **DO NOT** use `public` partial constructors.
11. **DO NOT** call `virtual` functions from constructors.
12. **Provide** `swap` as `void swap(T& other) noexcept` and `friend void swap(T& a, T& b) noexcept{ return a.swap(b); }`.
13. **Add** `constexpr` qualifers when possible.
14. **Provide** functions defintions where they are declared **if** they are short or do not perform algorithmic logic.
15. **Use** designated initialisers whenever possible.
16. **Avoid** keeping references to other objects.
    - Exceptions: objects can keep references to `fuyu::instance` and `fuyu::device`.
    - Objects that keep references to `fuyu::instance` or `fuyu::device` **must** provide a `rebind(parent p) noexcept` member function and `friend rebind(T&, parent p) noexcept`.
17. **Avoid** objects with ownership over more than one _handle_ of an external API (`VkBuffer`, `wl_display`, etc.).

### `constexpr`, and `inline` `[style.cpp.constexpr]`

1. **Use** `constexpr`.
2. **DO NOT** use `constexpr` when you meant `inline`.
3. **Use** `inline` for short functions or functions that do not perform algorithmic logic (construction of several objects and returning them in a object that packs them, etc.).
4. **DO NOT** add `inline` to `class` or `struct` member functions defined in the body of the `class`/`struct`. They alrerady are.

### `template`s `[style.cpp.template]`

1. **Use** `template`s for generic code.
2. **DO NOT** use `template`s for the sake of templating.
3. **Use** `concept`s to constrain `template`s.
4. **DO NOT** over-constrain `template`s.
5. **DO NOT** use SFINAE-style `std::enable_if` to "constrain" a `template`.

### Globals `[style.cpp.globals]`

1. **Avoid** non-`const` globals.
2. **Use** a mutex to guard access to non-`const` globals.
3. **Use** functions in an anonymous `namespace` to allocate globals.

> Example:
> ```cpp
> namespace
> {
>
> [[nodiscard]] auto& storage() noexcept
> {
>     static small_vector<int> s;
>     return r;
> }
>
> } // anonymous namespace
> ```

4. **DO NOT** put non-`const` globals accessible in headers.

> Example:
> ```cpp
> namespace
> {
>
> [[nodiscard]] auto& storage() noexcept
> {
>     static small_vector<int> s;
>     return r;
> }
>
> [[nodiscard]] auto& sync() noexcept
> {
>     static std::mutex m;
>     return m;
> }
>
> // Alternatively:
> [[nodiscard]] auto& globals() noexept
> {
>     struct type
>     {
>         small_vector<int> storage = {};
>         std::mutex        sync    = {};
>     };
>
>     static type s = {};
>
>     return s;
> }
>
> } // anonymous namespace
>
> // Public interface, functions defined in the corresponding header
> [[nodiscard]] void push(int i) // Not noexcept, may throw. Mark noexcept ONLY if a failure is not recoverable
> {
>    {
>         const std::scoped_lock<std::mutex> _(sync());
>         storage().push_back(i);
>    }
>    // Alternatively:
>    {
>         auto& [storage, sync] = globals();
>         const std::scoped_lock<std::mutex> _(sync);
>         storage.push_back(i);
>    }
> }
> ```

### Memory allocation `[style.cpp.memory]`

1. **Prefer** `fubuki::small_vector` as a default container.
    - Rationale: `small_vector` is `std::vector` with SBO (Small Buffer Optimisation). It doesn't allocate on the free store (heap) unless it reaches a certain size in bytes.
2. **Prefer** providing two overloads of functions that may allocate: one that uses a dynamic buffer (`small_vector`) and one that requires user-defined storage.
3. **DO NOT** over-pessimise the cost of dynamic allocation and attempt to cover by accepting user-defined allocators.
4. **DO NOT** provide `template` parameters for user-defined allocators to functions, **unless** you are implementing a container.
    - Instead: pass a view.
5. **Do** provide a `template` parameter for user-defined allocators if you are are implementing a container.
6. **Avoid** implementing new containers.
7. **Avoid** `fubuki::md_vector` unless the underlying API expects a `T**` (or with more levels of indirection).
    - Instead: use `std::mdspan` over a container or the types defined `fubuki::maths`.
8. **DO NOT** call `new` or `malloc` directly.
    - Instead: use a RAII container or a smart pointer.
9. **Do** wrap third-party C APIs owning pointer in a corresponding `unique_ptr`.
    - Example: `fubuki::io::platform::linux_bsb::xlib::unique_ptr`

## Vulkan `[style.vk]`

### Headers `[style.vk.headers]`

1. **DO NOT** `#include <vulkan/anything.h>`.
    - Instead: `#include <core/vulkan.hpp>`

### Handles `[style.vk.handles]`

1. **DO NOT** use "raw" handles `VkBuffer`.
    - Instead: use `core/handle.hpp"` and wrappers like `buffer_handle`.

### Functions `[style.vk.functions]`

1. **DO NOT** use functions defined in Vulkan headers.
2. **DO NOT** call `vkGetInstanceProcAddr` or `vkGetDeviceProcAddr`.
    - Instead: use `fubuki::pfn<"vkFunctionName">(...)`.
3. **Avoid** directly calling the members of `struct`s wrapping Vulkan  function pointers. 
    - Instead: **Use** `fubuki::invoke<"vkFunctionName">(...)` and `fuyu::invoke<"vkFunctionName">(...)`

### Validation `[style.vk.validation]`

1. **Use** `fubuki_validate(fubuki::validate_by::expected, expression)` to validate an operation that returns `VkResult`.
