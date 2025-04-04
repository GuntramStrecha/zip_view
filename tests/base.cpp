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
      REQUIRE(gst_zipped.size() == 3);
    }

    THEN("The front element shall be the first elements of each container")
    {
      auto gst_front = gst_zipped.front();
      auto std_front = std_zipped.front();
      REQUIRE(std::get<0>(gst_front) == std::get<0>(std_front));
      REQUIRE(std::get<1>(gst_front) == std::get<1>(std_front));
      REQUIRE(std::equal_to{}(std::get<2>(gst_front), std::get<2>(std_front)));
    }

    THEN("The back element shall be the last elements of each container")
    {
      auto gst_back = gst_zipped.back();
      REQUIRE(std::get<0>(gst_back) == 3);
      REQUIRE(std::get<1>(gst_back) == 'c');
      REQUIRE(std::equal_to{}(std::get<2>(gst_back), 3.3F));
    }

    THEN("The subscript operator shall return the correct elements")
    {
      auto gst_elem = gst_zipped[1];
      REQUIRE(std::get<0>(gst_elem) == 2);
      REQUIRE(std::get<1>(gst_elem) == 'b');
      REQUIRE(std::equal_to{}(std::get<2>(gst_elem), 2.2F));
    }

    THEN("The conversion operator shall return true") { REQUIRE(static_cast<bool>(gst_zipped)); }
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
      REQUIRE(gst_zipped.size() == 2);
    }
    THEN("The front element shall be the first elements of each container")
    {
      auto gst_front = gst_zipped.front();
      auto std_front = std_zipped.front();
      REQUIRE(std::get<0>(gst_front) == std::get<0>(std_front));
      REQUIRE(std::get<1>(gst_front) == std::get<1>(std_front));
      REQUIRE(std::equal_to{}(std::get<2>(gst_front), std::get<2>(std_front)));
    }

    THEN("The back element shall be the last elements of each container up to the smallest size")
    {
      auto gst_back = gst_zipped.back();
      REQUIRE(std::get<0>(gst_back) == 2);
      REQUIRE(std::get<1>(gst_back) == 'b');
      REQUIRE(std::equal_to{}(std::get<2>(gst_back), 2.2F));
    }

    THEN("The subscript operator shall return the correct elements")
    {
      auto gst_elem = gst_zipped[1];
      REQUIRE(std::get<0>(gst_elem) == 2);
      REQUIRE(std::get<1>(gst_elem) == 'b');
      REQUIRE(std::equal_to{}(std::get<2>(gst_elem), 2.2F));
    }

    THEN("The conversion operator shall return true") { REQUIRE(static_cast<bool>(gst_zipped)); }
  }
}
