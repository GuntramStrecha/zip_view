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
  auto make_zip = [](auto&&... args)
  {
    if constexpr (UseGst)
      return gst_zip(std::forward<decltype(args)>(args)...);
    else
      return std_zip(std::forward<decltype(args)>(args)...);
  };

  using iota = std::ranges::iota_view<int, int>;
  auto zip1   = make_zip(iota(0, 100000), iota(100000, 200000));
  auto zip2   = make_zip(iota(200000, 300000), iota(300000, 400000));
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
  auto make_zip = [](auto&&... args)
  {
    if constexpr (UseGst)
      return gst_zip(std::forward<decltype(args)>(args)...);
    else
      return std_zip(std::forward<decltype(args)>(args)...);
  };

  using iota = std::ranges::iota_view<int, int>;
  auto zip1   = make_zip(iota(0, 100000), iota(100000, 200000));
  auto zip2   = make_zip(iota(200000, 300000), iota(300000, 400000));
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
  auto make_zip = [](auto&&... args)
  {
    if constexpr (UseGst)
      return gst_zip(std::forward<decltype(args)>(args)...);
    else
      return std_zip(std::forward<decltype(args)>(args)...);
  };

  using iota = std::ranges::iota_view<int, int>;
  auto zip1   = make_zip(iota(0, 100000), iota(100000, 200000));
  auto zip2   = make_zip(iota(200000, 300000), iota(300000, 400000));
  auto nested = make_zip(zip1, zip2);
  auto out    = std::array<int, 100000>{};

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
  auto make_zip = [](auto&&... args)
  {
    if constexpr (UseGst)
      return gst_zip(std::forward<decltype(args)>(args)...);
    else
      return std_zip(std::forward<decltype(args)>(args)...);
  };

  using iota = std::ranges::iota_view<int, int>;
  auto zip1   = make_zip(iota(0, 100000), iota(100000, 200000));
  auto zip2   = make_zip(iota(200000, 300000), iota(300000, 400000));
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
  auto make_zip = [](auto&&... args)
  {
    if constexpr (UseGst)
      return gst_zip(std::forward<decltype(args)>(args)...);
    else
      return std_zip(std::forward<decltype(args)>(args)...);
  };

  using iota = std::ranges::iota_view<int, int>;
  auto zip1   = make_zip(iota(0, 100000), iota(100000, 200000));
  auto zip2   = make_zip(iota(200000, 300000), iota(300000, 400000));
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
  auto make_zip = [](auto&&... args)
  {
    if constexpr (UseGst)
      return gst_zip(std::forward<decltype(args)>(args)...);
    else
      return std_zip(std::forward<decltype(args)>(args)...);
  };

  using iota = std::ranges::iota_view<int, int>;
  auto zip1_1 = make_zip(iota(0, 50000), iota(50000, 100000));
  auto zip1_2 = make_zip(iota(100000, 150000), iota(150000, 200000));
  auto zip2_1 = make_zip(iota(200000, 250000), iota(250000, 300000));
  auto zip2_2 = make_zip(iota(300000, 350000), iota(350000, 400000));
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
  auto make_zip = [](auto&&... args)
  {
    if constexpr (UseGst)
      return gst_zip(std::forward<decltype(args)>(args)...);
    else
      return std_zip(std::forward<decltype(args)>(args)...);
  };

  using iota = std::ranges::iota_view<int, int>;
  auto zip1_1      = make_zip(iota(0, 50000), iota(50000, 100000));
  auto zip1_2      = make_zip(iota(100000, 150000), iota(150000, 200000));
  auto zip2_1      = make_zip(iota(200000, 250000), iota(250000, 300000));
  auto zip2_2      = make_zip(iota(300000, 350000), iota(350000, 400000));
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
  auto make_zip = [](auto&&... args)
  {
    if constexpr (UseGst)
      return gst_zip(std::forward<decltype(args)>(args)...);
    else
      return std_zip(std::forward<decltype(args)>(args)...);
  };

  using iota = std::ranges::iota_view<int, int>;
  auto zip1   = make_zip(iota(0, 100000), iota(100000, 200000));
  auto zip2   = make_zip(iota(200000, 300000), iota(300000, 400000));
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
