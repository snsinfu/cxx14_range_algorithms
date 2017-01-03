/*
 * Test for rotate algorithms.
 *
 * Distributed under the Boost Software License, Version 1.0. (See accompanying
 * file LICENSE.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#include <array>
#include <forward_list>

#include <catch.hpp>
#include <range.hpp>


TEST_CASE("range::rotate")
{
    SECTION("basic test") {
        std::forward_list<int> lst {9, 4, 8, 2, 2, 6, 5, 1};
        REQUIRE(range::rotate(lst, std::next(lst.begin(), 3))
                == std::next(lst.begin(), 5));
        REQUIRE(lst == (std::forward_list<int> {2, 2, 6, 5, 1, 9, 4, 8}));
    }
}

TEST_CASE("range::rotate_copy")
{
    SECTION("basic test") {
        std::forward_list<int> lst {9, 4, 8, 2, 2, 6, 5, 1};
        std::array<int, 10> dst {{}};
        REQUIRE(range::rotate_copy(lst, std::next(lst.begin(), 3), dst.begin())
                == dst.begin() + 8);
        REQUIRE(dst == (std::array<int, 10> {{2, 2, 6, 5, 1, 9, 4, 8}}));
    }
}
