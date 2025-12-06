#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
#endif
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_test_macros.hpp>
#ifdef __clang__
#pragma clang diagnostic pop
#endif

#include "zip_view.hpp"
#include <algorithm>
#include <numeric>
#include <ranges>
#include <vector>

TEST_CASE("Benchmark ZipView Accumulate", "[algo]")
{
  std::vector<int> v1(1000000);
  auto             zip_ref = std::ranges::views::zip(v1);
  auto             zip_sut = gst::ranges::views::zip(v1);

  BENCHMARK("std zip accumulate")
  {
    return std::accumulate(
      zip_ref.begin(), zip_ref.end(), 0, [](auto acc, auto t) { return acc + std::get<0>(t); });
  };

  BENCHMARK("gst zip accumulate")
  {
    return std::accumulate(
      zip_sut.begin(), zip_sut.end(), 0, [](auto acc, auto t) { return acc + std::get<0>(t); });
  };
}

TEST_CASE("Benchmark ZipView Transform", "[algo]")
{
  std::vector<int> v1(1000000);
  std::vector<int> v2(v1.size());
  auto             zip_ref  = std::ranges::views::zip(v1);
  auto             zip_sut  = gst::ranges::views::zip(v1);
  auto const       doubling = [](auto t) { return std::get<0>(t) * 2; };

  BENCHMARK("std zip transform")
  {
    std::transform(zip_ref.begin(), zip_ref.end(), v2.begin(), doubling);
    return v2;
  };

  BENCHMARK("gst zip transform")
  {
    std::transform(zip_sut.begin(), zip_sut.end(), v2.begin(), doubling);
    return v2;
  };
}

TEST_CASE("Benchmark ZipView Sort", "[algo]")
{
  BENCHMARK("std zip + sort")
  {
    std::vector<int> v1{5, 2, 8, 1, 9, 3, 7, 4, 6};
    std::vector<int> v2{50, 20, 80, 10, 90, 30, 70, 40, 60};
    auto             zip_ref = std::ranges::views::zip(v1, v2);

    // Need to use ranges algorithms or create a temporary container
    std::vector<std::tuple<int, int>> temp;
    temp.reserve(v1.size());
    for (auto t : zip_ref) { temp.push_back(std::make_tuple(std::get<0>(t), std::get<1>(t))); }
    std::sort(temp.begin(), temp.end());
    return temp;
  };

  BENCHMARK("gst zip + sort")
  {
    std::vector<int> v1{5, 2, 8, 1, 9, 3, 7, 4, 6};
    std::vector<int> v2{50, 20, 80, 10, 90, 30, 70, 40, 60};
    auto             zip_sut = gst::ranges::views::zip(v1, v2);
    std::sort(zip_sut.begin(),
              zip_sut.end(),
              [](auto const& a, auto const& b) { return std::get<0>(a) < std::get<0>(b); });
    return v1;
  };
}

TEST_CASE("Benchmark ZipView Find", "[algo]")
{
  std::vector<int> v1(100000);
  std::vector<int> v2(100000);

  // Fill with values
  std::iota(v1.begin(), v1.end(), 0);
  std::iota(v2.begin(), v2.end(), 100000);

  auto zip_ref = std::ranges::views::zip(v1, v2);
  auto zip_sut = gst::ranges::views::zip(v1, v2);

  BENCHMARK("std zip + find_if")
  {
    auto it = std::find_if(std::ranges::begin(zip_ref),
                           std::ranges::end(zip_ref),
                           [](auto const& t) { return std::get<0>(t) == 75000; });
    return it != std::ranges::end(zip_ref);
  };

  BENCHMARK("gst zip + find_if")
  {
    auto it = std::find_if(
      zip_sut.begin(), zip_sut.end(), [](auto const& t) { return std::get<0>(t) == 75000; });
    return it != zip_sut.end();
  };
}

TEST_CASE("Benchmark ZipView Copy", "[algo]")
{
  std::vector<int> v1(100000);
  std::vector<int> v2(100000);
  std::vector<int> out1(100000);
  std::vector<int> out2(100000);

  auto zip_ref = std::ranges::views::zip(v1, v2);
  auto zip_sut = gst::ranges::views::zip(v1, v2);
  auto zip_out = gst::ranges::views::zip(out1, out2);

  BENCHMARK("std zip + copy")
  {
    std::copy(std::ranges::begin(zip_ref), std::ranges::end(zip_ref), zip_out.begin());
    return out1;
  };

  BENCHMARK("gst zip + copy")
  {
    std::copy(zip_sut.begin(), zip_sut.end(), zip_out.begin());
    return out1;
  };
}
