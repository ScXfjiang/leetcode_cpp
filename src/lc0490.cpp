#include <vector>

bool hasPath(std::vector<std::vector<int>>& maze, std::vector<int>& start,
             std::vector<int>& destination) {
  std::vector<std::vector<bool>> visited(maze.size(), std::vector<bool>(maze[0].size(), false));
  return dfs(maze, start[0], start[1], destination, visited);
}

bool dfs(std::vector<std::vector<int>>& maze, int row, int col, std::vector<int>& destination,
         std::vector<std::vector<bool>>& visited) {
  // If we're out of bounds or at a wall, or if we've visited this point before, stop exploring.
  if (!isValid(maze, row, col) || visited[row][col]) { return false; }

  // If we've reached the destination, return true.
  if (row == destination[0] && col == destination[1]) { return true; }

  // Mark this point as visited.
  visited[row][col] = true;

  // Roll the ball in each direction until it hits a wall.
  int i, j;
  // Up
  for (i = row; isValid(maze, i - 1, col); --i)
    ;
  if (dfs(maze, i, col, destination, visited)) return true;

  // Down
  for (i = row; isValid(maze, i + 1, col); ++i)
    ;
  if (dfs(maze, i, col, destination, visited)) return true;

  // Left
  for (j = col; isValid(maze, row, j - 1); --j)
    ;
  if (dfs(maze, row, j, destination, visited)) return true;

  // Right
  for (j = col; isValid(maze, row, j + 1); ++j)
    ;
  if (dfs(maze, row, j, destination, visited)) return true;

  // If none of the paths worked out, return false.
  return false;
}

// Helper function to check if a position is within the bounds and not a wall.
bool isValid(std::vector<std::vector<int>>& maze, int row, int col) {
  return row >= 0 && col >= 0 && row < maze.size() && col < maze[0].size() && maze[row][col] == 0;
}