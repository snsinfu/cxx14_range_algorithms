/*
 * Test for unique algorithms.
 *
 * Distributed under the Boost Software License, Version 1.0. (See accompanying
 * file LICENSE.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#include <array>
#include <list>

#include <catch.hpp>
#include <range.hpp>


TEST_CASE("range::unique")
{
    SECTION("basic test") {
        std::list<int> lst {9, 4, 8, 2, 2, 6, 5, 1};
        lst.erase(range::unique(lst), lst.end());
        REQUIRE(lst == (std::list<int> {9, 4, 8, 2, 6, 5, 1}));
    }
}

TEST_CASE("range::unique (predicate)")
{
    SECTION("basic test") {
        std::list<int> lst {9, 4, 8, 2, 2, 6, 5, 1};
        lst.erase(
            range::unique(lst, [](int a, int b) {
                return a % 2 == b % 2;
            }),
            lst.end()
        );
        REQUIRE(lst == (std::list<int> {9, 4, 5}));
    }
}

TEST_CASE("range::unique_copy")
{
    SECTION("basic test") {
        std::list<int> lst {9, 4, 8, 2, 2, 6, 5, 1};
        std::array<int, 10> dst {{}};
        REQUIRE(range::unique_copy(lst, dst.begin()) == dst.begin() + 7);
        REQUIRE(dst == (std::array<int, 10> {{9, 4, 8, 2, 6, 5, 1}}));
    }
}

TEST_CASE("range::unique_copy (predicate)")
{
    SECTION("basic test") {
        std::list<int> lst {9, 4, 8, 2, 2, 6, 5, 1};
        std::array<int, 10> dst {{}};
        REQUIRE(
            range::unique_copy(lst, dst.begin(), [](int a, int b) {
                return a % 2 == b % 2;
            })
            == dst.begin() + 3
        );
        REQUIRE(dst == (std::array<int, 10> {{9, 4, 5}}));
    }
}
