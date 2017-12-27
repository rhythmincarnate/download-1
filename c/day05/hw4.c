#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM 20

int main(void)
{
	int score[NUM] = {};
	int cnt[11] = {};

	srand(time(NULL));
	for (int i = 0; i < NUM; i++) {
		score[i] = rand() % 101;	
		cnt[score[i] / 10] ++;
		printf("%d ", score[i]);
	}
	printf("\n");

	printf("100: ");
	for (int i = 0; i < cnt[10]; i++) {
		printf("* ");	
	}
	printf("\n");

	for (int i = 9; i >= 0; i--) {
		printf("%2d~%2d: ", i*10, i*10+9);
		for (int j = 0; j < cnt[i]; j++) {
			printf("* ");	
		}	
		printf("\n");
	}

	return 0;
}

