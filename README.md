[![codecov](https://codecov.io/gh/GuntramStrecha/zip_view/graph/badge.svg?token=KD7V3790WF)](https://codecov.io/gh/GuntramStrecha/zip_view)
[![CodeQL](https://github.com/GuntramStrecha/zip_view/actions/workflows/codeql-analysis.yml/badge.svg)](https://github.com/GuntramStrecha/zip_view/actions/workflows/codeql-analysis.yml)
[![Benchmarks](https://github.com/GuntramStrecha/zip_view/actions/workflows/benchmark.yml/badge.svg)](https://github.com/GuntramStrecha/zip_view/actions/workflows/benchmark.yml)

# zip_view
C++-11 implementation of std::ranges::zip_view and std::ranges::views::zip

# Example
```cpp
#include "zip_view.hpp"

#include <array>
#include <cstddef>
#include <deque>
#include <forward_list>
#include <initializer_list>
#include <iostream>
#include <list>
#include <string>
#include <tuple>
#include <vector>

template <typename Tuple, std::size_t... Is>
void print_tuple_impl(Tuple const& tuple, gst::index_sequence<Is...>)
{
  static_cast<void>(std::initializer_list<int>{(std::cout << std::get<Is>(tuple) << ' ', 0)...});
  std::cout << '\n';
}

// Main function to print the tuple
template <typename... Args>
void print_tuple(std::tuple<Args...> const& tuple)
{
  print_tuple_impl(tuple, gst::make_index_sequence<sizeof...(Args)>{});
}

int main()
{
  std::array<int, 3>       a_3 = {1, 2, 3};
  std::list<double>        l_5 = {1.1, 2.2, 3.3, 4.4, 5.5};
  std::deque<bool>         d_7 = {true, false, true, false, true, false, true};
  std::forward_list<char>  f_6 = {'a', 'b', 'c', 'd', 'e', 'f'};
  std::vector<std::string> v_4 = {"one", "two", "three", "four"};

  for (auto const iter_tuple : gst::zip(a_3, l_5, d_7, f_6, v_4)) { print_tuple(iter_tuple); }
}
```

# Output
```
1 1.1 1 a one
2 2.2 0 b two
3 3.3 1 c three
```

# Requirements
- C++-11 for the examples
- C++-23 for the tests (`Catch2`)
- C++-23 for the benchmarks (for comparing to `std::ranged::zip_view`)

# Build
```bash
mkdir build
cd build
cmake ..
make
```
## Benchmarks

The project includes comprehensive benchmarks comparing `gst::ranges::views::zip` with `std::ranges::views::zip` (C++23):

### Benchmark History
View the [benchmark history dashboard](https://guntramstrecha.github.io/zip_view/dev/bench/) to track performance over time.

### Running Benchmarks Locally
```bash
cd build
./benchmarks/ZipViewBenchmark
```
