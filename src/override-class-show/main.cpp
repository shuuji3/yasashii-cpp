// operator << をオーバーライドすることで、自分で定義したクラスを cout
// できるようにする
#include <iostream>

class Point {
 private:
  double x;
  double y;

 public:
  Point(double x_, double y_) {
    x = x_;
    y = y_;
  }

  friend std::ostream &operator<<(std::ostream &os, const Point &p);
};

std::ostream &operator<<(std::ostream &os, const Point &p) {
  os << "Point{" << p.x << ", " << p.y << "}" << std::endl;
  return os;
}

int main() {
  using namespace std;
  auto p1 = Point{1, 3};
  auto p2 = Point{4, 5};
  cout << p1 << p2 << endl;
}
