CFLAGS=-g -Wall
LFLAGS=
HEADERS=ArbreRN.h



test.e: sample.o ArbreRN.o
	gcc $(LFLAGS) $^ -o $@
	
	
%.o: %.c $(HEADERS)
	gcc -c $(CFLAGS) $< -o $@

runTest: test.e
	./test.e
	

