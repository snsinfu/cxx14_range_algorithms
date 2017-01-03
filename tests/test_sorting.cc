/*
 * Test for sorting algorithms.
 *
 * Distributed under the Boost Software License, Version 1.0. (See accompanying
 * file LICENSE.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#include <vector>

#include <catch.hpp>
#include <range.hpp>


TEST_CASE("range::sort")
{
    SECTION("basic test") {
        std::vector<int> vec {9, 4, 8, 2, 2, 6, 5, 1};
        range::sort(vec);
        REQUIRE(vec == (std::vector<int> {1, 2, 2, 4, 5, 6, 8, 9}));
    }
}

TEST_CASE("range::sort (comparator)")
{
    SECTION("basic test") {
        std::vector<int> vec {9, 4, 8, 2, 2, 6, 5, 1};
        range::sort(vec, [](int a, int b) {
            return a > b;
        });
        REQUIRE(vec == (std::vector<int> {9, 8, 6, 5, 4, 2, 2, 1}));
    }
}

TEST_CASE("range::stable_sort")
{
    struct ranked_value
    {
        int rank;
        int value;

        bool operator==(ranked_value const& other) const
        {
            return rank == other.rank;
        }

        bool operator!=(ranked_value const& other) const
        {
            return !(*this == other);
        }

        bool operator<(ranked_value const& other) const
        {
            return rank < other.rank;
        }
    };

    SECTION("basic test") {
        std::vector<ranked_value> vec {
            {3, 1}, {2, 2}, {1, 3}, {2, 4},
            {2, 5}, {3, 6}, {1, 7}, {2, 8}
        };
        range::stable_sort(vec);
        REQUIRE(vec == (std::vector<ranked_value> {
            {1, 3}, {1, 7},
            {2, 2}, {2, 4}, {2, 5}, {2, 8},
            {3, 1}, {3, 6}
        }));
    }
}

TEST_CASE("range::stable_sort (comparator)")
{
    SECTION("basic test") {
        std::vector<int> vec {9, 4, 8, 2, 2, 6, 5, 1};
        //                    4, 4, 3, 2, 2, 1, 0, 1  (mod 5)
        range::sort(vec, [](int a, int b) {
            return a % 5 < b % 5;
        });
        REQUIRE(vec == (std::vector<int> {5, 6, 1, 2, 2, 8, 9, 4}));
    }
}

TEST_CASE("range::partial_sort")
{
    SECTION("basic test") {
        std::vector<int> vec {9, 4, 8, 2, 2, 6, 5, 1};
        range::partial_sort(vec, vec.begin() + 3);
        REQUIRE(vec[0] == 1);
        REQUIRE(vec[1] == 2);
        REQUIRE(vec[2] == 2);
    }
}

TEST_CASE("range::partial_sort (comparator)")
{
    SECTION("basic test") {
        std::vector<int> vec {9, 4, 8, 2, 2, 6, 5, 1};
        range::partial_sort(vec, vec.begin() + 3, [](int a, int b) {
            return a > b;
        });
        REQUIRE(vec[0] == 9);
        REQUIRE(vec[1] == 8);
        REQUIRE(vec[2] == 6);
    }
}

TEST_CASE("range::partial_sort_copy")
{
    SECTION("basic test") {
        std::vector<int> vec {9, 4, 8, 2, 2, 6, 5, 1};
        std::vector<int> dst {0, 0, 0};
        range::partial_sort_copy(vec, dst);
        REQUIRE(dst[0] == 1);
        REQUIRE(dst[1] == 2);
        REQUIRE(dst[2] == 2);
    }
}

TEST_CASE("range::partial_sort_copy (comparator)")
{
    SECTION("basic test") {
        std::vector<int> vec {9, 4, 8, 2, 2, 6, 5, 1};
        std::vector<int> dst {0, 0, 0};
        range::partial_sort_copy(vec, dst, [](int a, int b) {
            return a > b;
        });
        REQUIRE(dst[0] == 9);
        REQUIRE(dst[1] == 8);
        REQUIRE(dst[2] == 6);
    }
}

TEST_CASE("range::is_sorted")
{
    SECTION("basic test") {
        std::vector<int> vec {9, 4, 8, 2, 2, 6, 5, 1};
        REQUIRE(!range::is_sorted(vec));
    }
}

TEST_CASE("range::is_sorted (comparator)")
{
    SECTION("basic test") {
        std::vector<int> vec {9, 4, 8, 2, 2, 6, 5};
        //                    4, 4, 3, 2, 2, 1, 0  (mod 5)
        REQUIRE(range::is_sorted(vec, [](int a, int b) {
            return a % 5 > b % 5;
        }));
    }
}

TEST_CASE("range::is_sorted_until")
{
    SECTION("basic test") {
        std::vector<int> vec {2, 2, 6, 5};
        REQUIRE(range::is_sorted_until(vec) == vec.begin() + 3);
    }
}

TEST_CASE("range::is_sorted_until (comparator)")
{
    SECTION("basic test") {
        std::vector<int> vec {9, 4, 8, 2, 2, 6, 5, 1};
        //                    4, 4, 3, 2, 2, 1, 0, 1  (mod 5)
        REQUIRE(
            range::is_sorted_until(vec, [](int a, int b) {
                return a % 5 > b % 5;
            })
            == vec.end() - 1
        );
    }
}
