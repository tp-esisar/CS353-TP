CFLAGS=-g -Wall
LFLAGS=
HEADERS=ListeChain.h

%.o: %.c $(HEADERS)
	gcc -c $(CFLAGS) $< -o $@

test.e: main.o ListeChain.o
	gcc $(LFLAGS) $^ -o $@

runTest: test.e
	./test.e
	

