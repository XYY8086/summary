#include <stack>
#include <string>
#include <unordered_map>
// ()[]{}
bool isValid(std::string s) {
  if (s.empty()) {
    return false;
  }
  std::unordered_map<char, char> char_map{{'(', ')'}, {'[', ']'}, {'{', '}'}};
  std::stack<char> q;
  for (int index = 0; index < s.size(); ++index) {
    if (char_map.count(s[index])) {
      // 当前时左括号,直接入栈
      q.push(s[index]);
      continue;
    }
    // 当前是右括号
    if (q.empty()) {
      return false;
    }
    char current = q.top();
    // 当前右括号和上一个左括号步匹配
    if (char_map[current] != s[index]) {
      return false;
    }
    q.pop();
  }

  return q.empty();
}

int main(int argc, char **argv) { return 0; }