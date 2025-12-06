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
#include <ranges>
#include <vector>

TEST_CASE("Benchmark ZipView Constructor", "[ctor]")
{
  BENCHMARK("std zip construct")
  {
    std::vector<int> v1(1000000);
    return std::ranges::views::zip(v1);
  };

  BENCHMARK("gst zip construct")
  {
    std::vector<int> v1(1000000);
    return gst::ranges::views::zip(v1);
  };
}
