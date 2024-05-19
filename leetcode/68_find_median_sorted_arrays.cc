#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#include "common.hpp"

class Solution {
public:
  double findMedianSortedArrays4(std::vector<int> &nums1,
                                 std::vector<int> &nums2) {}

  /// @brief 一次查找第mid mid-1 小的两个数. 时间 O(m+n)
  double findMedianSortedArrays3(std::vector<int> &nums1,
                                 std::vector<int> &nums2) {
    int total = nums1.size() + nums2.size();
    // 偶数个时: 找到 total/2 -1 , total/2 小的两个数
    // 奇数个时: 找到 total/2 小的这个数
    int mid1, mid2, p1 = 0, p2 = 0;
    for (int index = 0; index <= total / 2; ++index) {
      mid1 = mid2;
      if (p1 < nums1.size() && (p2 >= nums2.size() || nums1[p1] < nums2[p2])) {
        mid2 = nums1[p1++];
      } else {
        mid2 = nums2[p2++];
      }
    }
    return total % 2 == 0 ? mid2 : (mid1 + mid2) / 2.0;
  }

  /// @brief 没两个而排序数组中找出第K小的元素. 时间O(m+n)
  double findMedianSortedArrays2(std::vector<int> &nums1,
                                 std::vector<int> &nums2) {
    int total = nums1.size() + nums2.size();
    // 偶数个时: 找到 total/2 -1 , total/2 小的两个数
    // 奇数个时: 找到 total/2 小的这个数
    // 依次从数组中找出这两个数
    return total % 2 == 1 ? findKthMiniElement(nums1, nums2, total / 2)
                          : (findKthMiniElement(nums1, nums2, total / 2) +
                             findKthMiniElement(nums1, nums2, total / 2 - 1)) /
                                2.0;
  }

  /// @brief 合并两个数组后求中位数,时间O(m+n) 空间O(m+n)
  double findMedianSortedArrays(std::vector<int> &nums1,
                                std::vector<int> &nums2) {
    std::vector<int> nums;
    int p1 = 0, p2 = 0;
    while (p1 < nums1.size() && p2 < nums2.size()) {
      if (nums1[p1] < nums2[p2]) {
        nums.push_back(nums1[p1++]);
      } else {
        nums.push_back(nums2[p2++]);
      }
    }
    if (p1 == nums1.size()) {
      nums.insert(nums.end(), nums2.begin() + p2, nums2.end());
    } else {
      nums.insert(nums.end(), nums1.begin() + p1, nums1.end());
    }

    PrintSeries(nums);
    int total = nums1.size() + nums2.size();
    return total % 2 == 0 ? (nums[total / 2] + nums[total / 2 - 1]) / 2.0
                          : nums[total / 2];
  }

private:
  // 0 <= k
  int findKthMiniElement4(std::vector<int> &nums1, std::vector<int> &nums2,
                          int k) {
    int p1 = 0, p2 = 0, len1 = nums1.size(), len2 = nums2.size();
    while (true) {
      if (p1 == len1) {
        return nums2[p2 + k];
      } else if (p2 == len2) {
        return nums1[p1 + k];
      }
      if (k == 0) {
        return std::min(nums1[p1], nums2[p2]);
      }
      int index_num1 = std::min(p1 + std::max(0, k / 2 - 1), len1 - 1);
      int index_num2 = std::min(p2 + std::max(0, k / 2 - 1), len2 - 1);
      if (nums1[index_num1] < nums2[index_num2]) {
        // 对于nums1来说 [p1, index_nums1] 不是目标区间
        k -= (index_num1 - p1 + 1);
        p1 = index_num1 + 1;
      } else {
        k -= (index_num2 - p2 + 1);
        p2 = index_num2 + 1;
      }
    }
  }

  // 1 <= k
  int findKthMiniElement3(std::vector<int> &nums1, std::vector<int> &nums2,
                          int k) {
    int p1 = 0, p2 = 0, len1 = nums1.size(), len2 = nums2.size();
    while (true) {
      if (p1 == len1) {
        return nums2[p2 + k - 1];
      } else if (p2 == len2) {
        return nums1[p1 + k - 1];
      }
      if (k == 1) {
        return std::min(nums1[p1], nums2[p2]);
      }
      int index_num1 = std::min(p1 + k / 2, len1) - 1;
      int index_num2 = std::min(p2 + k / 2, len2) - 1;
      if (nums1[index_num1] < nums2[index_num2]) {
        // 对于nums1来说 [p1, index_nums1] 不是目标区间
        k -= (index_num1 - p1 + 1);
        p1 = index_num1 + 1;
      } else {
        k -= (index_num2 - p2 + 1);
        p2 = index_num2 + 1;
      }
    }
  }

  /// @brief 从两个排序数组中找出第k小的元素. 0 <= k
  int findKthMiniElement2(std::vector<int> &nums1, std::vector<int> &nums2,
                          int k) {
    int ret;
    int p1 = 0, p2 = 0;
    for (int index = 0; index <= k; ++index) {
      // 这个条件分支写的比较好
      if (p1 < nums1.size() && (p2 >= nums2.size() || nums1[p1] < nums2[p2])) {
        ret = nums1[p1++];
      } else {
        ret = nums2[p2++];
      }
    }
    return ret;
  }

  /// @brief 从两个排序数组中找出第k小的元素
  int findKthMiniElement(std::vector<int> &nums1, std::vector<int> &nums2,
                         int k) {
    int p1 = 0, p2 = 0, count = 0, val = 0;
    while (p1 < nums1.size() && p2 < nums2.size()) {
      if (nums1[p1] < nums2[p2]) {
        if (count++ == k) {
          val = nums1[p1];
          break;
        }
        ++p1;
      } else {
        if (count++ == k) {
          val = nums2[p2];
          break;
        }
        ++p2;
      }
    }
    // 还没有找到指定位置,vec1还没有遍历完
    while (p1 < nums1.size() && count < k + 1) {
      if (count++ == k) {
        val = nums1[p1];
        break;
      }
      ++p1;
    }

    while (p2 < nums2.size() && count < k + 1) {
      if (count++ == k) {
        val = nums2[p2];
        break;
      }
      ++p2;
    }
    return val;
  }
  std::priority_queue<int, std::vector<int>, std::greater<int>> mini_queue;
  std::priority_queue<int, std::vector<int>, std::less<int>> max_queue;
};

int main() {

  std::vector<int> vec1{1, 2};
  std::vector<int> vec2{3, 4};

  std::cout << Solution{}.findMedianSortedArrays2(vec1, vec2) << std::endl;

  return 0;
}