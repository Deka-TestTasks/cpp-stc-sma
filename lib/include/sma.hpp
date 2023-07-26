#include <algorithm>
#include <cassert>
#include <queue>
#include <type_traits>
#include <vector>

template <typename T> std::vector<T> sma(const std::vector<T> &in, int k) {
  static_assert(std::is_floating_point<T>::value);
  assert(0 < k);

  std::vector<T> out;
  out.resize(in.size());

  std::queue<T> queue;
  T med = T(0.0);
  // K as floating point divider so we can easily use it in expressions
  T k_div = T(k);

  // We will use iterators for faster access
  auto it_in = in.begin();
  auto it_out = out.begin();

  // While read element count is less than our window k use cumulative avg
  auto limit_for_first_k_elements = std::min<int>(k, in.size());
  for (int i = 0; i < limit_for_first_k_elements; i++) {
    med += *it_in;
    *it_out = med / (i + 1);
    queue.push(*it_in);

    it_in++;
    it_out++;
  }

  med /= k_div;

  // Remaining elements(if any) works with filled window
  for (; it_in != in.end(); it_in++, it_out++) {
    auto element_out_of_window = queue.front();
    queue.pop();
    queue.push(*it_in);

    med = med + *it_in / k_div - element_out_of_window / k_div;
    *it_out = med;
  }

  return out;
}
