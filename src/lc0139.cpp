#include <string>
#include <vector>
#include <unordered_set>

bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
  std::unordered_set<std::string> dict(wordDict.begin(), wordDict.end());
  // dp[i] = true if s.substr(0, i) can be broken into words
  std::vector<bool> dp(s.size() + 1, false);
  // base case: dp[0] = 0
  dp[0] = true;
  for (int i = 1; i <= s.size(); ++i) {
    for (int j = 0; j < i; ++j) {
      // s.substr(0, j) can be broken into words && s.substr(j, i - j) is in the dict
      if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
        dp[i] = true;
        break;
      }
    }
  }
  return dp.back();
}
