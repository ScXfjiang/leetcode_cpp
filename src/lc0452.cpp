#include <vector>

// Solution 1 - Greedy, Sort By End
int findMinArrowShots(std::vector<std::vector<int>>& points) {
  std::sort(points.begin(), points.end(),
            [](const std::vector<int>& lhs, const std::vector<int>& rhs) {
              return lhs[1] < rhs[1];
            });
  int num_arrows = 1;
  int arrow_pos = points[0][1];
  for (const std::vector<int>& balloon : points) {
    if (balloon[0] > arrow_pos) {
      ++num_arrows;
      arrow_pos = balloon[1];
    }
  }
  return num_arrows;
}

// Solution 2 - Greedy, Sort By Start
int findMinArrowShots(std::vector<std::vector<int>>& points) {
  std::sort(points.begin(), points.end(),
            [](const std::vector<int>& lhs, const std::vector<int>& rhs) {
              return lhs[0] < rhs[0];
            });
  int num_arrows = 1;
  int arrow_pos = points[0][1];
  for (const std::vector<int>& balloon : points) {
    if (balloon[0] <= arrow_pos) {
      arrow_pos = std::min(arrow_pos, balloon[1]);
    } else {
      ++num_arrows;
      arrow_pos = balloon[1];
    }
  }
  return num_arrows;
}
