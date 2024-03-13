#include <iostream>
#include <vector>

void PrintDPTable(const std::vector<std::vector<int>>& dp) {
  for (const auto& row : dp) {
    for (int val : row) { std::cout << val << " "; }
    std::cout << std::endl;
  }
}

void PrintDPVector(const std::vector<int>& dp) {
  for (int val : dp) { std::cout << val << " "; }
  std::cout << std::endl;
}

// 2D DP Table
int Knapsack2D_1(const std::vector<int>& weights, const std::vector<int>& values,
                 int capacity) {
  // dp[i][j] - maximum value of the first i items with a capacity of j
  std::vector<std::vector<int>> dp(weights.size() + 1, std::vector<int>(capacity + 1, 0));
  for (int i = 1; i <= weights.size(); ++i) {
    for (int j = 1; j <= capacity; ++j) {
      if (j < weights[i - 1]) {
        dp[i][j] = dp[i - 1][j];
      } else {
        dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - weights[i - 1]] + values[i - 1]);
      }
    }
  }

  PrintDPTable(dp);

  return dp[weights.size()][capacity];
}

// 2D DP Table
int Knapsack2D_2(const std::vector<int>& weights, const std::vector<int>& values,
                 int capacity) {
  // dp[i][j] - maximum value of the first i items with a capacity of j
  std::vector<std::vector<int>> dp(weights.size() + 1, std::vector<int>(capacity + 1, 0));
  for (int j = 1; j <= capacity; ++j) {
    for (int i = 1; i <= weights.size(); ++i) {
      if (j < weights[i - 1]) {
        dp[i][j] = dp[i - 1][j];
      } else {
        dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - weights[i - 1]] + values[i - 1]);
      }
    }
  }

  PrintDPTable(dp);

  return dp[weights.size()][capacity];
}

// 2D DP Table
int Knapsack2D_3(const std::vector<int>& weights, const std::vector<int>& values,
                 int capacity) {
  // dp[i][j] - maximum value of the first i items with a capacity of j
  std::vector<std::vector<int>> dp(weights.size() + 1, std::vector<int>(capacity + 1, 0));
  for (int i = 1; i <= weights.size(); ++i) {
    for (int j = capacity; j >= 1; --j) {
      if (j < weights[i - 1]) {
        dp[i][j] = dp[i - 1][j];
      } else {
        dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - weights[i - 1]] + values[i - 1]);
      }
    }
  }

  PrintDPTable(dp);

  return dp[weights.size()][capacity];
}

// 1D DP Vector
int Knapsack1D(const std::vector<int>& weights, const std::vector<int>& values,
               int capacity) {
  // dp[j] - maximum value with a capacity of j
  std::vector<int> dp(capacity + 1, 0);
  for (int i = 1; i <= weights.size(); ++i) {
    for (int j = capacity; j >= weights[i - 1]; --j) {
      dp[j] = std::max(dp[j], dp[j - weights[i - 1]] + values[i - 1]);
    }
  }

  PrintDPVector(dp);

  return dp[capacity];
}

int main() {
  std::vector<int> weights = {1, 2, 3, 6, 12};
  std::vector<int> values = {2, 1, 4, 7, 10};
  int capacity = 10;
  std::cout << Knapsack2D_1(weights, values, capacity) << std::endl;  // 13
  std::cout << Knapsack2D_2(weights, values, capacity) << std::endl;  // 13
  std::cout << Knapsack2D_3(weights, values, capacity) << std::endl;  // 13
  std::cout << Knapsack1D(weights, values, capacity) << std::endl;    // 13
  return 0;
}
