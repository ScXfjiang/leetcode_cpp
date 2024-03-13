#include <stack>

class MyQueue {
 public:
  MyQueue() {}

  void push(int x) { in_stk.push(x); }

  int pop() {
    if (out_stk.empty()) { transfer(); }
    int front = out_stk.top();
    out_stk.pop();
    return front;
  }

  int peek() {  // std::queue::front()
    if (out_stk.empty()) { transfer(); }
    return out_stk.top();
  }

  bool empty() { return in_stk.empty() && out_stk.empty(); }

 private:
  std::stack<int> in_stk;
  std::stack<int> out_stk;

  // transfer elements from in_stk to out_stk
  void transfer() {
    while (!in_stk.empty()) {
      out_stk.push(in_stk.top());
      in_stk.pop();
    }
  }
};
