#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

// Solution 1 - Greedy + Max Heap
std::string reorganizeString(std::string s) {
  std::unordered_map<char, int> char2freq;
  for (char c : s) {
    ++char2freq[c];
    if (char2freq[c] > (s.size() + 1) / 2) { return ""; }
  }
  auto compare = [](const std::pair<char, int>& a, const std::pair<char, int>& b) {
    return a.second < b.second;
  };
  std::priority_queue<std::pair<char, int>, std::vector<std::pair<char, int>>,
                      decltype(compare)>
      max_heap(compare);
  for (const auto& pair : char2freq) { max_heap.emplace(pair); }
  std::string rearranged;
  while (max_heap.size() >= 2) {
    auto first = max_heap.top();
    max_heap.pop();
    auto second = max_heap.top();
    max_heap.pop();
    rearranged += first.first;
    rearranged += second.first;
    if (--first.second > 0) { max_heap.push(first); }
    if (--second.second > 0) { max_heap.push(second); }
  }
  if (!max_heap.empty()) { rearranged += max_heap.top().first; }
  return rearranged;
}

// Solution 2 - Greedy without Max Heap
std::string reorganizeString(std::string s) {
  std::vector<int> freq(26, 0);
  int n = s.size();
  for (char c : s) {
    ++freq[c - 'a'];
    if (freq[c - 'a'] > (n + 1) / 2) { return ""; }
  }
  std::string rearranged(n, ' ');
  for (int i = 0; i < n; ++i) {
    int max_freq = 0;
    char max_char = ' ';
    for (int j = 0; j < 26; ++j) {
      if (freq[j] > max_freq && (i == 0 || 'a' + j != rearranged[i - 1])) {
        max_freq = freq[j];
        max_char = 'a' + j;
      }
    }
    rearranged[i] = max_char;
    --freq[max_char - 'a'];
  }
  return rearranged;
}
