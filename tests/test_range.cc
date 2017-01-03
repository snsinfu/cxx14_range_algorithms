/*
 * Test for the range::range class template.
 *
 * Distributed under the Boost Software License, Version 1.0. (See accompanying
 * file LICENSE.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#include <forward_list>
#include <iterator>
#include <list>
#include <sstream>
#include <vector>

#include <catch.hpp>
#include <range.hpp>


TEST_CASE("range::range - construction")
{
    SECTION("from array") {
        int arr[] {9, 4, 8, 2, 2, 6, 5, 1};
        auto r = range::make(arr);
        REQUIRE(typeid(r) == typeid(range::range<int*>));
    }

    SECTION("from vector") {
        std::vector<int> vec;
        auto r = range::make(vec);
        REQUIRE(typeid(r) == typeid(range::range<std::vector<int>::iterator>));
    }

    SECTION("from list") {
        std::list<int> lst;
        auto r = range::make(lst);
        REQUIRE(typeid(r) == typeid(range::range<std::list<int>::iterator>));
    }

    SECTION("from iterators") {
        std::vector<int> vec {9, 4, 8, 2, 2, 6, 5, 1};
        auto r = range::make(vec.begin() + 2, vec.end() - 2);
        REQUIRE(typeid(r) == typeid(range::range<std::vector<int>::iterator>));
    }
}

TEST_CASE("range::range - begin/end")
{
    SECTION("non-empty vector") {
        std::vector<int> vec {9, 4, 8, 2, 2, 6, 5, 1};
        auto r = range::make(vec);
        REQUIRE(r.begin() == vec.begin());
        REQUIRE(r.end() == vec.end());
    }

    SECTION("empty vector") {
        std::vector<int> vec;
        auto r = range::make(vec);
        REQUIRE(r.begin() == vec.begin());
        REQUIRE(r.end() == vec.end());
    }

    SECTION("range-based for") {
        std::vector<int> vec {9, 4, 8, 2, 2, 6, 5, 1};
        auto r = range::make(vec);
        for (int& e : r) {
            --e;
        }
        REQUIRE(vec == (std::vector<int> {8, 3, 7, 1, 1, 5, 4, 0}));
    }

    SECTION("free-function begin/end") {
        std::vector<int> vec {9, 4, 8, 2, 2, 6, 5, 1};
        auto r = range::make(vec);
        REQUIRE(begin(r) == r.begin());
        REQUIRE(end(r) == r.end());
    }
}

TEST_CASE("range::range - empty")
{
    SECTION("positive test") {
        std::vector<int> vec;
        REQUIRE(range::make(vec).empty());
    }

    SECTION("negative test") {
        std::vector<int> vec {9, 4, 8, 2, 2, 6, 5, 1};
        REQUIRE(!range::make(vec).empty());
    }
}

TEST_CASE("range::range - size")
{
    SECTION("zero") {
        std::vector<int> vec;
        REQUIRE(range::make(vec).size() == 0);
    }

    SECTION("non-zero") {
        std::vector<int> vec {9, 4, 8, 2, 2, 6, 5, 1};
        REQUIRE(range::make(vec).size() == 8);
    }
}

TEST_CASE("range::range - prefix")
{
    SECTION("empty prefix") {
        std::vector<int> vec {9, 4, 8, 2, 2, 6, 5, 1};
        auto r = range::make(vec);
        auto p = r.prefix(0);
        REQUIRE(p.empty());
        REQUIRE(p.begin() == vec.begin());
    }

    SECTION("RandomAccessRange") {
        std::vector<int> vec {9, 4, 8, 2, 2, 6, 5, 1};
        auto r = range::make(vec);
        auto p = r.prefix(3);
        REQUIRE(p.size() == 3);
        REQUIRE(p.begin() == vec.begin());
        REQUIRE(p.end() == vec.begin() + 3);
    }

    SECTION("ForwardRange") {
        std::forward_list<int> lst {9, 4, 8, 2, 2, 6, 5, 1};
        auto r = range::make(lst);
        auto p = r.prefix(3);
        REQUIRE(p.size() == 3);
        REQUIRE(p.begin() == lst.begin());
        REQUIRE(p.end() == std::next(lst.begin(), 3));
    }
}

TEST_CASE("range::range - suffix")
{
    SECTION("empty suffix") {
        std::vector<int> vec {9, 4, 8, 2, 2, 6, 5, 1};
        auto r = range::make(vec);
        auto p = r.suffix(0);
        REQUIRE(p.empty());
        REQUIRE(p.begin() == vec.end());
    }

    SECTION("RandomAccessRange") {
        std::vector<int> vec {9, 4, 8, 2, 2, 6, 5, 1};
        auto r = range::make(vec);
        auto p = r.suffix(3);
        REQUIRE(p.size() == 3);
        REQUIRE(p.begin() == vec.end() - 3);
        REQUIRE(p.end() == vec.end());
    }

    SECTION("BidirectionalRange") {
        std::list<int> lst {9, 4, 8, 2, 2, 6, 5, 1};
        auto r = range::make(lst);
        auto p = r.suffix(3);
        REQUIRE(p.size() == 3);
        REQUIRE(p.begin() == std::prev(lst.end(), 3));
        REQUIRE(p.end() == lst.end());
    }
}

TEST_CASE("range::range - subrange(*)")
{
    SECTION("empty subrange") {
        std::vector<int> vec {9, 4, 8, 2, 2, 6, 5, 1};
        auto r = range::make(vec);
        auto p = r.subrange(8);
        REQUIRE(p.empty());
        REQUIRE(p.begin() == vec.end());
    }

    SECTION("RandomAccessRange") {
        std::vector<int> vec {9, 4, 8, 2, 2, 6, 5, 1};
        auto r = range::make(vec);
        auto p = r.subrange(3);
        REQUIRE(p.size() == 5);
        REQUIRE(p.begin() == vec.begin() + 3);
        REQUIRE(p.end() == vec.end());
    }

    SECTION("ForwardRange") {
        std::forward_list<int> lst {9, 4, 8, 2, 2, 6, 5, 1};
        auto r = range::make(lst);
        auto p = r.subrange(3);
        REQUIRE(p.size() == 5);
        REQUIRE(p.begin() == std::next(lst.begin(), 3));
        REQUIRE(p.end() == lst.end());
    }
}

TEST_CASE("range::range - subrange(*, *)")
{
    SECTION("empty subrange") {
        std::vector<int> vec {9, 4, 8, 2, 2, 6, 5, 1};
        auto r = range::make(vec);
        auto p = r.subrange(3, 0);
        REQUIRE(p.empty());
        REQUIRE(p.begin() == vec.begin() + 3);
    }

    SECTION("RandomAccessRange") {
        std::vector<int> vec {9, 4, 8, 2, 2, 6, 5, 1};
        auto r = range::make(vec);
        auto p = r.subrange(3, 4);
        REQUIRE(p.size() == 4);
        REQUIRE(p.begin() == vec.begin() + 3);
        REQUIRE(p.end() == vec.begin() + 7);
    }

    SECTION("ForwardRange") {
        std::forward_list<int> lst {9, 4, 8, 2, 2, 6, 5, 1};
        auto r = range::make(lst);
        auto p = r.subrange(3, 4);
        REQUIRE(p.size() == 4);
        REQUIRE(p.begin() == std::next(lst.begin(), 3));
        REQUIRE(p.end() == std::next(lst.begin(), 7));
    }
}

TEST_CASE("range::range - remove_prefix")
{
    SECTION("method chaining") {
        std::vector<int> vec {9, 4, 8, 2, 2, 6, 5, 1};
        auto r = range::make(vec);
        auto s = r.remove_prefix(3)
                  .remove_prefix(2)
                  .remove_prefix(1);
        REQUIRE(r.begin() == s.begin());
        REQUIRE(r.end() == s.end());
    }

    SECTION("exhausting") {
        std::vector<int> vec {9, 4, 8, 2, 2, 6, 5, 1};
        auto r = range::make(vec);
        r.remove_prefix(8);
        REQUIRE(r.empty());
        REQUIRE(r.begin() == vec.end());
    }

    SECTION("RandomAccessRange") {
        std::vector<int> vec {9, 4, 8, 2, 2, 6, 5, 1};
        auto r = range::make(vec);
        r.remove_prefix(3);
        REQUIRE(r.size() == 5);
        REQUIRE(r.begin() == vec.begin() + 3);
        REQUIRE(r.end() == vec.end());
    }

    SECTION("ForwardRange") {
        std::forward_list<int> lst {9, 4, 8, 2, 2, 6, 5, 1};
        auto r = range::make(lst);
        r.remove_prefix(3);
        REQUIRE(r.size() == 5);
        REQUIRE(r.begin() == std::next(lst.begin(), 3));
        REQUIRE(r.end() == lst.end());
    }

    SECTION("InputRange") {
        std::istringstream str{"The quick brown fox"};
        auto r = range::make(std::istream_iterator<char>{str >> std::noskipws},
                             std::istream_iterator<char>{});
        REQUIRE(*r.begin() == 'T');
        r.remove_prefix(4);
        REQUIRE(*r.begin() == 'q');
        r.remove_prefix(14);
        REQUIRE(*r.begin() == 'x');
        r.remove_prefix(1);
        REQUIRE(r.empty());
    }
}

TEST_CASE("range::range - remove_suffix")
{
    SECTION("method chaining") {
        std::vector<int> vec {9, 4, 8, 2, 2, 6, 5, 1};
        auto r = range::make(vec);
        auto s = r.remove_suffix(3)
                  .remove_suffix(2)
                  .remove_suffix(1);
        REQUIRE(r.begin() == s.begin());
        REQUIRE(r.end() == s.end());
    }

    SECTION("exhausting") {
        std::vector<int> vec {9, 4, 8, 2, 2, 6, 5, 1};
        auto r = range::make(vec);
        r.remove_suffix(8);
        REQUIRE(r.empty());
        REQUIRE(r.begin() == vec.begin());
    }

    SECTION("RandomAccessRange") {
        std::vector<int> vec {9, 4, 8, 2, 2, 6, 5, 1};
        auto r = range::make(vec);
        r.remove_suffix(3);
        REQUIRE(r.size() == 5);
        REQUIRE(r.begin() == vec.begin());
        REQUIRE(r.end() == vec.end() - 3);
    }

    SECTION("BidirectionalRange") {
        std::list<int> lst {9, 4, 8, 2, 2, 6, 5, 1};
        auto r = range::make(lst);
        r.remove_suffix(3);
        REQUIRE(r.size() == 5);
        REQUIRE(r.begin() == lst.begin());
        REQUIRE(r.end() == std::prev(lst.end(), 3));
    }
}

TEST_CASE("range::range - front")
{
    SECTION("RandomAccessRange") {
        std::vector<int> vec {9, 4, 8, 2, 2, 6, 5, 1};
        auto r = range::make(vec);
        int& e = r.front();
        REQUIRE(&e == &vec.front());
    }
}

TEST_CASE("range::range - back")
{
    SECTION("RandomAccessRange") {
        std::vector<int> vec {9, 4, 8, 2, 2, 6, 5, 1};
        auto r = range::make(vec);
        int& e = r.back();
        REQUIRE(&e == &vec.back());
    }
}

TEST_CASE("range::range - indexing operator")
{
    SECTION("without offset") {
        std::vector<int> vec {9, 4, 8, 2, 2, 6, 5, 1};
        auto r = range::make(vec);
        int& e0 = r[0];
        int& e4 = r[4];
        int& e7 = r[7];
        REQUIRE(&e0 == &vec[0]);
        REQUIRE(&e4 == &vec[4]);
        REQUIRE(&e7 == &vec[7]);
    }

    SECTION("with offset") {
        std::vector<int> vec {9, 4, 8, 2, 2, 6, 5, 1};
        auto r = range::make(vec.begin() + 2, vec.end() - 2);
        int& e0 = r[0];
        int& e3 = r[3];
        REQUIRE(&e0 == &vec[2]);
        REQUIRE(&e3 == &vec[5]);
    }
}
