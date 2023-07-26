#include <algorithm>
#include <cassert>
#include <chrono>
#include <fstream>
#include <iostream>
#include <random>
#include <type_traits>
#include <vector>

#include <sma.hpp>

const int DATA_SIZE = 1'000'000;
const float MIN_RANDOM_VALUE = -1000.0f;
const float MAX_RANDOM_VALUE = 1000.0f;

template <typename T> std::vector<T> generate(int size) {
  static_assert(std::is_floating_point<T>::value,
                "cannot generate array for non floating points");
  assert(size > 0);

  std::vector<T> out(size, 0);

  std::random_device rd;
  std::default_random_engine re(rd());
  std::uniform_real_distribution<T> dist(MIN_RANDOM_VALUE, MAX_RANDOM_VALUE);

  std::generate(out.begin(), out.end(),
                [re, dist]() mutable { return dist(re); });

  return out;
}

template <typename T>
double benchmark_single(const std::vector<T> &data, int k) {
  int n = data.size();

  auto start = std::chrono::high_resolution_clock::now();
  sma(data, k);
  auto end = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double> duration = end - start;
  return double(n) / duration.count();
};

int main(int argc, char **argv) {
  auto double_vec = generate<double>(DATA_SIZE);
  auto float_vec = generate<float>(DATA_SIZE);

  const std::vector<int> windows = {4, 8, 16, 32, 64, 128};

  std::ofstream file;
  try {
    file.open("out.csv", std::ios::out | std::ios::trunc);

    file << "window,float,double" << std::endl;

    for (auto k : windows) {
      auto double_res = benchmark_single(double_vec, k);
      auto float_res = benchmark_single(float_vec, k);

      file << std::fixed << k << "," << float_res << "," << double_res
           << std::endl;
    }

  } catch (const std::exception &ex) {
    std::cerr << ex.what() << std::endl;
  }

  return 0;
};
