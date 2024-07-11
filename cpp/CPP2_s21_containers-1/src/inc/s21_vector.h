#ifndef S21_VECTOR_H
#define S21_VECTOR_H

#include <initializer_list>
#include <memory>
#include <stdexcept>

namespace s21 {
template <typename T>
class vector {
 private:
  std::unique_ptr<T[]> arr;
  size_t capacity_;
  size_t current_;

 public:
  /*
   ВНУТРИКЛАССОВЫЕ ТИПЫ ПЕРЕОПРЕДЕЛЕНИЙ
  */
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using iterator = T*;
  using const_iterator = const T*;
  using size_type = size_t;

  /**
   * ОСНОВНЫЕ ПУБЛИЧНЫЕ МЕТОДЫ ДЛЯ ВЗАИМОДЕЙСТВИЯ С КЛАССОМ
   */

  // конструктор по умолчанию, создает пустой вектор
  // vector() : arr(std::make_unique<T[]>(0)), capacity_(0), current_(0) {}
  vector() : arr(nullptr), capacity_(0), current_(0) {}

  // параметризованный конструктор, создает вектор размера n
  vector(size_t n) : arr(std::make_unique<T[]>(n)), capacity_(n), current_(0) {}

  /*
    конструктор списка инициализаторов, создает вектор,
    инициализированный с использованием std::initializer_list
   */
  vector(std::initializer_list<T> const& list)
      : arr(std::make_unique<T[]>(list.size())),
        capacity_(list.size()),
        current_(list.size()) {
    for (auto it = list.begin(); it != list.end(); ++it)
      arr[it - list.begin()] = *it;
  }

  // Конструктор копирования
  vector(const vector& other)
      : arr(std::make_unique<T[]>(other.capacity_)),
        capacity_(other.capacity_),
        current_(other.current_) {
    for (size_t i = 0; i < current_; i++) arr[i] = other.arr[i];
  }

  // Конструктор перемещения
  vector(vector&& other) noexcept
      : arr(std::move(other.arr)),
        capacity_(other.capacity_),
        current_(other.current_) {
    other.capacity_ = 0;
    other.current_ = 0;
    other.arr = nullptr;
  }
  // Деструктор
  ~vector() = default;

  // Оператор присваивания
  vector& operator=(const vector& other) {
    if (this == &other) return *this;

    arr = std::make_unique<T[]>(other.capacity_);
    capacity_ = other.capacity_;
    current_ = other.current_;
    for (size_t i = 0; i < current_; i++) {
      arr[i] = other.arr[i];
    }

    return *this;
  }

  // Перегрузка оператора присваивания для движущегося объекта
  vector& operator=(vector&& other) noexcept {
    if (this == &other) return *this;
    arr = std::move(other.arr);
    capacity_ = other.capacity_;
    current_ = other.current_;

    other.capacity_ = 0;
    other.current_ = 0;
    other.arr = nullptr;

    return *this;
  }
  /*
    ПУБЛИЧНЫЕ МЕТОДЫ ДЛЯ ДОСТУПА К ЭЛЕМЕНТАМ КЛАССА
  */

  // доступ к указанному элементу с проверкой границ
  T& at(size_t pos) {
    if (pos >= size()) throw std::out_of_range("vector index out of range");
    return arr[pos];
  }

  // доступ к указанному элементу
  T& operator[](size_t index) { return arr[index]; }
  T& operator[](size_t index) const { return arr[index]; }

  // доступ к первому элементу
  const T& front() { return arr[0]; }
  // доступ к последнему элементу
  const T& back() { return arr[current_ - 1]; }
  // прямой доступ к базовому массиву
  T* data() { return arr.get(); }

  /*
    ПУБЛИЧНЫЕ МЕТОДЫ ДЛЯ ИТЕРИРОВАНИЯ ПО ЭЛЕМЕНТАМ КЛАССА(ДОСТУП К ИТЕРАТОРАМ)
  */

  // возвращает итератор в начало
  T* begin() { return arr.get(); }
  // возвращает итератор до конца
  T* end() { return arr.get() + current_; }
  // возвращает итератор в начало
  const T* begin() const { return arr.get(); }
  // возвращает итератор до конца
  const T* end() const { return arr.get() + current_; }

  /*
    ПУБЛИЧНЫЕ МЕТОДЫ ДЛЯ ДОСТУПА К ИНФОРМАЦИИ О НАПОЛНЕНИИ КОНТЕЙНЕРА
  */
  // проверяет, пуст ли контейнер
  bool empty() { return capacity_ == 0; }

  // возвращает количество элементов
  size_t size() const { return current_; }

  // возвращает максимально возможное количество элементов
  size_t max_size() {
    return std::numeric_limits<size_t>::max() / sizeof(arr[0]);
  }
  // выделяет хранилище элементов размера и копирует текущие элементы массива в
  // вновь выделенный массив
  void reserve(size_t size) {
    if (size > capacity_) {
      auto temp = std::make_unique<T[]>(size);
      for (size_t i = 0; i < current_; i++) {
        temp[i] = std::move(arr[i]);
      }
      arr = std::move(temp);
      capacity_ = size;
    }
  }
  // возвращает количество элементов, которые могут храниться в выделенном на
  // данный момент хранилище
  size_t capacity() { return capacity_; }

  // уменьшает использование памяти за счет освобождения неиспользуемой памяти
  void shrink_to_fit() {
    auto temp = std::make_unique<T[]>(current_);
    for (size_t i{}; i < current_; i++) temp[i] = arr[i];

    arr = std::move(temp);
    capacity_ = current_;
  }

  /*
    ПУБЛИЧНЫЕ МЕТОДЫ ДЛЯ ИЗМЕНЕНИЯ КОНТЕЙНЕРА
  */
  // очищает содержимое
  void clear() {
    if (current_ > 0) current_ = 0, capacity_ = 0, arr = nullptr;
  }

  // вставляет элементы в конкретную позицию и возвращает итератор, указывающий
  // на новый элемент
  T* insert(T* pos, const T& value) {
    if (pos < arr.get() || pos > arr.get() + current_)
      throw std::out_of_range("vector index out of range");

    size_t newPosIndex = pos - arr.get();

    if (current_ == capacity_) {
      auto temp = std::make_unique<T[]>(capacity_ * 2);

      for (size_t i = 0; i < newPosIndex; ++i) temp[i] = std::move(arr[i]);

      for (size_t i = current_; i > newPosIndex; --i)
        temp[i] = std::move(arr[i - 1]);
      temp[newPosIndex] = value;
      arr = std::move(temp);
      capacity_ *= 2;
    } else {
      for (size_t i = current_; i > static_cast<size_t>((pos - arr.get())); --i)
        arr[i] = std::move(arr[i - 1]);
      arr[newPosIndex] = value;
    }

    ++current_;
    return arr.get() + newPosIndex;
  }

  // стирает элемент в позиции
  void erase(T* pos) {
    if (pos < arr.get() || pos >= arr.get() + current_) {
      throw std::out_of_range("vector index out of range");
    }
    size_t new_pos = pos - arr.get();
    auto temp = std::make_unique<T[]>(current_);

    for (size_t i{}, j{}; i < current_; i++) {
      if (i == new_pos) i += 1;
      temp[j++] = arr[i];
    }

    arr = std::move(temp);
    current_--;
  }
  // добавляет элемент в конец
  void push_back(const T& data) {
    if (current_ == capacity_) {
      auto temp = std::make_unique<T[]>(capacity_ * 2);

      for (size_t i = 0; i < capacity_; i++) temp[i] = std::move(arr[i]);

      capacity_ *= 2;
      arr = std::move(temp);
    }

    arr[current_] = data;
    current_++;
  }
  // удаляет последний элемент
  void pop_back() {
    if (size() > 0) {
      auto temp = std::make_unique<T[]>(current_ - 1);
      for (size_t i{}; i < current_ - 1; i++) temp[i] = arr[i];
      arr = std::move(temp);
      current_--;
    }
  }
  // меняет содержимое
  void swap(vector& other) {
    std::unique_ptr<T[]> temp = std::move(other.arr);
    size_t temp_capacity = other.capacity_;
    size_t temp_current_ = other.current_;

    other.arr = std::move(arr);
    other.current_ = current_;
    other.capacity_ = capacity_;

    arr = std::move(temp);
    current_ = temp_current_;
    capacity_ = temp_capacity;
  }
  // Вставляет новые элементы в контейнер непосредственно перед pos.
  template <typename... Args>
  T* insert_many(const T* pos, Args&&... args) {
    size_t new_pos = pos - arr.get();
    (insert(begin() + new_pos++, std::forward<Args>(args)), ...);
    return arr.get() + new_pos;
  }
  // Добавляет новые элементы в конец контейнера.
  template <typename... Args>
  void insert_many_back(Args&&... args) {
    (insert(end(), std::forward<Args>(args)), ...);
  }
};
}  // namespace s21
#endif
