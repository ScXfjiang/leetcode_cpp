#include <string>
#include <sstream>

// Solution 1 - std::istringstream
int lengthOfLastWord(const std::string& s) {
  std::istringstream iss(s);
  std::string word;
  while (iss >> word) {}
  return word.size();
}

// Solution 2
int lengthOfLastWord(std::string s) {
  // idx of last char of last word
  int j = s.size() - 1;
  while (j >= 0 && s[j] == ' ') { --j; }
  if (j < 0) { return 0; }
  // idx of first space before last word
  int i = j - 1;
  while (i >= 0 && s[i] != ' ') { --i; }
  return j - i;
}