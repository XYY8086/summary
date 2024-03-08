#include <limits.h>

#include <iostream>
#include <queue>
#include <vector>

#include "common.hpp"

using namespace std;

class Solution {
public:
  std::pair<int, int> get_range_max(const vector<int> &nums, int start,
                                    int end) {
    int current_max_value = INT_MIN;
    int current_max_location = -1;
    for (int index = start; index <= end; ++index) {
      if (nums[index] > current_max_value) {
        current_max_value = nums[index];
        current_max_location = index;
      }
    }

    return {current_max_value, current_max_location};
  }
  /// @brief  暴力解法,每次需要求解窗口内的最大值
  vector<int> maxSlidingWindow1(vector<int> &nums, int k) {
    if (nums.size() < k) {
      return {};
    }
    auto result = get_range_max(nums, 0, k - 1);
    int current_max_value = result.first;
    int current_max_location = result.second;

    std::vector<int> ret{current_max_value};
    // 顺序迭代计算
    for (int index = k; index < nums.size(); ++index) {
      // 当前的值大于窗口内的最大值，则直接更新最值和位置
      if (nums[index] >= current_max_value) {
        current_max_value = nums[index];
        current_max_location = index;
      } else if (index - current_max_location > k - 1) {
        // 此时最大值已经不不在窗口内了,需要重新计算最值和位置
        auto result = get_range_max(nums, index - k + 1, index);
        current_max_value = result.first;
        current_max_location = result.second;
      }
      ret.push_back(current_max_value);
    }
    return ret;
  }

  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    if (nums.size() < k) {
      return {};
    }
    std::deque<int> dq;
    for (int index = 0; index < k; ++index) {
      while (!dq.empty() && nums[dq.back()] <= nums[index]) {
        dq.pop_back();
      }
      dq.push_back(index);
    }

    std::vector<int> ret{nums[dq.front()]};
    for (int index = k; index < nums.size(); ++index) {
      // 如果当前位置对应的值 nums[index] >= 前面位置的值
      // nums[dq.back()],则dq.back()永远不可能是最大值,因为其val小同时位置更靠左，在窗口向右滑动时更早出窗口。
      // 所以这种关系的元素都可以弹出,不在目标集合内。但是如果nums[index]<nums[dq.back()]，则随着前面元素出窗口，
      // index位置成为最大值,需要保存起来
      while (!dq.empty() && nums[dq.back()] <= nums[index]) {
        dq.pop_back();
      }
      dq.push_back(index);
      // 检测当前的最大值是否已经出窗口了
      while (dq.front() <= index - k) {
        dq.pop_front();
      }
      ret.push_back(nums[dq.front()]);
    }
    return ret;
  }
};

int main() {
  std::vector<int> input{1, 3, -1, -3, 5, 3, 6, 7};
  int k = 3;
  PrintSeries(Solution{}.maxSlidingWindow(input, k));
}