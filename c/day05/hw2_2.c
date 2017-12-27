#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define NUM 20

int main(void)
{
	int arr[NUM] = {};
	int new[NUM] = {};
	int i, j, k;
	
	srand(getpid());

	for (int i = 0; i < NUM; i++) {
		arr[i] = rand() % 11;	
		printf("%d ", arr[i]);
	}
	printf("\n");
		
	//将数组偶数在前，基数在后
	for (i = 0, k = 0, j = NUM-1; i < NUM; i++) {
		if (arr[i] % 2 == 0) {
			new[k++] = arr[i];	
		} else {
			new[j--] = arr[i];
		}
	}

	for (i = 0; i < NUM; i++) {
		printf("%d ", new[i]);	
	}
	printf("\n");

	return 0;
}

