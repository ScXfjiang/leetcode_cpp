#include <vector>
#include <stack>

int largestRectangleArea(std::vector<int>& heights) {
  std::stack<int> s;
  int max_area = 0;
  for (int i = 0; i <= heights.size(); ++i) {
    int h = (i == heights.size() ? 0 : heights[i]);
    if (s.empty() || h >= heights[s.top()]) {
      s.push(i);
    } else {
      int tp = s.top();
      s.pop();
      int width = s.empty() ? i : i - s.top() - 1;
      max_area = std::max(max_area, heights[tp] * width);
      i--;
    }
  }
  return max_area;
}
