#include <iostream>
#include <vector>

class Solution {
public:
  //   int maxProfit(std::vector<int> &prices) {
  //     int ret = 0;
  //     for (int index = 0; index < prices.size(); ++index) {
  //       // 第index买入 pos天卖出得到的利润
  //       for (int pos = index + 1; pos < prices.size(); ++pos) {
  //         ret = std::max(prices[pos] - prices[index], ret);
  //       }
  //     }
  //     return ret;
  //   }

  int maxProfit(std::vector<int> &prices) {
    if (prices.empty()) {
      return 0;
    }
    int ret = 0;
    int min_input = prices[0]; // 买入的最低价格

    for (int index = 1; index < prices.size(); ++index) {
      // 截止到第index天，最低买入价格是多少
      min_input = std::min(min_input, prices[index]);

      // 第index天卖出时的利润
      ret = std::max(ret, prices[index] - min_input);
    }
    return ret;
  }
};

int main() {
  std::vector<int> vec{7, 1, 5, 3, 6, 4};

  std::cout << Solution{}.maxProfit(vec) << std::endl;

  return 0;
}
