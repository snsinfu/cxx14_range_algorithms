/*
 * Test for reverse algorithms.
 *
 * Distributed under the Boost Software License, Version 1.0. (See accompanying
 * file LICENSE.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#include <array>
#include <list>

#include <catch.hpp>
#include <range.hpp>


TEST_CASE("range::reverse")
{
    SECTION("basic test") {
        std::list<int> lst {9, 4, 8, 2, 2, 6, 5, 1};
        range::reverse(lst);
        REQUIRE(lst == (std::list<int> {1, 5, 6, 2, 2, 8, 4, 9}));
    }
}

TEST_CASE("range::reverse_copy")
{
    SECTION("basic test") {
        std::list<int> lst {9, 4, 8, 2, 2, 6, 5, 1};
        std::array<int, 10> dst {{}};
        REQUIRE(range::reverse_copy(lst, dst.begin()) == dst.begin() + 8);
        REQUIRE(dst == (std::array<int, 10> {{1, 5, 6, 2, 2, 8, 4, 9}}));
    }
}
