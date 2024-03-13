#include <vector>
#include <unordered_map>

// Solution 1 - Prefix Sum (Time Limit Exceeded)
bool checkSubarraySum(std::vector<int>& nums, int target) {
  std::vector<int> prefix_sum(nums.size() + 1, 0);
  for (int i = 1; i <= nums.size(); ++i) { prefix_sum[i] = prefix_sum[i - 1] + nums[i - 1]; }
  for (int i = 0; i < nums.size() - 1; ++i) {
    for (int j = i + 2; j <= nums.size(); ++j) {
      if ((prefix_sum[j] - prefix_sum[i]) % target == 0) { return true; }
    }
  }
  return false;
}

// Solution 2 - Prefix Sum + Hash Map
bool checkSubarraySum(std::vector<int>& nums, int target) {
  std::unordered_map<int, int> acc_rem2idx;
  int acc_sum = 0;
  acc_rem2idx[0] = -1;
  for (int i = 0; i < nums.size(); ++i) {
    acc_sum += nums[i];
    int acc_rem = acc_sum % target;
    if (acc_rem2idx.find(acc_rem) != acc_rem2idx.end()) {
      if (i - acc_rem2idx[acc_rem] >= 2) { return true; }
    } else {  // store the earliest index for each remainder
      acc_rem2idx[acc_rem] = i;
    }
  }
  return false;
}
