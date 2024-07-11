#ifndef S21_STACK_H
#define S21_STACK_H
#include <iso646.h>

#include <initializer_list>
#include <iostream>
#include <memory>

using namespace std;

namespace s21 {
template <typename T>
struct Node {
  T data;
  std::shared_ptr<Node<T>> prew;
  Node(T value) : data(value), prew(nullptr) {}
};

template <typename T>
class stack {
 private:
  std::shared_ptr<Node<T>> head, tail;
  size_t current_size;

  void push_pv(const T& value) {
    auto new_node = std::make_shared<Node<T>>(value);
    if (tail) new_node->prew = tail;
    tail = new_node;
    if (!head) head = tail;
    current_size++;
  }
  void print_pv(std::shared_ptr<Node<T>> node) {
    while (node) {
      std::cout << node->data << "  ";
      node = node->prew;
    }
    cout << endl;
  }
  void copy_stack(const stack& s) {
    if (s.tail) {
      std::shared_ptr<Node<T>> temp_pointer = s.tail;
      s21::stack<T> temp_s;
      while (temp_pointer) {
        temp_s.push(temp_pointer->data);
        temp_pointer = temp_pointer->prew;
      }
      std::shared_ptr<Node<T>> temp_pointer_2 = temp_s.tail;
      while (temp_pointer_2) {
        this->push(temp_pointer_2->data);
        temp_pointer_2 = temp_pointer_2->prew;
      }
    }
  }
  // void erase_full_stack() {
  //   while (this->tail) {
  //     std::shared_ptr del = this->tail;
  //     this->tail = this->tail->prew;
  //     delete del;
  //   }
  //   this->head = nullptr;
  //   this->current_size = 0;
  // }
  void pop_pv() {
    if (this->tail) {
      this->tail = this->tail->prew;
      current_size--;
      if (!this->tail) this->head = nullptr;
    }
  }
  void swap_pv(stack& other) noexcept {
    stack<T> temp = std::move(other);
    other = std::move(*this);
    *this = std::move(temp);
  }

 public:
  /*
   ОСНОВНЫЕ ПУБЛИЧНЫЕ МЕТОДЫ ВЗАИМОДЕЙСТВИЯ С КЛАССОМ:
  */
  // конструктор по умолчанию, создает пустой стек
  stack() : head(nullptr), tail(nullptr), current_size(0) {}
  // конструктор списка инициализаторов, создает стек, инициализированный с
  // использованием std::initializer_list
  stack(std::initializer_list<T> const& items) : stack() {
    for (auto& i : items) this->push(i);
  }
  // конструктор копирования
  stack(const stack& s) : stack() { this->copy_stack(s); }
  // конструктор перемещения
  stack(stack&& s) noexcept
      : head(s.head), tail(s.tail), current_size(s.current_size) {
    s.head = nullptr;
    s.tail = nullptr;
    s.current_size = 0;
  }
  // деструктор
  // ~stack() { this->erase_full_stack(); }
  ~stack() = default;

  // Перегрузка оператора присваивания для движущегося объекта
  stack& operator=(stack&& s) noexcept {
    if (this != &s) {
      // this->head = std::move(s.head);
      // this->tail = std::move(s.tail);
      this->head = s.head;
      this->tail = s.tail;
      this->current_size = s.current_size;
    }
    return *this;
  }

  /*
      ПУБЛИЧНЫЕ МЕТОДЫ ДЛЯ ДОСТУПА К ЭЛЕМЕНТАМ КЛАССА:
  */
  // обращается к верхнему элементу
  const T& top() const {
    if (!tail) throw std::out_of_range("Stack is empty");
    return this->tail->data;
  }

  /*
      ОБЩЕДОСТУПНЫЕ МЕТОДЫ ДОСТУПА К ИНФОРМАЦИИ О ЗАПОЛНЕННОМ КОНТЕЙНЕРЕ:
  */
  // проверяет, пуст ли контейнер
  bool empty() { return tail == nullptr; }
  // возвращает количество элементов
  size_t size() { return this->current_size; }

  /*
    ПУБЛИЧНЫЕ МЕТОДЫ ДЛЯ ИЗМЕНЕНИЯ КОНТЕЙНЕРА:
  */
  // вставляет элемент вверху
  void push(const T& value) { push_pv(value); }
  // удаляет верхний элемент
  void pop() { pop_pv(); }

  // меняет содержимое
  void swap(stack& other) { swap_pv(other); }

  // Добавляет новые элементы в верхнюю часть контейнера
  template <typename... Args>
  void insert_many_front(Args&&... args) {
    (push_pv(std::forward<Args>(args)), ...);
  }

  void print() {
    if (tail) print_pv(tail);
  }
};

}  // namespace s21
#endif