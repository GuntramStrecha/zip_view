#include <benchmark/benchmark.h>

#include "zip_view.hpp"
#include <ranges>
#include <vector>

static void BM_StdZipIteratorIncrement(benchmark::State& state)
{
  std::vector<int>  v1(100000);
  std::vector<char> v2(100000);
  auto              zip_ref = std::ranges::views::zip(v1, v2);

  for (auto _ : state)
  {
    auto it = zip_ref.begin();
    while (it != zip_ref.end()) { ++it; }
    benchmark::DoNotOptimize(it);
  }
}
BENCHMARK(BM_StdZipIteratorIncrement);

static void BM_GstZipIteratorIncrement(benchmark::State& state)
{
  std::vector<int>  v1(100000);
  std::vector<char> v2(100000);
  auto              zip_sut = gst::ranges::views::zip(v1, v2);

  for (auto _ : state)
  {
    auto it = zip_sut.begin();
    while (it != zip_sut.end()) { ++it; }
    benchmark::DoNotOptimize(it);
  }
}
BENCHMARK(BM_GstZipIteratorIncrement);

static void BM_StdZipIteratorRandomAccess(benchmark::State& state)
{
  std::vector<int>  v1(100000);
  std::vector<char> v2(100000);
  auto              zip_ref = std::ranges::views::zip(v1, v2);

  for (auto _ : state)
  {
    auto it  = zip_ref.begin();
    auto val = it[50000];
    benchmark::DoNotOptimize(val);
  }
}
BENCHMARK(BM_StdZipIteratorRandomAccess);

static void BM_GstZipIteratorRandomAccess(benchmark::State& state)
{
  std::vector<int>  v1(100000);
  std::vector<char> v2(100000);
  auto              zip_sut = gst::ranges::views::zip(v1, v2);

  for (auto _ : state)
  {
    auto it  = zip_sut.begin();
    auto val = it[50000];
    benchmark::DoNotOptimize(val);
  }
}
BENCHMARK(BM_GstZipIteratorRandomAccess);
