#include <stdlib.h>
#include <string.h>

#include <dlist.h>

struct node_st {
	struct node_st *prev;	
	struct node_st *next;
	char data[0];
};

typedef struct {
	struct node_st head;
	int size;
}head_t;

int dlisthead_init(int size, dlisthead_t **l)
{
	head_t *h;

	h = malloc(sizeof(*h));
	if (NULL == h)
		return -1;
	memset(h, '\0', sizeof(*h));
	h->head.prev = h->head.next = &h->head;	
	h->size = size;

	*l = h;

	return 0;
}

/*
 将new结点插入到prev和next结点直接
 */
static void __insert(struct node_st *new, struct node_st *prev, struct node_st *next)
{
	new->prev = prev;
	new->next = next;
	prev->next = new;
	next->prev = new;
}

int dlist_insert(dlisthead_t *head, const void *data, insertway_t way)
{
	struct node_st *new;	
	head_t *h = head;

	new = malloc(sizeof(*new) + h->size);
	if (NULL == new)
		return -1;
	memcpy(new->data, data, h->size);

	if (way == INSERT_FRONT) {
		__insert(new, &h->head, h->head.next);
	} else if (way == INSERT_TAIL) {
		__insert(new, h->head.prev, &h->head);
	} else {
		free(new);
		return -1;
	}

	return 0;
}

/*
prev:待删除结点的前驱结点地址
next:待删除结点的后继结点的地址
 */
static void __delete(struct node_st *prev, struct node_st *next)
{
	prev->next = next;
	next->prev = prev;
}

static struct node_st *find_node(dlisthead_t *head, const void *key, cmp_t cmp)
{
	struct node_st *cur;
	head_t *h = head;

	for (cur = h->head.next; cur != &h->head; cur = cur->next)
		if (cmp(cur->data, key) == 0)
			return cur;

	return NULL;
}

int dlist_delete(dlisthead_t *head, const void *key, cmp_t cmp)
{
	struct node_st *f;
	head_t *h = head;

	f = find_node(h, key, cmp);
	if (f == NULL)
		return -1;
	__delete(f->prev, f->next);
	f->prev = f->next = NULL;
	free(f);

	return 0;
}

void dlist_traval(const dlisthead_t *head, print_t pri)
{
	struct node_st *cur;
	const head_t *h = head;

	for (cur = h->head.next; cur != &h->head; cur = cur->next)
		pri(cur->data);
}

void dlist_destroy(dlisthead_t * head)
{
	struct node_st *cur;	
	head_t *h = head;

	if (h->head.prev == &h->head && h->head.next == &h->head ) {
		//只有头结点
		free(h);
		return;
	}
			
	cur = h->head.next;//第一个结点地址
	for (cur = cur->next; cur != &h->head; cur = cur->next) {
		free(cur->prev);	
		cur->prev = NULL;
	}
	free(cur->prev);//最后一个结点

	free(h);
}

void *dlist_search(dlisthead_t *head, const void *key, cmp_t cmp)
{
	struct node_st *f = NULL;
	head_t *h = head;

	f = find_node(h, key, cmp);
	if (NULL == f)
		return NULL;

	return f->data;
}


int dlist_fetch(dlisthead_t *head, const void *key, cmp_t cmp, void *data)
{
	struct node_st *f = NULL;
	head_t *h = head;

	f = find_node(h, key, cmp);
	if (NULL == f)
		return -1;

	memcpy(data, f->data, h->size);
	dlist_delete(h, key, cmp);

	return 0;
}

int dlist_isempty(dlisthead_t *head)
{
	head_t *h = head;
	return h->head.next == &h->head && h->head.prev == &h->head;
}


int dlist_getfirstnode(dlisthead_t *head, void *data)
{
	head_t *h = head;
	if (dlist_isempty(h))
		return -1;
	memcpy(data, (h->head.next)->data, h->size);	

	return 0;
}

