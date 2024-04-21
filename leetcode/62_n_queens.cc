#include <algorithm>
#include <string>
#include <vector>

#include "common.hpp"

class Solution {
public:
  std::vector<std::vector<std::string>> solveNQueens(int n) {
    std::vector<std::string> queen(n, std::string(n, '.'));
    std::vector<int> path;
    solveNQueens(n, 0, queen, path);
    return ret;
  }

private:
  void solveNQueens(int total_n, int current, std::vector<std::string> &queen,
                    std::vector<int> &path) {
    // 最后一行成功放置,获取一条记录
    if (current == total_n) {
      ret.push_back(queen);
      return;
    }
    // 遍历当前行所有位置,依次遍历所有可能的位置
    std::string &row = queen[current];
    for (int index = 0; index < row.size(); ++index) {
      if (is_valid_pos(current, index, path)) {
        // 当前是可以放置的位置
        row[index] = 'Q';
        path.push_back(index);
        solveNQueens(total_n, current + 1, queen, path);
        path.pop_back();
        row[index] = '.';
      }
    }
  }

  bool is_valid_pos(int row, int col, const std::vector<int> &path) {
    // path的location实际就是行信息, 斜边上的位置满足 |row -m| = |col - n|
    for (int _row = 0; _row < path.size(); ++_row) {
      int _col = path[_row];
      if (_row == row || _col == col ||
          std::abs(row - _row) == std::abs(col - _col)) {
        return false;
      }
    }
    return true;
  }

  std::vector<std::vector<std::string>> ret;
};

int main() {
  auto ret = Solution{}.solveNQueens(4);
  PrintComplexSeries(ret);
  return 0;
}
