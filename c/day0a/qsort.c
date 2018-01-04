#include <stdio.h>
#include <stdlib.h>

static int cmp_int(const void *data1, const void *data2)
{
	const int *d1 = data1;
	const int *d2 = data2;

	return *d2 - *d1;
}

int main(void)
{
	int arr[] = {4,3,2,1,8,7,5,0,9,10,6};

	qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), cmp_int);

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		printf("%d ", arr[i]);	
	}
	printf("\n");

	return 0;
}

