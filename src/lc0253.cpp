#include <vector>
#include <queue>
#include <algorithm>

int minMeetingRooms(std::vector<std::vector<int>>& intervals) {
  std::sort(intervals.begin(), intervals.end(),
            [](const std::vector<int>& lhs, const std::vector<int>& rhs) {
              return lhs[0] < rhs[0];
            });
  std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
  min_heap.push(intervals[0][1]);
  for (int i = 1; i < intervals.size(); ++i) {
    if (intervals[i][0] >= min_heap.top()) { min_heap.pop(); }
    min_heap.push(intervals[i][1]);
  }
  return min_heap.size();
}
