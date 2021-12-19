all: compiler

OBJECTS = grammar.o \
		 token.o \
		 CodeGen.o \
		 main.o \

TESTOBJ = testOut/bubbleSort.o \
		testOut/KMP.o \
		testOut/palindromic.o  	 

GRAPH = graph/bubbleSort.png \
		graph/KMP.png \
		graph/palindromic.png \

LLVMCONFIG = llvm-config
CPPFLAGS = `$(LLVMCONFIG) --cppflags` -std=c++14  
LDFLAGS = `$(LLVMCONFIG) --ldflags` -lpthread -ldl -lz -lncurses -rdynamic -L/usr/local/lib
LIBS = `$(LLVMCONFIG) --libs`
CC = clang++

compiler: $(OBJECTS)
		$(CC)  $(CPPFLAGS) -o $@ $(OBJECTS) $(LIBS) $(LDFLAGS) && rm -rf $(OBJECTS)


token.cpp: token.l grammar.hpp
		flex -o $@ $<

grammar.cpp: grammar.y
		bison -d -o $@ $< -v --debug

grammar.hpp: grammar.cpp

%.o: %.cpp
		$(CC) -c $(CPPFLAGS) -o $@ $<


clean:
	rm -rf grammar.cpp grammar.hpp token.cpp compiler $(OBJECTS) testOut/* $(TESTOBJ) 

test: test.o 
	clang test.o  mystdlib.c -o test && dot test.o.dot -T png -o test.png

test.o: test.input compiler
	./compiler -i test.input -o test.o

graph/%.png: testOut/%.o.dot
	dot $< -T png -o $@

viz: $(GRAPH)
	echo "visualize all"

testOut/%.o: testCode/%.input compiler
	./compiler -o $@ -i $<  && clang $@ mystdlib.c -o testOut/$*


testall: $(TESTOBJ)
	echo "test all"

