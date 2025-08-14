#include <sstream>
#include <string>
#include <vector>

std::vector<std::string> splitString(const std::string &str) {
  std::vector<std::string> parts;
  std::stringstream ss(str);
  std::string part;
  while (ss >> part) {
    parts.push_back(part);
  }
  return parts;
}