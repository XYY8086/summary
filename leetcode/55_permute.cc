#include <string>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> ret;

  std::vector<std::vector<int>> permute(std::vector<int> &nums) {
    std::vector<int> path;
    std::vector<bool> visited(nums.size(), false);
    permute(nums, path, visited);
    return ret;
  }

  void permute(const std::vector<int> &nums, std::vector<int> &path,
               std::vector<bool> &visited) {
    if (path.size() == nums.size()) {
      ret.push_back(path);
      return;
    }

    for (int index = 0; index < nums.size(); ++index) {
      // 当前节点已经访问过了
      if (visited[index]) {
        continue;
      }
      // 访问当前节点
      path.push_back(nums.at(index));
      visited[index] = true;
      permute(nums, path, visited);

      // 回溯
      path.pop_back();
      visited[index] = false;
    }
  }
};
