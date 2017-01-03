# range.hpp

| Language | License                    |
|----------|----------------------------|
| C++14    | Boost Software License 1.0 |

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
in [algorithm](1) and [numeric](2) headers except for `random_shuffle` are
provided.

[1]: http://en.cppreference.com/w/cpp/header/algorithm
[2]: http://en.cppreference.com/w/cpp/header/numeric

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
