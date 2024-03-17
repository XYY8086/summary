#include "common.hpp"

ListNode *removeNthFromEnd(ListNode *head, int n) {
  ListNode *fast = head, *slow = head;

  while (n--) {
    fast = fast->next;
  }
  // 此时删除的为头节点
  if (fast == nullptr) {
    return head->next;
  }
  // 定位到删除位置的前一个节点
  while (fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next;
  }
  slow->next = slow->next->next;
  return head;
}