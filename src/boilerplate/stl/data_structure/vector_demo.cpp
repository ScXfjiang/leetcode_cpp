#include <vector>
#include <iostream>

void InsertDemo() {
  std::vector<int> nums = {0, 1, 2, 3, 4, 5};

  /* 1. push_back */
  nums.push_back(6);

  /* 2. emplace_back */
  nums.emplace_back(7);

  /* 3. insert */
  // insert 8 before iterator pos, return iterator to the inserted element
  auto pos = nums.begin() + 1;
  auto it1 = nums.insert(pos, 8);
  std::cout << *it1 << std::endl;  // 8

  // insert 3 9s before iterator pos, return iterator to the first inserted element
  pos = nums.begin() + 1;
  auto it2 = nums.insert(pos, 3, 9);
  std::cout << *it2 << std::endl;  // 9

  // insert {10, 11, 12} before iterator pos, return iterator to the first inserted element
  pos = nums.begin() + 1;
  auto it3 = nums.insert(pos, {10, 11, 12});
  std::cout << *it3 << std::endl;  // 10

  // insert subvector before iterator pos, return iterator to the first inserted
  pos = nums.begin() + 1;
  std::vector<int> nums2 = {12, 13, 14, 15, 16};
  auto it4 = nums.insert(pos, nums2.begin() + 1, nums2.begin() + 4);
  std::cout << *it4 << std::endl;  // 13

  for (auto& num : nums) { std::cout << num << " "; }
  std::cout << std::endl;
  // 0 13 14 15 10 11 12 9 9 9 8 1 2 3 4 5 6 7
}

void EraseDemo() {
  std::vector<int> nums = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  // 1. erase by iterator, return iterator to the next element
  auto pos = nums.begin() + 1;
  auto it1 = nums.erase(pos);
  std::cout << *it1 << std::endl;  // 2

  // 2. erase by range, return iterator to the next element
  auto it2 = nums.erase(nums.begin(), nums.begin() + 3);
  std::cout << *it2 << std::endl;  // 4

  // 3. pop the last element, void function
  nums.pop_back();

  for (auto& num : nums) { std::cout << num << " "; }
  std::cout << std::endl;
  // 4 5 6 7 8 9
}

void ElementAccessDemo() {
  std::vector<int> nums = {0, 1, 2, 3, 4, 5};

  /* 1. operator [] */
  // element exists
  // return reference to the element
  int num1 = nums[0];
  // element does not exist
  // undefined behavior
  int num6 = nums[6];

  /* 2. at() */
  // element exists
  // return reference to the element
  int num2 = nums.at(2);
  // element does not exist
  // throw std::out_of_range
  int num7 = nums.at(7);

  // front
  std::cout << nums.front() << std::endl;  // 0

  // back
  std::cout << nums.back() << std::endl;  // 5
}

void LookUpDemo() {
  std::vector<int> nums = {0, 1, 2, 3, 4, 5};
  auto it = std::find(nums.begin(), nums.end(), 1);
  if (it != nums.end()) {
    std::cout << *it << std::endl;
  } else {
    std::cout << "not found" << std::endl;
  }
}

int main() {
  InsertDemo();
  EraseDemo();
  ElementAccessDemo();
  LookUpDemo();
  return 0;
}