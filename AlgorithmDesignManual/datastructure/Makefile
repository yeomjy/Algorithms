CC=gcc
CFLAGS=-Wall -g

OBJS=queue.o stack.o test_queue test_stack

ALL: $(OBJS)

test_queue: test_queue.c queue.o
	$(CC) $(CFLAGS) test_queue.c queue.o -o test_queue

test_stack: test_stack.c stack.o
	$(CC) $(CFLAGS) test_stack.c stack.o -o test_stack

queue.o: queue.c 
	$(CC) $(CFLAGS) -c queue.c -o queue.o 

stack.o: stack.c 
	$(CC) $(CFLAGS) -c stack.c -o stack.o

clean:
	rm -rf *.dSYM 
	rm -f $(OBJS)

