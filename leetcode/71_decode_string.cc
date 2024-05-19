#include <iostream>
#include <stack>
#include <string>

using string = std::string;

class Solution {
public:
  std::string RepeatString(int num, const std::string &input) {
    std::string ret;
    for (int i = 0; i < num; ++i) {
      ret.append(input);
    }
    return ret;
  }

  std::string GetNum(const std::string &input, int &index) {
    std::string ret;
    while (index < input.size() && isdigit(input[index])) {
      ret += input[index++];
    }
    return ret;
  }
  std::string GetSting(const std::string &input, int &index) {
    std::string ret;
    while (index < input.size() && isalpha(input[index])) {
      ret += input[index++];
    }
    return ret;
  }

  string decodeString(string s) {
    if (s.empty()) {
      return "";
    }
    int len = s.size();
    int index = 0;
    while (index < len) {
      char c = s[index];
      if (isdigit(c)) {
        // 当前字符为数字
        data.push(GetNum(s, index));
      } else if (isalpha(c)) {
        // 当前字符为英文字母
        data.push(GetSting(s, index));
      } else if (c == '[') {
        // 起始语法
        data.push(std::string{c});
        ++index;
      } else {
        // ] 表示 终止语法,此时需要对表达式进行计算
        ++index;
        // 查找 [] 内的字符串
        std::string val;
        while (data.top() != "[") {
          val = data.top() + val;
          data.pop();
        }
        data.pop();
        // 查找重复次数
        int num = atoi(data.top().c_str());
        data.pop();
        // 获取新字符 3 a -> aaa
        std::string result = RepeatString(num, val);
        data.push(result);
      }
    }

    std::string ret;
    while (!data.empty()) {
      ret = data.top() + ret;
      data.pop();
    }
    return ret;
  }

private:
  std::stack<string> data;
};

int main(int argc, char **argv) {
  std::cout << Solution{}.decodeString("3[a]2[bc]") << std::endl;
  return 0;
}