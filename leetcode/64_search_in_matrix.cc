
#include <vector>

bool searchMatrix(std::vector<std::vector<int>> &matrix, int target) {
  if (matrix.empty()) {
    return false;
  }
  int row = matrix.size(), col = matrix[0].size();
  // m * col + n = pos, 已知pos col的情况下, m = pos / col , n = pos % col
  int sum = row * col;
  int left = 0, right = sum - 1;
  while (left <= right) {
    int mid = (left + right) / 2;
    if (matrix[mid / col][mid % col] == target) {
      return true;
    }
    if (matrix[mid / col][mid % col] > target) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return false;
}