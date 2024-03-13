#include <vector>
#include <string>
#include <abs>

int totalNQueens(int n) {
  // queen's position in each row
  std::vector<int> positions(n);
  int num_solution = 0;
  solveNQueens(n, 0, positions, num_solution);
  return num_solution;
}

// This function checks if a queen can be placed at the given row and col
bool isSafe(int row, int col, std::vector<int>& positions) {
  for (int prev = 0; prev < row; ++prev) {
    int pos = positions[prev];

    // Check if two queens are in the same column
    if (pos == col) { return false; }

    // Check diagonals: if the difference between the current col
    // and the col of the previous row queen is equal to the row difference,
    // then they're in the same diagonal.
    if (std::abs(col - pos) == row - prev) { return false; }
  }
  return true;
}

// This function tries to place queens on the board
void solveNQueens(int n, int row, std::vector<int>& positions, int& num_solution) {
  // If the row is equal to n, we've successfully placed all queens
  if (row == n) {
    ++num_solution;
    return;
  }

  // Try placing a queen in each column
  for (int col = 0; col < n; ++col) {
    if (isSafe(row, col, positions)) {
      positions[row] = col;                               // Place the queen
      solveNQueens(n, row + 1, positions, num_solution);  // Go to the next row
      // No need to remove the queen, as the position will be overwritten
    }
  }
}
