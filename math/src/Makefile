all: clean gcov_report


test: s21_math.a
	gcc -std=c11 -Wall -Werror -Wextra -c s21_tests.c -lcheck
	gcc  s21_tests.o s21_math.a -o s21_tests -lcheck


s21_math.a: 
	gcc -std=c11 -Wall -Werror -Wextra -c s21_math.c
	ar rc s21_math.a s21_math.o
	ranlib s21_math.a

style_check: 
	clang-format -n -style=Google *.c *.h

style_ok:
	clang-format -i -style=Google *.c *.h

gcov_report: s21_math.a
	gcc --coverage -std=c11 -Wall -Werror -Wextra -c s21_tests.c s21_math.c -lcheck
	gcc --coverage s21_tests.o s21_math.a -o test_g -lcheck
	./test_g
	gcov s21_math.c 
	lcov -t "test_g" -o test_g.info -c -d .
	genhtml -o report/ test_g.info
	open ./report/index.html

clean: 
	rm -rf *.o s21_math s21_tests *.html *.css *.gcov *.gcda *.gcno *.info *.gch *.a test_g report
