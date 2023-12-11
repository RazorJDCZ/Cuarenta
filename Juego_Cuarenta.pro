QT       += core gui
QT += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    baraja.cpp \
    carta.cpp \
    game.cpp \
    main.cpp \
    mainwindow.cpp \
    player.cpp \
    ventainicio.cpp

HEADERS += \
    baraja.h \
    carta.h \
    game.h \
    mainwindow.h \
    player.h \
    ventainicio.h

FORMS += \
    mainwindow.ui \
    ventainicio.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    imagenes.qrc

DISTFILES += \
    10c.jpg \
    10d.jpg \
    10p.jpg \
    10t.jpg \
    1c.jpg \
    1d.jpg \
    1p.jpg \
    1t.jpg \
    2c.jpg \
    2d.jpg \
    2p.jpg \
    2t.jpg \
    3c.jpg \
    3d.jpg \
    3p.jpg \
    3t.jpg \
    4c.jpg \
    4d.jpg \
    4p.jpg \
    4t.jpg \
    5c.jpg \
    5d.jpg \
    5p.jpg \
    5t.jpg \
    6c.jpg \
    6d.jpg \
    6p.jpg \
    6t.jpg \
    7c.jpg \
    7d.jpg \
    7p.jpg \
    7t.jpg \
    8c.jpg \
    8d.jpg \
    8p.jpg \
    8t.jpg \
    9c.jpg \
    9d.jpg \
    9p.jpg \
    9t.jpg \
    MIX FIESTAS DE QUITO.mp3
