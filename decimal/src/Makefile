CFLAGS = -std=c11 -Wall -Werror -Wextra

all: clean gcov_report

s21_decimal.a:
	gcc $(CFLAGS) -c *.c 
	ar rc s21_decimal.a *o 
	ranlib s21_decimal.a

test: clean s21_decimal.a
	gcc $(CFLAGS) -c tests/*.c -lcheck
	gcc *.o s21_decimal.a -o s21_test -lcheck
	./s21_test

clang-format:
	clang-format -n -style=Google tests/*.c *.c *.h
	clang-format -i -style=Google tests/*.c *.c *.h

gcov_report: 
	gcc --coverage $(CFLAGS) -c tests/*.c *.c -lcheck 
	gcc --coverage *.o -o test_g -lcheck 
	./test_g
	lcov -t "test_g" -o test_g.info -c -d .
	genhtml -o report/ test_g.info
	open ./report/index.html


clean:
	rm -rf *o *a s21_test test_g report