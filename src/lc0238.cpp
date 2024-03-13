#include <vector>

// Solution 1 - Prefix & Suffix Sum
std::vector<int> productExceptSelf(std::vector<int>& nums) {
  int n = nums.size();
  std::vector<int> prefix_prod(n + 1, 1);
  for (int i = 0; i < n; ++i) { prefix_prod[i + 1] = prefix_prod[i] * nums[i]; }
  std::vector<int> suffix_prod(n + 1, 1);
  for (int i = n - 1; i >= 0; --i) { suffix_prod[i] = suffix_prod[i + 1] * nums[i]; }
  std::vector<int> res(n);
  for (int i = 0; i < n; ++i) { res[i] = prefix_prod[i] * suffix_prod[i + 1]; }
  return res;
}

// Solution 1 - Prefix & Suffix Sum, Optimized 
std::vector<int> productExceptSelf(std::vector<int>& nums) {
  int n = nums.size();
  std::vector<int> prefix_prod(n, 1);
  std::vector<int> suffix_prod(n, 1);
  for (int i = 1; i < n; ++i) { prefix_prod[i] = prefix_prod[i - 1] * nums[i - 1]; }
  for (int i = n - 2; i >= 0; --i) { suffix_prod[i] = suffix_prod[i + 1] * nums[i + 1]; }
  std::vector<int> res(n);
  for (int i = 0; i < n; ++i) { res[i] = prefix_prod[i] * suffix_prod[i]; }
  return res;
}
