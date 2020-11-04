CXX = g++
#CXX = clang++

CXXFLAGS = -Wall -Wno-uninitialized

BINARIES= recTests

COMMON_OBJECT_FILES = linkedListFuncs.o strFuncs.o recLinkedListFuncs.o tddFuncs.o

all: ${BINARIES}

tests: ${BINARIES}
	./recTests 1
	./recTests 2
	./recTests 3
	./recTests 4

recTests: recTests.o ${COMMON_OBJECT_FILES}
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@

clean:
	/bin/rm -f ${BINARIES} *.o
