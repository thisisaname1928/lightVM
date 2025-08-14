#include "asmcmpl/asmcmpl.hpp"
#include "core/vm.hpp"
#include <cstdint>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

uint64_t getFileSize(string path) {
  ifstream f("test.bin");
  if (!f.is_open())
    return 0;

  f.seekg(0, ios::end);
  uint64_t s = f.tellg();

  f.close();
  return s;
}

int main(int argc, char *argv[]) {
  if (argc >= 4) {
    if (strcmp(argv[1], "compile") == 0) {
      return asmcmpl(argv[2], argv[3]);
    }
  }

  ifstream f("test.bin");
  uint32_t *buf = (uint32_t *)malloc(getFileSize("test.bin"));
  f.read((char *)buf, getFileSize("test.bin"));

  VMCore vm(1024);

  for (int i = 0; i < getFileSize("test.bin") / 4; i++) {
    bool s = vm.executeOpcode(buf[i]);
    if (!s) {
      cout << "?\n";
    }
  }

  cout << "program return: " << vm.returnReg << "\n";

  return 0;
}