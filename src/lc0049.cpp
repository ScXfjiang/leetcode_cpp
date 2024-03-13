#include <unordered_map>
#include <algorithm>
#include <string>

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
  std::unordered_map<std::string, std::vector<std::string>> key2group;
  for (std::string& str : strs) {
    std::string key = str;
    std::sort(key.begin(), key.end());
    key2group[key].push_back(str);
  }
  std::vector<std::vector<std::string>> result;
  for (auto& pair : key2group) { result.push_back(pair.second); }
  return result;
}
