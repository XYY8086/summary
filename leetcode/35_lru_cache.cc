#include <list>
#include <memory>
#include <unordered_map>

#include "common.hpp"

struct Node {
  int key;
  int val;
  std::shared_ptr<Node> pre = nullptr;
  std::shared_ptr<Node> next = nullptr;
};

class LRUCache {
public:
  LRUCache(int capacity) {
    capacity_ = capacity;
    used_ = 0;
    head_->next = tail_;
    tail_->pre = head_;
  }

  int get(int key) {
    auto itr = kv_.find(key);
    if (itr == kv_.end()) {
      return -1;
    }
    std::cout << "find key" << key << std::endl;
    auto current = itr->second;
    // 将当前节点从链表中删除
    remove_node(current);
    // 将当前节点插入到链表尾部
    insert_to_tail(current);
    return current->val;
  }

  void put(int key, int value) {
    auto itr = kv_.find(key);
    // 当前节点不存在,需要插入
    if (itr == kv_.end()) {
      if (used_ >= capacity_) {
        // 删除头节点
        std::cout << "remove node,key=" << head_->next->key << ",val=" << head_->next->val << std::endl;
        // remove之后 head->next 发生改变,所以这里存一个节点,为了能够删除map
        auto del_node = head_->next;
        remove_node(del_node);
        kv_.erase(del_node->key);
        --used_;
      }
      std::shared_ptr<Node> node = std::make_shared<Node>();
      node->key = key;
      node->val = value;
      // 新节点添加到尾部
      insert_to_tail(node);
      kv_[key] = node;
      ++used_;
      return;
    }
    // 当前节点已经存在,更新值
    auto current = itr->second;
    current->val = value;
    // 将当前节点从链表中删除
    remove_node(current);
    // 将当前节点插入到链表尾部
    insert_to_tail(current);
  }

  void insert_to_tail(std::shared_ptr<Node> node) {
    node->pre = tail_->pre;
    node->next = tail_;
    tail_->pre->next = node;
    tail_->pre = node;
  }

  void remove_node(std::shared_ptr<Node> current) {
    current->pre->next = current->next;
    current->next->pre = current->pre;
    current->pre = nullptr;
    current->next = nullptr;
  }

  void Debug() {
    auto p = head_->next;
    while (p != tail_) {
      std::cout <<"(" << p->key << "," <<p->val << "),";
      p = p->next;
    }
    std::cout << std::endl;
  }

private:
  int capacity_ = 0;
  int used_ = 0;

  std::shared_ptr<Node> head_ = std::make_shared<Node>();
  std::shared_ptr<Node> tail_ = std::make_shared<Node>();
  std::unordered_map<int, std::shared_ptr<Node>> kv_;
};

int main() {
  LRUCache cache = LRUCache(2);

  cache.put(1, 0);
  cache.put(2, 2);

  cache.Debug();
  cache.get(1);
  cache.Debug();
  cache.put(3, 3);
  cache.Debug();
  cache.get(2);
  cache.Debug();
  cache.put(4, 4);
  cache.Debug();
  cache.get(1);
  cache.Debug();
  cache.get(1);
  cache.get(3);
  cache.Debug();
  cache.get(4);
  cache.Debug();
  return 0;
}