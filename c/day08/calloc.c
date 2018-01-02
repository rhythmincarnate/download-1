#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
	定义一个函数，返回一个整型数组	 
	为数组产生随机值 
 */
static int *getarr(int nmemb)
{
	int *p = NULL;	

	p = calloc(nmemb, sizeof(int));
	if (NULL == p)
		return NULL;
	
	srand(getpid());	
	for (int i = 0; i < nmemb; i++) {
		p[i] = rand() % 100;	
	}
		
	return p;
}

/*
 	函数的功能与上一致
		函数的返回值 0成功
					 -1失败
 */
static int get_another(int **arr, int nmemb)
{
	*arr = calloc(nmemb, sizeof(int));	
	if (NULL == *arr)
		return -1;
	
	srand(getpid());	
	for (int i = 0; i < nmemb; i++) {
		(*arr)[i] = rand() % 100;	
	}
		
	return 0;
}


int main(void)
{
	int *arr = NULL;

	//arr = getarr(10);
	get_another(&arr, 10);

	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);	
	}
	printf("\n");

	free(arr);

	return 0;
}

