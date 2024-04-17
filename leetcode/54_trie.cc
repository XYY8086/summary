#include <iostream>
#include <memory>
#include <queue>
#include <string>
#include <unordered_map>

class Trie {
public:
  struct Node {
    std::unordered_map<char, Node *> children;
    bool is_end = false;
  };

  Trie() { root = new Node(); }

  ~Trie() {
    std::deque<Node *> q;
    q.push_back(root);

    while (!q.empty()) {
      auto *node = q.front();
      q.pop_front();
      for (auto itr : node->children) {
        q.push_back(itr.second);
      }
      delete node;
    }
  }

  void insert(std::string word) {
    Node *current = root;
    for (char ch : word) {
      auto itr = current->children.find(ch);
      if (itr == current->children.end()) {
        // 当前节点不存在这个字符,插入
        current->children.emplace(ch, new Node());
      }
      current = current->children[ch];
    }
    current->is_end = true;
  }

  bool search(std::string word) {
    auto *node = GetNode(word);
    return node != nullptr && node->is_end;
  }

  bool startsWith(std::string prefix) { return GetNode(prefix) != nullptr; }

private:
  Node *GetNode(const std::string &word) {
    if (word.empty()) {
      return nullptr;
    }
    Node *current = root;
    for (char ch : word) {
      auto itr = current->children.find(ch);
      if (itr == current->children.end()) {
        return nullptr;
      }
      current = current->children[ch];
    }
    return current;
  }

  Node *root;
};

int main() {
  Trie *tree = new Trie();
  tree->insert("apple");
  tree->insert("app");

  std::cout << tree->search("appl") << std::endl;
  std::cout << tree->startsWith("appl") << std::endl;
}