/*
 * Test for generalized numeric operation algorithms.
 *
 * Distributed under the Boost Software License, Version 1.0. (See accompanying
 * file LICENSE.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#include <functional>
#include <vector>

#include <catch.hpp>
#include <range.hpp>


TEST_CASE("range::accumulate")
{
    SECTION("basic test") {
        std::vector<int> vec {1, 2, 3, 4, 5};
        REQUIRE(range::accumulate(vec, 0) == (1 + 2 + 3 + 4 + 5));
    }
}

TEST_CASE("range::accumulate (binary op)")
{
    SECTION("basic test") {
        std::vector<int> vec {1, 2, 3, 4, 5};
        REQUIRE(range::accumulate(vec, -1, std::multiplies<>{})
                == (-1 * 1 * 2 * 3 * 4 * 5));
    }
}

TEST_CASE("range::inner_product")
{
    SECTION("basic test") {
        std::vector<int> vec1 {2, 3, 11};
        std::vector<int> vec2 {13, 7, 5};
        REQUIRE(range::inner_product(vec1, vec2, 0)
                == (2 * 13 + 3 * 7 + 11 * 5));
    }
}

TEST_CASE("range::inner_product (binary ops)")
{
    SECTION("basic test") {
        std::vector<int> vec1 {1, 0, 1};
        std::vector<int> vec2 {0, 1, 1};
        REQUIRE(range::inner_product(vec1, vec2, 0,
                                     std::bit_xor<>{}, std::bit_and<>{})
                == (0 ^ (1 & 0) ^ (0 & 1) ^ (1 & 1)));
    }
}

TEST_CASE("range::partial_sum")
{
    SECTION("basic test") {
        std::vector<int> src {1, 2, 3};
        std::vector<int> dst {0, 0, 0};
        REQUIRE(range::partial_sum(src, dst.begin()) == dst.begin() + 3);
        REQUIRE(dst == (std::vector<int> {1, 3, 6}));
    }
}

TEST_CASE("range::partial_sum (binary op)")
{
    SECTION("basic test") {
        std::vector<int> src {1, 2, 3};
        std::vector<int> dst {0, 0, 0};
        REQUIRE(range::partial_sum(src, dst.begin(), std::multiplies<>{})
                == dst.begin() + 3);
        REQUIRE(dst == (std::vector<int> {1, 2, 6}));
    }
}

TEST_CASE("range::adjacent_difference")
{
    SECTION("basic test") {
        std::vector<int> src {1, 3, 6};
        std::vector<int> dst {0, 0, 0};
        REQUIRE(range::adjacent_difference(src, dst.begin())
                == dst.begin() + 3);
        REQUIRE(dst == (std::vector<int> {1, 2, 3}));
    }
}

TEST_CASE("range::adjacent_difference (binary op)")
{
    SECTION("basic test") {
        std::vector<int> src {1, 3, 6};
        std::vector<int> dst {0, 0, 0};
        REQUIRE(range::adjacent_difference(src, dst.begin(), std::divides<>{})
                == dst.begin() + 3);
        REQUIRE(dst == (std::vector<int> {1, 3, 2}));
    }
}

TEST_CASE("range::iota")
{
    SECTION("basic test") {
        std::vector<int> vec {0, 0, 0, 0, 0};
        range::iota(vec, 3);
        REQUIRE(vec == (std::vector<int> {3, 4, 5, 6, 7}));
    }
}
