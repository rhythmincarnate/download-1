#include <stdlib.h>
#include <string.h>

#include <list.h>

listhead_t *listhead_init(int size)
{
	listhead_t *h = NULL;

	h = malloc(sizeof(*h));
	if (NULL == h)
		return NULL;
	memset(h, '\0', sizeof(*h));

	h->head.next = &h->head;
	h->size = size;

	return h;
}


int list_insert(listhead_t *h, const void *data, insertway_t way)
{
	struct node_st *new = NULL;
	struct node_st *cur = NULL;

	//新结点开辟存储空间
	new = calloc(1, sizeof(*new));
	if (NULL == new)
		return -1;

	//存放结点的数据	
	new->data = malloc(h->size);
	if (NULL == new->data) {
		free(new);
		return -1;
	}
	memcpy(new->data, data, h->size);

	//插入链表中
	if (way == FRONT) {
		//头插
		new->next = h->head.next;
		h->head.next = new;
	} else if (way == TAIL) {
		//尾插
		for (cur = h->head.next; cur->next != &h->head; ) {
			cur = cur->next;	
		}
		//cur存储的是最后一个结点的地址
		cur->next = new;
		new->next = &h->head;
	} else {
		free(new->data);
		free(new);
		return -1;
	}

	return 0;
}


void list_traval(const listhead_t *h, print_t pri)
{
	struct node_st *cur = NULL;	

	for (cur = h->head.next; cur != &h->head; cur = cur->next)
		pri(cur->data);

}


void list_destroy(listhead_t *h)
{
	struct node_st *cur, *n;

	cur = h->head.next;
	n = cur->next;

	while (cur != &h->head) {
		free(cur->data);	
		free(cur);
		cur = n;	
		n = n->next;
	}

	free(h);
}

static struct node_st *find_prev(listhead_t * h, const void *key, cmp_t cmp)
{
	struct node_st *p, *cur;

	for (p = &h->head, cur = h->head.next; cur != &h->head; p = cur, cur = cur->next) {
		if (!cmp(cur->data, key)) {
			return p;
		}
	}
	
	return NULL;
}

int list_delete(listhead_t *h, const void *key, cmp_t cmp)
{
	struct node_st *f = NULL, *c = NULL;

	f = find_prev(h, key, cmp);
	if (f == NULL)
		return -1;
	c = f->next;//c存储的就是要删除的结点的地址
	f->next = c->next;
	c->next = NULL;
	free(c->data);
	free(c);

	return 0;
}

void *list_search(const listhead_t *h, const void *key, cmp_t cmp)
{
	struct node_st *f = NULL;

	f = find_prev(h, key, cmp);
	if (f == NULL)
		return NULL;
	return f->next->data;
}

int list_update(const listhead_t *h, const void *key, cmp_t cmp, const void *newdata)
{
	void *p = NULL;

	p = list_search(h, key, cmp);
	if (p == NULL)
		return -1;
	memcpy(p, newdata, h->size);

	return 0;
}


