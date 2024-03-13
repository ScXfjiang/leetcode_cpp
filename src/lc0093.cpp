#include <string>
#include <vector>

std::vector<std::string> restoreIpAddresses(std::string s) {
  std::vector<std::string> solutions;
  std::string ip;
  Backtracking(s, 0, 0, ip, solutions);
  return solutions;
}

void Backtracking(const std::string& s, int start, int num_part, std::string& ip,
                  std::vector<std::string>& solutions) {
  // valid solution (base case)
  if (num_part == 4 && start == s.size()) { solutions.push_back(ip); }

  // pruning
  if (num_part >= 4) { return; }

  for (int len = 1; len <= 3; ++len) {
    // pruning
    if (start + len > s.size()) { break; }

    // get the current part
    std::string part = s.substr(start, len);

    // pruning
    if ((part[0] == '0' && part.size() > 1) || (len == 3 && std::stoi(part) > 255)) { continue; }

    ip += part;
    if (num_part < 3) ip += '.';
    Backtracking(s, start + len, num_part + 1, ip, solutions);
    ip.erase(ip.end() - len, ip.end());
    if (num_part < 3) ip.pop_back();
  }
}
