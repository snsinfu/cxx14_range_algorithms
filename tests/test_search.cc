/*
 * Test for search algorithms.
 *
 * Distributed under the Boost Software License, Version 1.0. (See accompanying
 * file LICENSE.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#include <forward_list>
#include <iterator>

#include <catch.hpp>
#include <range.hpp>


TEST_CASE("range::search")
{
    SECTION("basic test") {
        std::forward_list<int> lst {9, 4, 8, 2, 2, 6, 5, 1};
        std::forward_list<int> sub {2, 2};
        REQUIRE(range::search(lst, sub) == std::next(lst.begin(), 3));
    }
}

TEST_CASE("range::search (predicate)")
{
    SECTION("basic test") {
        std::forward_list<int> lst {9, 4, 8, 2, 2, 6, 5, 1};
        std::forward_list<int> sub {2, 2};
        REQUIRE(
            range::search(lst, sub, [](int a, int b) {
                return a % 2 == b % 2;
            })
            == std::next(lst.begin(), 1)
        );
    }
}

TEST_CASE("range::search_n")
{
    SECTION("basic test") {
        std::forward_list<int> lst {9, 4, 8, 2, 2, 6, 5, 1};
        REQUIRE(range::search_n(lst, 2, 2) == std::next(lst.begin(), 3));
    }
}

TEST_CASE("range::search_n (predicate)")
{
    SECTION("basic test") {
        std::forward_list<int> lst {9, 4, 8, 2, 2, 6, 5, 1};
        std::forward_list<int> sub {2, 2};
        REQUIRE(
            range::search_n(lst, 2, 2, [](int a, int b) {
                return a % 2 == b % 2;
            })
            == std::next(lst.begin(), 1)
        );
    }
}
