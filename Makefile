# Travis example for Identifier created by Rafael Garibotti

GCCFLAGS = -g -Wall -Wfatal-errors
ALL = identifier cov unity cppcheck valgrind adressSanitizer
GCC = gcc

all: $(ALL)

identifier: identifier.c
	$(GCC) $(GCCFLAGS) -o $@ $@.c

cov: identifier.c
	$(GCC) $(GCCFLAGS) -fprofile-arcs -ftest-coverage -o $@ identifier.c

clean:
	rm -fr $(ALL) *.o cov* *.dSYM *.gcda *.gcno *.gcov

test: all
	bash test

unity:
	cd identifier;pwd;make all;

cppcheck:
	cppcheck ./identifier/src/IdentifierTests.c

valgrind:
	gcc ./identifier/src/IdentifierTests.c -o idt
	valgrind --leak-check=full --show-leak-kinds=all ./idt

adressSanitizer:
	gcc -g -Wall -Wfatal-errors -fsanitize=address ./identifier/src/IdentifierTests.c -o idt2
	./idt2
