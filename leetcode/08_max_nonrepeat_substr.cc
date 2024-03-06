#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    if (s.empty()) {
      return 0;
    }
    std::unordered_map<char, int>
        count; //  key;s中的元素ele val:ele最后出现的位置
    int max_val = 1;
    int left = 0; // 当前最长不重复串的起始位置
    for (int index = 0; index < s.size(); ++index) {
      auto itr = count.find(s[index]);
      // 出现重复,此时需要移动左侧指针,移动到重复元素的下一个位置
      if (itr != count.end()) {
        // a b b a, 重复元素的下标有可能在left左侧，所以这里取了一个max
        left = std::max(itr->second + 1, left);
      }
      count[s[index]] = index;
      max_val = std::max(max_val, index - left + 1);
    }
    return max_val;
  }

  int solution1(string s) {
    std::vector<char> count;
    int max_val = 0;
    for (char ele : s) {
      auto itr = std::find(count.begin(), count.end(), ele);
      // 如果发现重复,则从重复元素的下一个位置开始重新计算
      if (itr != count.end()) {
        count.erase(count.begin(), ++itr);
      }
      count.push_back(ele);
      max_val = std::max(max_val, int(count.size()));
    }
    return max_val;
  }
};

int main() {
  std::cout << Solution{}.lengthOfLongestSubstring("abcabcbb") << std::endl;
}