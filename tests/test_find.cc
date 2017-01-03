/*
 * Test for find algorithms.
 *
 * Distributed under the Boost Software License, Version 1.0. (See accompanying
 * file LICENSE.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#include <forward_list>
#include <iterator>

#include <catch.hpp>
#include <range.hpp>


TEST_CASE("range::find (value)")
{
    SECTION("basic test") {
        std::forward_list<int> lst {9, 4, 8, 2, 2, 6, 5, 1};
        REQUIRE(range::find(lst, 2) == std::next(lst.begin(), 3));
    }
}

TEST_CASE("range::find (predicate)")
{
    SECTION("basic test") {
        std::forward_list<int> lst {9, 4, 8, 2, 2, 6, 5, 1};
        REQUIRE(range::find_if(lst, [](int v) { return v < 4; })
                == std::next(lst.begin(), 3));
    }
}

TEST_CASE("range::find (negative predicate)")
{
    SECTION("basic test") {
        std::forward_list<int> lst {9, 4, 8, 2, 2, 6, 5, 1};
        REQUIRE(range::find_if_not(lst, [](int v) { return v > 4; })
                == std::next(lst.begin(), 1));
    }
}
