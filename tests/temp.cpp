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
    auto const gst_zip = gst::ranges::views::zip(std::array<int, 3>{1, 2, 3},
                                                 std::list<char>{'a', 'b', 'c'},
                                                 std::vector<float>{1.1F, 2.2F, 3.3F});
    auto const std_zip = std::ranges::views::zip(std::array<int, 3>{1, 2, 3},
                                                 std::list<char>{'a', 'b', 'c'},
                                                 std::vector<float>{1.1F, 2.2F, 3.3F});

    THEN("emptiness matches std::ranges::zip_view") { REQUIRE(gst_zip.empty() == std_zip.empty()); }
    THEN("size matches std::ranges::zip_view") { REQUIRE(gst_zip.size() == std_zip.size()); }
    THEN("elements match std::ranges::zip_view")
    {
      auto gst_it = gst_zip.begin();
      auto std_it = std_zip.begin();
      for (; gst_it != gst_zip.end(); ++gst_it, ++std_it) { REQUIRE((*gst_it == *std_it)); }
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
    auto const gst_zip = gst::ranges::views::zip(std::array<int, 3>{1, 2, 3},
                                                 std::vector<char>{'a', 'b', 'c'},
                                                 std::list<double>{1.1, 2.2, 3.3});
    auto const std_zip = std::ranges::views::zip(std::array<int, 3>{1, 2, 3},
                                                 std::vector<char>{'a', 'b', 'c'},
                                                 std::list<double>{1.1, 2.2, 3.3});

    THEN("elements match std::ranges::zip_view")
    {
      auto gst_it = gst_zip.begin();
      auto std_it = std_zip.begin();
      for (; gst_it != gst_zip.end(); ++gst_it, ++std_it) { REQUIRE((*gst_it == *std_it)); }
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

SCENARIO("Testing nested zip_views with temporaries", "[zip_view][nested][temp]")
{
  {
    WHEN("Zipping temporary zip_views directly")
    {
      std::vector<int> v1 = {1, 2, 3};
      std::vector<int> v2 = {4, 5, 6};
      std::vector<int> v3 = {7, 8, 9};
      std::vector<int> v4 = {10, 11, 12};

      auto nested =
        gst::ranges::views::zip(gst::ranges::views::zip(v1, v2), gst::ranges::views::zip(v3, v4));

      THEN("Nested temporary zip_view has correct size") { REQUIRE(nested.size() == 3); }

      THEN("Can dereference and access elements")
      {
        auto it   = nested.begin();
        auto elem = *it;
        auto t0   = std::get<0>(elem);
        auto t1   = std::get<1>(elem);
        REQUIRE(std::get<0>(t0) == 1);
        REQUIRE(std::get<1>(t0) == 4);
        REQUIRE(std::get<0>(t1) == 7);
        REQUIRE(std::get<1>(t1) == 10);
      }

      THEN("Can iterate through all elements")
      {
        int count = 0;
        for (auto it = nested.begin(); it != nested.end(); ++it) { ++count; }
        REQUIRE(count == 3);
      }
    }

    WHEN("Zipping mix of temporary and stored zip_views")
    {
      std::vector<int>  v1 = {1, 2, 3};
      std::vector<int>  v2 = {4, 5, 6};
      std::vector<char> v3 = {'a', 'b', 'c'};
      std::vector<char> v4 = {'x', 'y', 'z'};

      auto zip1 = gst::ranges::views::zip(v1, v2);

      auto mixed = gst::ranges::views::zip(zip1, gst::ranges::views::zip(v3, v4));

      THEN("Mixed temporary structure has correct size") { REQUIRE(mixed.size() == 3); }

      THEN("Can access elements from both stored and temporary zip_views")
      {
        auto it     = mixed.begin();
        auto elem   = *it;
        auto tuple0 = std::get<0>(elem);
        auto tuple1 = std::get<1>(elem);
        REQUIRE(std::get<0>(tuple0) == 1);
        REQUIRE(std::get<1>(tuple0) == 4);
        REQUIRE(std::get<0>(tuple1) == 'a');
        REQUIRE(std::get<1>(tuple1) == 'x');
      }
    }

    WHEN("Creating deeply nested temporary zip_views")
    {
      std::vector<int> v1 = {1, 2};
      std::vector<int> v2 = {3, 4};
      std::vector<int> v3 = {5, 6};
      std::vector<int> v4 = {7, 8};
      std::vector<int> v5 = {9, 10};

      auto deep = gst::ranges::views::zip(
        gst::ranges::views::zip(gst::ranges::views::zip(v1, v2), gst::ranges::views::zip(v3, v4)),
        v5);

      THEN("Deep nesting with temporaries has correct size") { REQUIRE(deep.size() == 2); }

      THEN("Can iterate through deeply nested temporaries")
      {
        int count = 0;
        for (auto it = deep.begin(); it != deep.end(); ++it) { ++count; }
        REQUIRE(count == 2);
      }

      THEN("Can access deeply nested elements")
      {
        auto it      = deep.begin();
        auto elem    = *it;
        auto nested1 = std::get<0>(elem);
        auto nested2 = std::get<0>(nested1);
        auto nested3 = std::get<1>(nested1);
        auto regular = std::get<1>(elem);

        REQUIRE(std::get<0>(nested2) == 1);
        REQUIRE(std::get<1>(nested2) == 3);
        REQUIRE(std::get<0>(nested3) == 5);
        REQUIRE(std::get<1>(nested3) == 7);
        REQUIRE(regular == 9);
      }
    }

    WHEN("Zipping temporary containers through temporary zip_views")
    {
      auto nested = gst::ranges::views::zip(
        gst::ranges::views::zip(std::vector<int>{1, 2, 3}, std::vector<int>{4, 5, 6}),
        gst::ranges::views::zip(std::vector<char>{'a', 'b', 'c'},
                                std::vector<char>{'x', 'y', 'z'}));

      THEN("Temporary containers in temporary zip_views work") { REQUIRE(nested.size() == 3); }

      THEN("Can iterate with temporary containers")
      {
        int count = 0;
        for (auto it = nested.begin(); it != nested.end(); ++it) { ++count; }
        REQUIRE(count == 3);
      }

      THEN("Can dereference and access temporary container elements")
      {
        auto it   = nested.begin();
        auto elem = *it;
        auto t0   = std::get<0>(elem);
        auto t1   = std::get<1>(elem);
        REQUIRE(std::get<0>(t0) == 1);
        REQUIRE(std::get<1>(t0) == 4);
        REQUIRE(std::get<0>(t1) == 'a');
        REQUIRE(std::get<1>(t1) == 'x');
      }
    }

    WHEN("Using subscript operator with temporary nested zip_views")
    {
      std::vector<int> v1 = {10, 20, 30};
      std::vector<int> v2 = {40, 50, 60};
      std::vector<int> v3 = {70, 80, 90};

      auto nested =
        gst::ranges::views::zip(gst::ranges::views::zip(v1, v2), gst::ranges::views::zip(v2, v3));

      THEN("Subscript operator works with temporary nested zip_views")
      {
        auto elem = nested[1];
        auto t0   = std::get<0>(elem);
        auto t1   = std::get<1>(elem);
        REQUIRE(std::get<0>(t0) == 20);
        REQUIRE(std::get<1>(t0) == 50);
        REQUIRE(std::get<0>(t1) == 50);
        REQUIRE(std::get<1>(t1) == 80);
      }

      THEN("front() and back() work with temporaries")
      {
        auto front = nested.front();
        auto back  = nested.back();

        auto front_t0 = std::get<0>(front);
        REQUIRE(std::get<0>(front_t0) == 10);

        auto back_t1 = std::get<1>(back);
        REQUIRE(std::get<1>(back_t1) == 90);
      }
    }

    WHEN("Modifying through temporary nested zip_views")
    {
      std::vector<int> v1 = {1, 2, 3};
      std::vector<int> v2 = {4, 5, 6};
      std::vector<int> v3 = {7, 8, 9};

      auto nested = gst::ranges::views::zip(gst::ranges::views::zip(v1, v2), v3);

      THEN("Can modify underlying containers through temporary zip_view")
      {
        auto it           = nested.begin();
        auto elem         = *it;
        std::get<1>(elem) = 99;
        REQUIRE(v3[0] == 99);

        auto nested_tuple         = std::get<0>(elem);
        std::get<0>(nested_tuple) = 88;
        REQUIRE(v1[0] == 88);
      }
    }

    WHEN("Comparing temporary nested zip_views with std::ranges::zip_view")
    {
      std::vector<int> v1 = {1, 2, 3};
      std::vector<int> v2 = {4, 5, 6};
      std::vector<int> v3 = {7, 8, 9};
      std::vector<int> v4 = {10, 11, 12};

      auto gst_nested = gst::ranges::views::zip(gst::ranges::views::zip(v1, v2, v3),
                                                gst::ranges::views::zip(v2, v3, v4),
                                                gst::ranges::views::zip(v3, v4, v1));
      auto std_nested = std::ranges::views::zip(std::ranges::views::zip(v1, v2, v3),
                                                std::ranges::views::zip(v2, v3, v4),
                                                std::ranges::views::zip(v3, v4, v1));

      THEN("Temporary nested structures match std behavior")
      {
        REQUIRE(gst_nested.size() == std_nested.size());
        REQUIRE(gst_nested.empty() == std_nested.empty());

        auto gst_it = gst_nested.begin();
        auto std_it = std_nested.begin();

        int count = 0;
        while (gst_it != gst_nested.end() && std_it != std_nested.end())
        {
          auto gst_elem = *gst_it;
          auto std_elem = *std_it;
          REQUIRE((gst_elem == std_elem));
          ++gst_it;
          ++std_it;
          ++count;
        }
        REQUIRE(count == 3);
      }
    }

    WHEN("Using range-based for loop with temporary nested zip_views")
    {
      std::vector<int> v1 = {1, 2, 3};
      std::vector<int> v2 = {4, 5, 6};
      std::vector<int> v3 = {7, 8, 9};

      THEN("Can iterate with range-based for on temporary nested zip_views")
      {
        auto nested =
          gst::ranges::views::zip(gst::ranges::views::zip(v1, v2), gst::ranges::views::zip(v2, v3));
        int count = 0;
        for (auto elem : nested)
        {
          (void)elem;
          ++count;
        }
        REQUIRE(count == 3);
      }

      THEN("Can modify through range-based for on temporary nested zip_views")
      {
        auto nested = gst::ranges::views::zip(gst::ranges::views::zip(v1, v2), v3);

        for (auto&& elem : nested)
        {
          auto nested_tuple          = std::get<0>(elem);
          std::get<0>(nested_tuple) *= 2;
          std::get<1>(elem)         += 100;
        }

        REQUIRE(v1 == std::vector<int>{2, 4, 6});
        REQUIRE(v3 == std::vector<int>{107, 108, 109});
      }
    }

    WHEN("Using range-based for loop with stored nested zip_views")
    {
      std::vector<int> v1 = {10, 20, 30};
      std::vector<int> v2 = {40, 50, 60};
      std::vector<int> v3 = {70, 80, 90};
      std::vector<int> v4 = {100, 110, 120};

      auto zip1   = gst::ranges::views::zip(v1, v2);
      auto zip2   = gst::ranges::views::zip(v3, v4);
      auto nested = gst::ranges::views::zip(zip1, zip2);

      THEN("Can iterate with range-based for on stored nested zip_views")
      {
        int count = 0;
        int sum   = 0;
        for (auto elem : nested)
        {
          auto t0  = std::get<0>(elem);
          sum     += std::get<0>(t0);
          ++count;
        }
        REQUIRE(count == 3);
        REQUIRE(sum == 60); // 10 + 20 + 30
      }

      THEN("Can modify through range-based for on stored nested zip_views")
      {
        for (auto&& elem : nested)
        {
          auto t0          = std::get<0>(elem);
          auto t1          = std::get<1>(elem);
          std::get<0>(t0) += 5;
          std::get<1>(t1) += 10;
        }

        REQUIRE(v1 == std::vector<int>{15, 25, 35});
        REQUIRE(v4 == std::vector<int>{110, 120, 130});
      }
    }
  }
}
