#include <vector>
#include <algorithm>

std::vector<std::vector<int>> intervalIntersection(
    std::vector<std::vector<int>>& interval_list1,
    std::vector<std::vector<int>>& interval_list2) {
  std::vector<std::vector<int>> intersections;
  int i = 0;
  int j = 0;
  while (i < interval_list1.size() && j < interval_list2.size()) {
    // check if there is an intersection
    int start_max = std::max(interval_list1[i][0], interval_list2[j][0]);
    int end_min = std::min(interval_list1[i][1], interval_list2[j][1]);
    if (start_max <= end_min) { intersections.push_back({start_max, end_min}); }
    // move the pointer with the smaller end
    if (interval_list1[i][1] < interval_list2[j][1]) {
      ++i;
    } else {
      ++j;
    }
  }
  return intersections;
}
