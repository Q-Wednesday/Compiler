all: parser

OBJECTS = grammar.o \
		 token.o \
		 graphGen.o \

parser: $(OBJECTS)
		g++  -o $@ $(OBJECTS) 


token.cpp: token.l grammar.hpp
		flex -o $@ $<

grammar.cpp: grammar.y
		bison -d -o $@ $< -v --debug

grammar.hpp: grammar.cpp

%.o: %.cpp
		g++ -c -o $@ $< --std=c++14

compiler: ASTNodes.h

clean:
	rm -rf grammar.cpp grammar.hpp parser compiler $(OBJECTS) AST.dot

test: parser
	cat test.input | ./parser

viz: AST.dot
	dot AST.dot -T png -o AST.png
