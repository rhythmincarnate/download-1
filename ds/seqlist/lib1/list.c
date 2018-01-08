#include <stdlib.h>
#include <string.h>

#include <list.h>

int seqlist_init(int size, seqlist_t **l)
{
	seqlist_t *me = NULL;

	me = malloc(sizeof(seqlist_t));
	if (NULL == me)
		return -1;
	memset(me, '\0', sizeof(seqlist_t));

	me->arr = NULL;	
	me->nmemb = 0;
	me->size = size;

	*l = me;

	return 0;
}


int seqlist_insert(seqlist_t *l, const void *data)
{
	//为新成员开辟存储空间
	l->arr = realloc(l->arr, (l->nmemb+1) * l->size);
	if (l->arr == NULL)
		return -1;

	//将成员复制到新的地址空间中
	memcpy((char *)l->arr + l->nmemb * l->size, data, l->size);
	l->nmemb ++;

	return 0;
}


void seqlist_traval(const seqlist_t *l, print_t pri)
{
	for (int i = 0; i < l->nmemb; i++) {
		pri((char *)l->arr + i*l->size);
	}
}


void seqlist_destroy(seqlist_t *l)
{
	free(l->arr);
	free(l);
}


void *seqlist_search(const seqlist_t *l, const void *key, cmp_t cmp)
{
	for (int i = 0; i < l->nmemb; i++) {
		if (!cmp((char *)l->arr + i*l->size, key))	
			return l->arr+i*l->size;
	}

	return NULL;
}


int seqlist_delete(seqlist_t *l, const void *key, cmp_t cmp)
{
	void *s = NULL;	
	char *end;
	int movesize = 0;

	s = seqlist_search(l, key, cmp);
	if (NULL == s) {
		return -1;
	}

	//s就是要删除元素的首地址
	end = (char *)l->arr + l->nmemb * l->size;
	movesize = end - (char *)s+l->size;//要移动的字节个数
	memmove(s, (char *)s+l->size, movesize);

	l->nmemb --;

	l->arr = realloc(l->arr, l->nmemb * l->size);
	if (NULL == l->arr)
		return -1;

	return 0;
}


