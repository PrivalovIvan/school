QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
# QMAKE_CXXFLAGS += -fsanitize=address -fno-omit-frame-pointer
# QMAKE_LDFLAGS += -fsanitize=address

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    brick_game/snake/controllers/snakecontroller.cpp \
    brick_game/snake/fsm/fsmm.cpp \
    main.cpp \
    brick_game/snake/models/snakemodel.cpp \
    gui/desktop/views/snakeview.cpp


HEADERS += \
    brick_game/snake/controllers/snakecontroller.h \
    brick_game/snake/fsm/fsmm.h \
    brick_game/snake/models/snakemodel.h \
    gui/desktop/views/snakeview.h

SOURCES += \
    brick_game/tetris/backend.c \
    brick_game/tetris/fsm.c \
    brick_game/tetris/init_shapes.c \
    brick_game/tetris/tetris.c

HEADERS += \
    brick_game/tetris/inc/backend.h \
    brick_game/tetris/inc/fsm_m.h \
    brick_game/tetris/inc/defines.h \
    brick_game/tetris/inc/objects.h \
    brick_game/tetris/inc/frontend.h

LIBS += -lncurses

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
