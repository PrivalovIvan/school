FLAGS = -std=c11 -Wall -Werror -Wextra
all : clean s21_grep 

s21_grep: 
	gcc $(FLAGS) -lpcre -c s21_grep.c 
	gcc -o s21_grep s21_grep.o -lpcre

test: s21_grep
	sh test_func_grep.sh

style_check: 
	clang-format -n -style=Google *.c *.h

style_ok:
	clang-format -i -style=Google *.c *.h
	clang-format -n -style=Google *.c *.h

clean: 
	rm -rf *.o s21_grep
