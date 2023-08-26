#include <iostream>

struct Point {
  int x, y;

  Point() : x(0), y(0) {}
  Point(int x, int y) : x(x), y(y) {}
  ~Point() {}
};

int main(int argc, char const *argv[]) {
  Point **points;
  points = new Point *[8];
  for (size_t i = 0; i < 8; ++i) {
    points[i] = new Point[6];
    for (size_t j = 0; j < 6; ++j) {
      points[i][j] = Point(i, j);
    }
  }

  for (size_t i = 0; i < 8; ++i) {
    for (size_t j = 0; j < 6; ++j) {
      std::cout << "(x, y): "
                << "(" << points[i][j].x << ", " << points[i][j].y << ")"
                << ", (" << i << ", " << j << ")\n";
    }
  }

  for (size_t i = 0; i < 8; ++i) {
    delete[] points[i];
  }
  delete[] points;
  points = nullptr;

  std::cout << "\nreached end\n";
  return 0;
}
