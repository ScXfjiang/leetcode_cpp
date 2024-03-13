#include <queue>
#include <string>
#include <iostream>

int BuiltInTypeDemo() {
  std::priority_queue<int> max_heap;
  max_heap.push(3);
  max_heap.push(5);
  max_heap.push(1);
  max_heap.push(2);
  max_heap.push(4);
  while (!max_heap.empty()) {
    std::cout << max_heap.top() << " ";
    max_heap.pop();
  }
  std::cout << std::endl;  // 5 4 3 2 1

  std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
  min_heap.push(3);
  min_heap.push(5);
  min_heap.push(1);
  min_heap.push(2);
  min_heap.push(4);
  while (!min_heap.empty()) {
    std::cout << min_heap.top() << " ";
    min_heap.pop();
  }
  std::cout << std::endl;  // 1 2 3 4 5

  return 0;
}

class Compare {
 public:
  bool operator()(const std::pair<char, int>& lhs, const std::pair<char, int>& rhs) {
    return lhs.second > rhs.second;
  }
};

int CustomizedTypeDemo() {
  /* 1. use a functor to define the comparison function */
  std::priority_queue<std::pair<char, int>, std::vector<std::pair<char, int>>, Compare>
      min_heap;
  min_heap.push({'a', 3});
  min_heap.push({'b', 5});
  min_heap.push({'c', 1});
  min_heap.push({'d', 2});
  min_heap.push({'e', 4});
  while (!min_heap.empty()) {
    std::cout << min_heap.top().first << " ";
    min_heap.pop();
  }
  std::cout << std::endl;  // c d a e b

  /* 2. use lambda function to define the comparison function */
  auto compare = [](const std::pair<char, int>& lhs, const std::pair<char, int>& rhs) {
    return lhs.second < rhs.second;
  };
  std::priority_queue<std::pair<char, int>, std::vector<std::pair<char, int>>,
                      decltype(compare)>
      max_heap(compare);
  max_heap.push({'a', 3});
  max_heap.push({'b', 5});
  max_heap.push({'c', 1});
  max_heap.push({'d', 2});
  max_heap.push({'e', 4});
  while (!max_heap.empty()) {
    std::cout << max_heap.top().first << " ";
    max_heap.pop();
  }
  std::cout << std::endl;  // b e a d c

  return 0;
}

int main() {
  BuiltInTypeDemo();
  CustomizedTypeDemo();
  return 0;
}