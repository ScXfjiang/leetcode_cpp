#include <vector>

bool canAttendMeetings(std::vector<std::vector<int>>& intervals) {
  std::sort(intervals.begin(), intervals.end(),
            [](const std::vector<int>& lhs, const std::vector<int>& rhs) {
              return lhs[0] < rhs[0];
            });
  for (int i = 1; i < intervals.size(); ++i) {
    if (intervals[i][0] < intervals[i - 1][1]) { return false; }
  }
  return true;
}
