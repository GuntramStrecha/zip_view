#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
#endif
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_test_macros.hpp>
#ifdef __clang__
#pragma clang diagnostic pop
#endif

#include "zip_view.hpp"

#include <algorithm>
#include <numeric>
#include <ranges>
#include <string>
#include <tuple>
#include <vector>

namespace
{
// Small helper to create a non-trivial temporary.
// Returning by value ensures we exercise the "in-place temporary" case when used inside
// views::zip(...).
std::vector<int> make_iota_vec(std::size_t n, int start)
{
  std::vector<int> v(n);
  std::iota(v.begin(), v.end(), start);
  return v;
}
} // namespace

TEST_CASE("Benchmark ZipView In-place Temporary In Loop", "[temp][loop]")
{
  constexpr std::size_t N = 1'000'000;

  BENCHMARK("std zip loop with temporary")
  {
    long long sum = 0;
    for (auto t : std::ranges::views::zip(make_iota_vec(N, 0))) { sum += std::get<0>(t); }
    return sum;
  };

  BENCHMARK("gst zip loop with temporary")
  {
    long long sum = 0;
    for (auto t : gst::ranges::views::zip(make_iota_vec(N, 0))) { sum += std::get<0>(t); }
    return sum;
  };
}

TEST_CASE("Benchmark ZipView In-place Temporaries Multiple Ranges In Loop", "[temp][loop]")
{
  constexpr std::size_t N = 250'000;

  BENCHMARK("std zip loop 2 temporaries")
  {
    long long sum = 0;
    for (auto t : std::ranges::views::zip(make_iota_vec(N, 0), make_iota_vec(N, 1)))
    {
      sum += std::get<0>(t) + std::get<1>(t);
    }
    return sum;
  };

  BENCHMARK("gst zip loop 2 temporaries")
  {
    long long sum = 0;
    for (auto t : gst::ranges::views::zip(make_iota_vec(N, 0), make_iota_vec(N, 1)))
    {
      sum += std::get<0>(t) + std::get<1>(t);
    }
    return sum;
  };
}

TEST_CASE("Benchmark ZipView In-place Temporary With std::ranges Algorithms", "[temp][algo]")
{
  constexpr std::size_t N = 1'000'000;

  BENCHMARK("std zip + ranges::for_each (temporary)")
  {
    long long sum = 0;
    std::ranges::for_each(std::ranges::views::zip(make_iota_vec(N, 0)),
                          [&](auto t) { sum += std::get<0>(t); });
    return sum;
  };

  BENCHMARK("gst zip + ranges::for_each (temporary)")
  {
    long long sum = 0;
    std::ranges::for_each(gst::ranges::views::zip(make_iota_vec(N, 0)),
                          [&](auto t) { sum += std::get<0>(t); });
    return sum;
  };

  BENCHMARK("std zip + ranges::fold_left (temporary)")
  {
    return std::ranges::fold_left(std::ranges::views::zip(make_iota_vec(N, 0)),
                                  0LL,
                                  [](long long acc, auto t) { return acc + std::get<0>(t); });
  };

  BENCHMARK("gst zip + ranges::fold_left (temporary)")
  {
    return std::ranges::fold_left(gst::ranges::views::zip(make_iota_vec(N, 0)),
                                  0LL,
                                  [](long long acc, auto t) { return acc + std::get<0>(t); });
  };

  BENCHMARK("std zip + ranges::count_if (temporary)")
  {
    return std::ranges::count_if(std::ranges::views::zip(make_iota_vec(N, 0)),
                                 [](auto t) { return (std::get<0>(t) & 1) == 0; });
  };

  BENCHMARK("gst zip + ranges::count_if (temporary)")
  {
    return std::ranges::count_if(gst::ranges::views::zip(make_iota_vec(N, 0)),
                                 [](auto t) { return (std::get<0>(t) & 1) == 0; });
  };
}

TEST_CASE("Benchmark ZipView Temporary + ranges::copy", "[temp][algo]")
{
  constexpr std::size_t N = 500'000;

  BENCHMARK("std zip + ranges::copy (temporary)")
  {
    auto             r = std::ranges::views::zip(make_iota_vec(N, 0));
    std::vector<int> out(N);
    auto             out_zip = gst::ranges::views::zip(out);

    std::ranges::copy(r.begin(), r.end(), out_zip.begin());
    return out;
  };

  BENCHMARK("gst zip + ranges::copy (temporary)")
  {
    auto             r = gst::ranges::views::zip(make_iota_vec(N, 0));
    std::vector<int> out(N);
    auto             out_zip = gst::ranges::views::zip(out);

    std::ranges::copy(r.begin(), r.end(), out_zip.begin());
    return out;
  };
}
