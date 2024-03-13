#include <string>

// Solution 1
std::string intToRoman(int num) {
  std::vector<std::pair<int, std::string>> val2symbol = {
      {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"},
      {40, "XL"},  {10, "X"},   {9, "IX"},  {5, "V"},    {4, "IV"},  {1, "I"}};
  std::string roman;
  for (auto &pair : val2symbol) {
    while (num >= pair.first) {
      num -= pair.first;
      roman += pair.second;
    }
  }
  return roman;
}

// Solution 2
std::string intToRoman(int num) {
  std::string thousands[] = {"", "M", "MM", "MMM"};
  std::string hundreds[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
  std::string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
  std::string ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
  return thousands[num / 1000] + hundreds[(num % 1000) / 100] + tens[(num % 100) / 10]
         + ones[num % 10];
}
