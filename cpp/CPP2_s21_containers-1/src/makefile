GCC = g++
FLAGS = -Wall -Werror -Wextra -std=c++17 -fsanitize=address
LDFLAGS = -lgtest
SRC = tests/set_tests.cc \
      tests/multiset_tests.cc \
      tests/stack_tests.cc \
      tests/vector_tests.cc \
      tests/main_test.cc
TARGET = test

all: clean $(TARGET)

$(TARGET): $(SRC)
	@$(GCC) $(FLAGS) $^ $(LDFLAGS) -o $@ && ./$(TARGET)

clean:
	rm -f $(TARGET)

st:
	@clang-format -style=Google -i *.h inc/*.h tests/*

check_st:
	clang-format -style=Google -n *.h inc/* tests/*
