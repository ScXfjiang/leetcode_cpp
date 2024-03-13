#include <unordered_map>
#include <iostream>

void InsertDemo() {
  std::unordered_map<int, std::string> num2str = {{1, "one"}, {2, "two"}, {3, "three"}};

  /* 1. insert */
  num2str.insert({4, "four"});
  num2str.insert(std::make_pair(5, "five"));
  num2str.insert(std::pair<int, std::string>(6, "six"));

  /* 2. emplace */
  num2str.emplace(7, "seven");

  /* 3. operator [] */
  num2str[10] = "ten";
}

void EraseDemo() {
  std::unordered_map<int, std::string> num2str = {{1, "one"}, {2, "two"}, {3, "three"}};

  /* 1. erase by key */
  num2str.erase(1);

  /* 2. erase by iterator */
  auto it = num2str.find(2);
  if (it != num2str.end()) {
    num2str.erase(it);
  } else {
    std::cout << "not found" << std::endl;
  }
}

void ElementAccessDemo() {
  std::unordered_map<int, std::string> num2str = {{1, "one"}, {2, "two"}, {3, "three"}};

  /* 1. operator [] */
  // element exists
  // return reference to the mapped value of the existing element
  std::string num1 = num2str[1];
  // no element exists
  // insert a new element and return reference to the mapped value of the new element
  std::string num4 = num2str[4];

  /* 2. at() */
  // element exists
  // return reference to the mapped value of the existing element
  std::string num2 = num2str.at(2);
  // no element exists
  // throw std::out_of_range
  std::string num5 = num2str.at(5);
}

void IterateDemo() {
  std::unordered_map<int, std::string> num2str = {{1, "one"}, {2, "two"}, {3, "three"}};

  for (auto& pair : num2str) {
    std::cout << pair.first << std::endl;   // key
    std::cout << pair.second << std::endl;  // value
  }

  for (auto it = num2str.begin(); it != num2str.end(); ++it) {
    std::cout << it->first << std::endl;   // key
    std::cout << it->second << std::endl;  // value
  }
}

void LookUpDemo() {
  std::unordered_map<int, std::string> num2str = {{1, "one"}, {2, "two"}, {3, "three"}};
  auto it = num2str.find(1);
  if (it != num2str.end()) {
    std::cout << it->second << std::endl;
  } else {
    std::cout << "not found" << std::endl;
  }
}

int main() {
  InsertDemo();
  EraseDemo();
  ElementAccessDemo();
  IterateDemo();
  LookUpDemo();
  return 0;
}