#include <string>

#include <string>

bool validWordAbbreviation(std::string word, std::string abbr) {
  int i = 0;
  int j = 0;
  while (i < word.size() && j < abbr.size()) {
    if (std::isdigit(abbr[j])) {
      if (abbr[j] == '0') { return false; }
      int num = 0;
      while (j < abbr.size() && std::isdigit(abbr[j])) {
        num = num * 10 + (abbr[j] - '0');
        j++;
      }
      i += num;
    } else {
      if (word[i] != abbr[j]) { return false; }
      i++;
      j++;
    }
  }
  return i == word.size() && j == abbr.size();
}
