#include <iostream>
#include <vector>

#include "common.hpp"

using namespace std;

class Solution {
public:
  int trap(vector<int> &height) {
    return solution4(height);
  }

private:
  /// @brief
  /// 暴力解法,在计算每个位置的蓄水量时都要计算左右两侧最高的位置，取其中较短的边作为实际高度
  int solution1(vector<int> &height) {
    if (height.size() <= 2) {
      return 0;
    }
    int left = 0, right = 1;
    int ret = 0;
    for (int index = 1; index < height.size(); ++index) {
      // 向左查找一个最高的墙
      int left_max = -1;
      for (int i = index - 1; i >= 0; --i) {
        left_max = left_max < height[i] ? height[i] : left_max;
      }
      if (left_max < height[index]) {
        continue;
      }
      // 向右查找一个最高的强
      int right_max = -1;
      for (int i = index + 1; i < height.size(); ++i) {
        right_max = right_max < height[i] ? height[i] : right_max;
      }
      if (right_max < height[index]) {
        continue;
      }
      // 取左右中最小的那个
      int max_val = right_max < left_max ? right_max : left_max;
      ret += (max_val - height[index]);
    }
    return ret;
  }

  /// @brief 在暴力解法的基础上,提前将k位置的左右最高水位计算出来，存储到数组中
  int solution2(vector<int> &height) {
    if (height.size() <= 2) {
      return 0;
    }
    int ret = 0;
    vector<int> left_max(height.size(), 0); // vec[k]位置表示k左侧最高的墙
    vector<int> right_max(height.size(), 0); // vec[k]位置表示k右侧最高的墙

    for (int index = 1; index < height.size(); ++index) {
      // 若左边相邻的高度大于之前的高度则取相邻的高
      left_max[index] = left_max[index - 1] < height[index - 1]
                            ? height[index - 1]
                            : left_max[index - 1];
    }

    for (int index = height.size() - 2; index >= 0; --index) {
      right_max[index] = right_max[index + 1] < height[index + 1]
                             ? height[index + 1]
                             : right_max[index + 1];
    }

    for (int index = 1; index < height.size(); ++index) {
      // 向左查找一个最高的墙
      int left = left_max[index];
      // 向右查找一个最高的强
      int right = right_max[index];
      // 取左右中最小的那个
      int max_val = std::min(left, right);
      // 二u过 max_val < height[index], 说明该位置不能蓄水
      ret += std::max((max_val - height[index]), 0);
    }
    return ret;
  }

  /// @brief 在solution2的基础上,一次遍历计算出两个数组的值
  int solution3(vector<int> &height) {
    if (height.size() <= 2) {
      return 0;
    }
    int ret = 0;
    vector<int> left_max(height.size(), 0); // vec[k]位置表示k左侧最高的墙
    vector<int> right_max(height.size(), 0); // vec[k]位置表示k右侧最高的墙

    // 头尾位置显然时无法蓄水的，所以循环变量范围是 [1, size()-2]
    for (int index = 1; index < height.size() - 1; ++index) {
      // 若左边相邻的高度大于之前的高度则取相邻的高
      left_max[index] = std::max(left_max[index - 1], height[index - 1]);
      int right_location = height.size() - index - 1;
      right_max[right_location] =
          std::max(right_max[right_location + 1], height[right_location + 1]);
    }

    for (int index = 1; index < height.size(); ++index) {
      // 向左查找一个最高的墙
      int left = left_max[index];
      // 向右查找一个最高的强
      int right = right_max[index];
      // 取左右中最小的那个
      int max_val = std::min(left, right);
      // 若 max_val < height[index], 说明该位置不能蓄水
      ret += std::max((max_val - height[index]), 0);
    }
    return ret;
  }

  /// @brief 在方法3的基础上,我们希望能够在一次遍历中同时计算left_max
  /// right_max和蓄水量. 已知left_max从左到右递增,
  /// right_max从右到左递增，则使用双指针遍历，每次都可以确定left或者right位置的实际水位
  int solution4(vector<int> &height) {
    if (height.size() <= 2) {
      return 0;
    }
    int ret = 0;

    int left = 1, right = height.size() - 2;
    int left_max = height[0], right_max = height.back();
    // 循环内每次只计算left或者right位置的蓄水量,所以为了保证left
    // right都能计算到,这里取的是闭区间
    while (left <= right) {
      // left位置
      left_max = std::max(left_max, height[left]);
      right_max = std::max(right_max, height[right]);
      if (left_max < right_max) {
        // 如果left位置的左侧最高值left_max
        // 小于此时的right位置右侧最高值right_max ->
        // left位置右侧的最高值必定不大于right_max,这是因为right_max从右到左是递增的
        ret += (left_max - height[left]);
        ++left;
      } else {
        // 同理,由于left_max
        // 从做到右递增的,如此时left_max已经大于right_max，则对于right位置而言,较短的高是right_max
        ret += (right_max - height[right]);
        --right;
      }
    }
    return ret;
  }
};
int main(int argc, char **argv) {

  std::vector<int> input{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

  std::cout << Solution{}.trap(input) << std::endl;
  return 0;
}