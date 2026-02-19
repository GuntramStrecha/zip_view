#include <benchmark/benchmark.h>

#include "zip_view.hpp"
#include <array>
#include <ranges>
#include <vector>

namespace
{
constexpr std::size_t N = 1'000'000;
} // namespace

static void BM_StdZipWithTemporaries(benchmark::State& state)
{
  for (auto _ : state)
  {
    int sum = 0;
    for (auto t : std::ranges::views::zip(std::ranges::iota_view<int, int>(0, N)))
    {
      sum += std::get<0>(t);
    }
    benchmark::DoNotOptimize(sum);
  }
}
BENCHMARK(BM_StdZipWithTemporaries);

static void BM_GstZipWithTemporaries(benchmark::State& state)
{
  for (auto _ : state)
  {
    int sum = 0;
    for (auto t : gst::ranges::views::zip(std::ranges::iota_view<int, int>(0, N)))
    {
      sum += std::get<0>(t);
    }
    benchmark::DoNotOptimize(sum);
  }
}
BENCHMARK(BM_GstZipWithTemporaries);
