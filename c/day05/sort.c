#include <stdio.h>

#define NUM	10

/*
 排序
 	数组连续存储---->检索快--->有序
	二分/折半查找
	冒泡:相邻两个元素两两比较
	选择:依次选择无序序列中的一个数值，与所有无序序列中的每一个数值比较，找
		到其中的最大/最小值，如果不是所选择的，那么交换,将交换的数值加入有序序列
	直接插入
		将整个数组中的元素分有序区和无序区，将无序区中的元素依次向有序
		序列中插入
	
	快排
 */

int main(void)
{
	int arr[NUM] = {3,2,1,7,6,8,9,4,5,10};
	int i, j;

#if 0
	//比较多少趟，每比较一趟，有序序列将增加一个元素，无序序列将减少一个元素
	for (i = 0; i < NUM-1; i++) {
		//无序序列所有元素的下标	
		for (j = 0; j < NUM-i-1; j++) {
			if (arr[j] < arr[j+1]) {
				//从大到小
				arr[j] = arr[j] + arr[j+1];		
				arr[j+1] = arr[j] - arr[j+1];		
				arr[j] = arr[j] - arr[j+1];		
			}	
		}	
	}

	for (i = 0; i < NUM; i++) {
		printf("%d ", arr[i]);	
	}
	printf("\n");
#endif

#if 0
	int select, ind;

	//从小到大
	for (i = 0; i < NUM-1; i++) {
		select = arr[i];	
		ind = i;
		for	(j = i+1; j < NUM; j++) {
			if (arr[j] < select) {
				select = arr[j];
				ind = j;
			}
		}
		if (select != arr[i]) {
			arr[ind] = arr[i];	
			arr[i] = select;
		}
	}

	for (i = 0; i < NUM; i++) {
		printf("%d ", arr[i]);	
	}
	printf("\n");
#endif

	//从大到小
	int tmp;
	for (i = 1; i < NUM; i++) {
		tmp = arr[i];
		for (j = i-1; j >= 0; j--) {
			if (tmp > arr[j]) {
				arr[j+1] = arr[j];
			} else 
				break;
		}
		arr[j+1] = tmp;	
	}

	for (i = 0; i < NUM; i++) {
		printf("%d ", arr[i]);	
	}
	printf("\n");

	return 0;
}

