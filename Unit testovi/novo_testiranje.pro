QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_novo_testiranje.cpp ../untitled/solver.h ../untitled/solver.cpp
QMAKE_CXXFLAGS+=-g -Wall -fprofile-arcs -ftest-coverage -O0
QMAKE_LFLAGS += -g -Wall -fprofile-arcs -ftest-coverage -O0
LIBS += -lgcov
