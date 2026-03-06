#include <iostream>
#include "custom_shared_ptr.hpp"

struct Demo {
  float x;
  float y;
};

int main() {
  std::cout << "Homework 3\n\n";
  Homework::custom_shared_ptr<int> ptrOne(new int(42));
  std::cout << "(ptrOne) Show work method get: " << ptrOne.get() << '\n';
  std::cout << "(ptrOne) Show value: " << *ptrOne << "\n\n";
  Homework::custom_shared_ptr<int> ptrTwo = ptrOne;
  *ptrTwo = 100;
  std::cout << "(ptrTwo) Show work method get: " << ptrTwo.get() << '\n';
  std::cout << "(ptrTwo) Show value: " << *ptrTwo << "\n";
  std::cout << "(ptrOne) Show value: " << *ptrOne << "\n\n";
  Homework::custom_shared_ptr<Demo> demo(new Demo{100.0f, 200.0f});
  std::cout << "Demo value X: " << demo->x << '\n';

  return 0;
}
