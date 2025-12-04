[![codecov](https://codecov.io/gh/GuntramStrecha/zip_view/graph/badge.svg?token=KD7V3790WF)](https://codecov.io/gh/GuntramStrecha/zip_view)
[![CodeQL](https://github.com/GuntramStrecha/zip_view/actions/workflows/codeql-analysis.yml/badge.svg)](https://github.com/GuntramStrecha/zip_view/actions/workflows/codeql-analysis.yml)
[![Benchmarks](https://github.com/GuntramStrecha/zip_view/actions/workflows/benchmark.yml/badge.svg)](https://github.com/GuntramStrecha/zip_view/actions/workflows/benchmark.yml)

# zip_view
C++-11 implementation of std::ranges::zip_view and std::ranges::views::zip

## Examples

- Looping over multiple containers of different types:
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
  void print_tuple_impl(Tuple const& tuple, gst::detail::index_sequence<Is...>)
  {
    static_cast<void>(std::initializer_list<int>{(std::cout << std::get<Is>(tuple) << ' ', 0)...});
    std::cout << '\n';
  }

  // Main function to print the tuple
  template <typename... Args>
  void print_tuple(std::tuple<Args...> const& tuple)
  {
    print_tuple_impl(tuple, gst::detail::make_index_sequence<sizeof...(Args)>{});
  }

  int main()
  {
    std::array<int, 3>       a_3 = {1, 2, 3};
    std::list<double>        l_5 = {1.1, 2.2, 3.3, 4.4, 5.5};
    std::deque<bool>         d_7 = {true, false, true, false, true, false, true};
    std::forward_list<char>  f_6 = {'a', 'b', 'c', 'd', 'e', 'f'};
    std::vector<std::string> v_4 = {"one", "two", "three", "four"};

    for (auto const iter_tuple : gst::ranges::views::zip(a_3, l_5, d_7, f_6, v_4))
    {
      print_tuple(iter_tuple);
    }

  // 1 1.1 1 a one
  // 2 2.2 0 b two
  // 3 3.3 1 c three
  }
  ```
- When all containers are random-access, you can use `std::sort` directly on the zipped view:
  ```cpp
  #include "zip_view.hpp"
  #include <algorithm>
  #include <vector>

  int main()
  {
    std::vector<int>    keys   = {3, 1, 2};
    std::vector<double> values = {30.0, 10.0, 20.0};

    auto zipped = gst::ranges::views::zip(keys, values);

    std::sort(zipped.begin(), zipped.end(),
              [](auto const& a, auto const& b) { return std::get<0>(a) < std::get<0>(b); });

    // keys:   {1, 2, 3}
    // values: {10.0, 20.0, 30.0}
  }
  ```
- When a `std::list` or `std::forward_list` is involved, `std::sort` cannot be used on the view because the iterator category is no longer random-access. In such cases, consider using index-based sorting or materializing the data.


## Requirements
- C++-11 for the examples
- C++-23 for the tests (`Catch2`)
- C++-23 for the benchmarks (for comparing to `std::ranges::zip_view`)

## Build
```bash
mkdir build
cd build
cmake ..
make
```

## Iterator Category

`gst::ranges::zip_view` adapts its iterator category to the weakest underlying range, similar to `std::ranges::zip_view`:

- **Random Access Iterator**: When all underlying ranges are random-access (e.g., `std::vector`, `std::array`, `std::deque`)
- **Bidirectional Iterator**: When all underlying ranges are at least bidirectional (e.g., `std::list`)
- **Forward Iterator**: When any underlying range is only forward (e.g., `std::forward_list`)

This allows algorithms like `std::sort` to work directly on the zipped view when all underlying ranges support random access.

## Benchmarks

The project includes comprehensive benchmarks comparing `gst::ranges::views::zip` with `std::ranges::views::zip` (C++23):

### Benchmark History
View the [benchmark history dashboard](https://guntramstrecha.github.io/zip_view/dev/bench/) to track performance over time.

### Running Benchmarks Locally
```bash
cd build
./benchmarks/ZipViewBenchmark
```
