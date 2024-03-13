#include <vector>

// Solution 1 - Prefix Sum (size n + 1)
class NumArray {
 public:
  NumArray(std::vector<int>& nums) {
    prefix_sum_.resize(nums.size() + 1, 0);
    for (int i = 0; i < nums.size(); ++i) { prefix_sum_[i + 1] = prefix_sum_[i] + nums[i]; }
  }

  int sumRange(int left, int right) { return prefix_sum_[right + 1] - prefix_sum_[left]; }

  std::vector<int> prefix_sum_;
};

// Solution 2 - Prefix Sum (size n)
class NumArray {
 public:
  NumArray(std::vector<int>& nums) {
    prefix_sum_.resize(nums.size(), 0);
    for (int i = 0; i < nums.size(); ++i) {
      prefix_sum_[i] = (i == 0 ? 0 : prefix_sum_[i - 1]) + nums[i];
    }
  }

  int sumRange(int left, int right) {
    return prefix_sum_[right] - (left == 0 ? 0 : prefix_sum_[left - 1]);
  }

 private:
  std::vector<int> prefix_sum_;
};
