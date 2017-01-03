/*
 * Test for remove algorithms.
 *
 * Distributed under the Boost Software License, Version 1.0. (See accompanying
 * file LICENSE.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#include <array>
#include <list>

#include <catch.hpp>
#include <range.hpp>


TEST_CASE("range::remove")
{
    SECTION("basic test") {
        std::list<int> lst {9, 4, 8, 2, 2, 6, 5, 1};
        lst.erase(range::remove(lst, 2), lst.end());
        REQUIRE(lst == (std::list<int> {9, 4, 8, 6, 5, 1}));
    }
}

TEST_CASE("range::remove_if")
{
    SECTION("basic test") {
        std::list<int> lst {9, 4, 8, 2, 2, 6, 5, 1};
        lst.erase(
            range::remove_if(lst, [](int a) {
                return a % 2 == 0;
            }),
            lst.end()
        );
        REQUIRE(lst == (std::list<int> {9, 5, 1}));
    }
}

TEST_CASE("range::remove_copy")
{
    SECTION("basic test") {
        std::list<int> lst {9, 4, 8, 2, 2, 6, 5, 1};
        std::array<int, 10> dst {{}};
        REQUIRE(range::remove_copy(lst, dst.begin(), 2) == dst.begin() + 6);
        REQUIRE(dst == (std::array<int, 10> {{9, 4, 8, 6, 5, 1}}));
    }
}

TEST_CASE("range::remove_copy_if")
{
    SECTION("basic test") {
        std::list<int> lst {9, 4, 8, 2, 2, 6, 5, 1};
        std::array<int, 10> dst {{}};
        REQUIRE(
            range::remove_copy_if(lst, dst.begin(), [](int a) {
                return a % 2 == 0;
            })
            == dst.begin() + 3
        );
        REQUIRE(dst == (std::array<int, 10> {{9, 5, 1}}));
    }
}
