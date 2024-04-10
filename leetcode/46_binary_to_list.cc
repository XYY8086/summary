
#include <stack>
#include <vector>

#include "common.hpp"
/*
将2叉树按照前序遍历的方式转换成链表
*/
void flatten(TreeNode *root) {
  // 按照前序遍历获取所有节点,然后将节点的左子树置空,右子树指向下一个节点
  std::stack<TreeNode *> q;
  TreeNode *current = root;
  std::vector<TreeNode *> nodes;
  while (!q.empty() || current) {
    if (current) {
      nodes.push_back(current);
      q.push(current);
      current = current->left;
    } else {
      auto *node = q.top();
      q.pop();
      current = node->right;
    }
  }

  // 遍历节点，左子树置空，右子树连接到下一个节点
  for (int index = 1; index < nodes.size(); ++index) {
    nodes[index - 1]->left = nullptr;
    nodes[index - 1]->right = nodes[index];
  }
}

void flatten1(TreeNode *root) {
  // 在前序遍历后再连接指针的方法中，需要使用额外的数组保存节点。那么能够不适用额外的空间呢
  // 当我们再遍历一个节点current时，我们需要将current->left = nullptr,current->right = next_node
  // 所以我们需要寻找current节点再前序遍历中的下一个节点；同时由于
  // current->right要发生改变，为了防止右子树丢失
  // 我们需要把右子树连接到正确节点上，根据前序遍历的特点，右子树应当连接到左子树的最后一个节点上。
  // 所以我们的思路是:
  // 1. 假设当前正在遍历的节点为current,如果左子树空,则已经满足 current->left = nullptr, current->right = next_node
  // 2. 若左子树不为空,需要虚招左子树在前序遍历中的最后一个节点 next_node
  // 3. next_node->nright = current->right; current->left = nullptr; current->right = next_node
  // 4. current = current->right
  TreeNode *current = root;
  while (current) {
    if (current->left) {
      TreeNode *p = current->left;
      // 左子树的最后一个节点为左子树的最后一个右节点
      while (p->right) {
        p = p->right;
      }
      // 将右子树接上去
      p->right = current->right;
      // current->left = nullptr, current->right = next_node
      current->right = current->left;
      current->left = nullptr;
    }
    current = current->right;
  }
}