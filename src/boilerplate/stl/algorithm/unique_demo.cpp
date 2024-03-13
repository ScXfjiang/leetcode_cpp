#include <algorithm>
#include <iostream>

void unique_demo() {
  std::vector<int> nums = {2, 2, 1, 1, 3, 3, 4, 4};
  auto it = std::unique(nums.begin(), nums.end());
  nums.erase(it, nums.end());
  for (int num : nums) { std::cout << num << " "; }
  // 2 1 3 4
}

int main() {
  unique_demo();
  return 0;
}