#include <string>
#include <vector>

#include "common.hpp"

class Solution {
public:
  std::vector<std::vector<int>> ret;
  std::vector<std::vector<int>> subsets(std::vector<int> &nums) {
    std::vector<int> path;
    subsets(nums, path, 0);
    return ret;
  }

  void subsets(const std::vector<int> &nums, std::vector<int> &path,
               int last_index) {
    ret.push_back(path);
    for (int index = last_index; index < nums.size(); ++index) {
      path.push_back(nums[index]);
      subsets(nums, path, index + 1);
      path.pop_back();
    }
  }
};

int main() {
  std::vector<int> vec{1, 2, 3};

  auto ret = Solution{}.subsets(vec);
  PrintComplexSeries(ret);
}
