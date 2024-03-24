#include <limits>
#include <stack>

// #include <bits/stdint-intn.h>

#include "common.hpp"

bool isValidBST(TreeNode *root, int64_t left, int64_t right) {
  if (root == nullptr) {
    return true;
  }
  // 1. 当前节点满足  left < val < right
  // 2. 后续左子树满足 val -> [left, current->val]
  // 3. 后续右子树满足 val -> [current->val, right]
  return root->val < right && root->val > left &&
         isValidBST(root->left, left, root->val) &&
         isValidBST(root->right, root->val, right);
}

bool isValidBST(TreeNode *root) {
  // 最初的想法是先验证一个小树 A B C 是否满足 B < A < C，
  // 然后依次递归，但是这种情况无法满足整棵树的大小关系
  // 正确的思路是验证一个节点是否true,判断当前节点的值是否在理想区间内
  return isValidBST(root, std::numeric_limits<int64_t>::min(),
                    std::numeric_limits<int64_t>::max());
}

// 中序遍历,依次递增
bool isValidBST(TreeNode *root){
    if(root == nullptr){return true;}

    std::stack<TreeNode*> q;
    TreeNode* current = root;
    // 保存上一个节点的值
    int64_t last_num = std::numeric_limits<int64_t>::min();
    while(!q.empty() || current){
        if(current){
            q.push(current);
            current = current->left;
        }else{
            auto* node = q.top();
            q.pop();
            // 比较当前节点的值是否大于上一个节点的值
            if(node->val <= last_num){
                return false;
            }
            last_num = node->val;
            current = node->right;
        }
    }
    return true;
}
