#include <stdio.h>

int main(void)
{
	int row;
	int t;

	printf("多少行?\n");
	scanf("%d", &row);
	/*
	 	* * *
	 	* * *
	 	* * *
	 */

	for (int i = 0; i < row; i++) {
		//空格
		for (int j = 0; j < row-i-1; j++) {
			printf(" ");	
		}
		for (int j = 0; j < 2*i+1; j++) {
			printf("*");	
		}	
		printf("\n");
	}

	printf("-------------hw2-------------\n");

	for (int i = 0; i < row; i++) {
		for (int j = 0; j <= i; j++) {
			printf("%c", 'A'+j % 26);
		}		
		printf("\n");
	}


	return 0;
}

