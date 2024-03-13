#include <sstream>
#include <iostream>

int Demo() {
  std::istringstream iss("123 abc");
  int num;
  std::string str;
  // this operation will succeed and num will contain 123
  if (iss >> num) {
    std::cout << "read int: " << num << std::endl;
  } else {
    std::cout << "failed to read int" << std::endl;
  }
  // this operation will fail because the next in the stream is not an int
  if (iss >> num) {
    std::cout << "read int: " << num << std::endl;
  } else {
    std::cout << "failed to read int" << std::endl;
  }

  iss.clear();

  // this operation will succeed and str will contain "abc"
  if (iss >> str) {
    std::cout << "read string: " << str << std::endl;
  } else {
    std::cout << "failed to read string" << std::endl;
  }
  return 0;
}

int main() { return Demo(); }