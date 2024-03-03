#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    // key:数字num val:该数字所在的最长序列长度
    std::unordered_map<int, int> dp;
    /*
    dp[k] = dp[k-1] + dp[k+1] + 1
    但是我们不能选择从k-1开始执行,所以我们在填充dp[k]时只是根据当前情况预填充，在后续发现连续序列时还要进行更新
    */
    int result = 0;
    for (int num : nums) {
      if (dp.count(num)) {
        continue;
      }
      int left_view_len = dp.find(num - 1) == dp.end() ? 0 : dp[num - 1];
      int right_view_len = dp.find(num + 1) == dp.end() ? 0 : dp[num + 1];
      int current_view_len = left_view_len + right_view_len + 1;

      // 更新,每次只更新连续序列的两个端点即可,因为后续的连接起来的序列也只会取两个端点的值相加
      dp[num] = current_view_len;
      dp[num - left_view_len] = current_view_len; // 这里更新右左侧端点的值
      dp[num + right_view_len] = current_view_len; // 这里更新右侧端点的值

      result = result < current_view_len ? current_view_len : result;
    }
    return result;
  }

private:
  // 题目要求O(n)的时间复杂度内完成,使用排序或者间接排序(set,
  // map)的方式都会超出要求
  int bad_case(vector<int> &nums) {
    if (nums.empty()) {
      return 0;
    }
    std::set<int> counts{nums.begin(), nums.end()};
    int ret = 1;
    for (auto itr = counts.begin(); itr != counts.end();) {
      int start = *itr;
      int result = 1;
      ++itr;
      if (itr == counts.end()) {
        break;
      }
      while (itr != counts.end() && *itr == start + 1) {
        ++start;
        ++result;
        ++itr;
      }
      ret = std::max(ret, result);
    }
    return ret;
  }

  int solution1(vector<int> &nums) {
    std::unordered_set<int> counts{nums.begin(), nums.end()};
    int ret = 0;
    for (int num : nums) {
      // 总是尝试从一个序列的起点开始计算
      if (counts.count(num - 1)) {
        continue;
      }
      int result = 0;
      // 包含连续序列
      while (counts.count(num++)) {
        ++result;
      }
      ret = std::max(ret, result);
    }
    return ret;
  }
};

int main() {
  std::vector<int> input{1, 2, 0, 1};

  std::cout << Solution{}.longestConsecutive(input) << std::endl;
}