cmake_minimum_required(VERSION 3.23)
project(fubuki_fuyu_test LANGUAGES CXX)

if(NOT ${FUBUKI_NO_IO})

    #------------------------------------------------------------------------------

    fubuki_add_test(NAME fuyu_test
                       PUBLIC_DEPENDENCIES "fuyu" "io"
                       PRIVATE_DEPENDENCIES ""
                       HEADERS "context.hpp"
                               "descriptor_set_resources.hpp"
                               "pipeline_resources.hpp"
                               "resources_for_swapchain.hpp"
                               "shader_resources.hpp"
                               "validation.hpp"
                       SOURCES "buffer.cpp"
                               "command_buffer_array.cpp"
                               "command_pool.cpp"
                               "compute_pipeline.cpp"
                               "context.cpp"
                               "descriptor_pool.cpp"
                               "descriptor_pool_size.cpp"
                               "descriptor_set_array.cpp"
                               "descriptor_set_layout.cpp"
                               "descriptor_type.cpp"
                               "device.cpp"
                               "event.cpp"
                               "fence.cpp"
                               "framebuffer.cpp"
                               "formatted_storage.cpp"
                               "fuyu_test.cpp"
                               "graphics_pipeline.cpp"
                               "image.cpp"
                               "instance.cpp"
                               "memory.cpp"
                               "pipeline_cache.cpp"
                               "pipeline_layout.cpp"
                               "query_pool.cpp"
                               "render_pass.cpp"
                               "sampler.cpp"
                               "semaphore.cpp"
                               "shader_module.cpp"
                               "surface.cpp"
                               "swapchain.cpp"
                               "swapchain_resources.cpp"
                               "validation.cpp"
                       PUBLIC_LINK ""
                       PRIVATE_LINK ""
                       SYSTEM_PUBLIC_LINK "glm"
                       SYSTEM_PRIVATE_LINK ""
                      )

    if(MSVC)
        # C4868: compiler may not enforce left-to-right evaluation order in braced initializer list
        #     See fubuki_core_test's CMakeLists.txt for more info
        target_compile_options(fubuki_fuyu_test
                               PRIVATE
                               "/wd4868"
                           )
    endif() # if(MSVC)

    # Ideally, I'd like to perform static analysis here too, but it looks like my i9 14900KF isn't enough
    # to complete it by the end of the universe lifespan...
    # I'm thus disabling clang-tidy for this(these) source(s)
    set_source_files_properties(formatted_storage.cpp PROPERTIES SKIP_LINTING ON)

endif() # if(NOT ${FUBUKI_NO_IO})
