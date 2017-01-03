/*
 * Test for minimum and maximum algorithms.
 *
 * Distributed under the Boost Software License, Version 1.0. (See accompanying
 * file LICENSE.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#include <forward_list>
#include <functional>
#include <iterator>
#include <utility>

#include <catch.hpp>
#include <range.hpp>


TEST_CASE("range::min_element")
{
    SECTION("basic test") {
        std::forward_list<int> lst {6, 5, 1, 9, 4, 8, 2, 2};
        REQUIRE(range::min_element(lst) == std::next(lst.begin(), 2));
    }
}

TEST_CASE("range::min_element (comparator)")
{
    SECTION("basic test") {
        std::forward_list<int> lst {6, 5, 1, 9, 4, 8, 2, 2};
        REQUIRE(range::min_element(lst, std::greater<>{})
                == std::next(lst.begin(), 3));
    }
}

TEST_CASE("range::max_element")
{
    SECTION("basic test") {
        std::forward_list<int> lst {6, 5, 1, 9, 4, 8, 2, 2};
        REQUIRE(range::max_element(lst) == std::next(lst.begin(), 3));
    }
}

TEST_CASE("range::max_element (comparator)")
{
    SECTION("basic test") {
        std::forward_list<int> lst {6, 5, 1, 9, 4, 8, 2, 2};
        REQUIRE(range::max_element(lst, std::greater<>{})
                == std::next(lst.begin(), 2));
    }
}

TEST_CASE("range::minmax_element")
{
    SECTION("basic test") {
        std::forward_list<int> lst {6, 5, 1, 9, 4, 8, 2, 2};
        REQUIRE(range::minmax_element(lst)
                == std::make_pair(std::next(lst.begin(), 2),
                                  std::next(lst.begin(), 3)));
    }
}

TEST_CASE("range::minmax_element (comparator)")
{
    SECTION("basic test") {
        std::forward_list<int> lst {6, 5, 1, 9, 4, 8, 2, 2};
        REQUIRE(range::minmax_element(lst, std::greater<>{})
                == std::make_pair(std::next(lst.begin(), 3),
                                  std::next(lst.begin(), 2)));
    }
}
