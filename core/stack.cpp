#include "stack.hpp"
#include "vm.hpp"
#include <cstdint>
#include <cstdlib>

VM::stack::stack(uint32_t stackSz) {
  while (stackSz % 2 != 0)
    stackSz++;

  stackSize = stackSz;
  stackOffset = (uint16_t *)malloc(stackSz);

  if (stackOffset == NULL) {
    exit(OUT_OF_MEMORY);
  }

  stackTop = stackOffset;

  return;
}

VM::stack::~stack() { free(stackOffset); }

uint16_t *VM::stack::top() { return stackTop; }

void VM::stack::pop() {
  // make sure it doesn't eat anythings wrong
  if (stackTop - 1 >= stackOffset) {
    stackTop--;
  }
}

void VM::stack::push(uint16_t value) {
  // prevent overflow
  if (stackTop + 1 > stackTop + (stackSize / 2)) {
    exit(STACK_OVERFLOW);
  }

  stackTop++;
  *(stackTop) = value;
}