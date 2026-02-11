#include <benchmark/benchmark.h>

#include "zip_view.hpp"
#include <ranges>
#include <vector>

static void BM_StdZipConstruction(benchmark::State& state)
{
  std::vector<int>  v1(1000);
  std::vector<char> v2(1000);

  for (auto _ : state)
  {
    auto zip = std::ranges::views::zip(v1, v2);
    benchmark::DoNotOptimize(zip);
  }
}
BENCHMARK(BM_StdZipConstruction);

static void BM_GstZipConstruction(benchmark::State& state)
{
  std::vector<int>  v1(1000);
  std::vector<char> v2(1000);

  for (auto _ : state)
  {
    auto zip = gst::ranges::views::zip(v1, v2);
    benchmark::DoNotOptimize(zip);
  }
}
BENCHMARK(BM_GstZipConstruction);

static void BM_StdZipConstruction4Containers(benchmark::State& state)
{
  std::vector<int>    v1(1000);
  std::vector<double> v2(1000);
  std::vector<char>   v3(1000);
  std::vector<float>  v4(1000);

  for (auto _ : state)
  {
    auto zip = std::ranges::views::zip(v1, v2, v3, v4);
    benchmark::DoNotOptimize(zip);
  }
}
BENCHMARK(BM_StdZipConstruction4Containers);

static void BM_GstZipConstruction4Containers(benchmark::State& state)
{
  std::vector<int>    v1(1000);
  std::vector<double> v2(1000);
  std::vector<char>   v3(1000);
  std::vector<float>  v4(1000);

  for (auto _ : state)
  {
    auto zip = gst::ranges::views::zip(v1, v2, v3, v4);
    benchmark::DoNotOptimize(zip);
  }
}
BENCHMARK(BM_GstZipConstruction4Containers);
