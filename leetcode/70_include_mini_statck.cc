#include <algorithm>
#include <iostream>
#include <stack>

class MinStack {
public:
  MinStack() {}

  void push(int val) {
    vals.push(val);
    // 当前值如果小于栈顶元素则入栈，否则copy栈顶元素
    minis.push(minis.empty() ? val : std::min(minis.top(), val));
  }

  void pop() {
    vals.pop();
    minis.pop();
  }

  int top() { return vals.top(); }

  int getMin() { return minis.top(); }

private:
  std::stack<int> vals;
  std::stack<int> minis; // 存放当前最小值
};