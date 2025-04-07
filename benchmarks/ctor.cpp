#ifdef __clang__
#pragma clang diagnostic push
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

TEST_CASE("Benchmark ZipView Constructor", "[ctor]")
{
  BENCHMARK("std::ranges::views::zip Construct")
  {
    std::vector<int> v1(1000000);
    return std::ranges::views::zip(v1);
  };

  BENCHMARK("gst::ranges::views::zip Construct")
  {
    std::vector<int> v1(1000000);
    return gst::ranges::views::zip(v1);
  };
}
