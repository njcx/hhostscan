QT += core network gui widgets

CONFIG += c++11 console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
           bannergrabber.cpp \
           httpclient.cpp \
           logutils.cpp \
           main.cpp \
           networktoolsapp.cpp \
           pinger.cpp \
           timeutils.cpp

HEADERS += httpclient.h \
    bannergrabber.h \
    logutils.h \
    main.cppp \
    networktoolsapp.h \
    pinger.h \
    timeutils.h

