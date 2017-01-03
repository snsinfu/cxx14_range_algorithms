/*
 * Test for binary search algorithms.
 *
 * Distributed under the Boost Software License, Version 1.0. (See accompanying
 * file LICENSE.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#include <forward_list>
#include <iterator>

#include <catch.hpp>
#include <range.hpp>


TEST_CASE("range::lower_bound")
{
    SECTION("basic test") {
        std::forward_list<int> lst {1, 2, 2, 4, 5, 6, 8, 9};
        REQUIRE(range::lower_bound(lst, 3) == std::next(lst.begin(), 3));
    }
}

TEST_CASE("range::lower_bound (comparator)")
{
    SECTION("basic test") {
        std::forward_list<int> lst {9, 8, 6, 5, 4, 2, 2, 1};
        REQUIRE(
            range::lower_bound(lst, 4, [](int a, int b) {
                return a > b;
            })
            == std::next(lst.begin(), 4)
        );
    }
}

TEST_CASE("range::upper_bound")
{
    SECTION("basic test") {
        std::forward_list<int> lst {1, 2, 2, 4, 5, 6, 8, 9};
        REQUIRE(range::upper_bound(lst, 4) == std::next(lst.begin(), 4));
    }
}

TEST_CASE("range::upper_bound (comparator)")
{
    SECTION("basic test") {
        std::forward_list<int> lst {9, 8, 6, 5, 4, 2, 2, 1};
        REQUIRE(
            range::upper_bound(lst, 4, [](int a, int b) {
                return a > b;
            })
            == std::next(lst.begin(), 5)
        );
    }
}

TEST_CASE("range::equal_range")
{
    SECTION("basic test") {
        std::forward_list<int> lst {1, 2, 2, 4, 5, 6, 8, 9};
        auto r = range::equal_range(lst, 2);
        REQUIRE(r.begin() == std::next(lst.begin(), 1));
        REQUIRE(r.end() == std::next(lst.begin(), 3));
    }
}

TEST_CASE("range::equal_range (comparator)")
{
    SECTION("basic test") {
        std::forward_list<int> lst {9, 4, 7, 2, 2, 6, 5};
        //                          4, 4, 2, 2, 2, 1, 0  (mod 5)
        auto r = range::equal_range(lst, 2, [](int a, int b) {
            return a % 5 > b % 5;
        });
        REQUIRE(r.begin() == std::next(lst.begin(), 2));
        REQUIRE(r.end() == std::next(lst.begin(), 5));
    }
}

TEST_CASE("range::binary_search")
{
    SECTION("basic test") {
        std::forward_list<int> lst {1, 2, 2, 4, 5, 6, 8, 9};
        REQUIRE( range::binary_search(lst, 2));
        REQUIRE(!range::binary_search(lst, 3));
    }
}

TEST_CASE("range::binary_search (comparator)")
{
    SECTION("basic test") {
        std::forward_list<int> lst {9, 8, 6, 5, 4, 2, 2, 1};
        auto comp = [](int a, int b) { return a > b; };
        REQUIRE( range::binary_search(lst, 2, comp));
        REQUIRE(!range::binary_search(lst, 3, comp));
    }
}
