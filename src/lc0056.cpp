#include <vector>
#include <algorithm>
#include <iostream>

std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
  std::sort(intervals.begin(), intervals.end(),
            [](const std::vector<int>& lhs, const std::vector<int>& rhs) {
              return lhs[0] < rhs[0];
            });
  std::vector<std::vector<int>> merged;
  for (const auto& interval : intervals) {
    if (!merged.empty() && interval[0] <= merged.back()[1]) {
      merged.back()[1] = std::max(merged.back()[1], interval[1]);
    } else {
      merged.push_back(interval);
    }
  }
  return merged;
}