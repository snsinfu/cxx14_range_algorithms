/*
 * Test for shuffle algorithm.
 *
 * Distributed under the Boost Software License, Version 1.0. (See accompanying
 * file LICENSE.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#include <array>
#include <random>

#include <catch.hpp>
#include <range.hpp>


TEST_CASE("range::shuffle")
{
    SECTION("basic test") {
        std::array<int, 8> src {{9, 4, 8, 2, 2, 6, 5, 1}};
        std::array<int, 8> arr = src;
        range::shuffle(arr, std::default_random_engine{});
        REQUIRE(range::is_permutation(arr, src));
    }
}
