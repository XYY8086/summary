#include "common.hpp"

#include <queue>
#include <vector>

std::vector<std::vector<int>> levelOrder(TreeNode *root) {
  if (root == nullptr) {
    return {};
  }
  std::deque<TreeNode *> q;
  q.push_back(root);
  std::vector<std::vector<int>> ret;
  while (!q.empty()) {
    int len = q.size(); // 当前层的节点数
    std::vector<int> level_nodes;
    for (int index = 0; index < len; ++index) {
      auto *node = q.front();
      q.pop_front();
      level_nodes.emplace_back(node->val);

      if (node->left) {
        q.push_back(node->left);
      }
      if (node->right) {
        q.push_back(node->right);
      }
    }

    ret.emplace_back(level_nodes);
  }
  return ret;
}