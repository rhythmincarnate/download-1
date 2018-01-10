
CFLAGS+=-I.
OBJ = lqueue

$(OBJ):main.o lqueue.o dlist.o
	gcc -o $@ $^
clean:
	rm *.o $(OBJ)

