#include <iostream>

template<typename T>
void print(T msg) {
  std::cout << msg << std::endl;
}

template<typename T, typename... U>
void print(T msg, U... rest) {
  std::cout << msg << '\t';
  print(rest...);
}

int main(int argc, char const *argv[]) {
  print(5, "456", 9, "we");
  return 0;
}
