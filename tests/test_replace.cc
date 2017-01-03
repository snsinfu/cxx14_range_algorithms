/*
 * Test for replace algorithms.
 *
 * Distributed under the Boost Software License, Version 1.0. (See accompanying
 * file LICENSE.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#include <array>
#include <forward_list>

#include <catch.hpp>
#include <range.hpp>


TEST_CASE("range::replace")
{
    SECTION("basic test") {
        std::forward_list<int> lst {9, 4, 8, 2, 2, 6, 5, 1};
        range::replace(lst, 2, 0);
        REQUIRE(lst == (std::forward_list<int> {9, 4, 8, 0, 0, 6, 5, 1}));
    }
}

TEST_CASE("range::replace_if")
{
    SECTION("basic test") {
        std::forward_list<int> lst {9, 4, 8, 2, 2, 6, 5, 1};
        range::replace_if(lst, [](int a) { return a % 2 == 0; }, 0);
        REQUIRE(lst == (std::forward_list<int> {9, 0, 0, 0, 0, 0, 5, 1}));
    }
}

TEST_CASE("range::replace_copy")
{
    SECTION("basic test") {
        std::forward_list<int> src {9, 4, 8, 2, 2, 6, 5, 1};
        std::array<int, 10> dst {{}};
        REQUIRE(range::replace_copy(src, dst.begin(), 2, 0) == dst.begin() + 8);
        REQUIRE(dst == (std::array<int, 10> {{9, 4, 8, 0, 0, 6, 5, 1}}));
    }
}

TEST_CASE("range::replace_copy_if")
{
    SECTION("basic test") {
        std::forward_list<int> src {9, 4, 8, 2, 2, 6, 5, 1};
        std::array<int, 10> dst {{}};
        REQUIRE(
            range::replace_copy_if(src, dst.begin(), [](int a) {
                return a % 2 == 0;
            }, 0)
            == dst.begin() + 8);
        REQUIRE(dst == (std::array<int, 10> {{9, 0, 0, 0, 0, 0, 5, 1}}));
    }
}
