#include <vector>
#include <string>

std::vector<std::string> summaryRanges(std::vector<int>& nums) {
  std::vector<std::string> ranges;
  if (nums.empty()) { return ranges; }
  for (int i = 0; i < nums.size(); ++i) {
    int start = nums[i];
    while (i + 1 < nums.size() && nums[i] + 1 == nums[i + 1]) { ++i; }
    if (start == nums[i]) {
      ranges.push_back(std::to_string(start));
    } else {
      ranges.push_back(std::to_string(start) + "->" + std::to_string(nums[i]));
    }
  }
  return ranges;
}
