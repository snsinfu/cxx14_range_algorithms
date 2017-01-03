/*
 * Test for generate algorithms.
 *
 * Distributed under the Boost Software License, Version 1.0. (See accompanying
 * file LICENSE.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#include <forward_list>
#include <iterator>

#include <catch.hpp>
#include <range.hpp>


TEST_CASE("range::generate")
{
    SECTION("basic test") {
        std::forward_list<int> lst {9, 4, 8, 2, 2, 6, 5, 1};
        range::generate(lst, [c = 0]() mutable {
            return c++;
        });
        REQUIRE(lst == (std::forward_list<int> {0, 1, 2, 3, 4, 5, 6, 7}));
    }
}

TEST_CASE("range::generate_n")
{
    SECTION("basic test") {
        std::forward_list<int> lst {9, 4, 8, 2, 2, 6, 5, 1};
        REQUIRE(
            range::generate_n(lst.begin(), 4, [c = 0]() mutable {
                return c++;
            })
            == std::next(lst.begin(), 4)
        );
        REQUIRE(lst == (std::forward_list<int> {0, 1, 2, 3, 2, 6, 5, 1}));
    }
}
