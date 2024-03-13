#include <vector>

void reveal(std::vector<std::vector<char>>& board, int x, int y) {
  if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] != 'E') { return; }

  // Directions for the adjacent squares (including diagonals)
  int dirs[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
  int count = 0;

  // First pass to count the adjacent mines
  for (auto& dir : dirs) {
    int newX = x + dir[0], newY = y + dir[1];
    if (newX >= 0 && newX < board.size() && newY >= 0 && newY < board[0].size()) {
      if (board[newX][newY] == 'M') { count++; }
    }
  }

  if (count > 0) {
    // If there are adjacent mines, set the count and stop.
    board[x][y] = '0' + count;
  } else {
    // If there are no adjacent mines, reveal all adjacent squares.
    board[x][y] = 'B';
    for (auto& dir : dirs) {
      int newX = x + dir[0], newY = y + dir[1];
      reveal(board, newX, newY);
    }
  }
}

std::vector<std::vector<char>> updateBoard(std::vector<std::vector<char>>& board,
                                           std::vector<int>& click) {
  int x = click[0], y = click[1];

  // If the player clicks a mine, game over.
  if (board[x][y] == 'M') {
    board[x][y] = 'X';
  } else {
    // Otherwise, reveal the board based on the click.
    reveal(board, x, y);
  }

  return board;
}
