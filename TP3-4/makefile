CFLAGS=-g -Wall
LFLAGS=
HEADERS=ArbreRN.h


main.e: main.o ArbreRN.o
	gcc $(LFLAGS) $^ -o $@

main.o: main.c 
	gcc -c $(CFLAGS) $< -o $@

test.e: sample.o ArbreRN.o
	gcc $(LFLAGS) $^ -o $@

	
%.o: %.c $(HEADERS)
	gcc -c $(CFLAGS) $< -o $@

runTest: test.e
	./test.e
	

