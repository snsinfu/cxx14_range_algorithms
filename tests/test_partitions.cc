/*
 * Test for partition algorithms.
 *
 * Distributed under the Boost Software License, Version 1.0. (See accompanying
 * file LICENSE.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#include <array>
#include <iterator>
#include <list>
#include <utility>

#include <catch.hpp>
#include <range.hpp>


TEST_CASE("range::is_partitioned")
{
    SECTION("basic test") {
        std::list<int> lst {9, 4, 8, 2, 2, 6, 5, 1};
        REQUIRE(!range::is_partitioned(lst, [](int a) {
            return a % 2 == 0;
        }));
    }
}

TEST_CASE("range::partition")
{
    SECTION("basic test") {
        std::list<int> lst {9, 4, 8, 2, 2, 6, 5, 1};
        auto pred = [](int a) {
            return a % 2 == 0;
        };
        REQUIRE(range::partition(lst, pred) == std::next(lst.begin(), 5));
        REQUIRE(range::is_partitioned(lst, pred));
    }
}

TEST_CASE("range::stable_partition")
{
    SECTION("basic test") {
        std::list<int> lst {9, 4, 8, 2, 2, 6, 5, 1};
        REQUIRE(
            range::stable_partition(lst, [](int a) {
                return a % 2 == 0;
            })
            == std::next(lst.begin(), 5)
        );
        REQUIRE(lst == (std::list<int> {4, 8, 2, 2, 6, 9, 5, 1}));
    }
}

TEST_CASE("range::partition_copy")
{
    SECTION("basic test") {
        std::list<int> lst {9, 4, 8, 2, 2, 6, 5, 1};
        std::array<int, 10> t {{}};
        std::array<int, 10> f {{}};
        REQUIRE(
            range::partition_copy(lst, t.begin(), f.begin(), [](int a) {
                return a % 2 == 0;
            })
            == std::make_pair(t.begin() + 5, f.begin() + 3)
        );
        REQUIRE(t == (std::array<int, 10> {{4, 8, 2, 2, 6}}));
        REQUIRE(f == (std::array<int, 10> {{9, 5, 1}}));
    }
}

TEST_CASE("range::partition_point")
{
    SECTION("basic test") {
        std::list<int> lst {4, 8, 2, 2, 6, 9, 5, 1};
        REQUIRE(
            range::partition_point(lst, [](int a) {
                return a % 2 == 0;
            })
            == std::next(lst.begin(), 5)
        );
    }
}
