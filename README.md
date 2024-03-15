- [leetcode100](#leetcode100)
  - [01 两数之和](#01-两数之和)
  - [02 字母异或词分组](#02-字母异或词分组)
  - [03 最长连续数字序列](#03-最长连续数字序列)
  - [04 移动0元素](#04-移动0元素)
  - [05 盛最多水的容器](#05-盛最多水的容器)
  - [06 三数之和](#06-三数之和)
  - [07 接雨水](#07-接雨水)
  - [08 最长不重复的字串](#08-最长不重复的字串)
  - [09 寻找所有的字母异位词](#09-寻找所有的字母异位词)
  - [10 和为k的子数组](#10-和为k的子数组)
    - [1.暴力解法](#1暴力解法)
    - [2.保存求和结果](#2保存求和结果)
    - [3.使用map代替数组](#3使用map代替数组)
    - [4.优化之后的一次遍历](#4优化之后的一次遍历)
  - [11 滑动窗口内的最大值](#11-滑动窗口内的最大值)
  - [12 最小覆盖子串](#12-最小覆盖子串)
  - [13 最大子数组和](#13-最大子数组和)
    - [暴力求解](#暴力求解)
    - [动态规划](#动态规划)
  - [14 合并区间](#14-合并区间)
  - [15 轮转数组](#15-轮转数组)
    - [内存拷贝](#内存拷贝)
    - [多次反转](#多次反转)
  - [16 除自身之外的累积结果](#16-除自身之外的累积结果)
  - [17 数组中缺失的第一个正数](#17-数组中缺失的第一个正数)
    - [hash表](#hash表)
    - [将元素放到正确位置上](#将元素放到正确位置上)
  - [18 矩阵置零](#18-矩阵置零)
    - [使用额外标记数组](#使用额外标记数组)
    - [在原数组中存储标记信息](#在原数组中存储标记信息)

# leetcode100

## 01 两数之和

[两数之和](https://leetcode.cn/problems/two-sum/description/?envType=study-plan-v2&envId=top-100-liked)

## 02 字母异或词分组

[字母异或词分组](https://leetcode.cn/problems/group-anagrams/description/?envType=study-plan-v2&envId=top-100-liked)

## 03 最长连续数字序列

[最长连续序列](https://leetcode.cn/problems/longest-consecutive-sequence/?envType=study-plan-v2&envId=top-100-liked)

```text
输入：nums = [100,4,200,1,3,2]
输出：4
解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。

思路: 这个题目要求时间复杂度为O(n), 所以就不能最输入序列最排序或者使用红黑树的结构存储
方法1: 先使用hash map存储, 再一次遍历原数组，尽可能从序列的最小元素可以计算最长序列(当前元素n,若n-1在map中 则直接跳过)
方法2: dp[k]表示k元素所在最长序列长度, dp[k]=dp[k-1]+dp[k+1], 每次更新dp时只需要更新当前位置、新拼接序列的起始和结束位置。重复元素不再进行计算
```

## 04 移动0元素

[移动零](https://leetcode.cn/problems/move-zeroes/submissions/507246693/?envType=study-plan-v2&envId=top-100-liked)

```text
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
请注意 ，必须在不复制数组的情况下原地对数组进行操作
输入: nums = [0,1,0,3,12]
输出: [1,3,12,0,0]
思路:
慢指针指向0元素位置,快指针指向非0元素位置
```

## 05 盛最多水的容器

[盛最多水的容器](https://leetcode.cn/problems/container-with-most-water/description/?envType=study-plan-v2&envId=top-100-liked)

![示例](https://aliyun-lc-upload.oss-cn-hangzhou.aliyuncs.com/aliyun-lc-upload/uploads/2018/07/25/question_11.jpg)

```text
双指针情况下，需要明确:
- 头尾指针分别指向开始和结尾，这样每次移动时容器宽度都是减小的
- 判断移动左指针还是右指针，只有移动短的边才**有可能**使容量变大。 (3, 6), 若移动长边->(3, 1)(容量变小) (3, 4)(容量不变) (3, 7)(容量不变),
  若移动短边 -> (1, 6)(容量变小)  (4, 6)(容量变大) (8, 6)(容量变大)
```

## 06 三数之和

[三数之和](https://leetcode.cn/problems/3sum/description/?envType=study-plan-v2&envId=top-100-liked)

```text
题目要求不重复,所以重点在于如何去重，如果时服用两数之和的思路，是行不通的。
关键在于认识到先对数组排序，接着再递增数组上使用双指针做两数之和，同时注意在找到一组元素时，最相邻元素去重。
```

## 07 接雨水

[接雨水](https://leetcode.cn/problems/trapping-rain-water/description/?envType=study-plan-v2&envId=top-100-liked)

```text
最开始的想法是，每次寻找一个凹槽(先降后升)，计算槽内的蓄水量，但是后面发现，当前槽的高度会受后面槽的影响。
做这个题目首先要明确, k位置的蓄水量实际上是由左右两侧最高的墙决定的。所以我们的目标就是取计算每个位置左右两侧height的最大值。
计算k左侧的最大值,需要从左到右遍历数组, 计算k右侧的最大值则需要从右到左遍历数组。
最简单的可以直接两次循环计算出两个数组存放left_max,right_max;
进而,我们发现[left_max] 从左向右递增,[right_max]从右到左递增,可以使用双指针在遍历时同时计算出水位,设左指针位置ptr1,右指针位置ptr2,
此时我们能计算出 ptr1的{left_max, x}, ptr2的{y, right_max},已知ptr1<ptr2, x >= right_max, y>=left_max 若此时left_max < right_max,则 left_max < right_max <=x,
也就是说ptr1位置的墙高为left_max,同理若 left_max >= right_max，则 y>=left_max >= right_max， ptr2的墙高为 right_max
```


## 08 最长不重复的字串

[最长不重复的字串](https://leetcode.cn/problems/longest-substring-without-repeating-characters/description/?envType=study-plan-v2&envId=top-100-liked)

```text
输入: s = "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

在统计到重复元素时，此时的遍历位置应该重置到该位置的下一位，同时子串进行删除或者标记。例如遍历到index=3时发现右重复字符'a'，此时字串起点应该向前移动到index=2位置
```
```C++
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    if (s.empty()) {
      return 0;
    }
    //  key;s中的元素ele val:ele最后出现的位置
    std::unordered_map<char, int> count; 
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
```

## 09 寻找所有的字母异位词

[寻找所有的字母异位词](https://leetcode.cn/problems/find-all-anagrams-in-a-string/description/?envType=study-plan-v2&envId=top-100-liked)

```text
使用map或者vector统计目标字符的词频,判断map或vector是否相等也就是判断两个串是否为异位词。窗口大小固定，每次出一个元素进入一个元素，相应的修改词频
```

## 10 和为k的子数组

[和为k的子数组](https://leetcode.cn/problems/subarray-sum-equals-k/?envType=study-plan-v2&envId=top-100-liked)

```
给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的子数组的个数。
子数组是数组中元素的连续非空序列。
输入：nums = [1,2,3], k = 3
输出：2 存在{1, 2} {3}两个序列
```

### 1.暴力解法
直接计算所有子序列的和,此时的时间复杂度为n^2
```C++
int subarraySum(vector<int> &nums, int k) {
  int ret = 0;
  for (int i = 0; i < nums.size(); ++i) {
    // 计算从i开始的所有子序列的和
    int sum = 0;
    for (int j = i; j < nums.size(); ++j) {
      sum += nums[j];
      if (sum == k) {
        ++ret;
      }
    }
  }
  return ret;
}
```

### 2.保存求和结果

显然,在暴力解法中我们存在多次计算子序列和,i < j < k 时, k开始的子序列和被计算了多次。
那么我们想到计算一次保存起来dp[i] 表示[i, END] i开始到结尾的子序列和。
**若存在一个区间 [i,j]的和为t,则右这样的关系 dp[i]-dp[j]+nums[j]=t,其中 i<=j**,那么显然我们从后向前遍历一次即可

![[i,j]区间的和](./leetcode/img/连续子序列和.png)


```C++
int subarraySum2(vector<int> &nums, int k) {
  int ret = 0;
  std::vector<int> dp(nums.size()); // dp[i] 表示从i开始到结尾的子序列长度
  int sum = 0;
  for (int i = nums.size() - 1; i >= 0; --i) {
    sum += nums[i];
    dp[i] = sum;
  }

  for (int index = nums.size() - 1; index >= 0; --index) {
    int diff = dp[index] + k - nums[index];
    // dp[i]=dp[j]+k-nums[j],其中i<j, 显然dp[i]的值可以直接求出来，剩下的就是判断dp[i]是否真的在求和数组中
    auto itr = std::find(dp.begin(), dp.end(), diff);
    if (itr != dp.end() && (itr - dp.begin()) <= index) {
      ++ret;
    }
  }
  return ret;
}
```

### 3.使用map代替数组
在方法2中我们使用了数组保存求和的结果，但是在从右向左遍历时，每一次都要在数组中查找是否真的存在这个值，以及这个值的下标是否符合条件。对于查找问题，显然我们更希望通过map实现

我们需要解决的问题有下面几个:
- map是保存求和结果的,所以key是和，那么val是什么呢
- 我们需要保存下标信息，帮助我们判断 i < j 这种关系
- 我们在遍历的时候需要根据下标得到求和结果
最简单的想法，map key保存的是和,val保存的是子序列的起始位置(可能多个子序列的和相同)；同时使用一个数组保存求和结果，便于根据下标得到和

```c++
int subarraySum3(vector<int>& nums, int k) {
    int ret = 0;
    std::unordered_map<int, std::vector<int>> count; // key:sum val:子序列的起始位置
    std::vector<int> sum_vec(nums.size(), 0);
    int sum = 0;
    for(int i = nums.size() - 1; i >=0 ; --i){
        sum += nums[i];
        count[sum].push_back(i);
        sum_vec[i]=sum;
    }

    for(int index = nums.size() - 1; index >=0; --index){
        int diff = sum_vec[index] + k - nums[index];
        auto itr = count.find(diff);
        if(itr == count.end()){
            continue;
        }
        for(auto ele : itr->second){
            ret += (ele <= index);
        }
    }
    return ret;
}
```

### 4.优化之后的一次遍历
但从方法3的写法上看，显然 sum_vec数组是多余的，因为从右向左遍历时，我们可以顺便计算出dp[i]
```C++
int ret = 0;
std::unordered_map<int, std::vector<int>> count; // key:sum val:子序列的起始位置
int sum = 0;
for(int i = nums.size() - 1; i >=0 ; --i){
    sum += nums[i];
    count[sum].push_back(i);

}

int sum_vec = 0;
for(int index = nums.size() - 1; index >=0; --index){
    sum_vec += nums[index];
    int diff = sum_vec + k - nums[index];
    auto itr = count.find(diff);
    if(itr == count.end()){
        continue;
    }
    for(auto ele : itr->second){
        ret += (ele <= index);
    }
}
return ret;
```

进一步我们想，从右到左遍历，我们希望 i < j, 也就是说满足条件的 i 在遍历时可能还没办法计算出来。那么我们先把我们的期望值存起来，再向左计算的过程中看看是否出现了期望值
```C++
int ret = 0;
int current_sum = 0;
std::unordered_map<int , int> predicted;  // key 希望的子序列和, val:有多少个位置希望前方能出现这个和
for(int index = nums.size() - 1; index >=0; --index){
    current_sum += nums[index]; // current_sum表示的是 [index, END]子序列的和，也就是dp[index]
    int diff = current_sum + k - nums[index]; // diff 表示满足条件时，dp[x]的值，其中 0 <=x <=index,因为我们的迭代顺序,x显然时满足[0, index]的
    predicted[diff]++;  // 将这个值放入期望map中
    auto itr = predicted.find(current_sum);
    if(itr != predicted.end()){ // 当前的dp[index]能够满足 [index,END]的期望
        ret += itr->second;
    }
}
return ret;
```

## 11 滑动窗口内的最大值

[滑动窗口内的最大值](https://leetcode.cn/problems/sliding-window-maximum/?envType=study-plan-v2&envId=top-100-liked)

```text
输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
输出：[3,3,5,5,6,7]
解释：
滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

难点在于如何在O(1)复杂度内找到当前窗口内的最大值
思路: 比较关键的时需要认识到 i< j, nums[j] >= nums[i],i,j都在一个窗口内时,nums[i]不可能时窗口内的最大值。
- 可以使用双端队列(头部到尾部非递增)，保存下标，来保证队列内为窗口内的元素
- 满足上述条件时，删除元素
- 对头为当前窗口最大值

当前也可以使用大根堆实现,取堆顶元素时判断是否超出窗口
```

## 12 最小覆盖子串

[最小覆盖子串](https://leetcode.cn/problems/minimum-window-substring/?envType=study-plan-v2&envId=top-100-liked)

```text
输入：s = "ADOBECODEBANC", t = "ABC"
输出："BANC"
解释：最小覆盖子串 "BANC" 包含来自字符串 t 的 'A'、'B' 和 'C'。
```

暴力解法中,验证每个子序列,存在一些字串的信息被重复计算的情况。而使用滑动窗口,当前子串的信息始终包含在窗口内,移动滑动时更新这些信息，无需双重循环。
```C++
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
```

## 13 最大子数组和

[最大子数组和](https://leetcode.cn/problems/maximum-subarray/description/?envType=study-plan-v2&envId=top-100-liked)

```text
输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
输出：6
解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
```

### 暴力求解

又是子序列的问题,首先想到的是暴力求解,求和所有子序列的和。
```C++
int maxSubArray(vector<int> &nums) {
  int ret = INT_MIN;
  for (int i = 0; i < nums.size(); ++i) {
    int sum = 0;
    for (int j = i; j < nums.size(); ++j) {
      sum += nums[j];
      ret = std::max(ret, sum);
    }
  }
  return ret;
}
```

### 动态规划

暴力求解的时候，由于我们是从左到右遍历,对于序列[i, j]会重复计算多次这个序列的和。那么我们自然想到使用数组保存dp[i][j]保存[i,j]序列的和，
但是即便是这样。在第二层循环中我们需要找到dp[i, j], i<=j<=nums.size()==END 中的最大值，显然时间复杂度没有变化。所以我们更想更快的知道[i，END]范围内最大和的子序列.
而[i,END]范围内的最大和S(i)显然依赖于[i-1,END]范围内的最大和S(i-1),可见一个有状态依赖的动态规划出来了。
dp[i]表示[i,END]最大和,则dp[i] = nums[i], dp[i-1] <0,否则dp[i] = dp[i-1]+nums[i]
```C++
int maxSubArray(vector<int>& nums) {
  int ret = nums.back();
  int last_sum = nums.back();
  for(int index = nums.size() - 2; index >=0; --index){
      last_sum = nums[index] + (last_sum < 0 ? 0 : last_sum);
      ret = std::max(last_sum, ret);
  }
  return ret;
}
``` 

## 14 合并区间

[合并区间](https://leetcode.cn/problems/merge-intervals/description/?envType=study-plan-v2&envId=top-100-liked)

```text
输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
输出：[[1,6],[8,10],[15,18]]
解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
```

按照数组中的左边界进行排序,然后依次合并。


## 15 轮转数组

[轮转数组](https://leetcode.cn/problems/rotate-array/description/?envType=study-plan-v2&envId=top-100-liked)

```text
输入: nums = [1,2,3,4,5,6,7], k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右轮转 1 步: [7,1,2,3,4,5,6]
向右轮转 2 步: [6,7,1,2,3,4,5]
向右轮转 3 步: [5,6,7,1,2,3,4]
```

### 内存拷贝

![内存拷贝](./leetcode/img/轮转数组.png)

需要提前将尾部的数据保存起来。
```C++
void rotate1(vector<int> &nums, int k) {
  if (nums.empty() || ((k % nums.size()) == 0)) {
    return;
  }
  int res = k % nums.size();
  std::vector<int> tail_nums(nums.begin() + nums.size() - res, nums.end());
  // 注意这里的nums.data() 返回的是 int*, 而第三个参数是字节为单位
  memmove(nums.data() + res, nums.data(), (nums.size() - res) * sizeof(int));
  memmove(nums.data(), tail_nums.data(), tail_nums.size() * sizeof(int));
}
```

### 多次反转

```C++
void rotate(vector<int> &nums, int k) {
  if (nums.empty() || ((k % nums.size()) == 0)) {
    return;
  }
  int res = k % nums.size();
  // 首先全部反转
  reverse(nums, 0, nums.size() - 1);
  // 然后依次反转前后两端内容
  reverse(nums, 0, res - 1);
  reverse(nums, res, nums.size() - 1);
}
```

## 16 除自身之外的累积结果

[除自身以外数组的乘积](https://leetcode.cn/problems/product-of-array-except-self/description/?envType=study-plan-v2&envId=top-100-liked)

```text
输入: nums = [1,2,3,4]
输出: [24,12,8,6]
```

dp[i] 保存 [i, END]的累积结果。然后从左到右遍历的时候可以计算[0, i]的累积结果, 两者相乘得到该位置上的结果。

```C++
vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> tail_results(nums.size(), nums.back());
    for(int index = nums.size() -2; index >=0; --index){
        tail_results[index] = tail_results[index+1]*nums[index];
    }

    int head_result  = 1;
    // 这里也可以使用额外的数组保存最后的结果；但是我们注意到 每次计算results[index]时只使用了tail_results[index+1]，也就是可以直接复用tail_results
    for(int index = 0; index < nums.size(); ++index){
        int right_val = index + 1 < nums.size() ? tail_results[index+1] : 1;
        int left_val =  index - 1 >= 0 ? head_result : 1;
        tail_results[index] = right_val * left_val;
        head_result *= nums[index];
    }

    return tail_results;
}
```

## 17 数组中缺失的第一个正数

[数组中缺失的第一个正数](https://leetcode.cn/problems/first-missing-positive/description/?envType=study-plan-v2&envId=top-100-liked)

```text
给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。
输入：nums = [3,4,-1,1]
输出：2
解释：1 在数组中，但 2 没有。
```

### hash表

数组元素存入hash表,方便O(1)时间查找某个元素是否缺失


### 将元素放到正确位置上

对于一个长度为n的数组,合理的数值范围是[1, n],那么我们通过遍历数组将array[i] 不断交换尝试放到[i+1]位置上.最后遍历数组查看哪个位置不满足 array[i] = i+1

```C++
for (int index = 0; index < nums.size(); ++index) {
  // 当前位置不满足 nums[i] == i + 1,尝试交换到正确位置上
  while (nums[index] != index + 1) {
    // 为防止因为缺失数据引起的无限循环,需要提前终止
    if (nums[index] <= 0 || nums[index] > nums.size() ||
        nums[index] == nums[nums[index] - 1]) {
      break;
    }
    // 交换 nums[i] 到其理想位置nums[i] - 1 上
    std::swap(nums[index], nums[nums[index] - 1]);
  }
}
for (int index = 0; index < nums.size(); ++index) {
  if (nums[index] != index + 1) {
    return index + 1;
  }
}
return nums.size() + 1;
```

## 18 [矩阵置零](https://leetcode.cn/problems/set-matrix-zeroes/description/?envType=study-plan-v2&envId=top-100-liked)


给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。

### 使用额外标记数组

使用两个数组分别记录哪些行和哪些列存在0元素,然后一次遍历矩阵,若该位置有对应的行列0标记,则置0
```C++
void setZeroes(std::vector<std::vector<int>> &matrix) {
  if (matrix.empty()) {
    return;
  }
  // 标记哪些行和哪些列存在0元素，空间复杂度O(m+n),时间复杂度O(m*n)
  std::vector<bool> row_flags(matrix.size(), false);
  std::vector<bool> col_flags(matrix[0].size(), false);

  for (int row = 0; row < matrix.size(); ++row) {
    for (int col = 0; col < matrix[0].size(); ++col) {
      row_flags[row] = row_flags[row] || (matrix[row][col] == 0);
      col_flags[col] = col_flags[col] || (matrix[row][col] == 0);
    }
  }

  for (int row = 0; row < matrix.size(); ++row) {
    for (int col = 0; col < matrix[0].size(); ++col) {
      // 该元素所在的行或者列存在0元素,则该元素置零
      if (row_flags[row] || col_flags[col]) {
        matrix[row][col] = 0;
      }
    }
  }
}
```

### 在原数组中存储标记信息

使用元组中的某一行存储哪些列有0标记,使用某一列存储哪些行有0标记。此时有个问题,用于标记的这个行和列是无法表达自身是否具有0元素的，所以需要额外使用两个变量记录这个信息。
```C++
void setZeroes(std::vector<std::vector<int>> &matrix) {
  if (matrix.empty()) {
    return;
  }
  // 我们能否把标记数组放到原矩阵中？
  // 由于后续第一行和第一列需要存储标记位,最后无法确定第一行，第一列本身是否包含0,所以这项信息需要存储下来
  bool set_row = false, set_col = false;
  // 遍历第一列,看看第一列自身是否存在0元素
  for (int index = 0; index < matrix.size(); ++index) {
    if (matrix[index][0] == 0) {
      set_col = true;
      break;
    }
  }
  // 遍历第一行,看看第一行自身是否存在0元素
  for (int index = 0; index < matrix[0].size(); ++index) {
    if (matrix[0][index] == 0) {
      set_row = true;
      break;
    }
  }

  // 遍历除去标记行列的其他位置,设置标记位，储存在原矩阵的第一行和第一列
  for (int row = 1; row < matrix.size(); ++row) {
    for (int col = 1; col < matrix[0].size(); ++col) {
      if (matrix[row][col] == 0) {
        matrix[0][col] = 0; // 存储哪些列有0
        matrix[row][0] = 0; // 存储哪些行有0
      }
    }
  }

  for (int row = 1; row < matrix.size(); ++row) {
    for (int col = 1; col < matrix[0].size(); ++col) {
      // 该元素所在的行或者列存在0元素,则该元素置零
      if (matrix[row][0] == 0 || matrix[0][col] == 0) {
        matrix[row][col] = 0;
      }
    }
  }
  // 判断第一列
  if (set_col) {
    for (int index = 0; index < matrix.size(); ++index) {
      matrix[index][0] = 0;
    }
  }
  // 判断第一行
  if (set_row) {
    for (int index = 0; index < matrix[0].size(); ++index) {
      matrix[0][index] = 0;
    }
  }
}
```
