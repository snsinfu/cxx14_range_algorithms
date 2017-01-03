/*
 * Test for fill algorithms.
 *
 * Distributed under the Boost Software License, Version 1.0. (See accompanying
 * file LICENSE.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#include <forward_list>

#include <catch.hpp>
#include <range.hpp>


TEST_CASE("range::fill")
{
    SECTION("basic test") {
        std::forward_list<int> lst {9, 4, 8, 2, 2, 6, 5, 1};
        range::fill(lst, 0);
        REQUIRE(lst == (std::forward_list<int> {0, 0, 0, 0, 0, 0, 0, 0}));
    }
}

TEST_CASE("range::fill_n")
{
    SECTION("basic test") {
        std::forward_list<int> lst {9, 4, 8, 2, 2, 6, 5, 1};
        range::fill_n(lst.begin(), 4, 0);
        REQUIRE(lst == (std::forward_list<int> {0, 0, 0, 0, 2, 6, 5, 1}));
    }
}
