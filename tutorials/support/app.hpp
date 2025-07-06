/*
 * BSD 2-Clause License
 *
 * Copyright (c) 2022-2024, Erwan DUHAMEL
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef FUBUKI_TUTORIAL_SUPPORT_APP_HPP
#define FUBUKI_TUTORIAL_SUPPORT_APP_HPP

#include "export.hpp"
#include "resources.hpp"
#include "setup.hpp"

/// The resources typically needed during the application lifetime.
namespace fubuki::tutorial::support::app
{

/**
 * A RAII object ensuring the deletion of the resources when it goes out of scope.
 *
 * @section example Example
 *
 * @code{.cpp}
 * #include <tutorial/app.hpp>
 *
 * int main()
 * {
 *     const auto app_resources_scope = fubuki::tutorial::app::init({});
 *
 *     if(not app_resources_scope)
 *     {
 *         std::cerr << "Failed to create the resources for the application. API error: " << app_resources_scope.error();
 *         return 1;
 *     }
 *
 *     ...
 *     return 0;
 * }
 * @endcode
 */
struct scoped_init
{
    scoped_init() noexcept = default;
    ~scoped_init() noexcept;

    scoped_init(const scoped_init&) = delete;
    scoped_init(scoped_init&&)      = delete;

    scoped_init& operator=(const scoped_init&) = delete;
    scoped_init& operator=(scoped_init&&)      = delete;
};

namespace get
{

class token;

[[nodiscard]] FUBUKI_TUTORIAL_SUPPORT_API std::unique_ptr<resources>& rc(token) noexcept;

class token
{
public:
    token(const token&) noexcept            = default;
    token(token&&) noexcept                 = default;
    token& operator=(const token&) noexcept = default;
    token& operator=(token&&) noexcept      = default;

    /// Creates the resources needed for the application lifetime.
    /// @returns Nothing, or the API call that failed.
    template<fubuki::traits::pnext_chain::type instance_pnext, fubuki::traits::pnext_chain::type device_pnext>
    [[nodiscard]]
    static std::expected<scoped_init, error::any> do_init(setup s, setup::pnext<instance_pnext, device_pnext> pnext) noexcept
    {
        // Defined as a static member function as a workaround for gcc, that doesn't support definitions of template friend functions outside classes

        auto& current = rc(token{});

        if(current == nullptr)
        {
            auto initialised = resources::make_unique(std::move(s), std::move(pnext));

            if(not initialised.has_value())
            {
                return std::unexpected{initialised.error()};
            }

            current = *std::move(initialised);
        }

        return {};
    }

private:
    token() noexcept = default;

    friend void shutdown() noexcept;

    friend const fubuki::fuyu::instance&       instance() noexcept;
    friend const fubuki::fuyu::device&         device() noexcept;
    friend const fubuki::fuyu::pipeline_cache& pipeline_cache() noexcept;
    friend const fubuki::fuyu::surface&        surface() noexcept;
    friend fubuki::fuyu::swapchain&            swapchain() noexcept;
    friend fubuki::fuyu::swapchain_resources&  swapchain_resources() noexcept;

    friend fubuki::io::display&      display() noexcept;
    friend fubuki::io::window&       window() noexcept;
    friend fubuki::io::event::queue& event_queue() noexcept;
};

template<fubuki::traits::pnext_chain::type instance_pnext, fubuki::traits::pnext_chain::type device_pnext>
[[nodiscard]] inline std::expected<scoped_init, error::any> init(setup s, setup::pnext<instance_pnext, device_pnext> pnext) noexcept
{
    // Workaround for GCC, that doesn't support definitions of template friend functions outside classes
    return token::do_init(std::move(s), std::move(pnext));
}

inline void shutdown() noexcept { rc(token{}).reset(); }

[[nodiscard]] inline const fubuki::fuyu::instance& instance() noexcept
{
    fubuki_assert(rc(token{}) != nullptr, "App resources not instantiated");
    return rc(token{})->instance();
}

[[nodiscard]] inline const fubuki::fuyu::device& device() noexcept
{
    fubuki_assert(rc(token{}) != nullptr, "App resources not instantiated");
    return rc(token{})->device();
}

[[nodiscard]] inline const fubuki::fuyu::pipeline_cache& pipeline_cache() noexcept
{
    fubuki_assert(rc(token{}) != nullptr, "App resources not instantiated");
    return rc(token{})->pipeline_cache();
}

[[nodiscard]] inline const fubuki::fuyu::surface& surface() noexcept
{
    fubuki_assert(rc(token{}) != nullptr, "App resources not instantiated");
    return rc(token{})->surface();
}

[[nodiscard]] inline fubuki::fuyu::swapchain& swapchain() noexcept
{
    fubuki_assert(rc(token{}) != nullptr, "App resources not instantiated");
    return rc(token{})->swapchain();
}

[[nodiscard]] inline fubuki::fuyu::swapchain_resources& swapchain_resources() noexcept
{
    fubuki_assert(rc(token{}) != nullptr, "App resources not instantiated");
    return rc(token{})->swapchain_resources();
}

[[nodiscard]] inline fubuki::io::display& display() noexcept
{
    fubuki_assert(rc(token{}) != nullptr, "App resources not instantiated");
    return rc(token{})->display();
}

[[nodiscard]] inline fubuki::io::window& window() noexcept
{
    fubuki_assert(rc(token{}) != nullptr, "App resources not instantiated");
    return rc(token{})->window();
}

[[nodiscard]] inline fubuki::io::event::queue& event_queue() noexcept
{
    fubuki_assert(rc(token{}) != nullptr, "App resources not instantiated");
    return rc(token{})->event_queue();
}

} // namespace get

/// Creates the resources needed for the application lifetime.
/// @returns Nothing, or the API call that failed.
template<fubuki::traits::pnext_chain::type instance_pnext = fubuki::pnext_chain<>,
         fubuki::traits::pnext_chain::type device_pnext   = fubuki::pnext_chain<>>
[[nodiscard("The returned object frees app resources upon destruction.")]]
inline std::expected<scoped_init, error::any> init(setup s, setup::pnext<instance_pnext, device_pnext> pnext) noexcept
{
    return get::init(std::move(s), std::move(pnext));
}

/// Creates the resources needed for the application lifetime.
/// @returns Nothing, or the API call that failed.
[[nodiscard("The returned object frees app resources upon destruction.")]]
inline std::expected<scoped_init, error::any> init(setup s) noexcept
{
    return init(std::move(s), setup_pnext{});
}

/// Destroys the app resources.
inline void shutdown() noexcept { get::shutdown(); }

inline scoped_init::~scoped_init() noexcept { shutdown(); }

/// Returns a reference to the instance used by the application.
[[nodiscard]] inline const fubuki::fuyu::instance& instance() noexcept { return get::instance(); }

/// Returns a reference to the device used by the application.
[[nodiscard]] inline const fubuki::fuyu::device& device() noexcept { return get::device(); }

/// Returns a reference to the pipeline cache used by the application.
[[nodiscard]] inline const fubuki::fuyu::pipeline_cache& pipeline_cache() noexcept { return get::pipeline_cache(); }

/// Returns a reference to the pipeline cache used by the application.
[[nodiscard]] inline const fubuki::fuyu::surface& surface() noexcept { return get::surface(); }

/// Returns a reference to the swapchain used by the application.
[[nodiscard]] inline fubuki::fuyu::swapchain& swapchain() noexcept { return get::swapchain(); }

/// Returns a reference to the swapchain resources used by the application.
[[nodiscard]] inline fubuki::fuyu::swapchain_resources& swapchain_resources() noexcept { return get::swapchain_resources(); }

/// Returns a reference to the displayused by this application.
[[nodiscard]] inline fubuki::io::display& display() noexcept { return get::display(); }

/// Returns a reference to the window used by this application.
[[nodiscard]] inline fubuki::io::window& window() noexcept { return get::window(); }

/// Returns a reference to a default user event queue the application can use for non-system events.
[[nodiscard]] inline fubuki::io::event::queue& user_event_queue() noexcept { return get::event_queue(); }

} // namespace fubuki::tutorial::support::app

#endif // FUBUKI_TUTORIAL_SUPPORT_APP_HPP
