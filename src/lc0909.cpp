#include <vector>
#include <queue>
#include <utility>

// Utility function to get the board value at a specific index.
int getBoardValue(const std::vector<std::vector<int>>& board, int pos) {
  int n = board.size();
  int r = (pos - 1) / n;
  int x = n - 1 - r;
  int y = (r % 2 == 0) ? (pos - 1) % n : n - 1 - ((pos - 1) % n);
  return board[x][y];
}

int snakesAndLadders(std::vector<std::vector<int>>& board) {
  int n = board.size();
  std::vector<bool> visited(n * n + 1, false);
  std::queue<std::pair<int, int>> q;  // Pair of (position, moves)

  q.push({1, 0});  // Start from cell 1 with 0 moves
  visited[1] = true;

  while (!q.empty()) {
    auto [pos, moves] = q.front();  // Current position and number of moves
    q.pop();

    if (pos == n * n) {  // Reached the last cell
      return moves;
    }

    for (int i = 1; i <= 6; ++i) {  // Explore next 6 cells
      if (pos + i <= n * n && !visited[pos + i]) {
        visited[pos + i] = true;
        int nextPos = getBoardValue(board, pos + i);
        if (nextPos == -1) {  // No ladder/snake, move normally
          q.push({pos + i, moves + 1});
        } else {  // Ladder or snake encountered
          if (!visited[nextPos]) {
            visited[nextPos] = true;
            q.push({nextPos, moves + 1});
          }
        }
      }
    }
  }

  return -1;  // If we're here, there's no way to reach the end
}
