#include <cstddef> // size_t
#include <iomanip>
#include <iostream>
#include <chrono>

int main(int argc, char const *argv[]) {
  using steady = std::chrono::steady_clock;
  using chrono_us = std::chrono::milliseconds;

  auto start = steady::now();

  size_t i = 0, count = 0, printLimit = 1;
  while (count <= 1) {
    if (i >= printLimit) {
      auto stamp = std::chrono::duration_cast<chrono_us>(steady::now() - start).count();
      std::cout << std::setw(7) << stamp << std::setw(21) << i << '\n';
      printLimit <<= 1;
    }
    ++i;
    if (i == 0) {
      ++count;
    }
  }
  return 0;
}
