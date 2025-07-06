# Fubuki's design notes and philosophy

> [!IMPORTANT]
> The following notes are for _developpers_.
> It does not provide any documentation of Fubuki's API.

The goal of this file is to describe how Fubuki is designed from a _high-level perspective_.

> [!CAUTION]
> This files is only **informative** and isn't meant to serve as a precise guide to dive into Fubuki's code base.

## Nomenclature

Each section name is followed by a tag of the format:

> **`[design.category.subcategory]`**

Use this to refer to a particular section when writing an issue. 
To refer to a particular point, use **`[design.category.subcategory#number]`**. 
For example: **`[design.philosophy.explicitness#1]`**  refers to the first design rule of the category "Philosophy" concerning explicitness.

## Philosophy `[design.philosophy]`

### Generalities `[design.philosophy.general]`

Overall, Fubuki attempts to stick to the following rules, detailed hereinafter in dedicated sections.

1. **Explicitness** (see `[design.philosophy.explicitness]`)
    - Fubuki doesn't hide what is does.
    - No action is performed unless explicitly tell Fubuki to do it.
2. **Idiomaticity** (see `[design.philosophy.idiomaticity]`)
    - Fubuki attempts to provide semantics that match what C++ programmers are used to.
    - The workflow to the GPU is meant to be the same as if done through the Vulkan C API.
3. **Responsibilise the user** (see `[design.philosophy.user]`)
    - Fubuki is designed to put the maximum amount of responsibility onto the user, _except_ regarding ownership.
    - Fubuki only perform minimal validation of the inputs forwarded to Vulkan.
4. **You don't pay for what you don't use** (see `[design.philosophy.overhead]`)
    - Fubuki _attempts_ to conform to C++'s [`Zero Overhead Principle`](https://en.cppreference.com/w/cpp/language/Zero-overhead_principle.html).
    - In practice, there is of course always overhead of some sort, but Fubuki attempts to amortise it.
5. **Interoperability** (see `[design.philosophy.interop]`)
    - Fubuki is designed to be as easy as sanely (and somewhat _safely_) integrate in an existing code base.

### Explicitness `[design.philosophy.explicitness]`

1. Fubuki doesn't hide what is does.

> **Rationale**:
> Fubuki attempts to reproduce the idioms of both Vulkan and C++ programming.
> Vulkan is a (very) explicit API, and Fubuki attempts to provide the same kind of interface, while abstracting in a "C++-ish" way.

2. Fubuki doesn't perform operations unless explicitly required to.

> **Rationale**:
> This matches the philosophy of Vulkan (and of low-level graphics API, for that matters). Note that this is _not_ a strict requirement: Fubuki sometimes allocate (temporary) CPU resources implicitly, for example, to perform conversion operations between `fubuki::handle` and Vulkan handles.
> Overall, Fubuki attempts to favour the _semantics_ of the operations.

3. Errors not ignorable.

> **Rationale**:
> A consequent chunk of bugs caused by C API comes from unchecked error codes (at least according to the authors experience).
> When using Vulkan through Fubuki, functions return an instance of `std::expected` that _must_ be handled. Constructors `throw`. Factory functions (`noexcept` equivalent of constructors) also return an `std::expected`, effectively forcing the caller to check if an error occurred.

### Idiomaticity `[design.philosophy.idomaticity]`

1. Fubuki attempts to provide semantics that match what C++ programmers are used to.

> **Rationale**:
> Vulkan is sometimes said to be _slightly_ verbose.
> Although I do not quite agree, I believe most of the verbosity comes from the syntax this API is forced to use... Because of C. Ignoring the problem of type names that cannot be shorted because no `namespace`, consider `VkGraphicsPipelineCreateInfo`. 
> This `struct` requires to create _separate_ instances of:
>`VkPipelineShaderStageCreateInfo`, `VkPipelineVertexInputStateCreateInfo`, `VkPipelineInputAssemblyStateCreateInfo`, `VkPipelineTessellationStateCreateInfo`, `VkPipelineViewportStateCreateInfo`, `VkPipelineRasterizationStateCreateInfo`, `VkPipelineMultisampleStateCreateInfo`, `VkPipelineDepthStencilStateCreateInfo`, `VkPipelineColorBlendStateCreateInfo`, `VkPipelineDynamicStateCreateInfo` (some are optional), and to take their address.
> Fubuki... Just uses one `struct`: `fuyu::graphics_pipeline::information::complements` (which type can even never be written, if used inline). One `struct` with `std::optional` members. That can be constructed separately (as for Vulkan), or not. The containing `struct` can be **copied**, **moved**, **swap**ped... With the expected behaviour.
> **Example**:
> All of `fubuki::fuyu::information`, all `fubuki::fuyu` objects (`instance`, `device`, `buffer`, ...)

2. The workflow to the GPU is meant to be the same as if done through the Vulkan C API.

> **Rationale**:
> Fubuki attempts to be friendly to C++ programmers, indeed.
> But Fubuki _also_ attempts to be friendly with _Vulkan_ programmers, regardless of the programming language.
> As such, the semantics of the abstractions presented in `fubuki::fuyu` are (almost) a 1-1 match to the Vulkan C API.

### User responsibility `[design.philosophy.user]`

1. Fubuki is designed to put the maximum amount of responsibility onto the user, _except_ regarding ownership.

> **Rationale**:
> As per `[design.philosophy.explicitness]`, Fubuki is an _explicit_ framework. By design, Fubuki _cannot_ endorse much responsibility over the entire application on its own that would require intrusive, hidden an implicit operations.
> On the other hand, Fubuki properly manages the resources used by its object, that are destroyed when `fubuki::<anything>` are destroyed.
> **Example**:
> Fubuki provides RAII semantics for (almost?) everything.
> Vulkan objects, platform-specific objects (see `io::wayland`), containers etc.

2. Fubuki only perform minimal validation of the inputs forwarded to Vulkan.

> **Rationale**: validation layers already perform such validations.
>
> **Example**:
> `fubuki::fuyu` usually only validates that the corresponding function pointer is loaded. This is done through `fuyu::invoke` and `fubuki::invoke`.

3. Fubuki doesn't attempt to put guards against modifications on the underlying handles (either from Vulkan, from Wayland, from Xlib, or any other platform-specific handles)

> **Rationale**: it is impossible to both guard and to provide `[design.philosophy.interop]`.
> For example, `std::unique_ptr` cannot guard against usage like `delete ptr.get();`.
> But it provides `unique_ptr::release` (and so do `fubuki::fuyu` abstractions) to _at least_ recover from doing such things.
>
> **Example**:
> All `fubuki::fuyu` have a `.handle()` member function, and convert to `views` that expose this handle. 
> The user must use this interface responsibly, as Fubuki makes the assumption all user _will_ be responsible.

4. Fubuki doesn't keep internal states when it's not absolutely necessary. In particular, the state of Vulkan objects provided through `fubuki::fuyu` is never kept.

> **Rationale**: since access to the underlying handles is possible, this would require keeping a state in sync with user code. This is a bad idea.
>
> **Example**:
> `fubuki::fuyu` objects don't have a `state()` member function (but they do know how they were allocated).
> On the over hand, `fubuki::io::window` _does_ provide a `state()`. 
> **It _may_ be put out-of-sync if the caller manipulates directly the underlying handles**.
> Keeping a state is unfortunately necessary for this construct (closed, hidden, etc.) by design.

### Overhead: You don't pay for what you don't use `[design.philosophy.overhead]`

1. Fubuki _attempts_ to conform to C++'s [`Zero Overhead Principle`](https://en.cppreference.com/w/cpp/language/Zero-overhead_principle.html).

> **Rationale**:
> The very goal of low-level graphics is to provide an API that can maximise the performance of the application through low-level control of the GPU and the CPU commands. Introducing unneeded overhead in Fubuki would not align with such goals.

> [!NOTE]
> `fuyu::information` and `fubuki::handle` obviously have a cost: the types are _not_ the underlying Vulkan ones.
> The feature in use here is _type safety_, that unfortunately has a runtime cost through allocations (**on the stack** in most cases).

### Interoperability `[design.philosophy.interop]`

1. It must be possible to switch between the abstractions provided by Fubuki and the ones provided by any other framework in any reasonable circumstances. In other words: it must be possible to integrate Fubuki in an existing infrastructure with a reasonable cost.
 
> **Rationale**:
> Introducing a new dependency is... A difficult decision. Especially for codebases written in C++ (and C).
> Transition has a cost, and even if the new dependency has wonderful features that could speedup the development time in the long run, if the transition would be too expensive, it _won't_ be performed.
> Fubuki is designed so favour **pass-by-view** ([see the style guide](https://github.com/Erellu/fubuki/tree/master/tutorials/doc/STYLE-GUIDE.md) for more about this, in particular `[style.cpp.semantics#1]`).
> The pass-by-view paradigm works _very_ well in functional approaches to mitigate the cost of transition from- and to a framework: the caller is never required to use the abstractions that own data (it can keep that as-is), is only needs to provide a valid _view_ of the contents to the API. Which is... Much simpler to obtain.
> For a similar reason, objects provided through `fubuki::fuyu` that wrap a Vulkan handle (`fubuki::fuyu::instance`, `fubuki::fuyu::device` and _all_ others) can work with handles allocated externally. They can take ownership over them, or just "borrow" them for their lifetime, facilitating the integration of such abstractions in an existing codebase. At the cost of _responsibility_.

