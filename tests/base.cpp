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
#include <list>
#include <map>
#include <ranges>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

SCENARIO("Comparing zip_view with std::ranges::zip_view using different containers and lengths",
         "[zip_view]")
{
  GIVEN("Containers of the same length")
  {
    std::vector<int>                     vec   = {1, 2, 3};
    std::list<char>                      lst   = {'a', 'b', 'c'};
    std::deque<float>                    deq   = {1.1F, 2.2F, 3.3F};
    std::set<double>                     set   = {4.4, 5.5, 6.6};
    std::unordered_set<int>              uset  = {1, 2, 3};
    std::unordered_multiset<char>        umset = {'a', 'b', 'c'};
    std::unordered_map<int, float>       umap  = {{1, 1.1F}, {2, 2.2F}, {3, 3.3F}};
    std::unordered_multimap<int, double> ummap = {{1, 4.4}, {2, 5.5}, {3, 6.6}};
    std::map<int, float>                 map   = {{1, 1.1F}, {2, 2.2F}, {3, 3.3F}};
    std::multimap<int, double>           mmap  = {{1, 4.4}, {2, 5.5}, {3, 6.6}};
    std::forward_list<int>               flst  = {1, 2, 3};

    WHEN("Using gst::ranges::views::zip to create gst::ranges::zip_view for the containers")
    {
      auto gst_zipped =
        gst::ranges::views::zip(vec, lst, deq, set, uset, umset, umap, ummap, map, mmap, flst);

      THEN("The zipped elements shall match std::ranges::zip_view")
      {
        auto std_zipped =
          std::ranges::views::zip(vec, lst, deq, set, uset, umset, umap, ummap, map, mmap, flst);

        auto gst_it = gst_zipped.begin();
        auto std_it = std_zipped.begin();

        while (gst_it != gst_zipped.end() && std_it != std_zipped.end())
        {
          REQUIRE((*gst_it == *std_it));
          ++gst_it;
          ++std_it;
        }
        REQUIRE(gst_it == gst_zipped.end());
        REQUIRE(std_it == std_zipped.end());
      }
    }
  }

  GIVEN("Containers of different lengths")
  {
    std::vector<int>                     vec   = {1, 2, 3, 4};
    std::list<char>                      lst   = {'a', 'b', 'c'};
    std::deque<float>                    deq   = {1.1F, 2.2F};
    std::set<double>                     set   = {4.4, 5.5};
    std::unordered_set<int>              uset  = {1, 2, 3, 4, 5, 6, 7};
    std::unordered_multiset<char>        umset = {'a', 'b', 'c', 'd', 'e'};
    std::unordered_map<int, float>       umap  = {{1, 1.1F}, {2, 2.2F}, {3, 3.3F}};
    std::unordered_multimap<int, double> ummap = {{1, 4.4}, {2, 5.5}};
    std::map<int, float>                 map   = {{1, 1.1F}, {2, 2.2F}, {3, 3.3F}};
    std::multimap<int, double>           mmap  = {{1, 4.4}, {2, 5.5}};
    std::forward_list<int>               flst  = {1, 2, 3, 4};

    WHEN("Using gst::ranges::views::zip to create gst::ranges::zip_view for the containers")
    {
      auto gst_zipped =
        gst::ranges::views::zip(vec, lst, deq, set, uset, umset, umap, ummap, map, mmap, flst);

      THEN("The zipped elements shall match std::ranges::zip_view w.r.t. the shortest container")
      {
        auto std_zipped =
          std::ranges::views::zip(vec, lst, deq, set, uset, umset, umap, ummap, map, mmap, flst);

        auto gst_it = gst_zipped.begin();
        auto std_it = std_zipped.begin();

        while (gst_it != gst_zipped.end() && std_it != std_zipped.end())
        {
          REQUIRE((*gst_it == *std_it));
          ++gst_it;
          ++std_it;
        }
        REQUIRE(gst_it == gst_zipped.end());
        REQUIRE(std_it == std_zipped.end());
      }
    }
  }

  GIVEN("Empty containers")
  {
    std::vector<int>                     vec   = {};
    std::list<char>                      lst   = {};
    std::deque<float>                    deq   = {};
    std::set<double>                     set   = {};
    std::unordered_set<int>              uset  = {};
    std::unordered_multiset<char>        umset = {};
    std::unordered_map<int, float>       umap  = {};
    std::unordered_multimap<int, double> ummap = {};
    std::map<int, float>                 map   = {};
    std::multimap<int, double>           mmap  = {};
    std::forward_list<int>               flst  = {};

    WHEN("Using gst::ranges::views::zip to create gst::ranges::zip_view for the containers")
    {
      auto gst_zipped =
        gst::ranges::views::zip(vec, lst, deq, set, uset, umset, umap, ummap, map, mmap, flst);

      THEN("The zipped view shall be empty and match std::ranges::zip_view")
      {
        auto std_zipped =
          std::ranges::views::zip(vec, lst, deq, set, uset, umset, umap, ummap, map, mmap, flst);

        REQUIRE(gst_zipped.begin() == gst_zipped.end());
        REQUIRE(std_zipped.begin() == std_zipped.end());
      }
    }
  }
}

SCENARIO("Testing gst::ranges::zip_view member functions", "zip_view")
{
  GIVEN("Empty containers")
  {
    std::vector<int>  vec = {};
    std::list<char>   lst = {};
    std::deque<float> deq = {};

    auto gst_zipped = gst::ranges::views::zip(vec, lst, deq);
    auto std_zipped = std::ranges::views::zip(vec, lst, deq);

    THEN("The zip_view shall be empty") { REQUIRE(gst_zipped.empty()); }
    THEN("The size shall be zero") { REQUIRE(gst_zipped.size() == 0); }
    THEN("The conversion operator shall return false")
    {
      REQUIRE_FALSE(static_cast<bool>(gst_zipped));
    }
    THEN("The zipped elements shall match std::ranges::zip_view")
    {
      REQUIRE(gst_zipped.begin() == gst_zipped.end());
      REQUIRE(std_zipped.begin() == std_zipped.end());
    }
  }

  GIVEN("Containers of the same length")
  {
    std::vector<int>  vec = {1, 2, 3};
    std::list<char>   lst = {'a', 'b', 'c'};
    std::deque<float> deq = {1.1F, 2.2F, 3.3F};

    auto gst_zipped = gst::ranges::views::zip(vec, lst, deq);
    auto std_zipped = std::ranges::views::zip(vec, lst, deq);

    THEN("The zip_view shall not be empty") { REQUIRE_FALSE(gst_zipped.empty()); }
    THEN("The size shall be equal to the smallest container size")
    {
      REQUIRE(gst_zipped.size() == std_zipped.size());
    }

    THEN("The front element shall be the first elements of each container")
    {
      auto gst_front = gst_zipped.front();
      auto std_front = std_zipped.front();
      REQUIRE((gst_front == std_front));
    }

    THEN("The back element shall be the last elements of each container")
    {
      auto gst_back = gst_zipped.back();
      REQUIRE((gst_back == std::make_tuple(3, 'c', 3.3F)));
    }

    THEN("The subscript operator shall return the correct elements")
    {
      auto gst_elem = gst_zipped[1];
      REQUIRE((gst_elem == std::make_tuple(2, 'b', 2.2F)));
    }

    THEN("The conversion operator shall return true")
    {
      REQUIRE(static_cast<bool>(gst_zipped) == static_cast<bool>(std_zipped));
    }
  }

  GIVEN("Containers of different sizes")
  {
    std::vector<int>  vec = {1, 2, 3, 4};
    std::list<char>   lst = {'a', 'b', 'c'};
    std::deque<float> deq = {1.1F, 2.2F};

    auto gst_zipped = gst::ranges::views::zip(vec, lst, deq);
    auto std_zipped = std::ranges::views::zip(vec, lst, deq);

    THEN("The zip_view shall not be empty") { REQUIRE_FALSE(gst_zipped.empty()); }

    THEN("The size shall be equal to the smallest container size")
    {
      REQUIRE(gst_zipped.size() == std_zipped.size());
    }

    THEN("The front element shall be the first elements of each container")
    {
      auto gst_front = gst_zipped.front();
      auto std_front = std_zipped.front();
      REQUIRE((gst_front == std_front));
    }

    THEN("The back element shall be the last elements of each container up to the smallest size")
    {
      auto gst_back = gst_zipped.back();
      REQUIRE((gst_back == std::make_tuple(2, 'b', 2.2F)));
    }

    THEN("The subscript operator shall return the correct elements")
    {
      auto gst_elem = gst_zipped[1];
      REQUIRE((gst_elem == std::make_tuple(2, 'b', 2.2F)));
    }

    THEN("The conversion operator shall return correct boolean value")
    {
      REQUIRE(static_cast<bool>(gst_zipped) == static_cast<bool>(std_zipped));
    }
  }

  GIVEN("Single container (N=1 case)")
  {
    THEN("The zip_view shall have correct size")
    {
      std::vector<int> vec        = {1, 2, 3, 4, 5};
      auto             gst_zipped = gst::ranges::views::zip(vec);
      REQUIRE(gst_zipped.size() == 5);
    }

    THEN("Elements are tuples with single element")
    {
      std::vector<int> vec        = {1, 2, 3, 4, 5};
      auto             gst_zipped = gst::ranges::views::zip(vec);
      auto             std_zipped = std::ranges::views::zip(vec);
      auto             elem       = gst_zipped[2];
      REQUIRE(std::get<0>(elem) == std::get<0>(std_zipped[2]));
    }

    THEN("front() returns correct element")
    {
      std::vector<int> vec        = {1, 2, 3, 4, 5};
      auto             gst_zipped = gst::ranges::views::zip(vec);
      REQUIRE(std::get<0>(gst_zipped.front()) == 1);
    }

    THEN("back() returns correct element")
    {
      std::vector<int> vec        = {1, 2, 3, 4, 5};
      auto             gst_zipped = gst::ranges::views::zip(vec);
      REQUIRE(std::get<0>(gst_zipped.back()) == 5);
    }

    THEN("Can iterate and modify elements")
    {
      std::vector<int> vec        = {1, 2, 3, 4, 5};
      auto             gst_zipped = gst::ranges::views::zip(vec);
      for (auto&& elem : gst_zipped) { std::get<0>(elem) *= 2; }
      REQUIRE(vec == std::vector<int>{2, 4, 6, 8, 10});
      REQUIRE(std::get<0>(gst_zipped.front()) == 2);
      REQUIRE(std::get<0>(gst_zipped.back()) == 10);
    }
  }
}

SCENARIO("Testing zip_view with many containers (stress test)", "[zip_view]")
{
  GIVEN("10 containers of different types")
  {
    std::vector<int>   v1  = {1, 2, 3};
    std::vector<int>   v2  = {4, 5, 6};
    std::vector<int>   v3  = {7, 8, 9};
    std::vector<int>   v4  = {10, 11, 12};
    std::vector<int>   v5  = {13, 14, 15};
    std::list<int>     v6  = {16, 17, 18};
    std::list<int>     v7  = {19, 20, 21};
    std::deque<int>    v8  = {22, 23, 24};
    std::deque<int>    v9  = {25, 26, 27};
    std::array<int, 3> v10 = {28, 29, 30};

    WHEN("Creating zip_view with 10 containers")
    {
      auto gst_zipped = gst::ranges::views::zip(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10);
      auto std_zipped = std::ranges::views::zip(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10);

      THEN("The zip_view has correct size") { REQUIRE(gst_zipped.size() == 3); }

      THEN("All elements are accessible")
      {
        auto elem = gst_zipped[1];
        REQUIRE(std::get<0>(elem) == 2);
        REQUIRE(std::get<5>(elem) == 17);
        REQUIRE(std::get<9>(elem) == 29);
      }

      THEN("Matches std::ranges::zip_view behavior")
      {
        auto gst_it = gst_zipped.begin();
        auto std_it = std_zipped.begin();
        while (gst_it != gst_zipped.end())
        {
          REQUIRE((*gst_it == *std_it));
          ++gst_it;
          ++std_it;
        }
      }

      THEN("Can modify all containers through zip_view")
      {
        for (auto&& elem : gst_zipped)
        {
          std::get<0>(elem) += 100;
          std::get<9>(elem) += 1000;
        }
        REQUIRE(v1[0] == 101);
        REQUIRE(v10[0] == 1028);
      }
    }
  }

  GIVEN("15 containers with varying sizes")
  {
    std::vector<int> v1  = {1};
    std::vector<int> v2  = {2, 3};
    std::vector<int> v3  = {4, 5, 6};
    std::vector<int> v4  = {7, 8, 9, 10};
    std::vector<int> v5  = {11, 12, 13, 14, 15};
    std::vector<int> v6  = {16};
    std::vector<int> v7  = {17};
    std::vector<int> v8  = {18};
    std::vector<int> v9  = {19};
    std::vector<int> v10 = {20};
    std::vector<int> v11 = {21};
    std::vector<int> v12 = {22};
    std::vector<int> v13 = {23};
    std::vector<int> v14 = {24};
    std::vector<int> v15 = {25};

    WHEN("Creating zip_view with 15 containers")
    {
      auto zipped =
        gst::ranges::views::zip(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15);

      THEN("Size is limited by shortest container") { REQUIRE(zipped.size() == 1); }

      THEN("All 15 elements in tuple are accessible")
      {
        auto elem = zipped.front();
        REQUIRE(std::get<0>(elem) == 1);
        REQUIRE(std::get<7>(elem) == 18);
        REQUIRE(std::get<14>(elem) == 25);
      }
    }
  }
}

SCENARIO("Testing assignment operators", "[zip_view]")
{
  GIVEN("Two zip_views over different vectors")
  {
    WHEN("Copy assignment from different zip_view is performed")
    {
      std::vector<int> v1 = {1, 2, 3};
      std::vector<int> v2 = {4, 5, 6};
      std::vector<int> v3 = {7, 8, 9, 10};
      std::vector<int> v4 = {11, 12, 13, 14};

      auto zipped1 = gst::ranges::views::zip(v1, v2);
      auto zipped2 = gst::ranges::views::zip(v3, v4);

      zipped1 = zipped2;

      THEN("Views are rebound (std::ranges::zip_view semantics)")
      {
        // Assignment rebinds the views, not copying container contents
        // zipped1 now refers to v3 and v4
        REQUIRE(zipped1.size() == 4);
        REQUIRE(std::get<0>(zipped1.front()) == 7);
        REQUIRE(std::get<1>(zipped1.front()) == 11);
        REQUIRE(std::get<0>(zipped1.back()) == 10);
        REQUIRE(std::get<1>(zipped1.back()) == 14);

        // Original containers v1 and v2 are unchanged
        REQUIRE(v1 == std::vector<int>{1, 2, 3});
        REQUIRE(v2 == std::vector<int>{4, 5, 6});

        // Modifying through zipped1 now affects v3 and v4
        std::get<0>(zipped1[0]) = 99;
        std::get<1>(zipped1[1]) = 88;
        REQUIRE(v3[0] == 99);
        REQUIRE(v4[1] == 88);
        REQUIRE(v1[0] == 1);
        REQUIRE(v2[1] == 5);
      }
    }

    WHEN("Move assignment from different zip_view is performed")
    {
      std::vector<int> v1 = {1, 2, 3};
      std::vector<int> v2 = {4, 5, 6};
      std::vector<int> v3 = {7, 8, 9, 10};
      std::vector<int> v4 = {11, 12, 13, 14};

      auto zipped1 = gst::ranges::views::zip(v1, v2);
      auto zipped2 = gst::ranges::views::zip(v3, v4);

      zipped1 = std::move(zipped2);

      THEN("Views are rebound via move")
      {
        // Move assignment also rebinds the views
        REQUIRE(zipped1.size() == 4);
        REQUIRE(std::get<0>(zipped1[2]) == 9);
        REQUIRE(std::get<1>(zipped1[3]) == 14);

        // Original containers v1 and v2 are unchanged
        REQUIRE(v1 == std::vector<int>{1, 2, 3});
        REQUIRE(v2 == std::vector<int>{4, 5, 6});
      }
    }

    WHEN("Copy self-assignment is performed")
    {
      std::vector<int> v1 = {1, 2, 3};
      std::vector<int> v2 = {4, 5, 6};

      auto zipped1 = gst::ranges::views::zip(v1, v2);

      auto& ref = zipped1;
      zipped1   = ref;

      THEN("The zip_view remains valid and functional")
      {
        REQUIRE(zipped1.size() == 3);
        REQUIRE(std::get<0>(zipped1.front()) == 1);
        REQUIRE(std::get<1>(zipped1.back()) == 6);
      }
    }

    WHEN("Move self-assignment is performed")
    {
      std::vector<int> v1 = {1, 2, 3};
      std::vector<int> v2 = {4, 5, 6};

      auto zipped1 = gst::ranges::views::zip(v1, v2);

      auto& ref = zipped1;
      zipped1   = std::move(ref);

      THEN("The zip_view remains in a valid state")
      {
        REQUIRE(zipped1.size() == 3);
        REQUIRE(std::get<0>(zipped1[1]) == 2);
      }
    }
  }
}

SCENARIO("Testing nested zip_views (zip of zip_views)", "[zip_view][nested]")
{
  {
    GIVEN("Empty zip_views")
    {
      std::vector<int>  v1 = {};
      std::vector<int>  v2 = {};
      std::vector<char> v3 = {};
      std::vector<char> v4 = {};

      auto zip1 = gst::ranges::views::zip(v1, v2);
      auto zip2 = gst::ranges::views::zip(v3, v4);

      WHEN("Zipping two empty zip_views")
      {
        auto nested = gst::ranges::views::zip(zip1, zip2);

        THEN("The nested zip_view is empty")
        {
          REQUIRE(nested.empty());
          REQUIRE(nested.size() == 0);
          REQUIRE(nested.begin() == nested.end());
        }
      }
    }

    GIVEN("A single zip_view with other containers")
    {
      std::vector<int>   v1 = {1, 2, 3};
      std::vector<int>   v2 = {4, 5, 6};
      std::vector<float> v3 = {1.1F, 2.2F, 3.3F};

      auto zip1 = gst::ranges::views::zip(v1, v2);

      WHEN("Zipping one zip_view with a regular container")
      {
        auto nested = gst::ranges::views::zip(zip1, v3);

        THEN("The nested zip_view has correct size") { REQUIRE(nested.size() == 3); }

        THEN("Can iterate through nested zip_view")
        {
          int count = 0;
          for (auto it = nested.begin(); it != nested.end(); ++it) { ++count; }
          REQUIRE(count == 3);
        }

        THEN("Can access and verify size")
        {
          REQUIRE(zip1.size() == 3);
          REQUIRE(nested.size() == 3);
          REQUIRE_FALSE(nested.empty());
        }

        THEN("Can access elements correctly using iterators")
        {
          auto it     = nested.begin();
          auto elem0  = *it;
          auto tuple0 = std::get<0>(elem0);
          REQUIRE(std::get<0>(tuple0) == 1);
          REQUIRE(std::get<1>(tuple0) == 4);
          REQUIRE(std::get<1>(elem0) > 1.0F);
          REQUIRE(std::get<1>(elem0) < 1.2F);

          ++it;
          auto elem1  = *it;
          auto tuple1 = std::get<0>(elem1);
          REQUIRE(std::get<0>(tuple1) == 2);
          REQUIRE(std::get<1>(tuple1) == 5);
          REQUIRE(std::get<1>(elem1) > 2.1F);
          REQUIRE(std::get<1>(elem1) < 2.3F);
        }

        THEN("Can modify regular container elements through nested zip_view")
        {
          auto it          = nested.begin();
          std::get<1>(*it) = 9.9F;
          REQUIRE(v3[0] > 9.8F);
          REQUIRE(v3[0] < 10.0F);
        }
      }
    }

    GIVEN("Multiple zip_views of the same length")
    {
      std::vector<int>  v1 = {1, 2, 3, 4};
      std::vector<int>  v2 = {5, 6, 7, 8};
      std::vector<char> v3 = {'a', 'b', 'c', 'd'};
      std::vector<char> v4 = {'w', 'x', 'y', 'z'};
      std::list<float>  v5 = {1.1F, 2.2F, 3.3F, 4.4F};
      std::list<float>  v6 = {5.5F, 6.6F, 7.7F, 8.8F};

      auto zip1 = gst::ranges::views::zip(v1, v2);
      auto zip2 = gst::ranges::views::zip(v3, v4);
      auto zip3 = gst::ranges::views::zip(v5, v6);

      WHEN("Zipping three zip_views together")
      {
        auto nested = gst::ranges::views::zip(zip1, zip2, zip3);

        THEN("The nested zip_view has correct size") { REQUIRE(nested.size() == 4); }

        THEN("Can iterate and access all elements")
        {
          auto it    = nested.begin();
          auto elem0 = *it;
          REQUIRE((std::get<0>(elem0) == std::make_tuple(1, 5)));
          REQUIRE((std::get<1>(elem0) == std::make_tuple('a', 'w')));
          REQUIRE((std::get<2>(elem0) == std::make_tuple(1.1F, 5.5F)));

          std::advance(it, 2);
          auto elem2 = *it;
          REQUIRE((std::get<0>(elem2) == std::make_tuple(3, 7)));
          REQUIRE((std::get<1>(elem2) == std::make_tuple('c', 'y')));
          REQUIRE((std::get<2>(elem2) == std::make_tuple(3.3F, 7.7F)));
        }

        THEN("Can modify all underlying containers through nested zip_view")
        {
          for (auto&& elem : nested)
          {
            std::get<0>(std::get<0>(elem)) += 100;
            std::get<1>(std::get<1>(elem))  = 'Z';
            std::get<0>(std::get<2>(elem)) += 10.0F;
          }

          REQUIRE(v1[0] == 101);
          REQUIRE(v1[3] == 104);
          REQUIRE(v4[0] == 'Z');
          REQUIRE(v4[3] == 'Z');
          REQUIRE(v5.front() > 11.0F);
          REQUIRE(v5.front() < 11.2F);
          REQUIRE(v5.back() > 14.3F);
          REQUIRE(v5.back() < 14.5F);
        }
      }
    }

    GIVEN("Multiple zip_views of different lengths")
    {
      std::vector<int>  v1 = {1, 2, 3, 4, 5};
      std::vector<int>  v2 = {10, 20, 30, 40, 50};
      std::vector<char> v3 = {'a', 'b', 'c'};
      std::vector<char> v4 = {'x', 'y', 'z'};
      std::deque<float> v5 = {1.1F, 2.2F};
      std::deque<float> v6 = {9.9F, 8.8F};

      auto zip1 = gst::ranges::views::zip(v1, v2);
      auto zip2 = gst::ranges::views::zip(v3, v4);
      auto zip3 = gst::ranges::views::zip(v5, v6);

      WHEN("Zipping zip_views of different lengths")
      {
        auto nested = gst::ranges::views::zip(zip1, zip2, zip3);

        THEN("Size is limited by shortest zip_view") { REQUIRE(nested.size() == 2); }

        THEN("Can access elements up to shortest length")
        {
          auto it    = nested.begin();
          auto elem0 = *it;
          REQUIRE((std::get<0>(elem0) == std::make_tuple(1, 10)));
          REQUIRE((std::get<1>(elem0) == std::make_tuple('a', 'x')));
          REQUIRE((std::get<2>(elem0) == std::make_tuple(1.1F, 9.9F)));

          ++it;
          auto elem1 = *it;
          REQUIRE((std::get<0>(elem1) == std::make_tuple(2, 20)));
          REQUIRE((std::get<1>(elem1) == std::make_tuple('b', 'y')));
          REQUIRE((std::get<2>(elem1) == std::make_tuple(2.2F, 8.8F)));
        }

        THEN("front() and back() work correctly")
        {
          auto front = nested.front();
          REQUIRE((std::get<0>(front) == std::make_tuple(1, 10)));

          auto back = nested.back();
          REQUIRE((std::get<0>(back) == std::make_tuple(2, 20)));
        }
      }
    }

    GIVEN("Mixed: zip_views and regular containers")
    {
      std::vector<int>   v1 = {1, 2, 3};
      std::vector<int>   v2 = {10, 20, 30};
      std::vector<char>  v3 = {'a', 'b', 'c'};
      std::vector<char>  v4 = {'x', 'y', 'z'};
      std::vector<float> v5 = {1.1F, 2.2F, 3.3F};
      std::list<double>  v6 = {100.0, 200.0, 300.0};

      auto zip1 = gst::ranges::views::zip(v1, v2);
      auto zip2 = gst::ranges::views::zip(v3, v4);

      WHEN("Zipping mix of zip_views and regular containers")
      {
        auto mixed = gst::ranges::views::zip(zip1, v5, zip2, v6);

        THEN("The mixed zip_view has correct size") { REQUIRE(mixed.size() == 3); }

        THEN("Can iterate through mixed structure")
        {
          int count = 0;
          for (auto it = mixed.begin(); it != mixed.end(); ++it) { ++count; }
          REQUIRE(count == 3);
        }

        THEN("Can access regular container elements")
        {
          auto it = mixed.begin();
          ++it;
          auto elem1 = *it;
          REQUIRE((std::get<0>(elem1) == std::make_tuple(2, 20)));
          REQUIRE(std::get<1>(elem1) > 2.1F);
          REQUIRE(std::get<1>(elem1) < 2.3F);
          REQUIRE((std::get<2>(elem1) == std::make_tuple('b', 'y')));
          REQUIRE(std::get<3>(elem1) > 199.0);
          REQUIRE(std::get<3>(elem1) < 201.0);
        }

        THEN("Can modify regular container elements through mixed structure")
        {
          for (auto&& elem : mixed)
          {
            std::get<1>(std::get<0>(elem)) *= 10;
            std::get<1>(elem)              += 100.0F;
          }

          REQUIRE(v2 == std::vector<int>{100, 200, 300});
          REQUIRE(v5 == std::vector<float>{101.1F, 102.2F, 103.3F});
        }
      }
    }

    GIVEN("Nested zip_views with different container types")
    {
      std::array<int, 3> arr1 = {1, 2, 3};
      std::list<int>     lst1 = {4, 5, 6};
      std::deque<char>   deq1 = {'a', 'b', 'c'};
      std::vector<char>  vec1 = {'x', 'y', 'z'};

      auto zip1 = gst::ranges::views::zip(arr1, lst1);
      auto zip2 = gst::ranges::views::zip(deq1, vec1);

      WHEN("Zipping zip_views with different underlying container types")
      {
        auto nested = gst::ranges::views::zip(zip1, zip2);

        THEN("Size matches shortest container") { REQUIRE(nested.size() == 3); }

        THEN("front() returns first elements")
        {
          auto front = nested.front();
          REQUIRE((std::get<0>(front) == std::make_tuple(1, 4)));
          REQUIRE((std::get<1>(front) == std::make_tuple('a', 'x')));
        }

        THEN("back() returns last elements")
        {
          auto back = nested.back();
          REQUIRE((std::get<0>(back) == std::make_tuple(3, 6)));
          REQUIRE((std::get<1>(back) == std::make_tuple('c', 'z')));
        }

        THEN("Can iterate with range-based for loop")
        {
          int count = 0;
          for (auto elem : nested)
          {
            (void)elem;
            ++count;
          }
          REQUIRE(count == 3);
        }
      }
    }

    GIVEN("Deeply nested zip_views")
    {
      std::vector<int> v1 = {1, 2};
      std::vector<int> v2 = {3, 4};
      std::vector<int> v3 = {5, 6};
      std::vector<int> v4 = {7, 8};

      auto zip1 = gst::ranges::views::zip(v1, v2);
      auto zip2 = gst::ranges::views::zip(v3, v4);
      auto zip3 = gst::ranges::views::zip(zip1, zip2);

      WHEN("Creating another zip from nested zip_views")
      {
        std::vector<int> v5   = {9, 10};
        auto             zip4 = gst::ranges::views::zip(zip3, v5);

        THEN("Deeply nested structure has correct size") { REQUIRE(zip4.size() == 2); }

        THEN("Can access deeply nested elements")
        {
          auto it    = zip4.begin();
          auto elem0 = *it;
          REQUIRE(std::get<1>(elem0) == 9);

          auto nested_tuple = std::get<0>(elem0);
          REQUIRE((std::get<0>(nested_tuple) == std::make_tuple(1, 3)));
          REQUIRE((std::get<1>(nested_tuple) == std::make_tuple(5, 7)));
        }

        THEN("Can modify through deep nesting")
        {
          auto it          = zip4.begin();
          std::get<1>(*it) = 99;
          REQUIRE(v5[0] == 99);
        }

        THEN("All nested structures have correct sizes")
        {
          REQUIRE(zip1.size() == 2);
          REQUIRE(zip2.size() == 2);
          REQUIRE(zip3.size() == 2);
          REQUIRE(zip4.size() == 2);
        }
      }
    }

    GIVEN("Zip_views with one element each")
    {
      std::vector<int>  v1 = {42};
      std::vector<int>  v2 = {84};
      std::vector<char> v3 = {'X'};

      auto zip1 = gst::ranges::views::zip(v1);
      auto zip2 = gst::ranges::views::zip(v2, v3);

      WHEN("Zipping single-element zip_views")
      {
        auto nested = gst::ranges::views::zip(zip1, zip2);

        THEN("Size is 1") { REQUIRE(nested.size() == 1); }

        THEN("Element is accessible")
        {
          auto it   = nested.begin();
          auto elem = *it;
          REQUIRE((std::get<0>(elem) == std::make_tuple(42)));
          REQUIRE((std::get<1>(elem) == std::make_tuple(84, 'X')));
        }

        THEN("Can iterate once")
        {
          int count = 0;
          for (auto it = nested.begin(); it != nested.end(); ++it) { ++count; }
          REQUIRE(count == 1);
        }
      }
    }

    GIVEN("Comparison with std::ranges::zip_view")
    {
      std::vector<int> v1 = {1, 2, 3};
      std::vector<int> v2 = {4, 5, 6};
      std::vector<int> v3 = {7, 8, 9};
      std::vector<int> v4 = {10, 11, 12};

      auto gst_zip1 = gst::ranges::views::zip(v1, v2, v3);
      auto gst_zip2 = gst::ranges::views::zip(v2, v3, v4);
      auto gst_zip3 = gst::ranges::views::zip(v4, v1, v2);
      auto std_zip1 = std::ranges::views::zip(v1, v2, v3);
      auto std_zip2 = std::ranges::views::zip(v2, v3, v4);
      auto std_zip3 = std::ranges::views::zip(v4, v1, v2);

      WHEN("Comparing nested gst::zip_view with std::ranges::zip_view")
      {
        auto gst_nested = gst::ranges::views::zip(gst_zip1, gst_zip2, gst_zip3);
        auto std_nested = std::ranges::views::zip(std_zip1, std_zip2, std_zip3);

        THEN("Sizes match") { REQUIRE(gst_nested.size() == std_nested.size()); }

        THEN("Elements match")
        {
          auto gst_it = gst_nested.begin();
          auto std_it = std_nested.begin();

          while (gst_it != gst_nested.end() && std_it != std_nested.end())
          {
            REQUIRE((*gst_it == *std_it));
            ++gst_it;
            ++std_it;
          }
          REQUIRE(gst_it == gst_nested.end());
          REQUIRE(std_it == std_nested.end());
        }
      }
    }

    GIVEN("Very large nested zip_views")
    {
      std::vector<int> v1(10'000, 1);
      std::vector<int> v2(10'000, 2);
      std::vector<int> v3(10'000, 3);
      std::vector<int> v4(10'000, 4);

      auto zip1 = gst::ranges::views::zip(v1, v2);
      auto zip2 = gst::ranges::views::zip(v3, v4);

      WHEN("Creating large nested zip_views")
      {
        auto nested = gst::ranges::views::zip(zip1, zip2);

        THEN("Size is correct") { REQUIRE(nested.size() == 10'000); }

        THEN("Can iterate through all elements")
        {
          int count = 0;
          for (auto it = nested.begin(); it != nested.end(); ++it)
          {
            ++count;
            if (count >= 100) break;
          }
          REQUIRE(count == 100);
        }

        THEN("Can access and modify elements")
        {
          auto elem = nested[5000];
          REQUIRE((std::get<0>(elem) == std::make_tuple(1, 2)));
          REQUIRE((std::get<1>(elem) == std::make_tuple(3, 4)));

          std::get<0>(std::get<0>(elem)) = 999;
          REQUIRE(v1[5000] == 999);
        }
      }
    }

    GIVEN("Multiple levels of nesting")
    {
      std::vector<int> v1 = {1, 2, 3};
      std::vector<int> v2 = {4, 5, 6};
      std::vector<int> v3 = {7, 8, 9};
      std::vector<int> v4 = {10, 11, 12};
      std::vector<int> v5 = {13, 14, 15};
      std::vector<int> v6 = {16, 17, 18};

      WHEN("Creating multiple levels of nested zip_views")
      {
        auto zip1 = gst::ranges::views::zip(v1, v2);
        auto zip2 = gst::ranges::views::zip(v3, v4);
        auto zip3 = gst::ranges::views::zip(v5, v6);

        auto level1 = gst::ranges::views::zip(zip1, zip2);
        auto level2 = gst::ranges::views::zip(level1, zip3);

        THEN("All levels have correct sizes")
        {
          REQUIRE(zip1.size() == 3);
          REQUIRE(zip2.size() == 3);
          REQUIRE(zip3.size() == 3);
          REQUIRE(level1.size() == 3);
          REQUIRE(level2.size() == 3);
        }

        THEN("Can iterate through multiple levels")
        {
          int count = 0;
          for (auto it = level2.begin(); it != level2.end(); ++it) { ++count; }
          REQUIRE(count == 3);
        }
      }
    }
  }
}
