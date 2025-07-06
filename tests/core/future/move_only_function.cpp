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

#include <numeric>
#include <string>
#include <vector>

#include <gtest/gtest.h>

#include <core/future/move_only_function.hpp>

/*
 * These tests are based on
 * https://github.com/zhihaoy/nontype_functional/tree/main/tests
 * License: BSD-2 (https://github.com/zhihaoy/nontype_functional/blob/main/LICENSE)
 * ____________________________________________________________________________
 * BSD 2-Clause License
 *
 * Copyright (c) 2022, Zhihao Yuan
 * All rights reserved.
 * [...]
 * ____________________________________________________________________________
 *
 * The code was adapted to match gtest and the coding style.
 *
 */

// While true, this test suite requires these member functions in static_asserts for example
#if defined(__clang__)
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wunneeded-member-function"
#endif

namespace
{

using fubuki::move_only_function;
using fubuki::nontype;
using fubuki::nontype_t;

// NOLINTBEGIN(readability-convert-member-functions-to-static)
// This test suite is designed to test member functions, which must return predictable values
namespace detail
{

template<auto N>
struct int_c
{
    using value_type            = decltype(N);
    static constexpr auto value = N;

    [[nodiscard]] constexpr      operator value_type() const noexcept { return N; }
    [[nodiscard]] constexpr auto get() const { return N; }
};

constexpr int_c<0> free_function;
constexpr int_c<1> empty;
constexpr int_c<2> constness;
constexpr int_c<3> lref;
constexpr int_c<4> const_lref;
constexpr int_c<5> rref;
constexpr int_c<6> const_rref;
constexpr int_c<7> noexceptness;

struct structure
{
    int g() { return empty; }

    int data = 99;
};

int function() { return free_function; }
int function_1(structure) { return free_function; }

namespace qualifiers
{

using type = std::unique_ptr<char>;

struct unspecific_value_category : type
{
    int operator()(type) { return empty; }
};

struct l_value_only : type
{
    int operator()(type) & { return lref; }
};

struct r_value_only : type
{
    int operator()(type) && { return rref; }
};

struct either_value_category : l_value_only,
                               r_value_only
{
    using l_value_only::operator();
    using r_value_only::operator();
};

template<class T>
struct immutable_call;

template<>
struct immutable_call<unspecific_value_category> : unspecific_value_category
{
    using unspecific_value_category::operator();
    int operator()(type) const { return constness; }
};

template<>
struct immutable_call<l_value_only> : l_value_only
{
    using l_value_only::operator();
    int operator()(type) const& { return const_lref; }
};

template<>
struct immutable_call<r_value_only> : r_value_only
{
    using r_value_only::operator();
    int operator()(type) const&& { return const_rref; }
};

template<>
struct immutable_call<either_value_category> : immutable_call<l_value_only>,
                                               immutable_call<r_value_only>
{
    using immutable_call<l_value_only>::operator();
    using immutable_call<r_value_only>::operator();
};

struct nocall
{
    int unspecific_value_category(type) { return static_cast<int>('k'); }
    int lvalue_only(type) & { return static_cast<int>('k'); }
    int rvalue_only(type) && { return static_cast<int>('k'); }
    int immutable(type) const { return static_cast<int>('k'); }
    int immutable_lvalue_only(type) const& { return static_cast<int>('k'); }
    int immutable_rvalue_only(type) const&& { return static_cast<int>('k'); }
};

} // namespace qualifiers

namespace inplace
{

struct not_movable : private std::vector<int>
{
    using std::vector<int>::vector;

    not_movable(not_movable&&)            = delete;
    not_movable& operator=(not_movable&&) = delete;

    int operator()(int initial, std::string& out)
    {
        auto r = std::accumulate(begin(), end(), initial); // NOLINT(boost-use-ranges)
        out    = std::to_string(r);
        return r;
    }
};

struct not_default_constructible : public not_movable
{
    using not_movable::not_movable;

    not_default_constructible() = delete;
};

using type = move_only_function<void(int, std::string&)>;

// Required for static_assert, never really called
#if defined(__clang__)
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wunused-member-function"
#endif

struct copy_init
{
    void operator()(type) {}
};

#if defined(__clang__)
    #pragma clang diagnostic pop
#endif

} // namespace inplace

namespace no_throw
{

constexpr auto throwable_call = [](move_only_function<int()> f) { return f(); };

constexpr auto nothrow_call = [](move_only_function<int() noexcept> f) { return f(); };

template<class... T>
struct overload : T...
{
    using T::operator()...;
};

template<class... T>
overload(T...) -> overload<T...>;

constexpr auto call = overload{throwable_call, nothrow_call};

int f_good() noexcept { return free_function; }

struct structure_good
{
    int g() noexcept { return static_cast<int>('g'); }
};

int h_good(structure) noexcept { return static_cast<int>('h'); }

} // namespace no_throw

namespace return_ref
{

template<typename T>
T&& identity_fn(T&& x)
{
    return std::forward<T>(x);
}

template<typename T>
class refwrap
{
    T* m_x;

public:
    refwrap(T& obj) : m_x(std::addressof(obj)) {}

#if defined(__GNUC__)
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wnull-dereference"
#endif
    // Cannot be nullptr by design

    T& operator()() const { return *m_x; }
    T& get() const { return *m_x; }

#if defined(__GNUC__)
    #pragma GCC diagnostic pop
#endif
};

template<typename T>
refwrap(T) -> refwrap<T>;

} // namespace return_ref

namespace value_semantics
{

class move_counter
{
    std::unique_ptr<int> m_n = std::make_unique<int>(0);

public:
    int operator()() & { return (*m_n)++; }
};

} // namespace value_semantics

} // namespace detail

// NOLINTEND(readability-convert-member-functions-to-static)

TEST(move_only_function, basics)
{
    // Empty
    {
        move_only_function<int()> f = {}; // NOLINT(misc-const-correctness)
        EXPECT_FALSE(f);
        EXPECT_EQ(f, nullptr);
        EXPECT_EQ(nullptr, f);
    }

    {
        move_only_function<int()> f = detail::function;
        EXPECT_TRUE(f);
        EXPECT_NE(f, nullptr);
        EXPECT_NE(nullptr, f);

        static_assert(detail::free_function == 0);

        EXPECT_EQ(f(), 0);
    }

    {
        move_only_function<int()> f = []() { return 1; };
        EXPECT_TRUE(f);
        EXPECT_NE(f, nullptr);
        EXPECT_NE(nullptr, f);

        EXPECT_EQ(f(), 1);
    }

    {
        move_only_function<int() noexcept> f  = []() noexcept { return 1; };
        auto                               f2 = std::move(f);

        EXPECT_TRUE(f2);
        EXPECT_NE(f2, nullptr);
        EXPECT_NE(nullptr, f2);

        EXPECT_EQ(f2(), 1);
    }

    {
        auto                               l = []() noexcept { return 1; };
        move_only_function<int() noexcept> f = l;

        ASSERT_TRUE(f);
        EXPECT_NE(f, nullptr);
        EXPECT_NE(nullptr, f);
        EXPECT_EQ(f(), 1);
    }

    {
        auto                               l = []() noexcept { return 1; };
        move_only_function<int() noexcept> f = std::ref(l);

        ASSERT_TRUE(f);
        EXPECT_NE(f, nullptr);
        EXPECT_NE(nullptr, f);
        EXPECT_EQ(f(), 1);
    }

    {
        auto                               l = []() noexcept { return 1; };
        move_only_function<int() noexcept> f = std::cref(l);

        ASSERT_TRUE(f);
        EXPECT_NE(f, nullptr);
        EXPECT_NE(nullptr, f);
        EXPECT_EQ(f(), 1);
    }

    {
        const auto                         l = []() noexcept { return 1; };
        move_only_function<int() noexcept> f = l;

        ASSERT_TRUE(f);
        EXPECT_EQ(f(), 1);
    }

    {
        const auto                         l = []() noexcept { return 1; };
        move_only_function<int() noexcept> f = std::cref(l);

        ASSERT_TRUE(f);
        EXPECT_NE(f, nullptr);
        EXPECT_NE(nullptr, f);
        EXPECT_EQ(f(), 1);
    }
}

TEST(move_only_function, cv_qualifiers)
{
    using namespace detail::qualifiers;

    // No qualifier
    {
        constexpr auto call = [](move_only_function<int(type)> f) { return f(nullptr); };

        {
            using category = unspecific_value_category;
            category fn    = {};
            EXPECT_EQ(call(category{}), detail::empty);
            EXPECT_EQ(call(std::reference_wrapper{fn}), detail::empty);
        }

        {
            using category = either_value_category;
            category fn    = {};
            EXPECT_EQ(call(category{}), detail::lref);
            EXPECT_EQ(call(std::reference_wrapper{fn}), detail::lref);
        }

        {
            static_assert(not std::is_invocable_v<decltype(call), l_value_only>, "See also: https://cplusplus.github.io/LWG/issue3680");
        }

        {
            using category = immutable_call<unspecific_value_category>;
            category fn    = {};

            EXPECT_EQ(call(category{}), detail::empty);
            EXPECT_EQ(call(std::ref(fn)), detail::empty);
            EXPECT_EQ(call(std::cref(fn)), detail::constness);
        }

        {
            using category = nocall;
            category fn    = {};

            EXPECT_EQ(call({nontype<&nocall::unspecific_value_category>, fn}), static_cast<int>('k'));
            EXPECT_EQ(call({nontype<&nocall::immutable>, &fn}), static_cast<int>('k'));
            EXPECT_EQ(call({nontype<&nocall::lvalue_only>, std::ref(fn)}), static_cast<int>('k'));
        }
    }

    // const-qualified
    {
        constexpr auto call = [](move_only_function<int(type) const> const f) { return f(nullptr); };

        {
            using category = immutable_call<unspecific_value_category>;
            category fn    = {};

            EXPECT_EQ(call(category{}), detail::constness);
            EXPECT_EQ(call(std::ref(fn)), detail::empty);
            EXPECT_EQ(call(std::cref(fn)), detail::constness);
        }

        {
            using category = immutable_call<either_value_category>;

            EXPECT_EQ(call(category{}), detail::const_lref);
        }

        {
            static_assert(not std::is_invocable_v<decltype(call), unspecific_value_category>, "unqual signature is non-const-only");
        }

        {
            using category = unspecific_value_category;
            category fn    = {};

            EXPECT_EQ(call(std::ref(fn)), detail::empty);
        }

        {
            using category = nocall;
            category fn    = {};

            EXPECT_EQ(call({nontype<&nocall::immutable>, fn}), static_cast<int>('k'));
            EXPECT_EQ(call({nontype<&nocall::immutable>, &fn}), static_cast<int>('k'));
            EXPECT_EQ(call({nontype<&nocall::immutable_lvalue_only>, std::ref(fn)}), static_cast<int>('k'));
        }
    }

    // &-qualified
    {
        constexpr auto call = [](move_only_function<int(type)&> f) { return f(nullptr); };

        {
            using category = l_value_only;
            EXPECT_EQ(call(category{}), detail::lref);
        }

        {
            using category = unspecific_value_category;
            EXPECT_EQ(call(category{}), detail::empty);
        }

        {
            using category = either_value_category;
            EXPECT_EQ(call(category{}), detail::lref);
        }

        {
            static_assert(not std::is_invocable_v<decltype(call), r_value_only>, "&-qualified cannot be called as an lvalue");
        }

        {
            using category = immutable_call<unspecific_value_category>;
            EXPECT_EQ(call(category{}), detail::empty);
        }
    }

    // &&-qualified
    {
        constexpr auto call = [](move_only_function<int(type)&&> f) { return std::move(f)(nullptr); };

        {
            using category = r_value_only;

            EXPECT_EQ(call(category{}), detail::rref);
        }

        {
            using category = unspecific_value_category;

            EXPECT_EQ(call(category{}), detail::empty);
        }

        {
            using category = either_value_category;
            category fn    = {};

            EXPECT_EQ(call(category{}), detail::rref);
            EXPECT_EQ(call(std::ref(fn)), detail::lref);
        }

        {
            static_assert(not std::is_invocable_v<decltype(call), l_value_only>, "&&-qualified cannot be called as an rvalue");
        }

        {
            using category = immutable_call<unspecific_value_category>;
            category fn    = {}; // NOLINT(misc-const-correctness)

            EXPECT_EQ(call(category{}), detail::empty);
        }

        {
            using category = nocall;
            category fn    = {}; // NOLINT(misc-const-correctness)

            EXPECT_EQ(call({nontype<&nocall::rvalue_only>, fn}), static_cast<int>('k'));

            static_assert(not std::is_constructible_v<move_only_function<int(type) &&>, decltype(nontype<&nocall::immutable_rvalue_only>), nocall*>);
        }
    }

    // const-& qualified
    {
        constexpr auto call = [](move_only_function<int(type) const&> const f) { return f(nullptr); };

        {
            using category = immutable_call<l_value_only>;

            EXPECT_EQ(call(category{}), detail::const_lref);
        }

        {
            using category = immutable_call<unspecific_value_category>;

            EXPECT_EQ(call(category{}), detail::constness);
        }

        {
            using category = immutable_call<either_value_category>;

            EXPECT_EQ(call(category{}), detail::const_lref);
        }

        {
            static_assert(not std::is_invocable_v<decltype(call), immutable_call<r_value_only>>, "&&-qualified cannot be called as an lvalue");
        }

        {
            static_assert(not std::is_invocable_v<decltype(call), unspecific_value_category>, "unqual signature is non-const-only");
        }
    }

    // const-&& qualified
    {
        constexpr auto call = [](move_only_function<int(type) const&&> const f) { return static_cast<decltype(f)&&>(f)(nullptr); };

        {
            using category = immutable_call<r_value_only>;

            EXPECT_EQ(call(category{}), detail::const_rref);
        }

        {
            using category = immutable_call<unspecific_value_category>;

            EXPECT_EQ(call(category{}), detail::constness);
        }

        {
            using category = immutable_call<either_value_category>;
            category fn    = {};

            EXPECT_EQ(call(category{}), detail::const_rref);
            EXPECT_EQ(call(std::ref(fn)), detail::lref);
            EXPECT_EQ(call(std::cref(fn)), detail::const_lref);
        }

        {
            using category = immutable_call<l_value_only>;

            EXPECT_EQ(call(category{}), detail::const_lref);
        }

        {
            static_assert(not std::is_invocable_v<decltype(call), unspecific_value_category>, "unqual signature is non-const-only");
        }
    }

    static_assert(std::is_invocable_v<move_only_function<int()>>);
    static_assert(std::is_invocable_v<move_only_function<int() const>>);
    static_assert(not std::is_invocable_v<move_only_function<int()> const>);
    static_assert(std::is_invocable_v<move_only_function<int() const> const>);

    static_assert(not std::is_invocable_v<move_only_function<int()&>>);
    static_assert(std::is_invocable_v<move_only_function<int() const&>>, "const & can bind rvalue");
    static_assert(not std::is_invocable_v<move_only_function<int()&> const>);
    static_assert(std::is_invocable_v<move_only_function<int() const&> const>);

    static_assert(not std::is_invocable_v<move_only_function<int() &&>&>);
    static_assert(not std::is_invocable_v<move_only_function<int() const&&>&>);
    static_assert(not std::is_invocable_v<move_only_function<int() &&> const&>);
    static_assert(not std::is_invocable_v<move_only_function<int() const&&> const&>);
}

TEST(move_only_function, inplace)
{
    using namespace detail::inplace;

    // Non-movable types
    {
        type fn(std::in_place_type<not_movable>); // NOLINT(misc-const-correctness)

        {
            std::string s; // NOLINT(misc-const-correctness)
            fn(42, s);
            EXPECT_EQ(s, "42");
        }

        {
            auto fn2 = std::move(fn);

            std::string s; // NOLINT(misc-const-correctness)
            fn2(-1, s);

            EXPECT_EQ(s, "-1");
        }

        {
            static_assert(not std::is_invocable_v<copy_init, decltype(std::in_place_type<not_movable>)>, "Not a converting ctor");
        }
    }

    // Any accessible constructor
    {
        {
            // NOLINTNEXTLINE(misc-const-correctness)
            type        fn(std::in_place_type<not_default_constructible>, 3u, 2); // vector(count, value)
            std::string s;                                                        // NOLINT(misc-const-correctness)
            fn(0, s);

            EXPECT_EQ(s, "6");
        }

        {
            static_assert(not std::is_invocable_v<copy_init, decltype(std::in_place_type<not_default_constructible>), std::size_t, int>,
                          "Not a converting ctor");
        }

        {
            std::allocator<int> a = {};                                                             // NOLINT(misc-const-correctness)
            type                fn(std::in_place_type<not_default_constructible>, {3, 1, 5, 4}, a); // NOLINT(misc-const-correctness)
            {
                std::string s; // NOLINT(misc-const-correctness)
                fn(0, s);

                EXPECT_EQ(s, "13");
            }
            {

                static_assert(not std::is_invocable_v<copy_init, decltype(std::in_place_type<not_default_constructible>), std::initializer_list<int>>,
                              "Not a converting ctor");
            }
        }
    }

    // Types without operator()
    {
        // User-defined ctor
        {
            // NOLINTNEXTLINE(misc-const-correctness)
            move_only_function<std::string()> fn(
                nontype<[](std::vector<double>& v) { return std::to_string(v.size()); }>, std::in_place_type<std::vector<double>>, 4u);

            EXPECT_EQ(fn(), "4");
        }

        // initializer_list ctor
        {
            // NOLINTNEXTLINE(misc-const-correctness)
            move_only_function<int()> fn(
                nontype<[](std::string const& s) { return std::stoi(s); }>, std::in_place_type<std::string>, {'5', '9', '2', '\0'});

            EXPECT_EQ(fn(), 592);
        }
    }

    {
        static_assert(std::is_constructible_v<type, std::in_place_type_t<not_movable>>,
                      "std23::in_place_type should be as same as std::in_place_type");
        static_assert(not std::is_constructible_v<type, std::in_place_type_t<not_default_constructible>>);
        static_assert(std::is_constructible_v<type, std::in_place_type_t<not_default_constructible>, std::size_t>);
    }
}

TEST(move_only_function, noexcept_qualifier)
{
    using namespace detail::no_throw;

    // Callable objects
    {
        EXPECT_EQ(nothrow_call(f_good), detail::free_function);
        EXPECT_EQ(nothrow_call([]() noexcept { return detail::noexceptness; }), detail::noexceptness);
    }

    // Non-type template parameter
    {
        {
            structure_good x = {};

            EXPECT_EQ(nothrow_call({nontype<&structure_good::g>, x}), static_cast<int>('g'));
            EXPECT_EQ(nothrow_call({nontype<&structure_good::g>, &x}), static_cast<int>('g'));
            EXPECT_EQ(nothrow_call({nontype<&structure_good::g>, std::ref(x)}), static_cast<int>('g'));
        }

        {
            detail::structure a = {}; // NOLINT(misc-const-correctness)

            EXPECT_EQ(nothrow_call({nontype<&detail::structure::data>, a}), 99);
            EXPECT_EQ(nothrow_call({nontype<h_good>, a}), static_cast<int>('h'));
        }
    }

    // noexcept and non-nonexcept overloads
    {
        static_assert(not std::is_invocable_v<decltype(call), decltype(f_good)>, "a noexcept function is ambiguous to this overload set");

        EXPECT_EQ(call(detail::function), detail::free_function);
    }

    static_assert(std::is_invocable_v<decltype(throwable_call), decltype(detail::function)>);
    static_assert(std::is_invocable_v<decltype(throwable_call), decltype(f_good)>);
    static_assert(not std::is_invocable_v<decltype(nothrow_call), decltype(detail::function)>);
    static_assert(std::is_invocable_v<decltype(nothrow_call), decltype(f_good)>);

    using f1 = move_only_function<int(detail::structure)>;
    using f2 = move_only_function<int(detail::structure) noexcept>;
    using f3 = move_only_function<int(structure_good)>;
    using f4 = move_only_function<int(structure_good) noexcept>;

    static_assert(std::is_invocable_v<f1, detail::structure>);
    static_assert(not std::is_nothrow_invocable_v<f1, detail::structure>);
    static_assert(std::is_nothrow_invocable_v<f2, detail::structure>);

    static_assert(std::is_constructible_v<f1, decltype(&detail::structure::g)>);
    static_assert(std::is_constructible_v<f3, decltype(&structure_good::g)>);
    static_assert(std::is_constructible_v<f1, decltype(&detail::structure::data)>);
    static_assert(not std::is_constructible_v<f2, decltype(&detail::structure::g)>);
    static_assert(std::is_constructible_v<f4, decltype(&structure_good::g)>);
    static_assert(std::is_constructible_v<f2, decltype(&detail::structure::data)>, "pointer-to-data-member is deemed noexcept");

    using t1 = move_only_function<int()>;
    using t2 = move_only_function<int() noexcept>;

    static_assert(std::is_constructible_v<t1, nontype_t<&detail::structure::g>, detail::structure>);
    static_assert(not std::is_constructible_v<t2, nontype_t<&detail::structure::g>, detail::structure>, "member function may throw");
    static_assert(std::is_constructible_v<t1, nontype_t<&structure_good::g>, structure_good>);
    static_assert(std::is_constructible_v<t2, nontype_t<&structure_good::g>, structure_good>);
    static_assert(std::is_constructible_v<t1, nontype_t<detail::function_1>, detail::structure>);
    static_assert(not std::is_constructible_v<t2, nontype_t<detail::function_1>, detail::structure>, "explicit member function may throw");
    static_assert(std::is_constructible_v<t1, nontype_t<h_good>, detail::structure>);
    static_assert(std::is_constructible_v<t2, nontype_t<h_good>, detail::structure>);
}

TEST(move_only_function, nontype)
{
    using type = move_only_function<int() const>;

    // Type-erase a bound instance method
    {
        // Objects with operator()
        {
            auto obj = std::make_optional<detail::structure>();

            {
                type fn = {nontype<&detail::structure::data>, &obj.value()}; // NOLINT(misc-const-correctness)

                {
                    obj->data = 27;
                    EXPECT_EQ(fn(), 27);
                }

                {
                    fn = {nontype<&detail::structure::data>, std::optional{obj}}; // Copy

                    obj->data = 84;
                    EXPECT_EQ(fn(), 27); // Value set in the previous scope
                }

                {
                    static_assert(std::is_constructible_v<type, nontype_t<detail::function_1>, decltype(*obj)>);
                    static_assert(not std::is_constructible_v<type, nontype_t<detail::function_1>, decltype(obj)>,
                                  "non-member does not dereference pointer-like objects");

                    using obj_t = decltype(obj);
                    static_assert(std::is_constructible_v<type, nontype_t<[](obj_t const& x) { return detail::function_1(*x); }>, obj_t>,
                                  "...but you can DIY");
                }
            }
        }
    }

    // Type-erase an unbound instance method
    {
        move_only_function<int(detail::structure&)> fn;       // NOLINT(misc-const-correctness)
        detail::structure                           obj = {}; // NOLINT(misc-const-correctness)

        // memfn-like
        {
            fn       = nontype<&detail::structure::data>;
            obj.data = 33;
            EXPECT_EQ(fn(obj), 33);
        }

        // Like a function
        {
            fn = nontype<detail::function_1>;

            EXPECT_EQ(fn(obj), detail::free_function);
        }
    }

    {
        using type2 = move_only_function<int(detail::structure)>;

        static_assert(std::is_nothrow_constructible_v<type2, nontype_t<&detail::structure::data>>);
        static_assert(std::is_nothrow_constructible_v<type2, nontype_t<detail::function_1>>, "unbounded cases are always noexcept");
        static_assert(std::is_nothrow_assignable_v<type2, nontype_t<&detail::structure::data>>);
        static_assert(std::is_nothrow_assignable_v<type2, nontype_t<detail::function_1>>);

        static_assert(std::is_constructible_v<type, nontype_t<&detail::structure::data>, detail::structure>);
        static_assert(std::is_constructible_v<type, nontype_t<detail::function_1>, detail::structure>,
                      "initializing bounded objects potentially throws");

        // extension
        static_assert(std::is_nothrow_constructible_v<type, nontype_t<&detail::structure::data>, detail::structure*>,
                      "...unless we stored a pointer");
        static_assert(std::is_nothrow_constructible_v<type, nontype_t<&detail::structure::data>, std::reference_wrapper<detail::structure>>,
                      "...or reference_wrapper");
    }
}

TEST(move_only_function, nullable)
{
    // Becomes empty when assigned nullptr
    {
        move_only_function<int()> fn = detail::function;
        EXPECT_NE(fn, nullptr);

        {
            decltype(detail::function)* p = {};
            fn                            = p;
            EXPECT_FALSE(fn);
        }
    }

    // Empty when assigned a null pointer to member function
    {
        struct meow
        {
            int data = 99;
        };

        meow a = {}; // NOLINT(misc-const-correctness)

        int meow::*                   pm = {}; // NOLINT(misc-const-correctness)
        move_only_function<int(meow)> fn = pm;

        EXPECT_FALSE(fn);

        fn = &meow::data;
        ASSERT_TRUE(bool(fn));
        EXPECT_EQ(fn(a), 99);
    }

    // Empty when assigned an empty move_only_function
    {
        move_only_function<int()> fn; // NOLINT(misc-const-correctness)
        EXPECT_FALSE(fn);
        move_only_function<std::int32_t()> fn2 = std::move(fn); // NOLINT(misc-const-correctness)
        EXPECT_FALSE(fn2);
    }
}

TEST(move_only_function, reference_semantics)
{
    struct counter
    {
        int n = 0;

#if defined(__GNUC__)
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wnull-dereference"
#endif
        void operator()() & { ++n; }

#if defined(__GNUC__)
    #pragma GCC diagnostic pop
#endif
    };

    {
        counter                    obj = {};            // NOLINT(misc-const-correctness)
        move_only_function<void()> fn  = std::ref(obj); // NOLINT(misc-const-correctness)

        fn();
        fn();

        EXPECT_EQ(obj.n, 2);

        // Swap
        {
            counter other = {}; // NOLINT(misc-const-correctness)

            move_only_function<void()> fn2(std::in_place_type<std::reference_wrapper<counter>>, other); // NOLINT(misc-const-correctness)
            swap(fn, fn2);

            EXPECT_EQ(obj.n, 2);
            EXPECT_EQ(other.n, 0);

            fn();
            EXPECT_EQ(other.n, 1);

            fn2();
            EXPECT_EQ(obj.n, 3);
        }
    }

    // const-correctness
    {
        counter                          obj = {.n = 3};      // NOLINT(misc-const-correctness)
        move_only_function<void() const> fn  = std::ref(obj); // NOLINT(misc-const-correctness)

        // "Broken" by reference wrapper by design
        fn();
        EXPECT_EQ(obj.n, 4);

        using type = decltype(fn);
        static_assert(not std::is_constructible_v<type, counter>, "counter's call op is not const");
        static_assert(std::is_constructible_v<type, std::reference_wrapper<counter>>, "refwrap's call op is unconditionally const");
        static_assert(not std::is_constructible_v<type, std::reference_wrapper<counter const>>, "refwrap's call op is constrained");
    }

    {
        using t1 = move_only_function<void(int)>;
        using t2 = decltype([](int) {});

        static_assert(std::is_constructible_v<t1, t2>);
        static_assert(std::is_constructible_v<t1, std::reference_wrapper<t2>>);
        static_assert(std::is_assignable_v<t1, t2>);
        static_assert(std::is_constructible_v<t1, std::reference_wrapper<t2>>);

        static_assert(std::is_constructible_v<t1, std::in_place_type_t<t2>>);
        static_assert(std::is_constructible_v<t1, std::in_place_type_t<std::reference_wrapper<t2>>, t2&>);

        // extension
        static_assert(std::is_nothrow_constructible_v<t1, std::reference_wrapper<t2>>);
        static_assert(std::is_nothrow_assignable_v<t1, std::reference_wrapper<t2>>);
        static_assert(std::is_nothrow_constructible_v<t1, void (&)(int)>);
        static_assert(std::is_nothrow_constructible_v<t1, void (*)(int)>);
        static_assert(std::is_nothrow_assignable_v<t1, void (&)(int)>);
        static_assert(std::is_nothrow_assignable_v<t1, void (*)(int)>);
    }
}

TEST(move_only_function, return_ref)
{
    using namespace detail::return_ref;

    // Variable
    {
        int                            x  = {};
        move_only_function<int&(int&)> fn = identity_fn<int&>;
        EXPECT_EQ(std::addressof(fn(x)), &x);
    }

    // Data member
    {
        int     x   = {};
        refwrap obj = x; // NOLINT(misc-const-correctness)

        {
            move_only_function<int&()> fn = obj;
            EXPECT_EQ(std::addressof(fn()), &x);
        }

        {
            move_only_function<int&() const> fn = obj; // NOLINT(misc-const-correctness)
            EXPECT_EQ(std::addressof(fn()), &x);
        }
    }

    // Pointer to member object
    {
        int     x   = {};
        refwrap obj = x; // NOLINT(misc-const-correctness)

        {
            move_only_function<int&(refwrap<int> const&)> fn = nontype<&refwrap<int>::get>;
            EXPECT_EQ(std::addressof(fn(obj)), &x);
        }

        {
            move_only_function<int&()> fn = {nontype<&refwrap<int>::get>, obj};
            EXPECT_EQ(std::addressof(fn()), &x);
        }

        {
            move_only_function<int&() const> fn = {nontype<&refwrap<int>::get>, obj}; // NOLINT(misc-const-correctness)
            EXPECT_EQ(std::addressof(fn()), &x);
        }
    }
}

// NOTE: the original test_unique is skipped, as I can't really understand what is being tested, and how

TEST(move_only_function, value_semantics)
{
    using namespace detail::value_semantics;

    // Stateful move_only_function
    {
        move_only_function<int()&> fn = move_counter();

        {
            fn();
            fn();
            EXPECT_EQ(fn(), 2);
        }

        {
            swap(fn, fn);
            EXPECT_NE(fn, nullptr);
            EXPECT_EQ(fn(), 3);
        }

        {
            auto fn2 = std::move(fn);
            EXPECT_EQ(fn2(), 4);
        }
    }

    // Same as above, but with two objects
    {
        move_only_function<int()&> fn1 = move_counter();
        move_only_function<int()&> fn2 = move_counter();

        fn1();
        EXPECT_EQ(fn1(), 1);

        fn2();
        fn2();
        fn2();
        EXPECT_EQ(fn2(), 3);

        {
            swap(fn1, fn2);

            EXPECT_EQ(fn1(), 4);
            EXPECT_EQ(fn2(), 2);
        }
    }

    {
        using type   = move_only_function<void(int)>;
        using result = type::result_type;

        static_assert(std::is_nothrow_default_constructible_v<type>);
        static_assert(std::is_nothrow_constructible_v<type, std::nullptr_t>);
        static_assert(not std::is_copy_constructible_v<type>);
        static_assert(not std::is_copy_assignable_v<type>);
        static_assert(std::is_nothrow_assignable_v<type, std::nullptr_t>);
        static_assert(std::is_nothrow_move_constructible_v<type>);
        static_assert(std::is_nothrow_move_assignable_v<type>);
        static_assert(std::is_nothrow_swappable_v<type>);

        static_assert(std::is_same_v<std::invoke_result_t<type, char>, result>);

        struct reject_rvalue
        {
            friend detail::structure; // silence Wctor-dtor-privacy
            reject_rvalue(reject_rvalue&) = default;

            void operator()(int) {}
            void mf(int) {}
        };

        static_assert(not std::is_move_constructible_v<reject_rvalue>);
        static_assert(std::is_invocable_r_v<void, reject_rvalue, int>);

        static_assert(std::is_constructible_v<type, reject_rvalue&>);
        static_assert(not std::is_constructible_v<type, reject_rvalue>, "target object must be initialized");

        static_assert(std::is_constructible_v<type, nontype_t<&reject_rvalue::mf>, reject_rvalue&>);
        static_assert(not std::is_constructible_v<type, nontype_t<&reject_rvalue::mf>, reject_rvalue>, "bounded target object must be initialized");
    }
}

#if defined(__clang__)
    #pragma clang diagnostic pop
#endif

} // anonymous namespace
