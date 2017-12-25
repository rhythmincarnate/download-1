#include <stdio.h>

int main(void)
{
	/*
		1*1 = 1
	    1*2 = 2 2*2 = 4	
	 */

	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= i; j++) {
			printf("%d*%d = %-3d", j, i, j*i);	
			//%-3d 输出的结果占三个宽度, 靠左对齐
		}	
		printf("\n");
	}

	return 0;
}

