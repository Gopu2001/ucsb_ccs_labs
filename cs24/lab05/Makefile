CXX = g++
#CXX = clang++

CXXFLAGS = -Wall -Wno-uninitialized

stack: usestack.cpp
	${CXX} ${CXXFLAGS} -o usestack usestack.cpp

main: evalfull.cpp
	${CXX} ${CXXFLAGS} -o evalfull evalfull.cpp

clean:
	rm -f usestack evalFull
