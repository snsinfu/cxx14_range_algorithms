/*
 * Test for count algorithms.
 *
 * Distributed under the Boost Software License, Version 1.0. (See accompanying
 * file LICENSE.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#include <forward_list>
#include <iterator>

#include <catch.hpp>
#include <range.hpp>


TEST_CASE("range::count")
{
    SECTION("basic test") {
        std::forward_list<int> lst {9, 4, 8, 2, 2, 6, 5, 1};
        REQUIRE(range::count(lst, 2) == 2);
    }
}

TEST_CASE("range::count_if")
{
    SECTION("basic test") {
        std::forward_list<int> lst {9, 4, 8, 2, 2, 6, 5, 1};
        REQUIRE(
            range::count_if(lst, [](int a) {
                return a % 2 == 0;
            })
            == 5
        );
    }
}
