#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <limits>

std::vector<std::vector<std::string>> findLadders(std::string beginWord, std::string endWord,
                                                  std::vector<std::string>& wordList) {
  std::unordered_set<std::string> dict(wordList.begin(), wordList.end());
  std::vector<std::vector<std::string>> result;
  std::queue<std::vector<std::string>> paths;
  paths.push({beginWord});

  // To keep track of the minimum level where we found endWord
  int level = 1, minLevel = std::numeric_limits<int>::max();

  // To keep track of words that are already visited in this level
  std::unordered_set<std::string> visited;

  while (!paths.empty()) {
    std::vector<std::string> path = paths.front();
    paths.pop();
    if (path.size() > level) {
      // Remove all last level's words from the dict
      for (std::string w : visited) dict.erase(w);
      visited.clear();
      level = path.size();
      if (level > minLevel) break;  // If we have already found the shortest paths
    }

    std::string last = path.back();
    for (int i = 0; i < last.size(); ++i) {
      std::string newLast = last;
      for (char ch = 'a'; ch <= 'z'; ++ch) {
        newLast[i] = ch;
        if (!dict.count(newLast)) continue;
        visited.insert(newLast);
        std::vector<std::string> newPath = path;
        newPath.push_back(newLast);
        if (newLast == endWord) {
          minLevel = level;
          result.push_back(newPath);
        } else {
          paths.push(newPath);
        }
      }
    }
  }
  return result;
}
