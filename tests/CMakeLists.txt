# Distributed under the Boost Software License, Version 1.0. (See accompanying
# file LICENSE.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

cmake_minimum_required(VERSION 3.1)

project(cxx14_range_algorithms CXX)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(
    ..
    ./third_party/Catch2
)

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
    set(CMAKE_CXX_FLAGS
        "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Wconversion -Wshadow")
endif()

add_executable(run
    unittest.cc
    test_range.cc
    test_all_of.cc
    test_any_of.cc
    test_none_of.cc
    test_for_each.cc
    test_find.cc
    test_find_end.cc
    test_find_first.cc
    test_adjacent_find.cc
    test_count.cc
    test_mismatch.cc
    test_equal.cc
    test_is_permutation.cc
    test_search.cc
    test_copy.cc
    test_move.cc
    test_swap.cc
    test_transform.cc
    test_replace.cc
    test_fill.cc
    test_generate.cc
    test_remove.cc
    test_unique.cc
    test_reverse.cc
    test_rotate.cc
    test_shuffle.cc
    test_partitions.cc
    test_sorting.cc
    test_nth_element.cc
    test_binary_search.cc
    test_merge.cc
    test_set_operations.cc
    test_heap_operations.cc
    test_minimum_and_maximum.cc
    test_lexicographical_comparison.cc
    test_permutation_generators.cc
    test_generalized_numeric_operations.cc
)

enable_testing()
add_test(unittest run)
