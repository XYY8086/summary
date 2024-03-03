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