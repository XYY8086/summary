#include <vector>

class Solution {
public:
  std::vector<int> searchRange(std::vector<int> &nums, int target) {
    return {lower_bound_search(nums, target), upper_bound_search(nums, target)};
  }

  // 找到第一个值等于target的位置
  int lower_bound_search(std::vector<int> &nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] > target) {
        right = mid - 1;
      } else if (nums[mid] < target) {
        left = mid + 1;
      } else {
        // 当前位置等于target && 左边的值不等于target
        if (mid == 0 || nums[mid - 1] != target) {
          return mid;
        } else {
          right = mid - 1;
        }
      }
    }
    return -1;
  }

  int upper_bound_search(std::vector<int> &nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] > target) {
        right = mid - 1;
      } else if (nums[mid] < target) {
        left = mid + 1;
      } else {
        if (mid == nums.size() - 1 || nums[mid + 1] != target) {
          return mid;
        } else {
          left = mid + 1;
        }
      }
    }
    return -1;
  }
};