#include <memory>
#include <vector>

#include <math.h>

#include "common.hpp"

ListNode *mergeTowLists(ListNode *list1, ListNode *list2) {
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

ListNode *mergeKLists(std::vector<ListNode *> &lists) {
  ListNode *ret = lists[0];

  for (int index = 1; index < lists.size(); ++index) {
    ret = mergeTowLists(ret, lists[index]);
  }

  return ret;
}

ListNode *mergeKLists(std::vector<ListNode *> &lists) {
  ListNode *ret = lists[0];
  int len = lists.size();
  int step = 1;
  for (int i = 0; i < std::ceil(std::log2(len)); ++i) {
    for (int index = 0; index < lists.size(); index += 2 * step) {
      // 参与合并的两个节点之间距离为step
      lists[index] = mergeTowLists(lists[index], index + step >= lists.size()
                                                     ? nullptr
                                                     : lists[index + step]);
    }
    step = 2*step;
  }
  return ret;
}