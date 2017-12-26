#include <stdio.h>

static int sumn(int n);
static int febonacci(int n);
int main(void)
{
	printf("%d\n", sumn(100));

	for (int i = 1; i <= 10; i++) {
		printf("%d ", febonacci(i));	
	}
	printf("\n");

	return 0;
}

/*
 递归调用:解决步骤问题
	终止条件
	递归点
 */
static int sumn(int n)
{
	if (n == 1)
		return 1;
	
	return n + sumn(n-1);
	//3 + sumn(2) 
	//3 + 2 + sumn(1)
	//3 + 2 + 1
}

static int febonacci(int n)
{
	if (n == 1 || n == 2)	
		return 1;

	return febonacci(n-1) + febonacci(n-2);
}


