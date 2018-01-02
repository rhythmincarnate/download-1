#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//p 二级指针:存储一级指针变量的地址
static void test(char **p)
{
	*p = malloc(100);
	if (NULL == *p)
		return ;
	memset(*p, '\0', 100);
	strcpy(*p, "good morning");
}

static void free_test(char *p)
{
	free(p);
	p = NULL;
}

int main(void)
{
	char *q = NULL;	

	test(&q);//p = q
	printf("%s\n", q);

	//free(q);
	free_test(q);

	return 0;
}

