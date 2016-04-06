CFLAGS=-g -Wall
LFLAGS=
HEADERS=ArbreBin.h

%.o: %.c $(HEADERS)
	gcc -c $(CFLAGS) $< -o $@

test.e: main.o ListeChain.o
	gcc $(LFLAGS) $^ -o $@

runTest: test.e
	./test.e
	

