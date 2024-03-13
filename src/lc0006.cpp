#include <vector>
#include <string>

std::string convert(std::string s, int numRows) {
  if (numRows == 1) { return s; }
  std::vector<std::string> rows(std::min(numRows, int(s.size())));
  int cur_row = 0;
  bool go_down = false;
  for (char c : s) {
    rows[cur_row] += c;
    if (cur_row == 0 || cur_row == numRows - 1) { go_down = !go_down; }
    cur_row += go_down ? 1 : -1;
  }
  std::string converted;
  for (std::string row : rows) { converted += row; }
  return converted;
}
