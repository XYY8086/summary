#include <stack>
#include <vector>

template <typename T> using vector = std::vector<T>;

class Solution {
public:
  int GetIndex(int val, int start_pos, const vector<int> &temperatures) {
    int fail = start_pos;
    while (start_pos < temperatures.size()) {
      if (temperatures[start_pos] > val) {
        return start_pos;
      }
      ++start_pos;
    }
    return fail;
  }
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    // 计算数组中下一次较大元素的位置
    std::vector<int> ret;
    for (int index = 0; index < temperatures.size(); ++index) {
      int val = temperatures[index];
      // 存在重复计算
      ret.push_back(GetIndex(val, index, temperatures) - index);
    }
    return ret;
  }

  vector<int> dailyTemperatures(vector<int> &temperatures) {
    if (temperatures.empty()) {
      return {};
    }
    std::stack<int> pos;
    std::vector<int> ret;
    ret.resize(temperatures.size());
    pos.push(0);
    for (int index = 1; index < temperatures.size(); ++index) {
      // 当前遍历的元素大于栈顶元素的时候,说明栈顶元素找到了目标位置
      while (!pos.empty() && temperatures[index] > temperatures[pos.top()]) {
        ret[pos.top()] = index - pos.top();
        pos.pop();
      }
      pos.push(index);
    }
    return ret;
  }
};