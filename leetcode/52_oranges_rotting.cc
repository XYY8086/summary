#include <iostream>
#include <queue>
#include <utility>
#include <vector>

bool change(std::vector<std::vector<int>> &grid, int row, int col) {
  if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size()) {
    return false;
  }
  if (grid[row][col] != 1) {
    return false;
  }
  grid[row][col] = 2;
  return true;
}

int orangesRotting(std::vector<std::vector<int>> &grid) {
  if (grid.empty()) {
    return 0;
  }
  std::deque<std::pair<int, int>> q; // 存储腐烂橘子的位置
  int fresh_num = 0;                 // 存储新鲜橘子的数量
  for (int row = 0; row < grid.size(); ++row) {
    for (int col = 0; col < grid[0].size(); ++col) {
      if (grid[row][col] == 1) {
        ++fresh_num;
      } else if (grid[row][col] == 2) {
        q.push_back({row, col});
      }
    }
  }
  // 当前已经没有新鲜的橘子，直接返回。(这一步容易遗漏)
  if (fresh_num == 0) {
    return 0;
  }

  int res = 0;
  while (!q.empty()) {
    int nums = q.size();
    ++res;
    for (int i = 0; i < nums; ++i) {
      auto locations = q.front();
      q.pop_front();
      // 对这个腐烂的位置进行传播
      if (change(grid, locations.first + 1, locations.second)) {
        --fresh_num;
        q.push_back({locations.first + 1, locations.second});
      }
      if (change(grid, locations.first - 1, locations.second)) {
        --fresh_num;
        q.push_back({locations.first - 1, locations.second});
      }
      if (change(grid, locations.first, locations.second + 1)) {
        --fresh_num;
        q.push_back({locations.first, locations.second + 1});
      }
      if (change(grid, locations.first, locations.second - 1)) {
        --fresh_num;
        q.push_back({locations.first, locations.second - 1});
      }
    }
  }
  return fresh_num == 0 ? res - 1 : -1;
}

int main() {
  std::vector<std::vector<int>> vec{{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};

  std::cout << orangesRotting(vec) << std::endl;
  return 0;
}
