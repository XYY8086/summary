#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

#include "common.hpp"

class Solution {
public:
  std::vector<std::vector<int>> ret;
  std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates,
                                               int target) {
    std::sort(candidates.begin(), candidates.end());
    std::vector<int> path;
    combinationSum(candidates, path, target, 0, 0);
    return ret;
  }

  void combinationSum(const std::vector<int> &candidates,
                      std::vector<int> &path, int target, int current,
                      int pos) {
    if (target == current) {
      ret.push_back(path);
      return;
    }

    if (current > target) {
      return;
    }
    // 题目要求是不能重复的,这里这里遍历会已知向前遍历
    for (int index = pos; index < candidates.size(); ++index) {
      path.push_back(candidates[index]);
      // 同一个元素可以多次选择,所以这里index迭代时没有进行+1
      combinationSum(candidates, path, target, current + candidates[index],
                     index);
      path.pop_back();
    }
  }
};

int main() {
  std::vector<int> input{2, 3, 6, 7};
  int target = 7;
  auto ret = Solution{}.combinationSum(input, target);

  PrintComplexSeries(ret);

  return 0;
}