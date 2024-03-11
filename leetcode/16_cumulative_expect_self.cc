#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> tail_results(nums.size(), nums.back());
        for(int index = nums.size() -2; index >=0; --index){
            tail_results[index] = tail_results[index+1]*nums[index];
        }

        int head_result  = 1;
        for(int index = 0; index < nums.size(); ++index){
            int right_val = index + 1 < nums.size() ? tail_results[index+1] : 1;
            int left_val =  index - 1 >= 0 ? head_result : 1;
            tail_results[index] = right_val * left_val;
            head_result *= nums[index];
        }

        return tail_results;
    }
};