#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "common.hpp"

std::vector<int> findAnagrams(std::string s, std::string p) {
  if (s.size() < p.size()) {
    return {};
  }

  // 使用map存储词频、判断是否相等
  std::unordered_map<char, int> target_count;
  for (char ele = 'a'; ele <= 'z'; ++ele) {
    target_count[ele] = 0;
  }
  std::unordered_map<char, int> src_count = target_count;

  for (auto ele : p) {
    target_count[ele]++;
  }

  for (int index = 0; index < p.size(); ++index) {
    src_count[s[index]]++;
  }

  std::vector<int> ret;
  int left = 0;
  while (left <= s.size() - p.size()) {
    if (src_count == target_count) {
      ret.push_back(left);
    }

    // 窗口向右移动
    --src_count[s[left]];
    ++src_count[s[left + p.size()]];
    ++left;
  }
  return ret;
}

int main() {
  auto ret = findAnagrams("cbaebabacd", "abc");
  PrintSeries(ret);
  return 0;
}