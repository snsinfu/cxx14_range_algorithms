/*
 * Test for heap operation algorithms.
 *
 * Distributed under the Boost Software License, Version 1.0. (See accompanying
 * file LICENSE.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#include <functional>
#include <vector>

#include <catch.hpp>
#include <range.hpp>


TEST_CASE("range::push_heap")
{
    SECTION("basic test") {
        std::vector<int> vec {3, 1, 2};
        vec.push_back(4);
        range::push_heap(vec);
        REQUIRE(vec.front() == 4);
        REQUIRE(vec.back() == 1);
    }
}

TEST_CASE("range::push_heap (comparator)")
{
    SECTION("basic test") {
        std::vector<int> vec {1, 3, 2};
        vec.push_back(4);
        range::push_heap(vec, std::greater<>{});
        REQUIRE(vec.front() == 1);
        REQUIRE(vec.back() == 4);
    }
}

TEST_CASE("range::pop_heap")
{
    SECTION("basic test") {
        std::vector<int> vec {4, 3, 2, 1};
        range::pop_heap(vec);
        REQUIRE(vec.back() == 4);
        vec.pop_back();
        REQUIRE(vec.front() == 3);
    }
}

TEST_CASE("range::pop_heap (comparator)")
{
    SECTION("basic test") {
        std::vector<int> vec {1, 3, 2, 4};
        range::pop_heap(vec, std::greater<>{});
        REQUIRE(vec.back() == 1);
        vec.pop_back();
        REQUIRE(vec.front() == 2);
    }
}

TEST_CASE("range::make_heap")
{
    SECTION("basic test") {
        std::vector<int> vec {1, 2, 3, 4};
        range::make_heap(vec);
        REQUIRE(vec.front() == 4);
        REQUIRE(vec.back() == 1);
    }
}

TEST_CASE("range::make_heap (comparator)")
{
    SECTION("basic test") {
        std::vector<int> vec {4, 3, 2, 1};
        range::make_heap(vec, std::greater<>{});
        REQUIRE(vec.front() == 1);
        REQUIRE(vec.back() == 4);
    }
}

TEST_CASE("range::sort_heap")
{
    SECTION("basic test") {
        std::vector<int> vec {4, 3, 2, 1};
        range::make_heap(vec);
        range::sort_heap(vec);
        REQUIRE(vec == (std::vector<int> {1, 2, 3, 4}));
    }
}

TEST_CASE("range::sort_heap (comparator)")
{
    SECTION("basic test") {
        std::vector<int> vec {1, 2, 3, 4};
        range::make_heap(vec, std::greater<>{});
        range::sort_heap(vec, std::greater<>{});
        REQUIRE(vec == (std::vector<int> {4, 3, 2, 1}));
    }
}

TEST_CASE("range::is_heap")
{
    SECTION("basic test") {
        std::vector<int> vec1 {4, 3, 2, 1};
        std::vector<int> vec2 {4, 2, 3, 1};
        std::vector<int> vec3 {4, 1, 2, 3};
        REQUIRE( range::is_heap(vec1));
        REQUIRE( range::is_heap(vec2));
        REQUIRE(!range::is_heap(vec3));
    }
}

TEST_CASE("range::is_heap (comparator)")
{
    SECTION("basic test") {
        std::vector<int> vec1 {1, 2, 3, 4};
        std::vector<int> vec2 {1, 3, 2, 4};
        std::vector<int> vec3 {1, 4, 2, 3};
        REQUIRE( range::is_heap(vec1, std::greater<>{}));
        REQUIRE( range::is_heap(vec2, std::greater<>{}));
        REQUIRE(!range::is_heap(vec3, std::greater<>{}));
    }
}

TEST_CASE("range::is_heap_until")
{
    SECTION("basic test") {
        std::vector<int> vec {7, 6, 5, 4, 5, 6, 7};
        REQUIRE(range::is_heap_until(vec) == vec.begin() + 5);
    }
}

TEST_CASE("range::is_heap_until (comparator)")
{
    SECTION("basic test") {
        std::vector<int> vec {1, 2, 3, 4, 3, 2, 1};
        REQUIRE(range::is_heap_until(vec, std::greater<>{})
                == vec.begin() + 5);
    }
}
