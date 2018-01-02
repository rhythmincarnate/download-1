#include <stdio.h>

int main(void)
{
	int num = 100;
	int *p = &num;
	int **pp = &p;
	char *c;

	printf("%d %d %d\n", num, *p, **pp);

	**pp = 328;
	printf("num: %d\n", num);

	c = (char *)p;//256+64+8--->1 0100 1000
	printf("%d\n", *c);


	return 0;
}

