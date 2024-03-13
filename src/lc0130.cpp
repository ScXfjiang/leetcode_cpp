#include <vector>
#include <queue>
#include <utility>

void solve(std::vector<std::vector<char>>& board) {
  int m = board.size();
  int n = board[0].size();
  // mark 'O's on border and connected to border as 'S' (safe)
  for (int i = 0; i < m; ++i) {
    if (board[i][0] == 'O') { DFSMarkSafe(board, i, 0); }
    if (board[i][n - 1] == 'O') { DFSMarkSafe(board, i, n - 1); }
  }
  for (int j = 0; j < n; ++j) {
    if (board[0][j] == 'O') { DFSMarkSafe(board, 0, j); }
    if (board[m - 1][j] == 'O') { DFSMarkSafe(board, m - 1, j); }
  }
  // flip 'O's to 'X's and 'S's back to 'O's
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (board[i][j] == 'O') { board[i][j] = 'X'; }
      if (board[i][j] == 'S') { board[i][j] = 'O'; }
    }
  }
}

void DFSMarkSafe(std::vector<std::vector<char>>& board, int i, int j) {
  if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) { return; }
  if (board[i][j] != 'O') { return; }
  board[i][j] = 'S';
  DFSMarkSafe(board, i - 1, j);
  DFSMarkSafe(board, i + 1, j);
  DFSMarkSafe(board, i, j - 1);
  DFSMarkSafe(board, i, j + 1);
}
