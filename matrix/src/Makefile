FGCC = -std=c11 -Wall -Werror -Wextra 

all: clean gcov_report

test: clean s21_matrix.a
	gcc $(FGCC) -c tests/*.c -lcheck -lm 
	gcc $(FGCC) -o test *.o s21_matrix.a -lcheck -lm 
	./test

style:
	clang-format -n -style=Google *.c *.h tests/*.c tests/*.h
	clang-format -i -style=Google *.c *.h tests/*.c tests/*.h

s21_matrix.a:
	gcc $(FGCC) -c s21_matrix.c
	ar rc s21_matrix.a s21_matrix.o
	ranlib s21_matrix.a

gcov_report: 
	gcc --coverage $(CFLAGS) -c tests/*.c *.c -lcheck 
	gcc --coverage *.o -o test_g -lcheck 
	./test_g
	lcov -t "test_g" -o test_g.info -c -d .
	genhtml -o report/ test_g.info
	open ./report/index.html

clean:
	rm -rf *.o *.a app test test_g *.gcda *.gcno *.info report s21_matrix