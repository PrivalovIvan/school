CFLAGS = -std=c11 -Wall -Werror -Wextra

all: clean gcov_report

#-lsubunut -lm for Ubuntu

test: s21_string.a
	gcc $(CFLAGS) -c tests/*.c -lcheck
	gcc *.o s21_string.a -o s21_tests -lcheck 
	./s21_tests

s21_string.a: 
	gcc $(CFLAGS) -c *.c
	ar rc s21_string.a *.o
	ranlib s21_string.a

style_check: 
	clang-format -n -style=Google tests/*.c *.c
	clang-format -n -style=Google tests/*.h *.h

style_ok:
	clang-format -i -style=Google tests/*.c *.c *.h
	clang-format -n -style=Google tests/*.c *.c *.h

gcov_report: s21_string.a
	gcc --coverage -std=c11 -Wall -Werror -Wextra -c tests/*.c s21_string.c *.c -lcheck 
	gcc --coverage *.o s21_string.a -o test_g -lcheck 
	./test_g
	gcov s21_string.c 
	lcov -t "test_g" -o test_g.info -c -d .
	genhtml -o report/ test_g.info
	open ./report/index.html

clean: 
	rm -rf *.o s21_string s21_tests *.html *.css *.gcov *.gcda *.gcno *.info *.gch *.a test_g report test1
