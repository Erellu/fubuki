# `fubuki::tutorial::support`

> [!IMPORTANT]
> `fubuki::tutorial::support` is an example library used to factorise the setup code for tutorials.
> It is NOT meant to be used in a serious production environment, but can be used as a reference for similar code.

## CMake

### Externally

**This library is not part of the exported targets.**

>[!NOTE]
> Of course, you can build Fubuki as part of your project and then link with `fubuki_tutorial_support`.

### Internally

```cmake
fubuki_add_library(NAME                 target_name
                   PUBLIC_DEPENDENCIES  "tutorial_support"
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

`fubuki::tutorial::support` is a small library designed to illustrate how to use Fubuki to manipulate Vulkan objects, and in particular, how to setup an application.

## Public API

| Name                       | Type          | Category            | Description                                                                     | Notes                                   |
| -------------------------- | ------------- | ------------------- | ------------------------------------------------------------------------------- | --------------------------------------- |
| `app::display`             | Free function | Resource access     | Returns a reference to the display used by the application.                     | N.A.                                    |
| `app::error::any`          | `struct`      | Error handling      |                                                                                 |                                         |
| `app::init`                | Free function | Resources lifetime  | Creates the resources needed for the application lifetime.                      | Returns an instance of `std::expected`. |
| `app::instance`            | Free function | Resource access     | Returns a reference to the instance used by the application.                    | N.A.                                    |
| `app::pipeline_cache`      | Free function | Resource access     | Returns a reference to the device used by the application.                      | N.A.                                    |
| `app::pipeline_cache`      | Free function | Resource access     | Returns a reference to the pipeline cache used by the application.              | N.A.                                    |
| `app::resources`           | `class`       | Resources owner     | The resources required during the application lifetime.                         | N.A.                                    |
| `app::scoped_init`         | `struct`      | Resources lifetime  | A RAII object ensuring the deletion of the resources when it goes out of scope. | N.A.                                    |
| `app::setup`               | `struct`      | Resource allocation | Application setup                                                               | N.A.                                    |
| `app::setup_pnext`         | `struct`      | Resource allocation | `pnext` chains for the application resources objects.                           | N.A.                                    |
| `app::shutdown`            | Free function | Resources lifetime  | Destroys the app resources.                                                     | N.A.                                    |
| `app::surface`             | Free function | Resource access     | Returns a reference to the surface used by the application.                     | N.A.                                    |
| `app::swapchain`           | Free function | Resource access     | Returns a reference to the swapchain used by the application.                   | N.A.                                    |
| `app::swapchain_resources` | Free function | Resource access     | Returns a reference to the swapchain resources used by the application.         | N.A.                                    |
| `app::user_event_queue`    | Free function | Resource access     | Returns a reference to the user_event_queue used by the application.            | N.A.                                    |
| `app::window`              | Free function | Resource access     | Returns a reference to the window used by the application.                      | N.A.                                    |
