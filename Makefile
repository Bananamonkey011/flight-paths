CXX=clang++
INCLUDES=-Iincludes/
CXXEXTRAS=-Wall -Wextra -Werror -pedantic 
CXXFLAGS=-std=c++2a -g -fstandalone-debug 

exec: bin/exec
tests: bin/tests

bin/exec: ./main.cpp ./Graph.h ./Graph.cpp ./Node.h ./Node.cpp 
	$(CXX) $(CXXFLAGS) $(CXXEXTRAS) $(INCLUDES) ./main.cpp ./Graph.cpp ./Node.cpp -o ./bin/exec

bin/tests: tests/unitTests.cpp Graph.h Graph.cpp Node.h Node.cpp
	# $(CXX) $(CXXFLAGS) $(CXXEXTRAS) $(INCLUDES) tests/unitTests.ccp Graph.cpp Node.cpp -o $@

.DEFAULT_GOAL := exec
.PHONY: clean exec tests

clean:
	rm -fr bin/*
# CXX=clang++
# CXXFLAGS=-std=c++20 -g -fstandalone-debug -Wall -Wextra -Werror -pedantic $(INCLUDES)

# exec: exec
# tests: tests

# exec: main.cpp Graph.h Node.h
# 	$(CXX) $(CXXFLAGS) $^ -o $@

# tests: tests/tests.cpp tests/catch.hpp Graph.h Node.h
# 	$(CXX) $(CXXFLAGS) $^ -o $@

# catch.o: cs225/catch/catch.hpp cs225/catch/catchmain.cpp
# 	$(CXX) $(CXXFLAGS) -c $^ -o $@

# .DEFAULT_GOAL := exec
# .PHONY: clean exec tests

# clean:
# 	rm -fr bin/*

# Executable names:
# EXE = 
# TEST = test

# Add all object files needed for compiling:
# EXE_OBJ = main.o
# OBJS = Graph.o main.o

# Use the cs225 makefile template:
include cs225/make/cs225.mk