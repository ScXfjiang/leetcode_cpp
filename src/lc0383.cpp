#include <unordered_map>
#include <string>

bool canConstruct(std::string ransomNote, std::string magazine) {
  std::unordered_map<char, int> char2cnt;
  for (char c : magazine) { ++char2cnt[c]; }
  for (char c : ransomNote) {
    if (char2cnt[c] <= 0) {
      return false;
    } else {
      --char2cnt[c];
    }
  }
  return true;
}