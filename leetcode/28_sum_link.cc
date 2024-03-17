#include <memory>

#include "common.hpp"

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
  ListNode *ptr1 = l1, *ptr2 = l2;

  int res = 0;
  std::shared_ptr<ListNode> head = std::make_shared<ListNode>();
  ListNode *p = head.get();
  while (ptr1 || ptr2) {
    int sum = (ptr1 == nullptr ? 0 : ptr1->val) +
              (ptr2 == nullptr ? 0 : ptr2->val) + res;
    res = sum >= 10 ? 1 : 0;

    p->next = new ListNode(sum % 10);
    p = p->next;

    ptr1 = ptr1 == nullptr ? nullptr : ptr1->next;
    ptr2 = ptr2 == nullptr ? nullptr : ptr2->next;
  }

  if (res) {
    p->next = new ListNode(res);
  }

  return head->next;
}