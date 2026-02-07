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
#include <vector>

TEST_CASE("Benchmark Nested ZipView Iteration", "[nested]")
{
  std::vector<int> v1(100000);
  std::vector<int> v2(100000);
  std::vector<int> v3(100000);
  std::vector<int> v4(100000);

  std::iota(v1.begin(), v1.end(), 0);
  std::iota(v2.begin(), v2.end(), 100000);
  std::iota(v3.begin(), v3.end(), 200000);
  std::iota(v4.begin(), v4.end(), 300000);

  auto zip1   = gst::ranges::views::zip(v1, v2);
  auto zip2   = gst::ranges::views::zip(v3, v4);
  auto nested = gst::ranges::views::zip(zip1, zip2);

  BENCHMARK("flat zip iterate (4 ranges)")
  {
    auto flat_zip = gst::ranges::views::zip(v1, v2, v3, v4);
    int  sum      = 0;
    for (auto t : flat_zip)
    {
      sum += std::get<0>(t) + std::get<1>(t) + std::get<2>(t) + std::get<3>(t);
    }
    return sum;
  };

  BENCHMARK("nested zip iterate (2x2 ranges)")
  {
    int sum = 0;
    for (auto t : nested)
    {
      auto t0  = std::get<0>(t);
      auto t1  = std::get<1>(t);
      sum     += std::get<0>(t0) + std::get<1>(t0) + std::get<0>(t1) + std::get<1>(t1);
    }
    return sum;
  };
}

TEST_CASE("Benchmark Nested ZipView Accumulate", "[nested]")
{
  std::vector<int> v1(100000);
  std::vector<int> v2(100000);
  std::vector<int> v3(100000);
  std::vector<int> v4(100000);

  std::iota(v1.begin(), v1.end(), 0);
  std::iota(v2.begin(), v2.end(), 100000);
  std::iota(v3.begin(), v3.end(), 200000);
  std::iota(v4.begin(), v4.end(), 300000);

  auto zip1   = gst::ranges::views::zip(v1, v2);
  auto zip2   = gst::ranges::views::zip(v3, v4);
  auto nested = gst::ranges::views::zip(zip1, zip2);

  BENCHMARK("flat zip accumulate")
  {
    auto flat_zip = gst::ranges::views::zip(v1, v2, v3, v4);
    return std::accumulate(
      flat_zip.begin(),
      flat_zip.end(),
      0,
      [](auto acc, auto t)
      { return acc + std::get<0>(t) + std::get<1>(t) + std::get<2>(t) + std::get<3>(t); });
  };

  BENCHMARK("nested zip accumulate")
  {
    return std::accumulate(nested.begin(),
                           nested.end(),
                           0,
                           [](auto acc, auto t)
                           {
                             auto t0 = std::get<0>(t);
                             auto t1 = std::get<1>(t);
                             return acc + std::get<0>(t0) + std::get<1>(t0) + std::get<0>(t1) +
                                    std::get<1>(t1);
                           });
  };
}

TEST_CASE("Benchmark Nested ZipView Transform", "[nested]")
{
  std::vector<int> v1(100000);
  std::vector<int> v2(100000);
  std::vector<int> v3(100000);
  std::vector<int> v4(100000);
  std::vector<int> out(100000);

  std::iota(v1.begin(), v1.end(), 0);
  std::iota(v2.begin(), v2.end(), 100000);
  std::iota(v3.begin(), v3.end(), 200000);
  std::iota(v4.begin(), v4.end(), 300000);

  auto zip1   = gst::ranges::views::zip(v1, v2);
  auto zip2   = gst::ranges::views::zip(v3, v4);
  auto nested = gst::ranges::views::zip(zip1, zip2);

  BENCHMARK("flat zip transform")
  {
    auto flat_zip = gst::ranges::views::zip(v1, v2, v3, v4);
    std::transform(flat_zip.begin(),
                   flat_zip.end(),
                   out.begin(),
                   [](auto t)
                   { return std::get<0>(t) + std::get<1>(t) + std::get<2>(t) + std::get<3>(t); });
    return out;
  };

  BENCHMARK("nested zip transform")
  {
    std::transform(nested.begin(),
                   nested.end(),
                   out.begin(),
                   [](auto t)
                   {
                     auto t0 = std::get<0>(t);
                     auto t1 = std::get<1>(t);
                     return std::get<0>(t0) + std::get<1>(t0) + std::get<0>(t1) + std::get<1>(t1);
                   });
    return out;
  };
}

TEST_CASE("Benchmark Nested ZipView Find", "[nested]")
{
  std::vector<int> v1(100000);
  std::vector<int> v2(100000);
  std::vector<int> v3(100000);
  std::vector<int> v4(100000);

  std::iota(v1.begin(), v1.end(), 0);
  std::iota(v2.begin(), v2.end(), 100000);
  std::iota(v3.begin(), v3.end(), 200000);
  std::iota(v4.begin(), v4.end(), 300000);

  auto zip1   = gst::ranges::views::zip(v1, v2);
  auto zip2   = gst::ranges::views::zip(v3, v4);
  auto nested = gst::ranges::views::zip(zip1, zip2);

  BENCHMARK("flat zip find_if")
  {
    auto flat_zip = gst::ranges::views::zip(v1, v2, v3, v4);
    auto it       = std::find_if(
      flat_zip.begin(), flat_zip.end(), [](auto const& t) { return std::get<0>(t) == 75000; });
    return it != flat_zip.end();
  };

  BENCHMARK("nested zip find_if")
  {
    auto it = std::find_if(nested.begin(),
                           nested.end(),
                           [](auto const& t)
                           {
                             auto t0 = std::get<0>(t);
                             return std::get<0>(t0) == 75000;
                           });
    return it != nested.end();
  };
}

TEST_CASE("Benchmark Nested ZipView For_each", "[nested]")
{
  std::vector<int> v1(100000);
  std::vector<int> v2(100000);
  std::vector<int> v3(100000);
  std::vector<int> v4(100000);

  std::iota(v1.begin(), v1.end(), 0);
  std::iota(v2.begin(), v2.end(), 100000);
  std::iota(v3.begin(), v3.end(), 200000);
  std::iota(v4.begin(), v4.end(), 300000);

  auto zip1   = gst::ranges::views::zip(v1, v2);
  auto zip2   = gst::ranges::views::zip(v3, v4);
  auto nested = gst::ranges::views::zip(zip1, zip2);

  BENCHMARK("flat zip for_each")
  {
    auto flat_zip = gst::ranges::views::zip(v1, v2, v3, v4);
    int  sum      = 0;
    std::for_each(flat_zip.begin(),
                  flat_zip.end(),
                  [&sum](auto t)
                  { sum += std::get<0>(t) + std::get<1>(t) + std::get<2>(t) + std::get<3>(t); });
    return sum;
  };

  BENCHMARK("nested zip for_each")
  {
    int sum = 0;
    std::for_each(nested.begin(),
                  nested.end(),
                  [&sum](auto t)
                  {
                    auto t0 = std::get<0>(t);
                    auto t1 = std::get<1>(t);
                    sum += std::get<0>(t0) + std::get<1>(t0) + std::get<0>(t1) + std::get<1>(t1);
                  });
    return sum;
  };
}

TEST_CASE("Benchmark Nested ZipView Deep Nesting", "[nested]")
{
  std::vector<int> v1(50000);
  std::vector<int> v2(50000);
  std::vector<int> v3(50000);
  std::vector<int> v4(50000);
  std::vector<int> v5(50000);
  std::vector<int> v6(50000);
  std::vector<int> v7(50000);
  std::vector<int> v8(50000);

  std::iota(v1.begin(), v1.end(), 0);
  std::iota(v2.begin(), v2.end(), 50000);
  std::iota(v3.begin(), v3.end(), 100000);
  std::iota(v4.begin(), v4.end(), 150000);
  std::iota(v5.begin(), v5.end(), 200000);
  std::iota(v6.begin(), v6.end(), 250000);
  std::iota(v7.begin(), v7.end(), 300000);
  std::iota(v8.begin(), v8.end(), 350000);

  auto zip1_1      = gst::ranges::views::zip(v1, v2);
  auto zip1_2      = gst::ranges::views::zip(v3, v4);
  auto zip2_1      = gst::ranges::views::zip(v5, v6);
  auto zip2_2      = gst::ranges::views::zip(v7, v8);
  auto nested_1    = gst::ranges::views::zip(zip1_1, zip1_2);
  auto nested_2    = gst::ranges::views::zip(zip2_1, zip2_2);
  auto deep_nested = gst::ranges::views::zip(nested_1, nested_2);

  BENCHMARK("flat zip iterate (8 ranges)")
  {
    auto flat_zip = gst::ranges::views::zip(v1, v2, v3, v4, v5, v6, v7, v8);
    int  sum      = 0;
    for (auto t : flat_zip)
    {
      sum += std::get<0>(t) + std::get<1>(t) + std::get<2>(t) + std::get<3>(t) + std::get<4>(t) +
             std::get<5>(t) + std::get<6>(t) + std::get<7>(t);
    }
    return sum;
  };

  BENCHMARK("nested zip iterate (2x2 ranges)")
  {
    auto nested = gst::ranges::views::zip(zip1_1, zip1_2, zip2_1, zip2_2);
    int  sum    = 0;
    for (auto t : nested)
    {
      auto t0  = std::get<0>(t);
      auto t1  = std::get<1>(t);
      auto t2  = std::get<2>(t);
      auto t3  = std::get<3>(t);
      sum     += std::get<0>(t0) + std::get<1>(t0) + std::get<0>(t1) + std::get<1>(t1) +
             std::get<0>(t2) + std::get<1>(t2) + std::get<0>(t3) + std::get<1>(t3);
    }
    return sum;
  };

  BENCHMARK("deep nested zip iterate (2x(2x2) ranges)")
  {
    int sum = 0;
    for (auto t : deep_nested)
    {
      auto n0   = std::get<0>(t);
      auto n1   = std::get<1>(t);
      auto t00  = std::get<0>(n0);
      auto t01  = std::get<1>(n0);
      auto t10  = std::get<0>(n1);
      auto t11  = std::get<1>(n1);
      sum      += std::get<0>(t00) + std::get<1>(t00) + std::get<0>(t01) + std::get<1>(t01) +
             std::get<0>(t10) + std::get<1>(t10) + std::get<0>(t11) + std::get<1>(t11);
    }
    return sum;
  };
}

TEST_CASE("Benchmark Nested ZipView Subscript Access", "[nested]")
{
  std::vector<int> v1(100000);
  std::vector<int> v2(100000);
  std::vector<int> v3(100000);
  std::vector<int> v4(100000);

  std::iota(v1.begin(), v1.end(), 0);
  std::iota(v2.begin(), v2.end(), 100000);
  std::iota(v3.begin(), v3.end(), 200000);
  std::iota(v4.begin(), v4.end(), 300000);

  auto zip1   = gst::ranges::views::zip(v1, v2);
  auto zip2   = gst::ranges::views::zip(v3, v4);
  auto nested = gst::ranges::views::zip(zip1, zip2);

  BENCHMARK("flat zip subscript access")
  {
    auto flat_zip = gst::ranges::views::zip(v1, v2, v3, v4);
    int  sum      = 0;
    for (std::ptrdiff_t i = 0; i < static_cast<std::ptrdiff_t>(flat_zip.size()); ++i)
    {
      auto t  = flat_zip[i];
      sum    += std::get<0>(t) + std::get<1>(t) + std::get<2>(t) + std::get<3>(t);
    }
    return sum;
  };

  BENCHMARK("nested zip subscript access")
  {
    int sum = 0;
    for (std::ptrdiff_t i = 0; i < static_cast<std::ptrdiff_t>(nested.size()); ++i)
    {
      auto t   = nested[i];
      auto t0  = std::get<0>(t);
      auto t1  = std::get<1>(t);
      sum     += std::get<0>(t0) + std::get<1>(t0) + std::get<0>(t1) + std::get<1>(t1);
    }
    return sum;
  };
}
