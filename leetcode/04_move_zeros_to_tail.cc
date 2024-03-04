#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void moveZeroes(vector<int> &nums) {
    // 官方给出的解法,慢指针指向0元素位置,快指针指向非0元素位置,每次交换快慢指针
    int slow = 0, fast = 0;
    while(fast < nums.size()){
        if(nums[fast]!=0){
            std::swap(nums[fast], nums[slow]);
            ++slow;
        }
        ++fast;
    }
  }

private:
  void solution2(vector<int> &nums) {
    // 在方法1的基础上,0元素没必要交换,直接将非0元素向前移动,最后直接填充0即可
    int non_zeros_location = 0;
    for (int index = 0; index < nums.size(); ++index) {
      if (nums[index] != 0) {
        nums[non_zeros_location++] = nums[index];
      }
    }

    for (int index = non_zeros_location; index < nums.size(); ++index) {
      nums[index] = 0;
    }
  }
  void solution1(vector<int> &nums) {
    // 最初的想法,找到一个0位置和一个非0位置,然后交换两者位置就好了
    if (nums.size() <= 1) {
      return;
    }
    int zeros_location = -1, non_zeros_location = -1;
    do {
      // 找到一个0位置 loc0
      zeros_location = find_zero_location(nums, zeros_location + 1);
      if (zeros_location < 0) {
        return;
      }
      // 找到一个非0位置 loc1
      non_zeros_location = find_nonzero_location(nums, zeros_location + 1);
      if (non_zeros_location < 0) {
        return;
      }
      // 交换
      nums[zeros_location] = nums[non_zeros_location];
      nums[non_zeros_location] = 0;
    } while (true);
  }
  int find_location(const vector<int> &nums, int start, bool zeros_flag) {
    if (start >= nums.size()) {
      return -1;
    }
    for (int index = start; index < nums.size(); ++index) {
      if ((nums[index] == 0 && zeros_flag) ||
          (nums[index] != 0 && !zeros_flag)) {
        return index;
      }
    }
    return -1;
  }

  int find_zero_location(const vector<int> &nums, int start) {
    return find_location(nums, start, true);
  }

  int find_nonzero_location(const vector<int> &nums, int start) {
    return find_location(nums, start, false);
  }
};

int main() {
  std::vector<int> input{1, 2, 0, 1};

  Solution{}.moveZeroes(input);
}