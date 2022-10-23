TEMPLATE = lib
CONFIG += console c++17
CONFIG -= app_bundle
#CONFIG += staticlib

#TARGET = sUpdateController

QT       += network core gui widgets

SOURCES += \
        httpmanager.cpp \
#        main.cpp \
        updatecontroller.cpp

HEADERS += \
    ../include/httpmanager.h \
    ../include/updatecontroller.h

INCLUDEPATH += ../include
