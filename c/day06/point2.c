#include <stdio.h>

//*和++作用于指针的几种情况
int main(void)
{
	int arr[] = {1,2,3,4,5};
	int *p;

	p = arr;

	//p++;//arr++不可以

	//printf(char *p, int b)
	
	printf("%d\n", *p++);//b = *p++	
	printf("%d\n", *(p++));//b = *(p++);	
	printf("%d\n", (*p)++);//b = (*p)++	
	printf("%d\n", ++*p);
	printf("%d\n", *++p);

	for (int i = 0; i < sizeof(arr) / sizeof(*arr); i++) {
		printf("%d ", arr[i]);	
	}
	printf("\n");

	return 0;
}

