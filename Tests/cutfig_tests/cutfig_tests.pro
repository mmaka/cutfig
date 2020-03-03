QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle
TEMPLATE = app
CXXFLAGS += -std=c++1z
SOURCES +=  tst_cutfig_tests.cpp
