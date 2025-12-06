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
#include <list>
#include <numeric>
#include <ranges>
#include <vector>

TEST_CASE("Benchmark ZipView Bidirectional Containers", "[bidirectional]")
{
  std::list<int> l1(100000);
  std::list<int> l2(100000);

  // Fill with values
  std::iota(l1.begin(), l1.end(), 0);
  std::iota(l2.begin(), l2.end(), 100000);

  auto zip_ref = std::ranges::views::zip(l1, l2);
  auto zip_sut = gst::ranges::views::zip(l1, l2);

  BENCHMARK("std zip bidi iterate")
  {
    int sum = 0;
    for (auto t : zip_ref) { sum += std::get<0>(t) + std::get<1>(t); }
    return sum;
  };

  BENCHMARK("gst zip bidi iterate")
  {
    int sum = 0;
    for (auto t : zip_sut) { sum += std::get<0>(t) + std::get<1>(t); }
    return sum;
  };
}

TEST_CASE("Benchmark ZipView Forward Iteration", "[forward]")
{
  std::vector<int> v1(100000);
  std::vector<int> v2(100000);

  std::iota(v1.begin(), v1.end(), 0);
  std::iota(v2.begin(), v2.end(), 100000);

  auto zip_ref = std::ranges::views::zip(v1, v2);
  auto zip_sut = gst::ranges::views::zip(v1, v2);

  BENCHMARK("std zip fwd iterate")
  {
    int  sum = 0;
    auto it  = zip_ref.begin();
    while (it != zip_ref.end())
    {
      sum += std::get<0>(*it) + std::get<1>(*it);
      ++it;
    }
    return sum;
  };

  BENCHMARK("gst zip fwd iterate")
  {
    int  sum = 0;
    auto it  = zip_sut.begin();
    while (it != zip_sut.end())
    {
      sum += std::get<0>(*it) + std::get<1>(*it);
      ++it;
    }
    return sum;
  };
}

TEST_CASE("Benchmark ZipView Reverse Iteration", "[reverse]")
{
  std::vector<int> v1(100000);
  std::vector<int> v2(100000);

  std::iota(v1.begin(), v1.end(), 0);
  std::iota(v2.begin(), v2.end(), 100000);

  auto zip_ref = std::ranges::views::zip(v1, v2);
  auto zip_sut = gst::ranges::views::zip(v1, v2);

  BENCHMARK("std zip rev iterate")
  {
    int  sum = 0;
    auto it  = zip_ref.end();
    while (it != zip_ref.begin())
    {
      --it;
      sum += std::get<0>(*it) + std::get<1>(*it);
    }
    return sum;
  };

  BENCHMARK("gst zip rev iterate")
  {
    int  sum = 0;
    auto it  = zip_sut.end();
    while (it != zip_sut.begin())
    {
      --it;
      sum += std::get<0>(*it) + std::get<1>(*it);
    }
    return sum;
  };
}
