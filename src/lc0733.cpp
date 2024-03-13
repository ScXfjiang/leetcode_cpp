#include <vector>

void dfs(std::vector<std::vector<int>>& image, int sr, int sc, int newColor, int oldColor) {
  if (sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size()
      || image[sr][sc] != oldColor) {
    return;
  }

  image[sr][sc] = newColor;

  // Flood fill in all 4 directions
  dfs(image, sr + 1, sc, newColor, oldColor);
  dfs(image, sr - 1, sc, newColor, oldColor);
  dfs(image, sr, sc + 1, newColor, oldColor);
  dfs(image, sr, sc - 1, newColor, oldColor);
}

std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image, int sr, int sc,
                                        int newColor) {
  int oldColor = image[sr][sc];
  if (oldColor
      != newColor) {  // Only fill if the new color is different to avoid infinite recursion
    dfs(image, sr, sc, newColor, oldColor);
  }
  return image;
}
