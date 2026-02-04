// This is free and unencumbered software released into the public domain.
//
// Anyone is free to copy, modify, publish, use, compile, sell, or
// distribute this software, either in source code form or as a compiled
// binary, for any purpose, commercial or non-commercial, and by any
// means.
//
// In jurisdictions that recognize copyright laws, the author or authors
// of this software dedicate any and all copyright interest in the
// software to the public domain. We make this dedication for the benefit
// of the public at large and to the detriment of our heirs and
// successors. We intend this dedication to be an overt act of
// relinquishment in perpetuity of all present and future rights to this
// software under copyright law.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
// IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
// OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
// OTHER DEALINGS IN THE SOFTWARE.
//
// For more information, please refer to <https://unlicense.org>

#pragma once

#include <algorithm>
#include <cstddef>
#include <iterator>
#include <tuple>
#include <type_traits>
#include <utility>

namespace gst
{
namespace detail
{
template <std::size_t... Is>
struct index_sequence
{};

template <std::size_t N, std::size_t... Is>
struct make_index_sequence : make_index_sequence<N - 1, N - 1, Is...>
{};

template <std::size_t... Is>
struct make_index_sequence<0, Is...> : index_sequence<Is...>
{};

template <typename Category, typename Target>
struct is_at_least_category
{
  static constexpr bool value = std::is_convertible<Category, Target>::value;
};
template <typename Category>
struct is_at_least_bidirectional : is_at_least_category<Category, std::bidirectional_iterator_tag>
{};
template <typename Category>
struct is_at_least_random_access : is_at_least_category<Category, std::random_access_iterator_tag>
{};

template <typename... Iters>
struct zip_iterator_category_impl;
template <typename Iter>
struct zip_iterator_category_impl<Iter>
{
  using type = typename std::iterator_traits<Iter>::iterator_category;
};
template <typename Iter, typename... Rest>
struct zip_iterator_category_impl<Iter, Rest...>
{
private:
  using iter_category = typename std::iterator_traits<Iter>::iterator_category;
  using rest_category = typename zip_iterator_category_impl<Rest...>::type;

  static constexpr bool iter_is_random_access = is_at_least_random_access<iter_category>::value;
  static constexpr bool rest_is_random_access = is_at_least_random_access<rest_category>::value;
  static constexpr bool iter_is_bidirectional = is_at_least_bidirectional<iter_category>::value;
  static constexpr bool rest_is_bidirectional = is_at_least_bidirectional<rest_category>::value;

public:
  using type = typename std::conditional<
    iter_is_random_access && rest_is_random_access,
    std::random_access_iterator_tag,
    typename std::conditional<iter_is_bidirectional && rest_is_bidirectional,
                              std::bidirectional_iterator_tag,
                              std::forward_iterator_tag>::type>::type;
};

template <typename... Iters>
using zip_iterator_category = typename zip_iterator_category_impl<Iters...>::type;

template <typename Container>
class ref_view
{
private:
  Container* container_;

public:
  ref_view() : container_(nullptr) {}
  explicit ref_view(Container& c) : container_(&c) {}

  ref_view(ref_view const&)     = default;
  ref_view(ref_view&&) noexcept = default;

  // Assignment rebinds the reference (matches std::ranges::ref_view)
  ref_view& operator=(ref_view const& other)
  {
    container_ = other.container_;
    return *this;
  }
  ref_view& operator=(ref_view&& other) noexcept
  {
    container_ = other.container_;
    return *this;
  }

  Container&       get() { return *container_; }
  Container const& get() const { return *container_; }

  auto begin() -> decltype(std::begin(*container_)) { return std::begin(*container_); }
  auto end() -> decltype(std::end(*container_)) { return std::end(*container_); }
  auto begin() const -> decltype(std::begin(*container_)) { return std::begin(*container_); }
  auto end() const -> decltype(std::end(*container_)) { return std::end(*container_); }
};

template <typename Container>
class owning_view
{
private:
  Container container_;

public:
  owning_view() : container_() {}
  explicit owning_view(Container&& c) : container_(std::move(c)) {}

  owning_view(owning_view const& other) : container_(other.container_) {}
  owning_view(owning_view&& other) noexcept : container_(std::move(other.container_)) {}

  // Assignment replaces the owned container
  owning_view& operator=(owning_view const& other)
  {
    container_ = other.container_;
    return *this;
  }
  owning_view& operator=(owning_view&& other) noexcept
  {
    container_ = std::move(other.container_);
    return *this;
  }

  Container&       get() { return container_; }
  Container const& get() const { return container_; }

  auto begin() -> decltype(std::begin(container_)) { return std::begin(container_); }
  auto end() -> decltype(std::end(container_)) { return std::end(container_); }
  auto begin() const -> decltype(std::begin(container_)) { return std::begin(container_); }
  auto end() const -> decltype(std::end(container_)) { return std::end(container_); }
};

template <typename T>
struct view_type
{
  using type = typename std::conditional<std::is_lvalue_reference<T>::value,
                                         ref_view<typename std::remove_reference<T>::type>,
                                         owning_view<typename std::decay<T>::type>>::type;
};

template <typename T>
using view_t = typename view_type<T>::type;
} // namespace detail

namespace ranges
{
// zip_view provides a view over multiple ranges, iterating over them in lockstep.
//
// Important performance note:
// For non-random-access iterators (bidirectional, forward), size() and end() are O(n)
// because they must traverse each range to compute the minimum size. In range-based
// for loops, end() is called repeatedly, resulting in O(n²) complexity. To avoid this,
// cache the end iterator: for (auto it = z.begin(), e = z.end(); it != e; ++it)
//
// Const-correctness note:
// This view provides shallow constness, matching std::ranges::zip_view behavior.
// A const zip_view can still modify elements if the underlying containers are non-const,
// because references to elements are preserved. The constness applies to the view
// structure itself (cannot rebind containers), not to the referenced elements.
template <typename... Containers>
class zip_view
{
private:
  static constexpr auto INDICES = detail::make_index_sequence<sizeof...(Containers)>{};

  using storage_tuple = std::tuple<detail::view_t<Containers>...>;

  template <typename T>
  using view_ref = detail::view_t<T>&;
  template <typename T>
  using view_const_ref = detail::view_t<T> const&;

  template <typename T>
  using iter_t = decltype(std::declval<view_ref<T>>().begin());
  template <typename T>
  using const_iter_t = decltype(std::declval<view_const_ref<T>>().begin());

  using iterators_mut   = std::tuple<iter_t<Containers>...>;
  using iterators_const = std::tuple<const_iter_t<Containers>...>;

  storage_tuple views_;

  using references       = std::tuple<decltype(*std::declval<iter_t<Containers>>())...>;
  using const_references = std::tuple<decltype(*std::declval<const_iter_t<Containers>>())...>;

  using values = std::tuple<
    typename std::remove_reference<decltype(*std::declval<iter_t<Containers>>())>::type...>;

  template <std::size_t... Is>
  auto min_size(detail::index_sequence<Is...>) const -> std::size_t
  {
    return static_cast<std::size_t>(
      std::min({std::distance(std::get<Is>(views_).begin(), std::get<Is>(views_).end())...}));
  }

  template <std::size_t... Is>
  auto begin_impl(detail::index_sequence<Is...>) -> iterators_mut
  {
    return std::make_tuple(std::get<Is>(views_).begin()...);
  }

  template <std::size_t... Is>
  auto begin_impl(detail::index_sequence<Is...>) const -> iterators_const
  {
    return std::make_tuple(std::get<Is>(views_).begin()...);
  }

  template <std::size_t... Is>
  auto end_impl(detail::index_sequence<Is...> is) -> iterators_mut
  {
    return std::make_tuple(
      std::next(std::get<Is>(views_).begin(), static_cast<std::ptrdiff_t>(min_size(is)))...);
  }

  template <std::size_t... Is>
  auto end_impl(detail::index_sequence<Is...> is) const -> iterators_const
  {
    return std::make_tuple(
      std::next(std::get<Is>(views_).begin(), static_cast<std::ptrdiff_t>(min_size(is)))...);
  }

  template <std::size_t... Is>
  auto subscripts(std::ptrdiff_t const index, detail::index_sequence<Is...>) -> references
  {
    return references(*std::next(std::get<Is>(views_).begin(), index)...);
  }

  template <std::size_t... Is>
  auto subscripts(std::ptrdiff_t const index,
                  detail::index_sequence<Is...>) const -> const_references
  {
    return const_references(*std::next(std::get<Is>(views_).begin(), index)...);
  }

public:
  template <typename IterTuple>
  class basic_iterator
  {
  public:
    using iter_category     = detail::zip_iterator_category<iter_t<Containers>...>;
    using iterator_category = iter_category;
    using value_type        = values;
    using size_type         = std::size_t;
    using difference_type   = std::ptrdiff_t;
    using pointer           = value_type*;

  private:
    IterTuple iters_;

    static constexpr bool is_bidirectional =
      detail::is_at_least_bidirectional<iter_category>::value;
    static constexpr bool is_random_access =
      detail::is_at_least_random_access<iter_category>::value;

    template <std::size_t... Is>
    auto increment(detail::index_sequence<Is...>) -> void
    {
      static_cast<void>(std::initializer_list<int>{(std::advance(std::get<Is>(iters_), 1), 0)...});
    }

    template <std::size_t... Is>
    auto decrement(detail::index_sequence<Is...>) -> void
    {
      static_cast<void>(std::initializer_list<int>{(std::advance(std::get<Is>(iters_), -1), 0)...});
    }

    template <std::size_t... Is>
    auto advance_by(difference_type const n, detail::index_sequence<Is...>) -> void
    {
      static_cast<void>(std::initializer_list<int>{(std::advance(std::get<Is>(iters_), n), 0)...});
    }

    template <std::size_t... Is>
    using deref_tuple =
      std::tuple<decltype(*std::declval<typename std::tuple_element<Is, IterTuple>::type&>())...>;

    template <std::size_t... Is>
    static auto reference_for(detail::index_sequence<Is...>) -> deref_tuple<Is...>;

  private:
    template <std::size_t... Is>
    auto dereference(detail::index_sequence<Is...>) -> deref_tuple<Is...>
    {
      return deref_tuple<Is...>(*std::get<Is>(iters_)...);
    }

    template <std::size_t... Is>
    auto dereference(detail::index_sequence<Is...>) const -> deref_tuple<Is...>
    {
      return deref_tuple<Is...>(*std::get<Is>(iters_)...);
    }

  public:
    using reference =
      decltype(reference_for(detail::make_index_sequence<std::tuple_size<IterTuple>::value>{}));

    basic_iterator() = default;
    explicit basic_iterator(IterTuple iters) : iters_(std::move(iters)) {}

    auto operator++() -> basic_iterator&
    {
      increment(INDICES);
      return *this;
    }

    auto operator++(int) -> basic_iterator
    {
      basic_iterator tmp = *this;
      increment(INDICES);
      return tmp;
    }

    auto operator*() -> reference { return dereference(INDICES); }
    auto operator*() const -> reference { return dereference(INDICES); }

    auto operator==(basic_iterator const& other) const noexcept -> bool
    {
      return iters_ == other.iters_;
    }
    auto operator!=(basic_iterator const& other) const noexcept -> bool
    {
      return !(*this == other);
    }

    template <bool B = is_bidirectional, typename std::enable_if<B, int>::type = 0>
    auto operator--() -> basic_iterator&
    {
      decrement(INDICES);
      return *this;
    }

    template <bool B = is_bidirectional, typename std::enable_if<B, int>::type = 0>
    auto operator--(int) -> basic_iterator
    {
      basic_iterator tmp = *this;
      decrement(INDICES);
      return tmp;
    }

    template <bool B = is_random_access, typename std::enable_if<B, int>::type = 0>
    auto operator+=(difference_type const n) -> basic_iterator&
    {
      advance_by(n, INDICES);
      return *this;
    }

    template <bool B = is_random_access, typename std::enable_if<B, int>::type = 0>
    auto operator-=(difference_type const n) -> basic_iterator&
    {
      advance_by(-n, INDICES);
      return *this;
    }

    template <bool B = is_random_access, typename std::enable_if<B, int>::type = 0>
    auto operator+(difference_type const n) const -> basic_iterator
    {
      basic_iterator tmp  = *this;
      tmp                += n;
      return tmp;
    }

    template <bool B = is_random_access, typename std::enable_if<B, int>::type = 0>
    auto operator-(difference_type const n) const -> basic_iterator
    {
      basic_iterator tmp  = *this;
      tmp                -= n;
      return tmp;
    }

    template <bool B = is_random_access, typename std::enable_if<B, int>::type = 0>
    auto operator-(basic_iterator const& other) const -> difference_type
    {
      return std::distance(std::get<0>(other.iters_), std::get<0>(iters_));
    }

    template <bool B = is_random_access, typename std::enable_if<B, int>::type = 0>
    auto operator[](difference_type const n) const -> reference
    {
      basic_iterator tmp  = *this;
      tmp                += n;
      return *tmp;
    }

    template <bool B = is_random_access, typename std::enable_if<B, int>::type = 0>
    auto operator<(basic_iterator const& other) const noexcept -> bool
    {
      return std::get<0>(iters_) < std::get<0>(other.iters_);
    }

    template <bool B = is_random_access, typename std::enable_if<B, int>::type = 0>
    auto operator>(basic_iterator const& other) const noexcept -> bool
    {
      return other < *this;
    }

    template <bool B = is_random_access, typename std::enable_if<B, int>::type = 0>
    auto operator<=(basic_iterator const& other) const noexcept -> bool
    {
      return !(other < *this);
    }

    template <bool B = is_random_access, typename std::enable_if<B, int>::type = 0>
    auto operator>=(basic_iterator const& other) const noexcept -> bool
    {
      return !(*this < other);
    }

    // Friend function for n + iterator
    template <bool B = is_random_access, typename std::enable_if<B, int>::type = 0>
    friend auto operator+(difference_type const n, basic_iterator const& it) -> basic_iterator
    {
      return it + n;
    }

    // Custom iter_swap for proper swapping of zipped elements
    friend auto iter_swap(basic_iterator const& lhs, basic_iterator const& rhs) -> void
    {
      iter_swap_impl(lhs, rhs, INDICES);
    }

  private:
    template <std::size_t... Is>
    static auto iter_swap_impl(basic_iterator const& lhs,
                               basic_iterator const& rhs,
                               detail::index_sequence<Is...>) -> void
    {
      using std::swap;
      static_cast<void>(std::initializer_list<int>{
        (swap(*std::get<Is>(lhs.iters_), *std::get<Is>(rhs.iters_)), 0)...});
    }
  };

  using iterator       = basic_iterator<iterators_mut>;
  using const_iterator = basic_iterator<iterators_const>;

  template <typename... Cs,
            typename std::enable_if<sizeof...(Cs) == sizeof...(Containers), int>::type = 0>
  explicit zip_view(Cs&&... containers)
    : views_(detail::view_t<Cs>(std::forward<Cs>(containers))...)
  {}

  zip_view(zip_view const& other) : views_(other.views_) {}
  zip_view(zip_view&& other) noexcept : views_(std::move(other.views_)) {}
  ~zip_view() = default;

  zip_view& operator=(zip_view const& other)
  {
    views_ = other.views_;
    return *this;
  }
  zip_view& operator=(zip_view&& other) noexcept
  {
    views_ = std::move(other.views_);
    return *this;
  }
  explicit operator bool() const noexcept { return !empty(); }
  auto     operator[](typename iterator::difference_type const idx) const -> const_references
  {
    return subscripts(idx, INDICES);
  }
  auto operator[](typename iterator::difference_type const idx) -> references
  {
    return subscripts(idx, INDICES);
  }

  auto           begin() const -> const_iterator { return const_iterator(begin_impl(INDICES)); }
  auto           begin() -> iterator { return iterator(begin_impl(INDICES)); }
  auto           end() const -> const_iterator { return const_iterator(end_impl(INDICES)); }
  auto           end() -> iterator { return iterator(end_impl(INDICES)); }
  constexpr auto size() const -> std::size_t { return min_size(INDICES); }
  constexpr auto empty() const noexcept -> bool { return size() == 0; }

  auto front() const -> const_references { return subscripts(0, INDICES); }
  auto front() -> references { return subscripts(0, INDICES); }

  auto back() const -> const_references
  {
    return subscripts(static_cast<typename iterator::difference_type>(size() - 1), INDICES);
  }
  auto back() -> references
  {
    return subscripts(static_cast<typename iterator::difference_type>(size() - 1), INDICES);
  }
};

namespace views
{
template <typename... Containers>
auto zip(Containers&&... containers) -> zip_view<Containers&&...>
{
  return zip_view<Containers&&...>(std::forward<Containers>(containers)...);
}

} // namespace views
} // namespace ranges
} // namespace gst
