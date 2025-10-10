#include <chrono>
#include <cstddef> // size_t
#include <functional>

template <int T, class F, class... Args> auto timeIt(F func, Args... args) {
  using hr_clock = std::chrono::steady_clock;
  auto start = hr_clock::now();

  for (size_t i = 0; i < T; i++) {
    if constexpr (std::is_void_v<std::invoke_result_t<F, Args...>>) {
      std::invoke(std::forward<F>(func), std::forward<Args>(args)...);
    } else {
      // result is discarded
      std::invoke(std::forward<F>(func), std::forward<Args>(args)...);
    }
  }

  return hr_clock::now() - start;
}
