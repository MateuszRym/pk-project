QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ModelARX.cpp \
    Testy_ARX.cpp \
    Testy_PID.cpp \
    main.cpp \
    mainwindow.cpp \
    pid.cpp \
    syggen.cpp \
    sygkwad.cpp \
    sygsin.cpp \
    sygskok.cpp \
    symulacja.cpp \
    zegar.cpp
    wejscie.cpp

HEADERS += \
    ModelARX.h \
    mainwindow.h \
    pid.h \
    syggen.h \
    sygkwad.h \
    sygsin.h \
    sygskok.h \
    symulacja.h \
    zegar.h
    wejscie.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
