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
