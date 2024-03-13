#include <vector>
#include <stack>
#include <algorithm>

// Solution 1 - Brute Force (Time Limit Exceeded)
int trap(std::vector<int>& heights) {
  int trapped_water = 0;
  for (int i = 1; i < heights.size() - 1; ++i) {
    int left_max_h = *std::max_element(heights.begin(), heights.begin() + i);
    int right_max_h = *std::max_element(heights.begin() + i + 1, heights.end());
    int height = std::min(left_max_h, right_max_h) - heights[i];
    trapped_water += height > 0 ? height : 0;
  }
  return trapped_water;
}

// Solution 1 - Brute Force, Optimized 1
int trap(std::vector<int>& heights) {
  if (heights.size() <= 2) { return 0; }
  int n = heights.size();
  std::vector<int> max_left_height(n, 0);
  std::vector<int> max_right_height(n, 0);
  max_left_height[0] = heights[0];
  for (int i = 1; i < n; ++i) {
    max_left_height[i] = std::max(heights[i], max_left_height[i - 1]);
  }
  max_right_height[n - 1] = heights[n - 1];
  for (int i = n - 2; i >= 0; --i) {
    max_right_height[i] = std::max(heights[i], max_right_height[i + 1]);
  }
  int trapped_water = 0;
  for (int i = 0; i < n; i++) {
    int height = std::min(max_left_height[i], max_right_height[i]) - heights[i];
    if (height > 0) { trapped_water += height; }
  }
  return trapped_water;
}

// Solution 1 - Brute Force, Optimized 2
int trap(std::vector<int>& heights) {
  int left_max_h = 0;
  int right_max_h = 0;
  int trapped_water = 0;
  int left = 0;
  int right = heights.size() - 1;
  while (left < right) {
    left_max_h = std::max(left_max_h, heights[left]);
    right_max_h = std::max(right_max_h, heights[right]);
    if (left_max_h < right_max_h) {
      trapped_water += left_max_h - heights[left];
      left++;
    } else {
      trapped_water += right_max_h - heights[right];
      right--;
    }
  }
  return trapped_water;
}

// Solution 2 - Monotonic Stack
int trap(std::vector<int>& heights) {
  std::stack<int> stk;
  int trapped_water = 0;
  int i = 0;
  while (i < heights.size()) {
    while (!stk.empty() && heights[i] > heights[stk.top()]) {
      int top = stk.top();
      stk.pop();
      if (stk.empty()) { break; }
      int width = i - stk.top() - 1;
      int height = std::min(heights[i], heights[stk.top()]) - heights[top];
      trapped_water += width * height;
    }
    stk.push(i);
    ++i;
  }
  return trapped_water;
}
