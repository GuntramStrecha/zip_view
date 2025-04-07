#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-macros"
#endif
#define CATCH_CONFIG_MAIN
#ifdef __clang__
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_test_macros.hpp>
#pragma clang diagnostic pop
#else
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_test_macros.hpp>
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

  BENCHMARK("std::ranges::views::zip Accumulate")
  {
    return std::accumulate(
      zip_ref.begin(), zip_ref.end(), 0, [](auto acc, auto t) { return acc + std::get<0>(t); });
  };

  BENCHMARK("gst::ranges::views::zip Accumulate")
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

  BENCHMARK("std::ranges::views::zip Transform")
  {
    std::transform(zip_ref.begin(), zip_ref.end(), v2.begin(), doubling);
    return v2;
  };

  BENCHMARK("gst::ranges::views::zip Transform")
  {
    std::transform(zip_sut.begin(), zip_sut.end(), v2.begin(), doubling);
    return v2;
  };
}
