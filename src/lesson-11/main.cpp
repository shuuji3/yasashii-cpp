#include <iostream>

struct Person {
  int age;
  double height;
};

void aging(Person &p);
void showPerson(const Person &p);

int main() {
  const int num = 2;
  auto persons = new Person[num];

  for (int i = 0; i < num; i++) {
    std::cout << i + 1 << "人目の年齢を入力してください: " << std::endl;
    std::cin >> persons[i].age;
    std::cout << i + 1 << "人目身長を入力してください: " << std::endl;
    std::cin >> persons[i].height;
  }

  for (int i = 0; i < num; i++) {
    std::cout << i + 1 << "人目: ";
    showPerson(persons[i]);
  }

  aging(persons[0]);
  aging(persons[1]);
  std::cout << "歳を取りました" << std::endl;

  for (int i = 0; i < num; i++) {
    std::cout << i + 1 << "人目: ";
    showPerson(persons[i]);
  }

  delete[] persons;
}

void showPerson(const Person &p) {
  std::cout << "年齢 = " << p.age << ", 身長 = " << p.height << std::endl;
}

void aging(Person &p) {
  p.age++;
}
