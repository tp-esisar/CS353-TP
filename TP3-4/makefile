CFLAGS=-g -Wall
LFLAGS=
HEADERS=ArbreRN.h

%.o: %.c $(HEADERS)
	gcc -c $(CFLAGS) $< -o $@

test.e: sample.o ArbreBin.o
	gcc $(LFLAGS) $^ -o $@

runTest: test.e
	./test.e
	

