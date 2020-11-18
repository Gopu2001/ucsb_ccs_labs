CXX = g++
#CXX = clang++

CXXFLAGS = -Wall -Wno-uninitialized

test: examheap.cpp heap.cpp
	${CXX} ${CXXFLAGS} -o examheap examheap.cpp heap.cpp

clean:
	rm -f examheap
