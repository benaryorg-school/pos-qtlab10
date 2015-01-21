TEMPLATE = app
TARGET = main
DEPENDPATH += lang src
INCLUDEPATH += src
OBJECTS_DIR = build/obj
MOC_DIR = build/moc

QT += core gui widgets
CONFIG += release qt
CONFIG -= debug

QMAKE_CXXFLAGS += -std=c++11

RESOURCES = qt.qrc

# Input
HEADERS += src/window.h
SOURCES += src/main.cpp src/window.cpp
#TRANSLATIONS += lang/de.ts
