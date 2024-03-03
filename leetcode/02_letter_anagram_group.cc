#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "common.hpp"

using namespace std;

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    std::unordered_map<string, std::vector<string>> s;  // key, 排序后的单词 val: 同一组的词
    for (int index = 0; index < strs.size(); ++index) {
      std::string origin = strs[index];
      std::sort(strs[index].begin(), strs[index].end());
      auto itr = s.find(strs[index]);
      s[strs[index]].emplace_back(origin);
    }
    vector<vector<string>> ret;
    for (auto itr : s) {
      ret.emplace_back(itr.second);
    }
    return ret;
  }
};

int main(){
    std::vector<std::string> input{"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> results = Solution{}.groupAnagrams(input);
    PrintComplexSeries<vector<vector<string>>>(results);
}