#include "common.hpp"

bool isSymmetric(TreeNode *root) { return isSymmetric(root, root); }

bool isSymmetric(TreeNode *left, TreeNode *right) {
  if (!left && right || (left && !right)) {
    return false;
  }
  if (!left && !right) {
    return true;
  }
  return (left->val == right->val) && isSymmetric(left->right, right->left) &&
         isSymmetric(left->left, right->right);
}