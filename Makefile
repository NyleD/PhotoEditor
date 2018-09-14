# example4/Makefile
CXX=g++
CXXFLAGS=-std=c++14  -Wpedantic -Wall -Werror=vla -MMD -g
OBJECTS=main.o basic.o image.o exception.o Decorator.o Flip.o Rotate.o Sepia.o ppm.o
DEPENDS=${OBJECTS:.o=.d}
EXEC=a4q3

TESTDIR=./tests
EXECSDIR=../executables
EXECGIVEN=${EXEC}
SUITE=suiteq4.txt

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}
.PHONY: clean
