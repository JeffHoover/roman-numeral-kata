IDIR =../include
CC=gcc
COV=gcov
CFLAGS=-I$(IDIR) -std=c99 -O0 -g -Wall -Wextra -fprofile-arcs -ftest-coverage

ODIR=obj
LDIR =../lib

_DEPS = arabic_to_roman.h roman_to_arabic.h roman_arithmetic.h msg_asserts.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = arabic_to_roman.o roman_to_arabic.o roman_arithmetic.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

_$(ODIR)/%.o: %.c $(DEPS)
obj/%.o: %.c $(DEPS)
	@mkdir -p obj
	$(CC) -c -o $@ $< $(CFLAGS) 

all: clean test valgrind_test

check: test valgrind_test

valgrind_test:
	valgrind ./test
	$(COV) *.c 

../tests/obj/test_roman_numbers.o: ../tests/test_roman_numbers.c $(DEPS)
	@mkdir -p ../tests/obj
	$(CC) -c -o $@ $< $(CFLAGS) 

msg_asserts.o: msg_asserts.c $(DEPS)
	@mkdir -p obj
	$(CC) -c -o $@ $< $(CFLAGS) 

test: ../tests/obj/test_roman_numbers.o arabic_to_roman.o roman_to_arabic.o roman_arithmetic.o msg_asserts.o
	$(CC) -pthread -o $@ -o $@ $^ $(CFLAGS) -l check -lm -lrt 

.PHONY: clean

clean:
	rm -f *.o $(ODIR)/*.* ../tests/$(ODIR)/*.* ./test
	rm -f *.gcda *.gcno *.gcov
	rm -f *.c~ ../tests/*.c~

