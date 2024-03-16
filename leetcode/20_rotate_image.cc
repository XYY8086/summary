#include <algorithm>
#include <iostream>
#include <vector>

#include "common.hpp"
void rotate(std::vector<std::vector<int>> &matrix) {
  int n = matrix.size(); // 方阵
  // 一圈一圈的遍历，每次遍历一层,矩阵宽度就 -2,所以总共需要遍历 n/2层
  for (int current_row = 0; current_row < n / 2; ++current_row) {
    // 当前这一圈需要交换多少个元素,实际为当前的宽度-1
    for (int current_col = current_row; current_col < n - current_row - 1;
         ++current_col) {
      // 交换四个点的位置
      int tmp = matrix[current_row][current_col];
      matrix[current_row][current_col] =
          matrix[n - current_col - 1][current_row];
      matrix[n - current_col - 1][current_row] =
          matrix[n - current_row - 1][n - current_col - 1];
      matrix[n - current_row - 1][n - current_col - 1] =
          matrix[current_col][n - current_row - 1];
      // matrix[current_col][n - current_row - 1] =
      // matrix[current_row][current_col];
      matrix[current_col][n - current_row - 1] = tmp;
    }
  }
}

int main() {
  std::vector<std::vector<int>> input{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  PrintComplexSeries(input);
  rotate(input);
  PrintComplexSeries(input);
  return 0;
}