#include <vector>

int majorityElement(std::vector<int>& nums) {
  int candidate = 0;
  int count = 0;
  for (auto num : nums) {
    if (count == 0) { candidate = num; }
    count += (num == candidate) ? 1 : -1;
  }
  return candidate;
}
