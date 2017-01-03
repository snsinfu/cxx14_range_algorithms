/*
 * Test for for_each algorithm.
 *
 * Distributed under the Boost Software License, Version 1.0. (See accompanying
 * file LICENSE.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#include <forward_list>

#include <catch.hpp>
#include <range.hpp>


TEST_CASE("range::for_each")
{
    SECTION("basic test") {
        std::forward_list<int> lst {9, 4, 8, 2, 2, 6, 5, 1};
        auto counter = [c = 0](int) mutable {
            return c++;
        };
        auto result = range::for_each(lst, counter);
        REQUIRE(counter(0) == 0);
        REQUIRE(result(0) == 8);
    }
}
