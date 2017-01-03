/*
 * Test for swap algorithm.
 *
 * Distributed under the Boost Software License, Version 1.0. (See accompanying
 * file LICENSE.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#include <vector>

#include <catch.hpp>
#include <range.hpp>


TEST_CASE("range::swap_ranges")
{
    SECTION("basic test") {
        std::vector<int> vec1 {1, 2, 3};
        std::vector<int> vec2 {4, 5, 6, 0, 0};
        REQUIRE(range::swap_ranges(vec1, vec2) == vec2.begin() + 3);
        REQUIRE(vec1 == (std::vector<int> {4, 5, 6}));
        REQUIRE(vec2 == (std::vector<int> {1, 2, 3, 0, 0}));
    }
}
