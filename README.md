range.hpp
=========

![C++14][cxx-badge]
[![Boost License][license-badge]](LICENSE.txt)
[![Build Status][travis-badge]][travis-url]

A single-file, header-only library of C++14 standard algorithms adapted to
ranges. range.hpp aims to be a thin wrapper around the standard algorithms.
If you need a more comprehensive range library, you may want to use
[range-v3](https://github.com/ericniebler/range-v3) instead.

- [Installation](#installation)
- [Usage](#usage)
- [Testing](#testing)
- [License](#license)

[cxx-badge]: https://img.shields.io/badge/C%2B%2B-14-orange.svg
[license-badge]: http://img.shields.io/badge/license-Boost-blue.svg
[travis-badge]: https://travis-ci.org/snsinfu/cxx14_range_algorithms.svg?branch=master
[travis-url]: https://travis-ci.org/snsinfu/cxx14_range_algorithms

## Installation

Copy [range.hpp][range.hpp] to the include directory of your project. Change
file name and/or namespace as you like.

[range.hpp]: https://raw.githubusercontent.com/snsinfu/cxx14_range_algorithms/master/range.hpp

## Usage

Include range.hpp and use algorithms in namespace `range`:

```cpp
#include <iostream>
#include <iterator>
#include <vector>

#include <range.hpp>

int main()
{
    std::vector<int> numbers {49, 72, 17, 16, 98, 52, 18, 61, 21, 29, 86};
    range::sort(numbers);
    range::copy(numbers, std::ostream_iterator(std::cout, " "));
    std::cout << '\n';
}
```

Sequence algorithms in [algorithm][algorithm-ref] and [numeric][numeric-ref]
headers except for `random_shuffle` are provided.

[algorithm-ref]: http://en.cppreference.com/w/cpp/header/algorithm
[numeric-ref]: http://en.cppreference.com/w/cpp/header/numeric

## Testing

Move to the repository root and type following commands to run tests:

    mkdir tests/build
    cd tests/build
    cmake ..
    cmake --build .
    ./run

Tested compilers are:

- g++ 7
- clang++ 5.0 with libc++

## License

Boost Software License, Version 1.0.

License text is included in the header file. You don't need to copy license
file (LICENSE.txt) into your project if you just use the header file.
