#include <vector>
#include <algorithm>

// Solution 1 - Greedy
int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
  std::sort(g.begin(), g.end(), std::greater<int>());
  std::sort(s.begin(), s.end(), std::greater<int>());
  int num_content = 0;
  int i = 0;  // idx of child
  int j = 0;  // idx of cookies
  // assign the biggest cookie to the child with the biggest greed factor
  while (i < g.size() && j < s.size()) {
    if (s[j] >= g[i]) {
      ++num_content;
      ++j;
    }
    ++i;
  }
  return num_content;
}

int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
  std::sort(g.begin(), g.end(), std::greater<int>());
  std::sort(s.begin(), s.end(), std::greater<int>());
  // assign the biggest cookie to the child with the biggest greed factor
  // i - idx of child
  // j - idx of cookie
  int j = 0;
  for (int i = 0; i < g.size(); ++i) {
    if (j < s.size() && s[j] >= g[i]) { ++j; }
  }
  return j;
}

// Solution 2 - Greedy
int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
  std::sort(g.begin(), g.end());
  std::sort(s.begin(), s.end());
  int num_content = 0;
  int i = 0;  // idx of child
  int j = 0;  // idx of cookies
  // assign the smallest cookie to the child with the smallest greed factor
  while (i < g.size() && j < s.size()) {
    if (s[j] >= g[i]) {
      ++num_content;
      ++i;
    }
    ++j;
  }
  return num_content;
}

int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
  std::sort(g.begin(), g.end());
  std::sort(s.begin(), s.end());
  // assign the smallest cookie to the child with the smallest greed factor
  // i - idx of child
  // j - idx of cookie
  int i = 0;
  for (int j = 0; j < s.size(); ++j) {
    if (i < g.size() && s[j] >= g[i]) { ++i; }
  }
  return i;
}
