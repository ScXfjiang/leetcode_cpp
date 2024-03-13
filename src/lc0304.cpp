#include <vector>

// Solution 1 - Prefix Sum (size m + 1 x n + 1)
class NumMatrix {
 public:
  NumMatrix(std::vector<std::vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    prefix_sum_ = std::vector<std::vector<int>>(m + 1, std::vector<int>(n + 1, 0));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        prefix_sum_[i + 1][j + 1] =
            matrix[i][j] + prefix_sum_[i][j + 1] + prefix_sum_[i + 1][j] - prefix_sum_[i][j];
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    return prefix_sum_[row2 + 1][col2 + 1] - prefix_sum_[row2 + 1][col1]
           - prefix_sum_[row1][col2 + 1] + prefix_sum_[row1][col1];
  }

 private:
  std::vector<std::vector<int>> prefix_sum_;
};

// Solution 2 - Prefix Sum (size m x n)
class NumMatrix {
 public:
  NumMatrix(std::vector<std::vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    prefix_sum_ = std::vector<std::vector<int>>(m, std::vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        prefix_sum_[i][j] = matrix[i][j] + (i == 0 ? 0 : prefix_sum_[i - 1][j])
                            + (j == 0 ? 0 : prefix_sum_[i][j - 1])
                            - (i == 0 || j == 0 ? 0 : prefix_sum_[i - 1][j - 1]);
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    return prefix_sum_[row2][col2] - (row1 == 0 ? 0 : prefix_sum_[row1 - 1][col2])
           - (col1 == 0 ? 0 : prefix_sum_[row2][col1 - 1])
           + (row1 == 0 || col1 == 0 ? 0 : prefix_sum_[row1 - 1][col1 - 1]);
  }

 private:
  std::vector<std::vector<int>> prefix_sum_;
};
