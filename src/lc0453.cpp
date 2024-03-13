#include <vector>
#include <algorithm> x

int minMoves(std::vector<int>& nums) {
  int minimum = *std::min_element(nums.begin(), nums.end());
  int num_moves = 0;
  for (int num : nums) { num_moves += num - minimum; }
  return num_moves;
}
