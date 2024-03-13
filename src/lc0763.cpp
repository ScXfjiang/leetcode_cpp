#include <vector>
#include <string>
#include <unordered_map>

std::vector<int> partitionLabels(std::string s) {
  std::unordered_map<char, int> char2last_idx;
  for (int i = 0; i < s.size(); ++i) { char2last_idx[s[i]] = i; }
  std::vector<int> partitions;
  int start = 0;
  int end = 0;
  for (int i = 0; i < s.size(); ++i) {
    end = std::max(end, char2last_idx[s[i]]);
    if (i == end) {
      partitions.push_back(i - start + 1);
      start = i + 1;
    }
  }
  return partitions;
}
