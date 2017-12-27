#include <stdio.h>

#define NUM 10

int main(void)
{
	int arr[NUM][NUM] = {};

	printf("   ");
	for (int i = 1; i <= NUM; i++) {
		printf("%-2d", i);	
	}
	printf("\n");
	for (int i = 0; i < NUM; i++) {
		printf("%-3d", i+1);			
		for (int j = 0; j < NUM; j++) {
			if (arr[i][j] == 0) {
				printf("+ ");	
			}
		}	
		printf("\n");
	}


	return 0;
}

