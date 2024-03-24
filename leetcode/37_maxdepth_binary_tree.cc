#include <iostream>

#include <queue>

#include "common.hpp"
#include <algorithm>

int maxDepth(TreeNode *root) {
  if (root == nullptr) {
    return 0;
  }
  return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

int maxDepth(TreeNode *root) {
  if (root == nullptr) {
    return 0;
  }
  std::deque<TreeNode *> q;
  q.push_back(root);

  int ret = 0;
  while (!q.empty()) {
    int len = q.size(); // 当前层的节点数
    for (int i = 0; i < len; ++i) {
      auto *node = q.front();
      if (node->left) {
        q.push_back(node->left);
      }
      if (node->right) {
        q.push_back(node->right);
      }
      q.pop_front();
    }
    ++ret;
  }
  return ret;
}