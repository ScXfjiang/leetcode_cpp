#include <vector>
#include <cstdlib>

// Solution 1 - Binary Search
std::vector<int> findClosestElements(std::vector<int>& arr, int k, int x) {
  int left = 0;
  int right = arr.size() - k;
  while (left < right) {
    int mid = left + (right - left) / 2;
    if (x - arr[mid] > arr[mid + k] - x) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }
  return std::vector<int>(arr.begin() + left, arr.begin() + left + k);
}

// Solution 2 - Binary Search + Expand From Center
std::vector<int> findClosestElements(std::vector<int>& arr, int k, int x) {
  // binary search to find the closest element
  int left = 0;
  int right = arr.size() - 1;
  while (left < right) {
    int mid = left + (right - left) / 2;
    if (x <= arr[mid]) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  // expand outwards to find the k closest elements
  int low = left - 1;
  int high = left;
  while (k--) {
    if (low < 0 || (high < arr.size() && std::abs(arr[high] - x) < std::abs(arr[low] - x))) {
      ++high;
    } else {
      --low;
    }
  }
  return std::vector<int>(arr.begin() + low + 1, arr.begin() + high);
}