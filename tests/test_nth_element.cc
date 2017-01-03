/*
 * Test for nth_element algorithms.
 *
 * Distributed under the Boost Software License, Version 1.0. (See accompanying
 * file LICENSE.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#include <vector>

#include <catch.hpp>
#include <range.hpp>


TEST_CASE("range::nth_element")
{
    SECTION("basic test") {
        std::vector<int> vec {9, 4, 8, 2, 2, 6, 5, 1};
        range::nth_element(vec, vec.begin() + 4);
        for (std::vector<int>::size_type i = 0; i < 4; ++i) {
            for (std::vector<int>::size_type j = 4; j < vec.size(); ++j) {
                REQUIRE(vec[i] <= vec[j]);
            }
        }
    }
}

TEST_CASE("range::nth_element (comparator)")
{
    SECTION("basic test") {
        std::vector<int> vec {9, 4, 8, 2, 2, 6, 5, 1};
        range::nth_element(vec, vec.begin() + 4, [](int a, int b) {
            return a > b;
        });
        for (std::vector<int>::size_type i = 0; i < 4; ++i) {
            for (std::vector<int>::size_type j = 4; j < vec.size(); ++j) {
                REQUIRE(vec[i] >= vec[j]);
            }
        }
    }
}
