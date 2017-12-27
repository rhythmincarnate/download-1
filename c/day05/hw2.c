#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define NUM 20

int main(void)
{
	int arr[NUM] = {};
	int i, j;
	
	srand(getpid());

	for (int i = 0; i < NUM; i++) {
		arr[i] = rand() % 11;	
		printf("%d ", arr[i]);
	}
	printf("\n");
		
	//将数组偶数在前，基数在后

	for (i = 0, j = NUM-1; i < j; i++, j--) {
		if (arr[i] % 2) {
			//arr[i]是一个奇数	
			while (1) {
				if (!(arr[j] % 2)) 
					break;
				j--;
				if (j == i)//数组没有偶数
					goto END;
			}		
			arr[i] = arr[i] ^ arr[j];
			arr[j] = arr[i] ^ arr[j];
			arr[i] = arr[i] ^ arr[j];
		} else {
			j++;	
		}
	}

END:
	printf("after\n");
	for (int i = 0; i < NUM; i++) {
		printf("%d ", arr[i]);	
	}
	printf("\n");

	return 0;
}

