#include <iostream>
#include <string.h>
#include <vector>

class Solution {
public:
  bool canJump(std::vector<int> &nums) {
    bool can_jump[nums.size()];
    memset(can_jump, 0, nums.size());
    can_jump[0] = true;
    for (int index = 0; index < nums.size() - 1; ++index) {
      // 当前位于第index位置(可以抵达), 在这个基础上可以跳到哪些位置?
      if (can_jump[index] && nums[index] > 0) {
        memset(can_jump + index + 1, 1,
               std::min(nums[index], int(nums.size() - index)));
      }
    }

    return can_jump[nums.size() - 1];
  }
};

int main() {
  std::vector<int> vec{2, 0};
  std::cout << Solution{}.canJump(vec) << std::endl;

  return 0;
}
