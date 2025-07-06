/*
 * BSD 2-Clause License
 *
 * Copyright (c) 2025, Erwan DUHAMEL
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

#ifndef FUBUKI_IO_PLATFORM_EVENT_DISPATCHER_HPP
#define FUBUKI_IO_PLATFORM_EVENT_DISPATCHER_HPP

#include <algorithm>
#include <memory>

#include <core/small_vector.hpp>

#include "io/platform/event/handler.hpp"

namespace fubuki::io::platform::event
{

/**
 * An object dispatching events to handlers.
 *
 * event::dispatcher behaves like a container or `event::handler`, sorted by priority.
 *
 * @note Insertions and deletions of an event handler, along with calls to functions modifying this container must be externally synchronised.
 */
class dispatcher
{

public:

    /********************************************************************************/
    /*                            PUBLIC MEMBER TYPES                               */
    /********************************************************************************/

    struct priority
    {
        float value = 0.f;

        [[nodiscard]] friend constexpr bool operator==(const priority&, const priority&)  = default;
        [[nodiscard]] friend constexpr bool operator!=(const priority&, const priority&)  = default;
        [[nodiscard]] friend constexpr auto operator<=>(const priority&, const priority&) = default;

        /// Swaps two objects.
        constexpr void swap(priority& other) noexcept { std::swap(value, other.value); }

        /// Swaps two objects.
        constexpr friend void swap(priority& a, priority& b) noexcept { a.swap(b); }
    };

    struct entry
    {
        std::unique_ptr<event::handler> handle     = {nullptr}; ///< Event handler.
        priority                        precedence = {0.f};     ///< Priority of the event handler this entry holds.
        bool                            marked     = false;     ///< Indicates if this entry will be removed.

        [[nodiscard]] friend constexpr bool operator==(const entry&, const entry&)  = default;
        [[nodiscard]] friend constexpr bool operator!=(const entry&, const entry&)  = default;
        [[nodiscard]] friend constexpr auto operator<=>(const entry&, const entry&) = default;

        /// Swaps two objects.
        constexpr void swap(entry& other) noexcept
        {
            handle.swap(other.handle);
            precedence.swap(other.precedence);
            std::swap(marked, other.marked);
        }

        /// Swaps two objects.
        constexpr friend void swap(entry& a, entry& b) noexcept { a.swap(b); }
    };

    using underlying_type = small_vector<entry>;

    using value_type      = underlying_type::value_type;
    using size_type       = underlying_type::size_type;
    using difference_type = underlying_type::difference_type;
    using reference       = underlying_type::reference;
    using const_reference = underlying_type::const_reference;
    using pointer         = underlying_type::pointer;
    using const_pointer   = underlying_type::const_pointer;

    using iterator               = underlying_type::iterator;
    using const_iterator         = underlying_type::const_iterator;
    using reverse_iterator       = underlying_type::reverse_iterator;
    using const_reverse_iterator = underlying_type::const_reverse_iterator;

    /********************************************************************************/
    /*                    CONSTRUCTION, ASSIGNEMENT, DESTRUCTION                    */
    /********************************************************************************/

    dispatcher() = default;

    dispatcher(dispatcher&& other) noexcept { swap(other); }

    dispatcher& operator=(dispatcher&& other) noexcept
    {
        swap(other);
        return *this;
    }

    dispatcher(const dispatcher&)            = delete;
    dispatcher& operator=(const dispatcher&) = delete;

    ~dispatcher() = default;

    /********************************************************************************/
    /*                                  ITERATORS                                   */
    /********************************************************************************/

    [[nodiscard]] auto begin() const noexcept { return m_handlers.begin(); }
    [[nodiscard]] auto end() const noexcept { return m_handlers.end(); }

    [[nodiscard]] auto begin() noexcept { return m_handlers.begin(); }
    [[nodiscard]] auto end() noexcept { return m_handlers.end(); }

    [[nodiscard]] auto cbegin() const noexcept { return m_handlers.cbegin(); }
    [[nodiscard]] auto cend() const noexcept { return m_handlers.cend(); }

    [[nodiscard]] auto rbegin() const noexcept { return m_handlers.rbegin(); }
    [[nodiscard]] auto rend() const noexcept { return m_handlers.rend(); }

    [[nodiscard]] auto rbegin() noexcept { return m_handlers.rbegin(); }
    [[nodiscard]] auto rend() noexcept { return m_handlers.rend(); }

    [[nodiscard]] auto crbegin() const noexcept { return m_handlers.crbegin(); }
    [[nodiscard]] auto crend() const noexcept { return m_handlers.crend(); }

    /********************************************************************************/
    /*                                  ELEMENT ACCESS                              */
    /********************************************************************************/

    /// Returns the first event handler, with the highest priority. The behaviour is undefined if this array is empty.
    [[nodiscard]] const event::handler& front() const noexcept
    {
        fubuki_assert(not empty(), "This array is empty");
        fubuki_assert(m_handlers.front().handle != nullptr, "Internal error. Should never happen.");

        return *m_handlers.front().handle;
    }

    /// Returns the first event handler, with the highest priority. The behaviour is undefined if this array is empty.
    [[nodiscard]] event::handler& front() noexcept
    {
        fubuki_assert(not empty(), "This array is empty");
        fubuki_assert(m_handlers.front().handle != nullptr, "Internal error. Should never happen.");

        return *m_handlers.front().handle;
    }

    /// Returns the last event handler, with the lowest priority. The behaviour is undefined if this array is empty.
    [[nodiscard]] const event::handler& back() const noexcept
    {
        fubuki_assert(not empty(), "This array is empty");
        fubuki_assert(m_handlers.back().handle != nullptr, "Internal error. Should never happen.");

        return *m_handlers.back().handle;
    }

    /// Returns the last event handler, with the lowest priority. The behaviour is undefined if this array is empty.
    [[nodiscard]] event::handler& back() noexcept
    {
        fubuki_assert(not empty(), "This array is empty");
        fubuki_assert(m_handlers.back().handle != nullptr, "Internal error. Should never happen.");

        return *m_handlers.back().handle;
    }

    /// Returns the event handler at the given index. Throws an instance of std::out_of_range if `idx >= size()`.
    [[nodiscard]] const event::handler& at(std::size_t idx) const
    {
        if(idx >= size())
        {
            throw std::out_of_range("Index out-of-bounds (max:" + std::to_string(size()) + ")");
        }
        fubuki_assert(m_handlers[idx].handle != nullptr, "Internal error. Should never happen.");

        return *m_handlers[idx].handle;
    }

    /// Returns the event handler at the given index. Throws an instance of std::out_of_range if `idx >= size()`.
    [[nodiscard]] event::handler& at(std::size_t idx)
    {
        if(idx >= size())
        {
            throw std::out_of_range("Index out-of-bounds (max:" + std::to_string(size()) + ")");
        }
        fubuki_assert(m_handlers[idx].handle != nullptr, "Internal error. Should never happen.");

        return *m_handlers[idx].handle;
    }

    /// Returns the event handler at the given index. The behaviour is undefined if `idx >= size()`.
    [[nodiscard]] const event::handler& operator[](std::size_t idx) const noexcept
    {
        fubuki_assert(idx < size(), "Index out-of-bounds (max: " << size() << ")");
        fubuki_assert(m_handlers[idx].handle != nullptr, "Internal error. Should never happen.");

        return *m_handlers[idx].handle;
    }

    /// Returns the event handler at the given index. The behaviour is undefined if `idx >= size()`.
    [[nodiscard]] event::handler& operator[](std::size_t idx) noexcept
    {
        fubuki_assert(idx < size(), "Index out-of-bounds (max: " << size() << ")");
        fubuki_assert(m_handlers[idx].handle != nullptr, "Internal error. Should never happen.");

        return *m_handlers[idx].handle;
    }

    /********************************************************************************/
    /*                                    CAPACITY                                  */
    /********************************************************************************/

    /// Returns the size of this array.
    [[nodiscard]] std::size_t size() const noexcept { return m_handlers.size(); }

    /// Indicates if this array is empty.
    [[nodiscard]] bool empty() const noexcept { return m_handlers.empty(); }

    /********************************************************************************/
    /*                          PUBLIC MEMBER FUNCTIONS                             */
    /********************************************************************************/

    /// Forwards an event to all handlers.
    /// @warning This function is meant to be called from a window. Calling event::dispatcher::process() directly will NOT update the state of the
    /// window.
    template<typename event_type>
    void process(surface_data surface, event_type&& event) noexcept
    {
        if(m_state.update_pending)
        {
            sort();
        }

        m_state.active = true;

        for(entry& handler : m_handlers)
        {
            if(not handler.handle->enabled()) // Purposefully not views::filter to allow mutation while iterating
            {
                continue;
            }

            handler.handle->handle(surface, std::forward<event_type>(event));
        }

        m_state.active = false;
    }

    /// Forwards an event to all the handlers.
    /// @warning This function is meant to be called from a window. Calling event::dispatcher::process() directly will NOT update the state of the
    /// window.
    bool process(surface_data surface, event::window::close event) noexcept
    {
        if(m_state.update_pending)
        {
            sort();
        }

        m_state.active = true;

        bool will_close = not m_handlers.empty(); // Accept when no handlers are installed or when all are disabled
        for(entry& handler : m_handlers)
        {
            if(not handler.handle->enabled()) // Purposefully not views::filter to allow mutation while iterating
            {
                continue;
            }

            const auto answer = handler.handle->handle(surface, event);
            will_close        = will_close and (answer == event::answer::accept);
        }

        m_state.active = false;

        return will_close;
    }

    /********************************************************************************/
    /*                              ACCESSORS, MUTATORS                             */
    /********************************************************************************/

    /// Indicates if this object is active, that is, an event is being processed.
    [[nodiscard]] bool active() const noexcept { return m_state.active; }

    /// Forces an update of the priorities of all event handlers contained and removes all handles marked for removal.
    /// If this dispatcher is `active()`, the update is performed in the next call of `process()` or the next call of `refresh_priorities()`
    /// when it is no more active.
    void refresh()
    {
        if(m_state.active)
        {
            m_state.update_pending = true;
        }
        else
        {
            sort();
        }
    }

    /// Removes all event handlers.
    void clear() { m_handlers.clear(); }

    /**
     * Adds an event handler.
     * @warning The behaviour is undefined if called while the dispatcher is active().
     *
     * @param p Priority of this event. The higher this value, the sooner it will handle the events (compared to other handlers).
     * @param h (variadic) Handler to add.
     *
     */
    iterator add(priority p, std::unique_ptr<event::handler> h)
    {
        // Sanity checks
        {
            fubuki_assert(h != nullptr, "Event handler must not be nullptr.");
        }

        // Works because we call ranges::filter in process, so the loop is computed lazily

        const auto insert_pos = std::ranges::upper_bound(
            m_handlers.begin(), m_handlers.end(), p.value, std::greater<float>{}, [](const entry& e) noexcept { return e.precedence.value; });

        return m_handlers.emplace(insert_pos, entry{std::move(h), p});
    }

    /**
     * Adds an event handler.
     * @warning The behaviour is undefined if called while the dispatcher is active().
     *
     * @tparam handler_type Event handler type.
     * @tparam args_type Deduced. Types of the arguments to construct the handler.
     *
     * @param p Priority of this event. The higher this value, the sooner it will handle the events (compared to other handlers).
     * @param args (variadic) Arguments to construct the event handler.
     *
     * @pre handler_type must be a child class of fubuki::event::handler.
     */
    template<typename handler_type, typename... args_type>
    auto add(const priority p, args_type&&... args)
    requires(std::is_base_of_v<event::handler, handler_type>)
    {
        return add(p, std::make_unique<handler_type>(std::forward<args_type>(args)...));
    }

    /// Marks or unmarks an handler for removal or upon the next call to process() or to refresh().
    void mark(iterator it, bool b)
    {
        fubuki_assert(begin() <= it, "iterator not in range");
        fubuki_assert(it <= end(), "iterator not in range");
        it->marked             = b;
        m_state.update_pending = true;
    }

    /// Marks an handler for removal upon the next call to process() or to refresh().
    void mark(iterator it) { return mark(it, true); }

    /// Unmarks an handler for removal upon the next call to process() or to refresh().
    void unmark(iterator it) { return mark(it, false); }

    void        swap(dispatcher& other) noexcept { m_handlers.swap(other.m_handlers); }
    friend void swap(dispatcher& a, dispatcher& b) noexcept { a.swap(b); }

private:

    void sort()
    {
        if(m_state.active)
        {
            m_state.update_pending = true;
            return;
        }

        {
            auto marked = std::ranges::remove_if(m_handlers.begin(), m_handlers.end(), [](const entry& e) noexcept { return e.marked; });
            m_handlers.erase(std::ranges::begin(marked), std::ranges::end(marked));
        }

        std::ranges::sort(m_handlers, [](const entry& a, const entry& b) noexcept { return a.precedence.value > b.precedence.value; });
        m_state.update_pending = false;
    }

    struct status
    {
        bool update_pending = false;
        bool active         = false;
    };

    small_vector<entry> m_handlers{}; ///< Event handlers owned by this dispatcher.
    status              m_state = {}; ///< The state of this object.
};

} // namespace fubuki::io::platform::event

#endif // FUBUKI_IO_PLATFORM_EVENT_DISPATCHER_HPP
