#include <vector>

#include "common.hpp"

ListNode *reverseList(ListNode *head) {
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

bool isPalindrome(ListNode *head) {
  if (head == nullptr) {
    return false;
  }
  // 反转链表的后半部分,然后同前半部分进行值对比
  ListNode *slow = head, *fast = head;
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
  }
  ListNode *reverse_node = reverseList(slow);
  ListNode *normal_node = head;
  while (reverse_node) {
    if (reverse_node->val != normal_node->val) {
      return false;
    }
    reverse_node = reverse_node->next;
    normal_node = normal_node->next;
  }
  return true;
}

int main() {
  ListNode *head = TransVectorToList({1, 3, 5, 3, 1});
  std::cout << isPalindrome(head) << std::endl;
  return 0;
}