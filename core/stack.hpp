#include <cstdint>
#pragma once

namespace VM {
class stack {
public:
  stack(uint32_t stackSize);
  ~stack();
  uint16_t *top();
  void push(uint16_t value);
  void pop();

private:
  uint16_t *stackOffset;
  uint16_t *stackTop;
  uint16_t stackSize;
};
} // namespace VM