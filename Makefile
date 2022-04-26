CXX=clang++
INCLUDES=-Iincludes/
CXXFLAGS=-std=c++20 -g -fstandalone-debug -Wall -Wextra -Werror -pedantic $(INCLUDES)

exec: bin/exec
tests: bin/tests

bin/exec: ./main.cc src/Graph.cc src/Node.cc  src/Graph.h src/Node.h
	$(CXX) $(CXXFLAGS) ./main.cc src/Graph.cc src/Node.cc -o $@

bin/tests: ./tests/tests.cc cs225/catch/catch.hpp src/Graph.cc src/Node.cc src/Graph.h src/Node.h
	$(CXX) $(CXXFLAGS) ./tests/tests.cc src/Graph.cc src/Node.cc -o $@


.DEFAULT_GOAL := exec
.PHONY: clean exec tests

clean:
	rm -fr bin/*

########


# CXX=clang++
# INCLUDES=-Iinclude/
# CXXFLAGS=-std=c++20 -g

# exec: bin/exec
# test: bin/tests

# bin/exec: main.cc ./src/Graph.cc ./src/Graph.h ./src/Node.cc ./src/Node.h
# 	$(CXX) $(CXXFLAGS) $(INCLUDES) src/Graph.cc src/Node.cc -o $@
# clean: 
# 	rm -rf bin/*

# .DEFAULT: exec

# #######

# CXX=clang++
# INCLUDES=-Iincludes/
# CXXEXTRAS=-pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c 
# CXXFLAGS=-std=c++14 -stdlib=libc++ -O0 

# exec: bin/exec
# tests: bin/tests

# bin/exec: ./main.cpp ./Graph.h ./Graph.cpp ./Node.h ./Node.cpp 
# 	$(CXX) $(CXXFLAGS) $(CXXEXTRAS) $(INCLUDES) ./main.cpp ./Graph.cpp ./Node.cpp -o $@ 

# bin/tests: tests/unitTests.cpp Graph.h Graph.cpp Node.h Node.cpp
# 	$(CXX) $(CXXFLAGS) $(CXXEXTRAS) $(INCLUDES) tests/unitTests.ccp Graph.cpp Node.cpp -o $@

# obj/main.o: ./main.cpp
# 	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $^ -o $@

# obj/Graph.o: ./Graph.h ./Graph.cpp
# 	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $^ -o $@

# obj/Node.o: ./Node.h ./Node.cpp
# 	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $^ -o $@

# .DEFAULT_GOAL := exec
# .PHONY: clean exec tests

# clean:
# 	rm -fr bin/*
# # CXX=clang++
# # CXXFLAGS=-std=c++20 -g -fstandalone-debug -Wall -Wextra -Werror -pedantic $(INCLUDES)

# # exec: exec
# # tests: tests

# # exec: main.cpp Graph.h Node.h
# # 	$(CXX) $(CXXFLAGS) $^ -o $@

# # tests: tests/tests.cpp tests/catch.hpp Graph.h Node.h
# # 	$(CXX) $(CXXFLAGS) $^ -o $@

# # catch.o: cs225/catch/catch.hpp cs225/catch/catchmain.cpp
# # 	$(CXX) $(CXXFLAGS) -c $^ -o $@

# # .DEFAULT_GOAL := exec
# # .PHONY: clean exec tests

# # clean:
# # 	rm -fr bin/*

# # Executable names:
# EXE = 
# TEST = test

# Add all object files needed for compiling:
# EXE_OBJ = main.o
# OBJS = Graph.o main.o

# Use the cs225 makefile template:
# include cs225/make/cs225.mk