#
# File: Makefile
# Creator: George Ferguson
# Created: Thu Jun 30 11:00:49 2016
# Time-stamp: <Tue Aug  8 10:34:37 EDT 2017 ferguson>
#

PROGRAMS = IntSet_test LinkedList_test

CFLAGS = -g -std=c99 -Wall -Werror

programs: $(PROGRAMS)

IntSet_test: IntSet_test.o IntSet.o
	$(CC) -o $@ $^

LinkedList_test: LinkedList_test.o LinkedList.o
	$(CC) -o $@ $^

clean:
	-rm $(PROGRAMS) *.o
