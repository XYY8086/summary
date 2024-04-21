#include <vector>

/// @brief 实际上就是查找第一个小于或等于target值的位置
int searchInsert(std::vector<int> &nums, int target) {
  int left = 0, right = nums.size() - 1;
  while (left <= right) {
    int mid = left + ((right - left) >> 1);
    if (target == nums[mid]) {
      return mid;
    }
    if (nums[mid] > target) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return left;
}
