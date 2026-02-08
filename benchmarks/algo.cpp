#include <benchmark/benchmark.h>

#include "zip_view.hpp"
#include <algorithm>
#include <numeric>
#include <ranges>
#include <vector>

static void BM_StdZipWithSort(benchmark::State& state)
{
  for (auto _ : state)
  {
    state.PauseTiming();
    std::vector<int>  v1(10000);
    std::vector<char> v2(10000);
    std::iota(v1.begin(), v1.end(), 0);
    std::iota(v2.begin(), v2.end(), 0);
    auto zip = std::ranges::views::zip(v1, v2);
    state.ResumeTiming();

    std::ranges::sort(zip,
                      [](auto const& a, auto const& b) { return std::get<0>(a) > std::get<0>(b); });
    benchmark::DoNotOptimize(v1.data());
  }
}
BENCHMARK(BM_StdZipWithSort);

static void BM_GstZipWithSort(benchmark::State& state)
{
  for (auto _ : state)
  {
    state.PauseTiming();
    std::vector<int>  v1(10000);
    std::vector<char> v2(10000);
    std::iota(v1.begin(), v1.end(), 0);
    std::iota(v2.begin(), v2.end(), 0);
    auto zip = gst::ranges::views::zip(v1, v2);
    state.ResumeTiming();

    std::ranges::sort(zip,
                      [](auto const& a, auto const& b) { return std::get<0>(a) > std::get<0>(b); });
    benchmark::DoNotOptimize(v1.data());
  }
}
BENCHMARK(BM_GstZipWithSort);

static void BM_StdZipWithFind(benchmark::State& state)
{
  std::vector<int>  v1(100000);
  std::vector<char> v2(100000);
  std::iota(v1.begin(), v1.end(), 0);
  auto zip = std::ranges::views::zip(v1, v2);

  for (auto _ : state)
  {
    auto it = std::ranges::find_if(zip, [](auto const& t) { return std::get<0>(t) == 50000; });
    benchmark::DoNotOptimize(it);
  }
}
BENCHMARK(BM_StdZipWithFind);

static void BM_GstZipWithFind(benchmark::State& state)
{
  std::vector<int>  v1(100000);
  std::vector<char> v2(100000);
  std::iota(v1.begin(), v1.end(), 0);
  auto zip = gst::ranges::views::zip(v1, v2);

  for (auto _ : state)
  {
    auto it = std::ranges::find_if(zip, [](auto const& t) { return std::get<0>(t) == 50000; });
    benchmark::DoNotOptimize(it);
  }
}
BENCHMARK(BM_GstZipWithFind);
