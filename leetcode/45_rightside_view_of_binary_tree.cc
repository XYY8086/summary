#include <queue>
#include <vector>

#include "common.hpp"

std::vector<int> rightSideView(TreeNode *root) {
  if (root == nullptr) {
    return {};
  }
  std::vector<int> ret;
  std::deque<TreeNode *> q;
  q.push_back(root);
  while (!q.empty()) {
    int len = q.size();
    while (len != 1) {
      auto *current = q.front();
      q.pop_front();
      if (current->left) {
        q.push_back(current->left);
      }
      if (current->right) {
        q.push_back(current->right);
      }
      --len;
    }
    auto *current = q.front();
    ret.push_back(current->val);
    q.pop_front();
    if (current->left) {
      q.push_back(current->left);
    }
    if (current->right) {
      q.push_back(current->right);
    }
  }
  return ret;
}
