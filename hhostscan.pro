QT += core network
QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
           bannergrabber.cpp \
           httpclient.cpp \
           logutils.cpp \
           timeutils.cpp

HEADERS += httpclient.h \
    bannergrabber.h \
    logutils.h \
    timeutils.h

