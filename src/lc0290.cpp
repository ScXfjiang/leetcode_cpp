#include <string>
#include <sstream>

bool wordPattern(std::string pattern, std::string s) {
  std::unordered_map<char, std::string> char2word;
  std::unordered_map<std::string, char> word2char;
  std::istringstream iss(s);
  std::string word;
  for (char c : pattern) {
    if (!(iss >> word)) { return false; }
    if (char2word.find(c) != char2word.end() && char2word[c] != word) { return false; }
    char2word[c] = word;
    if (word2char.find(word) != word2char.end() && word2char[word] != c) { return false; }
    word2char[word] = c;
  }
  return !(iss >> word);
}
