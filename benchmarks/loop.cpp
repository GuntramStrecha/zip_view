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

#include "zip_view.hpp" // gst::ranges::views::zip
#include <ranges>       // std::ranges::views::zip
#include <vector>       // std::vector

TEST_CASE("Benchmark ZipView Iteration", "[loop]")
{
  std::vector<int> v1(1000000);
  auto             zip_ref = std::ranges::views::zip(v1);
  auto             zip_sut = gst::ranges::views::zip(v1);

  BENCHMARK("std::zip Iterate")
  {
    int sum = 0;
    for (auto t : zip_ref) { sum += std::get<0>(t); }
    return sum;
  };

  BENCHMARK("gst::ranges::views::zip Iterate")
  {
    int sum = 0;
    for (auto t : zip_sut) { sum += std::get<0>(t); }
    return sum;
  };
}
