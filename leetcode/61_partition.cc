#include <string>
#include <vector>

#include "common.hpp"

class Solution {
public:
  std::vector<std::vector<std::string>> partition(std::string s) {
    partition(s, 0);
    return ret;
  }

private:
  std::vector<std::string> path;
  std::vector<std::vector<std::string>> ret;

  bool is_valid(const std::string &input, int left, int right) {
    while (left < right) {
      if (input[left] != input[right]) {
        return false;
      }
      ++left;
      --right;
    }
    return true;
  }

  void partition(const std::string &input, int start) {
    // 遍历到末尾,仍然是回文串,这种分割结果是合法的,加入结果集中
    if (start == input.size()) {
      ret.push_back(path);
      return;
    }
    // 从start开始分割,验证子串是否是回文串
    for (int index = start; index < input.size(); ++index) {
      // [start, index] 是一个回文串
      if (is_valid(input, start, index)) {
        // [start, index]加入当前分割结果中
        path.push_back(input.substr(start, index - start + 1));
        // 开始迭代 [index+1, END]
        partition(input, index + 1);
        path.pop_back();
      }
    }
  }
};

int main(){
    auto ret = Solution{}.partition("aab");
    PrintComplexSeries(ret);
    return 0;
}