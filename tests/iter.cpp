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

#include <array>
#include <deque>
#include <forward_list>
#include <iterator>
#include <list>
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

    THEN("we can use operator++")
    {
      ++it;
      REQUIRE(std::get<0>(*it) == 2);
    }

    THEN("we can use operator++(int) post-increment")
    {
      auto it_prev = it++;
      REQUIRE(std::get<0>(*it_prev) == 1);
      REQUIRE(std::get<0>(*it) == 2);
    }

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

    THEN("we can calculate distance with operator- between iterators") { REQUIRE(end - it == 5); }

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

    THEN("we can use relational operators <")
    {
      auto it2 = it + 2;
      REQUIRE(it < it2);
    }

    THEN("we can use relational operators >")
    {
      auto it2 = it + 2;
      REQUIRE(it2 > it);
    }

    THEN("we can use relational operators <=")
    {
      auto it2 = it + 2;
      REQUIRE(it <= it2);
      REQUIRE(it <= it);
    }

    THEN("we can use relational operators >=")
    {
      auto it2 = it + 2;
      REQUIRE(it2 >= it);
      REQUIRE(it >= it);
    }
  }
}

SCENARIO("zip_view iterator default constructor", "[iterator]")
{
  GIVEN("A zip_view over two vectors")
  {
    std::vector<int>    vec1 = {1, 2, 3};
    std::vector<double> vec2 = {10.0, 20.0, 30.0};

    auto zipped = gst::ranges::views::zip(vec1, vec2);

    THEN("we can default construct an iterator")
    {
      typename decltype(zipped)::iterator it1;
      typename decltype(zipped)::iterator it2;
      REQUIRE(it1 == it2);
    }
  }
}

SCENARIO("zip_view iterator inequality comparison", "[iterator]")
{
  GIVEN("A zip_view over three vectors")
  {
    std::vector<int>  vec1 = {1, 2, 3, 4, 5};
    std::vector<char> vec2 = {'a', 'b', 'c', 'd', 'e'};
    std::vector<int>  vec3 = {10, 20, 30, 40, 50};

    auto zipped = gst::ranges::views::zip(vec1, vec2, vec3);

    THEN("iterators at different positions compare unequal")
    {
      auto it1 = zipped.begin();
      auto it2 = zipped.begin();
      ++it2;

      REQUIRE(it1 != it2);
      REQUIRE_FALSE(it1 == it2);
    }

    THEN("iterators at far apart positions compare unequal")
    {
      auto it1 = zipped.begin();
      auto it2 = zipped.begin();
      ++it2;
      ++it2;
      ++it2;

      REQUIRE(it1 != it2);
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

SCENARIO("Testing std::advance and std::distance with zip_view iterators", "[iterator]")
{
  GIVEN("A zip_view over random-access containers")
  {
    std::vector<int>    vec1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<double> vec2 = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.1};

    auto zipped = gst::ranges::views::zip(vec1, vec2);

    WHEN("Using std::advance with positive offset")
    {
      auto it = zipped.begin();
      std::advance(it, 5);

      THEN("Iterator is advanced correctly")
      {
        REQUIRE(std::get<0>(*it) == 6);
        REQUIRE(std::get<1>(*it) == Catch::Approx(6.6));
      }
    }

    WHEN("Using std::advance with negative offset")
    {
      auto it = zipped.end();
      std::advance(it, -3);

      THEN("Iterator is moved backward correctly")
      {
        REQUIRE(std::get<0>(*it) == 8);
        REQUIRE(std::get<1>(*it) == Catch::Approx(8.8));
      }
    }

    WHEN("Using std::advance with zero offset")
    {
      auto it  = zipped.begin() + 4;
      auto pos = std::get<0>(*it);
      std::advance(it, 0);

      THEN("Iterator position remains unchanged") { REQUIRE(std::get<0>(*it) == pos); }
    }

    WHEN("Using std::distance between iterators")
    {
      auto it1  = zipped.begin() + 2;
      auto it2  = zipped.begin() + 7;
      auto dist = std::distance(it1, it2);

      THEN("Distance is calculated correctly") { REQUIRE(dist == 5); }
    }

    WHEN("Using std::distance from begin to end")
    {
      auto dist = std::distance(zipped.begin(), zipped.end());

      THEN("Distance equals size") { REQUIRE(dist == static_cast<std::ptrdiff_t>(zipped.size())); }
    }
  }

  GIVEN("A zip_view over bidirectional containers")
  {
    std::list<int>    lst1 = {10, 20, 30, 40, 50};
    std::list<double> lst2 = {1.1, 2.2, 3.3, 4.4, 5.5};

    auto zipped = gst::ranges::views::zip(lst1, lst2);

    WHEN("Using std::advance forward on bidirectional iterator")
    {
      auto it = zipped.begin();
      std::advance(it, 3);

      THEN("Iterator advances correctly") { REQUIRE(std::get<0>(*it) == 40); }
    }

    WHEN("Using std::advance backward on bidirectional iterator")
    {
      auto it = zipped.end();
      std::advance(it, -2);

      THEN("Iterator moves backward correctly") { REQUIRE(std::get<0>(*it) == 40); }
    }

    WHEN("Using std::distance on bidirectional iterator")
    {
      auto dist = std::distance(zipped.begin(), zipped.end());

      THEN("Distance is computed (O(n) for bidirectional)") { REQUIRE(dist == 5); }
    }
  }

  GIVEN("A zip_view over forward containers")
  {
    std::forward_list<int> flst1 = {100, 200, 300};
    std::forward_list<int> flst2 = {10, 20, 30};

    auto zipped = gst::ranges::views::zip(flst1, flst2);

    WHEN("Using std::advance forward on forward iterator")
    {
      auto it = zipped.begin();
      std::advance(it, 2);

      THEN("Iterator advances correctly")
      {
        REQUIRE(std::get<0>(*it) == 300);
        REQUIRE(std::get<1>(*it) == 30);
      }
    }

    WHEN("Using std::distance on forward iterator")
    {
      auto dist = std::distance(zipped.begin(), zipped.end());

      THEN("Distance is computed (O(n) for forward)") { REQUIRE(dist == 3); }
    }
  }
}

SCENARIO("Testing iterator copy and move semantics", "[iterator]")
{
  GIVEN("A zip_view over two vectors")
  {
    std::vector<int>  vec1 = {1, 2, 3, 4, 5};
    std::vector<char> vec2 = {'a', 'b', 'c', 'd', 'e'};

    auto zipped = gst::ranges::views::zip(vec1, vec2);

    WHEN("Copy constructing an iterator")
    {
      auto it1 = zipped.begin() + 2;
      auto it2 = it1; // Copy

      THEN("Both iterators point to the same element")
      {
        REQUIRE((*it1 == *it2));
        REQUIRE(it1 == it2);
      }

      THEN("Modifying one iterator doesn't affect the other's position")
      {
        ++it1;
        REQUIRE(it1 != it2);
        REQUIRE(std::get<0>(*it1) == 4);
        REQUIRE(std::get<0>(*it2) == 3);
      }
    }

    WHEN("Copy assigning an iterator")
    {
      auto it1 = zipped.begin() + 1;
      auto it2 = zipped.begin() + 3;
      it2      = it1; // Copy assign

      THEN("Both iterators point to the same element")
      {
        REQUIRE(it1 == it2);
        REQUIRE(std::get<0>(*it2) == 2);
      }
    }

    WHEN("Move constructing an iterator")
    {
      auto it1 = zipped.begin() + 2;
      auto val = std::get<0>(*it1);
      auto it2 = std::move(it1); // Move

      THEN("Moved-to iterator has correct value") { REQUIRE(std::get<0>(*it2) == val); }
    }

    WHEN("Move assigning an iterator")
    {
      auto it1 = zipped.begin() + 4;
      auto it2 = zipped.begin();
      it2      = std::move(it1); // Move assign

      THEN("Moved-to iterator points to original position") { REQUIRE(std::get<0>(*it2) == 5); }
    }
  }
}

SCENARIO("Testing default constructed iterators", "[iterator]")
{
  GIVEN("Default constructed iterators")
  {
    using zip_t = decltype(gst::ranges::views::zip(std::vector<int>{}, std::vector<char>{}));

    WHEN("Two iterators are default constructed")
    {
      typename zip_t::iterator it1;
      typename zip_t::iterator it2;

      THEN("They compare equal") { REQUIRE(it1 == it2); }

      THEN("They are not not-equal") { REQUIRE_FALSE(it1 != it2); }
    }

    WHEN("Default constructed const_iterator")
    {
      typename zip_t::const_iterator cit1;
      typename zip_t::const_iterator cit2;

      THEN("They compare equal") { REQUIRE(cit1 == cit2); }
    }
  }
}

SCENARIO("Testing iterator edge cases with arithmetic", "[iterator]")
{
  GIVEN("A zip_view over random-access containers")
  {
    std::vector<int> vec1 = {10, 20, 30, 40, 50};
    std::vector<int> vec2 = {1, 2, 3, 4, 5};

    auto zipped = gst::ranges::views::zip(vec1, vec2);

    WHEN("Adding zero to an iterator")
    {
      auto it1 = zipped.begin() + 2;
      auto it2 = it1 + 0;

      THEN("Iterator position is unchanged")
      {
        REQUIRE(it1 == it2);
        REQUIRE(std::get<0>(*it2) == 30);
      }
    }

    WHEN("Subtracting zero from an iterator")
    {
      auto it1 = zipped.begin() + 3;
      auto it2 = it1 - 0;

      THEN("Iterator position is unchanged")
      {
        REQUIRE(it1 == it2);
        REQUIRE(std::get<0>(*it2) == 40);
      }
    }

    WHEN("Computing distance from iterator to itself")
    {
      auto it   = zipped.begin() + 2;
      auto dist = it - it;

      THEN("Distance is zero") { REQUIRE(dist == 0); }
    }

    WHEN("Adding and subtracting same value")
    {
      auto it1 = zipped.begin() + 1;
      auto it2 = (it1 + 3) - 3;

      THEN("Iterator returns to original position") { REQUIRE(it1 == it2); }
    }

    WHEN("Using negative subscript offset from end")
    {
      auto it  = zipped.end();
      it      -= 1;

      THEN("Can access last element") { REQUIRE(std::get<0>(*it) == 50); }
    }
  }
}
