#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

#include <limits.h>

class Solution {
public:
  int largestRectangleArea1(const std::vector<int> &heights) {
    // 遍历所有可能的矩阵，计算最大值
    int max_width = heights.size();
    int ans = 0;
    // left指向矩阵左侧位置
    for (int left = 0; left < max_width; ++left) {
      // 遍历矩阵右侧位置
      int min_val = INT_MAX;
      for (int right = left; right < max_width; ++right) {
        min_val = std::min(heights[right], min_val);
        ans = std::max(ans, (right - left + 1) * min_val);
      }
    }
    return ans;
  }

  int largestRectangleArea(const std::vector<int> &heights) {
    std::vector<int> left(heights.size()), right(heights.size());
    std::stack<int> pos; // 单调递增栈
    // 寻找右边界,寻找heights[i]右侧第一个小于它的值
    // 搞清楚为什么找右边界是从右向左遍历: 从左向右的话不存在状态上的依赖了
    for (int i = heights.size() - 1; i >= 0; --i) {
      // 当前值小于栈顶元素,需要进行退栈
      while (!pos.empty() && heights[i] <= heights[pos.top()]) {
        pos.pop();
      }
      right[i] = (pos.empty() ? heights.size() : pos.top());
      pos.push(i);
    }

    pos = std::stack<int>{};
    // 寻找左边界
    for (int i = 0; i < heights.size(); ++i) {
      // 当前值小于栈顶元素,需要进行退栈
      while (!pos.empty() && heights[i] <= heights[pos.top()]) {
        pos.pop();
      }
      left[i] = (pos.empty() ? -1 : pos.top());
      pos.push(i);
    }

    // 计算矩阵面积
    int ans = 0;
    for (int i = 0; i < left.size(); ++i) {
      ans = std::max(ans, (right[i] - left[i] - 1) * heights[i]);
    }
    return ans;
  }
};

int main(int argc, char **argv) {
  std::cout << Solution{}.largestRectangleArea({9, 0}) << std::endl;
  return 0;
}