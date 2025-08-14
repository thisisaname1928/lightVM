#include "vm.hpp"
#include "stack.hpp"
#include <cstdint>

VMCore::VMCore(uint32_t stackSize) : stack(stackSize) {}

VMCore::~VMCore() {}