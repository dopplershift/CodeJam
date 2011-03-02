TARGET = alienlanguage
QMAKE_CXXFLAGS = -std=c++0x

LIBS += -lboost_regex

INCLUDEPATH += ..
SOURCES += \
	alienlanguage.cpp

OTHER_FILES += \
	test_data.txt \
    A-small-practice.in \
    A-large-practice.in
