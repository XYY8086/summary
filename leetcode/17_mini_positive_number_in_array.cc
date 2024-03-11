#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int firstMissingPositive(vector<int> &nums) {
    for (int index = 0; index < nums.size(); ++index) {
      // 当前位置不满足 nums[i] == i + 1,尝试交换到正确位置上
      while (nums[index] != index + 1) {
        // 为防止因为缺失数据引起的无限循环,需要提前终止
        if (nums[index] <= 0 || nums[index] > nums.size() ||
            nums[index] == nums[nums[index] - 1]) {
          break;
        }
        // 交换 nums[i] 到其理想位置nums[i] - 1 上
        std::swap(nums[index], nums[nums[index] - 1]);
      }
    }
    for (int index = 0; index < nums.size(); ++index) {
      if (nums[index] != index + 1) {
        return index + 1;
      }
    }
    return nums.size() + 1;
  }

  int firstMissingPositive1(vector<int> &nums) {
    std::unordered_map<int, int> count;
    for (auto ele : nums) {
      ++count[ele];
    }

    for (int ele = 1; ele <= nums.size(); ++ele) {
      if (!count.count(ele)) {
        return ele;
      }
    }
    return nums.size() + 1;
  }
};

int main() {
  std::vector<int> input{3, 4, -1, 1};
  std::cout << Solution{}.firstMissingPositive(input) << std::endl;
  return 0;
}