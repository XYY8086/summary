#include <vector>

void dfs(std::vector<std::vector<char>> &grid, int row, int col) {
  if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size()) {
    return;
  }
  if (grid[row][col] != '1') {
    return;
  }
  grid[row][col] = 0;
  dfs(grid, row + 1, col);
  dfs(grid, row - 1, col);
  dfs(grid, row, col + 1);
  dfs(grid, row, col - 1);
}

int numIslands(std::vector<std::vector<char>> &grid) {
  int ret = 0;
  for (int row = 0; row < grid.size(); ++row) {
    for (int col = 0; col < grid[0].size(); ++col) {
      if (grid[row][col] == '1') {
        ++ret;
        dfs(grid, row, col);
      }
    }
  }
}