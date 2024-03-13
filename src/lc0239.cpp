#include <vector>
#include <deque>

// Solution 1 - Brute Force
std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
  std::vector<int> max_elements;
  for (int i = 0; i < nums.size() - k + 1; ++i) {
    int maximum = std::numeric_limits<int>::min();
    for (int j = i; j < i + k; ++j) { maximum = std::max(maximum, nums[j]); }
    max_elements.push_back(maximum);
  }
  return max_elements;
}

// Solution 2 - Deque
std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
  std::vector<int> max_elements;
  std::deque<int> window;
  for (int i = 0; i < nums.size(); ++i) {
    // Remove the indices that are out of the current window
    while (!window.empty() && window.front() <= i - k) { window.pop_front(); }

    // Remove indices from the back that are less than the current element
    while (!window.empty() && nums[i] >= nums[window.back()]) { window.pop_back(); }

    // Add the current index to the deque
    window.push_back(i);

    // If we've hit k elements, add the front of the deque to the result, as it's the max
    if (i >= k - 1) { max_elements.push_back(nums[window.front()]); }
  }

  return max_elements;
}
