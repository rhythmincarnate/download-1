/*
	随机产生有10个整型数所组成的数组，求得其最大最小及平均值 
 	将数组的最大最小值交换
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define NUM	10

int main(void)
{
	int arr[NUM] = {};
	int max, min, sum;
	int maxindex, minindex;
	
	srand(getpid());
	for (int i = 0; i < NUM; i++) {
		arr[i] = rand() % 100;	
		printf("%-3d", arr[i]);	
	}
	printf("\n");

	max = min = sum = arr[0];
	maxindex = minindex = 0;
	for (int i = 1; i < NUM; i ++) {
		if (arr[i] > max) {	
			max = arr[i];
			maxindex = i;
		}
		if (arr[i] < min) {
			min = arr[i];
			minindex = i;
		}
		sum += arr[i];
	}
	printf("max:%d, min:%d, avg:%d\n", max, min, sum / NUM);

	//最大最小值交换
	arr[maxindex] = arr[minindex];
	arr[minindex] = max;

	for (int i = 0; i < NUM; i++) {
		printf("%d ", arr[i]);	
	}
	printf("\n");


	return 0;
}

