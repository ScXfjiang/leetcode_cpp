#include <vector>

// Solution 1 - One Binary Search
bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
  int m = matrix.size();
  int n = matrix[0].size();
  int left = 0;
  int right = m * n - 1;
  while (left <= right) {
    int mid_idx = left + (right - left) / 2;
    int mid_val = matrix[mid_idx / n][mid_idx % n];
    if (target == mid_val) {
      return true;
    } else if (target < mid_val) {
      right = mid_idx - 1;
    } else {
      left = mid_idx + 1;
    }
  }
  return false;
}

// Solution 2 - Two Binary Searches
bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
  // find the row
  int row = -1;
  int top = 0;
  int bottom = matrix.size() - 1;
  while (top <= bottom) {
    int mid = top + (bottom - top) / 2;
    if (target >= matrix[mid].front() && target <= matrix[mid].back()) {
      row = mid;
      break;
    } else if (target < matrix[mid].front()) {
      bottom = mid - 1;
    } else {
      top = mid + 1;
    }
  }
  if (row == -1) { return false; }
  // find the column
  int left = 0;
  int right = matrix[row].size() - 1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (target == matrix[row][mid]) {
      return true;
    } else if (target < matrix[row][mid]) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return false;
}
