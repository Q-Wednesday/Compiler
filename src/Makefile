all: parser

OBJECTS = grammar.o \
		 token.o \
		 graphGen.o \
		 CodeGen.o \

LLVMCONFIG = llvm-config
CPPFLAGS = `$(LLVMCONFIG) --cppflags` -std=c++14
LDFLAGS = `$(LLVMCONFIG) --ldflags` -lpthread -ldl -lz -lncurses -rdynamic -L/usr/local/lib
LIBS = `$(LLVMCONFIG) --libs`
CC = clang++

parser: $(OBJECTS)
		$(CC)  $(CPPFLAGS) -o $@ $(OBJECTS) $(LIBS) $(LDFLAGS)


token.cpp: token.l grammar.hpp
		flex -o $@ $<

grammar.cpp: grammar.y
		bison -d -o $@ $< -v --debug

grammar.hpp: grammar.cpp

%.o: %.cpp
		$(CC) -c $(CPPFLAGS) -o $@ $<

compiler: ASTNodes.h

clean:
	rm -rf grammar.cpp grammar.hpp parser compiler $(OBJECTS) AST.dot

test: parser
	cat test.input | ./parser

viz: AST.dot
	dot AST.dot -T png -o AST.png

