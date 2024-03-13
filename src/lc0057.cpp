#include <vector>

std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals,
                                     std::vector<int>& new_interval) {
  std::vector<std::vector<int>> adjusted_intervals;
  int i = 0;
  // 1. intervals before new_interval
  while (i < intervals.size() && intervals[i][1] < new_interval[0]) {
    adjusted_intervals.push_back(intervals[i]);
    ++i;
  }
  // 2. intervals overlapping with new_interval
  while (i < intervals.size() && intervals[i][0] <= new_interval[1]) {
    new_interval[0] = std::min(new_interval[0], intervals[i][0]);
    new_interval[1] = std::max(new_interval[1], intervals[i][1]);
    ++i;
  }
  adjusted_intervals.push_back(new_interval);
  // 3. intervals after new_interval
  while (i < intervals.size()) {
    adjusted_intervals.push_back(intervals[i]);
    ++i;
  }
  return adjusted_intervals;
}
