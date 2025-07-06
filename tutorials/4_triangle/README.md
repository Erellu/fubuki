# Fubuki tutorials: 04 - Triangle

## Overview

The infamous triangle on blue background, drawn through the facilities of `fubuki::fuyu` and `fubuki::hyoka`.

## Creating resources

### Global resources

The global resources (instance, device, window) are allocated through the facilities of `fubuki::tutorial::support`, similar to [Tutorial 02](https://github.com/Erellu/fubuki/tree/master/tutorials/2_vulkan_context).

`fubuki::tutorial::support::app::init` does the following:
- Creates a `fubuki::io::display`
- Creates a `fubuki::io::window`
- Creates an `fubuki::fuyu::instance`
- Creates a `fubuki::fuyu::surface` linked to the window
- Creates a `fubuki::fuyu::device`
- Creates a `fubuki::fuyu::swapchain` and its resources (`fubuki::fuyu::swapchain_resources`).

Because this tutorial uses Vulkan 1.3 _dynamic rendering_ (unconditionally), we provide a `pnext_chain` for the `fuyu::device`.

> [!NOTE]
> `fubuki::tutorial::support` **cannot** be linked with (it is not an exported target). Should the facilities be wanted in a user project, the user is required to manually integrate this code. 

```cpp
    namespace app = fubuki::tutorial::support::app;

    const auto app_resources_scope = app::init(
        {.display{}, .instance{}, .device{}, .swapchain{{.info = {.image = {.minimum_count = frames_in_flight}}}}},
        app::setup_pnext{.instance = fubuki::empty_pnext_chain,
                         .device   = fubuki::owning_pnext_chain{
                             VkPhysicalDeviceVulkan13Features{
                                   .sType                                              = {},
                                   .pNext                                              = {},
                                   .robustImageAccess                                  = false,
                                   .inlineUniformBlock                                 = false,
                                   .descriptorBindingInlineUniformBlockUpdateAfterBind = false,
                                   .pipelineCreationCacheControl                       = false,
                                   .privateData                                        = false,
                                   .shaderDemoteToHelperInvocation                     = false,
                                   .shaderTerminateInvocation                          = false,
                                   .subgroupSizeControl                                = false,
                                   .computeFullSubgroups                               = false,
                                   .synchronization2                                   = false,
                                   .textureCompressionASTC_HDR                         = false,
                                   .shaderZeroInitializeWorkgroupMemory                = false,
                                   .dynamicRendering                                   = true,
                                   .shaderIntegerDotProduct                            = false,
                                   .maintenance4                                       = false,
                             }}.chain()});

    if(not app_resources_scope)
    {
        do_something_with(app_resources_scope.error());
    }

```

### Other resources

When resources and their usage is known at compile time, grouping them by their usage usually allows to factorise the error reporting mechanism.

For example:

```cpp
struct resources
{
    struct synchronisation {...};
    struct commands        {...};
    struct drawing         {...};
    struct buffers         {...};

    synchronisation frame;   ///< Resources related to frames.
    commands        command; ///< Command pool and buffers.
    drawing         draw;    ///< Resources  related to the draw operations.
    buffers         buffer;  ///< Data to draw.
```

Can be obtained through a mechanism such like:

```cpp
[[nodiscard]] static std::expected<resources, fubuki::api_call_info> make(parameters p) noexcept
{
    auto sync = resources::synchronisation::make(...);

    if(not sync)
    {
        return std::unexpected{sync.error()}
    };

    auto com = resources::commands::make(...);

    if(not com)
    {
        return std::unexpected{com.error()}
    };

    ...

    return resources{*std::move(sync), *std::move(com), ...}
}
```

In which each `resources::xxx::make()` is implemented using the same paradigm.
This is what is illustrated through this example.

> [!TIP]
> `fubuki::fuyu` resources are _move-constructible_ , _move-assignable_ and _swappable_. They can therefore be used in _containers_ (Standard or user-provided) when the number is not known at compile time, while _still_ be grouped by functionality. This is illustrated through `resources::synchronisation`

## Swapchain

`fubuki::fuyu::swapchain` and `fubuki::swapchain_resources` provide an interface to handle `VkSwapchainKHR` and the associated resources.

A `swapchain`, the `image_view`s (and the associated `framebuffer`s) must be recreated when a `swapchain` is `out-of-date` (when a window was resized). This can be done in one call through `fubuki::fuyu::recreate`:

```cpp
// Recreate the swapchain and its resources, specify an extent, clamped to the limits of the surface
const auto success = fubuki::fuyu::recreate(swapchain, swapchain_resources, optional_extent); 

// Recreate the swapchain (but leave the old resources untouched), take the maximum extent allowed by the surface
const auto success = fubuki::fuyu::recreate(swapchain);

// Recreate the swapchain and its resources, with pnext chains
const auto success = fubuki::fuyu::recreate(swapchain, swapchain_resources, pnext_chain_swapchain, pnext_chain_resource);
```

## Command pipes

`fubuki::fuyu` provides the `command::pipe` `namespace`, which enables the user to write code similar to `std::ranges`,  by concatenating Vulkan commands.

> [!TIP]
> See also  [fuyu/command/README.md](https://github.com/Erellu/fubuki/tree/master/libs/fuyu/command/pipe/README.md) for more information about `command::pipe`.

```cpp

namespace cmd = fubuki::fuyu::command;

auto flow = cmd::pipe::record(command_buffer, VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT)
            | cmd::pipe::barrier( // Transition the render image to an adapted layout
                    cmd::image_memory_barrier {...},
                    cmd::barrier_stage        {...})
            | cmd::pipe::render_scope( // Introduce a dynamic rendering scope
                cmd::dynamic_render_target {...},
                [&](cmd::pipe::flow f) noexcept -> cmd::pipe::flow
                {
                    const VkViewport vp    {...};
                    const VkRect2D scissor {...};

                    return std::move(f)
                        | cmd::pipe::set::viewport(0, {vp})
                        | cmd::pipe::set::scissor(0, {scissor})
                        | cmd::pipe::bind::pipeline(graphics_pipeline)
                        | cmd::pipe::bind::vertex_buffer(0, vbo, 0)
                        | cmd::pipe::draw::call(6, 1, 0, 0);
                })
            | cmd::pipe::barrier( // Transition the swapchain to present image layout
                cmd::image_memory_barrier {...},
                cmd::barrier_stage        {...});
```

This `cmd::pipe::flow` can then be submitted to a `queue` the following way:

```cpp
if(flow.error())
{
    return std::unexpected{draw_error{*flow.error()}}; 
}

if(const auto check = cmd::pipe::submit(graphics_queue, std::move(flow), fubuki::fuyu::submission {...}); not check)
{
    return std::unexpected{draw_error{check.error()}};
}
```

## Handling errors

`fubuki::fuyu` functions report errors through `std::expected`. Most errors are instances of `fubuki::api_call_info`. _However_, other errors also exist to indicate more specific errors, such as a swapchain being out-of-date or a `command::pipe::flow` that could not be submitted.
Typically:

```cpp
    using swapchain    = fubuki::fuyu::presentation::error;
    using wait         = fubuki::fuyu::wait_error;
    using command_flow = fubuki::fuyu::cmd::pipe::error::any;
    using generic      = fubuki::api_call_info;
```

This can be typically factorised the following way (and scales with more error types):

```cpp
struct draw_error
{
    using swapchain    = fubuki::fuyu::presentation::error;
    using wait         = fubuki::fuyu::wait_error;
    using command_flow = fubuki::fuyu::cmd::pipe::error::any;
    using generic      = fubuki::api_call_info;
    // your errors go here
    using any          = std::variant<generic, wait, command_flow, swapchain /*your errors go here*/>;

    any value = {};

    template<typename char_type, typename traits = std::char_traits<char_type>>
    friend std::basic_ostream<char_type, traits>& operator<<(std::basic_ostream<char_type, traits>& out, const draw_error& error)
    {
        return std::visit([&out]<typename variant>(const variant& v) -> auto& { return out << v; }, error);
    }
};

[[nodiscard]]
std::expected<void, draw_error> draw(...) noexcept{...}
```

The client code can then be typically written as such:

```cpp
const auto r = draw(...);

// An error occurred
if(not r)
{
    // It is related to the swapchain
    if(const auto* const swapchain_error = std::get_if<draw_error::swapchain>(std::addressof(r.error().value)))
    {
        // The swapchain is out of date and must be recreated (the window got resized, etc.)
        if(error->value == out_of_date)
        {
            recreate_swapchain();
        }
        else
        {
            log(r.error());
        }
    }
    else
    {
        log(r.error());
    }
}
```
_______________________________________________

<!-- [Next tutorial](https://github.com/Erellu/fubuki/tree/master/tutorials/5_xxx)-->
