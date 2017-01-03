/*
 * Test for transform algorithms.
 *
 * Distributed under the Boost Software License, Version 1.0. (See accompanying
 * file LICENSE.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#include <catch.hpp>
#include <range.hpp>


TEST_CASE("range::transform (unary)")
{
    SECTION("basic test") {
        int src[3] {1, 2, 3};
        int dst[5] {};
        REQUIRE(
            range::transform(src, dst, [](int a) {
                return a * 2;
            })
            == dst + 3
        );
        REQUIRE(dst[0] == 2);
        REQUIRE(dst[1] == 4);
        REQUIRE(dst[2] == 6);
    }
}

TEST_CASE("range::transform (binary)")
{
    SECTION("basic test") {
        int src1[3] {1, 2, 3};
        int src2[3] {3, 4, 2};
        int dst[5] {};
        REQUIRE(
            range::transform(src1, src2, dst, [](int a, int b) {
                return a * b;
            })
            == dst + 3
        );
        REQUIRE(dst[0] == 1 * 3);
        REQUIRE(dst[1] == 2 * 4);
        REQUIRE(dst[2] == 3 * 2);
    }
}
