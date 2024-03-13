#include <iostream>
#include <unordered_map>

// Solution 1
int romanToInt(std::string s) {
  std::unordered_map<char, int> symbol2val = {{'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
                                              {'C', 100}, {'D', 500}, {'M', 1000}};
  int num = symbol2val[s.back()];
  for (int i = s.size() - 2; i >= 0; --i) {
    if (symbol2val[s[i]] < symbol2val[s[i + 1]]) {
      num -= symbol2val[s[i]];
    } else {
      num += symbol2val[s[i]];
    }
  }
  return num;
}

// Solution 2
int romanToInt(std::string s) {
  std::unordered_map<std::string, int> symbol2val = {
      {"I", 1},   {"IV", 4},  {"V", 5},    {"IX", 9},  {"X", 10},   {"XL", 40}, {"L", 50},
      {"XC", 90}, {"C", 100}, {"CD", 400}, {"D", 500}, {"CM", 900}, {"M", 1000}};
  int num = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (i < s.size() - 1 && symbol2val.find(s.substr(i, 2)) != symbol2val.end()) {
      num += symbol2val[s.substr(i, 2)];
      ++i;
    } else {
      num += symbol2val[s.substr(i, 1)];
    }
  }
  return num;
}
