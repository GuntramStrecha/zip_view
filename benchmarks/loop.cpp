#include <benchmark/benchmark.h>

#include "zip_view.hpp"
#include <ranges>
#include <vector>

static void BM_StdZipIterate(benchmark::State& state)
{
  std::vector<int> v1(1000000);
  auto             zip_ref = std::ranges::views::zip(v1);

  for (auto _ : state)
  {
    int sum = 0;
    for (auto t : zip_ref) { sum += std::get<0>(t); }
    benchmark::DoNotOptimize(sum);
  }
}
BENCHMARK(BM_StdZipIterate);

static void BM_GstZipIterate(benchmark::State& state)
{
  std::vector<int> v1(1000000);
  auto             zip_sut = gst::ranges::views::zip(v1);

  for (auto _ : state)
  {
    int sum = 0;
    for (auto t : zip_sut) { sum += std::get<0>(t); }
    benchmark::DoNotOptimize(sum);
  }
}
BENCHMARK(BM_GstZipIterate);

static void BM_StdZipIterate4Ranges(benchmark::State& state)
{
  std::vector<int>    v1(100000);
  std::vector<double> v2(100000);
  std::vector<char>   v3(100000);
  std::vector<float>  v4(100000);
  auto                zip_ref = std::ranges::views::zip(v1, v2, v3, v4);

  for (auto _ : state)
  {
    int sum = 0;
    for (auto t : zip_ref)
    {
      sum += static_cast<int>(std::get<0>(t)) + static_cast<int>(std::get<1>(t)) +
             static_cast<int>(std::get<2>(t)) + static_cast<int>(std::get<3>(t));
    }
    benchmark::DoNotOptimize(sum);
  }
}
BENCHMARK(BM_StdZipIterate4Ranges);

static void BM_GstZipIterate4Ranges(benchmark::State& state)
{
  std::vector<int>    v1(100000);
  std::vector<double> v2(100000);
  std::vector<char>   v3(100000);
  std::vector<float>  v4(100000);
  auto                zip_sut = gst::ranges::views::zip(v1, v2, v3, v4);

  for (auto _ : state)
  {
    int sum = 0;
    for (auto t : zip_sut)
    {
      sum += static_cast<int>(std::get<0>(t)) + static_cast<int>(std::get<1>(t)) +
             static_cast<int>(std::get<2>(t)) + static_cast<int>(std::get<3>(t));
    }
    benchmark::DoNotOptimize(sum);
  }
}
BENCHMARK(BM_GstZipIterate4Ranges);
