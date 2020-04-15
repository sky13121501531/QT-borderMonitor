#-------------------------------------------------
#
# Project created by QtCreator 2020-04-07 T18:38:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET      = uidemo01
TEMPLATE    = app
MOC_DIR     = temp/moc
RCC_DIR     = temp/rcc
UI_DIR      = temp/ui
OBJECTS_DIR = temp/obj
DESTDIR     = $$PWD/../bin

SOURCES     += main.cpp \
    StrUtil.cpp \
    XmlParser.cpp \
    xml/tinystr.cpp \
    xml/tinyxml.cpp \
    xml/tinyxmlerror.cpp \
    xml/tinyxmlparser.cpp
SOURCES     += iconhelper.cpp
SOURCES     += appinit.cpp
SOURCES     += uidemo01.cpp

HEADERS     += iconhelper.h \
    StrUtil.h \
    XmlParser.h \
    externType.h \
    xml/tinystr.h \
    xml/tinyxml.h
HEADERS     += appinit.h
HEADERS     += uidemo01.h

FORMS       += uidemo01.ui

RESOURCES   += main.qrc
RESOURCES   += qss.qrc
CONFIG      += qt warn_off
INCLUDEPATH += $$PWD