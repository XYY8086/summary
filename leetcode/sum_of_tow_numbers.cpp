#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    std::unordered_map<int, int> tmp;   // key: target - i; 如果i+j=target, 则 j=target - i, j在map中
    for(int index = 0; index < nums.size(); ++index){
        auto itr = tmp.find(nums[index]);
        if(itr != tmp.end()){
            return {index, itr->second};
        }
        tmp[target - nums[index]] = index;
    }
    return {};
  }

private:
  /// @brief 暴力解法,两次循环
  /// @param nums 
  /// @param target 
  /// @return 
  vector<int> solution1(vector<int> &nums, int target) {
    int len = nums.size();
    for (int i = 0; i < len - 1; ++i) {
      for (int j = i + 1; j < len; ++j) {
        if (nums[i] + nums[j] == target) {
          return {i, j};
        }
      }
    }
    return {};
  }
};

int main(int argc, char **argv) {
    std::vector<int>data{2,7,11,15};
    auto results = Solution{}.twoSum(data, 9);
    for(auto& val : results){
        std::cout << val << std::endl;
    }
}