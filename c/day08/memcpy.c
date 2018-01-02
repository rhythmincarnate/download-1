#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	int *p = NULL;

	p = calloc(10, sizeof(int));
	//if error

#if 0
	for (int i = 0; i < 10; i++) {
		p[i] = arr[i];	
	}
#endif

#if 0
	memcpy(p, arr, 10*sizeof(int));

	for (int i = 0; i < 10; i++) {
		printf("%d ", p[i]);	
	}
	printf("\n");

	free(p);
	p = NULL;
#endif

	//memcpy缺点 src和dest地址重叠 使用memmove(3)代替
	//memcpy(arr+2, arr, 4*sizeof(int));
	memmove(arr+2, arr, 4*sizeof(int));
	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	printf("\n");


	return 0;
}

