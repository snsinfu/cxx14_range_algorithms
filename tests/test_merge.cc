/*
 * Test for merge algorithms.
 *
 * Distributed under the Boost Software License, Version 1.0. (See accompanying
 * file LICENSE.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#include <array>
#include <list>
#include <iterator>

#include <catch.hpp>
#include <range.hpp>


TEST_CASE("range::merge")
{
    SECTION("basic test") {
        std::list<int> src1 {1, 4, 5, 9};
        std::list<int> src2 {2, 2, 6, 8};
        std::array<int, 10> dst {{}};
        REQUIRE(range::merge(src1, src2, dst.begin()) == dst.begin() + 8);
        REQUIRE(dst == (std::array<int, 10> {{1, 2, 2, 4, 5, 6, 8, 9}}));
    }
}

TEST_CASE("range::merge (comparator)")
{
    SECTION("basic test") {
        std::list<int> src1 {9, 5, 4, 1};
        std::list<int> src2 {8, 6, 2, 2};
        std::array<int, 10> dst {{}};
        REQUIRE(
            range::merge(src1, src2, dst.begin(), [](int a, int b) {
                return a > b;
            })
            == dst.begin() + 8);
        REQUIRE(dst == (std::array<int, 10> {{9, 8, 6, 5, 4, 2, 2, 1}}));
    }
}

TEST_CASE("range::inplace_merge")
{
    SECTION("basic test") {
        std::list<int> lst {1, 4, 5, 9,
                            2, 2, 6, 8};
        range::inplace_merge(lst, std::next(lst.begin(), 4));
        REQUIRE(lst == (std::list<int> {1, 2, 2, 4, 5, 6, 8, 9}));
    }
}

TEST_CASE("range::inplace_merge (comparator)")
{
    SECTION("basic test") {
        std::list<int> lst {9, 5, 4, 1,
                            8, 6, 2, 2};
        range::inplace_merge(lst, std::next(lst.begin(), 4), [](int a, int b) {
            return a > b;
        });
        REQUIRE(lst == (std::list<int> {9, 8, 6, 5, 4, 2, 2, 1}));
    }
}
