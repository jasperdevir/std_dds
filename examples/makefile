CC := gcc
CFLAGS := -Wall -Werror -std=c11 -I../

.PHONY: all mkbin clean

all: mkbin array_list d_linked_list linked_list queue stack

mkbin: 
	mkdir -p bin

array_list: array_list.c
	$(CC) $(CFLAGS) -o ./bin/$@ $^

d_linked_list: d_linked_list.c
	$(CC) $(CFLAGS) -o ./bin/$@ $^

linked_list: linked_list.c
	$(CC) $(CFLAGS) -o ./bin/$@ $^

queue: queue.c
	$(CC) $(CFLAGS) -o ./bin/$@ $^

stack: stack.c
	$(CC) $(CFLAGS) -o ./bin/$@ $^

clean:
	rm -rf bin
	mkdir -p bin
