#include "cow.hpp"
#include <random>
#include <iostream>

Homework::Cow::Cow() { this->milk = 0.0f; }

Homework::Cow::~Cow() { std::cout << "[!] Cow say goodbye\n"; }

float Homework::Cow::GetMilk() {
  this->milk = this->randMilk();
  return this->milk;
}

void Homework::Cow::Speak() const { std::cout << "My-my-my!"; }

float Homework::Cow::randMilk() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<float> dist(1.0f, 21.0f);
  return dist(gen);
}
