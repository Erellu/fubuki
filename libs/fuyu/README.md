# fubuki::fuyu

> [!IMPORTANT]
> This file is _not_ a substitue for the in-code documentation.
> Its goal is to advertise the features available through `fubuki::fuyu`.
> For examples and detailed documentation, see the `doxygen`.

## CMake

### Externally

```cmake
target_link_libraries(your_target <PUBLIC|PRIVATE> fubuki::fuyu)
```

### Internally

```cmake
fubuki_add_library(NAME                 target_name
                   PUBLIC_DEPENDENCIES  "fuyu"
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

`fubuki::fuyu` provides an idiomatic C++ API (bindings) to the Vulkan API.
It provides objects with RAII semantics, that support `move` (but not copy), and are aware of how they were allocated. To a certain extend.

`fuyu`, as the rest of Fubuki, is a _functional_ API: the owning RAII objects convert to an equivalent representation in `fuyu::views`, trivially copiable objects that can be passed around in functions. 

## Public API

### Containers


| Name                | Type    | Category                        | Description                                                                                                  | Notes                                                                       |
| ------------------- | ------- | ------------------------------- | ------------------------------------------------------------------------------------------------------------ | --------------------------------------------------------------------------- |
| `formatted_storage` | `class` | Container, contiguous container | A non-`template` container that can be used to manipulate formatted storage (buffer and images) on the host. | Essentially implemented in terms of `variant<vector<...>, vector<...>,...>` | 

### Main objects

> [!NOTE]
> All of these objects follow the same paradigm, define the same interface and share the same pattern for provided aliases. For example, `fuyu::device::information` is an alias to `fuyu::information::device`, `fuyu::device::view` is an alias to `fuyu::views::device`, etc.
> Member functions are named identically and perform the same operation regardless of the object.
> **Note that `fubuki::fuyu` objects support borrowing or taking ownership over an externally-allocated Vulkan handle through `fuyu::external_handle` (see also: [Tutorial 00: Instance and device](https://github.com/Erellu/fubuki/tree/master/tutorials/0_instance_device)).**

| Name                    | Type    | Category            | Description                                                                                                | Notes                       |
| ----------------------- | ------- | ------------------- | ---------------------------------------------------------------------------------------------------------- | --------------------------- |
| `buffer`                | `class` | RAII, owning object | An object owning (or borrowing an external) `VkBuffer` (`fubuki::buffer_handle`).                          | Converts to`views::buffer`. |
| `buffer_view`           | `class` | RAII, owning object | Analogue for `VkBufferView` (`fubuki::buffer_view_handle`).                                                | Analogue to the above.      |
| `command_buffer_array`  | `class` | RAII, owning object | Analogue for `VkCommandBuffer` (`fubuki::command_buffer_handle`)                                           | Analogue to the above.      |
| `command_pool`          | `class` | RAII, owning object | Analogue for `VkCommandPool` (`fubuki::buffer_view_handle`)                                                | Analogue to the above.      |
| `compute_pipeline`      | `class` | RAII, owning object | Analogue for `VkPipeline` referring to a compute pipeline (`fubuki::compute_pipeline_handle`)              | Analogue to the above.      |
| `debug::messenger`      | `class` | RAII, owning object | Analogue for `VkDebugUtilsMessengerEXT` (`fubuki::debug_utils_messenger_ext`)                              | Analogue to the above.      |
| `descriptor_pool`       | `class` | RAII, owning object | Analogue for `VkDescriptorPool` (`fubuki::descriptor_pool_handle`)                                         | Analogue to the above.      |
| `descriptor_set_array`  | `class` | RAII, owning object | Analogue for `VkDescriptorSet` (`fubuki::descriptor_set_handle`)                                           | Analogue to the above.      |
| `descriptor_set_layout` | `class` | RAII, owning object | Analogue for `VkDescriptorSetLayout` (`fubuki::descriptor_set_layout_handle`)                              | Analogue to the above.      |
| `device`                | `class` | RAII, owning object | Analogue for `VkDevice` (`fubuki::device_handle`)                                                          | Analogue to the above.      |
| `event`                 | `class` | RAII, owning object | Analogue for `VkEvent` (`fubuki::event_handle`)                                                            | Analogue to the above.      |
| `fence`                 | `class` | RAII, owning object | Analogue for `VkFence` (`fubuki::fence_handle`)                                                            | Analogue to the above.      |
| `framebuffer`           | `class` | RAII, owning object | Analogue for `VkFramebuffer` (`fubuki::framebuffer_handle`)                                                | Analogue to the above.      |
| `graphics_pipeline`     | `class` | RAII, owning object | Analogue for `VkPipeline` referring to a graphics pipeline (`fubuki::graphics_pipeline_handle`)            | Analogue to the above.      |
| `image`                 | `class` | RAII, owning object | Analogue for `VkImage` (`fubuki::image_handle`)                                                            | Analogue to the above.      |
| `image_view`            | `class` | RAII, owning object | Analogue for `VkImageView` (`fubuki::i_view_handle`)                                                       | Analogue to the above.      |
| `instance`              | `class` | RAII, owning object | Analogue for `VkInstance` (`fubuki::instance_handle`)                                                      | Analogue to the above.      |
| `memory`                | `class` | RAII, owning object | Analogue for `VkDeviceMemory` (`fubuki::memory_handle`)                                                    | Analogue to the above.      |
| `pipeline_cache`        | `class` | RAII, owning object | Analogue for `VkPipelineCache` (`fubuki::device_memory_handle`)                                            | Analogue to the above.      |
| `pipeline_layout`       | `class` | RAII, owning object | Analogue for `VkPipelineLayout` (`fubuki::pipeline_layout_handle`)                                         | Analogue to the above.      |
| `query_pool`            | `class` | RAII, owning object | Analogue for `VkQueryPool` (`fubuki::query_pool_handle`)                                                   | Analogue to the above.      |
| `queue`                 | `class` | RAII, owning object | Queue (`VkQueue`/`fubuki::queue_handle`) retrieved upon device creation.                                   | Analogue to the above.      |
| `render_pass`           | `class` | RAII, owning object | Analogue for `VkRenderPass` (`fubuki::buffer_view_handle`)                                                 | Analogue to the above.      |
| `sampler`               | `class` | RAII, owning object | Analogue for `VkSampler` (`fubuki::sampler_handle`)                                                        | Analogue to the above.      |
| `semaphore`             | `class` | RAII, owning object | Analogue for `VkSemaphore` (`fubuki::semaphore_handle`)                                                    | Analogue to the above.      |
| `shader_module`         | `class` | RAII, owning object | Analogue for `VkShaderModule` (`fubuki::shader_module_handle`)                                             | Analogue to the above.      |
| `surface`               | `class` | RAII, owning object | Analogue for `VkSurfaceKHR` (`fubuki::surface_khr_handle`)                                                 | Analogue to the above.      |
| `swapchain`             | `class` | RAII, owning object | Analogue for `VkSwapchainKHR` (`fubuki::swapchain_khr_handle`)                                             | Analogue to the above.      |
| `swapchain_resources`   | `class` | RAII, owning object | Objects associated to swapchain usages (images, corresponding views, framebuffers if needed, render pass). | Analogue to the above.      |

### Views

| Name                             | Type     | Category                  | Description                                                                                                                      | Notes                                                |
| -------------------------------- | -------- | ------------------------- | -------------------------------------------------------------------------------------------------------------------------------- | ---------------------------------------------------- |
| `views::buffer_resource`         | `struct` | View                      | A view of a buffer resource (`VkBuffer`/`fubuki::buffer_handle`). Does NOT destroy the Vulkan handle upon destruction.           | `fuyu::buffer` converts to that `struct`.            |
| `views::buffer_view_description` | `struct` | View                      | Analogue for `VkBufferView` (`fubuki::buffer_view_handle`).                                                                      | Analogue to the above.                               |
| `views::command_buffer_array`    | `struct` | View                      | Analogue for an array of `VkCommandBuffer` (`fubuki::command_buffer_handle`)                                                     | Analogue to the above.                               |
| `views::command_buffer`          | `struct` | View                      | Analogue for `VkCommandBuffer` (`fubuki::command_buffer_handle`)                                                                 | Analogue to the above.                               |
| `views::command_pool`            | `struct` | View                      | Analogue for `VkCommandPool` (`fubuki::buffer_view_handle`)                                                                      | Analogue to the above.                               |
| `views::compute_pipeline`        | `struct` | View                      | Analogue for `VkPipeline` referring to a compute pipeline (`fubuki::compute_pipeline_handle`)                                    | Analogue to the above.                               |
| `views::descriptor_pool`         | `struct` | View                      | Analogue for `VkDescriptorPool` (`fubuki::descriptor_pool_handle`)                                                               | Analogue to the above.                               |
| `views::descriptor_set_array`    | `struct` | View                      | Analogue for an array of`VkDescriptorSet` (`fubuki::descriptor_set_handle`)                                                      | Analogue to the above.                               |
| `views::descriptor_set`          | `struct` | View                      | Analogue for `VkDescriptorSet` (`fubuki::descriptor_set_handle`)                                                                 | Analogue to the above.                               |
| `views::descriptor_set_layout`   | `struct` | View                      | Analogue for `VkDescriptorSetLayout` (`fubuki::descriptor_set_layout_handle`)                                                    | Analogue to the above.                               |
| `views::device`                  | `struct` | View                      | Analogue for `VkDevice` (`fubuki::device_handle`)                                                                                | Analogue to the above.                               |
| `views::event`                   | `struct` | View                      | Analogue for `VkEvent` (`fubuki::event_handle`)                                                                                  | Analogue to the above.                               |
| `views::fence`                   | `struct` | View                      | Analogue for `VkFence` (`fubuki::fence_handle`)                                                                                  | Analogue to the above.                               |
| `views::framebuffer`             | `struct` | View                      | Analogue for `VkFramebuffer` (`fubuki::framebuffer_handle`)                                                                      | Analogue to the above.                               |
| `views::graphics_pipeline`       | `struct` | View                      | Analogue for `VkPipeline` referring to a graphics pipeline (`fubuki::graphics_pipeline_handle`)                                  | Analogue to the above.                               |
| `views::image_resource`          | `struct` | View                      | Analogue for `VkImage` (`fubuki::image_handle`)                                                                                  | Analogue to the above.                               |
| `views::image_view_description`  | `struct` | View                      | Analogue for `VkImageView` (`fubuki::i_view_handle`)                                                                             | Analogue to the above.                               |
| `views::instance`                | `struct` | View                      | Analogue for `VkInstance` (`fubuki::instance_handle`)                                                                            | Analogue to the above.                               |
| `views::memory`                  | `struct` | View                      | Analogue for `VkDeviceMemory` (`fubuki::memory_handle`)                                                                          | Analogue to the above.                               |
| `views::pipeline_cache`          | `struct` | View                      | Analogue for `VkPipelineCache` (`fubuki::device_memory_handle`)                                                                  | Analogue to the above.                               |
| `views::pipeline_layout`         | `struct` | View                      | Analogue for `VkPipelineLayout` (`fubuki::pipeline_layout_handle`)                                                               | Analogue to the above.                               |
| `views::query_pool`              | `struct` | View                      | Analogue for `VkQueryPool` (`fubuki::query_pool_handle`)                                                                         | Analogue to the above.                               |
| `views::render_pass`             | `struct` | View                      | Analogue for `VkRenderPass` (`fubuki::buffer_view_handle`)                                                                       | Analogue to the above.                               |
| `views::sampler`                 | `struct` | View                      | Analogue for `VkSampler` (`fubuki::sampler_handle`)                                                                              | Analogue to the above.                               |
| `views::semaphore`               | `struct` | View                      | Analogue for `VkSemaphore` (`fubuki::semaphore_handle`)                                                                          | Analogue to the above.                               |
| `views::shader_module`           | `struct` | View                      | Analogue for `VkShaderModule` (`fubuki::shader_module_handle`)                                                                   | Analogue to the above.                               |
| `views::surface`                 | `struct` | View                      | Analogue for `VkSurfaceKHR` (`fubuki::surface_khr_handle`)                                                                       | Analogue to the above.                               |
| `views::swapchain`               | `struct` | View                      | Analogue for `VkSwapchainKHR` (`fubuki::swapchain_khr_handle`)                                                                   | Analogue to the above.                               |
| `views::swapchain_resources`     | `struct` | View                      | A view of the resources associated to a swapchain (images, image views, framebuffers if needed, etc.)                            | Analogue to the above.                               |
| `views::owning<T>`               | `struct` | View, ownership indicator | Wrapper object containing a view. Indicates the user to responsible for freeing the Vuklan handle. Does **NOT** free the handle. | Typically obtained by `fuyu::<object>::release()`.   |
| `views::memory_range`            | `struct` | Helper                    | A memory range (offset and size).                                                                                                | N.A.                                                 |
| `views::memory_region`           | `struct` | Helper                    | A memory region (handle, location).                                                                                              | N.A                                                  |
| `views::mapped_memory`           | `struct` | Helper, container         | A region of mapped memory, writable by the host as-if `span<byte>`.                                                              | Typically obtained by `fuyu::map(memory_view, ...)`. |

### Information

> [!NOTE]
> All `fuyu` main objects keep this information for they lifetime.
> Some objects, such as `fuyu::device`, `fuyu::instance` and pipelines require an additional parameter (aliased to `object::complements`) that **is not kept** and only used upon construction.
> The information kept can be access through the respective `fuyu::<object>::info()` member function, or upon conversion to a `view`.

| Name                                   | Type     | Category    | Description                                                                   | Notes                                      |
| -------------------------------------- | -------- | ----------- | ----------------------------------------------------------------------------- | ------------------------------------------ |
| `information::buffer_resource`         | `struct` | Information | Information required to create an instance of `fuyu::buffer`.                 | Accessible through `fuyu::buffer::info()`. |
| `information::buffer_view_description` | `struct` | Information | Information required to create an instance of `fuyu::buffer_view`.            | Analogue to the above.                     |
| `information::command_buffer_array`    | `struct` | Information | Information required to create an instance of `fuyu::command_buffer_array`.   | Analogue to the above.                     |
| `information::command_pool`            | `struct` | Information | Information required to create an instance of `fuyu::command_pool`.           | Analogue to the above.                     |
| `information::compute_pipeline`        | `struct` | Information | Information required to create an instance of `fuyu::compute_pipeline`.       | Analogue to the above.                     |
| `information::descriptor_pool`         | `struct` | Information | Information required to create an instance of `fuyu::descriptor_pool`.        | Analogue to the above.                     |
| `information::descriptor_set_array`    | `struct` | Information | Information required to create an instance of `fuyu::descriptor_set_array`.   | Analogue to the above.                     |
| `information::descriptor_set_layout`   | `struct` | Information | Information required to create an instance of `fuyu::descriptor_set_layout`.  | Analogue to the above.                     |
| `information::device`                  | `struct` | Information | Information required to create an instance of `fuyu::device`.                 | Analogue to the above.                     |
| `information::event`                   | `struct` | Information | Information required to create an instance of `fuyu::event`.                  | Analogue to the above.                     |
| `information::fence`                   | `struct` | Information | Information required to create an instance of `fuyu::fence`.                  | Analogue to the above.                     |
| `information::framebuffer`             | `struct` | Information | Information required to create an instance of `fuyu::framebuffer`.            | Analogue to the above.                     |
| `information::graphics_pipeline`       | `struct` | Information | Information required to create an instance of `fuyu::graphics_pipeline`.      | Analogue to the above.                     |
| `information::image_resource`          | `struct` | Information | Information required to create an instance of `fuyu::image_resource`.         | Analogue to the above.                     |
| `information::image_view_description`  | `struct` | Information | Information required to create an instance of `fuyu::image_view_description`. | Analogue to the above.                     |
| `information::instance`                | `struct` | Information | Information required to create an instance of `fuyu::instance`.               | Analogue to the above.                     |
| `information::memory`                  | `struct` | Information | Information required to create an instance of `fuyu::memory`.                 | Analogue to the above.                     |
| `information::pipeline_cache`          | `struct` | Information | Information required to create an instance of `fuyu::pipeline_cache`.         | Analogue to the above.                     |
| `information::pipeline_layout`         | `struct` | Information | Information required to create an instance of `fuyu::pipeline_layout`.        | Analogue to the above.                     |
| `information::query_pool`              | `struct` | Information | Information required to create an instance of `fuyu::query_pool`.             | Analogue to the above.                     |
| `information::render_pass`             | `struct` | Information | Information required to create an instance of `fuyu::render_pass`.            | Analogue to the above.                     |
| `information::sampler`                 | `struct` | Information | Information required to create an instance of `fuyu::sampler`.                | Analogue to the above.                     |
| `information::semaphore`               | `struct` | Information | Information required to create an instance of `fuyu::semaphore`.              | Analogue to the above.                     |
| `information::shader_module`           | `struct` | Information | Information required to create an instance of `fuyu::shader_module`.          | Analogue to the above.                     |
| `information::surface`                 | `struct` | Information | Information required to create an instance of `fuyu::surface`.                | Analogue to the above.                     |
| `information::swapchain`               | `struct` | Information | Information required to create an instance of `fuyu::swapchain`.              | Analogue to the above.                     |
| `information::swapchain_resources`     | `struct` | Information | Information required to create an instance of `fuyu::swapchain_resources`.    | Analogue to the above.                     |

### Commands

Functions provided in `fubuki::fuyu::command` are the strict analogues to `vkCmdxxx`, except the first argument is a `fuyu::command_buffer_view`. See [fuyu/command](https://github.com/Erellu/fubuki/tree/master/libs/fuyu/command).
Similarly, functions manipulating objects are also the strict analogue to the Vulkan C-API:

- The `vk` prefix is **removed**.
- The name of the Vulkan object is **removed**.
- The first argument is a **`view`** of the main object.
- The Vulkan handles are **replaced** by type-safe Fubuki handles.
- The ranges are provided through **`std::span`** or **`std::initializer_list`** (depending on the overload) to allow `fuyu::func({a, b , c});`.

> **Examples**:
> - `vkResetFences` ->`fuyu::reset(fence_view{...})` / `fuyu::reset({fence_view{...}, fence_view{...}})`
> - `vkGetSemaphoreCounterValue` -> `fuyu::counter_value(semaphore_view{...})`
> - `vkResetCommandPool` -> `fuyu::reset(command_pool_view{...}, flags)`

> [!NOTE]
> Because Fubuki uses _distinct types_ for handles and views, their is no possible clash possible between functions performing on different handles.

> [!TIP]
> `fuyu::command` also offers additional functionalities such as RAII objects for rendering scopes and query scopes, and shortcuts for pipeline barriers detailed in the link above.

#### Pipes

Briefly: `fubuki::fuyu` offers free functions to manipulate command buffers (see above), and also provides an equivalent _composable_ interfaces similar to pipes of `std::ranges`. See [fuyu/command](https://github.com/Erellu/fubuki/tree/master/libs/fuyu/command/pipe) for more details.

**Example**:

```cpp
namespace pipe = fubuki::fuyu::command::pipe;

auto command_buffer = ...;

auto flow = pipe::record(command_buffer)
            | pipe::bind::pipeline(a_graphics_pipeline)
            | pipe::render_scope(render_target,
                                 [=](pipe::flow f) noexcept
                                 {
                                     return std::move(f)
                                     | pipe::push::constants(...)
                                     | pipe::draw::call(...)
                                     | ...;
                                 })
            | pipe::bind::pipeline(a_compute_pipeline)
            | ...;

if(const auto check = pipe::submit(queue, std::move(flow)); not check)
{
    use(check.error());
}
```

### Utility

#### Generic

| Name                  | Type          | Category            | Description                           | Notes                                           |
| --------------------- | ------------- | ------------------- | ------------------------------------- | ----------------------------------------------- |
| `fuyu::swap`          | Free function | Object manipulation | Swaps two objects.                    | Always equivalent to `obj1.swap(obj2);`.        |
| `fuyu::to_underlying` | Free function | Object manipulation | Returns the underlying Vulkan object. | Essentially for `fuyu::information` structures. |

#### Vulkan

##### Generic

| Name                            | Type          | Category            | Description                                                                                                   | Notes                                                                                                                                 |
| ------------------------------- | ------------- | ------------------- | ------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------- |
| `extension_support`             | `struct`      | Hardware, extension | Information about extension supported by available hardware.                                                  | N.A.                                                                                                                                  |
| `external_buffer_properties`    | Free function | Memory, buffer      | Returns the external handle types supported by buffers.                                                       | N.A.                                                                                                                                  |
| `memory_index`                  | Free function | Hardware, memory    | Finds a memory index corresponding to a certain memory type.                                                  | N.A.                                                                                                                                  |
| `memory_requirements`           | Free function | Memory, buffer      | Determines memory requirements for a buffer or an image.                                                      | N.A.                                                                                                                                  |
| `physical_device`               | `struct`      | Hardware            | Queries available information about a physical device.                                                        | Extension support can be queried by passing `fubuki::pnext_chain`s. Without providing such arguments, only core features are queried. |
| `physical_device_count`         | Free function | Hardware            | Determines the total number of physical devices.                                                              | N.A.                                                                                                                                  |
| `physical_device_information`   | Free function | Hardware            | Returns information about a physical device.                                                                  | N.A.                                                                                                                                  |
| `physical_devices`              | Free function | Hardware            | Polls the hardware to determine the available devices.                                                        | N.A.                                                                                                                                  |
| `queue_family_index`            | Free function | Hardware, queues    | Determines the index for the requested queue family, or returns `std::nullopt` if no match was found.         | N.A.                                                                                                                                  |
| `queue_properties`              | Free function | Hardware, queues    | Returns the queue properties of a physical device.                                                            | N.A.                                                                                                                                  |
| `recorded_scope`                | `struct`      | Command buffer      | A RAII object equivalent to a call to `cmd::begin()` upon construction, and to `cmd::end()` upon destruction. | N.A.                                                                                                                                  |
| `sparse_memory_requirements`    | Free function | Memory, image       | Queries the memory requirements for a sparse image.                                                           | N.A.                                                                                                                                  |
| `submission`                    | `struct`      | Command buffer      | Synchronisation primitives required upon submitting a command buffer.                                         | N.A.                                                                                                                                  |
| `subpass`                       | `struct`      | Rendering           | Description of a subpass setup and its dependencies.                                                          | N.A.                                                                                                                                  |
| `supported_extensions`          | Free function | Hardware, extension | Determines the extensions supported by a device.                                                              | N.A.                                                                                                                                  |
| `supported_instance_extensions` | Free function | Hardware, extension | Determines the extension supported by an instance, optionally, if a layer is enabled.                         | N.A.                                                                                                                                  |

##### Object manipulation

| Name                             | Type          | Category                | Description                                                                                                                                                   | Notes                                                       |
| -------------------------------- | ------------- | ----------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------- |
| `borrow`                         | `struct`      | External handle         | Indicates the fuyu object (`fuyu::device`, `fuyu::buffer`...) only borrows the object for its lifetime, and won't destroy it.                                 | N.A.                                                        |
| `external_handle`                | `struct`      | External handle         | A tag-like struct that can be passed to the constructor of fuyu objects (`fuyu::device`, `fuyu::buffer`...) to use Vulkan handles allocated from another API. | N.A.                                                        |
| `handle_of`                      | Free function | External handle, helper | Returns the underlying handle an `external_handle` carries.                                                                                                   | N.A.                                                        |
| `indicates_ownership`            | Free function | External handle, helper | Indicates if an instance of `external_handle` indicates the fuyu object must take ownership.                                                                  | N.A.                                                        |
| `parent::device`                 | `struct`      | Parenting               | Parent device object.                                                                                                                                         | N.A.                                                        |
| `parent::instance`               | `struct`      | Parenting               | Parent device object.                                                                                                                                         | N.A.                                                        |
| `queue_count(sharing_mode::any)` | Free function | Sharing mode, helper    | Returns the number of queues that will be used to access a resource.                                                                                          | N.A.                                                        |
| `queue_data(sharing_mode::any)`  | Free function | Sharing mode, helper    | Returns a pointer to a contiguous array of queue family indices that will access a resource, or `nullptr` is only one is used.                                | N.A.                                                        |
| `rendering_area`                 | `struct`      | Rendering               | Structure describing rendering area granularity query info.                                                                                                   | N.A.                                                        |
| `sampling_rate::any`             | Type alias    | Sampling, helper        | Any sampling rate.                                                                                                                                            | N.A.                                                        |
| `sampling_rate::sample_<n>`      | `struct`      | Sampling                | The various available sampling rates, with a conditional mask `VkSampleMask` that can be provided when `n >= 32` (n: 1 -> 64).                                | Each `struct` maps to a value of `VkSampleCountFlagBits`.   |
| `sharing_mode::any`              | `struct`      | Sharing mode            | Any sharing mode.                                                                                                                                             | Semantically equivalent to`variant<exclusive, concurrent>`. |
| `sharing_mode::concurrent`       | `struct`      | Sharing mode            | Specifies that concurrent access to any range or image subresource of the object from multiple queue families is supported.                                   | Equivalent to `VK_SHARING_MODE_CONCURRENT`.                 |
| `sharing_mode::exclusive`        | `struct`      | Sharing mode            | Specifies that access to any range or image subresource of the object will be exclusive to a single queue family at a time.                                   | Equivalent to `VK_SHARING_MODE_EXCLUSIVE`.                  |
| `take_ownership`                 | `struct`      | External handle         | Indicates the fuyu object (`fuyu::device`, `fuyu::buffer`...) must take the ownership over this handle, that is, destroy it when its lifetime ends.           | N.A.                                                        |

##### Debug

| Name                                    | Type          | Category                     | Description                                                                                                          | Notes                                                                                                                                      |
| --------------------------------------- | ------------- | ---------------------------- | -------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------ |
| `debug::layer_callback::standard_ouput` | Free function | Debugging, validation layers | A callback function that prints to `std::cerr` if the message is an error or a warning, or to `std::clog` otherwise. | N.A.                                                                                                                                       |
| `debug::layer_message`                  | `struct`      | Debugging, validation layers | A printable representation of a message sent by a validation layer.                                                  | Unlike a layer_message_view, there is no need to synchronise the lifetime of this structure with the VkDebugUtilsMessengerCallbackDataEXT. |
| `debug::layer_message_view`             | `struct`      | Debugging, validation layers | A printable view of a `VkDebugUtilsMessengerCallbackDataEXT`.                                                        | **Becomes dangling if the corresponding `VkDebugUtilsMessengerCallbackDataEXT` goes out of scope.**                                        |
| `debug::name`                           | Free function | Debugging, debug markers     | Names a handle.                                                                                                      | N.A.                                                                                                                                       |
| `debug::name_if_loaded`                 | Free function | Debugging, debug markers     | Names a handle if the `ext_debug_utils` extension is loaded.                                                         | N.A.                                                                                                                                       |
| `debug::validate_layers`                | Free function | Debugging, validation layers | Returns all available validation layers names and properties                                                         | N.A.                                                                                                                                       |
| `debug::validation_layers_available`    | Free function | Debugging, validation layers | Indicates if at least a validation layer is available.                                                               | N.A.                                                                                                                                       |

### Errors

| Name                                  | Type     | Category         | Description                                                                     | Notes |
| ------------------------------------- | -------- | ---------------- | ------------------------------------------------------------------------------- | ----- |
| `parent::error::incompatible<handle>` | `struct` | Error, parenting | Error returned when attempting to call `rebind` with a different parent handle. | N.A.  |
| `pipe::error::any`                    | `struct` | Error, pipes     | Any error that can happen through pipes.                                        | N.A.  |
| `pipe::error::begin`                  | `struct` | Error, pipes     | Indicates an error occurred upon starting the command buffer recording.         | N.A.  |
| `pipe::error::end`                    | `struct` | Error, pipes     | Indicates an error occurred upon ending the command buffer recording.           | N.A.  |
| `pipe::error::submit`                 | `struct` | Error, pipes     | Indicates an error occurred upon submission.                                    | N.A.  |
