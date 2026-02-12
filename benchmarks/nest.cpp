#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
#endif
#include <benchmark/benchmark.h>
#ifdef __clang__
#pragma clang diagnostic pop
#endif

#include "zip_view.hpp"
#include <algorithm>
#include <numeric>
#include <ranges>
#include <utility>
#include <vector>

template <typename... R>
auto std_zip(R&&... r)
{
  return std::ranges::views::zip(std::forward<R>(r)...);
}

template <typename... R>
auto gst_zip(R&&... r)
{
  return gst::ranges::views::zip(std::forward<R>(r)...);
}

// Converted Catch2 benchmarks -> Google Benchmark

template <bool UseGst>
static void BM_NestedZipIterate2x2_impl(benchmark::State& state)
{
  std::vector<int> v1(100000);
  std::vector<int> v2(100000);
  std::vector<int> v3(100000);
  std::vector<int> v4(100000);

  std::iota(v1.begin(), v1.end(), 0);
  std::iota(v2.begin(), v2.end(), 100000);
  std::iota(v3.begin(), v3.end(), 200000);
  std::iota(v4.begin(), v4.end(), 300000);

  auto make_zip = [](auto&&... args)
  {
    if constexpr (UseGst)
      return gst_zip(std::forward<decltype(args)>(args)...);
    else
      return std_zip(std::forward<decltype(args)>(args)...);
  };

  auto zip1   = make_zip(v1, v2);
  auto zip2   = make_zip(v3, v4);
  auto nested = make_zip(zip1, zip2);

  for (auto _ : state)
  {
    int sum = 0;
    for (auto t : nested)
    {
      auto t0  = std::get<0>(t);
      auto t1  = std::get<1>(t);
      sum     += std::get<0>(t0) + std::get<1>(t0) + std::get<0>(t1) + std::get<1>(t1);
    }
    benchmark::DoNotOptimize(sum);
  }
}

static void BM_StdNestedZipIterate2x2(benchmark::State& s)
{
  BM_NestedZipIterate2x2_impl<false>(s);
}
static void BM_GstNestedZipIterate2x2(benchmark::State& s) { BM_NestedZipIterate2x2_impl<true>(s); }

BENCHMARK(BM_StdNestedZipIterate2x2);
BENCHMARK(BM_GstNestedZipIterate2x2);

template <bool UseGst>
static void BM_NestedZipAccumulate_impl(benchmark::State& state)
{
  std::vector<int> v1(100000);
  std::vector<int> v2(100000);
  std::vector<int> v3(100000);
  std::vector<int> v4(100000);

  std::iota(v1.begin(), v1.end(), 0);
  std::iota(v2.begin(), v2.end(), 100000);
  std::iota(v3.begin(), v3.end(), 200000);
  std::iota(v4.begin(), v4.end(), 300000);

  auto make_zip = [](auto&&... args)
  {
    if constexpr (UseGst)
      return gst_zip(std::forward<decltype(args)>(args)...);
    else
      return std_zip(std::forward<decltype(args)>(args)...);
  };

  auto zip1   = make_zip(v1, v2);
  auto zip2   = make_zip(v3, v4);
  auto nested = make_zip(zip1, zip2);

  for (auto _ : state)
  {
    int res = std::accumulate(nested.begin(),
                              nested.end(),
                              0,
                              [](auto acc, auto t)
                              {
                                auto t0 = std::get<0>(t);
                                auto t1 = std::get<1>(t);
                                return acc + std::get<0>(t0) + std::get<1>(t0) + std::get<0>(t1) +
                                       std::get<1>(t1);
                              });
    benchmark::DoNotOptimize(res);
  }
}

static void BM_StdNestedZipAccumulate(benchmark::State& s)
{
  BM_NestedZipAccumulate_impl<false>(s);
}
static void BM_GstNestedZipAccumulate(benchmark::State& s) { BM_NestedZipAccumulate_impl<true>(s); }

BENCHMARK(BM_StdNestedZipAccumulate);
BENCHMARK(BM_GstNestedZipAccumulate);

template <bool UseGst>
static void BM_NestedZipTransform_impl(benchmark::State& state)
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

  auto make_zip = [](auto&&... args)
  {
    if constexpr (UseGst)
      return gst_zip(std::forward<decltype(args)>(args)...);
    else
      return std_zip(std::forward<decltype(args)>(args)...);
  };

  auto zip1   = make_zip(v1, v2);
  auto zip2   = make_zip(v3, v4);
  auto nested = make_zip(zip1, zip2);

  for (auto _ : state)
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
    benchmark::DoNotOptimize(out.data());
  }
}

static void BM_StdNestedZipTransform(benchmark::State& s) { BM_NestedZipTransform_impl<false>(s); }
static void BM_GstNestedZipTransform(benchmark::State& s) { BM_NestedZipTransform_impl<true>(s); }

BENCHMARK(BM_StdNestedZipTransform);
BENCHMARK(BM_GstNestedZipTransform);

template <bool UseGst>
static void BM_NestedZipFindIf_impl(benchmark::State& state)
{
  std::vector<int> v1(100000);
  std::vector<int> v2(100000);
  std::vector<int> v3(100000);
  std::vector<int> v4(100000);

  std::iota(v1.begin(), v1.end(), 0);
  std::iota(v2.begin(), v2.end(), 100000);
  std::iota(v3.begin(), v3.end(), 200000);
  std::iota(v4.begin(), v4.end(), 300000);

  auto make_zip = [](auto&&... args)
  {
    if constexpr (UseGst)
      return gst_zip(std::forward<decltype(args)>(args)...);
    else
      return std_zip(std::forward<decltype(args)>(args)...);
  };

  auto zip1   = make_zip(v1, v2);
  auto zip2   = make_zip(v3, v4);
  auto nested = make_zip(zip1, zip2);

  for (auto _ : state)
  {
    auto it = std::find_if(nested.begin(),
                           nested.end(),
                           [](auto const& t)
                           {
                             auto t0 = std::get<0>(t);
                             return std::get<0>(t0) == 75000;
                           });
    benchmark::DoNotOptimize(it);
  }
}

static void BM_StdNestedZipFindIf(benchmark::State& s) { BM_NestedZipFindIf_impl<false>(s); }
static void BM_GstNestedZipFindIf(benchmark::State& s) { BM_NestedZipFindIf_impl<true>(s); }

BENCHMARK(BM_StdNestedZipFindIf);
BENCHMARK(BM_GstNestedZipFindIf);

template <bool UseGst>
static void BM_NestedZipForEach_impl(benchmark::State& state)
{
  std::vector<int> v1(100000);
  std::vector<int> v2(100000);
  std::vector<int> v3(100000);
  std::vector<int> v4(100000);

  std::iota(v1.begin(), v1.end(), 0);
  std::iota(v2.begin(), v2.end(), 100000);
  std::iota(v3.begin(), v3.end(), 200000);
  std::iota(v4.begin(), v4.end(), 300000);

  auto make_zip = [](auto&&... args)
  {
    if constexpr (UseGst)
      return gst_zip(std::forward<decltype(args)>(args)...);
    else
      return std_zip(std::forward<decltype(args)>(args)...);
  };

  auto zip1   = make_zip(v1, v2);
  auto zip2   = make_zip(v3, v4);
  auto nested = make_zip(zip1, zip2);

  for (auto _ : state)
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
    benchmark::DoNotOptimize(sum);
  }
}

static void BM_StdNestedZipForEach(benchmark::State& s) { BM_NestedZipForEach_impl<false>(s); }
static void BM_GstNestedZipForEach(benchmark::State& s) { BM_NestedZipForEach_impl<true>(s); }

BENCHMARK(BM_StdNestedZipForEach);
BENCHMARK(BM_GstNestedZipForEach);

template <bool UseGst>
static void BM_NestedZipIterate2x2x2_impl(benchmark::State& state)
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

  auto make_zip = [](auto&&... args)
  {
    if constexpr (UseGst)
      return gst_zip(std::forward<decltype(args)>(args)...);
    else
      return std_zip(std::forward<decltype(args)>(args)...);
  };

  auto zip1_1 = make_zip(v1, v2);
  auto zip1_2 = make_zip(v3, v4);
  auto zip2_1 = make_zip(v5, v6);
  auto zip2_2 = make_zip(v7, v8);
  auto nested = make_zip(zip1_1, zip1_2, zip2_1, zip2_2);

  for (auto _ : state)
  {
    int sum = 0;
    for (auto t : nested)
    {
      auto t0  = std::get<0>(t);
      auto t1  = std::get<1>(t);
      auto t2  = std::get<2>(t);
      auto t3  = std::get<3>(t);
      sum     += std::get<0>(t0) + std::get<1>(t0) + std::get<0>(t1) + std::get<1>(t1) +
             std::get<0>(t2) + std::get<1>(t2) + std::get<0>(t3) + std::get<1>(t3);
    }
    benchmark::DoNotOptimize(sum);
  }
}

static void BM_StdNestedZipIterate2x2x2(benchmark::State& s)
{
  BM_NestedZipIterate2x2x2_impl<false>(s);
}
static void BM_GstNestedZipIterate2x2x2(benchmark::State& s)
{
  BM_NestedZipIterate2x2x2_impl<true>(s);
}

BENCHMARK(BM_StdNestedZipIterate2x2x2);
BENCHMARK(BM_GstNestedZipIterate2x2x2);

template <bool UseGst>
static void BM_DeepNestedZipIterate_impl(benchmark::State& state)
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

  auto make_zip = [](auto&&... args)
  {
    if constexpr (UseGst)
      return gst_zip(std::forward<decltype(args)>(args)...);
    else
      return std_zip(std::forward<decltype(args)>(args)...);
  };

  auto zip1_1      = make_zip(v1, v2);
  auto zip1_2      = make_zip(v3, v4);
  auto zip2_1      = make_zip(v5, v6);
  auto zip2_2      = make_zip(v7, v8);
  auto nested_1    = make_zip(zip1_1, zip1_2);
  auto nested_2    = make_zip(zip2_1, zip2_2);
  auto deep_nested = make_zip(nested_1, nested_2);

  for (auto _ : state)
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
    benchmark::DoNotOptimize(sum);
  }
}

static void BM_StdDeepNestedZipIterate(benchmark::State& s)
{
  BM_DeepNestedZipIterate_impl<false>(s);
}
static void BM_GstDeepNestedZipIterate(benchmark::State& s)
{
  BM_DeepNestedZipIterate_impl<true>(s);
}

BENCHMARK(BM_StdDeepNestedZipIterate);
BENCHMARK(BM_GstDeepNestedZipIterate);

template <bool UseGst>
static void BM_NestedZipSubscriptAccess_impl(benchmark::State& state)
{
  std::vector<int> v1(100000);
  std::vector<int> v2(100000);
  std::vector<int> v3(100000);
  std::vector<int> v4(100000);

  std::iota(v1.begin(), v1.end(), 0);
  std::iota(v2.begin(), v2.end(), 100000);
  std::iota(v3.begin(), v3.end(), 200000);
  std::iota(v4.begin(), v4.end(), 300000);

  auto make_zip = [](auto&&... args)
  {
    if constexpr (UseGst)
      return gst_zip(std::forward<decltype(args)>(args)...);
    else
      return std_zip(std::forward<decltype(args)>(args)...);
  };

  auto zip1   = make_zip(v1, v2);
  auto zip2   = make_zip(v3, v4);
  auto nested = make_zip(zip1, zip2);

  for (auto _ : state)
  {
    int sum = 0;
    for (std::ptrdiff_t i = 0; i < static_cast<std::ptrdiff_t>(nested.size()); ++i)
    {
      auto t   = nested[i];
      auto t0  = std::get<0>(t);
      auto t1  = std::get<1>(t);
      sum     += std::get<0>(t0) + std::get<1>(t0) + std::get<0>(t1) + std::get<1>(t1);
    }
    benchmark::DoNotOptimize(sum);
  }
}

static void BM_StdNestedZipSubscriptAccess(benchmark::State& s)
{
  BM_NestedZipSubscriptAccess_impl<false>(s);
}
static void BM_GstNestedZipSubscriptAccess(benchmark::State& s)
{
  BM_NestedZipSubscriptAccess_impl<true>(s);
}

BENCHMARK(BM_StdNestedZipSubscriptAccess);
BENCHMARK(BM_GstNestedZipSubscriptAccess);
