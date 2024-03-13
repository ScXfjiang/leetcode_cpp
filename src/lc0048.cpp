#include <vector>

// Solution 1 - Brute Force
void rotate(std::vector<std::vector<int>>& matrix) {
  int n = matrix.size();
  for (int layer = 0; layer < n / 2; ++layer) {
    int first = layer;
    int last = n - 1 - layer;
    for (int i = first; i < last; ++i) {
      int offset = i - first;
      int top = matrix[first][i];  // save top
      // left -> top
      matrix[first][i] = matrix[last - offset][first];
      // bottom -> left
      matrix[last - offset][first] = matrix[last][last - offset];
      // right -> bottom
      matrix[last][last - offset] = matrix[i][last];
      // top -> right
      matrix[i][last] = top;  // right <- saved top
    }
  }
}

// Solution 2 - Transpose and Reverse
void rotate(std::vector<std::vector<int>>& matrix) {
  // transpose the matrix
  for (int i = 0; i < matrix.size(); ++i) {
    for (int j = i; j < matrix.size(); ++j) { std::swap(matrix[i][j], matrix[j][i]); }
  }
  // reverse each row
  for (auto& row : matrix) { std::reverse(row.begin(), row.end()); }
}
