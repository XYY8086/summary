#include <algorithm>
#include <iostream>
#include <vector>

bool searchMatrix(std::vector<std::vector<int>> &matrix, int target) {
  int row = matrix.size(), col = matrix[0].size();
  int current_row = 0, current_col = col - 1;
  while (current_row < row && current_col >= 0) {
    if (matrix[current_row][current_col] == target) {
      return true;
    }
    if (matrix[current_row][current_col] > target) {
      --current_col;
    } else {
      ++current_row;
    }
  }
  return false;
}

int main() { return 0; }