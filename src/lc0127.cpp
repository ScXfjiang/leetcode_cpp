#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>

int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList) {
  std::unordered_set<std::string> dict(wordList.begin(), wordList.end());
  // edge case - endWord not in dict
  if (dict.find(endWord) == dict.end()) { return 0; }

  std::queue<std::pair<std::string, int>> toVisit;
  toVisit.push({beginWord, 1});

  while (!toVisit.empty()) {
    auto [word, steps] = toVisit.front();
    toVisit.pop();

    if (word == endWord) { return steps; }

    dict.erase(word);

    for (int i = 0; i < word.length(); i++) {
      char letter = word[i];
      for (int k = 0; k < 26; k++) {
        word[i] = 'a' + k;
        if (dict.find(word) != dict.end()) { toVisit.push({word, steps + 1}); }
      }
      word[i] = letter;
    }
  }

  return 0;
}
