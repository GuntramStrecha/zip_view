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
#include <deque>
#include <forward_list>
#include <iterator>
#include <list>
#include <string>
#include <type_traits>
#include <vector>

SCENARIO("zip_view iterator category is computed from weakest underlying iterator",
         "[iterator_category]")
{
  GIVEN("Two vectors (random access containers)")
  {
    std::vector<int>    vec1 = {1, 2, 3};
    std::vector<double> vec2 = {4.0, 5.0, 6.0};

    WHEN("we create a zip_view over them")
    {
      auto zipped         = gst::ranges::views::zip(vec1, vec2);
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
    std::vector<int>   vec = {1, 2, 3};
    std::array<int, 3> arr = {4, 5, 6};
    std::deque<int>    deq = {7, 8, 9};

    WHEN("we create a zip_view over them")
    {
      auto zipped         = gst::ranges::views::zip(vec, arr, deq);
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
      auto zipped         = gst::ranges::views::zip(vec, lst);
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
      auto zipped         = gst::ranges::views::zip(lst1, lst2);
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
      auto zipped         = gst::ranges::views::zip(vec, flst);
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
      auto zipped         = gst::ranges::views::zip(vec, lst, flst);
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
      REQUIRE(std::get<1>(*it2) == Catch::Approx(30.0));
    }

    THEN("we can use n + iterator")
    {
      auto it2 = 3 + it;
      REQUIRE(std::get<0>(*it2) == 4);
      REQUIRE(std::get<1>(*it2) == Catch::Approx(40.0));
    }

    THEN("we can use operator-")
    {
      auto it2 = end - 2;
      REQUIRE(std::get<0>(*it2) == 4);
      REQUIRE(std::get<1>(*it2) == Catch::Approx(40.0));
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
      REQUIRE(std::get<1>(it[4]) == Catch::Approx(50.0));
    }

    THEN("we can use operator+=")
    {
      auto it2  = it;
      it2      += 3;
      REQUIRE(std::get<0>(*it2) == 4);
    }

    THEN("we can use operator-=")
    {
      auto it2  = end;
      it2      -= 2;
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
