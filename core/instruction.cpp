#include "vm.hpp"
#include <cstdint>

#define newInstruction(func, N) {.instruction = func, .name = N}

namespace VM {

int push(VMCore *vm, int16_t value) {
  // only push 32bit value to stack
  vm->stack.push(value & 0xffffffff);
  return 0;
}

int unknown(VMCore *vm, int16_t value) { return 0; }

const VMInstruction instructions[] = {newInstruction(unknown, "unk"),
                                      newInstruction(push, "push")};

const uint64_t numberOfInstruction =
    sizeof(instructions) / sizeof(VMInstruction);
} // namespace VM