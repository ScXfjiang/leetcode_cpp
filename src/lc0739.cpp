#include <vector>
#include <stack>

std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
  std::vector<int> num_days(temperatures.size(), 0);
  std::stack<int> stk;
  for (int i = 0; i < temperatures.size(); ++i) {
    while (!stk.empty() && temperatures[i] > temperatures[stk.top()]) {
      int top = stk.top();
      stk.pop();
      num_days[top] = i - top;
    }
    stk.push(i);
  }
  return num_days;
}
