#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#include "common.hpp"

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    if (intervals.empty()) {
      return {};
    }
    std::sort(intervals.begin(), intervals.end(),
              [](const vector<int> &left, const vector<int> &right) {
                return left[0] < right[0];
              });
    vector<vector<int>> ret{intervals[0]};
    int index = 1;
    while (index < intervals.size()) {
      if (intervals[index][0] <= ret.back()[1]) {
        ret.back()[1] = std::max(intervals[index][1], ret.back()[1]);
      } else {
        ret.push_back(intervals[index]);
      }
      ++index;
    }
    return ret;
  }
};

int main() {
  vector<vector<int>> input{{1, 3}, {2, 6}, {8, 10}, {15, 18}};
  PrintComplexSeries(Solution{}.merge(input));
}