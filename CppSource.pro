QMAKE_CXXFLAGS += -std=c++17

TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += sdk_no_version_check

SOURCES += \
        main.cpp

HEADERS += \
    all.h
