#include <stdio.h>

int main(void)
{
	int arr[4] = {1,2,3,4};
	int arr2[2][3] = {};

	printf("arr:%p\n", arr);
	printf("arr+1:%p\n", arr+1);

	printf("&arr:%p\n", &arr);
	printf("&arr+1:%p\n", &arr+1);

	printf("arr2:%p\n", arr2);
	printf("arr2+1:%p\n", arr2+1);
	printf("&arr2[0]:%p\n", &arr2[0]);
	printf("&arr2[0]+1:%p\n", &arr2[0]+1);

	return 0;
}

