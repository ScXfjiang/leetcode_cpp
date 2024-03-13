#include <vector>
#include <iostream>

void InsertionSort(std::vector<int>& nums) {
  for (int j = 1; j < nums.size(); ++j) {
    int insert_val = nums[j];
    int i = j - 1;
    while (i >= 0 && nums[i] > insert_val) {
      nums[i + 1] = nums[i];
      --i;
    }
    nums[i + 1] = insert_val;
  }
}

int main() {
  std::vector<int> nums = {12, 11, 13, 5, 6, 7};
  InsertionSort(nums);
  for (int num : nums) { std::cout << num << " "; }
  // 5 6 7 11 12 13
  return 0;
}
