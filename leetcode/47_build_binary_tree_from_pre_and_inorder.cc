#include <algorithm>
#include <iostream>
#include <vector>

#include "common.hpp"

TreeNode *buildTree(std::vector<int> &preorder, std::vector<int> &inorder) {
  if (preorder.empty()) {
    return nullptr;
  }
  TreeNode *current = new TreeNode(preorder[0]);
  // 当前值在中序遍历中出现的位置
  auto inorder_itr = std::find(inorder.begin(), inorder.end(), preorder[0]);
  // 获取中序遍历的前后两段内容
  std::vector<int> inorder_left_vec(inorder.begin(), inorder_itr);
  std::vector<int> inorder_right_vec(inorder_itr + 1, inorder.end());
  // 获取先序遍历的前后两端内容,前半段内容等于 [1, inorder_itr] 后半段
  // [inorder_itr, END]
  std::vector<int> preorder_left_vec(preorder.begin() + 1,
                                     preorder.begin() +
                                         (inorder_itr - inorder.begin()) + 1);
  std::vector<int> preorder_right_vec(
      preorder.begin() + (inorder_itr - inorder.begin()) + 1, preorder.end());

  current->left = buildTree(preorder_left_vec, inorder_left_vec);
  current->right = buildTree(preorder_right_vec, inorder_right_vec);
  return current;
}

int main() {

  std::vector<int> vec{1, 2, 3, 4};
  auto inorder_itr = std::find(vec.begin(), vec.end(), 2);

  std::cout << inorder_itr - vec.begin() << std::endl;

  std::vector<int> vec2(vec.begin(), vec.begin() + 1);

  PrintSeries(vec2);
}