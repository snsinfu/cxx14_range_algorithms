/*
 * Test for find_end algorithms.
 *
 * Distributed under the Boost Software License, Version 1.0. (See accompanying
 * file LICENSE.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#include <forward_list>
#include <iterator>

#include <catch.hpp>
#include <range.hpp>


TEST_CASE("range::find_end")
{
    SECTION("basic test") {
        std::forward_list<int> lst {9, 4, 8, 2, 2, 6, 5, 1};
        std::forward_list<int> sub {2, 2, 6};
        REQUIRE(range::find_end(lst, sub) == std::next(lst.begin(), 3));
    }
}

TEST_CASE("range::find_end (predicate)")
{
    SECTION("basic test") {
        std::forward_list<int> lst {9, 4, 8, 2, 2, 6, 5, 1};
        std::forward_list<int> sub {0, 0, 0};
        REQUIRE(
            range::find_end(lst, sub, [](int a, int b) {
                return a % 2 == b % 2;
            })
            == std::next(lst.begin(), 3)
        );
    }
}
