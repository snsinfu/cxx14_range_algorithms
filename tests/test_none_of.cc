/*
 * Test for none_of algorithm.
 *
 * Distributed under the Boost Software License, Version 1.0. (See accompanying
 * file LICENSE.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#include <forward_list>

#include <catch.hpp>
#include <range.hpp>


TEST_CASE("range::none_of")
{
    SECTION("basic test") {
        std::forward_list<int> lst {9, 4, 8, 2, 2, 6, 5, 1};
        REQUIRE( range::none_of(lst, [](int v) { return v < 0; }));
        REQUIRE(!range::none_of(lst, [](int v) { return v > 8; }));
    }
}
