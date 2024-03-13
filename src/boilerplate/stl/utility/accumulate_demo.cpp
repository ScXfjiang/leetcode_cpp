#include <numeric>
#include <functional>
#include <algorithm>
#include <vector>
#include <iostream>

int AccumulateDemo() {
  std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  // accumulate sum (default)
  int sum = std::accumulate(v.begin(), v.end(), 0);
  std::cout << sum << std::endl;  // 55

  // accumulate product
  int product = std::accumulate(v.begin(), v.end(), 1, std::multiplies<int>());
  std::cout << product << std::endl;  // 3628800

  // dash-separated string
  std::string str = std::accumulate(
      std::next(v.begin()), v.end(), std::to_string(v[0]),
      [](std::string a, int b) { return std::move(a) + '-' + std::to_string(b); });
  std::cout << str << std::endl;  // 1-2-3-4-5-6-7-8-9-10
}

int main() {
  AccumulateDemo();
  return 0;
}