#pragma once


namespace Homework {
class Cow {
public:
  Cow();
  ~Cow();
  void Speak() const;
  float GetMilk();


private:
  float milk;
  float randMilk();
};
} // namespace Homework