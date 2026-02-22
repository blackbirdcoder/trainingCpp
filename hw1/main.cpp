#include <iostream>
#include "shepherd.hpp"
#include <cstdint>

const uint16_t TOTAL_COW = 10;

int main() {
  std::cout << "Homework 1\n\n";
  Homework::Shepherd shepherd(TOTAL_COW);
  shepherd.Herd();
  std::cout << std::endl;
  shepherd.GetDairy();
  std::cout << std::endl;

  return 0;
}