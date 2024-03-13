#include <vector>
#include <iostream>

void MergeSort(std::vector<int>& nums) {
  MergeSortRecursive(nums, 0, nums.size() - 1);
}

void MergeSortRecursive(std::vector<int>& nums, int start, int end) {
  if (start >= end) { return; }
  int mid = start + (end - start) / 2;
  MergeSortRecursive(nums, start, mid);
  MergeSortRecursive(nums, mid + 1, end);
  Merge(nums, start, mid, end);
}

void Merge(std::vector<int>& nums, int start, int mid, int end) {
  std::vector<int> tmp(end - start + 1);
  int i = start;
  int j = mid + 1;
  int k = 0;
  while (i <= mid && j <= end) {
    if (nums[i] < nums[j]) {
      tmp[k++] = nums[i++];
    } else {
      tmp[k++] = nums[j++];
    }
  }
  while (i <= mid) { tmp[k++] = nums[i++]; }
  while (j <= end) { tmp[k++] = nums[j++]; }
  for (int i = 0; i < tmp.size(); ++i) { nums[start + i] = tmp[i]; }
}

int main() {
  std::vector<int> nums = {12, 11, 13, 5, 6, 7};
  MergeSort(nums);
  for (int num : nums) { std::cout << num << " "; }
  // 5 6 7 11 12 13
  return 0;
}
