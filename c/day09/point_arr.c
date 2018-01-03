#include <stdio.h>

int main(void)
{
	char *str[2][3] = {
		{"hello", "good", "boys"},
		{"world", "uplooking", "girls"}
	};
	int arr[2][3] = {1,2,3,4,5,6};
	int (*p)[3] = arr; //数组指针 type (*p)[nmemb]
	char *(*q)[3] = str;
	int (*l)[2][3] = &arr;

	int ptr[10] = {};

	int *n = ptr;
	int (*m)[10] = &ptr;
	printf("m:%p, n:%p\n", m, n);
	printf("m+1:%p, n+1:%p\n", m+1, n+1);

	puts(str[1][1]);

	//arr == &arr[0] ---->int (*)[3]

	printf("%p\n", p);
	printf("%p\n", p+1);

	printf("%p\n", q);
	printf("%p\n", q+1);

	puts(q[0][2]);

	printf("l:%p\n", l);
	printf("l+1:%p\n", l+1);

	return 0;
}


