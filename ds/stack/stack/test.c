#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "stack.h"

//汉诺塔 三个栈模拟三个柱子a,b,c, a柱子有n个圆盘,目的将n个圆盘移到b柱子\
	在移动期间永远不能将大的放在小的上

static void *addr[3]; 
static int cnt = 0;

/*
 将栈a中的栈顶的圆盘移动到b上
 */
void move(stack_t *a, stack_t *b)
{
	char *tmp = NULL;

	if (isempty(a))	
		return;
	tmp = malloc(a->size);//存放出栈元素
	//if error
	pop(a, tmp);
	if (isfull(b))
		return;
	push(b, tmp);

	//调试
	for (int i = 0; i < 3; i++) {
		if (a == addr[i])
			printf("%d号", i+1);
	}
	for (int i = 0; i < 3; i++) {
		if (b == addr[i])
			printf("---->%d号", i+1);
	}
	printf("%d\n", *((int*)tmp));

	free(tmp);
	//sleep(1);
	//getchar();
	cnt ++;
}

/*
 将栈a中所有的元素(圆盘)有序移动到b,借助c
 */
int hanno(int n, stack_t *a, stack_t *b, stack_t *c)
{
	if (n == 1) {
		move(a, b);
		return 0;
	}
	if (n < 1)
		return -1;
	hanno(n-1, a, c, b);	
	//hanno(1, a, b, c);
	move(a, b);
	hanno(n-1, c, b, a);	

}

int main(void)
{
	stack_t *a, *b, *c;	
	int num;

	a = init(sizeof(int), 10);
	b = init(sizeof(int), 10);
	c = init(sizeof(int), 10);

	addr[0] = a;
	addr[1] = b;
	addr[2] = c;

	for (int i = 10; i > 0; i--) {
		push(a, &i);	
	}

	hanno(9, a, b, c);	

	printf("共多少步%d\n", cnt);

	while (!isempty(b)) {
		pop(b, &num);
		printf("%d ", num);
	}
	printf("\n");

	destory(a);
	destory(b);
	destory(c);

	return 0;
}

