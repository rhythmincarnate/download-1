/*
 读入一个整型数
 将其转换为2进制输出
 */
#include <stdio.h>

#define NUM 	32

int main(void)
{
	int arr[NUM] = {};
	int num;
	int i;

	printf("请输入一个整型数: ");
	scanf("%d", &num);

	i = 0;
	while (i < NUM) {
		arr[i++] = num % 2;	
		num /= 2;	
		if (num == 0)
			break;
	}

	for (i = NUM-1; i >= 0; i--) {
		if ((i + 1) % 8 == 0)
			printf(" ");
		printf("%d", arr[i]);	
	}
	printf("\n");

	return 0;
}

