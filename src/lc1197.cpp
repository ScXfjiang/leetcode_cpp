#include <vector>
#include <queue>
#include <utility>
#include <set>

// Solution 1 - BFS (Time Limit Exceeded)
int minKnightMoves(int x, int y) {
  std::vector<std::vector<int>> moves = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2},
                                         {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
  std::set<std::pair<int, int>> visited;
  std::queue<std::pair<std::pair<int, int>, int>> q;
  q.push({{0, 0}, 0});
  visited.insert({0, 0});
  while (!q.empty()) {
    auto& front = q.front();
    auto cur_pos = front.first;
    int num_move = front.second;
    q.pop();
    if (cur_pos.first == x && cur_pos.second == y) { return num_move; }
    for (const auto& move : moves) {
      int next_x = cur_pos.first + move[0];
      int next_y = cur_pos.second + move[1];
      std::pair<int, int> next_pos = {next_x, next_y};
      if (visited.find(next_pos) == visited.end()) {
        q.push({next_pos, num_move + 1});
        visited.insert(next_pos);
      }
    }
  }
  return -1;
}

// Solution 2 - Formula
int minKnightMoves(int x, int y) {
  // adjust to 1/8
  if (x < 0) { x = -x; }
  if (y < 0) { y = -y; }
  if (x < y) { std::swap(x, y); }

  // edge case
  if (x == 1 and y == 0) { return 3; }
  if (x == 2 and y == 2) { return 4; }

  // core formula
  if (y <= x / 2) {
    return (x + 1) / 2 + (x / 2 - y) % 2;
  } else {
    return (x + y) / 3 + (x + y) % 3;
  }
}