#include <iostream>

struct Point {
  int x, y, z;

  Point() : x(0), y(0), z(0) {}
  Point(int x, int y, int z) : x(x), y(y), z(z) {}
  ~Point() {}
};

int main(int argc, char const *argv[]) {
  Point ***points;
  points = new Point **[4];
  for (size_t i = 0; i < 4; ++i) {
    points[i] = new Point *[3];
    for (size_t j = 0; j < 3; ++j) {
      points[i][j] = new Point[2];
      for (size_t k = 0; k < 2; ++k) {
        points[i][j][k] = Point(i, j, k);
      }
    }
  }

  for (size_t i = 0; i < 4; ++i) {
    for (size_t j = 0; j < 3; ++j) {
      for (size_t k = 0; k < 2; ++k) {
        std::cout << "(x, y, z): "
                  << "(" << points[i][j][k].x << ", " << points[i][j][k].y
                  << ", " << points[i][j][k].z << ")"
                  << ", (" << i << ", " << j << ", " << k << ")\n";
      }
    }
  }

  for (size_t i = 0; i < 4; ++i) {
    for (size_t j = 0; j < 3; ++j) {
      delete[] points[i][j];
    }
    delete[] points[i];
  }
  delete[] points;
  points = nullptr;

  std::cout << "\nreached end\n";
  return 0;
}
