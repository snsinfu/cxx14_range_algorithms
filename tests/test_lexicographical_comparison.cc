/*
 * Test for lexicographical comparison algorithms.
 *
 * Distributed under the Boost Software License, Version 1.0. (See accompanying
 * file LICENSE.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#include <forward_list>
#include <functional>

#include <catch.hpp>
#include <range.hpp>


TEST_CASE("range::lexicographical_compare")
{
    SECTION("basic test") {
        std::forward_list<int> lst1 {1, 2, 5};
        std::forward_list<int> lst2 {1, 3, 5};
        REQUIRE(range::lexicographical_compare(lst1, lst2));
    }
}

TEST_CASE("range::lexicographical_compare (comparator)")
{
    SECTION("basic test") {
        std::forward_list<int> lst1 {1, 2, 5};
        std::forward_list<int> lst2 {1, 3, 5};
        REQUIRE(!range::lexicographical_compare(lst1, lst2, std::greater<>{}));
    }
}
