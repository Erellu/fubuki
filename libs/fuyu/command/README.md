# Commands

`fubuki::fuyu::command` (aliased to `fubuki::fuyu::cmd`) provides two way to use Vulkan commands operating on command buffers: free functions and pipes.

## Free functions

Functions provided in `fubuki::fuyu::command` are the strict analogues to `vkCmdxxx`, except the first argument is a `fuyu::command_buffer_view`.
Headers are grouped by functionalities:

| Header                          | Contents                                                 |
| ------------------------------- | -------------------------------------------------------- |
| `fuyu/command/barrier.hpp`      | Pipeline barrier commands                                |
| `fuyu/command/bind.hpp`         | Bind commands (pipelines, descriptor sets, buffers, ...) |
| `fuyu/command/copy.hpp`         | Copy commands (between buffers and images)               |
| `fuyu/command/dispatch.hpp`     | Dispatch commands                                        |
| `fuyu/command/draw.hpp`         | Draw calls                                               |
| `fuyu/command/event.hpp`        | Event state commands                                     |
| `fuyu/command/execute.hpp`      | Execute secondary command buffers                        |
| `fuyu/command/manipulation.hpp` | Blit, fill, resolve, update commands                     |
| `fuyu/command/push.hpp`         | Push commands (constants, ...)                           |
| `fuyu/command/query.hpp`        | Query commands                                           |
| `fuyu/command/set.hpp`          | Dynamic states commands                                  |
| `fuyu/command/submit.hpp`       | Submission to queues.                                    |


> [!TIP]
> `fuyu::command` also offers additional functionalities such as RAII objects for rendering scopes and query scopes, and shortcuts for pipeline barriers.

| Addition                | Description                                                                                                                                                                                                                                             |
| ----------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| `recorded_scope`        | A RAII object equivalent to a call to `cmd::begin()` upon construction, and to `cmd::end()` upon destruction.                                                                                                                                           |
| `pipeline_barrier`      | A `struct` describing a pipeline barrier call. Use through `command::barrier` overloads.                                                                                                                                                                |
| `image_memory_barrier`  | A `struct` describing an image memory barrier, as `VkImageMemoryBarrier`. Use through `command::barrier` overloads.                                                                                                                                     |
| `buffer_memory_barrier` | A `struct` describing a buffer memory barrier, as `VkBufferMemoryBarrier`. Use through `command::barrier` overloads.                                                                                                                                    |
| `query::scope`          | A RAII object equivalent to an immediate call to `command::query::begin` and a call to `command::query::end upon` its destruction.                                                                                                                      |
| `render_target`         | Specifies a setup for render pass-based rendering. Equivalent of `VkRenderPassBeginInfo`.                                                                                                                                                               |
| `dynamic_render_target` | Specifies a setup for dynamic rendering. Equivalent of `VkRenderingInfo`.                                                                                                                                                                               |
| `rendering_scope`       | A RAII object equivalent to an immediate call to `command::begin_render_pass` and a call to `command::end_render_pass` upon its destruction, or to `command::begin_rendering`/`command::end_rendering` (depending on the arguments of the constructor). |


## Command pipes

`fubuki::fuyu::command::pipe`s provide an interface to compose functions in `fuyu::command` in a way similar to `std::ranges`.
Under the hood, pipes are implemented using the free functions mentioned earlier.

> [!TIP]
> `fuyu::command::pipe` offers all functionalities available through free functions, including the additional RAII objects like `scoped_rendering`. 

### Basic usage

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

### Integrating in existing code

Command buffers are started (in the Vulkan meaning of the term) through `pipe::record(...)` and ended when calling `pipe::submit(...)`

> [!IMPORTANT]
> However, tag `struct`s `pipe::already_started` and `pipe::already_ended` are provided to indicate these operations must be skipped and the command buffer in its current state.

```cpp
auto flow = pipe::record(pipe::already_started{command_buffer}) // Won't call vkBeginCommandBuffer on the command buffer
            | ...;

if(const auto check = pipe::submit(queue, pipe::already_ended{std::move(flow)}); not check) // Won't call vkEndCommandBuffer on the pipe command buffer
{
    use(check.error());
}
```

### Custom pipes

User code can provide custom pipes by following the pattern below:

```cpp
namespace external::pipe
{

struct parameters
{
     something_heavy stuff = {};
};

struct meow
{
    [[nodiscard]] auto operator()(parameters p) noexcept(...)
    {
        return fuyu::command::pipe::adaptor_closure
        {
            [param = std::move(p)](fuyu::command::pipe::flow f) noexcept(...)
            {
                external::do_something(f.command_buffer(), param);
                return f;
            }
        };
    }
};

} // namespace external::pipe
```

Such a `pipe` can then by appended through `operator|` like the built-in ones:

```cpp
auto flow = pipe::record(command_buffer)
            | external::pipe::meow({...});
```