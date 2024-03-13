#include <stack>
#include <string>
#include <iostream>

void StackDemo() {
  std::stack<int> num_stk;
  std::stack<std::pair<int, std::string>> pair_stk;

  /* 1. push, void function */
  num_stk.push(1);
  num_stk.push(2);
  num_stk.push(3);
  num_stk.push(4);
  num_stk.push(5);

  /* 2. emplace, void function */
  pair_stk.emplace(1, "one");
  pair_stk.emplace(2, "two");
  pair_stk.emplace(3, "three");
  pair_stk.emplace(4, "four");
  pair_stk.emplace(5, "five");

  /* 3. top, return reference to the top element in the stack */
  /* 4. pop, void function */
  while (!num_stk.empty()) {
    auto x_ref = num_stk.top();
    std::cout << x_ref << " ";
    num_stk.pop();
  }
  // 5 4 3 2 1
}

int main() {
  StackDemo();
  return 0;
}
