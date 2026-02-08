#include <benchmark/benchmark.h>

#include "zip_view.hpp"
#include <array>
#include <ranges>
#include <vector>

static void BM_StdZipWithTemporaries(benchmark::State& state)
{
  for (auto _ : state)
  {
    auto zip =
      std::ranges::views::zip(std::vector<int>{1, 2, 3}, std::array<char, 3>{'a', 'b', 'c'});
    int sum = 0;
    for (auto t : zip) { sum += std::get<0>(t); }
    benchmark::DoNotOptimize(sum);
  }
}
BENCHMARK(BM_StdZipWithTemporaries);

static void BM_GstZipWithTemporaries(benchmark::State& state)
{
  for (auto _ : state)
  {
    auto zip =
      gst::ranges::views::zip(std::vector<int>{1, 2, 3}, std::array<char, 3>{'a', 'b', 'c'});
    int sum = 0;
    for (auto t : zip) { sum += std::get<0>(t); }
    benchmark::DoNotOptimize(sum);
  }
}
BENCHMARK(BM_GstZipWithTemporaries);
