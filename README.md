range.hpp
=========

![C++14][cxx-badge]
[![Boost License][license-badge]](LICENSE.txt)
[![Build Status][travis-badge]][travis-url]

A single-file, header-only library of C++14 standard algorithms adapted to
ranges.

```c++
std::vector<int> numbers {49, 72, 17, 16, 98, 52, 18, 61, 21, 29, 86};
range::sort(numbers);
range::copy(numbers, std::ostream_iterator(std::cout, " "));
```

The purpose of this library is just to enable standard algorithms usable
without annoyance of `begin()` and `end()`. If you need a more comprehensive
range library, use [range-v3](https://github.com/ericniebler/range-v3)
instead.

---

## Install

Copy range.hpp to the include directory of your project.

## Use

Include range.hpp and use algorithms in namespace `range`. Sequence algorithms
in [algorithm](http://en.cppreference.com/w/cpp/header/algorithm) and
[numeric](http://en.cppreference.com/w/cpp/header/numeric) headers except for
`random_shuffle` are provided.

## Test

Move to the tests directory and type following commands to run tests:

    mkdir build
    cd build
    cmake ..
    make
    ctest

Tested compilers are:

- g++ 4.9.4
- clang++ 3.8.0 with libc++

## License

Boost Software License, Version 1.0.

License text is included in the header file. You don't need to copy license
file (LICENSE.txt) into your project if you just use the header file.


[cxx-badge]: https://img.shields.io/badge/C%2B%2B-14-orange.svg
[license-badge]: http://img.shields.io/badge/license-Boost-blue.svg
[travis-badge]: https://travis-ci.org/frickiericker/cxx14_range_algorithms.svg?branch=master
[travis-url]: https://travis-ci.org/frickiericker/cxx14_range_algorithms
