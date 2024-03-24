#include "common.hpp"

#include <stack>

int kthSmallest(TreeNode *root, int k) {

  std::stack<TreeNode *> q;
  TreeNode *current = root;

  while (!q.empty() || root != nullptr) {
    if (current) {
      q.push(current);
      current = current->left;
    } else {
      auto *node = q.top();
      q.pop();
      if (--k == 0) {
        return node->val;
      }
      current = current->right;
    }
  }

  return -1;
}