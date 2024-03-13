#include <vector>

int singleNumber(std::vector<int>& nums) {
  int single = 0;
  for (int i = 0; i < 32; i++) {
    int digit_cnt = 0;
    for (int num : nums) {
      if ((num >> i) & 1) { ++digit_cnt; }
    }
    if (digit_cnt % 3) { single |= (1 << i); }
  }
  return single;
}
