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
#include <list>
#include <numeric>
#include <vector>

SCENARIO("zip_view zips three containers and applies for_each", "[algorithms]")
{
  GIVEN("three vectors of same size and different element types")
  {
    std::array<int, 3> v1{1, 2, 3};
    std::vector<float> v2{4.1F, 5.2F, 6.3F, 7.4F};
    std::list<char>    v3{'a', 'b', 'c', 'd', 'e'};

    THEN("we can zip them")
    {
      auto zip = gst::ranges::views::zip(v1, v2, v3);
      AND_THEN("we can apply for_each to the zipped view")
      {
        std::for_each(zip.begin(),
                      zip.end(),
                      [](auto&& t)
                      {
                        std::get<0>(t) *= 2;
                        std::get<1>(t) += 1.0F;
                        std::get<2>(t)  = static_cast<char>(std::toupper(std::get<2>(t)));
                      });

        REQUIRE(v1 == std::array<int, 3>{2, 4, 6});
        REQUIRE(v2 == std::vector<float>{5.1F, 6.2F, 7.3F, 7.4F});
        REQUIRE(v3 == std::list<char>{'A', 'B', 'C', 'd', 'e'});
      }
    }
  }
}

SCENARIO("zip_view zips three containers and counts elements with count_if", "[algorithms]")
{
  GIVEN("three vectors of same size and different element types")
  {
    std::array<int, 3> v1{1, 2, 3};
    std::vector<float> v2{4.1F, 5.2F, 6.3F, 7.4F};
    std::list<char>    v3{'a', 'b', 'c', 'd', 'e'};

    THEN("we can zip them")
    {
      auto zip = gst::ranges::views::zip(v1, v2, v3);
      AND_THEN("we can count elements in the zipped view with count_if")
      {
        auto count = std::count_if(
          zip.begin(), zip.end(), [](auto const& t) { return std::get<0>(t) % 2 == 0; });

        REQUIRE(count == 1);
      }
    }
  }
}

SCENARIO("zip_view zips three containers and removes elements with remove_if", "[algorithms]")
{
  GIVEN("three vectors of same size and different element types")
  {
    std::array<bool, 3> v1{false, true, false};
    std::vector<float>  v2{4.1F, 5.2F, 6.3F, 7.4F};
    std::list<char>     v3{'a', 'b', 'c', 'd', 'e'};

    THEN("we can zip them")
    {
      auto zip = gst::ranges::views::zip(v1, v2, v3);
      AND_THEN("we can remove elements from the zipped view with remove_if")
      {
        auto new_end =
          std::remove_if(zip.begin(), zip.end(), [](auto const&& t) { return std::get<0>(t); });

        REQUIRE(new_end == std::next(zip.begin(), 2));
        REQUIRE(v1 == std::array<bool, 3>{false, false, false});
        REQUIRE(v2 == std::vector<float>{4.1F, 6.3F, 6.3F, 7.4F});
        REQUIRE(v3 == std::list<char>{'a', 'c', 'c', 'd', 'e'});
      }
    }
  }
}

SCENARIO("zip_view zips three containers and accumulate", "[algorithms]")
{
  GIVEN("three vectors of same size and different element types")
  {
    std::array<bool, 3> v1{true, false, true};
    std::vector<double> v2{4.1, 5.2, 6.3, 7.4};
    std::list<char>     v3{'a', 'b', 'c', 'd', 'e'};

    THEN("we can zip them")
    {
      auto zip = gst::ranges::views::zip(v1, v2, v3);

      AND_THEN("we can accumulate the zipped view depending on the first element")
      {
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
}

SCENARIO("zip_view zips three containers and transforms (unary)", "[algorithms]")
{
  GIVEN("three vectors of same size and different element types")
  {
    std::array<int, 3>  v1{1, 2, 3};
    std::vector<double> v2{4.1, 5.2, 6.3, 7.4};
    std::list<char>     v3{'a', 'b', 'c', 'd', 'e'};

    THEN("we can zip them")
    {
      auto zip = gst::ranges::views::zip(v1, v2, v3);
      AND_THEN("we can transform the zipped view")
      {
        std::array<double, 3> res;
        std::array<double, 3> ref{1 + 4.1 + 'a', 2 + 5.2 + 'b', 3 + 6.3 + 'c'};

        auto itr = std::transform(zip.begin(),
                                  zip.end(),
                                  res.begin(),
                                  [](auto const& t)
                                  { return std::apply([](auto&&... v) { return (v + ...); }, t); });

        REQUIRE(res == ref);
        REQUIRE(itr == res.end());
      }
    }
  }
}

SCENARIO("zip_view zips two containers and transforms (binary)", "[algorithms]")
{
  GIVEN("two vectors of same size and different element types")
  {
    std::vector<int>    v1{1, 2, 3};
    std::vector<double> v2{4.1, 5.2, 6.3};

    THEN("we can zip them")
    {
      auto zip1 = gst::ranges::views::zip(v1);
      auto zip2 = gst::ranges::views::zip(v2);

      AND_THEN("we can transform the zipped views with a binary operation")
      {
        std::vector<double> res(v1.size());
        std::vector<double> ref{1 + 4.1, 2 + 5.2, 3 + 6.3};

        auto itr =
          std::transform(zip1.begin(),
                         zip1.end(),
                         zip2.begin(),
                         res.begin(),
                         [](auto const& t1, auto const& t2)
                         {
                           return std::apply([](auto&& arg1, auto&& arg2) { return arg1 + arg2; },
                                             std::tuple_cat(t1, t2));
                         });

        REQUIRE(res == ref);
        REQUIRE(itr == res.end());
      }
    }
  }
}

SCENARIO("zip_view zips three containers and fills", "[algorithms]")
{
  GIVEN("three vectors of same size and different element types")
  {
    std::array<int, 3> v1{1, 2, 3};
    std::vector<float> v2{4.1F, 5.2F, 6.3F, 7.4F};
    std::list<char>    v3{'a', 'b', 'c', 'd', 'e'};

    THEN("we can zip them")
    {
      auto zip = gst::ranges::views::zip(v1, v2, v3);
      AND_THEN("we can fill the zipped view")
      {
        std::fill(zip.begin(), zip.end(), std::make_tuple(0, 0.0F, 'z'));

        REQUIRE(v1 == std::array<int, 3>{0, 0, 0});
        REQUIRE(v2 == std::vector<float>{0.0F, 0.0F, 0.0F, 7.4F});
        REQUIRE(v3 == std::list<char>{'z', 'z', 'z', 'd', 'e'});
      }
    }
  }
}

SCENARIO("zip_view zips three containers and fills with a generator", "[algorithms]")
{
  GIVEN("three vectors of same size and different element types")
  {
    std::array<int, 3> v1{0, 0, 0};
    std::vector<float> v2{0.0F, 0.0F, 0.0F, 0.0F};
    std::list<char>    v3{' ', ' ', ' ', ' ', ' '};

    THEN("we can zip them")
    {
      auto zip = gst::ranges::views::zip(v1, v2, v3);
      AND_THEN("we can fill the zipped view with a generator")
      {
        auto generator = [n = 1, f = 1.1F, c = 'a']() mutable
        { return std::make_tuple(n++, f++, c++); };

        std::generate(zip.begin(), zip.end(), generator);

        REQUIRE(v1 == std::array<int, 3>{1, 2, 3});
        REQUIRE(v2 == std::vector<float>{1.1F, 2.1F, 3.1F, 0.0F});
        REQUIRE(v3 == std::list<char>{'a', 'b', 'c', ' ', ' '});
      }
    }
  }
}
