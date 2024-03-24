#include "common.hpp"

int result = 0;
int dfs(TreeNode *root) {
  if (root == nullptr) {
    return 0;
  }
  int left = dfs(root->left);   // 左子树的深度
  int right = dfs(root->right); // 右子树的深度
                                // left + right 为当前root节点的直径
  result = result > (left + right)
               ? result
               : (left + right); // 比较每个节点的直径,取最大值
  return (left > right ? left : right) + 1; // 返回当前节点的最大深度
}

int diameterOfBinaryTree(TreeNode *root) {
  dfs(root);
  return result;
}
