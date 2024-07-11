#ifndef S21_SET_H
#define S21_SET_H

#include <initializer_list>
#include <iostream>
#include <limits>
#include <stack>
#include <utility>

using namespace std;

template <typename T>
struct Node {
  T data;
  Node *left;
  Node *right;
  Node(T value) : data(value), left(nullptr), right(nullptr) {}
};

namespace s21 {
template <typename T>
class set {
 private:
  Node<T> *root;
  Node<T> *new_node;
  size_t current_;
  std::pair<Node<T> *, bool> insert_pv(Node<T> *node, const T &value) {
    if (!node) {
      current_++;
      new_node = new Node<T>(value);
      return {new_node, true};
    }
    if (value < node->data) {
      auto result = insert_pv(node->left, value);
      node->left = result.first;
      return {node, result.second};
    } else if (value > node->data) {
      auto result = insert_pv(node->right, value);
      node->right = result.first;
      return {node, result.second};
    } else {
      new_node = node;
      return {new_node, false};
    }
  }

  void print_pv(Node<T> *node) {
    if (node != nullptr) {
      print_pv(node->left);
      cout << node->data << " ";
      print_pv(node->right);
    }
  }
  void delete_pv(Node<T> *node) {
    if (node != nullptr) {
      delete_pv(node->left);
      delete_pv(node->right);
      delete node;
    }
  }
  Node<T> *erase_pv(Node<T> *node, const T &val) {
    if (node == nullptr) return node;

    if (val < node->data) {
      node->left = erase_pv(node->left, val);
    } else if (val > node->data) {
      node->right = erase_pv(node->right, val);
    } else {
      if (node->left == nullptr) {
        Node<T> *right_child = node->right;
        delete node;
        return right_child;
      } else if (node->right == nullptr) {
        Node<T> *left_child = node->left;
        delete node;
        return left_child;
      }

      Node<T> *min_node = find_min(node->right);
      node->data = min_node->data;
      node->right = erase_pv(node->right, min_node->data);
    }
    return node;
  }
  Node<T> *find_min(Node<T> *node) {
    while (node and node->left) node = node->left;
    return node;
  }
  Node<T> *find_max(Node<T> *node) {
    while (node and node->right) node = node->right;
    return node;
  }
  void swap_pv(set &other) {
    set<T> temp = std::move(other);
    other = std::move(*this);
    *this = std::move(temp);
  }
  void merge_pv(set &other) {
    if (this != &other) {
      for (auto it = other.begin(); it != other.end(); ++it) {
        insert(std::move(*it));
      }
      other.root = nullptr;
    }
  }

 public:
  // Итератор класса
  class iterator {
   public:
    iterator(Node<T> *root) {
      // push_left(root);
      if (root) {
        while (root) {
          nodes.push(root);
          root = root->left;
        }
        current = nodes.top();
        nodes.pop();
      }
    }
    T &operator*() const { return current->data; }
    iterator &operator++() {
      if (current == nullptr && !nodes.empty()) {
        current = nodes.top();
        nodes.pop();
      } else if (current != nullptr) {
        if (current->right) {
          push_left(current->right);
        } else {
          while (!nodes.empty() && nodes.top()->right == current) {
            current = nodes.top();
            nodes.pop();
          }
          if (!nodes.empty()) {
            current = nodes.top();
            nodes.pop();
          } else {
            current = nullptr;
          }
        }
      }
      return *this;
    }
    iterator &operator--() {
      if (current == nullptr && !nodes.empty()) {
        current = nodes.top();
        nodes.pop();
      } else if (current != nullptr) {
        if (current->left) {
          push_right(current->left);
        } else {
          while (!nodes.empty() && nodes.top()->left == current) {
            current = nodes.top();
            nodes.pop();
          }
          if (!nodes.empty()) {
            current = nodes.top();
            nodes.pop();
          } else {
            current = nullptr;
          }
        }
      }
      return *this;
    }
    bool operator!=(const iterator &other) const {
      return current != other.current;
    }
    bool operator==(const iterator &other) const {
      return current == other.current;
    }
    Node<T> *get_node() const { return this->current; }

   private:
    Node<T> *current = nullptr;
    std::stack<Node<T> *> nodes;

    void push_left(Node<T> *node) {
      while (node) {
        nodes.push(node);
        node = node->left;
      }
      if (!nodes.empty()) {
        current = nodes.top();
        nodes.pop();
      }
    }
    void push_right(Node<T> *node) {
      while (node) {
        nodes.push(node);
        node = node->right;
      }
      if (!nodes.empty()) {
        current = nodes.top();
        nodes.pop();
      }
    }
  };
  /*
    ОСНОВНЫЕ ПУБЛИЧНЫЕ МЕТОДЫ ДЛЯ ВЗАИМОДЕЙСТВИЯ С КЛАССОМ:
  */
  // default constructor, creates empty set
  set() : root(nullptr), current_(0) {}
  // initializer list constructor, creates the set initizialized using
  // std::initializer_list
  set(std::initializer_list<T> const &items) : set() {
    for (auto &i : items) this->insert(i);
  }
  // copy constructor
  set(const set &s) : set() {
    for (auto it = s.begin(); it != s.end(); ++it) {
      this->insert(*it);
    }
    this->current_ = s.current_;
  }
  // move constructor
  set(set &&s) noexcept : root(s.root), current_(s.current_) {
    s.root = nullptr;
    s.current_ = 0;
  }
  // destructor
  ~set() { clear(); }
  // assignment operator overload for moving object
  set &operator=(set &&s) noexcept {
    if (this != &s) {
      delete_pv(root);
      this->root = s.root;
      this->current_ = s.current_;
      s.root = nullptr, s.current_ = 0;
    }
    return *this;
  }

  /*
    ПУБЛИЧНЫЕ МЕТОДЫ ДЛЯ ДОСТУПА К ИНФОРМАЦИИ О НАПОЛНЕНИИ КОНТЕЙНЕРА:
  */
  // checks whether the container is empty
  bool empty() { return this->root == nullptr; }
  // returns the number of elements
  size_t size() { return this->current_; }
  // returns the maximum possible number of elements
  size_t max_size() const {
    return std::numeric_limits<size_t>::max() / sizeof(Node<T>);
  }

  /*
  ПУБЛИЧНЫЕ МЕТОДЫ ДЛЯ ИЗМЕНЕНИЯ КОНТЕЙНЕРА:
  */
  // clears the contents
  void clear() {
    delete_pv(root);
    this->root = nullptr;
    this->current_ = 0;
  }
  // inserts node and returns iterator to where the element is in the container
  // and bool denoting whether the insertion took place
  std::pair<s21::set<T>::iterator, bool> insert(const T &value) {
    auto result = insert_pv(root, value);
    root = result.first;
    return {iterator(new_node), result.second};
  }

  // Вставляет новые элементы в контейнер.
  template <typename... Args>
  std::vector<std::pair<s21::set<T>::iterator, bool>> insert_many(
      Args &&...args) {
    std::vector<std::pair<s21::set<T>::iterator, bool>> result;
    (result.push_back(this->insert(std::forward<Args>(args))), ...);
    return result;
  }
  // erases element at pos
  void erase(iterator pos) { root = erase_pv(root, pos.get_node()->data); }
  // swaps the contents
  void swap(set &other) { swap_pv(other); }
  // splices nodes from another container
  void merge(set &other) { merge_pv(other); }

  /*
  ПУБЛИЧНЫЕ МЕТОДЫ ДЛЯ ИТЕРИРОВАНИЯ ПО ЭЛЕМЕНТАМ КЛАССА
  */
  // returns an iterator to the beginning
  iterator begin() const { return iterator(root); }
  // returns an iterator to the end
  iterator end() const { return iterator(nullptr); }

  iterator begin() { return iterator(root); }
  iterator end() { return iterator(nullptr); }

  /*
    ПУБЛИЧНЫЕ МЕТОДЫБ ОСУЩЕСТВЛЯЮШИЕ ПРОСМОТР КОНТЕЙНЕРА:
  */
  // finds element with specific key
  iterator find(const T &key) {
    for (auto it = this->begin(); it != this->end(); ++it) {
      if (*it == key) return it;
    }
    return end();
  }
  // checks if the container contains element with specific key
  bool contains(const T &key) {
    for (auto it = this->begin(); it != this->end(); ++it) {
      if (*it == key) return true;
    }
    return false;
  }
  void print() {
    if (root) print_pv(root), cout << endl;
  }
};
}  // namespace s21

#endif