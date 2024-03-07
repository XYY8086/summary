#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int subarraySum(vector<int> &nums, int k) {
    int ret = 0;
    int current_sum = 0;
    std::unordered_map<int, int> expected;
    for (int index = nums.size() - 1; index >= 0; --index) {
      current_sum += nums[index];
      int diff = current_sum + k - nums[index];
      // 此时我们希望后续能够出现一个dp[index]=diff
      expected[diff]++;
      auto itr = expected.find(current_sum);
      if (itr != expected.end()) {
        ret += itr->second;
      }
    }
    return ret;
  }

  /// @brief
  /// 方法2每次都需要在一个数组中查找某个元素是否存在,我们自然想到能否使用map保存数组中的结果
  int subarraySum3(vector<int> &nums, int k) {
    int ret = 0;
    std::unordered_map<int, std::vector<int>>
        count; // key:sum val:子序列的起始位置
    std::vector<int> sum_vec(nums.size(), 0);
    int sum = 0;
    for (int i = nums.size() - 1; i >= 0; --i) {
      sum += nums[i];
      count[sum].push_back(i);
      sum_vec[i] = sum;
    }

    for (int index = nums.size() - 1; index >= 0; --index) {
      int diff = sum_vec[index] + k - nums[index];
      auto itr = count.find(diff);
      if (itr == count.end()) {
        continue;
      }
      for (auto ele : itr->second) {
        ret += (ele <= index);
      }
    }
    return ret;
  }

  /// @brief 在暴力求和的基础上,我们先遍历数组进行求和 dp[k]
  /// 从k开始到结尾的序列和
  int subarraySum2(vector<int> &nums, int k) {
    int ret = 0;
    std::vector<int> dp(nums.size());
    int sum = 0;
    for (int i = nums.size() - 1; i >= 0; --i) {
      sum += nums[i];
      dp[i] = sum;
    }

    for (int index = nums.size() - 1; index >= 0; --index) {
      int diff = dp[index] + k - nums[index];
      auto itr = std::find(dp.begin(), dp.end(), diff);
      if (itr != dp.end() && (itr - dp.begin()) <= index) {
        ++ret;
      }
    }
    return ret;
  }

  /// @brief 暴力求和
  int subarraySum1(vector<int> &nums, int k) {
    int ret = 0;
    for (int i = 0; i < nums.size(); ++i) {
      int sum = 0;
      for (int j = i; j < nums.size(); ++j) {
        sum += nums[j];
        if (sum == k) {
          ++ret;
        }
      }
    }
    return ret;
  }
};

int main() {
  std::vector<int> vec{-1, 10, 3};

  auto itr = std::find(vec.begin(), vec.end(), -1);
  std::cout << *itr << "," << itr - vec.begin() << std::endl;
}