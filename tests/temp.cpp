#include "zip_view.hpp"

#include <algorithm>
#include <array>
#include <forward_list>
#include <iostream>
#include <list>
#include <memory>
#include <numeric>
#include <ranges>
#include <tuple>
#include <type_traits>
#include <utility>
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
      gst::ranges::views::zip(std::array<int, 3>{1, 2, 3}, std::list<char>{'a', 'b'});
    auto const std_zip =
      std::ranges::views::zip(std::array<int, 3>{1, 2, 3}, std::list<char>{'a', 'b'});

    THEN("emptiness matches std::ranges::zip_view") { REQUIRE(gst_zip.empty() == std_zip.empty()); }
    THEN("size matches std::ranges::zip_view") { REQUIRE(gst_zip.size() == std_zip.size()); }
    THEN("elements match std::ranges::zip_view")
    {
      auto const result = std::ranges::mismatch(gst_zip,
                                                std_zip,
                                                [](auto const& a, auto const& b) {
                                                  return std::get<0>(a) == std::get<0>(b) &&
                                                         std::get<1>(a) == std::get<1>(b);
                                                });
      REQUIRE(result.in1 == gst_zip.end());
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

SCENARIO("zip_view references lvalue containers", "[temporaries]")
{
  GIVEN("zip_view from lvalue containers")
  {
    std::vector<int> v = {1, 2, 3};
    std::list<char>  l = {'a', 'b', 'c'};

    auto gst_zip = gst::ranges::views::zip(v, l);

    WHEN("writing through the zip_view")
    {
      gst_zip[1] = std::make_tuple(42, 'd');

      THEN("original containers reflect changes")
      {
        REQUIRE(v[1] == 42);
        REQUIRE(*std::next(l.begin()) == 'd');
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
      gst::ranges::views::zip(std::array<int, 3>{1, 2, 3}, std::vector<char>{'a', 'b'});
    auto const std_zip =
      std::ranges::views::zip(std::array<int, 3>{1, 2, 3}, std::vector<char>{'a', 'b'});

    THEN("begin/end match std::ranges::zip_view")
    {
      auto const result = std::ranges::mismatch(gst_zip,
                                                std_zip,
                                                [](auto const& a, auto const& b) {
                                                  return std::get<0>(a) == std::get<0>(b) &&
                                                         std::get<1>(a) == std::get<1>(b);
                                                });
      REQUIRE(result.in1 == gst_zip.end());
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

SCENARIO("zip_view iterator category for random access ranges", "[temporaries]")
{
  GIVEN("two random access vectors as temporaries")
  {
    auto gst_zip = gst::ranges::views::zip(std::vector<int>{1, 2, 3, 4}, std::vector<int>{5, 6, 7});

    using It       = decltype(gst_zip.begin());
    using Category = typename std::iterator_traits<It>::iterator_category;

    THEN("iterator category is random_access")
    {
      STATIC_REQUIRE(std::is_same<Category, std::random_access_iterator_tag>::value);
    }

    THEN("random access operations work")
    {
      auto it = gst_zip.begin();
      REQUIRE(std::get<0>(it[0]) == 1);
      REQUIRE(std::get<1>(it[0]) == 5);
      REQUIRE(std::get<0>(it[2]) == 3);
      REQUIRE(std::get<1>(it[2]) == 7);

      auto it2 = it + 1;
      REQUIRE(std::get<0>(*it2) == 2);
      REQUIRE((gst_zip.end() - gst_zip.begin()) == static_cast<std::ptrdiff_t>(gst_zip.size()));
    }
  }
}

SCENARIO("zip_view iterator category for bidirectional ranges", "[temporaries]")
{
  GIVEN("vector and list as temporaries")
  {
    auto gst_zip = gst::ranges::views::zip(std::vector<int>{1, 2, 3}, std::list<char>{'a', 'b'});

    using It       = decltype(gst_zip.begin());
    using Category = typename std::iterator_traits<It>::iterator_category;

    THEN("iterator category is bidirectional")
    {
      STATIC_REQUIRE(std::is_same<Category, std::bidirectional_iterator_tag>::value);
    }

    THEN("bidirectional operations work")
    {
      auto it = gst_zip.begin();
      REQUIRE(std::get<0>(*it) == 1);
      ++it;
      REQUIRE(std::get<0>(*it) == 2);
      --it;
      REQUIRE(std::get<0>(*it) == 1);
    }
  }
}

SCENARIO("zip_view iterator category for forward ranges", "[temporaries]")
{
  GIVEN("vector and forward_list as temporaries")
  {
    auto gst_zip =
      gst::ranges::views::zip(std::vector<int>{1, 2, 3}, std::forward_list<char>{'a', 'b'});

    using It       = decltype(gst_zip.begin());
    using Category = typename std::iterator_traits<It>::iterator_category;

    THEN("iterator category is forward")
    {
      STATIC_REQUIRE(std::is_same<Category, std::forward_iterator_tag>::value);
    }

    THEN("forward iteration works")
    {
      auto it = gst_zip.begin();
      REQUIRE(std::get<0>(*it) == 1);
      ++it;
      REQUIRE(std::get<0>(*it) == 2);
    }

    THEN("not random access")
    {
      STATIC_REQUIRE(!std::is_same<Category, std::random_access_iterator_tag>::value);
    }
  }
}

SCENARIO("zip_view in range-based for loops", "[temporaries]")
{
  GIVEN("zip_view in range-based for loop")
  {
    THEN("can sum elements")
    {
      std::array<int, 2> sums = {0, 0};
      for (auto&& t : gst::ranges::views::zip({1, 2}, {'a', 'b', 'c'}))
      {
        sums[0] += std::get<0>(t);
        sums[1] += std::get<1>(t);
      }
      REQUIRE(sums == std::array<int, 2>{3, 195});
    }
  }
}

SCENARIO("zip_view with STL algorithms", "[temporaries]")
{
  GIVEN("zip_view as algorithm range")
  {
    THEN("for_each works")
    {
      int sum = 0;
      std::ranges::for_each(gst::ranges::views::zip({1, 2, 3}, {'a', 'b', 'c'}),
                            [&](auto const& t) { sum += std::get<0>(t) + std::get<1>(t); });
      REQUIRE(sum == (1 + 'a') + (2 + 'b') + (3 + 'c'));
    }

    THEN("all_of works")
    {
      auto const all_positive = std::ranges::all_of(
        gst::ranges::views::zip({1, 2, 3}, {'a', 'b', 'c'}),
        [](auto const& t) { return std::get<0>(t) > 0 && std::get<1>(t) != '\0'; });
      REQUIRE(all_positive);
    }

    THEN("fold_left works")
    {
      int dot = std::ranges::fold_left(gst::ranges::views::zip({1, 2, 3}, {'a', 'b', 'c'}),
                                       0,
                                       [](int acc, auto const& t)
                                       { return acc + (std::get<0>(t) * std::get<1>(t)); });
      REQUIRE(dot == (1 * 'a' + 2 * 'b' + 3 * 'c'));
    }

    THEN("transform works")
    {
      std::vector<int> out;
      std::ranges::transform(gst::ranges::views::zip({1, 2, 3}, {'a', 'b', 'c'}),
                             std::back_inserter(out),
                             [](auto const& t) { return std::get<0>(t) + std::get<1>(t); });
      REQUIRE(out == std::vector<int>{1 + 'a', 2 + 'b', 3 + 'c'});
    }
  }
}

SCENARIO("const zip_view preserves mutability for owned non-const storage", "[temporaries][const]")
{
  GIVEN("const zip_view from temporaries")
  {
    auto const std_zip = std::ranges::views::zip(std::array<int, 3>{1, 2, 3});
    auto const gst_zip = gst::ranges::views::zip(std::array<int, 3>{1, 2, 3});

    THEN("element reference types match std::ranges::zip_view")
    {
      using std_elem_ref_t = decltype(std::get<0>(std_zip[0]));
      using gst_elem_ref_t = decltype(std::get<0>(gst_zip[0]));
      STATIC_REQUIRE(std::is_lvalue_reference<gst_elem_ref_t>::value ==
                     std::is_lvalue_reference<std_elem_ref_t>::value);
      STATIC_REQUIRE(std::is_const<std::remove_reference_t<gst_elem_ref_t>>::value ==
                     std::is_const<std::remove_reference_t<std_elem_ref_t>>::value);
    }

    THEN("can mutate elements through const zip_view")
    {
      REQUIRE(std::get<0>(gst_zip[0]) == std::get<0>(std_zip[0]));
    }
  }
}
