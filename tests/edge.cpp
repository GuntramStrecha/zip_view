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
#include <string>
#include <tuple>
#include <vector>

SCENARIO("Testing gst::zip_view with edge scenarios", "[edge]")
{
  GIVEN("Single element containers")
  {
    std::vector<int>  vec = {1};
    std::list<char>   lst = {'a'};
    std::deque<float> deq = {1.1F};

    auto gst_zipped = gst::zip(vec, lst, deq);

    THEN("The zip_view should not be empty") { REQUIRE_FALSE(gst_zipped.empty()); }
    THEN("The size should be one") { REQUIRE(gst_zipped.size() == 1); }
    THEN("The front element should be the only elements of each container")
    {
      auto gst_front = gst_zipped.front();
      REQUIRE(std::get<0>(gst_front) == 1);
      REQUIRE(std::get<1>(gst_front) == 'a');
      REQUIRE(std::equal_to{}(std::get<2>(gst_front), 1.1F));
    }
  }

  GIVEN("Containers with different types")
  {
    std::vector<int>       vec = {1, 2};
    std::list<std::string> lst = {"a", "b"};
    std::deque<double>     deq = {1.1, 2.2};

    auto gst_zipped = gst::zip(vec, lst, deq);

    THEN("The zip_view should not be empty") { REQUIRE_FALSE(gst_zipped.empty()); }
    THEN("The size should be two") { REQUIRE(gst_zipped.size() == 2); }
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

    auto gst_zipped = gst::zip(vec, lst, deq);

    THEN("The zip_view should not be empty") { REQUIRE_FALSE(gst_zipped.empty()); }
    THEN("The size should be two") { REQUIRE(gst_zipped.size() == 2); }
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

    auto gst_zipped = gst::zip(vec, lst, deq);

    THEN("The zip_view should not be empty") { REQUIRE_FALSE(gst_zipped.empty()); }
    THEN("The size should be two") { REQUIRE(gst_zipped.size() == 2); }
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

    auto gst_zipped = gst::zip(std::move(vec), std::move(lst), std::move(deq));

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

SCENARIO("Testing gst::zip_view with constant containers", "[edge]")
{
  GIVEN("Constant containers")
  {
    std::vector<int> const  vec = {1, 2, 3};
    std::list<char> const   lst = {'a', 'b', 'c'};
    std::deque<float> const deq = {1.1F, 2.2F, 3.3F};

    auto gst_zipped = gst::zip(vec, lst, deq);

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

SCENARIO("Testing constant gst::zip_view with const containers", "[edge]")
{
  GIVEN("Constant containers")
  {
    std::vector<int> const  vec = {1, 2, 3};
    std::list<char> const   lst = {'a', 'b', 'c'};
    std::deque<float> const deq = {1.1F, 2.2F, 3.3F};

    gst::zip_view const gst_zipped = gst::zip(vec, lst, deq);

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

SCENARIO("Testing constant gst::zip_view with non-const containers", "[edge]")
{
  GIVEN("Non-const containers")
  {
    std::vector<int>  vec = {1, 2, 3};
    std::list<char>   lst = {'a', 'b', 'c'};
    std::deque<float> deq = {1.1F, 2.2F, 3.3F};

    gst::zip_view const gst_zipped = gst::zip(vec, lst, deq);

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

SCENARIO("Reading elements using subscript operator", "[edge]")
{
  GIVEN("two arrays of the same size but different element types")
  {
    std::array<int, 3> v1{1, 2, 3};
    std::list<double>  v2{4.1, 5.2, 6.3};

    WHEN("we create a zip_view")
    {
      auto const zip = gst::zip(v1, v2);

      THEN("we can read the elements using the subscript operator")
      {
        REQUIRE((zip[0] == std::make_tuple(1, 4.1)));
        REQUIRE((zip[1] == std::make_tuple(2, 5.2)));
        REQUIRE((zip[2] == std::make_tuple(3, 6.3)));
      }
    }
  }
}

SCENARIO("Writing elements using subscript operator", "[edge]")
{
  GIVEN("two arrays of the same size but different element types")
  {
    std::array<int, 3> v1{1, 2, 3};
    std::list<double>  v2{4.1, 5.2, 6.3};

    WHEN("we create a zip_view")
    {
      auto zip = gst::zip(v1, v2);

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

    WHEN("we create a const zip_view")
    {
      auto const zip = gst::zip(v1, v2);

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
  }
}

SCENARIO("Testing temporary gst::zip_view", "[edge]")
{
  using Vec = std::vector<int>;
  using Lst = std::list<char>;
  using Deq = std::deque<float>;

  GIVEN("Three containers that go out of scope")
  {
    Vec vec = {1, 2, 3};
    Lst lst = {'a', 'b', 'c'};
    Deq deq = {1.1F, 2.2F, 3.3F};

    THEN("The zip_view should not have dangling references")
    {
      REQUIRE(gst::zip(vec, lst, deq).size() == 3);
      REQUIRE(std::get<0>(gst::zip(vec, lst, deq)[0]) == 1);
      REQUIRE(std::get<1>(gst::zip(vec, lst, deq)[0]) == 'a');
      REQUIRE(std::equal_to{}(std::get<2>(gst::zip(vec, lst, deq)[0]), 1.1F));
    }
  }

  GIVEN("Temporary containers")
  {
    THEN("The zip_view should not be empty")
    {
      REQUIRE_FALSE(gst::zip(Vec{1, 2, 3}, Lst{'a', 'b', 'c'}).empty());
    }
    THEN("The size should be three")
    {
      REQUIRE(gst::zip(Vec{1, 2, 3}, Lst{'a', 'b', 'c'}).size() == 3);
    }
    THEN("The front element should be the first elements of each container")
    {
      REQUIRE(std::get<0>(gst::zip(Vec{1, 2, 3}, Lst{'a', 'b', 'c'}).front()) == 1);
      REQUIRE(std::get<1>(gst::zip(Vec{1, 2, 3}, Lst{'a', 'b', 'c'}).front()) == 'a');
    }
    THEN("The back element should be the last elements of each container")
    {
      REQUIRE(std::get<0>(gst::zip(Vec{1, 2, 3}, Lst{'a', 'b', 'c'}).back()) == 3);
      REQUIRE(std::get<1>(gst::zip(Vec{1, 2, 3}, Lst{'a', 'b', 'c'}).back()) == 'c');
    }
  }
}

SCENARIO("Testing gst::zip_view with modified containers", "[edge]")
{
  GIVEN("Containers that are modified after creating zip_view")
  {
    std::vector<int>  vec = {1, 2, 3};
    std::list<char>   lst = {'a', 'b', 'c'};
    std::deque<float> deq = {1.1F, 2.2F, 3.3F};

    auto gst_zipped = gst::zip(vec, lst, deq);

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
