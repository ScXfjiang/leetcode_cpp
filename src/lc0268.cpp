#include <vector>

// Solution 1 - Bit manipulation
int missingNumber(const std::vector<int>& nums) {
  int xor_sum = 0;
  for (int i = 0; i <= nums.size(); ++i) { xor_sum ^= i; }
  for (int num : nums) { xor_sum ^= num; }
  return xor_sum;
}

// Solution 2 - Mathematical Formula
int missingNumber(std::vector<int>& nums) {
  int n = nums.size();
  int expected_sum = n * (n + 1) / 2;
  int actual_sum = 0;
  for (int num : nums) { actual_sum += num; }
  return expected_sum - actual_sum;
}
