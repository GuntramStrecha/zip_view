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

TEST_CASE("Benchmark ZipView Iteration", "[loop]")
{
  std::vector<int> v1(1000000);
  auto             zip_ref = std::ranges::views::zip(v1);
  auto             zip_sut = gst::ranges::views::zip(v1);

  BENCHMARK("std zip iterate")
  {
    int sum = 0;
    for (auto t : zip_ref) { sum += std::get<0>(t); }
    return sum;
  };

  BENCHMARK("gst zip iterate")
  {
    int sum = 0;
    for (auto t : zip_sut) { sum += std::get<0>(t); }
    return sum;
  };
}

TEST_CASE("Benchmark ZipView Iteration Multiple Containers", "[loop]")
{
  std::vector<int>    v1(100000);
  std::vector<double> v2(100000);
  std::vector<char>   v3(100000);
  std::vector<float>  v4(100000);

  auto zip_ref = std::ranges::views::zip(v1, v2, v3, v4);
  auto zip_sut = gst::ranges::views::zip(v1, v2, v3, v4);

  BENCHMARK("std zip iterate 4 ranges")
  {
    int sum = 0;
    for (auto t : zip_ref)
    {
      sum += static_cast<int>(std::get<0>(t)) + static_cast<int>(std::get<1>(t)) +
             static_cast<int>(std::get<2>(t)) + static_cast<int>(std::get<3>(t));
    }
    return sum;
  };

  BENCHMARK("gst zip iterate 4 ranges")
  {
    int sum = 0;
    for (auto t : zip_sut)
    {
      sum += static_cast<int>(std::get<0>(t)) + static_cast<int>(std::get<1>(t)) +
             static_cast<int>(std::get<2>(t)) + static_cast<int>(std::get<3>(t));
    }
    return sum;
  };
}
