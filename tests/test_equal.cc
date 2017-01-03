/*
 * Test for equal algorithms.
 *
 * Distributed under the Boost Software License, Version 1.0. (See accompanying
 * file LICENSE.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#include <forward_list>
#include <iterator>

#include <catch.hpp>
#include <range.hpp>


TEST_CASE("range::equal")
{
    SECTION("basic test") {
        std::forward_list<int> lst1 {9, 4, 8, 2, 2, 6, 5, 1};
        std::forward_list<int> lst2 {9, 4, 8, 2, 0, 4, 3, 3};
        REQUIRE( range::equal(lst1, lst1));
        REQUIRE(!range::equal(lst1, lst2));
    }
}

TEST_CASE("range::equal (predicate)")
{
    SECTION("basic test") {
        std::forward_list<int> lst1 {9, 4, 8, 2, 2, 6, 5, 1};
        std::forward_list<int> lst2 {9, 4, 8, 2, 0, 4, 3, 3};
        REQUIRE(range::equal(lst1, lst2, [](int a, int b) {
            return a % 2 == b % 2;
        }));
    }
}
