/*
 * Test for set operation algorithms.
 *
 * Distributed under the Boost Software License, Version 1.0. (See accompanying
 * file LICENSE.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#include <array>
#include <list>

#include <catch.hpp>
#include <range.hpp>


TEST_CASE("range::includes")
{
    SECTION("basic test") {
        std::list<int> lst {1, 2, 2, 4, 5, 6, 8, 9};
        std::list<int> sub {2, 5, 9};
        REQUIRE(range::includes(lst, sub));
    }
}

TEST_CASE("range::includes (comparator)")
{
    SECTION("basic test") {
        std::list<int> lst {9, 8, 6, 5, 4, 2, 2, 1};
        std::list<int> sub {9, 5, 2};
        REQUIRE(range::includes(lst, sub, [](int a, int b) {
            return a > b;
        }));
    }
}

TEST_CASE("range::set_union")
{
    SECTION("basic test") {
        std::list<int> src1 {1, 2, 5, 6, 6};
        std::list<int> src2 {2, 3, 5, 7};
        std::array<int, 12> dst {{}};
        REQUIRE(range::set_union(src1, src2, dst.begin()) == dst.begin() + 7);
        REQUIRE(dst == (std::array<int, 12> {{1, 2, 3, 5, 6, 6, 7}}));
    }
}

TEST_CASE("range::set_union (comparator)")
{
    SECTION("basic test") {
        std::list<int> src1 {6, 6, 5, 2, 1};
        std::list<int> src2 {7, 5, 3, 2};
        std::array<int, 12> dst {{}};
        REQUIRE(
            range::set_union(src1, src2, dst.begin(), [](int a, int b) {
                return a > b;
            })
            == dst.begin() + 7);
        REQUIRE(dst == (std::array<int, 12> {{7, 6, 6, 5, 3, 2, 1}}));
    }
}

TEST_CASE("range::set_intersection")
{
    SECTION("basic test") {
        std::list<int> src1 {1, 2, 5, 6, 6};
        std::list<int> src2 {2, 3, 5, 7};
        std::array<int, 12> dst {{}};
        REQUIRE(range::set_intersection(src1, src2, dst.begin())
                == dst.begin() + 2);
        REQUIRE(dst == (std::array<int, 12> {{2, 5}}));
    }
}

TEST_CASE("range::set_intersection (comparator)")
{
    SECTION("basic test") {
        std::list<int> src1 {6, 6, 5, 2, 1};
        std::list<int> src2 {7, 5, 3, 2};
        std::array<int, 12> dst {{}};
        REQUIRE(
            range::set_intersection(src1, src2, dst.begin(), [](int a, int b) {
                return a > b;
            })
            == dst.begin() + 2);
        REQUIRE(dst == (std::array<int, 12> {{5, 2}}));
    }
}

TEST_CASE("range::set_difference")
{
    SECTION("basic test") {
        std::list<int> src1 {1, 2, 5, 6, 6};
        std::list<int> src2 {2, 3, 5, 7};
        std::array<int, 12> dst {{}};
        REQUIRE(range::set_difference(src1, src2, dst.begin())
                == dst.begin() + 3);
        REQUIRE(dst == (std::array<int, 12> {{1, 6, 6}}));
    }
}

TEST_CASE("range::set_difference (comparator)")
{
    SECTION("basic test") {
        std::list<int> src1 {6, 6, 5, 2, 1};
        std::list<int> src2 {7, 5, 3, 2};
        std::array<int, 12> dst {{}};
        REQUIRE(
            range::set_difference(src1, src2, dst.begin(), [](int a, int b) {
                return a > b;
            })
            == dst.begin() + 3);
        REQUIRE(dst == (std::array<int, 12> {{6, 6, 1}}));
    }
}

TEST_CASE("range::set_symmetric_difference")
{
    SECTION("basic test") {
        std::list<int> src1 {1, 2, 5, 6, 6};
        std::list<int> src2 {2, 3, 5, 7};
        std::array<int, 12> dst {{}};
        REQUIRE(range::set_symmetric_difference(src1, src2, dst.begin())
                == dst.begin() + 5);
        REQUIRE(dst == (std::array<int, 12> {{1, 3, 6, 6, 7}}));
    }
}

TEST_CASE("range::set_symmetric_difference (comparator)")
{
    SECTION("basic test") {
        std::list<int> src1 {6, 6, 5, 2, 1};
        std::list<int> src2 {7, 5, 3, 2};
        std::array<int, 12> dst {{}};
        REQUIRE(
            range::set_symmetric_difference(
                src1, src2, dst.begin(), [](int a, int b) {
                    return a > b;
                }
            )
            == dst.begin() + 5);
        REQUIRE(dst == (std::array<int, 12> {{7, 6, 6, 3, 1}}));
    }
}
