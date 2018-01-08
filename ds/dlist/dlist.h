#ifndef __DLIST_H
#define __DLIST_H

//双向环链

typedef enum {
	INSERT_FRONT,
	INSERT_TAIL
}insertway_t;

struct node_st {
	struct node_st *prev;	
	struct node_st *next;
	char data[0];
};

typedef struct {
	struct node_st head;
	int size;
}dlisthead_t;

typedef int (*cmp_t)(const void *data, const void *key);
typedef void (*print_t)(const void *data);

int dlisthead_init(int size, dlisthead_t **l);

int dlist_insert(dlisthead_t *h, const void *data, insertway_t way);

int dlist_delete(dlisthead_t *h, const void *key, cmp_t cmp);

void dlist_traval(const dlisthead_t *h, print_t pri);

void dlist_destroy(dlisthead_t * h);

#endif

