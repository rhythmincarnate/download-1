#include <stdio.h>
#include <stdlib.h>

static int isprimer(int num)
{
	int f = 1;

	if (num <= 1 )
		return 0;

	for (int i = 2; i <= num/2; i++) {
		if (num % i == 0) {
			f = 0;
			break;
		}
	}

	return f;
}

int main(void)
{
	int *arr = NULL;
	int i = 0;
	int num;

	while (1) {
		scanf("%d", &num);	
		if (num == -1)	
			break;
		arr = realloc(arr, (i+1)*sizeof(int));	
		if (NULL == arr) {
			printf("realloc() failed\n");
			return 1;
		}

		arr[i] = num;

		i++;
	}			

	num = 0;
	for (int j = 0; j < i; j++) {
		if (isprimer(arr[j]))	
			num ++;
	}

	printf("共%d个素数\n", num);

	return 0;
}

