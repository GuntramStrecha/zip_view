#include "zip_view.hpp"

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
#include <catch2/catch_test_macros.hpp>
#pragma clang diagnostic pop
#else
#include <catch2/catch_test_macros.hpp>
#endif

#include <algorithm>
#include <array>
#include <deque>
#include <forward_list>
#include <iterator>
#include <list>
#include <string>
#include <type_traits>
#include <vector>

SCENARIO("zip_view iterator category is computed from weakest underlying iterator", "[iterator_category]")
{
  GIVEN("Two vectors (random access containers)")
  {
    std::vector<int>    vec1 = {1, 2, 3};
    std::vector<double> vec2 = {4.0, 5.0, 6.0};

    WHEN("we create a zip_view over them")
    {
      auto zipped = gst::ranges::views::zip(vec1, vec2);
      using iterator_type = decltype(zipped.begin());
      using category      = typename std::iterator_traits<iterator_type>::iterator_category;

      THEN("the iterator category should be random_access_iterator_tag")
      {
        STATIC_REQUIRE(std::is_same<category, std::random_access_iterator_tag>::value);
      }
    }
  }

  GIVEN("Three random access containers (vector, array, deque)")
  {
    std::vector<int>    vec = {1, 2, 3};
    std::array<int, 3>  arr = {4, 5, 6};
    std::deque<int>     deq = {7, 8, 9};

    WHEN("we create a zip_view over them")
    {
      auto zipped = gst::ranges::views::zip(vec, arr, deq);
      using iterator_type = decltype(zipped.begin());
      using category      = typename std::iterator_traits<iterator_type>::iterator_category;

      THEN("the iterator category should be random_access_iterator_tag")
      {
        STATIC_REQUIRE(std::is_same<category, std::random_access_iterator_tag>::value);
      }
    }
  }

  GIVEN("A vector and a list (bidirectional container)")
  {
    std::vector<int>  vec = {1, 2, 3};
    std::list<double> lst = {4.0, 5.0, 6.0};

    WHEN("we create a zip_view over them")
    {
      auto zipped = gst::ranges::views::zip(vec, lst);
      using iterator_type = decltype(zipped.begin());
      using category      = typename std::iterator_traits<iterator_type>::iterator_category;

      THEN("the iterator category should be bidirectional_iterator_tag")
      {
        STATIC_REQUIRE(std::is_same<category, std::bidirectional_iterator_tag>::value);
      }
    }
  }

  GIVEN("Two lists (bidirectional containers)")
  {
    std::list<int>    lst1 = {1, 2, 3};
    std::list<double> lst2 = {4.0, 5.0, 6.0};

    WHEN("we create a zip_view over them")
    {
      auto zipped = gst::ranges::views::zip(lst1, lst2);
      using iterator_type = decltype(zipped.begin());
      using category      = typename std::iterator_traits<iterator_type>::iterator_category;

      THEN("the iterator category should be bidirectional_iterator_tag")
      {
        STATIC_REQUIRE(std::is_same<category, std::bidirectional_iterator_tag>::value);
      }
    }
  }

  GIVEN("A vector and a forward_list (forward container)")
  {
    std::vector<int>       vec  = {1, 2, 3};
    std::forward_list<int> flst = {4, 5, 6};

    WHEN("we create a zip_view over them")
    {
      auto zipped = gst::ranges::views::zip(vec, flst);
      using iterator_type = decltype(zipped.begin());
      using category      = typename std::iterator_traits<iterator_type>::iterator_category;

      THEN("the iterator category should be forward_iterator_tag")
      {
        STATIC_REQUIRE(std::is_same<category, std::forward_iterator_tag>::value);
      }
    }
  }

  GIVEN("A vector, list, and forward_list")
  {
    std::vector<int>       vec  = {1, 2, 3};
    std::list<double>      lst  = {4.0, 5.0, 6.0};
    std::forward_list<int> flst = {7, 8, 9};

    WHEN("we create a zip_view over them")
    {
      auto zipped = gst::ranges::views::zip(vec, lst, flst);
      using iterator_type = decltype(zipped.begin());
      using category      = typename std::iterator_traits<iterator_type>::iterator_category;

      THEN("the iterator category should be forward_iterator_tag (weakest)")
      {
        STATIC_REQUIRE(std::is_same<category, std::forward_iterator_tag>::value);
      }
    }
  }
}

SCENARIO("zip_view random access iterator operations", "[random_access]")
{
  GIVEN("Two vectors")
  {
    std::vector<int>    vec1 = {1, 2, 3, 4, 5};
    std::vector<double> vec2 = {10.0, 20.0, 30.0, 40.0, 50.0};

    auto zipped = gst::ranges::views::zip(vec1, vec2);
    auto it     = zipped.begin();
    auto end    = zipped.end();

    THEN("we can use operator+")
    {
      auto it2 = it + 2;
      REQUIRE(std::get<0>(*it2) == 3);
      REQUIRE(std::get<1>(*it2) == 30.0);
    }

    THEN("we can use n + iterator")
    {
      auto it2 = 3 + it;
      REQUIRE(std::get<0>(*it2) == 4);
      REQUIRE(std::get<1>(*it2) == 40.0);
    }

    THEN("we can use operator-")
    {
      auto it2 = end - 2;
      REQUIRE(std::get<0>(*it2) == 4);
      REQUIRE(std::get<1>(*it2) == 40.0);
    }

    THEN("we can calculate distance with operator- between iterators")
    {
      REQUIRE(end - it == 5);
      REQUIRE((it + 3) - it == 3);
    }

    THEN("we can use operator[]")
    {
      REQUIRE(std::get<0>(it[0]) == 1);
      REQUIRE(std::get<0>(it[2]) == 3);
      REQUIRE(std::get<1>(it[4]) == 50.0);
    }

    THEN("we can use operator+=")
    {
      auto it2 = it;
      it2 += 3;
      REQUIRE(std::get<0>(*it2) == 4);
    }

    THEN("we can use operator-=")
    {
      auto it2 = end;
      it2 -= 2;
      REQUIRE(std::get<0>(*it2) == 4);
    }

    THEN("we can use relational operators")
    {
      auto it2 = it + 2;
      REQUIRE(it < it2);
      REQUIRE(it2 > it);
      REQUIRE(it <= it2);
      REQUIRE(it2 >= it);
      REQUIRE(it <= it);
      REQUIRE(it >= it);
    }
  }
}

SCENARIO("zip_view bidirectional iterator operations", "[bidirectional]")
{
  GIVEN("Two lists")
  {
    std::list<int>    lst1 = {1, 2, 3, 4, 5};
    std::list<double> lst2 = {10.0, 20.0, 30.0, 40.0, 50.0};

    auto zipped = gst::ranges::views::zip(lst1, lst2);
    auto it     = zipped.begin();

    THEN("we can use operator++")
    {
      ++it;
      REQUIRE(std::get<0>(*it) == 2);
    }

    THEN("we can use operator++(int)")
    {
      auto it_prev = it++;
      REQUIRE(std::get<0>(*it_prev) == 1);
      REQUIRE(std::get<0>(*it) == 2);
    }

    THEN("we can use operator--")
    {
      ++it;
      ++it;
      --it;
      REQUIRE(std::get<0>(*it) == 2);
    }

    THEN("we can use operator--(int)")
    {
      ++it;
      ++it;
      auto it_prev = it--;
      REQUIRE(std::get<0>(*it_prev) == 3);
      REQUIRE(std::get<0>(*it) == 2);
    }
  }
}

SCENARIO("std::sort works on random access zip_view", "[algorithms][sort]")
{
  GIVEN("Two vectors where first should be sorted and second follows")
  {
    std::vector<int>    keys   = {3, 1, 4, 1, 5, 9, 2, 6};
    std::vector<double> values = {30.0, 10.0, 40.0, 11.0, 50.0, 90.0, 20.0, 60.0};

    WHEN("we sort the zip_view by the key")
    {
      auto zipped = gst::ranges::views::zip(keys, values);
      std::sort(zipped.begin(),
                zipped.end(),
                [](auto const& a, auto const& b) { return std::get<0>(a) < std::get<0>(b); });

      THEN("both containers are sorted according to the keys")
      {
        REQUIRE(keys == std::vector<int>{1, 1, 2, 3, 4, 5, 6, 9});
        // Values should follow their respective keys (note: std::sort is not stable,
        // so for equal keys the relative order may vary, but values should still match keys)
        // Original pairs: (3,30), (1,10), (4,40), (1,11), (5,50), (9,90), (2,20), (6,60)
        // After sorting, each value should match its original key
        REQUIRE(values == std::vector<double>{10.0, 11.0, 20.0, 30.0, 40.0, 50.0, 60.0, 90.0});
      }
    }
  }

  GIVEN("Three vectors to be sorted together")
  {
    std::vector<int>         keys    = {5, 2, 8, 1, 9};
    std::vector<std::string> names   = {"five", "two", "eight", "one", "nine"};
    std::vector<double>      weights = {5.5, 2.2, 8.8, 1.1, 9.9};

    WHEN("we sort by key")
    {
      auto zipped = gst::ranges::views::zip(keys, names, weights);
      std::sort(zipped.begin(),
                zipped.end(),
                [](auto const& a, auto const& b) { return std::get<0>(a) < std::get<0>(b); });

      THEN("all three containers are sorted consistently")
      {
        REQUIRE(keys == std::vector<int>{1, 2, 5, 8, 9});
        REQUIRE(names == std::vector<std::string>{"one", "two", "five", "eight", "nine"});
        REQUIRE(weights == std::vector<double>{1.1, 2.2, 5.5, 8.8, 9.9});
      }
    }
  }
}

SCENARIO("std::nth_element works on random access zip_view", "[algorithms][nth_element]")
{
  GIVEN("Two vectors")
  {
    std::vector<int>    keys   = {5, 2, 8, 1, 9, 3, 7};
    std::vector<double> values = {50.0, 20.0, 80.0, 10.0, 90.0, 30.0, 70.0};

    WHEN("we find the 3rd smallest element")
    {
      auto zipped = gst::ranges::views::zip(keys, values);
      std::nth_element(zipped.begin(),
                       zipped.begin() + 3,
                       zipped.end(),
                       [](auto const& a, auto const& b) { return std::get<0>(a) < std::get<0>(b); });

      THEN("the element at position 3 has key 5 (4th smallest)")
      {
        // After nth_element, position 3 should have the element that would be there if sorted
        // Sorted keys would be: 1, 2, 3, 5, 7, 8, 9
        // So position 3 (0-indexed) should have key 5
        REQUIRE(keys[3] == 5);
        REQUIRE(values[3] == 50.0);
      }
    }
  }
}
