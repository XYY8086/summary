#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maxArea(vector<int> &height) {
    int left = 0, right = height.size() - 1;
    int ret = 0;
    while (left < right) {
      int current_height = std::min(height[left], height[right]);
      int current_erea = (right - left) * current_height;
      ret = std::max(ret, current_erea);
      // 移动左右指针,低的边移动才可能将高度变高
      if (height[left] < height[right]) {
        left++;
      } else {
        right--;
      }
    }
    return ret;
  }

private:
  int max_area(vector<int> &height) {
    // 暴力解法，两重循环
    int ret = 0;
    for (int left = 0; left < height.size(); ++left) {
      for (int right = left + 1; right < height.size(); ++right) {
        int area = (right - left) * std::min(height[left], height[right]);
        ret = std::max(ret, area);
      }
    }
    return ret;
  }
};

int main() {
  std::vector<int> input{1, 8, 6, 2, 5, 4, 8, 3, 7};

  std::cout << Solution{}.maxArea(input) << std::endl;
}