#include <vector>

std::vector<int> getModifiedArray(int length, std::vector<std::vector<int>>& updates) {
  std::vector<int> arr(length, 0);
  for (const auto& update : updates) {
    int start_idx = update[0];
    int end_idx = update[1];
    int inc = update[2];
    arr[start_idx] += inc;
    if (end_idx + 1 < length) { arr[end_idx + 1] -= inc; }
  }
  for (int i = 1; i < length; ++i) { arr[i] += arr[i - 1]; }
  return arr;
}
