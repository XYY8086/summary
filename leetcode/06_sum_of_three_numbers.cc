#include <algorithm>
#include <iostream>
#include <vector>

#include "common.hpp"

using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> ret;
    std::sort(nums.begin(), nums.end());

    for (int index = 0; index < nums.size(); ++index) {
      // 数组已经排序,若当前位置>0 后续不可能存在两数之和小于0
      // 要求不重复,所以直接跳过判断过的元素
      if (nums[index] > 0 || (index > 0 && nums[index] == nums[index - 1])) {
        continue;
      }

      // 下面求两数之和=target
      int left = index + 1;
      int right = nums.size() - 1;

      int target = -nums[index];
      while (left < right) {
        int count = nums[left] + nums[right];
        if (count == target) {
          ret.emplace_back(
              std::vector<int>{nums[index], nums[left], nums[right]});

          // 为了保证不重复,需要跳过相同元素
          while (left < right && nums[left + 1] == nums[left]) {
            left++;
          }
          while (left < right && nums[right - 1] == nums[right]) {
            right--;
          }
          left++;
        } else if (count < target) {
          left++;
        } else {
          right--;
        }
      }
    }
    return ret;
  }
};

int main() {
  std::vector<int> input{-1, 0, 1, 2, -1, -4};

  PrintComplexSeries<vector<vector<int>>>(Solution{}.threeSum(input));
}