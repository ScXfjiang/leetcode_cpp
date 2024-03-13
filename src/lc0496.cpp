#include <vector>
#include <stack>
#include <unordered_map>

std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2) {
  std::stack<int> stk;
  std::unordered_map<int, int> num2next_greater;
  for (int num : nums2) {
    while (!stk.empty() && num > stk.top()) {
      num2next_greater[stk.top()] = num;
      stk.pop();
    }
    stk.push(num);
  }
  std::vector<int> result;
  for (int num : nums1) {
    if (num2next_greater.find(num) != num2next_greater.end()) {
      result.push_back(num2next_greater[num]);
    } else {
      result.push_back(-1);
    }
  }
  return result;
}
