#include <iostream>
#include <vector>

#include "common.hpp"

void setZeroes1(std::vector<std::vector<int>> &matrix) {
  if (matrix.empty()) {
    return;
  }
  // 标记哪些行和哪些列存在0元素，空间复杂度O(m+n),时间复杂度O(m*n)
  std::vector<bool> row_flags(matrix.size(), false);
  std::vector<bool> col_flags(matrix[0].size(), false);

  for (int row = 0; row < matrix.size(); ++row) {
    for (int col = 0; col < matrix[0].size(); ++col) {
      row_flags[row] = row_flags[row] || (matrix[row][col] == 0);
      col_flags[col] = col_flags[col] || (matrix[row][col] == 0);
    }
  }

  for (int row = 0; row < matrix.size(); ++row) {
    for (int col = 0; col < matrix[0].size(); ++col) {
      // 该元素所在的行或者列存在0元素,则该元素置零
      if (row_flags[row] || col_flags[col]) {
        matrix[row][col] = 0;
      }
    }
  }
}

void setZeroes(std::vector<std::vector<int>> &matrix) {
  if (matrix.empty()) {
    return;
  }
  // 我们能否把标记数组放到原矩阵中？
  // 由于后续第一行和第一列需要存储标记位,最后无法确定第一行，第一列本身是否包含0,所以这项信息需要存储下来
  bool set_row = false, set_col = false;
  // 遍历第一列
  for (int index = 0; index < matrix.size(); ++index) {
    if (matrix[index][0] == 0) {
      set_col = true;
      break;
    }
  }
  // 遍历第一行
  for (int index = 0; index < matrix[0].size(); ++index) {
    if (matrix[0][index] == 0) {
      set_row = true;
      break;
    }
  }

  // 遍历除去标记行列的其他位置,设置标记位
  for (int row = 1; row < matrix.size(); ++row) {
    for (int col = 1; col < matrix[0].size(); ++col) {
      if (matrix[row][col] == 0) {
        matrix[0][col] = 0; // 存储哪些列有0
        matrix[row][0] = 0; // 存储哪些行有0
      }
    }
  }

  for (int row = 1; row < matrix.size(); ++row) {
    for (int col = 1; col < matrix[0].size(); ++col) {
      // 该元素所在的行或者列存在0元素,则该元素置零
      if (matrix[row][0] == 0 || matrix[0][col] == 0) {
        matrix[row][col] = 0;
      }
    }
  }
  // 判断第一列
  if (set_col) {
    for (int index = 0; index < matrix.size(); ++index) {
      matrix[index][0] = 0;
    }
  }
  // 判断第一行
  if (set_row) {
    for (int index = 0; index < matrix[0].size(); ++index) {
      matrix[0][index] = 0;
    }
  }
}

int main() {
  std::vector<std::vector<int>> input = {
      {0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
  PrintComplexSeries(input);
  setZeroes(input);
  PrintComplexSeries(input);
  return 0;
}
