#include <limits.h>

#include "common.hpp"

class Solution {
public:
  int ans = INT_MIN;
  int maxPathSum(TreeNode *root) {
    if (!root) {
      return 0;
    }
    max_path(root);

    return ans;
  }

  // 计算以root为起点的最大路径和
  int max_path(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    // 左子树中的最大路径和
    int left = std::max(max_path(root->left), 0);
    // 右子树中的最大路径和
    int right = std::max(max_path(root->right), 0);
    // 选择一条最大的路径
    // 1. 如果左右子树有小于0的结果，直接丢弃
    // 2. 如果都大于0， 左右子树都添加到结果中
    ans = std::max(ans, root->val + left + right);

    // 以当前节点为起点的路径，最大值要选择一个子树
    return root->val + std::max(left, right);
  }
};