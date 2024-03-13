#include <vector>
#include <string>

bool exist(std::vector<std::vector<char>>& board, std::string word) {
  for (int i = 0; i < board.size(); ++i) {
    for (int j = 0; j < board[0].size(); ++j) {
      // Start the DFS from the first matching character
      if (board[i][j] == word[0] && dfs(board, word, i, j, 0)) { return true; }
    }
  }
  return false;
}

bool dfs(std::vector<std::vector<char>>& board, std::string& word, int i, int j, int wordIndex) {
  // Check the bounds and the matching of the current character
  if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()
      || board[i][j] != word[wordIndex]) {
    return false;
  }

  // If all characters are matched
  if (wordIndex == word.size() - 1) { return true; }

  // Mark the current cell as visited by changing its value
  char temp = board[i][j];
  board[i][j] = '#';  // '#' used to indicate this cell is visited

  // Explore all possible directions: up, down, left, right
  bool found =
      dfs(board, word, i + 1, j, wordIndex + 1) || dfs(board, word, i - 1, j, wordIndex + 1)
      || dfs(board, word, i, j + 1, wordIndex + 1) || dfs(board, word, i, j - 1, wordIndex + 1);

  // Unmark the current cell as visited to backtrack
  board[i][j] = temp;

  return found;
}
