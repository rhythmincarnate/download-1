#ifndef __SQUEUE_H
#define __SQUEUE_H

typedef struct squeue_st{
	void *start;
	int front;
	int tail;
	int size;
	int summemb;
}squeue_t;

int squeue_init(squeue_t **l, int summemb, int size);

int squeue_isempty(const squeue_t *l);

int squeue_isfull(const squeue_t *l);

int squeue_enq(squeue_t *l,const void *data);

int squeue_deq(squeue_t *l,void *data);

int squeue_destroy(squeue_t *l);

#endif

