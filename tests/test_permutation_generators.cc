/*
 * Test for permutation generation algorithms.
 *
 * Distributed under the Boost Software License, Version 1.0. (See accompanying
 * file LICENSE.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#include <list>

#include <catch.hpp>
#include <range.hpp>


TEST_CASE("range::next_permutation")
{
    SECTION("basic test") {
        std::list<int> lst {1, 2, 3};
        REQUIRE(range::next_permutation(lst));
        REQUIRE(lst == (std::list<int> {1, 3, 2}));
        REQUIRE(range::next_permutation(lst));
        REQUIRE(lst == (std::list<int> {2, 1, 3}));
        REQUIRE(range::next_permutation(lst));
        REQUIRE(lst == (std::list<int> {2, 3, 1}));
        REQUIRE(range::next_permutation(lst));
        REQUIRE(lst == (std::list<int> {3, 1, 2}));
        REQUIRE(range::next_permutation(lst));
        REQUIRE(lst == (std::list<int> {3, 2, 1}));
        REQUIRE(!range::next_permutation(lst));
    }
}

TEST_CASE("range::next_permutation (comparator)")
{
    SECTION("basic test") {
        std::list<int> lst {3, 2, 1};
        std::greater<> comp;
        REQUIRE(range::next_permutation(lst, comp));
        REQUIRE(lst == (std::list<int> {3, 1, 2}));
        REQUIRE(range::next_permutation(lst, comp));
        REQUIRE(lst == (std::list<int> {2, 3, 1}));
        REQUIRE(range::next_permutation(lst, comp));
        REQUIRE(lst == (std::list<int> {2, 1, 3}));
        REQUIRE(range::next_permutation(lst, comp));
        REQUIRE(lst == (std::list<int> {1, 3, 2}));
        REQUIRE(range::next_permutation(lst, comp));
        REQUIRE(lst == (std::list<int> {1, 2, 3}));
        REQUIRE(!range::next_permutation(lst, comp));
    }
}

TEST_CASE("range::prev_permutation")
{
    SECTION("basic test") {
        std::list<int> lst {3, 2, 1};
        REQUIRE(range::prev_permutation(lst));
        REQUIRE(lst == (std::list<int> {3, 1, 2}));
        REQUIRE(range::prev_permutation(lst));
        REQUIRE(lst == (std::list<int> {2, 3, 1}));
        REQUIRE(range::prev_permutation(lst));
        REQUIRE(lst == (std::list<int> {2, 1, 3}));
        REQUIRE(range::prev_permutation(lst));
        REQUIRE(lst == (std::list<int> {1, 3, 2}));
        REQUIRE(range::prev_permutation(lst));
        REQUIRE(lst == (std::list<int> {1, 2, 3}));
        REQUIRE(!range::prev_permutation(lst));
    }
}

TEST_CASE("range::prev_permutation (comparator)")
{
    SECTION("basic test") {
        std::list<int> lst {1, 2, 3};
        std::greater<> comp;
        REQUIRE(range::prev_permutation(lst, comp));
        REQUIRE(lst == (std::list<int> {1, 3, 2}));
        REQUIRE(range::prev_permutation(lst, comp));
        REQUIRE(lst == (std::list<int> {2, 1, 3}));
        REQUIRE(range::prev_permutation(lst, comp));
        REQUIRE(lst == (std::list<int> {2, 3, 1}));
        REQUIRE(range::prev_permutation(lst, comp));
        REQUIRE(lst == (std::list<int> {3, 1, 2}));
        REQUIRE(range::prev_permutation(lst, comp));
        REQUIRE(lst == (std::list<int> {3, 2, 1}));
        REQUIRE(!range::prev_permutation(lst, comp));
    }
}
