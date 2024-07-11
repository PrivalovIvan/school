FLAGS := -std=c++17 -Wall -Werror -Wextra -pedantic 


OS = $(shell uname)
ifeq ($(OS), Linux)
 CHECK = -lpthread -lcheck -pthread -lrt -lm -lsubunit -lgtest
else
 CHECK = -lm -lpthread -lgtest
endif


all: clean test
	
s21_matrix_oop.a:
	@mkdir -p obj
	@g++ ${FLAGS} -g -c s21_matrix_oop.cpp -o obj/s21_matrix_oop.o
	@ar rcs obj/s21_matrix_oop.a obj/s21_matrix_oop.o
	@ranlib obj/s21_matrix_oop.a

test: clean s21_matrix_oop.a
	@g++ ${FLAGS} -c s21_matrix_oop_tests.cpp -o obj/s21_matrix_oop_tests.o ${CHECK}
	@g++ ${FLAGS} obj/s21_matrix_oop_tests.o obj/s21_matrix_oop.a -o test_matrix.out ${CHECK}
	@./test_matrix.out

st:
	clang-format -style=Google -i *.cpp *.h

n:
	clang-format -style=Google -n *.cpp *.h

push:
	git add .
	git commit -m 'add project'
	git push origin develop

clean:
	rm -rf obj *.o *.a app* test_matrix.out obj report *.info