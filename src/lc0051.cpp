#include <vector>
#include <string>

std::vector<std::vector<std::string>> solveNQueens(int n) {
  std::vector<std::vector<std::string>> solutions;
  std::vector<std::string> board(n, std::string(n, '.'));
  solveNQueensRec(0, board, solutions, n);
  return solutions;
}

bool isSafe(int row, int col, std::vector<std::string>& board, int n) {
  // Check this row on left side
  for (int i = 0; i < col; i++)
    if (board[row][i] == 'Q') return false;

  // Check upper diagonal on left side
  for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    if (board[i][j] == 'Q') return false;

  // Check lower diagonal on left side
  for (int i = row, j = col; j >= 0 && i < n; i++, j--)
    if (board[i][j] == 'Q') return false;

  return true;
}

void solveNQueensRec(int col, std::vector<std::string>& board,
                     std::vector<std::vector<std::string>>& solutions, int n) {
  if (col == n) {
    solutions.push_back(board);
    return;
  }

  for (int i = 0; i < n; i++) {
    if (isSafe(i, col, board, n)) {
      board[i][col] = 'Q';
      solveNQueensRec(col + 1, board, solutions, n);
      board[i][col] = '.';  // backtrack
    }
  }
}
