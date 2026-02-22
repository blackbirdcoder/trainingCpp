#include "custom_unique_ptr.hpp"
#include <iostream>

struct Demo {
  float x;
  float y;
};

int main() {
  std::cout << "Homework 2\n\n";

  Homework::custom_unique_ptr<float> fltPtr(new float(100));
  std::cout << "Memory addresses: " << fltPtr.get() << '\n'
            << "Value: " << *fltPtr << "\n\n";

  Homework::custom_unique_ptr<Demo> demoPtr(new Demo{10.0f, 22.0f});
  std::cout << "Memory addresses: " << demoPtr.get() << '\n'
            << "Value X: " << demoPtr->x << "\n\n";

  return 0;
}