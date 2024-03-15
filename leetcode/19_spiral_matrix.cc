#include <iostream>
#include <vector>

#include "common.hpp"

std::vector<int> spiralOrder(std::vector<std::vector<int>> &matrix) {
  int left = 0, right = matrix[0].size() - 1, up = 0, down = matrix.size() - 1;
  std::vector<int> ret;
  while (left <= right && up <= down) {
    // 遍历当前行(第up行,从左到右), [left, right]
    for (int index = left; index <= right; ++index) {
      ret.push_back(matrix[up][index]);
    }
    ++up;
    // 遍历第right列,从上到下
    for (int index = up; index <= down; ++index) {
      ret.push_back(matrix[index][right]);
    }
    --right;
    // 遍历第down行,从右到左.
    // 此时循环只关注左右关系,并没有注意到上下关系(up已经发生变化)的限制,避免出现重复此时要判断上下关系是否合理
    if (up > down) {
      break;
    }
    for (int index = right; index >= left; --index) {
      ret.push_back(matrix[down][index]);
    }
    --down;
    // 遍历第left列,从下到上.
    // 此时循环只关注上下关系,并没有注意到左右关系(right已发生变化)的限制,避免出现重复此时要判断左右关系是否合理
    if (left > right) {
      break;
    }
    for (int index = down; index >= up; --index) {
      ret.push_back(matrix[index][left]);
    }
    ++left;
  }
  return ret;
}

int main() {
  std::vector<std::vector<int>> input = {
      {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  PrintComplexSeries(input);
  auto ret = spiralOrder(input);
  PrintSeries(ret);
  return 0;
}
