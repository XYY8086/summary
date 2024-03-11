#include <algorithm>
#include <iostream>
#include <vector>

#include <string.h>

#include "common.hpp"

using namespace std;

class Solution {
public:
  void rotate1(vector<int> &nums, int k) {
    if (nums.empty() || ((k % nums.size()) == 0)) {
      return;
    }
    int res = k % nums.size();
    std::vector<int> tail_nums(nums.begin() + nums.size() - res, nums.end());
    memmove(nums.data() + res, nums.data(), (nums.size() - res) * sizeof(int));
    memmove(nums.data(), tail_nums.data(), tail_nums.size() * sizeof(int));
  }

  void rotate(vector<int> &nums, int k) {
    if (nums.empty() || ((k % nums.size()) == 0)) {
      return;
    }
    int res = k % nums.size();
    reverse(nums, 0, nums.size() - 1);
    reverse(nums, 0, res - 1);
    reverse(nums, res, nums.size() - 1);
  }

  void reverse(vector<int> &nums, int start, int end) {
    if (start < 0 || end >= nums.size() || start >= end) {
      return;
    }
    while (start < end) {
      std::swap(nums[start++], nums[end--]);
    }
  }
};

int main() {
  std::vector<int> input{1, 2, 3, 4, 5, 6, 7};
  int k = 20;
  Solution{}.rotate(input, k);
  PrintSeries(input);
  return 0;
}