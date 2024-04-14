#include <unordered_map>

#include "common.hpp"

// 以root为起点的所有路径和
int rootSum(TreeNode *root, int64_t targetSum) {
  if (root == nullptr) {
    return 0;
  }
  int ret = 0;
  if (targetSum == root->val) {
    ret++;
  }
  // 当前节点+左子树组成的路径
  ret += rootSum(root->left, targetSum - root->val);
  // 当前节点+右子树组成的路径
  ret += rootSum(root->right, targetSum - root->val);
  return ret;
}

int pathSum(TreeNode *root, int targetSum) {
  if (root == nullptr) {
    return 0;
  }
  // 每个节点有两种选择,当前节点加入路径、不加入路径
  // 1. 当前节点计入路径
  int ret = rootSum(root, targetSum);
  // 2. 当前节点不计入路径
  ret += pathSum(root->left, targetSum);
  ret += pathSum(root->right, targetSum);

  return ret;
}

class Solution {
public:
  int pathSum(TreeNode *root, int targetSum) {
    if (root == nullptr) {
      return 0;
    }

    return dfs(root, 0, targetSum);
  }

  int dfs(TreeNode *root, int currentSum, int targetSum) {
    if (root == nullptr) {
      return 0;
    }

    //  如果存在前缀和为 currentSum - targetSum, 也就所有同样存在一个从 node(k)
    //  -> current_node的路径和为 targetSum
    currentSum += root->val;

    int ret = 0;
    if (prefix_.count(currentSum - targetSum)) {
      ret = prefix_[currentSum - targetSum];
    }
    // 当前节点加入路径
    ++prefix_[currentSum];
    ret += dfs(root->left, currentSum, targetSum);
    ret += dfs(root->right, currentSum, targetSum);
    // 当前节点退出路径
    --++prefix_[currentSum];
    return ret;
  }

private:
  // 保存从root->node(k) 的所有前缀和 key:前缀和 val:频次
  std::unordered_map<int64_t, int> prefix_ = {{0, 1}};
};