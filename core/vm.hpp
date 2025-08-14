#pragma once

#include "stack.hpp"
#include <cstdint>

class VMCore {
public:
  VMCore(uint32_t stackSize);
  ~VMCore();
  VM::stack stack;
  bool executeOpcode(uint32_t opcode);
  uint64_t returnReg;
};

typedef enum { OUT_OF_MEMORY = -2, STACK_OVERFLOW = -3 } VMError;
typedef int (*Instruction)(VMCore *, int16_t);
typedef struct {
  Instruction instruction;
  char name[10];
} VMInstruction;

namespace VM {
extern const VMInstruction instructions[];
extern const uint64_t numberOfInstruction;
} // namespace VM
