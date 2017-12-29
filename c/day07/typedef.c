#include <stdio.h>

//定义类型
typedef int s_t;
typedef int *p_t;

#define DPS	int *

int main(void)
{
	s_t a, b;
	p_t q;
	p_t m, n;
	DPS o, p;//int *o, p;

	printf("%ld %ld\n", sizeof(m), sizeof(n));
	printf("%ld %ld\n", sizeof(o), sizeof(p));

	a = 100;

	q = &a;

	printf("%d\n", *q);

	return 0;
}

