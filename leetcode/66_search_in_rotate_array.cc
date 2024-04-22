#include <iostream>
#include <vector>

int search(std::vector<int> &nums, int target) {
  int left = 0, right = nums.size() - 1;
  while (left <= right) {
    int mid = left + ((right - left) >> 1);
    if (nums[mid] == target) {
      return mid;
    }
    // [left, mid] [mid, right] 中一定存在一个有序的区间
    // [left, mid] 是有序的
    if (nums[left] <= nums[mid]) {
      // target 在 [left, mid), 移动right指针
      if (nums[left] <= target && nums[mid] > target) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    } else {
      // [mid, right] 是有序的
      // target 在 (mid, right], 移动right指针
      if (nums[mid] < target && nums[right] >= target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
  }
  return -1;
}

int main() {
  // 4,5,6,7,0,1,2

  std::vector<int> vec{4, 5, 6, 7, 0, 1, 2};

  std::cout << search(vec, 10) << std::endl;
  return 0;
}