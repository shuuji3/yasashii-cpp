#include <iostream>

template<class T>
auto square(T num) -> T;

int main() {
  int num;
  double dnum;

  std::cout << "整数を入力してください。" << std::endl;
  std::cin >> num;
  std::cout << num << "の2乗は" << square(num) << "です。" << std::endl;

  std::cout << "小数を入力してください。" << std::endl;
  std::cin >> dnum;
  std::cout << dnum << "の2乗は" << square(dnum) << "です。" << std::endl;
}

template<class T>
inline auto square(T num) -> T {
  return num * num;
}