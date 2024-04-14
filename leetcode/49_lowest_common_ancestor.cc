#include "common.hpp"

class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    // p q有一个节点等于root时，则公共节点就是root
    if (!root || p == root || q == root) {
      return root;
    }

    // 求左子树中p q的公共祖先
    auto *left = lowestCommonAncestor(root->left, p, q);
    auto *right = lowestCommonAncestor(root->right, p, q);

    // 左子树中p q不存在公共祖先,则返回右子树
    if (!left) {
      return right;
    }
    // 右子树中p q不存在公共祖先,则返回左子树
    if (!right) {
      return left;
    }
    // 左右子树中p q的公共祖先都不为空,则返回 两个子树的根节点root
    return root;
  }
};