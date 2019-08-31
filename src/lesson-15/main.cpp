// コピーコンストラクタと代入演算子のオーバーライドの練習
#include <iostream>

class Drink {
 public:
  char *name;
  double volume;

  Drink(const char *name_, const double volume_) {
    name = new char[strlen(name_) + 1];
    strcpy(name, name_);
    volume = volume_;
  }

  ~Drink() {
    delete[] name;
  }

  Drink(const Drink& drink) {
    name = new char[strlen(drink.name) + 1];
    strcpy(name, drink.name);
    volume = drink.volume;
  }

  Drink &operator=(const Drink &drink) {
    if (this == &drink) {
      return *this;
    }

    delete[] name;
    name = new char[strlen(drink.name) + 1];
    strcpy(name, drink.name);
    volume = drink.volume;

    return *this;
  }

  friend std::ostream &operator<<(std::ostream &os, const Drink &drink);
};

std::ostream &operator<<(std::ostream &os, const Drink &drink) {
  os << "Drink(name = " << drink.name << ", volume = " << drink.volume << ")";
  return os;
}

int main() {
  Drink orangeJuice{"Orangina", 500.0};
  Drink water{"Wilkinson", 1500.0};

  std::cout << "orange: " << orangeJuice << std::endl;
  std::cout << "water: " << water << std::endl;

  Drink orange2{"orange", 100};
  orange2 = orangeJuice;
  orange2.volume = 200;

  Drink orange3 = orangeJuice;
  orange3.volume = 300;

  std::cout << "orange2: " << orange2 << std::endl;
  std::cout << "orange3: " << orange3 << std::endl;

  return 0;
}
