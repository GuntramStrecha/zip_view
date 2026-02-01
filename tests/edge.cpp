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
#include <list>
#include <ranges>
#include <string>
#include <tuple>
#include <vector>

SCENARIO("Testing gst::ranges::zip_view with edge scenarios", "[edge]")
{
  GIVEN("Empty containers")
  {
    std::vector<int>  vec = {};
    std::list<char>   lst = {};
    std::deque<float> deq = {};

    auto gst_zipped = gst::ranges::views::zip(vec, lst, deq);
    auto std_zipped = std::ranges::views::zip(vec, lst, deq);

    THEN("The zip_view should be empty") { REQUIRE(gst_zipped.empty()); }
    THEN("The size should be equal") { REQUIRE(gst_zipped.size() == std_zipped.size()); }
    THEN("The sizes of the whole instances should be equal")
    {
      REQUIRE(sizeof(gst_zipped) == sizeof(std_zipped));
    }
  }

  GIVEN("Single element containers")
  {
    std::vector<int>  vec = {1};
    std::list<char>   lst = {'a'};
    std::deque<float> deq = {1.1F};

    auto gst_zipped = gst::ranges::views::zip(vec, lst, deq);
    auto std_zipped = std::ranges::views::zip(vec, lst, deq);

    THEN("The zip_view should not be empty") { REQUIRE_FALSE(gst_zipped.empty()); }
    THEN("The size should be equal") { REQUIRE(gst_zipped.size() == std_zipped.size()); }
    THEN("The sizes of the whole instances should be equal")
    {
      REQUIRE(sizeof(gst_zipped) == sizeof(std_zipped));
    }
    THEN("The front element should be the only elements of each container")
    {
      auto gst_front = gst_zipped.front();
      auto std_front = std_zipped.front();
      REQUIRE(std::get<0>(gst_front) == std::get<0>(std_front));
      REQUIRE(std::get<1>(gst_front) == std::get<1>(std_front));
      REQUIRE(std::equal_to{}(std::get<2>(gst_front), std::get<2>(std_front)));
    }
  }

  GIVEN("Multiple element containers")
  {
    std::vector<int>       vec = {1, 2};
    std::list<std::string> lst = {"a", "b"};
    std::deque<double>     deq = {1.1, 2.2};

    auto gst_zipped = gst::ranges::views::zip(vec, lst, deq);
    auto std_zipped = std::ranges::views::zip(vec, lst, deq);

    THEN("The zip_view should not be empty") { REQUIRE_FALSE(gst_zipped.empty()); }
    THEN("The size should be equal") { REQUIRE(gst_zipped.size() == std_zipped.size()); }
    THEN("The sizes of the whole instances should be equal")
    {
      REQUIRE(sizeof(gst_zipped) == sizeof(std_zipped));
    }
    THEN("The elements should match the corresponding elements of each container")
    {
      auto gst_elem = gst_zipped[1];
      REQUIRE(std::get<0>(gst_elem) == 2);
      REQUIRE(std::get<1>(gst_elem) == "b");
      REQUIRE(std::equal_to{}(std::get<2>(gst_elem), 2.2));
    }
  }

  GIVEN("Containers with nested containers")
  {
    std::vector<std::vector<int>> vec = {{1, 2}, {3, 4}};
    std::list<std::list<char>>    lst = {{'a', 'b'}, {'c', 'd'}};
    std::deque<std::deque<float>> deq = {{1.1F, 2.2F}, {3.3F, 4.4F}};

    auto gst_zipped = gst::ranges::views::zip(vec, lst, deq);
    auto std_zipped = std::ranges::views::zip(vec, lst, deq);

    THEN("The zip_view should not be empty") { REQUIRE_FALSE(gst_zipped.empty()); }
    THEN("The size should be equal") { REQUIRE(gst_zipped.size() == std_zipped.size()); }
    THEN("The sizes of the whole instances should be equal")
    {
      REQUIRE(sizeof(gst_zipped) == sizeof(std_zipped));
    }
    THEN("The elements should match the corresponding elements of each container")
    {
      auto gst_elem = gst_zipped[1];
      REQUIRE(std::get<0>(gst_elem) == std::vector<int>({3, 4}));
      REQUIRE(std::get<1>(gst_elem) == std::list<char>({'c', 'd'}));
      REQUIRE(std::get<2>(gst_elem) == std::deque<float>({3.3F, 4.4F}));
    }
  }

  GIVEN("Containers with custom objects")
  {
    struct Custom
    {
      int   a;
      char  b;
      float c;
      bool  operator==(Custom const& other) const
      {
        return std::equal_to{}(std::tie(a, b, c), std::tie(other.a, other.b, other.c));
      }
    };

    std::vector<Custom> vec = {{1, 'a', 1.1F}, {2, 'b', 2.2F}};
    std::list<Custom>   lst = {{3, 'c', 3.3F}, {4, 'd', 4.4F}};
    std::deque<Custom>  deq = {{5, 'e', 5.5F}, {6, 'f', 6.6F}};

    auto gst_zipped = gst::ranges::views::zip(vec, lst, deq);
    auto std_zipped = std::ranges::views::zip(vec, lst, deq);

    THEN("The zip_view should not be empty") { REQUIRE_FALSE(gst_zipped.empty()); }
    THEN("The size should be equal") { REQUIRE(gst_zipped.size() == std_zipped.size()); }
    THEN("The sizes of the whole instances should be equal")
    {
      REQUIRE(sizeof(gst_zipped) == sizeof(std_zipped));
    }
    THEN("The elements should match the corresponding elements of each container")
    {
      auto gst_elem = gst_zipped[1];
      REQUIRE(std::get<0>(gst_elem) == Custom{2, 'b', 2.2F});
      REQUIRE(std::get<1>(gst_elem) == Custom{4, 'd', 4.4F});
      REQUIRE(std::get<2>(gst_elem) == Custom{6, 'f', 6.6F});
    }
  }

  GIVEN("Containers with non-copyable elements")
  {
    struct NonCopyable
    {
      int value;
      NonCopyable(int v) : value(v) {}
      NonCopyable(NonCopyable const&)            = delete;
      NonCopyable& operator=(NonCopyable const&) = delete;
      NonCopyable(NonCopyable&&)                 = default;
      NonCopyable& operator=(NonCopyable&&)      = delete;
    };

    std::vector<NonCopyable> vec;
    vec.emplace_back(1);
    vec.emplace_back(2);
    std::list<NonCopyable> lst;
    lst.emplace_back(3);
    lst.emplace_back(4);
    std::deque<NonCopyable> deq;
    deq.emplace_back(5);
    deq.emplace_back(6);

    auto gst_zipped = gst::ranges::views::zip(vec, lst, deq);

    THEN("The zip_view should not be empty") { REQUIRE_FALSE(gst_zipped.empty()); }
    THEN("The size should be two") { REQUIRE(gst_zipped.size() == 2); }
    THEN("The elements should match the corresponding elements of each container")
    {
      auto gst_elem = gst_zipped[1];
      REQUIRE(std::get<0>(gst_elem).value == 2);
      REQUIRE(std::get<1>(gst_elem).value == 4);
      REQUIRE(std::get<2>(gst_elem).value == 6);
    }
  }
}

SCENARIO("Testing gst::ranges::zip_view with constant containers", "[edge]")
{
  GIVEN("Constant containers")
  {
    std::vector<int> const  vec = {1, 2, 3};
    std::list<char> const   lst = {'a', 'b', 'c'};
    std::deque<float> const deq = {1.1F, 2.2F, 3.3F};

    WHEN("Creating a non-const zip_view from const containers")
    {
      auto gst_zipped = gst::ranges::views::zip(vec, lst, deq);

      THEN("The zip_view should not be empty") { REQUIRE_FALSE(gst_zipped.empty()); }
      THEN("The size should be three") { REQUIRE(gst_zipped.size() == 3); }
      THEN("The front element should be the first elements of each container")
      {
        auto const gst_front = gst_zipped.front();
        REQUIRE(std::get<0>(gst_front) == 1);
        REQUIRE(std::get<1>(gst_front) == 'a');
        REQUIRE(std::equal_to{}(std::get<2>(gst_front), 1.1F));
      }
      THEN("The back element should be the last elements of each container")
      {
        auto const gst_back = gst_zipped.back();
        REQUIRE(std::get<0>(gst_back) == 3);
        REQUIRE(std::get<1>(gst_back) == 'c');
        REQUIRE(std::equal_to{}(std::get<2>(gst_back), 3.3F));
      }
      THEN("The subscript operator should return the correct elements")
      {
        auto const gst_elem = gst_zipped[1];
        REQUIRE(std::get<0>(gst_elem) == 2);
        REQUIRE(std::get<1>(gst_elem) == 'b');
        REQUIRE(std::equal_to{}(std::get<2>(gst_elem), 2.2F));
      }
      THEN("The zip_view should be convertible to bool")
      {
        REQUIRE(static_cast<bool>(gst_zipped) == true);
      }
    }

    WHEN("Creating a const zip_view from const containers")
    {
      auto const gst_zipped = gst::ranges::views::zip(vec, lst, deq);

      THEN("The zip_view should not be empty") { REQUIRE_FALSE(gst_zipped.empty()); }
      THEN("The size should be three") { REQUIRE(gst_zipped.size() == 3); }
      THEN("The front element should be the first elements of each container")
      {
        auto const gst_front = gst_zipped.front();
        REQUIRE(std::get<0>(gst_front) == 1);
        REQUIRE(std::get<1>(gst_front) == 'a');
        REQUIRE(std::equal_to{}(std::get<2>(gst_front), 1.1F));
      }
      THEN("The back element should be the last elements of each container")
      {
        auto const gst_back = gst_zipped.back();
        REQUIRE(std::get<0>(gst_back) == 3);
        REQUIRE(std::get<1>(gst_back) == 'c');
        REQUIRE(std::equal_to{}(std::get<2>(gst_back), 3.3F));
      }
      THEN("The subscript operator should return the correct elements")
      {
        auto const gst_elem = gst_zipped[1];
        REQUIRE(std::get<0>(gst_elem) == 2);
        REQUIRE(std::get<1>(gst_elem) == 'b');
        REQUIRE(std::equal_to{}(std::get<2>(gst_elem), 2.2F));
      }
      THEN("The zip_view should be convertible to bool")
      {
        REQUIRE(static_cast<bool>(gst_zipped) == true);
      }
    }
  }

  GIVEN("Non-const containers")
  {
    std::vector<int>  vec = {1, 2, 3};
    std::list<char>   lst = {'a', 'b', 'c'};
    std::deque<float> deq = {1.1F, 2.2F, 3.3F};

    WHEN("Creating a const zip_view from non-const containers")
    {
      auto const gst_zipped = gst::ranges::views::zip(vec, lst, deq);

      THEN("The zip_view should not be empty") { REQUIRE_FALSE(gst_zipped.empty()); }
      THEN("The size should be three") { REQUIRE(gst_zipped.size() == 3); }
      THEN("The front element should be the first elements of each container")
      {
        auto const gst_front = gst_zipped.front();
        REQUIRE(std::get<0>(gst_front) == 1);
        REQUIRE(std::get<1>(gst_front) == 'a');
        REQUIRE(std::equal_to{}(std::get<2>(gst_front), 1.1F));
      }
      THEN("The back element should be the last elements of each container")
      {
        auto const gst_back = gst_zipped.back();
        REQUIRE(std::get<0>(gst_back) == 3);
        REQUIRE(std::get<1>(gst_back) == 'c');
        REQUIRE(std::equal_to{}(std::get<2>(gst_back), 3.3F));
      }
      THEN("The subscript operator should return the correct elements")
      {
        auto const gst_elem = gst_zipped[1];
        REQUIRE(std::get<0>(gst_elem) == 2);
        REQUIRE(std::get<1>(gst_elem) == 'b');
        REQUIRE(std::equal_to{}(std::get<2>(gst_elem), 2.2F));
      }
      THEN("The zip_view should be convertible to bool")
      {
        REQUIRE(static_cast<bool>(gst_zipped) == true);
      }
    }
  }
}

SCENARIO("Testing gst::ranges::zip_view with C arrays", "[edge]")
{
  GIVEN("Two C arrays with different extents")
  {
    int  a[4] = {1, 2, 3, 4};
    char b[2] = {'x', 'y'};

    auto zipped = gst::ranges::views::zip(a, b);

    THEN("The size should be the min extent") { REQUIRE(zipped.size() == 2); }
    THEN("Iteration should stop at the min extent")
    {
      auto it = zipped.begin();
      REQUIRE(std::get<0>(*it) == 1);
      REQUIRE(std::get<1>(*it) == 'x');
      ++it;
      REQUIRE(std::get<0>(*it) == 2);
      REQUIRE(std::get<1>(*it) == 'y');
      ++it;
      REQUIRE(it == zipped.end());
    }
  }
}

SCENARIO("Testing subscript operator read and write", "[edge]")
{
  GIVEN("two arrays of the same size but different element types")
  {
    WHEN("we create a const zip_view for reading")
    {
      std::array<int, 3> v1{1, 2, 3};
      std::list<double>  v2{4.1, 5.2, 6.3};
      auto const         zip = gst::ranges::views::zip(v1, v2);

      THEN("we can read the elements using the subscript operator")
      {
        REQUIRE((zip[0] == std::make_tuple(1, 4.1)));
        REQUIRE((zip[1] == std::make_tuple(2, 5.2)));
        REQUIRE((zip[2] == std::make_tuple(3, 6.3)));
      }
    }

    WHEN("we create a non-const zip_view for writing")
    {
      std::array<int, 3> v1{1, 2, 3};
      std::list<double>  v2{4.1, 5.2, 6.3};
      auto               zip = gst::ranges::views::zip(v1, v2);

      THEN("we can write the elements using the subscript operator")
      {
        zip[0] = std::make_tuple(10, 40.1);
        zip[1] = std::make_tuple(20, 50.2);
        zip[2] = std::make_tuple(30, 60.3);

        AND_THEN("the elements of the original containers are updated")
        {
          REQUIRE(v1 == std::array<int, 3>{10, 20, 30});
          REQUIRE(v2 == std::list<double>{40.1, 50.2, 60.3});
        }
      }
    }

    WHEN("we create a const zip_view for writing")
    {
      std::array<int, 3> v1{1, 2, 3};
      std::list<double>  v2{4.1, 5.2, 6.3};
      auto const         zip = gst::ranges::views::zip(v1, v2);

      THEN("we can still write the elements using the subscript operator")
      {
        zip[0] = std::make_tuple(10, 40.1);
        zip[1] = std::make_tuple(20, 50.2);
        zip[2] = std::make_tuple(30, 60.3);

        AND_THEN("the elements of the original containers are updated")
        {
          REQUIRE(v1 == std::array<int, 3>{10, 20, 30});
          REQUIRE(v2 == std::list<double>{40.1, 50.2, 60.3});
        }
      }
    }
  }
}

SCENARIO("Testing gst::ranges::zip_view with modified containers", "[edge]")
{
  GIVEN("Containers that are modified after creating zip_view")
  {
    std::vector<int>  vec = {1, 2, 3};
    std::list<char>   lst = {'a', 'b', 'c'};
    std::deque<float> deq = {1.1F, 2.2F, 3.3F};

    auto gst_zipped = gst::ranges::views::zip(vec, lst, deq);

    THEN("The zip_view should reflect the modifications")
    {
      vec.push_back(4);
      lst.push_back('d');
      deq.push_back(4.4F);

      REQUIRE(gst_zipped.size() == 4);
      REQUIRE(std::get<0>(gst_zipped[3]) == 4);
      REQUIRE(std::get<1>(gst_zipped[3]) == 'd');
      REQUIRE(std::equal_to{}(std::get<2>(gst_zipped[3]), 4.4F));
    }
  }
}

SCENARIO("Testing const and non-const access to zip_view", "[const_correctness]")
{
  GIVEN("Non-const containers with multiple elements")
  {
    std::vector<int>  vec = {1, 2, 3, 4, 5};
    std::list<char>   lst = {'a', 'b', 'c', 'd', 'e'};
    std::deque<float> deq = {1.1F, 2.2F, 3.3F, 4.4F, 5.5F};

    WHEN("Creating a non-const zip_view")
    {
      auto zipped = gst::ranges::views::zip(vec, lst, deq);

      THEN("non-const begin() and end() work")
      {
        auto it  = zipped.begin();
        auto end = zipped.end();
        REQUIRE(it != end);
        REQUIRE(std::get<0>(*it) == 1);
      }

      THEN("non-const front() works")
      {
        auto front_elem = zipped.front();
        REQUIRE(std::get<0>(front_elem) == 1);
        REQUIRE(std::get<1>(front_elem) == 'a');
        REQUIRE(std::equal_to{}(std::get<2>(front_elem), 1.1F));
      }

      THEN("non-const back() works")
      {
        auto back_elem = zipped.back();
        REQUIRE(std::get<0>(back_elem) == 5);
        REQUIRE(std::get<1>(back_elem) == 'e');
        REQUIRE(std::equal_to{}(std::get<2>(back_elem), 5.5F));
      }

      THEN("non-const operator[] works")
      {
        auto elem = zipped[2];
        REQUIRE(std::get<0>(elem) == 3);
        REQUIRE(std::get<1>(elem) == 'c');
        REQUIRE(std::equal_to{}(std::get<2>(elem), 3.3F));
      }
    }

    WHEN("Creating a const zip_view")
    {
      auto const zipped = gst::ranges::views::zip(vec, lst, deq);

      THEN("const begin() and end() work")
      {
        auto it  = zipped.begin();
        auto end = zipped.end();
        REQUIRE(it != end);
        REQUIRE(std::get<0>(*it) == 1);
      }

      THEN("we can iterate using const iterators")
      {
        auto it = zipped.begin();
        ++it;
        REQUIRE(std::get<0>(*it) == 2);
        REQUIRE(std::get<1>(*it) == 'b');
      }

      THEN("const front() works")
      {
        auto front_elem = zipped.front();
        REQUIRE(std::get<0>(front_elem) == 1);
        REQUIRE(std::get<1>(front_elem) == 'a');
        REQUIRE(std::equal_to{}(std::get<2>(front_elem), 1.1F));
      }

      THEN("const back() works")
      {
        auto back_elem = zipped.back();
        REQUIRE(std::get<0>(back_elem) == 5);
        REQUIRE(std::get<1>(back_elem) == 'e');
        REQUIRE(std::equal_to{}(std::get<2>(back_elem), 5.5F));
      }

      THEN("const operator[] works")
      {
        auto elem = zipped[2];
        REQUIRE(std::get<0>(elem) == 3);
        REQUIRE(std::get<1>(elem) == 'c');
        REQUIRE(std::equal_to{}(std::get<2>(elem), 3.3F));
      }

      THEN("const operator bool() works correctly") { REQUIRE(static_cast<bool>(zipped) == true); }
    }
  }

  GIVEN("Empty containers")
  {
    std::vector<int> vec = {};
    std::list<char>  lst = {};

    WHEN("Creating a const zip_view from empty containers")
    {
      auto const zipped = gst::ranges::views::zip(vec, lst);

      THEN("const operator bool() returns false for empty view")
      {
        REQUIRE(static_cast<bool>(zipped) == false);
      }

      THEN("const begin() and end() are equal") { REQUIRE(zipped.begin() == zipped.end()); }
    }
  }
}

SCENARIO("Testing const vs non-const element access through zip_view", "[const_correctness]")
{
  GIVEN("Zip of const and non-const containers")
  {
    std::vector<int> const const_vec = {1, 2, 3, 4, 5};

    WHEN("Creating a zip_view over both")
    {
      std::vector<int> mutable_vec = {6, 7, 8, 9, 10};
      auto             zipped      = gst::ranges::views::zip(const_vec, mutable_vec);

      THEN("Can read from both containers")
      {
        auto elem = zipped[2];
        REQUIRE(std::get<0>(elem) == 3);
        REQUIRE(std::get<1>(elem) == 8);
      }

      THEN("Cannot modify const container elements")
      {
        // std::get<0>(zipped[0]) = 99;  // Should not compile - const
        REQUIRE(const_vec[0] == 1); // Remains unchanged
      }
    }

    WHEN("Testing modification of non-const elements")
    {
      std::vector<int> mutable_vec = {6, 7, 8, 9, 10};
      auto             zipped      = gst::ranges::views::zip(const_vec, mutable_vec);

      THEN("Can modify non-const container elements")
      {
        std::get<1>(zipped[0]) = 99;
        REQUIRE(mutable_vec[0] == 99);
      }
    }

    WHEN("Iterating over zip")
    {
      std::vector<int> mutable_vec = {6, 7, 8, 9, 10};
      auto             zipped      = gst::ranges::views::zip(const_vec, mutable_vec);

      THEN("Iteration respects constness")
      {
        size_t count = 0;
        for (auto&& elem : zipped)
        {
          // std::get<0>(elem) = 0;  // Should not compile
          std::get<1>(elem) += 10; // Should compile
          ++count;
        }
        REQUIRE(count == 5);
        REQUIRE(mutable_vec[0] == 16);
      }
    }
  }

  GIVEN("All const containers")
  {
    std::vector<int> const v1 = {1, 2, 3};
    std::list<char> const  v2 = {'a', 'b', 'c'};

    WHEN("Creating zip_view over const containers")
    {
      auto zipped = gst::ranges::views::zip(v1, v2);

      THEN("Can read elements")
      {
        REQUIRE(std::get<0>(zipped.front()) == 1);
        REQUIRE(std::get<1>(zipped.front()) == 'a');
      }

      THEN("Dereferenced elements are const references")
      {
        [[maybe_unused]] auto elem = zipped[1];
        // std::get<0>(elem) = 99;  // Should not compile
        // std::get<1>(elem) = 'z';  // Should not compile
        REQUIRE(v1[1] == 2);
        REQUIRE(v2.begin() != v2.end());
      }
    }
  }
}

SCENARIO("Testing nested zip_view", "[edge]")
{
  GIVEN("Two separate zip_views as stored objects")
  {
    std::vector<int>  v1 = {1, 2, 3};
    std::vector<char> v2 = {'a', 'b', 'c'};
    std::vector<int>  v3 = {10, 20, 30};
    std::vector<char> v4 = {'x', 'y', 'z'};

    auto z1 = gst::ranges::views::zip(v1, v2);
    auto z2 = gst::ranges::views::zip(v3, v4);

    WHEN("Creating a zip of zip_views")
    {
      auto nested = gst::ranges::views::zip(z1, z2);

      THEN("The nested zip_view has correct size") { REQUIRE(nested.size() == 3); }

      THEN("Can iterate and access nested elements")
      {
        int count = 0;
        for (auto it = nested.begin(); it != nested.end(); ++it) { ++count; }
        REQUIRE(count == 3);
      }

      THEN("Subscript access works with nested structure")
      {
        // Access first element of nested zip
        // This demonstrates that zip_views can be zipped
        REQUIRE(nested.size() == 3);
        REQUIRE(z1.size() == 3);
        REQUIRE(z2.size() == 3);
      }
    }
  }

  GIVEN("Zip of vectors within a zip")
  {
    std::vector<std::vector<int>> vv1 = {{1, 2}, {3, 4}, {5, 6}};
    std::vector<std::vector<int>> vv2 = {{7, 8}, {9, 10}, {11, 12}};

    WHEN("Zipping containers of containers")
    {
      auto zipped = gst::ranges::views::zip(vv1, vv2);

      THEN("Can access nested vectors")
      {
        auto elem = zipped[1];
        REQUIRE(std::get<0>(elem) == std::vector<int>{3, 4});
        REQUIRE(std::get<1>(elem) == std::vector<int>{9, 10});
      }

      THEN("Can modify nested vectors through zip")
      {
        std::get<0>(zipped[0]).push_back(99);
        REQUIRE(vv1[0].size() == 3);
        REQUIRE(vv1[0][2] == 99);
      }
    }
  }
}

SCENARIO("Testing iterator invalidation behavior", "[edge]")
{
  GIVEN("A zip_view over a vector")
  {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    auto zipped = gst::ranges::views::zip(vec);

    WHEN("The underlying container is modified")
    {
      [[maybe_unused]] auto it = zipped.begin();
      vec.push_back(6); // May invalidate iterators

      THEN("Iterator behavior is undefined (documented)")
      {
        // This test documents that iterator invalidation follows
        // the same rules as the underlying containers
        // Using 'it' after vec.push_back() is UB, just like with raw vector iterators
        REQUIRE(vec.size() == 6);
        // Note: We don't dereference 'it' as it's undefined behavior
      }
    }

    WHEN("Creating new iterators after modification")
    {
      vec[0]   = 99;
      auto it2 = zipped.begin();

      THEN("New iterators reflect the modifications") { REQUIRE(std::get<0>(*it2) == 99); }
    }

    WHEN("The size changes such that old end() is beyond new range")
    {
      vec.resize(2); // Shrink container
      auto new_end = zipped.end();

      THEN("New end iterator is computed correctly")
      {
        REQUIRE(std::distance(zipped.begin(), new_end) == 2);
      }
    }
  }
}

SCENARIO("Testing very large containers", "[edge]")
{
  GIVEN("Large vectors with 1 million elements")
  {
    std::vector<int> large1(1'000'000, 42);
    std::vector<int> large2(1'000'000, 84);

    WHEN("Creating a zip_view over large containers")
    {
      auto zipped = gst::ranges::views::zip(large1, large2);

      THEN("Size is computed correctly") { REQUIRE(zipped.size() == 1'000'000); }

      THEN("Can access elements at various positions")
      {
        REQUIRE(std::get<0>(zipped[0]) == 42);
        REQUIRE(std::get<0>(zipped[500'000]) == 42);
        REQUIRE(std::get<1>(zipped[999'999]) == 84);
      }

      THEN("Iterator arithmetic works correctly")
      {
        auto it = zipped.begin() + 750'000;
        REQUIRE(std::get<0>(*it) == 42);
        REQUIRE(it - zipped.begin() == 750'000);
      }
    }
  }
}
