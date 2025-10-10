#include <chrono>
#include <iostream>

#include "profiler.hpp"

int foobar(int a, bool b) { return b ? a : -a; }

int foo() { return 42; }

int main(int argc, char const *argv[]) {
  using chrono_us = std::chrono::milliseconds;
  constexpr auto to_ms = [](auto x) {
    return std::chrono::duration_cast<chrono_us>(x).count();
  };

  std::cout << to_ms(timeIt<0x200000>(foo)) << "\n";
  std::cout << to_ms(timeIt<0x200000>(foobar, 5, false)) << "\n";

  return 0;
}
