#include <vector>
#include <algorithm>

int maxArea(std::vector<int>& height) {
  int max_water = 0;
  int left = 0;
  int right = height.size() - 1;
  while (left < right) {
    int water_height = std::min(height[left], height[right]);
    int water_width = right - left;
    max_water = std::max(max_water, water_height * water_width);
    // move the pointer of the shorter line inward
    if (height[left] < height[right]) {
      left++;
    } else {
      right--;
    }
  }
  return max_water;
}
