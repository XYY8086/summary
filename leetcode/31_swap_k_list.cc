#include <memory>

#include "common.hpp"

ListNode *reverse(ListNode *head) {
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

ListNode *reverseKGroup(ListNode *head, int k) {
  // p 指针用于遍历链表
  // start end 记录反转区间
  // last记录的是已经完成反转的链表尾部
  // ret为返回值,实际是第一次完成区间反转的头节点
  ListNode *p = head, *start = head, *end = nullptr, *ret = nullptr,
           *last = nullptr;
  int num = 0;
  while (p) {
    ++num;
    // 当前区间的链表需要反转
    if (num % k == 0) {
      // 明确当前段链表的起始节点[start, end]
      end = p;
      auto *next = end->next;
      // 为了能正常反转,这里需要对链表做截断,截断之前需要保证next
      end->next = nullptr;
      // 反转 [start, end] -> [end, start]
      reverse(start);
      // 连接起来, start这时候位于反转后的最后一个节点
      // 将反转后的链表加入到之前整个链表中
      if (last) {
        last->next = end;
      }
      start->next = next;
      // 记录返回值
      ret = ret == nullptr ? end : ret;
      // 更新,此时p为了继续向下迭代,指向当前最后一个元素
      p = last = start;
      start = next;
    }
    p = p->next;
  }
  return ret;
}

int main() {
  ListNode *head = TransVectorToList({1, 2, 3, 4, 5, 6, 7});
  auto *ret = reverseKGroup(head, 3);
  PrintLinkList(ret);
  return 0;
}
