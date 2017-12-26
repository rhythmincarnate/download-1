#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#define NUM	20

/*
   a[b] -----> *(a+b)   a / b一定有一个是地址
	类型
		char short int long float double 

	int a;
	&a类型int *

	强转
		int a; 
		int *值+int值---->int *
		int * + 1---->sizeof(int)
		
*/

int main(void)
{
	int arr[NUM] = {};	

	srand(getpid());//只提供一次	
	for (int i = 0; i < NUM; i++) {
		//i[arr] = rand() % 100;
		*(arr+i) = rand() % 100;
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}

