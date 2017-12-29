#include <stdio.h>

/*
警示调用者a, b不能给定同一个地址 
restrict关键字 c99
要求调用者正确调用才能得到理想的结果
 */
int fun(int * restrict a, int * restrict b);
int main(void)
{
	int n1, n2;

	n1 = 100;
	n2 = 200;
	printf("%d\n", fun(&n1, &n2));	

	return 0;
}


int fun(int * restrict a, int * restrict b)
{
	*a = 5;
	*b = 7;

	return *a + *b;
}


