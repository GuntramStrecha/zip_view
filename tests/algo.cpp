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
      auto zipped   = gst::ranges::views::zip(v1, v2, v3);
      auto eq_first = [](auto const& a, auto const& b) { return std::get<0>(a) == std::get<0>(b); };
      auto it       = std::ranges::adjacent_find(zipped, eq_first);

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

    auto zipped        = gst::ranges::views::zip(v1, v2, v3);
    auto is_even_first = [](auto const& t) { return std::get<0>(t) % 2 == 0; };
    auto first_gt_6    = [](auto const& t) { return std::get<0>(t) > 6; };
    auto first_gt_10   = [](auto const& t) { return std::get<0>(t) > 10; };

    THEN("all_of returns true when all elements satisfy the predicate")
    {
      bool result = std::ranges::all_of(zipped, is_even_first);
      REQUIRE(result == true);
    }

    THEN("any_of returns true when at least one element satisfies the predicate")
    {
      bool result = std::ranges::any_of(zipped, first_gt_6);
      REQUIRE(result == true);
    }

    THEN("none_of returns true when no elements satisfy the predicate")
    {
      bool result = std::ranges::none_of(zipped, first_gt_10);
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

    auto zipped       = gst::ranges::views::zip(v1, v2, v3);
    auto cmp_by_first = [](auto const& a, auto const& b)
    { return std::get<0>(a) < std::get<0>(b); };

    THEN("binary_search finds existing elements")
    {
      bool found = std::ranges::binary_search(zipped, std::make_tuple(3, 0.0, '\0'), cmp_by_first);
      REQUIRE(found == true);
    }

    THEN("binary_search doesn't find non-existing elements")
    {
      bool found = std::ranges::binary_search(zipped, std::make_tuple(6, 0.0, '\0'), cmp_by_first);
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

      auto is_even_src        = [](auto const& t) { return std::get<0>(t) % 2 == 0; };
      auto src_zip            = gst::ranges::views::zip(v1, v2, v3);
      auto dst_zip            = gst::ranges::views::zip(dest_v1, dest_v2, dest_v3);
      auto [src_end, dst_end] = std::ranges::copy_if(src_zip, dst_zip.begin(), is_even_src);

      THEN("the correct number of elements are copied")
      {
        REQUIRE(src_end == src_zip.end());
        REQUIRE(dst_end == dst_zip.end());
      }

      THEN("only tuples with even v1 values are copied")
      {
        REQUIRE(dest_v1 == std::vector<int>{2, 4, 6});
        REQUIRE(dest_v2 == std::vector<double>{2.2, 4.4, 6.6});
        REQUIRE(dest_v3 == std::vector<char>{'b', 'd', 'f'});
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
      bool result = std::ranges::equal(zip_a, zip_b);
      REQUIRE(result == true);
    }

    THEN("equal returns false for different zipped ranges")
    {
      auto zip_a  = gst::ranges::views::zip(v1a, v2a);
      auto zip_c  = gst::ranges::views::zip(v1c, v2c);
      bool result = std::ranges::equal(zip_a, zip_c);
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
      auto it     = std::ranges::find(zipped, std::make_tuple(3, 3.3, 'c'));

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
      auto is_even = [](auto const& t) { return std::get<0>(t) % 2 == 0; };
      auto zipped  = gst::ranges::views::zip(v1, v2, v3);
      auto it      = std::ranges::find_if(zipped, is_even);

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
      auto is_even = [](auto const& t) { return std::get<0>(t) % 2 == 0; };
      auto zipped  = gst::ranges::views::zip(v1, v2, v3);
      auto it      = std::ranges::find_if_not(zipped, is_even);

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

    auto cmp_by_first = [](auto const& a, auto const& b)
    { return std::get<0>(a) < std::get<0>(b); };

    THEN("is_sorted returns true for sorted zip_view")
    {
      auto sorted_zip = gst::ranges::views::zip(sorted_v1, sorted_v2);
      bool result     = std::ranges::is_sorted(sorted_zip, cmp_by_first);
      REQUIRE(result == true);
    }

    THEN("is_sorted returns false for unsorted zip_view")
    {
      auto unsorted_zip = gst::ranges::views::zip(unsorted_v1, unsorted_v2);
      bool result       = std::ranges::is_sorted(unsorted_zip, cmp_by_first);
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

      bool result = std::ranges::lexicographical_compare(zip_a, zip_b);

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
      auto zip_a              = gst::ranges::views::zip(v1a, v2a);
      auto zip_b              = gst::ranges::views::zip(v1b, v2b);
      auto [first_a, first_b] = std::ranges::mismatch(zip_a, zip_b, std::equal_to<>{});

      THEN("we find the mismatch at position 2")
      {
        REQUIRE(std::get<0>(*first_a) == 3);
        REQUIRE(std::get<0>(*first_b) == 9);
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
      std::ranges::replace(zipped, std::make_tuple(2, 2.2, 'b'), std::make_tuple(9, 9.9, 'z'));

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
      auto const is_even_first = [](auto const& t) { return std::get<0>(t) % 2 == 0; };
      auto const replacement   = std::make_tuple(0, 0.0, 'X');
      auto       zipped        = gst::ranges::views::zip(v1, v2, v3);
      auto       itr           = std::ranges::replace_if(zipped, is_even_first, replacement);

      THEN("the returned iterator points to the end of the range") { REQUIRE(itr == zipped.end()); }

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
      auto itr    = std::ranges::reverse(zipped);

      THEN("the returned iterator points to the end of the range") { REQUIRE(itr == zipped.end()); }

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

      auto src_zip            = gst::ranges::views::zip(v1, v2, v3);
      auto dst_zip            = gst::ranges::views::zip(dest_v1, dest_v2, dest_v3);
      auto [src_end, dst_end] = std::ranges::reverse_copy(src_zip, dst_zip.begin());

      THEN("the returned iterator points to the end of the destination range")
      {
        REQUIRE(src_end == src_zip.end());
        REQUIRE(dst_end == dst_zip.end());
      }

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
      auto zipped            = gst::ranges::views::zip(v1, v2, v3);
      auto [new_first, last] = std::ranges::rotate(zipped, zipped.begin() + 2);

      THEN("the returned iterators point to the new first and last positions")
      {
        REQUIRE(new_first == std::ranges::prev(zipped.end(), 2));
        REQUIRE(last == zipped.end());
      }

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
      std::array<int, 5>    dest_v1;
      std::array<double, 5> dest_v2;
      std::array<short, 5>  dest_v3;

      auto src_zip            = gst::ranges::views::zip(v1, v2, v3);
      auto dst_zip            = gst::ranges::views::zip(dest_v1, dest_v2, dest_v3);
      auto itr_mid            = std::next(src_zip.begin(), 2);
      auto [src_end, dst_end] = std::ranges::rotate_copy(src_zip, itr_mid, dst_zip.begin());

      THEN("the returned iterators point to the end of the source and destination ranges")
      {
        REQUIRE(src_end == src_zip.end());
        REQUIRE(dst_end == dst_zip.end());
      }

      THEN("destination contains rotated elements")
      {
        REQUIRE((dest_v1 == std::array<int, 5>{3, 4, 5, 1, 2}));
        REQUIRE((dest_v2 == std::array<double, 5>{3.3, 4.4, 5.5, 1.1, 2.2}));
        REQUIRE((dest_v3 == std::array<short, 5>{'c', 'd', 'e', 'a', 'b'}));
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
      auto [first, last]  = std::ranges::search(zipped, pattern_zipped);

      THEN("the returned iterators point to the start and end of the found subsequence")
      {
        REQUIRE(first == zipped.begin() + 2);
        REQUIRE(last == zipped.begin() + 4);
      }

      THEN("we find the subsequence")
      {
        REQUIRE(std::get<0>(*first) == 3);
        REQUIRE(std::get<1>(*first) == 'c');
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
      auto zipped        = gst::ranges::views::zip(v1, v2);
      auto [first, last] = std::ranges::search_n(zipped, 3, std::make_tuple(5, 'c'));

      THEN("the returned iterators point to the start and end of the found sequence")
      {
        REQUIRE(first == zipped.begin() + 2);
        REQUIRE(last == zipped.begin() + 5);
      }

      THEN("we find the sequence")
      {
        REQUIRE(std::get<0>(*first) == 5);
        REQUIRE(std::get<1>(*first) == 'c');
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
      auto zip_a          = gst::ranges::views::zip(v1a, v2a);
      auto zip_b          = gst::ranges::views::zip(v1b, v2b);
      auto [end_a, end_b] = std::ranges::swap_ranges(zip_a, zip_b);

      THEN("the iterators point to the end of the ranges")
      {
        REQUIRE(end_a == zip_a.end());
        REQUIRE(end_b == zip_b.end());
      }

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

    WHEN("we conditionally accumulate based on the boolean first element")
    {
      auto cond_accum = [](auto acc, auto const& t)
      { return acc + (std::get<0>(t) ? std::get<1>(t) + std::get<2>(t) : 0); };

      auto zip = gst::ranges::views::zip(v1, v2, v3);
      auto sum = std::ranges::fold_left(zip, 0.0, cond_accum);

      THEN("the sum is correct based on the predicate")
      {
        REQUIRE(sum == Catch::Approx(4.1F + 'a' + 6.3F + 'c'));
      }
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

    WHEN("we apply for_each to double the first element of each tuple")
    {
      auto double_first = [](auto&& t) { std::get<0>(t) *= 2; };
      auto zip          = gst::ranges::views::zip(v1, v2, v3);
      auto [zip_end, _] = std::ranges::for_each(zip, double_first);

      THEN("the returned iterator points to the end of the range")
      {
        REQUIRE(zip_end == zip.end());
      }

      THEN("the first elements are doubled while others remain unchanged")
      {
        REQUIRE(v1 == std::array<int, 3>{2, 4, 6});
      }
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

    WHEN("we count elements in the zipped view with count_if")
    {
      auto is_even_first = [](auto const& t) { return std::get<0>(t) % 2 == 0; };
      auto zip           = gst::ranges::views::zip(v1, v2, v3);
      auto count         = std::ranges::count_if(zip, is_even_first);

      THEN("the count is correct") { REQUIRE(count == 1); }
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

    WHEN("we fill the zipped view")
    {
      auto zip = gst::ranges::views::zip(v1, v2, v3);
      auto end = std::ranges::fill(zip, std::make_tuple(0, 0.0F, 'z'));

      THEN("the returned iterator points to the end of the range") { REQUIRE(end == zip.end()); }

      THEN("the containers are filled with the specified values")
      {
        REQUIRE(v1 == std::array<int, 3>{0, 0, 0});
      }
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

    WHEN("we fill the zipped view with a generator")
    {
      auto generator = [n = 1]() mutable { return std::make_tuple(n++, 0.0F, ' '); };
      auto zip       = gst::ranges::views::zip(v1, v2, v3);
      auto end       = std::ranges::generate(zip, generator);

      THEN("the returned iterator points to the end of the range") { REQUIRE(end == zip.end()); }

      THEN("the containers are filled with generated values")
      {
        REQUIRE(v1 == std::array<int, 3>{1, 2, 3});
      }
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

    WHEN("we remove elements from the zipped view based on a predicate")
    {
      auto zip           = gst::ranges::views::zip(v1, v2, v3);
      auto first_is_true = [](auto const& t) { return std::get<0>(t); };
      auto [ret, last]   = std::ranges::remove_if(zip, first_is_true);

      THEN("the returned iterator points to the new end of the range")
      {
        REQUIRE(ret == std::ranges::next(zip.begin(), 2));
        REQUIRE(last == zip.end());
      }

      THEN("the elements with true in the first container are removed")
      {
        REQUIRE(v1 == std::array<bool, 3>{false, false, false});
        REQUIRE(v2 == std::vector<float>{4.1F, 6.3F, 6.3F, 7.4F});
        REQUIRE(v3 == std::list<char>{'a', 'c', 'c', 'd', 'e'});
      }
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

    WHEN("we transform the zipped views with a unary operation")
    {
      auto               multiply_first_by_2 = [](auto const& t) { return std::get<0>(t) * 2; };
      auto               zip                 = gst::ranges::views::zip(v1, v2, v3);
      std::array<int, 3> res;
      auto [itr1, itr2] = std::ranges::transform(zip, res.begin(), multiply_first_by_2);

      THEN("the returned iterators point to the end of the range")
      {
        REQUIRE(itr1 == zip.end());
        REQUIRE(itr2 == res.end());
      }

      THEN("the transformation is applied correctly")
      {
        REQUIRE(res == std::array<int, 3>{2, 4, 6});
      }
    }
  }
}

SCENARIO("zip_view zips two containers and transforms (binary)", "[algorithms]")
{
  GIVEN("two containers with different element types")
  {
    std::vector<int>    v1{1, 2, 3};
    std::vector<double> v2{4.1, 5.2, 6.3};

    WHEN("we transform the zipped views with a binary operation")
    {
      auto add_firsts = [](auto const& t1, auto const& t2)
      { return std::get<0>(t1) + std::get<0>(t2); };

      auto                zip1 = gst::ranges::views::zip(v1);
      auto                zip2 = gst::ranges::views::zip(v2);
      std::vector<double> res(v1.size());
      std::vector<double> ref{1 + 4.1, 2 + 5.2, 3 + 6.3};
      auto [itr1, itr2, itr3] = std::ranges::transform(zip1, zip2, res.begin(), add_firsts);

      THEN("the returned iterators point to the end of the ranges")
      {
        REQUIRE(itr1 == zip1.end());
        REQUIRE(itr2 == zip2.end());
        REQUIRE(itr3 == res.end());
      }

      THEN("the transformation is applied correctly") { REQUIRE(res == ref); }
    }
  }
}

SCENARIO("std::equal_range works on sorted zip_view", "[algorithms][binary_search]")
{
  GIVEN("Sorted vectors with duplicates")
  {
    std::vector<int>    v1{1, 2, 2, 2, 3, 4, 5};
    std::vector<double> v2{1.1, 2.2, 2.2, 2.2, 3.3, 4.4, 5.5};
    std::vector<char>   v3{'a', 'b', 'b', 'b', 'c', 'd', 'e'};

    WHEN("we find the equal range for a specific tuple")
    {
      auto to_find      = std::make_tuple(2, 2.2, 'b');
      auto zipped       = gst::ranges::views::zip(v1, v2, v3);
      auto [itr1, itr2] = std::ranges::equal_range(zipped, to_find, std::less<>{});

      THEN("the range contains the correct number of elements")
      {
        REQUIRE(std::ranges::distance(itr1, itr2) == 3);
      }

      THEN("all elements in the range are equal to the searched value")
      {
        auto const equal_to_to_find = [&to_find](auto const& t) { return t == to_find; };
        REQUIRE(std::ranges::all_of(itr1, itr2, equal_to_to_find));
      }
    }
  }
}

SCENARIO("std::is_partitioned works on zip_view", "[algorithms][partition]")
{
  GIVEN("A partitioned and a non-partitioned sequence")
  {
    auto                is_even_first = [](auto const& t) { return std::get<0>(t) % 2 == 0; };
    std::vector<int>    partitioned_v1{2, 4, 6, 1, 3, 5};
    std::vector<double> partitioned_v2{2.2, 4.4, 6.6, 1.1, 3.3, 5.5};
    std::vector<int>    not_partitioned_v1{1, 2, 3, 4, 5, 6};
    std::vector<double> not_partitioned_v2{1.1, 2.2, 3.3, 4.4, 5.5, 6.6};

    WHEN("is_partitioned is called on a partitioned sequence")
    {
      auto zipped = gst::ranges::views::zip(partitioned_v1, partitioned_v2);
      bool result = std::ranges::is_partitioned(zipped, is_even_first);

      THEN("the result is true") { REQUIRE(result == true); }
    }

    WHEN("is_partitioned is called on a non-partitioned sequence")
    {
      auto zipped = gst::ranges::views::zip(not_partitioned_v1, not_partitioned_v2);
      bool result = std::ranges::is_partitioned(zipped, is_even_first);

      THEN("the result is false") { REQUIRE(result == false); }
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
      auto cmp_by_first = [](auto const& a, auto const& b)
      { return std::get<0>(a) < std::get<0>(b); };
      auto zipped = gst::ranges::views::zip(v1, v2, v3);
      auto it     = std::ranges::is_sorted_until(zipped, cmp_by_first);

      THEN("we find the first unsorted element")
      {
        REQUIRE(it == std::ranges::next(zipped.begin(), 3));
        REQUIRE((*it == std::make_tuple(2, Catch::Approx(2.2), 'd')));
      }
    }
  }
}

SCENARIO("std::lower_bound and std::upper_bound work on sorted zip_view",
         "[algorithms][binary_search]")
{
  GIVEN("Sorted vectors")
  {
    auto cmp_by_first = [](auto const& a, auto const& b)
    { return std::get<0>(a) < std::get<0>(b); };

    std::vector<int>    v1{1, 2, 2, 3, 4, 4, 4, 5};
    std::vector<double> v2{1.1, 2.1, 2.2, 3.3, 4.1, 4.2, 4.3, 5.5};
    std::vector<char>   v3{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    auto                zipped  = gst::ranges::views::zip(v1, v2, v3);
    auto                to_find = std::make_tuple(4, 0.0, '\0');

    WHEN("we find lower_bound for value 4")
    {
      auto it = std::ranges::lower_bound(zipped, to_find, cmp_by_first);

      THEN("we get the first element not less than 4")
      {
        REQUIRE(it != zipped.end());
        REQUIRE((*it == std::make_tuple(4, Catch::Approx(4.1), 'e')));
      }
    }

    WHEN("we find upper_bound for value 4")
    {
      auto it = std::ranges::upper_bound(zipped, to_find, cmp_by_first);

      THEN("we get the first element greater than 4")
      {
        REQUIRE(it != zipped.end());
        REQUIRE((*it == std::make_tuple(5, Catch::Approx(5.5), 'h')));
      }
    }
  }
}

SCENARIO("std::max_element works on zip_view", "[algorithms][minmax]")
{
  GIVEN("Three vectors")
  {
    auto cmp_by_first = [](auto const& a, auto const& b)
    { return std::get<0>(a) < std::get<0>(b); };

    std::vector<int>    v1{3, 1, 4, 1, 5, 9, 2};
    std::vector<double> v2{3.3, 1.1, 4.4, 1.2, 5.5, 9.9, 2.2};
    std::vector<char>   v3{'c', 'a', 'd', 'b', 'e', 'i', 'f'};

    auto zipped = gst::ranges::views::zip(v1, v2, v3);

    WHEN("we find the maximum element by first component")
    {
      auto it = std::ranges::max_element(zipped, cmp_by_first);

      THEN("we get the tuple with maximum first element")
      {
        REQUIRE(it != zipped.end());
        REQUIRE((*it == std::make_tuple(9, Catch::Approx(9.9), 'i')));
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
      auto cmp_by_first = [](auto const& a, auto const& b)
      { return std::get<0>(a) < std::get<0>(b); };
      auto it = std::ranges::min_element(zipped, cmp_by_first);

      THEN("we get the tuple with minimum first element")
      {
        REQUIRE(it != zipped.end());
        REQUIRE((*it == std::make_tuple(1, Catch::Approx(1.1), 'a')));
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
      auto cmp_by_first = [](auto const& a, auto const& b)
      { return std::get<0>(a) < std::get<0>(b); };
      auto zipped          = gst::ranges::views::zip(v1, v2, v3);
      auto [first, second] = std::ranges::minmax_element(zipped, cmp_by_first);

      THEN("we get both minimum and maximum")
      {
        REQUIRE(first != zipped.end());
        REQUIRE(second != zipped.end());
        REQUIRE((*first == std::make_tuple(1, Catch::Approx(1.1), 'a')));
        REQUIRE((*second == std::make_tuple(9, Catch::Approx(9.9), 'i')));
      }
    }
  }
}

SCENARIO("std::next_permutation and std::prev_permutation work on zip_view",
         "[algorithms][permutation]")
{
  GIVEN("Three sorted vectors")
  {
    auto cmp_by_first = [](auto const& a, auto const& b)
    { return std::get<0>(a) < std::get<0>(b); };

    WHEN("we generate permutations with next_permutation")
    {
      std::vector<int>  v1{1, 2, 3};
      std::vector<char> v2{'a', 'b', 'c'};
      auto              zipped = gst::ranges::views::zip(v1, v2);

      THEN("the first permutation is generated correctly")
      {
        auto result = std::ranges::next_permutation(zipped, cmp_by_first);
        REQUIRE(result.found);
        REQUIRE(result.in == zipped.end());
        REQUIRE(v1 == std::vector<int>{1, 3, 2});
        REQUIRE(v2 == std::vector<char>{'a', 'c', 'b'});

        AND_THEN("the second permutation is generated correctly")
        {
          result = std::ranges::next_permutation(zipped, cmp_by_first);
          REQUIRE(result.found);
          REQUIRE(result.in == zipped.end());
          REQUIRE(v1 == std::vector<int>{2, 1, 3});
          REQUIRE(v2 == std::vector<char>{'b', 'a', 'c'});

          AND_THEN("the third permutation is generated correctly")
          {
            result = std::ranges::next_permutation(zipped, cmp_by_first);
            REQUIRE(result.found);
            REQUIRE(result.in == zipped.end());
            REQUIRE(v1 == std::vector<int>{2, 3, 1});
            REQUIRE(v2 == std::vector<char>{'b', 'c', 'a'});

            AND_THEN("the fourth permutation is generated correctly")
            {
              result = std::ranges::next_permutation(zipped, cmp_by_first);
              REQUIRE(result.found);
              REQUIRE(result.in == zipped.end());
              REQUIRE(v1 == std::vector<int>{3, 1, 2});
              REQUIRE(v2 == std::vector<char>{'c', 'a', 'b'});

              AND_THEN("the last permutation is generated correctly")
              {
                result = std::ranges::next_permutation(zipped, cmp_by_first);
                REQUIRE(result.found);
                REQUIRE(result.in == zipped.end());
                REQUIRE(v1 == std::vector<int>{3, 2, 1});
                REQUIRE(v2 == std::vector<char>{'c', 'b', 'a'});

                AND_THEN("we wrap around to the first permutation")
                {
                  result = std::ranges::next_permutation(zipped, cmp_by_first);
                  REQUIRE_FALSE(result.found);
                  REQUIRE(result.in == zipped.end());
                  REQUIRE(v1 == std::vector<int>{1, 2, 3});
                  REQUIRE(v2 == std::vector<char>{'a', 'b', 'c'});
                }
              }
            }
          }
        }
      }
    }

    WHEN("we generate permutations with prev_permutation")
    {
      std::vector<int>  v1     = {1, 2, 3};
      std::vector<char> v2     = {'a', 'b', 'c'};
      auto              zipped = gst::ranges::views::zip(v1, v2);

      THEN("we wrap around to the last permutation")
      {
        auto result = std::ranges::prev_permutation(zipped, cmp_by_first);
        REQUIRE_FALSE(result.found);
        REQUIRE(result.in == zipped.end());
        REQUIRE(v1 == std::vector<int>{3, 2, 1});
        REQUIRE(v2 == std::vector<char>{'c', 'b', 'a'});

        AND_THEN("the second previous permutation is generated correctly")
        {
          result = std::ranges::prev_permutation(zipped, cmp_by_first);
          REQUIRE(result.found);
          REQUIRE(result.in == zipped.end());
          REQUIRE(v1 == std::vector<int>{3, 1, 2});
          REQUIRE(v2 == std::vector<char>{'c', 'a', 'b'});

          AND_THEN("the third previous permutation is generated correctly")
          {
            result = std::ranges::prev_permutation(zipped, cmp_by_first);
            REQUIRE(result.found);
            REQUIRE(result.in == zipped.end());
            REQUIRE(v1 == std::vector<int>{2, 3, 1});
            REQUIRE(v2 == std::vector<char>{'b', 'c', 'a'});

            AND_THEN("the fourth previous permutation is generated correctly")
            {
              result = std::ranges::prev_permutation(zipped, cmp_by_first);
              REQUIRE(result.found);
              REQUIRE(result.in == zipped.end());
              REQUIRE(v1 == std::vector<int>{2, 1, 3});
              REQUIRE(v2 == std::vector<char>{'b', 'a', 'c'});

              AND_THEN("the last previous permutation is generated correctly")
              {
                result = std::ranges::prev_permutation(zipped, cmp_by_first);
                REQUIRE(result.found);
                REQUIRE(result.in == zipped.end());
                REQUIRE(v1 == std::vector<int>{1, 3, 2});
                REQUIRE(v2 == std::vector<char>{'a', 'c', 'b'});
              }
            }
          }
        }
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
      auto cmp_by_first = [](auto const& a, auto const& b)
      { return std::get<0>(a) < std::get<0>(b); };
      auto zipped = gst::ranges::views::zip(keys, values);
      std::nth_element(zipped.begin(), zipped.begin() + 3, zipped.end(), cmp_by_first);

      THEN("the element at position 3 has key 5 (4th smallest)")
      {
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
      auto cmp_by_first = [](auto const& a, auto const& b)
      { return std::get<0>(a) < std::get<0>(b); };
      auto zipped = gst::ranges::views::zip(v1, v2, v3);
      auto end    = std::ranges::partial_sort(zipped, std::next(zipped.begin(), 3), cmp_by_first);

      THEN("the returned iterator points to the end of the sorted range")
      {
        REQUIRE(end == zipped.end());
      }

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
    std::vector<short>       v3{'a', 'b', 'c', 'd', 'e', 'f'};

    WHEN("we partition by even numbers")
    {
      auto is_even         = [](auto const& t) { return std::get<0>(t) % 2 == 0; };
      auto zipped          = gst::ranges::views::zip(v1, v2, v3);
      auto [it_bound, end] = std::ranges::partition(zipped, is_even);

      THEN("the end iterator remains unchanged") { REQUIRE(end == zipped.end()); }

      THEN("the return value points to the partition boundary")
      {
        REQUIRE(it_bound == std::next(zipped.begin(), 3));
      }

      THEN("even elements come first in the first container")
      {
        auto is_even_val = [](auto const arg) { return arg % 2 == 0; };
        auto is_odd_val  = [](auto const arg) { return arg % 2 != 0; };
        REQUIRE(std::ranges::all_of(v1.begin(), std::next(v1.begin(), 3), is_even_val));
        REQUIRE(std::ranges::all_of(std::next(v1.begin(), 3), v1.end(), is_odd_val));
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
      auto zipped        = gst::ranges::views::zip(v1, v2);
      auto is_even_first = [](auto const& t) { return std::get<0>(t) % 2 == 0; };
      auto it            = std::ranges::partition_point(zipped, is_even_first);

      THEN("we find the boundary between partitions")
      {
        REQUIRE(it == std::next(zipped.begin(), 3));
        REQUIRE((*it == std::make_tuple(1, Catch::Approx(1.1))));
      }
    }
  }
}

SCENARIO("sort works on random access zip_view", "[algorithms]")
{
  GIVEN("Two vectors where first should be sorted and second follows")
  {
    std::vector<int>    keys{3, 7, 4, 1, 5, 9, 2, 6};
    std::vector<double> values{30.0, 70.0, 40.0, 10.0, 50.0, 90.0, 20.0, 60.0};

    WHEN("we sort the zip_view by the key")
    {
      auto zipped     = gst::ranges::views::zip(keys, values);
      auto proj_first = [](auto const& t) { return std::get<0>(t); };
      std::ranges::sort(zipped, std::less<>(), proj_first);

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
      auto zipped     = gst::ranges::views::zip(keys, names, pairs);
      auto proj_first = [](auto const& t) { return std::get<0>(t); };
      std::ranges::sort(zipped, std::less<>(), proj_first);

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
      auto zipped        = gst::ranges::views::zip(v1, v2, v3);
      auto is_even_first = [](auto const& t) { return std::get<0>(t) % 2 == 0; };
      auto [pivot, end]  = std::ranges::stable_partition(zipped, is_even_first);

      THEN("the return value points to the partition boundary")
      {
        REQUIRE(pivot != zipped.end());
        REQUIRE(pivot == std::next(zipped.begin(), 3));
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
      auto zipped     = gst::ranges::views::zip(v1, v2, v3);
      auto proj_first = [](auto const& t) { return std::get<0>(t); };
      std::ranges::stable_sort(zipped, std::less<>(), proj_first);

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
      auto eq_by_first = [](auto const& a, auto const& b)
      { return std::get<0>(a) == std::get<0>(b); };
      auto zipped           = gst::ranges::views::zip(v1, v2, v3);
      auto [new_last, last] = std::ranges::unique(zipped, eq_by_first);

      THEN("the returned iterator points to the new end of the range")
      {
        REQUIRE(new_last == std::next(zipped.begin(), 4));
        REQUIRE(last == zipped.end());
      }

      THEN("consecutive duplicates are removed")
      {
        REQUIRE(std::vector<int>(v1.begin(), v1.begin() + 4) == std::vector<int>{1, 2, 3, 4});
        REQUIRE(std::vector<std::string>(v2.begin(), v2.begin() + 4) ==
                std::vector<std::string>{"a", "c", "e", "g"});
        REQUIRE(std::vector<double>(v3.begin(), v3.begin() + 4) ==
                std::vector<double>{1.1, 2.1, 3.1, 4.1});
      }
    }
  }
}

SCENARIO("Using std::for_each on nested zip_views", "[zip_view][nested][algo]")
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
    int  sum         = 0;
    auto collect_sum = [&sum](auto elem)
    {
      auto t0  = std::get<0>(elem);
      sum     += std::get<0>(t0) + std::get<1>(t0);
    };
    auto [zip_end, _] = std::ranges::for_each(nested, collect_sum);
    REQUIRE(zip_end == nested.end());
    REQUIRE(sum == 21);
  }

  THEN("std::for_each can modify elements through nested zip_view")
  {
    auto multiply_first_by_10 = [](auto&& elem)
    {
      auto t0          = std::get<0>(elem);
      std::get<0>(t0) *= 10;
    };
    auto [zip_end2, _2] = std::ranges::for_each(nested, multiply_first_by_10);
    REQUIRE(zip_end2 == nested.end());
    REQUIRE(v1 == std::vector<int>{10, 20, 30});
  }
}

SCENARIO("Using std::count_if on nested zip_views", "[zip_view][nested][algo]")
{
  std::vector<int> v1 = {1, 2, 3, 4, 5};
  std::vector<int> v2 = {2, 4, 6, 8, 10};
  std::vector<int> v3 = {1, 3, 5, 7, 9};

  auto nested = gst::ranges::views::zip(gst::ranges::views::zip(v1, v2), v3);

  THEN("std::count_if works on nested zip_views")
  {
    auto v1_greater_than_2 = [](auto elem)
    {
      auto t0 = std::get<0>(elem);
      return std::get<0>(t0) > 2;
    };
    auto count = std::ranges::count_if(nested, v1_greater_than_2);
    REQUIRE(count == 3);
  }

  THEN("std::count_if with complex predicate on nested elements")
  {
    auto complex_pred = [](auto elem)
    {
      auto t0      = std::get<0>(elem);
      auto regular = std::get<1>(elem);
      return std::get<1>(t0) % 4 == 0 && regular % 2 == 1;
    };
    auto count = std::ranges::count_if(nested, complex_pred);
    REQUIRE(count == 2);
  }
}

SCENARIO("Using std::transform on nested zip_views", "[zip_view][nested][algo]")
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
    auto extract_and_add = [](auto elem)
    {
      auto t0 = std::get<0>(elem);
      auto t1 = std::get<1>(elem);
      return std::get<0>(t0) + std::get<1>(t1);
    };
    std::ranges::transform(nested, std::back_inserter(results), extract_and_add);
    REQUIRE(results == std::vector<int>{101, 202, 303});
  }
}

SCENARIO("Using std::any_of and std::all_of on nested zip_views", "[zip_view][nested][algo]")
{
  std::vector<int> v1 = {2, 4, 6};
  std::vector<int> v2 = {1, 3, 5};
  std::vector<int> v3 = {10, 20, 30};

  auto nested = gst::ranges::views::zip(gst::ranges::views::zip(v1, v2), v3);

  THEN("std::any_of works on nested zip_views")
  {
    auto has_even_pred = [](auto elem)
    {
      auto t0 = std::get<0>(elem);
      return std::get<0>(t0) % 2 == 0;
    };
    bool has_even_in_first = std::ranges::any_of(nested, has_even_pred);
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

SCENARIO("Using std::find_if on nested zip_views", "[zip_view][nested][algo]")
{
  std::vector<int> v1 = {1, 2, 3, 4, 5};
  std::vector<int> v2 = {10, 20, 30, 40, 50};
  std::vector<int> v3 = {5, 4, 3, 2, 1};

  auto zip1   = gst::ranges::views::zip(v1, v2);
  auto zip2   = gst::ranges::views::zip(v2, v3);
  auto nested = gst::ranges::views::zip(zip1, zip2);

  THEN("std::find_if can locate specific nested elements")
  {
    auto find_v1_eq_3 = [](auto elem)
    {
      auto t0 = std::get<0>(elem);
      return std::get<0>(t0) == 3;
    };
    auto it = std::ranges::find_if(nested, find_v1_eq_3);

    REQUIRE(it != nested.end());
    auto found = *it;
    auto t0    = std::get<0>(found);
    REQUIRE(std::get<1>(t0) == 30);
  }
}

SCENARIO("Using std::fold_left on nested zip_views", "[zip_view][nested][algo]")
{
  std::vector<int> v1 = {1, 2, 3};
  std::vector<int> v2 = {4, 5, 6};
  std::vector<int> v3 = {7, 8, 9};

  auto nested = gst::ranges::views::zip(gst::ranges::views::zip(v1, v2), v3);

  THEN("std::fold_left can sum nested elements")
  {
    auto fold_sum = [](int acc, auto elem)
    {
      auto t0 = std::get<0>(elem);
      return acc + std::get<0>(t0) + std::get<1>(elem);
    };
    int sum = std::ranges::fold_left(nested, 0, fold_sum);
    REQUIRE(sum == 30);
  }
}

SCENARIO("Using std::copy_if with nested zip_views", "[zip_view][nested][algo]")
{
  std::vector<int> v1 = {1, 2, 3, 4, 5};
  std::vector<int> v2 = {10, 20, 30, 40, 50};
  std::vector<int> v3 = {2, 4, 6, 8, 10};

  auto             nested = gst::ranges::views::zip(gst::ranges::views::zip(v1, v2), v3);
  std::vector<int> selected;

  THEN("std::copy_if can filter and extract from nested zip_views")
  {
    auto select_and_append = [&selected](auto elem)
    {
      auto t0 = std::get<0>(elem);
      if (std::get<0>(t0) > 2) selected.push_back(std::get<0>(t0));
    };
    std::ranges::for_each(nested, select_and_append);
    REQUIRE(selected == std::vector<int>{3, 4, 5});
  }
}

SCENARIO("For-each on inline temporary nested zip_views", "[zip_view][nested][algo]")
{
  std::vector<int> v1 = {1, 2, 3, 4};
  std::vector<int> v2 = {10, 20, 30, 40};
  std::vector<int> v3 = {100, 200, 300, 400};
  std::vector<int> v4 = {5, 6, 7, 8};

  THEN("Can apply std::for_each directly to temporary nested zip_view")
  {
    int  sum            = 0;
    auto tmp_accumulate = [&sum](auto elem)
    {
      auto t0  = std::get<0>(elem);
      auto t1  = std::get<1>(elem);
      sum     += std::get<0>(t0) + std::get<0>(t1);
    };
    auto [tmp_it, _tmp] = std::ranges::for_each(
      gst::ranges::views::zip(gst::ranges::views::zip(v1, v2), gst::ranges::views::zip(v3, v4)),
      tmp_accumulate);
    (void)tmp_it;
    REQUIRE(sum == 1010);
  }

  THEN("Can modify through std::for_each on temporary nested zip_view")
  {
    auto tmp_double_second = [](auto&& elem)
    {
      auto t0          = std::get<0>(elem);
      std::get<1>(t0) *= 2;
    };
    std::ranges::for_each(gst::ranges::views::zip(gst::ranges::views::zip(v1, v2), v4),
                          tmp_double_second);
    REQUIRE(v2 == std::vector<int>{20, 40, 60, 80});
  }
}

SCENARIO("Count_if on inline temporary nested zip_views", "[zip_view][nested][algo]")
{
  std::vector<int> v1 = {1, 2, 3, 4, 5};
  std::vector<int> v2 = {2, 4, 6, 8, 10};
  std::vector<int> v3 = {10, 20, 30, 40, 50};

  THEN("std::count_if works directly on temporary nested zip_view")
  {
    auto tmp_count_pred = [](auto elem)
    {
      auto t0 = std::get<0>(elem);
      return std::get<0>(t0) > 2 && std::get<1>(t0) % 4 == 0;
    };
    auto count = std::ranges::count_if(gst::ranges::views::zip(gst::ranges::views::zip(v1, v2), v3),
                                       tmp_count_pred);
    REQUIRE(count == 1);
  }
}

SCENARIO("Any_of on inline temporary nested zip_views", "[zip_view][nested][algo]")
{
  std::vector<int> v1 = {1, 3, 5, 7};
  std::vector<int> v2 = {2, 4, 6, 8};
  std::vector<int> v3 = {10, 20, 30, 40};

  THEN("std::any_of works on temporary nested zip_view")
  {
    auto tmp_any_pred = [](auto elem)
    {
      auto t0 = std::get<0>(elem);
      return std::get<0>(t0) + std::get<1>(t0) + std::get<1>(elem) > 50;
    };
    bool has_sum_greater_than_50 = std::ranges::any_of(
      gst::ranges::views::zip(gst::ranges::views::zip(v1, v2), v3), tmp_any_pred);
    REQUIRE(has_sum_greater_than_50);
  }
}

SCENARIO("Transform on inline temporary nested zip_views", "[zip_view][nested][algo]")
{
  std::vector<int> v1 = {1, 2, 3};
  std::vector<int> v2 = {4, 5, 6};
  std::vector<int> v3 = {7, 8, 9};
  std::vector<int> v4 = {10, 11, 12};
  std::vector<int> results;

  THEN("std::transform works on temporary nested zip_view")
  {
    auto tmp_transform = [](auto elem)
    {
      auto t0 = std::get<0>(elem);
      auto t1 = std::get<1>(elem);
      return std::get<0>(t0) + std::get<1>(t0) + std::get<0>(t1) + std::get<1>(t1);
    };
    std::ranges::transform(
      gst::ranges::views::zip(gst::ranges::views::zip(v1, v2), gst::ranges::views::zip(v3, v4)),
      std::back_inserter(results),
      tmp_transform);
    REQUIRE(results == std::vector<int>{22, 26, 30});
  }
}

SCENARIO("Find_if on inline temporary nested zip_views", "[zip_view][nested][algo]")
{
  std::vector<int> v1 = {10, 20, 30, 40, 50};
  std::vector<int> v2 = {1, 2, 3, 4, 5};
  std::vector<int> v3 = {5, 4, 3, 2, 1};

  THEN("std::find_if locates element in temporary nested zip_view")
  {
    auto temp_zip = gst::ranges::views::zip(gst::ranges::views::zip(v1, v2), v3);
    auto tmp_find = [](auto elem)
    {
      auto t0 = std::get<0>(elem);
      return std::get<0>(t0) == 30;
    };
    auto it = std::ranges::find_if(temp_zip, tmp_find);

    REQUIRE(it != temp_zip.end());
    auto found = *it;
    auto t0    = std::get<0>(found);
    REQUIRE(std::get<1>(t0) == 3);
    REQUIRE(std::get<1>(found) == 3);
  }
}

SCENARIO("Accumulate on inline temporary nested zip_views", "[zip_view][nested][algo]")
{
  std::vector<int> v1 = {1, 2, 3};
  std::vector<int> v2 = {10, 20, 30};
  std::vector<int> v3 = {100, 200, 300};

  THEN("std::fold_left works on temporary nested zip_view")
  {
    auto temp     = gst::ranges::views::zip(gst::ranges::views::zip(v1, v2), v3);
    auto tmp_fold = [](int acc, auto elem)
    {
      auto t0 = std::get<0>(elem);
      return acc * std::get<0>(t0);
    };
    int product = std::ranges::fold_left(temp, 1, tmp_fold);
    REQUIRE(product == 6);
  }
}

SCENARIO("All_of on deeply nested temporary zip_views", "[zip_view][nested][algo]")
{
  std::vector<int> v1 = {1, 2, 3};
  std::vector<int> v2 = {4, 5, 6};
  std::vector<int> v3 = {7, 8, 9};
  std::vector<int> v4 = {10, 11, 12};
  std::vector<int> v5 = {2, 2, 2};

  THEN("std::all_of works on deeply nested temporary zip_view")
  {
    auto tmp_all_pred = [](auto elem) { return std::get<1>(elem) > 0; };
    bool all_positive = std::ranges::all_of(
      gst::ranges::views::zip(
        gst::ranges::views::zip(gst::ranges::views::zip(v1, v2), gst::ranges::views::zip(v3, v4)),
        v5),
      tmp_all_pred);
    REQUIRE(all_positive);
  }
}

SCENARIO("Chaining algorithms on inline temporary nested zip_views", "[zip_view][nested][algo]")
{
  std::vector<int> v1 = {1, 2, 3, 4, 5};
  std::vector<int> v2 = {10, 20, 30, 40, 50};
  std::vector<int> v3 = {5, 4, 3, 2, 1};

  THEN("Can chain multiple algorithm operations on temporary nested zip_view")
  {
    auto temp = gst::ranges::views::zip(gst::ranges::views::zip(v1, v2), v3);

    auto count_pred = [](auto elem)
    {
      auto t0 = std::get<0>(elem);
      return std::get<0>(t0) > 2;
    };
    auto count = std::ranges::count_if(temp, count_pred);
    REQUIRE(count == 3);

    auto find_pred = [](auto elem) { return std::get<1>(elem) < 3; };
    auto it        = std::ranges::find_if(temp, find_pred);
    REQUIRE(it != temp.end());

    auto sum_proj = [](int acc, auto elem)
    {
      auto t0 = std::get<0>(elem);
      return acc + std::get<1>(t0);
    };
    int sum = std::ranges::fold_left(temp, 0, sum_proj);
    REQUIRE(sum == 150);
  }
}

SCENARIO("Range-based for on inline temporary nested zip_views", "[zip_view][nested][algo]")
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
    REQUIRE(sum == 30);
  }
}
