#include <vector>

// Solution 1 - Greedy, Sort By End
int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals) {
  std::sort(intervals.begin(), intervals.end(),
            [](const std::vector<int>& lhs, const std::vector<int>& rhs) {
              return lhs[1] < rhs[1];
            });
  int num_removals = 0;
  int prev_end = intervals[0][1];
  for (int i = 1; i < intervals.size(); ++i) {
    if (intervals[i][0] < prev_end) {
      ++num_removals;
    } else {
      prev_end = intervals[i][1];
    }
  }
  return num_removals;
}

// Solution 2 - Greedy, Sort By Start
int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals) {
  std::sort(intervals.begin(), intervals.end(),
            [](const std::vector<int>& lhs, const std::vector<int>& rhs) {
              return lhs[0] < rhs[0];
            });
  int num_removals = 0;
  int prev_end = intervals[0][1];
  for (int i = 1; i < intervals.size(); ++i) {
    if (intervals[i][0] < prev_end) {
      ++num_removals;
      prev_end = std::min(prev_end, intervals[i][1]);
    } else {
      prev_end = intervals[i][1];
    }
  }
  return num_removals;
}
