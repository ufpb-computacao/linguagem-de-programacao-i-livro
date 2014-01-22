CC=gcc
CFLAGS=-Wall -g -std=c1x

all: lingua-do-i lingua-do-i-test

lingua-do-i: lingua-do-i.c
	$(CC) $(CFLAGS) lingua-do-i.c lingua-do-i-core.c -o lingua-do-i

lingua-do-i-test: lingua-do-i-test.c
	$(CC) $(CFLAGS) lingua-do-i-test.c lingua-do-i-core.c -o lingua-do-i-test

test_all:
	./lingua-do-i-test

clean:
	rm -rf lingua-do-i lingua-do-i-test

