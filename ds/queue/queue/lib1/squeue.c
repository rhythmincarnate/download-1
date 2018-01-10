#include <stdlib.h>
#include <string.h>

#include <squeue.h>

int squeue_init(squeue_t **l, int summemb, int size)
{
	squeue_t *q;

	q = malloc(sizeof(squeue_t));
	if (NULL == q)
		return -1;
	memset(q, '\0', sizeof(squeue_t));
	q->start = calloc(summemb, size);
	if (NULL == q->start) {
		free(q);
		return -1;
	}
	q->size = size;
	q->summemb = summemb;
	q->front = q->tail = 0;

	*l = q;

	return 0;
}

int squeue_isempty(const squeue_t *l)
{
	return l->front == l->tail;
}

int squeue_isfull(const squeue_t *l)
{
	return (l->tail+1) % l->summemb == l->front;
}

int squeue_enq(squeue_t *l,const void *data)
{
	if (squeue_isfull(l))
		return -1;
	memcpy((char *)l->start + l->tail * l->size, data, l->size);
	l->tail = (l->tail + 1) % l->summemb;

	return 0;
}

int squeue_deq(squeue_t *l,void *data)
{
	if (squeue_isempty(l))
		return -1;
	memcpy(data, (char *)l->start + l->front * l->size, l->size);
	l->front = (l->front + 1) % l->summemb;

	return 0;
}

int squeue_destroy(squeue_t *l)
{
	free(l->start);
	free(l);
}

