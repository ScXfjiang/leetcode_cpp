#include <iostream>
#include <string>
#include <cctype>

void InsertDemo() {
  std::string str = "0123456789";

  // insert 'x' before iterator pos, return iterator to the inserted character
  auto pos = str.begin() + 5;
  auto it1 = str.insert(pos, 'x');
  std::cout << *it1 << std::endl;  // x

  // insert 3 'y's before iterator pos, return iterator to the first inserted character
  pos = str.begin() + 5;
  auto it2 = str.insert(pos, 3, 'y');
  std::cout << *it2 << std::endl;  // y

  // insert {'i', 'j', 'k'} before iterator pos, return iterator to the first inserted
  // character
  pos = str.begin() + 5;
  auto it3 = str.insert(pos, {'i', 'j', 'k'});
  std::cout << *it3 << std::endl;  // i

  std::string str2 = "abcdefg";
  // insert "abc" before iterator pos, return iterator to the first inserted character
  pos = str.begin() + 5;
  auto it4 = str.insert(pos, str2.begin(), str2.begin() + 3);
  std::cout << *it4 << std::endl;  // a

  std::cout << str << std::endl;  // 01234abcijkyyyx56789
}

void AppendDemo() {
  std::string str = "0123456789";

  // append 'x' to the end of the string
  str.push_back('x');

  // append 3 'y's to the end of the string
  str.append(3, 'y');

  // append {'i', 'j', 'k'} to the end of the string
  str.append({'i', 'j', 'k'});

  std::string str2 = "abcdefg";
  // append "abc" to the end of the string
  str.append(str2.begin(), str2.begin() + 3);

  std::cout << str << std::endl;  // 0123456789xyyyijkabc
}

void EraseDemo() {
  std::string str = "0123456789";

  // 1. erase by iterator, return iterator to the next character
  auto pos = str.begin() + 5;
  auto it1 = str.erase(pos);
  std::cout << *it1 << std::endl;  // 6

  // 2. erase by range, return iterator to the next character
  auto it2 = str.erase(str.begin() + 5, str.begin() + 8);
  std::cout << *it2 << std::endl;  // 9

  // 3. pop the last character, void function
  str.pop_back();

  std::cout << str << std::endl;  // 01234
}

void ConcatenateDemo() {
  std::string str = "0123456789";

  // concatenate str and a character
  str += 'x';

  // concatenate str and a string
  std::string str2 = "abcdefg";
  str += str2;

  std::cout << str << std::endl;  // 0123456789xabcdefg
}

void LookUpDemo() {
  std::string str = "01234567890123456789";

  // find the first occurrence of the given character, return index
  int idx = str.find('5');
  if (idx != std::string::npos) {
    std::cout << idx << std::endl;  // 5
  } else {
    std::cout << "not found" << std::endl;
  }

  // find the first occurrence of the given substring, return index
  idx = str.find("345");
  if (idx != std::string::npos) {
    std::cout << idx << std::endl;  // 3
  } else {
    std::cout << "not found" << std::endl;
  }

  // start searching from the given index, return index
  idx = str.find('0', 10);
  if (idx != std::string::npos) {
    std::cout << idx << std::endl;  // 10
  } else {
    std::cout << "not found" << std::endl;
  }

  // start searching from the given index, return index
  idx = str.find("012", 10);
  if (idx != std::string::npos) {
    std::cout << idx << std::endl;  // 10
  } else {
    std::cout << "not found" << std::endl;
  }
}

void CharacterOperation() {
  char ch = 'a';

  int isalnum(int ch);
  int isalpha(int ch);
  int isdigit(int ch);

  int std::tolower(int ch);
  int std::toupper(int ch);

  std::string str = "AbcDefG";
  std::transform(str.begin(), str.end(), str.begin(),
                 [](char c) { return std::tolower(c); });
}

int main() {
  InsertDemo();
  AppendDemo();
  EraseDemo();
  ConcatenateDemo();
  LookUpDemo();
  return 0;
}
