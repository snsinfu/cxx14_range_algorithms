/*
 * Test for adjacent_find algorithms.
 *
 * Distributed under the Boost Software License, Version 1.0. (See accompanying
 * file LICENSE.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#include <forward_list>
#include <iterator>

#include <catch.hpp>
#include <range.hpp>


TEST_CASE("range::adjacent_find")
{
    SECTION("basic test") {
        std::forward_list<int> lst {9, 4, 8, 2, 2, 6, 5, 1};
        REQUIRE(range::adjacent_find(lst) == std::next(lst.begin(), 3));
    }
}

TEST_CASE("range::adjacent_find (predicate)")
{
    SECTION("basic test") {
        std::forward_list<int> lst {9, 4, 8, 2, 2, 6, 5, 1};
        REQUIRE(
            range::adjacent_find(lst, [](int a, int b) {
                return a % 2 == b % 2;
            })
            == std::next(lst.begin())
        );
    }
}
