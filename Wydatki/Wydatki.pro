#-------------------------------------------------
#
# Project created by QtCreator 2014-12-05T19:11:41
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 5): QT += widgets

TARGET = Wydatki
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    wydatek.cpp \
    listawydatkow.cpp \
    dialogdodaj.cpp \
    menagerwydatkow.cpp \
    listakategorii.cpp \
    wpiszestawienia.cpp

HEADERS  += mainwindow.h \
    wydatek.h \
    listawydatkow.h \
    dialogdodaj.h \
    menagerwydatkow.h \
    listakategorii.h \
    wpiszestawienia.h

FORMS    += mainwindow.ui \
    dialogdodaj.ui
