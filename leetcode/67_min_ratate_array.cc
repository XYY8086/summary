#include <vector>

class Solution {
public:
  int findMin(std::vector<int> &nums) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
      int mid = (right + left) >> 1;
      // 翻转的部分在右侧,也就是说最小值在右侧
      if (nums[right] < nums[mid]) {
        left = mid + 1;
      } else {
        /*
        最小值可能在mid 也可能在 左侧 [left, mid], 这里由于是闭区间查找,只能mid -1 (否则有可能死循环) 
        但是mid - 1的情况下会漏掉mid为最小值的情况, 例如{3, 1, 2}
        */
        /*
        方法1:right只移动一个位置
        */
        right--;

        /*
        方法2: 也可以将两种情况分别计算出来:
        bool t1 = mid < nums.size() - 1 ? nums[mid] < nums[mid + 1] : true;
        bool t2 = mid > 0 ? nums[mid] < nums[mid - 1] : true;
        if (t1 && t2) {
            left = mid;
            break;
        } else {
            right = mid - 1;
        }
        */

       /*
       方法3: 变为开区间查找
       */
      }
    }
    return nums[left];
  }
};