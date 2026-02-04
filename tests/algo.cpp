#include "zip_view.hpp"

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
#include <catch2/catch_test_macros.hpp>
#pragma clang diagnostic pop
#else
#include <catch2/catch_test_macros.hpp>
#endif
#include <catch2/catch_approx.hpp>

#include <algorithm>
#include <array>
#include <functional>
#include <list>
#include <numeric>
#include <set>
#include <string>
#include <vector>

using namespace std::string_literals;

SCENARIO("std::adjacent_find works on zip_view", "[algorithms][find]")
{
  GIVEN("Three vectors with adjacent duplicates")
  {
    std::vector<int>    v1{1, 2, 3, 3, 5};
    std::vector<double> v2{1.1, 2.2, 3.3, 3.4, 5.5};
    std::vector<char>   v3{'a', 'b', 'c', 'd', 'e'};

    WHEN("we search for adjacent elements with same first component")
    {
      auto zipped = gst::ranges::views::zip(v1, v2, v3);
      auto it     = std::adjacent_find(zipped.begin(),
                                   zipped.end(),
                                   [](auto const& a, auto const& b)
                                   { return std::get<0>(a) == std::get<0>(b); });

      THEN("we find the first adjacent pair")
      {
        REQUIRE(it != zipped.end());
        REQUIRE(std::get<0>(*it) == 3);
        REQUIRE(std::get<1>(*it) == Catch::Approx(3.3));
        REQUIRE(std::get<2>(*it) == 'c');
      }
    }
  }
}

SCENARIO("std::all_of, std::any_of, std::none_of work on zip_view", "[algorithms][predicates]")
{
  GIVEN("Three vectors")
  {
    std::vector<int>  v1{2, 4, 6, 8};
    std::vector<int>  v2{1, 1, 1, 1};
    std::vector<char> v3{'a', 'b', 'c', 'd'};

    auto zipped = gst::ranges::views::zip(v1, v2, v3);

    THEN("all_of returns true when all elements satisfy the predicate")
    {
      bool result = std::all_of(
        zipped.begin(), zipped.end(), [](auto const& t) { return std::get<0>(t) % 2 == 0; });
      REQUIRE(result == true);
    }

    THEN("any_of returns true when at least one element satisfies the predicate")
    {
      bool result =
        std::any_of(zipped.begin(), zipped.end(), [](auto const& t) { return std::get<0>(t) > 6; });
      REQUIRE(result == true);
    }

    THEN("none_of returns true when no elements satisfy the predicate")
    {
      bool result = std::none_of(
        zipped.begin(), zipped.end(), [](auto const& t) { return std::get<0>(t) > 10; });
      REQUIRE(result == true);
    }
  }
}

SCENARIO("std::binary_search works on sorted zip_view", "[algorithms][binary_search]")
{
  GIVEN("Sorted vectors")
  {
    std::vector<int>    v1{1, 2, 3, 4, 5};
    std::vector<double> v2{1.1, 2.2, 3.3, 4.4, 5.5};
    std::vector<char>   v3{'a', 'b', 'c', 'd', 'e'};

    auto zipped = gst::ranges::views::zip(v1, v2, v3);

    THEN("binary_search finds existing elements")
    {
      bool found = std::binary_search(zipped.begin(),
                                      zipped.end(),
                                      std::make_tuple(3, 0.0, '\0'),
                                      [](auto const& a, auto const& b)
                                      { return std::get<0>(a) < std::get<0>(b); });
      REQUIRE(found == true);
    }

    THEN("binary_search doesn't find non-existing elements")
    {
      bool found = std::binary_search(zipped.begin(),
                                      zipped.end(),
                                      std::make_tuple(6, 0.0, '\0'),
                                      [](auto const& a, auto const& b)
                                      { return std::get<0>(a) < std::get<0>(b); });
      REQUIRE(found == false);
    }
  }
}

SCENARIO("std::copy_if works with zip_view", "[algorithms][copy]")
{
  GIVEN("Three vectors")
  {
    std::vector<int>    v1{1, 2, 3, 4, 5, 6};
    std::vector<double> v2{1.1, 2.2, 3.3, 4.4, 5.5, 6.6};
    std::vector<char>   v3{'a', 'b', 'c', 'd', 'e', 'f'};

    WHEN("we copy only even elements")
    {
      std::vector<int>    dest_v1(3);
      std::vector<double> dest_v2(3);
      std::vector<char>   dest_v3(3);

      auto zipped      = gst::ranges::views::zip(v1, v2, v3);
      auto dest_zipped = gst::ranges::views::zip(dest_v1, dest_v2, dest_v3);

      auto dest_end = std::copy_if(zipped.begin(),
                                   zipped.end(),
                                   dest_zipped.begin(),
                                   [](auto const& t) { return std::get<0>(t) % 2 == 0; });

      THEN("only tuples with even v1 values are copied")
      {
        REQUIRE(dest_v1 == std::vector<int>{2, 4, 6});
        REQUIRE(dest_v2 == std::vector<double>{2.2, 4.4, 6.6});
        REQUIRE(dest_v3 == std::vector<char>{'b', 'd', 'f'});
        REQUIRE(std::distance(dest_zipped.begin(), dest_end) == 3);
      }
    }
  }
}

SCENARIO("std::equal works with zip_view", "[algorithms][equal]")
{
  GIVEN("Two pairs of vectors")
  {
    std::vector<int>  v1a{1, 2, 3, 4, 5};
    std::vector<char> v2a{'a', 'b', 'c', 'd', 'e'};

    std::vector<int>  v1b{1, 2, 3, 4, 5};
    std::vector<char> v2b{'a', 'b', 'c', 'd', 'e'};

    std::vector<int>  v1c{1, 2, 3, 4, 6};
    std::vector<char> v2c{'a', 'b', 'c', 'd', 'f'};

    THEN("equal returns true for identical zipped ranges")
    {
      auto zip_a  = gst::ranges::views::zip(v1a, v2a);
      auto zip_b  = gst::ranges::views::zip(v1b, v2b);
      bool result = std::equal(zip_a.begin(), zip_a.end(), zip_b.begin());
      REQUIRE(result == true);
    }

    THEN("equal returns false for different zipped ranges")
    {
      auto zip_a  = gst::ranges::views::zip(v1a, v2a);
      auto zip_c  = gst::ranges::views::zip(v1c, v2c);
      bool result = std::equal(zip_a.begin(), zip_a.end(), zip_c.begin());
      REQUIRE(result == false);
    }
  }
}

SCENARIO("std::find works on zip_view", "[algorithms][find]")
{
  GIVEN("Three vectors")
  {
    std::vector<int>    v1{1, 2, 3, 4, 5};
    std::vector<double> v2{1.1, 2.2, 3.3, 4.4, 5.5};
    std::vector<char>   v3{'a', 'b', 'c', 'd', 'e'};

    WHEN("we search for a specific tuple")
    {
      auto zipped = gst::ranges::views::zip(v1, v2, v3);
      auto it     = std::find(zipped.begin(), zipped.end(), std::make_tuple(3, 3.3, 'c'));

      THEN("we find the tuple")
      {
        REQUIRE(it != zipped.end());
        REQUIRE(std::get<0>(*it) == 3);
        REQUIRE(std::get<1>(*it) == Catch::Approx(3.3));
        REQUIRE(std::get<2>(*it) == 'c');
      }
    }
  }
}

SCENARIO("std::find_if works on zip_view", "[algorithms][find]")
{
  GIVEN("Three vectors")
  {
    std::vector<int>         v1{1, 2, 3, 4, 5};
    std::vector<std::string> v2{"one", "two", "three", "four", "five"};
    std::vector<double>      v3{1.1, 2.2, 3.3, 4.4, 5.5};

    WHEN("we search for an element where v1 is even")
    {
      auto zipped = gst::ranges::views::zip(v1, v2, v3);
      auto it     = std::find_if(
        zipped.begin(), zipped.end(), [](auto const& t) { return std::get<0>(t) % 2 == 0; });

      THEN("we find the first even element")
      {
        REQUIRE(it != zipped.end());
        REQUIRE(std::get<0>(*it) == 2);
        REQUIRE(std::get<1>(*it) == "two");
        REQUIRE(std::get<2>(*it) == Catch::Approx(2.2));
      }
    }
  }
}

SCENARIO("std::find_if_not works on zip_view", "[algorithms][find]")
{
  GIVEN("Three vectors")
  {
    std::vector<int>    v1{2, 4, 6, 7, 8};
    std::vector<double> v2{2.2, 4.4, 6.6, 7.7, 8.8};
    std::vector<char>   v3{'b', 'd', 'f', 'g', 'h'};

    WHEN("we search for the first element that is not even")
    {
      auto zipped = gst::ranges::views::zip(v1, v2, v3);
      auto it     = std::find_if_not(
        zipped.begin(), zipped.end(), [](auto const& t) { return std::get<0>(t) % 2 == 0; });

      THEN("we find the first odd element")
      {
        REQUIRE(it != zipped.end());
        REQUIRE(std::get<0>(*it) == 7);
        REQUIRE(std::get<1>(*it) == Catch::Approx(7.7));
        REQUIRE(std::get<2>(*it) == 'g');
      }
    }
  }
}

SCENARIO("std::is_sorted works on zip_view", "[algorithms][sorted]")
{
  GIVEN("Sorted and unsorted vectors")
  {
    std::vector<int>    sorted_v1{1, 2, 3, 4, 5};
    std::vector<double> sorted_v2{1.1, 2.2, 3.3, 4.4, 5.5};

    std::vector<int>    unsorted_v1{3, 1, 4, 2, 5};
    std::vector<double> unsorted_v2{3.3, 1.1, 4.4, 2.2, 5.5};

    THEN("is_sorted returns true for sorted zip_view")
    {
      auto sorted_zip = gst::ranges::views::zip(sorted_v1, sorted_v2);
      bool result     = std::is_sorted(sorted_zip.begin(),
                                   sorted_zip.end(),
                                   [](auto const& a, auto const& b)
                                   { return std::get<0>(a) < std::get<0>(b); });
      REQUIRE(result == true);
    }

    THEN("is_sorted returns false for unsorted zip_view")
    {
      auto unsorted_zip = gst::ranges::views::zip(unsorted_v1, unsorted_v2);
      bool result       = std::is_sorted(unsorted_zip.begin(),
                                   unsorted_zip.end(),
                                   [](auto const& a, auto const& b)
                                   { return std::get<0>(a) < std::get<0>(b); });
      REQUIRE(result == false);
    }
  }
}

SCENARIO("std::lexicographical_compare works with zip_view", "[algorithms][compare]")
{
  GIVEN("Two pairs of vectors")
  {
    std::vector<int>  v1a{1, 2, 3};
    std::vector<char> v2a{'a', 'b', 'c'};

    std::vector<int>  v1b{1, 2, 4};
    std::vector<char> v2b{'a', 'b', 'd'};

    WHEN("we compare them lexicographically")
    {
      auto zip_a = gst::ranges::views::zip(v1a, v2a);
      auto zip_b = gst::ranges::views::zip(v1b, v2b);

      bool result =
        std::lexicographical_compare(zip_a.begin(), zip_a.end(), zip_b.begin(), zip_b.end());

      THEN("the first sequence is less than the second") { REQUIRE(result == true); }
    }
  }
}

SCENARIO("std::mismatch works with zip_view", "[algorithms][mismatch]")
{
  GIVEN("Two pairs of vectors with a difference")
  {
    std::vector<int>  v1a{1, 2, 3, 4, 5};
    std::vector<char> v2a{'a', 'b', 'c', 'd', 'e'};

    std::vector<int>  v1b{1, 2, 9, 4, 5};
    std::vector<char> v2b{'a', 'b', 'c', 'd', 'e'};

    WHEN("we find the first mismatch")
    {
      auto zip_a  = gst::ranges::views::zip(v1a, v2a);
      auto zip_b  = gst::ranges::views::zip(v1b, v2b);
      auto result = std::mismatch(zip_a.begin(),
                                  zip_a.end(),
                                  zip_b.begin(),
                                  [](auto const& a, auto const& b) {
                                    return (std::get<0>(a) == std::get<0>(b)) &&
                                           (std::get<1>(a) == std::get<1>(b));
                                  });

      THEN("we find the mismatch at position 2")
      {
        REQUIRE(result.first != zip_a.end());
        REQUIRE(std::get<0>(*result.first) == 3);
        REQUIRE(std::get<0>(*result.second) == 9);
      }
    }
  }
}

SCENARIO("std::replace works on zip_view", "[algorithms][replace]")
{
  GIVEN("Three vectors")
  {
    std::vector<int>    v1{1, 2, 3, 2, 5};
    std::vector<double> v2{1.1, 2.2, 3.3, 2.2, 5.5};
    std::vector<char>   v3{'a', 'b', 'c', 'd', 'e'};

    WHEN("we replace specific tuples")
    {
      auto zipped = gst::ranges::views::zip(v1, v2, v3);
      std::replace(
        zipped.begin(), zipped.end(), std::make_tuple(2, 2.2, 'b'), std::make_tuple(9, 9.9, 'z'));

      THEN("the matching tuple is replaced")
      {
        REQUIRE(v1 == std::vector<int>{1, 9, 3, 2, 5});
        REQUIRE(v2 == std::vector<double>{1.1, 9.9, 3.3, 2.2, 5.5});
        REQUIRE(v3 == std::vector<char>{'a', 'z', 'c', 'd', 'e'});
      }
    }
  }
}

SCENARIO("std::replace_if works on zip_view", "[algorithms][replace]")
{
  GIVEN("Three vectors")
  {
    std::vector<int>    v1{1, 2, 3, 4, 5};
    std::vector<double> v2{1.1, 2.2, 3.3, 4.4, 5.5};
    std::vector<char>   v3{'a', 'b', 'c', 'd', 'e'};

    WHEN("we replace elements where v1 is even")
    {
      auto zipped = gst::ranges::views::zip(v1, v2, v3);
      std::replace_if(
        zipped.begin(),
        zipped.end(),
        [](auto const& t) { return std::get<0>(t) % 2 == 0; },
        std::make_tuple(0, 0.0, 'X'));

      THEN("tuples with even v1 values are replaced")
      {
        REQUIRE(v1 == std::vector<int>{1, 0, 3, 0, 5});
        REQUIRE(v2 == std::vector<double>{1.1, 0.0, 3.3, 0.0, 5.5});
        REQUIRE(v3 == std::vector<char>{'a', 'X', 'c', 'X', 'e'});
      }
    }
  }
}

SCENARIO("std::reverse works on random access zip_view", "[algorithms][reverse]")
{
  GIVEN("Three vectors")
  {
    std::vector<int>         v1{1, 2, 3, 4, 5};
    std::vector<std::string> v2{"one", "two", "three", "four", "five"};
    std::array<char, 5>      v3{'a', 'b', 'c', 'd', 'e'};

    WHEN("we reverse the zip_view")
    {
      auto zipped = gst::ranges::views::zip(v1, v2, v3);
      std::reverse(zipped.begin(), zipped.end());

      THEN("all containers are reversed")
      {
        REQUIRE(v1 == std::vector<int>{5, 4, 3, 2, 1});
        REQUIRE(v2 == std::vector<std::string>{"five", "four", "three", "two", "one"});
        REQUIRE(v3 == std::array<char, 5>{'e', 'd', 'c', 'b', 'a'});
      }
    }
  }
}

SCENARIO("std::reverse_copy works on zip_view", "[algorithms][reverse]")
{
  GIVEN("Three vectors")
  {
    std::vector<int>    v1{1, 2, 3, 4, 5};
    std::vector<double> v2{1.1, 2.2, 3.3, 4.4, 5.5};
    std::vector<char>   v3{'a', 'b', 'c', 'd', 'e'};

    WHEN("we copy in reverse")
    {
      std::vector<int>    dest_v1(5);
      std::vector<double> dest_v2(5);
      std::vector<char>   dest_v3(5);

      auto zipped      = gst::ranges::views::zip(v1, v2, v3);
      auto dest_zipped = gst::ranges::views::zip(dest_v1, dest_v2, dest_v3);

      std::reverse_copy(zipped.begin(), zipped.end(), dest_zipped.begin());

      THEN("destination contains reversed elements")
      {
        REQUIRE(dest_v1 == std::vector<int>{5, 4, 3, 2, 1});
        REQUIRE(dest_v2 == std::vector<double>{5.5, 4.4, 3.3, 2.2, 1.1});
        REQUIRE(dest_v3 == std::vector<char>{'e', 'd', 'c', 'b', 'a'});
      }
    }
  }
}

SCENARIO("std::rotate works on zip_view", "[algorithms][rotate]")
{
  GIVEN("Three vectors")
  {
    std::vector<int>    v1{1, 2, 3, 4, 5};
    std::vector<double> v2{1.1, 2.2, 3.3, 4.4, 5.5};
    std::vector<char>   v3{'a', 'b', 'c', 'd', 'e'};

    WHEN("we rotate by 2 positions")
    {
      auto zipped = gst::ranges::views::zip(v1, v2, v3);
      std::rotate(zipped.begin(), zipped.begin() + 2, zipped.end());

      THEN("all containers are rotated together")
      {
        REQUIRE(v1 == std::vector<int>{3, 4, 5, 1, 2});
        REQUIRE(v2 == std::vector<double>{3.3, 4.4, 5.5, 1.1, 2.2});
        REQUIRE(v3 == std::vector<char>{'c', 'd', 'e', 'a', 'b'});
      }
    }
  }
}

SCENARIO("std::rotate_copy works on zip_view", "[algorithms][rotate]")
{
  GIVEN("Three vectors")
  {
    std::vector<int>    v1{1, 2, 3, 4, 5};
    std::vector<double> v2{1.1, 2.2, 3.3, 4.4, 5.5};
    std::vector<char>   v3{'a', 'b', 'c', 'd', 'e'};

    WHEN("we rotate and copy")
    {
      std::vector<int>    dest_v1(5);
      std::vector<double> dest_v2(5);
      std::vector<char>   dest_v3(5);

      auto zipped      = gst::ranges::views::zip(v1, v2, v3);
      auto dest_zipped = gst::ranges::views::zip(dest_v1, dest_v2, dest_v3);

      std::rotate_copy(zipped.begin(), zipped.begin() + 2, zipped.end(), dest_zipped.begin());

      THEN("destination contains rotated elements")
      {
        REQUIRE(dest_v1 == std::vector<int>{3, 4, 5, 1, 2});
        REQUIRE(dest_v2 == std::vector<double>{3.3, 4.4, 5.5, 1.1, 2.2});
        REQUIRE(dest_v3 == std::vector<char>{'c', 'd', 'e', 'a', 'b'});
      }
    }
  }
}

SCENARIO("std::search works on zip_view", "[algorithms][search]")
{
  GIVEN("Two sequences")
  {
    std::vector<int>  v1{1, 2, 3, 4, 5, 6};
    std::vector<char> v2{'a', 'b', 'c', 'd', 'e', 'f'};

    std::vector<int>  pattern_v1{3, 4};
    std::vector<char> pattern_v2{'c', 'd'};

    WHEN("we search for a subsequence")
    {
      auto zipped         = gst::ranges::views::zip(v1, v2);
      auto pattern_zipped = gst::ranges::views::zip(pattern_v1, pattern_v2);

      auto it =
        std::search(zipped.begin(), zipped.end(), pattern_zipped.begin(), pattern_zipped.end());

      THEN("we find the subsequence")
      {
        REQUIRE(it != zipped.end());
        REQUIRE(std::get<0>(*it) == 3);
        REQUIRE(std::get<1>(*it) == 'c');
      }
    }
  }
}

SCENARIO("std::search_n works on zip_view", "[algorithms][search]")
{
  GIVEN("Vectors with consecutive values")
  {
    std::vector<int>  v1{1, 2, 5, 5, 5, 6};
    std::vector<char> v2{'a', 'b', 'c', 'c', 'c', 'd'};

    WHEN("we search for 3 consecutive occurrences")
    {
      auto zipped = gst::ranges::views::zip(v1, v2);
      auto it     = std::search_n(zipped.begin(), zipped.end(), 3, std::make_tuple(5, 'c'));

      THEN("we find the sequence")
      {
        REQUIRE(it != zipped.end());
        REQUIRE(std::get<0>(*it) == 5);
        REQUIRE(std::get<1>(*it) == 'c');
      }
    }
  }
}

SCENARIO("std::swap_ranges works on zip_view", "[algorithms][swap]")
{
  GIVEN("Two pairs of vectors")
  {
    std::vector<int>    v1a{1, 2, 3};
    std::vector<double> v2a{1.1, 2.2, 3.3};

    std::vector<int>    v1b{7, 8, 9};
    std::vector<double> v2b{7.7, 8.8, 9.9};

    WHEN("we swap the ranges")
    {
      auto zip_a = gst::ranges::views::zip(v1a, v2a);
      auto zip_b = gst::ranges::views::zip(v1b, v2b);

      std::swap_ranges(zip_a.begin(), zip_a.end(), zip_b.begin());

      THEN("the ranges are swapped")
      {
        REQUIRE(v1a == std::vector<int>{7, 8, 9});
        REQUIRE(v2a == std::vector<double>{7.7, 8.8, 9.9});
        REQUIRE(v1b == std::vector<int>{1, 2, 3});
        REQUIRE(v2b == std::vector<double>{1.1, 2.2, 3.3});
      }
    }
  }
}

SCENARIO("zip_view with conditional accumulate based on boolean predicate", "[algorithms]")
{
  GIVEN("three containers of different sizes with boolean predicate")
  {
    std::array<bool, 3> v1{true, false, true};
    std::vector<double> v2{4.1, 5.2, 6.3, 7.4};
    std::list<char>     v3{'a', 'b', 'c', 'd', 'e'};

    THEN("we can conditionally accumulate based on the boolean first element")
    {
      auto zip = gst::ranges::views::zip(v1, v2, v3);
      auto sum =
        std::accumulate(zip.begin(),
                        zip.end(),
                        0.0,
                        [](auto acc, auto t)
                        { return acc + (std::get<0>(t) ? std::get<1>(t) + std::get<2>(t) : 0); });

      REQUIRE(sum == Catch::Approx(4.1F + 'a' + 6.3F + 'c'));
    }
  }
}

SCENARIO("zip_view zips three containers and applies for_each", "[algorithms]")
{
  GIVEN("three containers of different element types")
  {
    std::array<int, 3> v1{1, 2, 3};
    std::vector<float> v2{4.1F, 5.2F, 6.3F, 7.4F};
    std::list<char>    v3{'a', 'b', 'c', 'd', 'e'};

    THEN("we can zip them and apply for_each to modify elements")
    {
      auto zip = gst::ranges::views::zip(v1, v2, v3);
      std::for_each(zip.begin(), zip.end(), [](auto&& t) { std::get<0>(t) *= 2; });

      REQUIRE(v1 == std::array<int, 3>{2, 4, 6});
    }
  }
}

SCENARIO("zip_view zips three containers and counts elements with count_if", "[algorithms]")
{
  GIVEN("three containers with different element types")
  {
    std::array<int, 3> v1{1, 2, 3};
    std::vector<float> v2{4.1F, 5.2F, 6.3F, 7.4F};
    std::list<char>    v3{'a', 'b', 'c', 'd', 'e'};

    THEN("we can count elements in the zipped view with count_if")
    {
      auto zip   = gst::ranges::views::zip(v1, v2, v3);
      auto count = std::count_if(
        zip.begin(), zip.end(), [](auto const& t) { return std::get<0>(t) % 2 == 0; });

      REQUIRE(count == 1);
    }
  }
}

SCENARIO("zip_view zips three containers and fills", "[algorithms]")
{
  GIVEN("three containers with different element types")
  {
    std::array<int, 3> v1{1, 2, 3};
    std::vector<float> v2{4.1F, 5.2F, 6.3F, 7.4F};
    std::list<char>    v3{'a', 'b', 'c', 'd', 'e'};

    THEN("we can fill the zipped view")
    {
      auto zip = gst::ranges::views::zip(v1, v2, v3);
      std::fill(zip.begin(), zip.end(), std::make_tuple(0, 0.0F, 'z'));

      REQUIRE(v1 == std::array<int, 3>{0, 0, 0});
    }
  }
}

SCENARIO("zip_view zips three containers and fills with a generator", "[algorithms]")
{
  GIVEN("three containers with different element types")
  {
    std::array<int, 3> v1{0, 0, 0};
    std::vector<float> v2{0.0F, 0.0F, 0.0F, 0.0F};
    std::list<char>    v3{' ', ' ', ' ', ' ', ' '};

    THEN("we can fill the zipped view with a generator")
    {
      auto zip       = gst::ranges::views::zip(v1, v2, v3);
      auto generator = [n = 1]() mutable { return std::make_tuple(n++, 0.0F, ' '); };

      std::generate(zip.begin(), zip.end(), generator);

      REQUIRE(v1 == std::array<int, 3>{1, 2, 3});
    }
  }
}

SCENARIO("zip_view zips three containers and removes elements with remove_if", "[algorithms]")
{
  GIVEN("three containers with different element types")
  {
    std::array<bool, 3> v1{false, true, false};
    std::vector<float>  v2{4.1F, 5.2F, 6.3F, 7.4F};
    std::list<char>     v3{'a', 'b', 'c', 'd', 'e'};

    THEN("we can remove elements from the zipped view with remove_if")
    {
      auto zip = gst::ranges::views::zip(v1, v2, v3);
      auto new_end =
        std::remove_if(zip.begin(), zip.end(), [](auto const&& t) { return std::get<0>(t); });

      REQUIRE(new_end == std::next(zip.begin(), 2));
    }
  }
}

SCENARIO("zip_view zips three containers and transforms (unary)", "[algorithms]")
{
  GIVEN("three containers with different element types")
  {
    std::array<int, 3>  v1{1, 2, 3};
    std::vector<double> v2{4.1, 5.2, 6.3, 7.4};
    std::list<char>     v3{'a', 'b', 'c', 'd', 'e'};

    THEN("we can transform the zipped view")
    {
      auto               zip = gst::ranges::views::zip(v1, v2, v3);
      std::array<int, 3> res;

      auto itr = std::transform(
        zip.begin(), zip.end(), res.begin(), [](auto const& t) { return std::get<0>(t) * 2; });

      REQUIRE(res == std::array<int, 3>{2, 4, 6});
      REQUIRE(itr == res.end());
    }
  }
}

SCENARIO("zip_view zips two containers and transforms (binary)", "[algorithms]")
{
  GIVEN("two containers with different element types")
  {
    std::vector<int>    v1{1, 2, 3};
    std::vector<double> v2{4.1, 5.2, 6.3};

    THEN("we can transform the zipped views with a binary operation")
    {
      auto zip1 = gst::ranges::views::zip(v1);
      auto zip2 = gst::ranges::views::zip(v2);

      std::vector<double> res(v1.size());
      std::vector<double> ref{1 + 4.1, 2 + 5.2, 3 + 6.3};

      auto itr = std::transform(zip1.begin(),
                                zip1.end(),
                                zip2.begin(),
                                res.begin(),
                                [](auto const& t1, auto const& t2)
                                { return std::get<0>(t1) + std::get<0>(t2); });

      REQUIRE(res == ref);
      REQUIRE(itr == res.end());
    }
  }
}

SCENARIO("std::equal_range works on sorted zip_view", "[algorithms][binary_search]")
{
  GIVEN("Sorted vectors with duplicates")
  {
    std::vector<int>    v1{1, 2, 2, 2, 3, 4, 5};
    std::vector<double> v2{1.1, 2.1, 2.2, 2.3, 3.3, 4.4, 5.5};
    std::vector<char>   v3{'a', 'b', 'c', 'd', 'e', 'f', 'g'};

    WHEN("we find the equal range for value 2")
    {
      auto zipped = gst::ranges::views::zip(v1, v2, v3);
      auto range  = std::equal_range(zipped.begin(),
                                    zipped.end(),
                                    std::make_tuple(2, 0.0, '\0'),
                                    [](auto const& a, auto const& b)
                                    { return std::get<0>(a) < std::get<0>(b); });

      THEN("we get the range of all elements equal to 2")
      {
        REQUIRE(std::distance(range.first, range.second) == 3);
        REQUIRE(std::get<0>(*range.first) == 2);
        REQUIRE(std::get<1>(*range.first) == Catch::Approx(2.1));
        REQUIRE(std::get<2>(*range.first) == 'b');
      }
    }
  }
}

SCENARIO("std::is_partitioned works on zip_view", "[algorithms][partition]")
{
  GIVEN("A partitioned and a non-partitioned sequence")
  {
    std::vector<int>    partitioned_v1{2, 4, 6, 1, 3, 5};
    std::vector<double> partitioned_v2{2.2, 4.4, 6.6, 1.1, 3.3, 5.5};

    std::vector<int>    not_partitioned_v1{1, 2, 3, 4, 5, 6};
    std::vector<double> not_partitioned_v2{1.1, 2.2, 3.3, 4.4, 5.5, 6.6};

    THEN("is_partitioned returns true for partitioned sequence")
    {
      auto zipped = gst::ranges::views::zip(partitioned_v1, partitioned_v2);
      bool result = std::is_partitioned(
        zipped.begin(), zipped.end(), [](auto const& t) { return std::get<0>(t) % 2 == 0; });
      REQUIRE(result == true);
    }

    THEN("is_partitioned returns false for non-partitioned sequence")
    {
      auto zipped = gst::ranges::views::zip(not_partitioned_v1, not_partitioned_v2);
      bool result = std::is_partitioned(
        zipped.begin(), zipped.end(), [](auto const& t) { return std::get<0>(t) % 2 == 0; });
      REQUIRE(result == false);
    }
  }
}

SCENARIO("std::is_sorted_until works on zip_view", "[algorithms][sorted]")
{
  GIVEN("A partially sorted sequence")
  {
    std::vector<int>    v1{1, 2, 3, 2, 5};
    std::vector<double> v2{1.1, 2.2, 3.3, 2.2, 5.5};
    std::vector<char>   v3{'a', 'b', 'c', 'd', 'e'};

    WHEN("we find where the sequence stops being sorted")
    {
      auto zipped = gst::ranges::views::zip(v1, v2, v3);
      auto it     = std::is_sorted_until(zipped.begin(),
                                     zipped.end(),
                                     [](auto const& a, auto const& b)
                                     { return std::get<0>(a) < std::get<0>(b); });

      THEN("we find the first unsorted element")
      {
        REQUIRE(std::distance(zipped.begin(), it) == 3);
        REQUIRE(std::get<0>(*it) == 2);
        REQUIRE(std::get<1>(*it) == Catch::Approx(2.2));
        REQUIRE(std::get<2>(*it) == 'd');
      }
    }
  }
}

SCENARIO("std::lower_bound and std::upper_bound work on sorted zip_view",
         "[algorithms][binary_search]")
{
  GIVEN("Sorted vectors")
  {
    std::vector<int>    v1{1, 2, 2, 3, 4, 4, 4, 5};
    std::vector<double> v2{1.1, 2.1, 2.2, 3.3, 4.1, 4.2, 4.3, 5.5};
    std::vector<char>   v3{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};

    auto zipped = gst::ranges::views::zip(v1, v2, v3);

    WHEN("we find lower_bound for value 4")
    {
      auto it = std::lower_bound(zipped.begin(),
                                 zipped.end(),
                                 std::make_tuple(4, 0.0, '\0'),
                                 [](auto const& a, auto const& b)
                                 { return std::get<0>(a) < std::get<0>(b); });

      THEN("we get the first element not less than 4")
      {
        REQUIRE(std::get<0>(*it) == 4);
        REQUIRE(std::get<1>(*it) == Catch::Approx(4.1));
        REQUIRE(std::get<2>(*it) == 'e');
      }
    }

    WHEN("we find upper_bound for value 4")
    {
      auto it = std::upper_bound(zipped.begin(),
                                 zipped.end(),
                                 std::make_tuple(4, 0.0, '\0'),
                                 [](auto const& a, auto const& b)
                                 { return std::get<0>(a) < std::get<0>(b); });

      THEN("we get the first element greater than 4")
      {
        REQUIRE(std::get<0>(*it) == 5);
        REQUIRE(std::get<1>(*it) == Catch::Approx(5.5));
        REQUIRE(std::get<2>(*it) == 'h');
      }
    }
  }
}

SCENARIO("std::max_element works on zip_view", "[algorithms][minmax]")
{
  GIVEN("Three vectors")
  {
    std::vector<int>    v1{3, 1, 4, 1, 5, 9, 2};
    std::vector<double> v2{3.3, 1.1, 4.4, 1.2, 5.5, 9.9, 2.2};
    std::vector<char>   v3{'c', 'a', 'd', 'b', 'e', 'i', 'f'};

    auto zipped = gst::ranges::views::zip(v1, v2, v3);

    WHEN("we find the maximum element by first component")
    {
      auto it = std::max_element(zipped.begin(),
                                 zipped.end(),
                                 [](auto const& a, auto const& b)
                                 { return std::get<0>(a) < std::get<0>(b); });

      THEN("we get the tuple with maximum first element")
      {
        REQUIRE(it != zipped.end());
        REQUIRE(std::get<0>(*it) == 9);
        REQUIRE(std::get<1>(*it) == Catch::Approx(9.9));
        REQUIRE(std::get<2>(*it) == 'i');
      }
    }
  }
}

SCENARIO("std::min_element works on zip_view", "[algorithms][minmax]")
{
  GIVEN("Three vectors")
  {
    std::vector<int>    v1{3, 1, 4, 1, 5, 9, 2};
    std::vector<double> v2{3.3, 1.1, 4.4, 1.2, 5.5, 9.9, 2.2};
    std::vector<char>   v3{'c', 'a', 'd', 'b', 'e', 'i', 'f'};

    auto zipped = gst::ranges::views::zip(v1, v2, v3);

    WHEN("we find the minimum element by first component")
    {
      auto it = std::min_element(zipped.begin(),
                                 zipped.end(),
                                 [](auto const& a, auto const& b)
                                 { return std::get<0>(a) < std::get<0>(b); });

      THEN("we get the tuple with minimum first element")
      {
        REQUIRE(it != zipped.end());
        REQUIRE(std::get<0>(*it) == 1);
        REQUIRE(std::get<1>(*it) == Catch::Approx(1.1));
        REQUIRE(std::get<2>(*it) == 'a');
      }
    }
  }
}

SCENARIO("std::minmax_element works on zip_view", "[algorithms][minmax]")
{
  GIVEN("Three vectors")
  {
    std::vector<int>    v1{3, 1, 4, 1, 5, 9, 2};
    std::vector<double> v2{3.3, 1.1, 4.4, 1.2, 5.5, 9.9, 2.2};
    std::vector<char>   v3{'c', 'a', 'd', 'b', 'e', 'i', 'f'};

    WHEN("we find both min and max elements")
    {
      auto zipped = gst::ranges::views::zip(v1, v2, v3);
      auto result = std::minmax_element(zipped.begin(),
                                        zipped.end(),
                                        [](auto const& a, auto const& b)
                                        { return std::get<0>(a) < std::get<0>(b); });

      THEN("we get both minimum and maximum")
      {
        REQUIRE(std::get<0>(*result.first) == 1);
        REQUIRE(std::get<1>(*result.first) == Catch::Approx(1.1));
        REQUIRE(std::get<2>(*result.first) == 'a');

        REQUIRE(std::get<0>(*result.second) == 9);
        REQUIRE(std::get<1>(*result.second) == Catch::Approx(9.9));
        REQUIRE(std::get<2>(*result.second) == 'i');
      }
    }
  }
}

SCENARIO("std::next_permutation and std::prev_permutation work on zip_view",
         "[algorithms][permutation]")
{
  GIVEN("Three sorted vectors")
  {
    std::vector<int>  v1{1, 2, 3};
    std::vector<char> v2{'a', 'b', 'c'};

    WHEN("we generate the next permutation")
    {
      auto zipped = gst::ranges::views::zip(v1, v2);
      bool result = std::next_permutation(zipped.begin(),
                                          zipped.end(),
                                          [](auto const& a, auto const& b)
                                          { return std::get<0>(a) < std::get<0>(b); });

      THEN("all vectors are permuted together")
      {
        REQUIRE(result == true);
        REQUIRE(v1 == std::vector<int>{1, 3, 2});
        REQUIRE(v2 == std::vector<char>{'a', 'c', 'b'});
      }
    }

    WHEN("we generate the previous permutation from non-first permutation")
    {
      v1 = {2, 1, 3};
      v2 = {'b', 'a', 'c'};

      auto zipped = gst::ranges::views::zip(v1, v2);
      bool result = std::prev_permutation(zipped.begin(),
                                          zipped.end(),
                                          [](auto const& a, auto const& b)
                                          { return std::get<0>(a) < std::get<0>(b); });

      THEN("all vectors are permuted together")
      {
        REQUIRE(result == true);
        REQUIRE(v1 == std::vector<int>{1, 3, 2});
        REQUIRE(v2 == std::vector<char>{'a', 'c', 'b'});
      }
    }
  }
}

SCENARIO("std::nth_element works on random access zip_view", "[algorithms][nth_element]")
{
  GIVEN("Two vectors")
  {
    std::vector<int>  keys{5, 2, 8, 1, 9, 3, 7};
    std::vector<char> values{'5', '2', '8', '1', '9', '3', '7'};

    WHEN("we find the 3rd smallest element")
    {
      auto zipped = gst::ranges::views::zip(keys, values);
      std::nth_element(zipped.begin(),
                       zipped.begin() + 3,
                       zipped.end(),
                       [](auto const& a, auto const& b)
                       { return std::get<0>(a) < std::get<0>(b); });

      THEN("the element at position 3 has key 5 (4th smallest)")
      {
        // After nth_element, position 3 should have the element that would be there if sorted
        // Sorted keys would be: 1, 2, 3, 5, 7, 8, 9
        // So position 3 (0-indexed) should have key 5
        REQUIRE(keys[3] == 5);
        REQUIRE(values[3] == '5');
      }
    }
  }
}

SCENARIO("std::partial_sort works on random access zip_view", "[algorithms][sort]")
{
  GIVEN("Three vectors")
  {
    std::vector<int>    v1{5, 2, 8, 1, 9, 3, 7};
    std::vector<double> v2{5.5, 2.2, 8.8, 1.1, 9.9, 3.3, 7.7};
    std::vector<char>   v3{'e', 'b', 'h', 'a', 'i', 'c', 'g'};

    WHEN("we partially sort the first 3 elements")
    {
      auto zipped = gst::ranges::views::zip(v1, v2, v3);
      std::partial_sort(zipped.begin(),
                        zipped.begin() + 3,
                        zipped.end(),
                        [](auto const& a, auto const& b)
                        { return std::get<0>(a) < std::get<0>(b); });

      THEN("the first 3 elements are the smallest, in sorted order")
      {
        REQUIRE(std::vector<int>(v1.begin(), v1.begin() + 3) == std::vector<int>{1, 2, 3});
        REQUIRE(std::vector<double>(v2.begin(), v2.begin() + 3) ==
                std::vector<double>{1.1, 2.2, 3.3});
        REQUIRE(std::vector<char>(v3.begin(), v3.begin() + 3) == std::vector<char>{'a', 'b', 'c'});
      }
    }
  }
}

SCENARIO("std::partition works on zip_view", "[algorithms][partition]")
{
  GIVEN("Three vectors")
  {
    std::vector<int>         v1{1, 2, 3, 4, 5, 6};
    std::vector<std::string> v2{"one", "two", "three", "four", "five", "six"};
    std::vector<char>        v3{'a', 'b', 'c', 'd', 'e', 'f'};

    WHEN("we partition by even numbers")
    {
      auto is_even  = [](auto const& t) { return std::get<0>(t) % 2 == 0; };
      auto zipped   = gst::ranges::views::zip(v1, v2, v3);
      auto it_bound = std::partition(zipped.begin(), zipped.end(), is_even);

      THEN("the return value points to the partition boundary")
      {
        REQUIRE(it_bound == std::next(zipped.begin(), 3));
      }

      THEN("even elements come first in the first container")
      {
        REQUIRE(std::all_of(
          v1.begin(), std::next(v1.begin(), 3), [](auto const arg) { return arg % 2 == 0; }));
        REQUIRE(std::all_of(
          std::next(v1.begin(), 3), v1.end(), [](auto const arg) { return arg % 2 != 0; }));
      }
    }
  }
}

SCENARIO("std::partition_point works on partitioned zip_view", "[algorithms][partition]")
{
  GIVEN("A partitioned sequence")
  {
    std::vector<int>    v1{2, 4, 6, 1, 3, 5};
    std::vector<double> v2{2.2, 4.4, 6.6, 1.1, 3.3, 5.5};

    WHEN("we find the partition point")
    {
      auto zipped = gst::ranges::views::zip(v1, v2);
      auto it     = std::partition_point(
        zipped.begin(), zipped.end(), [](auto const& t) { return std::get<0>(t) % 2 == 0; });

      THEN("we find the boundary between partitions")
      {
        REQUIRE(std::distance(zipped.begin(), it) == 3);
        REQUIRE(std::get<0>(*it) == 1);
        REQUIRE(std::get<1>(*it) == Catch::Approx(1.1));
      }
    }
  }
}

SCENARIO("std::sort works on random access zip_view", "[algorithms]")
{
  GIVEN("Two vectors where first should be sorted and second follows")
  {
    std::vector<int>    keys{3, 7, 4, 1, 5, 9, 2, 6};
    std::vector<double> values{30.0, 70.0, 40.0, 10.0, 50.0, 90.0, 20.0, 60.0};

    WHEN("we sort the zip_view by the key")
    {
      auto zipped = gst::ranges::views::zip(keys, values);
      std::sort(zipped.begin(),
                zipped.end(),
                [](auto const& a, auto const& b) { return std::get<0>(a) < std::get<0>(b); });

      THEN("both containers are sorted according to the keys")
      {
        REQUIRE(keys == std::vector<int>{1, 2, 3, 4, 5, 6, 7, 9});
        REQUIRE(values == std::vector<double>{10.0, 20.0, 30.0, 40.0, 50.0, 60.0, 70.0, 90.0});
      }
    }
  }

  GIVEN("Three vectors to be sorted together")
  {
    std::array<int, 5>                keys{5, 2, 8, 1, 9};
    std::vector<std::string>          names{"five", "two", "eight", "one", "nine"};
    std::vector<std::pair<int, char>> pairs{{5, 'e'}, {2, 'b'}, {8, 'd'}, {1, 'a'}, {9, 'c'}};

    WHEN("we sort by key")
    {
      auto zipped = gst::ranges::views::zip(keys, names, pairs);
      std::sort(zipped.begin(),
                zipped.end(),
                [](auto const& a, auto const& b) { return std::get<0>(a) < std::get<0>(b); });

      THEN("all three containers are sorted consistently")
      {
        REQUIRE(keys == std::array<int, 5>{1, 2, 5, 8, 9});
        REQUIRE(names == std::vector<std::string>{"one", "two", "five", "eight", "nine"});
        REQUIRE(pairs == std::vector<std::pair<int, char>>{
                           {1, 'a'}, {2, 'b'}, {5, 'e'}, {8, 'd'}, {9, 'c'}});
      }
    }
  }
}

SCENARIO("std::stable_partition works on zip_view", "[algorithms][partition]")
{
  GIVEN("Three vectors")
  {
    std::vector<int>         v1{1, 2, 3, 4, 5, 6};
    std::vector<std::string> v2{"one", "two", "three", "four", "five", "six"};
    std::vector<char>        v3{'a', 'b', 'c', 'd', 'e', 'f'};

    WHEN("we stable partition by even numbers")
    {
      auto zipped = gst::ranges::views::zip(v1, v2, v3);
      auto it     = std::stable_partition(
        zipped.begin(), zipped.end(), [](auto const& t) { return std::get<0>(t) % 2 == 0; });

      THEN("the return value points to the partition boundary")
      {
        REQUIRE(it == std::next(zipped.begin(), 3));
      }

      THEN("even elements come first, order preserved, all vectors partitioned")
      {
        REQUIRE(v1 == std::vector<int>{2, 4, 6, 1, 3, 5});
        REQUIRE(v2 == std::vector<std::string>{"two", "four", "six", "one", "three", "five"});
        REQUIRE(v3 == std::vector<char>{'b', 'd', 'f', 'a', 'c', 'e'});
      }
    }
  }
}

SCENARIO("std::stable_sort works on random access zip_view", "[algorithms][sort]")
{
  GIVEN("Three vectors with equal keys")
  {
    std::vector<int>         v1{3, 1, 2, 1, 3};
    std::vector<std::string> v2{"a", "b", "c", "d", "e"};
    std::vector<int>         v3{10, 20, 30, 40, 50};

    WHEN("we stable sort by the first element")
    {
      auto zipped = gst::ranges::views::zip(v1, v2, v3);
      std::stable_sort(zipped.begin(),
                       zipped.end(),
                       [](auto const& a, auto const& b)
                       { return std::get<0>(a) < std::get<0>(b); });

      THEN("equal elements maintain their relative order")
      {
        REQUIRE(v1 == std::vector<int>{1, 1, 2, 3, 3});
        REQUIRE(v2 == std::vector<std::string>{"b", "d", "c", "a", "e"});
        REQUIRE(v3 == std::vector<int>{20, 40, 30, 10, 50});
      }
    }
  }
}

SCENARIO("std::unique works on sorted zip_view", "[algorithms][unique]")
{
  GIVEN("Vectors with duplicates")
  {
    std::vector<int>         v1{1, 1, 2, 2, 3, 3, 4};
    std::vector<std::string> v2{"a", "b", "c", "d", "e", "f", "g"};
    std::vector<double>      v3{1.1, 1.2, 2.1, 2.2, 3.1, 3.2, 4.1};

    WHEN("we remove consecutive duplicates based on first element")
    {
      auto zipped = gst::ranges::views::zip(v1, v2, v3);
      auto it =
        std::unique(zipped.begin(),
                    zipped.end(),
                    [](auto const& a, auto const& b) { return std::get<0>(a) == std::get<0>(b); });

      THEN("duplicates are removed from all vectors")
      {
        auto new_size = std::distance(zipped.begin(), it);
        REQUIRE(new_size == 4);
        v1.erase(v1.begin() + new_size, v1.end());
        v2.erase(v2.begin() + new_size, v2.end());
        v3.erase(v3.begin() + new_size, v3.end());

        REQUIRE(v1 == std::vector<int>{1, 2, 3, 4});
        REQUIRE(v2 == std::vector<std::string>{"a", "c", "e", "g"});
        REQUIRE(v3 == std::vector<double>{1.1, 2.1, 3.1, 4.1});
      }
    }
  }
}

SCENARIO("Testing algorithms on nested zip_views", "[zip_view][nested][algo]")
{
  {
    WHEN("Using std::for_each on nested zip_views")
    {
      std::vector<int> v1 = {1, 2, 3};
      std::vector<int> v2 = {4, 5, 6};
      std::vector<int> v3 = {7, 8, 9};
      std::vector<int> v4 = {10, 11, 12};

      auto zip1   = gst::ranges::views::zip(v1, v2);
      auto zip2   = gst::ranges::views::zip(v3, v4);
      auto nested = gst::ranges::views::zip(zip1, zip2);

      THEN("std::for_each can iterate and access nested elements")
      {
        int sum = 0;
        std::for_each(nested.begin(),
                      nested.end(),
                      [&sum](auto elem)
                      {
                        auto t0  = std::get<0>(elem);
                        sum     += std::get<0>(t0) + std::get<1>(t0);
                      });
        REQUIRE(sum == 21); // (1+4) + (2+5) + (3+6) = 21
      }

      THEN("std::for_each can modify elements through nested zip_view")
      {
        std::for_each(nested.begin(),
                      nested.end(),
                      [](auto&& elem)
                      {
                        auto t0          = std::get<0>(elem);
                        std::get<0>(t0) *= 10;
                      });
        REQUIRE(v1 == std::vector<int>{10, 20, 30});
      }
    }

    WHEN("Using std::count_if on nested zip_views")
    {
      std::vector<int> v1 = {1, 2, 3, 4, 5};
      std::vector<int> v2 = {2, 4, 6, 8, 10};
      std::vector<int> v3 = {1, 3, 5, 7, 9};

      auto nested = gst::ranges::views::zip(gst::ranges::views::zip(v1, v2), v3);

      THEN("std::count_if works on nested zip_views")
      {
        auto count = std::count_if(nested.begin(),
                                   nested.end(),
                                   [](auto elem)
                                   {
                                     auto t0 = std::get<0>(elem);
                                     return std::get<0>(t0) > 2; // Count where v1 > 2
                                   });
        REQUIRE(count == 3);                                     // Elements 3, 4, 5
      }

      THEN("std::count_if with complex predicate on nested elements")
      {
        auto count = std::count_if(nested.begin(),
                                   nested.end(),
                                   [](auto elem)
                                   {
                                     auto t0      = std::get<0>(elem);
                                     auto regular = std::get<1>(elem);
                                     return std::get<1>(t0) % 4 == 0 &&
                                            regular % 2 == 1; // v2 divisible by 4 AND v3 odd
                                   });
        REQUIRE(count == 2); // Positions 1 and 3 (v2=4,v3=3 and v2=8,v3=7)
      }
    }

    WHEN("Using std::transform on nested zip_views")
    {
      std::vector<int> v1 = {1, 2, 3};
      std::vector<int> v2 = {10, 20, 30};
      std::vector<int> v3 = {100, 200, 300};

      auto zip1   = gst::ranges::views::zip(v1, v2);
      auto zip2   = gst::ranges::views::zip(v2, v3);
      auto nested = gst::ranges::views::zip(zip1, zip2);

      std::vector<int> results;

      THEN("std::transform can extract and combine nested elements")
      {
        std::transform(nested.begin(),
                       nested.end(),
                       std::back_inserter(results),
                       [](auto elem)
                       {
                         auto t0 = std::get<0>(elem);
                         auto t1 = std::get<1>(elem);
                         return std::get<0>(t0) + std::get<1>(t1); // v1 + v3
                       });
        REQUIRE(results == std::vector<int>{101, 202, 303});
      }
    }

    WHEN("Using std::any_of and std::all_of on nested zip_views")
    {
      std::vector<int> v1 = {2, 4, 6};
      std::vector<int> v2 = {1, 3, 5};
      std::vector<int> v3 = {10, 20, 30};

      auto nested = gst::ranges::views::zip(gst::ranges::views::zip(v1, v2), v3);

      THEN("std::any_of works on nested zip_views")
      {
        bool has_even_in_first = std::any_of(nested.begin(),
                                             nested.end(),
                                             [](auto elem)
                                             {
                                               auto t0 = std::get<0>(elem);
                                               return std::get<0>(t0) % 2 == 0;
                                             });
        REQUIRE(has_even_in_first);
      }

      THEN("std::all_of works on nested zip_views")
      {
        bool all_positive =
          std::all_of(nested.begin(),
                      nested.end(),
                      [](auto elem) { return std::get<0>(elem) > std::make_tuple(0, 0); });
        REQUIRE(all_positive);
      }
    }

    WHEN("Using std::find_if on nested zip_views")
    {
      std::vector<int> v1 = {1, 2, 3, 4, 5};
      std::vector<int> v2 = {10, 20, 30, 40, 50};
      std::vector<int> v3 = {5, 4, 3, 2, 1};

      auto zip1   = gst::ranges::views::zip(v1, v2);
      auto zip2   = gst::ranges::views::zip(v2, v3);
      auto nested = gst::ranges::views::zip(zip1, zip2);

      THEN("std::find_if can locate specific nested elements")
      {
        auto it = std::find_if(nested.begin(),
                               nested.end(),
                               [](auto elem)
                               {
                                 auto t0 = std::get<0>(elem);
                                 return std::get<0>(t0) == 3;
                               });

        REQUIRE(it != nested.end());
        auto found = *it;
        auto t0    = std::get<0>(found);
        REQUIRE(std::get<1>(t0) == 30);
      }
    }

    WHEN("Using std::accumulate on nested zip_views")
    {
      std::vector<int> v1 = {1, 2, 3};
      std::vector<int> v2 = {4, 5, 6};
      std::vector<int> v3 = {7, 8, 9};

      auto nested = gst::ranges::views::zip(gst::ranges::views::zip(v1, v2), v3);

      THEN("std::accumulate can sum nested elements")
      {
        int sum = std::accumulate(nested.begin(),
                                  nested.end(),
                                  0,
                                  [](int acc, auto elem)
                                  {
                                    auto t0 = std::get<0>(elem);
                                    return acc + std::get<0>(t0) + std::get<1>(elem);
                                  });
        REQUIRE(sum == 30); // (1+7) + (2+8) + (3+9) = 8 + 10 + 12 = 30
      }
    }

    WHEN("Using std::copy_if with nested zip_views")
    {
      std::vector<int> v1 = {1, 2, 3, 4, 5};
      std::vector<int> v2 = {10, 20, 30, 40, 50};
      std::vector<int> v3 = {2, 4, 6, 8, 10};

      auto             nested = gst::ranges::views::zip(gst::ranges::views::zip(v1, v2), v3);
      std::vector<int> selected;

      THEN("std::copy_if can filter and extract from nested zip_views")
      {
        std::for_each(nested.begin(),
                      nested.end(),
                      [&selected](auto elem)
                      {
                        auto t0 = std::get<0>(elem);
                        if (std::get<0>(t0) > 2)
                        { // Copy v1 values > 2
                          selected.push_back(std::get<0>(t0));
                        }
                      });
        REQUIRE(selected == std::vector<int>{3, 4, 5});
      }
    }
  }

  GIVEN("Algorithms with temporary nested zip_views")
  {
    WHEN("Using std::for_each on inline temporary nested zip_views")
    {
      std::vector<int> v1 = {1, 2, 3, 4};
      std::vector<int> v2 = {10, 20, 30, 40};
      std::vector<int> v3 = {100, 200, 300, 400};
      std::vector<int> v4 = {5, 6, 7, 8};

      THEN("Can apply std::for_each directly to temporary nested zip_view")
      {
        int sum = 0;
        std::for_each(
          gst::ranges::views::zip(gst::ranges::views::zip(v1, v2), gst::ranges::views::zip(v3, v4))
            .begin(),
          gst::ranges::views::zip(gst::ranges::views::zip(v1, v2), gst::ranges::views::zip(v3, v4))
            .end(),
          [&sum](auto elem)
          {
            auto t0  = std::get<0>(elem);
            auto t1  = std::get<1>(elem);
            sum     += std::get<0>(t0) + std::get<0>(t1);
          });
        REQUIRE(sum == 1010); // (1+100) + (2+200) + (3+300) + (4+400) = 1010
      }

      THEN("Can modify through std::for_each on temporary nested zip_view")
      {
        std::for_each(gst::ranges::views::zip(gst::ranges::views::zip(v1, v2), v4).begin(),
                      gst::ranges::views::zip(gst::ranges::views::zip(v1, v2), v4).end(),
                      [](auto&& elem)
                      {
                        auto t0          = std::get<0>(elem);
                        std::get<1>(t0) *= 2;
                      });
        REQUIRE(v2 == std::vector<int>{20, 40, 60, 80});
      }
    }

    WHEN("Using std::count_if on inline temporary nested zip_views")
    {
      std::vector<int> v1 = {1, 2, 3, 4, 5};
      std::vector<int> v2 = {2, 4, 6, 8, 10};
      std::vector<int> v3 = {10, 20, 30, 40, 50};

      THEN("std::count_if works directly on temporary nested zip_view")
      {
        auto count =
          std::count_if(gst::ranges::views::zip(gst::ranges::views::zip(v1, v2), v3).begin(),
                        gst::ranges::views::zip(gst::ranges::views::zip(v1, v2), v3).end(),
                        [](auto elem)
                        {
                          auto t0 = std::get<0>(elem);
                          return std::get<0>(t0) > 2 && std::get<1>(t0) % 4 == 0;
                        });
        REQUIRE(count == 1); // v1 > 2 AND v2 divisible by 4: only (4,8)
      }
    }

    WHEN("Using std::any_of on inline temporary nested zip_views")
    {
      std::vector<int> v1 = {1, 3, 5, 7};
      std::vector<int> v2 = {2, 4, 6, 8};
      std::vector<int> v3 = {10, 20, 30, 40};

      THEN("std::any_of works on temporary nested zip_view")
      {
        bool has_sum_greater_than_50 =
          std::any_of(gst::ranges::views::zip(gst::ranges::views::zip(v1, v2), v3).begin(),
                      gst::ranges::views::zip(gst::ranges::views::zip(v1, v2), v3).end(),
                      [](auto elem)
                      {
                        auto t0 = std::get<0>(elem);
                        return std::get<0>(t0) + std::get<1>(t0) + std::get<1>(elem) > 50;
                      });
        REQUIRE(has_sum_greater_than_50); // 7 + 8 + 40 = 55 > 50
      }
    }

    WHEN("Using std::transform on inline temporary nested zip_views")
    {
      std::vector<int> v1 = {1, 2, 3};
      std::vector<int> v2 = {4, 5, 6};
      std::vector<int> v3 = {7, 8, 9};
      std::vector<int> v4 = {10, 11, 12};
      std::vector<int> results;

      THEN("std::transform works on temporary nested zip_view")
      {
        std::transform(
          gst::ranges::views::zip(gst::ranges::views::zip(v1, v2), gst::ranges::views::zip(v3, v4))
            .begin(),
          gst::ranges::views::zip(gst::ranges::views::zip(v1, v2), gst::ranges::views::zip(v3, v4))
            .end(),
          std::back_inserter(results),
          [](auto elem)
          {
            auto t0 = std::get<0>(elem);
            auto t1 = std::get<1>(elem);
            return std::get<0>(t0) + std::get<1>(t0) + std::get<0>(t1) + std::get<1>(t1);
          });
        REQUIRE(results == std::vector<int>{22, 26, 30}); // (1+4+7+10), (2+5+8+11), (3+6+9+12)
      }
    }

    WHEN("Using std::find_if on inline temporary nested zip_views")
    {
      std::vector<int> v1 = {10, 20, 30, 40, 50};
      std::vector<int> v2 = {1, 2, 3, 4, 5};
      std::vector<int> v3 = {5, 4, 3, 2, 1};

      THEN("std::find_if locates element in temporary nested zip_view")
      {
        auto temp_zip = gst::ranges::views::zip(gst::ranges::views::zip(v1, v2), v3);
        auto it       = std::find_if(temp_zip.begin(),
                               temp_zip.end(),
                               [](auto elem)
                               {
                                 auto t0 = std::get<0>(elem);
                                 return std::get<0>(t0) == 30;
                               });

        REQUIRE(it != temp_zip.end());
        auto found = *it;
        auto t0    = std::get<0>(found);
        REQUIRE(std::get<1>(t0) == 3);
        REQUIRE(std::get<1>(found) == 3);
      }
    }

    WHEN("Using std::accumulate on inline temporary nested zip_views")
    {
      std::vector<int> v1 = {1, 2, 3};
      std::vector<int> v2 = {10, 20, 30};
      std::vector<int> v3 = {100, 200, 300};

      THEN("std::accumulate works on temporary nested zip_view")
      {
        auto temp    = gst::ranges::views::zip(gst::ranges::views::zip(v1, v2), v3);
        int  product = std::accumulate(temp.begin(),
                                      temp.end(),
                                      1,
                                      [](int acc, auto elem)
                                      {
                                        auto t0 = std::get<0>(elem);
                                        return acc * std::get<0>(t0); // Multiply all v1 values
                                      });
        REQUIRE(product == 6);                                         // 1 * 2 * 3 = 6
      }
    }

    WHEN("Using std::all_of on inline temporary deeply nested zip_views")
    {
      std::vector<int> v1 = {1, 2, 3};
      std::vector<int> v2 = {4, 5, 6};
      std::vector<int> v3 = {7, 8, 9};
      std::vector<int> v4 = {10, 11, 12};
      std::vector<int> v5 = {2, 2, 2};

      THEN("std::all_of works on deeply nested temporary zip_view")
      {
        bool all_positive = std::all_of(
          gst::ranges::views::zip(gst::ranges::views::zip(gst::ranges::views::zip(v1, v2),
                                                          gst::ranges::views::zip(v3, v4)),
                                  v5)
            .begin(),
          gst::ranges::views::zip(gst::ranges::views::zip(gst::ranges::views::zip(v1, v2),
                                                          gst::ranges::views::zip(v3, v4)),
                                  v5)
            .end(),
          [](auto elem)
          {
            return std::get<1>(elem) > 0; // Check v5 elements all > 0
          });
        REQUIRE(all_positive);
      }
    }

    WHEN("Using multiple algorithms in sequence on temporary nested zip_views")
    {
      std::vector<int> v1 = {1, 2, 3, 4, 5};
      std::vector<int> v2 = {10, 20, 30, 40, 50};
      std::vector<int> v3 = {5, 4, 3, 2, 1};

      THEN("Can chain multiple algorithm operations on temporary nested zip_view")
      {
        auto temp = gst::ranges::views::zip(gst::ranges::views::zip(v1, v2), v3);

        // First: count elements where v1 > 2
        auto count = std::count_if(temp.begin(),
                                   temp.end(),
                                   [](auto elem)
                                   {
                                     auto t0 = std::get<0>(elem);
                                     return std::get<0>(t0) > 2;
                                   });
        REQUIRE(count == 3);

        // Second: find first where v3 < 3
        auto it =
          std::find_if(temp.begin(), temp.end(), [](auto elem) { return std::get<1>(elem) < 3; });
        REQUIRE(it != temp.end());

        // Third: accumulate sum of v2 values
        int sum = std::accumulate(temp.begin(),
                                  temp.end(),
                                  0,
                                  [](int acc, auto elem)
                                  {
                                    auto t0 = std::get<0>(elem);
                                    return acc + std::get<1>(t0);
                                  });
        REQUIRE(sum == 150); // 10+20+30+40+50
      }
    }

    WHEN("Using range-based for directly on temporary nested zip_views in algorithm context")
    {
      std::vector<int> v1 = {1, 2, 3};
      std::vector<int> v2 = {4, 5, 6};
      std::vector<int> v3 = {7, 8, 9};

      THEN("Can use range-based for on temporary created inline")
      {
        int sum = 0;
        for (auto elem : gst::ranges::views::zip(gst::ranges::views::zip(v1, v2), v3))
        {
          auto t0  = std::get<0>(elem);
          sum     += std::get<0>(t0) + std::get<1>(elem);
        }
        REQUIRE(sum == 30); // (1+7) + (2+8) + (3+9) = 30
      }
    }
  }
}
