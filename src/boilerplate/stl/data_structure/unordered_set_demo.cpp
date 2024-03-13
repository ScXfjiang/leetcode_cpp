#include <unordered_set>
#include <iostream>

void InsertDemo() {
  std::unordered_set<int> nums = {0, 1, 2, 3, 4, 5};

  /* 1. insert */
  // insert 6, return pair<iterator, bool> indicating the insertion result
  auto res1 = nums.insert(6);
  std::cout << *res1.first << " " << res1.second << std::endl;  // 6 1

  // insert 6 again, return pair<iterator, bool> indicating the insertion result
  auto res2 = nums.insert(6);
  std::cout << *res2.first << " " << res2.second << std::endl;  // 6 0

  /* 2. emplace */
  // emplace 7, return pair<iterator, bool> indicating the insertion result
  auto res3 = nums.emplace(7);
  std::cout << *res3.first << " " << res3.second << std::endl;  // 7 1

  // emplace 7 again, return pair<iterator, bool> indicating the insertion result
  auto res4 = nums.emplace(7);
  std::cout << *res4.first << " " << res4.second << std::endl;  // 7 0
}

void EraseDemo() {
  std::unordered_set<int> nums = {0, 1, 2, 3, 4, 5};

  // 1. erase by iterator, return iterator to the next element
  for (auto it = nums.begin(); it != nums.end();) {
    if (*it % 2 == 0)
      it = nums.erase(it);
    else
      ++it;
  }

  // 2. erase by key, return the number of elements erased (0 or 1)
  int count = nums.erase(3);
  std::cout << count << std::endl;
  count = nums.erase(3);
  std::cout << count << std::endl;
}

void LookUpDemo() {
  std::unordered_set<int> nums = {0, 1, 2, 3, 4, 5};

  auto it1 = nums.find(3);
  if (it1 != nums.end()) {
    std::cout << *it1 << std::endl;
  } else {
    std::cout << "not found" << std::endl;
  }
}

int main() {
  InsertDemo();
  EraseDemo();
  LookUpDemo();
  return 0;
}