# 后端开发

## leetcode

### 01 两数之和

[两数之和](https://leetcode.cn/problems/two-sum/description/?envType=study-plan-v2&envId=top-100-liked)

### 02 字母异或词分组

[字母异或词分组](https://leetcode.cn/problems/group-anagrams/description/?envType=study-plan-v2&envId=top-100-liked)

### 03 最长连续数字序列

[最长连续序列](https://leetcode.cn/problems/longest-consecutive-sequence/?envType=study-plan-v2&envId=top-100-liked)

```text
输入：nums = [100,4,200,1,3,2]
输出：4
解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。

思路: 这个题目要求时间复杂度为O(n), 所以就不能最输入序列最排序或者使用红黑树的结构存储
方法1: 先使用hash map存储, 再一次遍历原数组，尽可能从序列的最小元素可以计算最长序列(当前元素n,若n-1在map中 则直接跳过)
方法2: dp[k]表示k元素所在最长序列长度, dp[k]=dp[k-1]+dp[k+1], 每次更新dp时只需要更新当前位置、新拼接序列的起始和结束位置。重复元素不再进行计算
```

### 04 移动0元素

[移动零](https://leetcode.cn/problems/move-zeroes/submissions/507246693/?envType=study-plan-v2&envId=top-100-liked)

```text
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
请注意 ，必须在不复制数组的情况下原地对数组进行操作
输入: nums = [0,1,0,3,12]
输出: [1,3,12,0,0]
思路:
慢指针指向0元素位置,快指针指向非0元素位置
```

### 05 盛最多水的容器

[盛最多水的容器](https://leetcode.cn/problems/container-with-most-water/description/?envType=study-plan-v2&envId=top-100-liked)

![示例](https://aliyun-lc-upload.oss-cn-hangzhou.aliyuncs.com/aliyun-lc-upload/uploads/2018/07/25/question_11.jpg)

```text
双指针情况下，需要明确:
- 头尾指针分别指向开始和结尾，这样每次移动时容器宽度都是减小的
- 判断移动左指针还是右指针，只有移动短的边才**有可能**使容量变大。 (3, 6), 若移动长边->(3, 1)(容量变小) (3, 4)(容量不变) (3, 7)(容量不变),
  若移动短边 -> (1, 6)(容量变小)  (4, 6)(容量变大) (8, 6)(容量变大)
```

### 06 三数之和

[三数之和](https://leetcode.cn/problems/3sum/description/?envType=study-plan-v2&envId=top-100-liked)

```text
题目要求不重复,所以重点在于如何去重，如果时服用两数之和的思路，是行不通的。
关键在于认识到先对数组排序，接着再递增数组上使用双指针做两数之和，同时注意在找到一组元素时，最相邻元素去重。
```

### 07 接雨水

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


### 08 最长不重复的字串

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

### 09 寻找所有的字母异位词

[寻找所有的字母异位词](https://leetcode.cn/problems/find-all-anagrams-in-a-string/description/?envType=study-plan-v2&envId=top-100-liked)

```text
使用map或者vector统计目标字符的词频,判断map或vector是否相等也就是判断两个串是否为异位词。窗口大小固定，每次出一个元素进入一个元素，相应的修改词频
```