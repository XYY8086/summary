#include <iostream>
#include <vector>

template <typename T> void PrintSeries(const T &input, char sep = ',') {
  for (const auto &itr : input) {
    std::cout << itr << sep;
  }
  std::cout << std::endl;
}

template <typename T> void PrintComplexSeries(const T &input, char sep = ',') {
  for (const auto &itr : input) {
    PrintSeries<decltype(itr)>(itr, sep);
  }
  std::cout << std::endl;
}

template <typename T> void PrintPairs(const T &input, char sep = ',') {
  for (const auto &itr : input) {
    std::cout << itr.first << sep
              << PrintSeries<decltype(itr.second)>(itr.second, sep);
  }
  std::cout << std::endl;
}

template <typename T> void PrintLinkList(const T *input, char sep = ',') {
  const T *head = input;
  while (head) {
    std::cout << head->val << sep;
    head = head->next;
  }
  std::cout << std::endl;
}

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode *TransVectorToList(const std::vector<int> &input) {
  ListNode *head = nullptr, *p = nullptr;
  for (int index = 0; index < input.size(); ++index) {
    if (index == 0) {
      head = new ListNode(input[index]);
      p = head;
      continue;
    }

    p->next = new ListNode(input[index]);
    p = p->next;
  }
  return head;
}

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};