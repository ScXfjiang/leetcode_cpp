#include <vector>
#include <numeric>
#include <iostream>

int PartialSumDemo() {
  std::vector<int> nums(10, 2);

  // partial sum
  std::vector<int> prefix_sum(nums.size());
  std::partial_sum(nums.begin(), nums.end(), prefix_sum.begin());
  for (int num : prefix_sum) { std::cout << num << ' '; }
  std::cout << std::endl;

  // partial product
  std::vector<int> prefix_product(nums.size());
  std::partial_sum(nums.begin(), nums.end(), prefix_product.begin(), std::multiplies<int>());
  for (int num : prefix_product) { std::cout << num << ' '; }
  std::cout << std::endl;
}

int main() { PartialSumDemo(); }
