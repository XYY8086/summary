#include "common.hpp"

#include <vector>

// 将排序数组转换成平衡搜索二叉树
TreeNode *sortedArrayToBST(std::vector<int> &nums) {
  return sortedArrayToBST(nums, 0, nums.size() - 1);
}

TreeNode *sortedArrayToBST(std::vector<int> &nums, int left, int right) {
  if (left > right) {
    return nullptr;
  }
  int mid = (left + right) / 2;
  TreeNode *current = new TreeNode(nums[mid]);
  current->left = sortedArrayToBST(nums, left, mid - 1);
  current->right = sortedArrayToBST(nums, mid + 1, right);
  return current;
}
