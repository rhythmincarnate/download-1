#include <stdio.h>

int main(void)
{
	char str[] = "happy new year";	
	const char *p = str;//常量指针
	long *q;
	int arr[] = {10, 20, 30, 40, 50};
	int *pa1, *pa2;

	*p ++;
	printf("str:%s\n", str);
	printf("p:%s\n", p);

	//指针的类型决定的是步长
	q = (long *)str;
	q++;
	printf("%s\n", (char *)q);

	//指针的类型与字节宽度无关
	printf("sizeof(p):%ld, sizeof(q):%ld\n", sizeof(p), sizeof(q));
	printf("sizeof(*p):%ld, sizeof(*q):%ld\n", sizeof(*p), sizeof(*q));

	//同类型的指针相减，得到的是两个地址之间的元素个数
	printf("%ld\n", ((char *)q - p));

	pa1 = arr;
	pa2 = &arr[4];
	printf("pa2-pa1:%ld\n", pa2-pa1);


	return 0;
}

