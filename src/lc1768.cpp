#include <string>

std::string mergeAlternately(std::string word1, std::string word2) {
  std::string merged;
  int i = 0;
  int j = 0;
  while (i < word1.size() || j < word2.size()) {
    if (i < word1.size()) { merged += word1[i++]; }
    if (j < word2.size()) { merged += word2[j++]; }
  }
  return merged;
}

std::string mergeAlternately(std::string word1, std::string word2) {
  int m = word1.size();
  int n = word2.size();
  int k = std::min(m, n);
  std::string merged;
  for (int i = 0; i < k; ++i) {
    merged += word1[i];
    merged += word2[i];
  }
  if (m > n) {
    merged += word1.substr(k, m - k + 1);
  } else if (n > m) {
    merged += word2.substr(k, n - k + 1);
  }
  return merged;
}