#include <stdio.h>

#define NUM 10

static int isprimer(int num);
int main(void)
{
	int arr[NUM] = {};
	int cnt = 0;

	for (int i = 0; i < NUM; i++) {
		printf("请输入第%d个数\n", i+1);	
		scanf("%d", arr+i/*&arr[i]*/);	
		if (isprimer(arr[i]))
			cnt ++;
	}

	printf("有%d个质数\n", cnt);

	return 0;
}

static int isprimer(int num)
{
	int i;

	if (num < 2)
		return 0;

	for (i = 2; i <= num/2; i++) {
		if (num % i == 0)	
			break;
	}

	return i > num / 2;
}


