#include "common.hpp"
#include <iostream>
#include <vector>

ListNode *reverseList1(ListNode *head) {
  if (!head || !head->next) {
    return head;
  }
  ListNode *pre = nullptr;
  ListNode *current = head;
  while (current) {
    auto *next = current->next;
    // 反转 pre -> current 到 current -> pre,
    // 因为后面要移动current,所以需要临时保存current->next
    current->next = pre;
    pre = current;
    current = next;
  }
  return pre;
}

ListNode *reverseList2(ListNode *head) {
  if (!head || !head->next) {
    return head;
  }
  // head之后的节点已经反转完毕  head -> tmp <- x1，
  // tmp实际上一直是反转链表的头节点
  auto *reverse_head = reverseList2(head->next);
  // head->next
  // 为已经反转的链表尾节点,将其指向head，也就是完成包括head在内的反转
  head->next->next = head;
  // 置空，避免出现环。这一步比较容易遗忘
  head->next = nullptr;

  return reverse_head;
}

int main() {
  std::vector<int> input{1, 2, 3, 4, 5};
  ListNode *head = new ListNode(-1);
  ListNode *p = head;
  for (int val : input) {
    p->next = new ListNode(val);
    p = p->next;
  }
  PrintLinkList(head->next);
  auto *ret = reverseList2(head->next);
  PrintLinkList(ret);
  return 0;
}