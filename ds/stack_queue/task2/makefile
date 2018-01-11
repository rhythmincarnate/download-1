
LDFLAGS+=-lstack -L.
LDFLAGS+=-lqueue -L.

CFLAGS+=-I/srv/ftp/download/emb20171218/ds/queue/queue/lib1
CFLAGS+=-I/srv/ftp/download/emb20171218/ds/stack/stack

main:main.o
	gcc -o $@ $^ $(CFLAGS) $(LDFLAGS)

clean:
	rm *.o main
