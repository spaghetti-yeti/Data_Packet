.SUFFIXES: .c .o 
CC = gcc
CFLAGS = -g

.c.o:  
	$(CC) $(CFLAGS) -c $<

p2: p2.o p2fun.o
	gcc p2.o p2fun.o -o p2

p2.o:	p2.h

clean:
	rm -f *.o core
