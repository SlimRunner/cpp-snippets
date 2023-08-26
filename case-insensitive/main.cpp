#include <iostream>
#include <string>

inline bool compareChars(char first, char second) {
  return std::tolower(first) == std::tolower(second);
}

int main(int argc, char const *argv[]) {
  std::cout << (compareChars('a', 'a') ? "true" : "false") << "\n";
  return 0;
}
