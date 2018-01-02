#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int *test(void)
{
	//static int num;
	int num = 100;
	int *p = NULL;

	p = malloc(4);
	if (NULL == p) {
		return NULL;
	}

	//为动态开辟的堆空间赋初始值
	memset(p, '\0', 4);

	*p = num;

	return p;
}

int main(void)
{
	int *p = NULL;

	p = test();

	printf("%d\n", *p);

	free(p);
	p = NULL;//推荐
	free(p);
	/*
		释放:
	   		1.如果不去释放,当进程结束了，内核会释放
		但是做到谁申请谁释放	
			2.free(NULL)是没有问题的　no operation is performed
			3.free(ptr)　ptr不为NULL 一定不可重复free
			4.free(ptr) ptr一定要是堆空间 
	 */

	return 0;
}

