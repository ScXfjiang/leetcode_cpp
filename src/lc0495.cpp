#include <vector>

// Solution - Greedy
int findPoisonedDuration(std::vector<int>& attacks, int duration) {
  int total_duration = 0;
  for (int i = 0; i < attacks.size() - 1; ++i) {
    int diff = attacks[i + 1] - attacks[i];
    total_duration += std::min(diff, duration);
  }
  total_duration += duration;
  return total_duration;
}

// Solution 2 - Greedy with Interval Merge
int findPoisonedDuration(std::vector<int>& attacks, int duration) {
  std::vector<std::vector<int>> intervals;
  for (int attack : attacks) { intervals.push_back({attack, attack + duration - 1}); }
  std::vector<std::vector<int>> merged;
  for (const auto& interval : intervals) {
    if (!merged.empty() && interval[0] <= merged.back()[1]) {
      merged.back()[1] = std::max(merged.back()[1], interval[1]);
    } else {
      merged.push_back(interval);
    }
  }
  int total_duration = 0;
  for (const auto& interval : merged) { total_duration += interval[1] - interval[0] + 1; }
  return total_duration;
}