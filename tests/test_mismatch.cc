/*
 * Test for mismatch algorithms.
 *
 * Distributed under the Boost Software License, Version 1.0. (See accompanying
 * file LICENSE.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#include <forward_list>
#include <iterator>
#include <utility>

#include <catch.hpp>
#include <range.hpp>


TEST_CASE("range::mismatch")
{
    SECTION("basic test") {
        std::forward_list<int> lst1 {9, 4, 8, 2, 2, 6, 5, 1};
        std::forward_list<int> lst2 {9, 4, 8, 2, 0, 1};
        REQUIRE(range::mismatch(lst1, lst2) ==
                    std::make_pair(std::next(lst1.begin(), 4),
                                   std::next(lst2.begin(), 4)));
    }
}

TEST_CASE("range::mismatch (predicate)")
{
    SECTION("basic test") {
        std::forward_list<int> lst1 {9, 4, 8, 2, 2, 6, 5, 1};
        std::forward_list<int> lst2 {9, 4, 8, 2, 0, 1};
        REQUIRE(
            range::mismatch(lst1, lst2, [](int a, int b) {
                return a % 2 == b % 2;
            })
            == std::make_pair(std::next(lst1.begin(), 5),
                              std::next(lst2.begin(), 5))
        );
    }
}
