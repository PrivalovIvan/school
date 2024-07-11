#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "../inc/s21_vector.h"

namespace std {
template <typename T>
bool operator==(const s21::vector<T>& lhs, const std::vector<T>& rhs) {
  if (lhs.size() != rhs.size()) {
    return false;
  }

  for (int i = 0; i < int(lhs.size()); ++i) {
    if (lhs[i] != rhs[i]) {
      return false;
    }
  }
  return true;
}
}  // namespace std

TEST(vector_constructor, case1) {
  s21::vector<int> int_vector;
  s21::vector<double> double_vector;
  s21::vector<std::string> string_vector;

  EXPECT_EQ(int_vector.empty(), true);
  EXPECT_EQ(int_vector.capacity(), 0U);
  EXPECT_EQ(&int_vector[0], nullptr);

  EXPECT_EQ(double_vector.empty(), true);
  EXPECT_EQ(double_vector.capacity(), 0U);
  EXPECT_EQ(&double_vector[0], nullptr);

  EXPECT_EQ(string_vector.empty(), true);
  EXPECT_EQ(string_vector.capacity(), 0U);
  EXPECT_EQ(&string_vector[0], nullptr);
}

TEST(vector_constructor, case2) {
  s21::vector<int> int_vector(5);
  s21::vector<double> double_vector(5);
  s21::vector<std::string> string_vector(5);

  EXPECT_EQ(int_vector.empty(), false);
  EXPECT_EQ(int_vector.capacity(), 5U);
  EXPECT_NE(&int_vector[0], nullptr);

  EXPECT_EQ(double_vector.empty(), false);
  EXPECT_EQ(double_vector.capacity(), 5U);
  EXPECT_NE(&double_vector[0], nullptr);

  EXPECT_EQ(string_vector.empty(), false);
  EXPECT_EQ(string_vector.capacity(), 5U);
  EXPECT_NE(&string_vector[0], nullptr);
}

TEST(vector_constructor, case3) {
  s21::vector<int> int_vector{1, 4, 8, 9};
  s21::vector<double> double_vector{1.4, 4.8, 8.9, 9.1};
  s21::vector<std::string> string_vector{"Hello", ",", "world", "!"};

  std::vector<int> std_int_vector{1, 4, 8, 9};
  std::vector<double> std_double_vector{1.4, 4.8, 8.9, 9.1};
  std::vector<std::string> std_string_vector{"Hello", ",", "world", "!"};

  EXPECT_EQ(int_vector.capacity(), std_int_vector.capacity());
  EXPECT_EQ(int_vector, std_int_vector);

  EXPECT_EQ(double_vector.capacity(), std_double_vector.capacity());
  EXPECT_EQ(double_vector, std_double_vector);

  EXPECT_EQ(string_vector.size(), std_string_vector.size());
  EXPECT_EQ(string_vector.capacity(), std_string_vector.capacity());
  EXPECT_EQ(string_vector, std_string_vector);
}

TEST(vector_constructor, case4) {
  s21::vector<int> ref_int_vector{1, 4, 8, 9};
  s21::vector<int> res_int_vector(ref_int_vector);

  s21::vector<double> ref_double_vector{1.4, 4.8, 8.9, 9.1};
  s21::vector<double> res_double_vector(ref_double_vector);

  s21::vector<std::string> ref_string_vector{"Hello", ",", "world", "!"};
  s21::vector<std::string> res_string_vector(ref_string_vector);

  EXPECT_EQ(ref_int_vector.size(), res_int_vector.size());
  EXPECT_EQ(ref_int_vector.capacity(), res_int_vector.capacity());
  EXPECT_EQ(ref_int_vector[0], res_int_vector[0]);
  EXPECT_EQ(ref_int_vector[1], res_int_vector[1]);
  EXPECT_EQ(ref_int_vector[2], res_int_vector[2]);
  EXPECT_EQ(ref_int_vector[3], res_int_vector[3]);

  EXPECT_EQ(ref_double_vector.size(), res_double_vector.size());
  EXPECT_EQ(ref_double_vector.capacity(), res_double_vector.capacity());
  EXPECT_EQ(ref_double_vector[0], res_double_vector[0]);
  EXPECT_EQ(ref_double_vector[1], res_double_vector[1]);
  EXPECT_EQ(ref_double_vector[2], res_double_vector[2]);
  EXPECT_EQ(ref_double_vector[3], res_double_vector[3]);

  EXPECT_EQ(ref_string_vector.size(), res_string_vector.size());
  EXPECT_EQ(ref_string_vector.capacity(), res_string_vector.capacity());
  EXPECT_EQ(ref_string_vector[0], res_string_vector[0]);
  EXPECT_EQ(ref_string_vector[1], res_string_vector[1]);
  EXPECT_EQ(ref_string_vector[2], res_string_vector[2]);
  EXPECT_EQ(ref_string_vector[3], res_string_vector[3]);
}

TEST(vector_constructor, case5) {
  s21::vector<int> ref_int_vector{1, 4, 8, 9};
  s21::vector<int> res_int_vector = std::move(ref_int_vector);

  s21::vector<double> ref_double_vector{1.4, 4.8, 8.9, 9.1};
  s21::vector<double> res_double_vector = std::move(ref_double_vector);

  s21::vector<std::string> ref_string_vector{"Hello", ",", "world", "!"};
  s21::vector<std::string> res_string_vector = std::move(ref_string_vector);

  EXPECT_EQ(ref_int_vector.size(), 0U);
  EXPECT_EQ(ref_int_vector.capacity(), 0U);
  EXPECT_EQ(res_int_vector.size(), 4U);
  EXPECT_EQ(res_int_vector.capacity(), 4U);
  EXPECT_EQ(res_int_vector[0], 1);
  EXPECT_EQ(res_int_vector[1], 4);
  EXPECT_EQ(res_int_vector[2], 8);
  EXPECT_EQ(res_int_vector[3], 9);

  EXPECT_EQ(ref_double_vector.size(), 0U);
  EXPECT_EQ(ref_double_vector.capacity(), 0U);
  EXPECT_EQ(res_double_vector.size(), 4U);
  EXPECT_EQ(res_double_vector.capacity(), 4U);
  EXPECT_EQ(res_double_vector[0], 1.4);
  EXPECT_EQ(res_double_vector[1], 4.8);
  EXPECT_EQ(res_double_vector[2], 8.9);
  EXPECT_EQ(res_double_vector[3], 9.1);

  EXPECT_EQ(ref_string_vector.size(), 0U);
  EXPECT_EQ(ref_string_vector.capacity(), 0U);
  EXPECT_EQ(res_string_vector.size(), 4U);
  EXPECT_EQ(res_string_vector.capacity(), 4U);
  EXPECT_EQ(res_string_vector[0], "Hello");
  EXPECT_EQ(res_string_vector[1], ",");
  EXPECT_EQ(res_string_vector[2], "world");
  EXPECT_EQ(res_string_vector[3], "!");
}

TEST(vector_constructor, case6) {
  s21::vector<int> ref_int_vector{1, 4, 8, 9};
  s21::vector<int> res_int_vector;
  res_int_vector = std::move(ref_int_vector);

  s21::vector<double> ref_double_vector{1.4, 4.8, 8.9, 9.1};
  s21::vector<double> res_double_vector;
  res_double_vector = std::move(ref_double_vector);

  s21::vector<std::string> ref_string_vector{"Hello", ",", "world", "!"};
  s21::vector<std::string> res_string_vector;
  res_string_vector = std::move(ref_string_vector);

  EXPECT_EQ(ref_int_vector.size(), 0U);
  EXPECT_EQ(ref_int_vector.capacity(), 0U);
  EXPECT_EQ(res_int_vector.size(), 4U);
  EXPECT_EQ(res_int_vector.capacity(), 4U);
  EXPECT_EQ(res_int_vector[0], 1);
  EXPECT_EQ(res_int_vector[1], 4);
  EXPECT_EQ(res_int_vector[2], 8);
  EXPECT_EQ(res_int_vector[3], 9);

  EXPECT_EQ(ref_double_vector.size(), 0U);
  EXPECT_EQ(ref_double_vector.capacity(), 0U);
  EXPECT_EQ(res_double_vector.size(), 4U);
  EXPECT_EQ(res_double_vector.capacity(), 4U);
  EXPECT_EQ(res_double_vector[0], 1.4);
  EXPECT_EQ(res_double_vector[1], 4.8);
  EXPECT_EQ(res_double_vector[2], 8.9);
  EXPECT_EQ(res_double_vector[3], 9.1);

  EXPECT_EQ(ref_string_vector.size(), 0U);
  EXPECT_EQ(ref_string_vector.capacity(), 0U);
  EXPECT_EQ(res_string_vector.size(), 4U);
  EXPECT_EQ(res_string_vector.capacity(), 4U);
  EXPECT_EQ(res_string_vector[0], "Hello");
  EXPECT_EQ(res_string_vector[1], ",");
  EXPECT_EQ(res_string_vector[2], "world");
  EXPECT_EQ(res_string_vector[3], "!");
}

TEST(vector_at, case1) {
  s21::vector<int> int_vector{1, 4, 8, 9};
  s21::vector<double> double_vector{1.4, 4.8, 8.9, 9.1};
  s21::vector<std::string> string_vector{"Hello", ",", "world", "!"};

  EXPECT_EQ(int_vector.at(0), 1);
  EXPECT_EQ(double_vector.at(0), 1.4);
  EXPECT_EQ(string_vector.at(0), "Hello");
}

TEST(vector_at, case2) {
  s21::vector<int> int_vector{1, 4, 8, 9};
  s21::vector<double> double_vector{1.4, 4.8, 8.9, 9.1};
  s21::vector<std::string> string_vector{"Hello", ",", "world", "!"};

  EXPECT_THROW(int_vector.at(5), std::out_of_range);
  EXPECT_THROW(double_vector.at(5), std::out_of_range);
  EXPECT_THROW(string_vector.at(5), std::out_of_range);
}

TEST(vector_at, case3) {
  s21::vector<int> int_vector;
  s21::vector<double> double_vector;
  s21::vector<std::string> string_vector;

  EXPECT_THROW(int_vector.at(5), std::out_of_range);
  EXPECT_THROW(double_vector.at(5), std::out_of_range);
  EXPECT_THROW(string_vector.at(5), std::out_of_range);
}

TEST(vector_front, case1) {
  s21::vector<int> int_vector{1, 4, 8, 9};
  s21::vector<double> double_vector{1.4, 4.8, 8.9, 9.1};
  s21::vector<std::string> string_vector{"Hello", ",", "world", "!"};

  EXPECT_EQ(int_vector.front(), 1);
  EXPECT_EQ(double_vector.front(), 1.4);
  EXPECT_EQ(string_vector.front(), "Hello");
}

TEST(vector_back, case1) {
  s21::vector<int> int_vector{1, 4, 8, 9};
  s21::vector<double> double_vector{1.4, 4.8, 8.9, 9.1};
  s21::vector<std::string> string_vector{"Hello", ",", "world", "!"};

  EXPECT_EQ(int_vector.back(), 9);
  EXPECT_EQ(double_vector.back(), 9.1);
  EXPECT_EQ(string_vector.back(), "!");
}

TEST(vector_data, case1) {
  s21::vector<int> int_vector{1, 4, 8, 9};
  s21::vector<double> double_vector{1.4, 4.8, 8.9, 9.1};
  s21::vector<std::string> string_vector{"Hello", ",", "world", "!"};

  EXPECT_EQ(int_vector.data(), &int_vector[0]);
  EXPECT_EQ(double_vector.data(), &double_vector[0]);
  EXPECT_EQ(string_vector.data(), &string_vector[0]);
}

TEST(vector_begin, case1) {
  s21::vector<int> int_vector{1, 4, 8, 9};
  s21::vector<double> double_vector{1.4, 4.8, 8.9, 9.1};
  s21::vector<std::string> string_vector{"Hello", ",", "world", "!"};

  EXPECT_EQ(int_vector.begin(), &int_vector[0]);
  EXPECT_EQ(double_vector.begin(), &double_vector[0]);
  EXPECT_EQ(string_vector.begin(), &string_vector[0]);
}

TEST(vector_end, case1) {
  s21::vector<int> int_vector{1, 4, 8, 9};
  s21::vector<double> double_vector{1.4, 4.8, 8.9, 9.1};
  s21::vector<std::string> string_vector{"Hello", ",", "world", "!"};

  EXPECT_EQ(int_vector.end(), &int_vector[0] + 4);
  EXPECT_EQ(double_vector.end(), &double_vector[0] + 4);
  EXPECT_EQ(string_vector.end(), &string_vector[0] + 4);
}

TEST(vector_empty, case1) {
  s21::vector<int> int_vector{1, 4, 8, 9};
  s21::vector<double> double_vector{1.4, 4.8, 8.9, 9.1};
  s21::vector<std::string> string_vector{"Hello", ",", "world", "!"};

  EXPECT_EQ(int_vector.empty(), false);
  EXPECT_EQ(double_vector.empty(), false);
  EXPECT_EQ(string_vector.empty(), false);
}

TEST(vector_empty, case2) {
  s21::vector<int> int_vector{};
  s21::vector<double> double_vector{};
  s21::vector<std::string> string_vector{};

  EXPECT_EQ(int_vector.empty(), true);
  EXPECT_EQ(double_vector.empty(), true);
  EXPECT_EQ(string_vector.empty(), true);
}

TEST(vector_size, case1) {
  s21::vector<int> int_vector{1, 4, 8, 9};
  s21::vector<double> double_vector{1.4, 4.8, 8.9, 9.1};
  s21::vector<std::string> string_vector{"Hello", ",", "world", "!"};

  EXPECT_EQ(int_vector.size(), 4U);
  EXPECT_EQ(double_vector.size(), 4U);
  EXPECT_EQ(string_vector.size(), 4U);
}

TEST(vector_size, case2) {
  s21::vector<int> int_vector{};
  s21::vector<double> double_vector{};
  s21::vector<std::string> string_vector{};

  EXPECT_EQ(int_vector.size(), 0U);
  EXPECT_EQ(double_vector.size(), 0U);
  EXPECT_EQ(string_vector.size(), 0U);
}

TEST(vector_max_size, case1) {
  s21::vector<int> int_vector{1, 4, 8, 9};
  std::vector<int> std_vec_int{1, 4, 8, 9};

  s21::vector<double> double_vector{1.4, 4.8, 8.9, 9.1};
  std::vector<double> std_vec_double{1.4, 4.8, 8.9, 9.1};

  s21::vector<std::string> string_vector{"Hello", ",", "world", "!"};
  std::vector<std::string> std_vec_string{"Hello", ",", "world", "!"};

  EXPECT_EQ(int_vector.max_size(), std_vec_int.max_size());
  EXPECT_EQ(double_vector.max_size(), std_vec_double.max_size());
  EXPECT_EQ(string_vector.max_size(), std_vec_string.max_size());
}

TEST(vector_reserve, case1) {
  s21::vector<int> int_vector{1, 4, 8, 9};
  s21::vector<double> double_vector{1.4, 4.8, 8.9, 9.1};
  s21::vector<std::string> string_vector{"Hello", ",", "world", "!"};

  int_vector.reserve(20);
  double_vector.reserve(20);
  string_vector.reserve(20);

  EXPECT_EQ(int_vector.capacity(), 20U);
  EXPECT_EQ(double_vector.capacity(), 20U);
  EXPECT_EQ(string_vector.capacity(), 20U);
}

TEST(vector_reserve, case2) {
  s21::vector<int> int_vector{1, 4, 8, 9};
  s21::vector<double> double_vector{1.4, 4.8, 8.9, 9.1};
  s21::vector<std::string> string_vector{"Hello", ",", "world", "!"};

  int_vector.reserve(2);
  double_vector.reserve(2);
  string_vector.reserve(2);

  EXPECT_EQ(int_vector.capacity(), 4U);
  EXPECT_EQ(double_vector.capacity(), 4U);
  EXPECT_EQ(string_vector.capacity(), 4U);
}

TEST(vector_capacity, case1) {
  s21::vector<int> int_vector{1, 4, 8, 9};
  s21::vector<double> double_vector{1.4, 4.8, 8.9, 9.1};
  s21::vector<std::string> string_vector{"Hello", ",", "world", "!"};

  EXPECT_EQ(int_vector.capacity(), 4U);
  EXPECT_EQ(double_vector.capacity(), 4U);
  EXPECT_EQ(string_vector.capacity(), 4U);
}

TEST(vector_capacity, case2) {
  s21::vector<int> int_vector{};
  s21::vector<double> double_vector{};
  s21::vector<std::string> string_vector{};

  EXPECT_EQ(int_vector.capacity(), 0U);
  EXPECT_EQ(double_vector.capacity(), 0U);
  EXPECT_EQ(string_vector.capacity(), 0U);
}

TEST(vector_shrink_to_fit, case1) {
  s21::vector<int> int_vector{1, 4, 8, 9};
  s21::vector<double> double_vector{1.4, 4.8, 8.9, 9.1};
  s21::vector<std::string> string_vector{"Hello", ",", "world", "!"};

  int_vector.reserve(20);
  double_vector.reserve(20);
  string_vector.reserve(20);

  int_vector.shrink_to_fit();
  double_vector.shrink_to_fit();
  string_vector.shrink_to_fit();

  EXPECT_EQ(int_vector.capacity(), 4U);
  EXPECT_EQ(double_vector.capacity(), 4U);
  EXPECT_EQ(string_vector.capacity(), 4U);
}

TEST(vector_shrink_to_fit, case2) {
  s21::vector<int> int_vector{1, 4, 8, 9};
  s21::vector<double> double_vector{1.4, 4.8, 8.9, 9.1};
  s21::vector<std::string> string_vector{"Hello", ",", "world", "!"};

  int_vector.shrink_to_fit();
  double_vector.shrink_to_fit();
  string_vector.shrink_to_fit();

  EXPECT_EQ(int_vector.capacity(), 4U);
  EXPECT_EQ(double_vector.capacity(), 4U);
  EXPECT_EQ(string_vector.capacity(), 4U);
}

TEST(vector_clear, case1) {
  s21::vector<int> int_vector{1, 4, 8, 9};
  s21::vector<double> double_vector{1.4, 4.8, 8.9, 9.1};
  s21::vector<std::string> string_vector{"Hello", ",", "world", "!"};

  int_vector.clear();
  double_vector.clear();
  string_vector.clear();

  EXPECT_EQ(&int_vector[0], nullptr);
  EXPECT_EQ(&double_vector[0], nullptr);
  EXPECT_EQ(&string_vector[0], nullptr);
}

TEST(vector_clear, case2) {
  s21::vector<int> int_vector{1, 4, 8, 9};
  s21::vector<double> double_vector{1.4, 4.8, 8.9, 9.1};
  s21::vector<std::string> string_vector{"Hello", ",", "world", "!"};

  int_vector.clear();
  double_vector.clear();
  string_vector.clear();

  EXPECT_EQ(&int_vector[0], nullptr);
  EXPECT_EQ(&double_vector[0], nullptr);
  EXPECT_EQ(&string_vector[0], nullptr);
}

TEST(vector_insert, case1) {
  s21::vector<int> int_vector{1, 4, 8, 9};
  s21::vector<double> double_vector{1.4, 4.8, 8.9, 9.1};
  s21::vector<std::string> string_vector{"Hello", ",", "", "!"};

  std::vector<int> std_int_vector{1, 4, 8, 9};
  std::vector<double> std_double_vector{1.4, 4.8, 8.9, 9.1};
  std::vector<std::string> std_string_vector{"Hello", ",", "", "!"};

  auto pos_int = int_vector.begin() + 2;
  auto pos_double = double_vector.begin() + 2;
  auto pos_string = string_vector.begin() + 2;

  auto std_pos_int = std_int_vector.begin() + 2;
  auto std_pos_double = std_double_vector.begin() + 2;
  auto std_pos_string = std_string_vector.begin() + 2;

  int_vector.insert(pos_int, 2);
  double_vector.insert(pos_double, 2.0);
  string_vector.insert(pos_string, "world");

  std_int_vector.insert(std_pos_int, 2);
  std_double_vector.insert(std_pos_double, 2.0);
  std_string_vector.insert(std_pos_string, "world");

  EXPECT_EQ(int_vector, std_int_vector);
  EXPECT_EQ(double_vector, std_double_vector);
  EXPECT_EQ(string_vector, std_string_vector);
}

TEST(vector_insert, case2) {
  s21::vector<int> int_vector{1, 4, 8, 9};
  s21::vector<double> double_vector{1.4, 4.8, 8.9, 9.1};
  s21::vector<std::string> string_vector{"Hello", ",", "", "!"};

  std::vector<int> std_int_vector{1, 4, 8, 9};
  std::vector<double> std_double_vector{1.4, 4.8, 8.9, 9.1};
  std::vector<std::string> std_string_vector{"Hello", ",", "", "!"};

  auto pos_int = int_vector.begin();
  auto pos_double = double_vector.begin();
  auto pos_string = string_vector.begin();

  auto std_pos_int = std_int_vector.begin();
  auto std_pos_double = std_double_vector.begin();
  auto std_pos_string = std_string_vector.begin();

  int_vector.insert(pos_int, 2);
  double_vector.insert(pos_double, 2.0);
  string_vector.insert(pos_string, "world");

  std_int_vector.insert(std_pos_int, 2);
  std_double_vector.insert(std_pos_double, 2.0);
  std_string_vector.insert(std_pos_string, "world");

  EXPECT_EQ(int_vector, std_int_vector);
  EXPECT_EQ(double_vector, std_double_vector);
  EXPECT_EQ(string_vector, std_string_vector);
}

TEST(vector_insert, case3) {
  s21::vector<int> int_vector{1, 4, 8, 9};
  s21::vector<double> double_vector{1.4, 4.8, 8.9, 9.1};
  s21::vector<std::string> string_vector{"Hello", ",", "", "!"};

  std::vector<int> std_int_vector{1, 4, 8, 9};
  std::vector<double> std_double_vector{1.4, 4.8, 8.9, 9.1};
  std::vector<std::string> std_string_vector{"Hello", ",", "", "!"};

  auto pos_int = int_vector.end();
  auto pos_double = double_vector.end();
  auto pos_string = string_vector.end();

  auto std_pos_int = std_int_vector.end();
  auto std_pos_double = std_double_vector.end();
  auto std_pos_string = std_string_vector.end();

  int_vector.insert(pos_int, 2);
  double_vector.insert(pos_double, 2.0);
  string_vector.insert(pos_string, "world");

  std_int_vector.insert(std_pos_int, 2);
  std_double_vector.insert(std_pos_double, 2.0);
  std_string_vector.insert(std_pos_string, "world");

  EXPECT_EQ(int_vector, std_int_vector);
  EXPECT_EQ(double_vector, std_double_vector);
  EXPECT_EQ(string_vector, std_string_vector);
}

TEST(vector_erase, case1) {
  s21::vector<int> int_vector{1, 1, 4, 8, 9};
  s21::vector<double> double_vector{1.0, 1.4, 4.8, 8.9, 9.1};
  s21::vector<std::string> string_vector{"", "Hello", ",", "world", "!"};

  std::vector<int> std_int_vector{1, 1, 4, 8, 9};
  std::vector<double> std_double_vector{1.0, 1.4, 4.8, 8.9, 9.1};
  std::vector<std::string> std_string_vector{"", "Hello", ",", "world", "!"};

  auto pos_int = int_vector.begin() + 2;
  auto pos_double = double_vector.begin() + 2;
  auto pos_string = string_vector.begin() + 2;

  auto std_pos_int = std_int_vector.begin() + 2;
  auto std_pos_double = std_double_vector.begin() + 2;
  auto std_pos_string = std_string_vector.begin() + 2;

  int_vector.erase(pos_int);
  double_vector.erase(pos_double);
  string_vector.erase(pos_string);

  std_int_vector.erase(std_pos_int);
  std_double_vector.erase(std_pos_double);
  std_string_vector.erase(std_pos_string);

  EXPECT_EQ(int_vector, std_int_vector);
  EXPECT_EQ(double_vector, std_double_vector);
  EXPECT_EQ(string_vector, std_string_vector);
}

TEST(vector_erase, case2) {
  s21::vector<int> int_vector{1, 1, 4, 8, 9};
  s21::vector<double> double_vector{1.0, 1.4, 4.8, 8.9, 9.1};
  s21::vector<std::string> string_vector{"", "Hello", ",", "world", "!"};

  std::vector<int> std_int_vector{1, 1, 4, 8, 9};
  std::vector<double> std_double_vector{1.0, 1.4, 4.8, 8.9, 9.1};
  std::vector<std::string> std_string_vector{"", "Hello", ",", "world", "!"};

  auto pos_int = int_vector.begin();
  auto pos_double = double_vector.begin();
  auto pos_string = string_vector.begin();

  auto std_pos_int = std_int_vector.begin();
  auto std_pos_double = std_double_vector.begin();
  auto std_pos_string = std_string_vector.begin();

  int_vector.erase(pos_int);
  double_vector.erase(pos_double);
  string_vector.erase(pos_string);

  std_int_vector.erase(std_pos_int);
  std_double_vector.erase(std_pos_double);
  std_string_vector.erase(std_pos_string);

  EXPECT_EQ(int_vector, std_int_vector);
  EXPECT_EQ(double_vector, std_double_vector);
  EXPECT_EQ(string_vector, std_string_vector);
}

TEST(vector_push_back, case1) {
  s21::vector<int> int_vector{1, 4, 8, 9};
  s21::vector<double> double_vector{1.4, 4.8, 8.9, 9.1};
  s21::vector<std::string> string_vector{"Hello", ",", "world", "!"};

  std::vector<int> std_int_vector{1, 4, 8, 9};
  std::vector<double> std_double_vector{1.4, 4.8, 8.9, 9.1};
  std::vector<std::string> std_string_vector{"Hello", ",", "world", "!"};

  int_vector.push_back(10);
  double_vector.push_back(10.0);
  string_vector.push_back("!!");

  std_int_vector.push_back(10);
  std_double_vector.push_back(10.0);
  std_string_vector.push_back("!!");

  EXPECT_EQ(int_vector, std_int_vector);
  EXPECT_EQ(double_vector, std_double_vector);
  EXPECT_EQ(string_vector, std_string_vector);
}

TEST(vector_push_back, case2) {
  s21::vector<int> int_vector{1, 4, 8, 9};
  s21::vector<double> double_vector{1.4, 4.8, 8.9, 9.1};
  s21::vector<std::string> string_vector{"Hello", ",", "world", "!"};

  int_vector.reserve(20);
  double_vector.reserve(20);
  string_vector.reserve(20);

  int_vector.push_back(10);
  double_vector.push_back(10.0);
  string_vector.push_back("!!");

  EXPECT_EQ(*(int_vector.end() - 1), 10);
  EXPECT_EQ(*(double_vector.end() - 1), 10.0);
  EXPECT_EQ(*(string_vector.end() - 1), "!!");
}

TEST(vector_pop_back, case1) {
  s21::vector<int> int_vector{1, 4, 8, 9};
  s21::vector<double> double_vector{1.4, 4.8, 8.9, 9.1};
  s21::vector<std::string> string_vector{"Hello", ",", "world", "!"};

  int_vector.pop_back();
  double_vector.pop_back();
  string_vector.pop_back();

  EXPECT_EQ(int_vector.size(), 3U);
  EXPECT_EQ(int_vector.capacity(), 4U);
  EXPECT_EQ(double_vector.size(), 3U);
  EXPECT_EQ(double_vector.capacity(), 4U);
  EXPECT_EQ(string_vector.size(), 3U);
  EXPECT_EQ(string_vector.capacity(), 4U);
}

TEST(vector_swap, case1) {
  s21::vector<int> ref_int_vector{1, 4, 8, 9};
  s21::vector<int> res_int_vector{0, 0, 0};

  s21::vector<double> ref_double_vector{1.4, 4.8, 8.9, 9.1};
  s21::vector<double> res_double_vector{0.0, 0.0, 0.0};

  s21::vector<std::string> ref_string_vector{"Hello", ",", "world", "!"};
  s21::vector<std::string> res_string_vector{"", "", ""};

  ref_int_vector.swap(res_int_vector);
  ref_double_vector.swap(res_double_vector);
  ref_string_vector.swap(res_string_vector);

  EXPECT_EQ(res_int_vector.size(), 4U);
  EXPECT_EQ(res_int_vector.capacity(), 4U);
  EXPECT_EQ(res_int_vector[2], 8);

  EXPECT_EQ(res_double_vector.size(), 4U);
  EXPECT_EQ(res_double_vector.capacity(), 4U);
  EXPECT_EQ(res_double_vector[2], 8.9);

  EXPECT_EQ(res_string_vector.size(), 4U);
  EXPECT_EQ(res_string_vector.capacity(), 4U);
  EXPECT_EQ(res_string_vector[2], "world");
}

TEST(vector_insert_many, case1) {
  s21::vector<int> int_vector{1, 4, 7};
  s21::vector<double> double_vector{1.4, 4.8, 7.2};
  s21::vector<std::string> string_vector{"Hello", ",", "world"};

  std::vector<int> std_int_vector{1, 4, 7};
  std::vector<double> std_double_vector{1.4, 4.8, 7.2};
  std::vector<std::string> std_string_vector{"Hello", ",", "world"};

  int_vector.insert_many(int_vector.begin() + 2, 2, 3, 5);
  double_vector.insert_many(double_vector.begin(), 2.0, 3.0, 5.0);
  string_vector.insert_many(string_vector.end(), "!", "?");

  std_int_vector.insert(std_int_vector.begin() + 2, {2, 3, 5});
  std_double_vector.insert(std_double_vector.begin(), {2.0, 3.0, 5.0});
  std_string_vector.insert(std_string_vector.end(), {"!", "?"});

  EXPECT_EQ(int_vector, std_int_vector);
  EXPECT_EQ(double_vector, std_double_vector);
  EXPECT_EQ(string_vector, std_string_vector);
}

TEST(vector_insert_many_back, case1) {
  s21::vector<int> int_vector{1, 4, 7};
  s21::vector<double> double_vector{1.4, 4.8, 7.2};
  s21::vector<std::string> string_vector{"Hello", ",", "world"};

  std::vector<int> std_int_vector{1, 4, 7};
  std::vector<double> std_double_vector{1.4, 4.8, 7.2};
  std::vector<std::string> std_string_vector{"Hello", ",", "world"};

  int_vector.insert_many_back(5, 3, 2);
  double_vector.insert_many_back(5.0, 3.0, 2.0);
  string_vector.insert_many_back("!", "?");

  std_int_vector.insert(std_int_vector.end(), {5, 3, 2});
  std_double_vector.insert(std_double_vector.end(), {5.0, 3.0, 2.0});
  std_string_vector.insert(std_string_vector.end(), {"!", "?"});

  EXPECT_EQ(int_vector, std_int_vector);
  EXPECT_EQ(double_vector, std_double_vector);
  EXPECT_EQ(string_vector, std_string_vector);
}