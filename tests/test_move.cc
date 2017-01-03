/*
 * Test for move algorithms.
 *
 * Distributed under the Boost Software License, Version 1.0. (See accompanying
 * file LICENSE.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#include <forward_list>
#include <list>
#include <memory>

#include <catch.hpp>
#include <range.hpp>


TEST_CASE("range::move")
{
    SECTION("basic test") {
        std::forward_list<std::unique_ptr<int>> src;
        src.emplace_front(std::make_unique<int>(3));
        src.emplace_front(std::make_unique<int>(2));
        src.emplace_front(std::make_unique<int>(1));
        std::unique_ptr<int> dst[4] {};
        REQUIRE(range::move(src, dst) == dst + 3);
        REQUIRE(*dst[0] == 1);
        REQUIRE(*dst[1] == 2);
        REQUIRE(*dst[2] == 3);
    }
}

TEST_CASE("range::move_backward")
{
    SECTION("basic test") {
        std::list<std::unique_ptr<int>> src;
        src.emplace_back(std::make_unique<int>(1));
        src.emplace_back(std::make_unique<int>(2));
        src.emplace_back(std::make_unique<int>(3));
        std::unique_ptr<int> dst[4] {};
        REQUIRE(range::move_backward(src, dst + 4) == dst + 1);
        REQUIRE(*dst[1] == 1);
        REQUIRE(*dst[2] == 2);
        REQUIRE(*dst[3] == 3);
    }
}
