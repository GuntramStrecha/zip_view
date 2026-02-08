#include <benchmark/benchmark.h>

#include "zip_view.hpp"
#include <array>
#include <ranges>
#include <vector>

namespace
{
template <std::size_t N, int start = 0>
std::array<int32_t, N> make_iota_vec()
{
  std::array<int32_t, N> arr;
  std::ranges::iota(arr, start);
  return arr;
}

constexpr std::size_t N = 1'000'000;
} // namespace

static void BM_StdZipWithTemporaries(benchmark::State& state)
{
  for (auto _ : state)
  {
    int sum = 0;
    for (auto t : std::ranges::views::zip(make_iota_vec<N, 0>())) { sum += std::get<0>(t); }
    benchmark::DoNotOptimize(sum);
  }
}
BENCHMARK(BM_StdZipWithTemporaries);

static void BM_GstZipWithTemporaries(benchmark::State& state)
{
  for (auto _ : state)
  {
    int sum = 0;
    for (auto t : gst::ranges::views::zip(make_iota_vec<N, 0>())) { sum += std::get<0>(t); }
    benchmark::DoNotOptimize(sum);
  }
}
BENCHMARK(BM_GstZipWithTemporaries);
