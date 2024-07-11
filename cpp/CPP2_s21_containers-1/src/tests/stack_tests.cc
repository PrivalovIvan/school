#include <gtest/gtest.h>

#include <stack>

#include "../inc/s21_stack.h"

namespace std {
template <typename T>
bool operator==(const s21::stack<T>& lhs, const std::stack<T>& rhs) {
  auto lhs_copy = lhs;
  auto rhs_copy = rhs;
  if (lhs_copy.size() != rhs_copy.size()) {
    return false;
  }

  while (!lhs_copy.empty() && !rhs_copy.empty()) {
    if (lhs_copy.top() != rhs_copy.top()) {
      return false;
    }
    lhs_copy.pop();
    rhs_copy.pop();
  }
  return true;
}
}  // namespace std

namespace s21 {
template <typename T>
bool operator==(const s21::stack<T>& lhs, const s21::stack<T>& rhs) {
  auto lhs_copy = lhs;
  auto rhs_copy = rhs;
  if (lhs_copy.size() != rhs_copy.size()) {
    return false;
  }

  while (!lhs_copy.empty() && !rhs_copy.empty()) {
    if (lhs_copy.top() != rhs_copy.top()) {
      return false;
    }
    lhs_copy.pop();
    rhs_copy.pop();
  }
  return true;
}
}  // namespace s21

namespace test {
struct test_struct {
  std::stack<int> std_int_stack;
  std::stack<double> std_double_stack;
  std::stack<std::string> std_string_stack;

  s21::stack<int> int_stack;
  s21::stack<double> double_stack;
  s21::stack<std::string> string_stack;
};

static test_struct init_struct() {
  test_struct st;
  st.int_stack.insert_many_front(1, 4, 8, 9, 1);
  st.double_stack.insert_many_front(1.4, 4.8, 8.9, 9.1, 1.1);
  st.string_stack.insert_many_front("Hello", ",", "world", "!", "!!");

  st.std_int_stack.push(1);
  st.std_int_stack.push(4);
  st.std_int_stack.push(8);
  st.std_int_stack.push(9);
  st.std_int_stack.push(1);

  st.std_double_stack.push(1.4);
  st.std_double_stack.push(4.8);
  st.std_double_stack.push(8.9);
  st.std_double_stack.push(9.1);
  st.std_double_stack.push(1.1);

  st.std_string_stack.push("Hello");
  st.std_string_stack.push(",");
  st.std_string_stack.push("world");
  st.std_string_stack.push("!");
  st.std_string_stack.push("!!");

  return st;
}
}  // namespace test

TEST(stack, case1) {
  s21::stack<int> stack_int;
  s21::stack<double> stack_double;
  s21::stack<std::string> stack_string;

  EXPECT_EQ(stack_int.size(), 0U);
  EXPECT_EQ(stack_double.size(), 0U);
  EXPECT_EQ(stack_string.size(), 0U);
}

TEST(stack, case2) {
  auto st = test::init_struct();

  EXPECT_EQ(st.int_stack, st.std_int_stack);
  EXPECT_EQ(st.double_stack, st.std_double_stack);
  EXPECT_EQ(st.string_stack, st.std_string_stack);
}

TEST(stack, case3) {
  auto st = test::init_struct();

  s21::stack<int> stack_res_int(st.int_stack);
  s21::stack<double> stack_res_double(st.double_stack);
  s21::stack<std::string> stack_res_string(st.string_stack);

  std::stack<int> std_stack_res_int(st.std_int_stack);
  std::stack<double> std_stack_res_double(st.std_double_stack);
  std::stack<std::string> std_stack_res_string(st.std_string_stack);

  EXPECT_EQ(st.int_stack, std_stack_res_int);
  EXPECT_EQ(st.double_stack, std_stack_res_double);
  EXPECT_EQ(st.string_stack, std_stack_res_string);
}

TEST(stack, case4) {
  auto st = test::init_struct();

  s21::stack<int> stack_res_int = st.int_stack;
  s21::stack<double> stack_res_double = st.double_stack;
  s21::stack<std::string> stack_res_string = st.string_stack;

  std::stack<int> std_stack_res_int = st.std_int_stack;
  std::stack<double> std_stack_res_double = st.std_double_stack;
  std::stack<std::string> std_stack_res_string = st.std_string_stack;

  EXPECT_EQ(st.int_stack, std_stack_res_int);
  EXPECT_EQ(st.double_stack, std_stack_res_double);
  EXPECT_EQ(st.string_stack, std_stack_res_string);
}

TEST(stack, case5) {
  auto st = test::init_struct();

  s21::stack<int> stack_res_int = std::move(st.int_stack);
  s21::stack<double> stack_res_double = std::move(st.double_stack);
  s21::stack<std::string> stack_res_string = std::move(st.string_stack);

  std::stack<int> std_stack_res_int = std::move(st.std_int_stack);
  std::stack<double> std_stack_res_double = std::move(st.std_double_stack);
  std::stack<std::string> std_stack_res_string = std::move(st.std_string_stack);

  EXPECT_EQ(stack_res_int, std_stack_res_int);
  EXPECT_EQ(stack_res_double, std_stack_res_double);
  EXPECT_EQ(stack_res_string, std_stack_res_string);
}

TEST(STACK_EMPTY, case1) {
  auto st = test::init_struct();

  EXPECT_EQ(st.int_stack.empty(), false);
  EXPECT_EQ(st.double_stack.empty(), false);
  EXPECT_EQ(st.string_stack.empty(), false);
}

TEST(STACK_EMPTY, case2) {
  s21::stack<int> stack_int;
  s21::stack<double> stack_double;
  s21::stack<std::string> stack_string;

  EXPECT_EQ(stack_int.empty(), true);
  EXPECT_EQ(stack_double.empty(), true);
  EXPECT_EQ(stack_string.empty(), true);
}

TEST(STACK_SIZE, case1) {
  auto st = test::init_struct();

  EXPECT_EQ(st.int_stack.size(), st.std_int_stack.size());
  EXPECT_EQ(st.double_stack.size(), st.std_double_stack.size());
  EXPECT_EQ(st.string_stack.size(), st.std_string_stack.size());
}

TEST(STACK_SIZE, case2) {
  s21::stack<int> stack_int;
  s21::stack<double> stack_double;
  s21::stack<std::string> stack_string;

  EXPECT_EQ(stack_int.size(), 0U);
  EXPECT_EQ(stack_double.size(), 0U);
  EXPECT_EQ(stack_string.size(), 0U);
}

TEST(STACK_TOP, case1) {
  auto st = test::init_struct();

  EXPECT_EQ(st.int_stack.top(), st.std_int_stack.top());
  EXPECT_EQ(st.double_stack.top(), st.std_double_stack.top());
  EXPECT_EQ(st.string_stack.top(), st.std_string_stack.top());
}

TEST(STACK_PUSH, case1) {
  s21::stack<int> stack_int{1, 4, 8, 9, 1};
  s21::stack<double> stack_double{1.4, 4.8, 8.9, 9.1, 1.1};
  s21::stack<std::string> stack_string{"Hello", ",", "world", "!", "!!"};

  std::stack<int> std_stack_int = test::init_struct().std_int_stack;
  std::stack<double> std_stack_double = test::init_struct().std_double_stack;
  std::stack<std::string> std_stack_string =
      test::init_struct().std_string_stack;

  stack_int.push(255);
  stack_double.push(255.0);
  stack_string.push("255");

  std_stack_int.push(255);
  stack_double.push(255.0);
  std_stack_string.push("255");

  EXPECT_EQ(stack_int, std_stack_int);
  EXPECT_EQ(stack_double, stack_double);
  EXPECT_EQ(stack_string, std_stack_string);
}

TEST(STACK_PUSH, case2) {
  s21::stack<int> stack_int;
  s21::stack<double> stack_double;
  s21::stack<std::string> stack_string;

  std::stack<int> std_stack_int;
  std::stack<double> std_stack_double;
  std::stack<std::string> std_stack_string;

  stack_int.push(255);
  stack_double.push(255.0);
  stack_string.push("255");

  std_stack_int.push(255);
  stack_double.push(255.0);
  std_stack_string.push("255");

  EXPECT_EQ(stack_int, std_stack_int);
  EXPECT_EQ(stack_double, stack_double);
  EXPECT_EQ(stack_string, std_stack_string);
}

TEST(STACK_POP, case1) {
  s21::stack<int> stack_int{1, 4, 8, 9, 1};
  s21::stack<double> stack_double{1.4, 4.8, 8.9, 9.1, 1.1};
  s21::stack<std::string> stack_string{"Hello", ",", "world", "!", "!!"};

  std::stack<int> std_stack_int = test::init_struct().std_int_stack;
  std::stack<double> std_stack_double = test::init_struct().std_double_stack;
  std::stack<std::string> std_stack_string =
      test::init_struct().std_string_stack;

  stack_int.pop();
  stack_double.pop();
  stack_string.pop();

  std_stack_int.pop();
  stack_double.pop();
  std_stack_string.pop();

  EXPECT_EQ(stack_int, std_stack_int);
  EXPECT_EQ(stack_double, stack_double);
  EXPECT_EQ(stack_string, std_stack_string);
}

TEST(STACK_SWAP, case1) {
  s21::stack<int> stack_ref_int{1, 4, 8, 9, 1};
  s21::stack<int> stack_res_int;

  s21::stack<double> stack_ref_double{1.4, 4.8, 8.9, 9.1, 1.1};
  s21::stack<double> stack_res_double;

  s21::stack<std::string> stack_ref_string{"Hello", ",", "world", "!", "!!"};
  s21::stack<std::string> stack_res_string;

  stack_ref_int.swap(stack_res_int);
  stack_ref_double.swap(stack_res_double);
  stack_ref_string.swap(stack_res_string);

  EXPECT_EQ(stack_ref_int.size(), 0U);
  EXPECT_EQ(stack_res_int.size(), 5U);
  EXPECT_EQ(stack_res_int.top(), 1);

  EXPECT_EQ(stack_ref_double.size(), 0U);
  EXPECT_EQ(stack_res_double.size(), 5U);
  EXPECT_EQ(stack_res_double.top(), 1.1);

  EXPECT_EQ(stack_ref_string.size(), 0U);
  EXPECT_EQ(stack_res_string.size(), 5U);
  EXPECT_EQ(stack_res_string.top(), "!!");
}

TEST(STACK_SWAP, case2) {
  s21::stack<int> stack_ref_int{1, 4, 8, 9, 1};
  s21::stack<int> stack_res_int{12, 13, 14};

  s21::stack<double> stack_ref_double{1.4, 4.8, 8.9, 9.1, 1.1};
  s21::stack<double> stack_res_double{13.0};

  s21::stack<std::string> stack_ref_string{"Hello", ",", "world", "!", "!!"};
  s21::stack<std::string> stack_res_string{"14", "15"};

  stack_ref_int.swap(stack_res_int);
  stack_ref_double.swap(stack_res_double);
  stack_ref_string.swap(stack_res_string);

  EXPECT_EQ(stack_ref_int.size(), 3U);
  EXPECT_EQ(stack_ref_int.top(), 14);
  EXPECT_EQ(stack_res_int.size(), 5U);
  EXPECT_EQ(stack_res_int.top(), 1);

  EXPECT_EQ(stack_ref_double.size(), 1U);
  EXPECT_EQ(stack_ref_double.top(), 13.0);
  EXPECT_EQ(stack_res_double.size(), 5U);
  EXPECT_EQ(stack_res_double.top(), 1.1);

  EXPECT_EQ(stack_ref_string.size(), 2U);
  EXPECT_EQ(stack_ref_string.top(), "15");
  EXPECT_EQ(stack_res_string.size(), 5U);
  EXPECT_EQ(stack_res_string.top(), "!!");
}

TEST(stack, insert_many_front) {
  s21::stack<int> stack_int;
  s21::stack<double> stack_double;
  s21::stack<std::string> stack_string;

  stack_int.push(1);
  stack_int.push(2);
  stack_int.push(3);

  stack_double.push(1.1);
  stack_double.push(2.2);
  stack_double.push(3.3);

  stack_string.push("one");
  stack_string.push("two");
  stack_string.push("three");

  stack_int.insert_many_front(4, 5, 6);
  stack_double.insert_many_front(4.4, 5.5, 6.6);
  stack_string.insert_many_front("four", "five", "six");

  std::stack<int> std_stack_int;
  std_stack_int.push(1);
  std_stack_int.push(2);
  std_stack_int.push(3);
  std_stack_int.push(4);
  std_stack_int.push(5);
  std_stack_int.push(6);

  std::stack<double> std_stack_double;
  std_stack_double.push(1.1);
  std_stack_double.push(2.2);
  std_stack_double.push(3.3);
  std_stack_double.push(4.4);
  std_stack_double.push(5.5);
  std_stack_double.push(6.6);

  std::stack<std::string> std_stack_string;
  std_stack_string.push("one");
  std_stack_string.push("two");
  std_stack_string.push("three");
  std_stack_string.push("four");
  std_stack_string.push("five");
  std_stack_string.push("six");

  EXPECT_EQ(stack_int, std_stack_int);
  EXPECT_EQ(stack_double, stack_double);
  EXPECT_EQ(stack_string, std_stack_string);
}
