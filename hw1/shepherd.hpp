#pragma once
#include "cow.hpp"
#include <cstdint>
#include <memory>

namespace Homework {
class Shepherd {
public:
  Shepherd(uint16_t total);
  ~Shepherd();
  void Herd() const;
  void GetDairy() const;

private:
  uint16_t total;
  std::unique_ptr<Cow[]> cow;
};
} // namespace Homework