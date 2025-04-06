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
#include <iostream>
#include <iterator>
#include <list>
#include <set>
#include <tuple>
#include <vector>

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
} // namespace detail

namespace ranges
{
template <typename... Containers>
class zip_view
{
private:
  std::tuple<Containers&...> containers_;

  static constexpr auto INDICES = detail::make_index_sequence<sizeof...(Containers)>{};
  using iterators               = std::tuple<decltype(std::begin(std::declval<Containers&>()))...>;
  using references              = std::tuple<decltype(*std::begin(std::declval<Containers&>()))...>;

  template <std::size_t... Is>
  auto min_size(detail::index_sequence<Is...>) const -> std::ptrdiff_t
  {
    return std::min({std::distance(std::get<Is>(containers_).begin(), std::get<Is>(containers_).end())...});
  }

  template <std::size_t... Is>
  auto begin_impl(detail::index_sequence<Is...>) const -> iterators
  {
    return std::make_tuple(std::begin(std::get<Is>(containers_))...);
  }

  template <std::size_t... Is>
  auto end_impl(detail::index_sequence<Is...> is) const -> iterators
  {
    return std::make_tuple(std::next(std::begin(std::get<Is>(containers_)), min_size(is))...);
  }

  template <std::size_t... Is>
  auto subscripts(std::ptrdiff_t const index, detail::index_sequence<Is...>) -> references
  {
    return std::tie(*std::next(std::begin(std::get<Is>(containers_)), index)...);
  }

  template <std::size_t... Is>
  auto subscripts(std::ptrdiff_t const index, detail::index_sequence<Is...>) const -> references
  {
    return std::tie(*std::next(std::begin(std::get<Is>(containers_)), index)...);
  }

public:
  class iterator
  {
  private:
    iterators iters_;

    template <std::size_t... Is>
    auto increment(detail::index_sequence<Is...>) -> void
    {
      static_cast<void>(std::initializer_list<int>{(std::advance(std::get<Is>(iters_), 1), 0)...});
    }

    template <std::size_t... Is>
    auto dereference(detail::index_sequence<Is...>) -> references
    {
      return std::tie(*std::get<Is>(iters_)...);
    }

  public:
    typedef std::forward_iterator_tag iterator_category;
    typedef references                value_type;
    typedef std::ptrdiff_t            difference_type;
    typedef value_type*               pointer;
    typedef value_type&               reference;

    iterator(iterators iters) : iters_(iters) {}

    auto operator++() -> iterator&
    {
      increment(INDICES);
      return *this;
    }

    references operator*() { return dereference(INDICES); }

    auto operator==(iterator const& other) const -> bool { return iters_ == other.iters_; }
    auto operator!=(iterator const& other) const -> bool { return !(*this == other); }
  };

  zip_view(Containers&... containers) : containers_(containers...) {}
  zip_view(Containers&&... containers) : containers_(std::tie(containers...)) {}
  zip_view() = default;
  zip_view(zip_view const& other) : containers_(other.containers_) {}
  zip_view(zip_view&& other) noexcept : containers_(std::move(other.containers_)) {}
  ~zip_view() = default;

  zip_view& operator=(zip_view const& other)
  {
    if (this != &other) { containers_ = other.containers_; }
    return *this;
  }
  zip_view& operator=(zip_view&& other) noexcept
  {
    if (this != &other) { containers_ = std::move(other.containers_); }
    return *this;
  }
  operator bool() const { return !empty(); }
  auto operator[](std::ptrdiff_t const idx) const -> references { return subscripts(idx, INDICES); }
  auto operator[](std::ptrdiff_t const idx) -> references { return subscripts(idx, INDICES); }

  auto           begin() const -> iterator { return iterator(begin_impl(INDICES)); }
  auto           begin() -> iterator { return iterator(begin_impl(INDICES)); }
  auto           end() const -> iterator { return iterator(end_impl(INDICES)); }
  auto           end() -> iterator { return iterator(end_impl(INDICES)); }
  constexpr auto size() const -> std::ptrdiff_t { return min_size(INDICES); }
  constexpr auto empty() const -> bool { return size() == 0; }
  auto           front() const -> references { return subscripts(0, INDICES); }
  auto           front() -> references { return subscripts(0, INDICES); }
  auto           back() const -> references { return subscripts(size() - 1U, INDICES); }
  auto           back() -> references { return subscripts(size() - 1U, INDICES); }
};

#if __cplusplus >= 201703L
template <typename... Containers>
explicit zip_view(Containers&... containers) -> zip_view<Containers...>;

template <typename... Containers>
explicit zip_view(Containers&&... containers) -> zip_view<Containers...>;
#endif

namespace views
{
template <typename... Containers>
auto zip(Containers&... containers) -> zip_view<Containers...>
{
  return zip_view<Containers...>(containers...);
}

template <typename... Containers>
auto zip(Containers&&... containers) -> zip_view<Containers...>
{
  return zip_view<Containers...>(std::forward<Containers>(containers)...);
}

} // namespace views
} // namespace ranges
} // namespace gst
