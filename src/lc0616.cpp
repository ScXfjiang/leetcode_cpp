#include <vector>
#include <string>

std::string addBoldTag(std::string s, std::vector<std::string>& words) {
  std::vector<std::pair<int, int>> intervals;
  // 1. create intervals for all words
  for (const std::string& word : words) {
    size_t pos = s.find(word);
    while (pos != std::string::npos) {
      intervals.emplace_back(pos, pos + word.size());
      pos = s.find(word, pos + 1);
    }
  }
  // 2. merge intervals
  std::vector<std::pair<int, int>> merged;
  std::sort(intervals.begin(), intervals.end(),
            [](const auto& lhs, const auto& rhs) { return lhs.first < rhs.first; });
  for (const auto& interval : intervals) {
    if (!merged.empty() && interval.first <= merged.back().second) {
      merged.back().second = std::max(merged.back().second, interval.second);
    } else {
      merged.push_back(interval);
    }
  }
  // add bold tags
  std::string result;
  size_t i = 0;
  for (const auto& interval : merged) {
    result += s.substr(i, interval.first - i);
    result += "<b>";
    result += s.substr(interval.first, interval.second - interval.first);
    result += "</b>";
    i = interval.second;
  }
  result += s.substr(i);
  return result;
}
