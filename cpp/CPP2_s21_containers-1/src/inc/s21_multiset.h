#ifndef MULTISET_H
#define MULTISET_H

#include <iso646.h>

#include <initializer_list>
#include <iostream>
#include <set>
#include <stack>

namespace s21 {
template <typename T>
struct Node {
  T data;
  Node<T> *left;
  Node<T> *right;
  Node(T value) : data(value), left(nullptr), right(nullptr) {}
};

template <typename T>
class multiset {
 public:
  class iterator {
   public:
    iterator(Node<T> *root) { push_left(root); }
    T &operator*() const { return current->data; }
    iterator &operator++() {
      if (current->right) {
        push_left(current->right);
      } else {
        while (!nodes.empty() and nodes.top()->right == current) {
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
          Node<T> *parent = nullptr;
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
  // default constructor, creates empty set
  multiset() : root(nullptr), current_(0) {}
  // initializer list constructor, creates the set initizialized using
  // std::initializer_list
  multiset(std::initializer_list<T> const &items) : multiset() {
    for (auto &i : items) insert(i);
  }
  // copy constructor
  multiset(const multiset &ms) : multiset() {
    if (this != &ms)
      for (auto &i : ms) this->insert(i);
  }
  // move constructor
  multiset(multiset &&ms) : root(ms.root), current_(ms.current_) {
    ms.root = nullptr, ms.current_ = 0;
  }
  // destructor
  ~multiset() { clear_pv(root); }
  // assignment operator overload for moving object
  multiset &operator=(multiset &&ms) noexcept {
    if (this != &ms) {
      root = ms.root;
      current_ = ms.current_;
      ms.root = nullptr;
      ms.current_ = 0;
    }
    return *this;
  }

  /*
ПУБЛИЧНЫЕ МЕТОДЫ ДЛЯ ИТЕРИРОВАНИЯ ПО ЭЛЕМЕНТАМ КЛАССА
*/
  // returns an iterator to the beginning
  const iterator begin() const { return iterator(root); }
  // returns an iterator to the end
  const iterator end() const { return iterator(nullptr); }
  iterator begin() { return iterator(root); }
  iterator end() { return iterator(nullptr); }

  /*
   ПУБЛИЧНЫЕ МЕТОДЫ ДЛЯ ДОСТУПА К ИНФОРМАЦИИ О НАПОЛНЕНИИ КОНТЕЙНЕРА:
  */
  // checks whether the container is empty
  bool empty() { return root == nullptr; }
  // returns the number of elements
  size_t size() { return current_; }
  size_t size() const { return current_; }
  // returns the maximum possible number of elements
  size_t max_size() const {
    return std::numeric_limits<size_t>::max() / sizeof(Node<T>);
  }

  /*
  ПУБЛИЧНЫЕ МЕТОДЫ ДЛЯ ИЗМЕНЕНИЯ КОНТЕЙНЕРА:
  */
  // clears the contents
  void clear() { clear_pv(); }
  // inserts node and returns iterator to where the element is in the container

  iterator insert(const T &value) {
    root = insert_pv(root, value).first;
    return iterator(new_node);
  }

  // erases element at pos
  void erase(iterator pos) { root = erase_pv(root, pos.get_node()->data); }
  // swaps the contents
  void swap(multiset &other) {
    s21::multiset<T> temp(other);
    other = std::move(*this);
    *this = std::move(temp);
  }
  // splices nodes from another container
  void merge(multiset &other) { merge_pv(other); }
  /*
    ПУБЛИЧНЫЕ МЕТОДЫ, ОСУЩЕСТВЛЯЮЩИЕ ПРОСМОТР КОНТЕЙНЕРА:
  */

  // returns the number of elements matching specific key
  size_t count(const T &key) { return count_pv(key); }
  // finds element with specific key
  iterator find(const T &key) {
    for (auto it = begin(); it != end(); ++it)
      if (key == *it) return it;
    return end();
  }
  // checks if the container contains element with specific key
  bool contains(const T &key) {
    for (auto it = begin(); it != end(); ++it)
      if (key == *it) return true;
    return false;
  }

  /*
    Возвращает пару итераторов.
    Первый итератор в паре указывает на первый элемент в multiset с ключом,
    который больше указанного ключа. (upper_bound)
    Второй итератор в паре указывает на первый элемент в multiset с ключом,
    который больше или равен заданному ключу.(lower_bound)
  */
  std::pair<iterator, iterator> equal_range(const T &key) {
    return {upper_bound(key), lower_bound(key)};
  }
  /*
    Возвращает итератор, указывающий на первый элемент в multiset с ключом,
    который больше указанного ключа.
  */
  iterator upper_bound(const T &key) {
    iterator it = begin();
    while (it != end() and *it < key) ++it;
    return it;
  }
  /*
    Возвращает итератор, указывающий на первый элемент в multiset с ключом,
    который больше или равен указанному ключу.
  */
  iterator lower_bound(const T &key) {
    iterator it = begin();
    while (it != end() and *it <= key) ++it;
    return it;
  }

  template <typename... Args>
  std::vector<std::pair<s21::multiset<T>::iterator, bool>> insert_many(
      Args &&...args) {
    std::vector<std::pair<s21::multiset<T>::iterator, bool>> result;
    (result.push_back(this->insert_for_many(root, std::forward<Args>(args))),
     ...);
    return result;
  }
  void print() {
    for (auto &i : *this) std::cout << i << " ";
    std::cout << std::endl;
  }

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
    if (value < node->data)
      node->left = insert_pv(node->left, value).first;
    else
      node->right = insert_pv(node->right, value).first;

    return {node, true};
  }

  std::pair<Node<T> *, bool> insert_for_many(Node<T> *node, const T &value) {
    auto result = insert_pv(node, value);
    root = result.first;
    // std::cout << &new_node << std::endl;
    return {new_node, result.second};
  }

  void clear_pv(Node<T> *node) {
    if (node) {
      clear_pv(node->left);
      clear_pv(node->right);
      delete node;
    }
    current_ = 0;
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
        current_--;
        return right_child;
      } else if (node->right == nullptr) {
        Node<T> *left_child = node->left;
        delete node;
        current_--;
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
  void merge_pv(multiset &other) {
    if (this != &other)
      for (auto it = other.begin(); it != other.end(); ++it) {
        insert(std::move(*it));
        // std::cout << *it << std::endl;
        // insert(*it);
      }
  }
  size_t count_pv(const T &key) {
    size_t count{};
    for (auto it = begin(); it != end(); ++it)
      if (key == *it) count++;
    return count;
  }
};
}  // namespace s21
#endif