#include "zip_view.hpp"

#include <algorithm>
#include <array>
#include <iterator>
#include <list>
#include <memory>
#include <ranges>
#include <tuple>
#include <vector>

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
#include <catch2/catch_test_macros.hpp>
#pragma clang diagnostic pop
#else
#include <catch2/catch_test_macros.hpp>
#endif

SCENARIO("zip_view with empty temporaries", "[temporaries]")
{
  GIVEN("zip_view from empty temporaries")
  {
    auto const gst_zip = gst::ranges::views::zip(std::array<int, 0>{}, std::list<char>{});
    auto const std_zip = std::ranges::views::zip(std::array<int, 0>{}, std::list<char>{});

    THEN("zip_view is empty") { REQUIRE(gst_zip.empty() == std_zip.empty()); }
    THEN("size is zero") { REQUIRE(gst_zip.size() == std_zip.size()); }
  }
}

SCENARIO("zip_view with non-empty temporaries", "[temporaries]")
{
  GIVEN("zip_view from temporaries")
  {
    auto const gst_zip =
      gst::ranges::views::zip(std::array<int, 3>{1, 2, 3}, std::list<char>{'a', 'b', 'c'});
    auto const std_zip =
      std::ranges::views::zip(std::array<int, 3>{1, 2, 3}, std::list<char>{'a', 'b', 'c'});

    THEN("emptiness matches std::ranges::zip_view") { REQUIRE(gst_zip.empty() == std_zip.empty()); }
    THEN("size matches std::ranges::zip_view") { REQUIRE(gst_zip.size() == std_zip.size()); }
    THEN("elements match std::ranges::zip_view")
    {
      auto gst_it = gst_zip.begin();
      auto std_it = std_zip.begin();
      for (; gst_it != gst_zip.end(); ++gst_it, ++std_it)
      {
        REQUIRE(std::get<0>(*gst_it) == std::get<0>(*std_it));
        REQUIRE(std::get<1>(*gst_it) == std::get<1>(*std_it));
      }
      REQUIRE(std_it == std_zip.end());
    }
  }
}

SCENARIO("zip_view owns temporaries data", "[temporaries]")
{
  GIVEN("zip_view from rvalue containers")
  {
    auto gst_zip =
      gst::ranges::views::zip(std::vector<int>{1, 2, 3}, std::vector<char>{'a', 'b', 'c'});

    WHEN("mutating values through the view")
    {
      for (auto&& t : gst_zip)
      {
        std::get<0>(t) += 10;
        std::get<1>(t)  = static_cast<char>(std::get<1>(t) - 'a' + 'A');
      }

      THEN("mutations are observable")
      {
        REQUIRE((gst_zip[0] == std::make_tuple(11, 'A')));
        REQUIRE((gst_zip[1] == std::make_tuple(12, 'B')));
        REQUIRE((gst_zip[2] == std::make_tuple(13, 'C')));
      }
    }
  }
}

SCENARIO("zip_view supports mixing lvalues and temporaries", "[temporaries]")
{
  GIVEN("zip_view mixing lvalue and temporary")
  {
    std::vector<int> v = {1, 2, 3, 4};

    auto gst_zip = gst::ranges::views::zip(v, std::list<char>{'x', 'y'});

    THEN("size matches shortest range") { REQUIRE(gst_zip.size() == 2); }

    THEN("writing to first component updates lvalue")
    {
      std::get<0>(gst_zip.front()) = 9;
      REQUIRE(v[0] == 9);
    }

    THEN("second component from owned temporary")
    {
      REQUIRE(std::get<1>(gst_zip.front()) == 'x');
      REQUIRE(std::get<1>(gst_zip.back()) == 'y');
    }
  }
}

SCENARIO("const zip_view from temporaries matches std", "[temporaries]")
{
  GIVEN("const zip_view from temporaries")
  {
    auto const gst_zip =
      gst::ranges::views::zip(std::array<int, 3>{1, 2, 3}, std::vector<char>{'a', 'b', 'c'});
    auto const std_zip =
      std::ranges::views::zip(std::array<int, 3>{1, 2, 3}, std::vector<char>{'a', 'b', 'c'});

    THEN("elements match std::ranges::zip_view")
    {
      auto gst_it = gst_zip.begin();
      auto std_it = std_zip.begin();
      for (; gst_it != gst_zip.end(); ++gst_it, ++std_it)
      {
        REQUIRE(std::get<0>(*gst_it) == std::get<0>(*std_it));
        REQUIRE(std::get<1>(*gst_it) == std::get<1>(*std_it));
      }
      REQUIRE(std_it == std_zip.end());
    }
  }
}

SCENARIO("zip_view with move-only temporaries", "[temporaries]")
{
  GIVEN("zip_view with unique_ptr vector and rvalue list")
  {
    std::vector<std::unique_ptr<int>> vp;
    vp.emplace_back(std::make_unique<int>(1));
    vp.emplace_back(std::make_unique<int>(2));

    auto gst_zip = gst::ranges::views::zip(std::move(vp), std::list<char>{'a', 'b', 'c'});

    THEN("size matches shortest range") { REQUIRE(gst_zip.size() == 2); }

    THEN("access pointed-to values")
    {
      REQUIRE(*std::get<0>(gst_zip[0]) == 1);
      REQUIRE(std::get<1>(gst_zip[0]) == 'a');
      REQUIRE(*std::get<0>(gst_zip[1]) == 2);
      REQUIRE(std::get<1>(gst_zip[1]) == 'b');
    }
  }
}

SCENARIO("zip_view inline usage in range-based for loops", "[temporaries]")
{
  GIVEN("temporary zip_view with temporary containers in range-based for loop")
  {
    THEN("can iterate and sum elements")
    {
      std::array<int, 2> sums = {0, 0};
      for (auto&& t :
           gst::ranges::views::zip(std::array<int, 2>{1, 2}, std::array<char, 3>{'a', 'b', 'c'}))
      {
        sums[0] += std::get<0>(t);
        sums[1] += std::get<1>(t);
      }
      REQUIRE(sums == std::array<int, 2>{3, 195});
    }
  }
}

SCENARIO("zip_view inline usage with STL algorithms", "[temporaries]")
{
  GIVEN("temporary zip_view with temporary containers passed to algorithms")
  {
    THEN("for_each works with inline temporary zip_view")
    {
      int sum = 0;
      std::ranges::for_each(
        gst::ranges::views::zip(std::array<int, 3>{1, 2, 3}, std::array<char, 3>{'a', 'b', 'c'}),
        [&](auto const& t) { sum += std::get<0>(t) + std::get<1>(t); });
      REQUIRE(sum == (1 + 'a') + (2 + 'b') + (3 + 'c'));
    }

    THEN("transform works with inline temporary zip_view")
    {
      std::vector<int> out;
      std::ranges::transform(
        gst::ranges::views::zip(std::array<int, 3>{1, 2, 3}, std::array<char, 3>{'a', 'b', 'c'}),
        std::back_inserter(out),
        [](auto const& t) { return std::get<0>(t) + std::get<1>(t); });
      REQUIRE(out == std::vector<int>{1 + 'a', 2 + 'b', 3 + 'c'});
    }

    THEN("fold_left works with inline temporary zip_view")
    {
      int dot = std::ranges::fold_left(
        gst::ranges::views::zip(std::array<int, 3>{1, 2, 3}, std::array<char, 3>{'a', 'b', 'c'}),
        0,
        [](int acc, auto const& t) { return acc + (std::get<0>(t) * std::get<1>(t)); });
      REQUIRE(dot == (1 * 'a' + 2 * 'b' + 3 * 'c'));
    }
  }
}
