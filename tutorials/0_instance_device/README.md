# Fubuki tutorials: 00 - Instance and device

## Overview

This tutorial explains how to create a Vulkan instance and a Vulkan logical device through `fubuki::fuyu`.

> [!NOTE]
> Fubuki is designed so that it only performs on _`views`_. However, `fuyu::instance` and `fuyu::device` are two exceptions to this rule. 
> Note also that, technically, you could restrict the use of `fuyu` objects to these two, and use another framework for all the other handles (`VkBuffer`, `VkImage`, etc.), and construct `fuyu::views` on-the-fly.


## Using`fuyu`

### General workflow

Unlike frameworks that introduce a global context, similar to OpenGL, there is no such notion in Fubuki.
Overall, the API is designed so that the workflow is **identical** to what one would do using Vulkan's C API.
[Tutorial 02](https://github.com/Erellu/fubuki/tree/master/tutorials/2_vulkan_context) explains how an application can setup its own context (handles that need to be accessible through all the application), but this _has_ to be implemented explicitly.

### Error handling

`fuyu` offers the possibility to handle errors by two mechanisms (but not at the same time).

#### Construction

Constructors that fail because of an API call `throw` instances of `api_call_exception`.

```cpp
// May throw an instance of api_call_exception if an API call failed
const auto instance = fuyu::instance{...};
```

But all objects can be constructed through there respective `make` function, which returns an instance of `std::expected<the_object, api_call_info>`:

> [!NOTE]
> `fuyu::xxx::make` functions are **not** necessarly `noexcept`.
> Most of them are, but some **can** throw an instance of `std::bad_alloc` if an allocation of (temporary) host resource failed.

```cpp
// std::expected<fuyu::instance, api_call_info>
// CAN throw std::bad_alloc if host allocation failed
const auto instance = fuyu::instance::make(...);

if(not instance)
{
    log(instance.error());
    crash();
}
```

#### Functions

All functions that return a `VkResult` in their Vulkan version (`vkGetSomething(...)`) return an `std::expected` in `fuyu`.

> [!NOTE]
> These functions are **not** necessarly `noexcept`.
> Most of them are, but some **can** throw an instance of `std::bad_alloc` if an allocation of (temporary) host resource failed.

```cpp
// Vulkan
if(const auto r = vkResetFences(device, 1, std::addressof(fence)); r != VK_SUCCESS)
{
   std::cerr << r;
}

// fuyu
if(const auto r = fuyu::reset(fuyu::fence_view{...}); not r)
{
   std::cerr << r.error();
}
```

### Creating and instance and a device

- `[1]`: We first start by checking what are the Vulkan extensions supported for the instance on the current platform. This is useful if you need to support various GPUs and are not really sure of what it can do. Note that you may refer to [vulkan.gpuinfo.org](http://www.vulkan.gpuinfo.org/) for information about most GPUs on the market.

```cpp
const auto extensions = fuyu::hardware::supported_instance_extensions();

if(not extensions.has_value())
{
    std::cout << "An error occurred while fetching available extensions: " << extensions.error();
    return 1;
}

const auto layers = fuyu::debug::layers();

if(not layers.has_value())
{
    std::cout << "An error occurred while fetching available validation layers: " << layers.error();
    return 1;
}
```

- `[2]`: Provide the required information to the constructor of `fuyu::instance` (or to `fuyu::instance::make` for an equivalent returning `std::expected` upon failure):

```cpp
const fuyu::instance instance{
    {.application = {.name           = "Tutorial 00: instance and device",
                     .version        = {1, 0, 0},
                     .vulkan_version = {1, 3, 0},
                     .engine         = {.name = "Engine", .version = {1, 3, 0}}},
     .flags       = {},
     .callbacks   = {}},
    {
     .layers     = {"VK_LAYER_KHRONOS_validation"},
     .extensions = {},
     }
};
```

> [!TIP]
>**It is safe to ask for unsupported validation layers and extensions** as they will be removed when parsing the information. Note that you then WANT to check your application still works without them, or write manual fall-backs. Both `fuyu::instance` and `fuyu::device`
 support an argument of type `fuyu::unsupported_features`, that indicates when an extension was not available.

- `[3]`: Load Vulkan function pointers. By default, only _some_ functions available through Vulkan headers can be called from the prototype available in `vulkan_xxx.h`.

> [!TIP]
> This is done _automagically_ for all Vulkan functions, from core features and extensions, for both instance and device functions.
> The function pointers are accessible through `instance::function()` (resp. `device::function()`), and are sorted per version and extensions:

```cpp
const auto& device_functions      = device.function();
const auto& vk10                  = device_functions.core.vk10;
const auto& khr_dynamic_rendering = device_functions.ext.khr_dynamic_rendering; // unique_ptr, nullptr when not loaded
```

- `[4]`: You need to specify which GPU you will use for the logical device we will create. This tutorial uses the first one available, but most of the time, it's required to select a device based on its properties.

```cpp
const auto physical_devices = fuyu::hardware::physical_devices(instance);

if(not physical_devices.has_value())
{
    std::cout << "An error occurred while retrieving the devices  " << physical_devices.error();
    return 1;
}

const auto find_the_perfect_device = [&instance](const fubuki::physical_device_handle h) noexcept
{
    const auto properties = fuyu::hardware::physical_device_information(instance, h);

    if(properties)
    {
        return properties->vk11.storageBuffer16BitAccess 
               and properties->vk12.timelineSemaphore
               and ...;
    }

    return false;
};

const auto the_perfect_device = std::ranges::find_if(*physical_devices, find_the_perfect_device);

if(the_perfect_device == physical_devices->end())
{
    std::cerr << "No available device matches this application requirements.";
    return 1;
}
```

- `[5]`: Fill the remaining information required to construct a `fuyu::device`:
```cpp
const fuyu::device device(instance,
                          physical_device,
                          { /*fuyu::device::information only set debug markers and allocation callbacks*/ },
                          {.queues     = {{
                                              .type     = VK_QUEUE_GRAPHICS_BIT,
                                              .flags    = {},
                                              .priority = +0.f,
                                      },
                                          {
                                              .type     = VK_QUEUE_COMPUTE_BIT,
                                              .flags    = {},
                                              .priority = +0.f,
                                      }},
                           .extensions = {VK_KHR_DEFERRED_HOST_OPERATIONS_EXTENSION_NAME, VK_KHR_SWAPCHAIN_EXTENSION_NAME},
                           .surfaces   = {},
                           .features   = {}},
                          device_unsupported_features);
```

- `[6]`: Queues created when the device is constructed can be retrieved using `device::queues()`.

```cpp
// All queues created
for(const auto& q : device.queues().all)
{
    do_something_with(q);
}

// Only queues that can render to surfaces provided to the constructor of fuyu::device
for(const auto& q : device.queues().presentable)
{
    do_something_with(q);
}
```

### `pNext` chains

Use `fubuki::pnext_chain` or `fubuki::owning_pnext_chain` when it is required to extend the information, for example, to enable features on the device.

> [!TIP]
> The contents of `pnext_chain`s are **validated at compile-time**.

## External handles

All `fuyu` objects (`fuyu::instance`, `fuyu::device`, `fuyu::buffer`...) have constructors (resp. `static auto make(...)`) accepting an instance of `fuyu::external_handle`.
**These are meant to be used when several APIs need to work together**, and when it is not necessarily possible to allocate through `fuyu`. Typically:

```cpp
// Non-owning, non RAII Vulkan handle allocated through third-party code
VkBuffer vk_buffer = external_api::make_buffer(...); 

// owning_buffer will destroy vk_buffer when its destructor runs
fuyu::buffer owning_buffer{{fuyu::take_ownership{buffer_handle{vk_buffer}}}, device, fuyu::information::buffer{...}};

// borrowing_buffer will NOT destroy it when its destructor runs
fuyu::buffer borrowing_buffer{{fuyu::borrow{owning_buffer.handle()}}, owning_buffer.device(), owning_buffer.info()};
```

> [!TIP]
> It's also possible to allocate through `fuyu` and to free through another API. All objects have a `release()` member function, that returns a `fuyu::owning_view` holding its handle, and telling the object to "forget" about the handle it had.

_______________________________________________

[Next tutorial](https://github.com/Erellu/fubuki/tree/master/tutorials/1_window)
