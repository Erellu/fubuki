# Fubuki tutorials: 02 - Vulkan context

## Overview

This tutorial illustrates how a typical application based on `fuyu` resources should setup its main resources.
The code in tutorial 02 uses almost exclusively the tutorial support library.

> [!NOTE]
> `fubuki::tutorial` is not exported as a target one can link to (in particular, the headers are _not_ part of the installation process).
> Should one want to replicate the functionalities, the code should be extracted into the user project.

## Typical API

```cpp
/// The resources typically needed during the application lifetime.
namespace app
{

/// A RAII object ensuring the deletion of the resources when it goes out of scope.
struct scoped_init
{
    scoped_init() noexcept = default;
    ~scoped_init() noexcept;

    scoped_init(const scoped_init&) = delete;
    scoped_init(scoped_init&&)      = delete;

    scoped_init& operator=(const scoped_init&) = delete;
    scoped_init& operator=(scoped_init&&)      = delete;
};

/// Creates the resources needed for the application lifetime.
[[nodiscard]] std::expected<scoped_resources, fubuki::api_call_info> init() noexcept;

/// Destroys the app resources.
void shutdown() noexcept;

[[nodiscard]] const fubuki::fuyu::instance&       instance() noexcept;
[[nodiscard]] const fubuki::fuyu::device&         device() noexcept;
[[nodiscard]] const fubuki::fuyu::pipeline_cache& pipeline_cache() noexcept;
[[nodiscard]] const fubuki::fuyu::surface&        surface() noexcept;
[[nodiscard]] fubuki::io::display::window& window() noexcept;

inline scoped_init::~scoped_init() noexcept{shutdown();}

} // namespace app
```

## Typical `main`

```cpp
int main()
{
    const auto app_resources_scope = app::init(...);

    if(not app_resources_scope)
    {
        std::cerr << "Failed to create the resources for the application. API error: " << app_resources_scope.error();
        return 1;
    }

    // Add event dispatchers
    {
        auto& event_dispatcher = app::window().event_dispatcher();

        event_dispatcher.add<...>(...);
        ...
    }

    return fubuki::io::event::loop::execute(...);
}
```

## Cleanup

`app::shutdown` (or `resource_scope`, as presented above) usually performs serialisation and various cleanup operations like the following:

```cpp
void shutdown() noexcept
{
    auto pipeline_cache_data = fubuki::fuyu::data(pipeline_cache());

    if(pipeline_cache_data.has_value())
    {
        write_to_disk(*pipeline_cache_data);
    }
    else
    {
        log(pipeline_cache_data.error());
    }

    // Remove event handlers that are susceptible to reference app::surface(), app::device(), app::instance() or other resources after they are
    // already destroyed
    window().event_dispatcher().clear();
}
```

> [!NOTE]
> In `fubuki::tutorial::app`, these operations are performed in `app::~resources`.
_______________________________________________

[Next tutorial](https://github.com/Erellu/fubuki/tree/master/tutorials/3_compiling_shaders)
