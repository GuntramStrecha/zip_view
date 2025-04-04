#include "zip_view.hpp"

#include <array>
#include <cstddef>
#include <deque>
#include <forward_list>
#include <initializer_list>
#include <iostream>
#include <list>
#include <string>
#include <tuple>
#include <vector>

template <typename Tuple, std::size_t... Is>
void print_tuple_impl(Tuple const& tuple, gst::detail::index_sequence<Is...>)
{
  static_cast<void>(std::initializer_list<int>{(std::cout << std::get<Is>(tuple) << ' ', 0)...});
  std::cout << '\n';
}

// Main function to print the tuple
template <typename... Args>
void print_tuple(std::tuple<Args...> const& tuple)
{
  print_tuple_impl(tuple, gst::detail::make_index_sequence<sizeof...(Args)>{});
}

int main()
{
  std::array<int, 3>       a_3 = {1, 2, 3};
  std::list<double>        l_5 = {1.1, 2.2, 3.3, 4.4, 5.5};
  std::deque<bool>         d_7 = {true, false, true, false, true, false, true};
  std::forward_list<char>  f_6 = {'a', 'b', 'c', 'd', 'e', 'f'};
  std::vector<std::string> v_4 = {"one", "two", "three", "four"};

  for (auto const iter_tuple : gst::ranges::views::zip(a_3, l_5, d_7, f_6, v_4))
  {
    print_tuple(iter_tuple);
  }
}
