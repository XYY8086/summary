#include <limits.h>

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int ret = nums.back();
    int last_sum = nums.back();
    for (int index = nums.size() - 2; index >= 0; --index) {
      // // last_sum = nums[index] + (last_sum < 0 ? 0 : last_sum);
      if (last_sum < 0) {
        last_sum = nums[index];
      } else {
        last_sum = last_sum + nums[index];
      }
      ret = std::max(last_sum, ret);
    }
    return ret;
  }

  int maxSubArray2(vector<int> &nums) {
    // record[k] 表示[k, END]范围内最大和的子序列
    std::vector<int> record(nums.size());
    record[nums.size() - 1] = nums.back();
    for (int index = nums.size() - 2; index >= 0; --index) {
      // 上一个状态 <0 相加之后更小,直接取nums[index]作为新序列
      if (record[index + 1] < 0) {
        record[index] = nums[index];
      } else {
        record[index] = record[index + 1] + nums[index];
      }
    }
    return *std::max_element(record.begin(), record.end());
  }
  // 暴力解法
  int maxSubArray1(vector<int> &nums) {
    int ret = INT_MIN;
    for (int i = 0; i < nums.size(); ++i) {
      int sum = 0;
      for (int j = i; j < nums.size(); ++j) {
        sum += nums[j];
        ret = std::max(ret, sum);
      }
    }
    return ret;
  }
};

int main() {
  std::vector<int> input{-2, 1, -3, 4, -1, 2, 1, -5, 4};
  std::cout << Solution{}.maxSubArray(input) << std::endl;
}
