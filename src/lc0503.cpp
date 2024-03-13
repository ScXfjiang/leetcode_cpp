#include <vector>
#include <stack>

std::vector<int> nextGreaterElements(std::vector<int>& nums) {
  int n = nums.size();
  std::vector<int> result(n, -1);
  std::stack<int> stk;
  for (int i = 0; i < n * 2; ++i) {
    int num = nums[i % n];
    while (!stk.empty() && num > nums[stk.top()]) {
      result[stk.top()] = num;
      stk.pop();
    }
    if (i < n) { stk.push(i); }
  }
  return result;
}
