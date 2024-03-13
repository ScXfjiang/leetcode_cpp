#include <deque>
#include <iostream>

void DequeDemo() {
  std::deque<int> num_deque;
  std::deque<std::pair<int, std::string>> pair_deque;

  /* 1. push_back, push_front, void function */
  num_deque.push_back(1);
  num_deque.push_back(2);
  num_deque.push_back(3);
  num_deque.push_front(4);
  num_deque.push_front(5);
  num_deque.push_front(6);

  /* 2. emplace_back, emplace_front, void function */
  pair_deque.emplace_back(1, "one");
  pair_deque.emplace_back(2, "two");
  pair_deque.emplace_back(3, "three");
  pair_deque.emplace_front(4, "four");
  pair_deque.emplace_front(5, "five");
  pair_deque.emplace_front(6, "six");

  /* 3. front, return reference to the front element in the deque */
  /* 4. back, return reference to the back element in the deque */
  /* 5. pop_front, pop_back, void function */
  while (!num_deque.empty()) {
    auto x_ref = num_deque.front();
    std::cout << x_ref << " ";
    num_deque.pop_front();
  }
  // 6 5 4 1 2 3
  while (!pair_deque.empty()) {
    auto x_ref = pair_deque.back();
    std::cout << x_ref.first << " " << x_ref.second << " ";
    pair_deque.pop_back();
  }
  // 3 three 2 two 1 one 4 four 5 five 6 six
}
