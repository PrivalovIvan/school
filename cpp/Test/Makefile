.PHONY: all st install clean

SRC_FILES_SNAKE = brick_game/snake/controllers/snakecontroller.cpp brick_game/snake/fsm/fsmm.cpp brick_game/snake/models/snakemodel.cpp gui/desktop/views/snakeview.cpp
HEADER_FILES_SNAKE = brick_game/snake/controllers/snakecontroller.h brick_game/snake/fsm/fsmm.h brick_game/snake/models/snakemodel.h gui/desktop/views/snakeview.h

SRC_FILES_TETRIS = brick_game/tetris/backend.c brick_game/tetris/fsm.c brick_game/tetris/init_shapes.c brick_game/tetris/tetris.c
HEADER_FILES_TETRIS = brick_game/tetris/inc/*

all: clean install

st:
	@clang-format -i ${SRC_FILES_SNAKE} ${HEADER_FILES_SNAKE} ${SRC_FILES_TETRIS} ${HEADER_FILES_TETRIS} main.cpp
check:
	@clang-format -n ${SRC_FILES_SNAKE} ${HEADER_FILES_SNAKE} ${SRC_FILES_TETRIS} ${HEADER_FILES_TETRIS} main.cpp

install:
	@mkdir -p build/bk
	@cd build/bk && qmake ../../Test.pro && make 
	@rm -rf build/bk/*.cpp build/bk/*.h  build/bk/*.o build/bk/Makefile .qmake.stash
#	@open ./build/bk
	./build/bk/Test.app/Contents/MacOS/Test
clean:
	@rm -rf build
