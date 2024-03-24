#include <iostream>
#include <memory>
#include <unordered_map>

class Node {
public:
  int val;
  Node *next;
  Node *random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

Node *copyRandomList(Node *head) {
  if (head == nullptr) {
    return nullptr;
  }
  std::shared_ptr<Node> copy_link = std::make_shared<Node>(-1);
  Node *p = copy_link.get();
  // key 原链表节点地址, val copy出来的链表地址
  std::unordered_map<Node *, Node *> mapping{{nullptr, nullptr}};
  Node *ori = head;
  // 第一次遍历,将简单链表拷贝出来
  while (ori) {
    p->next = new Node(ori->val);
    mapping.emplace(ori, p->next);
    p = p->next;
    ori = ori->next;
  }
  // 第二次遍历,连接random指针
  ori = head;
  p = copy_link->next;
  while (ori) {
    p->random = mapping[ori->random];
    ori = ori->next;
    p = p->next;
  }

  return copy_link->next;
}

Node *copyRandomList(Node *head) {
  // 1. copy一份链表连接在原链表的后面
  Node *p = head;
  while (p) {
    auto *next = p->next;
    p->next = new Node(p->val);
    p->next->next = next;
    p = next;
  }
  // 2. 连接random指针
  p = head;
  while (p) {
    auto *cur = p->next;
    cur->random = p->random == nullptr ? nullptr : p->random->next;
    p = cur->next;
  }

  // 3. 断开连接
  Node *ret = head->next;
  p = head;
  while (p) {
    auto* next = p->next->next;
    auto *new_node = p->next;
    p->next = new_node->next;
    new_node->next = new_node->next == nullptr ? nullptr : new_node->next->next;

    p = next;
  }

  return ret;
}
