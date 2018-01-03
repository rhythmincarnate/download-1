#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void (*cmp_t)(const void *, const void *);

//void sort_array(void *arr, int nmemb, int size, int (*cmp)(const void *, const void *));
void sort_array(void *arr, int nmemb, int size, cmp_t cmp);
static int cmp_int(const void *data1, const void *data2)
{
	const int *d1 = data1;
	const int *d2 = data2;

	return *d2 - *d1;
}

static int cmp_str(const void *data1, const void *data2)
{
	char **d1 = (char **)data1;
	char **d2 = (char **)data2;

	return strcmp(*d2, *d1);
}

int main(int argc, char **argv)
{
	int arr[] = {3,1,2,7,6,8,9,10,5,3,4};

	sort_array(arr, sizeof(arr)/sizeof(arr[0]), sizeof(int), cmp_int);

	for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
		printf("%d ", arr[i]);	
	}
	printf("\n");

	sort_array(argv, argc, sizeof(char *), cmp_str);
	for (int i = 0; argv[i]; i++)
		puts(argv[i]);

	
	return 0;
}

/*
 定义一个函数:为任意类型的数组排序
arr:数组的首地址
nmemb:成员个数
size:每个成员的字节个数
cmp:比较函数，根据待比较两个元素的地址，比较其大小关系
 */
static void swap2num(void *data1, void *data2, int size);
void sort_array(void *arr, int nmemb, int size, int (*cmp)(const void *, const void *))
{
	for (int i = 0; i < nmemb-1; i++) {
		for (int j = 0; j < nmemb-i-1; j++) {
			if (cmp((char *)arr+j*size, (char *)arr+(j+1)*size) > 0) {
				swap2num((char *)arr+j*size, (char *)arr+(j+1)*size, size);	
			}
		}	
	}	
}

static void swap2num(void *data1, void *data2, int size)
{
	char *tmp = NULL;

	tmp = malloc(size);

	memcpy(tmp, data1, size);
	memcpy(data1, data2, size);
	memcpy(data2, tmp, size);

	free(tmp);
}


