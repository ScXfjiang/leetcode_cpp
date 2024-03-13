#include <vector>
#include <iostream>

void QuickSort(std::vector<int>& nums) { QuickSortRecursive(nums, 0, nums.size() - 1); }

void QuickSortRecursive(std::vector<int>& nums, int start, int end) {
  if (start >= end) { return; }
  int pivot_idx = Partition(nums, start, end);
  QuickSortRecursive(nums, start, pivot_idx - 1);
  QuickSortRecursive(nums, pivot_idx + 1, end);
}

int Partition(std::vector<int>& nums, int start, int end) {
  int pivot = nums[end];
  int i = start - 1;
  for (int j = start; j < end; ++j) {
    if (nums[j] <= pivot) {
      ++i;
      std::swap(nums[i], nums[j]);
    }
  }
  std::swap(nums[i + 1], nums[end]);
  return i + 1;
}

int main() {
  std::vector<int> nums = {12, 11, 13, 5, 6, 7};
  QuickSort(nums);
  for (int num : nums) { std::cout << num << " "; }
  // 5 6 7 11 12 13
  return 0;
}
