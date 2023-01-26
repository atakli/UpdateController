TEMPLATE = lib
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG += staticlib # bunu commentleyip derleyince de shared halini uretiyor

CONFIG(release, debug|release){
    CONFIG(staticlib): DESTDIR = $$OUT_PWD/release/static
    else: DESTDIR = $$OUT_PWD/release/shared
}
CONFIG(debug, debug|release){
    CONFIG(staticlib): DESTDIR = $$OUT_PWD/debug/static
    else: DESTDIR = $$OUT_PWD/debug/shared
}

CONFIG(debug_and_release): DEFINES += LIB_SHARED LIB_BUILD_SHARED

QT       += network core gui widgets

SOURCES += \
        httpmanager.cpp \
#        main.cpp \
        updatecontroller.cpp

HEADERS += \
    ../include/httpmanager.h \
    ../include/updatecontroller.h

INCLUDEPATH += ../include

##CONFIG(release, static):
#CONFIG(release, shared): DEFINES += LIB_SHARED LIB_BUILD_SHARED
##CONFIG(debug, static):
#CONFIG(debug, shared): DEFINES += LIB_SHARED LIB_BUILD_SHARED
