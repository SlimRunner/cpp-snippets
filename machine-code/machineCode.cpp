/*
a constexpr results in a zero-cost abstraction over
#define so long as the type is a built-in
*/

#define MACRO_CONST "Hello world"
constexpr const char *EXPR_CONST = "Hello world";

int addChars(const char *src) {
  int total = 0;
  for (int i = 0; src[i] != '\0'; ++i) {
    total += static_cast<int>(src[i]);
  }
  return total;
}

int main() {
  addChars(EXPR_CONST);
  return 0;
}