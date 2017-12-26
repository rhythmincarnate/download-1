#include <stdio.h>

/*
 	数组:
		定义
			type arr[nmemb];
			成员个数不能缺省
		初始化
			成员个数能缺省
		赋值
		遍历
	一维数组
	二维数组
	字符数组
 */

int main(void)
{
	int arr1[10];//相当于定义了10个整型变量,存储地址连续	
	int arr2[3] = {1};
	int arr3[] = {1,2,3,4};
	//int arr4[10] = {[4]=10};
	int arr4[10];

	for (int i = 0; i < 10 || !printf("\n"); i++) {
		printf("%d ", arr4[i]);	
	}

	printf("sizeof(arr):%ld\n", sizeof(arr1));
	//数组的赋值
	//arr1[0] ~ arr1[9]
	for (int i = 0; i < 10; i++) {
		arr1[i] = i+1;	
	}

	//数组的遍历
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr1[i]);	
	}
	printf("\n");

	return 0;
}

