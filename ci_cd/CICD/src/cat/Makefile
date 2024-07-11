all : clean s21_cat

OS = $(shell uname)
ifeq ($(OS), Linux)
 SH = bash
else
 SH = sh
endif

s21_cat: 
	gcc -std=c11 -Wall -Werror -Wextra -c s21_cat.c -lpcre
	gcc -o s21_cat s21_cat.o -lpcre

test: s21_cat 
	${SH} test_func_cat.sh

style_check: 
	clang-format -n -style=Google *.c *.h

style_ok:
	clang-format -i -style=Google *.c *.h
	clang-format -n -style=Google *.c *.h


clean: 
	rm -rf *.o s21_grep s21_cat
