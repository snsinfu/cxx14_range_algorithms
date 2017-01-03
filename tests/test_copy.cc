/*
 * Test for copy algorithms.
 *
 * Distributed under the Boost Software License, Version 1.0. (See accompanying
 * file LICENSE.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#include <forward_list>
#include <list>

#include <catch.hpp>
#include <range.hpp>


TEST_CASE("range::copy")
{
    SECTION("basic test") {
        std::forward_list<int> src {9, 4, 8};
        int dst[4] {};
        REQUIRE(range::copy(src, dst) == dst + 3);
        REQUIRE(dst[0] == 9);
        REQUIRE(dst[1] == 4);
        REQUIRE(dst[2] == 8);
    }
}

TEST_CASE("range::copy_if")
{
    SECTION("basic test") {
        std::forward_list<int> src {9, 4, 8};
        int dst[4] {};
        REQUIRE(
            range::copy_if(src, dst, [](int a) {
                return a % 2 == 0;
            })
            == dst + 2);
        REQUIRE(dst[0] == 4);
        REQUIRE(dst[1] == 8);
    }
}

TEST_CASE("range::copy_n")
{
    SECTION("basic test") {
        std::forward_list<int> src {9, 4, 8};
        int dst[4] {};
        REQUIRE(range::copy_n(src, 2, dst) == dst + 2);
        REQUIRE(dst[0] == 9);
        REQUIRE(dst[1] == 4);
    }
}

TEST_CASE("range::copy_backward")
{
    SECTION("basic test") {
        std::list<int> src {9, 4, 8};
        int dst[4] {};
        REQUIRE(range::copy_backward(src, dst + 4) == dst + 1);
        REQUIRE(dst[1] == 9);
        REQUIRE(dst[2] == 4);
        REQUIRE(dst[3] == 8);
    }
}
