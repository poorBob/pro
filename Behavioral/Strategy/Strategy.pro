TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_LFLAGS += -pthread

SOURCES += main.cpp \
    PrintStrategy.cpp \
    ReversePrintStrategy.cpp \
    Context.cpp \
    Printer.cpp \
    LambdaPrintStrategy.cpp \
    RandomNumbersStrategy.cpp \
    ThreadPrinter.cpp

HEADERS += \
    IStrategy.h \
    PrintStrategy.h \
    ReversePrintStrategy.h \
    Context.h \
    Printer.h \
    LambdaPrintStrategy.h \
    RandomNumbersStrategy.h \
    ThreadPrinter.h

