#ifndef __LSTACK_H
#define __LSTACK_H

#include <dlist.h>

//链式存储的栈结构

typedef dlisthead_t lstack_t;

/***********基本操作*************/
//初始化栈结构
int lstack_init(int size, lstack_t **s);

//入栈:将链表的第一个结点看成栈顶
int lstack_push(lstack_t *s, const void *data);

int lstack_isempty(lstack_t *s);

int lstack_pop(lstack_t *s, void *data);

void lstack_destory(lstack_t *s);

#endif

