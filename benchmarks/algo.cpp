#include <benchmark/benchmark.h>

#include "zip_view.hpp"
#include <algorithm>
#include <array>
#include <ranges>
#include <tuple>


namespace {

void BM_StdZipWithSort(benchmark::State& state)
{
  for (auto _ : state)
  {
    state.PauseTiming();
        std::array<int, 10000>  a1;
        std::array<char, 10000> a2;
        std::ranges::generate(a1, [n = 0]() mutable { return n++; });
        std::ranges::generate(a2, [n = 0]() mutable { return static_cast<char>(n++); });
    auto zip = std::ranges::views::zip(a1, a2);
    state.ResumeTiming();

    std::ranges::sort(zip, std::ranges::greater{});
    benchmark::DoNotOptimize(a1.data());
  }
}
BENCHMARK(BM_StdZipWithSort);

void BM_GstZipWithSort(benchmark::State& state)
{
  for (auto _ : state)
  {
    state.PauseTiming();
        std::array<int, 10000>  a1;
        std::array<char, 10000> a2;
        std::ranges::generate(a1, [n = 0]() mutable { return n++; });
        std::ranges::generate(a2, [n = 0]() mutable { return static_cast<char>(n++); });
    auto zip = gst::ranges::views::zip(a1, a2);
    state.ResumeTiming();

    std::ranges::sort(zip, std::ranges::greater{});
    benchmark::DoNotOptimize(a1.data());
  }
}
BENCHMARK(BM_GstZipWithSort);

void BM_StdZipWithFind(benchmark::State& state)
{
      std::array<int, 100000>  a1;
      std::array<char, 100000> a2;
      std::ranges::generate(a1, [n = 0]() mutable { return n++; });
      std::ranges::generate(a2, [n = 0]() mutable { return static_cast<char>(n++); });
      auto zip = std::ranges::views::zip(a1, a2);

  for (auto _ : state)
  {
    auto it = std::ranges::find_if(zip, [](auto const& t) { return std::get<0>(t) == 50000; });
    benchmark::DoNotOptimize(it);
  }
}
BENCHMARK(BM_StdZipWithFind);

void BM_GstZipWithFind(benchmark::State& state)
{
      std::array<int, 100000>  a1;
      std::array<char, 100000> a2;
      std::ranges::generate(a1, [n = 0]() mutable { return n++; });
      std::ranges::generate(a2, [n = 0]() mutable { return static_cast<char>(n++); });
      auto zip = gst::ranges::views::zip(a1, a2);

  for (auto _ : state)
  {
    auto it = std::ranges::find_if(zip, [](auto const& t) { return std::get<0>(t) == 50000; });
    benchmark::DoNotOptimize(it);
  }
}
BENCHMARK(BM_GstZipWithFind);

} // namespace
