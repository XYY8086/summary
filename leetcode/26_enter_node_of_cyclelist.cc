#include "common.hpp"

ListNode *detectCycle(ListNode *head) {
  if (head == nullptr || head->next == nullptr) {
    return nullptr;
  }
  ListNode *slow = head, *fast = head->next;

  while (slow != fast) {
    if (fast == nullptr || fast->next == nullptr) {
      return nullptr;
    }
    slow = slow->next;
    fast = fast->next->next;
  }
  ListNode *length_helper = head; // 这里赋值的时候相当于已经走了一步
  slow = slow->next;
  while (length_helper != slow) {
    length_helper = length_helper->next;
    slow = slow->next;
  }

  return slow;
}