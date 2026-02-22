#include "shepherd.hpp"
#include <iostream>

Homework::Shepherd::Shepherd(uint16_t total) {
  this->total = total;
  this->cow = std::make_unique<Cow[]>(this->total);
}

Homework::Shepherd::~Shepherd() {
  std::cout << "[!] Shepherd end of existence, data destroyed\n";
}

void Homework::Shepherd::Herd() const {
  for (uint16_t i = 0; i < this->total; ++i) {
    std::cout << "Cow id:" << i + 1 << " eats grass ";
    cow[i].Speak();
    std::cout << std::endl;
  }
}

void Homework::Shepherd::GetDairy() const {
  for (uint16_t i = 0; i < this->total; ++i) {
    std::cout << "Cow id: " << i + 1 << " gave milk " << cow[i].GetMilk()
              << " litre\n";
  }
}
