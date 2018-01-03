#include <stdio.h>
#include <stdlib.h>

static int sum2num(int a, int b)
{
	return a + b;
}

static int sub2num(int a, int b)
{
	return a - b;
}

int main(int argc, char **argv)
{
	int res;
	//函数指针:存储一个函数的地址
	//定义 返回值类型 (*p)(参数列表类型)
	int (*p)(int, int);

	p = sum2num;

	if (argc < 3)
		return 1;

	res = sum2num(atoi(argv[1]), atoi(argv[2]));	
	printf("%d\n", res);

	p = sub2num;

	res = p(atoi(argv[1]), atoi(argv[2]));	
	printf("%d\n", res);

	return 0;
}

