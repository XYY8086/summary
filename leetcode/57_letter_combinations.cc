#include <string>
#include <unordered_map>
#include <vector>

#include "common.hpp"

class Solution {
public:
  std::vector<std::string> ret;
  std::vector<std::string> letterCombinations(std::string digits) {
    if(digits.empty()){return {};}
    std::string path;
    letterCombinations(digits, path, 0);
    return ret;
  }

  void letterCombinations(const std::string &digits, std::string &path,
                          int index) {
    if (path.size() == digits.size()) {
      ret.push_back(path);
      return;
    }

    std::vector<char> res = characters[digits[index]];

    for (char ch : res) {
      path.push_back(ch);
      letterCombinations(digits, path, index + 1);
      path.pop_back();
    }
  }

private:
  std::unordered_map<char, std::vector<char>> characters{
      {'2', {'a', 'b', 'c'}}, {'3', {'d', 'e', 'f'}},
      {'4', {'g', 'h', 'i'}}, {'5', {'j', 'k', 'l'}},
      {'6', {'m', 'n', 'o'}}, {'7', {'p', 'q', 'r', 's'}},
      {'8', {'t', 'u', 'v'}}, {'9', {'w', 'x', 'y', 'z'}},
  };
};

int main() {
  std::string input = "234";
  auto ret = Solution{}.letterCombinations(input);
  PrintComplexSeries(ret);
  return 0;
}