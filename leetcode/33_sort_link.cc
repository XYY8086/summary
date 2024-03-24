#include <memory>
#include <vector>

#include "common.hpp"

int GetLength(ListNode *head) {
  ListNode *p = head;
  int ret = 0;
  while (p) {
    ++ret;
    p = p->next;
  }
  return ret;
}

// [l1, l2) [l2,final]
// 合并两个区间,并返回链表的头尾节点
std::pair<ListNode *, ListNode *> mergeList(ListNode *list1, ListNode *list2,
                                            ListNode *final) {
  if (list1 == nullptr) {
    return {list2, final};
  }
  if (list2 == nullptr) {
    return {list1, list2};
  }
  std::shared_ptr<ListNode> _p = std::make_shared<ListNode>(-1);
  ListNode *p = _p.get();
  ListNode *p1 = list1, *p2 = list2,
           *over_node = final == nullptr ? nullptr : final->next;
  while (p1 != list2 && p2 != over_node) {
    if (p1->val < p2->val) {
      p->next = p1;
      p1 = p1->next;
    } else {
      p->next = p2;
      p2 = p2->next;
    }
    p = p->next;
  }
  auto *res = p1 == list2 ? p2 : p1;
  auto *final_node = p1 == list2 ? over_node : list2;
  while (res->next != final_node) {
    p->next = res;
    p = p->next;
    res = res->next;
  }
  p->next = res;
  p->next->next = over_node;
  return {_p->next, res};
}

ListNode *mergeList2(ListNode *list1, ListNode *list2) {
  ListNode *p1 = list1, *p2 = list2;
  std::shared_ptr<ListNode> _p = std::make_shared<ListNode>(-1);
  ListNode *p = _p.get();
  while (p1 && p2) {
    if (p1->val < p2->val) {
      p->next = p1;
      p1 = p1->next;
    } else {
      p->next = p2;
      p2 = p2->next;
    }
    p = p->next;
  }
  p->next = p1 == nullptr ? p2 : p1;
  return _p->next;
}

ListNode *sortList2(ListNode *head) {
  if (head == nullptr || head->next == nullptr) {
    return head;
  }
  ListNode *p = head;
  int len = GetLength(head);
  ListNode *ret = head; // ret 存储每次排序结束的头节点位置
  // index 表示当前参与排序的两个链表的长度
  for (int index = 1; index < len; index = 2 * index) {
    p = ret;
    std::cout << "******************" << index << ",start=" << p->val
              << ",list=";
    PrintLinkList(p);
    ListNode *list1 = p, *list2 = nullptr;
    std::shared_ptr<ListNode> __ = std::make_shared<ListNode>(0);
    // connect 用于连接本次排序后的链表
    ListNode *connect = __.get();
    while (p) {
      list1 = p;
      // 寻找 list2
      for (int i = 1; i < index && p->next; ++i) {
        p = p->next;
      }
      list2 = p->next;
      // 将list1 截断成独立链表
      p->next = nullptr;

      // 寻找final
      p = list2;
      for (int i = 1; i < index && p && p->next; ++i) {
        p = p->next;
      }
      auto *final = p ? p->next : nullptr;
      // 将list2 截断成独立链表
      if (p != nullptr) {
        p->next = nullptr;
      }

      std::cout << "sort info=" << list1->val << ","
                << (list2 == nullptr ? "null" : std::to_string(list2->val))
                << ","
                << (final == nullptr ? "null" : std::to_string(final->val))
                << std::endl;
      // 对两段有序部分进行合并
      auto sorted_list = mergeList2(list1, list2);

      // 将本次排序的子链表连接起来
      connect->next = sorted_list;
      // 找到有序链表的尾节点,用于下一次连接两个有序的部分
      while (connect->next) {
        connect = connect->next;
      }
      // p指针移动到下一个待排序的位置
      p = final;
    }

    std::cout << "##################" << index << ",after sort=";
    PrintLinkList(__->next);
    ret = __->next;
  }
  return ret;
}

ListNode *sortList(ListNode *head) {
  if (head == nullptr || head->next == nullptr) {
    return head;
  }
  ListNode *p = head;
  int len = GetLength(head);
  ListNode *ret = head; // ret 存储每次排序结束的头节点位置

  for (int index = 1; index < len; index = 2 * index) {
    p = ret;
    std::cout << "******************" << index << ",start=" << p->val
              << ",list=";
    PrintLinkList(p);
    ListNode *list1 = p, *list2 = nullptr, *final = nullptr;
    std::shared_ptr<ListNode> __ = std::make_shared<ListNode>(0);
    ListNode *connect = __.get();
    while (p) {
      list1 = p;
      // 寻找 list2
      for (int i = 0; i < index && p != nullptr; ++i) {
        p = p->next;
      }
      list2 = p;
      // 寻找final
      for (int i = 1; i < index && p != nullptr; ++i) {
        p = p->next;
      }
      final = p;
      std::cout << "sort info=" << list1->val << ","
                << (list2 == nullptr ? "null" : std::to_string(list2->val))
                << ","
                << (final == nullptr ? "null" : std::to_string(final->val))
                << std::endl;
      auto head_tail = mergeList(list1, list2, final);
      // 将本次排序的子链表连接起来
      connect->next = head_tail.first;
      connect = head_tail.second;
      p = connect == nullptr ? nullptr : connect->next;

      // getchar();
    }

    std::cout << "##################" << index << ",after sort=";
    PrintLinkList(__->next);
    ret = __->next;
  }
  return ret;
}

int main() {
  ListNode *p = TransVectorToList({-1, 5, 3, 4, 0});
  //   PrintLinkList(p);
  //   auto ret = mergeList(p, p->next->next, p->next->next->next);
  //   PrintLinkList(ret.first);
  //   PrintLinkList(ret.second);
  auto *ret = sortList2(p);
  return 0;
}