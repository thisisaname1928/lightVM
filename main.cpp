#include "asmcmpl/asmcmpl.hpp"
#include <cstring>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  if (argc >= 4) {
    if (strcmp(argv[1], "compile") == 0) {
      return asmcmpl(argv[2], argv[3]);
    }
  }

  cout << "hi\n";

  return 0;
}