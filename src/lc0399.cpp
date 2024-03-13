#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <queue>

class Solution {
 public:
  // create directed graph
  // node: variable, e.g., x, y
  // directed edge, e.g., x->y is x / y
  void BuildGraph(std::vector<std::vector<std::string>>& equations, std::vector<double>& values) {
    for (int i = 0; i < equations.size(); ++i) {
      std::string x = equations[i][0];
      std::string y = equations[i][1];
      double val = values[i];
      graph[x][y] = val;
      graph[y][x] = 1.0 / val;
    }
  }

  // calculate answer for a single query
  double AnswerQuery(std::string start, std::string end, std::unordered_set<std::string>& visited) {
    if (start == end) { return 1.0; }
    visited.insert(start);
    for (auto& pair : graph[start]) {
      std::string next = pair.first;
      double value = pair.second;
      if (visited.find(next) == visited.end()) {
        double res = AnswerQuery(next, end, visited);
        if (res != -1.0) { return value * res; }
      }
    }
    return -1.0;
  }

  std::vector<double> calcEquation(std::vector<std::vector<std::string>>& equations,
                                   std::vector<double>& values,
                                   std::vector<std::vector<std::string>>& queries) {
    BuildGraph(equations, values);
    std::vector<double> answers;
    for (auto& query : queries) {
      std::string start = query[0];
      std::string end = query[1];
      if (graph.find(start) == graph.end() || graph.find(end) == graph.end()) {
        answers.push_back(-1.0);
      } else {
        std::unordered_set<std::string> visited;
        answers.push_back(AnswerQuery(start, end, visited));
      }
    }

    return answers;
  }

  std::unordered_map<std::string, std::unordered_map<std::string, double>> graph;
};
