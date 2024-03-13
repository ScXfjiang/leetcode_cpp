#include <vector>
#include <utility>
#include <iostream>

void HeapSort(std::vector<int>& nums) {
  int n = nums.size();
  for (int i = n / 2 - 1; i >= 0; --i) { Heapify(nums, n, i); }
  for (int i = n - 1; i > 0; --i) {
    std::swap(nums[0], nums[i]);
    Heapify(nums, i, 0);
  }
}

void Heapify(std::vector<int>& nums, int n, int i) {
  int largest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;
  if (l < n && nums[l] > nums[largest]) { largest = l; }
  if (r < n && nums[r] > nums[largest]) { largest = r; }
  if (largest != i) {
    std::swap(nums[i], nums[largest]);
    Heapify(nums, n, largest);
  }
}

int main() {
  std::vector<int> nums = {12, 11, 13, 5, 6, 7};
  HeapSort(nums);
  for (int num : nums) { std::cout << num << " "; }
  // 5 6 7 11 12 13
  return 0;
}
