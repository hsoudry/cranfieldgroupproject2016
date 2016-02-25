#-------------------------------------------------
#
# Project created by QtCreator 2016-02-19T18:19:38
#
#-------------------------------------------------

QT       += core gui

QT += svg
CONFIG += c++11


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cranfieldgroupproject2016
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    graphpart.cpp \
    graphvizpopup.cpp \
    metisoutput.cpp

HEADERS  += mainwindow.h \
    graphpart.h \
    graphvizpopup.h \
    metisoutput.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    graph_mod.py
