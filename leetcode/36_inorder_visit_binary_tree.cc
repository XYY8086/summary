#include <stack>
#include <vector>

#include "common.hpp"

class Test {
public:
  std::vector<int> inorderTraversal(TreeNode *root) {
    nodes_.clear();
    inorder(root);
    return nodes_;
  }

  void inorder(TreeNode *root) {
    if (root == nullptr) {
      return;
    }
    inorder(root->left);
    nodes_.push_back(root->val);
    inorder(root->right);
  }

private:
  std::vector<int> nodes_;
};

std::vector<int> inorderTraversal(TreeNode *root) {
  if (!root) {
    return {};
  }
  std::vector<int> ret;
  std::stack<TreeNode *> q;

  TreeNode *current = root;

  while (current || !q.empty()) {
    if (current) {
      q.push(current);
      current = current->left;
    } else {
      auto *visited_node = q.top();
      q.pop();
      ret.push_back(visited_node->val);
      current = visited_node->right;
    }
  }
  return ret;
}

int main() { return 0; }