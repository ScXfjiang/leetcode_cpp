#include <vector>
#include <unordered_map>

int findMaxLength(std::vector<int>& nums) {
  std::unordered_map<int, int> acc_sum2idx;
  int max_len = 0;
  int acc_sum = 0;
  acc_sum2idx[0] = -1;
  for (int i = 0; i < nums.size(); i++) {
    acc_sum += (nums[i] == 0) ? -1 : 1;
    if (acc_sum2idx.find(acc_sum) != acc_sum2idx.end()) {
      max_len = std::max(max_len, i - acc_sum2idx[acc_sum]);
    } else {  // store the earliest index for each acc_sum
      acc_sum2idx[acc_sum] = i;
    }
  }
  return max_len;
}
