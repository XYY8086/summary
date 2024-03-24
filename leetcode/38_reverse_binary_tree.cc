#include <queue>

#include "common.hpp"

TreeNode *invertTree(TreeNode *root) {
  if (root == nullptr) {
    return root;
  }
  // 这里也可以写成尾递归,先交换当前节点的左右子树,再往下递归
  auto *left_ret = invertTree(root->left);
  auto *right_ret = invertTree(root->right);
  root->left = right_ret;
  root->right = left_ret;
  return root;
}

TreeNode *invertTree(TreeNode *root) {
  if (root == nullptr) {
    return root;
  }
  std::deque<TreeNode *> q;
  q.push_back(root);
  while (!q.empty()) {
    auto *current = q.front();
    auto *left = current->left;
    current->left = current->right;
    current->right = left;

    if (current->left) {
      q.push_back(current->left);
    }
    if (current->right) {
      q.push_back(current->right);
    }

    q.pop_front();
  }

  return root;
}