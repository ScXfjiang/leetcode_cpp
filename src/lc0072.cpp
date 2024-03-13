#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int minDistance(std::string word1, std::string word2) {
  int m = word1.size();
  int n = word2.size();
  // dp[i][j] = min edit distance between word1.substr(0, i) and word2.substr(0, j)
  std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
  dp[0][0] = 0;
  for (int i = 1; i <= m; ++i) { dp[i][0] = i; }
  for (int j = 1; j <= n; ++j) { dp[0][j] = j; }
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (word1[i - 1] == word2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1];
      } else {
        dp[i][j] =
            1
            + std::min(
                {/* [Deletion] delete the last character of word1.substr(0, i) before the
                    transformation from word1.sbustr(0, i - 1) to word2.substr(0, j) */
                 dp[i - 1][j],
                 /* [Insertion] append the last character of word2.substr(0, j) to
                    word2.substr(0, j - 1) after the transformation from word1.sbustr(0, i)
                    to word2.substr(0, j - 1) */
                 dp[i][j - 1],
                 /* [Substitution] replace the last character of word1.substr(0, i) with the
                    last character of word2.substr(0, j) after the transformation from
                    word1.sbustr(0, i - 1) to word2.substr(0, j - 1) */
                 dp[i - 1][j - 1]});
      }
    }
  }
  return dp[m][n];
}
