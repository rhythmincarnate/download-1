#include <stdio.h>

static void swap(int *a, int *b);
static int max_min_array(int *p, int nmemb, int *min);
int main(void)
{
	int n1 = 100;
	int n2 = 200;
	int arr[] = {1,6,5,2,3,9,8,7,10,19,2};

	swap(&n1, &n2);
	printf("n1:%d, n2:%d\n", n1, n2);

	n1 = max_min_array(arr, sizeof(arr)/sizeof(arr[0]), &n2);
	printf("数组中的最大值:%d, 最小值:%d\n", n1, n2);

	return 0;
}

/*
	定义一个函数，实现两个整型数的交换 
	a, b指针变量 
 */
static void swap(int *a, int *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}

/*
	定义一个函数,求得一个整型数组的最大最小值 
p:存储待计算的数组首地址
nmemb:带计算数组的成员个数
min:存储调用者获取最小值变量的地址
return value:
	最大值
 */
static int max_min_array(int *p, int nmemb, int *min)
{
	int max;
	*min = max = p[0];
	for (int i = 1; i < nmemb; i++) {
		if (p[i] > max)	//*(p+i)
			max = p[i];
		if (p[i] < *min)
			*min = p[i];
	}

	return max;
}

