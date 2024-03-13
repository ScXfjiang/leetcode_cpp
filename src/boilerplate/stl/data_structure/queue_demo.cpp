#include <queue>
#include <string>
#include <iostream>

void QueueDemo() {
  std::queue<int> num_que;
  std::queue<std::pair<int, std::string>> pair_que;

  /* 1. push, void function */
  num_que.push(1);
  num_que.push(2);
  num_que.push(3);
  num_que.push(4);
  num_que.push(5);

  /* 2. emplace, void function */
  pair_que.emplace(1, "one");
  pair_que.emplace(2, "two");
  pair_que.emplace(3, "three");
  pair_que.emplace(4, "four");
  pair_que.emplace(5, "five");

  /* 3. front, return reference to the front element in the queue */
  /* 4. back, return reference to the back element in the queue */
  /* 5. pop, void function */
  while (!num_que.empty()) {
    auto x_ref = num_que.front();
    std::cout << x_ref << " ";
    num_que.pop();
  }
  // 1 2 3 4 5
}

int main() {
  QueueDemo();
  return 0;
}