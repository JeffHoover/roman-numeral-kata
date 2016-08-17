IDIR =../include
CC=gcc
CFLAGS=-I$(IDIR) -std=c99 -O0 -g -Wall -Wextra

ODIR=obj
LDIR =../lib

_DEPS = arabic_to_roman.h roman_to_arabic.h roman_utils.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = arabic_to_roman.o roman.o roman_to_arabic.o roman_utils.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

_$(ODIR)/%.o: %.c $(DEPS)
obj/%.o: %.c $(DEPS)
	@mkdir -p obj
	$(CC) -c -o $@ $< $(CFLAGS) 

all: clean roman test valgrind_roman valgrind_test

check: test valgrind_test

valgrind_roman:
	valgrind ./roman 

valgrind_test:
	valgrind ./test

roman: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) 

../tests/obj/test_roman_numbers.o: ../tests/test_roman_numbers.c $(DEPS)
	@mkdir -p ../tests/obj
	$(CC) -c -o $@ $< $(CFLAGS) 

test: ../tests/obj/test_roman_numbers.o arabic_to_roman.o roman_to_arabic.o roman_utils.o
	$(CC) -pthread -o $@ -o $@ $^ $(CFLAGS) -l check -lm -lrt 

run-test: clean test roman valgrind_test valgrind_roman
	./test

.PHONY: clean

clean:
	rm -f *.o $(ODIR)/*.o *~ core $(INCDIR)/*~ ./roman ../tests/$(ODIR)/*.o ./test 

