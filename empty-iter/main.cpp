#include <cstdint>
#include <string>
int main(int argc, char const **argv) {
  uint64_t max;
  max = (argc<=1?UINT64_MAX:std::stoll(argv[1]));
  for (uint64_t i = 0; i < max; ++i) {}
  return 0;
}
