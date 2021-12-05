compiler: ASTNodes.h

parser:  lex.yy.c token.h grammar.cpp grammar.hpp
		gcc -o $@ lex.yy.c token.h grammar.cpp grammar.hpp
scanner: lex.yy.c token.h
		gcc  -o $@ $<

lex.yy.c: token.l grammar.hpp
		flex $<

grammar.cpp: grammar.y
	bison -d -o $@ $<

grammar.hpp: grammar.cpp

