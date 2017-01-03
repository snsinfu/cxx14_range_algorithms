/*
 * Test for is_permutation algorithms.
 *
 * Distributed under the Boost Software License, Version 1.0. (See accompanying
 * file LICENSE.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#include <forward_list>
#include <iterator>

#include <catch.hpp>
#include <range.hpp>


TEST_CASE("range::is_permutation")
{
    SECTION("basic test") {
        std::forward_list<int> lst1 {9, 4, 8, 2, 2, 6, 5, 1};
        std::forward_list<int> lst2 {1, 2, 2, 4, 5, 6, 8, 9};
        REQUIRE(range::is_permutation(lst1, lst2));
    }
}

TEST_CASE("range::is_permutation (predicate)")
{
    SECTION("basic test") {
        std::forward_list<int> lst1 {9, 4, 8, 2, 2, 6, 5, 1};
        std::forward_list<int> lst2 {1, 0, 0, 0, 1, 0, 0, 1};
        REQUIRE(range::is_permutation(lst1, lst2, [](int a, int b) {
            return a % 2 == b % 2;
        }));
    }
}
