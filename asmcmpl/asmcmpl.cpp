#include "../core/vm.hpp"
#include "../utils/utils.hpp"
#include <cstdint>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

bool compileIns(std::string line, char *buffer) {
  auto tok = splitString(line);

  // stub for bad case
  if (tok.size() < 1)
    return true;
  if (tok.size() == 0)
    return true;
  if (tok.size() == 1)
    tok.push_back(0);

  for (int i = 0; i < VM::numberOfInstruction; i++) {
    if (strcmp(tok[0].c_str(), VM::instructions[i].name) == 0) {
      uint16_t *buf = (uint16_t *)buffer;
      buf[0] = i;

      std::stringstream ss(tok[1]);
      int number = 0;
      if (ss >> number)
        buf[1] = number;
      else {
        std::cout << "idk what is this: " << tok[1] << '\n';
        return false;
      }

      return true;
    }
  }

  std::cout << "unkown opcode: " << tok[0] << '\n';

  return false;
}

int asmcmpl(std::string filePath, std::string outPath) {
  std::ifstream f(filePath);
  std::ofstream fo(outPath);
  if (!f.is_open()) {
    std::cout << "Error: no such file " << filePath << '\n';
    return -1;
  }

  if (!fo.is_open()) {
    std::cout << "Error: can't create file " << filePath << '\n';
    return -1;
  }

  while (!f.eof()) {
    std::string line;
    char buffer[4];
    std::getline(f, line);

    bool isComment = false;
    for (auto c : line) {
      if (c == '#') {
        isComment = true;
        break;
      } else if (c != ' ') // not a comment
        break;
    }

    if (isComment)
      continue;

    bool s = compileIns(line, buffer);
    if (!s) {
      return -1;
    }

    fo.write(buffer, 4);
    if (f.eof())
      break;
  }

  f.close();
  fo.flush();
  fo.close();

  return 0;
}