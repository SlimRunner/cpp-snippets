#include <chrono>
#include <cstddef> // size_t
#include <functional>

template <int T, class F, class... Args> auto timeIt(F func, Args... args) {
  using hr_clock = std::chrono::high_resolution_clock;
  using chrono_ms = std::chrono::milliseconds;
  constexpr auto to_ms = [](auto x) {
    return std::chrono::duration_cast<chrono_ms>(x).count();
  };

  auto start = hr_clock::now();

  for (size_t i = 0; i < T; ++i) {
    std::invoke(std::forward<F>(func), std::forward<Args>(args)...);
  }

  return to_ms(hr_clock::now() - start);
}
