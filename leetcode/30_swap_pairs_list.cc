#include <memory>

#include "common.hpp"

ListNode *swapPairs1(ListNode *head) {
  if (head == nullptr || head->next == nullptr) {
    return head;
  }

  ListNode *pre = head, *current = head->next, *last_node = nullptr,
           *ret = head->next;

  while (pre && pre->next) {
    // 确定pre current节点
    current = pre->next;
    // 保存next节点,便于继续向下迭代
    auto *next = current->next;
    // 反转指针
    current->next = pre;
    pre->next = next;
    if (last_node) {
      last_node->next = current;
    }

    last_node = pre;

    // pre指针继续移动
    pre = next;
  }
  return ret;
}

ListNode *swapPairs(ListNode *head) {
  if (head == nullptr || head->next == nullptr) {
    return head;
  }
  std::shared_ptr<ListNode> mock = std::make_shared<ListNode>();
  mock->next = head;
  ListNode *pre = mock.get(), *current, *next;

  while (pre->next && pre->next->next) {
    // 确定pre current next节点
    current = pre->next;
    next = current->next;
    // 反转指针
    pre->next = next;
    current->next = next->next;
    next->next = current;
    // pre指针继续移动
    pre = current;
  }
  return mock->next;
}