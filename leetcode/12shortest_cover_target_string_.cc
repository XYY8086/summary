#include <limits.h>

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  bool equal(const std::unordered_map<char, int> &target,
             const std::unordered_map<char, int> &now) {
    for (auto itr : target) {
      auto it = now.find(itr.first);
      if (it == now.end() || it->second < itr.second) {
        return false;
      }
    }
    return true;
  }

  string minWindow(string s, string t) {
    std::unordered_map<char, int> count; // 目标串的词频
    for (char c : t) {
      ++count[c];
    }

    int start_pos = -1;                // 符合条件的子串起始位置
    int len = INT_MAX;                 // 符合条件的子串长度
    std::unordered_map<char, int> pre; // map中只存放s中的字符统计

    int left = 0; // left指向窗口左边,right指向窗口右边
    for (int right = 0; right < s.size(); ++right) {
      if (!count.count(s[right])) {
        continue;
      }
      ++pre[s[right]];
      // 检测当前当前窗口是否满足要求，不能直接使用map
      // .operator==(),实际上在窗口内ele出现次数大于target的中ele的词频也是OK的
      while (equal(count, pre) && left <= right) {
        if (right - left + 1 < len) {
          len = right - left + 1;
          start_pos = left;
        }
        // 左指针向右移动,同时修改词频map
        if (pre.count(s[left])) {
          --pre[s[left]];
        }
        ++left;
      }
    }
    return start_pos < 0 ? "" : s.substr(start_pos, len);
  }

  // 暴力解法 会超时,这是因为双重循环会对一些子序列进行重复计算
  string minWindow1(string s, string t) {
    std::unordered_map<char, int> count;
    for (char c : t) {
      ++count[c];
    }

    std::string ret;
    for (int i = 0; i < s.size(); ++i) {
      if (!count.count(s[i])) {
        continue;
      }
      std::unordered_map<char, int> pre;
      std::string tmp;
      for (int j = i; j < s.size(); ++j) {
        // 判断[i,j]的字串是否符合要求
        if (count.count(s[j]) && count[s[j]] != pre[s[j]]) {
          ++pre[s[j]];
        }
        tmp.push_back(s[j]);
        if (pre == count && (ret.empty() || tmp.size() < ret.size())) {
          ret = tmp;
          break;
        }
      }
    }
    return ret;
  }
};