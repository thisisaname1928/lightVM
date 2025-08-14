#include "vm.hpp"
#include "stack.hpp"
#include <cstdint>
#include <iostream>

VMCore::VMCore(uint32_t stackSize) : stack(stackSize) {}

VMCore::~VMCore() {}

bool VMCore::executeOpcode(uint32_t block) {
  uint16_t opcode = block & 0xffff;
  if (opcode >= VM::numberOfInstruction) {
    std::cout << "invalid opcode: " << opcode << '\n';
    return false;
  }

  VM::instructions[opcode].instruction(this, (block >> 16) & 0xffff);

  return true;
}