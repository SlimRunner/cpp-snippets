#include <chrono>
#include <iostream>

#include "profiler.hpp"

int foobar(int a, bool b) { return b ? a : -a; }

int foo() { return 42; }

int main(int argc, char const *argv[]) {
  std::cout << timeIt<0x1000000>(foo) << "\n";
  std::cout << timeIt<0x1000000>(foobar, 5, false) << "\n";

  return 0;
}
