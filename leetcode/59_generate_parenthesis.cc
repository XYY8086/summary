#include <string>
#include <vector>

#include "common.hpp"

class Solution {
public:
  std::vector<std::string> ret;
  std::vector<std::string> generateParenthesis(int n) {
    std::string path;
    generateParenthesis(n, path, 0, 0);
    return ret;
  }

  void generateParenthesis(int n, std::string &path, int left, int right) {
    if (left == n && right == n) {
      ret.push_back(path);
    }
    // 左括号数量一定不小于右括号数量
    if (right > left) {
      return;
    }
    // 还有左括号可以使用
    if (left < n) {
      path.push_back('(');
      generateParenthesis(n, path, left + 1, right);
      path.pop_back();
    }
    // 还有右括号可以使用
    if (right < n) {
      path.push_back(')');
      generateParenthesis(n, path, left, right + 1);
      path.pop_back();
    }
  }
};

int main() {
  auto ret = Solution{}.generateParenthesis(3);
  PrintSeries(ret);
  return 0;
}