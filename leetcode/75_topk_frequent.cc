#include <queue>
#include <unordered_map>
#include <vector>

#include "common.hpp"

// 获取nums数组中出现频率最高的k个数
std::vector<int> topKFrequent(std::vector<int> &nums, int k) {
  std::unordered_map<int, int> counts; // key: num val:频率
  for (int num : nums) {
    ++counts[num];
  }
  auto cmp_fcn = [](const std::pair<int, int> &left,
                    const std::pair<int, int> &right) {
    return left.second < right.second;
  };

  // 大根堆
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                      decltype(cmp_fcn)>
      q(cmp_fcn);

  for (auto itr : counts) {
    q.push(itr);
  }

  std::vector<int> ret;
  while (k-- > 0) {
    ret.push_back(q.top().first);
    q.pop();
  }

  return ret;
}

int main() {

  std::vector<int> vec{1, 1, 1, 2, 2, 3};

  auto ret = topKFrequent(vec, 2);
  PrintSeries(ret);
  return 0;
}
