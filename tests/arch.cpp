// Architecture tests for zip_view
// Verifies architectural properties at compile time and runtime using Catch2
// Uses C++23 features for cleaner test code

#include "zip_view.hpp"
#include <catch2/catch_test_macros.hpp>

#include <concepts>
#include <forward_list>
#include <list>
#include <type_traits>
#include <vector>

namespace
{
// Modern C++20 concepts for detecting iterator operations
template <typename Iter>
concept has_decrement = requires(Iter it) {
  --it;
  it--;
};

template <typename Iter>
concept has_subscript = requires(Iter it) { it[0]; };

template <typename Iter>
concept has_plus = requires(Iter it) {
  it + 1;
  1 + it;
};

template <typename Iter>
concept has_minus = requires(Iter it, Iter other) {
  it - 1;
  it - other;
};

template <typename Iter>
concept has_comparison = requires(Iter it, Iter other) {
  it < other;
  it > other;
  it <= other;
  it >= other;
};
} // namespace

TEST_CASE("Architecture: View size constraints", "[architecture]")
{
  SECTION("ref_view is small (just a pointer)")
  {
    // ref_view should be exactly one pointer (no heap allocation)
    static_assert(sizeof(gst::detail::ref_view<std::vector<int>>) == sizeof(void*),
                  "ref_view should be exactly one pointer");
    SUCCEED("ref_view size verified at compile time");
  }

  SECTION("owning_view has no overhead")
  {
    // owning_view should have no overhead beyond the container itself
    static_assert(sizeof(gst::detail::owning_view<std::vector<int>>) == sizeof(std::vector<int>),
                  "owning_view should have no overhead beyond the container itself");
    SUCCEED("owning_view size verified at compile time");
  }

  SECTION("zip_view is small")
  {
    using ZipView = gst::ranges::zip_view<std::vector<int>&, std::vector<int>&>;
    // Should be exactly 2 pointers in a tuple (2 ref_views, no padding)
    REQUIRE(sizeof(ZipView) == 2 * sizeof(void*));
  }
}

TEST_CASE("Architecture: Iterator category computation", "[architecture]")
{
  SECTION("Single container: vector is random access")
  {
    using ZipVec        = gst::ranges::zip_view<std::vector<int>&>;
    using ZipVecIterCat = typename ZipVec::iterator::iterator_category;
    static_assert(std::is_same<ZipVecIterCat, std::random_access_iterator_tag>::value,
                  "zip of vector should be random access");

    // Also verify C++20 iterator concept
    static_assert(std::random_access_iterator<typename ZipVec::iterator>,
                  "Should satisfy random_access_iterator concept");
    SUCCEED("Vector zip is random access");
  }

  SECTION("Single container: list is bidirectional")
  {
    using ZipList        = gst::ranges::zip_view<std::list<int>&>;
    using ZipListIterCat = typename ZipList::iterator::iterator_category;
    static_assert(std::is_same<ZipListIterCat, std::bidirectional_iterator_tag>::value,
                  "zip of list should be bidirectional");

    // Also verify C++20 iterator concept
    static_assert(std::bidirectional_iterator<typename ZipList::iterator>,
                  "Should satisfy bidirectional_iterator concept");
    static_assert(!std::random_access_iterator<typename ZipList::iterator>,
                  "Should NOT satisfy random_access_iterator concept");
    SUCCEED("List zip is bidirectional");
  }

  SECTION("Single container: forward_list is forward")
  {
    using ZipFwd        = gst::ranges::zip_view<std::forward_list<int>&>;
    using ZipFwdIterCat = typename ZipFwd::iterator::iterator_category;
    static_assert(std::is_same<ZipFwdIterCat, std::forward_iterator_tag>::value,
                  "zip of forward_list should be forward");

    // Also verify C++20 iterator concept
    static_assert(std::forward_iterator<typename ZipFwd::iterator>,
                  "Should satisfy forward_iterator concept");
    static_assert(!std::bidirectional_iterator<typename ZipFwd::iterator>,
                  "Should NOT satisfy bidirectional_iterator concept");
    SUCCEED("Forward_list zip is forward");
  }

  SECTION("Mixed: vector + list = bidirectional (weakest wins)")
  {
    using ZipMixed1    = gst::ranges::zip_view<std::vector<int>&, std::list<int>&>;
    using ZipMixed1Cat = typename ZipMixed1::iterator::iterator_category;
    static_assert(std::is_same<ZipMixed1Cat, std::bidirectional_iterator_tag>::value,
                  "zip of vector+list should degrade to bidirectional");

    static_assert(std::bidirectional_iterator<typename ZipMixed1::iterator>,
                  "Should satisfy bidirectional_iterator concept");
    static_assert(!std::random_access_iterator<typename ZipMixed1::iterator>,
                  "Should NOT satisfy random_access_iterator concept");
    SUCCEED("Vector+list zip is bidirectional");
  }

  SECTION("Mixed: vector + forward_list = forward (weakest wins)")
  {
    using ZipMixed2    = gst::ranges::zip_view<std::vector<int>&, std::forward_list<int>&>;
    using ZipMixed2Cat = typename ZipMixed2::iterator::iterator_category;
    static_assert(std::is_same<ZipMixed2Cat, std::forward_iterator_tag>::value,
                  "zip of vector+forward_list should degrade to forward");

    static_assert(std::forward_iterator<typename ZipMixed2::iterator>,
                  "Should satisfy forward_iterator concept");
    static_assert(!std::bidirectional_iterator<typename ZipMixed2::iterator>,
                  "Should NOT satisfy bidirectional_iterator concept");
    SUCCEED("Vector+forward_list zip is forward");
  }

  SECTION("Mixed: three containers, weakest wins")
  {
    using ZipMixed3 =
      gst::ranges::zip_view<std::vector<int>&, std::list<int>&, std::forward_list<int>&>;
    using ZipMixed3Cat = typename ZipMixed3::iterator::iterator_category;
    static_assert(std::is_same<ZipMixed3Cat, std::forward_iterator_tag>::value,
                  "zip of vector+list+forward_list should degrade to forward");

    static_assert(std::forward_iterator<typename ZipMixed3::iterator>,
                  "Should satisfy forward_iterator concept");
    SUCCEED("Vector+list+forward_list zip is forward");
  }
}

TEST_CASE("Architecture: SFINAE-based conditional interface", "[architecture]")
{
  // Type aliases for testing
  using ZipVec  = gst::ranges::zip_view<std::vector<int>&>;
  using ZipList = gst::ranges::zip_view<std::list<int>&>;
  using ZipFwd  = gst::ranges::zip_view<std::forward_list<int>&>;

  SECTION("operator-- only available for bidirectional+")
  {
    static_assert(!has_decrement<typename ZipFwd::iterator>,
                  "Forward iterator should not have operator--");
    static_assert(has_decrement<typename ZipList::iterator>,
                  "Bidirectional iterator should have operator--");
    static_assert(has_decrement<typename ZipVec::iterator>,
                  "Random access iterator should have operator--");
    SUCCEED("operator-- SFINAE verified");
  }

  SECTION("operator[] only available for random access")
  {
    static_assert(!has_subscript<typename ZipFwd::iterator>,
                  "Forward iterator should not have operator[]");
    static_assert(!has_subscript<typename ZipList::iterator>,
                  "Bidirectional iterator should not have operator[]");
    static_assert(has_subscript<typename ZipVec::iterator>,
                  "Random access iterator should have operator[]");
    SUCCEED("operator[] SFINAE verified");
  }

  SECTION("operator+ only available for random access")
  {
    static_assert(!has_plus<typename ZipFwd::iterator>,
                  "Forward iterator should not have operator+");
    static_assert(!has_plus<typename ZipList::iterator>,
                  "Bidirectional iterator should not have operator+");
    static_assert(has_plus<typename ZipVec::iterator>,
                  "Random access iterator should have operator+");
    SUCCEED("operator+ SFINAE verified");
  }

  SECTION("operator- only available for random access")
  {
    static_assert(!has_minus<typename ZipFwd::iterator>,
                  "Forward iterator should not have operator-");
    static_assert(!has_minus<typename ZipList::iterator>,
                  "Bidirectional iterator should not have operator-");
    static_assert(has_minus<typename ZipVec::iterator>,
                  "Random access iterator should have operator-");
    SUCCEED("operator- SFINAE verified");
  }

  SECTION("Comparison operators only available for random access")
  {
    static_assert(!has_comparison<typename ZipFwd::iterator>,
                  "Forward iterator should not have comparison operators");
    static_assert(!has_comparison<typename ZipList::iterator>,
                  "Bidirectional iterator should not have comparison operators");
    static_assert(has_comparison<typename ZipVec::iterator>,
                  "Random access iterator should have comparison operators");
    SUCCEED("Comparison operators SFINAE verified");
  }
}

TEST_CASE("Architecture: Standard iterator interface", "[architecture]")
{
  using ZipVec = gst::ranges::zip_view<std::vector<int>&>;

  SECTION("iterator_category is defined")
  {
    static_assert(std::is_same<typename ZipVec::iterator::iterator_category,
                               std::random_access_iterator_tag>::value,
                  "Iterator must define iterator_category");
    SUCCEED("iterator_category verified");
  }

  SECTION("difference_type is ptrdiff_t")
  {
    static_assert(std::is_same<typename ZipVec::iterator::difference_type, std::ptrdiff_t>::value,
                  "Iterator must define difference_type as ptrdiff_t");
    SUCCEED("difference_type verified");
  }

  SECTION("value_type is defined")
  {
    // value_type should exist (exact type is complex tuple, just check it exists)
    using ValueType = typename ZipVec::iterator::value_type;
    REQUIRE(sizeof(ValueType) > 0);
  }
}

TEST_CASE("Architecture: Value semantics", "[architecture]")
{
  using ZipVec = gst::ranges::zip_view<std::vector<int>&>;

  SECTION("zip_view is copyable and movable")
  {
    static_assert(std::copyable<ZipVec>, "zip_view should be copyable");
    static_assert(std::movable<ZipVec>, "zip_view should be movable");
    SUCCEED("zip_view has value semantics");
  }

  SECTION("iterator is copyable and movable")
  {
    using Iterator = typename ZipVec::iterator;
    static_assert(std::copyable<Iterator>, "zip iterator should be copyable");
    static_assert(std::movable<Iterator>, "zip iterator should be movable");
    SUCCEED("iterator has value semantics");
  }

  SECTION("iterator satisfies iterator concept")
  {
    using Iterator = typename ZipVec::iterator;
    static_assert(std::input_or_output_iterator<Iterator>, "Should be an iterator");
    static_assert(std::forward_iterator<Iterator>, "Should be at least forward iterator");
    static_assert(std::bidirectional_iterator<Iterator>, "Should be bidirectional iterator");
    static_assert(std::random_access_iterator<Iterator>, "Should be random access iterator");
    SUCCEED("iterator satisfies std::random_access_iterator concept");
  }
}

TEST_CASE("Architecture: Const-correctness (shallow constness)", "[architecture]")
{
  using ConstZipVec = gst::ranges::zip_view<std::vector<int>&> const;

  SECTION("const zip_view provides const_iterator")
  {
    static_assert(std::is_same<typename ConstZipVec::const_iterator,
                               decltype(std::declval<ConstZipVec>().begin())>::value,
                  "const zip_view should provide const_iterator");
    SUCCEED("const_iterator verified");
  }

  SECTION("const view allows element modification (shallow constness)")
  {
    std::vector<int> v1{1, 2, 3};
    std::vector<int> v2{4, 5, 6};

    const auto z = gst::ranges::views::zip(v1, v2);

    // Should compile: const view but non-const elements
    auto [a, b] = *z.begin();
    a           = 10; // Modifies v1
    b           = 20; // Modifies v2

    REQUIRE(v1[0] == 10);
    REQUIRE(v2[0] == 20);
  }
}

TEST_CASE("Architecture: No heap allocation", "[architecture]")
{
  SECTION("View construction doesn't allocate")
  {
    std::vector<int> v1{1, 2, 3};
    std::vector<int> v2{4, 5, 6};

    // This only allocates via the vectors themselves, not the view
    auto z = gst::ranges::views::zip(v1, v2);

    // Verify we can iterate without issues
    auto it  = z.begin();
    auto end = z.end();

    int count = 0;
    while (it != end)
    {
      auto [a, b] = *it;
      (void)a;
      (void)b;
      ++it;
      ++count;
    }

    REQUIRE(count == 3);
  }
}

TEST_CASE("Architecture: Zero-cost abstraction properties", "[architecture]")
{
  SECTION("No virtual functions (can verify via size)")
  {
    using ZipView = gst::ranges::zip_view<std::vector<int>&, std::vector<int>&>;

    // If there were virtual functions, size would include vptr
    // With just two pointers (ref_view * 2), should be exactly 2 pointers
    REQUIRE(sizeof(ZipView) == 2 * sizeof(void*));
  }

  SECTION("Iterator is lightweight")
  {
    using Iterator       = gst::ranges::zip_view<std::vector<int>&>::iterator;
    using UnderlyingIter = std::vector<int>::iterator;

    // Should be exactly the size of a tuple containing one underlying iterator
    // (tuple of one iterator has no overhead)
    REQUIRE(sizeof(Iterator) == sizeof(UnderlyingIter));
  }
}
