#include "common.hpp"
#include <iostream>
#include <vector>

int findKthLargest(std::vector<int> &nums, int left, int right, int k) {
  int hock = (left + right) / 2; // left + right)/2  本次选定的哨兵
  int hock_val = nums[hock];     // 哨兵对应的值
  std::swap(nums[left],
            nums[hock]); // 因为要先遍历右侧的值，所以先将哨兵交换到左侧
  int fact_hock = left; // 交换之后哨兵的实际起始位置

  while (left < right) {
    while (left < right && nums[right] >= hock_val) {
      --right;
    }
    while (left < right && nums[left] <= hock_val) {
      ++left;
    }
    std::swap(nums[left], nums[right]);
  }
  std::swap(nums[left], nums[fact_hock]);
  return left;
}

int findKthLargest(std::vector<int> &nums, int left, int right, int k) {
  int hock = left; // 本次选定的哨兵,这样选择哨兵，极端情况下会退化
  int hock_val = nums[hock];
  while (left < right) {
    while (left < right && nums[right] >= nums[hock]) {
      --right;
    }
    while (left < right && nums[left] <= nums[hock]) {
      ++left;
    }
    std::swap(nums[left], nums[right]);
  }
  std::swap(nums[left], nums[hock]);
  PrintSeries(nums);
  std::cout << "hock=" << hock_val << ",ret=" << left << ",k=" << k
            << std::endl;
  getchar();
  return left;
}

int findKthLargest(std::vector<int> &nums, int k) {
  int left = 0, right = nums.size() - 1;
  k = nums.size() - k;
  while (left < right) {
    int loc = findKthLargest(nums, left, right, k);
    if (loc == k) {
      return nums[k];
    }
    if (loc > k) {
      right = loc;
    } else {
      left = loc + 1;
    }
  }

  return nums[left];
}

int main() {
  std::vector<int> vec{
      1, 2, 3, 4, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
      1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  };
  std::cout << findKthLargest(vec, 2) << std::endl;

  return 0;
}