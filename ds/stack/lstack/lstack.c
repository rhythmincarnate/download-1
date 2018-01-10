#include <stdlib.h>
#include <lstack.h>

int lstack_init(int size, lstack_t **s)
{
	return dlisthead_init(size, s);		
}

//入栈:将链表的第一个结点看成栈顶
int lstack_push(lstack_t *s, const void *data)
{
	return dlist_insert(s, data, INSERT_FRONT);
}

int lstack_isempty(lstack_t *s)
{
	return dlist_isempty(s);
}

static int __cmpfun(const void *data, const void *key)
{
	return 0;
}

int lstack_pop(lstack_t *s, void *data)
{
	return dlist_fetch(s, NULL, __cmpfun, data);	
}

void lstack_destory(lstack_t *s)
{
	dlist_destroy(s);
}

