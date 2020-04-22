#-------------------------------------------------
#
# Project created by QtCreator 2020-04-07 T18:38:15
#
#-------------------------------------------------

QT       += core gui
#标记 网络
QT       += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET      = JSWS
TEMPLATE    = app

SOURCES     += main.cpp \
    StrUtil.cpp \
    VLCWrapper.cpp \
    VLCWrapperImpl.cpp \
    XmlParser.cpp \
    circleprogress.cpp \
    qttcpsocekt.cpp \
    xml/tinystr.cpp \
    xml/tinyxml.cpp \
    xml/tinyxmlerror.cpp \
    xml/tinyxmlparser.cpp
SOURCES     += iconhelper.cpp
SOURCES     += appinit.cpp
SOURCES     += uidemo01.cpp

HEADERS     += iconhelper.h \
    StrUtil.h \
    VLCWrapper.h \
    VLCWrapperImpl.h \
    XmlParser.h \
    circleprogress.h \
    externType.h \
    qttcpsocekt.h \
    xml/tinystr.h \
    xml/tinyxml.h
HEADERS     += appinit.h
HEADERS     += uidemo01.h

FORMS       += uidemo01.ui

RESOURCES   += main.qrc
RESOURCES   += qss.qrc

##添加输出目录
CONFIG (release, release|debug){
    message(release)
    OBJECTS_DIR = $$PWD/tmp/objs/release #指定所有中间文件.o（.obj）放置的目录
    MOC_DIR     = $$PWD/tmp/moc/release  #指定来自moc的所有中间文件放置的目录（含Q_OBJECT宏的头文件转换成标准.h文件的存放目录）
    UI_DIR      = $$PWD/tmp/ui/release   #指定来自uic的所有中间文件放置的目录（.ui文件转化成ui_*.h文件的存放目录）
    RCC_DIR     = $$PWD/tmp/rcc/release  #指定Qt资源编译器输出文件的目录（.qrc文件转换成qrc_*.h文件的存放目录）
    DESTDIR     = $$PWD/release      #指定在何处放置目标文件
}
CONFIG (debug,release|debug){
    message(debug)
    OBJECTS_DIR = $$PWD/tmp/objs/debug
    MOC_DIR     = $$PWD/tmp/moc/debug
    UI_DIR      = $$PWD/tmp/ui/debug
    RCC_DIR     = $$PWD/tmp/rcc/debug
    DESTDIR     = $$PWD/debug
}

INCLUDEPATH+=c:/vlc/sdk/include
LIBS += c:/vlc/sdk/lib/libvlc.lib
LIBS += c:/vlc/sdk/lib/libvlccore.lib


