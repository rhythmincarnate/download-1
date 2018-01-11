#ifndef __STACK_H
#define __STACK_H

typedef struct {
	void *bottom;//栈底地址
	void *top;//入栈元素地址
	int size;//每个元素占字节个数
	int container;//栈容量(最多存储的成员个数)
}stack_t;

stack_t *init(int size, int container);

int isempty(const stack_t *s);

int isfull(const stack_t *s);

int push(stack_t *s, const void *data);

int pop(stack_t *s, void *data);

void destory(stack_t *s);

#endif

