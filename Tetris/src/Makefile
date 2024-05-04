CFLAGS := -I inc -std=c11 -Wall -Werror -Wextra
OS := ${shell uname}
USERNAME := ${shell whoami}
PATHBREW := cd /opt/goinfre/${USERNAME}

SOURCE = brick_game/tetris/*.c gui/cli/front.c
FORTESTSOURCE = brick_game/tetris/*.c
TESTSOURCE = tests/test.c

ifeq ($(OS),Linux)
 OPEN_CMD = open
 LIB = -lcheck -lsubunit -lm -lrt -lpthread -D_GNU_SOURSE
endif

ifeq ($(OS),Darwin)
 OPEN_CMD = open
 LIB = -lcheck 
endif

ifndef DIR
	DIR := ./game
endif

all:clean install

test: clean
	mkdir obj
	gcc ${CFLAGS} -c brick_game/tetris/backend.c -o obj/backend.o
	gcc ${CFLAGS} -c brick_game/tetris/fsm.c -o obj/fsm.o
	gcc ${CFLAGS} -c brick_game/tetris/init_shapes.c -o obj/init_shapes.o
	gcc ${CFLAGS} -c gui/cli/frontend.c -o obj/frontend.o
	gcc ${CFLAGS} -c tests/tetris_test.c -o obj/test.o 
	gcc obj/*.o -o test -lncurses ${LIB}

	./test

install: 
	mkdir -p $(DIR)
	mkdir obj
	gcc ${CFLAGS} -c brick_game/tetris/backend.c -o obj/backend.o
	gcc ${CFLAGS} -c brick_game/tetris/fsm.c -o obj/fsm.o
	gcc ${CFLAGS} -c brick_game/tetris/init_shapes.c -o obj/init_shapes.o
	gcc ${CFLAGS} -c brick_game/tetris/tetris.c -o obj/tetris.o
	gcc ${CFLAGS} -c gui/cli/frontend.c -o obj/frontend.o
	gcc obj/*.o -o $(DIR)/tetris -lncurses
	./$(DIR)/tetris 

uninstall: 
	rm -rf $(DIR) obj

gcov_report: clean
	mkdir obj
	gcc --coverage ${CFLAGS} -c brick_game/tetris/backend.c -o obj/backend.o
	gcc --coverage ${CFLAGS} -c brick_game/tetris/fsm.c -o obj/fsm.o
	gcc --coverage ${CFLAGS} -c brick_game/tetris/init_shapes.c -o obj/init_shapes.o
	gcc --coverage ${CFLAGS} -c gui/cli/frontend.c -o obj/frontend.o
	gcc --coverage ${CFLAGS} -c tests/tetris_test.c -o obj/test.o 
	gcc --coverage obj/*.o -o g_test -lncurses ${LIB}

	./g_test
	# gcov backend.c 
	lcov -t "g_test" -o g_test.info -c -d .
	genhtml -o report/ g_test.info
	open ./report/index.html

dvi:
	doxygen -q
	open html/index.html 

dist: 
	mkdir -p tetris_game/src
	cp -R brick_game tetris_game/src
	cp -R gui tetris_game/src
	cp -R inc tetris_game/src
	cp -R Makefile tetris_game/src
	tar cvzf tetris_game.tgz tetris_game/
	rm -rf tetris_game

st: 
	clang-format --style=Google -i brick_game/tetris/*.c 
	clang-format --style=Google -i gui/cli/*.c 
	clang-format --style=Google -i inc/*.h
	clang-format --style=Google -i tests/*.h tests/*.c

n: 
	clang-format --style=Google -n brick_game/tetris/*.c 
	clang-format --style=Google -n gui/cli/*.c 
	clang-format --style=Google -n inc/*.h
	clang-format --style=Google -n tests/*.h tests/*.c


doxygen_install:
	brew install doxygen

# для школьных маков
brew_install:
	${PATHBREW}
	git clone https://github.com/Homebrew/brew homebrew

brew_run:
	eval "$(/opt/goinfre/${USERNAME}/homebrew/bin/brew shellenv)"
	brew update --force --quiet	

clean:
	rm -rf *.o $(DIR) obj html test g_test.info g_test report tetris_game.tgz
