#include <memory>

#include "common.hpp"

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
  ListNode *ptr1 = list1, *ptr2 = list2;
  std::shared_ptr<ListNode> head = std::make_shared<ListNode>();
  ListNode *p = head.get(); // p->next指向val小的节点
  while (ptr1 && ptr2) {
    if (ptr1->val < ptr2->val) {
      p->next = ptr1;
      ptr1 = ptr1->next;
    } else {
      p->next = ptr2;
      ptr2 = ptr2->next;
    }
    p = p->next;
  }

  p->next = (ptr1 == nullptr) ? ptr2 : ptr1;

  return head->next;
}

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
  if (list1 == nullptr) {
    return list2;
  }
  if (list2 == nullptr) {
    return list1;
  }

  if (list1->val < list2->val) {
    // list1对应的值较小 继续向后递归
    list1->next = mergeTwoLists(list1->next, list2);
    return list1;
  } else {
    list2->next = mergeTwoLists(list1, list2->next);
    return list2;
  }
}