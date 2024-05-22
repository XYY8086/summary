#include <limits.h>
#include <queue>
#include <vector>

#include "common.hpp"

constexpr int kMaxNums = 1e5;

class MedianFinder {
public:
  MedianFinder() {}

  void addNum(int num) {
    // min_q 存小于中位数的部分
    if (min_q.empty() || num <= min_q.top()) {
      // 当前值已经小于 min_q中最大的数,说明min_q要更新
      min_q.push(num);
      if (max_q.size() + 1 < min_q.size()) {
        max_q.push(min_q.top());
        min_q.pop();
      }

    } else {
      // max_q 存大于中位数的部分
      max_q.push(num);
      if (min_q.size() < max_q.size()) {
        min_q.push(max_q.top());
        max_q.pop();
      }
    }
  }

  double findMedian() {
    return (min_q.size() + max_q.size()) & 1
               ? min_q.top()
               : (min_q.top() + max_q.top()) / 2.0;
  }

private:
  std::priority_queue<int, std::vector<int>, std::less<int>>
      min_q; // 大根堆 -> 存较小的数
  std::priority_queue<int, std::vector<int>, std::greater<int>>
      max_q; // 小根堆->存较大的数
};

int main() {
  MedianFinder val;
  return 0;
}