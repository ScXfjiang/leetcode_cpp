#include <vector>

// Solution 1 - Prefix Sum (Time Limit Exceeded)
int subarraySum(std::vector<int>& nums, int target) {
  std::vector<int> prefix_sum(nums.size() + 1, 0);
  for (int i = 1; i <= nums.size(); ++i) { prefix_sum[i] = prefix_sum[i - 1] + nums[i - 1]; }
  int num_subarray = 0;
  for (int i = 0; i < nums.size(); ++i) {
    for (int j = i + 1; j <= nums.size(); ++j) {
      if (prefix_sum[j] - prefix_sum[i] == target) { ++num_subarray; }
    }
  }
  return num_subarray;
}

// Solution 2 - Prefix Sum + Hash Map
int subarraySum(std::vector<int>& nums, int target) {
  std::unordered_map<int, int> acc_sum2freq;
  int num_subarray = 0;
  int acc_sum = 0;
  acc_sum2freq[0] = 1;
  for (int num : nums) {
    acc_sum += num;
    if (acc_sum2freq.find(acc_sum - target) != acc_sum2freq.end()) {
      num_subarray += acc_sum2freq[acc_sum - target];
    }
    ++acc_sum2freq[acc_sum];
  }
  return num_subarray;
}
